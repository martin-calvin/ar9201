/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : dbg.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/4/24
*  Last Modified :
*  Description   : dbg.cpp header file
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
#ifndef __DBG_H__
#define __DBG_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
 

/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/
extern void dbg_console(void);
extern void dbg_softfilter_test_func(char *param);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __DBG_H__ */

