#include "uvc_service_sync.h"
#include "ar_log.h"
#include "ar_video_stream.h"
#include "ar_pipeline_ctrl.h"
#include "pipeline_ctl.h"
#include "ar_lancher.h"
#include "ar_cam_src.h"
#include "ar_customize_msg_type.h"
#include "ar_video_codec.h"

#include "pipeline_service.h"

typedef struct
{
    int args_num;
    char args[16][128];
}cmd_args_t;

void ar_uvc_get_context(void** context, uint32_t* context_size, uvc_server_t *server_l)
{
    ar_uvc_context_t * tmp = NULL;
    ar_facotry_element_obj_t uvc_init_list[] =
    {
        /* shoule match with context */
        {"pipeline","uvc_path",NULL},
        {"cam_src",{0},NULL},
        //{"tee",NULL,NULL},
        {"user_compositor",{0},NULL},
        {"hevc_encoder",{0},NULL},
        {"avc_encoder",{0},NULL},
        {"jpeg_encoder",{0},NULL},
        {"tee",{0},NULL},//yuv encoder for yuy2 and nv12
        {"icc_proxy_rpc_sink","uvc_sink",NULL},
        //{"jpeg_encoder",NULL,NULL},
        /* yuv element */
        {"tee",{0},NULL},
        {"icc_proxy_rpc_sink","video_yuv-0",NULL},
        {"tee",{0},NULL},
        {"icc_proxy_rpc_sink","video_yuv-1",NULL},
        {"tee",{0},NULL},
        {"display_sink",{0},NULL},
    };
    int flag = 0;

    if(NULL == *context)
    {
        *context = (void *)calloc(sizeof(uvc_init_list), 1);
        tmp = (ar_uvc_context_t *)uvc_init_list;
        flag = 1;
    }
    else
    {
        tmp = server_l->context;
    }

    sprintf((char *)&tmp->pipeline.object_name, "uvc_path-%d", server_l->pipe_index);
    sprintf((char *)&tmp->cam_src.object_name, "cam_src-%d", server_l->pipe_index);
    sprintf((char *)&tmp->hevc_enc.object_name, "hevc_encoder-%d", server_l->pipe_index);
    sprintf((char *)&tmp->avc_enc.object_name, "avc_encoder-%d", server_l->pipe_index);
    sprintf((char *)&tmp->mjpeg_enc.object_name, "jpeg_encoder-%d", server_l->pipe_index);
    sprintf((char *)&tmp->yuv_enc.object_name, "yuv_encoder-%d", server_l->pipe_index);
    sprintf((char *)&tmp->mjpeg_bs_sink.object_name, "uvc_sink-%d", server_l->pipe_index);
    sprintf((char *)&tmp->yuv_0_tee.object_name, "tee_0-%d", server_l->pipe_index);
    sprintf((char *)&tmp->yuv_0_sink.object_name, "video_yuv-0-%d", server_l->pipe_index);
    sprintf((char *)&tmp->yuv_1_tee.object_name, "tee_1-%d", server_l->pipe_index);
    sprintf((char *)&tmp->display_tee.object_name, "display_tee-%d", server_l->pipe_index);

    if (server_l->osd == 0) {
        sprintf((char *)&tmp->comp.object_name, "user_compositor-noosd-%d", server_l->pipe_index);
        sprintf((char *)&tmp->yuv_1_sink.object_name, "video_yuv-1-noosd-%d", server_l->pipe_index);
        log_info("pid %d pipe line %d disable osd.\n", getpid(), server_l->pipe_index);
    } else {
        sprintf((char *)&tmp->comp.object_name, "user_compositor-0");
        sprintf((char *)&tmp->yuv_1_sink.object_name, "video_yuv-1");
        //log_info("pid %d pipe line %d enable osd.\n", getpid(), server_l->pipe_index);
    }

    if(1 == flag)
    {
        memcpy(*context, tmp, sizeof(uvc_init_list));
    }
    *context_size = sizeof(uvc_init_list)/sizeof(ar_facotry_element_obj_t);

    //*context = (void*)&uvc_init_list;
    //*context_size = sizeof(uvc_init_list)/sizeof(ar_facotry_element_obj_t);

    return;
}

int find_pra_index_by_name(char *name,int argc, char *argv[])
{
    int i=0;
    for(i=0;i<argc;i++)
    {
        if(!strcmp(name,argv[i]))
        {
            return i;
        }
    }
    return -1;
}

static int find_cmd_pra_index_by_name(char *name,cmd_args_t *argv)
{
    int i=0;
    for(i=0;i<argv->args_num;i++)
    {
        if(!strcmp(name,argv->args[i]))
        {
            return i;
        }
    }
    return -1;
}

cmd_args_t *get_args(const char *cmd)
{
    cmd_args_t * args=(cmd_args_t *)malloc(sizeof(cmd_args_t));
    char *p_cmd=(char *)malloc(1024);
    char *p_str=NULL;
    char  *split_char=" ";
    char *p_free_p_cmd=p_cmd;
    memset(args,0,sizeof(cmd_args_t));
    strcpy(p_cmd,cmd);
    p_str=strtok(p_cmd,split_char);
    if(p_str)
    {
        strcpy(&args->args[args->args_num][0],p_str);
        args->args_num++;
    }

    while(p_str)
    {
        p_str=strtok(NULL,split_char);
        if(p_str)
        {
            strcpy(&args->args[args->args_num][0],p_str);
            args->args_num++;
        }
    }
    free(p_free_p_cmd);
    return args;
}

static void uvc_process_msg(ar_multimedia_message_t* msg, void* user_data)
{
    printf("got msg\n");

    uvc_server_t *server_l = (uvc_server_t *)user_data;
    if(!server_l || !msg)
    {
        printf("error : empty input\n");
        return;
    }

    if(AR_MM_MESSAGE_CUSTOMIZE != msg->type)
    {
        return;
    }

    ar_pipeline_t p_pipeline = ( ar_pipeline_t )msg->from_pipeline;
    //ar_element_t p_trigger_element = ( ar_element_t )msg->from_element;

    switch(msg->msg_id)
    {
        case AR_CAM_SENSOR_RUNTIME_DETECT_STREAM_TIMEOUT :
            printf("stream time-out pipeline 0x%x state 0x%x element 0x%x\n"\
                , msg->from_pipeline \
                , msg->pipeline_state \
                , msg->from_element );

            BUFFER_SINK_PORT_TIMEOUT_pra_t* param_stream_timeout = \
                (BUFFER_SINK_PORT_TIMEOUT_pra_t*)ar_mm_message_get_property_value((ar_multimedia_message_t*)msg, AR_CAM_SENSOR_MSG_BUFFER_SINK_STREAM_TIMEOUT);

            printf("buffer sink time out : cam_id %d \n", param_stream_timeout->cam_id );

            if(server_l->err_process)
			{
                printf("!!!!!!!!!!!!pipeline terminal\n");
                ar_pipeline_terminal_stream(server_l->handle, p_pipeline);
                log_always("!!!!!!!!!!!!pipeline set ready");
                ar_element_set_state(server_l->handle\
                    ,p_pipeline,AR_ELEMENT_STATE_READY);
            }
            else
            {
                log_always("no err process");
            }
            break;
        default:
	        break;
     }
     return;
}

void ar_uvc_init(uvc_server_t *server_l, ar_mm_handle_t handle,int argc, char *argv[])
{
    uint32_t width = 1920, height = 1080;
    int queue_depth = 3;
    int vfe_en=0;
    int num=30;
    int den=1;
    int qp_coef = 3;
    int tee_copy=0;
    int tee_pad_num=0;
    int tee_copy_bufffer_num=5;
    int face_stats=0;
    int index = 0;

    if(1 == server_l->is_hdr)
    {
        vfe_en = 1;
    }

    index=find_pra_index_by_name("--face_stats",argc,argv);
    if(index>0)
    {
        face_stats=1;
    }

    index=find_pra_index_by_name("--tee_copy",argc,argv);
    if(index>0)
    {
        tee_copy=1;
        tee_pad_num=atoi(argv[index+1]);
        tee_copy_bufffer_num=atoi(argv[index+2]);
    }

    //ar_jpeg_remote_service_init();
    if(ar_element_factory_make_many(handle,server_l->context_size,(ar_facotry_element_obj_t*)server_l->context) != AR_SUCCESS){
        return;
    }
    /* change cam src property */
    ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_CAM_SET_ID,&server_l->pipe_index,sizeof(server_l->pipe_index));
    if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc || 0 == server_l->dev->fcc)
    {
        ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_CAM_SET_ID,&server_l->pipe_index,sizeof(server_l->pipe_index));
        ar_element_modify_property_value(handle,server_l->context->mjpeg_enc.element,AR_VIDEO_CODEC_META_QP,&qp_coef,sizeof(qp_coef));
        //printf("mjpeg_enc: %s\n", server_l->context->mjpeg_enc.facotry_name);
    }
    /*else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
    {

    }*/

    log_always("vfe_en=%d multi=%d",vfe_en,server_l->multi);
    if(vfe_en)
    {
        if(server_l->multi)
        {
            ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE,strlen(AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE)+1);
        }else
        {
            ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
        }
        ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DDR,strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DDR)+1);
        ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_CAM_SET_VFE_EN,&vfe_en,sizeof(vfe_en));
        ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_SET_SOFTWARE_FACE_STATS,&face_stats,sizeof(int));
    }else
    {
        if(server_l->multi)
        {
            ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE,strlen(AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE)+1);
            ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DDR,strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DDR)+1);
        }else
        {
            if(face_stats||server_l->force_isp_ddr_mode)
            {
                ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
                ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DDR,strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DDR)+1);
            }
            else
            {
               ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL)+1);
               ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT,strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT)+1);
            }
        }
        ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_CAM_SET_VFE_EN,&vfe_en,sizeof(vfe_en));
        ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_SET_SOFTWARE_FACE_STATS,&face_stats,sizeof(int));
    }


    //add hw sync property
    ar_element_modify_property_value(handle,server_l->context->cam_src.element,AR_VIDEO_SET_HW_SYNC,&server_l->hw_sync,sizeof(int));

    width = server_l->width[0];
    height = server_l->height[0];
    log_always("res0 w=%d h=%d",width,height);
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,server_l->context->cam_src.element, 0),AR_COMMON_META_VIDEO_WIDTH_NAME,&width,sizeof(int));
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,server_l->context->cam_src.element, 0),AR_COMMON_META_VIDEO_HEIGHT_NAME,&height,sizeof(int));
    width = server_l->width[1];
    height = server_l->height[1];
    log_always("res1 w=%d h=%d",width,height);
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,server_l->context->cam_src.element, 1),AR_COMMON_META_VIDEO_WIDTH_NAME,&width,sizeof(int));
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,server_l->context->cam_src.element, 1),AR_COMMON_META_VIDEO_HEIGHT_NAME,&height,sizeof(int));

    //set fps
    num = server_l->fps;
    log_always("fps=%d",num);
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,server_l->context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&num,sizeof(int));
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,server_l->context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,server_l->context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&num,sizeof(int));
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,server_l->context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));

    if(NULL != server_l->dev && V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
    {
        uint32_t bitrate = __DEFAULT_HEVC_BITRATE__;
        ar_element_modify_property_value(handle, server_l->context->hevc_enc.element,AR_VIDEO_CODEC_META_BITRATE, &bitrate, sizeof(uint32_t));
    }

    if(NULL != server_l->dev && V4L2_PIX_FMT_H264 == server_l->dev->fcc)
    {
        uint32_t bitrate = __DEFAULT_H264_BITRATE__;
        ar_element_modify_property_value(handle, server_l->context->avc_enc.element,AR_VIDEO_CODEC_META_BITRATE, &bitrate, sizeof(uint32_t));
    }

    /* change icc_proxy_sink property */
    ar_element_modify_property_value(handle,server_l->context->yuv_0_sink.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth,sizeof(int));
    ar_element_modify_property_value(handle,server_l->context->yuv_1_sink.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth,sizeof(int));

    //set the tee copy bit for pad 0
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, server_l->context->yuv_0_tee.element,tee_pad_num),
                               AR_COMMON_META_TEE_COPY_PROP,&tee_copy,sizeof(uint32_t));
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, server_l->context->yuv_0_tee.element, tee_pad_num),
                               AR_COMMON_META_TEE_COPY_BUFFER_COUNT,&tee_copy_bufffer_num,sizeof(uint32_t));

    //add monitor
    ar_mm_message_add_monitor_pipelines(handle,server_l->context->pipeline.element, NULL);
    /* add all element to pipeline/subpipe */

    if(server_l->use_display)
    {
        if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc)
            ar_pipeline_add_many(handle,(ar_pipeline_t)server_l->context->pipeline.element,
                                server_l->context->cam_src.element, server_l->context->yuv_0_tee.element, server_l->context->yuv_0_sink.element, \
                                server_l->context->yuv_1_sink.element, server_l->context->comp.element,
                                server_l->context->mjpeg_enc.element, server_l->context->mjpeg_bs_sink.element, server_l->context->display_tee.element, server_l->context->display.element,NULL);
        else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
            ar_pipeline_add_many(handle,(ar_pipeline_t)server_l->context->pipeline.element,
                                server_l->context->cam_src.element, server_l->context->yuv_0_tee.element, server_l->context->yuv_0_sink.element, \
                                server_l->context->yuv_1_sink.element, server_l->context->comp.element,
                                server_l->context->hevc_enc.element, server_l->context->mjpeg_bs_sink.element, server_l->context->display_tee.element, server_l->context->display.element,NULL);
        else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
            ar_pipeline_add_many(handle,(ar_pipeline_t)server_l->context->pipeline.element,
                                server_l->context->cam_src.element, server_l->context->yuv_0_tee.element, server_l->context->yuv_0_sink.element, \
                                server_l->context->yuv_1_sink.element, server_l->context->comp.element,
                                server_l->context->avc_enc.element, server_l->context->mjpeg_bs_sink.element, server_l->context->display_tee.element, server_l->context->display.element,NULL);
        else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc)
            ar_pipeline_add_many(handle,(ar_pipeline_t)server_l->context->pipeline.element,
                                server_l->context->cam_src.element, server_l->context->yuv_0_tee.element, server_l->context->yuv_0_sink.element, \
                                server_l->context->yuv_1_sink.element, server_l->context->comp.element,
                                server_l->context->yuv_enc.element, server_l->context->mjpeg_bs_sink.element, server_l->context->display_tee.element, server_l->context->display.element,NULL);

    }
    else
    {
        if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc)
            ar_pipeline_add_many(handle,(ar_pipeline_t)server_l->context->pipeline.element,
                                server_l->context->cam_src.element, server_l->context->yuv_0_tee.element, server_l->context->yuv_0_sink.element, \
                                server_l->context->yuv_1_sink.element, server_l->context->comp.element,
                                server_l->context->mjpeg_enc.element, server_l->context->mjpeg_bs_sink.element, NULL);
        else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
            ar_pipeline_add_many(handle,(ar_pipeline_t)server_l->context->pipeline.element,
                                server_l->context->cam_src.element, server_l->context->yuv_0_tee.element, server_l->context->yuv_0_sink.element, \
                                server_l->context->yuv_1_sink.element, server_l->context->comp.element,
                                server_l->context->hevc_enc.element, server_l->context->mjpeg_bs_sink.element, NULL);
        else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
            ar_pipeline_add_many(handle,(ar_pipeline_t)server_l->context->pipeline.element,
                                server_l->context->cam_src.element, server_l->context->yuv_0_tee.element, server_l->context->yuv_0_sink.element, \
                                server_l->context->yuv_1_sink.element, server_l->context->comp.element,
                                server_l->context->avc_enc.element, server_l->context->mjpeg_bs_sink.element, NULL);
        else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc)
            ar_pipeline_add_many(handle,(ar_pipeline_t)server_l->context->pipeline.element,
                                server_l->context->cam_src.element, server_l->context->yuv_0_tee.element, server_l->context->yuv_0_sink.element, \
                                server_l->context->yuv_1_sink.element, server_l->context->comp.element,
                                server_l->context->yuv_enc.element, server_l->context->mjpeg_bs_sink.element, NULL);
    }
    /* link pads */
    ar_pad_link_by_element(handle,server_l->context->cam_src.element,0,server_l->context->yuv_0_tee.element, 0);
    ar_pad_link_by_element(handle,server_l->context->yuv_0_tee.element, 0,server_l->context->comp.element, 0);
    if(server_l->use_display)
    {
        //set dispaly out put
        int disp_width = server_l->disp_w;
        int disp_height = server_l->disp_h;
        int fix_fps =server_l->fix_fps;
        ar_element_modify_property_value(handle,server_l->context->display.element,AR_DISPLAY_META_OUT_WIDTH,&disp_width,sizeof(int));
        ar_element_modify_property_value(handle,server_l->context->display.element,AR_DISPLAY_META_OUT_HEIGHT,&disp_height,sizeof(int));
        ar_element_modify_property_value(handle,server_l->context->display.element,AR_DISPLAY_META_FIX_FPS,&fix_fps,sizeof(int));
        ar_pad_link_by_element(handle,server_l->context->comp.element, 0,server_l->context->display_tee.element, 0);
        ar_pad_link_by_element(handle,server_l->context->display_tee.element, 0,server_l->context->display.element, 0);

        if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc || 0 == server_l->dev->fcc)
            ar_pad_link_by_element(handle,server_l->context->display_tee.element, 1,server_l->context->mjpeg_enc.element, 0);
        else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
            ar_pad_link_by_element(handle,server_l->context->display_tee.element, 1,server_l->context->hevc_enc.element, 0);
        else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
            ar_pad_link_by_element(handle,server_l->context->display_tee.element, 1,server_l->context->avc_enc.element, 0);
        else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc)
            ar_pad_link_by_element(handle,server_l->context->display_tee.element, 1,server_l->context->yuv_enc.element, 0);
    }
    else
    {
        if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc || 0 == server_l->dev->fcc)
            ar_pad_link_by_element(handle,server_l->context->comp.element, 0,server_l->context->mjpeg_enc.element, 0);
        else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
            ar_pad_link_by_element(handle,server_l->context->comp.element, 0,server_l->context->hevc_enc.element, 0);
        else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
            ar_pad_link_by_element(handle,server_l->context->comp.element, 0,server_l->context->avc_enc.element, 0);
        else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc)
            ar_pad_link_by_element(handle,server_l->context->comp.element, 0,server_l->context->yuv_enc.element, 0);
    }
    ar_pad_link_by_element(handle,server_l->context->yuv_0_tee.element, 1,server_l->context->yuv_0_sink.element, 0);
    ar_pad_link_by_element(handle,server_l->context->cam_src.element, 1,server_l->context->yuv_1_sink.element, 0);

    if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc || 0 == server_l->dev->fcc)
        ar_pad_link_by_element(handle,server_l->context->mjpeg_enc.element, 0,server_l->context->mjpeg_bs_sink.element,0);
    else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
        ar_pad_link_by_element(handle,server_l->context->hevc_enc.element, 0,server_l->context->mjpeg_bs_sink.element,0);
    else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
        ar_pad_link_by_element(handle,server_l->context->avc_enc.element, 0,server_l->context->mjpeg_bs_sink.element,0);
    else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc)
        ar_pad_link_by_element(handle,server_l->context->yuv_enc.element, 0,server_l->context->mjpeg_bs_sink.element,0);

    if(0 == server_l->first_inited)
    {
        ar_element_set_state(handle,(ar_pipeline_t)server_l->context->pipeline.element,AR_ELEMENT_STATE_READY);
        server_l->first_inited = 1;
    }

    //we register a message to detected sensor msg
    /* create message thread */
    int32_t ret = ar_mm_message_thread_create(handle,
                                    NULL,
                                    uvc_process_msg,
                                    (void*)(server_l) );

    if(ret != AR_MULTIMEDIA_SUCCESS){
        log_err("to create msg proc  failed");
    }
}

void ar_uvc_deinit(uvc_server_t     *server_l, ar_mm_handle_t handle)
{
    //int32_t             ret;
    //int32_t             i;

    ar_mm_message_thread_destory(handle);

    if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc || 0 == server_l->dev->fcc)
        ar_pad_unlink_by_element(handle,server_l->context->mjpeg_enc.element, 0,server_l->context->mjpeg_bs_sink.element,0);
    else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
        ar_pad_unlink_by_element(handle,server_l->context->hevc_enc.element, 0,server_l->context->mjpeg_bs_sink.element,0);
    else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
        ar_pad_unlink_by_element(handle,server_l->context->avc_enc.element, 0,server_l->context->mjpeg_bs_sink.element,0);
    else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc)
        ar_pad_unlink_by_element(handle,server_l->context->yuv_enc.element, 0,server_l->context->mjpeg_bs_sink.element,0);

    ar_pad_unlink_by_element(handle,server_l->context->cam_src.element, 1,server_l->context->yuv_1_sink.element, 0);
    ar_pad_unlink_by_element(handle,server_l->context->yuv_0_tee.element, 1,server_l->context->yuv_0_sink.element, 0);

    if(server_l->use_display)
    {
        if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc || 0 == server_l->dev->fcc)
            ar_pad_unlink_by_element(handle,server_l->context->display_tee.element, 1,server_l->context->mjpeg_enc.element, 0);
        else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
            ar_pad_unlink_by_element(handle,server_l->context->display_tee.element, 1,server_l->context->hevc_enc.element, 0);
        else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
            ar_pad_unlink_by_element(handle,server_l->context->display_tee.element, 1,server_l->context->avc_enc.element, 0);
        else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc)
            ar_pad_unlink_by_element(handle,server_l->context->display_tee.element, 1,server_l->context->yuv_enc.element, 0);

        ar_pad_unlink_by_element(handle,server_l->context->display_tee.element, 0,server_l->context->display.element, 0);
        ar_pad_unlink_by_element(handle,server_l->context->comp.element, 0,server_l->context->display_tee.element, 0);
    }
    else
    {
        if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc || 0 == server_l->dev->fcc)
            ar_pad_unlink_by_element(handle,server_l->context->comp.element, 0,server_l->context->mjpeg_enc.element, 0);
        else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
            ar_pad_unlink_by_element(handle,server_l->context->comp.element, 0,server_l->context->hevc_enc.element, 0);
        else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
            ar_pad_unlink_by_element(handle,server_l->context->comp.element, 0,server_l->context->avc_enc.element, 0);
        else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc)
            ar_pad_unlink_by_element(handle,server_l->context->comp.element, 0,server_l->context->yuv_enc.element, 0);
    }

    ar_pad_unlink_by_element(handle,server_l->context->yuv_0_tee.element, 0,server_l->context->comp.element, 0);
    ar_pad_unlink_by_element(handle,server_l->context->cam_src.element,0,server_l->context->yuv_0_tee.element, 0);

    ar_pipeline_remove_all(handle,(ar_pipeline_t)server_l->context->pipeline.element);

    /*for(i = 0; i < context_size; ++i)
    {
        ar_facotry_element_obj_t* list = (ar_facotry_element_obj_t*)context;
        ar_element_factory_destory(handle, list[i].element);
    }*/
}

int get_fcc_index(uvc_server_t *server_l, struct uvc_format_info *format, int fcc)
{
    int ret = -1, i = 0;
    for(i = 0; i < server_l->uvc_formats_num; ++i)
    {
        if(format[i].fcc == fcc)
            return i;
    }
    return ret;
}

int uvc_pipeline_set_stop(uvc_server_t *server_l)
{
    int i;

    if(NULL == server_l || NULL == server_l->handle)
    {
        log_err("check failed!\n");
        return -1;
    }

    for(i = 0; i < server_l->slave_num; ++i)
    {
        uvc_server_t * slave_l = server_l->slave[i];

        ar_pipeline_terminal_stream(slave_l->handle, (ar_pipeline_t)slave_l->context->pipeline.element);
    }

    return ar_pipeline_terminal_stream(server_l->handle, (ar_pipeline_t)server_l->context->pipeline.element);
}

int uvc_pipeline_set_start(uvc_server_t *server_l)
{
    int i, ret;
    int stat = 0;

    if(NULL == server_l || NULL == server_l->handle)
    {
        log_err("check failed!\n");
        return -1;
    }

    for(i = 0; i < server_l->slave_num; ++i)
    {
        uvc_server_t * slave_l = server_l->slave[i];

        ar_pipeline_start_stream_nonblocking(slave_l->handle, (ar_pipeline_t)slave_l->context->pipeline.element);

        while(*(server_l->run_flag))
        {
            ret = ar_cam_src_get_sensor_stats(slave_l->pipe_index, &stat);
            if(0 == ret)
            {
                if(1 == stat)
                {
                    //printf("slave %d pipe_index %d state %d\n", i, slave_l->pipe_index, stat);
                    break;
                }
            }
            else
            {
                //printf("get sensor stats failed!\n");
            }
            usleep(10 * 1000);
        }

        log_always("slave %d wait success!\n", i);
    }

    return ar_pipeline_start_stream(server_l->handle, (ar_pipeline_t)server_l->context->pipeline.element);
}

int uvc_pipeline_set_format(uvc_server_t *server_l, unsigned int width, unsigned int height, unsigned int fps, unsigned int fcc)
{
    int pipe_fd = -1, ret = -1, den_num = 1;

    pipe_fd = server_l->pipe_line_fd;
    if(pipe_fd < 0 || NULL == server_l->handle)
    {
        log_err("uvc_pipeline_set_format check failed!(%d %p)\n", pipe_fd, server_l->handle);
        return ret;
    }

    if(server_l->is_hdr)
    {
        fps=25;
    }

    //ret = ar_pipeline_terminal_stream(server_l->handle, (ar_pipeline_t)context->pipeline.element);

    if(server_l->dev->fcc != fcc)
    {
        unsigned int                fcc_index;
        struct uvc_format_opt     * format_opt;
        //char *p2 = (char *)&fcc;

        fcc_index = server_l->dev->fcc_index;
        format_opt  = server_l->uvc_formats[fcc_index].data->format_opt;

        //printf("change format to %c%c%c%c(%d x %d @%d fps)\n", p2[0], p2[1], p2[2], p2[3], width, height, fps);

        ret = format_opt->format_deinit(server_l, server_l->uvc_formats[fcc_index].data, server_l->handle);

        server_l->dev->fcc = fcc;
        server_l->dev->fcc_index = get_fcc_index(server_l, server_l->uvc_formats, fcc);
        fcc_index = server_l->dev->fcc_index;
        format_opt  = server_l->uvc_formats[fcc_index].data->format_opt;

        ret = format_opt->format_init(server_l, server_l->uvc_formats[fcc_index].data, server_l->handle, server_l->argc, server_l->argv);
    }

    //if(V4L2_PIX_FMT_NV12 == fcc || V4L2_PIX_FMT_YUYV == fcc)
    if(V4L2_PIX_FMT_H264 == fcc || V4L2_PIX_FMT_HEVC == fcc)
    {
        struct framebased_priv_data * priv_data = server_l->uvc_formats[server_l->dev->fcc_index].data->priv;
        priv_data->i_frame_for_start = 0;
    }

    ret = ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,server_l->context->cam_src.element, 0),AR_COMMON_META_VIDEO_WIDTH_NAME,&width,sizeof(int));
    ret = ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,server_l->context->cam_src.element, 0),AR_COMMON_META_VIDEO_HEIGHT_NAME,&height,sizeof(int));
    ret = ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,server_l->context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&fps,sizeof(int));
    ret = ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,server_l->context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den_num,sizeof(int));
    ret = ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,server_l->context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&fps,sizeof(int));
    ret = ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,server_l->context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den_num,sizeof(int));

    //ret = ar_pipeline_start_stream(server_l->handle, (ar_pipeline_t)context->pipeline.element);

    return ret;
}

static int pipeline_clt_stop(pipeline_ctl_server_t *server_l)
{
    uvc_server_t   *server_uvc = (uvc_server_t *)server_l->usr_data;
    int             pipe_fd = server_uvc->pipe_line_fd;
    int             ret=-1;

    ret = ar_pipeline_ctrl_pause_stream(pipe_fd);
    log_always("ar_pipeline_ctrl_pause_stream ret=%d",ret);
    ret = ar_pipeline_ctrl_stop_stream(pipe_fd);
    log_always("ar_pipeline_ctrl_stop_stream ret=%d",ret);
    return 0;
}
static int pipeline_clt_start(pipeline_ctl_server_t *server_l)
{
    uvc_server_t   *server_uvc = (uvc_server_t *)server_l->usr_data;
    int             pipe_fd =server_uvc->pipe_line_fd;
    int             ret=-1;

    ret = ar_pipeline_ctrl_start_stream(pipe_fd);
    log_always("ar_pipeline_ctrl_start_stream ret=%d",ret);
    return 0;
}

static int pipeline_clt_set_prop_uvc(pipeline_ctl_server_t *server_l, char *arg, int len)
{
    uvc_server_t   *server_uvc = (uvc_server_t *)server_l->usr_data;
    cmd_args_t     *args = get_args(arg);

    int index = find_cmd_pra_index_by_name("--hdr",args);
    if(index>=0)
    {
        int vfe_en = atoi(args->args[index+1]);
        log_always("set_hdr vfe_en=%d multi=%d",vfe_en,server_uvc->multi);
        if(vfe_en)
        {
            if(server_uvc->multi)
            {
                ar_element_modify_property_value(server_uvc->handle,server_uvc->context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
                ar_element_modify_property_value(server_uvc->handle,server_uvc->context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DDR,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
            }
            else
            {
                ar_element_modify_property_value(server_uvc->handle,server_uvc->context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
                ar_element_modify_property_value(server_uvc->handle,server_uvc->context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DDR,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
            }
            ar_element_modify_property_value(server_uvc->handle,server_uvc->context->cam_src.element,AR_VIDEO_CAM_SET_VFE_EN,&vfe_en,sizeof(int));
        }
        else
        {
            if(server_uvc->multi)
            {
                ar_element_modify_property_value(server_uvc->handle,server_uvc->context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
                ar_element_modify_property_value(server_uvc->handle,server_uvc->context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DDR,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
            }
            else
            {
                ar_element_modify_property_value(server_uvc->handle,server_uvc->context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL)+1);
                ar_element_modify_property_value(server_uvc->handle,server_uvc->context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT,strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT)+1);
            }
            ar_element_modify_property_value(server_uvc->handle,server_uvc->context->cam_src.element,AR_VIDEO_CAM_SET_VFE_EN,&vfe_en,sizeof(int));
        }
    }

    index = find_cmd_pra_index_by_name("--fps",args);
    if(index >=0)
    {
        int num = atoi(args->args[index+1]);
        int den = 1;
        log_always("set fps =%d",num);
        ar_pad_modify_meta_value(server_uvc->handle,ar_element_get_src_pad_by_idx(server_uvc->handle,server_uvc->context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&num,sizeof(int));
        ar_pad_modify_meta_value(server_uvc->handle,ar_element_get_src_pad_by_idx(server_uvc->handle,server_uvc->context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));
        ar_pad_modify_meta_value(server_uvc->handle,ar_element_get_src_pad_by_idx(server_uvc->handle,server_uvc->context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&num,sizeof(int));
        ar_pad_modify_meta_value(server_uvc->handle,ar_element_get_src_pad_by_idx(server_uvc->handle,server_uvc->context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));
    }


    index = find_cmd_pra_index_by_name("--res",args);
	if(index >=0)
	{
         int w= atoi(args->args[index+1]);
         int h= atoi(args->args[index+2]);
		 log_always("set w h =(%d %d)",w,h);
		 ar_pad_modify_meta_value(server_uvc->handle,ar_element_get_src_pad_by_idx(server_uvc->handle,server_uvc->context->cam_src.element, 0),AR_COMMON_META_VIDEO_WIDTH_NAME,&w,sizeof(int));
		 ar_pad_modify_meta_value(server_uvc->handle,ar_element_get_src_pad_by_idx(server_uvc->handle,server_uvc->context->cam_src.element, 0),AR_COMMON_META_VIDEO_HEIGHT_NAME,&h,sizeof(int));
	}

    free(args);
    return 0;
}

static int pipeline_clt_set_prop(pipeline_ctl_server_t *server_l,char *arg,int len)
{
    pipeline_clt_set_prop_uvc(server_l,arg,len);
    return 0;
}

server_api_ops_t api_ops = {
    .ar_pipeline_clt_stop=pipeline_clt_stop,
    .ar_pipeline_clt_start=pipeline_clt_start,
    .ar_pipeline_clt_set_prop=pipeline_clt_set_prop,
};

