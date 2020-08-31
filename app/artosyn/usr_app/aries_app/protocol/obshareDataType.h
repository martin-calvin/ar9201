// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2020 Orbbec  Corporation. All Rights Reserved.

#pragma once
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif



/* firmware ack code enum */
typedef enum _ACK_CODE
{
	ACK_OB_SUCCESS                 = 0,
	ACK_OB_INVALID_COMMAND         = 1,
	ACK_OB_DEVICE_NOT_SUPPORT      = 2, 
	ACK_OB_DEVICE_BUSY             = 3,
	ACK_OB_FLASH_AREA_NOT_ACCESS   = 4,
	ACK_OB_ERROR_COMMAND           = 5,
	ACK_OB_UNKNOWN_ERROR           = 0xFFFF
}FIRMWARE_ACK_CODE_EM;


//opcode枚举  OPCODE_GET_FIRMWARE_DATA  
enum EPsProtocolOpCodes {
    OPCODE_GET_VERSION = 0,
    OPCODE_GET_PROPERTY       = 1,
    OPCODE_SET_PROPERTY       = 2,
    OPCODE_GET_FIRMWARE_DATA  = 3,
    OPCODE_SET_FIRMWARE_DATA  = 4,
    OPCODE_READ_FLASH_NEW     = 5,
    OPCODE_ERASE_FLASH        = 6,
    OPCODE_WRITE_FLASH        = 7,
    OPCODE_READ_AHB           = 8,
    OPCODE_WRITE_AHB          = 9,
    OPCODE_READ_I2C           = 10,
    OPCODE_WRITE_I2C          = 11,
    OPCODE_INIT_FILE_UPLOAD = 13,
    OPCODE_WRITE_FILE_UPLOAD = 14,
    OPCODE_FINISH_FILE_UPLOAD = 15,
    OPCODE_DOWNLOAD_FILE = 16,
    OPCODE_READ_FLASH = 25,
};

//设备属性ID枚举
typedef enum {
    OB_DEVICE_PROPERTY_ID_FLASH_WRITE_PROTECTION = 1,                 // FLASH写保护开关；0，关闭；1，开启
    OB_DEVICE_PROPERTY_ID_TEC_ENABLE,                                 // TEC开关
    OB_DEVICE_PROPERTY_ID_LDP,                                        // LDP开关
    OB_DEVICE_PROPERTY_ID_EMITTER,                                    // 激光开光
    OB_DEVICE_PROPERTY_ID_LASER_PULSE_WIDTH,                          // 读写激光Time值（脉宽）,
    OB_DEVICE_PROPERTY_ID_LASER_CURRENT,                              // 激光电流
    OB_DEVICE_PROPERTY_ID_FLOOD,                                      // 泛光灯开关
    OB_DEVICE_PROPERTY_ID_FLOOD_LEVEL,                                // 泛光灯等级
    OB_DEVICE_PROPERTY_ID_TEMPERATURE_COMPENSATION_ENABLE,            // 温度补偿开关
    OB_DEVICE_PROPERTY_ID_TEMPERATURE_CALIBRATED_IR,                  // IR标定温度
    OB_DEVICE_PROPERTY_ID_TEMPERATURE_CALIBRATED_LDMP,                // 激光标定温度
    OB_DEVICE_PROPERTY_ID_TEMPERATURE_COMPENSATION_COEFFICIENT_IR,    // IR温补系数
    OB_DEVICE_PROPERTY_ID_TEMPERATURE_COMPENSATION_COEFFICIENT_LDMP,  // 激光温补系数
    OB_DEVICE_PROPERTY_ID_DEPTH_ALIGN,                                // 深度对齐模式(D2C)
    OB_DEVICE_PROPERTY_ID_DEPTH_MIRROR,                               // 深度镜像
    OB_DEVICE_PROPERTY_ID_DEPTH_FLIP,                                 // 深度翻转
    OB_DEVICE_PROPERTY_ID_DEPTH_POSTFILTER,                           // 深度Postfilter
    OB_DEVICE_PROPERTY_ID_DEPTH_HOLEFILTER,                           // 深度Holefilter
    OB_DEVICE_PROPERTY_ID_IR_MIRROR,                                  // IR 镜像
    OB_DEVICE_PROPERTY_ID_IR_FLIP,                                    // IR 翻转
    OB_DEVICE_PROPERTY_ID_IR_SWITCH,                                  // IR 左右切换

    //TOF设备属性相关
    OB_DEVICE_PROPERTY_ID_TOF_FPS    = 0x10000,                          // tof帧率
    OB_DEVICE_PROPERTY_ID_TOF_MIRROR = 0x10001,                          // tof sensor镜像
    OB_DEVICE_PROPERTY_ID_TOF_EXPOSURE_TIME   = 0x10002,                 // tof 曝光时间
    OB_DEVICE_PROPERTY_ID_TOF_GAIN            = 0x10003,                 // tof 增益
    OB_DEVICE_PROPERTY_ID_TOF_GAUSSIAN_FILTER = 0x10004,                 // tof 高斯噪声滤波器开关
    OB_DEVICE_PROPERTY_ID_TOF_SCATTER_FILTER  = 0x10005,                 // tof 散射滤波器开关
    OB_DEVICE_PROPERTY_ID_TOF_BILATERAL_FILTER  = 0x10006,               // tof 双边波器开关
    OB_DEVICE_PROPERTY_ID_TOF_FLY_POINT_FILTER  = 0x10007,               // tof Fly Point波器开关
    OB_DEVICE_PROPERTY_ID_TOF_MEDIAN_FILTER     = 0x10008,               // tof 中值波器开关
    OB_DEVICE_PROPERTY_ID_TOF_CONFIDENCE_FILTER = 0x10009,               // tof 置信波器开关
    OB_DEVICE_PROPERTY_ID_TOF_SHUFFLE_MODE      = 0x1000A,               // tof Phase Shuffle模式

    //设备其他属性相关
    OB_DEVICE_PROPERTY_ID_ADB_FUNCTION_CONTROL  = 0x20000,               //ADB调试功能开关
    OB_DEVICE_PROPERTY_ID_REBOOT_DEVICE         = 0x20001,               //重启设备
    OB_DEVICE_PROPERTY_ID_FACTORY_RESET         = 0x20002,               //恢复出产设置
    OB_DEVICE_PROPERTY_ID_FORCE_UPGRADE_MODE    = 0x20003,               //获取或设置设备强制升级模式
} OBDevicePropertyID;


//自定义数据枚举
typedef enum {
    OB_DATA_TYPE_VERSIONS = 1,                        // 版本信息
    OB_DATA_TYPE_CAMERA_PARA,                         // 相机内外参数
    OB_DATA_TYPE_BASELINE_CALIBRATION_PARA,           // 基线标定参数
    OB_DATA_TYPE_MULTIPLE_DISTANCE_CALIBRATION_PARA,  // 多距离标定参数
    OB_DATA_TYPE_REFERENCE_IMAGE,                     // 参考图
    OB_DATA_TYPE_HARDWARE_ALIGN_PARA,                 // 硬件对齐参数
    OB_DATA_TYPE_SOFTWARE_ALIGN_PARA,                 // 软件对齐参数
    OB_DATA_TYPE_HARDWARE_DISTORTION_PARA,            // 硬件去畸变参数
    OB_DATA_TYPE_DEPTH_CONFIG_PARA,                   // Config区
    OB_DATA_TYPE_DEVICE_TEMPERATURE,                  // 设备温度信息
    OB_DATA_TYPE_DEVICE_AE_PARAMS,                    // AE调试参数
    OB_DATA_TYPE_DEVICE_UPGRADE_STATUS,               // 读固件升级进度信息
    OB_DATA_TYPE_DEVICE_CALIBRATION_UPGRADE_STATUS,   // 读标定升级进度信息
    OB_DATA_TYPE_DEVICE_FILE_TRAN_STATUS,             // 读取文件传输状态
    OB_DATA_TYPE_DEVICE_ALIGN_UPGRADE_STATUS,         // 读取对齐标定文件的传输状态

    //TOF自定义属性相关
    OB_DATA_TYPE_TOF_TX_RX_TEMP       = 0x10000,         // tof tx rx温度信息
    OB_DATA_TYPE_TOF_MODULATION_FREQ  = 0x10001,         // tof 调制频率
    OB_DATA_TYPE_TOF_DUTY_CYCLE       = 0x10002,         // tof 调制信号占空比
    OB_DATA_TYPE_TOF_CALIBRATION_PARA = 0x10003,         // tof 标定参数
    OB_DATA_TYPE_TOF_DEPTH_COEF_PARA  = 0x10004,         // tof 距离转深度系数
    OB_DATA_TYPE_TOF_VCSEL_TEMP_COMPENSATION = 0x10005,  // tof 温补系数
    OB_DATA_TYPE_TOF_GAUSSIAN_FILTER_PARA    = 0x10006,  // tof 高斯噪声滤波参数
    OB_DATA_TYPE_TOF_SCATTER_FILTER_PARA     = 0x10007,  // tof 散射滤波参数
    OB_DATA_TYPE_TOF_BILATERAL_FILTER_PARA   = 0x10008,  // tof 双边滤波参数    
    OB_DATA_TYPE_TOF_FLY_POINT_FILTER_PARA   = 0x10009,  // tof Fly Point滤波参数
    OB_DATA_TYPE_TOF_MEDIAN_FILTER_PARA      = 0x1000A,  // tof 中值滤波参数
    OB_DATA_TYPE_TOF_CONFIDENCE_FILTER_PARA  = 0x1000B,  // tof 置信滤波参数
    OB_DATA_TYPE_TOF_NEAREST_FARTHEST_LENGTH = 0x1000C,  // tof 最近最远距离
    OB_DATA_TYPE_TOF_EXPOSURE_THRESHOLD_CONTROL = 0x1000D,  // TOF曝光阈值范围


    //其他自定义
    OB_DATA_TYPE_RECORD_RGB_DATA             = 0x20000,  //设备端rgb存图控制(仅用与内部调试)
    OB_DATA_TYPE_RECORD_PHASE_DATA           = 0x20001,  //设备端phase存图控制(仅用与内部调试)
    OB_DATA_TYPE_RECORD_IR_DATA              = 0x20002,  //设备端IR存图控制(仅用与内部调试)
    OB_DATA_TYPE_RECORD_DEPTH_DATA           = 0x20003,  //设备端深度存图控制(仅用与内部调试)

    OB_DATA_TYPE_COUNT,
} OBDataTypeID;




typedef enum {
    OB_DEPTH_EXTENTION_ALIGN_MODE = 1,  // D2C对齐开关；0，关闭；1，默认对齐模式；2，多分辨对齐，RGB分辨率1280x720；3，多分辨对齐，RGB分辨率1920x1080
    OB_DEPTH_EXTENTION_MIRROR,          //深度镜像
    OB_DEPTH_EXTENTION_FLIP,            //深度上下翻转
    OB_DEPTH_EXTENTION_POSTFILTER,      //滤波参数
    OB_DEPTH_EXTENTION_HOLE_FILTER,     //孔洞填充
} OBDepthExtention;

typedef enum {
    OB_IR_EXTENTION_MIRROR = 1,  // IR镜像
    OB_IR_EXTENTION_FLIP,        // IR翻转
    OB_IR_EXTENTION_IR_SWITCH,   //双目IR切换
} OBIRExtention;

typedef struct SDKVersion {
    unsigned char  nMajor;  //  主版本号
    unsigned char  nMinor;  // 次版本号
    unsigned short nBuild;  //修订版本号
} SDKVersion;

typedef struct Versions {
    unsigned char  nMajor;                   // 主版本号
    unsigned char  nMinor;                   // 次版本号
    unsigned short nBuild;                   // 修订版本号
    unsigned int   nChip;                    // 0601 -mx6000
    unsigned short nFPGA;                    // 0701-fgpa    fpga的枚举值
    unsigned char  nSerialNumber[ 12 ];      // 设备序列号
    unsigned short nDeviceType;              // 设备类型的枚举值，单目结构光，双目结构光，双目，tof
    SDKVersion     SDK;                      // 支持sdk的版本号，sdk版本号：2.3.2（主.次.修订)
    unsigned short HWVer;                    // 硬件PCBA的版本号，枚举值。考虑相同产品名称，
    unsigned short nFWVer;                   // 枚举值，描述不同的固件实现类型，uvc或openni的协议
    unsigned char  nChipSerialNumber[ 12 ];  // 芯片的序列号
    unsigned char  nRgbSensor[ 32 ];         // rgb芯片型号
    unsigned char  nIRSensor[ 32 ];          // IR 芯片型号

    unsigned char  nGitVer[64];              // 固件的git版本
    unsigned char  nBuildTime[64];           // 固件的编译时间
} Versions;



typedef struct BaselineCalibrationPara {
    float fZ0;
    float fBaseline;
} BaselineCalibrationPara;

typedef struct MultipleDistanceCalibrationPara {
    uint32_t       nSize;
    unsigned char* data;
} MultipleDistanceCalibrationPara;

typedef struct ReferenceImage {
    uint32_t       nSize;
    unsigned char* data;
} ReferenceImage;

typedef struct HardwareAlignPara {
    uint32_t       nSize;
    unsigned char* data;
} HardwareAlignPara;

typedef struct SoftwareAlignPara {
    uint32_t       nSize;
    unsigned char* data;
} SoftwareAlignPara;

typedef struct HardwareDistortionPara {
    uint32_t       nSize;
    unsigned char* data;
} HardwareDistortionPara;

typedef struct DepthConfigPara {
    uint32_t       nSize;
    unsigned char* data;
} DepthConfigPara;

typedef struct DeviceTemperature {
    float cpuTemp;
    float irTemp;
    float ldmTemp;
    float mainBoardTemp;
    float tecTemp;
    float imuTemp;
} DeviceTemperature;

typedef struct _Range {
    uint32_t min;
    uint32_t max;
} RANGE;

typedef struct AeParams {
    RANGE    expTime;
    RANGE    AGain;
    RANGE    laserCurrent;
    uint32_t targetBrightness;
    uint32_t targetThd;
    uint32_t centerWeight;
    uint32_t skipFrame;
    uint32_t smoothSteps;
    uint32_t dealy_ms;
    uint32_t meterMethod;
    uint8_t  expTimeAdj;
    uint8_t  AGainAdj;
    uint8_t  laserCurrentAdj;
    uint8_t  reserve;
} AeParams;


typedef struct UpgradeStatus {
    int16_t    status;
    int16_t    percentage;
    unsigned char  message[ 256 ];
} UpgradeStatus;

typedef struct PropertyVal {
    uint32_t cur;
    uint32_t max;
    uint32_t min;
    uint32_t def;
    uint32_t step;
}PropertyVal;

typedef struct __attribute__((__packed__)) tof_temp {
    float tx_temp;     //摄氏度
    float rx_temp;
}tof_temp;

typedef struct __attribute__((__packed__)) tof_modulation_freq {
    uint32_t mode;     //1: 表示单频调制，2: 表示双频调制
    uint32_t freq_A;   //第一个调制频率(单频调制只有A频率有效)
    uint32_t freq_B;   //第二个调制频率
    uint32_t reseved;  //保留位
}tof_modulation_freq;

typedef struct __attribute__((__packed__)) tof_duty_cycle_info {
    uint32_t mode;     //1: 表示单频调制，2: 表示双频调制
    float duty_A;      //第一个调制信号占空比， 取值省略百分号，如：54.2
   	float duty_B;      //第二个调制信号占空比
    float reseved;     //保留位
} tof_duty_cycle_info;

typedef struct __attribute__((__packed__)) _ToFTempCompensation {
    float vcsel_temp_comp_coeff;      //vcsel 温度补偿系数
    float sensor_temp_comp_coeff;     //ir 温度补偿系数
    float temp_dist_offset;           //温度引起的零漂
}ToFTempCompensation;

//单频调制只有freq_A信息有效
typedef struct __attribute__((__packed__)) _ObToFTempCompensation {
    uint32_t mode;                    //1: 表示单频调制，2: 表示双频调制
    ToFTempCompensation freq_A;
    ToFTempCompensation freq_B;
}ObToFTempCompensation;

typedef struct __attribute__((__packed__)) _GAUSSIAN_FILTER_PARAM {
    int win_x;                       // filter size
    int win_y;
    float sigma_x;                   // x sigma
    float sigma_y;                   // y sigma
    bool bypass;                     // skip or not； 滤波开关
}GaussianFilterParam;

typedef struct __attribute__((__packed__)) _SCATTER_FILTER_PARAM {
                                     // 待定。。
}ScatterFilterParam;

typedef struct __attribute__((__packed__)) _BILATERAL_FILTER_PARAM {
    int 	d;                       // filter distance
    float 	sigma_color;             // color sigma
    float 	sigma_space;             // space sigma
    bool 	bypass;                  // skip or not； 滤波开关
}BilateralFilterParam;

typedef struct  __attribute__((__packed__)) _FLYPOINT_FILTER_PARAM {
    float 	thres;                   // thres for fly point filtering
    float 	noise_coeff;             // noise coeff;
    bool 	fill_hole;               // fill the hole after fly point filtering
    bool 	bypass;                  //  skip or not， 滤波使能开关
}FlyPointFilterParam;

typedef struct __attribute__((__packed__)) _MEDIAN_FILTER_PARAM {
	int 	win_size;                // window size
	bool 	bypass;                  // skip or not； 滤波开关
}MedianFilterParam;

typedef struct __attribute__((__packed__)) _CONFIDENCE_FILTER_PARAM {
    float 	confidence_thres;
    bool 	bypass;                  // skip or not； 滤波开关
}ConfidenceFilterParam;

typedef struct __attribute__((__packed__)) _DepthLenghtParam {
    uint32_t 	nearest_length;      //最近距离， 单位：mm 
    uint32_t 	farthest_length;     //最远距离， 单位：mm
}DepthLenghtParam;

typedef struct __attribute__((__packed__)) _TofExpThreshold {
    int upper;                               // 阈值上限， 单位：ms
    int lower;                               // 阈值下限， 单位：ms
}TofExpThreshold;


#ifdef __cplusplus
}
#endif

