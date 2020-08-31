/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : item_ring_buffer.cpp
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/6/2
*  Last Modified :
*  Description   : orbbec item ring buffer opration api
*  History:
* 
*       1.  Date         : 2020/6/2
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/

/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <string.h>
#include <stdlib.h>
#include "item_ring_buffer.h"
#include "logutil.h"


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
#define ITEM_INTERVAL(size, curno, oldno, wpos, opos) ((((curno) - (oldno))*(size)) + (wpos) - (opos))


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/



/*****************************************************************************
*   Prototype    : item_ring_buffer_init
*   Description  : ring buff队列初始化
*   Input        : item_ring_buffer *rb          
*                  item_release_func release_cb  
*                  unsigned int itemSize  (队列中每个元素的size)
*                  unsigned int capacity  (队列长度)     
*   Output       : None
*   Return Value : int
*****************************************************************************/
int item_ring_buffer_init(item_ring_buffer *rb, item_release_func release_cb, unsigned int itemSize, unsigned int capacity)
{
    int ret = -1;

    if(!rb) {
        ERR("rb is NULL.\n");
        goto OUT;
    }

    rb->data = malloc(itemSize * capacity);
    if(rb->data == NULL){
        ERR("no memory.\n");
        goto OUT;
    }
    
    rb->old_wpos = rb->cur_wpos = 0;
    rb->cur_wo = 0;
    rb->count = 0;
    rb->capacity = capacity;
    rb->itemsize = itemSize;
    rb->release_cb = release_cb;
    
    pthread_mutex_init(&rb->mutex,NULL);
    
    ret = 0;
OUT:
    return ret;
}


/*****************************************************************************
*   Prototype    : item_ring_buffer_deinit
*   Description  : item ring buff 去初始化
*   Input        : item_ring_buffer *rb  
*   Output       : None
*   Return Value : void
*****************************************************************************/
void item_ring_buffer_deinit(item_ring_buffer *rb)
{
    if(!rb){
        return;
    }
    while(!item_ring_buffer_empty(rb)){
        item_ring_buffer_pop(rb);
    }
    free(rb->data);
    pthread_mutex_destroy(&rb->mutex);
}


/*****************************************************************************
*   Prototype    : item_ring_buffer_empty
*   Description  : 判断是否ringbuff是否为空
*   Input        : item_ring_buffer *rb  
*   Output       : None
*   Return Value : int
*****************************************************************************/
int item_ring_buffer_empty(item_ring_buffer *rb)
{
    int count = rb->count;

    return count == 0;
}


/*****************************************************************************
*   Prototype    : item_ring_buffer_full
*   Description  : 判断ring buff是否full
*   Input        : item_ring_buffer *rb  
*   Output       : None
*   Return Value : int
*****************************************************************************/
int item_ring_buffer_full(item_ring_buffer *rb)
{
    int flag = rb->count>0 && (rb->old_wpos == rb->cur_wpos);

    return flag;
}


/*****************************************************************************
*   Prototype    : item_ring_buffer_push
*   Description  : push item to ring buff
*   Input        : item_ring_buffer *rb   
*                  void* itemData         
*                  unsigned int itemSize  
*   Output       : None
*   Return Value : int
*****************************************************************************/
int item_ring_buffer_push(item_ring_buffer *rb, void* itemData, unsigned int itemSize)
{
    unsigned int pos;
    unsigned long offset = 0;

    if(!rb || !itemData || itemSize!=rb->itemsize){
        return -1;
    }
    
    pthread_mutex_lock(&rb->mutex);
    offset = rb->cur_wpos * rb->itemsize;
    memcpy(rb->data + offset, itemData, itemSize);
    rb->cur_wpos += 1;

    if(rb->cur_wpos >= rb->capacity){
        rb->cur_wpos = 0;
        rb->cur_wo += 1;
    }
    atomic_inc(&rb->count);
    pthread_mutex_unlock(&rb->mutex);
    
    //Ringbuffer full,get the oldest item and release
    if(item_ring_buffer_full(rb)){
        item_ring_buffer_pop(rb);
    }
    
    return 0;
}


int item_ring_buffer_peek(item_ring_buffer *rb, int offset, void *itemData, unsigned int itemSize)
{
    if(!rb || !itemData || itemSize!= rb->itemsize || item_ring_buffer_empty(rb)){
        return -1;
    }
    
    if(offset < 0 || offset >= rb->capacity){
        return -1;
    }
    pthread_mutex_lock(&rb->mutex);
    memcpy(itemData, rb->data + offset*rb->itemsize, rb->itemsize);
    pthread_mutex_unlock(&rb->mutex);
    return 0;
}


int item_ring_buffer_peek_oldest(item_ring_buffer *rb, void *itemData, unsigned int itemSize)
{
    if(!rb || !itemData || itemSize!=rb->itemsize || item_ring_buffer_empty(rb)){
        return -1;
    }
    pthread_mutex_lock(&rb->mutex);
    memcpy(itemData, rb->data + rb->old_wpos*rb->itemsize, rb->itemsize);
    pthread_mutex_unlock(&rb->mutex);
    return 0;
}

int item_ring_buffer_peek_nearest_index(item_ring_buffer *rb,int range,int oldPos,int *oldNo)
{
    unsigned int n;
    int index = -1,remain;

    pthread_mutex_lock(&rb->mutex);
     if(rb->cur_wpos>=rb->old_wpos){
        n = rb->cur_wpos-rb->old_wpos;
    }else{
        n = rb->cur_wpos-rb->old_wpos + rb->capacity;
    }
    
    remain = ITEM_INTERVAL(rb->capacity,rb->cur_wo,*oldNo,rb->cur_wpos,oldPos<0?0:oldPos);
    //printf("remain:%d,cur_no:%d,old_no:%d,cur_pos:(%d,%d),old_pos:%d\n",remain,rb->cur_wo,*oldNo,rb->cur_wpos,rb->old_wpos,oldPos);
    if(remain<=0){
        goto OUT;
    }else if(remain>rb->capacity || oldPos<0){
        n = n>range?range:n;
        index = rb->cur_wpos>=n?rb->cur_wpos-n:rb->cur_wpos-n+rb->capacity;
        *oldNo = rb->cur_wo;
        goto OUT;
    }
   
    if(remain>0){
            index = oldPos + 1;
            if(index>=rb->capacity){
                index = 0;
                *oldNo = rb->cur_wo;
            }
        }else{
        n = n>range?range:n;
        index = rb->cur_wpos>=n?rb->cur_wpos-n:rb->cur_wpos-n+rb->capacity;
        *oldNo = rb->cur_wo;
    }

OUT:
    pthread_mutex_unlock(&rb->mutex);
    return index;
}


int item_ring_buffer_pop(item_ring_buffer *rb)
{
    if(!rb || item_ring_buffer_empty(rb)){
        return -1;
    }
    pthread_mutex_lock(&rb->mutex);
    if(rb->release_cb){
        rb->release_cb(rb->data+rb->old_wpos*rb->itemsize);
    }
    rb->old_wpos += 1;
    if(rb->old_wpos>=rb->capacity){
        rb->old_wpos = 0;
    }
    atomic_dec(&rb->count);
    pthread_mutex_unlock(&rb->mutex);
    return 0;
}


int item_ring_buffer_reset(item_ring_buffer *rb)
{
    while(!item_ring_buffer_empty(rb)){
        item_ring_buffer_pop(rb);
        pthread_mutex_lock(&rb->mutex);
        rb->old_wpos = rb->cur_wpos = 0;
        rb->count = 0;
        pthread_mutex_unlock(&rb->mutex);
    }
    return 0;
}


