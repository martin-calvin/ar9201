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


/*==============================================*
 *      enum define                             *
 *----------------------------------------------*/
typedef enum _OB_EVENTS_POLL_STATUS
{
    OB_EVENTS_POLL_START = 0x01,
    OB_EVENTS_POLL_STOP  = 0x02
}OB_EVENTS_POLL_SATUS_T; 


typedef enum _OB_TOF_GADGET_CMD_EM
{
    OB_GADGET_CMD_NONE, 
    OB_GADGET_CMD_TOF_UVC_STREAM_ON,
    OB_GADGET_CMD_TOF_UVC_STREAM_OFF,
    OB_GADGET_CMD_MAX
}OB_TOF_GADGET_CMD_EM;


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/
typedef void(ob_tof_uvc_gadget_cmd_cb)(OB_TOF_GADGET_CMD_EM cmd, void *data);



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/
 
 
#endif /* __ORBBEC_GADGET_TYPES_H__ */


