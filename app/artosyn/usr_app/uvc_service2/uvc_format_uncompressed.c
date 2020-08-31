#define ENABALE_ALL_LOG

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "uvc_service2.h"
#include "pipeline_service.h"
#include "libyuv.h"
#include "ar_log.h"

struct yuv_priv_data
{
    unsigned int    index;
    unsigned char   buffer_status[BUFFER_COUNT];
    unsigned char * yuv_buffer[BUFFER_COUNT];  //存储转换后的buff,如: isp出来的i420经过各种转换成目的格式的buff
};

static int uvc_z16_deinit(uvc_format_data_t *data, ar_mm_handle_t handle);
static int uvc_z16_init(uvc_format_data_t *data, ar_mm_handle_t handle, int argc, char *argv[]);
static struct uvc_frame_buf_info * uvc_z16_get_frame(uvc_format_data_t *data);
static int uvc_z16_release_frame(uvc_format_data_t *data, struct uvc_frame_buf_info * buf_info);

static int uvc_yuy2_deinit(uvc_format_data_t *data, ar_mm_handle_t handle);

static int uvc_yuy2_init(uvc_format_data_t *data, ar_mm_handle_t handle, int argc, char *argv[])
{
    ar_picture_handle   uvc_yuy2_vs_handle = NULL;
    char                path[128]       = {""};
    uvc_server_t       *server_l        = get_uvc_server();
    int                 time_out        = 0;
    struct yuv_priv_data   *priv_data   = NULL;
    int                 i;

    if(1 == server_l->is_raw &&
        (V4L2_PIX_FMT_YUYV == server_l->dev->fcc || V4L2_PIX_FMT_Z16 == server_l->dev->fcc))
    {
        return uvc_z16_init(data, handle, argc, argv);
    }

    if(NULL == data || NULL != data->vs_handle)
    {
        log_err("param check error!\n");
        return -1;
    }

    ar_uvc_init(server_l->handle, argc, argv);

    while(server_l->run_flag)
    {
        sprintf(path, __UVC_SINK_PATH__, server_l->pipe_index);
        uvc_yuy2_vs_handle = ar_picture_open(path);
        if (!uvc_yuy2_vs_handle)
        {
            log_err("pid %d open %s failed!\n", getpid(), path);
            usleep(10 * 1000);
            time_out++;
            if(time_out > 500)
            {
                log_err("pid %d open %s failed! 5s exit the uvc\n", getpid(), path);
                goto YUY2_INIT_FAILED;
            }
        }
        else
        {
            break;
        }
    }

    data->vs_handle = uvc_yuy2_vs_handle;

    priv_data = (struct yuv_priv_data *)malloc(sizeof(struct yuv_priv_data));
    if(NULL == priv_data)
    {
        log_err("yuv priv_data malloc failed!\n");
        goto PRIV_DATA_ERROR;
    }

    memset(priv_data, 0, sizeof(struct yuv_priv_data));

    for(i = 0; i < BUFFER_COUNT; ++i)
    {
        priv_data->yuv_buffer[i] = (unsigned char *)malloc(MAX_BUFFER_SIZE * sizeof(unsigned char));
        if(NULL == priv_data->yuv_buffer[i])
        {
            log_err("yuv buffer malloc failed!\n");
            goto BUFFER_ERROR;
        }
    }

    priv_data->index = 0;
    data->priv = priv_data;

    return 0;

BUFFER_ERROR:
    for(i = 0; i < BUFFER_COUNT; ++i)
    {
        if(NULL != priv_data->yuv_buffer[i])
        {
            free(priv_data->yuv_buffer[i]);
            priv_data->yuv_buffer[i] = NULL;
        }
    }

PRIV_DATA_ERROR:
    ar_picture_close(data->vs_handle);

    data->vs_handle = NULL;

YUY2_INIT_FAILED:
    uvc_yuy2_deinit(data, handle);

    return -1;
}

static int uvc_yuy2_deinit(uvc_format_data_t *data, ar_mm_handle_t handle)
{
    ar_picture_handle   uvc_yuy2_vs_handle = NULL;
    uvc_server_t       *server_l        = get_uvc_server();
    struct yuv_priv_data   *priv_data   = NULL;
    int                 i;

    if(1 == server_l->is_raw &&
        (V4L2_PIX_FMT_YUYV == server_l->dev->fcc || V4L2_PIX_FMT_Z16 == server_l->dev->fcc))
    {
        return uvc_z16_deinit(data, handle);
    }

    if(NULL == data || NULL == data->vs_handle || NULL == data->priv)
    {
        log_err("param check error!\n");
        return -1;
    }

    uvc_yuy2_vs_handle = (ar_picture_handle)data->vs_handle;
    priv_data = (struct yuv_priv_data *)data->priv;

    for(i = 0; i < BUFFER_COUNT; ++i)
    {
        if(NULL != priv_data->yuv_buffer[i])
        {
            free(priv_data->yuv_buffer[i]);
            priv_data->yuv_buffer[i] = NULL;
        }
    }

    free(data->priv);
    data->priv = NULL;

    ar_picture_close(uvc_yuy2_vs_handle);
    data->vs_handle = NULL;

    ar_uvc_deinit(server_l->handle);

    return 0;
}

int get_free_buffer(struct yuv_priv_data * priv)
{
    int i, ret = -1;

    for(i = 0; i < BUFFER_COUNT; ++i)
    {
        if(0 == priv->buffer_status[i])
        {
            ret = i;
            priv->buffer_status[i] = 1;
            break;
        }
    }

    return ret;
}

unsigned int get_y_stride(unsigned int width)
{
    //return (width + 511) / 512 * 512;  //512对齐
    return (width + 127) / 128 * 128;  //128对齐
}

unsigned int get_u_v_stride(unsigned int width)
{
    //return (width + 255) / 256 * 256; //512对齐
    return (width + 63) / 64 * 64;    //128对齐
}

static struct uvc_frame_buf_info * uvc_yuy2_get_frame(uvc_format_data_t *data)
{
    struct uvc_frame_buf_info       *buf_info           = NULL;
    ar_picture_buffer_t             *stream_buf_info    = NULL;
    ar_video_format_info_t          format_info;
    struct yuv_priv_data            *priv_data          = NULL;
    uvc_server_t                    *server_l           = get_uvc_server();

    if(1 == server_l->is_raw &&
        (V4L2_PIX_FMT_YUYV == server_l->dev->fcc || V4L2_PIX_FMT_Z16 == server_l->dev->fcc))
    {
        return uvc_z16_get_frame(data);
    }

    if(NULL == data || NULL == data->vs_handle || NULL == data->priv)
    {
        log_err("uvc_format_data is NULL or error!\n");
        return NULL;
    }

    buf_info = (struct uvc_frame_buf_info *)malloc(sizeof(struct uvc_frame_buf_info));
    if(NULL == buf_info)
    {
        log_err("malloc buf_info failed!\n");
        return NULL;
    }

    memset(buf_info, 0, sizeof(struct uvc_frame_buf_info));
    memset(&format_info, 0 , sizeof(ar_video_format_info_t));

    stream_buf_info = ar_picture_get_img((ar_picture_handle)data->vs_handle);
    if(NULL == stream_buf_info)
    {
        log_err("ar_picture_get_img failed!\n");
        goto FAILED;
    }


    priv_data = (struct yuv_priv_data *)data->priv;

    if(-1 == (buf_info->index = get_free_buffer(priv_data)))
    {
        log_err("No free yuv buffer!\n");
        if(ar_picture_release_img(data->vs_handle, stream_buf_info))
        {
            log_err("0 YUV buffer release error!\n");
        }
        goto FAILED;
    }

    ar_picture_get_format(data->vs_handle, &format_info);
    if(0 == format_info.height || 0 == format_info.width)
    {
        log_err("YUV format error!\n");
        goto FAILED;
    }

    I420ToYUY2((const uint8_t *)(stream_buf_info->mem[0].addr), get_y_stride(format_info.width),
               (const uint8_t *)(stream_buf_info->mem[1].addr), get_u_v_stride(format_info.width / 2),
               (const uint8_t *)(stream_buf_info->mem[2].addr), get_u_v_stride(format_info.width / 2),
               priv_data->yuv_buffer[buf_info->index], format_info.width * 2, format_info.width, format_info.height);

    buf_info->addr = (unsigned int)priv_data->yuv_buffer[buf_info->index];
    buf_info->len = format_info.width * 2 * format_info.height;
    buf_info->pts = stream_buf_info->pts;

    /*printf("YUV format(0x%08x): width %d height %d fps %d/%d\n",
                format_info.format,
                format_info.width,
                format_info.height,
                format_info.fps_num,
                format_info.fps_den);*/

    if(ar_picture_release_img(data->vs_handle, stream_buf_info))
    {
        log_err("YUV buffer release error!\n");
    }

    return buf_info;

FAILED:
    free(buf_info);

    return NULL;
}

static int uvc_yuy2_release_frame(uvc_format_data_t *data, struct uvc_frame_buf_info * buf_info)
{
    struct yuv_priv_data    * priv_data = NULL;
    uvc_server_t            *server_l   = get_uvc_server();

    if(1 == server_l->is_raw &&
        (V4L2_PIX_FMT_YUYV == server_l->dev->fcc || V4L2_PIX_FMT_Z16 == server_l->dev->fcc))
    {
        return uvc_z16_release_frame(data, buf_info);
    }

    if(NULL == data || NULL == data->priv || NULL == buf_info || buf_info->index >= BUFFER_COUNT || buf_info->index < 0)
    {
        log_err("param check failed!\n");
        return -1;
    }

    priv_data = (struct yuv_priv_data *)data->priv;
    priv_data->buffer_status[buf_info->index] = 0;

    free(buf_info);

    return 0;
}

static struct uvc_format_opt uvc_yuy2_opt =
{
    .format_init = uvc_yuy2_init,
    .format_deinit = uvc_yuy2_deinit,
    .get_frame = uvc_yuy2_get_frame,
    .release_frame = uvc_yuy2_release_frame,
};

uvc_format_data_t uvc_yuy2_data =
{
    .vs_handle = NULL,
    .format_opt = &uvc_yuy2_opt,
};


static int uvc_z16_init(uvc_format_data_t *data, ar_mm_handle_t handle, int argc, char *argv[])
{
    ar_picture_handle   uvc_z16_vs_handle = NULL;
    char                path[128]       = {""};
    uvc_server_t       *server_l        = get_uvc_server();
    int                 time_out        = 0;
    int                 ret;

    if(NULL == data || NULL != data->vs_handle)
    {
        log_err("param check error!\n");
        return -1;
    }

    ar_uvc_init(server_l->handle, argc, argv);

    while(server_l->run_flag)
    {
        sprintf(path, __UVC_SINK_PATH__, server_l->pipe_index);
        uvc_z16_vs_handle = ar_picture_open(path);
        if (!uvc_z16_vs_handle)
        {
            log_err("pid %d open %s failed!\n", getpid(), path);
            usleep(10 * 1000);
            time_out++;
            if(time_out > 500)
            {
                log_err("pid %d open %s failed! 5s exit the uvc\n", getpid(), path);
                goto Z16_INIT_FAILED;
            }
        }
        else
        {
            break;
        }
    }

    data->vs_handle = uvc_z16_vs_handle;

    ret = ar_picture_set_min_align_size(data->vs_handle, MAX_BUFFER_SIZE);
    if(ret != 0)
    {
        log_err("pid %d set ar_picture min align failed!\n", getpid());
        goto Z16_INIT_FAILED;
    }
    log_always("pid %d set ar_picture min align %d success %d!\n", getpid(), MAX_BUFFER_SIZE, ret);

    return 0;

Z16_INIT_FAILED:
    uvc_z16_deinit(data, handle);

    return -1;
}

static int uvc_z16_deinit(uvc_format_data_t *data, ar_mm_handle_t handle)
{
    ar_picture_handle   uvc_z16_vs_handle = NULL;
    uvc_server_t       *server_l        = get_uvc_server();

    if(NULL == data || NULL == data->vs_handle)
    {
        log_err("param check error!\n");
        return -1;
    }

    uvc_z16_vs_handle = (ar_picture_handle)data->vs_handle;
    ar_picture_close(uvc_z16_vs_handle);
    data->vs_handle = NULL;

    ar_uvc_deinit(server_l->handle);

    return 0;
}

static struct uvc_frame_buf_info * uvc_z16_get_frame(uvc_format_data_t *data)
{
    struct uvc_frame_buf_info       *buf_info = NULL;
    ar_picture_buffer_t             *stream_buf_info = NULL;
    ar_video_format_info_t          format_info;

    if(NULL == data || NULL == data->vs_handle)
    {
        log_err("uvc_format_data is NULL or error!\n");
        return NULL;
    }

    buf_info = (struct uvc_frame_buf_info *)malloc(sizeof(struct uvc_frame_buf_info));
    if(NULL == buf_info)
    {
        log_err("malloc buf_info failed!\n");
        return NULL;
    }

    memset(buf_info, 0, sizeof(struct uvc_frame_buf_info));
    memset(&format_info, 0 , sizeof(ar_video_format_info_t));

    stream_buf_info = ar_picture_get_img(data->vs_handle);
    if(NULL == stream_buf_info)
    {
        log_err("ar_picture_get_img failed!\n");
        goto FAILED;
    }

    buf_info->addr = (unsigned int)stream_buf_info->mem[0].addr;
    buf_info->len = stream_buf_info->mem[0].len;//format_info.width * 2 * format_info.height;
    buf_info->ptr = stream_buf_info;
    buf_info->pts = stream_buf_info->pts;

    /*printf("Z16 format(0x%08x): width %d height %d fps %d/%d\n",
                format_info.format,
                format_info.width,
                format_info.height,
                format_info.fps_num,
                format_info.fps_den);*/

    return buf_info;

FAILED:
    free(buf_info);

    return NULL;
}

static int uvc_z16_release_frame(uvc_format_data_t *data, struct uvc_frame_buf_info * buf_info)
{
    if(NULL == data || NULL == data->vs_handle || NULL == buf_info || NULL == buf_info->ptr)
    {
        log_err("param check failed!\n");
        return -1;
    }

    if(ar_picture_release_img(data->vs_handle, (ar_picture_buffer_t *)buf_info->ptr))
    {
        log_err("YUV buffer release error!\n");
    }

    free(buf_info);

    return 0;
}

static struct uvc_format_opt uvc_z16_opt =
{
    .format_init = uvc_z16_init,
    .format_deinit = uvc_z16_deinit,
    .get_frame = uvc_z16_get_frame,
    .release_frame = uvc_z16_release_frame,
};

uvc_format_data_t uvc_z16_data =
{
    .vs_handle = NULL,
    .format_opt = &uvc_z16_opt,
};

static struct uvc_frame_buf_info * uvc_nv12_get_frame(uvc_format_data_t *data)
{
    struct uvc_frame_buf_info       *buf_info = NULL;
    ar_picture_buffer_t             *stream_buf_info = NULL;
    ar_video_format_info_t          format_info;
    struct yuv_priv_data            *priv_data = NULL;

    if(NULL == data || NULL == data->vs_handle || NULL == data->priv)
    {
        log_err("uvc_format_data is NULL or error!\n");
        return NULL;
    }

    buf_info = (struct uvc_frame_buf_info *)malloc(sizeof(struct uvc_frame_buf_info));
    if(NULL == buf_info)
    {
        log_err("malloc buf_info failed!\n");
        return NULL;
    }

    memset(buf_info, 0, sizeof(struct uvc_frame_buf_info));
    memset(&format_info, 0 , sizeof(ar_video_format_info_t));

    stream_buf_info = ar_picture_get_img(data->vs_handle);
    if(NULL == stream_buf_info)
    {
        log_err("ar_picture_get_img failed!\n");
        goto FAILED;
    }

    priv_data = (struct yuv_priv_data *)data->priv;

    if(-1 == (buf_info->index = get_free_buffer(priv_data)))
    {
        log_err("No free yuv buffer!\n");
        if(ar_picture_release_img(data->vs_handle, stream_buf_info))
        {
            log_err("0 YUV buffer release error!\n");
        }
        goto FAILED;
    }

    ar_picture_get_format(data->vs_handle, &format_info);
    if(0 == format_info.height || 0 == format_info.width)
    {
        log_err("YUV format error!\n");
        goto FAILED;
    }

    I420ToNV12((const uint8_t *)(stream_buf_info->mem[0].addr), get_y_stride(format_info.width),
               (const uint8_t *)(stream_buf_info->mem[1].addr), get_u_v_stride(format_info.width / 2),
               (const uint8_t *)(stream_buf_info->mem[2].addr), get_u_v_stride(format_info.width / 2),
               priv_data->yuv_buffer[buf_info->index], format_info.width,
               priv_data->yuv_buffer[buf_info->index] + format_info.width * format_info.height, format_info.width,
               format_info.width, format_info.height);

    buf_info->addr = (unsigned int)priv_data->yuv_buffer[buf_info->index];
    buf_info->len  = format_info.width * 3 / 2 * format_info.height;
    buf_info->pts  = stream_buf_info->pts;

    /*printf("YUV format(0x%08x): width %d height %d fps %d/%d\n",
                format_info.format,
                format_info.width,
                format_info.height,
                format_info.fps_num,
                format_info.fps_den);*/

    if(ar_picture_release_img(data->vs_handle, stream_buf_info))
    {
        log_err("YUV buffer release error!\n");
    }

    return buf_info;

FAILED:
    free(buf_info);

    return NULL;
}


static struct uvc_format_opt uvc_nv12_opt =
{
    .format_init = uvc_yuy2_init,
    .format_deinit = uvc_yuy2_deinit,
    .get_frame = uvc_nv12_get_frame,
    .release_frame = uvc_yuy2_release_frame,
};

uvc_format_data_t uvc_nv12_data =
{
    .vs_handle = NULL,
    .format_opt = &uvc_nv12_opt,
};
