/****************************************************************************
 * Copyright (C) 2019 Shanghai Artosyn Microelectronics Limited.            *
 ****************************************************************************/
/** \addtogroup alg 
 *  @{
 */

/**
 * @file ar_img_api.h
 * @author Artosyn
 * @date 7 March 2019
 * @brief File containing the APIs to get YUV data.
 *        Users can refer to app/artosyn/usr_test/test_icc_proxy_sink/test_icc_proxy_sink.c for sample code, or contact Artosyn for help.
 * @example <app/artosyn/usr_test/test_icc_proxy_sink/test_icc_proxy_sink.c>
 */

#ifndef AR_ALG_IMG_API_H_
#define AR_ALG_IMG_API_H_
#ifdef __cplusplus
extern "C"{
#endif
#include <stdint.h>
#include "ar_system.h"

/**
* @brief  yuv data memory information struct
*/
typedef struct {
    uint32_t addr; /**< virtual address */
    uint32_t len; /**< memory length */
    uint32_t pa; /**< physical address */
}ar_rpc_sink_mem_t;

/**
* @brief  yuv buffer information struct
*/
typedef struct {
    uint32_t frame_id; /**< yuv buffer frame id */
    uint32_t pts; /**< timestamps */
    ar_video_format_info_t format; /**< yuv data information */
    uint32_t mem_num; /**< memory number */
    ar_rpc_sink_mem_t mem[3]; /**<  yuv data memory information struct*/
}ar_rpc_sink_buffer_t;

#if defined(WIN32) || defined(X64)

/* video_name is "/dev/video_yuv-0" or "/dev/video_yuv-1" */
__inline int ar_alg_open_video_stream(char *video_name)
{
	return 1;
}
__inline ar_rpc_sink_buffer_t* ar_alg_get_img(int fd)
{
	return 0;
}
__inline int ar_alg_release_img(int fd, ar_rpc_sink_buffer_t *buf_info)
{
	return 0;
}
__inline void ar_alg_close_video_stream(int fd)
{
	return ;
}
#else
/**
* @brief    open device to get yuv data
* @param  video_name device name,  video_name is "/dev/video_yuv-0" or "/dev/video_yuv-1"
* @return  integer.
*              0 is error,
*              others is ok.
* @note null.
*/
int ar_alg_open_video_stream(char *video_name);

/**
* @brief  acquire yuv buffer 
* @param  fd device handler
* @return  yuv buffer information struct pointer.
*              Null is error,
*              not null is ok.
* @note null.
*/
ar_rpc_sink_buffer_t* ar_alg_get_img(int fd);
/**
* @brief  release yuv buffer 
* @param  fd device handler
* @param  buf_info yuv buffer information struct
* @return  integer.
*              0 is ok,
*              other is error.
* @note null.
*/
int ar_alg_release_img(int fd, ar_rpc_sink_buffer_t *buf_info);
/**
* @brief  open device about geting freeRtos info
* @param  void
* @return  integer fd.
*              > 0 is ok,
*              others is error.
* @note null.
*/
int ar_alg_open_time_dev();
/**
* @brief  get timestamp of freeRtos info
* @param  time_fd the fd returned by open device 
* @return  unsigned integer.
*              > 0 is ok,
*              0 is error.
* @note null.
*/
uint32_t ar_alg_get_sys_time(int time_fd);
/**
* @brief  close getting yuv data device 
* @param  fd device handler
* @return  void
* @note null.
*/
void ar_alg_close_video_stream(int fd);


#endif

#ifdef __cplusplus
}
#endif

#endif
/** @}*/
