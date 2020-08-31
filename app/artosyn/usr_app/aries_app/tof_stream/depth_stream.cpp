/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : depth_stream.cpp
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/7/14
*  Last Modified :
*  Description   : 深度流管理模块
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/7/14
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/

/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <sys/select.h>
#include <sys/prctl.h>
#include <sys/time.h>

#include <linux/usb/video.h>
#include <linux/videodev2.h>
#include <linux/usb/uvc.h>
    
#include "utils.h"
#include "logutil.h"

#include "tof_uvc_op.h"
#include "orbbec_gadget_types.h"
#include "tof_gadget.h"
#include "depth_stream.h"
#include "buff_queue.h"
#include "time_util.h"
#include "ob_ion_buff.h"
#include "obc_tof_dsp_icc.h"


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
#define DEPTH_BUFF_QUEUE_MAX_LEN  4    //深度缓存队列深度

#define DEPTH_FRAME_WIDTH         640
#define DEPTH_FRAME_HEIGHT        480
#define DEPTH_FRAME_BPP           16   //每个像素占用bit数


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/


/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/


/*****************************************************************************
*   Prototype    : depth_uvc_send_process_thd
*   Description  : calc depth in dsp thread
*   Input        : void *arg  
*   Output       : None
*   Return Value : static void *
*****************************************************************************/
static void *depth_uvc_send_process_thd(void *arg)
{
    DepthStreamContext *pHandler = (DepthStreamContext *)arg;
    if (NULL == pHandler){
        ERR("pHandler is NULL.\n");
        return NULL;
    }

    tof_uvc_service *pUvcService = tof_uvc_gadget_get_service(OB_UVC_DEVICE_NODE_NUM_DEPTH);
    if (!pUvcService) {
        ERR("pService is NULL. \n");
        return NULL;
    }

    sem_wait(&pHandler->semDepthProcessStart);
    DBG("Start depth uvc send!\n");

    while(pHandler->bProcessFlag){
        ObDepthFrame *pstDepthBuffer = pHandler->pBuffQueue->queue_wait_and_pop();
       
        int ret = uvc_video_send_process(pUvcService->dev,  
                                         pstDepthBuffer->stIonBuff.va, 
                                         pstDepthBuffer->stIonBuff.size, 
                                         pstDepthBuffer->pts); //14ms

        pHandler->pBuffQueue->pool_put_buffer(pstDepthBuffer);
    }

    INFO("Exit depth uvc send thread.\n");

    pthread_exit(NULL);
}


/*****************************************************************************
*   Prototype    : DepthStreamContext.DepthStreamContext
*   Description  : constructor function
*   Input        : None
*   Output       : None
*   Return Value : DepthStreamContext::
*****************************************************************************/
DepthStreamContext::DepthStreamContext(){
	width  = DEPTH_FRAME_WIDTH;
	height = DEPTH_FRAME_HEIGHT;
	bpp    = DEPTH_FRAME_BPP;
    bProcessFlag = false;
    pBuffQueue = NULL;
	calcDepth_thd_tid = 0;
    sem_init(&semDepthProcessStart, 0, 0);

    //申请buff pool用于管理ion内存address
    pBuffQueue = CommonQueue<ObDepthFrame>::create(DEPTH_BUFF_QUEUE_MAX_LEN, DEPTH_BUFF_QUEUE_MAX_LEN);
    if (NULL == pBuffQueue){
        ERR("Create pBuffQueue failed.\n");
        return;
    }

    //遍历队列申请ion内存,并把ion内存地址存储到队列管理
    for (int i = 0; i < pBuffQueue->pool_size(); i++){
        ObDepthFrame *pBuff = pBuffQueue->pool_get_buffer();
        INFO("[%d] pBuff:0x%X\n", i, pBuff);
        pBuff->stIonBuff.size = width*height*bpp/8;
        OB_ALLOC_ION_BUFFER(pBuff->stIonBuff.va, pBuff->stIonBuff.pa, pBuff->stIonBuff.size);
        pBuffQueue->pool_put_buffer(pBuff);
    }
}


/*****************************************************************************
*   Prototype    : DepthStreamContext.~DepthStreamContext
*   Description  : destructor function
*   Input        : None
*   Output       : None
*   Return Value : DepthStreamContext::
*****************************************************************************/
DepthStreamContext::~DepthStreamContext(){
    //put all quque buffer to buffer pool
    while(!pBuffQueue->queue_empty()){
        ObDepthFrame *pBuff = NULL;
        pBuffQueue->queue_try_pop(&pBuff);
        pBuffQueue->pool_put_buffer(pBuff);
    }
    
    //遍历buff poll, 释放ion内存
    for (int i = 0; i < pBuffQueue->pool_size(); i++){
        ObDepthFrame *pBuff = pBuffQueue->pool_get_buffer();
        INFO("[%d] pBuff:0x%X\n", i, pBuff);
        OB_RELEASE_ION_BUFFER(pBuff->stIonBuff.va);
        pBuff->stIonBuff.size = 0;
        pBuffQueue->pool_put_buffer(pBuff);
    }

    //释放队列资源
    if (NULL != pBuffQueue){
        delete pBuffQueue;
        pBuffQueue = NULL;
    }
}


/*****************************************************************************
*   Prototype    : DepthStreamContext.depth_calc_process
*   Description  : 
*   Input        : ObTofFrameGroup *group  
*   Output       : None
*   Return Value : int DepthStreamContext::
*****************************************************************************/
int DepthStreamContext::depth_calc_process(ObTofFrameGroup *pGroupBuff) //计算深度
{
    if (!bProcessFlag)
        return -1;
    
    if (!pGroupBuff){
        ERR("pGroupBuff is NULL.\n");
        return -1;
    }

    if (NULL == pBuffQueue){
        ERR("cache haven't malloc yet!\n");
        return -1;
    }

    //[1]---------Dqbuff an empty buffer----
    ObDepthFrame *pstDepthBuffer = pBuffQueue->pool_get_buffer();
    if (NULL == pstDepthBuffer){
        WARN("Dqbuff failed, maybe uvc send is blocking\n");
        return -1;
    }

    //[2]---------dsp calc depth------------
    int ret = ob_depth_calc(pGroupBuff, 0, NULL, 1, pstDepthBuffer->stIonBuff.pa);  //37ms
    if(ret < 0){
        ERR("ob_depth_calc Error.\n");
        return -1;
    }

    pstDepthBuffer->pts = pGroupBuff->frames[0]->pts;

    //[3]---------Qbuff-----------
    pBuffQueue->queue_push(pstDepthBuffer);  // ==> depth_uvc_send_process_thd

    return 0;
}


/*****************************************************************************
*   Prototype    : DepthStreamContext.depth_uvc_start
*   Description  : Depth process start
*   Input        : void  
*   Output       : None
*   Return Value : int DepthStreamContext::
*****************************************************************************/
int DepthStreamContext::depth_uvc_start(void)
{
    if (bProcessFlag){
        WARN("depth process is already start.\n");
        return -1;
    }

    //[1]------create calc depth thread-------------------
    start_new_thread_join("depth process", &calcDepth_thd_tid, depth_uvc_send_process_thd, (void *)this);

    //[2]------clear queue buff, give back to buff pool----
    while(!pBuffQueue->queue_empty()){
        ObDepthFrame *pBuff = NULL;
        pBuffQueue->queue_try_pop(&pBuff);
        pBuffQueue->pool_put_buffer(pBuff);
    }

    //[3]------trigger start depth process thread----------
    bProcessFlag = true;
    sem_post(&semDepthProcessStart);

    DBG("Start Depth process success!\n");

    return 0;
}


/*****************************************************************************
*   Prototype    : DepthStreamContext.depth_uvc_stop
*   Description  : depth process stop
*   Input        : void  
*   Output       : None
*   Return Value : int DepthStreamContext::
*****************************************************************************/
int DepthStreamContext::depth_uvc_stop(void)
{
    if (!bProcessFlag){
        WARN("depth process is already stop.\n");
        return -1;
    }

    //[1]------trigger depth process stop--------------
    bProcessFlag = false;

    if (pBuffQueue->queue_empty()){
        //push an empty buffer to queue and wakeup queue wait when queue is empty.
        ObDepthFrame *pstEmptyBuffer = pBuffQueue->pool_get_buffer();
        if (NULL != pstEmptyBuffer)
            pBuffQueue->queue_push(pstEmptyBuffer);
    }

    //[2]-----join depth process thread----------------
    if (0 != calcDepth_thd_tid){
        pthread_join(calcDepth_thd_tid, NULL);
        calcDepth_thd_tid = 0;
    }

    DBG("Stop Depth process success!\n");

    return 0;
}



