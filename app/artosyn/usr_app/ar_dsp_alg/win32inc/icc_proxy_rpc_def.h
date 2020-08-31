#ifndef ICC_PROXY_RPC_DEF_H
#define ICC_PROXY_RPC_DEF_H

#include <stdint.h>
#include <fcntl.h>
#include <sys/types.h>
#include "v4ar_dev.h"
#include "ion.h"

#define ICC_PROXY_MAX_NUM 16
#define ICC_PROXY_TO_LINUX_MEM_NUM_MAX 3

struct buf_info {
    uint32_t addr;
    uint32_t len;
};

//to freertos
struct ion_info {
    uint32_t ion_fd;
    uint32_t ion_map_fd;
    ion_user_handle_t handle;
    unsigned char *p_map;
    uint32_t va;
    uint32_t pa;
    uint32_t alloc_len;
    uint32_t buf_size;
    uint32_t buf_num;
    uint32_t valid_buf_index;
}__attribute__((__packed__));

struct icc_proxy_rpc_element {
    uint32_t fd;
    struct ion_info ion;
    v4ar_buffer_t v4_buf;
    uint32_t is_valid;
}__attribute__((__packed__));

struct icc_proxy_rpc_info {
    uint32_t nr;
    struct icc_proxy_rpc_element icc_proxy_set[ICC_PROXY_MAX_NUM];
}__attribute__((__packed__));


//to linux
struct buf_info_to_linux {
    uint32_t pa;
    uint32_t len;
    uint32_t offset;
    uint32_t map_addr;
    uint32_t map_size;
};

struct icc_proxy_rpc_to_linux_element_t{
    uint32_t fd;
    uint32_t frame_id;
    uint32_t pts;
    uint32_t duration;/* us */
    uint32_t mem_num;
    struct buf_info_to_linux mem_info[ICC_PROXY_TO_LINUX_MEM_NUM_MAX];
    uint32_t buffer_addr;
    v4ar_private_buffer_info_t private_data_info;
	v4ar_buffer_t v4ar_data_info;
}__attribute__((__packed__));

#endif
