#ifndef __TOF_DSP_MEMORY_MAP_H__
#define __TOF_DSP_MEMORY_MAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "ar_icc.h"
#include "ar_ion.h"
#include <sys/time.h>
#include <time.h>
#include "arm_to_dsp_data.h"

typedef struct 
{
	char * va;	// 输入结构体参数的虚拟地址
	char * pa;	// 输入结构体参数的物理地址
	int  len;		// 申请输入数据结构体的长度
}param_ion_mellc_t;

typedef struct
{
	int status;
	uint32_t input_va_addr;
    uint32_t input_pa_addr;
    uint32_t output_va_addr;
	uint32_t output_pa_addr;
}ring_buf_ctrl_t;

#define AR_DSP_HEAP_ID      27
#define USE_ION_MEM_NUM     10
typedef enum
{
    /* mark memory number */
    TOF_DspParams_MEM = 0,         /* tofdspParams结构体参数空间 */
    TOF_FrameInputs_MEM,        /* 图像数据输入缓冲空间 */
    TOF_FrameOutputs_MEM,       /* 图像数据输出缓冲空间 */
    TOF_DspTemporaryUse_MEM,    /* DSP运算使用空间 */
    TOF_DepthCoef_MEM,          /* 距离转深度系数空间 */
    TOF_CalibParam_MEM,         /* 标定所需的临时buffer */

    /* need of memory length,规划使用空间预留，不一定全用完全 */
    TOF_DspParams_LEN = 1*1024*1024,//1MB
    TOF_FrameInputs_LEN = 1280*1000*2*16,//预留16张图片尺寸大小缓冲，37MB
    TOF_FrameOutputs_LEN = 1280*1000*2*16,//预留16张图片尺寸大小缓冲，37MB
    TOF_DspTemporaryUse_LEN = 64*1024*1024,//64MB
    TOF_DepthCoef_LEN = 1*1024*1024,//1MB,目前实际使用1200kB
    TOF_CalibParam_LEN = 30*1024*1024,//30MB
}tof_mem_info_t;


//-----------------数据帧及帧组---------------------//
typedef enum {
	OB_TOF_OUT_MODE_A_B = 0,
	OB_TOF_OUT_MODE_A_ADD_B = 1,
	OB_TOF_OUT_MODE_A = 2,
	OB_TOF_OUT_MODE_B = 3,
	OB_TOF_OUT_MODE_A_AND_B = 4,
	OB_TOF_OUT_MODE_S5K_4TAP_DUAL_FREQ = 10,
}ObTofOutMode;

typedef enum {
	PHASE_NON_SHUFFLE = 0X10,
	PHASE_SHUFFLE 	  = 0X1B,
	UNKNOW			  = -1,
}ObTofPhaseType;

typedef enum {
	FRAME_TYPE_PHASE,	//相位图
	FRAME_TYPE_AMP,		//幅值图
	FRAME_TYPE_IR,		//ir强度图
	FRAME_TYPE_DEPTH,	//深度图
}ObTofFrameType;

// #pragma pack(push, 4)

typedef struct obc_tof_frameinfo_ {
    char* buffer;
    uint32_t buffer_size;
    int width;
    int height;
	
    uint32_t frequency;     		// 调制频率
    float duty_cycle;      			// 占空比
    uint32_t integration_time;  	// 积分时间

    ObTofOutMode out_mode;      	// 数据模式
	ObTofPhaseType phaseType;		// 相位类型

	float temp_tx;					// tx温度	对应dsp中vcsel_temp
    float temp_rx;          		// rx温度	对应dsp中sensor_temp
    float temp_delay;  				// 延时电路温度

    uint8_t frame_index;    		// 帧序号，范围1~254
    uint8_t group_index;    		// 组序号，没有组概念时为-1
    ObTofFrameType frameType;   	// 数据类型
}ObTofFrame;

typedef struct obc_tof_frames_ {
    //时间戳，异步计算时采用
	long long timestamp;
    // 指针数组
    ObTofFrame **frames;
    // 表示传入的帧空间数
    uint32_t frame_count;
    // 实际帧数量
    uint32_t real_count;
}ObTofFrameGroup;



#define AR_GET_ION_MEMORY(VA, PA, SIZE) \
do{ \
	VA = ar_ion_malloc(SIZE); \
	if(!VA) \
	{ \
		printf("%s %d: Malloc memory failed, exit!\r\n", __FUNCTION__, __LINE__); \
	} \
	PA = ar_ion_virt_to_phy(VA); \
	if(!PA) \
	{ \
		printf("%s %d: Virt to phy failed, exit!\r\n", __FUNCTION__, __LINE__); \
	} \
}while(0)

#define AR_RELEASE_ION_MEMORY(VA) ar_ion_free(VA)

/*
	申请-初始化buffer空间
    初始化 ObTofDspParams
    初始化 icc_msg
*/
int init_tof_buffer();

#endif
