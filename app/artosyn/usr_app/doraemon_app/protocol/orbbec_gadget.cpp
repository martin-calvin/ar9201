/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : orbbec_gadget.cpp
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/5/7
*  Last Modified :
*  Description   : orbbec private control protocol
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/5/7
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
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/prctl.h>

#include <linux/usb/video.h>
#include <linux/videodev2.h>
#include <linux/usb/uvc.h>

#include "dbg.h"
#include "utils.h"
#include "basic_typedef.h"
#include "logutil.h"
#include "orbbec_gadget.h"

#include "include/kernel/orbbec.h"

#include "usb_bulk_protocol.h"


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/

void ob_gadget_register_cmd_cb(int dev_index, ob_pri_node_gadget_cmd_cb cb)
{
    ob_device *pService = ob_get_device_handle();
    if (!pService){
        ERR("pObdev is NULL.\n");
        return;
    } 

    if (NULL != cb)
        pService->cmd_cb = cb;
    else
       ERR("cb is NULL.\n");
}


/*****************************************************************************
*   Prototype    : ob_gadget_events_init
*   Description  : subscribe orbbec event to v4l2
*   Input        : ob_device *dev  
*   Output       : None
*   Return Value : static void
*****************************************************************************/
static void ob_gadget_events_init(ob_device *dev)
{
    struct v4l2_event_subscription sub;

    if (!dev)
    {
        ERR("dev is NULL.\n");
        return;
    }
    
    memset(&sub, 0, sizeof(sub));
    sub.type = ORBBEC_EVENT_CONNECT;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);

    memset(&sub, 0, sizeof sub);
    sub.type = ORBBEC_EVENT_DISCONNECT;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);

    memset(&sub, 0, sizeof sub);
    sub.type = ORBBEC_EVENT_SETUP;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);
    
    memset(&sub, 0, sizeof sub);
    sub.type = ORBBEC_EVENT_DATA;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);

}


/*****************************************************************************
*   Prototype    : ob_event_process_setup_vendor
*   Description  : orbbec vendor event process
*   Input        : ob_device *dev                
*                  struct usb_ctrlrequest *ctrl  
*   Output       : None
*   Return Value : static void
*****************************************************************************/
static void ob_event_process_setup_vendor(ob_device *dev, struct usb_ctrlrequest *ctrl)
{   
    // INFO("ob_event_process_setup_vendor, ctrl->bRequestType = %d\n", ctrl->bRequestType);

    struct orbbec_request_data resp;
    memset(&resp, 0, sizeof(resp));
    resp.length = -EL2HLT;

    if (ctrl->bRequestType == 0xc0) //USB_TYPE_VENDOR & 0x80
    {
        memcpy(resp.data, (const uint8_t *)&dev->vendor_response, dev->vendor_response.buf.len);
        resp.length = dev->vendor_response.buf.len < ctrl->wLength ? dev->vendor_response.buf.len : ctrl->wLength;
    }
    else
    {
        resp.length = ctrl->wLength;
    }

    if (resp.length <= 0)
    {
        ERR("resp.length:%d\n", resp.length);
        return;
    }

    int ret = ioctl(dev->fd, ORBBECIOC_SEND_RESPONSE, &resp);
    if (ret < 0)
    {
        ERR("send ob response failed, %s(%d)\n", strerror(errno), errno);
    }
}


/*****************************************************************************
*   Prototype    : ob_events_process_setup
*   Description  : orbec events setup process
*   Input        : ob_device *dev                
*                  struct usb_ctrlrequest *ctrl  
*   Output       : None
*   Return Value : static void
*****************************************************************************/
static void ob_events_process_setup(ob_device *dev, struct usb_ctrlrequest *ctrl)
{
#if 1
    // INFO("bRequestType:0x%x, bRequest:0x%x, wValue:0x%x, wIndex:0x%x, wLength:0x%x\n", ctrl->bRequestType, ctrl->bRequest, ctrl->wValue, ctrl->wIndex, ctrl->wLength);
#endif

    switch (ctrl->bRequestType & USB_TYPE_MASK)
    {
        case USB_TYPE_STANDARD:
            INFO("USB_TYPE_STANDARD.\n");
            break;

        case USB_TYPE_CLASS:
            INFO("USB_TYPE_CLASS.\n");
            break;

        case USB_TYPE_VENDOR:
            ob_event_process_setup_vendor(dev, ctrl);
            break;

        default:
            ERR("UnSupport setup event.\n");
            break;
    }
}


/*****************************************************************************
*   Prototype    : ob_events_process_data
*   Description  : orbbec events data process
*   Input        : dev              
*                  &ob_event->data  
*   Output       : None
*   Return Value : static void
*****************************************************************************/
static void ob_events_process_data(ob_device *dev, struct orbbec_request_data *data)
{
    ProtocolMsg *pVendor_request = (ProtocolMsg *)data->data;

    if (pVendor_request->header.nMagic == PROTOCOL_REQUEST_MAGIC)
    {
        memset(&dev->vendor_response, 0, sizeof(ProtocolMsg));
        int ret = ob_protocol_process(dev, pVendor_request, &dev->vendor_response);
        data->length = dev->vendor_response.buf.len;
    }
    else
    {
        ERR("magic:0x%4X opcode:%d.\n", pVendor_request->header.nMagic, pVendor_request->header.nOpcode);
    }
}


/*****************************************************************************
*   Prototype    : ob_events_process
*   Description  : orbbec event process
*   Input        : struct ob_device *dev  
*   Output       : None
*   Return Value : void
*****************************************************************************/
static void ob_events_process(ob_device *dev)
{
    int ret = 0;
    struct v4l2_event v4l2_event;
    struct orbbec_event *ob_event = (struct orbbec_event *)&v4l2_event.u.data;

    if (!dev)
    {
        ERR("dev is NULL\n");
        return;
    }

    ret = ioctl(dev->fd, VIDIOC_DQEVENT, &v4l2_event);
    if (ret < 0) 
    {
        ERR("VIDIOC_DQEVENT failed: %s (%d)\n", strerror(errno), errno);
        return;
    }


    switch (v4l2_event.type) 
    {
        case ORBBEC_EVENT_CONNECT:
            // INFO("ORBBEC_EVENT_CONNECT!\n");
            return;
        
        case ORBBEC_EVENT_DISCONNECT:
            // INFO("ORBBEC_EVENT_DISCONNECT!\n");
            return;

        case ORBBEC_EVENT_SETUP:
            // INFO("ORBBEC_EVENT_SETUP!\n");
            ob_events_process_setup(dev, &ob_event->req);
            break;

        case ORBBEC_EVENT_DATA:
            // INFO("ORBBEC_EVENT_DATA!\n");
            ob_events_process_data(dev, &ob_event->data);
            break;
        
        default:
            ERR("unsupport event type:%d\n", v4l2_event.type);
            break;
    }

}

unsigned char  bulk_file_recv_buffer[MAX_RECV_PACKET_LEN];

/*****************************************************************************
*   Prototype    : ob_file_recv_process
*   Description  : receive file from host
*   Input        : ob_device *dev  
*   Output       : None
*   Return Value : static void
*   Calls        : 
*   Called By    : 
*****************************************************************************/
static int32_t ob_file_recv_process(ob_device *dev)
{
    // unsigned char buffer[512];
    // memset(buffer, 0, sizeof(buffer));


    int32_t read_len = read(dev->fd, bulk_file_recv_buffer, MAX_RECV_PACKET_LEN);
    if(read_len <= 0)
    {
        ERR("read error! ret:%d \n", read_len);
        return read_len;
    }

    //DBG("recv [len:%d]: %X %X %X %X %X %X %X %X %X %X.\n",
    //    read_len,
    //    bulk_file_recv_buffer[0],
    //    bulk_file_recv_buffer[1],
    //    bulk_file_recv_buffer[2],
    //    bulk_file_recv_buffer[3],
    //    bulk_file_recv_buffer[4],
    //    bulk_file_recv_buffer[5],
    //    bulk_file_recv_buffer[6],
    //    bulk_file_recv_buffer[7],
    //    bulk_file_recv_buffer[8],
    //    bulk_file_recv_buffer[9],
    //    bulk_file_recv_buffer[10]
    //    );

    usb_bulk_data_analysis(bulk_file_recv_buffer, read_len);
    
    return 0;
}

/*****************************************************************************
*   Prototype    : ob_gadget_trans_data_poll_thd
*   Description  : orbbec gadget trans_data poll thread
*   Input        : void *arg  
*   Output       : None
*   Return Value : static void *
*****************************************************************************/
static void *ob_gadget_trans_data_poll_thd(void *arg)
{
    int32_t ret = 0;
    fd_set fds;
    struct timeval tv; 
	  
    ob_device *dev = (ob_device *)arg;
    if (!dev)
    {
        ERR("dev is NULL.\n");
        return NULL;
    }

    while(1)
    {
        FD_ZERO(&fds);
        FD_SET(dev->fd, &fds);
        fd_set dfds = fds;

        /* Timeout. */
        tv.tv_sec  = 1;
        tv.tv_usec = 0;

        ret = select(dev->fd + 1, NULL, &dfds, NULL, &tv);  //监控数据 
        if (-1 == ret)
        {
            ERR("select error:%d, %s\n", errno, strerror(errno));
            if (EINTR == errno) continue;
            break;
        } 
        
        if (ret > 0)
        {
            if (FD_ISSET(dev->fd, &dfds))
            {
               ob_file_recv_process(dev);
            }
        }
    }

    INFO("exit ob get trans data monitor loop.\n");
}


/*****************************************************************************
*   Prototype    : ob_gadget_events_poll_thd
*   Description  : orbbec gadget events poll thread
*   Input        : void *arg  
*   Output       : None
*   Return Value : static void *
*****************************************************************************/
static void *ob_gadget_events_poll_thd(void *arg)
{
    int32_t ret = 0;
    fd_set fds;
    struct timeval tv;
    pthread_t   tid_getbuf; 

    prctl(PR_SET_NAME, "ob_gadget_events_poll_thd");

    ob_device *dev = (ob_device *)arg;
    if (!dev)
    {
        ERR("dev is NULL.\n");
        return NULL;
    }

#if 1
    //just to test array len!
    struct v4l2_event stEvent;
    int iLen = sizeof(stEvent.u.data);
    printf("xavier, v4l2_event.u.data's Length:%d\n", iLen);

    struct orbbec_event stOBEvent;
    int iReqLen = sizeof(stOBEvent.data.data);
    printf("xavier, orbbec_event.data.data's Lenght:%d\n", iReqLen);
#endif

    usb_bulk_init();

    ret = pthread_create(&tid_getbuf, NULL, ob_gadget_trans_data_poll_thd, dev);
    if (0 != ret)
    {
          ERR("failed, to create ob gadget trans_data_poll_thd.\n");
    }

    dev->pollrun = 1;
    while (1 == dev->pollrun)    
    {
        FD_ZERO(&fds);
        FD_SET(dev->fd, &fds);
        fd_set efds = fds;

        /* Timeout. */
        tv.tv_sec  = 1;
        tv.tv_usec = 0;

        ret = select(dev->fd + 1, NULL, NULL, &efds, &tv);    //监控指令
        if (-1 == ret)
        {
            ERR("select error:%d, %s\n", errno, strerror(errno));
            if (EINTR == errno) continue;
            break;
        } 
        
        if (ret > 0)
        {
            if (FD_ISSET(dev->fd, &efds))
            {
                ob_events_process(dev);
            }
        }
    }

    INFO("exit ob event monitor loop.\n");

    return NULL;
}

/*****************************************************************************
*   Prototype    : ob_gadget_events_poll
*   Description  : orbbec gadget events poll switch
*   Input        : OB_EVENTS_POLL_SATUS_T s  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_gadget_events_poll(OB_EVENTS_POLL_SATUS_T s)
{
    int32_t ret = 0;
    ob_device *pObDev = ob_get_device_handle();
    if (!pObDev)
    {
        ERR("pObdev is NULL.\n");
        return -1;
    }

    switch (s)
    {
        case OB_EVENTS_POLL_START:
        { 
            ret = pthread_create(&pObDev->tid_obpoll, NULL, ob_gadget_events_poll_thd, pObDev);
            if (0 != ret)
            {
                ERR("failed, to create ob gadget poll thread.\n");
                return -1;
            }

            break;
        }
        
        case OB_EVENTS_POLL_STOP:
        {
            ERR("failed, to create ob gadget poll thread.\n");
            pObDev->pollrun = 0;
            pthread_join(pObDev->tid_obpoll, NULL);
            break;
        }
        default:
        {
            ERR("cmd is not support, cmd:%d\n", s);
            break;
        }
    }

    return 0;
}


/*****************************************************************************
*   Prototype    : ob_get_device_handle
*   Description  : create or get orbbec handle
*   Input        : None
*   Output       : None
*   Return Value : ob_device *
*****************************************************************************/
ob_device *ob_get_device_handle(void)
{
    static ob_device *pObDev = NULL;

    if (!pObDev)
    {
        WARN("pObDev is note inited, so malloc it here!\n");
        
        pObDev = (ob_device *)malloc(sizeof(ob_device));
        if(!pObDev)
        {
            ERR("memeory out!\n");
            return NULL;
        }

        memset(pObDev, 0, sizeof(ob_device)); 
    }

    return pObDev;
}


/*****************************************************************************
*   Prototype    : ob_gadget_init
*   Description  : orbbec gadget init function
*   Input        : int dev_index  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_gadget_init(int dev_index)
{
    char devName[32];
    ob_device *pObDev = NULL;

    pObDev = ob_get_device_handle();
    if (!pObDev)
    {
        ERR("pObDev is NULL.\n");
        return -1;
    }

    memset(devName, 0, sizeof(devName));
    snprintf(devName, sizeof(devName), "/dev/video%d", dev_index);
    if (0 != access(devName, F_OK))
    {
        ERR("not found %s\n", devName);
        return -1;
    }
    
    pObDev->fd = open(devName, O_RDWR);
    if (-1 == pObDev->fd)
    {
        ERR("ob device open failed:%s(%d).\n", strerror(errno), errno);
        return -1;
    }
    INFO("ob open succeeded, file descriptor:%d.\n", pObDev->fd);

    ob_gadget_events_init(pObDev);

    INFO("init success!\n");

    return 0;
}



