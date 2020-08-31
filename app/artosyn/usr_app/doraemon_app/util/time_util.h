/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : time_util.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/06/10
*  Last Modified :
*  Description   : time_util.h header file
*  Function List :
*
*
*  History:
*
*       1.  Date         : 2020/06/10
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/
#ifndef __TIME_UTIL_H__
#define __TIME_UTIL_H__


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <time.h>
#include "logutil.h"


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
#define DESCRIPTOR_MAX_LENGTH               128


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/


/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/

//1970年1月1日到现在的时间
static inline uint64_t get_time_ms(void) //ms
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (uint64_t)tv.tv_sec * 1000 + (uint64_t)tv.tv_usec /1000;
}


//1970年1月1日到现在的时间
static inline uint64_t get_time_us() //us
{
	struct timeval tv;
	gettimeofday(&tv,NULL);
	return (uint64_t)tv.tv_sec * 1000000 + (uint64_t)tv.tv_usec;
}

/************************************************************************
 ** 函数名:	   get_sys_runtime
 ** 函数描述:	返回系统运行时间 ms
 ** 返回: 	 毫秒
 ************************************************************************/
static inline long long get_sys_runtime_ms()
{
	struct timespec times = {0, 0};
	clock_gettime(CLOCK_MONOTONIC, &times);
	return times.tv_sec * 1000 + times.tv_nsec / 1000000;
}

static inline long long get_sys_runtime_us()
{
	struct timespec times = {0, 0};
	clock_gettime(CLOCK_MONOTONIC, &times);
	return times.tv_sec * 1000000ULL + times.tv_nsec / 1000;
}


/*****************************************************************************
*   Prototype    : Timer
*   Description  : 用于耗时测试的类
*   Input        : None
*   Output       : None
*   Return Value : class
*   Calls        :
*   Called By    :

    用法举例:

    Timer stOpenniRGATimer;
    stOpenniRGATimer.SetDescriptors((char *)"OpenniRGA one frame");
    stOpenniRGATimer.OpenTimeSwitch();


    stOpenniRGATimer.StartTiming();

    process...

    stOpenniRGATimer.StopTiming();
    stOpenniRGATimer.PrintAverageTime(30);

*****************************************************************************/
class Timer
{
private:
    bool bTimeSwitch;   /* 计时开关 */
    u64 ullStartTime;   /* 启动(计时)时间 us*/
    u64 ullStopTime;    /* 停止(计时)时间 us*/

    u64 ullTimeCount;   /* 计时次数 */
    u64 ullTotalTime;   //us
    u64 ullAverageTime; //us

    u64 ullLastTime;    //us

    char acDescriptors[DESCRIPTOR_MAX_LENGTH];

    bool GetCurTime(u64 *pCurTime)  { //us
        struct timeval stCurTime = {0};

        if (gettimeofday(&stCurTime, NULL) == -1) {
            ERR("Get current time failed\n");
            return false;
        }

        u64 ullTotalUsec = stCurTime.tv_sec * 1000000ULL;
        *pCurTime = ullTotalUsec + stCurTime.tv_usec;
        return true;
    }

    char *PrintTimeDiff(u64 ullTimeFrom, u64 ullTimeTo){ //us
        u64 ullTotalUsec, ullTotalSec;              /* 总微秒数、总秒数 */
        u32 uiHour, uiMin, uiSec, uiMsec, uiUsec;   /* 小时、分钟、秒数、毫秒数、微秒数 */
        static char acStr[DESCRIPTOR_MAX_LENGTH] = {0};

        ullTotalUsec = ullTimeTo - ullTimeFrom;

        uiUsec = ullTotalUsec % 1000;
        uiMsec = (ullTotalUsec / 1000) % 1000;
        ullTotalSec = ullTotalUsec / 1000000;
        uiSec = ullTotalSec % 60;

        if (ullTotalSec / 60 > 0){
            uiMin = (ullTotalSec / 60) % 60; /* 获取分钟 */
            uiHour = ullTotalSec / 3600;  /* 获取小时(总秒数 / (60 * 60)) */
            sprintf(acStr, "%02u:%02u:%02u.%03u[%03u]", uiHour, uiMin, uiSec, uiMsec, uiUsec);
        }
        else
            sprintf(acStr, "%02u.%03u[%03u]", uiSec, uiMsec, uiUsec);

        return acStr;
    }


public:

    Timer(void){
        bTimeSwitch = false;
        ullStartTime = 0;
        ullStopTime = 0;
        ullTimeCount = 0;
        ullAverageTime = 0;
        ullLastTime = 0;

        memset((void *)acDescriptors, 0, DESCRIPTOR_MAX_LENGTH);
        strcpy(acDescriptors, "Time interval");
    }

    ~Timer(){}

    bool GetTimeSwitch(){return bTimeSwitch;}
    void OpenTimeSwitch(){bTimeSwitch = true;}
    void CloseTimeSwitch(){bTimeSwitch = false;}

    bool SetDescriptors(char *pcDescriptors)  {
        if (strlen(pcDescriptors) >= DESCRIPTOR_MAX_LENGTH) {
            ERR("The description is too long!\n");
            return false;
        }

        memset((void *)acDescriptors, 0, DESCRIPTOR_MAX_LENGTH);
        strcpy(acDescriptors, pcDescriptors);
        return true;
    }

    bool StartTiming()  {
        if (!bTimeSwitch)
            return true;

        if (!this->GetCurTime(&ullStartTime)) {
            ERR("Get start time failed\n");
            return false;
        }
        return true;
    }

    bool StopTiming() {
        if (!bTimeSwitch)
            return true;

        if (!this->GetCurTime(&ullStopTime)) {
            ERR("Get stop time failed\n");
            return false;
        }

        ullTimeCount++;
        ullTotalTime += ullStopTime - ullStartTime;
        return true;
    }

#if 0
    bool StartTimeInterval()  {
        if (!bTimeSwitch)
            return true;

        if (!this->GetCurTime(&ullLastTime)) {
            err("Get the first time failed\n");
            return false;
        }
        return true;
    }

    bool TimeIntervalTimer()  {
        if (!bTimeSwitch)
            return true;

        u64 ullCurTime;
        if (!this->GetCurTime(&ullCurTime)) {
            err("Get current time failed\n");
            return false;
        }

        ullTimeCount++;
        ullTotalTime += ullCurTime - ullLastTime;
        ullLastTime = ullCurTime;

        return true;
    }
#endif

    void PrintTime() {
        if (!bTimeSwitch)
            return;

        printf("\t%s cost %s\n", acDescriptors, this->PrintTimeDiff(ullStartTime, ullStopTime));
        ullStartTime = 0;
        ullStopTime = 0;
    }

    void PrintAverageTime(u32 uiCycle = 1) {
        if (!bTimeSwitch)
            return;
        if (ullTimeCount && ((ullTimeCount % uiCycle) == 0)) {
            ullAverageTime = ullTotalTime / ullTimeCount;
            printf("\t%s average cost %s\n", acDescriptors, this->PrintTimeDiff(0, ullAverageTime));
            ullStartTime = 0;
            ullStopTime = 0;
            ullTimeCount = 0;
            ullTotalTime = 0;
            ullAverageTime = 0;
        }
    }
};

#endif /* __TIME_UTIL_H__ */


