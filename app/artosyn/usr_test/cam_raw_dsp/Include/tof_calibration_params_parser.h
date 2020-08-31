/*****************************************************************************
*  Orbbec ToFDepth 1.0
*  Copyright (C) 2020 by ORBBEC Technology., Inc.
*
*  This file is part of Orbbec ToFDepth.
*
*  This file belongs to ORBBEC Technology., Inc.
*  It is considered a trade secret, and is not to be divulged or used by
* parties who have NOT received written authorization from the owner.
*
*  Description:
*
****************************************************************************/

#ifndef __TOF_CALIBRATION_PARAMS_PARSER_H__
#define __TOF_CALIBRATION_PARAMS_PARSER_H__

#include "tof_calib_params.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#    ifdef VCAL_EXPORTS
#        define VCAL_API __declspec(dllexport)
#    else
#        define VCAL_API __declspec(dllimport)
#    endif
#else
#    define VCAL_API
#endif

typedef enum
{
    PARAM_PARSE_OK = 0,
    PARAM_PARSE_FAILED = 4095,
    /**< Unixϵͳʹ��-1 ~ -4095��Ϊϵͳ���� */
    PARAM_PARSE_INVALID_ARG = 4096, /**< ��Ч��������� */
    PARAM_PARSE_CORRUPT = 4097,     /**< У��ʧ�� */
    PARAM_PARSE_NOSUPP = 4098,      /**< �����ݲ�֧�� */
} ParamParseErr;

/***
/**
 * @brief   ���ز����ļ�
 * @param[in]  fname     �ļ���
 * @param[out] params    ���ز���
 * @param[in]  format    �ļ���ʽ
 * @retval  0   success
 * @retval -1   failed
 */
VCAL_API ParamParseErr LoadToFCalibrationParams(const char *fname, ObToFParam *params);

/***
/**
* @brief   �ͷŲ���
* @retval  0   success
* @retval -1   failed
*/
VCAL_API ParamParseErr ObToFParamsFree();

#ifdef __cplusplus
}
#endif

#endif //__TOF_CALIBRATION_PARAMS_PARSER_H__
