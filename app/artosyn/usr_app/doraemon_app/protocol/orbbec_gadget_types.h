 /******************************************************************************
 *
 *  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
 *
 *******************************************************************************
 *  File Name     : orbbec_gadget_types.h
 *  Version       : Initial Draft
 *  Author        : jiangxiaohui
 *  Created       : 2020/5/7
 *  Last Modified :
 *  Description   : orbbec_gadget_types.h header file
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
#ifndef __ORBBEC_GADGET_TYPES_H__
#define __ORBBEC_GADGET_TYPES_H__
 
/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
 
/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
#define OB_GADGET_SUCCESS  0x00
#define OB_GADGET_ERROR    0x01


/* uvc video设备号定义 */
#define OB_UVC_DEVICE_NODE_NUM_RGB    0  // /dev/video0 for RGB
#define OB_UVC_DEVICE_NODE_NUM_DEPTH  1  // /dev/video1 for depth or raw phase
#define OB_UVC_DEVICE_NODE_NUM_IR     2  // /dev/video2 for IR
#define OB_UVC_DEVICE_NODE_NUM_MAX    3

//对应驱动的设定: kernel/drivers/usb/gadget/function/f_orbbec.c  orbbec_register_video
#define OB_PRIVATE_CHANNEL_DEVICE_NODE_NUM   10  


/* USB interface 编号定义, 需要与驱动相互对应 */
#define OB_UVC_INTF_WIN_USB           0

#define OB_UVC_INTF_CONTROL_RGB       1
#define OB_UVC_INTF_STREAMIMG_RGB     2

#define OB_UVC_INTF_CONTROL_DEPTH     3
#define OB_UVC_INTF_STREAMIMG_DEPTH   4

#define OB_UVC_INTF_CONTROL_IR        5
#define OB_UVC_INTF_STREAMIMG_IR      6



/*==============================================*
 *      enum define                             *
 *----------------------------------------------*/
typedef enum _OB_EVENTS_POLL_STATUS
{
    OB_EVENTS_POLL_START = 0x01,
    OB_EVENTS_POLL_STOP  = 0x02
}OB_EVENTS_POLL_SATUS_T; 


typedef enum _OB_NODE_GADGET_CMD_EM
{
    OB_NODE_CMD_NONE, 
    OB_NODE_CMD_STOP_IR,
    OB_NODE_CMD_STOP_DEPTH,
    OB_NODE_CMD_MAX
}OB_NODE_GADGET_CMD_EM;

/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/
typedef void(ob_pri_node_gadget_cmd_cb)(OB_NODE_GADGET_CMD_EM cmd, void *data);

/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/
 
 
#endif /* __ORBBEC_GADGET_TYPES_H__ */


