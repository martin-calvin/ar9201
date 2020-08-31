#ifndef __TOF_ARM_TO_DSP_API_H__
#define __TOF_ARM_TO_DSP_API_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */



#include <stdint.h>
#include "tof_calib_params.h"

// #pragma once
// #pragma pack(push,1)

///////////////存储到memory的参数   begin////////////////

//-------------------标定信息-----------------------//
typedef struct _ObToFTempCompensation_dsp
{
    float vcsel_temp_comp_coeff;  //vcsel 温度补偿系数
    float sensor_temp_comp_coeff;  //ir 温度补偿系数
    float temp_dist_offset;  //温度引起的零漂
}ObToFTempCompensation_dsp;

typedef struct _ObToFDistanceCalib_dsp
{
    float phase_offset;  // phase 漂移
    uint32_t wiggling_lut_size;// wiggling lut 的尺寸
	uint32_t fppn_lut_size;// fppn lut 尺寸
    int16_t *wiggling_lut; // wiggling 查找表内容, 内存由内部释放
    int16_t *fppn_lut;//fppn 查找表内容, 内存由内部释放
}ObToFDistanceCalib_dsp;

typedef struct distortion_calib
{
  float scale;
  int16_t* fppn_slop_lut_low;  //640*480*2
  int16_t* fppn_slop_lut_high;  //640*480*2
  uint32_t *fppn_offset;    //根据内参和fppn_cali_dist计算的表
}distortion_calib_t;
typedef struct ob_tof_calib_param
{
	uint8_t  headerType; 						// Tof param 头文件类型
	uint8_t	 res1;
	uint16_t res2;
	uint16_t freq_mod[2]; 						//调制频率，freq_mod[0]为低频，freq_mod[1]为高频
	ObToFTempCompensation_dsp temp_comp[2]; 		//ToF的温度补偿		ObToFTempCompensation已在tof_arm_api.h中定义
	ObToFDistanceCalib_dsp dist_calib[2];			// ToF的距离补偿	ObToFDistanceCalib已在tof_arm_api.h中定义
	distortion_calib_t dist_slop_calib;
}ObTofCalibParam;

//-------------------相机内参-----------------------//
typedef struct ob_camera_intrin {
	float fx;
	float fy;
	float cx;
	float cy;
}ObCameraIntrin;


//-------------------滤波配置-----------------------//
// 目前只用到了中值滤波、高斯滤波、飞点滤波，且win_size在dsp中固定，不做配置。
typedef struct _OB_TOF_FILTER_CONFIG {
	// ---------------- 中值滤波 ---------------- //
	uint8_t median_bypass;
	// ---------------- 高斯滤波 ---------------- //
	// x sigma
	float gaussian_sigma_x;
	// y sigma
	float gaussian_sigma_y;
	// skip or not
	uint8_t  gaussian_bypass;
	// ---------------- 飞点滤波 ---------------- //
	float 	fly_thres;
	// noise coeff;
	float 	fly_noise_coeff;
	// fill the hole after fly point filtering
	uint8_t 	fly_fill_hole;
	//  skip or not
	uint8_t 	fly_bypass;
}ObTofFilterConfig;


// //-------------------深度范围-----------------------//	已在tof_arm_api.h中定义
 typedef struct _DEPTH_CONFIGURATION_PARAM {
     float 	depth_uint;
     int 	max_depth;
     int	min_depth;
 }DepthConfigParam;


//-----------------温度参数---------------------//
typedef struct ob_tof_temp_params {
	float		vcsel_temp_low;				// 低频vcsel_temp
	float		sensor_temp_low;			// 低频sensor_temp
	float		vcsel_temp_high;			// 高频vcsel_temp
	float		sensor_temp_high;			// 高频sensor_temp
}ObTofTempParams;


//-------------------DSP输入-----------------------//
typedef struct ob_tof_const_inputs {
	int 					width;					// 相位图宽度
	int 					height;					// 相位图高度
	// ObTofCalibParam 		calibParams;			// 标定信息
	// ObCameraIntrin			cameraIntrin;			// 相机内参
	ObToFParam				calibParams;				// 标定内参---from 庆红
	ObTofFilterConfig		filterCfg;				// 滤波参数
	DepthConfigParam     	depthCfg;				// 深度范围及最小深度单位
	int* 					depth_coef;			    // 距离转深度系数 大小是1200KB,640*480*4
	void*					buf;					// 供dsp算法使用的临时ionbuf  len = 64MB
}ObTofConstInputs;

typedef struct ob_tof_frame_inputs {
	  uint16_t*		 	    phase_low_nshl_src;		// 低频non_shuffle相位帧数据
	  uint16_t*			    phase_low_shl_src;		// 低频shuffle相位帧数据
	  uint16_t*			    phase_high_nshl_src;	// 高频non_shuffle相位帧数据
	  uint16_t*			    phase_high_shl_src;		// 高频shuffle相位帧数据
	  ObTofTempParams	    tempParams;				// 相位帧组中温度参数
	  uint16_t 				integration_time;		// 单位us，所有频率积分时间一致.
}ObTofFrameInputs;

typedef struct ob_tof_inputs {
	ObTofConstInputs			constInputs;			// 不变的参数
	ObTofFrameInputs			frameInputs;			// 每帧变化的参数
	int 				        multiplex;			 	// 是否开启帧复用， 1 复用， 0 非复用
}ObTofInputs;

typedef struct ob_version {
    uint8_t major;			//主版本号
    uint8_t minor;			//次版本号
    uint8_t patch_level;	//修订号
    uint8_t build;			//预留
}ob_version_t;

//-------------------DSP输出-----------------------//
typedef struct ob_tof_outputs {
	uint16_t* 			amp_low;			// 低频幅值帧数据
	uint16_t* 			amp_high;			// 高频幅值帧数据
	uint16_t*			depth0;				// 深度帧数据第一帧
	uint16_t*			depth1;				// 深度帧数据第二帧
	uint16_t*           ir_0;             // ir数据第一帧
	uint16_t*           ir_1;             // ir数据第二帧
	uint32_t			cost_times;			// dsp每计算一个深度耗费的时间，单位是us，初始化为0
	ob_version_t		dsp_version;		// dsp版本号
	int32_t			    status;				// dsp状态信息，初始化为-1，正确输出为0
}ObTofOutputs;

//-------------------DSP总体参数-----------------------//
typedef struct ob_tof_dsp_params {
	ObTofInputs			inputs;				// dsp输入
	ObTofOutputs		outputs;			// dsp输出
}ObTofDspParams;

///////////////存储到memory的参数   end////////////////

///////////////通过ICC传递的参数   begin////////////////
typedef enum{
  CONSTPARAMS_SET = 0,
  ALGORITHM_WORK = 1,
  CONFIG_WORK    = 2
}work_type;



typedef	struct  {
	uint32_t type;    // DSP_ALGORITHM_COPY  0x00000001
	uint32_t packet_phys;
	uint32_t packet_virt;
	uint32_t size;
}algorithm_params;

typedef struct  {
  uint32_t type;    // 默认 0x00000001
  uint32_t packet_phys;
  uint32_t packet_virt;
  uint32_t size;
}const_params;

#define MAX_IMAGE 16

typedef struct  {
	uint32_t type;
	uint32_t image_count;
	uint32_t image_phys[MAX_IMAGE];
	uint32_t trace_buffer;
	uint32_t trace_buffer_size;
	uint32_t trace_slot_size;
	uint32_t reserve[8];
}config_params;

typedef	struct  {
	uint32_t id;	
	uint32_t type;   ///ALGORITHM_WORK
	uint32_t result;
	uint32_t rate;
	uint32_t cycles;
	union{
		const_params constpara;
		algorithm_params algorithm;
		config_params config;// 目前未用
	}params;
}work;

///////////////通过ICC传递的参数   end////////////////
// #pragma pack(pop)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif //__TOF_ARM_TO_DSP_API_H__

