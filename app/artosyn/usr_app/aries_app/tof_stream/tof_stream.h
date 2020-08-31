/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : tof_stream.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/5/30
*  Last Modified :
*  Description   : tof_stream.c header file
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/5/30
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/
#ifndef __TOF_STREAM_H__
#define __TOF_STREAM_H__


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <semaphore.h>
#include "tof_info.h"
#include "ar_picture_common_api.h"
#include "depth_stream.h"

/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
#define TOF_RAW_PHASE_GROUP_QUEUE_SIZE     (3)  //tof帧group缓存队列大小
#define TOF_RAW_PHASE_FRAME_NUM_IN_GROUP   (4)  //tof每组内部帧数量


/*==============================================*
 *      enum define                             *
 *----------------------------------------------*/

/*
tof stream模块消息枚举
由于tof流共享多模块使用(pahse uvc、depth计算、ir计算等)
需要统一按消息机制来管理
*/
typedef enum _TOF_STREAM_MSG_ID
{
    //request
	MSG_REQ_TOF_STREAM_FOR_PHASE_UVC, //phase uvc请求tof流
	MSG_REQ_TOF_STREAM_FOR_DEPTH,     //Depth计算请求tof流
	MSG_REQ_TOF_STREAM_FOR_IR,        //IR计算请求tof流
    //release
    MSG_REL_TOF_STREAM_FOR_PHASE_UVC, //phase uvc释放tof流
	MSG_REL_TOF_STREAM_FOR_DEPTH,     //Depth计算释放tof流
	MSG_REL_TOF_STREAM_FOR_IR,        //IR计算释放tof流
	
 	MSG_TOF_STREAM_MAX
}TOF_STREAM_MSG_ID;
    


/*==============================================*
 *      struct define                           *
 *----------------------------------------------*/
template <typename T> class MessageQueue;
template <typename T> class CommonQueue;
class DepthStreamContext;


typedef struct _ob_tof_group_opt
{
    int32_t (*init_group)(void);
    ObTofFrameGroup* (*get_cur_group)(void);
    int32_t (*add_buff_to_group)(ObTofFrameGroup *pGroup, ar_picture_buffer_t *pRawBuff);
    int32_t (*release_buff_from_group)(ObTofFrameGroup *pGroup);
    int32_t (*group_frame_check)(ObTofFrameGroup *pGroup);
}ObTofGroupOpt;


typedef struct _ob_tof_camera_handle
{
    void *buf_sink_fd;           //设备/dev/icc_proxy_rpc_sink-0的句柄
    volatile uint32_t idx;       //全局记录frame index
    pthread_mutex_t mutex;

    int out_stream_type;         //输出的数据流类型: refer to: TOF_UVC_RQ_STREAM_TYPE

#if DEPTH_CACHE_ENABLE
    DepthStreamContext *pDepthProcess;
#endif

    bool bTofCaptureThdRunFlag;  //tof capturn thread run flag (rw)
    bool bTofStreaming;          //Whether tof sensor streaming or not (rw)
    bool bTofConsumeRunFlag;     //tof data consume flag (rw)
	sem_t semTofConsumeProcessStart;
    pthread_t TofConsumeThdId;  
    unsigned short sTofStreamManageFlag;  //tof data share module, refer to BIT_TOF_STREAM_FOR_RAW_UVC
    
    MessageQueue<TOF_STREAM_MSG_ID> *pMsgQueue;

    //Group相关
    CommonQueue<ObTofFrameGroup> *pTofGroupQueue;  //tof帧group队列
    ObTofFrameGroup *pCurGroup;   //当前正在处理的Group
    ObTofGroupOpt *pGroupOpt;     //Group操作函数
    pthread_mutex_t mutex_group_opt;

}ob_tof_camera_handle;



typedef struct _uvc_frame_buf_info
{
    unsigned int addr; //虚拟地址
    unsigned int len;  //数据buff长度
    union
    {
        unsigned int index;
        void * ptr;   //pointer to ar_picture_buffer_t
    };
}ob_uvc_frame_buf_info;



/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/


/*****************************************************************************
*   Prototype    : ob_tof_data_process_start
*   Description  : tof data consume start
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
extern int32_t ob_tof_data_process_start(void);

/*****************************************************************************
*   Prototype    : ob_tof_data_process_stop
*   Description  : tof data consume stop
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
extern int32_t ob_tof_data_process_stop(void);


/*****************************************************************************
*   Prototype    : ob_tof_stream_sendmsg
*   Description  : 消息发送
*   Input        : TOF_STREAM_MSG_ID msg  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
extern int32_t ob_tof_stream_sendmsg(TOF_STREAM_MSG_ID msg);


/*****************************************************************************
*   Prototype    : ob_tof_stream_module_init
*   Description  : tof 数据流模块初始化
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
extern int32_t ob_tof_stream_module_init(void);


/*****************************************************************************
*   Prototype    : ob_tof_stream_module_uninit
*   Description  : tof 数据流模块去初始化
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
extern int32_t ob_tof_stream_module_uninit(void);



#endif /* __TOF_STREAM_H__ */

