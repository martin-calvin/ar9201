#ifndef __TOF_DSP_MEMORY_MAP_H__
#define __TOF_DSP_MEMORY_MAP_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "ar_icc.h"
#include "ar_ion.h"
#include <sys/time.h>
#include <time.h>
#include "arm_to_dsp_data.h"
#include "tof_calib_params.h"
#include "tof_calibration_params_parser.h"

typedef struct 
{
	char * va;	// 输入结构体参数的虚拟地址
	char * pa;	// 输入结构体参数的物理地址
	int  len;		// 申请输入数据结构体的长度
}param_ion_mellc_t;

#define AR_DSP_HEAP_ID      27
#define USE_ION_MEM_NUM     20

struct mem_list_t
{
    uint32_t mem_name;
    uint32_t mem_len;
};

typedef enum
{
    /* mark memory number */
    TOF_DspParams_MEM = 0,     /* tofdspParams结构体参数空间 */

    /* 输入空间memory */
    TOF_phase_low_nshl_MEM,	
    TOF_phase_low_shl_MEM,	
    TOF_phase_high_nshl_MEM,
    TOF_phase_high_shl_MEM,
    /* 输出空间memory */
    TOF_amp_low_MEM,
    TOF_amp_high_MEM,
    TOF_depth0_MEM,
    TOF_depth1_MEM,
    TOF_ir_0_MEM,
    TOF_ir_1_MEM,

    TOF_DspUse_MEM,    			/* DSP运算使用空间 */
    TOF_temp_MEM,         	   /* 内外参标定所需的空间 */

	D2C_linear_rot_coeff_ht,
	D2C_linear_color_y_max_lut,
	D2C_linear_color_y_min_lut
}tof_mem_info_t;

#pragma once
#pragma pack(push,1) //按字节对齐
//[静态]标定内参结构体：验证通信数据用
typedef struct CALIB_PARAM_FILE_ST
{
	int 					width;					// 相位图宽度
	int 					height;					// 相位图高度
/***************************ObToFParam***************************************/
	ObTofHeader hdr; // Tof param 头文件
	ObToFDeviceInfo dev_info; // 器件信息
	ObToFIRIntrinsic ir_intrin; // ir的内参信息
	ObDistoCoeffs distort; //畸变的类型
	ObToFSensorParams sensor_param[TOF_FREQ_NUM]; //sensor的参数

	//ObToFTempCompensation temp_comp[0];// ==> 转化为连续内存
	uint16_t vcsel_coeff_size_0; //目前为size为1
	uint16_t sensor_coeff_size_0;//目前为size为1
	float vcsel_temp_comp_coeff_0[1];
	float sensor_temp_comp_coeff_0[1];
	float temp_dist_offset_0; 
	//ObToFTempCompensation temp_comp[1];// ==> 转化为连续内存
	uint16_t vcsel_coeff_size_1; //目前为size为1
	uint16_t sensor_coeff_size_1;//目前为size为1
	float vcsel_temp_comp_coeff_1[1];
	float sensor_temp_comp_coeff_1[1];
	float temp_dist_offset_1; 

	//ObToFDistanceCalib dist_calib[0];// ==> 转化为连续内存
	float phase_offset0;  // phase 漂移
    uint32_t wiggling_lut_size0;// wiggling lut 的尺寸
    uint32_t fppn_lut_size0;// fppn lut 尺寸
	int16_t 		wiggling_lut0[5001];
	int16_t 		fppn_lut0[640*480];
	float fppn_offset0;
	uint32_t fppn_slope_lut_size0;
	// int16_t 		fppn_slop_lut0[640 * 480]; //2020-07-24,no fppn_slop
	//ObToFDistanceCalib dist_calib[1];// ==> 转化为连续内存
	float phase_offset1;  // phase 漂移
    uint32_t wiggling_lut_size1;// wiggling lut 的尺寸
    uint32_t fppn_lut_size1;// fppn lut 尺寸
	int16_t 		wiggling_lut1[5001];
	int16_t 		fppn_lut1[640*480];
	float fppn_offset1;
	uint32_t fppn_slope_lut_size1;
	// int16_t 		fppn_slop_lut1[640 * 480]; //2020-07-24,no fppn_slop
/***************************ObToFParam***************************************/

	ObTofFilterConfig		filterCfg;				// 滤波参数
	DepthConfigParam     	depthCfg;				// 深度范围及最小深度单位

	//arm计算出的depth coef
	int 			depth_coff[640 * 480];
	//临时ionbuf给一个地址
	uint32_t					buf;				// 供dsp算法使用的临时ionbuf  len = 64MB
/***************************ObTofFrameInputs***************************************/	
	uint32_t		 	    phase_low_nshl_src;		// 低频non_shuffle相位帧数据
	uint32_t			    phase_low_shl_src;		// 低频shuffle相位帧数据
	uint32_t			    phase_high_nshl_src;	// 高频non_shuffle相位帧数据
	uint32_t			    phase_high_shl_src;		// 高频shuffle相位帧数据
	ObTofTempParams	    	tempParams;				// 相位帧组中温度参数
	uint16_t 				integration_time;

	int 				        multiplex;			 	// 是否开启帧复用， 1 复用， 0 非复用
//-----ObTofInputs end-----

/***************************ObTofOutputs***************************************/
	uint32_t 			amp_low;			// 低频幅值帧数据
	uint32_t 			amp_high;			// 高频幅值帧数据
	uint32_t			depth0;				// 深度帧数据第一帧
	uint32_t			depth1;				// 深度帧数据第二帧
	uint32_t           	ir_0;             	// ir数据第一帧
	uint32_t           	ir_1;             	// ir数据第二帧
	uint32_t			cost_times;			// dsp每计算一个深度耗费的时间，单位是us，初始化为0
	ob_version_t		dsp_version;		// dsp版本号
	int32_t			    status;				// dsp状态信息，初始化为-1，正确输出为0	
//------ObTofOutputs end-----
}CALIB_PARAM_FILE_ST_t;

#pragma pack(pop) //恢复对齐状态

#if 0
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
#else
#define AR_GET_ION_MEMORY(VA, PA, SIZE) \
do{ \
  unsigned int flag = 1; \
  VA = (unsigned char *)ar_ion_malloc_ex(SIZE,flag); \
  if(!VA) \
  { \
    printf("%s %d: Malloc memory failed, exit!\r\n", __FUNCTION__, __LINE__); \
  } \
  PA = (unsigned char *)ar_ion_virt_to_phy(VA); \
  if(!PA) \
  { \
    printf("%s %d: Virt to phy failed, exit!\r\n", __FUNCTION__, __LINE__); \
  } \
}while(0)
#endif

#define AR_RELEASE_ION_MEMORY(VA) ar_ion_free(VA)

/*
	申请-初始化buffer空间
    初始化 ObTofDspParams
    初始化 icc_msg
*/
int init_tof_buffer();
int release_tof_buffer(void);

int all_ion_cache_flush(uint8_t usr_ion_mem_num);
int all_ion_cache_invalid(uint8_t usr_ion_mem_num);

int dsp_D2Cparams_init(ObTofDspParams *ObfDspParams, Depth2Color_pixFormat pixFormat);
int ar_load_file(char *path, char *buf, int size);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif
