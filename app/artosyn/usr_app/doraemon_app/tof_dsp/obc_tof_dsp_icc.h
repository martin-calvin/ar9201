#ifndef __OBC_TOF_DSP_ICC_H__
#define __OBC_TOF_DSP_ICC_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include <tof_info.h>
#include "arm_to_dsp_data.h"
#include "tof_dsp_memory_map.h"

#define ARM_DSP_DBG_INFO        	(0)//打印调试信息
#define DEPTH_CALC_FROM_PICTURES	(0)//通过图片计算深度

typedef struct
{
	uint32_t va;
	uint32_t pa;
}comm_addr_t;

//给到dsp的数据地址
typedef	struct
{
	comm_addr_t phase_low_nshl;
	comm_addr_t phase_low_shl;
	comm_addr_t phase_high_nshl;
	comm_addr_t phase_high_shl;
}imgSendDsp_t;

//-----------------命令参数结构---------------------//
// 以下枚举成员是ob_dsp_msg_t中可能的cmd值
typedef enum ob_dsp_cmd_type{
    OB_DSP_LOAD_REF,	         //加载TOF标定文件，data类型为char*
	OB_DSP_GET_PARAMS,           //获取相机内参，data类型为ob_camera_params*
    OB_DSP_GET_FILTER_CONFIG,    //获取滤波相关配置，data类型为ObToFConfig *
    OB_DSP_SET_FILTER_CONFIG,    //设置滤波相关配置，data类型为ObToFConfig *
	OB_DSP_ENABLE_MULTIPLEX, 	 //设置是否开启帧复用， data 类型为 int*， 1 复用， 0 非复用
}ob_dsp_cmd_type_t;

typedef struct ob_dsp_msg{
	int 	cmd;		// command id,  ob_dsp_cmd_type_t
	int 	data_size;	//成员data的长度，单位字节
	void* 	data;		//对应cmd类型携带的数据
}ob_dsp_msg_t;

typedef struct _D2C_Process_Parame
{
	uint8_t *buf;
	uint32_t image_width;
	uint32_t image_height;
}D2C_Process_Parame;


int ar9201_icc_init();
int ar9201_icc_deinit();
int ar9201_icc_register_msgid(int core_id);
int ar9201_icc_snd_msg(int core_id,void *msg_ptr,int msg_len);
int ar9201_icc_rev_msg(int core_id,void *msg_ptr,int msg_len);

// 获取arm版本号
int ob_arm_version(ob_version_t* version);

// 获取dsp版本号
int ob_dsp_version(ob_version_t* version);

/**
 * @brief  ob_dsp_init 初始化icc通信并申请ION内存
 * @param  void
 * @return 0 success !0 failed
 * @note null
 */
int ob_dsp_init(Depth2Color_pixFormat pixFormat, bool d2c_enable, softfilterParam softfilter_Param);

/**
 * @brief  ob_dsp_deinit 注销icc通信并释放所有申请ION内存
 * @param  void
 * @return 0 success !0 failed
 * @note null
 */
int ob_dsp_deinit(void);

/**
 * @brief  ob_dsp_sendcmd 应用发送命令给dsp
 * @param  msg  应用端发送msg和dsp进行通信
 * @return 0 success !0 failed
 * @note null
 */
int ob_dsp_sendcmd(ob_dsp_msg_t* msg);

/**
 * @brief  close the camera which open_cam
 * @param  group raw_phase group 
 * @param  needAmp if need dsp calc Amp
 * @param  amp out amp img VA addr
 * @param  needDepth if need dsp calc Depth
 * @param  depth out dep img VA addr
 * @return 0 success !0 failed
 * @note null
 */
int ob_depth_calc(void *group, int needAmp, void* amp, int needDepth, void* depth);

/**
 * @brief  DSP data process function
 * @param  param_ion_mellc_t inputBuf 
 * @param  uint32_t inputBuf_weith
 * @param  uint32_t inputBuf_height
 * @param  param_ion_mellc_t *outputBuf
 * @param  uint32_t outputBuf_weith
 * @param  uint32_t outputBuf_height
 * @return 0 success !0 failed
 * @note null
 */
int ob_dsp_data_process(param_ion_mellc_t *inputBuf, uint32_t inputBuf_weith, uint32_t inputBuf_height,
                       param_ion_mellc_t *outputBuf, uint32_t outputBuf_weith, uint32_t outputBuf_height);

/**
 * @brief  dsp load paramters
 * @param  Depth2Color_pixFormat pixFormat
 * @param  bool d2c_enable
 * @param  softfilterParam softfilter_param
 * @return 0 success !0 failed
 * @note null
 */
int ob_dsp_loadParam(Depth2Color_pixFormat pixFormat, bool d2c_enable, softfilterParam softfilter_param);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif