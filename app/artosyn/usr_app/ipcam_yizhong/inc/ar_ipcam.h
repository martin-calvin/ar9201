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
#include "ar_lancher.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "ar_system.h"
#include "ar_meta_define.h"
#include "ar_multimedia_base.h"
#include "ar_ipcam_type.h"

ipcam_obj_t *ipcam_init(void);
int ipcam_start_stream_impl(void *ipcam_obj);
int ipcam_stop_stream_impl(void *ipcam_obj);
int ipcam_change_bitrate_impl(void *ipcam_obj, unsigned int idx, unsigned int max_bitrate, unsigned int avg_bitrate);
int ipcam_change_resolution_impl(void *ipcam_obj, unsigned int idx, unsigned int width, unsigned int height);
int ipcam_change_codec_impl(void * ipcam_obj, unsigned int new_codec);

#ifdef __cplusplus
}
#endif
#endif // __IPCAM__
