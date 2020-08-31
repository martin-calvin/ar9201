#ifndef __OB_REF_PARSER_
#define __OB_REF_PARSER_

#ifdef _WIN32
#define OB_EXPORT_API __declspec(dllexport)
#else
#define OB_EXPORT_API __attribute__ ((visibility("default")))
#endif
#include <stdint.h>

/**
* @brief 采集参考图时的温度
*/
typedef struct ObRefTemp_t {
    float ir_cali_temp;
    float ldemp_cali_temp;
}ObRefTemp;

/**
* @brief ir sensor内参
*/
typedef struct ObIRIntrinsic_t {
    /** 内参 fx */
    float fx;
    /** 内参 fy */
    float fy;
    /** 内参 cx */
    float cx;
    /** 内参 cy */
    float cy;
}ObIRIntrinsic;

/**
* @brief ir rotation 外参
*/
typedef struct ObIrExtrin_t {
    float rx;
    float ry;
    float rz;
}ObIrExtrin;

/**
* @brief ir rotation 外参
*/
typedef struct ObRefCalibInfo_t {
    /** IR Sensor到激光的距离 */
    float baseline;
    /** 标定距离 */
    float z0;
    /** 标定平面量化单位 */
    float zpps;
}ObRefCalibInfo;


/**
* @brief 参考图解析后结构体成员
*/
typedef struct ObRefInfo_t {
    ObIrExtrin ir_extrin;
    ObRefTemp temp;
    int ref_len;
    /** 解析后参考图的buffer */
    char* ref_buf;
}ObRefInfo;

/**
* @brief 参考图解析后内参、标定信息
*/
typedef struct ObDepthConfig_t {
    ObRefCalibInfo calib;
    ObIRIntrinsic intrinsic;
    uint32_t unit;//1:1mm； 10：表示0.1mm
    uint32_t ref_left_extend;
}ObDepthCfg;


#ifdef __cplusplus
extern "C" {
#endif

    /**
    * @brief 参考图解析
    * @param[in]       in_buf  传入参考图文件内容buffer
    * @param[in]       in_len  传入参考图文件内容buffer的长度
    * @param[in/out]   ObRefInfo 传入并传出解析参考图后结构体地址
    * @param[in/out]   cfg 传入并传出Depth配置参数
    * @retval  0  成功
    * @retval 非0  失败
    */
    OB_EXPORT_API int obref_parser(const char* in_buf, int in_len, ObRefInfo* info, ObDepthCfg* cfg);

    /**
    * @brief 参考图解析
    * @param[in] ref_buf 传入参考图文件内容buffer
    * @param[in] ref_len 传入参考图文件内容buffer的长度
    * @param[in/out] ref_decrypt 传入并传出解析参考图后结构体地址
    * @param[in/out] ref_info 传入并传出REF配置参数
    * @retval 0 成功
    * @retval 非0 失败
    */
    OB_EXPORT_API int obref_parser_ex(const char* ref_buf, int ref_len, ObRefInfo* ref_decrypt, void* ref_info);

    /**
    * @brief 释放资源
    * @param[in/out]   info 释放该参考图资源
    *
    * @retval  0  成功
    * @retval 非0  失败
    */
    OB_EXPORT_API int obref_release(ObRefInfo* info);

    /**
    * @brief 获取解析库版本号
    * @retval  版本号格式: 从高位到低位依次是major, minor, revision
    */
    OB_EXPORT_API uint32_t obref_version();

#ifdef __cplusplus
}
#endif

#endif
