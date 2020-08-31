#ifndef __OB_DSP_TEST_H__
#define __OB_DSP_TEST_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include <tof_info.h>
#include "arm_to_dsp_data.h"


#define MAGIC_NUM                       0X349B3A18

#define DSP_WORK_GET_VERSION            0x00000030
#define DSP_WORK_TOF_DEPTH              0x00000031


#define DSP_RESULT_OK                   0x00000000
#define DSP_RESULT_PARAM_CHECK_FAIL     0x00000001
#define DSP_RESULT_ICC_CHECK_FAIL       0x00000002

typedef struct {
	uint32_t shufl_low_buf_pa;
	uint32_t nshufl_low_buf_pa;
	uint32_t shufl_high_buf_pa;
	uint32_t nshufl_high_buf_pa;
}ob_tof_input_buf_pa_t;

typedef struct {
	uint32_t amp_out_buf_pa[2];
	uint32_t ir_out_buf_pa[2];
	uint32_t depth_out_buf_pa[2];
	uint32_t trace_buf_pa;
}ob_tof_output_buf_pa_t;

typedef struct  {
	uint32_t packet_phys_addr;
	uint32_t packet_virt_addr;  //只能arm->dsp单向传递数据，因为dsp如果也以传PA地址方式来传buf，arm是无法知道其va地址的。
	uint32_t packet_bytes;      //packet_phys_addr地址空间对应的有效字节大小    
}packet_t;

typedef struct  {
	 float vcsel_temp;	
	 float sensor_temp;  
}tof_temperature_t;

typedef union  {
	//arm send to dsp
	tof_temperature_t tof_temperature[2];	 

	//dsp send to arm
	ob_version_t	  dsp_version;			
}tof_data_t;

typedef struct  {
	uint32_t        		magic_num;
	uint32_t        		cmd_type;

	ob_tof_input_buf_pa_t   tof_input_buf_pa;
	ob_tof_output_buf_pa_t  tof_output_buf_pa;
    packet_t     			params_packet;        //arm->dsp 单向传递顶层结构体参数
	uint32_t        		dsp_result;	
	uint32_t        		dsp_times;
    uint8_t         		pl_data[10];   		 //arm<->dsp间以传值方式传递少量载荷数据，可双向传递
	tof_data_t				tof_data;
}dsp_work_t;



/*初始化icc,申请ION内存片区*/
int dsp_init_t(void);
/*关闭icc,释放所有申请的ION内存*/
int ob_dsp_deinit(void);
//最终深度计算api，调用一次计算一次，阻塞型api，阻塞时间取决于收到dsp回应msg的时间
int depth_calc_t(void *group, int needAmp, void* amp, int needDepth, void* depth);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif