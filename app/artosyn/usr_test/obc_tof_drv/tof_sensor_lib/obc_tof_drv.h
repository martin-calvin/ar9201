/*****************************************************************************
Copyright: 2020, orbbec. Co., Ltd.
File name: obc_tof_drv.h
Description: define orbbec tof camera driver
Author: houfeifei@orbbec.com
Version: v1.0
Date:2020-06-01
History:2018-05-22 : first release sdk
*****************************************************************************/
#ifndef __OBC_TOF_DRV__
#define __OBC_TOF_DRV__
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "ar_system.h"
#include "ar_meta_define.h"
#include "ar_multimedia_base.h"
#include "icc_proxy_rpc_to_linux.h"
#include "ar_log.h"
#include "ar_pipeline_ctrl.h"
#include "ar_fifo.h"
#include "ar_picture_common_api.h"
#include "ar_video_stream.h"
#include <sys/time.h>
#include <stdint.h>
#include <sys/mman.h>
#include "backtrace.h"
#include "libremote_i2c.h"
#include "s5k33dxx_i2c_ctl.h"
#include "obc_tof_i2c.h"
#include "ar_cam_src.h"



//---------------------------------数据帧及帧组定义------------------------------------//
#if 0
/* EBD解析地址 */
typedef	enum
{
	ebd_frame_length_lines = 362, //2bytes
	ebd_line_length_pck = 366, //2bytes
	ebd_rd_sensor_temperature = 28, //2bytes
	ebd_rd_laser_temperature = 190, //2bytes
	ebd_frame_count = 16, //1byte
	ebd_output_format = 180, //1byte
	ebd_phase_map = 182, //1byte
	ebd_frequency_modulation_index = 184,//1byte
}ebd_info_t;

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
//---------------------------------数据帧及帧组定义------------------------------------//
#endif


//-----------------------------9201-RTOS-camera框架控制-------------------------------//

#define RAW_DATA_PATH  "/mnt/data.raw"
#define AR_IPCAM_CAM_SRC_STREAM_NUMBER           2  // Pipeline only use scaler 0/1 in current pipeline
#define MAX_MEM_FIFO   4096
typedef struct {
    ar_facotry_element_obj_t pipeline;
    ar_facotry_element_obj_t cam_src;
    ar_facotry_element_obj_t buf_sink_0;
    
} cam_raw_context_t;

typedef struct
{
    char        *buf_mem;
    uint32_t    buf_len;  
}cam_buffer_t;

typedef struct
{
    int fd;
    int buf_sink_fd;
    pthread_t  thread_id;
    pthread_t  thread_process_id;
    pthread_cond_t   buf_signal;
    ar_queue_t      *buf_que;
    uint32_t         buf_len;
    pthread_mutex_t  mutex;
    int     frame_count;
}cam_raw_config_t;

typedef enum {START = 1, STOP = !START,}dev_ppl_status_t;

typedef struct
{
    uint32_t width;
    uint32_t height; 
}vidio_res_t;

/* 用户配置cam_src pipeline 参数 */
typedef struct
{
    int cam_id;                     /* cam_id in dts*/
    vidio_res_t input_vidio_res;    /* input vidio width and height */
    int subsample_rate;             /* rtos vip subsample_rate <0-15> */
    int fps;                        /* vidio fps */
}usr_cfg_ppl_t;

/* <global>记录当前驱动状态 */
typedef struct
{
    dev_ppl_status_t tof_ppl_status;        /* pipline can only init once */
    int tof_cam_id;                     /* cam_id in driver,default use 0 */
    int tof_cam_fd;                     /* cam_fd */
    usr_cfg_ppl_t  cam_pipeline_cfg;    /* 用户配置cam_src pipeline 参数 */
}cam_handle_t;

typedef cam_handle_t* obc_cam_handle_t;



/*
    获取驱动配置参数结构默认值，init以及open时可以根据需要修改
*/
obc_cam_handle_t get_ob_cam_handle(void);

/**
 * @brief  init camera driver and rtos pipeline setup
 * @param usr_cfg_ppl  the driver info need to set
 * @code
 * typedef struct
 * {
 *     int cam_id;                     // cam_id in dts, default @param 0
 *     vidio_res_t input_vidio_res;    // input vidio width and height, default @param 1280x962
 *     int subsample_rate;             // rtos vip subsample_rate <0-15>, default @param 15
 *     int fps;                        // vidio fps,default @param 30 
 * }usr_cfg_ppl_t;
 * @endcode
 * @return   <0 err
 * @note  no
 */
int init_tof_cam(obc_cam_handle_t p_handle);

/**
 * @brief  open the camera to set ctl
 * @param  cam_id  the number of camera device node, such as /dev/cam_src-0, default  @param 0
 * @return a fd of the camera device >=0 success, <0 err
 * @note null
 */ 
int open_tof_cam(int cam_id);

/**
 * @brief  close the camera which open_cam
 * @param  fd the fd of  open_cam
 * @return 0 success !0 failed
 * @note null
 */
int close_tof_cam(int fd);


/**
 * @brief  tof_cam_stream_on
 * @param  none 
 * @return 0 success !0 failed
 * @note null
 */
int tof_cam_stream_on(void);


/**
 * @brief  tof_cam_stream_off
 * @param  none
 * @return 0 success !0 failed
 * @note null
 */
int tof_cam_stream_off(void);


//-----------------------------9201-RTOS-camera框架控制-------------------------------//



// ---------------tof sensor API控制及 sensor相关全局变量 ----------------------------// 
typedef struct
{
    int (*init)(void);
    int (*get_sensor_id)(uint16_t *id);
    int (*video_streaming)(bool enable);
    int (*set_fps)(uint8_t fps);
    int (*get_fps)(uint8_t *fps);
    int (*set_illum_power)(uint8_t value_A, uint8_t value_B);
    int (*get_illum_power)(uint8_t *value_A, uint8_t *value_B);
    int (*illum_power_control)(bool enable);
    int (*set_integration_time)(uint16_t time);
    int (*get_integration_time)(uint16_t *time);
    int (*set_modulation_frequency)(uint16_t modFreq);
    int (*get_modulation_frequency)(uint16_t *modFreq);
    int (*set_illum_duty_cycle)(uint8_t duty);
    int (*get_illum_duty_cycle)(uint8_t *duty);
    int (*set_data_output_mode)(uint8_t mode);
    int (*get_data_output_mode)(uint8_t *mode);
    int (*set_img_mirror_flip)(img_rotation_t mode);
    int (*get_img_mirror_flip)(img_rotation_t *mode);
    int (*set_pixel_binning)(uint8_t mode);
    int (*get_pixel_binning)(uint8_t *mode);
    int (*test_pattern)(test_pattern_t mode);
    int (*set_AE_enable)(bool enable);
    int (*get_rx_temp)(float *temperature);
    int (*get_tx_temp)(float *temperature);
    int (*sel_setting)(uint32_t laser_list, uint32_t sensor_list);
    int (*set_exp_threshold)(uint16_t max, uint16_t min);
    int (*get_exp_threshold)(uint16_t *max, uint16_t *min);
    int (*set_hts)(uint16_t val);
    int (*get_hts)(uint16_t *val);
    int (*set_vts)(uint16_t val);
    int (*get_vts)(uint16_t *val);
    int (*i2c_open)(void);
    int (*i2c_close)(void);
    int (*sensor_i2c_read)(uint16_t reg, uint16_t *val);
    int (*sensor_i2c_write)(uint16_t reg, uint16_t val);
    int (*laser_i2c_read)(uint16_t reg, uint16_t *val);
    int (*laser_i2c_write)(uint16_t reg, uint16_t val);

    bool streaming_en;
    uint16_t sensor_id;
    uint8_t microFrameFps;
    uint8_t PowerTapA;
    uint8_t PowerTapB;
    uint16_t integration_time;
    uint8_t modulation_frequency;
    uint8_t illum_duty_cycle;
    uint8_t data_output_mode;
    uint8_t img_mirror_flip;
    uint8_t test_pattern_mode;
    uint8_t fps;
    uint8_t binning_en;
    //ObTofFrame tof_frame_info;
} tof_cam_ctrl_t;
extern volatile tof_cam_ctrl_t tof_sensor;
// ---------------tof sensor API控制及 sensor相关全局变量 ----------------------------// 


#ifdef __cplusplus
}
#endif
#endif // __IPCAM__
