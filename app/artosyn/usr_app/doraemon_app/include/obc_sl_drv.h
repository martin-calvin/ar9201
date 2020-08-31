//#pragma once
#ifndef _OBC_SL_DRV_H_
#define _OBC_SL_DRV_H_
#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* __cplusplus */

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdint.h>
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
#include <stdint.h>
#include <sys/mman.h>
#include "backtrace.h"
#include "ar_cam_src.h"
#include "Mx6300_ctl.h"
#define RAW_DATA_PATH "/mnt/data.raw"
#define AR_IPCAM_CAM_SRC_STREAM_NUMBER 2 // Pipeline only use scaler 0/1 in current pipeline
#define MAX_MEM_FIFO 4096
#define DEVICE_CONFIG_ADDR 0x10000
#define DISTORTION_PARAMS_ADDR 0x20000
#define CONFIG_VALID_ADDR 0x30000
#define SOFT_D2C_PARAMS_ADDR 0x60000
#define REFERENCE_ADDR 0x80000
    typedef struct
    {
        ar_facotry_element_obj_t pipeline;
        ar_facotry_element_obj_t cam_src;
        ar_facotry_element_obj_t buf_sink_0;

    } sl_cam_raw_context_t;

    typedef struct
    {
        char *buf_mem;
        uint32_t buf_len;
    } sl_cam_buffer_t;

    typedef struct
    {
        int fd;
        int buf_sink_fd;
        pthread_t thread_id;
        pthread_t thread_process_id;
        pthread_cond_t buf_signal;
        ar_queue_t *buf_que;
        uint32_t buf_len;
        pthread_mutex_t mutex;
        int frame_count;
    } sl_cam_raw_config_t;

    typedef enum
    {
        OBC_DEV_OPEN = 1,
        OBC_DEV_CLOSE = !OBC_DEV_OPEN,
    } sl_dev_status_t;
    typedef enum
    {
        STREAM_CLOSED = 0,
        STREAM_DEPTH_OPENED,
        STREAM_IR_OPENED,
    } sl_stream_status_t;
    typedef enum
    {
        STREAM_NONE = 0,
        STREAM_DEPTH = 1,
        STREAM_IR = 2,
    } sl_stream_type_t;
    typedef struct
    {
        uint32_t width;
        uint32_t height;
    } sl_video_res_t;

    /* 用户配置cam_src pipeline 参数 */
    typedef struct
    {
        int cam_id; /* cam_id in dts*/
        sl_stream_type_t stream_type;
        sl_video_res_t input_vidio_res; /* input vidio width and height */
        int subsample_rate;             /* rtos vip subsample_rate <0-15> */
        int fps;                        /* vidio fps */
    } sl_usr_cfg_ppl_t;

    /* <global>记录当前驱动状态 */
    typedef struct
    {
        sl_dev_status_t remote_spi_status;   /* remote i2c open/close status */
        ar_mm_handle_t sl_cam_src_handle;    /* ar_cam_src pipline handle */
        sl_dev_status_t sl_ppl_status;       /* pipline can only init once */
        sl_stream_status_t sl_stream_status; /* stream status */
        int sl_cam_id;                       /* cam_id in driver,default use 0 */
        int sl_cam_fd;                       /* cam_fd */
        int spi_fd;                          /* spi_fd */
        sl_usr_cfg_ppl_t cam_pipeline_cfg;   /* 用户配置cam_src pipeline 参数 */
    } gl_dev_t;
    //extern  gl_dev_t g_dev;

    /**
 * @brief  init camera driver and rtos pipeline setup
 * @param usr_cfg_ppl  the driver info need to set
 * @code
 * typedef struct
 * {
 *     int cam_id;                     // cam_id in dts, default @param 0
 *     sl_video_res_t input_vidio_res;    // input vidio width and height, default @param 640*480
 *     int subsample_rate;             // rtos vip subsample_rate <0-15>, default @param 15
 *     int fps;                        // vidio fps,default @param 30 
 * }sl_usr_cfg_ppl_t;
 * @endcode
 * @return   0 success <0 failed
 * @note  no
 */
    int init_sl_cam(sl_usr_cfg_ppl_t *usr_cfg_ppl);

    /**
 * @brief  deinit  camera driver and multimedia sys
 * @param  cam_id  the number of camera device node, such as /dev/cam_src-0, default  @param 0
 * @return a fd of the camera device >=0 success, <0 err
 * @note null
 */
    int delint_sl_cam(sl_usr_cfg_ppl_t *usr_cfg_ppl);
    /**
 * @brief  open the camera to set ctl
 * @param  cam_id  the number of camera device node, such as /dev/cam_src-0, default  @param 0
 * @return a fd of the camera device >=0 success, <0 err
 * @note null
 */
    int open_sl_cam(int cam_id);

    /**
 * @brief  close the camera which open_cam
 * @param  fd the fd of  open_cam
 * @return 0 success !0 failed
 * @note null
 */
    int close_sl_cam(int fd);

    /**
 * @brief  open stream 
 * @param  stream  the type of stream
 * @return 0 success !0 failed
 * @note null
 */
    int sl_stream_on(Stream_ctl_State stream);
    /**
 * @brief  close stream
 * @return 0 success !0 failed
 * @note null
 */
    int sl_stream_off();
    /**
 * @brief  switch resolution 
 * @param  stream  the type of stream
 * @param  res resolution defined in Mx6300_ctl.h
 * @return 0 success !0 failed
 * @note null
 */
    int switch_resolution(Stream_ctl_State stream, Resolution res,uint8_t fps);

    /**
 * @brief  read flash 
 * @param  addr  the address of flash
 * @param  pdata  the buffer to store data
 * @param  len  the length of data
 * @return 0 success !0 failed
 * @note null
 */
    int obc_sl_read_flash(uint32_t addr, void *pdata, uint32_t len);

    /**
 * @brief  write resolution 
 * @param  addr  the address of flash
 * @param  pdata  the buffer to store data
 * @param  len  the length of data
 * @return 0 success !0 failed
 * @note null
 */
    int obc_sl_write_flash(uint32_t addr, void *pdata, uint32_t len);

    int obc_sl_setBaseAddr(uint32_t base_addr);
    int obc_sl_send_rectify_params();
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif