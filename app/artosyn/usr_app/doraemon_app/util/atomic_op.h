/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : atomic_op.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/6/2
*  Last Modified :
*  Description   : atomic_op.h header file
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
#ifndef __ATOMIC_OP_H__
#define __ATOMIC_OP_H__


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/

typedef volatile int atomic_t;

#define atomic_fetch_and_add(p, val)  __sync_fetch_and_add(p, val)
#define atomic_add_and_fetch(p, val)  __sync_add_and_fetch(p, val)
#define atomic_fetch_and_sub(p, val)  __sync_fetch_and_sub(p, val)
#define atomic_sub_and_fetch(p, val)  __sync_sub_and_fetch(p, val)
#define atomic_inc(p) atomic_add_and_fetch(p, 1)
#define atomic_dec(p) atomic_sub_and_fetch(p, 1)

#define atomic_test_and_set(p, oldval, newval) __sync_bool_compare_and_swap(p, oldval, newval)

#define UNLOCK  0
#define LOCK 1
#define atomic_lock(p) while(!atomic_test_and_set(p, UNLOCK, LOCK))\
                                usleep(10000)
#define atomic_unlock(p) atomic_test_and_set(p, LOCK, UNLOCK)

#define UNLOCK_RW  0
#define LOCK_READ   2
#define LOCK_WRITE 3
#define atomic_lock_read(p, ref)    do { \
                                       while(!atomic_test_and_set(p, UNLOCK_RW, LOCK_READ) && \
                                        !atomic_test_and_set(p, LOCK_READ, LOCK_READ)) {\
                                                usleep(10000);}\
                                                atomic_inc(ref);\
                                } while(0)

#define atomic_unlock_read(p, ref)     do {\
                                        atomic_dec(ref);\
                                        if (0 == *ref)\
                                            atomic_test_and_set(p, LOCK_READ, UNLOCK_RW);\
                                   } while(0)

#define atomic_lock_write(p)      do { \
                                       while(!atomic_test_and_set(p, UNLOCK_RW, LOCK_WRITE)) {\
                                                usleep(10000);}\
                              } while(0)

#define atomic_unlock_write(p)    do {\
                                       atomic_test_and_set(p, LOCK_WRITE, UNLOCK_RW);\
                              } while(0)


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/


/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/


#endif /* __ATOMIC_OP_H__ */


