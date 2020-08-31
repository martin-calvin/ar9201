/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: snapshot_service.c
Description: implement snapshot service
Author: ycqiu@artosyn.cn
Version: v1.0
Date:2018-10-15
History:2018-10-15 : first release sdk
*****************************************************************************/
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "ar_video_stream.h"

#define AR_SNAPSHOT_JPEG_NAME_PREFIX             "IMG"

static void usage(const char *argv0)
{
    fprintf(stderr, "Usage: %s [options]\n", argv0);
    fprintf(stderr, "Available options are\n");
    fprintf(stderr, " -d device	 Device name \n");
    fprintf(stderr, " -p path    Snapshot save path \n");
}
// snapshot service
int main(int argc, char *argv[])
{

    int opt = 0;
    char* optString = "d:p:";
    char* device_name = NULL;
    char* save_path = NULL;
    int device_fd = 0;
    void* img_buffer = NULL;
    uint32_t img_size = 0;
    char file_name[64] = {0};
    int file_fd = 0;
    int file_count = 1;
    ar_video_stream_buffer_t *buffer = NULL;
	ar_video_stream_handle_t vs_handle = NULL;
    while ((opt = getopt(argc, argv, optString)) != -1) {
        switch (opt) {
        case 'd':
            device_name = optarg;
            break;
        case 'p':
             save_path = optarg;
             break;
        case 'h':
            usage(argv[0]);
            return 0;
        default:
            fprintf(stderr, "Invalid option '-%c'\n", opt);
            usage(argv[0]);
            return -1;
        }
    }
    if((!device_name) || (!save_path)) {
        fprintf(stderr, "Invalid device name or save path\n");
        usage(argv[0]);
        return -1;
    }
    vs_handle = ar_video_stream_open(device_name);
    if (!vs_handle){
        printf("open device %s failed!\n", device_name);
        return -1;
    }
    while(1){
        buffer = NULL;
        buffer = ar_video_stream_acquire_buffer(vs_handle);
        if(!buffer){
            fprintf(stderr, "icc_proxy_rpc_to_linux_acquire_buffer get buffer failed.\n");
            return -1;
        }
        img_buffer = (void *)buffer->memory.addr;
        img_size = buffer->memory.len;
        sprintf(file_name, "%s/%s_%04d.JPG", save_path, AR_SNAPSHOT_JPEG_NAME_PREFIX, file_count);
        printf("save img %s ...\n", file_name);
        file_fd = open(file_name, O_RDWR|O_CREAT);
        if(!file_fd){
            fprintf(stderr, "open file %s failed.\n", file_name);
            return -1;
        }
        write(file_fd, img_buffer, img_size);
        fsync(file_fd);
        close(file_fd);
        file_count++;
        ar_video_stream_release_buffer(vs_handle, buffer);
    }
    /* TODO: close in signal proc */
    ar_video_stream_close(vs_handle);
}
