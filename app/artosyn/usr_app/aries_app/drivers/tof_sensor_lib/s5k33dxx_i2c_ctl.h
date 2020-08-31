#ifndef __S5K33DXX_I2C_CTL_H__
#define __S5K33DXX_I2C_CTL_H__

#include "obc_tof_i2c.h"
#include <stdbool.h>


struct regList {
    uint16_t reg;
    uint16_t val;
};

// sensor settings type
typedef	enum
{
    SENSOR_LIST_NONE = -1,
	SENSOR_LIST_BURST_MASTER = 0,
	SENSOR_LIST_RV1108,
	SENSOR_LIST_MODE3,
	SENSOR_LIST_MEIZU,
    //---slave mode from 1000 start---
	SENSOR_LIST_BURST_SLAVE = 1000,
    SENSOR_LIST_SLAVE_1TRG1 = 1001,//1frame rgb trigger 1frame tof, sing freq
    SENSOR_LIST_SLAVE_1TRG2 = 1002,//1frame rgb trigger 2frame tof, dual freq
    SENSOR_LIST_SLAVE_1TRG4 = 1004,//1frame rgb trigger 4frame tof, dual freq

}sensor_list_type_t;

// vcsel driver IC type
typedef enum
{
    DRIVER_IC_NONE = -1,
    DRIVER_IC_CXA4016 = 4016,
    DRIVER_IC_PHX3D_3021_AA = 5016,
    DRIVER_IC_PHX3D_3021_CB = 5017,
}laser_driver_type_t;

/* support of laser setting list */
typedef	struct 
{
	laser_driver_type_t laser_type;
	struct regList *laser_settings;
    uint32_t laser_list_size;
}laser_list_t;

/* support of tof-sensor setting list */
typedef	struct 
{
	sensor_list_type_t sensor_type;
	struct regList *sensor_settings;
    uint32_t sensor_list_size;
}sensor_list_t;



typedef enum 
{
    IMAGE_NORMAL = 0,
    IMAGE_H_MIRROR,
    IMAGE_V_MIRROR,
    IMAGE_HV_MIRROR
}img_rotation_t;

typedef enum 
{
    IMAGE_NO_PATTERN = 0,
    IMAGE_GRADIENT_PATTERN,
    IMAGE_SOLID_PATTERN,
}test_pattern_t;

/* 
 open remote i2c 
 return -1 : open failed
 return 0 : open success
 return 1 ：re-opened
*/
int s5k33d_i2c_open(void);

/* 
    close remote i2c 
    return < 0 is err
*/
int s5k33d_i2c_close(void);

/* 
    get remote i2c status
    return <0 :closed
*/
int get_s5k33d_i2c_status(void);

/*
    i2c write 16bit reg_addr, 16bit data
    return < 0 is err
*/
int s5k33d_i2c_write16(uint32_t reg_addr, uint32_t data);

/*
    i2c read 16bit reg_addr, 16bit data
    return < 0 is err
*/
int s5k33d_i2c_read16(uint32_t reg_addr, uint32_t *data);

/* laser driver reg write */
int cxa4016_reg_write(uint16_t reg, uint8_t data);
/* laser driver reg write */
int cxa4016_reg_write2(uint16_t reg, uint8_t data);
/* laser driver reg read */
int cxa4016_reg_read(uint16_t reg, uint8_t *data);


/**
* @brief  sensor_list_setup 选择使用sensor_setting/ laser_setting
* @param  laser_type 激光配置类型
* #define DRIVER_IC_CXA4016              4016
* #define DRIVER_IC_PHX3D_3021_AA        5016
* #define DRIVER_IC_PHX3D_3021_CB        5017
* @param  sensor_type sensor配置类型
* typedef	enum
* {
* 	SENSOR_LIST_BURST_MASTER = 0,
* 	SENSOR_LIST_RV1108,
* 	SENSOR_LIST_MODE3,
* 	SENSOR_LIST_MEIZU,
* 	SENSOR_LIST_BURST_SLAVE,
* }sensor_list_type_t;
* @return int
*/
int sensor_list_setup(uint32_t laser_type, uint32_t sensor_type);

/**
* @brief  s5k33dxx_sensor_init 寄存器初始化
* @return int
*/
int s5k33dxx_sensor_init(void);

/**
* @brief  s5k33dxx_get_sensor_id 获取sensor设备ID
* @param  [out] uint16_t *id
* @return int
*/
int s5k33dxx_get_sensor_id(uint16_t *id);

/**
* @brief  s5k33dxx_video_streaming 开关数据流
* @param  [in] bool enable
* @return int
* [0x0100] is RW/SR ,change cause entering stand-by/soft reset
*/
int s5k33dxx_video_streaming(bool enable);



/**
* @brief  s5k33dxx_set_hts 
* @param  hts line_length_pck
* @return int
*/
int s5k33dxx_set_hts(uint16_t hts);
/**
* @brief  s5k33dxx_set_vts
* @param  vts frame_length_lines
* @return int
*/
int s5k33dxx_set_vts(uint16_t vts);

/**
* @brief  s5k33dxx_get_hts 
* @param  hts line_length_pck
* @return int
*/
int s5k33dxx_get_hts(uint16_t hts);
/**
* @brief  s5k33dxx_get_vts
* @param  vts frame_length_lines
* @return int
*/
int s5k33dxx_get_vts(uint16_t vts);


/**
* @brief  s5k33dxx_set_fps 帧率设置
* @param  [in] uint8_t fps
* @return int
*/
int s5k33dxx_set_fps(uint8_t fps);

/**
* @brief  s5k33dxx_get_fps 获取当前帧率
* @param  [out] uint8_t* fps
* @return int
*/
int s5k33dxx_get_fps(uint8_t* fps);

int s5k33dxx_set_data_output_mode(uint8_t mode);
int s5k33dxx_get_data_output_mode(uint8_t *mode);

int s5k33dxx_set_illum_duty_cycle(uint8_t duty);
int s5k33dxx_get_illum_duty_cycle(uint8_t *duty);
int s5k33dxx_set_illum_power(uint8_t value_A, uint8_t value_B);
int s5k33dxx_get_illum_power(uint8_t *value_A, uint8_t *value_B);

/**
* @brief  s5k33dxx_illum_power_control 控制激光开关，目前只能通过配置laser供电或者s5k33dxx_set_illum_power(0)实现
* @param  enable
* @return int
*/
int s5k33dxx_illum_power_control(bool enable);


/**
* @brief  s5k33dxx_set_integration_threshold 设置积分时间调整区间
* @param  max 积分时间上限us
* @param  min 积分时间下限us
* @return <0 failed
*/
int s5k33dxx_set_integration_threshold(uint16_t max, uint16_t min);

/**
* @brief  s5k33dxx_set_integration_threshold 获取积分时间调整区间
* @param  max 积分时间上限us
* @param  min 积分时间下限us
* @return <0 failed
*/
int s5k33dxx_get_integration_threshold(uint16_t *max, uint16_t *min);

/**
* @brief  s5k33dxx_set_integration_time 积分时间设置
* @param  [in] uint16_t integrationTime (us)
* @return int
*/
int s5k33dxx_set_integration_time(uint16_t integrationTime);

/**
* @brief  s5k33dxx_get_integration_time 获取当前积分时间
* @param  [out] uint16_t *integrationTime (us)
* @return int
*/
int s5k33dxx_get_integration_time(uint16_t *integrationTime);


/**
* @brief  s5k33dxx_get_modulation_frequency 获取调制频率(双频)
* @param modFreq freq0=modFreq>>8, freq1=modFreq&0xff
* @return int
*/
int s5k33dxx_get_modulation_frequency(uint16_t *modFreq);


/**
* @brief  s5k33dxx_get_modulation_frequency 设置调制频率(双频)
* @param modFreq *modFreq = ((freq_0 << 8) | freq_1)
* @return int
*/
int s5k33dxx_set_modulation_frequency(uint16_t modFreq);

/**
* @brief  s5k33dxx_set_img_mirror_flip 设置sensor镜像
* @param  [in] uint8_t mode
* @code 
* typedef enum 
* {
*     IMAGE_NORMAL = 0,
*     IMAGE_H_MIRROR,
*     IMAGE_V_MIRROR,
*     IMAGE_HV_MIRROR
* }img_rotation_t;
* @code 
* @return int
*/
int s5k33dxx_set_img_mirror_flip(img_rotation_t mode);

/**
* @brief  s5k33dxx_get_img_mirror_flip 获取当前镜像状态
* @param  [out] uint8_t* mode
* @return int
*/
int s5k33dxx_get_img_mirror_flip(img_rotation_t* mode);

/**
* @brief  s5k33dxx_test_pattern test pattern设置
* @param  [in] uint8_t mode
* @code
* typedef enum 
* {
*     IMAGE_NO_PATTERN = 0,
*     IMAGE_GRADIENT_PATTERN,
*     IMAGE_SOLID_PATTERN,
* }test_pattern_t; 
* @code
* @return int
*/
int s5k33dxx_test_pattern(test_pattern_t mode);

// 2x2 binning, resolution changed from 1280*960 to 640*480
int s5k33d_set_pixel_binning(uint8_t mode);
int s5k33d_get_pixel_binning(uint8_t *mode);

/**
* @brief  s5k33dxx_AE 自动AE开关
* @param  [in] bool enable
* @return int
*/
int s5k33dxx_AE(bool enable);

/**
* @brief  s5k33dxx_get_rx_temp 获取sensor温度
* @param  temperature
* @return int
*/
int s5k33dxx_get_rx_temp(float *temperature);

/**
* @brief  s5k33dxx_get_tx_temp 获取laser温度
* @param  temperature
* @return int
*/
int s5k33dxx_get_tx_temp(float *temperature);

#endif