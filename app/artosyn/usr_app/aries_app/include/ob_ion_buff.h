/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : ob_ion_buff.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/7/23
*  Last Modified :
*  Description   : orbbec ion buff manage
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/7/23
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/
#ifndef __OB_ION_BUFF_H__
#define __OB_ION_BUFF_H__


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include "ar_ion.h"
#include "utils.h"
#include "logutil.h"


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/

typedef struct{
	unsigned char *va;	//虚拟地址
	unsigned char *pa;	//物理地址
	size_t size;        //长度
}ion_buff_t;


#define OB_ALLOC_ION_BUFFER(VA, PA, SIZE) \
    do{ \
    	VA = ar_ion_malloc(SIZE); \
    	if(!VA) \
    	{ \
    		ERR("Malloc memory failed, exit!\r\n"); \
    	} \
    	PA = ar_ion_virt_to_phy(VA); \
    	if(!PA) \
    	{ \
    		ERR("Virt to phy failed, exit!\r\n"); \
    	} \
    }while(0)


#define OB_RELEASE_ION_BUFFER(VA) \
    do{\
        if (NULL != VA){ \
            ar_ion_free(VA);\
            VA = NULL; \
        } \
    }while(0)



/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/


/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/


#endif /* __OB_ION_BUFF_H__ */

