/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: ar_pipeline_test.h
Description: define pipeline test case
Author: ycqiu@artosyn.cn
Version: v1.0
Date:2018-05-22
History:2018-05-22 : first release sdk
*****************************************************************************/
#ifndef __IPCAM__
#define __IPCAM__
#ifdef __cplusplus
extern "C" {
#endif
#include "ar_system.h"
#include "ar_meta_define.h"
#include "ar_multimedia_base.h"
#include "ipcam.h"
#include "ar_lancher.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "pipeline_ctl.h"

// #define IPCAM_USE_JPEG

typedef enum {
    IPCAM_CODEC_HEVC = 0,
    IPCAM_CODEC_AVC = 1,
} ipcam_codec_type_t;

typedef struct {
    ar_facotry_element_obj_t pipeline;
    ar_facotry_element_obj_t cam_src;
    ar_facotry_element_obj_t tee;
    ar_facotry_element_obj_t comp;
    ar_facotry_element_obj_t tee_to_en_disp;
    ar_facotry_element_obj_t video_enc;
    ar_facotry_element_obj_t video_bs_sink;
    /* yuv pipeline */
    ar_facotry_element_obj_t yuv_0_sink;
    ar_facotry_element_obj_t yuv_1_sink;
    ar_facotry_element_obj_t bs_tee;
    ar_facotry_element_obj_t video_parser;
    ar_facotry_element_obj_t video_dec;
    ar_facotry_element_obj_t display;
} ipcam_context_t;

typedef struct
{
  ar_mm_handle_t handle;
  int pipe_fd;
  int cam_num;
  int hdr_mode;
  int fps;
  int need_display;
  int w;
  int h;
  int dis_fps;
  int face_stats;
  int tee_copy;
  int tee_src_pad_index;
  int tee_copy_buffer_count;
  int bitrate;
  int use_hw_eis_ldc;
  int force_isp_ddr_mode;
  int err_proc;
  int transcode;
  ipcam_context_t *ipcam_context;
  pipeline_ctl_server_t *server_l;
}ipcam_server_t;

void *ipcam_init(ipcam_codec_type_t codec_type, int width1, int height1, int width2, int height2, int angle, int camera_idx);
void ipcam_final();
ipcam_server_t *get_ipcam_server(void);
#ifdef __cplusplus
}
#endif
#endif // __IPCAM__
