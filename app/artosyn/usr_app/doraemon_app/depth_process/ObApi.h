/* License: Apache 2.0. See LICENSE file in root directory.
   Copyright(c) 2020  Orbbec Corporation. All Rights Reserved. */

/**   \file ObApi.h
 *    \brief        libobsensor的纯C的API，提供API接口定义文件
 *    \author xuchongyan@orbbec.com
 *   
 */
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "ObTypes.h"



/**
 * \brief 获取libobsensor的版本号，版本号格式： 0.1.0.0 .

 * \param[in]  null
 * \param[out] null.
 * \return    返回OBVersion的结构体
 */
OB_EXTENSION_API OBVersion obGetVersion();
/**
 * \brief   创建Context的句柄，检查API版本和日志的输出等级
 * \param[in]   apiVersion  用OB_API_VERSION的常量作为版本
 * \param[in]   log         SDK的日志的输出等级
 * \param[out]  result      记录发生异常时的错误信息
 * \return      void
 */

OB_EXTENSION_API void obContextCreate( OBLogSeverity log, int apiVersion, OBResult** result );
/**
 * \brief   设置日志的输出等级
 * \param[in]   log  OBLogSeverity的log的输出等级
 * \param[in]   type log的输出文件或终端
 * \param[out]  result      记录发生异常时的错误信息
 * \return      void
 */

OB_EXTENSION_API void obSetLogParameters( OBLogSeverity log, OBLogOutType type, OBResult** result );

/**
 * \brief   关闭obsensor的sdk，释放资源
 * \param[out]   result        返回发生异常时的错误信息
  * \return      void
 */
OB_EXTENSION_API void obContextDestory( OBResult** result );

/**
 * \brief   获取SDK枚举到设备信息列表
 * \param[out]   pNumDevices   返回指向获取列表的个数指针
 * \param[out]   result        记录发生异常时的错误信息
 * \return      OBDeviceInfo*  设备信息列表
 */
OB_EXTENSION_API OBDeviceDescription* obGetDeviceList( int* pNumDevices, OBResult** result );

/**
 * \brief   释放枚举到设备信息列表
 * \param[in]   pDevices      设备列表信息列表指针
 * \param[out]   result        返回发生异常时的错误信息
 * \return      void
 */
OB_EXTENSION_API void obReleaseDeviceList( OBDeviceDescription* pDevices, OBResult** result );
/**
 * \brief   设置监听设备插拔状态的回调
 * \param[in]   ctx  Context的句柄
 * \param[in]   pCallbacks  指向设备的回调的函数指针
 * \param[in]   pCookie     记录当前调用的者的指针
 * \param[out]   result     记录发生异常时的错误信息
 * \return      void
 */
OB_EXTENSION_API void obSetDeviceCallbacks( OBDeviceCallbacks* pCallbacks, void* pCookie, OBResult** result );


/**
 * \brief   基于设备的枚举信息，创建一个设备对象

 * \param[in]   deviceDescription        设备的描述信息
 * \param[out]  result      记录发生异常时的错误信息
 * \return      OBDeviceHandle 返回设备指针句柄
 */

OB_EXTENSION_API OBDeviceHandle obDeviceCreate( OBDeviceDescription* deviceDescription, OBResult** result );

/**
 * \brief   销毁一个设备
 * \param[in]   devHandle       指向设备的指针句柄
 * \param[out]   result         记录发生异常时的错误信息
 * \return      void
 */


OB_EXTENSION_API void obDeviceDestory( OBDeviceHandle devHandle,OBResult** result );


//=================================================================devHandle API========================================================

/**
 * \brief   获取设备本身详细描述信息
 * \param[in]   devHandle      指向设备的指针句柄
 * \param[out]   result         记录发生异常时的错误信息
 * \return      OBDeviceInfo
 */
OB_EXTENSION_API OBDeviceInfo obDeviceGetInfo( OBDeviceHandle devHandle, OBResult** result );
/**
 * \brief   设置设备的运行期间属性信息
 * \param[in]   devHandle      指向设备的指针句柄
 * \param[in]   propertyId  设备属性ID
 * \param[in]   data       指向设备的属性数据值
 * \param[in]   dataSize    属性数据长度
 * \param[out]   result         记录发生异常时的错误信息
 * \return      void
 */
OB_EXTENSION_API void obDeviceSetProperty( OBDeviceHandle devHandle, OBDeviceProperty propertyId, const void* data, int dataSize, OBResult** result );
/**
 * \brief   获取设备的运行期间属性信息
 * \param[in]   devHandle      指向设备的指针句柄
 * \param[in]   propertyId  设备属性ID
 * \param[out]   data       指向设备的属性数据值
 * \param[out]   pDataSize  返回属性数据长度
 * \param[out]   result     记录发生异常时的错误信息
 * \return      void
 */

OB_EXTENSION_API void obDeviceGetProperty( OBDeviceHandle devHandle, OBDeviceProperty propertyId, void* data, int* pDataSize, OBResult** result );
/**
 * \brief   判断设备是否支持属性
 * \param[in]   devHandle      指向设备的指针句柄
 * \param[in]   propertyId      设备属性ID
 * \param[out]   result         记录发生异常时的错误信息
 * \return      int      返回1代表支持，返回0代表不支持
 */

OB_EXTENSION_API int obDeviceIsPropertySupported( OBDeviceHandle devHandle, OBDeviceProperty propertyId, OBResult** result );

/**
 * \brief   获取设备默认属性取值范围
 * \param[in]   devHandle      指向设备的指针句柄
 * \param[in]   propertyId     设备属性ID
 * \param[out]   result         记录发生异常时的错误信息
 * \return      OBPropertyRange    返回设备属性取值范围。
 */
OB_EXTENSION_API OBPropertyRange obDeviceGetPropertyRange( OBDeviceHandle devHandle, OBDeviceProperty propertyId, OBResult** result );

/**
 * \brief   恢复设备的出厂设置
 * \param[in]   devHandle      指向设备的指针句柄
 * \param[out]   result         记录发生异常时的错误信息
 * \return      void
 */
OB_EXTENSION_API void obDeviceReset( OBDeviceHandle devHandle, OBResult** result );

/**
 * \brief   设置设备的开启和关闭帧同步功能
 * \param[in]   devHandle      指向设备的指针句柄
 * \param[in]   on           on=1开启同步，on=0关闭同步功能
 * \param[out]  result         记录发生异常时的错误信息
 * \return      void
 */
OB_EXTENSION_API void obDeviceSetSyncStatus( OBDeviceHandle devHandle, int on, OBResult** result );
/**
 * \brief   设备的固件升级
 * \param[in]   devHandle      指向设备的指针句柄
 * \param[in]   fwuri       固件的文件的uri地址
 * \param[in]   pCallback   固件升级进度回调
 * \param[out]   result         记录发生异常时的错误信息
 * \return     void
 */

OB_EXTENSION_API void obDeviceUpgrade( OBDeviceHandle devHandle, const char* fwuri, OBDeviceUpgradeProcess pCallback, OBResult** result );

/**
 * \brief   获取相机参数
 * \param[in]   devHandle       指向设备的指针句柄
 * \param[out]   result         记录发生异常时的错误信息
 * \return      OBCameraParameter    返回相机参数
 */
OB_EXTENSION_API OBCameraParameter obDeviceGetCameraParameter( OBDeviceHandle devHandle, OBResult** result );

/**
 * \brief   获取设备的指定类型传感器
 * \param[in]   devHandle       指向设备的指针句柄
 * \param[in]   type            指向设备的指针句柄
 * \param[out]   result         记录发生异常时的错误信息
 * \return      OBSensorHandle  返回传感器的指针句柄
 */

OB_EXTENSION_API OBSensorHandle obDeviceGetSensor( OBDeviceHandle devHandle, OBSensorType type, OBResult** result );
/**
 * \brief   释放设备传感器
 * \param[in]   pSensor       指向设备的指针句柄
 * \param[out]   result       记录发生异常时的错误信息
 * \return      void
 */
OB_EXTENSION_API void obDeviceReleaseSensor( OBSensorHandle pSensor, OBResult** result );
/**
 * \brief   获取设备中所有的传感器列表
 * \param[in]   devHandle       指向设备的指针句柄
 * \param[out]  pSensorNum  返回传感器的个数
 * \param[out]   result       记录发生异常时的错误信息
 * \return      OBSensorHandle*    返回传感器列表指针
 */

OB_EXTENSION_API OBSensorHandle* obDeviceGetSensorList( OBDeviceHandle devHandle, int* pSensorNum, OBResult** result );
/**
 * \brief   释放设备中所有的传感器列表
 * \param[out]   pSensors   指向设备中传感器的指针
 * \param[out]   result     记录发生异常时的错误信息
 * \return      void
 */

OB_EXTENSION_API void obDeviceReleaseSensorList( OBSensorHandle* pSensors ,OBResult** result );

//======================================sensorHandle API ================================

/**
 * \brief   设置传感器的属性信息
 * \param[in]   sensorHandle      指向传感器的指针句柄
 * \param[in]   sensorPropertyId  传感器属性ID
 * \param[in]   data       指向传感器的属性数据值
 * \param[in]   dataSize    属性数据长度
 * \param[out]   result       记录发生异常时的错误信息
 * \return     void
 */
OB_EXTENSION_API void obSensorSetProperty( OBSensorHandle sensorHandle, OBSensorProperty sensorPropertyId, const void* data, int dataSize, OBResult** result );
/**
 * \brief   获取传感器的属性信息
 * \param[in]   sensorHandle            指向传感器的指针句柄
 * \param[in]   sensorPropertyId  传感器属性ID
 * \param[out]  data              指向传感器的属性数据值
 * \param[out]  pDataSize         属性数据长度
 * \param[out]   result       记录发生异常时的错误信息
 * \return      void
 */
OB_EXTENSION_API void obSensorGetProperty( OBSensorHandle sensorHandle, OBSensorProperty sensorPropertyId, void* data, int* pDataSize, OBResult** result );

/**
 * \brief   获取传感器的属性信息
 * \param[in]   sensorHandle            指向传感器的指针句柄
 * \param[in]   sensorPropertyId  传感器属性的枚举值
 * \param[out]   result       记录发生异常时的错误信息
 * \return      OBPropertyRange         返回属性数据取值范围
 */
OB_EXTENSION_API OBPropertyRange obSensorGetPropertyRange( OBSensorHandle sensorHandle, OBSensorProperty sensorPropertyId, OBResult** result );
/**
 * \brief   判断传感器是否支持属性
 * \param[in]   devHandle      指向传感器的指针句柄
 * \param[in]   propertyId      传感器属性ID
 * \param[out]   result         记录发生异常时的错误信息
 * \return      int      返回1代表支持，返回0代表不支持
 */
OB_EXTENSION_API int obSensorIsPropertySupported( OBSensorHandle sensorHandle, OBSensorProperty sensorPropertyId, OBResult** result );
/**
 * \brief   获取传感器的类型
 * \param[in]   sensorHandle            指向传感器的指针句柄
 * \param[out]   result       记录发生异常时的错误信息
 * \return      OBSensorType          返回传感器的类型
 */
OB_EXTENSION_API OBSensorType obSensorGetType( OBSensorHandle sensorHandle, OBResult** result );
/**
 * \brief   获取传感器的信息
 * \param[in]   sensorHandle     指向传感器的指针句柄
 * \param[out]   result          记录发生异常时的错误信息
 * \return      OBSensorInfo*    返回传感器信息指针
 */
OB_EXTENSION_API OBSensorInfo* obSensorGetInfo( OBSensorHandle sensorHandle, OBResult** result );
/**
 * \brief   获取传感器的流配置信息
 * \param[in]   sensorHandle            指向传感器的指针句柄
 * \param[out]  profileCount     返回传感器的流配置的个数
 * \param[out]   result          记录发生异常时的错误信息
 * \return      OBStreamProfile*       返回流配置信息指针
 */
OB_EXTENSION_API OBStreamProfile* obSensorGetProfiles( OBSensorHandle sensorHandle, int* profileCount, OBResult** result );

/**
 * \brief   释放Profiles的资源
 * \param[in]   sensorHandle            指向传感器的指针句柄
 * \param[out]  pStreamProfiles   返回传感器的流配置的信息
 * \param[out]   result          记录发生异常时的错误信息
 * \return      void
 */
OB_EXTENSION_API void obSensorReleaseProfiles( OBSensorHandle sensorHandle, OBStreamProfile* pStreamProfiles, OBResult** result );
/**
 * \brief   传感器开始出流
 * \param[in]   sensorHandle            指向传感器的指针句柄
 * \param[in]  streamProfiles     单个流的配置信息，详细参考 OBStreamProfile
 * \param[in]  pCallback        获取数据帧的回调函数
 * \param[in]   cookie              用户自定义数据，记录回调者
 * \param[out]   result          记录发生异常时的错误信息
 * \return      void
 */
OB_EXTENSION_API void obSensorStart( OBSensorHandle sensorHandle, OBStreamProfile* streamProfiles, OBNewFrameFromCallback pCallback, void* pCookie,OBResult** result );
/**
 * \brief   传感器停止出流
 * \param[in]   sensorHandle            指向传感器的指针句柄
 * \param[out]   result          记录发生异常时的错误信息
 * \return      void
 */
OB_EXTENSION_API void obSensorStop( OBSensorHandle sensorHandle, OBResult** result );

//========================================High OBPipeline=====================================

/**
 * \brief   创建一个Pipeline做数据帧的处理.
 * \param[out]   result          记录发生异常时的错误信息
 * \return      OBPipelineHandle 返回pipeline的句柄
 */
OB_EXTENSION_API OBPipelineHandle obPipelineCreate( OBResult** result );

/**
 * \brief   创建一个Pipeline做数据帧的处理.
 * \param[in]   dev              设备句柄
 * \param[out]  result           记录发生异常时的错误信息
 * \return      OBPipelineHandle 返回pipeline的句柄
 */
OB_EXTENSION_API OBPipelineHandle obPipelineCreateFromDevice( OBDeviceHandle dev, OBResult** result );

/**
 * \brief       销毁一个pipeline，释放资源
 * \param[in]   pipeline           pipeline的指针
 * \param[out]  result           记录发生异常时的错误信息
 * \return      void
 */

OB_EXTENSION_API void obPipelineDestroy( OBPipelineHandle pipeline, OBResult** result );

/**
 * \brief       完成一个数据流的config配置后，开启数据流处理
 * \param[in]   config             数据流的格式、数据流的处理配置
 * \param[in]   pipeline           pipeline的指针
 * \param[in]   pFrameSetCallback  设置一个FrameSet的回调
 * \param[in]   cookie              用户自定义数据，记录回调者
 * \param[out]  result           记录发生异常时的错误信息
 * \return      void
 */
OB_EXTENSION_API void obPipelineStartForCB( OBPipelineHandle pipeline, OBConfig config, OBFrameSetFromCallback pFrameSetCallback, void* cookie, OBResult** result );

/**
 * \brief       完成一个数据流的config配置后，开启数据流处理
 * \param[in]   pipeline           pipeline的指针
 * \param[in]   config             数据流的格式、数据流的处理配置
 * \param[out]  result           记录发生异常时的错误信息
 * \return      void
 */
OB_EXTENSION_API void obPipelineStart( OBPipelineHandle pipeline, OBConfig config, OBResult** result );
//增加一个回调方式 ***
/**
 * \brief       停止数据流的处理
 * \param[in]   pipeline           pipeline的指针
 * \param[out]  result           记录发生异常时的错误信息
 * \return      void
 */

OB_EXTENSION_API void obPipelineStop( OBPipelineHandle pipeline, OBResult** result );

/**
 * \brief   开启主动的调用的方式读取数据帧。
 * \param[in]   pipeline          指向Pipeline的指针句柄
 * \param[in]   timeout          获取数据集的超时时间
 * \param[out]  result           记录发生异常时的错误信息
 * \return      OBFrameSet*       返回数据集
 */

OB_EXTENSION_API OBFrameSet* obPipelineWaitForFrame( OBPipelineHandle pipeline, int timeOut, OBResult** result );


//===================================================Filters=================================================================

/**
 * \brief   创建软件对齐的Filter。
 * \param[in]   pipeHandle        指向Pipeline的指针句柄
 * \param[in]  parameter          对齐参数结构体
 * \param[out]  result            记录发生异常时的错误信息
 * \return      OBAlignHandle     返回对齐句柄
 */

OB_EXTENSION_API OBAlignHandle obPipelineCreateAlign( OBPipelineHandle pipeHandle,OBAlignParameter parameter, OBResult** result );

/**
 * \brief   执行对齐操作。
 * \param[in]  handler            对齐的Align的句柄
 * \param[in]  parameter          输入对齐参数，选择硬件对齐，还是软件对齐。待对齐的Depth、Color的分辨率
 * \param[in]  inFrameSet         输入对齐的FrameSet
 * \param[out]  result            记录发生异常时的错误信息
 * \return      OBFrameSet*       返回对齐后的复合数据帧
 */

OB_EXTENSION_API OBFrameSet* obAlignProcess( OBAlignHandle handler, OBAlignParameter parameter, OBFrameSet* inFrameSet, OBResult** result );

/**
 * \brief   销毁一个Filter。
 * \param[in]  pipeHandle       pipeline的句柄
 * \param[in]  pFilter          指向Filter的指针。
 * \param[out]  result          记录发生异常时的错误信息
 * \return      void      
 */

OB_EXTENSION_API void obAlignDestory( OBPipelineHandle pipeHandle, OBAlignHandle pFilter, OBResult** result );

/**
 * \brief       设置对齐状态
 * \param[in]   pipeHandle      Pipe的指针handle
 * \param[in]   handle           对齐的滤波器指针
 * \param[in]   on               对齐的开关状态on-1，off-0
 * \param[out]  result          记录发生异常时的错误信息
 * \return      void
 */
OB_EXTENSION_API void obAlignSetStatus( OBPipelineHandle pipeHandle, OBAlignHandle handle, int on, OBResult** result );
/**
 * \brief   创建点云的Filter。
 * \param[out]  pipeline            返回点云过滤器指针
 * \param[out]  result              记录发生异常时的错误信息
 * \return      OBPointCloudHandle  返回点云句柄
 */
OB_EXTENSION_API OBPointCloudHandle obPipelineCreatePointCloud( OBPipelineHandle pipeline, OBResult** result );
/**
 * \brief   生产纯深度的点云数据。
 * \param[in]  pointHandle        点云的句柄
 * \param[in]  depthFrame              输入点云的数据
 * \param[out]  pointSize         返回点云的数据大小
 * \param[out]  result            记录发生异常时的错误信息
 * \return      OBPoint*          返回点云数据指针
 */

OB_EXTENSION_API OBPoint* obCreateDepthPointCloud( OBPointCloudHandle pointHandle, OBFrameSet* depthFrame, int* pointSize, OBResult** result );
/**
 * \brief   生产带有彩色的点云数据。
 \param[in]  pointHandle          点云的句柄
 * \param[in]  frame              输入点云的数据
 * \param[out]  pointSize         返回点云的数据大小
 * \param[out]  result            记录发生异常时的错误信息
 * \return      OBColorPoint*     返回彩色点云数据指针
 */

OB_EXTENSION_API OBColorPoint* obCreateRGBDPointCloud( OBPointCloudHandle pointHandle, OBFrameSet* frame, int* pointSize, OBResult** result );

/**
 * \brief   销毁一个Filter。
 * \param[in]  pFilter              指向点云Filter的指针。
 * \param[out]  result              记录发生异常时的错误信息
 * \return     void
 */

OB_EXTENSION_API void obPointCloudDestroy( OBPointCloudHandle pFilter, OBResult** result );

OB_EXTENSION_API OBResult* obCreateResult( OBStatus status, const char* what, const char* name, const char* args, ObExceptionType type );
OB_EXTENSION_API void       obDestroyResult( OBResult* result );
OB_EXTENSION_API const char* obGetFailedFunction( const OBResult* result );
OB_EXTENSION_API const char*  obGetFailedArgs( const OBResult* result );
OB_EXTENSION_API const char*  obGetResultMessage( const OBResult* result );
OB_EXTENSION_API ObExceptionType obGetOBExceptionType( const OBResult* result );
#ifdef __cplusplus
}
#endif
