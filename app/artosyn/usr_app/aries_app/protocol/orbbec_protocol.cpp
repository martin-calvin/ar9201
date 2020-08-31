/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : orbbec_protocol.cpp
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/5/7
*  Last Modified :
*  Description   : orbbbec private protocol
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
#include <sys/types.h>
        
#include <linux/usb/video.h>
#include <linux/videodev2.h>
#include <linux/usb/uvc.h>
    
#include "logutil.h"
#include "dbg.h"
#include "orbbec_protocol.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

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
#include "obc_tof_drv.h"
#include "usb_bulk/sys_upgrade.h"
#include "usb_bulk/sys_calibration_upgrade.h"
#include "usb_bulk/sys_filetran.h"
#include "usb_bulk/sys_align_upgrade.h"


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/
static uint32_t s_u32EmitterSwitchStatus = 1;
static uint32_t s_u32D2CSwitchStatus = 0;

static const float duty_cycle_table[] = 
{
     27, 28.4, 29.86, 31.32, 32.78, 34.24, 35.7, 37.16, 38.62, 40.08, 41.54, 43, 44.4, 45.8, 47.2,           //0~14
     48.7, 50, 51.4, 52.7, 54.2, 55.66, 57.12, 58.58, 60.04, 61.5, 62.96, 64.42, 65.88, 67.34, 68.8, 70.5,   //15~30
};

/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/


//将字符串版本号转换为整型版本号,如V1.2.3,提取出1、2、3存放到dst中
int get_int_version(const char *src,int *dst)
{
    char temp[5] = {0};
    char i = 0,j = 0,k = 0;

    //printf("src = %s\n",src);
    while(src[i++] != '\0')
    {
       if((src[i] != 'v')&&(src[i] != '.')&&(j < 5))    //版本号最大为65535，五位整数
       {
          temp[j++] = src[i];
       }
       else if((src[i] == '.')&&(k < 2))                  //版本号小于3段
       {
          j = 0;
          dst[k++]  = atoi(temp);                          //字符串转整数
          memset(temp,0,sizeof(temp));
       }
    }

    dst[k] = atoi(temp);                                     //最后一段版本号
	
    return 0;
}

static int32_t init_tof_cam_fd()
{
    int32_t ret = -1;
    obc_cam_handle_t cam_handle = get_ob_cam_handle();

    if(cam_handle->tof_cam_fd < 0)
    {
        cam_handle->cam_pipeline_cfg.input_vidio_res.width = 1280;
        cam_handle->cam_pipeline_cfg.input_vidio_res.height = 970;

        ret = init_tof_cam(cam_handle);        //init camera
        if(ret < 0){
            ERR("init_tof_cam failed!\n");
            return cam_handle->tof_cam_fd;
        }

	 usleep(100000);// delay 100ms
	 
        cam_handle->tof_cam_fd = open_tof_cam(cam_handle->tof_cam_id);  //open camera
        if(cam_handle->tof_cam_fd < 0){
            ERR("open_tof_cam failed!\n");
            return cam_handle->tof_cam_fd;
        }
    }
    else
    {
        ret = 0;
    }

    return ret;
}


static int32_t protocol_handle_default(const ProtocolMsg *request, ProtocolMsg *response)
{
    response->header.nMagic = PROTOCOL_RESPONE_MAGIC;
    response->header.nOpcode = request->header.nOpcode;
    response->header.nId = request->header.nId;
    response->buf.data.resp.res = 0x0001;     //defalut invalid command
    response->header.nSize = (sizeof(response->buf.data.resp.res)) >> 1;
    response->buf.len = sizeof(response->header) + (response->header.nSize << 1);
    return 0;
}

static int32_t protocol_handle_response(const ProtocolMsg *request, ProtocolMsg *response, uint16_t res)
{
    response->header.nMagic = PROTOCOL_RESPONE_MAGIC;
    response->header.nOpcode = request->header.nOpcode;
    response->header.nId = request->header.nId;
    response->buf.data.resp.res = res;
    response->header.nSize = (sizeof(response->buf.data.resp.res)) >> 1;
    response->buf.len = sizeof(response->header) + (response->header.nSize << 1);
    return 0;
}

static int32_t protocol_handle_with_data(const ProtocolMsg *request, ProtocolMsg *response, uint8_t *data, uint16_t len, uint16_t res)
{
    response->header.nMagic = PROTOCOL_RESPONE_MAGIC;
    response->header.nOpcode = request->header.nOpcode;
    response->header.nId = request->header.nId;
    response->buf.data.resp.res = res;

    memcpy(response->buf.data.resp.data, data, len);
    response->header.nSize = (sizeof(response->buf.data.resp.res) + len) >> 1;     // lenght(data)/2
    response->buf.len = sizeof(response->header) + (response->header.nSize << 1);  //数据data长度 + header长度, (缓存中实际使用的byteused长度)
    return 0;
}

static int32_t protocol_handle_get_flash_write_protection(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_tec_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_get_ldp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_get_emitter(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    propertyValue.cur = s_u32EmitterSwitchStatus;
    //DBG("get emitter:%d\n", s_u32EmitterSwitchStatus);

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_laser_pulse_width(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    propertyValue.cur = 3000;
    propertyValue.max = 3000;
    propertyValue.min = 1000;
    propertyValue.def = 3000;
    propertyValue.step = 100;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_laser_current(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint8_t value_A = 0,value_B = 0;
    PropertyVal propertyValue = {1,1,0,0,1};
    float temp_value = 0.0;

    ret = init_tof_cam_fd();                  //返回值为负值表示打开tof设备失败             
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _error;
    }

    ret = tof_sensor.get_illum_power(&value_A,&value_B);   //获取激光电流，通常只有A通道有值，B通道为0
    if(ret < 0)
    {
        ERR("get_illum_power failed!\n");
        goto _error;
    }
	
    temp_value =(value_A + value_B) * 14.8 * 1000;
    propertyValue.cur = (uint32_t)temp_value;
	
    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),(uint16_t)ret);
    return ret;

_error:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
    return ret;
}

static int32_t protocol_handle_get_flood(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_get_flood_level(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_get_temperature_compensation_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_temperature_calibrated_ir(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    propertyValue.cur = 30;
    propertyValue.max = 30;
    propertyValue.min = 0;
    propertyValue.def = 30;
    propertyValue.step = 1;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_temperature_calibrated_ldmp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    propertyValue.cur = 35;
    propertyValue.max = 35;
    propertyValue.min = 0;
    propertyValue.def = 35;
    propertyValue.step = 1;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_temperature_compensation_coefficient_ir(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_get_temperature_compensation_coefficient_ldmp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    propertyValue.cur = 2;
    propertyValue.max = 2;
    propertyValue.min = 0;
    propertyValue.def = 2;
    propertyValue.step = 1;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_depth_align(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    propertyValue.cur = s_u32D2CSwitchStatus;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_tof_fps(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    PropertyVal propertyValue = {1,1,0,0,1};

    ret = init_tof_cam_fd();                                 //返回值为负值表示打开tof设备失败
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _error;
    }

    ret = tof_sensor.get_fps((uint8_t *)&tof_sensor.fps);    //读取tof帧率
    if(ret < 0)
    {
        ERR("get_fps failed!\n");
        goto _error;
    }

    propertyValue.cur = tof_sensor.fps;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),(uint16_t)ret);
    return ret;

_error:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
    return ret;
}

static int32_t protocol_handle_get_tof_mirror(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    PropertyVal propertyValue = {1,1,0,0,1};
    img_rotation_t mode = IMAGE_NORMAL;

    ret = init_tof_cam_fd();                                 //返回值为负值表示打开tof设备失败
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _error;
    }

    ret = tof_sensor.get_img_mirror_flip(&mode);    //读取tof帧率
    if(ret < 0)
    {
        ERR("get_img_mrror_flip failed!\n");
        goto _error;
    }

    propertyValue.cur = (uint32_t)mode;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),(uint16_t)ret);
    return ret;

_error:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
    return ret;
}

static int32_t protocol_handle_get_tof_exposure_time(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    PropertyVal propertyValue = {1,1,0,0,1};

    ret = init_tof_cam_fd();                                 //返回值为负值表示打开tof设备失败
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _error;
    }

    ret = tof_sensor.get_integration_time((uint16_t *)&tof_sensor.integration_time);    //读取tof曝光时间
    if(ret < 0)
    {
        ERR("get_integration_time failed!\n");
        goto _error;
    }

    propertyValue.cur = tof_sensor.integration_time;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),(uint16_t)ret);
    return ret;

_error:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
    return ret;
}

static int32_t protocol_handle_get_tof_gain(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    propertyValue.cur = 3;
    propertyValue.max = 10;
    propertyValue.min = 1;
    propertyValue.def = 1;
    propertyValue.step = 1;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_tof_gaussian_filter_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_tof_scatter_filter_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_tof_bilateral_filter_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_tof_fly_point_filter_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_tof_median_filter_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_tof_confidence_filter_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_tof_shuffle_mode(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    propertyValue.cur = 0x10;
    propertyValue.max = 0xff;
    propertyValue.min = 0x10;
    propertyValue.def = 0x10;
    propertyValue.step = 1;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_adb_switch(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    char buf[128] = {0};
    char cmd_get_temp[] = "/usrdata/usr/data/arstack/adb_control.sh adb_status";
    strcpy(buf, get_shell(cmd_get_temp)); 
    
    //printf("xavier adb status: %s\n", buf);

    if (!strcmp(buf, "adb_status_on"))
        propertyValue.cur = 1;
    else if (!strcmp(buf, "adb_status_off"))
        propertyValue.cur = 0;
    else
        ERR("adb_status:%s\n", buf);
        
    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_force_upgrade_mode(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    PropertyVal propertyValue = {1,1,0,0,1};

    char buf[128] = {0};
    char cmd_get_temp[] = "fw_printenv orbbec_force_upgrade_flag";
    strcpy(buf, get_shell(cmd_get_temp)); 
    
    if (!strcmp(buf, "orbbec_force_upgrade_flag=y"))
        propertyValue.cur = 1;
    else
        propertyValue.cur = 0;
        
    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}


//设置属性接口
static int32_t protocol_handle_set_tec_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_ldp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_emitter(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    //DBG("set emitter:%d\n", value);
    
    if (value == 1)
    {
        s5k33dxx_illum_power_control(1);
        s_u32EmitterSwitchStatus = 1;
    }
    else
    {
        s5k33dxx_illum_power_control(0);
        s_u32EmitterSwitchStatus = 0;
    }

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_laser_pulse_width(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_laser_current(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint32_t value = 0;
    uint8_t value_A = 0,value_B = 0;

    value = *(uint32_t*)&request->buf.data._data[4];
    
    ret = init_tof_cam_fd();                                 
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _end;
    }
 
    value_A = (uint8_t)((float)value/1000/14.8);
    value_B = 0;

    ret = tof_sensor.set_illum_power(value_A , value_B);  //设置激光电流，B通道的值为0，只设置A通道
    if(ret < 0)
    {
        ERR("set_illum_power failed!\n");
    }

_end:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
}

static int32_t protocol_handle_set_flood(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_flood_level(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_temperature_compensation_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_temperature_calibrated_ir(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_temperature_calibrated_ldmp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_temperature_compensation_coefficient_ir(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_temperature_compensation_coefficient_ldmp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_depth_align(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);

    if(value)
    {
    	s_u32D2CSwitchStatus = 1;
    }
    else
    {
	s_u32D2CSwitchStatus = 0;
    }
	
    ret = protocol_handle_response(request, response, _res);

    return ret;
}


static int32_t protocol_handle_set_tof_fps(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    ret = init_tof_cam_fd();                                 //返回值为负值表示打开tof设备失败
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _end;
    }

    ret = tof_sensor.set_fps((uint8_t )value);               //设置tof帧率
    if(ret < 0)
    {
        ERR("set_fps failed!\n");
    }

_end:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
    return ret;
}

static int32_t protocol_handle_set_tof_mirror(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint32_t value = 0;
    img_rotation_t mode = IMAGE_NORMAL;

    value = *(uint32_t*)&request->buf.data._data[4];

    ret = init_tof_cam_fd();                                 //返回值为负值表示打开tof设备失败
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _end;
    }

    mode = (img_rotation_t)value;

    ret = tof_sensor.set_img_mirror_flip(mode);   //设置tof mirror
    if(ret < 0)
    {
        ERR("set_img_miriror_flip failed!\n");
    }

_end:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
    return ret;
}

static int32_t protocol_handle_set_tof_exposure_time(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint32_t value = 0;
    uint16_t exp_threshold_max = 0,exp_threshold_min = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    ret = init_tof_cam_fd();                                                     //返回值为负值表示打开tof设备失败
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _end;
    }

    ret = tof_sensor.get_exp_threshold(&exp_threshold_max,&exp_threshold_min);   //获取曝光时间上下限
    if(ret < 0)
    {
        ERR("set_exposure_time failed!\n");
	 goto _end;
    }

    //printf("exp_threshold_max is %d\n",exp_threshold_max);
    //printf("exp_threshold_min is %d\n",exp_threshold_min);

    if(value > exp_threshold_max)
    {
         value = exp_threshold_max;
    }
    else if(value < exp_threshold_min)
    {
         value = exp_threshold_min;
    }

    ret = tof_sensor.set_integration_time((uint16_t)value);    //设置tof曝光时间
    if(ret < 0)
    {
        ERR("set_integration_time failed!\n");
    }

_end:
    ret = protocol_handle_response(request, response, (uint16_t)ret);

    return ret;
}

static int32_t protocol_handle_set_tof_gain(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_tof_gaussian_filter_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_tof_scatter_filter_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_tof_bilateral_filter_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_tof_fly_point_filter_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_tof_median_filter_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_tof_confidence_filter_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_tof_shuffle_mode(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_adb_switch(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];
    //DBG("set adb switch::%d\n",value);

    if (value == 1)
        get_shell("/usrdata/usr/data/arstack/adb_control.sh adb_on");
    else
        get_shell("/usrdata/usr/data/arstack/adb_control.sh adb_off");    

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_reboot_device(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    INFO("begin reboot!!\n");
    system("/etc/init.d/arcastpro_restart.sh");

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_factory_reset(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    INFO("todo factory reset complete!!\n");

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_force_upgrade_mode(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];
    if (value == 1)
        system("fw_setenv orbbec_force_upgrade_flag y");
    else
        system("fw_setenv orbbec_force_upgrade_flag n");    

    ret = protocol_handle_response(request, response, _res);

    return ret;
}


//获取自定义数据 函数接口
static int32_t protocol_handle_get_data_versions(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    int32_t int_version[3] = {0};

    SDKVersion sdk;
    sdk.nMajor = 0x01;
    sdk.nMinor = 0x02;
    sdk.nBuild = 0x00;

    Versions v;
    get_int_version(ARIES_APP_VERSION,int_version);    //从字符串版本号中提取出整型版本号
    v.nMajor = (uint8_t)int_version[0];
    v.nMinor = (uint8_t)int_version[1];
    v.nBuild = (uint16_t)int_version[2];

    v.nChip = 0x0601;
    v.nFPGA = 0x0701;
    memcpy(v.nSerialNumber, "1234567890J", sizeof(v.nSerialNumber)/sizeof(unsigned char));
    v.nDeviceType = 0x01;
    v.SDK = sdk;
    v.HWVer = 0x00;
    v.nFWVer = 0x00;
    // v.nChipSerialNumber =
    // v.nRgbSensor =
    // v.nIRSensor =

    memcpy(v.nGitVer, SDK_GIT_VERSION, sizeof(SDK_GIT_VERSION));
    memcpy(v.nBuildTime, COMPILE_TIME, sizeof(COMPILE_TIME));

    ret = protocol_handle_with_data(request, response, (uint8_t*)&v, sizeof(v),_res);

    Versions *vv = (Versions *)response->buf.data.resp.data;
    DBG("return v->nSerialNumber is %s\n", vv->nSerialNumber);

    return ret;
}

static int32_t protocol_handle_get_data_camera_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0xffff;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_get_data_baseline_calibration_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_get_data_multiple_distance_calibration_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_get_data_reference_image(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_get_data_hardware_align_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_get_data_software_align_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0xffff;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_get_data_hardware_distortion_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_get_data_depth_config_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0xffff;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

/*从tof流的EBD获取irTemp和ldmTemp，不从这里获取*/
static int32_t protocol_handle_get_data_device_temperature(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    DeviceTemperature readParam;
    char temp_buf[128] = {0};
    char cmd_get_temp[] ="devmem 0x60632910 32\n";        //获取CPU温度的指令
    int32_t cpu_temp = 0;

    strcpy(temp_buf, get_shell(cmd_get_temp));             //获取执行shell指令后返回的十六进制字符串
    cpu_temp = str_to_int(temp_buf);                      //十六进制字符串转换成十进制整数
    
    readParam.cpuTemp = cpu_temp * 0.4825 - 77.7;         //获取CPU温度	
    readParam.imuTemp = 31.5;
    readParam.irTemp = 32.5;
    readParam.ldmTemp = 33.5;
    readParam.mainBoardTemp = 34.5;
    readParam.tecTemp = 35.5;
	    
    ret = protocol_handle_with_data(request, response, (uint8_t*)&readParam, sizeof(readParam),_res);

    return ret;
}

static int32_t protocol_handle_get_data_device_ae_params(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    AeParams readParam;

    readParam.expTime.max = 3000;
    readParam.expTime.min = 1000;
    readParam.AGain.max = 10;
    readParam.AGain.min = 1;

    readParam.laserCurrent.max = 1000;
    readParam.laserCurrent.min = 0;

    readParam.targetThd =  100;
    readParam.centerWeight = 100;
    readParam.skipFrame = 2;
    readParam.smoothSteps = 2;
    readParam.dealy_ms = 0;
    readParam.meterMethod = 100;
    readParam.expTimeAdj = 30;
    readParam.AGainAdj = 1;
    readParam.laserCurrentAdj = 10;
    readParam.reserve = 0;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&readParam, sizeof(readParam),_res);

    return ret;
}

static int32_t protocol_handle_get_device_upgrade_status(const ProtocolMsg *request, ProtocolMsg *response)
{
    uint16_t _res = 0x0000;

    int32_t ret = 0;
    UpgradeStatus upgrade_status;
    memset(upgrade_status.message, 0x00, 256);
    
    get_firmware_upgrade_status(&upgrade_status.status, &upgrade_status.percentage, upgrade_status.message);
    ret = protocol_handle_with_data(request, response, (uint8_t*)&upgrade_status, sizeof(upgrade_status), _res);

    return ret;
}

static int32_t protocol_handle_get_device_file_tran_status(const ProtocolMsg *request, ProtocolMsg *response)
{
    uint16_t _res = 0x0000;

    int32_t ret = 0;
    UpgradeStatus upgrade_status;
    memset(upgrade_status.message, 0x00, 256);
    get_filetran_status(&upgrade_status.status, &upgrade_status.percentage, upgrade_status.message);

    ret = protocol_handle_with_data(request, response, (uint8_t*)&upgrade_status, sizeof(upgrade_status), _res);
    return ret;
}

static int32_t protocol_handle_get_device_calibration_upgrade_status(const ProtocolMsg *request, ProtocolMsg *response)
{
    uint16_t _res = 0x0000;

    int32_t ret = 0;
    UpgradeStatus upgrade_status;
    memset(upgrade_status.message, 0x00, 256);
    get_calibration_upgrade_status(&upgrade_status.status, &upgrade_status.percentage, upgrade_status.message);

    ret = protocol_handle_with_data(request, response, (uint8_t*)&upgrade_status, sizeof(upgrade_status), _res);
    return ret;
}

static int32_t protocol_handle_get_device_align_upgrade_status(const ProtocolMsg *request, ProtocolMsg *response)
{
    uint16_t _res = 0x0000;

    int32_t ret = 0;
    UpgradeStatus upgrade_status;
    memset(upgrade_status.message, 0x00, 256);
    get_align_upgrade_status(&upgrade_status.status, &upgrade_status.percentage, upgrade_status.message);

    ret = protocol_handle_with_data(request, response, (uint8_t*)&upgrade_status, sizeof(upgrade_status), _res);
    return ret;
}


/*从tof流EBD中获取温度，该接口不使用*/
static int32_t protocol_handle_get_data_tof_rx_temp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    tof_temp readParam;

    readParam.tx_temp = 36.5;
    readParam.rx_temp = 37.5;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&readParam, sizeof(readParam),_res);

    return ret;
}

static int32_t protocol_handle_get_data_tof_modulation_freq(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t modulation_frequency = 0;
    tof_modulation_freq readParam ={2, 0, 0, 0};

    ret = init_tof_cam_fd();                                             //返回值为负值表示打开tof设备失败
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _error;
    }

    ret = tof_sensor.get_modulation_frequency(&modulation_frequency);   //获取激光调制频率，解析16位数据为两个频率
    if(ret < 0)
    {
        ERR("get_modulation_frequency failed!\n");
        goto _error;
    }

    readParam.freq_A =  (modulation_frequency >> 8) & 0xFF; 
    readParam.freq_B =  modulation_frequency & 0xFF;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&readParam, sizeof(readParam),(uint16_t)ret);
    return ret;

_error:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
    return ret;
}

static int32_t protocol_handle_get_data_tof_duty_cycle(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint8_t illum_duty_cycle = 0;
    tof_duty_cycle_info readParam ={2, 0, 0, 0};
    uint8_t array_size = sizeof(duty_cycle_table)/sizeof(float) - 1;

    ret = init_tof_cam_fd();                                     //返回值为负值表示打开tof设备失败
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _error;
    }

    ret = tof_sensor.get_illum_duty_cycle(&illum_duty_cycle);    //获取激光调制占空比，两个freq占空比同步调整，也就是占空比相等
    if(ret < 0)
    {
        ERR("get_illum_duty_cycle failed!\n");
        goto _error;
    }

    if(illum_duty_cycle >= array_size)
    {
          illum_duty_cycle = array_size;
    }
	
    readParam.duty_A = duty_cycle_table[illum_duty_cycle];
    readParam.duty_B = readParam.duty_A;
    ret = protocol_handle_with_data(request, response, (uint8_t*)&readParam, sizeof(readParam),(uint16_t)ret);
    return ret;

_error:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
    return ret;
}

static int32_t protocol_handle_get_data_tof_calibration_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0xffff;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_get_data_tof_depth_coef_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0xffff;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_get_data_tof_vcsel_temp_compensation(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    ObToFTempCompensation readParam;

    readParam.mode = 1;
    readParam.freq_A.vcsel_temp_comp_coeff = 1;
    readParam.freq_A.sensor_temp_comp_coeff = 1;
    readParam.freq_A.temp_dist_offset = 0;

    readParam.freq_B.vcsel_temp_comp_coeff = 2;
    readParam.freq_B.sensor_temp_comp_coeff = 2;
    readParam.freq_B.temp_dist_offset = 0;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&readParam, sizeof(readParam),_res);

    return ret;
}

static int32_t protocol_handle_get_data_tof_gaussian_filter_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    GaussianFilterParam readParam;

    readParam.win_x = 1;
    readParam.win_y = 2;
    readParam.sigma_x = 0.1;
    readParam.sigma_y = 0.2;
    readParam.bypass = 1;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&readParam, sizeof(readParam),_res);

    return ret;
}

static int32_t protocol_handle_get_data_tof_scatter_filter_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0xffff;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_get_data_tof_bilateral_filter_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    BilateralFilterParam readParam;

    readParam.d = 6;
    readParam.sigma_space = 0.234;
    readParam.sigma_color = 1.345;
    readParam.bypass = 1;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&readParam, sizeof(readParam),_res);

    return ret;
}

static int32_t protocol_handle_get_data_tof_fly_point_filter_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    FlyPointFilterParam readParam;

    readParam.thres = 1.234;
    readParam.noise_coeff = 2.456;
    readParam.fill_hole = 1;
    readParam.bypass = 1;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&readParam, sizeof(readParam),_res);

    return ret;
}

static int32_t protocol_handle_get_data_tof_median_filter_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    MedianFilterParam readParam;

    readParam.win_size = 2;
    readParam.bypass = 1;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&readParam, sizeof(readParam),_res);

    return ret;
}

static int32_t protocol_handle_get_data_tof_confidence_filter_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    ConfidenceFilterParam readParam;

    readParam.confidence_thres = 0.12345;
    readParam.bypass = 1;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&readParam, sizeof(readParam),_res);

    return ret;
}

static int32_t protocol_handle_get_data_tof_nearest_farthest_length(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    DepthLenghtParam readParam;

    readParam.nearest_length = 100;
    readParam.farthest_length = 3000;
 
    ret = protocol_handle_with_data(request, response, (uint8_t*)&readParam, sizeof(readParam),(uint16_t)ret);
    return ret;

_end:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
    return ret; 
}

static int32_t protocol_handle_get_data_tof_exposure_threshold_control(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    TofExpThreshold readParam;

    uint16_t exp_threshold_max = 0,exp_threshold_min = 0;
	
    ret = init_tof_cam_fd();                                                                                 //负值表示打开tof设备
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _end;
    }
	
    ret = tof_sensor.get_exp_threshold(&exp_threshold_max,&exp_threshold_min);     //获取曝光时间阈值
    if(ret < 0)
    {
        ERR("get_exp_threshold failed!\n");
	 goto _end;
    }

    readParam.lower = exp_threshold_min;
    readParam.upper = exp_threshold_max;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&readParam, sizeof(readParam),(uint16_t)ret);
    return ret;

_end:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
    return ret; 
}

//设置自定义数据接口
static int32_t protocol_handle_set_data_camera_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0xffff;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_baseline_calibration_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_data_multiple_distance_calibration_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_data_reference_image(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_data_hardware_align_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_data_software_align_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0xffff;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_hardware_distortion_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0002;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_data_depth_config_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0xffff;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_device_ae_params(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0000;
    AeParams *writeParam = (AeParams *)&request->buf.data._data[4];
    DBG("expTime.max:%d\n\
    expTime.min:%d\n\
    AGain.max:%d\n\
    AGain.min:%d\n\
    laserCurrent.max:%d\n\
    laserCurrent.min:%d\n\
    targetBrightness：%d\n\
    targetThd:%d\n\
    centerWeight:%d\n\
    skipFrame:%d\n\
    smoothSteps:%d\n\
    dealy_ms:%d\n\
    meterMethod:%d\n\
    expTimeAdj:%d\n\
    AGainAdj:%d\n\
    laserCurrentAdj:%d\n\
    reserve:%d\n",\
    writeParam->expTime.max,\
    writeParam->expTime.min,\
    writeParam->AGain.max,\
    writeParam->AGain.min,\
    writeParam->laserCurrent.max,\
    writeParam->laserCurrent.min,\
    writeParam->targetBrightness,\
    writeParam->targetThd,\
    writeParam->centerWeight,\
    writeParam->skipFrame,\
    writeParam->smoothSteps,\
    writeParam->dealy_ms,\
    writeParam->meterMethod,\
    writeParam->expTimeAdj,\
    writeParam->AGainAdj,\
    writeParam->laserCurrentAdj,\
    writeParam->reserve);

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_tof_modulation_freq(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t value = 0;
    uint8_t freq_A = 0,freq_B = 0;
    tof_modulation_freq writeParam ={2, 0, 0, 0};  

    writeParam = *(tof_modulation_freq*)&request->buf.data._data[4];
    freq_A = (uint8_t) writeParam.freq_A;              
    freq_B = (uint8_t) writeParam.freq_B;
    value = (uint16_t)freq_A<<8 | freq_B;
	
    printf("--------protocol_handle_set_data_tof_modulation_freq-----------=%d\n",value);

    ret = init_tof_cam_fd();                           //返回值为负值表示打开tof设备失败     
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _end;
    }

    ret = tof_sensor.set_modulation_frequency(value);  //设置激光调制频率，取两个频率合成一个16位的数据
    if(ret < 0)
    {
        ERR("set_modulation_frequency failed!\n");
    }

_end:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
    return ret;
}


static uint8_t get_value_from_duty_table(float value)
{
	uint8_t cnt = 0, array_size = 0;
	uint8_t ret = 0;
	float temp_value = 0.0;
	float temp_value_next = 0.0;

	array_size =  sizeof(duty_cycle_table)/sizeof(float) - 1;
	
	for(cnt = 0; cnt < array_size; cnt++)
	{
	      if(value > duty_cycle_table[array_size])
	      {
                  return array_size;
	      }
	      else if((value >= duty_cycle_table[cnt])&&(value <= duty_cycle_table[cnt+1]))
	      {
                  temp_value =  fabs(value - duty_cycle_table[cnt]);
	          temp_value_next = fabs(value - duty_cycle_table[cnt+1]);
		  return temp_value < temp_value_next ? cnt : cnt+1;
	      }
	}
       return ret;
}

static int32_t protocol_handle_set_data_tof_duty_cycle(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint8_t value = 0;
    tof_duty_cycle_info writeParam ={2, 0, 0, 0};
    writeParam = *(tof_duty_cycle_info*)&request->buf.data._data[4];

    value = get_value_from_duty_table(writeParam.duty_A);

    ret = init_tof_cam_fd();                       //返回值为负值表示打开tof设备失败 
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _end;
    }


    ret = tof_sensor.set_illum_duty_cycle(value);  //设置激光调制占空比，两个freq占空比同步调整，也就是占空比相等
    if(ret < 0)
    {
        ERR("set_illum_duty_cycle failed!\n");
    }

_end:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
    return ret;
}

static int32_t protocol_handle_set_data_tof_calibration_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0xffff;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_tof_depth_coef_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0xffff;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_tof_vcsel_temp_compensation(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    ObToFTempCompensation *writeParam = (ObToFTempCompensation *)&request->buf.data._data[4];
    DBG("mode:%d\n\
    freq_A.vcsel_temp_comp_coeff:%f\n\
    freq_A.sensor_temp_comp_coeff:%f\n\
    freq_A.temp_dist_offset:%f\n\
    freq_B.vcsel_temp_comp_coeff:%f\n\
    freq_B.sensor_temp_comp_coeff:%f\n\
    freq_B.temp_dist_offset:%f\n",\
    writeParam->mode,\
    writeParam->freq_A.vcsel_temp_comp_coeff,\
    writeParam->freq_A.sensor_temp_comp_coeff,\
    writeParam->freq_A.temp_dist_offset,\
    writeParam->freq_B.vcsel_temp_comp_coeff,\
    writeParam->freq_B.sensor_temp_comp_coeff,\
    writeParam->freq_B.temp_dist_offset);

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_tof_gaussian_filter_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    GaussianFilterParam *writeParam = (GaussianFilterParam *)&request->buf.data._data[4];
    DBG("win_x:%d\n\
    win_y:%d\n\
    sigma_x:%f\n\
    sigma_y:%f\n\
    bypass:%d\n",\
    writeParam->win_x,\
    writeParam->win_y,\
    writeParam->sigma_x,\
    writeParam->sigma_y,\
    writeParam->bypass);

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_tof_scatter_filter_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0xffff;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_tof_bilateral_filter_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    BilateralFilterParam *writeParam = (BilateralFilterParam *)&request->buf.data._data[4];
    DBG("d:%d\n\
    sigma_space:%f\n\
    sigma_color:%f\n\
    bypass:%d\n",\
    writeParam->d,\
    writeParam->sigma_space,\
    writeParam->sigma_color,\
    writeParam->bypass);

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_tof_fly_point_filter_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    FlyPointFilterParam *writeParam = (FlyPointFilterParam *)&request->buf.data._data[4];
    DBG("thres:%f\n\
    noise_coeff:%f\n\
    fill_hole:%d\n\
    bypass:%d\n",\
    writeParam->thres,\
    writeParam->noise_coeff,\
    writeParam->fill_hole,\
    writeParam->bypass);

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_tof_median_filter_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    MedianFilterParam *writeParam = (MedianFilterParam *)&request->buf.data._data[4];
    DBG("win_size:%d\n\
    bypass:%d\n",\
    writeParam->win_size,\
    writeParam->bypass);

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_tof_confidence_filter_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    ConfidenceFilterParam *writeParam = (ConfidenceFilterParam *)&request->buf.data._data[4];
    DBG("confidence_thres:%f\n\
    bypass:%d\n",\
    writeParam->confidence_thres,\
    writeParam->bypass);

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_tof_nearest_farthest_length(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;

    DepthLenghtParam *writeParam = (DepthLenghtParam *)&request->buf.data._data[4];
    DBG("nearest_length:%d\n  farthest_length:%d\n",writeParam->nearest_length,writeParam->farthest_length);

_end:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
    return ret;     
}


static int32_t protocol_handle_set_data_tof_exposure_threshold_control(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t exp_threshold_max = 0,exp_threshold_min = 0;

    TofExpThreshold *writeParam = (TofExpThreshold *)&request->buf.data._data[4];
   // DBG("nearest_length:%d\n  farthest_length:%d\n",writeParam->nearest_length,writeParam->farthest_length);

    exp_threshold_min = (uint16_t)writeParam->lower;
    exp_threshold_max = (uint16_t)writeParam->upper;

    if(exp_threshold_min > exp_threshold_max)
    {
       exp_threshold_min = exp_threshold_max;
    }

    ret = init_tof_cam_fd();                                                 
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _end;
    }

    ret = tof_sensor.set_exp_threshold(exp_threshold_max,exp_threshold_min);        //设置曝光时间阈值
    if(ret < 0)
    {
        ERR("set_exp_threshold failed!\n");
    }

_end:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
    return ret;     
}

/*****************************************************************************
*   Prototype    : protocol_handle_get_property
*   Description  : orbbec protocol get property
*   Input        :const ProtocolMsg *request  
*                  ProtocolMsg *response                                   
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
static int32_t protocol_handle_get_property(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint32_t *propertyID = NULL;

    propertyID = (uint32_t*)request->buf.data._data;
    //DBG(":: propertyID:0x%x)\n", *propertyID);

    switch(*propertyID)
    {
        case OB_DEVICE_PROPERTY_ID_FLASH_WRITE_PROTECTION:  //FLASH写保护开关；0，关闭；1，开启
            ret = protocol_handle_get_flash_write_protection(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TEC_ENABLE:              // TEC开关
            ret = protocol_handle_get_tec_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_LDP:                     //LDP开关
            ret = protocol_handle_get_ldp(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_EMITTER:                 // 激光开光
            ret = protocol_handle_get_emitter(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_LASER_PULSE_WIDTH:       // 激光Time值（脉宽）
            ret = protocol_handle_get_laser_pulse_width(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_LASER_CURRENT:           //激光电流
            ret = protocol_handle_get_laser_current(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_FLOOD:                   // 泛光灯开关
            ret = protocol_handle_get_flood(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_FLOOD_LEVEL:             // 泛光灯等级
            ret = protocol_handle_get_flood_level(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TEMPERATURE_COMPENSATION_ENABLE:            //温度补偿开关
            ret = protocol_handle_get_temperature_compensation_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TEMPERATURE_CALIBRATED_IR:                  //IR标定温度
            ret = protocol_handle_get_temperature_calibrated_ir(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TEMPERATURE_CALIBRATED_LDMP:                // 激光标定温度
            ret = protocol_handle_get_temperature_calibrated_ldmp(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TEMPERATURE_COMPENSATION_COEFFICIENT_IR:    // IR温补系数
            ret = protocol_handle_get_temperature_compensation_coefficient_ir(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TEMPERATURE_COMPENSATION_COEFFICIENT_LDMP:  // 激光温补系数
            ret = protocol_handle_get_temperature_compensation_coefficient_ldmp(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_DEPTH_ALIGN:                // D2C开关
            ret = protocol_handle_get_depth_align(request, response);
            break;
        
        case OB_DEVICE_PROPERTY_ID_TOF_FPS:                    // tof帧率
            ret = protocol_handle_get_tof_fps(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_MIRROR:                 // tof sensor镜像
            ret = protocol_handle_get_tof_mirror(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_EXPOSURE_TIME:          // tof 曝光时间
            ret = protocol_handle_get_tof_exposure_time(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_GAIN:                   // tof 增益
            ret = protocol_handle_get_tof_gain(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_GAUSSIAN_FILTER:        // tof 高斯噪声滤波器开关
            ret = protocol_handle_get_tof_gaussian_filter_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_SCATTER_FILTER:        // tof 散射滤波器开关
            ret = protocol_handle_get_tof_scatter_filter_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_BILATERAL_FILTER:      // tof 双边波器开关
            ret = protocol_handle_get_tof_bilateral_filter_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_FLY_POINT_FILTER:      // tof Fly Point波器开关
            ret = protocol_handle_get_tof_fly_point_filter_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_MEDIAN_FILTER:         // tof 中值波器开关
            ret = protocol_handle_get_tof_median_filter_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_CONFIDENCE_FILTER:     // tof 置信波器开关
            ret = protocol_handle_get_tof_confidence_filter_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_SHUFFLE_MODE:         //tof Phase Shuffle模式
            ret = protocol_handle_get_tof_shuffle_mode(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_ADB_FUNCTION_CONTROL:     //get adb开关
            ret = protocol_handle_get_adb_switch(request, response);
            break;
        
        case OB_DEVICE_PROPERTY_ID_FORCE_UPGRADE_MODE:       //get force upgrade mode
            ret = protocol_handle_get_force_upgrade_mode(request, response);
            break;

        default:
            ERR("protocol_handle_get_property,propertyID:%d\n", *propertyID);
            ret = protocol_handle_default(request, response);
            break;
    }

    return ret;
}

/*****************************************************************************
*   Prototype    : protocol_handle_set_property
*   Description  : orbbec protocol set property
*   Input        :const ProtocolMsg *request
*                  ProtocolMsg *response
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
static int32_t protocol_handle_set_property(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint32_t *propertyID = NULL;

    propertyID = (uint32_t*)&request->buf.data._data[0];
    //DBG(":: propertyID:0x%x)\n", *propertyID);

    switch(*propertyID)
    {
        case OB_DEVICE_PROPERTY_ID_TEC_ENABLE:
            ret = protocol_handle_set_tec_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_LDP:
            ret = protocol_handle_set_ldp(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_EMITTER:
            ret = protocol_handle_set_emitter(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_LASER_PULSE_WIDTH:
            ret = protocol_handle_set_laser_pulse_width(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_LASER_CURRENT:
            ret = protocol_handle_set_laser_current(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_FLOOD:
            ret = protocol_handle_set_flood(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_FLOOD_LEVEL:
           ret = protocol_handle_set_flood_level(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TEMPERATURE_COMPENSATION_ENABLE:
            ret = protocol_handle_set_temperature_compensation_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TEMPERATURE_CALIBRATED_IR:
            ret = protocol_handle_set_temperature_calibrated_ir(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TEMPERATURE_CALIBRATED_LDMP:
            ret = protocol_handle_set_temperature_calibrated_ldmp(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TEMPERATURE_COMPENSATION_COEFFICIENT_IR:
            ret = protocol_handle_set_temperature_compensation_coefficient_ir(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_DEPTH_ALIGN:       // D2C开关
            ret = protocol_handle_set_depth_align(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_FPS:
            ret = protocol_handle_set_tof_fps(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_MIRROR:
            ret = protocol_handle_set_tof_mirror(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_EXPOSURE_TIME:
            ret = protocol_handle_set_tof_exposure_time(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_GAIN:
            ret = protocol_handle_set_tof_gain(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_GAUSSIAN_FILTER:
            ret = protocol_handle_set_tof_gaussian_filter_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_SCATTER_FILTER:
            ret = protocol_handle_set_tof_scatter_filter_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_BILATERAL_FILTER:
            ret = protocol_handle_set_tof_bilateral_filter_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_FLY_POINT_FILTER:
            ret = protocol_handle_set_tof_fly_point_filter_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_MEDIAN_FILTER:
            ret = protocol_handle_set_tof_median_filter_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_CONFIDENCE_FILTER:
            ret = protocol_handle_set_tof_confidence_filter_enable(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_SHUFFLE_MODE:
            ret = protocol_handle_set_tof_shuffle_mode(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_ADB_FUNCTION_CONTROL:  //set adb switch
            ret = protocol_handle_set_adb_switch(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_REBOOT_DEVICE:       //重启设备
            ret = protocol_handle_reboot_device(request, response);
            break;
        
        case OB_DEVICE_PROPERTY_ID_FACTORY_RESET:       //恢复出产设置
            ret = protocol_handle_factory_reset(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_FORCE_UPGRADE_MODE:  //设置设备强制升级模式
            ret = protocol_handle_set_force_upgrade_mode(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_FLASH_WRITE_PROTECTION:
        case OB_DEVICE_PROPERTY_ID_TEMPERATURE_COMPENSATION_COEFFICIENT_LDMP:
        default:
            ERR("protocol_handle_set_property,propertyID:%d\n", *propertyID);
            ret = protocol_handle_default(request, response);
            break;
    }

    return ret;
}

/*****************************************************************************
*   Prototype    : protocol_handle_get_firmware_data
*   Description  : orbbec protocol get firmware_data
*   Input        :const ProtocolMsg *request  
*                  ProtocolMsg *response                                   
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
static int32_t protocol_handle_get_firmware_data(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint32_t *propertyID=NULL;

    propertyID = (uint32_t*)request->buf.data._data;
    // DBG(":: propertyID:0x%x)\n", *propertyID);

    switch(*propertyID)
    {
        case OB_DATA_TYPE_VERSIONS: // 版本信息
            ret = protocol_handle_get_data_versions(request, response);
            break;

        case OB_DATA_TYPE_CAMERA_PARA:                  // 相机内外参数
            ret = protocol_handle_get_data_camera_para(request, response);
            break;

        case OB_DATA_TYPE_BASELINE_CALIBRATION_PARA:   // 基线标定参数
            ret = protocol_handle_get_data_baseline_calibration_para(request, response);
            break;

        case OB_DATA_TYPE_MULTIPLE_DISTANCE_CALIBRATION_PARA:       // 多距离标定参数
            ret = protocol_handle_get_data_multiple_distance_calibration_para(request, response);
            break;

        case OB_DATA_TYPE_REFERENCE_IMAGE:                          // 参考图
            ret = protocol_handle_get_data_reference_image(request, response);
            break;

        case OB_DATA_TYPE_HARDWARE_ALIGN_PARA:        // 硬件对齐参数
            ret = protocol_handle_get_data_hardware_align_para(request, response);
            break;

        case OB_DATA_TYPE_SOFTWARE_ALIGN_PARA:       // 软件对齐参数
            ret = protocol_handle_get_data_software_align_para(request, response);
            break;

        case OB_DATA_TYPE_HARDWARE_DISTORTION_PARA:  // 硬件去畸变参数
            ret = protocol_handle_get_data_hardware_distortion_para(request, response);
            break;

        case OB_DATA_TYPE_DEPTH_CONFIG_PARA:         // Config区
            ret = protocol_handle_get_data_depth_config_para(request, response);
            break;

        case OB_DATA_TYPE_DEVICE_TEMPERATURE:        // 设备温度信息
            ret = protocol_handle_get_data_device_temperature(request, response);
            break;

        case OB_DATA_TYPE_DEVICE_AE_PARAMS:          // AE调试参数
            ret = protocol_handle_get_data_device_ae_params(request, response);
            break;
        case OB_DATA_TYPE_DEVICE_UPGRADE_STATUS:     // 读固件升级进度信息
            ret = protocol_handle_get_device_upgrade_status(request, response);
            break;
        case OB_DATA_TYPE_DEVICE_CALIBRATION_UPGRADE_STATUS:   // 读标定升级进度信息
            ret = protocol_handle_get_device_calibration_upgrade_status(request, response);
            break;
        case OB_DATA_TYPE_DEVICE_FILE_TRAN_STATUS:   // 读取文件传输状态
            ret = protocol_handle_get_device_file_tran_status(request, response);
            break;
        
        case OB_DATA_TYPE_DEVICE_ALIGN_UPGRADE_STATUS:  //读取对齐标定文件的传输状态
            ret = protocol_handle_get_device_align_upgrade_status(request, response);
            break;


        case OB_DATA_TYPE_TOF_TX_RX_TEMP:            // tof tx rx温度信息
            ret = protocol_handle_get_data_tof_rx_temp(request, response);
            break;

        case OB_DATA_TYPE_TOF_MODULATION_FREQ:       // tof 调制频率
            ret = protocol_handle_get_data_tof_modulation_freq(request, response);
            break;

        case OB_DATA_TYPE_TOF_DUTY_CYCLE:            // tof 调制信号占空比
            ret = protocol_handle_get_data_tof_duty_cycle(request, response);
            break;

        case OB_DATA_TYPE_TOF_CALIBRATION_PARA:      // tof 标定参数
            ret = protocol_handle_get_data_tof_calibration_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_DEPTH_COEF_PARA:       // tof 距离转深度系数
            ret = protocol_handle_get_data_tof_depth_coef_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_VCSEL_TEMP_COMPENSATION:   // tof 温补系数
            ret = protocol_handle_get_data_tof_vcsel_temp_compensation(request, response);
            break;

        case OB_DATA_TYPE_TOF_GAUSSIAN_FILTER_PARA:      // tof 高斯噪声滤波参数
            ret = protocol_handle_get_data_tof_gaussian_filter_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_SCATTER_FILTER_PARA:       // tof 散射滤波参数
            ret = protocol_handle_get_data_tof_scatter_filter_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_BILATERAL_FILTER_PARA:     // tof 双边滤波参数
            ret = protocol_handle_get_data_tof_bilateral_filter_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_FLY_POINT_FILTER_PARA:     // tof Fly Point滤波参数
            ret = protocol_handle_get_data_tof_fly_point_filter_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_MEDIAN_FILTER_PARA:        // tof 中值滤波参数
            ret = protocol_handle_get_data_tof_median_filter_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_CONFIDENCE_FILTER_PARA:    // tof 置信滤波参数
            ret = protocol_handle_get_data_tof_confidence_filter_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_NEAREST_FARTHEST_LENGTH:   // tof 最近最远距离
            ret = protocol_handle_get_data_tof_nearest_farthest_length(request, response);
            break;

        case OB_DATA_TYPE_TOF_EXPOSURE_THRESHOLD_CONTROL: // 获取tof曝光时间阈值
            ret = protocol_handle_get_data_tof_exposure_threshold_control(request, response);
            break;


        default:
            ERR("protocol_handle_get_firmware_data,propertyID:%d\n", *propertyID);
            ret = protocol_handle_default(request, response);
            break;
    }

    return ret;
}


/*****************************************************************************
*   Prototype    : protocol_handle_set_firmware_data
*   Description  : orbbec protocol set firmware_data
*   Input        :const ProtocolMsg *request  
*                  ProtocolMsg *response                                   
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
static int32_t protocol_handle_set_firmware_data(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint32_t *propertyID=NULL;

    propertyID = (uint32_t*)request->buf.data._data;
    //DBG(":: propertyID:0x%x)\n", *propertyID);

    switch(*propertyID)
    {
        case OB_DATA_TYPE_CAMERA_PARA:                  // 相机内外参数
            ret = protocol_handle_set_data_camera_para(request, response);
            break;

        case OB_DATA_TYPE_BASELINE_CALIBRATION_PARA:   // 基线标定参数
            ret = protocol_handle_set_data_baseline_calibration_para(request, response);
            break;

        case OB_DATA_TYPE_MULTIPLE_DISTANCE_CALIBRATION_PARA:       // 多距离标定参数
            ret = protocol_handle_set_data_multiple_distance_calibration_para(request, response);
            break;

        case OB_DATA_TYPE_REFERENCE_IMAGE:                          // 参考图
            ret = protocol_handle_set_data_reference_image(request, response);
            break;

        case OB_DATA_TYPE_HARDWARE_ALIGN_PARA:        // 硬件对齐参数
            ret = protocol_handle_set_data_hardware_align_para(request, response);
            break;

        case OB_DATA_TYPE_SOFTWARE_ALIGN_PARA:       // 软件对齐参数
            ret = protocol_handle_set_data_software_align_para(request, response);
            break;

        case OB_DATA_TYPE_HARDWARE_DISTORTION_PARA:  // 硬件去畸变参数
            ret = protocol_handle_set_data_hardware_distortion_para(request, response);
            break;

        case OB_DATA_TYPE_DEPTH_CONFIG_PARA:         // Config区
            ret = protocol_handle_set_data_depth_config_para(request, response);
            break;

        case OB_DATA_TYPE_DEVICE_AE_PARAMS:          // AE调试参数
            ret = protocol_handle_set_data_device_ae_params(request, response);
            break;

        case OB_DATA_TYPE_TOF_MODULATION_FREQ:       // tof 调制频率
            ret = protocol_handle_set_data_tof_modulation_freq(request, response);
            break;

        case OB_DATA_TYPE_TOF_DUTY_CYCLE:            // tof 调制信号占空比
            ret = protocol_handle_set_data_tof_duty_cycle(request, response);
            break;

        case OB_DATA_TYPE_TOF_CALIBRATION_PARA:      // tof 标定参
            ret = protocol_handle_set_data_tof_calibration_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_DEPTH_COEF_PARA:       // tof 距离转深度系数
            ret = protocol_handle_set_data_tof_depth_coef_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_VCSEL_TEMP_COMPENSATION:   // tof 温补系数
            ret = protocol_handle_set_data_tof_vcsel_temp_compensation(request, response);
            break;

        case OB_DATA_TYPE_TOF_GAUSSIAN_FILTER_PARA:      // tof 高斯噪声滤波参数
            ret = protocol_handle_set_data_tof_gaussian_filter_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_SCATTER_FILTER_PARA:       // tof 散射滤波参数
            ret = protocol_handle_set_data_tof_scatter_filter_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_BILATERAL_FILTER_PARA:     // tof 双边滤波参数
            ret = protocol_handle_set_data_tof_bilateral_filter_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_FLY_POINT_FILTER_PARA:     // tof Fly Point滤波参数
            ret = protocol_handle_set_data_tof_fly_point_filter_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_MEDIAN_FILTER_PARA:        // tof 中值滤波参数
            ret = protocol_handle_set_data_tof_median_filter_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_CONFIDENCE_FILTER_PARA:    // tof 置信滤波参数
            ret = protocol_handle_set_data_tof_confidence_filter_para(request, response);
            break;

        case OB_DATA_TYPE_TOF_NEAREST_FARTHEST_LENGTH:   // tof 最近最远距离
            ret = protocol_handle_set_data_tof_nearest_farthest_length(request, response);
            break;

        case OB_DATA_TYPE_TOF_EXPOSURE_THRESHOLD_CONTROL:   // 设置tof曝光时间阈值
            ret = protocol_handle_set_data_tof_exposure_threshold_control(request, response);
            break;


        default:
            ERR("protocol_handle_set_firmware_data,propertyID:%d\n", *propertyID);
            ret = protocol_handle_default(request, response);
            break;
    }

    return ret;
}
/*****************************************************************************
*   Prototype    : ob_protocol_process
*   Description  : orbbec protocol process function
*   Input        : ob_device *dev
*                  const ProtocolMsg *request
*                  ProtocolMsg *response
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_protocol_process(ob_device *dev, const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;

	if ((NULL == dev) || (NULL == request) || (NULL == response))
	{
		ERR("param is NULL, dev:%p, request:%p, respose:%p\n", dev, request, response);
		return -1;
	}

    //DBG("xavier, Recv OpCode:0x%02d(%d), nId:0x%02d(%d)\n", request->header.nOpcode, request->header.nOpcode, request->header.nId, request->header.nId);

    switch (request->header.nOpcode)
    {
        case OPCODE_GET_PROPERTY:
            ret = protocol_handle_get_property(request, response);
            break;

        case OPCODE_SET_PROPERTY:
            ret = protocol_handle_set_property(request, response);
            break;

        case OPCODE_GET_FIRMWARE_DATA:
            ret = protocol_handle_get_firmware_data(request, response);
            break;

        case OPCODE_SET_FIRMWARE_DATA:
            ret = protocol_handle_set_firmware_data(request, response);
            break;

        default:
            ERR("protocol_handle_default,opcode:%d\n", request->header.nOpcode);
            ret = protocol_handle_default(request, response);
            break;
    }

	//printf("\n");

    return ret;
}

