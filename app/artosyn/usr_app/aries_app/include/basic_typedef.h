/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : basic_typedef.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/5/7
*  Last Modified :
*  Description   : basic_typedef.h header file
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
#ifndef __BASIC_TYPEDEF_H__
#define __BASIC_TYPEDEF_H__



/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <stddef.h>  // For size_t and NULL
#include <stdint.h>
#include <sys/types.h>  // for uintptr_t on x86


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/
/* ------ 整型变量类型声明 ------ */
typedef signed char s8;         /* 有符号8位整型 */
typedef unsigned char u8;       /* 无符号8位整型 */

typedef signed short s16;       /* 有符号16位整型 */
typedef unsigned short u16;     /* 无符号16位整型 */

typedef signed int s32;         /* 有符号32位整型 */
typedef unsigned int u32;       /* 无符号32位整型 */

typedef signed long long s64;   /* 有符号64位整型 */
typedef unsigned long long u64; /* 无符号64位整型 */



typedef unsigned long long uint64_t;
typedef signed long long int64_t;

typedef unsigned int uint32_t;
typedef int int32_t;

typedef unsigned short uint16_t;
typedef short int16_t;

typedef unsigned char uint8_t;
typedef signed char int8_t;



typedef uint64_t uint64;
typedef int64_t int64;

typedef uint32_t uint32;
typedef int32_t int32;

typedef uint16_t uint16;
typedef int16_t int16;

typedef uint8_t uint8;
typedef int8_t int8;



#endif /* __BASIC_TYPEDEF_H__ */


   




