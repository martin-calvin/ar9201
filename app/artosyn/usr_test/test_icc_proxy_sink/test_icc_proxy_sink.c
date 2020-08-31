#define _GNU_SOURCE
#include <fcntl.h>
//#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <sched.h>

#include "ar_get_freeRtos_sys_info.h"
#include "ar_picture_common_api.h"
#include "ar_video_stream.h"
#include "ar_img_api.h"

#define AR_PICTURE_COMMON_API_TEST 0

#define SAVE_YUV_DATA_FRAME_NUM 10
#define DATA_SIZE 1024*1024*20 
static unsigned int data_size = 0;
static int yuv_0_cnt = 0;
static int yuv_1_cnt = 0;


typedef struct {
    int id;
    char name[64];
} icc_proxy_sink_test_t;

void save_yuv_thread(icc_proxy_sink_test_t *sink_info)
{
    void *buf;
    size_t ret;
    int cnt = 0, index;
    int fp, data_len;
    ar_picture_handle img_handle = NULL;
    ar_picture_buffer_t *picture_buffer = NULL;
    ar_rpc_sink_buffer_t *alg_buffer = NULL;
    void *buffer = NULL;
    int fd = -1;
    char file_name[64];
    if(!sink_info){
        printf("name is null, line:%d\n", __LINE__);
        return;
    }
    printf("sink_id:%d, name:%s line:%d\n", sink_info->id, sink_info->name, __LINE__);
    if(AR_PICTURE_COMMON_API_TEST){
        img_handle = ar_picture_open(sink_info->name);
        if(!img_handle){
            printf("open %s failed!\n", sink_info->name);
            return;
        }
        printf("start picture common api, line:%d\n", __LINE__);
    }else{
        fd = ar_alg_open_video_stream(sink_info->name);
        if(fd < 0){
            printf("open %s failed!\n", sink_info->name);
            return;
        }
        printf("start alg api, line:%d\n", __LINE__);
    }
    while(1){
        picture_buffer = NULL;
        alg_buffer = NULL;
        if(AR_PICTURE_COMMON_API_TEST){
            picture_buffer = ar_picture_get_img(img_handle);
            if(!picture_buffer){
                printf("get buffer fail!! %s line:%d\n", __func__, __LINE__);
                return;
            }
        }else{
            alg_buffer = ar_alg_get_img(fd);
            if(!alg_buffer){
                printf("get buffer fail!! %s line:%d\n", __func__, __LINE__);
                return;
            }
        }
        
        //handle private thing
#if 1
        memset(file_name, 0, 64);
        if(sink_info->id == 0){
            sprintf(file_name, "yuv0_%d", yuv_0_cnt);
            yuv_0_cnt++;
            cnt = yuv_0_cnt;
        }else{
            sprintf(file_name, "yuv1_%d", yuv_1_cnt);
            yuv_1_cnt++;
            cnt = yuv_1_cnt;
        }
#if 0
        printf("%s idx:%d  frame_id:%d check private_buffer format:%d width:%d height:%d fps_num:%d fps_den:%d luma_stride:%d chroma_stride:%d is_interlace:%d\n",
               file_name, 
               cnt, 
               buffer->frame_id,
               buffer->format.format,
               buffer->format.width,
               buffer->format.height,
               buffer->format.fps_num,
               buffer->format.fps_den,
               buffer->format.luma_stride,
               buffer->format.chroma_stride,
               buffer->format.is_interlace);
#endif
        fp = open(file_name, O_RDWR|O_CREAT);
        if(!fp){
            printf("open file fail!!  %s line:%d\n", __func__, __LINE__);
            return;
        }
        //printf("mem_num------>:%d   line:%d\n", buffer.mem_num, __LINE__);
        for(index = 0; index < 3; index++){
            if(AR_PICTURE_COMMON_API_TEST){
                if(index == 0)
                    data_len = (picture_buffer->format.luma_stride) * (picture_buffer->format.height);
                else
                    data_len = ((picture_buffer->format.chroma_stride) * (picture_buffer->format.height))/2;
                buf = (void *)picture_buffer->mem[index].addr;
            }else{
                if(index == 0)
                    data_len = (alg_buffer->format.luma_stride) * (alg_buffer->format.height);
                else
                    data_len = ((alg_buffer->format.chroma_stride) * (alg_buffer->format.height))/2;
                buf = (void *)alg_buffer->mem[index].addr;
            }
            ret = write(fp, buf, data_len);
            if(ret != data_len)
                printf("index:%d data_len:%d  ret_len:%d line:%d\n", index, data_len, ret, __LINE__);
        }
#endif
        if(AR_PICTURE_COMMON_API_TEST)
            ret = ar_picture_release_img(img_handle, picture_buffer);
        else
            ret = ar_alg_release_img(fd, alg_buffer);
        if(ret){
            printf("release buffer fail!! %s line:%d\n", __func__, __LINE__);
            return;
        }
        fsync(fp);
        close(fp);
        if(cnt == SAVE_YUV_DATA_FRAME_NUM){
            printf("get data over!!  %s line:%d\n", __func__, __LINE__);
            return;
        }
    }
}

void save_yuv_app()
{
    pthread_t thread[2];
    pthread_attr_t attr1, attr2;
    cpu_set_t cpu_info;
    static icc_proxy_sink_test_t sink_test0 = {0};
    static icc_proxy_sink_test_t sink_test1 = {0};
    memcpy(sink_test0.name, "/dev/video_yuv-0", sizeof("/dev/video_yuv-0"));
    sink_test0.id = 0;
    memcpy(sink_test1.name, "/dev/video_yuv-1", sizeof("/dev/video_yuv-1"));
    sink_test1.id = 1;  
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    CPU_ZERO(&cpu_info);
    CPU_SET(0, &cpu_info);
    //init arrt used in pthread
    if(0 != pthread_attr_setaffinity_np(&attr1, sizeof(cpu_set_t), &cpu_info))
    {
        printf("Set thread 1 affinity failed!\n");
        return;
    }
    if(0 != pthread_attr_setaffinity_np(&attr2, sizeof(cpu_set_t), &cpu_info))
    {
        printf("Set thread 2 affinity failed!\n");
        return;
    }
    if(0 != pthread_create(&thread[0], &attr1, save_yuv_thread, &sink_test0))
    {
        printf("Create thread %d failed!\n", 0);
        return;
    }
    if(0 != pthread_create(&thread[1], &attr2, save_yuv_thread, &sink_test1))
    {
        printf("Create thread %d failed!\n", 1);
        return;
    }
}

void save_data_app()
{
    void *buf;
    uint32_t data_len;
    int fd = -1, index;
    size_t ret;
    ar_video_stream_buffer_t *buffer = NULL;
    ar_video_stream_handle_t vs_handle = NULL;
    vs_handle = ar_video_stream_open("/dev/uvc_sink");
    if (!vs_handle){
        printf("open /dev/uvc_sink failed!\n");
        return;
    }
    int fp = open("rpc.bin", O_RDWR|O_CREAT);
    if(!fp){
        printf("open file fail!!  %s line:%d\n", __func__, __LINE__);
        return;
    }
    while(1){
        buffer = NULL;
        buffer = ar_video_stream_acquire_buffer(vs_handle);
        if(!buffer){
            printf("get buffer fail!! %s line:%d\n", __func__, __LINE__);
            return;
        }
    
        //handle private thing
#if 1
        data_len = buffer->memory.len;
        buf = (void *)buffer->memory.addr;
        #if 1
        data_size += data_len;
        if(data_size > DATA_SIZE){
            printf("get data over!!  %s line:%d\n", __func__, __LINE__);
            ar_video_stream_release_buffer(vs_handle, buffer);
            fsync(fp);
            close(fp);
            return;
        }
        ret = write(fp, buf, data_len);
        #else
        usleep(1000*10);
        #endif
        //uint8_t* ptr = buf;
        //printf("pa:0x%x len %u %x %x %x %x %x %x \n", buf.addr, buf.len, *(ptr), *(ptr++), *(ptr++), *(ptr++), *(ptr++), *(ptr++));
#endif
        if(ar_video_stream_release_buffer(vs_handle, buffer)){
            printf("release buffer fail!! %s line:%d\n", __func__, __LINE__);
            return;
        }
    }
}

#define GET_SYN_TIME_CNT_MAX 100
int get_sys_time_test()
{
    int index = 0, fd = -1;
    unsigned int time_stamp = 0, new_time = 0;
    int aver = 0;
    
#if 1
    fd = ar_alg_open_time_dev();
    if (fd < 0){
            printf("open failed! func:%s  line:%d  erron:%d str(err):%s\n",
                    __func__, 
                    __LINE__, 
                    errno,
                    strerror(errno));
    }
    for(index = 0; index < GET_SYN_TIME_CNT_MAX; index++){
        time_stamp = ar_alg_get_sys_time(fd);
        printf("time_stamp:0x%x\n", time_stamp);
        usleep(10000);
    }
    //printf("aver time:0x%x\n", aver/(GET_SYN_TIME_CNT_MAX - 1));
#else
    //test linux and freeRtos tick is same ?
    if(ar_get_freeRtos_sys_info_time_sync()){
        printf("syn time error, line:%d func:%s\n", __LINE__, __func__);
        return -1;
    }

    fd = open("/dev/sys_info", O_RDWR);
    if (fd < 0){
            printf("open failed! func:%s  line:%d  erron:%d str(err):%s\n",
                    __func__, 
                    __LINE__, 
                    errno,
                    strerror(errno));
    }
    unsigned int time_stamp_1 = 0, new_time_1 = 0;
    time_stamp = ar_get_freeRtos_sys_info_get_time(fd);
    new_time = ar_get_freeRtos_sys_info_timestamp();
    for(index = 0; index < (100*60)*5; index++)
        usleep(10000);
    time_stamp_1 = ar_get_freeRtos_sys_info_get_time(fd);
    new_time_1 = ar_get_freeRtos_sys_info_timestamp();
    printf("before  time_stamp:0x%x new_time:0x%x\n", time_stamp, new_time);
    printf("after  time_stamp_1:0x%x new_time_1:0x%x\n", time_stamp_1, new_time_1);
#endif
    return 0;
}
void test_nonblocking_api()
{
    void *buf;
    uint32_t data_len;
    int fd = -1, index;
    size_t ret;
    ar_video_stream_buffer_t *buffer = NULL;
    ar_video_stream_handle_t vs_handle = NULL;
    vs_handle = ar_video_stream_open("/dev/icc_proxy_rpc_sink-0");
    if (!vs_handle){
        printf("open /dev//dev/icc_proxy_rpc_sink-0 failed!\n");
        return;
    }
    int fp = open("rpc.bin", O_RDWR|O_CREAT);
    if(!fp){
        printf("open file fail!!  %s line:%d\n", __func__, __LINE__);
        return;
    }
    while(1){
        buffer = NULL;
        buffer = ar_video_stream_acquire_buffer_nonblocking(vs_handle);
        if(!buffer){
            printf("get buffer fail!! %s line:%d\n", __func__, __LINE__);
            usleep(5000);
            continue;
        }
    
        //handle private thing
#if 1
        data_len = buffer->memory.len;
        buf = (void *)buffer->memory.addr;
        #if 1
        data_size += data_len;
        if(data_size > DATA_SIZE){
            printf("get data over!!  %s line:%d\n", __func__, __LINE__);
            ar_video_stream_release_buffer(vs_handle, buffer);
            fsync(fp);
            close(fp);
            return;
        }
        ret = write(fp, buf, data_len);
        #else
        usleep(1000*10);
        #endif
        //uint8_t* ptr = buf;
        //printf("pa:0x%x len %u %x %x %x %x %x %x \n", buf.addr, buf.len, *(ptr), *(ptr++), *(ptr++), *(ptr++), *(ptr++), *(ptr++));
#endif
        if(ar_video_stream_release_buffer(vs_handle, buffer)){
            printf("release buffer fail!! %s line:%d\n", __func__, __LINE__);
            return;
        }
    }
}


int main()
{
    //save_yuv_app();
    test_nonblocking_api();
    //save_data_app();
    //get_sys_time_test();
    while(1)
    {
        sleep(1);
    }
}
