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

#include "zlog.h"
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
                       zlog_debug(zlog_category,"" fmt,##args); \    
                } while (0)
        
#define INFO(fmt, args...) \
                do { \
                       zlog_info(zlog_category,"" fmt,##args); \
                } while (0)
        
#define NOTICE(fmt, args...) \
                do { \
                       zlog_notice(zlog_category,"" fmt,##args); \
                } while (0)
        
#define WARN(fmt, args...) \
                do { \
                       zlog_warn(zlog_category,"" fmt,##args); \
                } while (0)
        
#define ERR(fmt, args...) \
                do { \
                       zlog_error(zlog_category,"" fmt,##args); \
                } while (0)
        
#define FATAL(fmt, args...) \
                do { \
                       zlog_debug(zlog_category,"" fmt,##args); \
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
