#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ar_video_codec.h"
#include "uvc_service2.h"
#include "pipeline_service.h"
#include "ar_log.h"

static int uvc_mjpeg_deinit(uvc_format_data_t *data, ar_mm_handle_t handle);

static int uvc_mjpeg_init(uvc_format_data_t *data, ar_mm_handle_t handle, int argc, char *argv[])
{
    ar_video_stream_handle_t uvc_mjpeg_vs_handle = NULL;
    char                path[128]       = {""};
    uvc_server_t       *server_l        = get_uvc_server();
    int                 time_out        = 0;
    int                 ret             = -1;

    if(NULL == data || NULL != data->vs_handle)
    {
        return -1;
    }

    ar_uvc_init(server_l->handle, argc, argv);

    while(server_l->run_flag)
    {
        sprintf(path, __UVC_SINK_PATH__, server_l->pipe_index);
        uvc_mjpeg_vs_handle = ar_video_stream_open(path);
        if (!uvc_mjpeg_vs_handle)
        {
            log_err("pid %d open %s failed!\n", getpid(), path);
            usleep(10 * 1000);
            time_out++;
            if(time_out > 500)
            {
                log_err("pid %d open %s failed! 5s exit the uvc\n", getpid(), path);
                goto MJPEG_INIT_FAILED;
            }
        }
        else
        {
            break;
        }
    }

    data->vs_handle = uvc_mjpeg_vs_handle;

    ret = ar_video_stream_set_min_align_size(data->vs_handle, MAX_BUFFER_SIZE);
    if(ret != 0)
    {
        log_err("pid %d set ar_video_stream min align failed!\n", getpid());
        goto MJPEG_INIT_FAILED;
    }

    return 0;

MJPEG_INIT_FAILED:
    uvc_mjpeg_deinit(data, handle);

    return -1;
}

static int uvc_mjpeg_deinit(uvc_format_data_t *data, ar_mm_handle_t handle)
{
    ar_video_stream_handle_t uvc_mjpeg_vs_handle = NULL;
    uvc_server_t       *server_l        = get_uvc_server();

    if(NULL == data || NULL == data->vs_handle)
    {
        log_err("param check error!\n");
        return -1;
    }

    uvc_mjpeg_vs_handle = (ar_video_stream_handle_t)data->vs_handle;
    ar_video_stream_close(uvc_mjpeg_vs_handle);
    data->vs_handle = NULL;

    ar_uvc_deinit(server_l->handle);

    return 0;
}

static struct uvc_frame_buf_info * uvc_mjpeg_get_frame(uvc_format_data_t *data)
{
    struct uvc_frame_buf_info   * buf_info = NULL;
    ar_video_stream_buffer_t    * stream_buf_info = NULL;

    if(NULL == data || NULL == data->vs_handle)
    {
        log_err("uvc_format_data is NULL\n");
        return NULL;
    }

    buf_info = (struct uvc_frame_buf_info *)malloc(sizeof(struct uvc_frame_buf_info));
    if(NULL == buf_info)
    {
        return NULL;
    }

    stream_buf_info = ar_video_stream_acquire_buffer(data->vs_handle);
    if(NULL == stream_buf_info)
    {
        goto FAILED;
    }

    buf_info->addr = stream_buf_info->memory.addr;
    buf_info->len = stream_buf_info->memory.len;
    buf_info->ptr = stream_buf_info;
    buf_info->pts = stream_buf_info->pts;

    return buf_info;

FAILED:
    free(buf_info);

    return NULL;
}

static int uvc_mjpeg_release_frame(uvc_format_data_t *data, struct uvc_frame_buf_info * buf_info)
{
    int ret = -1;

    if(NULL == data || NULL == data->vs_handle || NULL == buf_info || NULL == buf_info->ptr)
    {
        log_err("param check error!\n");
        return ret;
    }

    if(ar_video_stream_release_buffer((ar_video_stream_handle_t)data->vs_handle,
                                       (ar_video_stream_buffer_t *)buf_info->ptr))
    {
        log_err("release buffer fail!! %s line:%d\n", __func__, __LINE__);
    }
    else
    {
        ret = 0;
    }

    free(buf_info);

    return ret;
}

static struct uvc_format_opt uvc_mjpeg_opt =
{
    .format_init = uvc_mjpeg_init,
    .format_deinit = uvc_mjpeg_deinit,
    .get_frame = uvc_mjpeg_get_frame,
    .release_frame = uvc_mjpeg_release_frame,
};

uvc_format_data_t uvc_mjpeg_data =
{
    .vs_handle = NULL,
    .format_opt = &uvc_mjpeg_opt,
};


