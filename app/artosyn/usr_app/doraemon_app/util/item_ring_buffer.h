
/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : item_ring_buffer.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/6/2
*  Last Modified :
*  Description   : item_ring_buffer.cpp header file
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/6/2
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/
#ifndef __ITEM_RING_BUFFER_H__
#define __ITEM_RING_BUFFER_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <stdio.h>
#include <stdarg.h>
#include <pthread.h>
#include "atomic_op.h"



/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/
typedef void (*item_release_func)(void *data);

typedef struct{
    int cur_wpos;
    int old_wpos;
    int cur_wo;
    unsigned int itemsize;  //ring buff中每个元素的size
    unsigned int capacity;  //ring buff的长度
    atomic_t count;
    item_release_func release_cb; //内存释放回调
    pthread_mutex_t mutex;
    void* data;
}item_ring_buffer;



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/

extern void item_ring_buffer_deinit(item_ring_buffer *rb);
extern int item_ring_buffer_empty(item_ring_buffer *rb);
extern int item_ring_buffer_full(item_ring_buffer *rb);
extern int item_ring_buffer_init(item_ring_buffer *rb, item_release_func release_cb, unsigned int itemSize, unsigned int capacity);
extern int item_ring_buffer_peek(item_ring_buffer *rb, int offset, void *itemData, unsigned int itemSize);
extern int item_ring_buffer_peek_nearest_index(item_ring_buffer *rb,int range,int oldPos,int *oldNo);
extern int item_ring_buffer_peek_oldest(item_ring_buffer *rb, void *itemData, unsigned int itemSize);
extern int item_ring_buffer_pop(item_ring_buffer *rb);
extern int item_ring_buffer_push(item_ring_buffer *rb, void* itemData, unsigned int itemSize);
extern int item_ring_buffer_reset(item_ring_buffer *rb);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __ITEM_RING_BUFFER_H__ */


