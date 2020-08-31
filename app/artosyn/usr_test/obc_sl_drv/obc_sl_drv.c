#define ENABALE_ALL_LOG
#include "obc_sl_drv.h"
#include "obc_sl_spi.h"
#include "Mx6300.h"
#include "Mx6300_ctl.h"
static ar_mm_handle_t handle_gl = NULL;
int gwidth = 0;
int gheight = 0;
//volatile tof_cam_ctrl_t tof_sensor;
int gspifd = -1;
static gl_dev_t g_dev =
    {
        OBC_DEV_CLOSE, /* remote spi open/close status */
        NULL,          /* ar_cam_src pipline handle */
        OBC_DEV_CLOSE, /* pipline can only init once */
        STREAM_CLOSED, /* stream status */
        0,             /* cam_id in driver,default use 0 */
        -1,            /* cam_fd */
        -1,            /* spi_fd */
        {
            0, /* cam_id in dts */
            {
                1280, /* input vidio width and height */
                1024, /* input vidio width and height */
            },
            15, /* rtos vip subsample_rate <0-15> */
            30, /* vidio fps */
        },
};

static int find_pra_index_by_name(char *name, int argc, char *argv[])
{
    int i = 0;
    for (i = 0; i < argc; i++)
    {
        if (!strcmp(name, argv[i]))
        {
            log_always("find pra %s @ %d", name, i);
            return i;
        }
    }
    return 0;
}

static void cam_raw_get_context(void **context, uint32_t *context_size)
{
    int32_t idx = 0;
    static ar_facotry_element_obj_t cam_raw_init_list[] =
        {
            {"pipeline", "pipeline_mx6300", NULL},
            {"cam_src", "cam_src_mx6300", NULL},
            {"icc_proxy_rpc_sink", "icc_proxy_rpc_sink-0", NULL},
        };
    *context = (void *)&cam_raw_init_list;
    *context_size = sizeof(cam_raw_init_list) / sizeof(ar_facotry_element_obj_t);
    return;
}

int32_t cam_get_usr_cfg(int argc, char *argv[])
{
    int pra_index = 0;
    sl_usr_cfg_ppl_t *cam_raw_pipeline = &g_dev.cam_pipeline_cfg;

    pra_index = find_pra_index_by_name("--cam_id", argc, argv);
    if (pra_index > 0)
    {
        cam_raw_pipeline->cam_id = atoi(argv[pra_index + 1]);
        log_always("cam_id=%d", cam_raw_pipeline->cam_id);
    }
    pra_index = find_pra_index_by_name("--size", argc, argv);
    if (pra_index > 0)
    {
        cam_raw_pipeline->input_vidio_res.width = atoi(argv[pra_index + 1]);
        cam_raw_pipeline->input_vidio_res.height = atoi(argv[pra_index + 2]);
        log_always("width=%d height=%d", cam_raw_pipeline->input_vidio_res.width, cam_raw_pipeline->input_vidio_res.height);
    }
    pra_index = find_pra_index_by_name("--subsample_rate", argc, argv);
    if (pra_index > 0)
    {
        cam_raw_pipeline->subsample_rate = atoi(argv[pra_index + 1]);
        log_always("subsample_rate=%d", cam_raw_pipeline->subsample_rate);
    }

    pra_index = find_pra_index_by_name("--fps", argc, argv);
    if (pra_index > 0)
    {
        cam_raw_pipeline->fps = atoi(argv[pra_index + 1]);
        log_always("fps=%d", cam_raw_pipeline->fps);
    }
    return 0;
    // return cam_raw_init_impl(cam_raw_pipeline);
}

static int32_t cam_raw_init_impl(sl_usr_cfg_ppl_t *usr_cfg_ppl)

{
    ar_mm_handle_t handle = NULL;
    sl_cam_raw_context_t *context = NULL;
    uint32_t context_size = 0;
    // int pra_index=0;
    char *cam_mod = AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE;
    char *vif_isp_mode = AR_VIDEO_CAM_VIF_ISP_MOD_DDR;
    int fps = 30;
    int use_meta = 0;
    int use_scaler2 = 0;
    int queue_depth = 2;
    int no_display = 0;
    int den = 1;
    // int subsample_rate=15;
    char el_obj_name[50] = {
        'h',
        'f',
        'f',
    };

    cam_raw_get_context((void **)&context, &context_size);

    /* this only can be make once */
    //g_dev.sl_ppl_status =OBC_DEV_CLOSE;
    if (OBC_DEV_CLOSE == g_dev.sl_ppl_status)
    {
        // core_device open
        handle = ar_multimedia_core_device_open();
        if (!handle)
        {
            printf("%s, open multimedia core device failed.", __FUNCTION__);
            return AR_MULTIMEDIA_FAILURE;
        }
        else
        { /* store handle */
            g_dev.sl_cam_src_handle = handle;
            printf("\r\n multimedia_core_device handle:%d \n", handle);
        }
        //factory make
        if (ar_element_factory_make_many(handle, context_size, (ar_facotry_element_obj_t *)context) != AR_MULTIMEDIA_SUCCESS)
            return AR_MULTIMEDIA_FAILURE;
        else
            g_dev.sl_ppl_status = OBC_DEV_OPEN;
    }
    else
    {
        handle = g_dev.sl_cam_src_handle;
    }

    /* change cam src property */
    ar_element_modify_property_value(handle, context->cam_src.element, AR_VIDEO_CAM_SET_ID, &usr_cfg_ppl->cam_id, sizeof(uint32_t));
    ar_element_modify_property_value(handle, context->cam_src.element,
                                     AR_VIDEO_CAM_MODE,
                                     cam_mod,
                                     strlen(cam_mod) + 1);
    ar_element_modify_property_value(handle, context->cam_src.element,
                                     AR_VIDEO_CAM_VIF_ISP_MOD,
                                     vif_isp_mode,
                                     strlen(vif_isp_mode) + 1);
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 3),
                             AR_COMMON_META_VIDEO_WIDTH_NAME, &usr_cfg_ppl->input_vidio_res.width, sizeof(uint32_t));
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 3),
                             AR_COMMON_META_VIDEO_HEIGHT_NAME, &usr_cfg_ppl->input_vidio_res.height, sizeof(uint32_t));

    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 3),
                             AR_COMMON_META_VIDEO_FPS_NUM_NAME, &usr_cfg_ppl->fps, sizeof(uint32_t));
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 3),
                             AR_COMMON_META_VIDEO_FPS_DEN_NAME, &den, sizeof(uint32_t));

    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 3),
                             AR_COMMON_META_VIDEO_SUBSUMPLE_RATE, &usr_cfg_ppl->subsample_rate, sizeof(uint32_t));

    /* change icc_proxy_sink property */
    ar_element_modify_property_value(handle, context->buf_sink_0.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth, sizeof(uint32_t));

    /* add all element to pipeline/subpipe */
    ar_pipeline_add_many(handle, (ar_pipeline_t)context->pipeline.element, context->cam_src.element, NULL);
    ar_pipeline_add_many(handle, (ar_pipeline_t)context->pipeline.element, context->buf_sink_0.element, NULL);

    ar_pad_link_by_element(handle, context->cam_src.element, 3, context->buf_sink_0.element, 0);

    ar_element_set_state(handle, (ar_pipeline_t)context->pipeline.element, AR_ELEMENT_STATE_READY); // pipeline work
    /* check rots pipeline status,test if rtos thread run over */
    #if 0
    uint32_t set_count = 0;
    ar_element_state_t state;
#define MAX_WAIT_TIMES 10
    while (set_count < MAX_WAIT_TIMES)
    {
        set_count++;
        usleep(50000);
        ar_element_state_t state = ar_element_get_state(g_dev.sl_cam_src_handle, (ar_pipeline_t)context->pipeline.element);
        if (state == AR_ELEMENT_STATE_PLAYING)
        {
            break;
        }
        else
        {
            printf("%s::ar element state is not playing(state=%d)\n", __FUNCTION__, state);
        }
    }
    #endif
    printf("rots element set complete!\n");
    return AR_MULTIMEDIA_SUCCESS;
}

/**
 * @brief Unlink and remove pipeline
 * @param  none 
 * @param  none
 * @return	integer.
 *                 0 is ok,
 *                 others is error.
 * @note null.
 */
int cam_raw_final(void)
{
    sl_cam_raw_context_t *context = NULL;
    uint32_t context_size = 0;

    if (g_dev.sl_cam_src_handle == NULL)
    {
        printf("tof_cam_src handle is NULL\n");
        return -1;
    }
    ar_mm_handle_t handle = g_dev.sl_cam_src_handle;
    printf("ipcam_handle :%d\n", handle);
    cam_raw_get_context((void **)&context, &context_size);

    printf("ipcam_final\n");
    /* Set pipeline Any -> NULL */
    if (ar_pipeline_terminal_stream(handle, (ar_pipeline_t)context->pipeline.element) != AR_MULTIMEDIA_SUCCESS)
        return -1;
    /* unlink buf_sink_0 element */
    ar_pad_unlink_by_element(handle, context->cam_src.element, 3, context->buf_sink_0.element, 0);
    /* remove buf_sink_0 element */
    ar_pipeline_remove_element(handle, (ar_pipeline_t)context->pipeline.element, context->buf_sink_0.element);
    /* remove buf_sink_0 element */
    ar_pipeline_remove_element(handle, (ar_pipeline_t)context->pipeline.element, context->cam_src.element);
    /* destory element_factory */
    ar_element_factory_destory(handle, context->buf_sink_0.element);
    ar_element_factory_destory(handle, context->cam_src.element);
    ar_element_factory_destory(handle, context->pipeline.element);
    printf("DONE unlink remove cam_src\n");
#if 0
    ar_pad_unlink_by_element(handle, context->jpeg_enc0.element, 0, context->jpeg_bs_sink0.element, 0);
    ar_pad_unlink_by_element(handle, context->on_off0.element, 0, context->jpeg_enc0.element, 0);
    ar_pipeline_remove_element(handle, (ar_pipeline_t)context->pipeline.element, context->jpeg_enc0.element);
    ar_pipeline_remove_element(handle, (ar_pipeline_t)context->pipeline.element, context->jpeg_bs_sink0.element);
    PRINT("DONE unlink remove jpeg_enc,jpeg_bs_sink\n");

    ar_pad_unlink_by_element(handle, context->tee.element, 0, context->yuv_0_sink.element, 0);
    ar_pad_unlink_by_element(handle, context->tee.element, 1, context->comp.element, 0);
    ar_pad_unlink_by_element(handle, context->tee.element, 2, context->on_off0.element, 0);
    ar_pipeline_remove_element(handle, (ar_pipeline_t)context->pipeline.element, context->yuv_0_sink.element);
    ar_pipeline_remove_element(handle, (ar_pipeline_t)context->pipeline.element, context->comp.element);
    ar_pipeline_remove_element(handle, (ar_pipeline_t)context->pipeline.element, context->on_off0.element);
    
    PRINT("DONE unlink remove yuv_0_sink,comp,on_off\n");
    
    ar_pad_unlink_by_element(handle, context->cam_src.element, 1, context->yuv_1_sink.element, 0);
    ar_pad_unlink_by_element(handle, context->cam_src.element, 0, context->tee.element, 0);
    ar_pipeline_remove_element(handle, (ar_pipeline_t)context->pipeline.element, context->yuv_1_sink.element);
    ar_pipeline_remove_element(handle, (ar_pipeline_t)context->pipeline.element, context->tee.element);
    
    ar_pipeline_remove_element(handle, (ar_pipeline_t)context->pipeline.element, context->cam_src.element);
    PRINT("DONE unlink remove yuv_1_sink,tee,cam_src\n");
#endif

    return 0;
}

static void *process_sink_buf_0_thread(void *arg)
{
    sl_cam_raw_config_t *obj = (sl_cam_raw_config_t *)arg;
    sl_cam_buffer_t *buf = NULL;
    void *mem = NULL;
    int length = 0;
    int count = 0;
    while (obj->frame_count > 0)
    {
        pthread_mutex_lock(&obj->mutex);
        obj->buf_que->queue_pop(obj->buf_que, &buf);
        while (!buf)
        {
            pthread_cond_wait(&obj->buf_signal, &obj->mutex);
            obj->buf_que->queue_pop(obj->buf_que, &buf);
        }
        mem = buf->buf_mem;
        length = buf->buf_len;
        pthread_mutex_unlock(&obj->mutex);
        if (!mem)
        {
            printf("buf mem is NULL\n");
            free(buf);
            continue;
        }
        int width = gwidth;
        int height = gheight;

        int cnt = length / height;
        printf("width=%d,height=%d,cnt=%d\n", width, height, cnt);
        /* for (int i = 0; i < height; i++)
        {
            write(obj->fd, mem + (i * cnt), width * 2);
        }*/
        write(obj->fd, mem, length);
        free(mem);
        free(buf);
        obj->frame_count--;
        count++;
        printf("buf 0 count = %d\n", count);
        buf = NULL;
    }
    printf("process_sink_buf_0\r\n");
    close(obj->fd);
}

void get_sink_buf_0_thread(void *arg)
{
    struct timeval start, end;
    ar_picture_buffer_t *buffer = NULL;
    ar_picture_handle img_handle = NULL;
    int fd;
    sl_cam_raw_config_t *obj = (sl_cam_raw_config_t *)arg;
    int data_len = 0;
    sl_cam_buffer_t *buf;
    obj->buf_sink_fd = ar_picture_open("/dev/icc_proxy_rpc_sink-0");
    if (obj->buf_sink_fd < 0)
    {
        printf("open sink 0 error\n");
        return;
    }

    img_handle = (ar_picture_handle)(obj->buf_sink_fd);
    if (!img_handle)
    {
        printf("handle is null\n");
        return;
    }

    while (obj->frame_count > 0)
    {
        buffer = NULL;
        buffer = ar_picture_get_img(obj->buf_sink_fd);
        if (!buffer)
        {
            printf("get sink 0 buffer error\n");
            return;
        }
        //obj->fd = open(RAW_DATA_PATH, O_RDWR | O_CREAT);
        if (gwidth == 1280 && gheight == 1024)
        {
            system("rm ir.raw");
            obj->fd = open("ir.raw", O_RDWR | O_CREAT);
        }
        else if (gwidth == 1024 && gheight == 1280)
        {
            //system("rm 1024x1280.raw");
            obj->fd = open("1024x1280.raw", O_RDWR | O_CREAT | O_APPEND);
        }
        else if (gwidth == 960 && gheight == 1280)
        {
            system("rm 960x1280.raw");
            obj->fd = open("960x1280.raw", O_RDWR | O_CREAT);
        }
        else if (gwidth == 512 && gheight == 640)
        {
            system("rm 512x640.raw");
            obj->fd = open("512x640.raw", O_RDWR | O_CREAT);
        }
        else if (gwidth == 480 && gheight == 640)
        {
            system("rm 480x640.raw");
            obj->fd = open("480x640.raw", O_RDWR | O_CREAT);
        }
        else
        {
            obj->fd = open(RAW_DATA_PATH, O_RDWR | O_CREAT);
        }
        if (obj->fd < 0)
        {
            printf("open file error\n");
            return;
        }
        printf("the mem count = %d\n", buffer->mem_num);
        printf("frame id = %d\n", buffer->frame_id);
        printf("pts = %d\n", buffer->pts);
        printf("width = %d,height= %d\n", buffer->format.width, buffer->format.height);
        printf("luma_stride=%d,chroma_stride=%d\n", buffer->format.luma_stride, buffer->format.chroma_stride);
        data_len = buffer->mem[0].len;
        //buf = (void*)buffer->mem[0].addr;
        buf = (sl_cam_buffer_t *)malloc(sizeof(sl_cam_buffer_t));
        if (buf == NULL)
        {
            printf("malloc buf 0 error\n");
        }
        buf->buf_mem = (char *)malloc(data_len);
        if (!buf->buf_mem)
        {
            printf("malloc buf mem error\n");
        }
        buf->buf_len = data_len;
        printf("buf len = %d, %d, %d\n", buffer->mem[0].len, buffer->mem[1].len, buffer->mem[2].len);
        gettimeofday(&start, NULL);
        memcpy(buf->buf_mem, buffer->mem[0].addr, data_len);
        gettimeofday(&end, NULL);
        pthread_mutex_lock(&obj->mutex);
        if (obj->buf_que->queue_insert(obj->buf_que, buf))
        {
            printf("insert queue err\n");
        }
        pthread_cond_signal(&obj->buf_signal);
        pthread_mutex_unlock(&obj->mutex);
        if (ar_picture_release_img(img_handle, buffer))
        {
            printf("release buffer failed\n");
            return;
        }
    }
    ar_picture_close(obj->buf_sink_fd);
    printf("buf 0 write finish\n");
}


/*
    obc cam init
    return < 0 err;
*/
int init_sl_cam(sl_usr_cfg_ppl_t *usr_cfg_ppl)
{
    int ret;
    /* mx6300 init*/
    gspifd = obc_sl_spi_open();
    if (gspifd < 0)
    {
        printf("obc_sl_spi_open failed\n");
        return -1;
    }
    /* rtos pipeline setup */
    g_dev.spi_fd = gspifd;
    g_dev.cam_pipeline_cfg = *usr_cfg_ppl;
    if (cam_raw_init_impl(usr_cfg_ppl) != AR_MULTIMEDIA_SUCCESS)
    {
        printf("cam_raw_init_impl failed\n");
        return -1;
    }

    /* 2. open tof cam_src pipeline to READY */
    ret = open_sl_cam(g_dev.sl_cam_id);
    if (ret < 0)
    {
        printf("open_sl_cam failed\n");
        return -1;
    }
    usleep(2000);
    Stream_ctl_State stream_ctl;
    if (g_dev.cam_pipeline_cfg.stream_type == STREAM_DEPTH)
    {
        stream_ctl = STREAM_DEPTH_OPEN;
    }
    else
    {
        stream_ctl = STREAM_IR_OPEN;
    }
    //sl_stream_on(g_dev.cam_pipeline_cfg.stream_type);
    printf("InitSuccess!\n");
    return 0;
}
int sl_stream_on(Stream_ctl_State stream)
{
    int ret;
#if 0
    sl_cam_raw_context_t* context = NULL;
    uint32_t context_size = 0;
     cam_raw_get_context((void**)&context, &context_size);
   if (ar_pipeline_terminal_stream(g_dev.sl_cam_src_handle, (ar_pipeline_t)context->pipeline.element) != AR_MULTIMEDIA_SUCCESS)
       return -1;

    ar_element_set_state(g_dev.sl_cam_src_handle, (ar_pipeline_t)context->pipeline.element,AR_ELEMENT_STATE_READY); // pipeline work
    uint32_t set_count = 0;
   ar_element_state_t  state;
#define MAX_WAIT_TIMES 10
    while(set_count<MAX_WAIT_TIMES)
    {
         set_count++;
         usleep(50000);
       ar_element_state_t  state=ar_element_get_state(g_dev.sl_cam_src_handle, (ar_pipeline_t)context->pipeline.element);
       if(state==AR_ELEMENT_STATE_PLAYING){
             break;
       }else{
           printf("ar element state is not playing(state=%d)\n",state);
       }
    }
#endif
    ret = Mx6300_Stream_control(stream);
    if (ret != OB_SUCCESS)
    {
        printf("%s:open stream failed\n", __FUNCTION__);
    }
    else
    {
        printf("stream on(type=%d)\n",stream);
        if (stream == STREAM_DEPTH_OPEN)
        {
            g_dev.sl_stream_status = STREAM_DEPTH_OPENED;
        }
        else if (stream == STREAM_IR_OPEN)
        {
            g_dev.sl_stream_status = STREAM_IR_OPENED;
        }
        else
        {
            g_dev.sl_stream_status = STREAM_CLOSED;
        }
    }
}
int sl_stream_off()
{
    int ret;
#if 0
       sl_cam_raw_context_t* context = NULL;
    uint32_t context_size = 0;
     cam_raw_get_context((void**)&context, &context_size);
    if (ar_pipeline_terminal_stream(g_dev.sl_cam_src_handle, (ar_pipeline_t)context->pipeline.element) != AR_MULTIMEDIA_SUCCESS)
        return -1;
#endif
    ret = Mx6300_Stream_control(STREAM_CLOSE);
    if (ret != OB_SUCCESS)
    {
        printf("%s:close stream failed\n", __FUNCTION__);
    }
    else
    {
        printf("stream off\n");
        g_dev.sl_stream_status = STREAM_CLOSED;
    }
    return ret;
}
int switch_resolution(Stream_ctl_State stream, Resolution res,uint8_t fps)
{
    int ret;
    int width, height;
    int fps_ = fps;
    int sub_fps = 15;
    int den = 1;
    int queue_depth = 2;
    char *cam_mod = AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE;
    char *vif_isp_mode = AR_VIDEO_CAM_VIF_ISP_MOD_DDR;
    sl_cam_raw_context_t *context = NULL;
    uint32_t context_size = 0;
    Resolution res_state = res;
    cam_raw_get_context((void **)&context, &context_size);
    printf("switch res=%d,stream=%d,fps=%d\n", res, stream,fps);
    switch (res)
    {
    case RES_SXGA:
        width = 1280;
        height = 1024;
        break;
     case RES_1280_960:
        width = 1280;
        height = 960;
        break;
    case RES_1024_1280:
        width = 1024;
        height = 1280;
        break;
    case RES_1280_800:
        width = 1280;
        height = 800;
        break;
    case RES_640_400:
        width = 640;
        height = 400;
        break;
    case RES_960_1280:
        width = 960;
        height = 1280;
        break;
    case RES_512_640:
        width = 512;
        height = 640;
        break;
    case RES_480_640:
        width = 480;
        height = 640;
        break;
    default:
        if (stream == STREAM_DEPTH_OPEN)
        {
            width = 1024;
            height = 1280;
        }
        else
        {
            width = 1280;
            height = 1024;
        }
        break;
    }

    g_dev.cam_pipeline_cfg.input_vidio_res.height = height;
    g_dev.cam_pipeline_cfg.input_vidio_res.width = width;
    g_dev.cam_pipeline_cfg.fps = fps_;
    g_dev.cam_pipeline_cfg.subsample_rate = sub_fps;
    Mx6300_Stream_control(STREAM_CLOSE);
    /* terminal stream */
    if (ar_pipeline_terminal_stream(g_dev.sl_cam_src_handle, (ar_pipeline_t)context->pipeline.element) != AR_MULTIMEDIA_SUCCESS)
        return -1;
    if (stream == STREAM_IR_OPEN)
    {
        //Mx6300_set_ir_resolution(res_state);
        Mx6300_set_ir_video_mode(res_state,fps);
        printf("stream ir switch \n");
    }
    else if (stream == STREAM_DEPTH_OPEN)
    {
        //Mx6300_set_depth_resolution(res_state);
        Mx6300_set_depth_video_mode(res_state,fps);
        printf("stream depth switch \n");
    }
    #if 0
    Mx6300_Stream_control(stream);
    Mx6300_Stream_control(STREAM_CLOSE);
    usleep(20000);
    #endif
    #if 0
    {
        /* unlink buf_sink_0 element */
        //ar_pad_unlink_by_element(g_dev.sl_cam_src_handle, context->cam_src.element, 3, context->buf_sink_0.element, 0);
        /* remove buf_sink_0 element */
        // ar_pipeline_remove_element(g_dev.sl_cam_src_handle,(ar_pipeline_t)context->pipeline.element,context->buf_sink_0.element);
        /* remove buf_sink_0 element */
        //ar_pipeline_remove_element(g_dev.sl_cam_src_handle, (ar_pipeline_t)context->pipeline.element, context->cam_src.element);
        /* change cam src property */
        // ar_element_modify_property_value(g_dev.sl_cam_src_handle, context->cam_src.element, AR_VIDEO_CAM_SET_ID, &g_dev.cam_pipeline_cfg.cam_id , sizeof(uint32_t));
        /* ar_element_modify_property_value(g_dev.sl_cam_src_handle, context->cam_src.element,
                                     AR_VIDEO_CAM_MODE,
                                     cam_mod,
                                     strlen(cam_mod) + 1);*/
        /*ar_element_modify_property_value(g_dev.sl_cam_src_handle, context->cam_src.element,
                                     AR_VIDEO_CAM_VIF_ISP_MOD,
                                     vif_isp_mode,
                                     strlen(vif_isp_mode) + 1);*/
    }
    #endif
    ar_pad_modify_meta_value(g_dev.sl_cam_src_handle, ar_element_get_src_pad_by_idx(g_dev.sl_cam_src_handle, context->cam_src.element, 3),
                             AR_COMMON_META_VIDEO_WIDTH_NAME, &width, sizeof(uint32_t));
    ar_pad_modify_meta_value(g_dev.sl_cam_src_handle, ar_element_get_src_pad_by_idx(g_dev.sl_cam_src_handle, context->cam_src.element, 3),
                             AR_COMMON_META_VIDEO_HEIGHT_NAME, &height, sizeof(uint32_t));
#if 0
{
    ar_pad_modify_meta_value(g_dev.sl_cam_src_handle, ar_element_get_src_pad_by_idx(g_dev.sl_cam_src_handle, context->cam_src.element, 3),
                             AR_COMMON_META_VIDEO_FPS_NUM_NAME, &fps_, sizeof(uint32_t));
    ar_pad_modify_meta_value(g_dev.sl_cam_src_handle, ar_element_get_src_pad_by_idx(g_dev.sl_cam_src_handle, context->cam_src.element, 3),
                             AR_COMMON_META_VIDEO_FPS_DEN_NAME, &den, sizeof(uint32_t));
   /* ar_pad_modify_meta_value(g_dev.sl_cam_src_handle, ar_element_get_src_pad_by_idx(g_dev.sl_cam_src_handle, context->cam_src.element, 3),
                             AR_COMMON_META_VIDEO_FPS_NUM_NAME, &fps, sizeof(uint32_t));
    ar_pad_modify_meta_value(g_dev.sl_cam_src_handle, ar_element_get_src_pad_by_idx(g_dev.sl_cam_src_handle, context->cam_src.element, 3),
                             AR_COMMON_META_VIDEO_FPS_DEN_NAME, &den, sizeof(uint32_t));

    ar_pad_modify_meta_value(g_dev.sl_cam_src_handle, ar_element_get_src_pad_by_idx(g_dev.sl_cam_src_handle, context->cam_src.element, 3),
                             AR_COMMON_META_VIDEO_SUBSUMPLE_RATE, &sub_fps, sizeof(uint32_t));*/

    /* change icc_proxy_sink property */
    //ar_element_modify_property_value(g_dev.sl_cam_src_handle, context->buf_sink_0.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth, sizeof(uint32_t));

    /* add all element to pipeline/subpipe */
    // ar_pipeline_add_many(g_dev.sl_cam_src_handle, (ar_pipeline_t)context->pipeline.element,context->cam_src.element,NULL);
    //ar_pipeline_add_many(g_dev.sl_cam_src_handle,(ar_pipeline_t)context->pipeline.element,context->buf_sink_0.element,NULL);

    //ar_pad_link_by_element(g_dev.sl_cam_src_handle, context->cam_src.element, 3, context->buf_sink_0.element, 0);
    //printf("mx6300_handle=0x%x,element=0x%x\n",g_dev.sl_cam_src_handle, (ar_pipeline_t)context->pipeline.element);
}
#endif
    ar_element_set_state(g_dev.sl_cam_src_handle, (ar_pipeline_t)context->pipeline.element, AR_ELEMENT_STATE_READY); // pipeline work
    printf("mx6300 element has  set state to ready\n");
   
   #if 0
    usleep(10000);
    Mx6300_Stream_control(stream);
   
    uint32_t set_count = 0;
    ar_element_state_t state;
#define MAX_WAIT_TIMES 8
    while (set_count < MAX_WAIT_TIMES)
    {
        set_count++;
        usleep(50000);
        ar_element_state_t state = ar_element_get_state(g_dev.sl_cam_src_handle, (ar_pipeline_t)context->pipeline.element);
        if (state == AR_ELEMENT_STATE_PLAYING)
        {
            break;
        }
        else
        {
            printf("ar element state is not playing(state=%d)\n", state);
        }
    }
    #endif 
    printf("switch resolution complete! \n");
    return 0;
}
int deinit_sl_cam(sl_usr_cfg_ppl_t *usr_cfg_ppl)
{
    close_sl_cam(g_dev.sl_cam_id);
    obc_sl_spi_close(gspifd);
    remove_cam();
    return 0;
}
/*
    obc cam remove
    return < 0 err;
*/
int remove_cam(void)
{
    int cam_fd = -1, remote_spi_fd = -1;
    int camera_id = 0; // default use cam_0
    static int first_close = 1;
    char device_name[64];
    /* rtos pipeline only can close 1 times */
    if (!first_close)
    {
        return -1;
    }
    first_close = 0;
    /* rtos pipeline unlink and remove */
    if (cam_raw_final() < 0)
    {
        printf("remove_cam--remove pipeline err\n");
        return -1;
    }

    printf("RemoveSuccess!\n");
    return 0;
}

/*
    obc cam open
    return < 0 err;
*/
int open_sl_cam(int cam_id)
{
    char device_name[64];

    /* open cam_src pipeline */
    g_dev.sl_cam_id = cam_id;
    //sprintf(device_name, "/dev/cam_src-%d", g_dev.sl_cam_id);
    sprintf(device_name, "/dev/cam_src_mx6300");
    g_dev.sl_cam_fd = ar_cam_src_open(device_name); //"/dev/cam_src-0"
    if (g_dev.sl_cam_fd < 0)
    {
        printf("open sl_cam_src error\n");
        return -1;
    }
    printf("OpenSuccess!\n");
    return g_dev.sl_cam_fd;
}

/*
    obc cam open
    return < 0 err;
*/
int close_sl_cam(int fd)
{
    /* close cam_src */
    //g_dev.sl_cam_id = fd;
    if (ar_cam_src_close(g_dev.sl_cam_id) != 0)
    {
        printf("close tof_cam_src error\n");
        return -1;
    }
    printf("CloseSuccess!\n");
    return 0;
}

/*
    obc cam capture mipi raw data
    return < 0 err;
*/
int capture_cam_raw(uint32_t frame_cnt)
{
    sl_cam_raw_config_t obj;

    obj.frame_count = frame_cnt;
    pthread_cond_init(&obj.buf_signal, NULL);
    pthread_mutex_init(&obj.mutex, NULL);
    obj.buf_que = ar_creat_queue(MAX_MEM_FIFO, "buf_sink_0");
    pthread_create(&obj.thread_id, NULL, (void *)get_sink_buf_0_thread, (void *)&obj);
    pthread_create(&obj.thread_process_id, NULL, (void *)process_sink_buf_0_thread, (void *)&obj);
    pthread_join(obj.thread_id, NULL);
    pthread_join(obj.thread_process_id, NULL);
    return 0;
}

/*
    obc cam close stream
    return < 0 err;
*/
void test_command()
{
    char ch = (char)getchar();
    int addr = 0;
    int value = 0;
    mx6300_i2c_ctrl i2c_ctrl = {0};
    uint8_t val8;
    int ret;
    uint32_t addr_ahb, addr_value;
    while (ch != 'q')
    {

        switch (ch)
        {
        case '0':
            printf("get  device ID\n");
            uint16_t devID;
            ret = Mx6300_get_device_id(&devID);
            if (ret < 0)
            {
                printf("get Device id failed\n");
            }
            else
            {
                printf("Device ID=0x%x\n", devID);
            }
            break;
        case '1':
            printf("get firmware version\n");
            char fw[9] = {0};
            ret = Mx6300_read_fw_version(fw);
            if (ret < 0)
            {
                printf("get firmware version failed\n");
            }
            else
            {
                printf("fw ver:%s\n", fw);
            }
            break;
        case '2':
            printf("get hardware version\n");
            uint8_t hw;
            ret = Mx6300_read_hw_version(&hw);
            if (ret < 0)
            {
                printf("get hardware version failed\n");
            }
            else
            {
                printf("Hw ver:%d\n", hw);
            }
            break;
        case '3':
            printf("get hardware version\n");
            uint8_t hw1;
            ret = Mx6300_read_hw_version(&hw1);
            if (ret < 0)
            {
                printf("get hardware version failed\n");
            }
            else
            {
                printf("Hw ver:%d\n", hw1);
            }
            break;
        case '4':
            printf("stream control\n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);

            Stream_ctl_State s = value;
            ret = Mx6300_Stream_control(s);
            if (ret < 0)
            {
                printf("stream control failed\n");
            } 
            break;
        case '5':
            printf("laser status control\n");
            fflush(stdin);
            printf("please input  value");
            ret = scanf("%x", &value);
            ret = Mx6300_laser_control(value);
            if (ret < 0)
            {
                printf("laser control  failed\n");
            }
            break;
        case '6':
            printf("get laser status\n");
            uint8_t laser;
            ret = Mx6300_get_laser_status(&laser);
            if (ret < 0)
            {
                printf("get laser status failed\n");
            }
            else
            {
                printf("laser status:%d\n", laser);
            }
            break;
        case '7':
            printf("set ir gain\n");
            fflush(stdin);
            printf("please input  value");
            ret = scanf("%x", &value);
            ret = Mx6300_set_ir_gain(value);
            if (ret < 0)
            {
                printf("set ir gain failed\n");
            }
            break;
        case '8':
            printf("get ir gain\n");
            uint32_t gain;
            ret = Mx6300_get_ir_gain(&gain);
            if (ret < 0)
            {
                printf("get ir gain failed\n");
            }
            else
            {
                printf("ir  gain:%d\n", gain);
            }
            break;
        case '9':
            printf("set ir exposure\n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);
            ret = Mx6300_set_ir_exposure(value);
            if (ret < 0)
            {
                printf("set ir exposure failed\n");
            }
            break;
        case 'A':
            printf("get ir exposure\n");
            uint32_t exp;
            ret = Mx6300_get_ir_exposure(&exp);
            if (ret < 0)
            {
                printf("get ir exposure failed\n");
            }
            else
            {
                printf("ir exposure:%d\n", exp);
            }
            break;
        case 'B':
            printf("write ahb\n");
            fflush(stdin);
            printf("please input  addr and data\n");
            scanf("%x %x", &addr, &value);
            ret = Mx6300_write_ahb(addr, value);
            if (ret < 0)
            {
                printf("write adb failed\n");
            }
            break;
        case 'C':
            printf("read ahb\n");
            fflush(stdin);
            printf("please input  addr\n");
            scanf("%x", &addr);
            ret = Mx6300_read_ahb(addr, &value);
            if (ret < 0)
            {
                printf("read adb failed\n");
            }
            else
            {
                printf("data=0x%x(addr:0x%x)\n", value, addr);
            }
            break;
        case 'D':
            printf("write i2c\n");
            fflush(stdin);
            printf("please input bus,slave_addr,reg,reg_len,data,data_len\n");
            scanf("%x %x %x %x %x %x", &i2c_ctrl.bus, &i2c_ctrl.slave_addr, &i2c_ctrl.reg,
                  &i2c_ctrl.reg_len, &i2c_ctrl.data, &i2c_ctrl.data_len);
            ret = Mx6300_write_i2c(&i2c_ctrl);
            if (ret < 0)
            {
                printf("write i2c failed\n");
            }
            break;
        case 'E':
            printf("read i2c\n");
            fflush(stdin);
            printf("please input bus,slave_addr,reg,reg_len,data,data_len\n");
            scanf("%x %x %x %x %x %x", &i2c_ctrl.bus, &i2c_ctrl.slave_addr, &i2c_ctrl.reg,
                  &i2c_ctrl.reg_len, &i2c_ctrl.data, &i2c_ctrl.data_len);
            ret = Mx6300_read_i2c(&i2c_ctrl);
            if (ret < 0)
            {
                printf("read i2c failed\n");
            }
            else
            {
                printf("data=0x%x(reg_addr=0x%x)\n", i2c_ctrl.data, i2c_ctrl.reg);
            }
            break;
        case 'F':
            printf("ir resolution switch \n");
            fflush(stdin);
            printf("please input  value");
            ret = scanf("%x", &value);
            ret = Mx6300_set_ir_resolution((Resolution_State)value);
            if (ret < 0)
            {
                printf("ir resolution switch failed\n");
            }
            break;
        case 'G':
            printf("get ir resolution\n");
            uint8_t ir_res;
            ret = Mx6300_get_ir_resolution(&ir_res);
            if (ret < 0)
            {
                printf("get ir resolution failed\n");
            }
            else
            {
                printf("ir resolution :%d\n", ir_res);
            }
            break;
        case 'H':
            printf("depth resolution switch \n");
            fflush(stdin);
            printf("please input  value");
            ret = scanf("%x", &value);
            ret = Mx6300_set_depth_resolution((Resolution_State)value);
            if (ret < 0)
            {
                printf("depth resolution switch failed\n");
            }
            break;
        case 'I':
            printf("get depth resolution\n");
            uint8_t depth_res;
            ret = Mx6300_get_depth_resolution(&depth_res);
            if (ret < 0)
            {
                printf("get depth resolution failed\n");
            }
            else
            {
                printf("depth resolution :%d\n", depth_res);
            }
            break;
        case 'J':
            printf("switch ir resolution\n");
            printf("please input  value");
            ret = scanf("%x", &value);
            ret = switch_resolution(STREAM_IR_OPEN, value,30);
            // ret = Mx6300_set_ir_resolution(value);
            if (ret < 0)
            {
                printf("switch ir resolution failed\n");
            }
            else
            {
                system("rm /mnt/data.raw");
                if (value == 1)
                {
                    gwidth = 1280;
                    gheight = 800;
                }
                else
                {
                    gwidth = 640;
                    gheight = 400;
                }
                capture_cam_raw(1);
            }
            break;
        case 'K':
            printf("switch depth/IR resolution\n");
            printf("please input  value");
            ret = scanf("%x", &value);
            ret = switch_resolution(STREAM_DEPTH_OPEN, value,30);
            // ret = Mx6300_set_ir_resolution(value);
            if (ret < 0)
            {
                printf("switch depth resolution failed\n");
            }
            else
            {
                system("rm /mnt/data.raw");
                if (value == 1)
                {
                    gwidth = 1280;
                    gheight = 800;
                }
                else
                {
                    gwidth = 640;
                    gheight = 400;
                }
                capture_cam_raw(1);
            }
            break;
        case 'L':
            printf("auto switch ir resolution\n");
            value = 1;
            int loop_cnt;
            printf("please input  loop count\n");
            ret = scanf("%x", &loop_cnt);
            for (int i = 0; i < loop_cnt; i++)
            {
                printf("auto switch resolution loop=%d\n", i + 1);
                ret = switch_resolution(STREAM_DEPTH_OPEN, value,30);
                if (ret < 0)
                {
                    printf("switch depth resolution failed\n");
                }
                else
                {
                    system("rm /mnt/data.raw");
                    if (value == 1)
                    {
                        gwidth = 1280;
                        gheight = 800;
                        value = 2;
                    }
                    else
                    {
                        gwidth = 640;
                        gheight = 400;
                        value = 1;
                    }
                    capture_cam_raw(1);
                }
            }
            break;
        case 'N':
            printf("stream control\n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);
            for (int i = 0; i < value; i++)
            {
                printf("stream on/off loop count =%d\n", i);
                usleep(1000 * 1000);
                ret = Mx6300_Stream_control(STREAM_CLOSE);
                if (ret < 0)
                {
                    printf("stream control failed\n");
                }
                usleep(1000 * 1000);
                ret = Mx6300_Stream_control(STREAM_IR_OPEN);
                if (ret < 0)
                {
                    printf("stream control failed\n");
                }
                else
                {
                    if (value != 0)
                    {
                        system("rm /mnt/data.raw");
                        capture_cam_raw(1);
                    }
                }
            }
            break;
        case 'O':
            printf("stream control\n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);
            Stream_ctl_State sd = value;
            if (value == 0)
            {
                ret = sl_stream_off();
            }
            else
            {
                ret = sl_stream_on(sd);
            }
            if (ret < 0)
            {
                printf("stream control failed\n");
            }
            else
            {
                if (value != 0)
                {
                    usleep(20000);
                    capture_cam_raw(1);
                }
            }
            break;
        case 'P':
            printf("stream control\n");
            fflush(stdin);
            printf("please input  type of stream,0->depth,1->ir,2->interleave\n");
            int type;
            int turnFlag = 0;
            ret = scanf("%d", &type);
            printf("please input  loop count\n");
            ret = scanf("%x", &value);
            for (int i = 0; i < value; i++)
            {
                printf("stream on/off loop count =%d\n", i);
                usleep(1000 * 1000);
                printf("stream off start\n", i);
                ret = sl_stream_off();
                printf("stream off end\n", i);
                if (ret < 0)
                {
                    printf("stream off failed\n");
                }
                usleep(1000 * 1000);
                printf("stream on start\n");
                if (type == 0)
                {
                    ret = sl_stream_on(STREAM_DEPTH_OPEN);
                }
                else if (type == 1)
                {
                    ret = sl_stream_on(STREAM_IR_OPEN);
                }
                else
                {
                    if (turnFlag == 0)
                    {
                        ret = sl_stream_on(STREAM_DEPTH_OPEN);
                        turnFlag = 1;
                    }
                    else
                    {
                        ret = sl_stream_on(STREAM_IR_OPEN);
                        turnFlag = 0;
                    }
                }
                printf("stream on end\n", i);
                if (ret < 0)
                {
                    printf("stream control failed\n");
                }
                else
                {
                    if (value != 0)
                    {
                        system("rm data.raw");
                        capture_cam_raw(1);
                    }
                }
            }
            /*Stream_ctl_State s = value;
      ret=Mx6300_Stream_control(s);
      if(ret<0){
          printf("stream control failed\n");
      } else{
          if(value!=0){
          system("rm /mnt/data.raw");
            capture_cam_raw(1);
          }
      } */

            break;
        case 'Q':
            printf("mx6300 stream control\n");
            fflush(stdin);
            printf("please input  type of stream,0->depth,1->ir,2->interleave,3->depth interleave\n");
            int type1;
            int turnFlag1 = 0;
            ret = scanf("%d", &type1);
            printf("please input  loop count\n");
            ret = scanf("%x", &value);
            for (int i = 0; i < value; i++)
            {
                printf("mx6300 stream on/off loop count =%d\n", i);
                usleep(1000 * 1000);
                printf("mx6300 stream off start\n", i);
                ret = Mx6300_Stream_control(STREAM_CLOSE);
                printf("mx6300 stream off end\n", i);
                if (ret < 0)
                {
                    printf("mx6300 stream off failed\n");
                }
                usleep(1000 * 1000);
                printf("mx6300 stream on start\n");
                if (type1 == 0)
                {
                    ret = Mx6300_Stream_control(STREAM_DEPTH_OPEN);
                }
                else if (type1 == 1)
                {
                    ret = Mx6300_Stream_control(STREAM_IR_OPEN);
                }
                else if (type1 == 2)
                {
                    if (turnFlag1 == 0)
                    {
                        //ret = Mx6300_Stream_control(STREAM_DEPTH_OPEN);
                        ret = switch_resolution(STREAM_DEPTH_OPEN, RES_960_1280,30);
                        turnFlag1 = 0;
                        gwidth = 960;
                        gheight = 1280;
                    }
                    else
                    {
                        //ret = Mx6300_Stream_control(STREAM_IR_OPEN);
                        ret = switch_resolution(STREAM_IR_OPEN, RES_SXGA,30);
                        turnFlag1 = 0;
                        gwidth = 1280;
                        gheight = 1024;
                    }
                }
                else
                {
                    if (turnFlag1 == 0)
                    {
                        //ret = Mx6300_Stream_control(STREAM_DEPTH_OPEN);
                        ret = switch_resolution(STREAM_DEPTH_OPEN, RES_1024_1280,30);
                        turnFlag1 = 1;
                        gwidth = 1024;
                        gheight = 1280;
                    }
                    else if (turnFlag1 == 1)
                    {
                        //ret = Mx6300_Stream_control(STREAM_IR_OPEN);
                        ret = switch_resolution(STREAM_DEPTH_OPEN, RES_960_1280,30);
                        turnFlag1 = 2;
                        gwidth = 960;
                        gheight = 1280;
                    }
                    else if (turnFlag1 == 2)
                    {
                        //ret = Mx6300_Stream_control(STREAM_IR_OPEN);
                        ret = switch_resolution(STREAM_DEPTH_OPEN, RES_512_640,30);
                        turnFlag1 = 3;
                        gwidth = 512;
                        gheight = 640;
                    }
                    else if (turnFlag1 == 3)
                    {
                        //ret = Mx6300_Stream_control(STREAM_IR_OPEN);
                        ret = switch_resolution(STREAM_DEPTH_OPEN, RES_480_640,30);
                        turnFlag1 = 0;
                        gwidth = 480;
                        gheight = 640;
                    }
                }
                printf("mx6300 stream on end\n", i);
                if (ret < 0)
                {
                    printf("mx6300 stream control failed\n");
                }
                else
                {
                    if (value != 0)
                    {
                        capture_cam_raw(1);
                       
                    }
                }
            }
            break;
        case 'R':
            fflush(stdin);
            printf("write ahb operation \n");
            printf("please input addr and value:");
            ret = scanf("%x %x", &addr_ahb, &addr_value);
            ret = Mx6300_write_ahb(addr_ahb, addr_value);
            if (ret < 0)
            {
                printf("mx6300 write ahb failed\n");
            }
            break;
        case 'S':
            fflush(stdin);
            printf("read ahb operation \n");
            printf("please input addr :");
            ret = scanf("%x", &addr_ahb);
            ret = Mx6300_read_ahb(addr_ahb, &addr_value);
            if (ret < 0)
            {
                printf("mx6300 write ahb failed\n");
            }
            else
            {
                printf("the value is 0x%x(addr=0x%x)\n", addr_value, addr_ahb);
            }
            break;
        case 'T':
            fflush(stdin);
            uint32_t base_addr;
            printf("set base addr for mx6300 \n");
            printf("please input base addr :");
            ret = scanf("%x", &base_addr);
            obc_sl_setBaseAddr(base_addr);
            break;
        case 'U':
            printf("set laser current\n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);
            ret = Mx6300_set_laser_current(value);
            if (ret < 0)
            {
                printf("set laser current failed\n");
            }
            break;
        case 'V':
            printf("get laser current\n");
            uint32_t laser_current;
            ret = Mx6300_get_laser_current(&laser_current);
            if (ret < 0)
            {
                printf("get laser current failed\n");
            }
            else
            {
                printf("laser current:%d\n", laser_current);
            }
            break;
        case 'W':
            printf("set LDP enable status\n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);
            ret = Mx6300_set_ldp_enable(value);
            if (ret < 0)
            {
                printf("set LDP enable status failed\n");
            }
            break;
        case 'X':
            printf("get LDP enable status\n");
            uint8_t ldp_enable;
            ret = Mx6300_get_ldp_enable(&ldp_enable);
            if (ret < 0)
            {
                printf("get LDP enable status failed\n");
            }
            else
            {
                printf("LDP enable status:%d\n", ldp_enable);
            }
            break;
        case 'Y':
            printf("set LDP threshold \n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);
            ret = Mx6300_set_ldp_scale(value);
            if (ret < 0)
            {
                printf("set LDP enable status failed\n");
            }
            break;
        case 'Z':
            printf("get LDP  threshold\n");
            uint32_t ldp_scale;
            ret = Mx6300_get_ldp_scale(&ldp_scale);
            if (ret < 0)
            {
                printf("get LDP threshold failed\n");
            }
            else
            {
                printf("LDP threshold:%d\n", ldp_scale);
            }
            break;
        case 'a':
            printf("get LDP  protected status\n");
            uint8_t ldp_protect;
            ret = Mx6300_get_ldp_protect_status(&ldp_protect);
            if (ret < 0)
            {
                printf("get LDP protected status failed\n");
            }
            else
            {
                printf("LDP protected status:%d\n", ldp_protect);
            }
            break;
        case 'b':
            printf("set depth mirror \n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);
            ret = Mx6300_set_depth_mirror(value);
            if (ret < 0)
            {
                printf("set depth mirror failed\n");
            }
            break;
        case 'c':
            printf("get depth mirror\n");
            uint32_t mirror;
            ret = Mx6300_get_depth_mirror(&mirror);
            if (ret < 0)
            {
                printf("get depth mirror failed\n");
            }
            else
            {
                printf("depth mirror:%d\n", mirror);
            }
            break;
        case 'd':
            printf("send rectify params\n");
            ret = obc_sl_send_rectify_params();
            if (ret < 0)
            {
                printf("send rectify params failed\n");
            }
            break;
        case 'e':
            printf("calibrate ldp\n");
            ret = Mx6300_set_ldp_calibrate(1);
            if (ret < 0)
            {
                printf("calibrate ldp failed\n");
            }
            break;
        case 'f':
            printf("write ldp calibrate data\n");
            uint8_t data[16];
            for (int i = 0; i < 16; i++)
            {
                data[i] = 0x10 + i;
            }
            ret = Mx6300_write_ldp_calibrate_data(data);
            if (ret < 0)
            {
                printf("write ldp calibrate data failed\n");
            }
            break;
        case 'g':
            printf("capture depth raw data\n");
            ret = switch_resolution(STREAM_DEPTH_OPEN, RES_1024_1280,30);
            gwidth = 1024;
            gheight = 1280;
            if (ret < 0)
            {
                printf("switch resolution failed\n");
            }
            capture_cam_raw(5);
            break;
        case 'h':
        printf("please input loop count\n");
        scanf("%d",&value);
        for(int i=0;i<value;i++)
        {
          if(sl_stream_off() < 0){
            printf("off stream failed!\n");
        }
        //2,switch res depth 960 1280
        if(switch_resolution(STREAM_DEPTH_OPEN, RES_960_1280,30) < 0){
            printf("off stream failed!\n");
        }
        //3,start stream
        if(sl_stream_on(STREAM_DEPTH) < 0){
            printf("on stream failed!\n");
        }

        //4,get pictures
        capture_cam_raw(1);
        }
          
        break;
        case 'i':
        printf("get temperature of mx6300 component\n");
        Componet_temp temp;
        ret = Mx6300_get_componet_temp(&temp);
         if (ret < 0)
            {
                printf("get temperature of mx6300 failed\n");
                break;
            }
       printf("temperature(ldm=%f, ir=%f, rgb=%f)\n",temp.ldm_temp,temp.ir_temp,temp.rgb_temp);
        break;
        default:
            break;
        }
        ch = (char)getchar();
    }
}
int main(int argc, char *argv[])
{
    int ret = 0;
    /* download firmware to mx6300 */
    // int spifd =obc_sl_spi_open();
    /* 0。 cat usr config params */
    //cam_get_usr_cfg(argc, argv);
    int pra_index = 0;
    int init = 0;
    pra_index = find_pra_index_by_name("--pipeline", argc, argv);
    if (pra_index > 0)
    {
        init = !strcmp(argv[pra_index + 1], "init");
        log_always("will pipeline  be inited(init=%d)", init);
    }
    int stream_type = -1;
    pra_index = find_pra_index_by_name("--stream_type", argc, argv);
    if (pra_index > 0)
    {
        if (strcmp(argv[pra_index + 1], "ir") == 0)
        {
            stream_type = 1;
        }
        else if (strcmp(argv[pra_index + 1], "depth") == 0)
        {
            stream_type = 2;
        }
        log_always("stream type(%d)", stream_type);
    }
    int stream = -1;
    pra_index = find_pra_index_by_name("--stream", argc, argv);
    if (pra_index > 0)
    {
        if (strcmp(argv[pra_index + 1], "off") == 0)
        {
            stream = 0;
        }
        else if (strcmp(argv[pra_index + 1], "on") == 0)
        {
            stream = 1;
        }
        log_always("stream control operation(stream=%d)", stream);
    }
    sl_usr_cfg_ppl_t cfg_ppl = {0};
    //default action
    cfg_ppl.cam_id = 0;
    cfg_ppl.input_vidio_res.width = 1280;
    cfg_ppl.input_vidio_res.height = 1024;
    cfg_ppl.fps = 30;
    cfg_ppl.subsample_rate = 15;
    cfg_ppl.stream_type = STREAM_IR;

    switch (stream_type)
    {
    case 1:
        cfg_ppl.input_vidio_res.width = 1280;
        cfg_ppl.input_vidio_res.height = 1024;
        cfg_ppl.fps = 30;
        cfg_ppl.subsample_rate = 15;
        cfg_ppl.stream_type = STREAM_IR;
        break;
    case 2:
        cfg_ppl.input_vidio_res.width = 1024;
        cfg_ppl.input_vidio_res.height = 1280;
        cfg_ppl.fps = 30;
        cfg_ppl.subsample_rate = 15;
        cfg_ppl.stream_type = STREAM_DEPTH;
        break;
    default:
        break;
    }
    /* 1. init tof cam_src pipeline */
    if (init)
    {
        ret = init_sl_cam(&cfg_ppl);
    }
    if (stream == 0)
    {
        gspifd = obc_sl_spi_open();
        if (gspifd < 0)
        {
            printf("obc_sl_spi_open failed\n");
            return -1;
        }
        usleep(50000);
        sl_stream_off();
    }
    else if (stream == 1)
    {
        gspifd = obc_sl_spi_open();
        if (gspifd < 0)
        {
            printf("obc_sl_spi_open failed\n");
            return -1;
        }
        usleep(50000);
        sl_stream_on(cfg_ppl.stream_type);
    }
    /* 2. open tof cam_src pipeline to READY */
    //ret |= open_sl_cam(g_dev.sl_cam_id);
    //capture_cam_raw(1);
    //deinit_sl_cam(&g_dev.cam_pipeline_cfg);
    // obc_sl_spi_close(spifd);
    //close_sl_cam(g_dev.sl_cam_id);
    //remove_cam();
    //char a =getchar();
   gspifd =  obc_sl_spi_open_mini();
     if (gspifd < 0)
        {
            printf("obc_sl_spi_open_mini failed\n");
            return -1;
        }
    test_command();
     obc_sl_spi_close(gspifd);
}
#if 0
int main1(int argc, char *argv[])
{
    int pra_index = 0;
    sl_cam_raw_config_t obj;
    uint32_t frame_count = 1;
    uint32_t exp_time = 0;
    ar_mm_handle_t cur_handle = NULL;
    int cam_fd;
    int camera_id = 0;
    int cam_status = 0;

    pra_index = find_pra_index_by_name("--help", argc, argv);
    if (pra_index > 0)
    {
        printf("--help: show this help info\n");
        printf("--size w h: set cam out w && h,default is 1280 962\n");
        printf("--cam_id id: set cam id,default is 0\n");
        printf("--count frame_count: set the dump frames,the default is 1\n");
        printf("--subsample_rate  [rate]: set vif view subsample \n");
        printf("--fps: fps of camera \n");
        printf("--open: open obc_camera \n");
        printf("--close: close obc_camera \n");
        printf("--on: stream on \n");
        printf("--off: stream off \n");
        printf("--save: capture raw stream \n");
        printf("--init: init cam_src pipeline \n");
        printf("--remove: remove cam_src pipeline \n");
        printf("--test1: test all API in one thread n");
        return 0;
    }
    pra_index = find_pra_index_by_name("--count", argc, argv);
    if (pra_index > 0)
    {
        frame_count = atoi(argv[pra_index + 1]);
        printf("frame count: %d\n", frame_count);
    }

    /* camera_src init test */
    pra_index = find_pra_index_by_name("--init", argc, argv);
    if (pra_index > 0)
    {
        cam_get_usr_cfg(argc, argv);
        if (init_sl_cam(&g_dev.cam_pipeline_cfg) < 0)
        {
            printf("init camera failed!\n");
            // return -1;
        }
        // return 0;
    }

    /* camera open test */
    pra_index = find_pra_index_by_name("--open", argc, argv);
    if (pra_index > 0)
    {
        if (open_sl_cam(g_dev.sl_cam_id) < 0)
        {
            printf("Open camera failed!\n");
            // return -1;
        }
        // return 0;
    }

    /* camera close test */
    pra_index = find_pra_index_by_name("--close", argc, argv);
    if (pra_index > 0)
    {
        if (close_sl_cam(g_dev.sl_cam_id) < 0)
        {
            printf("Close camera failed!\n");
            // return -1;
        }
        // return 0;
    }

    /* camera stream on test */
    pra_index = find_pra_index_by_name("--on", argc, argv);
    if (pra_index > 0)
    {
        if (sl_cam_stream_on() < 0)
        {
            printf("on stream failed!\n");
            // return -1;
        }
        // return 0;
    }

    /* camera stream off test */
    pra_index = find_pra_index_by_name("--off", argc, argv);
    if (pra_index > 0)
    {
        if (sl_cam_stream_off() < 0)
        {
            printf("off stream failed!\n");
            // return -1;
        }
        // return 0;
    }

    /* camera_src remove test */
    pra_index = find_pra_index_by_name("--remove", argc, argv);
    if (pra_index > 0)
    {
        if (remove_cam() < 0)
        {
            printf("remove camera failed!\n");
            // return -1;
        }
        // return 0;
    }

    /* camera_src test all API */
    pra_index = find_pra_index_by_name("--test1", argc, argv);
    if (pra_index > 0)
    {
        if (one_thread_test(argc, argv) < 0)
        {
            printf("one_thread_test failed!\n");
        }
    }

    /* camera capture picture test */
    pra_index = find_pra_index_by_name("--save", argc, argv);
    if (pra_index > 0)
    {

        capture_cam_raw(frame_count);
    }
    return 0;
}
#endif
int obc_sl_read_flash(uint32_t addr, void *pdata, uint32_t len)
{
    int ret;
    spi_ctrl_msg ctrl_msg = {0};
#if 0
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_FLASH;
    ctrl_msg.regaddr = addr;
    ctrl_msg.pdata = pdata;
    ctrl_msg.dataLen = len;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
        printf("%s:read flash failed\n", __FUNCTION__);
        return OB_FAILURE;
    }
#else
    int cnt = len / 4096;
    int left = len % 4096;
    if (cnt > 0)
    {
        for (int i = 0; i < cnt; i++)
        {
            ctrl_msg.spi_fd = gspifd;
            ctrl_msg.dev_type = SPI_DEV_FLASH;
            ctrl_msg.regaddr = addr + i * 4096;
            ctrl_msg.pdata = pdata + i * 4096;
            ctrl_msg.dataLen = 4096;
            ret = obc_sl_spi_read(&ctrl_msg);
            if (ret < 0)
            {
                printf("%s:read data from flash failed(index =%d)\n", __FUNCTION__, i);
                return OB_FAILURE;
            }
            else
            {
                printf("%s:read data from flash completed(index =%d)\n", __FUNCTION__, i);
            }
            usleep(5000);
        }
    }

    if (left)
    {
        ctrl_msg.spi_fd = gspifd;
        ctrl_msg.dev_type = SPI_DEV_FLASH;
        ctrl_msg.regaddr = addr + cnt * 4096;
        ctrl_msg.pdata = pdata + cnt * 4096;
        ctrl_msg.dataLen = left;
        ret = obc_sl_spi_read(&ctrl_msg);
        if (ret < 0)
        {
            printf("%s:read data left from flash failed\n", __FUNCTION__);
            return OB_FAILURE;
        }
        else
        {
            printf("%s:read data left from flash completed\n", __FUNCTION__);
        }
    }
#endif
    return OB_SUCCESS;
}

int obc_sl_write_flash(uint32_t addr, void *pdata, uint32_t len)
{
    int ret;
    spi_ctrl_msg ctrl_msg = {0};
#if 1
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_FLASH;
    ctrl_msg.regaddr = addr;
    ctrl_msg.pdata = pdata;
    ctrl_msg.dataLen = len;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
        printf("%s:write flash failed\n", __FUNCTION__);
        return OB_FAILURE;
    }
#else
    int cnt = len / 4096;
    int left = len % 4096;
    if (cnt > 0)
    {
        for (int i = 0; i < cnt; i++)
        {
            ctrl_msg.spi_fd = gspifd;
            ctrl_msg.dev_type = SPI_DEV_FLASH;
            ctrl_msg.regaddr = addr + i * 4096;
            ctrl_msg.pdata = pdata + i * 4096;
            ctrl_msg.dataLen = 4096;
            ret = obc_sl_spi_write(&ctrl_msg);
            if (ret < 0)
            {
                printf("%s:write data to flash failed(index =%d)\n", __FUNCTION__, i);
                return OB_FAILURE;
            }
            else
            {
                printf("%s:write data to flash completed(index =%d)\n", __FUNCTION__, i);
            }
            usleep(5000);
        }
    }

    if (left)
    {
        ctrl_msg.spi_fd = gspifd;
        ctrl_msg.dev_type = SPI_DEV_FLASH;
        ctrl_msg.regaddr = addr + cnt * 4096;
        ctrl_msg.pdata = pdata + cnt * 4096;
        ctrl_msg.dataLen = left;
        ret = obc_sl_spi_write(&ctrl_msg);
        if (ret < 0)
        {
            printf("%s:write data left to flash failed\n", __FUNCTION__);
            return OB_FAILURE;
        }
        else
        {
            printf("%s:write data left to flash completed\n", __FUNCTION__);
        }
    }
#endif
    return OB_SUCCESS;
}
int obc_sl_erase_flash(uint32_t addr,uint32_t size)
{
    return obc_sl_spi_erase_flash(addr,size);
}
int obc_sl_setBaseAddr(uint32_t base_addr)
{
    return obc_sl_spi_mx6300_setBaseAddr(base_addr);
}

int obc_sl_send_rectify_params()
{
    return obc_sl_spi_send_rectify_param();
}