/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : ob_config_define.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/7/22
*  Last Modified :
*  Description   : orbbec config define
*
******************************************************************************/

/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/

/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
 
/*
uvc video device index config
matching to driver: f_uvc.c multi uvc's index define: UVC_INDEX_NUM_RGB UVC_INDEX_NUM_DEPTH UVC_INDEX_NUM_IR
*/
#define OB_UVC_DEVICE_NODE_NUM_RGB    0  // /dev/video0 for RGB
#define OB_UVC_DEVICE_NODE_NUM_DEPTH  1  // /dev/video1 for depth or raw phase
#define OB_UVC_DEVICE_NODE_NUM_IR     2  // /dev/video2 for IR
#define OB_UVC_DEVICE_NODE_NUM_MAX    3

//matching to driver: kernel/drivers/usb/gadget/function/f_orbbec.c  orbbec_register_video
#define OB_PRIVATE_CHANNEL_DEVICE_NODE_NUM   10  


/*USB interface number, matching to usb driver */
#define OB_UVC_INTF_WIN_USB           0   //matching to f_orbbec.c ORBBEC_PRIVATE_DATA_CAHNNEL_INTERFACE_NUM

#define OB_UVC_INTF_CONTROL_RGB       1
#define OB_UVC_INTF_STREAMIMG_RGB     2

#define OB_UVC_INTF_CONTROL_DEPTH     3
#define OB_UVC_INTF_STREAMIMG_DEPTH   4

#define OB_UVC_INTF_CONTROL_IR        5
#define OB_UVC_INTF_STREAMIMG_IR      6


/*
    imx415:  3840x2160
    ov02k10: 1920x1080

    just configure an initial resolution here, 
    if set 1920x1080 resoluton, then can be compatible with imx415 and ov02k10
*/
#define RGB_SENSOR_WIDTH           3840
#define RGB_SENSOR_HEIGHT          2160


/*
    tof 33d raw phase(include EBD data)
*/
#define TOF_SENSOR_WIDTH           1280
#define TOF_SENSOR_HEIGHT          970


/*
    camera id refer to sensor probe sequence in artosyn-cfg-data.dts file
    It's the same as pipeline's index
*/
#define RGB_CAMERA_ID              1
#define TOF_CAMERA_ID              0

#define RGB_PIPELINE_INDEX         RGB_CAMERA_ID
#define TOF_PIPELINE_INDEX         TOF_CAMERA_ID


/*
    whether depth support cache
*/
#define DEPTH_CACHE_ENABLE         1


#define RGB_TIMESTAMP_FIXED_ENABLE   1

/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/




