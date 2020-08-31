/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : depth_stream.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/7/14
*  Last Modified :
*  Description   : depth_stream.cpp header file
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/7/14
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/
#ifndef __DEPTH_STREAM_H__
#define __DEPTH_STREAM_H__




/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <semaphore.h>
#include <stdint.h>
#include "tof_info.h"
#include "buff_queue.h"

/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/
static void *depth_uvc_send_process_thd(void *arg);

class DepthStreamContext{
private:
	int width;
	int height;
	int bpp;

	sem_t semDepthProcessStart;
	bool bProcessFlag;
	pthread_t calcDepth_thd_tid;

    CommonQueue<ObDepthFrame> *pBuffQueue;  //depth cache buff queue

public:
	DepthStreamContext();
	~DepthStreamContext();

	int depth_calc_process(ObTofFrameGroup *group);
	int depth_uvc_start(void);
	int depth_uvc_stop(void);

	friend void *depth_uvc_send_process_thd(void *arg);

};


#endif /* __DEPTH_STREAM_H__ */


