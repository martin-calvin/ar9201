/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : logutil.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/4/24
*  Last Modified :
*  Description   : logutil.h header file
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
#ifndef __LOGUTIL_H__
#define __LOGUTIL_H__


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
       
#define __DEBUG__
#ifdef __DEBUG__
        
#define DBG(fmt, args...) \
                do { \
                    fprintf(stderr, "[DEBUG] %s(%d) " fmt, __FUNCTION__, __LINE__, ##args); \
                } while (0)
        
#define INFO(fmt, args...) \
                do { \
                    fprintf(stderr, "[INFO] %s(%d) " fmt, __FUNCTION__, __LINE__, ##args); \
                } while (0)
        
#define NOTICE(fmt, args...) \
                do { \
                    fprintf(stderr, "[NOTICE] %s(%d) " fmt, __FUNCTION__, __LINE__, ##args); \
                } while (0)
        
#define WARN(fmt, args...) \
                do { \
                    fprintf(stderr, "[WARN] %s(%d) " fmt, __FUNCTION__, __LINE__, ##args); \
                } while (0)
        
#define ERR(fmt, args...) \
                do { \
                    fprintf(stderr, "[ERROR] %s(%d) " fmt, __FUNCTION__, __LINE__, ##args); \
                } while (0)
        
#define FATAL(fmt, args...) \
                do { \
                    fprintf(stderr, "[FATAL] %s(%d) " fmt, __FUNCTION__, __LINE__, ##args); \
                } while (0)
        
#else
        
#define DBG(fmt, args...)
#define INFO(fmt, args...)
#define NOTICE(fmt, args...)
#define WARN(fmt, args...)
#define ERR(fmt, args...)
#define FATAL(fmt, args...)
        
#endif
        


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __LOGUTIL_H__ */
