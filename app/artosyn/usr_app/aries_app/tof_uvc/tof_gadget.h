/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : tof_gadget.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/5/29
*  Last Modified :
*  Description   : tof_gadget.c header file
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/5/29
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/
#ifndef __TOF_GADGET_H__
#define __TOF_GADGET_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include "basic_typedef.h"
#include "orbbec_gadget_types.h"
#include "tof_uvc_op.h"


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/


/*==============================================*
 *      struct define                           *
 *----------------------------------------------*/



/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/



/*****************************************************************************
*   Prototype    : tof_uvc_gadget_register_cmd_cb
*   Description  : register tof uvc cmd callback
*   Input        : int dev_index                
*                  ob_tof_uvc_gadget_cmd_cb cb  
*   Output       : None
*   Return Value : void t
*****************************************************************************/
extern void tof_uvc_gadget_register_cmd_cb(int dev_index, ob_tof_uvc_gadget_cmd_cb cb);


/*****************************************************************************
*   Prototype    : tof_uvc_gadget_events_poll
*   Description  : tof uvc gadget events poll switch
*   Input        : OB_EVENTS_POLL_SATUS_T s  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
extern int32_t tof_uvc_gadget_events_poll(int dev_index, OB_EVENTS_POLL_SATUS_T s);


/*****************************************************************************
*   Prototype    : tof_uvc_gadget_get_service
*   Description  : create or get orbbec handle
*   Input        : None
*   Output       : None
*   Return Value : tof_uvc_service *
*****************************************************************************/
extern tof_uvc_service *tof_uvc_gadget_get_service(int dev_index);


/*****************************************************************************
*   Prototype    : tof_uvc_gadget_init
*   Description  : tof gadget init function
*   Input        : int dev_index  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
extern int32_t tof_uvc_gadget_init(int dev_index);




#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __TOF_GADGET_H__ */







