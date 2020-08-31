/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : uvc_op.c
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/5/29
*  Last Modified :
*  Description   : uvc operation api
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/5/29
*           Author       : jiangxiaohui
*           Modification : Created file
*       2.  Date         : 2020/7/10
*           Author       : martin
*           Modification : add new funciton for doraemon
*
******************************************************************************/

/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/prctl.h>
#include <math.h>

extern "C"{
#include "uvc_function.h"
#include "uvc_configfs.h"
//#include "uvc_service2.h"
}

#include "tof_uvc_op.h"
#include "logutil.h"
#include "utils.h"
#include "orbbec_gadget.h"
#include "obc_sl_drv.h"
#include "tof_stream.h"
#include "tof_gadget.h"
#include "obc_tof_dsp_icc.h"


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
#define UVC_SEND_QUEUE_SIZE   (5)

#define OB_UVC_DEVICE_NODE_NUM_RGB    0  // /dev/video0 for RGB
#define OB_UVC_DEVICE_NODE_NUM_DEPTH  1  // /dev/video1 for depth or raw phase
#define OB_UVC_DEVICE_NODE_NUM_IR     2  // /dev/video2 for IR

#define ORBBEC_STREAM_TYPE_NONE          0
#define ORBBEC_STREAM_TYPE_DEPTH         1
#define ORBBEC_STREAM_TYPE_IR            2

#define ORBBEC_SUCCESS                   0
#define ORBBEC_FAILED                   -1


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/
pthread_mutex_t ob_ir_resolution_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t ob_depth_resolution_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t ob_stream_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t  g_stream_control_mutex;


/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/
static int32_t ob_stream_on_op(EM_DATA_TYPE data_type);
static int32_t ob_stream_off_op(EM_DATA_TYPE data_type);


static uint32_t ob_mx6300_stream_switch(uint32_t type, uint8_t img_fps)
{
    switch (type)
    {
        case STREAM_TYPE_IR_1280_960:
            switch_resolution(STREAM_IR_OPEN, RES_1280_960, img_fps);
            INFO("set ir resolution 1280*960, fps:%d\n",img_fps);
            break;
        case STREAM_TYPE_DEPTH_512_640:
            switch_resolution(STREAM_DEPTH_OPEN, RES_512_640, img_fps);
            INFO("set depth resolution 512*640, fps:%d\n",img_fps);
            break;
        case STREAM_TYPE_DEPTH_720_1280:
            switch_resolution(STREAM_DEPTH_OPEN, RES_960_1280, img_fps);
            INFO("set depth resolution 960*1280, fps:%d\n",img_fps);
            break;
        case STREAM_TYPE_DEPTH_960_1280:
            switch_resolution(STREAM_DEPTH_OPEN, RES_960_1280, img_fps);
            INFO("set depth resolution 960*1280, fps:%d\n",img_fps);
            break;
        case STREAM_TYPE_DEPTH_480_640:
            switch_resolution(STREAM_DEPTH_OPEN, RES_480_640, img_fps);
            INFO("set depth resolution 480*640, fps:%d\n",img_fps);
            break;
        default:
            ERR("invalid resolution:%d\n", type);
            break;
    }
    return ORBBEC_SUCCESS;
}


static int32_t uvc_video_stream(struct tof_uvc_device *dev, int dev_index, int32_t enable)
{
    int32_t type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
    int32_t ret;

    if (!enable)
    {
        ret = ioctl(dev->fd, VIDIOC_STREAMOFF, &type);
        if (ret < 0)
        {
            INFO("UVC: VIDIOC_STREAMOFF failed: %s (%d).\n",
                   strerror(errno), errno);
            return ret;
        }

        return 0;
    }

    ret = ioctl(dev->fd, VIDIOC_STREAMON, &type);
    if (ret < 0) {
        printf("UVC: Unable to start streaming %s (%d).\n",
               strerror(errno), errno);
        return ret;
    }

    printf("UVC: Starting video stream.\n");

    return 0;
}


static int uvc_uninit_device(struct tof_uvc_device *dev)
{
    unsigned int i;
    int ret;
    for (i = 0; i < dev->nbufs; ++i)
    {
        ret = munmap(dev->mem[i].start, dev->mem[i].length);
        if (ret < 0)
        {
            printf("UVC: munmap failed\n");
            return ret;
        }
    }

    free(dev->mem);

    // switch (dev->io)
	// {
    //     case IO_METHOD_MMAP:
    //         for (i = 0; i < dev->nbufs; ++i)
    // 		{
    //             ret = munmap(dev->mem[i].start, dev->mem[i].length);
    //             if (ret < 0)
    // 			{
    //                 printf("UVC: munmap failed\n");
    //                 return ret;
    //             }
    //         }

    //         free(dev->mem);
    //         break;

    //     case IO_METHOD_USERPTR:        
    //         break;
    //     default:
    //         #if 0
    //         if (dev->run_standalone)
    // 		{
    //             for (i = 0; i < dev->nbufs; ++i)
    //                 free(dev->dummy_buf[i].start);

    //             free(dev->dummy_buf);
    //         }
    //         #endif
    //         break;
    // }

    return 0;
}


static int uvc_video_qbuf_mmap(struct tof_uvc_device *dev)
{
    unsigned int i;
    int ret;

    for (i = 0; i < dev->nbufs; ++i) {
        memset(&dev->mem[i].buf, 0, sizeof(dev->mem[i].buf));

        dev->mem[i].buf.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
        dev->mem[i].buf.memory = V4L2_MEMORY_MMAP;
        dev->mem[i].buf.index = i;
        dev->mem[i].buf.bytesused = dev->mem[i].length;
   
        ret = ioctl(dev->fd, VIDIOC_QBUF, &(dev->mem[i].buf));
        if (ret < 0) {
            printf("UVC: VIDIOC_QBUF failed : %s (%d).\n",
                   strerror(errno), errno);
            return ret;
        }
    }

    return 0;
}


static int uvc_video_qbuf_userptr(struct tof_uvc_device *dev)
{
    unsigned int i;
    int ret;

#if 0
    /* UVC standalone setup. */
    if (dev->run_standalone) {
        for (i = 0; i < dev->nbufs; ++i) {
            struct v4l2_buffer buf;

            CLEAR(buf);
            buf.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
            buf.memory = V4L2_MEMORY_USERPTR;
            buf.m.userptr = (unsigned long)dev->dummy_buf[i].start;
            buf.length = dev->dummy_buf[i].length;
            buf.index = i;

            ret = ioctl(dev->fd, VIDIOC_QBUF, &buf);
            if (ret < 0) {
                printf("UVC: VIDIOC_QBUF failed : %s (%d).\n",
                       strerror(errno), errno);
                return ret;
            }

            dev->qbuf_count++;
        }
    }
#endif
    return 0;
}


static int uvc_video_qbuf(struct tof_uvc_device *dev)
{
    int ret = 0;

    switch (dev->io) {
    case IO_METHOD_MMAP:
        ret = uvc_video_qbuf_mmap(dev);
        break;

    case IO_METHOD_USERPTR:
        ret = uvc_video_qbuf_userptr(dev);
        break;

    default:
        ret = -EINVAL;
        break;
    }

    return ret;
}


static int uvc_video_reqbufs_mmap(struct tof_uvc_device *dev, int nbufs)
{
    struct v4l2_requestbuffers rb;
    unsigned int i;
    int ret;
    memset(&rb, 0, sizeof(rb));

    rb.count = nbufs;
    rb.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
    rb.memory = V4L2_MEMORY_MMAP;

    ret = ioctl(dev->fd, VIDIOC_REQBUFS, &rb);
    if (ret < 0) {
        if (ret == -EINVAL)
            printf("UVC: does not support memory mapping\n");
        else
            printf("UVC: Unable to allocate buffers: %s (%d).\n",
                   strerror(errno), errno);
        goto err;
    }

    if (!rb.count)
        return 0;

    if (rb.count < 2) {
        printf("UVC: Insufficient buffer memory.\n");
        ret = -EINVAL;
        goto err;
    }

    /* Map the buffers. */
    dev->mem = (struct buffer *)calloc(rb.count, sizeof dev->mem[0]);
    if (!dev->mem) {
        printf("UVC: Out of memory\n");
        ret = -ENOMEM;
        goto err;
    }

    for (i = 0; i < rb.count; ++i) {
        memset(&dev->mem[i].buf, 0, sizeof(dev->mem[i].buf));

        dev->mem[i].buf.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
        dev->mem[i].buf.memory = V4L2_MEMORY_MMAP;
        dev->mem[i].buf.index = i;

        ret = ioctl(dev->fd, VIDIOC_QUERYBUF, &(dev->mem[i].buf));
        if (ret < 0) {
            printf("UVC: VIDIOC_QUERYBUF failed for buf %d: "
                   "%s (%d).\n", i, strerror(errno), errno);
            ret = -EINVAL;
            goto err_free;
        }

        dev->mem[i].start = mmap(NULL /* start anywhere */,
                                 dev->mem[i].buf.length,
                                 PROT_READ | PROT_WRITE /* required */,
                                 MAP_SHARED /* recommended */,
                                 dev->fd, dev->mem[i].buf.m.offset);

        if (MAP_FAILED == dev->mem[i].start) {
            printf("UVC: Unable to map buffer %u: %s (%d).\n", i,
                   strerror(errno), errno);
            dev->mem[i].length = 0;
            ret = -EINVAL;
            goto err_free;
        }

        dev->mem[i].length = dev->mem[i].buf.length;
        printf("UVC: Buffer %u mapped at address %p.\n", i,
               dev->mem[i].start);
    }

    dev->nbufs = rb.count;
    printf("UVC: %u buffers allocated.\n", rb.count);

    return 0;

err_free:
    free(dev->mem);
err:
    return ret;
}


static int uvc_video_reqbufs_userptr(struct tof_uvc_device *dev, int nbufs)
{
    struct v4l2_requestbuffers rb;
    unsigned int i, j, bpl = 0, payload_size;
    int ret;
    memset(&rb, 0, sizeof(rb));

    rb.count = nbufs;
    rb.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
    rb.memory = V4L2_MEMORY_USERPTR;

    ret = ioctl(dev->fd, VIDIOC_REQBUFS, &rb);
    if (ret < 0) {
        if (ret == -EINVAL)
            printf("UVC: does not support user pointer i/o\n");
        else
            printf("UVC: VIDIOC_REQBUFS error %s (%d).\n",
                   strerror(errno), errno);
        goto err;
    }

    if (!rb.count)
        return 0;

    dev->nbufs = rb.count;
    printf("UVC: %u buffers allocated.\n", rb.count);
    
    return 0;

err:
    return ret;

}


static int uvc_video_reqbufs(struct tof_uvc_device *dev, int nbufs)
{
    int ret = 0;

    switch (dev->io) {
    case IO_METHOD_MMAP:
        ret = uvc_video_reqbufs_mmap(dev, nbufs);
        break;

    case IO_METHOD_USERPTR:
        ret = uvc_video_reqbufs_userptr(dev, nbufs);
        break;

    default:
        ret = -EINVAL;
        break;
    }

    return ret;
}


static int ob_tof_uvc_handle_streamon_event(struct tof_uvc_device *dev, int dev_index)
{
    int ret;

    ret = uvc_video_reqbufs(dev, dev->nbufs);
    if (ret < 0)
        goto err;

    /* Queue buffers to UVC domain and start streaming. */
    ret = uvc_video_qbuf(dev);
    if (ret < 0)
        goto err;

    uvc_video_stream(dev, dev_index, 1);
    dev->is_streaming = 1;
  
    return 0;

err:
    return ret;
}

int ob_tof_uvc_handle_streamoff_event(struct tof_uvc_device *dev, int dev_index)
{
    if (dev->is_streaming == 0)
    {
        WARN("device stream has been closed!\n");
        return 0;
    }

    dev->is_streaming = 0;   
    usleep(100*1000);
    uvc_video_stream(dev, dev_index, 0);
    uvc_uninit_device(dev);
    uvc_video_reqbufs(dev, 0);
        
    return 0;
}

void * memcpy_op2(void *dest, const void *src, size_t count)
{
	unsigned long *dl = (unsigned long *)dest, *sl = (unsigned long *)src;
	char *d8, *s8;

	if (src == dest)
		return dest;

	/* while all data is aligned (common case), copy a word at a time */
	if ( (((ulong)dest | (ulong)src) & (sizeof(*dl) - 1)) == 0) {
		while (count >= sizeof(*dl)) {
			*dl++ = *sl++;
			count -= sizeof(*dl);
		}
	}
	/* copy the reset one byte at a time */
	d8 = (char *)dl;
	s8 = (char *)sl;
	while (count--)
		*d8++ = *s8++;

	return dest;
}


static int uvc_video_fill_buffer(struct tof_uvc_device *dev, struct v4l2_buffer *buf, uint8_t *data, unsigned int len)
{
	if (buf->length >= len)
	{
        memcpy((uint8_t *)(dev->mem[buf->index].start), data, len);
		//memcpy_op2((uint8_t *)(dev->mem[buf->index].start), data, len);
		buf->bytesused = len;
	}
	else
	{
        WARN("buf->length:%d, len:%d\n", buf->length, len);
		buf->bytesused = buf->length;
	}

	return true;
}


/*****************************************************************************
*   Prototype    : ob_stop_uvc_by_frame_drop_thd
*   Description  : 检测连续丢帧进行主动停流, 适配插拔usb和第三方uvc播放器
*   Input        : void *arg  
*   Output       : None
*   Return Value : static void *
*   Calls        : 
*   Called By    : 
*****************************************************************************/
static void *ob_stop_uvc_by_frame_drop_thd(void *arg)
{
    struct tof_uvc_device *dev = (struct tof_uvc_device *)arg;

    DBG("[devID:%d] frame drop trigger ==> UVC_EVENT_STREAMOFF\n", dev->pService->dev_index);
    
    if (dev->pService->dev_index == OB_UVC_DEVICE_NODE_NUM_IR)
        ob_stream_off_op(TYPE_IR);
    else if(dev->pService->dev_index == OB_UVC_DEVICE_NODE_NUM_DEPTH)
        ob_stream_off_op(TYPE_DEPTH);
    else
        ERR("dev index:%d\n", dev->pService->dev_index);
    
    DBG("[devID:%d] frame drop trigger stop stream success!\n", dev->pService->dev_index);

    return NULL;
}


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
int uvc_video_send_process(struct tof_uvc_device *dev, void *data, unsigned int len, unsigned int pts)
{
    int ret = -1;
    fd_set fds;
    struct timeval tv;

    if (!dev->is_streaming)
        return -1;

    if (len == 0)
    {
        WARN("[devID:%d] uvc send buff len <= 0, len:%d\n", dev->pService->dev_index, len);
        return -2;
    }

    FD_ZERO(&fds);
    FD_SET(dev->fd, &fds);

    tv.tv_sec   = 0;
    tv.tv_usec  = 10000;

    ret = select(dev->fd + 1, NULL, &fds, NULL, &tv);
    if (ret > 0)
    {
        struct v4l2_buffer buf;
        memset(&buf, 0, sizeof buf);
        buf.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
        buf.memory = V4L2_MEMORY_MMAP;
        if ((ret = ioctl(dev->fd, VIDIOC_DQBUF, &buf)) < 0)
        {
            ERR("Unable to dequeue buffer: %s (%d).\n", strerror(errno), errno);
            return ret;
        }
        buf.timestamp.tv_usec = (pts % 1000) * 1000;
        buf.timestamp.tv_sec  = pts / 1000;
        uvc_video_fill_buffer(dev, &buf, (uint8_t *)data, len);

        if ((ret = ioctl(dev->fd, VIDIOC_QBUF, &buf)) < 0)
        {
            ERR("Unable to requeue buffer: %s (%d). \n", strerror(errno), errno);
            return ret;
        }

        dev->pService->u32FrameDropCount = 0;
    }
    else
    {
        /*
            由于uvc bulk传输模式, host关流没有event到应用,所以这里检测连续丢N帧后主动停流
        */
        dev->pService->u32FrameDropCount++;
        if (dev->pService->u32FrameDropCount == 20){
            start_new_thread("drop streamon thread", NULL, ob_stop_uvc_by_frame_drop_thd, (void *)dev);
        }

        ret = -1;
    }
    
    return ORBBEC_SUCCESS;
}



/*****************************************************************************
*   Prototype    : ob_tof_uvc_open
*   Description  : orbbec tof open uvc device
*   Input        : const char *devname  
*   Output       : None
*   Return Value : struct tof_uvc_device *
*****************************************************************************/
struct tof_uvc_device *ob_tof_uvc_open(const char *devname)
{
    struct tof_uvc_device *dev;
    struct v4l2_capability cap;
    int ret;
    int fd = -1;

    fd = open(devname, O_RDWR | O_NONBLOCK);
    if (fd < 0) {
        ERR("v4l2 open failed: %s (%d)\n", strerror(errno), errno);
        return NULL;
    }

    INFO("open %s succeeded, file descriptor = %d\n", devname, fd);

    ret = ioctl(fd, VIDIOC_QUERYCAP, &cap);
    if (ret < 0) {
        ERR("unable to query device: %s (%d)\n", strerror(errno),  errno);
        close(fd);
        return NULL;
    }

    printf("***********************Device info*********************\n");
    printf("device is %s on bus %s\n", cap.card, cap.bus_info);
    printf("device driver      : \t%s\n", cap.driver);
    printf("device card        : \t%s\n", cap.card);
    printf("device capabilities: \t0x%08x\n", cap.capabilities);
    printf("device device_caps : \t0x%08x\n", cap.device_caps);
    printf("*******************************************************\n");

    dev = (tof_uvc_device *)malloc(sizeof *dev);
    if (dev == NULL) {
        close(fd);
        return NULL;
    }
    memset(dev, 0, sizeof *dev);
    
    dev->fd = fd;

    return dev;
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_close
*   Description  : orbbec tof uvc device close
*   Input        : struct tof_uvc_device *dev  
*   Output       : None
*   Return Value : void
*****************************************************************************/
void ob_tof_uvc_close(struct tof_uvc_device *dev)
{
    if(dev)
    {
       close(dev->fd);
       //free(dev->imgdata);
       //free(dev->mem);
       free(dev);
    }
    pthread_mutex_destroy(&ob_ir_resolution_mutex);
    pthread_mutex_destroy(&ob_depth_resolution_mutex);
    pthread_mutex_destroy(&ob_stream_mutex);
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_video_stream
*   Description  : orbbec tof uvc video stream control
*   Input        : struct tof_uvc_device *dev  
*                  int enable                  
*   Output       : None
*   Return Value : static int
*****************************************************************************/
static int ob_tof_uvc_video_stream(struct tof_uvc_device *dev, int enable)
{
    struct v4l2_buffer buf;
    unsigned int i;
    int type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
    int ret = 0;
    tof_uvc_service *server_l = dev->pService;

    if (!enable) {
        INFO("Stopping video stream.\n");
        ioctl(dev->fd, VIDIOC_STREAMOFF, &type);
        server_l->g_stream_on = 0;
        return 0;
    }

    INFO("Starting video stream.\n");
    for (i = 0; i < dev->nbufs; ++i)
    {
        memset(&buf, 0, sizeof buf);

        buf.index = i;
        buf.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
        buf.memory = V4L2_MEMORY_USERPTR;//V4L2_MEMORY_MMAP;

        buf.length = TOF_UVC_MAX_BUFFER_SIZE;
        //memcpy(dev->mem[buf.index], first_image_data, first_image_size);
        buf.bytesused = server_l->first_image_size;
        buf.m.userptr = (uint32_t)server_l->first_image_data;

        //uvc_video_fill_buffer(dev, &buf);

        INFO("Queueing buffer %u.\n", i);
        if ((ret = ioctl(dev->fd, VIDIOC_QBUF, &buf)) < 0) 
        {
            ERR("Unable to queue buffer: %s (%d).\n", strerror(errno), errno);
            break;
        }
    }

    ioctl(dev->fd, VIDIOC_STREAMON, &type);
    server_l->g_stream_on = 1;
    
    return ret;
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_video_reqbufs
*   Description  : orbbec otf uvc video reqbufs
*   Input        : struct tof_uvc_device *dev  
*                  int nbufs                   
*   Output       : None
*   Return Value : static int
*****************************************************************************/
static int ob_tof_uvc_video_reqbufs(struct tof_uvc_device *dev, int nbufs)
{
    struct v4l2_requestbuffers rb;
    int ret;

    //for (i = 0; i < dev->nbufs; ++i)
    //    munmap(dev->mem[i], dev->bufsize);

    //free(dev->mem);
    //dev->mem = 0;
    dev->nbufs = 0;

    memset(&rb, 0, sizeof rb);
    rb.count = nbufs;
    rb.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
    rb.memory = V4L2_MEMORY_USERPTR;//V4L2_MEMORY_MMAP;

    ret = ioctl(dev->fd, VIDIOC_REQBUFS, &rb);
    if (ret < 0) {
        ERR("Unable to allocate buffers: %s (%d).\n", strerror(errno), errno);
        return ret;
    }

    DBG("%u buffers allocated.\n\n", rb.count);
    dev->nbufs = rb.count;

    return 0;
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_events_process_standard
*   Description  : orbbec tof uvc events process standard
*   Input        : struct tof_uvc_device *dev     
*                  struct usb_ctrlrequest *ctrl   
*                  struct uvc_request_data *resp  
*   Output       : None
*   Return Value : static void
*****************************************************************************/
static void ob_tof_uvc_events_process_standard(struct tof_uvc_device *dev, struct usb_ctrlrequest *ctrl,
                struct uvc_request_data *resp)
{
    //log_info("pid %d standard request\n", getpid());
    (void)dev;
    (void)ctrl;
    (void)resp;
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_events_process_control
*   Description  : orbbec tof uvc events process control
*   Input        : struct tof_uvc_device *dev     
*                  uint8_t req                    
*                  uint8_t cs                     
*                  uint8_t entity_id              
*                  uint8_t len                    
*                  struct uvc_request_data *resp  
*   Output       : None
*   Return Value : static void
*****************************************************************************/
//get
static void ob_tof_uvc_events_process_control(struct tof_uvc_device *dev, uint8_t req, 
                                                uint8_t cs, uint8_t entity_id,  
                                                uint8_t len, struct uvc_request_data *resp)
{
    dev->cs = cs;
    dev->entity_id = entity_id;
    unsigned int * p;
    unsigned short * p_s;
    tof_uvc_service *server_l = dev->pService;
    uint32_t ob_exposure = 0;
    uint32_t ob_gain = 0;

    //printf("xavier sl get: entity_id:%d, cs:0x%02x, req:0x%02x, len:0x%02x(%d)\n", entity_id, cs, req, len, len);

    switch (entity_id) 
    {
        case 0:
            switch (cs) 
            {
                case UVC_VC_REQUEST_ERROR_CODE_CONTROL:
                    /* Send the request error code last prepared. */
                    resp->data[0] = dev->request_error_code.data[0];
                    resp->length = dev->request_error_code.length;
                    break;

                default:
                    /*
                     * If we were not supposed to handle this
                     * 'cs', prepare an error code response.
                     */
                    dev->request_error_code.data[0] = 0x06;
                    dev->request_error_code.length = 1;
                    break;
            }
            break;

        /* Camera terminal unit 'UVC_VC_INPUT_TERMINAL'. */
        case 1:
            switch (cs) 
            {
                case UVC_CT_AE_MODE_CONTROL:
                    switch (req){
                        case UVC_SET_CUR:
                            /* Incase of auto exposure, attempts to
                             * programmatically set the auto-adjusted
                             * controls are ignored.
                             */
                            resp->data[0] = 0x01;
                            resp->length = len;
                            /*
                             * For every successfully handled control
                             * request set the request error code to no
                             * error.
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;

                        case UVC_GET_INFO:
                            /*
                             * TODO: We support Set and Get requests, but
                             * don't support async updates on an video
                             * status (interrupt) endpoint as of
                             * now.
                             */
                            resp->data[0] = 0x03;
                            resp->length = 1;
                            /*
                             * For every successfully handled control
                             * request set the request error code to no
                             * error.
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;

                        case UVC_GET_CUR:
                            resp->length = 1;
                            resp->data[0] = 0x01;

                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;

                        case UVC_GET_DEF:
                            resp->data[0] = CT_AUTO_EXPOSURE_MODE_DEFAULF_VAL;//0x02;
                            resp->length = 1;
                            /*
                             * For every successfully handled control
                             * request set the request error code to no
                             * error.
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;

                        case UVC_GET_RES:
                            /* Auto Mode and auto Exposure Time, auto Iris. */
                            resp->data[0] = CT_AUTO_EXPOSURE_MODE_RES;//0x02;
                            resp->length = 1;
                            /*
                             * For every successfully handled control
                             * request set the request error code to no
                             * error.
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;

                        default:
                            /*
                             * We don't support this control, so STALL the
                             * control ep.
                             */
                            resp->length = -EL2HLT;
                            /*
                             * For every unsupported control request
                             * set the request error code to appropriate
                             * value.
                             */
                            dev->request_error_code.data[0] = 0x07;
                            dev->request_error_code.length = 1;
                            break;
                        }
                    break;

                case UVC_CT_EXPOSURE_TIME_ABSOLUTE_CONTROL:
                    switch (req){
                        case UVC_SET_CUR:
                            resp->data[0] = 0x0;
                            resp->length = len;
                            /*
                             * For every successfully handled control
                             * request set the request error code to no
                             * error
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;

                        case UVC_GET_INFO:
                            resp->data[0] = 0x03;
                            resp->length = 1;

                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;

                        case UVC_GET_MIN:
                            p = (unsigned int *)resp->data;
                            *p = 310;
                            resp->length = 4;

                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;

                        case UVC_GET_MAX:
                            p = (unsigned int *)resp->data;
                            *p = 10000;
                            resp->length = 4;

                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;

                        case UVC_GET_CUR:
                            resp->length = 4;
                            Mx6300_get_ir_exposure(&ob_exposure);
                            p = (unsigned int *)resp->data;
                            *p = (((ob_exposure * 1514) - 180) / 48) / 100;
                            DBG("get ir exposure:%d\n", *p);
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;

                        case UVC_GET_DEF:
                            p = (unsigned int *)resp->data;
                            //ar_cam_get_3a_info(dev->camera_fd, &info);
                            //dev->camera_terminal.auto_exposure_aec_info = info.aec_info;
                            *p = CT_EXPOSURE_TIME_ABSOLUTE_MIN_VAL;
                            resp->length = 4;

                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;

                        case UVC_GET_RES:
                            resp->data[0] = CT_EXPOSURE_TIME_ABSOLUTE_STEP_SIZE;
                            resp->length = len;

                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;

                        default:
                            /*
                             * We don't support this control, so STALL the
                             * control ep.
                             */
                            resp->length = -EL2HLT;
                            /*
                             * For every unsupported control request
                             * set the request error code to appropriate
                             * value.
                             */
                            dev->request_error_code.data[0] = 0x07;
                            dev->request_error_code.length = 1;
                            break;
                        }
                    break;
#if 0
            case UVC_CT_IRIS_ABSOLUTE_CONTROL:
                switch (req) {
                case UVC_GET_INFO:
                case UVC_GET_CUR:
                case UVC_GET_MIN:
                case UVC_GET_MAX:
                case UVC_GET_DEF:
                case UVC_GET_RES:
                    resp->data[0] = 10;
                    resp->length = len;

                    dev->request_error_code.data[0] = 0x00;
                    dev->request_error_code.length = 1;
                    break;
                default:
                    /*
                     * We don't support this control, so STALL the
                     * control ep.
                     */
                    resp->length = -EL2HLT;
                    /*
                     * For every unsupported control request
                     * set the request error code to appropriate
                     * value.
                     */
                    dev->request_error_code.data[0] = 0x07;
                    dev->request_error_code.length = 1;
                }
                break;
#endif
            }
            break;

        /* processing unit 'UVC_VC_PROCESSING_UNIT' */
        case 2:
            switch (cs) 
            {
                /*
                 * We support only 'UVC_PU_BRIGHTNESS_CONTROL' for Processing
                 * Unit, as our bmControls[0] = 1 for PU.
                 */        
                case UVC_PU_GAIN_CONTROL:
                    switch (req) {
                        case UVC_SET_CUR:
                            resp->data[0] = 0x0;
                            resp->length = len;
                            /*
                             * For every successfully handled control
                             * request set the request error code to no
                             * error
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;
                        case UVC_GET_MIN:
                            p = (unsigned int *)resp->data;
                            *p = 1000;
                            resp->length = 4;
                            /*
                             * For every successfully handled control
                             * request set the request error code to no
                             * error
                             */
                            dev->request_error_code.data[0] = 0;
                            dev->request_error_code.length = 1;
                            break;
                        case UVC_GET_MAX:
                            p = (unsigned int *)resp->data;
                            *p = 15000;
                            resp->length = 4;
                            /*
                             * For every successfully handled control
                             * request set the request error code to no
                             * error
                             */
                            dev->request_error_code.data[0] = 1000;
                            dev->request_error_code.length = 1;
                            break;
                        case UVC_GET_CUR:
                            Mx6300_get_ir_gain(&ob_gain);
                            p = (unsigned int *)resp->data;
                            *p = ob_gain;
                            DBG("get ir gain:%d\n", ob_gain);
                            resp->length = 4;
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;
                        case UVC_GET_INFO:
                            /*
                             * We support Set and Get requests and don't
                             * support async updates on an interrupt endpt
                             */
                            resp->data[0] = 0x03;
                            resp->length = 1;
                            /*
                             * For every successfully handled control
                             * request, set the request error code to no
                             * error.
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;
                        case UVC_GET_DEF:
                            *p = 8000;
                            p = (unsigned int *)resp->data;  
                            resp->length = 2;
                            /*
                             * For every successfully handled control
                             * request, set the request error code to no
                             * error.
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;
                        case UVC_GET_RES:
                            resp->data[0] = PU_BRIGHTNESS_STEP_SIZE;
                            resp->length = 2;
                            /*
                             * For every successfully handled control
                             * request, set the request error code to no
                             * error.
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;
                        default:
                            /*
                             * We don't support this control, so STALL the
                             * default control ep.
                             */
                            resp->length = -EL2HLT;
                            /*
                             * For every unsupported control request
                             * set the request error code to appropriate
                             * code.
                             */
                            dev->request_error_code.data[0] = 0x07;
                            dev->request_error_code.length = 1;
                            break;
                        }
                    break;
#if 0
                case UVC_PU_BRIGHTNESS_CONTROL:
                    switch (req) {
                        case UVC_SET_CUR:
                            resp->data[0] = 0x0;
                            resp->length = len;
                            /*
                             * For every successfully handled control
                             * request set the request error code to no
                             * error
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;
                        case UVC_GET_MIN:
                            resp->data[0] = PU_BRIGHTNESS_MIN_VAL;
                            resp->length = 2;
                            /*
                             * For every successfully handled control
                             * request set the request error code to no
                             * error
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;
                        case UVC_GET_MAX:
                            resp->data[0] = PU_BRIGHTNESS_MAX_VAL;
                            resp->length = 2;
                            /*
                             * For every successfully handled control
                             * request set the request error code to no
                             * error
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;
                        case UVC_GET_CUR:
                            resp->length = 2;
                            memcpy(&resp->data[0], &dev->brightness_val, resp->length);
                            /*
                             * For every successfully handled control
                             * request set the request error code to no
                             * error
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;
                        case UVC_GET_INFO:
                            /*
                             * We support Set and Get requests and don't
                             * support async updates on an interrupt endpt
                             */
                            resp->data[0] = 0x03;
                            resp->length = 1;
                            /*
                             * For every successfully handled control
                             * request, set the request error code to no
                             * error.
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;
                        case UVC_GET_DEF:
                            resp->data[0] = PU_BRIGHTNESS_DEFAULT_VAL;
                            resp->length = 2;
                            /*
                             * For every successfully handled control
                             * request, set the request error code to no
                             * error.
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;
                        case UVC_GET_RES:
                            resp->data[0] = PU_BRIGHTNESS_STEP_SIZE;
                            resp->length = 2;
                            /*
                             * For every successfully handled control
                             * request, set the request error code to no
                             * error.
                             */
                            dev->request_error_code.data[0] = 0x00;
                            dev->request_error_code.length = 1;
                            break;
                        default:
                            /*
                             * We don't support this control, so STALL the
                             * default control ep.
                             */
                            resp->length = -EL2HLT;
                            /*
                             * For every unsupported control request
                             * set the request error code to appropriate
                             * code.
                             */
                            dev->request_error_code.data[0] = 0x07;
                            dev->request_error_code.length = 1;
                            break;
                        }
                    break;
#endif
                default:
                /*
                 * We don't support this control, so STALL the control
                 * ep.
                 */
                resp->length = -EL2HLT;
                /*
                 * If we were not supposed to handle this
                 * 'cs', prepare a Request Error Code response.
                 */
                dev->request_error_code.data[0] = 0x06;
                dev->request_error_code.length = 1;
                break;
            }

            break;

        default:
            /*
             * If we were not supposed to handle this
             * 'cs', prepare a Request Error Code response.
             */
            dev->request_error_code.data[0] = 0x06;
            dev->request_error_code.length = 1;
            break;
    }
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_fill_streaming_control
*   Description  : fill stream control context
*   Input        : struct tof_uvc_device *dev          
*                  struct uvc_streaming_control *ctrl  
*                  int iframe                          
*                  int iformat                         
*   Output       : None
*   Return Value : static void
*****************************************************************************/
static void ob_tof_uvc_fill_streaming_control(struct tof_uvc_device *dev,
              struct uvc_streaming_control *ctrl,
              int iframe, int iformat)
{
    struct uvc_format_info *format;
    struct uvc_frame_info *frame;
    unsigned int nframes;
    tof_uvc_service *server_l = dev->pService;

    if (iformat < 0)
        iformat = dev->pService->uvc_formats_num + iformat;
    if (iformat < 0 || iformat >= (int)dev->pService->uvc_formats_num)
        return;

    format = &dev->pService->uvc_formats[iformat];

    nframes = 0;
    while (format->frames[nframes].width != 0)
        ++nframes;

    if (iframe < 0)
        iframe = nframes + iframe;
    if (iframe < 0 || iframe >= (int)nframes)
        return;
    frame = &format->frames[iframe];

    memset(ctrl, 0, sizeof *ctrl);

    ctrl->bmHint = 1;
    ctrl->bFormatIndex = iformat + 1;
    ctrl->bFrameIndex = iframe + 1;
    ctrl->dwFrameInterval = frame->intervals[0];
    switch (format->fcc) 
    {
        case V4L2_PIX_FMT_YUYV:
            ctrl->dwMaxVideoFrameSize = frame->width * frame->height * 2;
            break;
        case V4L2_PIX_FMT_NV12:
            ctrl->dwMaxVideoFrameSize = frame->width * frame->height * 3 / 2;
            break;
        case V4L2_PIX_FMT_MJPEG:
        case V4L2_PIX_FMT_H264:
        case V4L2_PIX_FMT_HEVC:
            ctrl->dwMaxVideoFrameSize = TOF_UVC_MAX_BUFFER_SIZE * 3;//dev->imgsize * 3;
            break;
    }
    //ctrl->dwMaxPayloadTransferSize = getMaxPayloadTransferSize(server_l->dev_index);
    if(dev->bulk)
    {
        ctrl->dwMaxPayloadTransferSize = getMaxPayloadTransferSizeBulk(server_l->dev_index);
    }
    else
    {
        if(getConfigfsbcdUSB() >= USB_30_VALUE)
        {
            ctrl->dwMaxPayloadTransferSize = (getTransferMaxburst(server_l->dev_index) + 1) *
                                            getMaxPayloadTransferSize(server_l->dev_index);
        }
        else if(getConfigfsbcdUSB() >= USB_20_VALUE)
        {
            ctrl->dwMaxPayloadTransferSize = getMaxPayloadTransferSize(server_l->dev_index);
        }
        else
        {
            ctrl->dwMaxPayloadTransferSize = 1023;
        }
    }

    ctrl->bmFramingInfo = 3;
    ctrl->bPreferedVersion = 1;
    ctrl->bMaxVersion = 1;
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_events_process_streaming
*   Description  : orbbec tof uvc event s process streaming
*   Input        : struct tof_uvc_device *dev     
*                  uint8_t req                    
*                  uint8_t cs                     
*                  struct uvc_request_data *resp  
*   Output       : None
*   Return Value : static void
*****************************************************************************/
static void ob_tof_uvc_events_process_streaming(struct tof_uvc_device *dev, uint8_t req, uint8_t cs,
                struct uvc_request_data *resp)
{
    struct uvc_streaming_control *ctrl;

    // DBG("pid %d streaming request (req %02x cs %02x)\n", getpid(), req, cs);

    if (cs != UVC_VS_PROBE_CONTROL && cs != UVC_VS_COMMIT_CONTROL)
        return;

    ctrl = (struct uvc_streaming_control *)&resp->data;
    resp->length = sizeof *ctrl;

    switch (req) 
    {
        case UVC_SET_CUR:
            dev->control = cs;
            resp->length = 34;
            break;

        case UVC_GET_CUR:
            if (cs == UVC_VS_PROBE_CONTROL)
               memcpy(ctrl, &dev->probe, sizeof *ctrl);
            else
               memcpy(ctrl, &dev->commit, sizeof *ctrl);
            break;

        case UVC_GET_MIN:
        case UVC_GET_MAX:
        case UVC_GET_DEF:
            ob_tof_uvc_fill_streaming_control(dev, ctrl, req == UVC_GET_MAX ? -1 : 0,
                          req == UVC_GET_MAX ? -1 : 0);
            break;

        case UVC_GET_RES:
            memset(ctrl, 0, sizeof *ctrl);
            break;

        case UVC_GET_LEN:
            resp->data[0] = 0x00;
            resp->data[1] = 0x22;
            resp->length = 2;
            break;

        case UVC_GET_INFO:
            resp->data[0] = 0x03;
            resp->length = 1;
            break;
    }
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_events_process_class
*   Description  : orbbec tof uvc events process class
*   Input        : struct tof_uvc_device *dev     
*                  struct usb_ctrlrequest *ctrl   
*                  struct uvc_request_data *resp  
*   Output       : None
*   Return Value : static void
*****************************************************************************/
static void ob_tof_uvc_events_process_class(struct tof_uvc_device *dev, struct usb_ctrlrequest *ctrl,
             struct uvc_request_data *resp)
{
    if ((ctrl->bRequestType & USB_RECIP_MASK) != USB_RECIP_INTERFACE)
        return;

    if ((ctrl->wIndex & 0xff) == dev->control_interface)
    {
        ob_tof_uvc_events_process_control(dev, ctrl->bRequest, 
                                    ctrl->wValue >> 8, 
                                    ctrl->wIndex >> 8, 
                                    ctrl->wLength, resp);
    }
    else if ((ctrl->wIndex & 0xff) == dev->streaming_interface)
    {
        ob_tof_uvc_events_process_streaming(dev, 
                                     ctrl->bRequest, 
                                     ctrl->wValue >> 8, 
                                     resp);
    }
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_events_process_setup
*   Description  : process setup
*   Input        : struct tof_uvc_device *dev     
*                  struct usb_ctrlrequest *ctrl   
*                  struct uvc_request_data *resp  
*   Output       : None
*   Return Value : static void
*****************************************************************************/
static void ob_tof_uvc_events_process_setup(struct tof_uvc_device *dev, struct usb_ctrlrequest *ctrl,
             struct uvc_request_data *resp)
{
    dev->control = 0;

    // printf("pid %d bRequestType %02x bRequest %02x wValue %04x wIndex %04x "
    //    "wLength %04x\n",getpid(), ctrl->bRequestType, ctrl->bRequest,
    //   ctrl->wValue, ctrl->wIndex, ctrl->wLength);

    switch (ctrl->bRequestType & USB_TYPE_MASK)
    {
        case USB_TYPE_STANDARD:
            ob_tof_uvc_events_process_standard(dev, ctrl, resp);
            break;

        case USB_TYPE_CLASS:
            ob_tof_uvc_events_process_class(dev, ctrl, resp);
            break;

        default:
            break;
    }
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_events_process_control_data
*   Description  : orbbec tof uvc event process control data
*   Input        : struct tof_uvc_device *dev     
*                  uint8_t cs                     
*                  uint8_t entity_id              
*                  struct uvc_request_data *data  
*   Output       : None
*   Return Value : static int
*****************************************************************************/
//set
static int ob_tof_uvc_events_process_control_data(struct tof_uvc_device *dev, uint8_t cs,
                                                 uint8_t entity_id, struct uvc_request_data *data)
{
    int ret;
    tof_uvc_service *server_l = dev->pService;

    unsigned int *val = (unsigned int *)data->data;
    //printf("xavier sl set, entity_id:%d, cs:0x%02x, data:%d, length:%d\n", entity_id, cs, *val, data->length);

    if(0 == server_l->run_flag)
    {
        ERR("uvc service is not run!\n");
        return -1;
    }

    switch (entity_id) 
    {
        case 1:
        {
            switch (cs)
            {
                case UVC_CT_AE_MODE_CONTROL:                    
                    break;

                case UVC_CT_EXPOSURE_TIME_ABSOLUTE_CONTROL:
                    *val = (((*val) * 100 * 48) + 180) / 1514;
                    Mx6300_set_ir_exposure(*val);
                    DBG("set ir exposure:%d\n", *val);
                    break;

                case UVC_CT_ZOOM_ABSOLUTE_CONTROL:
                    break;

                case UVC_CT_ROLL_ABSOLUTE_CONTROL:
                    break;

                default:
                    break;
            }
            break;
        }
        
        case 2:
        {
            switch (cs)
            {
                case UVC_PU_BRIGHTNESS_CONTROL:
                    break;

                case UVC_PU_CONTRAST_CONTROL:
                    break;

                case UVC_PU_HUE_CONTROL:
                    break;

                case UVC_PU_SATURATION_CONTROL:
                    break;

                case UVC_PU_SHARPNESS_CONTROL:
                    break;

                case UVC_PU_GAMMA_CONTROL:
                    break;

                case UVC_PU_WHITE_BALANCE_TEMPERATURE_CONTROL:
                    break;

                case UVC_PU_BACKLIGHT_COMPENSATION_CONTROL:
                    break;

                case UVC_PU_GAIN_CONTROL:
                    Mx6300_set_ir_gain(*val);
                    DBG("set ir gain:%d\n", *val);
                    break;

                case UVC_PU_POWER_LINE_FREQUENCY_CONTROL:
                    break;

                case UVC_PU_HUE_AUTO_CONTROL:
                    break;

                case UVC_PU_WHITE_BALANCE_TEMPERATURE_AUTO_CONTROL:
                    break;

                default:
                    break;
            }
            break;
        }

        default:
            break;
    }

    return 0;
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_video_set_format
*   Description  : orbbec tof uvc video set fmt
*   Input        : struct tof_uvc_device *dev  
*   Output       : None
*   Return Value : int
*****************************************************************************/
int ob_tof_uvc_video_set_format(struct tof_uvc_device *dev, int dev_index)
{
    struct v4l2_format fmt;
    int ret = 0;
    char *p = (char *)&dev->fcc;
    float img_fps = dev->frame_interval;

    // INFO("Setting format to 0x%08x(%c%c%c%c) %ux%u\n", dev->fcc, p[0], p[1], p[2], p[3], dev->width, dev->height);

    memset(&fmt, 0, sizeof fmt);
    
    fmt.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
    fmt.fmt.pix.width = dev->width;
    fmt.fmt.pix.height = dev->height;
    fmt.fmt.pix.pixelformat = dev->fcc;
    fmt.fmt.pix.field = V4L2_FIELD_NONE;

    Depth2Color_pixFormat pixFormat;
    
    if (dev->fcc == V4L2_PIX_FMT_MJPEG)
        fmt.fmt.pix.sizeimage = TOF_UVC_MAX_BUFFER_SIZE;
    if(dev->fcc == V4L2_PIX_FMT_YUYV)
    {
        fmt.fmt.pix.sizeimage = dev->width * dev->height * 2;        
        switch (dev_index)
        {
            case OB_UVC_DEVICE_NODE_NUM_DEPTH:
                img_fps = 1 / (img_fps / pow(10,7));
                ob_streamControl.frameRate = (uint8_t)img_fps;
                if ((dev->width == 960) && (dev->height == 1280))
                {
                    //input:1024*1280; output:960*1280
                    ob_streamControl.cameraSwitchType = STREAM_TYPE_DEPTH_960_1280;
                    ob_streamControl.depth_inputImage_width = 960;
                    ob_streamControl.depth_inputImage_height = dev->height;
                    // INFO("set depth resolution 960*1280\n");
                    if (ob_streamControl.depthSoftD2C_enable)
                    {
                        pixFormat.color_width = 960;
                        pixFormat.color_height = 1280;
                        pixFormat.depth_width = 960;
                        pixFormat.depth_height = 1280;
                    }
                }
                else if ((dev->width == 720) && (dev->height == 1280))
                {
                    //input:512*640; output:720*1280
                    ob_streamControl.cameraSwitchType = STREAM_TYPE_DEPTH_720_1280;
                    ob_streamControl.depth_inputImage_width = 960;
                    ob_streamControl.depth_inputImage_height = dev->height;
                    // INFO("set depth resolution 720*1280\n");
                    if (ob_streamControl.depthSoftD2C_enable)
                    {
                        pixFormat.color_width = 720;
                        pixFormat.color_height = 1280;
                        pixFormat.depth_width = 960;
                        pixFormat.depth_height = 1280;
                    }
                }
                else if ((dev->width == 480) && (dev->height == 640))
                {
                    //input:512*640; output:480*640
                    ob_streamControl.cameraSwitchType = STREAM_TYPE_DEPTH_480_640;
                    ob_streamControl.depth_inputImage_width = dev->width;
                    ob_streamControl.depth_inputImage_height = dev->height;
                    // INFO("set depth resolution 480*640\n");
                    if (ob_streamControl.depthSoftD2C_enable)
                    {
                        pixFormat.color_width = 480;
                        pixFormat.color_height = 640;
                        pixFormat.depth_width = 480;
                        pixFormat.depth_height = 640;
                    }
                }
                else
                {
                    ERR("Not support depth resolution width:%d,height:%d\n", dev->width, dev->height);
                    break;
                }

                pthread_mutex_lock(&ob_depth_resolution_mutex);    
                ob_streamControl.depth_ouputImage_width = dev->width;
                ob_streamControl.depth_ouputImage_height = dev->height;
                pthread_mutex_unlock(&ob_depth_resolution_mutex);
                break;
                
            case OB_UVC_DEVICE_NODE_NUM_IR:
                img_fps = 1 / (img_fps / pow(10,7));
                ob_streamControl.frameRate = (uint8_t)img_fps;
                if ((dev->width == 1280) && (dev->height == 960))
                {
                    ob_streamControl.cameraSwitchType = STREAM_TYPE_IR_1280_960;
                    // INFO("set ir resolution 1280*1024\n");
                }
                else
                {
                    ERR("Not support ir resolution width:%d,height:%d\n", dev->width, dev->height);
                    break;
                }
                pthread_mutex_lock(&ob_ir_resolution_mutex);
                ob_streamControl.irImage_width = dev->width;
                ob_streamControl.irImage_height = dev->height;
                pthread_mutex_unlock(&ob_ir_resolution_mutex);
                break;            
            default:
                break;
        }        
    }
        
    if(dev->fcc == V4L2_PIX_FMT_NV12)
        fmt.fmt.pix.sizeimage = dev->width * dev->height * 3 / 2;
    if (dev->fcc == V4L2_PIX_FMT_H264)
        fmt.fmt.pix.sizeimage = TOF_UVC_MAX_BUFFER_SIZE;
    if (dev->fcc == V4L2_PIX_FMT_HEVC)
        fmt.fmt.pix.sizeimage = TOF_UVC_MAX_BUFFER_SIZE;
        
    if ((ret = ioctl(dev->fd, VIDIOC_S_FMT, &fmt)) < 0)
    {
        ERR("Unable to set format: %s (%d).\n", strerror(errno), errno);
    }

    if (ob_streamControl.depthSoftD2C_enable)
    {
        ob_dsp_loadParam(pixFormat);
    }
    return ret;
}

/*****************************************************************************
*   Prototype    : ob_tof_uvc_events_process_data
*   Description  : orbbec tof uvc event procss data api
*   Input        : struct tof_uvc_device *dev     
*                  struct uvc_request_data *data  
*   Output       : None
*   Return Value : static void
*****************************************************************************/
static void ob_tof_uvc_events_process_data(struct tof_uvc_device *dev, struct uvc_request_data *data, int dev_index)
{
    struct uvc_streaming_control *target;
    struct uvc_streaming_control *ctrl;
    struct uvc_format_info *format;  //帧格式
    struct uvc_frame_info *frame;    //帧格式对应的分辨率
    unsigned int iformat;   //format index 从1开始
    unsigned int iframe;    //分辨率 index 从1开始
    unsigned int nframes;   //帧格式支持的分辨率个数
    tof_uvc_service *pService = dev->pService;


    switch (dev->control) 
     {
        case UVC_VS_PROBE_CONTROL:
            INFO("setting probe control, length = %d\n", data->length);
            target = &dev->probe;
            break;

        case UVC_VS_COMMIT_CONTROL:
            INFO("setting commit control, length = %d\n", data->length);
            target = &dev->commit;
            break;

        default:
            //log_info("setting unknown control, length = %d\n", data->length);
            //printf("cs: %u, entity_id: %u\n", dev->cs, dev->entity_id);
            ob_tof_uvc_events_process_control_data(dev,
                                         dev->cs,
                                         dev->entity_id,
                                         data);

         return;
    }

    ctrl = (struct uvc_streaming_control *)&data->data;

    if(dev->control == UVC_VS_COMMIT_CONTROL && (0 == data->length || 0 == ctrl->dwFrameInterval))
    {
        ERR("uvc event data error !!!\n");
        return;
    }


    /* host端对device设置uvc数据格式和分辨率信息*/
    
    INFO("bFormatIndex:%d, bFrameIndex:%d, dwFrameInterval:%d\n", ctrl->bFormatIndex, ctrl->bFrameIndex, ctrl->dwFrameInterval);


    //[1] 获取当前host下发指定的帧格式信息
    iformat = clamp((unsigned int)ctrl->bFormatIndex, 1U, (unsigned int)pService->uvc_formats_num);
    format = &pService->uvc_formats[iformat - 1]; //获取帧格式

    //计算帧格式对应支持的分辨率个数
    nframes = 0;
    while (format->frames[nframes].width != 0)
        ++nframes;

    //[2] 获取当前host下发指定的帧格式对应指定的分辨率
    iframe = clamp((unsigned int)ctrl->bFrameIndex, 1U, nframes);
    frame = &format->frames[iframe-1];

    target->bFormatIndex = iformat; //帧格式索引
    target->bFrameIndex = iframe;   //分辨率索引

    char *p = (char *)&(format->fcc);
    INFO("format: %c%c%c%c (%d*%d)\n\n", p[0], p[1], p[2], p[3], frame->width, frame->height);
 
    switch (format->fcc) 
    {
        case V4L2_PIX_FMT_YUYV:
            target->dwMaxVideoFrameSize = frame->width * frame->height * 2;
            break;
        case V4L2_PIX_FMT_NV12:
            target->dwMaxVideoFrameSize = frame->width * frame->height * 3 / 2;
            break;
        case V4L2_PIX_FMT_MJPEG:
            if (dev->imgsize == 0)
                WARN("WARNING: MJPEG requested and no image loaded.\n");
            target->dwMaxVideoFrameSize = TOF_UVC_MAX_BUFFER_SIZE;
            break;
        case V4L2_PIX_FMT_H264:
            if (dev->imgsize == 0)
                WARN("WARNING: H264 requested and no image loaded.\n");
            target->dwMaxVideoFrameSize = TOF_UVC_MAX_BUFFER_SIZE;
            break;
        case V4L2_PIX_FMT_HEVC:
            if (dev->imgsize == 0)
                WARN("WARNING: h265 requested and no image loaded.\n");
            target->dwMaxVideoFrameSize = TOF_UVC_MAX_BUFFER_SIZE;
            break;
    }
    target->dwFrameInterval = ctrl->dwFrameInterval;

    if (dev->control == UVC_VS_COMMIT_CONTROL) 
    {
        if (dev->width != frame->width || dev->height != frame->height || \
            dev->frame_interval != target->dwFrameInterval || \
            (dev->fcc != format->fcc || V4L2_PIX_FMT_H264 == dev->fcc || V4L2_PIX_FMT_HEVC == dev->fcc)) 
        {
            DBG("[devID:%d] xavier, uvc host set new Format\n\n", pService->dev_index);
            dev->width          = frame->width;
            dev->height         = frame->height;
            dev->frame_interval = target->dwFrameInterval;
            dev->new_fcc        = format->fcc;
        }
           
        if (dev->bulk)
        {
            //开流之前强制尝试关闭所有流(ir and depth)
            DBG("stop last stream first!\n");
            ob_stream_off_op(TYPE_DEPTH);
            ob_stream_off_op(TYPE_IR);
            DBG("stop last stream success!\n");
        }           

        ob_tof_uvc_video_set_format(dev, dev_index);
        
        if (dev->bulk)
        {         
            INFO("[devID:%d] xavier, bulk mode: uvc stream on\n", dev_index);

            //开流
            DBG("[devID:%d] host start stream\n", dev_index);
            if (dev_index == OB_UVC_DEVICE_NODE_NUM_DEPTH)
                ob_stream_on_op(TYPE_DEPTH);
            else if (dev_index == OB_UVC_DEVICE_NODE_NUM_IR)
                ob_stream_on_op(TYPE_IR);
            else

                ERR("dev_index:%d, error\n", dev_index);
            DBG("[devID:%d] host start stream success!\n", dev_index);
        }
    }

    return;
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_events_process
*   Description  : tof uvc event process
*   Input        : struct tof_uvc_device *dev  
*   Output       : None
*   Return Value : void
*****************************************************************************/
void ob_tof_uvc_events_process(struct tof_uvc_device *dev, int dev_index)
{
    struct v4l2_event v4l2_event;
    struct uvc_event *uvc_event = (struct uvc_event *)&v4l2_event.u.data;
    struct uvc_request_data resp;
    int ret;
    tof_uvc_service *server_l  = dev->pService;

    ret = ioctl(dev->fd, VIDIOC_DQEVENT, &v4l2_event);
    if (ret < 0) 
    {
        ERR("VIDIOC_DQEVENT failed: %s (%d)\n", strerror(errno), errno);
        return;
    }

    memset(&resp, 0, sizeof resp);
    resp.length = -EL2HLT;

    switch (v4l2_event.type) 
    {
        case UVC_EVENT_CONNECT:
            //check usb version, when connect usb
            if(getConfigfsbcdUSB() >= USB_30_VALUE)
                dev->emVerUSB = USB_VER_3_0;
            else if(getConfigfsbcdUSB() >= USB_20_VALUE)
                dev->emVerUSB = USB_VER_2_0;
            else
                dev->emVerUSB = USB_VER_2_0;
	        INFO("[devID:%d] connect! usb version:%s\n", server_l->dev_index, (USB_VER_3_0 == dev->emVerUSB) ? "usb3.0":"usb2.0");
            
	        if (dev->bulk)
	        {
                dev->probe.dwMaxPayloadTransferSize = getMaxPayloadTransferSizeBulk(server_l->dev_index);
                dev->commit.dwMaxPayloadTransferSize = getMaxPayloadTransferSizeBulk(server_l->dev_index);
	        }
            return;
        
        case UVC_EVENT_DISCONNECT:
            //ob_tof_uvc_video_stream(dev, 0);
            //ob_tof_uvc_video_reqbufs(dev, 0);
            if (server_l->dev_index == OB_UVC_DEVICE_NODE_NUM_IR)
                ob_stream_off_op(TYPE_IR);
            else if(server_l->dev_index == OB_UVC_DEVICE_NODE_NUM_DEPTH)
                ob_stream_off_op(TYPE_DEPTH);
            else
                ERR("dev_index:%d\n", server_l->dev_index);

            INFO("[devID:%d] disconnect!\n", server_l->dev_index);
            return;

        case UVC_EVENT_SETUP:
            ob_tof_uvc_events_process_setup(dev, &uvc_event->req, &resp); //get
            break;

        case UVC_EVENT_DATA:
            ob_tof_uvc_events_process_data(dev, &uvc_event->data, dev_index); //set
            return;

        case UVC_EVENT_STREAMON:
            DBG("UVC_EVENT_STREAMON\n");
            //ob_tof_uvc_video_reqbufs(dev, UVC_SEND_QUEUE_SIZE);
            //ob_tof_uvc_video_stream(dev, 1);
            if (dev->bulk)
            {
                uvc_server_t *server_l = get_uvc_server();
                if (server_l->g_stream_on)
                {
                    return;
                }
            }
            ob_tof_uvc_handle_streamon_event(dev, dev_index);
            return;

        case UVC_EVENT_STREAMOFF:
            DBG("UVC_EVENT_STREAMOFF\n");
            //ob_tof_uvc_video_stream(dev, 0);
            //ob_tof_uvc_video_reqbufs(dev, 0);
            if (dev->is_streaming)
            {
                dev->is_streaming = 0;
                uvc_video_stream(dev, dev_index, 0);
                uvc_uninit_device(dev);
                uvc_video_reqbufs(dev, 0);
            }
            return;

        default:
            ERR("error tyep:%d\n", v4l2_event.type);
            break;
    }

    ioctl(dev->fd, UVCIOC_SEND_RESPONSE, &resp);
    if (ret < 0) 
    {
        ERR("UVCIOC_S_EVENT failed: %s (%d)\n", strerror(errno), errno);
        return;
    }
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_video_fill_buffer
*   Description  : uvc 发送 buff填充
*   Input        : struct tof_uvc_device *dev  
*                  struct v4l2_buffer *buf     
*   Output       : None
*   Return Value : static void
*   Calls        : 
*   Called By    : 
*****************************************************************************/
//Deprecated, 此接口已废弃不在使用
static void ob_tof_uvc_video_fill_buffer(struct tof_uvc_device *dev, struct v4l2_buffer *buf)
{
    unsigned int bpl;
    //unsigned int i;
    tof_uvc_service *server_l = dev->pService;

    switch (dev->fcc) 
    {
        case V4L2_PIX_FMT_YUYV:
            bpl = dev->width * 2;
            buf->m.userptr = (uint32_t)dev->imgdata;
            buf->bytesused = bpl * dev->height;
            break;

        case V4L2_PIX_FMT_NV12:
            bpl = dev->width * 3 / 2;
            buf->m.userptr = (uint32_t)dev->imgdata;
            buf->bytesused = bpl * dev->height;
            break;
            
        case V4L2_PIX_FMT_MJPEG:
        case V4L2_PIX_FMT_H264:
        case V4L2_PIX_FMT_HEVC:
            if(NULL != dev && NULL != dev->imgdata)
            {
                buf->m.userptr = (uint32_t)dev->imgdata;
                buf->bytesused = dev->imgsize;
            }
            else
            {
                buf->m.userptr = (uint32_t)server_l->first_image_data;
                buf->bytesused = server_l->first_image_size;
            }

            break;
    }
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_video_process
*   Description  : orbbec buff video process api
*   Input        : struct tof_uvc_device *dev  
*   Output       : None
*   Return Value : static int
*****************************************************************************/
//Deprecated, 此接口已废弃不在使用
static int ob_tof_uvc_video_process(struct tof_uvc_device *dev)
{
    struct v4l2_buffer buf;
    int ret;
    tof_uvc_service *server_l = dev->pService;

    memset(&buf, 0, sizeof buf);
    buf.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
    buf.memory = V4L2_MEMORY_USERPTR;//V4L2_MEMORY_MMAP;
    buf.length = TOF_UVC_MAX_BUFFER_SIZE;

    if ((ret = ioctl(dev->fd, VIDIOC_DQBUF, &buf)) < 0)
    {
        ERR("Unable to dequeue buffer: %s (%d).\n", strerror(errno), errno);
        return ret;
    }

    server_l->g_uvc_timestamp = dev->pts;
    buf.timestamp.tv_sec  = dev->pts / 1000;
    buf.timestamp.tv_usec = (dev->pts % 1000) * 1000;

    ob_tof_uvc_video_fill_buffer(dev, &buf);

    if ((ret = ioctl(dev->fd, VIDIOC_QBUF, &buf)) < 0)
    {
        ERR("Unable to requeue buffer: %s (%d). \n", strerror(errno), errno);
        return ret;
    }

    return 0;
}


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
//Deprecated, 此接口已废弃不在使用
int ob_tof_uvc_video_send(struct tof_uvc_device *dev, void *data, unsigned int len, unsigned int pts, fd_set wfds, struct timeval tv)
{
    int ret = -1;
    tof_uvc_service *server_l = dev->pService;
    
    pthread_mutex_lock(&server_l->g_wrt_com_mutex);
    
    if (1 == server_l->g_stream_on && len > 0)
    {
        ret = select(dev->fd + 1, NULL, &wfds, NULL, &tv);//&wfds
        if(ret > 0)
        {
            dev->imgdata = data;
            dev->imgsize = len;
            dev->pts     = pts;
            ret = ob_tof_uvc_video_process(dev);
        }
        else
        {
            //ERR("select time out (%d)\n", ret);
            ret = -1;
        }
    }

    pthread_mutex_unlock(&server_l->g_wrt_com_mutex);

    return ret;
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_events_init
*   Description  : ob tof uvc event init
*   Input        : struct tof_uvc_device *dev  
*   Output       : None
*   Return Value : void
*****************************************************************************/
void ob_tof_uvc_events_init(struct tof_uvc_device *dev)
{
    struct v4l2_event_subscription sub;

    ob_tof_uvc_fill_streaming_control(dev, &dev->probe, 0, 0);
    ob_tof_uvc_fill_streaming_control(dev, &dev->commit, 0, 0);

    if (dev->bulk) {
        /* FIXME Crude hack, must be negotiated with the driver. */
        dev->probe.dwMaxPayloadTransferSize =
            getMaxPayloadTransferSizeBulk(dev->pService->dev_index);
        dev->commit.dwMaxPayloadTransferSize =
            getMaxPayloadTransferSizeBulk(dev->pService->dev_index);
    }

    memset(&sub, 0, sizeof sub);

    sub.type = UVC_EVENT_CONNECT;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);
    
    sub.type = UVC_EVENT_DISCONNECT;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);

    sub.type = UVC_EVENT_SETUP;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);
    
    sub.type = UVC_EVENT_DATA;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);
    
    sub.type = UVC_EVENT_STREAMON;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);
    
    sub.type = UVC_EVENT_STREAMOFF;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);
}


/*****************************************************************************
*   Prototype    : ob_tof_uvc_video_init
*   Description  : video init
*   Input        : struct tof_uvc_device *dev __attribute__((__unused__))  
*   Output       : None
*   Return Value : int
*****************************************************************************/
int ob_tof_uvc_video_init(struct tof_uvc_device *dev __attribute__((__unused__)))
{
    return 0;
}


static int32_t ob_stream_on_op(EM_DATA_TYPE data_type)
{    
    int dev_index = -1;

    pthread_mutex_lock(&g_stream_control_mutex);

    do{
        if (data_type == TYPE_IR)
            dev_index = OB_UVC_DEVICE_NODE_NUM_IR;
        else if (data_type == TYPE_DEPTH)
            dev_index = OB_UVC_DEVICE_NODE_NUM_DEPTH;
        else{
            ERR("data type is error, data_type:%d\n", data_type);
            break;
        }

        tof_uvc_service *pService = tof_uvc_gadget_get_device_handle(dev_index);
        if (NULL == pService){
            ERR("pObdev is NULL.\n");
            break;
        }

        if (0 == pService->dev->is_streaming)
        {
            ob_tof_uvc_handle_streamon_event(pService->dev, dev_index);

            sl_stream_off();
            ob_mx6300_stream_switch(ob_streamControl.cameraSwitchType, ob_streamControl.frameRate);

            if (data_type == TYPE_DEPTH){
                sl_stream_on(STREAM_DEPTH_OPEN);
                ob_depth_data_process_start();
            }
            else{
                sl_stream_on(STREAM_IR_OPEN);
                ob_ir_data_process_start();
            }
        }
    }while(0);

    pthread_mutex_unlock(&g_stream_control_mutex);

    return 0;
}


static int32_t ob_stream_off_op(EM_DATA_TYPE data_type)
{
    int dev_index = -1;

    pthread_mutex_lock(&g_stream_control_mutex);

    do{
        if (data_type == TYPE_IR)
            dev_index = OB_UVC_DEVICE_NODE_NUM_IR;
        else if (data_type == TYPE_DEPTH)
            dev_index = OB_UVC_DEVICE_NODE_NUM_DEPTH;
        else{
            ERR("data type is error, data_type:%d\n", data_type);
            break;
        }

        tof_uvc_service *pService = tof_uvc_gadget_get_device_handle(dev_index);
        if (NULL == pService){
            ERR("pObdev is NULL.\n");
            break;
        }
        
        if (1 == pService->dev->is_streaming)
        {
            if (data_type == TYPE_IR)  
                ob_ir_data_process_stop();
            else    
                ob_depth_data_process_stop();
            ob_tof_uvc_handle_streamoff_event(pService->dev, dev_index);
            sl_stream_off();
        }
    }while(0);

    pthread_mutex_unlock(&g_stream_control_mutex);

    return 0;
}


/*****************************************************************************
*   Prototype    : ob_usb_gadget_cmd_from_host
*   Description  : 走私有协议的上位机停流回调消息
*   Input        : OB_NODE_GADGET_CMD_EM cmd  
*                  void *pData                
*   Output       : None
*   Return Value : void

*****************************************************************************/
void ob_usb_gadget_cmd_from_host(OB_NODE_GADGET_CMD_EM cmd, void *pData) //cost_time 200ms
{
    int val = -1;

    //上位机必须等待设备端的前一次流停止完成清理干净,才能启动下一次流
    switch (cmd)
    {
        case OB_NODE_CMD_STOP_IR:
        {               
            ob_stream_off_op(TYPE_IR);
            break;
        }
        
        case OB_NODE_CMD_STOP_DEPTH:
        {
            ob_stream_off_op(TYPE_DEPTH);
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
*   Prototype    : ob_sl_uvc_cmd_cb_register
*   Description  : register orbbec pri protocl callback
*   Input        : struct tof_uvc_device *dev  
*   Output       : None
*   Return Value : int
*****************************************************************************/
int ob_sl_uvc_cmd_cb_register(struct tof_uvc_device *dev)
{
    static bool s_first_flag = true;
    if (s_first_flag){
        pthread_mutex_init(&g_stream_control_mutex, NULL); 
        //ob_gadget_register_cmd_cb(OB_PRIVATE_CHANNEL_DEVICE_NODE_NUM, ob_usb_gadget_cmd_from_host);
        s_first_flag = false;
    }
}



