/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: ar_pipeline_test.h
Description: define pipeline test case
Author: ycqiu@artosyn.cn
Version: v1.0
Date:2018-05-22
History:2018-05-22 : first release sdk
*****************************************************************************/
#ifndef __CAM_RAW_SERVER__
#define __CAM_RAW_SERVER__
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
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
#define RAW_DATA_PATH0  "/mnt/data0.raw"
#define RAW_DATA_PATH1  "/mnt/data1.raw"
#define AR_IPCAM_CAM_SRC_STREAM_NUMBER           2  // Pipeline only use scaler 0/1 in current pipeline
#define MAX_MEM_FIFO   4096
typedef struct {
    ar_facotry_element_obj_t pipeline;
    ar_facotry_element_obj_t cam_src_0;
    ar_facotry_element_obj_t buf_sink_0;
    ar_facotry_element_obj_t cam_src_1;
    ar_facotry_element_obj_t buf_sink_1;
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


#ifdef __cplusplus
}
#endif
#endif // __IPCAM__
