/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : tof_uvc_op.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/5/29
*  Last Modified :
*  Description   : uvc_op.c header file
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/5/29
*           Author       : jiangxiaohui
*           Modification : Created file
*       2.  Date         : 2020/07/10
*           Author       : martin
*           Modification : Created file
*
******************************************************************************/
#ifndef __TOF_UVC_OP_H__
#define __TOF_UVC_OP_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
    
#include <linux/usb/video.h>
#include <linux/videodev2.h>
#include <linux/usb/uvc.h>

extern "C"{
#include "uvc_service2.h"
}


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
#define TOF_UVC_MAX_BUFFER_SIZE      (1280*970*2)


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/
typedef struct _tof_uvc_service tof_uvc_service;




/*==============================================*
 *      struct define                           *
 *----------------------------------------------*/
typedef enum _USB_VERSION{
    USB_VER_2_0,   //usb2.0(default)
    USB_VER_3_0,   //usb3.0
    USB_VER_MAX
}USB_VERSION_EM;

/* IO methods supported */
enum io_method {
    IO_METHOD_MMAP,
    IO_METHOD_USERPTR,
};

/* Buffer representing one video frame */
struct buffer {
    struct v4l2_buffer buf;
    void *start;
    size_t length;
};

typedef enum _DATA_TYPE
{
    TYPE_IR,
    TYPE_DEPTH
}EM_DATA_TYPE;

typedef struct tof_uvc_device
{
    tof_uvc_service         *pService;
    USB_VERSION_EM          emVerUSB;
    int                     fd;        //uvc fd:    "/dev/videoN"
    int                     is_streaming;
    int                     camera_fd; //camera fd: "/dev/cam_src-%d"

    struct uvc_streaming_control probe;
    struct uvc_streaming_control commit;
    unsigned int            control_interface;    //uvc的控制流 usb interface number
    unsigned int            streaming_interface;  //uvc的数据流 usb interface number

    int                     control;

    struct uvc_request_data request_error_code;
    unsigned int brightness_val;
    //uvc_camera_terminal_ext camera_terminal;
    //uvc_processing_unit_ext processing_unit;
    unsigned char           cs;
    unsigned char           entity_id;

    unsigned int            fcc;            //当前帧格式如: V4L2_PIX_FMT_MJPEG
    unsigned int            new_fcc;        //host设置新的数据格式
    unsigned int            fcc_index;      //由 get_fcc_index 获得
    unsigned int            width;          //uvc当前的width
    unsigned int            height;         //uvc当前的height
    unsigned int            frame_interval; //uvc当前的interval, (10000000/fps)

    //void                    **mem;
    unsigned int            nbufs;          //uvc buffqueue size
    unsigned int            bufsize;

    enum io_method          io;
    struct buffer           *mem;

    unsigned int            bulk;           //bulk传输模式,否则为ISOC模式
    uint8_t                 color;
    unsigned int            imgsize;
    void                    *imgdata;       //uvc发送buff(指向rtos数据buff)

    unsigned int            pts;            /*unit: ms*/
}tof_uvc_device;


//for depth/rawPhase and ir
typedef struct _tof_uvc_service 
{
    struct tof_uvc_device *dev;
    int dev_index;   // 1: depth/RawPhase 2:ir

    int                    run_flag;        //uvc run flag

    pthread_mutex_t        g_wrt_com_mutex; //uvc数据发送buff占用互斥锁

    volatile int           g_stream_on;     //uvc stream on的标志
    unsigned long long     g_uvc_timestamp; //ms
    volatile unsigned int  idx;             //buff's index(hold rtos)

    unsigned long long     u32FrameDropCount; //丢帧计数

    void                  *first_image_data;
    unsigned int           first_image_size;
    
    struct uvc_format_info *uvc_formats;
    int uvc_formats_num;


    pthread_t tid_poll;
    uint8_t  pollrun;

}tof_uvc_service;



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/

/*****************************************************************************
*   Prototype    : ob_tof_uvc_open
*   Description  : orbbec tof open uvc device
*   Input        : const char *devname  
*   Output       : None
*   Return Value : struct tof_uvc_device *
*****************************************************************************/
extern struct tof_uvc_device *ob_tof_uvc_open(const char *devname);


/*****************************************************************************
*   Prototype    : ob_tof_uvc_close
*   Description  : orbbec tof uvc device close
*   Input        : struct tof_uvc_device *dev  
*   Output       : None
*   Return Value : void
*****************************************************************************/
extern void ob_tof_uvc_close(struct tof_uvc_device *dev);


/*****************************************************************************
*   Prototype    : ob_tof_uvc_video_set_format
*   Description  : orbbec tof uvc video set fmt
*   Input        : struct tof_uvc_device *dev  
*   Output       : None
*   Return Value : int
*****************************************************************************/
extern int ob_tof_uvc_video_set_format(struct tof_uvc_device *dev, int dev_index);


/*****************************************************************************
*   Prototype    : ob_tof_uvc_events_process
*   Description  : tof uvc event process
*   Input        : struct tof_uvc_device *dev  
*   Output       : None
*   Return Value : void
*****************************************************************************/
extern void ob_tof_uvc_events_process(struct tof_uvc_device *dev, int dev_index);


/*****************************************************************************
*   Prototype    : ob_tof_uvc_video_send
*   Description  : send uvc stream api
*   Input        : struct tof_uvc_device *dev  
*                  void *data                  
*                  unsigned int len
*                  unsigned int pts, ms
*                  fd_set wfds                 
*                  struct timeval tv           
*   Output       : None
*   Return Value : int
*****************************************************************************/
//int ob_tof_uvc_video_send(struct tof_uvc_device *dev, void *data, unsigned int len, unsigned int pts, fd_set wfds, struct timeval tv);


/*****************************************************************************
*   Prototype    : ob_tof_uvc_events_init
*   Description  : ob tof uvc event init
*   Input        : struct tof_uvc_device *dev  
*   Output       : None
*   Return Value : void
*****************************************************************************/
extern void ob_tof_uvc_events_init(struct tof_uvc_device *dev);


/*****************************************************************************
*   Prototype    : ob_tof_uvc_video_init
*   Description  : video init
*   Input        : struct tof_uvc_device *dev __attribute__((__unused__))  
*   Output       : None
*   Return Value : int
*****************************************************************************/
extern int ob_tof_uvc_video_init(struct tof_uvc_device *dev __attribute__((__unused__)));


extern int ob_sl_uvc_cmd_cb_register(struct tof_uvc_device *dev);


/*****************************************************************************
*   Prototype    : uvc_video_send_process
*   Description  : uvc_video_send_process
*   Input        : struct tof_uvc_device *dev  
*                  void *data                  
*                  unsigned int len            
*                  unsigned int pts 单位:ms          
*   Output       : None
*   Return Value : extern int
*****************************************************************************/
extern int uvc_video_send_process(struct tof_uvc_device *dev, void *data, unsigned int len, unsigned int pts);

/*****************************************************************************
*   Prototype    : ob_tof_uvc_handle_streamoff_event
*   Description  : ob_tof_uvc_handle_streamoff_event
*   Input        : struct tof_uvc_device *dev  
*                  int dev_index
*   Output       : None
*   Return Value : extern int
*****************************************************************************/
int ob_tof_uvc_handle_streamoff_event(struct tof_uvc_device *dev, int dev_index);

int32_t ob_stream_on_op(EM_DATA_TYPE data_type);
int32_t ob_stream_off_op(EM_DATA_TYPE data_type);

uint32_t ob_mx6300_stream_switch(uint32_t type, uint8_t img_fps);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __TOF_UVC_OP_H__ */

