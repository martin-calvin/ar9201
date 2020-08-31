#define _GNU_SOURCE
#define ENABALE_ALL_LOG
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <sched.h>
#include <linux/usb/ch9.h>
#include <linux/usb/video.h>
#include <linux/videodev2.h>
#include <linux/usb/uvc.h>
#include <pthread.h>

#include "ar_pipeline_ctrl.h"
#include "ar_system.h"

#include "ar_log.h"
#include "pipeline_ctl.h"
#include "ar_lancher.h"

#include "uvc_service2.h"
#include "pipeline_service.h"
#include "uvc_configfs.h"
#include "uvc_function.h"
#include "ar_time.h"

extern server_api_ops_t api_ops;
//static struct uvc_frame_info *uvc_frames_mjpeg;
struct uvc_format_info *uvc_formats = NULL;
int uvc_formats_num = 0;


uvc_server_t *get_uvc_server()
{
    static uvc_server_t *p_uvc_server = NULL;
    if(!p_uvc_server)
    {
        p_uvc_server=malloc(sizeof(uvc_server_t));
        memset(p_uvc_server,0,sizeof(uvc_server_t));
        p_uvc_server->pipe_line_fd = -1;
        p_uvc_server->run_flag=1;
    }
    return p_uvc_server;
}

//capture exit signal
static void sighandler(int signo)
{
    uvc_server_t *server_l = get_uvc_server();
    if (signo == SIGINT || signo == SIGQUIT || signo == SIGKILL || signo == SIGTERM)
    {
        server_l->run_flag = 0;
        log_err("uvc gadget exit\n");
    }
}

//help function
static void usage(const char *argv0)
{
    fprintf(stderr, "Usage: %s [options]\n", argv0);
    fprintf(stderr, "Available options are\n");
    fprintf(stderr, " -b            Use bulk mode\n");
    fprintf(stderr, " -d device     Video device\n");
    fprintf(stderr, " -i image      MJPEG image\n");
}

//find output device
static int uvc_dev_recognition(char* buf, int len, int mode)
{
    int i = 0, j = 0;
    char* uvc_flag = __OUTPUT_DEVICE_NAME__;

    if(1 == mode)
    {
        uvc_flag = __OUTPUT_DEVICE_NAME2__;
    }

    for(i = 0; i < strlen(__OUTPUT_DEVICE_NAME__) - 1; i++)
    {
        while(j < len && uvc_flag[i] != buf[j])
            j++;
        if(j == len)
            return -1;
    }
    return 0;
}

#if 0
static unsigned int get_frame_idx_and_size_from_bs(unsigned char *pic_ptr)
{
    unsigned int frame_idx = 0, size = 0;

    if (pic_ptr[2] == 0xFF && pic_ptr[3] == 0xE1 && pic_ptr[4] == 0x00 && pic_ptr[5] == 0x16) {
        frame_idx = (pic_ptr[10]&0xff)<<24|(pic_ptr[11]&0xff)<<16|(pic_ptr[12]&0xff)<<8|(pic_ptr[13]&0xff)<<0;
        size = *(unsigned int*)(pic_ptr+22);
        printf("frame idx[%u] = 0x%x %ubytes\n", frame_idx, size, size);
    }
    return frame_idx;
}
#endif

//open device
static struct uvc_device * uvc_open(const char *devname, int fps)
{
    struct uvc_device *dev;
    struct v4l2_capability cap;
    int ret;
    int fd = -1;
    uvc_server_t       *server_l    = get_uvc_server();

    fd = open(devname, O_RDWR | O_NONBLOCK);
    if (fd < 0) {
        log_err("v4l2 open failed: %s (%d)\n", strerror(errno), errno);
        return NULL;
    }

    log_always("open %s succeeded, file descriptor = %d\n", devname, fd);

    ret = ioctl(fd, VIDIOC_QUERYCAP, &cap);
    if (ret < 0) {
        log_err("unable to query device: %s (%d)\n", strerror(errno),
            errno);
        close(fd);
        return NULL;
    }

    log_printf("***********************Device info*********************\n");
    log_printf("device is %s on bus %s\n", cap.card, cap.bus_info);
    log_printf("device driver      : \t%s\n", cap.driver);
    log_printf("device card        : \t%s\n", cap.card);
    log_printf("device capabilities: \t0x%08x\n", cap.capabilities);
    log_printf("device device_caps : \t0x%08x\n", cap.device_caps);
    log_printf("*******************************************************\n");

    dev = malloc(sizeof *dev);
    if (dev == NULL) {
        close(fd);
        return NULL;
    }

    memset(dev, 0, sizeof *dev);
    dev->fd = fd;
    dev->width = server_l->width[0];
    dev->height = server_l->height[0];
    dev->frame_interval = (10000000 / fps);
    dev->fcc = uvc_formats[0].fcc;
    dev->fcc_index = 0;
    dev->camera_fd = -1;

    return dev;
}

static void uvc_close(struct uvc_device *dev)
{
    if(dev)
    {
       close(dev->fd);
       //free(dev->imgdata);
       free(dev->mem);
       free(dev);
    }
}

//load still image
static void image_load(struct uvc_device *dev, const char *img)
{
    int fd = -1;
    uvc_server_t *server_l=get_uvc_server();

    if (img == NULL)
        return;

    fd = open(img, O_RDONLY);
    if (fd == -1) {
        log_err("Unable to open MJPEG image '%s'\n", img);
        return;
    }

    dev->imgsize = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    dev->imgdata = malloc(MAX_BUFFER_SIZE);
    if (dev->imgdata == NULL) {
        log_err("Unable to allocate memory for MJPEG image\n");
        dev->imgsize = 0;
        return;
    }

    read(fd, dev->imgdata, dev->imgsize);
    server_l->first_image_data = dev->imgdata;
    server_l->first_image_size = dev->imgsize;
    close(fd);
}

/****************************************WORKER FUNCTION**************************************/
void *get_uvc_video_form_uvc_sink(void * para)
{
    uvc_server_t                    *server_l               = get_uvc_server();
    struct uvc_frame_buf_info       *buf_info[BUFFER_COUNT] = {0};
    int                             count                   = 500;
    int                             lancher_fd              = -1;
    char                            path[128]               = {""};
    basic_3a_info_t                 info;
    fd_set                          fds;
    struct timeval                  tv;
    unsigned int                    tmp_index, fcc_index;
    struct uvc_format_opt           *format_opt;
    int                             ret = -1;
    ar_uvc_context_t                *context = NULL;
    uint32_t                        context_size = 0;
    int                             get_frame_succ = 0;

    while(server_l->run_flag)
    {
        switch(server_l->status)
        {
            case UVC_STATUS_IDLE:
                server_l->status = UVC_STATUS_INIT;
                break;
            case UVC_STATUS_INIT:

                do{
                    usleep(10*1000);
                    server_l->handle = ar_multimedia_core_device_open();
                    count--;
                }while(!server_l->handle && count > 0 && server_l->run_flag);

                if(!server_l->handle)
                {
                    log_err("can not open multicore try 500 times dur 5s,exit the app, please checkout your frame work !!!!");
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                count       = 500;
                do{
                    lancher_fd = ar_lancher_open();
                    if(lancher_fd < 0)
                        usleep(10*1000);
                    count--;
                }while(lancher_fd < 0 && count > 0 && server_l->run_flag);

                if(lancher_fd < 0)
                {
                    log_err("can not open lancher try 500 times dur 5s,exit the app, please checkout your frame work !!!!");
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }


                ar_lancher_creat_app(lancher_fd,"jpeg_service");
                ar_lancher_close(lancher_fd);

                if(NULL == uvc_formats[server_l->dev->fcc_index].data || NULL == uvc_formats[server_l->dev->fcc_index].data->format_opt)
                {
                    log_err("uvc_formats get error!\n");
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                if(uvc_formats[server_l->dev->fcc_index].data->format_opt->format_init(
                                                            uvc_formats[0].data,
                                                            server_l->handle,
                                                            server_l->argc,
                                                            server_l->argv))
                {
                    log_err("uvc_formats init error!\n");
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                log_always("pipe_index=%d",server_l->pipe_index);
                sprintf(path,"/dev/uvc_path-%d",server_l->pipe_index);
                server_l->pipe_line_fd = ar_pipeline_ctrl_open(path);
                if(server_l->pipe_line_fd < 0)
                {
                    log_err("open pipeline error pipe_index=%d\n",server_l->pipe_index);
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                sprintf(path, "/dev/cam_src-%d", server_l->pipe_index);
                server_l->dev->camera_fd = open(path, O_RDWR | O_SYNC);
                if(server_l->dev->camera_fd < 0)
                {
                    printf("open device %s failed fd=%d\n", path, server_l->dev->camera_fd);
                    server_l->dev->camera_fd = -1;
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                FD_ZERO(&fds);
                FD_SET(server_l->dev->fd, &fds);

                server_l->status = UVC_STATUS_INIT_COMPLETE;
                break;

            case UVC_STATUS_INIT_COMPLETE:

                ar_uvc_get_context((void**)&context, &context_size);
                if(NULL != context &&
                   AR_ELEMENT_STATE_PLAYING == ar_element_get_state(server_l->handle,(ar_pipeline_t)context->pipeline.element))
                {
                    ar_cam_get_3a_info(server_l->dev->camera_fd, &info);
                    server_l->dev->camera_terminal.exposure_time_absolute_val       = info.aec_info.exp_time_us * 10000;//server_l->CT_BRIGHTNESS_DEFAULT_VAL;
                    server_l->dev->camera_terminal.auto_exposure_aec_info           = info.aec_info;
                    server_l->status = UVC_STATUS_RELEASE_FRAME;
                }
                else
                {
                    printf("init complete, wait playing state!\n");
                    usleep(1000000);
                }
                break;

            case UVC_STATUS_RELEASE_FRAME:

                tmp_index   = server_l->idx % BUFFER_COUNT;
                fcc_index   = server_l->dev->fcc_index;
                format_opt  = uvc_formats[fcc_index].data->format_opt;

                if(NULL != buf_info[tmp_index])
                {
                    if(format_opt->release_frame(uvc_formats[fcc_index].data, buf_info[tmp_index]))
                    {
                        log_err("release buffer fail!! %s line:%d\n", __func__, __LINE__);
                        server_l->status = UVC_STATUS_EXIT;
                        break;
                    }

                    buf_info[tmp_index] = NULL;
                }

                if(1 == server_l->g_chg_fmt_flag)
                {
                    server_l->status = UVC_STATUS_CHANGE_FORMAT;
                }
                else
                {
                    server_l->status = UVC_STATUS_GET_FRAME;
                }

                break;

            case UVC_STATUS_GET_FRAME:

                ret = -1;
                tv.tv_sec   = 0;
                tv.tv_usec  = 10000;

                tmp_index   = server_l->idx % BUFFER_COUNT;
                fcc_index   = server_l->dev->fcc_index;
                format_opt  = uvc_formats[fcc_index].data->format_opt;

                buf_info[tmp_index] = format_opt->get_frame(uvc_formats[fcc_index].data);
                if(!buf_info[tmp_index])
                {
                    log_err("get buffer fail!! %s line:%d\n", __func__, __LINE__);
                }
                else
                {
                    if (server_l->idx == 0 && get_frame_succ == 0)
                    {
                        log_printf("UVC get frame success\n");
                        get_frame_succ = 1;
                    }
                    if (buf_info[tmp_index]->len > MAX_BUFFER_SIZE)
                    {
                        log_info("error package length over max buffer size %u bytes(%u bytes)\n", MAX_BUFFER_SIZE, buf_info[tmp_index]->len);
                        ret = uvc_video_send(server_l->dev, (void *)buf_info[tmp_index]->addr, MAX_BUFFER_SIZE, buf_info[tmp_index]->pts, fds, tv);
                    }
                    else
                    {
                        ret = uvc_video_send(server_l->dev, (void *)buf_info[tmp_index]->addr, buf_info[tmp_index]->len, buf_info[tmp_index]->pts, fds, tv);
                    }
                }

                if(ret < 0)
                {
                    //log_err("uvc_video_send failed!\n");
                }
                else
                {
                    server_l->idx++;
                }

                if(1 == server_l->g_chg_fmt_flag)
                {
                    server_l->status = UVC_STATUS_CHANGE_FORMAT;
                }
                else
                {
                    server_l->status = UVC_STATUS_RELEASE_FRAME;
                }

                break;

            case UVC_STATUS_CHANGE_FORMAT:

                if(server_l->dev->new_fcc != server_l->dev->fcc)
                {
                    int i;

                    printf("release buffer!\n");

                    //release frame
                    fcc_index   = server_l->dev->fcc_index;
                    format_opt  = uvc_formats[fcc_index].data->format_opt;
                    for(i = 0; i < BUFFER_COUNT; ++i)
                    {
                        if(NULL != buf_info[i])
                        {
                            if(format_opt->release_frame(uvc_formats[fcc_index].data, buf_info[i]))
                            {
                                log_err("release buffer fail!! %s line:%d\n", __func__, __LINE__);
                            }
                            buf_info[i] = NULL;
                        }
                    }
                }

                uvc_pipeline_set_format(server_l->dev->width, server_l->dev->height, 10000000/server_l->dev->frame_interval, server_l->dev->new_fcc);

                uvc_video_set_format(server_l->dev);

                server_l->g_chg_fmt_flag = 0;
                sem_post(&server_l->g_chg_fmt_sem);//release lock

                server_l->status = UVC_STATUS_INIT_COMPLETE;
                break;

            case UVC_STATUS_EXIT:
            case UVC_STATUS_MAX:
            default:
                if(1 == server_l->run_flag)
                    server_l->run_flag = 0;

                break;
        }
    }

    while(NULL != buf_info[server_l->idx % BUFFER_COUNT])
    {
        struct uvc_format_opt * format_opt;
        unsigned int            fcc_index;

        fcc_index   = server_l->dev->fcc_index;
        format_opt  = uvc_formats[fcc_index].data->format_opt;

        if(format_opt->release_frame(uvc_formats[fcc_index].data, buf_info[server_l->idx % BUFFER_COUNT]))
        {
            log_err("release buffer fail!! %s line:%d\n", __func__, __LINE__);
            break;
        }

        buf_info[server_l->idx % BUFFER_COUNT] = NULL;

        server_l->idx++;
    }

    if(1 == server_l->g_chg_fmt_flag)
    {
        server_l->g_chg_fmt_flag = 0;
        sem_post(&server_l->g_chg_fmt_sem);//release lock
    }

    log_err("%s exit!\n", __func__);

    return NULL;
}

void * get_ceva_data_form_user(void * para)
{
    size_t                  i = 0;
    uvc_server_t *server_l=get_uvc_server();
    fd_set                  fds;
    struct timeval          tv;
    struct timespec         timeout;

    void                    * ceva_buf_info[__IPC_CEVA_BUF_NUM__] = {0};
    unsigned char           * ceva_data[__IPC_CEVA_BUF_NUM__] = {0};


    FD_ZERO(&fds);
    FD_SET(server_l->dev->fd, &fds);

    for(i = 0; i < __IPC_CEVA_BUF_NUM__; ++i)
    {
        ceva_data[i] = (unsigned char *)calloc(MAX_BUFFER_SIZE, sizeof(unsigned char));
        if(NULL == ceva_data[i])
        {
            log_err("ceva data buffer calloc failed!!!\n");
            return NULL;
        }
    }

    i = 0;
    while(server_l->run_flag)
    {
        unsigned int    tmp_index;
        memory_head     phead;

        tv.tv_sec   = 0;
        tv.tv_usec  = 10000;
        timeout.tv_sec = 1;
        timeout.tv_nsec = 0;

        tmp_index   = i % __IPC_CEVA_BUF_NUM__;

        if(NULL != ceva_buf_info[tmp_index])
        {
            if(user_data_shr_mem_release(&server_l->trans_ceva_id, &(ceva_buf_info[tmp_index])) < 0)
            {
                log_err("release share memory fail!! %s line:%d\n", __func__, __LINE__);
                break;
            }

            ceva_buf_info[tmp_index] = NULL;
        }


        if(user_data_shr_mem_acquire(server_l->trans_ceva_id, &(ceva_buf_info[tmp_index]), &phead, &timeout) >= 0 && phead.lenght != 0)
        {
            memcpy(ceva_data[tmp_index], ceva_buf_info[tmp_index], phead.lenght);
            if (phead.lenght > MAX_BUFFER_SIZE)
            {
                log_info("error ceva package length over max buffer size %d bytes(%d bytes)\n", MAX_BUFFER_SIZE, phead.lenght);
                uvc_video_send(server_l->dev, ceva_data[tmp_index], MAX_BUFFER_SIZE, (uint32_t)ar_get_timeofclockcount_to_ms(), fds, tv);
            }
            else
            {
                uvc_video_send(server_l->dev, ceva_data[tmp_index], phead.lenght, (uint32_t)ar_get_timeofclockcount_to_ms(), fds, tv);
            }
        }
        else
        {
            //usleep(10000);
            continue;
        }

        ++i;
    }

    for(i = 0; i < __IPC_CEVA_BUF_NUM__; ++i)
    {
        free(ceva_data[i]);
        ceva_data[i] = NULL;
    }

    if(1 == server_l->run_flag)
        server_l->run_flag = 0;

    log_err("%s exit!\n", __func__);
    return NULL;
}

void * get_log_data_form_user(void * para)
{
    size_t                  i = 0;
    fd_set                  fds;
    struct timeval          tv;
    struct timespec         timeout;
    uvc_server_t *server_l=get_uvc_server();
    void                    * log_buf_info[__IPC_CEVA_BUF_NUM__] = {0};

    FD_ZERO(&fds);
    FD_SET(server_l->dev->fd, &fds);

    while(server_l->run_flag)
    {
        unsigned int    tmp_index;
        memory_head     phead;

        tv.tv_sec   = 0;
        tv.tv_usec  = 10000;
        timeout.tv_sec = 1;
        timeout.tv_nsec = 0;

        tmp_index   = i % __IPC_CEVA_BUF_NUM__;

        if(NULL != log_buf_info[tmp_index])
        {
            if(user_data_shr_mem_release(&server_l->trans_log_id, &(log_buf_info[tmp_index])) < 0)
            {
                log_err("release share memory fail!! %s line:%d\n", __func__, __LINE__);
                break;
            }

            log_buf_info[tmp_index] = NULL;
        }

        if(user_data_shr_mem_acquire(server_l->trans_log_id, &(log_buf_info[tmp_index]), &phead, &timeout) >= 0 && phead.lenght != 0)
        {
            if (phead.lenght > MAX_BUFFER_SIZE)
            {
                printf("error ceva package length over max buffer size %d bytes(%d bytes)\n", MAX_BUFFER_SIZE, phead.lenght);
                uvc_video_send(server_l->dev, log_buf_info[tmp_index], MAX_BUFFER_SIZE, 0, fds, tv);
            }
            else
            {
                uvc_video_send(server_l->dev, log_buf_info[tmp_index], phead.lenght, 0, fds, tv);
            }
        }
        else
        {
            //usleep(10000);
            continue;
        }

        ++i;
    }

    if(1 == server_l->run_flag)
        server_l->run_flag = 0;

    log_err("%s exit!\n", __func__);
    return NULL;
}

static int start_uvc_trans(int argc, char *argv[])
{
    int                 index           = 0;
    int                 len             = 0;
    int                 i, j;
    int                 ret             = 0;
    pthread_attr_t      attr;
    //struct sched_param  param;
    char               *device          = NULL;
    int                 bulk_mode       = 0;
    char               *mjpeg_image     = NULL;
    int                 cdns_mode       = 0;
    char                namebuf[32]     = {""};
    int                 fd              = -1;
    int                 fps             = 30;
    fd_set              fds;
    struct timeval      tv;
    pthread_t           thread_getbuf;
    pthread_t           thread_getcave;
    pthread_t           thread_getlog;
    cpu_set_t           cpu_info;
    //basic_3a_info_t     info;
    char                path[128]       = {""};

    uvc_server_t       *server_l        = get_uvc_server();

    pthread_mutex_init(&server_l->g_wrt_com_mutex, NULL);
    sem_init(&server_l->g_chg_fmt_sem, 0, 1);
    pthread_attr_init(&attr);

    index=find_pra_index_by_name("-d",argc,argv);
    if(index>0)
    {
        device = argv[index+1];
    }

    index=find_pra_index_by_name("-b",argc,argv);
    if(index>0)
    {
        bulk_mode = 1;
    }

    index=find_pra_index_by_name("-i",argc,argv);
    if(index>0)
    {
        mjpeg_image = argv[index+1];
    }

    index=find_pra_index_by_name("--fps",argc,argv);
    if(index>0)
    {
        fps=atoi(argv[index+1]);
    }

    uvc_formats_num = getConfigfsFormat(&uvc_formats, server_l->dev_index);
    if(uvc_formats_num < 0)
    {
        printf("UVC configfs info get failed!\n");
        return -1;
    }

    printf("***********************uvc_formats_num: %d***********************\n", uvc_formats_num);
    for(i = 0; i < uvc_formats_num; ++i)
    {
        char * p = (char *)&(uvc_formats[i].fcc);
        printf("format: %c%c%c%c\n", p[0], p[1], p[2], p[3]);
        j = 0;
        for(j = 0; 0 != uvc_formats[i].frames[j].height; ++j)
        {
            int k;
            printf("    %d. %d * %d:\n", j, uvc_formats[i].frames[j].width, uvc_formats[i].frames[j].height);
            printf("        interval: ");
            for(k = 0; k < 8; ++k)
            {
                printf("%d ", uvc_formats[i].frames[j].intervals[k]);
            }
            printf("\n");
        }
    }
    printf("*****************************************************************\n");

    if(getConfigfsUDCName(namebuf, 32) < 0)
    {
        printf("USB gadget UDC get failed!\n");
        return -1;
    }
    else
    {
        if(0 == strncmp(namebuf, "60300000", strlen("60300000")))
        {
            cdns_mode = 1;
        }
    }

    //IPC_KEY check
    if(__IPC_CEVA_KEY__ < __IPC_LOG_KEY__)
    {
        if(__IPC_CEVA_KEY__ + (server_l->dev_index + 1) * __IPC_CEVA_BUF_NUM__ > __IPC_LOG_KEY__)
        {
            log_err("IPC_KEY overlap\n");
            return -1;
        }
    }
    else
    {
        if(__IPC_LOG_KEY__ + (server_l->dev_index + 1) * __IPC_LOG_BUF_NUM__ > __IPC_CEVA_KEY__)
        {
            log_err("IPC_KEY overlap\n");
            return -1;
        }
    }

    ret = user_data_shr_mem_create(__IPC_CEVA_KEY__ + server_l->dev_index  * __IPC_CEVA_BUF_NUM__, MAX_BUFFER_SIZE, __IPC_CEVA_BUF_NUM__, &server_l->trans_ceva_id);
    if(ret < 0)
    {
        log_err("share memory create failed!\n");
        //return -1;
    }

    ret = user_data_shr_mem_create(__IPC_LOG_KEY__ + server_l->dev_index  * __IPC_LOG_BUF_NUM__, MAX_BUFFER_SIZE, __IPC_LOG_BUF_NUM__, &server_l->trans_log_id);
    if(ret < 0)
    {
        log_err("share memory create failed!\n");
        //return -1;
    }

    //if no appointed device auto find a usb gadget webcamera(output)
    if(NULL == device)
    {
        for (i = 0; i < CAM_NUM_MAX; i++)
        {
            memset(namebuf, 0, sizeof(namebuf));
            sprintf(path, "/sys/class/video4linux/video%d/name", i);
            fd = open(path, O_RDONLY);
            if (fd < 0)
            {
                log_err("open %s failed!\n", path);
                continue;
            }
            len = read(fd, namebuf, sizeof(namebuf));
            ret = uvc_dev_recognition(namebuf, len, cdns_mode);
            if (!ret)
            {
                 device = (char *)malloc(32);
                 sprintf(device, "/dev/video%d", i + server_l->dev_index);
                 break;
            }
        }
    }

    //find device open it or exit
    if(NULL != device)
    {
        server_l->dev = uvc_open(device, fps);
        if (server_l->dev == NULL)
            return -1;
    }
    else
    {
        log_err("auto find video device failed!\n");
        goto auto_find_fail;
    }

    server_l->dev->camera_terminal.auto_exposure_mode_control       = CT_AUTO_EXPOSURE_MODE_DEFAULF_VAL;
    server_l->dev->camera_terminal.zoom_absolute_val                = CT_ZOOM_ABSOLUTE_DEFAULT_VAL;
    server_l->dev->camera_terminal.roll_absolute_val                = CT_ROLL_ABSOLUTE_DEFAULT_VAL;
    server_l->dev->processing_unit.brightness_val                   = PU_BRIGHTNESS_DEFAULT_VAL;
    server_l->dev->processing_unit.contrast_val                     = PU_CONTRAST_DEFAULT_VAL;
    server_l->dev->processing_unit.hue_val                          = PU_HUE_DEFAULT_VAL;
    server_l->dev->processing_unit.saturation_val                   = PU_SATURATION_DEFAULT_VAL;
    server_l->dev->processing_unit.sharpness_val                    = PU_SHARPNESS_DEFAULT_VAL;
    server_l->dev->processing_unit.gamma_val                        = PU_GAMMA_DEFAULT_VAL;
    server_l->dev->processing_unit.white_balance_temperature_val    = PU_WHITE_BALANCE_TEMPERATURE_DEFAULT_VAL;
    server_l->dev->processing_unit.white_balance_component_val      = 0;
    server_l->dev->processing_unit.backlight_compensation_val       = PU_BACKLIGHT_COMPENSATION_DEFAULT_VAL;
    server_l->dev->processing_unit.gain_val                         = PU_GAIN_DEFAULT_VAL;
    server_l->dev->processing_unit.power_line_frequency_val         = PU_POWER_LINE_FREQUENCY_DEFAULT_VAL;
    server_l->dev->processing_unit.hue_auto_val                     = PU_HUE_AUTO_DEFAULT_VAL;
    server_l->dev->processing_unit.white_balance_temperature_auto_val = WHITE_BALANCE_TEMPERATURE_AUTO_DEFAULT_VAL;

    server_l->dev->bulk = bulk_mode;
    server_l->dev->control_interface = 0;
    server_l->dev->streaming_interface = 1;

    if((server_l->dev->control_interface = getCtrlInterfaceNum(server_l->dev_index)) < 0)
    {
        log_err("auto get control interface failed!\n");
    }
    else
    {
        log_info("pid %d get control bInterfaceNumber success(%d)!\n", getpid(), server_l->dev->control_interface);
    }

    if((server_l->dev->streaming_interface = getStreamInterfaceNum(server_l->dev_index)) < 0)
    {
        log_err("auto get stream interface failed!\n");
    }
    else
    {
        log_info("pid %d get streaming bInterfaceNumber success(%d)!\n", getpid(), server_l->dev->streaming_interface);
    }

    index = find_pra_index_by_name("--ctl-int", argc, argv);
    if (index > 0) {
        server_l->dev->control_interface = atoi(argv[index+1]);
        log_info("pid %d over write control bInterfaceNumber with argc %d success!\n", getpid(), server_l->dev->control_interface);
    }

    index = find_pra_index_by_name("--str-int", argc, argv);
    if (index > 0) {
        server_l->dev->streaming_interface = atoi(argv[index+1]);
        log_info("pid %d over write streaming bInterfaceNumber with argc to %d success!\n", getpid(), server_l->dev->streaming_interface);
    }

    //init uvc
    uvc_events_init(server_l->dev);
    uvc_video_init(server_l->dev);

    //if want output mjpeg image, load image
    if(NULL != mjpeg_image)
    {
        image_load(server_l->dev, mjpeg_image);
    }
    else//get video data form uvc sink
    {
        /* avoid broken frame in plugin */
        server_l->first_image_size = MAX_BUFFER_SIZE / (1024 * 16);
        server_l->first_image_data = (void *)malloc(MAX_BUFFER_SIZE * sizeof(char));
        memset(server_l->first_image_data, 0x0, MAX_BUFFER_SIZE);

        server_l->status = UVC_STATUS_IDLE;

        //CPU_ZERO(&cpu_info);
        //CPU_SET(1, &cpu_info);

        if(pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &cpu_info)){
            log_err("attr fail\n");
        }

        /*param.sched_priority = 99;
        pthread_attr_setschedpolicy(&attr, SCHED_RR);
        pthread_attr_setschedparam(&attr, &param);
        pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);*/

        pthread_create(&thread_getbuf, &attr, (void *)get_uvc_video_form_uvc_sink, (void *)server_l->dev);
    }

    CPU_ZERO(&cpu_info);
    CPU_SET(2, &cpu_info);

    if(pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &cpu_info)){
            log_err("attr fail\n");
    }

    pthread_create(&thread_getcave, &attr, (void *)get_ceva_data_form_user, (void *)server_l->dev);
    pthread_create(&thread_getlog, &attr, (void *)get_log_data_form_user, (void *)server_l->dev);

    //wait to get data
    /*while(NULL == server_l->dev->imgdata || 0 == server_l->dev->imgsize)
    {
        usleep(2000);
    }*/

    //uvc contorl loop
    FD_ZERO(&fds);
    FD_SET(server_l->dev->fd, &fds);

    while (server_l->run_flag)
    {
        fd_set efds = fds;
        fd_set wfds = fds;

        /* Timeout. */
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        if(NULL != mjpeg_image)//if output still image, listen wfds and efds
            ret = select(server_l->dev->fd + 1, NULL, &wfds, &efds, &tv);
        else
            ret = select(server_l->dev->fd + 1, NULL, NULL, &efds, &tv);

        if(ret > 0)
        {
            if (FD_ISSET(server_l->dev->fd, &efds))
                uvc_events_process(server_l->dev);
            if (NULL != mjpeg_image && 1 == server_l->g_stream_on && FD_ISSET(server_l->dev->fd, &wfds))
            {
                //usleep(30000);
                uvc_video_process(server_l->dev);
            }
        }
    }

    //wait thread stop
    if(NULL == mjpeg_image)
    {
        pthread_join(thread_getbuf, NULL);
    }
    pthread_join(thread_getcave, NULL);
    pthread_join(thread_getlog, NULL);

    //clean up
    if(NULL != server_l->first_image_data)
    {
        free(server_l->first_image_data);
    }

    if(NULL != mjpeg_image && NULL != server_l->dev->imgdata)
    {
        free(server_l->dev->imgdata);
        server_l->dev->imgdata = NULL;
    }
auto_find_fail:

    user_data_shr_mem_close(server_l->trans_ceva_id);
    user_data_shr_mem_close(server_l->trans_log_id);

    ar_video_stream_close(uvc_formats[server_l->dev->fcc_index].data->vs_handle);

    uvc_close(server_l->dev);

    freeConfigfsFormat(&uvc_formats, uvc_formats_num);

    free(device);
    return 0;
}


int main(int argc, char *argv[])
{
    int                 is_uvc      = 1;
    int                 lancher_fd  = -1;
    int                 index       = 0;
    int                 count       = 50;
    struct sigaction    action;
    uvc_server_t       *server_l    = get_uvc_server();
    char                name[64]    = {0};
    char                name_path[64];

    action.sa_flags                 = 0;
    action.sa_handler               = sighandler;

    sigaction(SIGINT, &action, NULL);
    sigaction(SIGKILL, &action, NULL);
    sigaction(SIGTERM, &action, NULL);

    index = find_pra_index_by_name("--help", argc, argv);
    if(index > 0)
    {
        log_printf("--help:show this help");
        log_printf("--fps [fps]: set start fps of src,eg --fps 25 \n");
        log_printf("--hdr : start with hdr mode \n");
        log_printf("--mode [uvc/hdmi] \n");
        log_printf("--res0 [w] [h] \n");
        log_printf("--res1 [w] [h] \n");
        log_printf("--face_stats : sart with face software stats\n");
        log_printf("--tee_copy [pad_num] [buffer_count} eg: --tee_copy 0 5 \n");
        log_printf("--display -w [1920] -h [1080] -fix_fps \n");
        log_printf("--raw_debug : set the app can to dump raw img use cmd line \n");
        log_printf("--err_proc: open the restart function when no sensor out \n");
        log_printf("--hw_sync: open the hw sync of two or more sensor devices\n");
        log_printf("--pipe_index: open the index of pipeline\n");
        log_printf("--dev_index: open the index of UVC gadget\n");
        log_printf("--raw: get raw picture from camera(Z16 or yuy2)\n");
        usage(argv[0]);
        return 0;
    }

    index = find_pra_index_by_name("-i",argc,argv);
    if(index > 0)
    {
        server_l->is_uvc = 1;
        server_l->pipe_line_fd = -1;
        start_uvc_trans(argc,argv);
    }
    else
    {
        server_l->argc = argc;
        server_l->argv = argv;

        index=find_pra_index_by_name("--pipe_index",argc,argv);
        if(index>0)
        {
            server_l->pipe_index = atoi(argv[index + 1]);
        }

        index=find_pra_index_by_name("--dev_index",argc,argv);
        if(index>0)
        {
            server_l->dev_index = atoi(argv[index + 1]);
        }
        else
        {
            server_l->dev_index =server_l->pipe_index;
        }

        index=find_pra_index_by_name("--res0",argc,argv);
        server_l->width[0]  = 1920;
        server_l->height[0] = 1080;
        if(index>0)
        {
            server_l->width[0]= atoi(argv[index + 1]);
            server_l->height[0]= atoi(argv[index + 2]);
        }

        index=find_pra_index_by_name("--res1",argc,argv);
        server_l->width[1]  = 640;
        server_l->height[1] = 480;
        if(index>0)
        {
            server_l->width[1]= atoi(argv[index + 1]);
            server_l->height[1]= atoi(argv[index + 2]);
        }

        index=find_pra_index_by_name("--multi",argc,argv);
        server_l->multi=0;
        if(index>0)
        {
            server_l->multi = 1;
        }

        index=find_pra_index_by_name("--display",argc,argv);
        server_l->disp_w=1920;
        server_l->disp_h=1080;
        server_l->fix_fps=60;
        if(index>0)
        {
            server_l->use_display = 1;
            index=find_pra_index_by_name("-w",argc,argv);
            if(index>0){
                server_l->disp_w= atoi(argv[index + 1]);
            }
            index=find_pra_index_by_name("-h",argc,argv);
            if(index>0){
                server_l->disp_h= atoi(argv[index + 1]);
            }
            index=find_pra_index_by_name("-fix_fps",argc,argv);
            if(index>0){
                server_l->fix_fps= atoi(argv[index + 1]);
            }
        }

        server_l->force_isp_ddr_mode = 0;
        index=find_pra_index_by_name("--raw_debug",argc,argv);
        if(index>0)
        {
            server_l->force_isp_ddr_mode = 1;
        }

        server_l->err_process=0;
        index=find_pra_index_by_name("--err_proc",argc,argv);
        if(index>0)
        {
            server_l->err_process = 1;
        }

        server_l->hw_sync=0;
        index=find_pra_index_by_name("--hw_sync",argc,argv);
        if(index>0)
        {
            server_l->hw_sync = 1;
        }

        index=find_pra_index_by_name("--mode",argc,argv);
        if(index>0)
        {
            if(!strcmp(argv[index+1],"hdmi"))
            {
                is_uvc=0;
            }
        }

        if(is_uvc)
        {

            index=find_pra_index_by_name("--raw",argc,argv);
            if(index > 0)
            {
                server_l->is_raw = 1;
            }

            //this function will block on uvc request
            ar_uvc_context_t* context = NULL;
            uint32_t context_size = 0;

            server_l->is_uvc = 1;
            ar_uvc_get_context((void**)&context, &context_size);
            log_always("pipe_index=%d",server_l->pipe_index);
            sprintf(name,"uvcserver%d",server_l->pipe_index);
            context->server_l=creat_pipeline_clt_server(name,&api_ops,server_l);
            start_uvc_trans(argc,argv);
            //wait_pipeline_ctl_main_loop_end(context->server_l);
        }
        else
        {

            do{
                usleep(10*1000);
                server_l->handle = ar_multimedia_core_device_open();
                count--;
            }while(!server_l->handle && count > 0 && server_l->run_flag);

            if(!server_l->handle)
            {
                log_err("can not open multicore try 5000 times dur 5s,exit the app, please checkout your frame work !!!!");
                return -1;
            }

            lancher_fd = ar_lancher_open();
            ar_lancher_creat_app(lancher_fd,"jpeg_service");
            ar_lancher_close(lancher_fd);

            ar_uvc_hdmi_init(server_l->handle,argc, argv);

            log_always("pipe_index=%d",server_l->pipe_index);
            sprintf(name_path,"/dev/uvc_path-%d",server_l->pipe_index);
            server_l->pipe_line_fd = ar_pipeline_ctrl_open(name_path);
            if(server_l->pipe_line_fd < 0)
            {
                log_err("open pipeline error pipe_index=%d\n",server_l->pipe_index);
                return -1;
            }

            server_l->is_uvc=0;
            ar_uvc_hdmi_context_t* context = NULL;
            uint32_t context_size = 0;
            ar_uvc_get_context((void**)&context, &context_size);
            sprintf(name,"uvcserver%d",server_l->pipe_index);
            context->server_l=creat_pipeline_clt_server(name,&api_ops,server_l);
            //hmdi ,we block here with gdbus
            wait_pipeline_ctl_main_loop_end(context->server_l);
        }

        ar_pipeline_ctrl_close(server_l->pipe_line_fd);

    }
    return 0;
}


