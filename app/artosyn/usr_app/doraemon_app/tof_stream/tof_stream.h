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
*       2.  Date         : 2020/08/24
*           Author       : martin
*           Modification : modify
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
#include "arm_to_dsp_data.h"

/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
#define TOF_RAW_PHASE_GROUP_QUEUE_SIZE     (3)  //tof帧group缓存队列大小
#define TOF_RAW_PHASE_FRAME_NUM_IN_GROUP   (1)  //tof每组内部帧数量


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


typedef enum _switch_StreamType
{
    STREAM_TYPE_NONE,

    STREAM_TYPE_IR_640_400,
    STREAM_TYPE_IR_1280_800,
    STREAM_TYPE_IR_1280_960,
    STREAM_TYPE_IR_1280_1024,

    STREAM_TYPE_DEPTH_640_400,
    STREAM_TYPE_DEPTH_1280_800,
    STREAM_TYPE_DEPTH_480_640,
    STREAM_TYPE_DEPTH_512_640,
    STREAM_TYPE_DEPTH_720_1280,
    STREAM_TYPE_DEPTH_960_1280,
    STREAM_TYPE_DEPTH_1024_1280,
    STREAM_TYPE_DEPTH_1280_1024
} switch_StreamType;

typedef struct _ob_stream_control
{
    uint32_t cameraSwitchType; // switch_StreamType
    uint32_t mx6300_stream_type;

    uint32_t mx6300_recevieBuf_size;

    uint32_t irImage_width;
    uint32_t irImage_height;

    uint32_t depth_inputImage_width;
    uint32_t depth_inputImage_height;

    uint32_t depth_ouputImage_width;
    uint32_t depth_ouputImage_height;

    uint8_t frameRate;
    
    bool typeSwitch_Enable;

    bool irStopStream;
    bool depthStopStream;

    softfilterParam softfilter_Param;
    Depth2Color_pixFormat d2c_pixFormat;

    int depth_MinValue;
    int depth_MaxValue;

    bool depthSoftD2C_enable;

    int deviceState;
} ob_streamcontrol;

extern ob_streamcontrol ob_streamControl;

/*==============================================*
 *      struct define                           *
 *----------------------------------------------*/
template <typename T> class MessageQueue;
template <typename T> class CommonQueue;


typedef struct _ob_tof_group_opt
{
    int32_t (*init_group)(void);
    ObTofFrameGroup* (*get_cur_group)(void);
    int32_t (*add_buff_to_group)(ObTofFrameGroup *pGroup, ar_picture_buffer_t *pRawBuff);
    int32_t (*release_buff_from_group)(ObTofFrameGroup *pGroup);
}ObTofGroupOpt;


typedef struct _ob_tof_camera_handle
{
    void *buf_sink_fd;           //设备/dev/icc_proxy_rpc_sink-0的句柄
    
    volatile uint32_t idx;       //全局记录frame index

    pthread_mutex_t op_mutex; 

    //生产端
    bool bSensorCaptureRunFlag;  //sensor采集流运行标志 rw
    sem_t semRtosCaptureStart;
    sem_t semRtosCaptureStop;

    //IR 消费端
    bool bIRConsumeRunFlag;     //tof data consume flag (rw)
	sem_t semIRConsumeProcessStart;
    pthread_t IRConsumeThdId;  

    //视差流消费端(视差转深度)
    bool bDepthConsumeRunFlag;     //depth data consume flag (rw)
    sem_t semDepthConsumeProcessStart;
    pthread_t DepthConsumeThdId;
    
    //深度流消费端(DSP)
    bool bDepthDSPRunFlag;        //depth data uvc consume flag (rw)
    sem_t semDepthDSPProcessStart;
    pthread_t DepthDSPThdId;

    //深度流消费端(uvc)
    bool bDepthUVCRunFlag;        //depth data uvc consume flag (rw)
    sem_t semDepthUVCProcessStart;
    pthread_t DepthUVCThdId; 


    unsigned short sTofStreamManageFlag;  //tof数据流共享模块标志
    pthread_mutex_t mutex;
    
    MessageQueue<TOF_STREAM_MSG_ID> *pMsgQueue;

    //Group相关
    //CommonQueue<ObTofFrameGroup> *pTofGroupQueue;  //tof帧group队列
    //ObTofFrameGroup *pCurGroup;   //当前正在处理的Group
    //ObTofGroupOpt *pGroupOpt;     //Group操作函数
    //pthread_mutex_t mutex_group_opt;
    
    CommonQueue<ObTofFrame> *pRawDataQueue; //manage data from rtos
    CommonQueue<ObTofFrame> *pDSPQueue;     //manage data from rtos
    CommonQueue<ObTofFrame> *pUVCQueue;     //manage data from rtos
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
*   Prototype    : ob_tof_sensor_on
*   Description  : tof sensor前端开流
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
extern int32_t ob_tof_sensor_on(void);


/*****************************************************************************
*   Prototype    : ob_tof_sensor_off
*   Description  : tof sensor前端关流
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
extern int32_t ob_tof_sensor_off(void);


/*****************************************************************************
*   Prototype    : ob_tof_stream_sendmsg
*   Description  : 消息发送
*   Input        : TOF_STREAM_MSG_ID msg  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
extern int32_t ob_tof_stream_sendmsg(TOF_STREAM_MSG_ID msg);


extern int32_t ob_ir_data_process_start(void);
extern int32_t ob_ir_data_process_stop(void);

extern int32_t ob_depth_data_process_start(void);
extern int32_t ob_depth_data_process_stop(void);


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

