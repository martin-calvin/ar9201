// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2020 Orbbec  Corporation. All Rights Reserved.

/** \file ObTypes.h
 * \brief
 * libobsensor的纯C的API，提供API 结构体、枚举常量定义文件
 */

#pragma once

#if (defined(WIN32) || defined(_WIN32) || defined(WINCE))
#  ifdef OB_EXPORTS
#    define OB_EXTENSION_API __declspec(dllexport)
#  else
#    define OB_EXTENSION_API __declspec(dllimport)
#  endif
#else
#  define OB_EXTENSION_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

//=====================================================================Context==============================================================

/** \brief
OBVersion 是libobsensor的版本号的描述结构体,例如格式: 0.1.0.
*/
typedef struct {
    /** Major version number, incremented for major API restructuring. */
    int major;
    /** Minor version number, incremented when significant new features added. */
    int minor;
    /** Patch build number, incremented for new releases that primarily provide minor bug fixes. */
    int patch;
} OBVersion;

/** \brief
 *OBStatus是描述统一的接口返回错误码的枚举值
 */
typedef enum {
    OB_STATUS_OK                           = 0,
    OB_STATUS_ERROR                        = 1,
    OB_STATUS_NOT_IMPLEMENTED              = 2,
    OB_STATUS_NOT_SUPPORTED                = 3,
    OB_STATUS_BAD_PARAMETER                = 4,
    OB_STATUS_OUT_OF_FLOW                  = 5,
    OB_STATUS_NO_DEVICE                    = 6,
    OB_STATUS_NOT_WRITE_PUBLIC_KEY         = 7,
    OB_STATUS_PUBLIC_KEY_MD5_VERIFY_FAILED = 8,
    OB_STATUS_NOT_WRITE_MD5                = 9,
    OB_STATUS_RSKEY_VERIFY_FAILED          = 10,
    OB_STATUS_NOT_ALIGN                    = 11,
    OB_STATUS_CONTEXT_NOT_INIT             = 12,
    OB_STATUS_TIME_OUT                     = 102,
    OB_STATUS_DEVICE_NOT_FOUND             = 200,
    OB_STATUS_SENSOR_NOT_FOUND             = 300,
} OBStatus;

/** \brief
 描述SDK的日志的等级的枚举值
*/
typedef enum OBLogSeverity {
    OB_LOG_SEVERITY_DEBUG, /**< Detailed information about ordinary operations */
    OB_LOG_SEVERITY_INFO,  /**< Terse information about ordinary operations */
    OB_LOG_SEVERITY_WARN,  /**< Indication of possible failure */
    OB_LOG_SEVERITY_ERROR, /**< Indication of definite failure */
    OB_LOG_SEVERITY_FATAL, /**< Indication of unrecoverable failure */
    OB_LOG_SEVERITY_NONE,  /**< No logging will occur */
    OB_LOG_SEVERITY_COUNT  /**< Number of enumeration values. Not a valid input:
                              intended to be used in for-loops. */
} OBLogSeverity;
typedef enum OBLogOutType {
    OB_LOG_OUT_FILE, /**<log output to files */
    OB_LOG_OUT_TERMINAL,  /**< log output to terminal */
} OBLogOutType;
struct OBContextImpl;
typedef struct OBContextImpl* OBContextHandle;

struct OBDeviceImpl;
typedef struct OBDeviceImpl* OBDeviceHandle;

typedef struct OBDeviceInfoImpl OBDeviceInfoImpl;



/** \brief
  OBDeviceDescription 描述设备枚举阶段的设备的描述
 */
typedef struct {
    char              deviceName[ 128 ];
    char              deviceUid[ 32 ];     //连接到系统中设备的唯一ID
    OBDeviceInfoImpl* devInfoImpl;         // 绑定内部的设备描述
} OBDeviceDescription;


/** \brief
  OBDeviceInfo 是对外暴露的设备的信息
 */
typedef struct {
    char              deviceName[ 128 ];
    int               devicePid;
    int               deviceVid;
    char              deviceUid[ 32 ];     //连接到系统中设备的唯一ID
    char              serialNumber[ 32 ];  //设备的序列号
    int               firmwareVersion;     // 5.2.30->5*10000+2*100+30
    char              asicNumber[ 32 ];    //芯片的序列号
    char              asicName[ 32 ];      // mx6000
} OBDeviceInfo;

typedef struct {
    char data[ 12 ];
} SerialNumber;

typedef void ( *OBDeviceInfoCallback )( const OBDeviceDescription* pInfo, void* pCookie );
typedef void ( *OBDeviceUpgradeProcess )( const int process );

typedef struct {
    OBDeviceInfoCallback deviceConnected;
    OBDeviceInfoCallback deviceDisconnected;
} OBDeviceCallbacks;

typedef enum ExceptionType {
    OB_EXCEPTION_TYPE_UNKNOWN,
    OB_EXCEPTION_TYPE_CAMERA_DISCONNECTED,     /**< Device was disconnected, this can
                                                  be caused by outside intervention,
                                                  by internal firmware error or due to
                                                  insufficient power */
    OB_EXCEPTION_TYPE_BACKEND,                 /**< Error was returned from the underlying
                                                  OS-specific layer */
    OB_EXCEPTION_TYPE_INVALID_VALUE,           /**< Invalid value was passed to the API */
    OB_EXCEPTION_TYPE_WRONG_API_CALL_SEQUENCE, /**< Function precondition was
                                                  violated */
    OB_EXCEPTION_TYPE_NOT_IMPLEMENTED,         /**< The method is not implemented at this
                                                  point */
    OB_EXCEPTION_TYPE_DEVICE_IN_RECOVERY_MODE, /**< Device is in recovery mode and
                                                  might require firmware update */
    OB_EXCEPTION_TYPE_IO,                      /**< IO Device failure */
    OB_EXCEPTION_TYPE_MEMORY,                  /**</allocating memory failed, or null pointer  variables */
    OB_EXCEPTION_TYPE_UNSUPPORTED_OPERATION,   /** the operation is unsupported by this device */
    OB_EXCEPTION_TYPE_COUNT                    /**< Number of enumeration values. Not a valid input:
                                                  intended to be used in for-loops. */
} ObExceptionType;

//===========================================================================Device &  Sensor Type============================================

/** \brief
  描述设备的属性的枚举值
*/
typedef enum {
    OB_DEVICE_PROPERTY_VERSIONS               = 0,
    OB_DEVICE_PROPERTY_FLASH_WRITE_PROTECTION = 1,                 // FLASH写保护开关；0，关闭；1，开启
    OB_DEVICE_PROPERTY_TEC_ENABLE,                                 // TEC开关
    OB_DEVICE_PROPERTY_LDP,                                        // LDP开关
    OB_DEVICE_PROPERTY_EMITTER,                                    // 激光开关
    OB_DEVICE_PROPERTY_LASER_PULSE_WIDTH,                          // 读写激光Time值（脉宽）,
    OB_DEVICE_PROPERTY_LASER_CURRENT,                              // 激光电流
    OB_DEVICE_PROPERTY_FLOOD,                                      // 泛光灯开关
    OB_DEVICE_PROPERTY_FLOOD_LEVEL,                                // 泛光灯等级
    OB_DEVICE_PROPERTY_TEMPERATURE_COMPENSATION_ENABLE,            // 温度补偿开关
    OB_DEVICE_PROPERTY_TEMPERATURE_CALIBRATED_IR,                  // IR标定温度
    OB_DEVICE_PROPERTY_TEMPERATURE_CALIBRATED_LDMP,                // 激光标定温度
    OB_DEVICE_PROPERTY_TEMPERATURE_COMPENSATION_COEFFICIENT_IR,    // IR温补系数
    OB_DEVICE_PROPERTY_TEMPERATURE_COMPENSATION_COEFFICIENT_LDMP,  // 激光温补系数
    OB_DEVICE_PROPERTY_DEPTH_ALIGN,                                // 深度对齐模式
    OB_DEVICE_PROPERTY_DEPTH_MIRROR,                               // 深度镜像
    OB_DEVICE_PROPERTY_DEPTH_FLIP,                                 // 深度翻转
    OB_DEVICE_PROPERTY_DEPTH_POSTFILTER,                           // 深度Postfilter
    OB_DEVICE_PROPERTY_DEPTH_HOLEFILTER,                           // 深度Holefilter
    OB_DEVICE_PROPERTY_IR_MIRROR,                                  // IR 镜像
    OB_DEVICE_PROPERTY_IR_FLIP,                                    // IR 翻转
    OB_DEVICE_PROPERTY_IR_SWITCH,                                  // IR 左右切换

    OB_DEVICE_PROPERTY_VERSIONS_NEW,                        // 版本信息
    OB_DEVICE_PROPERTY_CAMERA_PARA,                         // 相机内外参数
    OB_DEVICE_PROPERTY_BASELINE_CALIBRATION_PARA,           // 基线标定参数
    OB_DEVICE_PROPERTY_MULTIPLE_DISTANCE_CALIBRATION_PARA,  // 多距离标定参数
    OB_DEVICE_PROPERTY_REFERENCE_IMAGE,                     // 参考图
    OB_DEVICE_PROPERTY_HARDWARE_ALIGN_PARA,                 // 硬件对齐参数
    OB_DEVICE_PROPERTY_SOFTWARE_ALIGN_PARA,                 // 软件对齐参数
    OB_DEVICE_PROPERTY_HARDWARE_DISTORTION_PARA,            // 硬件去畸变参数
    OB_DEVICE_PROPERTY_DEPTH_CONFIG_PARA,                   // Config区
    OB_DEVICE_PROPERTY_DEVICE_TEMPERATURE,                  // 设备温度信息
    OB_DEVICE_PROPERTY_DEVICE_AE_PARAMS,                    // AE调试参数
    OB_DEVICE_PROPERTY_HARDWARE_SYNC,                       // 设备是否支持硬件同步设计
    OB_DEVICE_PROPERTY_SERIAL_NUMBER,                       // 序列号

    /****************************以下均为TOF相关属性***************************/
    OB_DEVICE_PROPERTY_TOF_FPS,                //TOF帧率
    OB_DEVICE_PROPERTY_TOF_EXPOSURE_TIME,      //TOF曝光时间
    OB_DEVICE_PROPERTY_TOF_GAIN,               //TOF增益
    OB_DEVICE_PROPERTY_TOF_MIRROR,             //TOF镜像开光
    OB_DEVICE_PROPERTY_TOF_GAUSSIAN_FILTER,    //噪声滤波开关
    OB_DEVICE_PROPERTY_TOF_SCATTER_FILTER,     //散射滤波开关
    OB_DEVICE_PROPERTY_TOF_BILATERAL_FILTER,   //双边滤波开关
    OB_DEVICE_PROPERTY_TOF_FLY_POINT_FILTER,   //点云滤波开关
    OB_DEVICE_PROPERTY_TOF_MEDIAN_FILTER,      //中值滤波开关
    OB_DEVICE_PROPERTY_TOF_CONFIDENCE_FILTER,  //置信滤波开关
    OB_DEVICE_PROPERTY_TOF_SHUFFLE_MODE,       //TOF Phase Shuffle模式

    OB_DEVICE_PROPERTY_TOF_TX_RX_TEMP,              //TOF tx rx温度
    OB_DEVICE_PROPERTY_TOF_MODULATION_FREQ,         //TOF调制频率信息
    OB_DEVICE_PROPERTY_TOF_DUTY_CYCLE,              //TOF调制信号占空比信息
    OB_DEVICE_PROPERTY_TOF_CALIBRATION_PARA,        //TOF标定参数
    OB_DEVICE_PROPERTY_TOF_DEPTH_COEF_PARA,         //TOF距离转深度系数
    OB_DEVICE_PROPERTY_TOF_VCSEL_TEMP_COMPENSATION, //TOF温补系数
    OB_DEVICE_PROPERTY_TOF_GAUSSIAN_FILTER_PARA,    //TOF高斯噪声滤波参数
    OB_DEVICE_PROPERTY_TOF_SCATTER_FILTER_PARA,     //TOF散射滤波参数
    OB_DEVICE_PROPERTY_TOF_BILATERAL_FILTER_PARA,   //TOF双边滤波参数
    OB_DEVICE_PROPERTY_TOF_FLY_POINT_FILTER_PARA,   //TOF点云滤波参数
    OB_DEVICE_PROPERTY_TOF_MEDIAN_FILTER_PARA,      //TOF中值滤波参数
    OB_DEVICE_PROPERTY_TOF_CONFIDENCE_FILTER_PARA,  //TOF置信滤波参数
    OB_DEVICE_PROPERTY_TOF_NEAREST_FARTHEST_LENGTH, //TOF最近与最远距

    OB_DEVICE_PROPERTY_COUNT,

} OBDeviceProperty;

typedef enum {
    // OB_SENSOR_PROPERTY_WRITE_AHB,
    // OB_SENSOR_PROPERTY_DEPTH_MIRROR,
    OB_SENSOR_PROPERTY_ENABLE_AUTO_EXPOSURE,
    OB_SENSOR_PROPERTY_EXPOSURE,
    OB_SENSOR_PROPERTY_GAIN,
    OB_SENSOR_PROPERTY_ENABLE_AUTO_WHITE_BALANCE,
    OB_SENSOR_PROPERTY_WHITE_BALANCE,
    OB_SENSOR_PROPERTY_BRIGHTNESS,
    OB_SENSOR_PROPERTY_SHARPNESS,
    OB_SENSOR_PROPERTY_COLOR_TEMPERATURE,
    OB_SENSOR_PROPERTY_SATURATION,
    OB_SENSOR_PROPERTY_CONTRAST,
    OB_SENSOR_PROPERTY_GAMMA,
    OB_SENSOR_PROPERTY_AUTO_EXPOSURE_PRIORITY,
    OB_SENSOR_PROPERTY_BACKLIGHT_COMPENSATION,
    OB_SENSOR_PROPERTY_HUE,
    OB_SENSOR_PROPERTY_POWER_LINE_FREQUENCY,
    OB_SENSOR_PROPERTY_MIRROR,
    OB_SENSOR_PROPERTY_FLIP,
    OB_SENSOR_PROPERTY_ID,

} OBSensorProperty;

struct OBSensorImpl;

typedef struct OBSensorImpl* OBSensorHandle;
typedef struct OBResult      OBResult;
/** \brief
  描述传感器类型的枚举值
*/
typedef enum {
    OB_SENSOR_UNKNOWN = 0,
    OB_SENSOR_IR      = 1,
    OB_SENSOR_COLOR   = 2,
    OB_SENSOR_DEPTH   = 3,
    OB_SENSOR_IMU     = 4,

} OBSensorType;

/** \brief
 描述属性范围的结构体
*/
typedef struct {
    int min;
    int max;
    int step;
    int def;
} OBPropertyRange;

typedef double obTime; /**< Timestamp format. units are milliseconds */

//====================================================================================Stream & Frame  type =============================================

/** \brief
  描述数据流类型的枚举值
*/
typedef enum {
    OB_STREAM_IR    = 1,
    OB_STREAM_COLOR = 2,
    OB_STREAM_DEPTH = 3,
    OB_STREAM_IMU   = 4,

} OBStreamType;

/** \brief
  描述Frame类型枚举值
*/
typedef enum {
    OB_FRAME_IR    = 1,
    OB_FRAME_COLOR = 2,
    OB_FRAME_DEPTH = 3,
    OB_FRAME_IMU   = 4,

} OBFrameType;

/** \brief
  描述数据帧的像素格式
*/
typedef enum {
    // Depth
    OB_PIXEL_FORMAT_DEPTH_1_MM   = 100,
    OB_PIXEL_FORMAT_DEPTH_100_UM = 101,
    OB_PIXEL_FORMAT_SHIFT_9_2    = 102,
    OB_PIXEL_FORMAT_SHIFT_9_3    = 103,
    OB_PIXEL_FORMAT_Z16          = 104,

    // Color
    OB_PIXEL_FORMAT_RGB888 = 200,
    OB_PIXEL_FORMAT_YUV422 = 201,
    OB_PIXEL_FORMAT_GRAY8  = 202,
    OB_PIXEL_FORMAT_GRAY16 = 203,
    OB_PIXEL_FORMAT_JPEG   = 204,
    OB_PIXEL_FORMAT_YUYV   = 205,

    // IR

    OB_PIXEL_FORMAT_Y10  = 300,
    OB_PIXEL_FORMAT_Y12  = 301,
    OB_PIXEL_FORMAT_Y16  = 302,
    OB_PIXEL_FORMAT_Y8I  = 303,
    OB_PIXEL_FORMAT_Y12I = 304

} OBPixelFormat;

/** \brief
 数据帧的元数据类型
*/

typedef enum {
    OB_FRAME_METADATA_FRAME_COUNTER,    /**< A sequential index managed per-stream. Integer value*/
    OB_FRAME_METADATA_FRAME_TIMESTAMP,  /**< Timestamp set by device clock when data readout and transmit commence. usec*/
    OB_FRAME_METADATA_SENSOR_TIMESTAMP, /**< Timestamp of the middle of sensor's exposure calculated by device. usec*/
    OB_FRAME_METADATA_ACTUAL_EXPOSURE,  /**< Sensor's exposure width. When Auto Exposure (AE) is on the value is controlled by firmware. usec*/
    OB_FRAME_METADATA_GAIN_LEVEL,
} OBFrameMetadataType;


/** \brief
  描述像素格式的枚举值
*/
typedef enum {
    OB_FORMAT_YUYV = 0,
    OB_FORMAT_UYVY,
    OB_FORMAT_NV12,
    OB_FORMAT_NV21,
    OB_FORMAT_MJPG,
    OB_FORMAT_H264,
    OB_FORMAT_H265,
    OB_FORMAT_Y16,
    OB_FORMAT_Y8,
    OB_FORMAT_Y10,
    OB_FORMAT_Y11,
    OB_FORMAT_Y12,
    OB_FORMAT_GREY,
    OB_FORMAT_UNKNOWN,
} OBFormat;
/** \brief
 描述数据的有效位
*/
typedef enum {
    OB_DEPTH_10_BIT = 10,
    OB_DEPTH_11_BIT = 11,
    OB_DEPTH_12_BIT = 12,
    OB_DEPTH_16_BIT = 16,
} OBValidDataBit;
/** \brief
 描述数据帧的结构体
*/
typedef struct {
    int                dataSize;
    void*              data;
    OBFrameType        frameType;
    OBFormat           pixelFormat;
    double             timestamp;
    unsigned long long frameIndex;
    int                width;
    int                height;
    int                fps;
} OBFrame;
/** \brief
  描述数据流类信息的配置文件
*/
typedef struct {
    int      width;
    int      height;
    int      fps;
    OBFormat format;  // pixel format forcc
} OBStreamProfile;
/** \brief
  数据帧video模式
*/
typedef struct {
    OBPixelFormat pixFormat_;
    int           resX_;
    int           resY_;
    int           fps;
} OBVideoMode;

/** \brief
 描述传感器的本身信息的结构体
*/
typedef struct {
    OBSensorType sensorType_;
    char         sensorName_[ 10 ];
    int          sensorID_;
    int          sensorFirmwareVersion_;

} OBSensorInfo;

typedef struct StreamConfig {
    OBStreamType streamType_;
    OBVideoMode  obVideoMode_;
} StreamConfig;

/** \brief
  数据帧的回调函数
*/
typedef void ( *OBNewFrameFromCallback )( void* pCookie, OBFrame* frame );

//======================================================================Pipeline type ==================================================
/** \brief
  SDK中3D点描述
*/
typedef struct {
    float x;
    float y;
    float z;
} OBPoint;
/** \brief
  带有颜色信息的3D点描述
*/
typedef struct {
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
} OBColorPoint;

struct OBPipelineImpl;
typedef struct OBPipelineImpl* OBPipelineHandle;

struct OBAlignImpl;
typedef struct OBAlignImpl* OBAlignHandle;

struct OBPointCloudImpl;
typedef struct OBPointCloudImpl* OBPointCloudHandle;

/** \brief
  对齐的输入参数
*/
typedef struct {
    OBVideoMode depthVideo;
    OBVideoMode colorVideo;
    int         softAlign;  // 1=>software Align, 0=>hardware Align
    int         HwAlignOn;
} OBAlignParameter;

/** \brief
  在Pipline高层接口的配置流的参数信息
*/
typedef struct {
    int      Enable;  // 0->false ,1->true
    OBFormat obFormat_;
    int      width;
    int      height;
    int      fps;

} OBStreamProfileConfig;

/** \brief
  High Level 中统一配置结构体和OBPipeline配合使用
*/
typedef struct {

    OBStreamProfileConfig DepthConfig;
    OBStreamProfileConfig IrConfig;
    OBStreamProfileConfig ColorConfig;
} OBConfig;

typedef enum {
    OB_ALIGN_ENABLE,
    OB_ALIGN_DISABLE,
} OBAlignStatus;
/** \brief
  High Level中的复合帧结构体
*/
typedef struct {
    OBFrame*      depthFrame;
    OBFrame*      colorFrame;
    OBFrame*      irFrame;
    OBAlignStatus isAlign;
} OBFrameSet;
/** \brief
  相机的内外参描述结构体
*/
typedef struct {
    float d_intr_p[ 4 ];  //深度相机内参：[fx,fy,cx,cy]
    float c_intr_p[ 4 ];  //彩色相机内参：[fx,fy,cx,cy]
    float d2c_r[ 9 ];     //深度相机到彩色相机的旋转矩阵 [r00,r01,r02;r10,r11,r12;r20,r21,r22]
    float d2c_t[ 3 ];     //深度相机到彩色相机的平移矩阵 [t1,t2,t3]
    float d_k[ 5 ];       //深度相机畸变参数 [k1,k2,k3,p1,p2]
    float c_k[ 5 ];       //彩色相机畸变参数 [k1,k2,k3,p1,p2]
} OBCameraParameter;

typedef struct SDKVersion {
   unsigned char  nMajor;  //  SDK主版本号
   unsigned char  nMinor;  // SDK次版本号
   unsigned short nBuild;  //  SDK编译版本号
} SDKVersion;

typedef struct Versions {
   char  nMajor;                   // 固件主版本号
   char  nMinor;                   // 固件次版本号
    short nBuild;                   // 固件编译版本号
   int   nChip;                    // 0601 -mx6000
    short nFPGA;                    // 0701-fgpa   FGPA的型号
    char  nSerialNumber[12];      // 设备的序列号
   short nDeviceType;              // 设备类型枚举值，TOF、结构光、双目
   SDKVersion     SDK;                      // ֧设备支持最低版本号
    short HWVer;                    // pcb的硬件版本号
   short nFWVer;                   // 固件的版本的枚举值
    char  nChipSerialNumber[12];  //   芯片序列号
    char  nRgbSensor[32];        //  rgb芯片型号
    char  nIRSensor[32];         //  ir的芯片型号                   
} Versions;

/** \brief
  双目视差转深度所需参数
*/
typedef struct {
    double fx;
    double baseline;
    double fCoefficient;
    int    nShiftScale;
    double disparityCoeff;
    int    maxDepthValue;
    int    minDepthValue;
} OBDualDisparityProcessParameter;
/** \brief
  单目视差转深度所需参数
*/
typedef struct {
    double fZeroPlaneDistance;  // Z0
    double nParamCoeff;
    double fZeroPlanePixelSize;
    float    fEmitterDComsDistance;  // baseline
    double nShiftScale;
    int    nConstShift;
    int    maxDepthValue;
    int    minDepthValue;
    int    nPixelSizeFactor;
} OBSingleDisparityProcessParameter;

typedef union {
    OBDualDisparityProcessParameter dualParameter;
    OBSingleDisparityProcessParameter singleParameter;
} OBDisparityProcessParameter;
/** \brief
  SoftFilter parameters
*/
typedef struct {
    int maxSpeckleSize_;
    int maxDiff_;
} OBSoftFilterParameter;

/** \brief
  深度处理所需的相关参数
*/
typedef struct {
    OBDisparityProcessParameter     disparityParameter_;
    OBSoftFilterParameter softFilterParameter_;
    int                            isDualCamera;
} OBDepthProcessParameter;

typedef struct BaselineCalibrationPara {
    float fZ0;
    float fBaseline;
} BaselineCalibrationPara;

 typedef struct MultipleDistanceCalibrationPara {
    int       nSize;
    unsigned char* data;
} MultipleDistanceCalibrationPara;

 typedef struct ReferenceImage {
    int       nSize;
    unsigned char* data;
} ReferenceImage;

 typedef struct HardwareAlignPara {
    int       nSize;
    unsigned char* data;
} HardwareAlignPara;

 typedef struct SoftwareAlignPara {
    int       nSize;
    unsigned char* data;
} SoftwareAlignPara;

 typedef struct HardwareDistortionPara {
    int       nSize;
    unsigned char* data;
} HardwareDistortionPara;

 typedef struct DepthConfigPara {
    int       nSize;
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
    int min;
    int max;
} RANGE;

 typedef struct AeParams {
    RANGE    expTime;
    RANGE    AGain;
    RANGE    laserCurrent;
    int targetBrightness;
    int targetThd;
    int centerWeight;
    int skipFrame;
    int smoothSteps;
    int dealy_ms;
    int meterMethod;
    unsigned char  expTimeAdj;
    unsigned char  AGainAdj;
    unsigned char  laserCurrentAdj;
    unsigned char  reserve;
} AeParams;


/****************************以下均为TOF参数相关结构体*************************/
typedef struct {
   float tx_temp;  //摄氏度
   float rx_temp;
} ObTofTemp;

typedef struct {
   int mode;  //1: 表示单频调制，2: 表示双频调制
   int freq_A;  //第一个调制频率(单频调制只有A频率有效)
   int freq_B;  //第二个调制频率
   int reseved; //保留位
} ObToFModulationFreq;

typedef struct {
   int mode;  //1: 表示单频调制，2: 表示双频调制
   float duty_A;  //第一个调制信号占空比， 取值省略百分号，如：54.2
   float duty_B;  //第二个调制信号占空比
   float reseved; //保留位
} ObToFDutyCycleInfo;

typedef struct
{
   float vcsel_temp_comp_coeff;   //vcsel 温度补偿系数
   float sensor_temp_comp_coeff;  //ir 温度补偿系数
   float temp_dist_offset;   //温度引起的零漂
}ToFTempCompensation;

// typedef struct
// {
//    int mode;  //1: 表示单频调制，2: 表示双频调制
//    ToFTempCompensation freq_A;
//    ToFTempCompensation freq_B;
// }ObToFTempCompensation;

typedef struct {
   // filter size
   int win_x;
   int win_y;
   float sigma_x;  // x sigma
   float sigma_y;  // y sigma
   unsigned char bypass;    // skip or not； 滤波开关
}GaussianFilterParam;

// typedef struct {
//    // 待定
//}ScatterFilterParam;

 typedef struct {
    int 	d;   // filter distance
    float 	sigma_color; // color sigma
    float 	sigma_space;  // space sigma
    unsigned char 	bypass;  // skip or not； 滤波开关
}BilateralFilterParam;

 typedef struct {
    float 	thres;  // thres for fly point filtering
    float 	noise_coeff;  // noise coeff;
    unsigned char 	fill_hole;   // fill the hole after fly point filtering
    unsigned char 	bypass;  //  skip or not， 滤波开关
}FlyPointFilterParam;

 typedef struct {
    int 	win_size; // window size
    unsigned char 	bypass; // skip or not； 滤波开关
}MedianFilterParam;

 typedef struct {
    float 	confidence_thres;
    unsigned char 	bypass; // skip or not； 滤波开关
}ConfidenceFilterParam;

 typedef struct {
    int 	nearest_length;   //最近距离， 单位：mm
    int 	farthest_length; //最远距离， 单位：mm
}DepthLenghtParam;

typedef void ( *OBFrameSetFromCallback )( void* pCookie, OBFrameSet* frame );
#ifdef __cplusplus
}
#endif
