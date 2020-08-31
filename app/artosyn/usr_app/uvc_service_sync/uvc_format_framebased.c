#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "uvc_service_sync.h"
#include "pipeline_service.h"
#include "ar_video_codec.h"
#include "ar_log.h"

static int uvc_h264_deinit(uvc_server_t * server_l, uvc_format_data_t *data, ar_mm_handle_t handle);

static int uvc_h264_init(uvc_server_t * server_l, uvc_format_data_t *data, ar_mm_handle_t handle, int argc, char *argv[])
{
    ar_video_stream_handle_t uvc_h264_vs_handle = NULL;
    char                path[128]       = {""};
    int                 time_out        = 0;
    int                 ret             = -1;
    struct framebased_priv_data   *priv_data  = NULL;

    if(NULL == data || NULL != data->vs_handle)
    {
        log_err("param check error!\n");
        return -1;
    }

    ar_uvc_init(server_l, server_l->handle, argc, argv);

    while(*(server_l->run_flag))
    {
        sprintf(path, __UVC_SINK_PATH__, server_l->pipe_index);
        uvc_h264_vs_handle = ar_video_stream_open(path);
        if (!uvc_h264_vs_handle)
        {
            log_err("pid %d open %s failed!\n", getpid(), path);
            usleep(10 * 1000);
            time_out++;
            if(time_out > 500)
            {
                log_err("pid %d open %s failed! 5s exit the uvc\n", getpid(), path);
                goto H264_INIT_FAILED;
            }
        }
        else
        {
            break;
        }
    }

    data->vs_handle = uvc_h264_vs_handle;

    ret = ar_video_stream_set_min_align_size(data->vs_handle, MAX_BUFFER_SIZE);
    if(ret != 0)
    {
        log_err("pid %d set ar_video_stream min align failed!\n", getpid());
        goto H264_INIT_FAILED;
    }

    priv_data = (struct framebased_priv_data *)malloc(sizeof(struct framebased_priv_data));
    if(NULL == priv_data)
    {
        log_err("framebased_priv_data malloc failed!\n");
        goto H264_INIT_FAILED;
    }

    memset(priv_data, 0, sizeof(struct framebased_priv_data));

    data->priv = priv_data;

    return 0;

H264_INIT_FAILED:
    uvc_h264_deinit(server_l, data, handle);

    return -1;
}

static int uvc_h264_deinit(uvc_server_t * server_l, uvc_format_data_t *data, ar_mm_handle_t handle)
{
    ar_video_stream_handle_t        uvc_h264_vs_handle  = NULL;

    if(NULL == data || NULL == data->vs_handle || NULL == data->priv)
    {
        log_err("param check error!\n");
        return -1;
    }

    free(data->priv);
    data->priv = NULL;

    uvc_h264_vs_handle = (ar_video_stream_handle_t)data->vs_handle;
    ar_video_stream_close(uvc_h264_vs_handle);
    data->vs_handle = NULL;

    ar_uvc_deinit(server_l, server_l->handle);

    return 0;
}

static struct uvc_frame_buf_info * uvc_h264_get_frame(uvc_server_t * server_l, uvc_format_data_t *data)
{
    struct uvc_frame_buf_info       *buf_info           = NULL;
    ar_video_stream_buffer_t        *stream_buf_info    = NULL;
    struct framebased_priv_data     *priv_data          = NULL;

    if(NULL == data || NULL == data->vs_handle || NULL == data->priv)
    {
        log_err("param check error!\n");
        return NULL;
    }

    priv_data = (struct framebased_priv_data *)data->priv;
    if(priv_data->i_frame_for_start < __MAX_I_FRAME_FOR_H264_START__)
    {
        ar_vcodec_handle_t          vcodec_handle   = NULL;
        char                        codec_path[256];

        ++priv_data->i_frame_for_start;
        //printf("request i frame %d\n", priv_data->i_frame_for_start);

        sprintf(codec_path, "/dev/%s", server_l->context->avc_enc.object_name);

        vcodec_handle = ar_video_codec_open(codec_path);

        ar_video_encoder_request_idr(vcodec_handle);

        ar_video_codec_close(vcodec_handle);
    }

    buf_info = (struct uvc_frame_buf_info *)malloc(sizeof(struct uvc_frame_buf_info));
    if(NULL == buf_info)
    {
        return NULL;
    }

    stream_buf_info = ar_video_stream_acquire_buffer(data->vs_handle);
    if(NULL == stream_buf_info)
    {
        return NULL;
    }

    buf_info->addr = stream_buf_info->memory.addr;
    buf_info->len = stream_buf_info->memory.len;
    buf_info->ptr = stream_buf_info;

    return buf_info;
}

static int uvc_h264_release_frame(uvc_server_t * server_l, uvc_format_data_t *data, struct uvc_frame_buf_info * buf_info)
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

struct uvc_format_opt uvc_h264_opt =
{
    .format_init = uvc_h264_init,
    .format_deinit = uvc_h264_deinit,
    .get_frame = uvc_h264_get_frame,
    .release_frame = uvc_h264_release_frame,
};

/*uvc_format_data_t uvc_h264_data =
{
    .vs_handle = NULL,
    .format_opt = &uvc_h264_opt,
};*/

static struct uvc_frame_buf_info * uvc_h265_get_frame(uvc_server_t * server_l, uvc_format_data_t *data)
{
    struct uvc_frame_buf_info       *buf_info           = NULL;
    ar_video_stream_buffer_t        *stream_buf_info    = NULL;
    struct framebased_priv_data     *priv_data          = NULL;

    if(NULL == data || NULL == data->vs_handle || NULL == data->priv)
    {
        log_err("param check error!\n");
        return NULL;
    }

    priv_data = (struct framebased_priv_data *)data->priv;
    if(priv_data->i_frame_for_start < __MAX_I_FRAME_FOR_H265_START__)
    {
        ar_vcodec_handle_t          vcodec_handle   = NULL;
        char                        codec_path[256];

        ++priv_data->i_frame_for_start;
        //printf("request i frame %d\n", priv_data->i_frame_for_start);

        sprintf(codec_path, "/dev/%s", server_l->context->hevc_enc.object_name);

        vcodec_handle = ar_video_codec_open(codec_path);

        ar_video_encoder_request_idr(vcodec_handle);

        ar_video_codec_close(vcodec_handle);
    }

    buf_info = (struct uvc_frame_buf_info *)malloc(sizeof(struct uvc_frame_buf_info));
    if(NULL == buf_info)
    {
        return NULL;
    }

    stream_buf_info = ar_video_stream_acquire_buffer(data->vs_handle);
    if(NULL == stream_buf_info)
    {
        return NULL;
    }

    buf_info->addr = stream_buf_info->memory.addr;
    buf_info->len = stream_buf_info->memory.len;
    buf_info->ptr = stream_buf_info;

    return buf_info;
}

struct uvc_format_opt uvc_h265_opt =
{
    .format_init = uvc_h264_init,
    .format_deinit = uvc_h264_deinit,
    .get_frame = uvc_h265_get_frame,
    .release_frame = uvc_h264_release_frame,
};

/*uvc_format_data_t uvc_h265_data =
{
    .vs_handle = NULL,
    .format_opt = &uvc_h265_opt,
};*/

