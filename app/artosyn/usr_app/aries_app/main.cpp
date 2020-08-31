/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : main.cpp
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/4/24
*  Last Modified :
*  Description   : aries app main
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/4/24
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/

/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
extern "C"{
#include "uvc_service2.h"
}
#include "logutil.h"
#include "dbg.h"
#include "message_queue.h"
#include "buff_queue.h"
#include "orbbec_gadget_types.h"
#include "orbbec_gadget.h"
#include "tof_gadget.h"
#include "tof_stream.h"
#include "event.h"

#include <thread>
#include <fstream>
#include <iostream>


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/


/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/


/*****************************************************************************
*   Prototype    : print_version_info
*   Description  : print version
*   Input        : None
*   Output       : None
*   Return Value : static void
*****************************************************************************/
static void print_version_info()
{
    printf("\n-----------------------------------------\n");
    printf("aries app version:%s\n", ARIES_APP_VERSION);
    printf("git version:%s\n", SDK_GIT_VERSION);
    printf("build time:%s\n", COMPILE_TIME);
    printf("-----------------------------------------\n\n");
}


/*****************************************************************************
*   Prototype    : main
*   Description  : main enter
*   Input        : int argc      
*                  char* argv[]  
*   Output       : None
*   Return Value : int
*   Calls        : 
*   Called By    : 


usb节点与pipeline对应关系表: 

         control_interface  stream_interface  device    酷芯微pipe_index      string
orbbec          0                /           /dev/video10      /            "Orbbec Aries Data Channel"
rgb             1                2           /dev/video0       1            "Orbbec Aries Camera"
depth/rawphase  3                4           /dev/video1       0            "Orbbec Aries 3D Camera Depth"
ir              5                6           /dev/video2       /            "Orbbec Aries 3D Camera IR"

*****************************************************************************/
int main(int argc, char* argv[])
{
    pthread_cond_t cond;
    pthread_mutex_t mutex;
    pthread_cond_init(&cond, NULL);
    pthread_mutex_init(&mutex, NULL);
   
    print_version_info();
    dbg_console();
	
    //[1] rgb数据流capture+uvc模块
    ob_rgb_uvc_module_init();

    //[2] orbbec私有控制通道 module init
    ob_gadget_init(OB_PRIVATE_CHANNEL_DEVICE_NODE_NUM);
    ob_gadget_events_poll(OB_EVENTS_POLL_START);

    //[3] depth/rawPhase uvc设备数据发送模块初始化
    tof_uvc_gadget_init(OB_UVC_DEVICE_NODE_NUM_DEPTH);
    tof_uvc_gadget_events_poll(OB_UVC_DEVICE_NODE_NUM_DEPTH, OB_EVENTS_POLL_START);

    //[4] ir uvc设备数据发送模块初始化
    tof_uvc_gadget_init(OB_UVC_DEVICE_NODE_NUM_IR);
    tof_uvc_gadget_events_poll(OB_UVC_DEVICE_NODE_NUM_IR, OB_EVENTS_POLL_START);

    //[5] tof数据流capture模块初始化
    ob_tof_stream_module_init();
	
    //[6] IMU采集模块初始化

    //[7] DSP模块初始化

    //[8] 文件传输模块初始化


    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);
    pthread_mutex_unlock(&mutex);

    WARN("Exit!\n");
    return 0;
}


