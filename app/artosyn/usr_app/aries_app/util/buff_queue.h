/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : buff_queue.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/4/24
*  Last Modified :
*  Description   : buff queue
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
#ifndef __BUFF_QUEUE_H__
#define __BUFF_QUEUE_H__


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <queue>
#include <mutex>
#include <new>
#include <iostream>
#include <condition_variable>
#include <initializer_list>
#include "basic_typedef.h"



/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/

/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/

/* 通用(多线程安全调用)队列类模版*/
template <typename T>
class CommonQueue{
private:
    std::mutex Mutex;
    std::condition_variable Cond;
    std::queue<T *> Queue;

    std::mutex PlMutex;
    std::queue<T *> Pool;


public:
    u32 uiCurMemberNum;
    u32 uiMaxMemberNum;

    CommonQueue(){}
    ~CommonQueue(){
        destroy();
    }

    virtual bool alloc_buffer(T **ppNewBuffer)    {
        if (uiCurMemberNum >= uiMaxMemberNum){
            //ERR("Current member number: %d have exceeded max: %d\n", uiCurMemberNum, uiMaxMemberNum);
            return false;
        }

        T *pBuffer = (T *)calloc(1, sizeof(T));
        if (NULL == pBuffer){
            ERR("Alloc buffer(size: %d B) failed\n", sizeof(T));
            return false;
        }

        uiCurMemberNum++;
        *ppNewBuffer = pBuffer;

        return true;
    }

    virtual void free_buffer(T *pOldBuffer)    {
		if (NULL != pOldBuffer){
        	free(pOldBuffer);
			pOldBuffer = NULL;
			uiCurMemberNum--;
		}
    }

    void free_queue(std::queue<T *> *pQueue) {
        if (pQueue->size()) {
            T *pBuffer = std::move(pQueue->front());
            pQueue->pop();
            if (NULL != pBuffer)
                free_buffer(pBuffer);
        }
    }

    void queue_clean()    {
        std::unique_lock<std::mutex> lk(Mutex);
        while (Queue.size())
            free_queue(&Queue);
    }

    void pool_clean()    {
        std::unique_lock<std::mutex> lk(PlMutex);
        while (Pool.size())
            free_queue(&Pool);
    }

    bool init(u32 uiBufferNum = 3, u32 uiMaxBufferNum = 5) {
        uiCurMemberNum = 0;
        uiMaxMemberNum = uiMaxBufferNum;

        if (uiBufferNum > uiMaxBufferNum)
            uiBufferNum = uiMaxBufferNum;

        for (int i = 0; i < uiBufferNum; i++) {
            T *pNewBuffer;
            if (!alloc_buffer(&pNewBuffer)) {
                ERR("Init buffer Pool %d/%d failed\n", i, uiBufferNum);
                break;
            }
            Pool.push(std::move(pNewBuffer));
        }

        if (0 == uiCurMemberNum) {
            ERR("None of alloc buffer(size: %d B) was successful\n", sizeof(T));
            return false;
        }

        return true;
    }

    static CommonQueue *create(u32 uiBufNum, u32 uiMaxBufNum) {
        CommonQueue *pQueue = new (std::nothrow) CommonQueue();
        if (NULL == pQueue){
			ERR("New pQuque failed.\n");
            return NULL;
        }

        if (pQueue->init(uiBufNum, uiMaxBufNum))
            return pQueue;

        delete pQueue;
        return NULL;
    }

    void destroy()   {
        queue_clean();
        pool_clean();
        if (!(Queue.empty() && Pool.empty()))  {
            ERR("Queue[Size: %d] and Pool[Size: %d] is not all empty, free buffer failed, Member number: %d/%d\n",
                Queue.size(), Pool.size(), uiCurMemberNum, uiMaxMemberNum);
        }
    }

    /**************buff池相关操作****************/
    void pool_put_buffer(T *pEmptyBuffer)   {
        std::unique_lock<std::mutex> lk(PlMutex);
        Pool.push(std::move(pEmptyBuffer));
    }

    T *pool_get_buffer()    {
        std::unique_lock<std::mutex> lk(PlMutex);
        T *pBuffer = NULL;

        if (!this->Pool.empty()) {
            pBuffer = std::move(Pool.front());
            Pool.pop();
        }else {
            if (!alloc_buffer(&pBuffer)){
                //ERR("Get buffer failed, size: %d\n", sizeof(T));
            }
        }

        return pBuffer;
    }

    bool pool_empty()   {
        std::unique_lock<std::mutex> lk(PlMutex);
        return Pool.empty();
    }

    u32 pool_size()   {
        std::unique_lock<std::mutex> lk(PlMutex);
        return Pool.size();
    }

    /**************队列相关操作****************/
    void queue_push(T *NewValue)   {
        std::unique_lock<std::mutex> lk(Mutex);
        Queue.push(std::move(NewValue));
        Cond.notify_one();
    }

    T *queue_wait_and_pop()    {
        std::unique_lock<std::mutex> lk(Mutex);
        Cond.wait(lk,[this]{return !this->Queue.empty();});
        auto Value=std::move(Queue.front());
        Queue.pop();
        return Value;
    }

    bool queue_try_pop(T **Value)    {
        std::unique_lock<std::mutex> lk(Mutex);
        if (Queue.empty())
            return false;
        *Value=std::move(Queue.front());
        Queue.pop();
        return true;
    }

    bool queue_empty()   {
        std::unique_lock<std::mutex> lk(Mutex);
        return Queue.empty();
    }

    u32 queue_size()   {
        std::unique_lock<std::mutex> lk(Mutex);
        return Queue.size();
    }

    u32 get_CurMemberNum(){       return uiCurMemberNum;}
    u32 get_MaxMemberNum(){return uiMaxMemberNum;}
    void set_MaxMemberNum(u32 uiMaxNum){uiMaxMemberNum = uiMaxNum;}
};


#if 0
typedef struct _FrameBuff
{
    struct video_ion stIonBuff;
}stFrameBuff;


class FrameBufferQueue{
private:
	u32 uiWidth;
	u32 uiHeight;
	int uiBpp;  //每像素bit数, 如rgb32的bpp为32, rgb24的bpp为24
	bool bIonFlag; //ture:用ion内存, false:用malloc的内存

	u8 ucMemberNum;
	u8 ucMemberMaxNum;

	std::mutex QuMutex;
	std::condition_variable QuCond;
	std::queue<stFrameBuff *> Queue;

	std::mutex PlMutex;
	std::queue<stFrameBuff *> Pool;

	bool alloc_buffer(stFrameBuff **ppNewBuffer){
		if (ucMemberNum >= ucMemberMaxNum){
			//err("Member number: %d has reached the Maximum: %d\n", ucMemberNum, ucMemberMaxNum);
			return false;
		}

		stFrameBuff *pBuffer = (stFrameBuff *)calloc(1, sizeof(stFrameBuff));
		if (NULL == pBuffer){
			FATAL("Alloc buffer failed, size: %d\n", sizeof(stFrameBuff));
			return false;
		}

		if (bIonFlag){
			/* 申请队列成员对应底层ion缓存区 */
			if (0 != video_ion_alloc_rational(&pBuffer->stIonBuff, uiWidth, uiHeight, uiBpp, 8)){
				FATAL("alloc ion buff failed.\n");
				return false;
			}
		}else{
			//使用malloc空间
			pBuffer->stIonBuff.width  = uiWidth;
			pBuffer->stIonBuff.height = uiHeight;
			pBuffer->stIonBuff.size   = uiWidth*uiHeight*uiBpp/8;;
			pBuffer->stIonBuff.buffer = malloc(pBuffer->stIonBuff.size);
			if (NULL == pBuffer->stIonBuff.buffer){
				FATAL("alloc userspace buff failed.\n");
				return false;
			}
		}

		ucMemberNum++;
		*ppNewBuffer = pBuffer;
		return true;
	}

	void free_buffer(std::queue<stFrameBuff *> *pQueue){
		if (pQueue->size())	{
			stFrameBuff *pBuffer = std::move(pQueue->front());
			pQueue->pop();

			if (bIonFlag){
				if (0 != video_ion_free(&pBuffer->stIonBuff)){
					FATAL("drm buff free failed.\n");
					return;
				}
			}else{
				if (NULL != pBuffer->stIonBuff.buffer){
					free(pBuffer->stIonBuff.buffer);
					pBuffer->stIonBuff.buffer = NULL;
				}
			}

			delete pBuffer;
			pBuffer = NULL;
			ucMemberNum--;
		}
	}

	void queue_clean()	{
		std::unique_lock<std::mutex> lk(QuMutex);
		while (Queue.size())
			free_buffer(&Queue);
	}

	void pool_clean()	{
		std::unique_lock<std::mutex> lk(PlMutex);
		while (Pool.size())
			free_buffer(&Pool);
	}


public:
	FrameBufferQueue(){}
	~FrameBufferQueue()	{
		DBG("~FrameBufferQueue clean, resolution: %u * %u\n", uiWidth, uiHeight);
		queue_clean();
		pool_clean();

		if (!(Queue.empty() && Pool.empty())){
			ERR("Queue[Size: %d] and Pool[Size: %d] is not all empty, free buffer failed, Member number: %d/%d\n",
				Queue.size(), Pool.size(), ucMemberNum, ucMemberMaxNum);
		}
	}

	bool init(u8 ucBufNum, u8 ucBufMaxNum, u32 w, u32 h, int bpp, bool flag){
		uiWidth = w;
		uiHeight = h;
		uiBpp = bpp;
		bIonFlag = flag;
		ucMemberNum = 0;
		ucMemberMaxNum = ucBufMaxNum;

		for (int i= 0; i < ucBufNum; i++){
			stFrameBuff *pNewBuffer = NULL;
			if (!alloc_buffer(&pNewBuffer))	{
				ERR("Init buffer Pool %d/%d failed\n", i, ucBufNum);
				return false;
			}
			Pool.push(std::move(pNewBuffer));
		}

		return true;
	}

	//参数flag: true表示申请队列成员对应底层Drm缓存区, false表示用malloc申请的buff
	static FrameBufferQueue *create(u8 ucBufNum, u8 ucBufMaxNum, u32 w, u32 h, int bpp, bool flag)	{
		FrameBufferQueue *pQueue = new (nothrow) FrameBufferQueue();
		if (NULL == pQueue){
			ERR("new CameraBufferQueue object failed.\n");
			return NULL;
		}

		if (pQueue && pQueue->init(ucBufNum, ucBufMaxNum, w, h, bpp, flag)){
			DBG("pQueue->init Success!\n");
			return pQueue;
		}

		ERR("pQueue->init Failed\n");
		delete pQueue;
		pQueue = NULL;
		return NULL;
	}

    bool pool_empty()   {
        std::unique_lock<std::mutex> lk(PlMutex);
        return Pool.empty();
    }

	u32 pool_size()	{
		std::unique_lock<std::mutex> lk(PlMutex);
		return Pool.size();
	}

	void pool_put_buffer(stFrameBuff *pEmptyBuffer){
		std::unique_lock<std::mutex> lk(PlMutex);
		Pool.push(std::move(pEmptyBuffer));
	}

	stFrameBuff *pool_get_buffer()	{
		std::unique_lock<std::mutex> lk(PlMutex);
		stFrameBuff *pBuffer = NULL;

		if (Pool.size()){
			pBuffer = std::move(Pool.front());
			Pool.pop();
		}else{
			if (!alloc_buffer(&pBuffer)){
				//err("Alloc a new buffer failed when pool was empty\n");
			}
		}
		return pBuffer;
	}

	void queue_push(stFrameBuff *pBuffer){
		std::unique_lock<std::mutex> lk(QuMutex);
		Queue.push(std::move(pBuffer));
		QuCond.notify_one();
	}

	stFrameBuff *queue_wait_and_pop(){
		std::unique_lock<std::mutex> lk(QuMutex);
		QuCond.wait(lk,[this]{return !this->Queue.empty();});
		auto Value=std::move(Queue.front());
		Queue.pop();
		return Value;
	}

	bool queue_try_pop(stFrameBuff **Value)	{
		std::unique_lock<std::mutex> lk(QuMutex);
		if (Queue.empty())
			return false;
		*Value=std::move(Queue.front());
		Queue.pop();
		return true;
	}

	bool queue_empty()	{
		std::unique_lock<std::mutex> lk(QuMutex);
		return Queue.empty();
	}

	u32 queue_size(){
		std::unique_lock<std::mutex> lk(QuMutex);
		return Queue.size();
	}

	u8 get_member_num(){
		return ucMemberNum;
	}
};
#endif


#endif /* __BUFF_QUEUE_H__ */


