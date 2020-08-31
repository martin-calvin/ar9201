/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: ar_ipcamer_type.h
Description: define ipcam
Author: klbai@artosyn.cn
Version: v1.0
Date:2019-06-03
History:2018-05-03 : first release sdk
*****************************************************************************/
#ifndef __IPCAM_TYPE__
#define __IPCAM_TYPE__
#ifdef __cplusplus
extern "C" {
#endif
#include "ar_multimedia_base.h"

typedef enum {
    IPCAM_CODEC_HEVC = 0,
    IPCAM_CODEC_AVC = 1,
} ipcam_encoder_type_t;

typedef enum {
    IPCAM_MAIN = 0,
    IPCAM_MINOR,
} ipcam_stream_index_t;

typedef struct {
    ar_facotry_element_obj_t pipeline;
    ar_facotry_element_obj_t cam_src;
    ar_facotry_element_obj_t yuv1_tee;
    ar_facotry_element_obj_t yuv2_tee;
    ar_facotry_element_obj_t comp1;
    ar_facotry_element_obj_t hevc_enc1;
    ar_facotry_element_obj_t hevc_enc2;
    ar_facotry_element_obj_t avc_enc1;
    ar_facotry_element_obj_t avc_enc2;
    /* bit stream sink*/
    ar_facotry_element_obj_t video_bs_sink1;
    ar_facotry_element_obj_t video_bs_sink2;
    /* yuv pipeline */
    ar_facotry_element_obj_t yuv_0_sink;
    ar_facotry_element_obj_t yuv_1_sink;
} ipcam_context_t;

typedef struct
{
  ar_mm_handle_t handle;
  ipcam_encoder_type_t enc_type;
  int cam_num;
  int hdr_mode;
  unsigned int fps;
  unsigned int width[2];//0:for main stream 1:for minor stream
  unsigned int height[2];
  unsigned int bitrate[2];
  ipcam_context_t *ipcam_context;
  ipcam_context_t *ipcam_dual_context;
} ipcam_obj_t;
#ifdef __cplusplus
}
#endif
#endif // __IPCAM_TYPE__
