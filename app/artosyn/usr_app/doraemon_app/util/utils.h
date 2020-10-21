/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : utils.h
*  Version       : Initial Draft
*  Author        : heimao
*  Created       : 2020/04/24
*  Last Modified :
*  Description   : utils.cpp header file
*  Function List :
*
*
*  History:
*
*       1.  Date         : 2020/04/24
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/
#ifndef __UTILS_H__
#define __UTILS_H__


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
#define ALIGN(value, bits) (((value) + ((bits) - 1)) & (~((bits) - 1)))
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define swap32_LittleToBig(x)	((((x) & 0xff) << 24) \
									 |(((x) & 0xff00) << 8) \
									 |(((x) & 0xff0000) >> 8) \
									 |(((x) & 0xff000000) >> 24))

#define swap32_BigToLittle(x)  	((((x) & 0xff000000) >> 24) \
									 |(((x) & 0xff0000) >> 8) \
									 |(((x) & 0xff00) << 8) \
									 |(((x) & 0xff) << 24))


#define clamp(val, min, max) ({                 \
        typeof(val) __val = (val);              \
        typeof(min) __min = (min);              \
        typeof(max) __max = (max);              \
        (void) (&__val == &__min);              \
        (void) (&__val == &__max);              \
        __val = __val < __min ? __min: __val;   \
        __val > __max ? __max: __val; })


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/
typedef void *(*THREAD_FUNC)(void *arg);




/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/

extern char *get_shell(char *cmd);


//十六进制字符串转十进制整数
extern int32_t str_to_int(char* str);


//将双字节中某一位置位置
extern void ob_util_set_bit_16(unsigned short *pBuff, int n);
//将双字节中某一位清零
extern void ob_util_clear_bit_16(unsigned short *pBuff, int n);
//获取双字节中某一位的值
extern int ob_util_get_bit_16(unsigned short buff, int n);

//将单字节中某一位置位置
extern void ob_util_set_bit_8(unsigned char *pBuff, int n);
//将单字节中某一位清零
extern void ob_util_clear_bit_8(unsigned char *pBuff, int n);
//获取单字节中某一位的值
extern int ob_util_get_bit_8(unsigned char buff, int n);


extern int ob_util_dumpToFile(const char *buf, int size, char *filename);
extern int ob_util_force_create_dir(const char *dirname);


extern int start_new_thread(const char *pThdName, pthread_t *pThdId, THREAD_FUNC pThdFunc, void *arg);
extern int start_new_thread_join(const char *pThdName, pthread_t *pThdId, THREAD_FUNC pThdFunc, void *arg);
extern int start_new_thread_ext(const char *pThdName, pthread_t *pThdId, THREAD_FUNC pThdFunc, void *arg, bool flag, int priority);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __UTILS_H__ */

