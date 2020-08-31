/****************************************************************************
 * Copyright (C) 2019 Shanghai Artosyn Microelectronics Limited.            *
 ****************************************************************************/
/** \addtogroup alg 
 *  @{
 */
/**
 * @file ar_picture_common_api.h
 * @author Artosyn
 * @date 7 March 2019
 * @brief File containing the APIs to get picture.
 *        Users can refer to app/artosyn/usr_test/test_icc_proxy_sink/test_icc_proxy_sink.c for sample code, or contact Artosyn for help.
 * @example <app/artosyn/usr_test/test_icc_proxy_sink/test_icc_proxy_sink.c>
 */

#ifndef AR_PICTURE_COMMON_API_H_
#define AR_PICTURE_COMMON_API_H_
#ifdef __cplusplus
extern "C"{
#endif
#include <stdint.h>
#include "ar_system.h"
#include "v4ar_dev.h"
/**
* @brief  picture handler
*/
typedef void* ar_picture_handle;
/**
* @brief  yuv data memory information struct
*/
typedef struct {
    uint32_t addr; /**< virtual address */
    uint32_t len; /**< memory length */
    uint32_t pa; /**< physical address */
}ar_img_mem_t;

/**
* @brief  yuv buffer information struct
*/
typedef struct {
    uint32_t frame_id; /**< yuv buffer frame id */
    uint32_t pts; /**< timestamps */
    ar_video_format_info_t format; /**< yuv data information */
    uint32_t mem_num; /**< memory number */
    ar_img_mem_t mem[3]; /**<  yuv data memory information struct*/
	v4ar_buffer_t v4ar_data_info;
}ar_picture_buffer_t;

#if defined(WIN32) || defined(X64)

/* video_name is "/dev/video_yuv-0" or "/dev/video_yuv-1" */
__inline ar_picture_handle ar_picture_open(const char *dev_name)
{
    return 0;
}
__inline ar_picture_buffer_t* ar_picture_get_img(ar_picture_handle handle)
{
    return 0;
}
__inline int ar_picture_release_img(ar_picture_handle handle, ar_picture_buffer_t *buf_info)
{
    return 0;
}
__inline void ar_picture_close(ar_picture_handle handle)
{
    return ;
}
#else
/**
* @brief    open picture device to get yuv data
* @param  dev_name device name,  dev_name is "/dev/video_yuv-0" or "/dev/video_yuv-1"
* @return  integer.
*              0 is error,
*              others is ok.
* @note null.
*/
ar_picture_handle ar_picture_open(const char *dev_name);
/**
* @brief  get picture infomation
* @param  void
* @return  failed, if no none
* @note null.
*/
int ar_picture_get_format(ar_picture_handle handle, ar_video_format_info_t*format);

/**
* @brief  acquire picture buffer
* @param  handle device handler
* @return  yuv buffer information struct pointer.
*              Null is error,
*              not null is ok.
* @note null.
*/
ar_picture_buffer_t* ar_picture_get_img(ar_picture_handle handle);
/**
* @brief  release picture buffer
* @param  fd device handler
* @param  buf_info picture buffer information struct
* @return  integer.
*              0 is ok,
*              other is error.
* @note: call ar_alg_release_img, set "buf_info" memory 0, means "buf_info" not used following.
*/
int ar_picture_release_img(ar_picture_handle handle, ar_picture_buffer_t *buf_info);
/**
* @brief  open device about geting freeRtos info
* @param  void
* @return  integer fd.
*              > 0 is ok,
*              others is error.
* @note null.
*/
int ar_picture_open_time_dev();
/**
* @brief  get timestamp of freeRtos info
* @param  time_fd the fd returned by open device
* @return  unsigned integer.
*              > 0 is ok,
*              0 is error.
* @note null.
*/
uint32_t ar_picture_get_sys_time(int time_fd);
/**
* @brief  close getting picture device
* @param  handle device handler
* @return  void
* @note null.
*/
void ar_picture_close(ar_picture_handle handle);

#endif

#ifdef __cplusplus
}
#endif

#endif
/** @}*/
