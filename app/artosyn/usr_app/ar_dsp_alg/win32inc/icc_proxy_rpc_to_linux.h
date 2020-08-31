/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: icc_proxy_rpc_to_linux.h
Description: define rpc structure and apis in linux
Author: lqfeng@artosyn.cn
Version: v1.0
Date:2018-05-22
History:2018-05-22 : first release sdk
*****************************************************************************/
#ifndef ICC_PROXY_RPC_TO_LINUX_H
#define ICC_PROXY_RPC_TO_LINUX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "ar_system.h"
#include "icc_proxy_rpc_def.h"
#include "icc_proxy_rpc_sink_data_type_define.h"

int32_t icc_proxy_rpc_give_cmd(int32_t fd, int32_t ctrl_code, void* param, int send_len, int receive_len);
int icc_proxy_rpc_to_linux_open_dev(const char *name);
int icc_proxy_rpc_to_linux_get_format(int fd,
                                                  ar_rpc_sink_get_format_t* format);

int icc_proxy_rpc_to_linux_acquire_buffer(int fd,
                                                  struct icc_proxy_rpc_to_linux_element_t *buffer_info);
int icc_proxy_rpc_to_linux_acquire_buffer_with_align_size(int fd, \
                                                  uint32_t min_align_size,
                                                  struct icc_proxy_rpc_to_linux_element_t *buffer_info);
int icc_proxy_rpc_to_linux_release_buffer(int fd,
                                                 struct icc_proxy_rpc_to_linux_element_t *usr_buffer);
int icc_proxy_rpc_to_linux_exit(int usr_fd);

#ifdef __cplusplus
}
#endif

#endif
