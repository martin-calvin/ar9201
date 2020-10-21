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
*       2.  Date         : 2020/7/10
*           Author       : martin
*           Modification : add new function
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

#include <regex>
#include <iostream>
#include <string>

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

#include "Mx6300_ctl.h"
#include "tof_stream.h"
#include "d2c_arith.h"
#include "obc_sl_drv.h"
#include "obc_tof_dsp_icc.h"
#include "uvc_service2.h"


using namespace std;
/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
#define MX6300_FIRMWARE                              0
#define MX6300_REFERENCE_PICTURE                     1
#define MX6300_CAMERA_CFG_PARAMETER_960_1280         2
#define MX6300_CAMERA_CFG_PARAMETER_720_1280         3

#define ORBBEC_SUCCESS     0
#define ORBBEC_FAILED     -1

/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/

//bit0: calibra
//bit1: d2c(SW)
//bit2: d2c(HW)
extern u16 g_rgb_crop_flag; //rgb裁剪标志(rw)  


/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/
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
/*****************************************************************************
*   Prototype    : orbbec_saveFile
*   Description  : orbbec save file
*   Input        : const char *file
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
static int32_t orbbec_saveFile(const char *filename, const void *p, uint32_t size)
{
    FILE *fp;

    if (!strcmp(filename, "-"))
    {
        fp = stdout;
    }
    else
    {
        fp = fopen(filename, "w");
        if (fp == NULL)
        {
            ERR("creat file failed\n");
            return -1;
        }
    }
    //printf("process_image size: %d\n", size);

    fwrite(p, size, 1, fp);
    fflush(fp);
    fclose(fp);

    return ORBBEC_SUCCESS;
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
    uint16_t _res = ACK_OB_SUCCESS;
    PropertyVal propertyValue = {1,1,0,0,1};

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_tec_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    uint8_t value = 0;
    PropertyVal propertyValue;
    Mx6300_get_tec_enable(&value);
    propertyValue.cur = (uint32_t)value;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}

static int32_t protocol_handle_get_ldp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;
    
    uint8_t value = 0;
    Mx6300_get_ldp_enable(&value);
    propertyValue.cur = (int32_t)value;    

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}

static int32_t protocol_handle_get_emitter(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    PropertyVal propertyValue;

    uint8_t value = 0;
    Mx6300_get_laser_status(&value);
    propertyValue.cur = (int32_t)value;
    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_laser_pulse_width(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;
    PropertyVal propertyValue = {1,1,0,0,1};

    // uint32_t value=0;
    // propertyValue.max = 3000;
    // propertyValue.min = 1000;
    // propertyValue.def = 3000;
    // propertyValue.step = 100;
    // Mx6300_get_laser_time(&value);
    // propertyValue.cur = value;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_laser_current(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    PropertyVal propertyValue;
    uint32_t temp_value = 0;

    float lasetCurrent_max = 358;
    float lasetCurrent_min = 1.954;
    float lasetCurrent_def = 200;
    float lasetCurrent_step = 2.8;

    propertyValue.max = (uint32_t)(lasetCurrent_max * 1000);
    propertyValue.min = (uint32_t)(lasetCurrent_min * 1000);
    propertyValue.def = (uint32_t)(lasetCurrent_def * 1000);
    propertyValue.step = (uint32_t)(lasetCurrent_step * 1000);

    Mx6300_get_laser_current(&temp_value);
    propertyValue.cur = (uint32_t)temp_value;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_flood(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}

static int32_t protocol_handle_get_flood_level(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}

static int32_t protocol_handle_get_temperature_compensation_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint8_t value;
    PropertyVal propertyValue;
    Mx6300_get_tca_enable(&value);
    propertyValue.cur = value;
    ret = protocol_handle_with_data(request, response, (uint8_t *)&propertyValue, sizeof(propertyValue), _res);
    return ret;
}

static int32_t protocol_handle_get_temperature_calibrated_ir(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
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
    uint16_t _res = ACK_OB_SUCCESS;
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
    uint16_t _res = ACK_OB_SUCCESS; 

    ret = protocol_handle_response(request, response, _res);
    return ret;
}


static int32_t protocol_handle_get_temperature_compensation_coefficient_ldmp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
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
    uint16_t _res = ACK_OB_SUCCESS;

    PropertyVal propertyValue;
    propertyValue.cur = ob_streamControl.depthSoftD2C_enable;
    ret = protocol_handle_with_data(request, response, (uint8_t *)&propertyValue, sizeof(propertyValue), _res);
    return ret;
}

static int32_t protocol_handle_get_depth_mirror(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint8_t value;
    
    PropertyVal propertyValue;

    Mx6300_get_depth_mirror(&value);
    propertyValue.cur = value;
    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_depth_flip(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_depth_postfilter(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_depth_holefilter(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_ir_mirror(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_ir_flip(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_ir_switch(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_hardware_sync(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_min_depth(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    PropertyVal propertyValue;
    propertyValue.cur = (uint32_t)ob_streamControl.depth_MinValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_max_depth(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;
    propertyValue.cur = (uint32_t)ob_streamControl.depth_MaxValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_depth_soft_filter(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    PropertyVal propertyValue;
    propertyValue.cur = (uint32_t)ob_streamControl.softfilter_Param.softfilterEnable;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_zero_plane_distance(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    PropertyVal propertyValue;

    FILE *Param_data = fopen(cfgParameter_960_1280, "rb");
    if (Param_data == NULL)
    {
        propertyValue.cur = 0;
        INFO("z0 param file cannot be found!\n");
    }
    else
    {
        Doraemon_Content_t *doraemon_d2c_param = (Doraemon_Content_t *)malloc(sizeof(Doraemon_Content_t));
        memset(doraemon_d2c_param, 0, sizeof(doraemon_d2c_param));

        fread(doraemon_d2c_param, sizeof(char), sizeof(Doraemon_Content_t), Param_data);
        propertyValue.cur = doraemon_d2c_param->disparity2depthparams.fZeroPlaneDistance * pow(10, 4); //float Expand 10^4

        fclose(Param_data);
        free(doraemon_d2c_param);
    }

    ret = protocol_handle_with_data(request, response, (uint8_t *)&propertyValue, sizeof(propertyValue), _res);
    return ret;
}
static int32_t protocol_handle_get_zero_plane_pixel_size(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    PropertyVal propertyValue;

    FILE *Param_data = fopen(cfgParameter_960_1280, "rb");
    if (Param_data == NULL)
    {
        propertyValue.cur = 0;
        INFO("zpps param file cannot be found!\n");
    }
    else
    {
        Doraemon_Content_t *doraemon_d2c_param = (Doraemon_Content_t *)malloc(sizeof(Doraemon_Content_t));
        memset(doraemon_d2c_param, 0, sizeof(doraemon_d2c_param));

        fread(doraemon_d2c_param, sizeof(char), sizeof(Doraemon_Content_t), Param_data);
        propertyValue.cur = doraemon_d2c_param->disparity2depthparams.fZeroPlanePixelSize * pow(10, 8); //double Expand 10^8

        fclose(Param_data);
        free(doraemon_d2c_param);
    }

    ret = protocol_handle_with_data(request, response, (uint8_t *)&propertyValue, sizeof(propertyValue), _res);
    return ret;
}
static int32_t protocol_handle_get_property_id_chip_type(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_usb_speed(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_soft_reset(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_ldp_thres_up(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_ldp_thres_low(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_lap_status(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    PropertyVal propertyValue;
    uint8_t value = 0;
    Mx6300_get_ldp_protect_status(&value);
    propertyValue.cur = (int32_t)value;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_tec_data(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_laset_temperature(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;
    Componet_temp temp;
    memset(&propertyValue, 0, sizeof(propertyValue));
    memset(&temp, 0, sizeof(temp));
    
    Mx6300_get_componet_temp(&temp);
    propertyValue.cur = temp.ldm_temp;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_bootloader_write_protection_status(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_rt_ir_temp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;
    Componet_temp temp;
    memset(&propertyValue, 0, sizeof(propertyValue));
    memset(&temp, 0, sizeof(temp));
    
    Mx6300_get_componet_temp(&temp);
    propertyValue.cur = temp.ir_temp;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_rt_ldmp_temp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;
    Componet_temp temp;
    memset(&propertyValue, 0, sizeof(propertyValue));
    memset(&temp, 0, sizeof(temp));
    
    Mx6300_get_componet_temp(&temp);
    propertyValue.cur = temp.ldm_temp;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_rt_rgb_temp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;
    Componet_temp temp;
    memset(&propertyValue, 0, sizeof(propertyValue));
    memset(&temp, 0, sizeof(temp));
    
    Mx6300_get_componet_temp(&temp);
    propertyValue.cur = temp.rgb_temp;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_version_mx6300(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_mx6300_start_time(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_gpm_config_data(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_gpm_status_data(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}
static int32_t protocol_handle_get_product_number(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    PropertyVal propertyValue;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);
    return ret;
}

static int32_t protocol_handle_get_max_diff(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    PropertyVal propertyValue;
    propertyValue.cur = ob_streamControl.softfilter_Param.maxDiff;

    ret = protocol_handle_with_data(request, response, (uint8_t *)&propertyValue, sizeof(propertyValue), _res);
    return ret;
}

static int32_t protocol_handle_get_maxspeckle_size(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    PropertyVal propertyValue;
    propertyValue.cur = ob_streamControl.softfilter_Param.maxSpeckleSize;

    ret = protocol_handle_with_data(request, response, (uint8_t *)&propertyValue, sizeof(propertyValue), _res);
    return ret;
}

static int32_t protocol_handle_get_depth_align_hardware(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint8_t value;
    PropertyVal propertyValue;
    Mx6300_get_depth_d2c_mode(&value);
    propertyValue.cur = value;
    ret = protocol_handle_with_data(request, response, (uint8_t *)&propertyValue, sizeof(propertyValue), _res);
    return ret;
}

static int32_t protocol_handle_get_rgb_timestamp_offset(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    PropertyVal propertyValue;
    int iGetParam = 0;

    uvc_server_t *pService = get_uvc_server();
    if (NULL == pService){
        ERR("pService is NULL.\n");
        return -1;
    }
    if (NULL != pService->cmd_cb)
        pService->cmd_cb(OB_RGB_TIMESTAMP_OFFSET_GET, (void *)&iGetParam);
    DBG("get rgb timestamp offset:%dms\n", iGetParam);

    memset(&propertyValue, 0, sizeof(propertyValue));
    propertyValue.cur = iGetParam;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}

static int32_t protocol_handle_get_calib_status(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    PropertyVal propertyValue;
    propertyValue.cur = ob_util_get_bit_16(g_rgb_crop_flag, 0);
    ret = protocol_handle_with_data(request, response, (uint8_t *)&propertyValue, sizeof(propertyValue), _res);
    return ret;
}

static int32_t protocol_handle_get_temp_comp_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint8_t value;
    PropertyVal propertyValue;
    Mx6300_get_tca_enable(&value);
    propertyValue.cur = value;
    ret = protocol_handle_with_data(request, response, (uint8_t *)&propertyValue, sizeof(propertyValue), _res);
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
    char cmd_get_temp[] = "/usrdata/usr/data/doraemon/adb_control.sh adb_status";
    strcpy(buf, get_shell(cmd_get_temp)); 
    
    INFO("xavier adb status: %s\n", buf);

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
    
    if (!strcmp(buf, "orbbec_force_upgrade_flag=y")){
        propertyValue.cur = 1;
        INFO("orbbec_force_upgrade_flag=y\n");
    }else{
        propertyValue.cur = 0;
        INFO("orbbec_force_upgrade_flag=n\n");
    }
        
    ret = protocol_handle_with_data(request, response, (uint8_t*)&propertyValue, sizeof(propertyValue),_res);

    return ret;
}



//设置属性接口
static int32_t protocol_handle_set_tec_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    uint32_t value = 0;
    memcpy(&value, &request->buf.data._data[4], 4);
    Mx6300_set_tec_enable((uint8_t)value);

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_ldp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    uint32_t value = 0;
    memcpy(&value, &request->buf.data._data[4], 4);
    INFO("ldp enable = %d\n",value);
    Mx6300_set_ldp_enable((uint8_t)value);

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_emitter(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    uint32_t value = 0;
    memcpy(&value, &request->buf.data._data[4], 4);
    Mx6300_laser_control((uint8_t)value);

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_laser_pulse_width(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;
    uint32_t value = 0;

    // value = *(uint32_t*)&request->buf.data._data[4];

    // DBG("writeProperty->cur is:%d\n",value);
    // Mx6300_set_laser_time(value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_laser_current(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    Mx6300_set_laser_current(value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_flood(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_flood_level(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_temperature_compensation_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];
    Mx6300_set_tca_enable(value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_temperature_calibrated_ir(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_temperature_calibrated_ldmp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_temperature_compensation_coefficient_ir(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_temperature_compensation_coefficient_ldmp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    DBG("writeProperty->cur is:%d\n",value);
    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_depth_align(const ProtocolMsg *request, ProtocolMsg *response) //D2C(SW)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint32_t value = *(uint32_t *)&request->buf.data._data[4];

    if (value != ob_streamControl.depthSoftD2C_enable)
    {
        if (!(value) && !(ob_streamControl.softfilter_Param.softfilterEnable))
        {
            ob_dsp_deinit();
        }
        if ((value) && !(ob_streamControl.softfilter_Param.softfilterEnable))
        {
            ob_dsp_init(ob_streamControl.d2c_pixFormat,
                        ob_streamControl.depthSoftD2C_enable, ob_streamControl.softfilter_Param);
        }
        ob_streamControl.depthSoftD2C_enable = value;
    }
    if (ob_streamControl.depthSoftD2C_enable)
        ob_util_set_bit_16(&g_rgb_crop_flag, 1);
    else
        ob_util_clear_bit_16(&g_rgb_crop_flag, 1);

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_depth_mirror(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint8_t value = 0;
    value = request->buf.data._data[4];
    Mx6300_set_depth_mirror(value);
    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_depth_flip(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_depth_postfilter(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_depth_holefilter(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_ir_mirror(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_ir_flip(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_ir_switch(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_hardware_sync(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_min_depth(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint32_t value = 0;
    value = *(uint32_t*)&request->buf.data._data[4];

    //ob_streamControl.depth_MinValue = (int)value;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_max_depth(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint32_t value = 0;
    value = *(uint32_t*)&request->buf.data._data[4];

    //ob_streamControl.depth_MaxValue = (int)value;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_depth_soft_filter(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint32_t value = 0;

    value = *(uint32_t*)&request->buf.data._data[4];

    if (value != ob_streamControl.softfilter_Param.softfilterEnable)
    {
        if (!(value) && !(ob_streamControl.depthSoftD2C_enable))
        {
            ob_dsp_deinit();
        }
        if ((value) && !(ob_streamControl.depthSoftD2C_enable))
        {
            ob_dsp_init(ob_streamControl.d2c_pixFormat,
                        ob_streamControl.depthSoftD2C_enable, ob_streamControl.softfilter_Param);
        }
        ob_streamControl.softfilter_Param.softfilterEnable = value;
    }
    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_zero_plane_distance(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_zero_plane_pixel_size(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_property_id_chip_type(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_usb_speed(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_soft_reset(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_ldp_thres_up(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_ldp_thres_low(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_lap_status(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_tec_data(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_laset_temperature(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_bootloader_write_protection_status(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_rt_ir_temp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_rt_ldmp_temp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_rt_rgb_temp(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_version_mx6300(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_mx6300_start_time(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_gpm_config_data(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_gpm_status_data(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_product_number(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_stop_depth_stream(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ob_streamControl.depthStopStream = true;
    ob_device *pObDev = ob_get_device_handle();
    if (!pObDev){
        ERR("pObdev is NULL.\n");
        return -1;
    }
    
    INFO("Stop Depth\n");
    if (NULL != pObDev->cmd_cb)
        pObDev->cmd_cb(OB_NODE_CMD_STOP_DEPTH, NULL);
    
    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_stop_ir_stream(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ob_streamControl.irStopStream = true;    
    ob_device *pObDev = ob_get_device_handle();
    if (!pObDev){
        ERR("pObdev is NULL.\n");
        return -1;
    }
    
    INFO("Stop IR\n");
    if (NULL != pObDev->cmd_cb)
        pObDev->cmd_cb(OB_NODE_CMD_STOP_IR, NULL);
    
    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_max_diff(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint32_t value = 0;
    value = *(uint32_t*)&request->buf.data._data[4];

    ob_streamControl.softfilter_Param.maxDiff = value;    

    ret = protocol_handle_response(request, response, _res);
    return ret;
}
static int32_t protocol_handle_set_maxspeckle_size(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint32_t value = 0;
    value = *(uint32_t*)&request->buf.data._data[4];

    ob_streamControl.softfilter_Param.maxSpeckleSize = value;    

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

static int32_t protocol_handle_set_depth_align_hardware(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint32_t value = 0;
    value = *(uint32_t*)&request->buf.data._data[4];
    Mx6300_set_depth_d2c_mode(value);

    if (1 == value)
        ob_util_set_bit_16(&g_rgb_crop_flag, 2); //新需求: 开启d2c则打开rgb裁剪
    else
        ob_util_clear_bit_16(&g_rgb_crop_flag, 2); 
    
    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_rgb_timestamp_offset(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    int iSetParam = *(int*)&request->buf.data._data[4];
    
    DBG("set timestamp offset:%dms\n", iSetParam);

    uvc_server_t *pService = get_uvc_server();
    if (NULL == pService){
        ERR("pService is NULL.\n");
        return -1;
    }
    
    if (NULL != pService->cmd_cb)
        pService->cmd_cb(OB_RGB_TIMESTAMP_OFFSET_SET, (void *)&iSetParam);

    ret = protocol_handle_response(request, response, _res);

    return ret;  
}

static int32_t protocol_handle_set_calib_status(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint32_t value = 0;
    value = *(uint32_t*)&request->buf.data._data[4];

    if (1 == value)
        ob_util_set_bit_16(&g_rgb_crop_flag, 0); //新需求: 进入标定模式则打开rgb裁剪
    else
        ob_util_clear_bit_16(&g_rgb_crop_flag, 0); 

    ret = protocol_handle_response(request, response, _res);
    return ret;
}


static int32_t protocol_handle_set_temp_comp_enable(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    uint32_t value = 0;
    value = *(uint32_t*)&request->buf.data._data[4];
    Mx6300_set_tca_enable(value);
    ret = protocol_handle_response(request, response, _res);
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

    value = *(uint32_t*)&request->buf.data._data[4];
    

    ret = init_tof_cam_fd();                                  //返回值为负值表示打开tof设备失败
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _end;
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
    INFO("set adb switch::%d\n",value);

    if (value == 1)
        get_shell("/usrdata/usr/data/doraemon/adb_control.sh adb_on");
    else
        get_shell("/usrdata/usr/data/doraemon/adb_control.sh adb_off");    

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
    if (value == 1){
        system("fw_setenv orbbec_force_upgrade_flag y");
        INFO("fw_setenv orbbec_force_upgrade_flag y\n");
    }else{
        system("fw_setenv orbbec_force_upgrade_flag n");
        INFO("fw_setenv orbbec_force_upgrade_flag n\n");
    }

    ret = protocol_handle_response(request, response, _res);

    return ret;
}


//获取自定义数据 函数接口
static int32_t protocol_handle_get_data_versions(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    
    char deviceSN[12] = "123456789";
    DeviceConfig devCfg;

    FILE *pFileBin = fopen(DeviceConfig_file, "rb");
    if (pFileBin == NULL)
    {
        ERR("get SN failed!\n");
    }
    else
    {
        fread(&devCfg, sizeof(char), sizeof(devCfg), pFileBin);
        memcpy(deviceSN, &devCfg.sn, sizeof(deviceSN));
        fclose(pFileBin);
    }

    SDKVersion sdk_version;
    sdk_version.nMajor = 1;
    sdk_version.nMinor = 0;
    sdk_version.nBuild = 0;

    Versions version;
    memset(&version, 0, sizeof(Versions));

    uint32_t mx6300_version = 0;
    Mx6300_get_firmware_ver(&mx6300_version);

    version.nMajor = (uint8_t)((mx6300_version & 0xff0000) >> 16);
    version.nMinor = (uint8_t)((mx6300_version & 0x00ff00) >> 8);
    version.nBuild = (uint16_t)(mx6300_version & 0xff);

    version.nChip = 0x0601;
    version.nFPGA = 0x0701;
    memcpy(version.nSerialNumber, deviceSN, sizeof(version.nSerialNumber) / sizeof(unsigned char));
    version.nDeviceType = 0x01;
    version.SDK = sdk_version;
    version.HWVer = 0x00;
    version.nFWVer = 0x00;
    // version.nChipSerialNumber = 0;
    // version.nRgbSensor = 0;
    // version.nIRSensor = 0;

    FILE* version_data = fopen("/etc/sdk.version", "r");

    fseek(version_data, 0, SEEK_END);
    long length = ftell(version_data);
    fseek(version_data, 0, SEEK_SET);
    char* filebuf = (char*)malloc(length);
    memset(filebuf, 0, length);
    fread(filebuf, 1, length, version_data);

    regex version_regex("gIMG_VERSION=");
    
    //string lines = "gIMG_VERSION = Dora.V1.0.01";
    string lines = filebuf;

    smatch version_match;

    string::const_iterator iterStart = lines.begin();
    string::const_iterator iterEnd = lines.end();

    if (regex_search(iterStart, iterEnd, version_match, version_regex)) 
    {
        // cout << "matches for '" << lines << "'\n";
        // cout << "Prefix: '" << version_match.prefix() << "'\n";
        // cout << version_match[0] << '\n';
        // cout << "Suffix: '" << version_match.suffix() << "\'\n\n";
        strncpy((char *)version.doraemon_version, (char *)(filebuf + 13), 10);
    }
    fclose(version_data);

    ret = protocol_handle_with_data(request, response, (uint8_t *)&version, sizeof(version), _res);
    return ret;
}

static int32_t protocol_handle_get_data_camera_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    OBCameraParameter cameraParameter;

    uint8_t parameterType = request->buf.data._data[1];

    switch (parameterType)
    {
        case CAMERA_CFG_PARAMETER_960_1280:
        {
            FILE *Param_data = fopen(cfgParameter_960_1280, "rb");
            if (Param_data == NULL)
            {
                memset(&cameraParameter, 0, sizeof(cameraParameter));
                INFO("distortion_d2c4x3 param file cannot be found!\n");
                break;
            }
            Doraemon_Content_t *doraemon_d2c_param = (Doraemon_Content_t *)malloc(sizeof(Doraemon_Content_t));
            memset(doraemon_d2c_param, 0, sizeof(doraemon_d2c_param));

            fread(doraemon_d2c_param, sizeof(char), sizeof(Doraemon_Content_t), Param_data);
            memcpy(&cameraParameter, &doraemon_d2c_param->soft_d2c, sizeof(cameraParameter));

            fclose(Param_data);
            free(doraemon_d2c_param);
        }
        break;
        case CAMERA_CFG_PARAMETER_720_1280:
        {   
            FILE *Param_data = fopen(cfgParameter_720_1280, "rb");
            if (Param_data == NULL)
            {
                memset(&cameraParameter, 0, sizeof(cameraParameter));
                INFO("d2c_16x9 param file cannot be found!\n");
                break;
            }
            Doraemon_Content_t *doraemon_d2c_param = (Doraemon_Content_t *)malloc(sizeof(Doraemon_Content_t));
            memset(doraemon_d2c_param, 0, sizeof(doraemon_d2c_param));

            fread(doraemon_d2c_param, sizeof(char), sizeof(Doraemon_Content_t), Param_data);
            memcpy(&cameraParameter, &doraemon_d2c_param->soft_d2c, sizeof(cameraParameter));

            fclose(Param_data);
            free(doraemon_d2c_param);
        }
        break;
        default:
            ERR("d2c_16x9 param file cannot be found!\n");
            break;
    }

    ret = protocol_handle_with_data(request, response, (uint8_t *)&cameraParameter, sizeof(cameraParameter), _res);
    return ret;
}

static int32_t protocol_handle_get_data_baseline_calibration_para(const ProtocolMsg *request, ProtocolMsg *response)
{    
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
    BaselineCalibrationPara caliparam;

    FILE *Param_data = fopen(cfgParameter_960_1280, "rb");
    if (Param_data == NULL)
    {
        caliparam.fZ0 = 0;
        caliparam.fBaseline = 0;
        INFO("z0 param file cannot be found!\n");
    }
    else
    {
        Doraemon_Content_t *doraemon_d2c_param = (Doraemon_Content_t *)malloc(sizeof(Doraemon_Content_t));
        memset(doraemon_d2c_param, 0, sizeof(doraemon_d2c_param));

        fread(doraemon_d2c_param, sizeof(char), sizeof(Doraemon_Content_t), Param_data);

        caliparam.fZ0 = doraemon_d2c_param->disparity2depthparams.fZeroPlaneDistance;
        caliparam.fBaseline = doraemon_d2c_param->disparity2depthparams.fEmitterDComsDistance;

        fclose(Param_data);
        free(doraemon_d2c_param);
    }

    ret = protocol_handle_with_data(request, response, (uint8_t *)&caliparam, sizeof(caliparam), _res);
    return ret;
}

static int32_t protocol_handle_get_data_multiple_distance_calibration_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_get_data_reference_image(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_get_data_hardware_align_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_get_data_software_align_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_get_data_hardware_distortion_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_get_data_depth_config_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_DEVICE_NOT_SUPPORT;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_get_data_device_temperature(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    DeviceTemperature readParam;
    char temp_buf[128] = {0};
    char cmd_get_temp[] = "devmem 0x60632910 32\n"; //get cpu temperature

    strcpy(temp_buf, get_shell(cmd_get_temp));
    int32_t cpu_temp = str_to_int(temp_buf);        //string to decimalism

    memset(&readParam, 0, sizeof(readParam));
    readParam.cpuTemp = cpu_temp * 0.4825 - 77.7;

    ret = protocol_handle_with_data(request, response, (uint8_t *)&readParam, sizeof(readParam), _res);

    return ret;
}

static int32_t protocol_handle_get_data_device_ae_params(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
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
    uint16_t _res = ACK_OB_SUCCESS;

    int32_t ret = 0;
    UpgradeStatus upgrade_status;
    memset(upgrade_status.message, 0x00, 256);
    
    get_firmware_upgrade_status(&upgrade_status.status, &upgrade_status.percentage, upgrade_status.message);
    ret = protocol_handle_with_data(request, response, (uint8_t*)&upgrade_status, sizeof(upgrade_status), _res);

    return ret;
}

static int32_t protocol_handle_get_device_file_tran_status(const ProtocolMsg *request, ProtocolMsg *response)
{
    uint16_t _res = ACK_OB_SUCCESS;

    int32_t ret = 0;
    UpgradeStatus upgrade_status;
    memset(upgrade_status.message, 0x00, 256);
    get_filetran_status(&upgrade_status.status, &upgrade_status.percentage, upgrade_status.message);

    ret = protocol_handle_with_data(request, response, (uint8_t*)&upgrade_status, sizeof(upgrade_status), _res);
    return ret;
}

static int32_t protocol_handle_get_device_calibration_upgrade_status(const ProtocolMsg *request, ProtocolMsg *response)
{
    uint16_t _res = ACK_OB_SUCCESS;

    int32_t ret = 0;
    UpgradeStatus upgrade_status;
    memset(upgrade_status.message, 0x00, 256);
    get_calibration_upgrade_status(&upgrade_status.status, &upgrade_status.percentage, upgrade_status.message);

    ret = protocol_handle_with_data(request, response, (uint8_t*)&upgrade_status, sizeof(upgrade_status), _res);
    return ret;
}

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
    tof_modulation_freq readParam ={2, 0, 0, 0};             //默认为双频调制模式

    ret = init_tof_cam_fd();                                 //返回值为负值表示打开tof设备失败
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _error;
    }

    ret = tof_sensor.get_modulation_frequency(&modulation_frequency);    //读取tof调制频率
    if(ret < 0)
    {
        ERR("get_modulation_frequency failed!\n");
        goto _error;
    }

    readParam.freq_A =  (modulation_frequency >> 8) & 0xFF;              //单位为MHz，高8位为freq_A,低8位为freq_B
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
    tof_duty_cycle_info readParam ={1, 0, 0, 0};

    ret = init_tof_cam_fd();                                     //返回值为负值表示打开tof设备失败
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _error;
    }

    ret = tof_sensor.get_illum_duty_cycle(&illum_duty_cycle);    //读取tof调制频率
    if(ret < 0)
    {
        ERR("get_illum_duty_cycle failed!\n");
        goto _error;
    }

    readParam.duty_A = (float)illum_duty_cycle;

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

    readParam.nearest_length = 200;
    readParam.farthest_length = 6000;

    ret = protocol_handle_with_data(request, response, (uint8_t*)&readParam, sizeof(readParam),_res);

    return ret;
}



//设置自定义数据接口
static int32_t protocol_handle_set_data_camera_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_INVALID_COMMAND;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_baseline_calibration_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_INVALID_COMMAND;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_data_multiple_distance_calibration_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_INVALID_COMMAND;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_data_reference_image(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_INVALID_COMMAND;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_data_hardware_align_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_INVALID_COMMAND;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_data_software_align_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_INVALID_COMMAND;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_hardware_distortion_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_INVALID_COMMAND;   //有效的命令，但是当前设备不支持

    ret = protocol_handle_response(request, response, _res);
    return ret;
}

static int32_t protocol_handle_set_data_depth_config_para(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_INVALID_COMMAND;

    ret = protocol_handle_response(request, response, _res);

    return ret;
}

static int32_t protocol_handle_set_data_device_ae_params(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;
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


static int32_t protocol_handle_ptz_control(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = 0x0;
    ob_ptz_control *pSetParam = (ob_ptz_control *)&request->buf.data._data[4];
    
    //DBG("enable:%d, x:%d, y:%d, w:%d, h:%d, speed:%.2f\n", 
      //  pSetParam->enable, pSetParam->x, pSetParam->y, pSetParam->width, pSetParam->height, pSetParam->speed);

    uvc_server_t *pService = get_uvc_server();
    if (NULL == pService){
        ERR("pService is NULL.\n");
        return -1;
    }
    
    if (NULL != pService->cmd_cb)
        pService->cmd_cb(OB_CROP_OPRATION, pSetParam);

    ret = protocol_handle_response(request, response, _res);

    return ret;
}


static int32_t protocol_handle_set_data_tof_modulation_freq(const ProtocolMsg *request, ProtocolMsg *response)
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

    ret = tof_sensor.set_modulation_frequency((uint16_t )value);  //设置tof调制频率
    if(ret < 0)
    {
        ERR("set_modulation_frequency failed!\n");
    }

_end:
    ret = protocol_handle_response(request, response, (uint16_t)ret);
    return ret;
}

static int32_t protocol_handle_set_data_tof_duty_cycle(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    float value = 0;

    value = *(float*)&request->buf.data._data[4];

    ret = init_tof_cam_fd();                                 //返回值为负值表示打开tof设备失败
    if(ret < 0)
    {
        ERR("init_tof_cam_fd failed!\n");
        goto _end;
    }

    ret = tof_sensor.set_illum_duty_cycle((uint8_t)value);  //设置tof调制占空比
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
    uint16_t _res = 0x0;
    DepthLenghtParam *writeParam = (DepthLenghtParam *)&request->buf.data._data[4];
    DBG("nearest_length:%d\n\
    farthest_length:%d\n",\
    writeParam->nearest_length,\
    writeParam->farthest_length);

    ret = protocol_handle_response(request, response, _res);

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
    //DBG("propertyID:%d(0x%x)\n", *propertyID, *propertyID);

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

        case OB_DEVICE_PROPERTY_ID_TEMPERATURE_COMPENSATION_COEFFICIENT_IR: // IR温补系数
            ret = protocol_handle_get_temperature_compensation_coefficient_ir(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_TEMPERATURE_COMPENSATION_COEFFICIENT_LDMP: // 激光温补系数
            ret = protocol_handle_get_temperature_compensation_coefficient_ldmp(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_ALIGN:
            ret = protocol_handle_get_depth_align(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_MIRROR:
            ret = protocol_handle_get_depth_mirror(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_FLIP:
            ret = protocol_handle_get_depth_flip(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_POSTFILTER:
            ret = protocol_handle_get_depth_postfilter(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_HOLEFILTER:
            ret = protocol_handle_get_depth_holefilter(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_IR_MIRROR:
            ret = protocol_handle_get_ir_mirror(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_IR_FLIP:
            ret = protocol_handle_get_ir_flip(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_IR_SWITCH:
            ret = protocol_handle_get_ir_switch(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_HARDWARE_SYNC:
            ret = protocol_handle_get_hardware_sync(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_MIN_DEPTH:
            ret = protocol_handle_get_min_depth(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_MAX_DEPTH:
            ret = protocol_handle_get_max_depth(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_SOFT_FILTER:
           ret = protocol_handle_get_depth_soft_filter(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_ZERO_PLANE_DISTANCE:
            ret = protocol_handle_get_zero_plane_distance(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_ZERO_PLANE_PIXEL_SIZE:
            ret = protocol_handle_get_zero_plane_pixel_size(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_CHIP_TYPE:
            ret = protocol_handle_get_property_id_chip_type(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_USB_SPEED:
            ret = protocol_handle_get_usb_speed(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_SOFT_RESET:
            ret = protocol_handle_get_soft_reset(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_LDP_THRES_UP:
            ret = protocol_handle_get_ldp_thres_up(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_LDP_THRES_LOW:
            ret = protocol_handle_get_ldp_thres_low(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_LDP_STATUS:
            ret = protocol_handle_get_lap_status(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_TEC_DATA:
            ret = protocol_handle_get_tec_data(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_LASER_TEMPERATURE:
            ret = protocol_handle_get_laset_temperature(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_BOOTLOADER_WRITE_PROTECTION_STATUS:
            ret = protocol_handle_get_bootloader_write_protection_status(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_RT_IR_TEMP:
            ret = protocol_handle_get_rt_ir_temp(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_RT_LDMP_TEMP:
            ret = protocol_handle_get_rt_ldmp_temp(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_RT_RGB_TEMP:
            ret = protocol_handle_get_rt_rgb_temp(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_VERSION_MX6300:
            ret = protocol_handle_get_version_mx6300(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_MX6300_START_TIME:
            ret = protocol_handle_get_mx6300_start_time(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_GPM_CONFIG_DATA:
            ret = protocol_handle_get_gpm_config_data(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_GPM_STATUS_DATA:
            ret = protocol_handle_get_gpm_status_data(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_PRODUCT_NUMBER:
            ret = protocol_handle_get_product_number(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_MAX_DIFF:
            ret = protocol_handle_get_max_diff(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_MAX_SPECKLE_SIZE:
            ret = protocol_handle_get_maxspeckle_size(request, response);
            break;            
        case OB_DEVICE_PROPERTY_ID_DEPTH_ALIGN_HARDWARE:
            ret = protocol_handle_get_depth_align_hardware(request, response);
            break;
        
        case OB_DEVICE_PROPERTY_ID_TIMESTEMP_OFFSET:
             ret = protocol_handle_get_rgb_timestamp_offset(request, response);
             break;
            
        case OB_DEVICE_PROPERTY_ID_ENABLE_CALIBRATION:
            ret = protocol_handle_get_calib_status(request, response);
            break;
            
        case OB_DEVICE_PROPERTY_ID_TOF_FPS:                    // tof帧率
            ret = protocol_handle_get_tof_fps(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_MIRROR:                // tof sensor镜像
            ret = protocol_handle_get_tof_mirror(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_EXPOSURE_TIME:         // tof 曝光时间
            ret = protocol_handle_get_tof_exposure_time(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_GAIN:                  // tof 增益
            ret = protocol_handle_get_tof_gain(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_TOF_GAUSSIAN_FILTER:       // tof 高斯噪声滤波器开关
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
        
        case OB_DEVICE_PROPERTY_ID_SET_FORCE_UPGRADE:       //get force upgrade mode
            ret = protocol_handle_get_force_upgrade_mode(request, response);
            break;

        default:
            ERR("protocol_handle_get_property,propertyID:%d(0x%x)\n", *propertyID, *propertyID);
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
    uint32_t data_value = 0;

    propertyID = (uint32_t*)&request->buf.data._data[0]; 
    data_value = *(uint32_t*)&request->buf.data._data[4];

    //DBG("propertyID:%d(0x%x), data_value:%d\n", *propertyID, *propertyID, data_value);

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

        case OB_DEVICE_PROPERTY_ID_TEMPERATURE_COMPENSATION_COEFFICIENT_LDMP:
            ret = protocol_handle_set_temperature_compensation_coefficient_ldmp(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_DEPTH_ALIGN:
            ret = protocol_handle_set_depth_align(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_MIRROR:
            ret = protocol_handle_set_depth_mirror(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_FLIP:
            ret = protocol_handle_set_depth_flip(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_POSTFILTER:
            ret = protocol_handle_set_depth_postfilter(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_HOLEFILTER:
            ret = protocol_handle_set_depth_holefilter(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_IR_MIRROR:
            ret = protocol_handle_set_ir_mirror(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_IR_FLIP:
            ret = protocol_handle_set_ir_flip(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_IR_SWITCH:
            ret = protocol_handle_set_ir_switch(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_HARDWARE_SYNC:
            ret = protocol_handle_set_hardware_sync(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_MIN_DEPTH:
            ret = protocol_handle_set_min_depth(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_MAX_DEPTH:
            ret = protocol_handle_set_max_depth(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_SOFT_FILTER:
           ret = protocol_handle_set_depth_soft_filter(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_ZERO_PLANE_DISTANCE:
            ret = protocol_handle_set_zero_plane_distance(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_ZERO_PLANE_PIXEL_SIZE:
            ret = protocol_handle_set_zero_plane_pixel_size(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_CHIP_TYPE:
            ret = protocol_handle_set_property_id_chip_type(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_USB_SPEED:
            ret = protocol_handle_set_usb_speed(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_SOFT_RESET:
            ret = protocol_handle_set_soft_reset(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_LDP_THRES_UP:
            ret = protocol_handle_set_ldp_thres_up(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_LDP_THRES_LOW:
            ret = protocol_handle_set_ldp_thres_low(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_LDP_STATUS:
            ret = protocol_handle_set_lap_status(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_TEC_DATA:
            ret = protocol_handle_set_tec_data(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_LASER_TEMPERATURE:
            ret = protocol_handle_set_laset_temperature(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_BOOTLOADER_WRITE_PROTECTION_STATUS:
            ret = protocol_handle_set_bootloader_write_protection_status(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_RT_IR_TEMP:
            ret = protocol_handle_set_rt_ir_temp(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_RT_LDMP_TEMP:
            ret = protocol_handle_set_rt_ldmp_temp(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_RT_RGB_TEMP:
            ret = protocol_handle_set_rt_rgb_temp(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_VERSION_MX6300:
            ret = protocol_handle_set_version_mx6300(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_MX6300_START_TIME:
            ret = protocol_handle_set_mx6300_start_time(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_GPM_CONFIG_DATA:
            ret = protocol_handle_set_gpm_config_data(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_GPM_STATUS_DATA:
            ret = protocol_handle_set_gpm_status_data(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_PRODUCT_NUMBER:
            ret = protocol_handle_set_product_number(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_STOP_DEPTH_STREAM:            
            ret = protocol_handle_stop_depth_stream(request, response);            
            break;
        case OB_DEVICE_PROPERTY_ID_STOP_IR_STREAM:            
            ret = protocol_handle_stop_ir_stream(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_MAX_DIFF:
            ret = protocol_handle_set_max_diff(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_MAX_SPECKLE_SIZE:
            ret = protocol_handle_set_maxspeckle_size(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_TOF_FPS:
            ret = protocol_handle_set_tof_fps(request, response);
            break;
        case OB_DEVICE_PROPERTY_ID_DEPTH_ALIGN_HARDWARE:
            ret = protocol_handle_set_depth_align_hardware(request, response);
            break;
        
        case OB_DEVICE_PROPERTY_ID_TIMESTEMP_OFFSET:         //时间戳校正配置
            ret = protocol_handle_set_rgb_timestamp_offset(request, response);
            break;

        case OB_DEVICE_PROPERTY_ID_ENABLE_CALIBRATION:
            ret = protocol_handle_set_calib_status(request, response);
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
        
        case OB_DEVICE_PROPERTY_ID_SET_FORCE_UPGRADE:  //设置设备强制升级模式
            ret = protocol_handle_set_force_upgrade_mode(request, response);
            break;

        default:
            ERR("protocol_handle_set_property,propertyID:%d(0x%x)\n", *propertyID, *propertyID);
            ret = protocol_handle_default(request, response);
            break;
    }

    return ret;
}
/*****************************************************************************
*   Prototype    : protocol_handle_get_Device_SN
*   Description  : orbbec protocol get firmware_data
*   Input        :const ProtocolMsg *request  
*                  ProtocolMsg *response                                   
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
static int32_t protocol_handle_get_Device_SN(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    char deviceSN[12] = "123456789";
    DeviceConfig devCfg;

    FILE *pFileBin = fopen(DeviceConfig_file, "rb");
    if (pFileBin == NULL)
    {
        ERR("get SN failed!\n");
    }
    else
    {
        fread(&devCfg, sizeof(char), sizeof(devCfg), pFileBin);
        memcpy(deviceSN, &devCfg.sn, sizeof(deviceSN));
        fclose(pFileBin);
    }

    ret = protocol_handle_with_data(request, response, (uint8_t *)&deviceSN, sizeof(deviceSN), _res);

    return ret;
}
/*****************************************************************************
*   Prototype    : protocol_handle_get_Device_status
*   Description  : orbbec protocol get firmware_data
*   Input        :const ProtocolMsg *request  
*                  ProtocolMsg *response                                   
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
static int32_t protocol_handle_get_Device_status(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    uint16_t _res = ACK_OB_SUCCESS;

    ob_device_state device_state;

    device_state.type = (ob_device_state_type)ob_streamControl.deviceState;

    ret = protocol_handle_with_data(request, response, (uint8_t *)&device_state, sizeof(device_state), _res);

    return ret;
}
/*****************************************************************************
*   Prototype    : protocol_handle_set_Device_SN
*   Description  : orbbec protocol get firmware_data
*   Input        :const ProtocolMsg *request  
*                  ProtocolMsg *response                                   
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
static int32_t protocol_handle_set_Device_SN(const ProtocolMsg *request, ProtocolMsg *response)
{
    uint8_t ret = ORBBEC_FAILED;
    uint16_t _res = ACK_OB_SUCCESS;

    char deviceSN[12] = "123456789";

    DeviceConfig devCfg;
    DeviceConfig devCfg_tmp;
    ConfigValidFlag cfgFlag;

    FILE *pFileBin = fopen(DeviceConfig_file, "rb");
    if (pFileBin != NULL)
    {
        fread(&devCfg, sizeof(char), sizeof(devCfg), pFileBin);
        fclose(pFileBin);
    }
    memcpy(deviceSN, &request->buf.data._data[4], sizeof(deviceSN));
    memcpy(&devCfg.sn, &deviceSN, sizeof(deviceSN));

    orbbec_saveFile(DeviceConfig_file, &devCfg, sizeof(devCfg));

    obc_sl_write_flash(DEVICE_CONFIG_ADDR, &devCfg, sizeof(devCfg));
    obc_sl_read_flash(DEVICE_CONFIG_ADDR, &devCfg_tmp, sizeof(devCfg));
    if (memcmp(&devCfg, &devCfg_tmp, sizeof(devCfg)) != 0)
    {
        _res = ACK_OB_DEVICE_BUSY;
        obc_sl_read_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
        cfgFlag.sn_valid = VALUE_INVALID;
        obc_sl_write_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
        ERR("write SN to flash failed!\n");
    }
    else
    {
        obc_sl_read_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
        cfgFlag.sn_valid = VALUE_VALID;
        obc_sl_write_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
    }

    response->header.nSize = (sizeof(response->buf.data.resp.res)) >> 1;
    response->buf.len = sizeof(response->header) + (response->header.nSize << 1);
    ret = protocol_handle_response(request, response, _res);

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
    uint32_t *propertyID = NULL;

    propertyID = (uint32_t*)request->buf.data._data;
    //INFO("-------propertyID:%d\n", *propertyID);

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

        case OB_DATA_TYPE_DEVICE_SERIAL_NUMBER:
           ret = protocol_handle_get_Device_SN(request, response);
           break;
        case OB_DATA_TYPE_DEVICE_STATE:
           ret = protocol_handle_get_Device_status(request, response);
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
    //DBG(":: propertyID:%d)\n", *propertyID);

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

        case OB_DATA_TYPE_PTZ_CONTROL:               //云台控制
            ret = protocol_handle_ptz_control(request, response);
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

        case OB_DATA_TYPE_TOF_NEAREST_FARTHEST_LENGTH: // tof 最近最远距离
            ret = protocol_handle_set_data_tof_nearest_farthest_length(request, response);
            break;

        case OB_DATA_TYPE_DEVICE_SERIAL_NUMBER:
           ret = protocol_handle_set_Device_SN(request, response);
           break;

        default:
            ERR("protocol_handle_set_firmware_data,propertyID:%d\n", *propertyID);
            ret = protocol_handle_default(request, response);
            break;
    }

    return ret;
}

/*****************************************************************************
*   Prototype    : protocol_handle_upload_file
*   Description  : orbbec protocol upload file to mx6300
*   Input        :const ProtocolMsg *request  
*                  ProtocolMsg *response                                   
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
static int32_t protocol_handle_upload_file(const ProtocolMsg *request, ProtocolMsg *response)
{
    uint16_t propertyID = request->buf.data._data[0] + (request->buf.data._data[1] << 8);
    uint16_t currentLength = request->header.nSize * 2 - 6;

    uint32_t fileLength = 0;
    memcpy(&fileLength, &request->buf.data._data[2], sizeof(uint32_t));

    uint8_t *fileBufffer = (uint8_t *)malloc(currentLength);
    if (fileBufffer == NULL)
    {
        ERR("malloc failed!\n");
        return ORBBEC_FAILED;
    }
    memset(fileBufffer, 0, currentLength);
    memcpy(fileBufffer, &request->buf.data._data[6], currentLength);

    uint8_t ret = ORBBEC_FAILED;
    uint16_t _res = ACK_OB_SUCCESS;

    static uint32_t fileCount = 0;
    static uint32_t fileOffset = 0;

    uint8_t *flashBuf;
    uint8_t *flashBuf_temp;

    //INFO("-----propertyID:%d,fileLength:%d,currentLength:%d\n", propertyID, fileLength, currentLength);
    if (fileOffset == 0)
    {
        flashBuf = (uint8_t *)malloc(fileLength + sizeof(fileLength));
        if (flashBuf == NULL)
        {
            ERR("malloc failed!\n");
            return ORBBEC_FAILED;
        }
        memset(flashBuf, 0, fileLength + sizeof(fileLength));
        memcpy(flashBuf, &fileLength, sizeof(fileLength));

        flashBuf_temp = (uint8_t *)malloc(fileLength + sizeof(fileLength));
        if (flashBuf_temp == NULL)
        {
            ERR("malloc failed!\n");
            return ORBBEC_FAILED;
        }
        memset(flashBuf_temp, 0, fileLength + sizeof(fileLength));
    }

    ConfigValidFlag cfgFlag;

    switch (propertyID)
    {
        case MX6300_FIRMWARE:
            memcpy(flashBuf + sizeof(fileLength) + fileOffset, fileBufffer, currentLength);
            break;
        case MX6300_REFERENCE_PICTURE:
            memcpy(flashBuf + sizeof(fileLength) + fileOffset, fileBufffer, currentLength);
            break;
        case MX6300_CAMERA_CFG_PARAMETER_960_1280:
            memcpy(flashBuf + sizeof(fileLength) + fileOffset, fileBufffer, currentLength);
            break;
        case MX6300_CAMERA_CFG_PARAMETER_720_1280:
            memcpy(flashBuf + sizeof(fileLength) + fileOffset, fileBufffer, currentLength);
            break;
        default:
            ERR("property ID:%d is invalid!\n", propertyID);
            break;
    }
    fileCount++;
    fileOffset += currentLength;
    if (fileOffset == fileLength)
    {
        fileOffset = 0;
        fileCount = 0;
        switch (propertyID)
        {
            case MX6300_FIRMWARE:
                orbbec_saveFile(firmwareFile, flashBuf + sizeof(fileLength), fileLength);
                break;
            case MX6300_REFERENCE_PICTURE:
                orbbec_saveFile(referencePictureFile, flashBuf + sizeof(fileLength), fileLength);
                obc_sl_write_flash(REFERENCE_ADDR, flashBuf, fileLength + sizeof(fileLength));
                obc_sl_read_flash(REFERENCE_ADDR, flashBuf_temp, fileLength + sizeof(fileLength));
                if (memcmp(flashBuf, flashBuf_temp, fileLength + sizeof(fileLength)) != 0)
                {
                    _res = ACK_OB_DEVICE_BUSY;                    
                    obc_sl_read_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
                    cfgFlag.reference_valid = VALUE_INVALID;
                    obc_sl_write_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
                    ERR("write reference to flash failed!\n");
                }
                else
                {
                    obc_sl_read_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
                    cfgFlag.reference_valid = VALUE_VALID;
                    obc_sl_write_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
                }
                break;
            case MX6300_CAMERA_CFG_PARAMETER_960_1280:
                orbbec_saveFile(cfgParameter_960_1280, flashBuf + sizeof(fileLength), fileLength);
                obc_sl_write_flash(DISTORTION_PARAMS_ADDR, flashBuf, fileLength + sizeof(fileLength));
                obc_sl_read_flash(DISTORTION_PARAMS_ADDR, flashBuf_temp, fileLength + sizeof(fileLength));
                if (memcmp(flashBuf, flashBuf_temp, fileLength + sizeof(fileLength)) != 0)
                {
                    _res = ACK_OB_DEVICE_BUSY;
                    obc_sl_read_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
                    cfgFlag.distortion_d2c4x3_valid = VALUE_INVALID;
                    obc_sl_write_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
                    ERR("write distortion_d2c4x3 file to flash failed!\n");
                }
                else
                {
                    obc_sl_read_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
                    cfgFlag.distortion_d2c4x3_valid = VALUE_VALID;
                    obc_sl_write_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
                }
                break;
            case MX6300_CAMERA_CFG_PARAMETER_720_1280:
                orbbec_saveFile(cfgParameter_720_1280, flashBuf + sizeof(fileLength), fileLength);
                obc_sl_write_flash(SOFT_D2C_PARAMS_ADDR, flashBuf, fileLength + sizeof(fileLength));            
                obc_sl_read_flash(SOFT_D2C_PARAMS_ADDR, flashBuf_temp, fileLength + sizeof(fileLength));
                if (memcmp(flashBuf, flashBuf_temp, fileLength + sizeof(fileLength)) != 0)
                {
                    _res = ACK_OB_DEVICE_BUSY;
                    obc_sl_read_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
                    cfgFlag.d2c_16x9_valid = VALUE_INVALID;
                    obc_sl_write_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
                    ERR("write distortion_d2c4x3 file to flash failed!\n");
                }
                else
                {
                    obc_sl_read_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
                    cfgFlag.d2c_16x9_valid = VALUE_VALID;
                    obc_sl_write_flash(CONFIG_VALID_ADDR, &cfgFlag, sizeof(cfgFlag));
                }
                break;
            default:
                ERR("flash property ID:%d is invalid!\n", propertyID);
                break;
        }
        free(flashBuf);
        free(flashBuf_temp);
    }
    
    response->header.nSize = (sizeof(response->buf.data.resp.res)) >> 1;
    response->buf.len = sizeof(response->header) + (response->header.nSize << 1);
    ret = protocol_handle_response(request, response, _res);

    free(fileBufffer);
    return ret;
}
/*****************************************************************************
*   Prototype    : ob_readFile
*   Description  : ob_readFile
*   Input        : const char *filename                
*                  uint8_t *fileBuf
                   uint32_t &fileBuf_length
*   Output       : 
*   Return Value :
*****************************************************************************/
static int ob_readFile(const char *filename, uint8_t *fileBuf, uint32_t &fileBuf_length)
{
    uint32_t file_content_len = 0;
    uint32_t len = 5 * 1024 * 1024;
    uint8_t *file_content = (uint8_t *)malloc(len);
    if (file_content == NULL)
    {
        ERR("malloc file_content failed!\n");
        return ORBBEC_FAILED;
    }
    memset(file_content, 0, len);

    FILE *pFileBin = fopen(filename, "rb");
    if (pFileBin == NULL)
    {
        ERR("can't not open %s\n", filename);
        return ORBBEC_FAILED;
    }
    else
    {
        while (!feof(pFileBin))
        {
            uint8_t content[1024] = {0};
            int count = fread(content, sizeof(char), 1024, pFileBin);

            if (file_content_len + count > len)
            {
                ERR("[error]: file size > 10MB!\n");
                return -1;
            }

            memcpy(file_content + file_content_len, content, count);
            file_content_len += count;
        }

        //INFO("file size %zd\n", file_content_len);

        if (file_content_len > len)
        {
            ERR("[error]: file oversize!\n");
            return -1;
        }
        fclose(pFileBin);
    }
    memcpy(fileBuf, file_content, file_content_len);
    fileBuf_length = file_content_len;
    free(file_content);
    return 0;
}

/*****************************************************************************
*   Prototype    : protocol_handle_download_file
*   Description  : orbbec protocol process function
*   Input        : const ProtocolMsg *request*                  
*                  ProtocolMsg *response
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
static int32_t protocol_handle_download_file(const ProtocolMsg *request, ProtocolMsg *response)
{
    int32_t ret = 0;
    int32_t _res = -1;
    static int32_t count = 0;
    // int32_t sendFile_count = 0;
    // int32_t sendFile_offset = 0;

    uint16_t propertyID = request->buf.data._data[0] + (request->buf.data._data[1] << 8);
    uint16_t requestLength = (request->buf.data._data[2] + (request->buf.data._data[3] << 8)) * 2;

    uint8_t *file_content = (uint8_t *)malloc(5 * 1024 * 1024);
    uint32_t file_length = 0;
    if (file_content == NULL)
    {
        ERR("malloc file_content failed!\n");
        return ORBBEC_FAILED;
    }
    memset(file_content, 0, 5 * 1024 * 1024);
    // uint8_t _file_length[4];

    static uint32_t fileOffset = 0;

    switch (propertyID)
    {
        case MX6300_REFERENCE_PICTURE:
            ob_readFile(referencePictureFile, file_content, file_length);
            break;
        case MX6300_CAMERA_CFG_PARAMETER_960_1280:
            ob_readFile(cfgParameter_960_1280, file_content, file_length);
            break;
        case MX6300_CAMERA_CFG_PARAMETER_720_1280:
            ob_readFile(cfgParameter_720_1280, file_content, file_length);
            break;
        default:
            ERR("request file type is not support!\n");
            _res = ACK_OB_INVALID_COMMAND;
            ret = protocol_handle_with_data(request, response, (uint8_t *)&file_length, sizeof(file_length), _res);
            return ORBBEC_FAILED;
    }
    _res = ACK_OB_SUCCESS;
    if (count == 0)
    {
        ret = protocol_handle_with_data(request, response, (uint8_t *)&file_length, sizeof(file_length), _res);
        count++;
    }
    else
    {
        // INFO("------fileOffset:%x\n", fileOffset);
        ret = protocol_handle_with_data(request, response, file_content + fileOffset, requestLength, _res);
        fileOffset += requestLength;
        if (fileOffset == file_length)
        {
            count = 0;
            fileOffset = 0;
        }
    }
    free(file_content);
    return ret;
}
/*****************************************************************************
*   Prototype    : protocol_handle_read_AHB
*   Description  : orbbec protocol process function
*   Input        : const ProtocolMsg *request*                  
*                  ProtocolMsg *response
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
static int32_t protocol_handle_read_AHB(const ProtocolMsg *request, ProtocolMsg *response)
{
    uint16_t _res = ACK_OB_SUCCESS;
    int32_t ret = 0;
    uint32_t *propertyID = NULL;
    propertyID = (uint32_t *)request->buf.data._data;

    AHBData ahbData;
	memcpy(&ahbData,&request->buf.data._data[0],sizeof(ahbData));
    Mx6300_read_ahb(ahbData.nRegister, (uint32_t *)&ahbData.nValue);
    ret = protocol_handle_with_data(request, response, (uint8_t *)&ahbData.nValue, 4, _res);
    return ret;
}
/*****************************************************************************
*   Prototype    : protocol_handle_write_AHB
*   Description  : orbbec protocol process function
*   Input        : const ProtocolMsg *request*                  
*                  ProtocolMsg *response
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
static int32_t protocol_handle_write_AHB(const ProtocolMsg *request, ProtocolMsg *response)
{
    uint16_t _res = ACK_OB_SUCCESS;
    int32_t ret = 0;
    uint32_t *propertyID = NULL;
    propertyID = (uint32_t *)request->buf.data._data;

    AHBData ahbData;
    memcpy(&ahbData,&request->buf.data._data[0],sizeof(ahbData));
    Mx6300_write_ahb(ahbData.nRegister, (uint32_t)ahbData.nValue);
    ret = protocol_handle_with_data(request, response, (uint8_t *)&ahbData, sizeof(ahbData), _res);
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

    //DBG("xavier, Recv OpCode:0x%02d(%d), nId:0x%02d(%d)\n",
      //  request->header.nOpcode, request->header.nOpcode, request->header.nId, request->header.nId);

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

    case OPCODE_READ_AHB:
        ret = protocol_handle_read_AHB(request, response);
        break;

    case OPCODE_WRITE_AHB:
        ret = protocol_handle_write_AHB(request, response);
        break;

    case OPCODE_WRITE_FILE_UPLOAD:
        ret = protocol_handle_upload_file(request, response);
        break;

    case OPCODE_FINISH_FILE_UPLOAD:
        break;

    case OPCODE_DOWNLOAD_FILE:
        ret = protocol_handle_download_file(request, response);
        break;

    default:
        ERR("protocol_handle_default,opcode:%d\n", request->header.nOpcode);
        ret = protocol_handle_default(request, response);
        break;
    }
    return ret;
}
