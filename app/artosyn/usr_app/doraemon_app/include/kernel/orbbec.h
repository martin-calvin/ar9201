/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : orbbec.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/4/29
*  Last Modified :
*  Description   : x

*  This program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2 of the License, or
*  (at your option) any later version.

*
*  History:
* 
*       1.  Date         : 2020/4/29
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/

#ifndef _ORBBEC_GADGET_H_
#define _ORBBEC_GADGET_H_

#include <linux/ioctl.h>
#include <linux/types.h>
#include <linux/usb/ch9.h>
#include <linux/usb/uvc.h>  //因为要延续uvc的枚举


//orbbec私有通道的 event事件枚举
#define ORBBEC_EVENT_FIRST			(UVC_EVENT_LAST + 0) //紧接着uvc模式的event事件枚举
#define ORBBEC_EVENT_CONNECT		(ORBBEC_EVENT_FIRST + 0)
#define ORBBEC_EVENT_DISCONNECT		(ORBBEC_EVENT_FIRST + 1)
#define ORBBEC_EVENT_STREAMON		(ORBBEC_EVENT_FIRST + 2)
#define ORBBEC_EVENT_STREAMOFF		(ORBBEC_EVENT_FIRST + 3)
#define ORBBEC_EVENT_SETUP			(ORBBEC_EVENT_FIRST + 4)
#define ORBBEC_EVENT_DATA			(ORBBEC_EVENT_FIRST + 5)
#define ORBBEC_EVENT_LAST			(ORBBEC_EVENT_FIRST + 5)

struct orbbec_request_data
{
	__s32 length;
	__u8 data[1020];
};

struct orbbec_event
{
	union {
		enum usb_device_speed speed;
		struct usb_ctrlrequest req;
		struct orbbec_request_data data;
	};
};


//ioctrl 控制字枚举定义 add by heimao

/*
    VIDIOC_DQEVENT 的定义在 videodev2.h
    #define	VIDIOC_DQEVENT		 _IOR('V', 89, struct v4l2_event)
*/
#define ORBBECIOC_SEND_RESPONSE		   _IOW('U', 1, struct orbbec_request_data)

#define ORBBECIOC_S_FMT_DEPTH          _IOWR('V', BASE_VIDIOC_PRIVATE + 1, struct v4l2_format)
#define ORBBECIOC_S_FMT_IR             _IOWR('V', BASE_VIDIOC_PRIVATE + 2, struct v4l2_format)

#define ORBBECIOC_REQBUFS_DEPTH        _IOWR('V', BASE_VIDIOC_PRIVATE + 3, struct v4l2_requestbuffers)
#define ORBBECIOC_REQBUFS_IR           _IOWR('V', BASE_VIDIOC_PRIVATE + 4, struct v4l2_requestbuffers)

#define ORBBECIOC_QUERYBUF_DEPTH       _IOWR('V', BASE_VIDIOC_PRIVATE + 5, struct v4l2_buffer)
#define ORBBECIOC_QUERYBUF_IR          _IOWR('V', BASE_VIDIOC_PRIVATE + 6, struct v4l2_buffer)

#define ORBBECIOC_QBUF_DEPTH           _IOWR('V', BASE_VIDIOC_PRIVATE + 7, struct v4l2_buffer)
#define ORBBECIOC_QBUF_IR              _IOWR('V', BASE_VIDIOC_PRIVATE + 8, struct v4l2_buffer)

#define ORBBECIOC_DQBUF_DEPTH          _IOWR('V', BASE_VIDIOC_PRIVATE + 9, struct v4l2_buffer)
#define ORBBECIOC_DQBUF_IR             _IOWR('V', BASE_VIDIOC_PRIVATE + 10, struct v4l2_buffer)

#define ORBBECIOC_STREAM_ENABLE_DEPTH  _IOWR('V', BASE_VIDIOC_PRIVATE + 11, int)
#define ORBBECIOC_STREAM_ENABLE_IR     _IOWR('V', BASE_VIDIOC_PRIVATE + 12, int)




#define ORBBEC_INTF_CONTROL		0
#define ORBBEC_INTF_STREAMING		1

/* ------------------------------------------------------------------------
 * Debugging, printing and logging
 */

#ifdef __KERNEL__

#include <linux/usb.h>	/* For usb_endpoint_* */
#include <linux/usb/composite.h>
#include <linux/usb/gadget.h>
#include <linux/videodev2.h>
#include <media/v4l2-fh.h>
#include <media/v4l2-device.h>

#include "orbbec_queue.h"

#define ORBBEC_TRACE_PROBE				(1 << 0)
#define ORBBEC_TRACE_DESCR				(1 << 1)
#define ORBBEC_TRACE_CONTROL			(1 << 2)
#define ORBBEC_TRACE_FORMAT			    (1 << 3)
#define ORBBEC_TRACE_CAPTURE			(1 << 4)
#define ORBBEC_TRACE_CALLS				(1 << 5)
#define ORBBEC_TRACE_IOCTL				(1 << 6)
#define ORBBEC_TRACE_FRAME				(1 << 7)
#define ORBBEC_TRACE_SUSPEND			(1 << 8)
#define ORBBEC_TRACE_STATUS			    (1 << 9)

#define ORBBEC_WARN_MINMAX				0
#define ORBBEC_WARN_PROBE_DEF			1

extern unsigned int orbbec_gadget_trace_param;

#define orbbec_trace(flag, msg...) \
	do { \
		if (orbbec_gadget_trace_param & flag) \
			printk(KERN_DEBUG "orbbecvideo: " msg); \
	} while (0)

#define orbbec_warn_once(dev, warn, msg...) \
	do { \
		if (!test_and_set_bit(warn, &dev->warnings)) \
			printk(KERN_INFO "orbbecvideo: " msg); \
	} while (0)

#define orbbec_printk(level, msg...) \
	printk(level "orbbecvideo: " msg)

/* ------------------------------------------------------------------------
 * Driver specific constants
 */
#ifdef CONFIG_USB_CONFIGFS_F_UVC_POOR_HOST
#define ORBBEC_NUM_REQUESTS			1
#else
#define ORBBEC_NUM_REQUESTS			64  //request队列buff个数定义
#endif

#define ORBBEC_MAX_REQUEST_SIZE	    512  //私有控制协议的request中data区域的buff占用的字节数
#define ORBBEC_MAX_EVENTS			4


#ifdef CONFIG_USB_CONFIGFS_F_ORBBEC_BULK_TRANSFER
#define ORBBEC_MAX_REQUEST_SIZE_BULK_OUT  1024  //私有通道的upload request的最大buff大小(Bytes) 
#define ORBBEC_NUM_REQUESTS_BULK_OUT      4     //upload request队列buff个数定义
#endif

/* ------------------------------------------------------------------------
 * Structures
 */

struct orbbec_video
{
	struct orbbec_device *orbbec;  //orbbec_video_init 中赋值
	struct usb_ep *ep;

	/* Frame parameters */
	u8 bpp;
	u32 fcc;
	unsigned int width;
	unsigned int height;
	unsigned int imagesize;
	struct mutex mutex;	/* protects frame parameters */

	/* Requests */
	unsigned int req_size; //buff队列的buff大小; 参考: orbbec_video_alloc_requests
	struct usb_request *req[ORBBEC_NUM_REQUESTS]; //req->buff 指向下面的变量: req_buffer[i]
	__u8 *req_buffer[ORBBEC_NUM_REQUESTS];        //真正存储数据的buff队列: req->buf = req_buffer
	struct list_head req_free;
	spinlock_t req_lock;

	void (*encode) (struct usb_request *req, struct orbbec_video *video,
			struct orbbec_buffer *buf);

	/* Context data used by the completion handler */
	__u32 payload_size;
	__u32 max_payload_size;

	struct orbbec_video_queue queue;
	unsigned int fid;
#ifdef CONFIG_USB_CONFIGFS_F_UVC_TIMESTAMP
	unsigned int sof;
#endif
};

enum orbbec_state
{
	ORBBEC_STATE_DISCONNECTED,
	ORBBEC_STATE_CONNECTED,
	ORBBEC_STATE_STREAMING,
};

#ifdef CONFIG_USB_CONFIGFS_F_ORBBEC_BULK_TRANSFER
struct upload_outbulk_req_list 
{
	struct usb_request	*req;
	unsigned int		pos;
	struct list_head 	list;
};
#endif


//orbbec 私有通道的usb 复合设备结构体定义
struct orbbec_device
{
	struct video_device vdev;
	struct v4l2_device v4l2_dev; //f_orbbec.c: v4l2_device_register
	enum orbbec_state state;
	struct usb_function func;

    //用于应用层qbuf,dquf的video设备
    struct orbbec_video video; //标准uvc video设备, 为了orbbec_v4l2.c: orbbec_v4l2_qbuf 编译通过
    //struct orbbec_video depth;
    //struct orbbec_video ir;
	//struct orbbec_video *mmap_video;
	
#ifdef CONFIG_USB_CONFIGFS_F_ORBBEC_BULK_TRANSFER
    struct orbbec_video upload;   //OUT BULK
    struct orbbec_video download; //IN BULK

	/* recv report, for OUT BULK EP */
	struct list_head   completed_out_req; //数据read缓存链表
	spinlock_t		   read_spinlock;
	wait_queue_head_t  read_queue;       //队列等待条件变量
	unsigned int	   qlen;             //reqeust队列长度, 初始化于: orbbec_function_bind
	unsigned short	   report_length;    //request buff的最大size(Bytes)

	/* send report, for IN BULK EP */
	spinlock_t			write_spinlock;
	bool				write_pending;
	wait_queue_head_t	write_queue;
	struct usb_request	*req;
#endif

	unsigned int intf;//orbbec私有通道的usb interface
    
	struct usb_ep *control_ep;
	struct usb_request *control_req; //control_req->buff 指向下面的变量: control_buf; 参考: orbbec_function_bind
	void *control_buf;               //此buff的大小由 ORBBEC_MAX_REQUEST_SIZE 指定


	/* Events */
	unsigned int event_length;
	unsigned int event_setup_out : 1; //只占用一位, 表示当前request是否是host->device方向的(OUT包).
};

static inline struct orbbec_device *to_orbbec(struct usb_function *f)
{
	return container_of(f, struct orbbec_device, func);
}

struct orbbec_file_handle
{
	struct v4l2_fh vfh;
	struct orbbec_video *device;
};

#define to_orbbec_file_handle(handle) \
	container_of(handle, struct orbbec_file_handle, vfh)

/* ------------------------------------------------------------------------
 * Functions
 */

extern void orbbec_function_setup_continue(struct orbbec_device *orbbec);
extern void orbbec_endpoint_stream(struct orbbec_device *dev);

extern void orbbec_function_connect(struct orbbec_device *orbbec);
extern void orbbec_function_disconnect(struct orbbec_device *orbbec);

#endif /* __KERNEL__ */

#endif /* _ORBBEC_H_ */

