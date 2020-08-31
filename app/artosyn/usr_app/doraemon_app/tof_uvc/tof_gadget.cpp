/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : tof_gadget.c
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/5/29
*  Last Modified :
*  Description   : tof gadget for rawPhase and depth uvc service,
*                  rawPhase and depth use the same uvc channel.

*  History:
* 
*       1.  Date         : 2020/5/29
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
#include "tof_gadget.h"
#include "orbbec_gadget_types.h"

#include "include/kernel/orbbec.h"

#include "tof_stream.h"
extern "C"{
#include "uvc_configfs.h"
}

 
 /*==============================================*
  *      constants or macros define              *
  *----------------------------------------------*/
#define ORBBEC_STREAM_TYPE_NONE          0
#define ORBBEC_STREAM_TYPE_DEPTH         1
#define ORBBEC_STREAM_TYPE_IR            2
 /*==============================================*
  *      project-wide global variables           *
  *----------------------------------------------*/


 /*==============================================*
  *      routines' or functions' implementations *
  *----------------------------------------------*/
  
 /*****************************************************************************
 *   Prototype    : tof_uvc_gadget_events_poll_thd
 *   Description  : tof uvc gadget events poll thread
 *   Input        : void *arg  
 *   Output       : None
 *   Return Value : static void *
 *****************************************************************************/
static void *tof_uvc_gadget_events_poll_thd(void *arg)
{
    int32_t ret = 0;
    fd_set fds;
    struct timeval tv;

    prctl(PR_SET_NAME, "ob_gadget_events_poll_thd");

    tof_uvc_service *pService = (tof_uvc_service *)arg;
    if (!pService)
    {
        ERR("pService is NULL.\n");
        return NULL;
    }
    struct tof_uvc_device *udev = pService->dev;
    if (!udev)
    {
        ERR("udev is NULL.\n");
        return NULL;
    }

    udev->io = IO_METHOD_MMAP;
    udev->nbufs = 4;

    pService->pollrun = 1;
    while (1 == pService->pollrun)
    {
        FD_ZERO(&fds);
        FD_SET(pService->dev->fd, &fds);
        fd_set efds = fds;
        fd_set dfds = fds;

        /* Timeout. */
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        ret = select(pService->dev->fd + 1, NULL, NULL, &efds, &tv);
        if (-1 == ret)
        {
            ERR("select error:%d, %s\n", errno, strerror(errno));
            if (EINTR == errno)
                continue;
            break;
        }

        if (ret > 0)
        {
            if (FD_ISSET(pService->dev->fd, &efds))
            {
                ob_tof_uvc_events_process(pService->dev, pService->dev_index);
            }
        }
#if 0
        if (ob_streamControl.depthStopStream)
        {
            INFO("depth stream off \n");
            ob_tof_uvc_handle_streamoff_event(pService->dev, ORBBEC_STREAM_TYPE_DEPTH);
            ob_streamControl.depthStopStream = false;
        }
        if (ob_streamControl.irStopStream)
        {
            INFO("ir stream off \n");
            ob_tof_uvc_handle_streamoff_event(pService->dev, ORBBEC_STREAM_TYPE_IR);         
            ob_streamControl.irStopStream = false;
        }
#endif
    }

    INFO("exit tof uvc event monitor loop.\n");
    return NULL;
}

 /*****************************************************************************
 *   Prototype    : tof_uvc_gadget_events_poll
 *   Description  : tof uvc gadget events poll switch
 *   Input        : OB_EVENTS_POLL_SATUS_T s  
 *   Output       : None
 *   Return Value : int32_t
 *****************************************************************************/
 int32_t tof_uvc_gadget_events_poll(int dev_index, OB_EVENTS_POLL_SATUS_T s)
 {
     int32_t ret = 0;
     tof_uvc_service *pService = tof_uvc_gadget_get_device_handle(dev_index);
     if (!pService)
     {
         ERR("pObdev is NULL.\n");
         return -1;
     }
 
     switch (s)
     {
         case OB_EVENTS_POLL_START:
         {
             ret = pthread_create(&pService->tid_poll, NULL, tof_uvc_gadget_events_poll_thd, pService);
             if (0 != ret)
             {
                 ERR("failed, to create ob gadget poll thread.\n");
                 return -1;
             }
             break;
         }
         
         case OB_EVENTS_POLL_STOP:
         {
             pService->pollrun = 0;
             pthread_join(pService->tid_poll, NULL);
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
 *   Prototype    : tof_uvc_gadget_get_device_handle
 *   Description  : create or get orbbec handle
 *   Input        : None
 *   Output       : None
 *   Return Value : tof_uvc_service *
 *****************************************************************************/
 tof_uvc_service *tof_uvc_gadget_get_device_handle(int dev_index)
 {
     static tof_uvc_service *pServer[OB_UVC_DEVICE_NODE_NUM_MAX] = {NULL, NULL, NULL}; //0: reseved, 1:depth, 2:ir
 
     if (!pServer[dev_index])
     {
         WARN("pServer is note inited, so malloc it here!\n");
         
         pServer[dev_index] = (tof_uvc_service *)malloc(sizeof(tof_uvc_service));
         if(!pServer[dev_index])
         {
             ERR("memeory out!\n");
             return NULL;
         }
         
         memset(pServer[dev_index], 0, sizeof(tof_uvc_service)); 

         pServer[dev_index]->run_flag = 1;
     }
 
     return pServer[dev_index];
 }
 
 
 /*****************************************************************************
 *   Prototype    : tof_uvc_gadget_init
 *   Description  : tof gadget init function
 *   Input        : int dev_index  
 *   Output       : None
 *   Return Value : int32_t
 *****************************************************************************/
 int32_t tof_uvc_gadget_init(int dev_index)
 {
     int i,j = 0;
     char devName[32];
     tof_uvc_service *pService = NULL;
 
     pService = tof_uvc_gadget_get_device_handle(dev_index);
     if (!pService)
     {
         ERR("pService is NULL.\n");
         goto FAIL_EXIT;
     }

     pService->uvc_formats_num = getConfigfsFormat(&pService->uvc_formats, dev_index);
     if (pService->uvc_formats_num < 0)
     {
         ERR("uvc configfs info get failed.\n");
         goto FAIL_EXIT;
     }

#if 0
     printf("*******************xavier ****uvc_formats_num: %d***********************\n", pService->uvc_formats_num);
     for(i = 0; i < pService->uvc_formats_num; ++i)
     {
         char * p = (char *)&(pService->uvc_formats[i].fcc);
         printf("format: %c%c%c%c\n", p[0], p[1], p[2], p[3]);
         j = 0;
         for(j = 0; 0 != pService->uvc_formats[i].frames[j].height; ++j)
         {
             int k;
             printf("    %d. %d * %d:\n", j, pService->uvc_formats[i].frames[j].width, pService->uvc_formats[i].frames[j].height);
             printf("        interval: ");
             for(k = 0; k < 8; ++k)
             {
                 printf("%d ", pService->uvc_formats[i].frames[j].intervals[k]);
             }
             printf("\n");
         }
     }
     printf("*****************************************************************\n");
#endif
     
     memset(devName, 0, sizeof(devName));
     snprintf(devName, sizeof(devName), "/dev/video%d", dev_index);
     if (0 != access(devName, F_OK))  {
         ERR("not found %s\n", devName);
         goto FAIL_EXIT;
     }

     pService->dev = ob_tof_uvc_open(devName);
     if (NULL == pService->dev)
     {
         ERR("pService open failed:%s(%d).\n", strerror(errno), errno);
         goto FAIL_EXIT;
     }
     INFO("xavier pService open succeeded, file descriptor:%d.\n", pService->dev->fd);


     if (dev_index == OB_UVC_DEVICE_NODE_NUM_DEPTH)
     {
         pService->dev->control_interface = OB_UVC_INTF_CONTROL_DEPTH;
         pService->dev->streaming_interface = OB_UVC_INTF_STREAMIMG_DEPTH;
     }
     else if (dev_index == OB_UVC_DEVICE_NODE_NUM_IR)
     {
         pService->dev->control_interface = OB_UVC_INTF_CONTROL_IR;
         pService->dev->streaming_interface = OB_UVC_INTF_STREAMIMG_IR;
     }
     pService->dev->bulk = 1;
     pService->dev->width  = 640;
     pService->dev->height = 480;
     pService->dev->frame_interval = (10000000 / 30);
     pService->dev->fcc = pService->uvc_formats[0].fcc;
     pService->dev->fcc_index = 0;
     pService->dev->camera_fd = -1;
     pService->dev->pService = pService;
     pService->dev_index = dev_index; 
   
     pService->first_image_size = TOF_UVC_MAX_BUFFER_SIZE / (1024 * 16);
     pService->first_image_data = (void *)malloc(TOF_UVC_MAX_BUFFER_SIZE * sizeof(char));
     memset(pService->first_image_data, 0, TOF_UVC_MAX_BUFFER_SIZE);
     
     pthread_mutex_init(&pService->g_wrt_com_mutex, NULL);

     ob_tof_uvc_events_init(pService->dev);
     ob_tof_uvc_video_init(pService->dev);

     ob_sl_uvc_cmd_cb_register(pService->dev);
     
     INFO("init success!\n");
     return 0;


FAIL_EXIT:
    ob_tof_uvc_close(pService->dev);
    freeConfigfsFormat(&pService->uvc_formats, pService->uvc_formats_num);

    if (NULL != pService)
    {
        free(pService);
        pService = NULL;
    }

    return -1;
 }
 


