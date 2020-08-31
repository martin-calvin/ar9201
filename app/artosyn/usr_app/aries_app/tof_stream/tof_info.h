/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : tof_info.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/6/5
*  Last Modified :
*  Description   : tof相关信息定义
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/6/5
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/
#ifndef __TOF_INFO_H__
#define __TOF_INFO_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include "basic_typedef.h"
#include "tof_embedded.h"
#include "ar_picture_common_api.h"
#include "ob_ion_buff.h"

/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/


/*==============================================*
 *      enum define                             *
 *----------------------------------------------*/
//帧标签
typedef enum{
	FRAME_TYPE_PHASE,    //相位图
	FRAME_TYPE_AMP,      //幅值图
	FRAME_TYPE_IR,       //ir强度图
	FRAME_TYPE_DEPTH,    //深度图
}ObTofFrameType;

    
//uvc上位机请求的tof流类型
typedef enum _TOF_UVC_RQ_STREAM_TYPE
{
    TOF_STREAM_UNKNOWN, //unknown
    TOF_STREAM_PHASE,   //rawphase流
    TOF_STREAM_IR,      //ir流
    TOF_STREAM_DEPTH,   //depth流
    TOF_STREAM_MAX
}TOF_UVC_RQ_STREAM_TYPE;


/*==============================================*
 *      struct define                           *
 *----------------------------------------------*/

#pragma pack(push, 4)
typedef struct obc_tof_frameinfo_
{
    uint32_t frame_id;           //rtos端打的id(注意与EBD数据里面的frame_index区别开)
    uint32_t pts;                //ms; pts from rtos
    uint32_t width; 
    uint32_t height;
    uint32_t buffer_size;        //frame size

    float duty_cycle;            //调制信号的占空比,如值为50.00对应50%的占空比
    uint32_t intergration_time;  //积分时间(us), 如:600us

    //embedded信息
    uint8_t frame_index;         //帧序号(0~254重复循环)
    ObTofModFreq frequency;      //调制频率
    ObTofPhaseType phaseType;    //相位类型
    ObTofOutMode out_mode;       //数据模式
    float temp_tx;               //tx温度 如: 34.24
    float temp_rx;               //rx温度

    ar_picture_buffer_t *pRawBuff;  //tof camera输出buff
}ObTofFrame;
#pragma pack(pop)


#pragma pack(push,4)
typedef struct ObTofFrameGroup_
{
    long long timestamp;
    ObTofFrame **frames;  //Group中存储的多个frame指针(4帧)
    uint32_t frame_count; //每个Group中的预计Frame数量    
    uint32_t real_count;  //当前Group中实际帧数量, 也作为grup中add帧的index
}ObTofFrameGroup;
#pragma pack(pop)

typedef struct obc_tof_exteraline_
{
    uint16_t sensorId;    //sesnsor-33d: 0x033D
    uint16_t width;
    uint16_t height;
    uint16_t frequency;   //调制频率
    float duty_cycle;     //调试信号占空比
    uint16_t intergration_time; //积分时间
    uint16_t out_mode;    //ObTofOutMode
    uint16_t phaseType;   //ObTofPhaseType
    float temp_tx;        //tx温度
    float temp_rx;        //rx温度
    uint16_t frame_index; //帧序号
    uint16_t frame_type;  //帧类型, ObTofFrameType
    uint32_t pts;         //rtos打的帧时间戳,设备开机到当前的毫秒数(ms)
}__attribute__((packed)) ObTofExteraLine;



#pragma pack(push,4)
typedef struct ObDepthFrame_
{
    uint32_t frame_id;           //rtos端打的id(注意与EBD数据里面的frame_index区别开)
    uint32_t pts;                //ms; pts from rtos
    uint32_t width; 
    uint32_t height;
    uint32_t buffer_size;        //frame size

    //embedded信息
    float duty_cycle;            //调制信号的占空比,如值为50.00对应50%的占空比
    uint32_t intergration_time;  //积分时间(us), 如:600us
    uint8_t frame_index;         //帧序号(0~254重复循环)
    ObTofModFreq frequency;      //调制频率
    ObTofPhaseType phaseType;    //相位类型
    ObTofOutMode out_mode;       //数据模式
    float temp_tx;               //tx温度 如: 34.24
    float temp_rx;               //rx温度

    ion_buff_t stIonBuff;        //深度输出存储buff
}ObDepthFrame;
#pragma pack(pop)


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


#endif /* __TOF_INFO_H__ */


