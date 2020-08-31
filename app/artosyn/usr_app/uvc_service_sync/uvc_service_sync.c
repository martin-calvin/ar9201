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

#include "uvc_service_sync.h"
#include "pipeline_service.h"
#include "uvc_configfs.h"
#include "uvc_function.h"

extern server_api_ops_t api_ops;

unsigned int g_run_flag = 0;
pthread_mutex_t g_chg_fmt_mutex;

//capture exit signal
static void sighandler(int signo)
{
    if (signo == SIGINT || signo == SIGQUIT || signo == SIGKILL || signo == SIGTERM)
    {
        g_run_flag = 0;
        log_err("uvc gadget exit\n");
    }
}

//help function
static void usage(const char *argv0)
{
    fprintf(stderr, "Usage: %s [options]\n", argv0);
    fprintf(stderr, "Available options are\n");
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

//open device
static struct uvc_device * uvc_open(uvc_server_t *server_l , const char *devname, int fps)
{
    struct uvc_device *dev;
    struct v4l2_capability cap;
    int ret;
    int fd = -1;

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
    dev->fcc = server_l->uvc_formats[0].fcc;
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
static void image_load(uvc_server_t *server_l, struct uvc_device *dev, const char *img)
{
    int fd = -1;

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
void *get_uvc_video_form_uvc_sink_master(void * para)
{
    uvc_server_t                    *server_l               = NULL;
    uvc_server_t                    *change_fmt_l           = NULL;
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
    int                             i = 0;

    if(NULL == para)
    {
        log_err("param check error!\n");
        return NULL;
    }

    server_l = (uvc_server_t *)para;

    while(*(server_l->run_flag))
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
                }while(!server_l->handle && count > 0 && *(server_l->run_flag));

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
                }while(lancher_fd < 0 && count > 0 && *(server_l->run_flag));

                if(lancher_fd < 0)
                {
                    log_err("can not open lancher try 500 times dur 5s,exit the app, please checkout your frame work !!!!");
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }


                ar_lancher_creat_app(lancher_fd,"jpeg_service");
                ar_lancher_close(lancher_fd);

                if(NULL == server_l->uvc_formats[server_l->dev->fcc_index].data || NULL == server_l->uvc_formats[server_l->dev->fcc_index].data->format_opt)
                {
                    log_err("uvc_formats get error!\n");
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                if(server_l->uvc_formats[server_l->dev->fcc_index].data->format_opt->format_init(server_l,
                                                            server_l->uvc_formats[0].data,
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

                ar_cam_get_3a_info(server_l->dev->camera_fd, &info);
                server_l->dev->camera_terminal.exposure_time_absolute_val       = info.aec_info.exp_time_us * 10000;//server_l->CT_BRIGHTNESS_DEFAULT_VAL;
                server_l->dev->camera_terminal.auto_exposure_aec_info           = info.aec_info;

                FD_ZERO(&fds);
                FD_SET(server_l->dev->fd, &fds);

                server_l->status = UVC_STATUS_RELEASE_FRAME;
                break;

            case UVC_STATUS_RELEASE_FRAME:

                tmp_index   = server_l->idx % BUFFER_COUNT;
                fcc_index   = server_l->dev->fcc_index;
                format_opt  = server_l->uvc_formats[fcc_index].data->format_opt;

                if(NULL != buf_info[tmp_index])
                {
                    if(format_opt->release_frame(server_l, server_l->uvc_formats[fcc_index].data, buf_info[tmp_index]))
                    {
                        log_err("release buffer fail!! %s line:%d\n", __func__, __LINE__);
                        server_l->status = UVC_STATUS_EXIT;
                        break;
                    }

                    buf_info[tmp_index] = NULL;
                }

                if(UVC_CHG_FMT_CHANGE == server_l->g_chg_fmt_flag)
                {
                    server_l->status = UVC_STATUS_STOP;
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
                format_opt  = server_l->uvc_formats[fcc_index].data->format_opt;

                buf_info[tmp_index] = format_opt->get_frame(server_l, server_l->uvc_formats[fcc_index].data);
                if(!buf_info[tmp_index])
                {
                    log_err("get buffer fail!! %s line:%d\n", __func__, __LINE__);
                }
                else
                {
                    if (buf_info[tmp_index]->len > MAX_BUFFER_SIZE)
                    {
                        log_info("error package length over max buffer size %d bytes(%d bytes)\n", MAX_BUFFER_SIZE, buf_info[tmp_index]->len);
                        ret = uvc_video_send(server_l, server_l->dev, (void *)buf_info[tmp_index]->addr, MAX_BUFFER_SIZE, fds, tv);
                    }
                    else
                    {
                        ret = uvc_video_send(server_l, server_l->dev, (void *)buf_info[tmp_index]->addr, buf_info[tmp_index]->len, fds, tv);
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

                if(UVC_CHG_FMT_CHANGE == server_l->g_chg_fmt_flag)
                {
                    server_l->status = UVC_STATUS_STOP;
                }
                else
                {
                    server_l->status = UVC_STATUS_RELEASE_FRAME;
                }

                break;

            case UVC_STATUS_STOP:

                //waiting all slave pause
                i = 0;
                while(*(server_l->run_flag) && server_l->slave_num)
                {
                    if(UVC_STATUS_PAUSE == server_l->slave[i]->status)
                        ++i;

                    if(i >= server_l->slave_num)
                        break;

                    usleep(1000);
                }

                uvc_pipeline_set_stop(server_l);

                server_l->status = UVC_STATUS_CHANGE_FORMAT;

                break;

            case UVC_STATUS_CHANGE_FORMAT:

                change_fmt_l = server_l->chg_fmt_server;
                if(change_fmt_l->dev->new_fcc != change_fmt_l->dev->fcc)
                {
                    printf("release buffer!\n");

                    //release frame
                    fcc_index   = change_fmt_l->dev->fcc_index;
                    format_opt  = change_fmt_l->uvc_formats[fcc_index].data->format_opt;
                    for(i = 0; i < BUFFER_COUNT; ++i)
                    {
                        if(NULL != buf_info[i])
                        {
                            if(format_opt->release_frame(change_fmt_l, change_fmt_l->uvc_formats[fcc_index].data, buf_info[i]))
                            {
                                log_err("release buffer fail!! %s line:%d\n", __func__, __LINE__);
                            }
                            buf_info[i] = NULL;
                        }
                    }
                }

                uvc_pipeline_set_format(change_fmt_l, change_fmt_l->dev->width, change_fmt_l->dev->height, 10000000/change_fmt_l->dev->frame_interval, change_fmt_l->dev->new_fcc);

                uvc_video_set_format(change_fmt_l, change_fmt_l->dev);

                server_l->status = UVC_STATUS_START;

                break;

            case UVC_STATUS_START:

                uvc_pipeline_set_start(server_l);

                server_l->g_chg_fmt_flag = UVC_CHG_FMT_IDLE;
                for(i = 0; i < server_l->slave_num; ++i)
                {
                    server_l->slave[i]->g_chg_fmt_flag = UVC_CHG_FMT_IDLE;
                }

                server_l->chg_fmt_server = NULL;

                pthread_mutex_unlock(server_l->p_chg_fmt_mutex);//release lock

                server_l->status = UVC_STATUS_RELEASE_FRAME;

                break;

            case UVC_STATUS_EXIT:
            case UVC_STATUS_MAX:
            default:

                while(NULL != buf_info[server_l->idx % BUFFER_COUNT])
                {
                    struct uvc_format_opt * format_opt;
                    unsigned int            fcc_index;

                    fcc_index   = server_l->dev->fcc_index;
                    format_opt  = server_l->uvc_formats[fcc_index].data->format_opt;

                    if(format_opt->release_frame(server_l, server_l->uvc_formats[fcc_index].data, buf_info[server_l->idx % BUFFER_COUNT]))
                    {
                        log_err("release buffer fail!! %s line:%d\n", __func__, __LINE__);
                        break;
                    }

                    buf_info[server_l->idx % BUFFER_COUNT] = NULL;

                    server_l->idx++;
                }

                if(*(server_l->run_flag))
                    *(server_l->run_flag) = 0;

                break;
        }
    }

    log_err("%s exit!\n", __func__);

    return NULL;
}

void *get_uvc_video_form_uvc_sink_slave(void * para)
{
    uvc_server_t                    *server_l               = NULL;
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

    if(NULL == para)
    {
        log_err("param check error!\n");
        return NULL;
    }

    server_l = (uvc_server_t *)para;

    while(*(server_l->run_flag))
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
                }while(!server_l->handle && count > 0 && *(server_l->run_flag));

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
                }while(lancher_fd < 0 && count > 0 && *(server_l->run_flag));

                if(lancher_fd < 0)
                {
                    log_err("can not open lancher try 500 times dur 5s,exit the app, please checkout your frame work !!!!");
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }


                ar_lancher_creat_app(lancher_fd,"jpeg_service");
                ar_lancher_close(lancher_fd);

                if(NULL == server_l->uvc_formats[server_l->dev->fcc_index].data || NULL == server_l->uvc_formats[server_l->dev->fcc_index].data->format_opt)
                {
                    log_err("uvc_formats get error!\n");
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                if(server_l->uvc_formats[server_l->dev->fcc_index].data->format_opt->format_init(server_l,
                                                            server_l->uvc_formats[0].data,
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

                ar_cam_get_3a_info(server_l->dev->camera_fd, &info);
                server_l->dev->camera_terminal.exposure_time_absolute_val       = info.aec_info.exp_time_us * 10000;//server_l->CT_BRIGHTNESS_DEFAULT_VAL;
                server_l->dev->camera_terminal.auto_exposure_aec_info           = info.aec_info;

                FD_ZERO(&fds);
                FD_SET(server_l->dev->fd, &fds);

                server_l->status = UVC_STATUS_RELEASE_FRAME;
                break;

            case UVC_STATUS_RELEASE_FRAME:

                tmp_index   = server_l->idx % BUFFER_COUNT;
                fcc_index   = server_l->dev->fcc_index;
                format_opt  = server_l->uvc_formats[fcc_index].data->format_opt;

                if(NULL != buf_info[tmp_index])
                {
                    if(format_opt->release_frame(server_l, server_l->uvc_formats[fcc_index].data, buf_info[tmp_index]))
                    {
                        log_err("release buffer fail!! %s line:%d\n", __func__, __LINE__);
                        server_l->status = UVC_STATUS_EXIT;
                        break;
                    }

                    buf_info[tmp_index] = NULL;
                }

                if(UVC_CHG_FMT_CHANGE == server_l->g_chg_fmt_flag)
                {
                    server_l->status = UVC_STATUS_PAUSE;
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
                format_opt  = server_l->uvc_formats[fcc_index].data->format_opt;

                buf_info[tmp_index] = format_opt->get_frame(server_l, server_l->uvc_formats[fcc_index].data);
                if(!buf_info[tmp_index])
                {
                    log_err("get buffer fail!! %s line:%d\n", __func__, __LINE__);
                }
                else
                {
                    if (buf_info[tmp_index]->len > MAX_BUFFER_SIZE)
                    {
                        log_info("error package length over max buffer size %d bytes(%d bytes)\n", MAX_BUFFER_SIZE, buf_info[tmp_index]->len);
                        ret = uvc_video_send(server_l, server_l->dev, (void *)buf_info[tmp_index]->addr, MAX_BUFFER_SIZE, fds, tv);
                    }
                    else
                    {
                        ret = uvc_video_send(server_l, server_l->dev, (void *)buf_info[tmp_index]->addr, buf_info[tmp_index]->len, fds, tv);
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

                if(UVC_CHG_FMT_CHANGE == server_l->g_chg_fmt_flag)
                {
                    server_l->status = UVC_STATUS_PAUSE;
                }
                else
                {
                    server_l->status = UVC_STATUS_RELEASE_FRAME;
                }

                break;

            case UVC_STATUS_PAUSE:

                //check master status
                printf("slave paused!\n");
                while(*(server_l->run_flag) && UVC_CHG_FMT_IDLE != server_l->g_chg_fmt_flag)
                {
                    usleep(1000);
                }
                server_l->status = UVC_STATUS_RELEASE_FRAME;

                break;

            case UVC_STATUS_EXIT:
            case UVC_STATUS_MAX:
            default:

                while(NULL != buf_info[server_l->idx % BUFFER_COUNT])
                {
                    struct uvc_format_opt * format_opt;
                    unsigned int            fcc_index;

                    fcc_index   = server_l->dev->fcc_index;
                    format_opt  = server_l->uvc_formats[fcc_index].data->format_opt;

                    if(format_opt->release_frame(server_l, server_l->uvc_formats[fcc_index].data, buf_info[server_l->idx % BUFFER_COUNT]))
                    {
                        log_err("release buffer fail!! %s line:%d\n", __func__, __LINE__);
                        break;
                    }

                    buf_info[server_l->idx % BUFFER_COUNT] = NULL;

                    server_l->idx++;
                }

                if(*(server_l->run_flag))
                    *(server_l->run_flag) = 0;

                break;
        }
    }

    log_err("%s exit!\n", __func__);

    return NULL;
}

void * get_ceva_data_form_user(void * para)
{
    size_t                  i           = 0;
    uvc_server_t           *server_l    = NULL;
    fd_set                  fds;
    struct timeval          tv;
    struct timespec         timeout;

    void                    * ceva_buf_info[__IPC_CEVA_BUF_NUM__] = {0};

    if(NULL == para)
    {
        log_err("param check error!\n");
        return NULL;
    }

    server_l = (uvc_server_t *)para;

    FD_ZERO(&fds);
    FD_SET(server_l->dev->fd, &fds);

    while(*(server_l->run_flag))
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
            if (phead.lenght > MAX_BUFFER_SIZE)
            {
                log_info("error ceva package length over max buffer size %d bytes(%d bytes)\n", MAX_BUFFER_SIZE, phead.lenght);
                uvc_video_send(server_l, server_l->dev, ceva_buf_info[tmp_index], MAX_BUFFER_SIZE, fds, tv);
            }
            else
            {
                uvc_video_send(server_l, server_l->dev, ceva_buf_info[tmp_index], phead.lenght, fds, tv);
            }
        }
        else
        {
            //usleep(10000);
            continue;
        }

        ++i;
    }

    if(1 == *(server_l->run_flag))
        *(server_l->run_flag) = 0;

    log_err("%s exit!\n", __func__);
    return NULL;
}

void * get_log_data_form_user(void * para)
{
    size_t                  i = 0;
    fd_set                  fds;
    struct timeval          tv;
    struct timespec         timeout;
    uvc_server_t           *server_l = NULL;
    void                   *log_buf_info[__IPC_CEVA_BUF_NUM__] = {0};

    if(NULL == para)
    {
        log_err("param check error!\n");
        return NULL;
    }

    server_l = (uvc_server_t *)para;

    FD_ZERO(&fds);
    FD_SET(server_l->dev->fd, &fds);

    while(*(server_l->run_flag))
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
                uvc_video_send(server_l, server_l->dev, log_buf_info[tmp_index], MAX_BUFFER_SIZE, fds, tv);
            }
            else
            {
                uvc_video_send(server_l, server_l->dev, log_buf_info[tmp_index], phead.lenght, fds, tv);
            }
        }
        else
        {
            //usleep(10000);
            continue;
        }

        ++i;
    }

    if(1 == *(server_l->run_flag))
        *(server_l->run_flag) = 0;

    log_err("%s exit!\n", __func__);
    return NULL;
}


static void * start_uvc_trans_master(void * para)
{
    uvc_server_t       *server_l        = NULL;
    int                 argc;
    char              **argv;
    int                 i, j;
    int                 index           = 0;
    int                 cdns_mode       = 0;
    char                namebuf[32]     = {""};
    char               *device          = NULL;
    char               *mjpeg_image     = NULL;
    int                 ret             = 0;
    int                 fd, len;
    fd_set              fds;
    struct timeval      tv;
    pthread_t           thread_getbuf;
    pthread_t           thread_getcave;
    pthread_t           thread_getlog;
    char                path[128]       = {""};

    if(NULL == para)
    {
        log_err("server is NULL!\n");
        return NULL;
    }

    server_l = (uvc_server_t *)para;

    argc = server_l->argc;
    argv = server_l->argv;

    pthread_mutex_init(&server_l->g_wrt_com_mutex, NULL);

    //create uvc formate
    server_l->uvc_formats_num = getConfigfsFormat(&server_l->uvc_formats, server_l->pipe_index);
    if(server_l->uvc_formats_num < 0)
    {
        printf("UVC configfs info get failed!\n");
        return NULL;
    }

    printf("***********************uvc_formats_num: %d***********************\n", server_l->uvc_formats_num);
    for(i = 0; i < server_l->uvc_formats_num; ++i)
    {
        char * p = (char *)&(server_l->uvc_formats[i].fcc);
        printf("format: %c%c%c%c\n", p[0], p[1], p[2], p[3]);
        j = 0;
        for(j = 0; 0 != server_l->uvc_formats[i].frames[j].height; ++j)
        {
            int k;
            printf("    %d. %d * %d:\n", j, server_l->uvc_formats[i].frames[j].width, server_l->uvc_formats[i].frames[j].height);
            printf("        interval: ");
            for(k = 0; k < 8; ++k)
            {
                printf("%d ", server_l->uvc_formats[i].frames[j].intervals[k]);
            }
            printf("\n");
        }
    }
    printf("*****************************************************************\n");

    if(getConfigfsUDCName(namebuf, 32) < 0)
    {
        printf("USB gadget UDC get failed!\n");
        return NULL;
    }
    else
    {
        if(0 == strncmp(namebuf, "60300000", strlen("60300000")))
        {
            cdns_mode = 1;
        }
    }

    //IPC_KEY check, create IPC service only in master
    if(__IPC_CEVA_KEY__ < __IPC_LOG_KEY__)
    {
        if(__IPC_CEVA_KEY__ + (server_l->pipe_index + 1) * __IPC_CEVA_BUF_NUM__ > __IPC_LOG_KEY__)
        {
            log_err("IPC_KEY overlap\n");
            return NULL;
        }
    }
    else
    {
        if(__IPC_LOG_KEY__ + (server_l->pipe_index + 1) * __IPC_LOG_BUF_NUM__ > __IPC_CEVA_KEY__)
        {
            log_err("IPC_KEY overlap\n");
            return NULL;;
        }
    }

    ret = user_data_shr_mem_create(__IPC_CEVA_KEY__ + server_l->pipe_index  * __IPC_CEVA_BUF_NUM__, MAX_BUFFER_SIZE, __IPC_CEVA_BUF_NUM__, &server_l->trans_ceva_id);
    if(ret < 0)
    {
        log_err("share memory create failed!\n");
    }

    ret = user_data_shr_mem_create(__IPC_LOG_KEY__ + server_l->pipe_index  * __IPC_LOG_BUF_NUM__, MAX_BUFFER_SIZE, __IPC_LOG_BUF_NUM__, &server_l->trans_log_id);
    if(ret < 0)
    {
        log_err("share memory create failed!\n");
    }

    //default master uvc parameter
    server_l->width[0]  = 1920;
    server_l->height[0] = 1080;
    server_l->width[1]  = 640;
    server_l->height[1] = 480;
    server_l->fps       = 30;
    server_l->disp_w    = 1920;
    server_l->disp_h    = 1080;
    server_l->fix_fps   = 60;

    //get param
    index = find_pra_index_by_name("--res0", argc, argv);
    {
        server_l->width[0] = atoi(argv[index + 1]);
        server_l->height[0] = atoi(argv[index + 2]);
    }

    index = find_pra_index_by_name("--res1", argc, argv);
    {
        server_l->width[1] = atoi(argv[index + 1]);
        server_l->height[1] = atoi(argv[index + 2]);
    }

    index = find_pra_index_by_name("--fps", argc, argv);
    if(index > 0)
    {
        server_l->fps = atoi(argv[index+1]);
    }

    index = find_pra_index_by_name("--multi", argc, argv);
    if(index > 0)
    {
        server_l->multi = 1;
    }

    index = find_pra_index_by_name("--hdr", argc, argv);
    if(index > 0)
    {
        server_l->is_hdr = 1;
    }

    index = find_pra_index_by_name("--osd", argc, argv);
    if(index > 0)
    {
        server_l->osd = 1;
    }

    index = find_pra_index_by_name("--display", argc, argv);
    if(index > 0)
    {
        server_l->use_display = 1;
        index=find_pra_index_by_name("-w", argc, argv);
        if(index > 0)
        {
            server_l->disp_w = atoi(argv[index + 1]);
        }
        index=find_pra_index_by_name("-h", argc, argv);
        if(index > 0)
        {
            server_l->disp_h = atoi(argv[index + 1]);
        }
        index=find_pra_index_by_name("-fix_fps", argc, argv);
        if(index > 0)
        {
            server_l->fix_fps = atoi(argv[index + 1]);
        }
    }

    index = find_pra_index_by_name("--raw_debug", argc, argv);
    if(index > 0)
    {
        server_l->force_isp_ddr_mode = 1;
    }

    index = find_pra_index_by_name("--err_proc", argc, argv);
    if(index > 0)
    {
        server_l->err_process = 1;
    }

    index = find_pra_index_by_name("-i", argc, argv);
    if(index > 0)
    {
        mjpeg_image = argv[index+1];
    }

    ar_uvc_get_context((void**)&server_l->context, &server_l->context_size, server_l);
    log_always("pipe_index=%d", server_l->pipe_index);
    sprintf(namebuf, "uvcserver%d", server_l->pipe_index);
    server_l->context->server_l =
        creat_pipeline_clt_server(namebuf, &api_ops, server_l);

    //if no appointed device auto find a usb gadget webcamera(output)
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
             sprintf(device, "/dev/video%d", i + server_l->pipe_index);
             break;
        }
    }

    //find device open it or exit
    if(NULL != device)
    {
        server_l->dev = uvc_open(server_l, device, server_l->fps);
        if (server_l->dev == NULL)
        {
            log_err("video device open failed!\n");
            goto auto_find_fail;
        }
    }
    else
    {
        log_err("auto find video device failed!\n");
        goto auto_find_fail;
    }

    server_l->dev->bulk = 0;
    server_l->dev->control_interface = 0;
    server_l->dev->streaming_interface = 1;

    if((server_l->dev->control_interface = getCtrlInterfaceNum(server_l->pipe_index)) < 0)
    {
        log_err("auto get control interface failed!\n");
        goto auto_find_fail;
    }
    else
    {
        log_info("pid %d get control bInterfaceNumber success(%d)!\n", getpid(), server_l->dev->control_interface);
    }

    if((server_l->dev->streaming_interface = getStreamInterfaceNum(server_l->pipe_index)) < 0)
    {
        log_err("auto get stream interface failed!\n");
        goto auto_find_fail;
    }
    else
    {
        log_info("pid %d get streaming bInterfaceNumber success(%d)!\n", getpid(), server_l->dev->streaming_interface);
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

    //init uvc
    uvc_events_init(server_l, server_l->dev);
    uvc_video_init(server_l, server_l->dev);

    //if want output mjpeg image, load image
    if(NULL != mjpeg_image)
    {
        image_load(server_l, server_l->dev, mjpeg_image);
    }
    else
    {
        /* avoid broken frame in plugin */
        server_l->first_image_size = MAX_BUFFER_SIZE / (1024 * 16);
        server_l->first_image_data = (void *)malloc(MAX_BUFFER_SIZE * sizeof(char));
        memset(server_l->first_image_data, 0x0, MAX_BUFFER_SIZE);

        server_l->status = UVC_STATUS_IDLE;

        pthread_create(&thread_getbuf, NULL, (void *)get_uvc_video_form_uvc_sink_master, (void *)server_l);
    }

    pthread_create(&thread_getcave, NULL, (void *)get_ceva_data_form_user, (void *)server_l);
    pthread_create(&thread_getlog, NULL, (void *)get_log_data_form_user, (void *)server_l);

    //uvc contorl loop
    FD_ZERO(&fds);
    FD_SET(server_l->dev->fd, &fds);

    while (*(server_l->run_flag))
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
                uvc_events_process(server_l, server_l->dev);
            if (NULL != mjpeg_image && 1 == server_l->g_stream_on && FD_ISSET(server_l->dev->fd, &wfds))
            {
                //usleep(30000);
                uvc_video_process(server_l, server_l->dev);
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

    ar_video_stream_close(server_l->uvc_formats[server_l->dev->fcc_index].data->vs_handle);

    uvc_close(server_l->dev);

    freeConfigfsFormat(&server_l->uvc_formats, server_l->uvc_formats_num);

    free(device);

    return NULL;
}


static void * start_uvc_trans_slave(void * para)

{
    uvc_server_t       *server_l        = NULL;
    int                 argc;
    char              **argv;
    int                 i, j;
    int                 index           = 0;
    int                 cdns_mode       = 0;
    char                namebuf[32]     = {""};
    char               *device          = NULL;
    char               *mjpeg_image     = NULL;
    int                 ret             = 0;
    int                 fd, len;
    fd_set              fds;
    struct timeval      tv;
    pthread_t           thread_getbuf;
    char                path[128]       = {""};

    if(NULL == para)
    {
        log_err("server is NULL!\n");
        return NULL;
    }

    server_l = (uvc_server_t *)para;

    argc = server_l->argc;
    argv = server_l->argv;

    pthread_mutex_init(&server_l->g_wrt_com_mutex, NULL);

    //create uvc formate
    server_l->uvc_formats_num = getConfigfsFormat(&server_l->uvc_formats, server_l->pipe_index);
    if(server_l->uvc_formats_num < 0)
    {
        printf("UVC configfs info get failed!\n");
        return NULL;
    }

    printf("***********************uvc_formats_num: %d***********************\n", server_l->uvc_formats_num);
    for(i = 0; i < server_l->uvc_formats_num; ++i)
    {
        char * p = (char *)&(server_l->uvc_formats[i].fcc);
        printf("format: %c%c%c%c\n", p[0], p[1], p[2], p[3]);
        j = 0;
        for(j = 0; 0 != server_l->uvc_formats[i].frames[j].height; ++j)
        {
            int k;
            printf("    %d. %d * %d:\n", j, server_l->uvc_formats[i].frames[j].width, server_l->uvc_formats[i].frames[j].height);
            printf("        interval: ");
            for(k = 0; k < 8; ++k)
            {
                printf("%d ", server_l->uvc_formats[i].frames[j].intervals[k]);
            }
            printf("\n");
        }
    }
    printf("*****************************************************************\n");

    if(getConfigfsUDCName(namebuf, 32) < 0)
    {
        printf("USB gadget UDC get failed!\n");
        return NULL;
    }
    else
    {
        if(0 == strncmp(namebuf, "60300000", strlen("60300000")))
        {
            cdns_mode = 1;
        }
    }

    //default master uvc parameter
    server_l->width[0]  = 1920;
    server_l->height[0] = 1080;
    server_l->width[1]  = 640;
    server_l->height[1] = 480;
    server_l->fps       = 30;
    server_l->disp_w    = 1920;
    server_l->disp_h    = 1080;
    server_l->fix_fps   = 60;

    //get param
    sprintf(namebuf, "--res0_%d", server_l->pipe_index);
    index = find_pra_index_by_name(namebuf, argc, argv);
    {
        server_l->width[0] = atoi(argv[index + 1]);
        server_l->height[0] = atoi(argv[index + 2]);
    }

    sprintf(namebuf, "--res1_%d", server_l->pipe_index);
    index = find_pra_index_by_name(namebuf, argc, argv);
    {
        server_l->width[1] = atoi(argv[index + 1]);
        server_l->height[1] = atoi(argv[index + 2]);
    }

    sprintf(namebuf, "--fps_%d", server_l->pipe_index);
    index = find_pra_index_by_name(namebuf, argc, argv);
    if(index > 0)
    {
        server_l->fps = atoi(argv[index+1]);
    }

    sprintf(namebuf, "--multi_%d", server_l->pipe_index);
    index = find_pra_index_by_name(namebuf, argc, argv);
    if(index > 0)
    {
        server_l->multi = 1;
    }

    sprintf(namebuf, "--hdr_%d", server_l->pipe_index);
    index = find_pra_index_by_name(namebuf, argc, argv);
    if(index > 0)
    {
        server_l->is_hdr = 1;
    }

    sprintf(namebuf, "--osd_%d", server_l->pipe_index);
    index = find_pra_index_by_name(namebuf, argc, argv);
    if(index > 0)
    {
        server_l->osd = 1;
    }

    sprintf(namebuf, "--display_%d", server_l->pipe_index);
    index = find_pra_index_by_name(namebuf, argc, argv);
    if(index > 0)
    {
        server_l->use_display = 1;
        sprintf(namebuf, "-w_%d", server_l->pipe_index);
        index=find_pra_index_by_name(namebuf, argc, argv);
        if(index > 0)
        {
            server_l->disp_w = atoi(argv[index + 1]);
        }

        sprintf(namebuf, "-h_%d", server_l->pipe_index);
        index=find_pra_index_by_name(namebuf, argc, argv);
        if(index > 0)
        {
            server_l->disp_h = atoi(argv[index + 1]);
        }

        sprintf(namebuf, "-fix_fps_%d", server_l->pipe_index);
        index=find_pra_index_by_name(namebuf, argc, argv);
        if(index > 0)
        {
            server_l->fix_fps = atoi(argv[index + 1]);
        }
    }

    sprintf(namebuf, "--raw_debug_%d", server_l->pipe_index);
    index = find_pra_index_by_name(namebuf, argc, argv);
    if(index > 0)
    {
        server_l->force_isp_ddr_mode = 1;
    }

    sprintf(namebuf, "--err_proc_%d", server_l->pipe_index);
    index = find_pra_index_by_name(namebuf, argc, argv);
    if(index > 0)
    {
        server_l->err_process = 1;
    }

    index = find_pra_index_by_name("-i", argc, argv);
    if(index > 0)
    {
        mjpeg_image = argv[index+1];
    }

    ar_uvc_get_context((void**)&server_l->context, &server_l->context_size, server_l);
    log_always("pipe_index=%d", server_l->pipe_index);
    sprintf(namebuf, "uvcserver%d", server_l->pipe_index);
    server_l->context->server_l =
        creat_pipeline_clt_server(namebuf, &api_ops, server_l);

    //if no appointed device auto find a usb gadget webcamera(output)
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
             sprintf(device, "/dev/video%d", i + server_l->pipe_index);
             break;
        }
    }

    //find device open it or exit
    if(NULL != device)
    {
        server_l->dev = uvc_open(server_l, device, server_l->fps);
        if (server_l->dev == NULL)
        {
            log_err("video device open failed!\n");
            goto auto_find_fail;
        }
    }
    else
    {
        log_err("auto find video device failed!\n");
        goto auto_find_fail;
    }

    server_l->dev->bulk = 0;
    server_l->dev->control_interface = 0;
    server_l->dev->streaming_interface = 1;

    if((server_l->dev->control_interface = getCtrlInterfaceNum(server_l->pipe_index)) < 0)
    {
        log_err("auto get control interface failed!\n");
        goto auto_find_fail;
    }
    else
    {
        log_info("pid %d get control bInterfaceNumber success(%d)!\n", getpid(), server_l->dev->control_interface);
    }

    if((server_l->dev->streaming_interface = getStreamInterfaceNum(server_l->pipe_index)) < 0)
    {
        log_err("auto get stream interface failed!\n");
        goto auto_find_fail;
    }
    else
    {
        log_info("pid %d get streaming bInterfaceNumber success(%d)!\n", getpid(), server_l->dev->streaming_interface);
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

    //init uvc
    uvc_events_init(server_l, server_l->dev);
    uvc_video_init(server_l, server_l->dev);

    //if want output mjpeg image, load image
    if(NULL != mjpeg_image)
    {
        image_load(server_l, server_l->dev, mjpeg_image);
    }
    else
    {
        /* avoid broken frame in plugin */
        server_l->first_image_size = MAX_BUFFER_SIZE / (1024 * 16);
        server_l->first_image_data = (void *)malloc(MAX_BUFFER_SIZE * sizeof(char));
        memset(server_l->first_image_data, 0x0, MAX_BUFFER_SIZE);

        server_l->status = UVC_STATUS_IDLE;

        pthread_create(&thread_getbuf, NULL, (void *)get_uvc_video_form_uvc_sink_slave, (void *)server_l);
    }

    //uvc contorl loop
    FD_ZERO(&fds);
    FD_SET(server_l->dev->fd, &fds);

    while (*(server_l->run_flag))
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
                uvc_events_process(server_l, server_l->dev);
            if (NULL != mjpeg_image && 1 == server_l->g_stream_on && FD_ISSET(server_l->dev->fd, &wfds))
            {
                //usleep(30000);
                uvc_video_process(server_l, server_l->dev);
            }
        }
    }

    //wait thread stop
    if(NULL == mjpeg_image)
    {
        pthread_join(thread_getbuf, NULL);
    }

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

    ar_video_stream_close(server_l->uvc_formats[server_l->dev->fcc_index].data->vs_handle);

    uvc_close(server_l->dev);

    freeConfigfsFormat(&server_l->uvc_formats, server_l->uvc_formats_num);

    free(device);

    return NULL;
}


int main(int argc, char *argv[])
{
    struct sigaction    action;
    uvc_server_t        uvc_master;
    int                 index       = 0;
    int                 i;
    uvc_server_t      **uvc_slave = NULL;
    pthread_t          *slave_thread_id;
    int                 slave_num   = 0;

    //char                name[64]    = {0};

    g_run_flag                      = 1;

    action.sa_flags                 = 0;
    action.sa_handler               = sighandler;

    sigaction(SIGINT, &action, NULL);
    sigaction(SIGQUIT, &action, NULL);
    sigaction(SIGKILL, &action, NULL);
    sigaction(SIGTERM, &action, NULL);

    index = find_pra_index_by_name("--help", argc, argv);
    if(index > 0)
    {
        log_printf("--help:show this help");
        log_printf("--master_index [idx]: register master and pipeline index for master");
        log_printf("--slave_index_N [idx]: register slave and pipeline index for slave");
        log_printf("--fps(_N) [fps]: set start fps of src,eg --fps 25 (N is pipeline index num N >= 1 --fps: master --fps_1: slave using pipeline 1)\n");
        log_printf("--hdr(_N) : start with hdr mode (N is pipeline index num N >= 1 --hdr: master --hdr_1: slave using pipeline 1)\n");
        log_printf("--res0(_N) [w] [h] \n");
        log_printf("--res1(_N) [w] [h] \n");
        log_printf("--face_stats : sart with face software stats\n");
        log_printf("--tee_copy [pad_num] [buffer_count} eg: --tee_copy 0 5 \n");
        log_printf("--display -w [1920] -h [1080] -fix_fps \n");
        log_printf("--raw_debug : set the app can to dump raw img use cmd line \n");
        log_printf("--err_proc: open the restart function when no sensor out \n");
        usage(argv[0]);
        return 0;
    }

    //init common
    memset(&uvc_master, 0, sizeof(uvc_server_t));
    uvc_master.pipe_line_fd    = -1;
    uvc_master.run_flag        = &g_run_flag;
    uvc_master.argc            = argc;
    uvc_master.argv            = argv;
    uvc_master.pipe_index      = 0;
    uvc_master.hw_sync         = 1; // force hardware sync

    //all master and slaves use same g_chg_fmt_mutex
    pthread_mutex_init(&g_chg_fmt_mutex, NULL);

    uvc_master.p_chg_fmt_mutex = &g_chg_fmt_mutex;

    //get master pipeline index
    index = find_pra_index_by_name("--master_index", argc, argv);
    if(index > 0)
    {
        uvc_master.pipe_index = atoi(argv[index + 1]);
    }

    //get slave num
    for (i = 0; i < CAM_NUM_MAX; i++)
    {
        char option_name[32] = {""};

        sprintf(option_name, "--slave_index_%d", i);
        index = find_pra_index_by_name(option_name, argc, argv);
    	if(index <= 0)
    	{
            break;
    	}
        ++slave_num;
    }

    if(slave_num > 0)
    {
        //create slaves
        uvc_slave = (uvc_server_t **)calloc(slave_num, sizeof(uvc_server_t *));
        slave_thread_id = (pthread_t *)calloc(slave_num, sizeof(pthread_t));

        //create slave threads
        for (i = 0; i < slave_num; i++)
        {
            char option_name[32] = {""};

            sprintf(option_name, "--slave_index_%d", i);
            index = find_pra_index_by_name(option_name, argc, argv);
        	if(index > 0)
        	{
        	    uvc_slave[i] = (uvc_server_t *)calloc(1, sizeof(uvc_server_t));
                memcpy(uvc_slave[i], &uvc_master, sizeof(uvc_server_t));
                uvc_slave[i]->pipe_index    = atoi(argv[index + 1]);
                uvc_slave[i]->master        = &uvc_master;

                pthread_create(&slave_thread_id[i], NULL, (void *)start_uvc_trans_slave, (void *)uvc_slave[i]);
        	}
            else
            {
                log_err("fail find uvc slave %d pipeline index\n", i);
                return -1;
            }
        }

        uvc_master.slave = uvc_slave;
        uvc_master.slave_num = slave_num;
    }

    i = 0;
    while(*(uvc_master.run_flag) && uvc_master.slave_num)
    {
        if(UVC_STATUS_INIT < uvc_master.slave[i]->status)
            ++i;

        if(i >= uvc_master.slave_num)
            break;

        usleep(1000);
    }

    //begin master process
    start_uvc_trans_master(&uvc_master);
    free(uvc_master.context);

    //waiting all slave
    for(i = 0; i < slave_num; ++i)
    {
        pthread_join(slave_thread_id[i], NULL);
        free(uvc_slave[i]->context);
        free(uvc_slave[i]);
    }

    //free all slave resource
    if(slave_num > 0)
    {
        free(slave_thread_id);
        free(uvc_slave);
    }

    return 0;
}

