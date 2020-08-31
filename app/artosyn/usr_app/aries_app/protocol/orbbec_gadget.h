/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : orbbec_gadget.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/5/7
*  Last Modified :
*  Description   : orbbec_gadget.cpp header file
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
#ifndef __ORBBEC_GADGET_H__
#define __ORBBEC_GADGET_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include "basic_typedef.h"
#include "orbbec_protocol.h"
#include "orbbec_gadget_types.h"


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/


/*==============================================*
 *      struct define                           *
 *----------------------------------------------*/
typedef struct _ob_device
{
    int32_t fd;               //设备句柄 /dev/videoN
    uint8_t dev_init;         //设备open完成,相关初始化完成
    pthread_t tid_obpoll;
    uint8_t  pollrun;

    ProtocolMsg vendor_request;
    ProtocolMsg vendor_response;
}ob_device;


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/


/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/
 

/*****************************************************************************
*   Prototype    : ob_gadget_events_poll
*   Description  : orbbec gadget events poll switch
*   Input        : OB_EVENTS_POLL_SATUS_T s  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
extern int32_t ob_gadget_events_poll(OB_EVENTS_POLL_SATUS_T s);


/*****************************************************************************
*   Prototype    : ob_get_device_handle
*   Description  : create or get orbbec handle
*   Input        : None
*   Output       : None
*   Return Value : ob_device *
*****************************************************************************/
extern ob_device *ob_get_device_handle(void);


/*****************************************************************************
*   Prototype    : ob_gadget_init
*   Description  : orbbec gadget init function
*   Input        : int dev_index  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
extern int32_t ob_gadget_init(int dev_index);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __ORBBEC_GADGET_H__ */

