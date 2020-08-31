/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : tof_stream.c
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/5/30
*  Last Modified :
*  Description   : tof camera stream manager
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/5/30
*           Author       : jiangxiaohui
*           Modification : Created file
*


说明(仅针对isoc传输方式):
上位机请求数据流流程:
1. 上位机下发请求流命令;
2. AR9201 linux 内核上报 UVC_EVENT_STREAMON 消息;
3. AR9201向内核申请 uvc buff队列并启动uvc;
4. AR9201应用层启动tof流数据流消费模块;
5. AR9201触发tof sensor出流;
6. 数据流贯通！


上位机关闭数据流流程:
1. 上位机下发关流流命令;
2. AR9201 linux 内核上报 UVC_EVENT_STREAMOFF 消息;
3. AR9201应用层停止tof流数据流消费模块;
4. AR9201触发tof sensor停流;
5. AR9201内核释放 uvc buff队列并关闭uvc;
6. 数据流停止！

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
#include "tof_stream.h"
#include "message_queue.h"
#include "buff_queue.h"
#include "tof_embedded.h"
#include "obc_tof_drv.h"
#include "obc_tof_i2c.h"
#include "s5k33dxx_i2c_ctl.h"
#include "time_util.h"
#include "obc_tof_dsp_icc.h"
#include "tof_dsp_memory_map.h"
#include "ob_dsp_test.h"
#include <new>


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/

/*
    采用一个short类型变量, 每个bit位代表一个模块使用tof数据流
    -------------------------------------
    |   bit3 |   bit2 |  bit1  | bit0   |
    ------------------------------------
    bit0: rawPhase flag
    bit1: depth flag
    bit2: ir flag
*/

#define BIT_TOF_STREAM_FOR_RAW_UVC	(0)
#define BIT_TOF_STREAM_FOR_DEPTH	(1)
#define BIT_TOF_STREAM_FOR_IR    	(2)

#define NON_MODULE_NEED_TOF         (0)


#define UVC_RAW_PHASE_INTERVAL_US         (73000)
#define EXLINE_DATA_BYTE_INDEX_IN_FRAME   (1280*1*2)

/*==============================================*
 *      struct define                           *
 *----------------------------------------------*/
// typedef struct _cam_raw_context_t
// {
//     ar_facotry_element_obj_t pipeline;
//     ar_facotry_element_obj_t cam_src;
//     ar_facotry_element_obj_t buf_sink_0;
// }cam_raw_context_t;

extern volatile param_ion_mellc_t ion_mem_info[USE_ION_MEM_NUM];


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/
static const char *pTofStreamManageStr[MSG_TOF_STREAM_MAX] =
{
    "PhaseUVC request tof stream",
    "Depth request tof stream",
    "IR phase request tof stream",
    
    "PhaseUVC release tof stream",
    "Depth release tof stream",
    "IR phase release tof stream"
};



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/


/*****************************************************************************
*   Prototype    : ob_tof_stream_get_handle
*   Description  : orbbec tof stream 操作句柄建立/获取
*   Input        : void  
*   Output       : None
*   Return Value : static ob_tof_camera_handle *
*****************************************************************************/
static ob_tof_camera_handle *ob_tof_stream_get_handle(void)
{
    static ob_tof_camera_handle *pHandle = NULL;

    if (!pHandle)
    {
        WARN("pHandle is note inited, so malloc it here!\n");
        pHandle = (ob_tof_camera_handle *)malloc(sizeof(ob_tof_camera_handle));
        if(!pHandle){
            ERR("memeory out!\n");
            return NULL;
        }
        memset(pHandle, 0, sizeof(ob_tof_camera_handle)); 
    }

    return pHandle;
}


//load still image
static void image_load(struct tof_uvc_device *dev, const char *img)
{
    int fd = -1;
    tof_uvc_service *server_l= dev->pService;

    if (img == NULL)
        return;

    fd = open(img, O_RDONLY);
    if (fd == -1) {
        ERR("Unable to open MJPEG image '%s'\n", img);
        return;
    }

    dev->imgsize = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    dev->imgdata = malloc(TOF_UVC_MAX_BUFFER_SIZE);
    if (dev->imgdata == NULL) 
    {
        ERR("Unable to allocate memory for MJPEG image\n");
        dev->imgsize = 0;
        return;
    }

    read(fd, dev->imgdata, dev->imgsize);

    server_l->first_image_data = dev->imgdata;
    server_l->first_image_size = dev->imgsize;
    
    close(fd);
}


//just for debug!
static void ob_tof_raw_phase_ebd_print_debug(ar_picture_buffer_t *pRawPhaseBuff)
{
    ObTofPhaseType emPhaseType = PHASE_TYPE_UNKNOW;
    ObTofOutMode emOutMode = S5K33D_OUT_MODE_UNKNOW;
    ObTofModFreq freq = OB_TOF_MOD_FREQ_UNKNOW;
    uint8_t frame_index = 0;
    float temp_tx = 0.0;
    float temp_rx = 0.0;
    uint32_t integration_time = 0;
    
    frame_index = tof_embedded_33d_get_FrameIndex((uint8_t *)pRawPhaseBuff->mem[0].addr); 
    emPhaseType = tof_embedded_33d_get_PhaseType((uint8_t *)pRawPhaseBuff->mem[0].addr);
    emOutMode   = tof_embedded_33d_get_output_format((uint8_t *)pRawPhaseBuff->mem[0].addr);
    freq        = tof_embedded_33d_get_Frequency((uint8_t *)pRawPhaseBuff->mem[0].addr);
    temp_tx     = tof_embedded_33d_getDriverICTemp((uint8_t *)pRawPhaseBuff->mem[0].addr);
    temp_rx     = tof_embedded_33d_getSensorTemp((uint8_t *)pRawPhaseBuff->mem[0].addr);
    integration_time = tof_embedded_33d_getIntegrationTime((uint8_t *)pRawPhaseBuff->mem[0].addr);

    static uint32_t expect_id = 0;
    if (pRawPhaseBuff->frame_id != expect_id){
        DBG("ERROR, frame_id:%d, expect_id:%d\n", pRawPhaseBuff->frame_id, expect_id);
	}
    expect_id = pRawPhaseBuff->frame_id+1;

    static uint32_t expect_index = 0;
    if (frame_index != expect_index){
        DBG("ERROR, ebd frame index:%d, expect_index:%d\n", frame_index, expect_index);
    }
    expect_index = frame_index+1;
    if (expect_index > 254){
        expect_index %= 254;
    }
      
    if (pRawPhaseBuff->frame_id % 1200 == 0){
        DBG("raw phase frame id:%d, ebd_frame_index:%03d, pts:%dms\n", 
            pRawPhaseBuff->frame_id, frame_index, pRawPhaseBuff->pts);
    }

    //printf("id:%d, pts:%dms\n", pRawPhaseBuff->frame_id, pRawPhaseBuff->pts);
    printf("id:%d, pts:%dms, index:%03d, freq:0x%X, phasetype:0x%X, outmode:0x%X, temp_tx:%.2f, temp_rx:%.2f, exptime:%d\n",
        pRawPhaseBuff->frame_id, pRawPhaseBuff->pts, frame_index, freq, emPhaseType, emOutMode, temp_tx, temp_rx, integration_time);
}


//just for debug!
static void ob_tof_raw_phase_group_debug(ObTofFrameGroup *pGroupBuff)
{
    if (!pGroupBuff){
        ERR("pGroupBuff is NULL.\n");
        return;
    }

    for (int i = 0; i < pGroupBuff->real_count; i++)
    {
        ObTofFrame *pFrame = pGroupBuff->frames[i];

        static uint32_t expect_id = 0;
        if (pFrame->frame_id != expect_id){
            DBG("ERROR, frame_id:%d, expect_id:%d\n", pFrame->frame_id, expect_id);
        }
        expect_id = pFrame->frame_id+1;
        
        static uint32_t expect_index = 0;
        if (pFrame->frame_index != expect_index){
            DBG("ERROR, ebd frame index:%d, expect_index:%d\n", pFrame->frame_index, expect_index);
        }
        expect_index = pFrame->frame_index+1;
        if (expect_index > 254){
            expect_index %= 254;
        }
          
        if (pFrame->frame_id % 1200 == 0){
            DBG("raw phase frame id:%d, ebd_frame_index:%03d, pts:%dms\n", 
                pFrame->frame_id, pFrame->frame_index, pFrame->pts);
        }

        usleep(4*1000); 

    }
}


/*****************************************************************************
*   Prototype    : ob_tof_stream_send_depth_img_test_thd
*   Description  : 深度或者rawphase图uvc发送测试
*   Input        : void * param  
*   Output       : None
*   Return Value : static void *
*****************************************************************************/
static void *ob_tof_stream_send_depth_img_test_thd(void *param)
{
    int ret = -1;
    fd_set fds;
    struct timeval tv;
    tof_uvc_service *pService = tof_uvc_gadget_get_service(OB_UVC_DEVICE_NODE_NUM_DEPTH);

    //image_load(pService->dev, "/nfs_share/testdata/tof_raw_data_1280_962.raw");
    //image_load(pService->dev, "/nfs_share/testdata/480p_16bit_depth.raw");
    //image_load(pService->dev, "/usrdata/usr/data/orbbec/testdata/tof_raw_data_1280_962.raw");
    image_load(pService->dev, "/nfs_share/testdata/tof_raw_data_1280_970.raw");
    //image_load(pService->dev, "/usrdata/usr/data/orbbec/testdata/480p_16bit_depth.raw");


    tv.tv_sec   = 0;
    tv.tv_usec  = 10000;

    FD_ZERO(&fds);
    FD_SET(pService->dev->fd, &fds);
    
    while(pService->run_flag)
    {
        //ret = ob_tof_uvc_video_send(pService->dev, (void *)pService->dev->imgdata, pService->dev->imgsize, 0, fds, tv);
        ret = uvc_video_send_process(pService->dev, (void *)pService->dev->imgdata, pService->dev->imgsize, 0);
        if (ret < 0)
        {
            //ERR("uvc send failed.\n");
        }

        usleep(30*1000);
    }

    return NULL;
}


/*****************************************************************************
*   Prototype    : ob_tof_stream_send_ir_img_test_thd
*   Description  : ir图uvc发送测试
*   Input        : void * param  
*   Output       : None
*   Return Value : static void *
*****************************************************************************/
static void *ob_tof_stream_send_ir_img_test_thd(void *param)
{
    int ret = -1;
    fd_set fds;
    struct timeval tv;
    tof_uvc_service *pService = tof_uvc_gadget_get_service(OB_UVC_DEVICE_NODE_NUM_IR);

    //image_load(pService->dev, "/nfs_share/testdata/480p_16bit_ir.raw");
    image_load(pService->dev, "/usrdata/usr/data/orbbec/testdata/480p_16bit_ir.raw");

    tv.tv_sec   = 0;
    tv.tv_usec  = 10000;

    FD_ZERO(&fds);
    FD_SET(pService->dev->fd, &fds);
    
    while(pService->run_flag)
    {
        //ret = ob_tof_uvc_video_send(pService->dev, (void *)pService->dev->imgdata, pService->dev->imgsize, 0, fds, tv); 
        ret = uvc_video_send_process(pService->dev, (void *)pService->dev->imgdata, pService->dev->imgsize, 0);
        if (ret < 0)
        {
            //ERR("uvc send failed.\n");
        }

        usleep(30*1000);
    }

    return NULL;
}


/*****************************************************************************
*   Prototype    : ob_tof_get_current_group
*   Description  : 获取当前group指针
*   Input        : void  
*   Output       : None
*   Return Value : static ObTofFrameGroup *
*****************************************************************************/
static ObTofFrameGroup *ob_tof_get_current_group(void)
{
    ob_tof_camera_handle *pHandle = ob_tof_stream_get_handle();
    if (!pHandle){
        ERR("pHandle is NULL.\n");
        return NULL;
    }

    if (pHandle->pCurGroup == NULL || pHandle->pCurGroup->real_count == TOF_RAW_PHASE_FRAME_NUM_IN_GROUP) 
    {
        if (!pHandle->pTofGroupQueue->pool_empty())
        {
            pHandle->pCurGroup = pHandle->pTofGroupQueue->pool_get_buffer();

            //clear frame group buff
            pHandle->pGroupOpt->release_buff_from_group(pHandle->pCurGroup); //ob_tof_release_buff_from_group    
            pHandle->pCurGroup->real_count = 0; 
        }
        else
        {
            //WARN("Group pool is empty(has no buff to use), process queue is full!\n");
            pHandle->pCurGroup = NULL;
        }   
    }

    return pHandle->pCurGroup;
}


/*****************************************************************************
*   Prototype    : ob_tof_release_buff_from_group
*   Description  : 释放已经添加到group的帧buff
*   Input        : ObTofFrameGroup *pGroup  
*   Output       : None
*   Return Value : static int32_t
*****************************************************************************/
static int32_t ob_tof_release_buff_from_group(ObTofFrameGroup *pGroup)
{
    ob_tof_camera_handle *pHandle = ob_tof_stream_get_handle();
    if (!pHandle){
        ERR("pHandle is NULL.\n");
        return -1;
    }

    ar_picture_handle sink_handle = (ar_picture_handle)(pHandle->buf_sink_fd);
    if(!sink_handle){
        ERR("sink_handle is null. \n");
        return -1;
    }

    //pthread_mutex_lock(&pHandler->mutex_group_opt);
    for (int i = 0; i < pGroup->real_count; i++){
       ObTofFrame *pFrame = pGroup->frames[i];
       if(ar_picture_release_img(sink_handle, pFrame->pRawBuff)){
           ERR("release buffer failed\n");
           continue;
       }   
    }
    //pthread_mutex_unlock(&pHandler->mutex_group_opt);

    return 0;
}


/*****************************************************************************
*   Prototype    : ob_tof_group_frame_check
*   Description  : check group frame
*   Input        : ObTofFrameGroup *pGroup  
*   Output       : None
*   Return Value : static int32_t
    组内帧为同一组返回0,否则-1

 每个Group的帧顺序为,且帧id连续: 
 第0帧: Freq: 100Mhz(0x00), Type: Non_Shuffle(0x10)
 第1帧: Freq: 100Mhz(0x00), Type: Shuffle(0x1B)
 第2帧: Freq:  80Mhz(0x01), type: Non_Shuffle(0x10)
 第3帧: Freq:  80MHz(0x01), type：Shuffle(0x1B)

*****************************************************************************/
static int32_t ob_tof_group_frame_check(ObTofFrameGroup *pGroup)
{
    int32_t ret = 0;
    if (pGroup->frame_count != TOF_RAW_PHASE_FRAME_NUM_IN_GROUP){
        ERR("There are no 4 frames in the group, num:%d\n", pGroup->frame_count);
        return -1;
    }

    for (int i = 0; i < pGroup->real_count; i++)
    {
        ObTofFrame *pFrame = pGroup->frames[i];
        ObTofModFreq freq = pFrame->frequency;
        ObTofPhaseType phaseType = pFrame->phaseType;

        if (0 == i && ((freq != OB_TOF_MOD_FREQ_100MHZ) || (phaseType != PHASE_TYPE_NON_SHUFFLE))) {
            ERR("The first frame is invalid, i:%d, freq:%d, phaseType:%d\n", i, freq, phaseType);
            ret = -1;
        }
        if (1 == i && ((freq != OB_TOF_MOD_FREQ_100MHZ) || (phaseType != PHASE_TYPE_SHUFFLE)
            || (pFrame->frame_id != pGroup->frames[i-1]->frame_id + 1))){
            ERR("The second frame is invalid, i:%d, freq:%d, phaseType:%d\n", i, freq, phaseType);
            ret = -1;
        }
        if (2 == i && ((freq != OB_TOF_MOD_FREQ_80MHZ) || (phaseType != PHASE_TYPE_NON_SHUFFLE)
            || (pFrame->frame_id != pGroup->frames[i-1]->frame_id + 1))){
            ERR("The third  frame is invalid, i:%d, freq:%d, phaseType:%d\n", i, freq, phaseType);
            ret = -1;
        }
        if (3 == i && ((freq != OB_TOF_MOD_FREQ_80MHZ) || (phaseType != PHASE_TYPE_SHUFFLE)
            || (pFrame->frame_id != pGroup->frames[i-1]->frame_id + 1))){
            ERR("The fourth frame is invalid, i:%d, freq:%d, phaseType:%d\n", i, freq, phaseType);
            ret = -1;
        }
    }
    
    return ret;
}


/*****************************************************************************
*   Prototype    : ob_tof_add_buff_to_group
*   Description  : 添加buff指针信息到group
*   Input        : ObTofFrameGroup *pGroup        
*                  ar_picture_buffer_t *pRawBuff  
*   Output       : None
*   Return Value : static int32_t

    每个Group的帧顺序为: 
    第一帧: Freq: 100Mhz(0x00), Type: Non_Shuffle(0x10)
    第二帧: Freq: 100Mhz(0x00), Type: Shuffle(0x1B)
    第三帧: Freq:  80Mhz(0x01), type: Non_Shuffle(0x10)
    第四帧: Freq:  80MHz(0x01), type：Shuffle(0x1B)


    这里设计了一个Group fifo, 用于存储tof的Group,
    该api会做一系列的校验以保证放入到Group fifo的是一组匹配的tof帧

*****************************************************************************/
static int32_t ob_tof_add_buff_to_group(ObTofFrameGroup *pGroup, ar_picture_buffer_t *pRawBuff)
{   
    ObTofPhaseType emPhaseType = PHASE_TYPE_UNKNOW;
    ObTofOutMode emOutMode = S5K33D_OUT_MODE_UNKNOW;
    ObTofModFreq freq = OB_TOF_MOD_FREQ_UNKNOW;
    uint8_t frame_index = 0;
    float temp_tx = 0.0;
    float temp_rx = 0.0;
    uint16_t integration_time;
    ObTofFrame *pFrame = NULL;  //frame which pointer to current group processing's frame

    ob_tof_camera_handle *pHandle = ob_tof_stream_get_handle();
    if (!pHandle){
        ERR("pHandle is NULL.\n");
        return -1;
    }   

    if (!pGroup || !pRawBuff || !pGroup->frames){
        ERR("null pointer, pGourp:%p, pRawBuff:%p, frame:%p\n", pGroup, pRawBuff, pGroup->frames);
        return -2;
    }

    int index = pGroup->real_count;
    pFrame = pGroup->frames[index];
    if (!pFrame){
        ERR("frame is null, index:%d.\n", index);
        return -3;
    }

    uint8_t *pData = (uint8_t *)pRawBuff->mem[0].addr;
    int ret_t = check_EBD_data((uint16_t *)pData);
    if (-1 == ret_t)
        ERR("check EBD data failed.\n");

    frame_index = tof_embedded_33d_get_FrameIndex(pData); 
    emPhaseType = tof_embedded_33d_get_PhaseType(pData);
    emOutMode   = tof_embedded_33d_get_output_format(pData);
    freq        = tof_embedded_33d_get_Frequency(pData);
    temp_tx     = tof_embedded_33d_getDriverICTemp(pData);
    temp_rx     = tof_embedded_33d_getSensorTemp(pData);
    integration_time = tof_embedded_33d_getIntegrationTime(pData);

    pFrame->frame_id          = pRawBuff->frame_id;
    pFrame->pts               = pRawBuff->pts;
    pFrame->width             = pRawBuff->format.width; 
    pFrame->height            = pRawBuff->format.height;
    pFrame->buffer_size       = pRawBuff->mem[0].len;
    pFrame->duty_cycle        = 35.70;        //调制信号的占空比,如值为50.00对应50%的占空比
    pFrame->intergration_time = integration_time;          //积分时间(us)
    pFrame->frame_index       = frame_index;
    pFrame->frequency         = freq;         //调制频率
    pFrame->phaseType         = emPhaseType;  //相位类型
    pFrame->out_mode          = emOutMode;    //数据模式
    pFrame->temp_tx           = temp_tx;      //tx温度 如: 34.24
    pFrame->temp_rx           = temp_rx;      //rx温度
    pFrame->pRawBuff          = pRawBuff;


    /*
        保证入队列的四帧是同一组的,否则整组数据丢弃(不入队列)
        每个Group的帧顺序为:(且帧id连续)
        第0帧: Freq: 100Mhz(0x00), Type: Non_Shuffle(0x10)
        第1帧: Freq: 100Mhz(0x00), Type: Shuffle(0x1B)
        第2帧: Freq:  80Mhz(0x01), type: Non_Shuffle(0x10)
        第3帧: Freq:  80MHz(0x01), type：Shuffle(0x1B)
    */

    if ((0 == pGroup->real_count) && ((freq != OB_TOF_MOD_FREQ_100MHZ) || (emPhaseType != PHASE_TYPE_NON_SHUFFLE))){
            pHandle->pGroupOpt->release_buff_from_group(pHandle->pCurGroup); //ob_tof_release_buff_from_group    
            pHandle->pCurGroup->real_count = 0; 
            return -4;
    }
    if ((1 == pGroup->real_count) && ((freq != OB_TOF_MOD_FREQ_100MHZ) || (emPhaseType != PHASE_TYPE_SHUFFLE)
        || (pFrame->frame_id != pGroup->frames[index-1]->frame_id + 1))) {
            pHandle->pGroupOpt->release_buff_from_group(pHandle->pCurGroup); //ob_tof_release_buff_from_group    
            pHandle->pCurGroup->real_count = 0; 
            return -5;
    }
    if ((pGroup->real_count == 2) && ((freq != OB_TOF_MOD_FREQ_80MHZ) || (emPhaseType != PHASE_TYPE_NON_SHUFFLE)
        || (pFrame->frame_id != pGroup->frames[index-1]->frame_id + 1))){
            pHandle->pGroupOpt->release_buff_from_group(pHandle->pCurGroup); //ob_tof_release_buff_from_group    
            pHandle->pCurGroup->real_count = 0; 
            return -6;
    }
    if ((pGroup->real_count == 3) && ((freq != OB_TOF_MOD_FREQ_80MHZ) || (emPhaseType != PHASE_TYPE_SHUFFLE)
        || (pFrame->frame_id != pGroup->frames[index-1]->frame_id + 1))){
            pHandle->pGroupOpt->release_buff_from_group(pHandle->pCurGroup); //ob_tof_release_buff_from_group    
            pHandle->pCurGroup->real_count = 0; 
            return -7;
    }


    pGroup->real_count++;
    if (pGroup->real_count == TOF_RAW_PHASE_FRAME_NUM_IN_GROUP)
        pHandle->pTofGroupQueue->queue_push(pGroup);  // ==> ob_tof_stream_rawdata_process_thd

    return 0;
}


/*****************************************************************************
*   Prototype    : ob_tof_init_group_queue
*   Description  : tof group队列初始化
*   Input        : None
*   Output       : None
*   Return Value : static int32_t
*****************************************************************************/
static int32_t ob_tof_init_group_queue(void)
{
    ob_tof_camera_handle *pHandle = ob_tof_stream_get_handle();
    if (!pHandle){
        ERR("pHandle is NULL.\n");
        return -1;
    }

    pHandle->pTofGroupQueue = new (std::nothrow) CommonQueue<ObTofFrameGroup>();
    if (!pHandle->pTofGroupQueue){
        ERR("no memeory.\n");
        return -1;
    }

    //初始化Group缓存队列(暂定3个Group, 每个Group含有4帧)
    pHandle->pTofGroupQueue->init(TOF_RAW_PHASE_GROUP_QUEUE_SIZE, TOF_RAW_PHASE_GROUP_QUEUE_SIZE); 
    for (int i = 0; i < pHandle->pTofGroupQueue->pool_size(); i++)  //遍历group队列
    {
        ObTofFrameGroup *pGroup = pHandle->pTofGroupQueue->pool_get_buffer();

        INFO("[%d] pGroup:0x%X\n", i, pGroup);

        pGroup->frame_count = TOF_RAW_PHASE_FRAME_NUM_IN_GROUP;
        pGroup->frames = (ObTofFrame **) new ObTofFrame*[TOF_RAW_PHASE_FRAME_NUM_IN_GROUP]();
        if (!pGroup->frames){
            ERR("no memory.\n");
            return -1;
        }

        for (int j = 0; j < pGroup->frame_count; j++) {
            pGroup->frames[j] = new ObTofFrame();
            if (!pGroup->frames[j]) {
                ERR("no memory.\n");
                return -1;
            }
        }
        
        pHandle->pTofGroupQueue->pool_put_buffer(pGroup);
    }

    return 0;
}


static ObTofGroupOpt ob_tof_group_op =
{
    .init_group = ob_tof_init_group_queue,
    .get_cur_group = ob_tof_get_current_group,
    .add_buff_to_group = ob_tof_add_buff_to_group,
    .release_buff_from_group = ob_tof_release_buff_from_group,
    .group_frame_check = ob_tof_group_frame_check
};


// phase -> dsp 
// dsp消费的时间必须小于一个group(4帧)时间
static void ob_tof_phase2dsp(ObTofFrameGroup *pGroupBuff)
{
    int ret = -1;
    
    tof_uvc_service *pUvcService = tof_uvc_gadget_get_service(OB_UVC_DEVICE_NODE_NUM_DEPTH);
    if (!pUvcService) {
        ERR("pService is NULL. \n");
        return;
    }

    if (!pGroupBuff){
        ERR("pGroupBuff is NULL.\n");
        return;
    }

    void* pDepth_pa = (void *)ion_mem_info[TOF_depth0_MEM].pa; //depth output buffer地址固定;
    void* pDepth_va = (void *)ion_mem_info[TOF_depth0_MEM].va; //depth output buffer地址固定;
    int output_size=640*480*sizeof(uint16_t);	 //bytes

    ret = ob_depth_calc(pGroupBuff, 0, NULL, 1, pDepth_pa);  //37ms
    if(ret < 0){
        ERR("ob_depth_calc Error.\n");
        return;
    } 

    //TODO: dsp计算与深度uvc发送拆分为异步模式
    ret = uvc_video_send_process(pUvcService->dev,  pDepth_va, output_size, pGroupBuff->frames[0]->pts); //14ms
}


//send phase data to uvc
static void ob_tof_phase_out(ObTofFrameGroup *pGroupBuff)
{
    int ret = -1;
    fd_set fds;
    struct timeval tv;

    tof_uvc_service *pUvcService = tof_uvc_gadget_get_service(OB_UVC_DEVICE_NODE_NUM_DEPTH);
    if (!pUvcService) {
        ERR("pService is NULL. \n");
        return;
    }

    if (!pGroupBuff){
        ERR("pGroupBuff is NULL.\n");
        return;
    }

	//usb2.0 uvc发送phase数据带宽受限, 这里做丢帧处理(按组丢帧) 
    if (pUvcService->dev->emVerUSB == USB_VER_2_0){
        static uint32 s_count = 0;
        if (s_count++ % 11 != 0)
            return;
    }
    
    tv.tv_sec  = 0;
    tv.tv_usec = 10*1000;
    FD_ZERO(&fds);
    FD_SET(pUvcService->dev->fd, &fds);

	struct timeval currentTimeval;
    static uint64_t lastSendTime; //us
	uint64_t waitTime = 0; //us

    ObTofExteraLine exLine;
    memset(&exLine, 0, sizeof(exLine));
    exLine.sensorId = 0x033D;
    exLine.width = 1280;
    exLine.height = 970;

    for (int i = 0; i < pGroupBuff->real_count; i++)
    {
        ObTofFrame *pFrame = pGroupBuff->frames[i];

        exLine.frequency = pFrame->frequency;
        exLine.out_mode = pFrame->out_mode;
        exLine.phaseType = pFrame->phaseType;
        exLine.temp_tx = pFrame->temp_tx;
        exLine.temp_rx = pFrame->temp_rx;
        exLine.frame_index = pFrame->frame_index;
        exLine.frame_type = FRAME_TYPE_PHASE;
        exLine.pts = pFrame->pts;

        uint8_t *pData = (uint8_t *)pFrame->pRawBuff->mem[0].addr;
        memcpy(pData + EXLINE_DATA_BYTE_INDEX_IN_FRAME, (char *)&exLine, sizeof(exLine));

        //由于usb2.0带宽速度限制, 所以发送帧间延时处理,保证每帧都正常传输完成
        if (pUvcService->dev->emVerUSB == USB_VER_2_0){   
    		gettimeofday(&currentTimeval, NULL);
    		waitTime = currentTimeval.tv_sec * 1000000ULL + currentTimeval.tv_usec - lastSendTime;
    		if(waitTime > 0 && waitTime < UVC_RAW_PHASE_INTERVAL_US){
    			waitTime = UVC_RAW_PHASE_INTERVAL_US - waitTime;
    		}else{
    			waitTime = 0;
    		}
    	    usleep(waitTime);  //printf("waitTime:%lldus\n", waitTime);

    		gettimeofday(&currentTimeval, NULL);
    		lastSendTime = currentTimeval.tv_sec * 1000000ULL + currentTimeval.tv_usec;
        }
        
        ret = uvc_video_send_process(pUvcService->dev,  (void *)pFrame->pRawBuff->mem[0].addr, pFrame->buffer_size, pFrame->pts);//3-4ms
        if (ret < 0){
            //ERR("uvc send failed, id:%d, ret:%d\n", pFrame->frame_id, ret);
        }else{
            //INFO("[%d]uvc send success, id:%d, freq:0x%02X, type:0x%02X\n", i, pFrame->frame_id, pFrame->frequency, pFrame->phaseType);
        }  
    }
}


//save phase data to sd card or emmc
static void ob_tof_phase_save(ObTofFrameGroup *pGroupBuff)
{
    if (!pGroupBuff){
        ERR("pGroupBuff is NULL.\n");
        return;
    }

    for (int i = 0; i < pGroupBuff->real_count; i++)
    {
        ObTofFrame *pFrame = pGroupBuff->frames[i];

        char name[128];

		time_t timep;
		struct tm *p_tm;
		timep = time(NULL);
		p_tm = gmtime(&timep); /*获取GMT时间*/

        int freq = 0;
        if (OB_TOF_MOD_FREQ_100MHZ == pFrame->frequency)
            freq = 100;
        else if (OB_TOF_MOD_FREQ_80MHZ == pFrame->frequency)
            freq = 80;
        else
            freq = 0;


        char szPhaseType[64];
        memset(szPhaseType, 0, sizeof(szPhaseType));
        if (PHASE_TYPE_NON_SHUFFLE == pFrame->phaseType)
            sprintf(szPhaseType, "NON_SHUFFLE");
        else if (PHASE_TYPE_SHUFFLE == pFrame->phaseType)
            sprintf(szPhaseType, "SHUFFLE");
        else 
            sprintf(szPhaseType, "UNKNON");

		sprintf(name, "/mnt/sdcard/record/%04d-%02d-%02d_%02d_%02d_%02d__" \
                      "%d_%03dMHZ_%s.raw",
			          (p_tm->tm_year+1900), (p_tm->tm_mon+1), p_tm->tm_mday, 
			          p_tm->tm_hour, p_tm->tm_min, p_tm->tm_sec,
			          i, freq, szPhaseType);

        ob_util_dumpToFile((char *)pFrame->pRawBuff->mem[0].addr, pFrame->buffer_size, name);
    }
}


/*****************************************************************************
*   Prototype    : ob_tof_usb_gadget_cmd_from_host
*   Description  : uvc event cmd callback,  uvc cmd from host
*   Input        : OB_TOF_GADGET_CMD_EM cmd  
*                  void *data                
*   Output       : None
*   Return Value : void
*****************************************************************************/
void ob_tof_usb_gadget_cmd_from_host(OB_TOF_GADGET_CMD_EM cmd, void *pData)
{
    int val = -1;
    ob_tof_camera_handle *pHandle = ob_tof_stream_get_handle();
    if (!pHandle){
        ERR("pHandle is NULL.\n");
        return;
    }
    
    DBG("cmd:%d, data:0x%x\n", cmd, *(int *)pData);
    switch (cmd)
    {
        case OB_GADGET_CMD_TOF_UVC_STREAM_ON:
        {
            val = *((int *)pData);
            pHandle->out_stream_type = val;//host’s requeset stream type

#if DEPTH_CACHE_ENABLE
            //[1] start depth stream process if host request depth
            if (pHandle->out_stream_type == TOF_STREAM_DEPTH){
                pHandle->pDepthProcess->depth_uvc_start();
            }
#endif
            //[2] start tof stream process thread
            ob_tof_data_process_start(); 

            //[3] start sensort stream process
            TOF_STREAM_MSG_ID msg = MSG_TOF_STREAM_MAX;
            
            if (val == TOF_STREAM_PHASE)
                ob_tof_stream_sendmsg(MSG_REQ_TOF_STREAM_FOR_PHASE_UVC);
            else if (val == TOF_STREAM_DEPTH)
                ob_tof_stream_sendmsg(MSG_REQ_TOF_STREAM_FOR_DEPTH);
            else
                ERR("val is error, val:%d\n", val);
            
            break;
        }
        
        case OB_GADGET_CMD_TOF_UVC_STREAM_OFF:
        {
            //[1] stop tof stream process
            ob_tof_data_process_stop(); 

#if DEPTH_CACHE_ENABLE
            //[2] stop depth stream process
            if (pHandle->out_stream_type == TOF_STREAM_DEPTH){
                pHandle->pDepthProcess->depth_uvc_stop();
            }
#endif

            //[3] stop sensor stream process
            TOF_STREAM_MSG_ID msg = MSG_TOF_STREAM_MAX;
            val = *((int *)pData);
            if (val == TOF_STREAM_PHASE)
                ob_tof_stream_sendmsg(MSG_REL_TOF_STREAM_FOR_PHASE_UVC);
            else if (val == TOF_STREAM_DEPTH)
                ob_tof_stream_sendmsg(MSG_REL_TOF_STREAM_FOR_DEPTH);
            else
                ERR("val is error, val:%d\n", val);

            pHandle->out_stream_type = TOF_STREAM_UNKNOWN;

            break;
        }
        
        default:
        {
            ERR("cmd is error, cmd:%d\n", cmd);
            break;
        }
    }
}


/*****************************************************************************
*   Prototype    : ob_tof_stream_rawdata_process_thd
*   Description  : raw phase 数据消费线程
*   Input        : void *arg  
*   Output       : None
*   Return Value : static void *
*****************************************************************************/
static void *ob_tof_stream_rawdata_process_thd(void *arg)
{
    INFO("Enter Message Process thread\n");

    ob_tof_camera_handle *pHandler = (ob_tof_camera_handle *)arg;
    if (!pHandler){
        ERR("pHandler is NULL!\n");
        return NULL;
    }

    tof_uvc_service *pUvcService = tof_uvc_gadget_get_service(OB_UVC_DEVICE_NODE_NUM_DEPTH);
    if (NULL == pUvcService){
        ERR("pUvcService is NULL.\n");
        return NULL;
    }

    sem_wait(&pHandler->semTofConsumeProcessStart);

    while (pHandler->bTofConsumeRunFlag)
    {
        #if 0
        while(pHandler->pTofGroupQueue->queue_empty()){
            if (!pHandler->bTofConsumeRunFlag)
                break;
            usleep(2000);
        }
        if (!pHandler->bTofConsumeRunFlag)
            break;
        #endif
        
        ObTofFrameGroup *pFullBuff = pHandler->pTofGroupQueue->queue_wait_and_pop(); //block api
        
        if (0 == pHandler->pGroupOpt->group_frame_check(pFullBuff)){ // ob_tof_group_frame_check  
            if (TOF_STREAM_PHASE == pUvcService->dev->tof_stream_type)
                ob_tof_phase_out(pFullBuff); // 16ms
            else if (TOF_STREAM_DEPTH == pUvcService->dev->tof_stream_type)
#if DEPTH_CACHE_ENABLE
                pHandler->pDepthProcess->depth_calc_process(pFullBuff);
#else
                ob_tof_phase2dsp(pFullBuff);
#endif                
            else;
        }
        
        pHandler->pTofGroupQueue->pool_put_buffer(pFullBuff);    //==> ob_tof_stream_get_data_from_rtos_thd
    }

    INFO("Exit tof raw data consume process thread.\n");

    pthread_exit(NULL);
}


/*****************************************************************************
*   Prototype    : ob_tof_stream_get_data_from_rtos_thd
*   Description  : tof camera数据流采集线程
*   Input        : void * param  
*   Output       : None
*   Return Value : static void *

*****************************************************************************/
static void *ob_tof_stream_get_data_from_rtos_thd(void *arg)
{
    int ret = 0;

    ar_picture_buffer_t *pRawBuff = NULL;   //采集到rtos端给的rawPhase数据buff
    ar_picture_handle sink_handle = NULL;
    ObTofFrameGroup *pCurGroup = NULL;

    tof_uvc_service *pUvcService = tof_uvc_gadget_get_service(OB_UVC_DEVICE_NODE_NUM_DEPTH);
    if (!pUvcService) {
        ERR("pService is NULL. \n");
        return NULL;
    }

    ob_tof_camera_handle *pTofCamHandle = (ob_tof_camera_handle *)arg;
    if (!pTofCamHandle) {
        ERR("pTofCamHandle is NULL. \n");
        return NULL;
    }

    pTofCamHandle->buf_sink_fd = ar_picture_open("/dev/icc_proxy_rpc_sink-0");
    if(pTofCamHandle->buf_sink_fd <= 0){
        ERR("open /dev/icc_proxy_rpc_sink-0 error. ret:%d\n", pTofCamHandle->buf_sink_fd);
        return NULL;
    }

    sink_handle = (ar_picture_handle)(pTofCamHandle->buf_sink_fd);
    if(!sink_handle){
        ERR("handle is null. \n");
        return NULL;
    }

    ret = ar_picture_set_min_align_size(sink_handle, TOF_UVC_MAX_BUFFER_SIZE);
    if(ret != 0){
        ERR("pid %d set ar_picture_set_min_align_size min align failed!\n", getpid());
    }


    DBG("Start Caputure tof stream.\n");

    //tof流采集
    while(pTofCamHandle->bTofCaptureThdRunFlag)
    {   
        //[1] capture raw data
        pRawBuff = ar_picture_get_img(pTofCamHandle->buf_sink_fd); //blocking api
        if(!pRawBuff)
        {
            ERR("get sink 0 buffer error\n");
            usleep(30*1000);
            continue;
        }     
      
        // ob_tof_raw_phase_ebd_print_debug(pRawBuff);
        //goto RELEASE;
        
        //[2] get an group from group pool to save the raw data address
        pCurGroup = (ObTofFrameGroup *)pTofCamHandle->pGroupOpt->get_cur_group(); //ob_tof_get_current_group
        if (!pCurGroup){
            //WARN("pCurGroup is NULL, Maybe the Group fifo is full!\n");
            goto RELEASE;
        }

        //[3] add frame buff address to group
        ret = pTofCamHandle->pGroupOpt->add_buff_to_group(pCurGroup, pRawBuff); //ob_tof_add_buff_to_group
        if (0 != ret){   
            //WARN("add buff to Group failed, ret:%d\n", ret);
            goto RELEASE;
        }

        continue;


RELEASE:    
        if(ar_picture_release_img(sink_handle, pRawBuff)){
            ERR("release buffer failed\n");
            return NULL;
        }    
    }

    INFO("Exit!\n");
    return NULL;
}


/*****************************************************************************
*   Prototype    : ob_tof_stream_msg_process_thd
*   Description  : 消息模块处理线程
*   Input        : void param  
*   Output       : None
*   Return Value : static void *
    根据后续需求:
    会有多个模块使用tof数据流: 
    (1) rawphase uvc
    (2) dsp cal depth
    (3) dsp cal ir

    本模块统一管理tof数据流的共享逻辑(最终决策是否关闭tof sensor流)

*****************************************************************************/
static void *ob_tof_stream_msg_process_thd(void *arg)
{
    INFO("Enter Message Process thread\n");

    ob_tof_camera_handle *pHandler = (ob_tof_camera_handle *)arg;
    if (!pHandler)
    {
        ERR("pHandler is NULL!\n");
        return NULL;
    }

    Message<TOF_STREAM_MSG_ID> *pMsg = NULL;
    assert(pHandler->pMsgQueue);


    while(true)
    {
        pHandler->pMsgQueue->WaitMessage();
        pMsg = pHandler->pMsgQueue->PopFront();

        INFO("Get Message:%d(%s)\n", pMsg->GetID(), pTofStreamManageStr[pMsg->GetID()]);
        switch (pMsg->GetID())
        {
            case MSG_REQ_TOF_STREAM_FOR_PHASE_UVC: //phase uvc请求tof流
            {
                ob_util_set_bit_16(&pHandler->sTofStreamManageFlag, BIT_TOF_STREAM_FOR_RAW_UVC);
                break;
            }
            case MSG_REQ_TOF_STREAM_FOR_DEPTH:     //Depth计算请求tof流
            {
                ob_util_set_bit_16(&pHandler->sTofStreamManageFlag, BIT_TOF_STREAM_FOR_DEPTH);
                break;
            }
        	case MSG_REQ_TOF_STREAM_FOR_IR:        //IR计算请求tof流
        	{
                ob_util_set_bit_16(&pHandler->sTofStreamManageFlag, BIT_TOF_STREAM_FOR_IR);
                break;
            }
            //release
            case MSG_REL_TOF_STREAM_FOR_PHASE_UVC: //phase uvc释放tof流
            {
                ob_util_clear_bit_16(&pHandler->sTofStreamManageFlag, BIT_TOF_STREAM_FOR_RAW_UVC);
                break;
            }

        	case MSG_REL_TOF_STREAM_FOR_DEPTH:     //Depth计算释放tof流
            {
                ob_util_clear_bit_16(&pHandler->sTofStreamManageFlag, BIT_TOF_STREAM_FOR_DEPTH);
                break;
            }
        	case MSG_REL_TOF_STREAM_FOR_IR:        //IR计算释放tof流
        	{
                ob_util_clear_bit_16(&pHandler->sTofStreamManageFlag, BIT_TOF_STREAM_FOR_IR);
                break;
            }
            default:
            {
                ERR("ID is error. ID:%d\n", pMsg->GetID());
                break;
            }
        }

        INFO("Tof stream Manage share flag: 0x%X\n", pHandler->sTofStreamManageFlag);

        if (NON_MODULE_NEED_TOF == pHandler->sTofStreamManageFlag) {
            //no need tof stream, then switch off
            if (pHandler->bTofStreaming){
                tof_cam_stream_off();
                pHandler->bTofStreaming = false;
            }
        }else{
            //need tof stream, then swithc on
            if (!pHandler->bTofStreaming){
               tof_cam_stream_on();
               pHandler->bTofStreaming = true;
            }
        }

        if (pMsg)
        {
            delete pMsg;
            pMsg = NULL;
        }
    }

    INFO("Exit Message Process thread\n");

    return NULL;
}


/*****************************************************************************
*   Prototype    : ob_tof_stream_sendmsg
*   Description  : 消息发送
*   Input        : TOF_STREAM_MSG_ID msg  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_tof_stream_sendmsg(TOF_STREAM_MSG_ID msg)
{
    Message<TOF_STREAM_MSG_ID> *pMsg = Message<TOF_STREAM_MSG_ID>::create(msg);
    if (!pMsg) {
        ERR("No memory!\n");
        return -1;
    }

    ob_tof_camera_handle *pHanlde = ob_tof_stream_get_handle();
    if (!pHanlde){
        ERR("pHandle is NULL.\n");
        return -1;
    }

    assert(NULL != pHanlde->pMsgQueue);
    pHanlde->pMsgQueue->Push(pMsg, true);
    DBG("Msg:%d(%d) \n", msg, pTofStreamManageStr[msg]);

    return 0;
}


/*****************************************************************************
*   Prototype    : ob_tof_data_process_start
*   Description  : tof data consume start
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_tof_data_process_start(void)
{
    ob_tof_camera_handle *pHandle = ob_tof_stream_get_handle();
    if (!pHandle){
        ERR("pHandle is NULL.\n");
        return -1;
    }

    if (pHandle->bTofConsumeRunFlag){
        WARN("is already start\n");
        return -1;
    }

    //[1] clear Group queue buff, give back to buff pool
    while(!pHandle->pTofGroupQueue->queue_empty()){
        ObTofFrameGroup *pBuff = NULL;
        pHandle->pTofGroupQueue->queue_try_pop(&pBuff);
        pHandle->pTofGroupQueue->pool_put_buffer(pBuff);
    }

    //[2] -------tof data consume thread create-------
    start_new_thread_ext("tof data process thread", &pHandle->TofConsumeThdId, ob_tof_stream_rawdata_process_thd, (void *)pHandle, false, 99);

    //[3] ---------trigger to start--------------------------
    pHandle->bTofConsumeRunFlag = true;
    sem_post(&pHandle->semTofConsumeProcessStart);

    DBG("Star Tof Preview Done!\n");

    return 0;
}


/*****************************************************************************
*   Prototype    : ob_tof_data_process_stop
*   Description  : tof data consume stop
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_tof_data_process_stop(void)
{
    ob_tof_camera_handle *pHandle = ob_tof_stream_get_handle();
    if (!pHandle){
        ERR("pHandle is NULL.\n");
        return -1;
    }

    if (!pHandle->bTofConsumeRunFlag){
        WARN("is already stop\n");
        return -1;
    }

    //[1] -------trigger stop tof data consume thread -------
    pHandle->bTofConsumeRunFlag = false;  //==> ob_tof_stream_rawdata_process_thd
    
    if (pHandle->pTofGroupQueue->queue_empty()) {
        //push an empty buffer to queue and wakeup queue wait when queue is empty.
        ObTofFrameGroup *pstEmptyBuffer = pHandle->pTofGroupQueue->pool_get_buffer();
        if (NULL != pstEmptyBuffer)
            pHandle->pTofGroupQueue->queue_push(pstEmptyBuffer);
    }

    if (0 != pHandle->TofConsumeThdId){
        pthread_join(pHandle->TofConsumeThdId, NULL);
        pHandle->TofConsumeThdId = 0;
    }


    DBG("Stop Tof Preview Done!\n");

    return 0;
}


/*****************************************************************************
*   Prototype    : ob_tof_sensor_init
*   Description  : tof sensor init
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
static int32_t ob_tof_sensor_init(void)
{
    int ret = 0;

    /* init camera global params */
    obc_cam_handle_t cam_handle = get_ob_cam_handle();
    // 全局变量默认值已经在so库中设置好。应用层也可以按照下面方式，根据需要修改
    cam_handle->cam_pipeline_cfg.input_vidio_res.width = 1280;
    cam_handle->cam_pipeline_cfg.input_vidio_res.height = 970;
    cam_handle->cam_pipeline_cfg.cam_id = TOF_CAMERA_ID; //Fixme: tof cam_id = 0 ,must sync with dts
    /* init camera */
    ret = init_tof_cam(cam_handle);
    if(ret < 0){
        printf("init_tof_cam failed!\n");
        return -1;
    }
    usleep(100000);// delay 100ms
    /* open camera */
    cam_handle->tof_cam_fd = open_tof_cam(cam_handle->tof_cam_id);
    if(cam_handle->tof_cam_fd < 0){
        printf("open_tof_cam failed!\n");
        return -1;
    }
    /* Set default parameters */
    //laser driver config, Miuxiangrong: 2020-07-15
    cxa4016_reg_write(0x4B06, 0xff);
    cxa4016_reg_write(0x4B07, 0x08);
    cxa4016_reg_write(0x4B08, 0xc5);
    // tof_sensor.set_pixel_binning(1);//binning mode 1, 1280 * 480

    ob_tof_camera_handle *handler = ob_tof_stream_get_handle();
    if (!handler){
        ERR("pHandle is NULL.\n");
        return -1;
    }
    handler->bTofCaptureThdRunFlag = true;  //star tof capture thread: ob_tof_stream_get_data_from_rtos_thd


    INFO("Success.\n");

    return AR_MULTIMEDIA_SUCCESS;

}


/*****************************************************************************
*   Prototype    : ob_tof_sensor_uninit
*   Description  : tof sensor uninit
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_tof_sensor_uninit(void)
{
    ob_tof_camera_handle *handler = ob_tof_stream_get_handle();
    if (!handler){
        ERR("pHandle is NULL.\n");
        return -1;
    }
    handler->bTofCaptureThdRunFlag = false;

    //todo

    return 0;
}


/*****************************************************************************
*   Prototype    : ob_tof_stream_module_init
*   Description  : tof前端数据流采集端模块初始化
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_tof_stream_module_init(void)
{
    ob_tof_camera_handle *pHandle = ob_tof_stream_get_handle();
    if (!pHandle){
        ERR("pHandle is NULL.\n");
        return -1;
    }

    pHandle->pMsgQueue = new (std::nothrow) MessageQueue<TOF_STREAM_MSG_ID>();
    if (!pHandle->pMsgQueue){
        ERR("pMsgQueue is NULL.\n");
        return -1;
    }

    pHandle->bTofStreaming = false;
    pHandle->bTofCaptureThdRunFlag = false;
    pHandle->bTofConsumeRunFlag = false;
    pHandle->TofConsumeThdId = 0;

    pthread_mutex_init(&pHandle->mutex_group_opt, NULL);
	sem_init(&pHandle->semTofConsumeProcessStart, 0, 0);
    
    pHandle->pGroupOpt = &ob_tof_group_op;
    pHandle->pGroupOpt->init_group(); //ob_tof_init_group_queue

    ob_tof_sensor_init(); //tof sensor初始化并建立pipeline
    ob_dsp_init();
#if DEPTH_CALC_FROM_PICTURES //dsp使用图片计算depth并存图测试
    int ret;
    void* pDepth = (void *)ion_mem_info[TOF_depth0_MEM].pa; //depth output buffer地址固定;
    int output_size=640*480*sizeof(uint16_t);	 //bytes
    //dsp使用图片计算一次
    ret = ob_depth_calc(NULL, 0, NULL, 1, pDepth);  //37ms
    if(ret < 0){
        ERR("ob_depth_calc Error.\n");
        return -1;
    }
    //depth存图
    ob_util_dumpToFile((char*)ion_mem_info[TOF_depth0_MEM].va, (long)output_size, "/mnt/tof_depth0_out.raw");
#endif

#if DEPTH_CACHE_ENABLE
    pHandle->pDepthProcess = new DepthStreamContext();
    if (NULL == pHandle->pDepthProcess){
        ERR("new DepthStreamContext failed!\n");
        return -1;
    }
#endif

    tof_uvc_gadget_register_cmd_cb(OB_UVC_DEVICE_NODE_NUM_DEPTH, ob_tof_usb_gadget_cmd_from_host);

    start_new_thread("capture tof stream thread", NULL, ob_tof_stream_msg_process_thd, (void *)pHandle);
    start_new_thread_ext("tof stream capture thread", NULL, ob_tof_stream_get_data_from_rtos_thd, (void *)pHandle, true, 80);
    
    //start_new_thread("Test Depth Data send thread", NULL, ob_tof_stream_send_depth_img_test_thd, (void *)pHandle);
    //start_new_thread("Test IR Data send thread", NULL, ob_tof_stream_send_ir_img_test_thd, (void *)pHandle);

    return 0;
}


/*****************************************************************************
*   Prototype    : ob_tof_stream_module_uninit
*   Description  : tof 数据流模块去初始化
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_tof_stream_module_uninit(void)
{
    ob_tof_camera_handle *pHandle = ob_tof_stream_get_handle();

    if (pHandle->pMsgQueue){
        free(pHandle->pMsgQueue);
        pHandle->pMsgQueue = NULL;
    }

#if DEPTH_CACHE_ENABLE
    if (pHandle->pDepthProcess){
        delete pHandle->pDepthProcess;
        pHandle->pDepthProcess = NULL;
    }
#endif

    if (pHandle) {
        free(pHandle);
        pHandle = NULL;
    }
    
    //TODO
}


