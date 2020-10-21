/******************************************************************************

  Copyright (C), 2020, orbbec Tech. Co., Ltd.

 ******************************************************************************
  File Name     : watch_dog.cpp

  Version       : 1.0.0
  Author        : Martin
  Created       : 2020/09/29
  Description   :
  History       :
  
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "ar_wdt.h"
#include "utils.h"
#include "logutil.h"
#include "tof_uvc_op.h"
#include "tof_stream.h"
#include "uvc_function.h"
#include "obc_sl_drv.h"

typedef enum {
    NORMAL,
    WARN,
    FATAL,
} temp_statuse;

/*****************************************************************************
*   Prototype    : monitoring_DeviceStatus
*   Description  : 
*   Input        : 
*   Output       : 
*   Return Value : 
*****************************************************************************/
static int monitoring_DeviceStatus(void)
{
    char temp_buf[128] = {0};
    char cmd_get_temp[] = "devmem 0x60632910 32\n"; //get cpu temperature 
    strcpy(temp_buf, get_shell(cmd_get_temp));
    int32_t cpu_temp = str_to_int(temp_buf); //string to decimalism
    cpu_temp = cpu_temp * 0.4825 - 77.7;
    // INFO("CPU temperature is %d\n", cpu_temp);

    if (cpu_temp < 95)
    {
        ob_streamControl.deviceState = NORMAL;
    }
    if ((cpu_temp > 95) && (ob_streamControl.deviceState == NORMAL))
    {
        ob_streamControl.deviceState = WARN;
        ob_depth_data_process_stop();
        sl_stream_off();
        ob_mx6300_stream_switch(ob_streamControl.cameraSwitchType, 20);
        sl_stream_on(STREAM_DEPTH_OPEN);
        ob_depth_data_process_start();

        ob_rgb_stream_param stParam;
        memset(&stParam, 0, sizeof(stParam));
        ob_rgb_get_currrent_stream_param((void *)&stParam);
        if (stParam.is_streaming && stParam.fps > 20){
            ob_rgb_stream_switch(stParam.fcc, stParam.width, stParam.height, 20);
        }

        WARN("cpu temperature over 95 degree centigrade! FPS down to 20fps.\n");
    }
    if ((cpu_temp > 105) && (ob_streamControl.deviceState == WARN))
    {
        ob_streamControl.deviceState = FATAL;
        ob_stream_off_op(TYPE_IR);
        ob_streamControl.irStopStream = true;
        ob_stream_off_op(TYPE_DEPTH);
        ob_streamControl.depthStopStream = true;

        ob_rgb_stop_stream();
        WARN("cpu temperature over 105 degree centigrade! Device has been stream off.\n");
    }
}

/*****************************************************************************
*   Prototype    : watchDog_timer_thread
*   Description  : 
*   Input        : 
*   Output       : 
*   Return Value : 
*****************************************************************************/
static void *watchDog_timer_thread(void *arg)
{
    int timeout = 16;  //const value:2, 4, 8, 16, 32, 65, 131

    int ret = ar_wdt_start();
    if (ret)
    {
        ERR("watchdog start error\n");
        return NULL;
    }

    ret = ar_wdt_set_timeout_threshhold(&timeout);
    if (ret != 0)
    {
        ERR("set wdt timeout ret = %d\n", ret);
        return NULL;
    }        

    // ret = ar_wdt_get_timeout_threshhold(&timeout);
    // if (ret == 0)
    //     INFO("get wdt timeout %ds\n", timeout);
    // else
    //     ERR("get wdt timeout ret = %d\n", ret);

    while (1)
    {
        ret = ar_wdt_feed();
        sleep(5);
        monitoring_DeviceStatus();
    }
}
/*****************************************************************************
*   Prototype    : watchDogTimer_init
*   Description  : 
*   Input        : 
*   Output       : 
*   Return Value : 
*****************************************************************************/
int watchDogTimer_init(void)
{
    INFO("start watch dog timer thread.\n");
    start_new_thread("watch dog timer thread", NULL, watchDog_timer_thread, NULL);
}
