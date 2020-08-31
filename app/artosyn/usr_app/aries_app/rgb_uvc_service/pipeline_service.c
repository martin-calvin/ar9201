#include "uvc_service2.h"
#include "ar_log.h"
#include "ar_video_stream.h"
#include "ar_pipeline_ctrl.h"
#include "pipeline_ctl.h"
#include "ar_lancher.h"
#include "ar_cam_src.h"

#include "pipeline_service.h"
#include "ar_customize_msg_type.h"
#include "ar_video_codec.h"
#include "logutil.h"

typedef struct
{
    int args_num;
    char args[16][128];
}cmd_args_t;

//const char encoder_hevc[]   = {"hevc_encoder"};
//const char encoder_avc[]    = {"avc_encoder"};
//const char encoder_mjpg[]   = {"jpeg_encoder"};

void ar_uvc_get_context(void** context, uint32_t* context_size)
{
    /* 初始化uvc_init_list; (初始化后需要使用: ar_element_factory_make_many将其传送到FreeRTOS端进行创建) */

    static ar_facotry_element_obj_t uvc_init_list[] =
    {
        /* shoule match with context */
        {"pipeline", "uvc_path", NULL},
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
        
    uvc_server_t *server_l = get_uvc_server();

    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->pipeline.object_name, "uvc_path-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->cam_src.object_name, "cam_src-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->hevc_enc.object_name, "hevc_encoder-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->avc_enc.object_name, "avc_encoder-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->mjpeg_enc.object_name, "jpeg_encoder-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->yuv_enc.object_name, "yuv_encoder-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->mjpeg_bs_sink.object_name, "uvc_sink-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->yuv_0_tee.object_name, "tee_0-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->yuv_0_sink.object_name, "video_yuv-0-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->yuv_1_tee.object_name, "tee_1-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->display_tee.object_name, "display_tee-%d", server_l->pipe_index);

    if (server_l->osd == 0) {
        sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->comp.object_name, "user_compositor-noosd-%d", server_l->pipe_index);
        sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->yuv_1_sink.object_name, "video_yuv-1-noosd-%d", server_l->pipe_index);
        //INFO("pid %d pipe line %d disable osd.\n", getpid(), server_l->pipe_index);
    } else {
        sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->comp.object_name, "user_compositor-0");
        sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->yuv_1_sink.object_name, "video_yuv-1");
        //INFO("pid %d pipe line %d enable osd.\n", getpid(), server_l->pipe_index);
    }

    *context = (void*)&uvc_init_list;
    *context_size = sizeof(uvc_init_list)/sizeof(ar_facotry_element_obj_t);

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
    DBG("got msg type:%d, msg id:0x%x\n", msg->type, msg->msg_id);

    uvc_server_t *server_l = get_uvc_server();
    if(!server_l || !msg)
    {
        ERR("error : empty input\n");
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
                INFO("!!!!!!!!!!!!pipeline set ready");
                ar_element_set_state(server_l->handle, p_pipeline, AR_ELEMENT_STATE_READY);
            }
            else
            {
                INFO("no err process\n");
            }
            break;
        default:
	        break;
     }
     return;
}


/*****************************************************************************
*   Prototype    : ar_uvc_init
*   Description  : uvc的pipeline配置
*   Input        : ar_mm_handle_t handle  
*                  int argc               
*                  char *argv[]           
*   Output       : None
*   Return Value : void
*****************************************************************************/
void ar_uvc_init(ar_mm_handle_t handle,int argc, char *argv[])
{
    uint32_t width = RGB_SENSOR_WIDTH, height = RGB_SENSOR_HEIGHT;
    int queue_depth = 3;
    ar_uvc_context_t *context = NULL;
    uint32_t context_size = 0;
    int vfe_en = 0;
    int num = 30; //fps
    int den = 1;
    int qp_coef = 3; //Mjpeg编码qp值
    int tee_copy = 0;
    int tee_pad_num = 0;
    int tee_copy_bufffer_num = 5;
    int face_stats = 0;
    
    uvc_server_t *server_l = get_uvc_server();
    server_l->is_hdr = 0;
    server_l->osd = 0;


    INFO("xavier, start create rgb pipeline!\n");

    //[1] 初始化uvc_init_list
    ar_uvc_get_context((void**)&context, &context_size);


    //[2] 初始化uvc_init_list后需要使用: ar_element_factory_make_many将其传送到FreeRTOS端进行创建)
    if(ar_element_factory_make_many(handle,context_size,(ar_facotry_element_obj_t*)context) != AR_SUCCESS){
        return;
    }


    //[3] 通过 ar_element_modify_property_value 设置属性;
        //通过 ar_pad_modify_meta_value 设置meta value
    /* change cam src property */
    ar_element_modify_property_value(handle, context->cam_src.element, AR_VIDEO_CAM_SET_ID, &server_l->pipe_index, sizeof(server_l->pipe_index));
    if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc || 0 == server_l->dev->fcc)
    {
        ar_element_modify_property_value(handle, context->cam_src.element, AR_VIDEO_CAM_SET_ID, &server_l->pipe_index, sizeof(server_l->pipe_index));
        ar_element_modify_property_value(handle, context->mjpeg_enc.element, AR_VIDEO_CODEC_META_QP, &qp_coef, sizeof(qp_coef));
        //printf("mjpeg_enc: %s\n", context->mjpeg_enc.facotry_name);
    }

    INFO("vfe_en=%d multi=%d\n", vfe_en, server_l->multi);
    if(vfe_en)
    {
        if(server_l->multi)
        {
            ar_element_modify_property_value(handle, context->cam_src.element, AR_VIDEO_CAM_MODE, AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE, strlen(AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE)+1);
        }
        else
        {
            ar_element_modify_property_value(handle, context->cam_src.element, AR_VIDEO_CAM_MODE, AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE, strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
        }
        ar_element_modify_property_value(handle, context->cam_src.element, AR_VIDEO_CAM_VIF_ISP_MOD, AR_VIDEO_CAM_VIF_ISP_MOD_DDR, strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DDR)+1);
        ar_element_modify_property_value(handle, context->cam_src.element, AR_VIDEO_CAM_SET_VFE_EN, &vfe_en, sizeof(vfe_en));
        ar_element_modify_property_value(handle, context->cam_src.element, AR_VIDEO_SET_SOFTWARE_FACE_STATS, &face_stats, sizeof(int));
    }
    else
    {
        if(server_l->multi)
        {
            ar_element_modify_property_value(handle, context->cam_src.element, AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE,strlen(AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE)+1);
            ar_element_modify_property_value(handle, context->cam_src.element, AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DDR,strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DDR)+1);
        }
        else
        {
            if(face_stats||server_l->force_isp_ddr_mode)
            {
                ar_element_modify_property_value(handle,context->cam_src.element, AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
                ar_element_modify_property_value(handle,context->cam_src.element, AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DDR,strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DDR)+1);
            }
            else
            {
               ar_element_modify_property_value(handle,context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL)+1);
               ar_element_modify_property_value(handle,context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT,strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT)+1);
            }
        }
        ar_element_modify_property_value(handle,context->cam_src.element,AR_VIDEO_CAM_SET_VFE_EN,&vfe_en,sizeof(vfe_en));
        ar_element_modify_property_value(handle,context->cam_src.element,AR_VIDEO_SET_SOFTWARE_FACE_STATS,&face_stats,sizeof(int));
    }
    //add hw sync property
	ar_element_modify_property_value(handle,context->cam_src.element,AR_VIDEO_SET_HW_SYNC,&server_l->hw_sync,sizeof(int));


    width  = server_l->width[0];
    height = server_l->height[0];
    INFO("res0 w=%d h=%d\n", width, height);
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_WIDTH_NAME,&width,sizeof(int));
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_HEIGHT_NAME,&height,sizeof(int));

    //width  = server_l->width[1];
    //height = server_l->height[1];
    //INFO("res1 w=%d h=%d\n", width, height);
    //ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_WIDTH_NAME,&width,sizeof(int));
    //ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_HEIGHT_NAME,&height,sizeof(int));

    //set fps
    INFO("fps=%d\n", num);
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&num,sizeof(int));
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));
    //ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&num,sizeof(int));
    //ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));

    //h264,h265码率配置
    if(NULL != server_l->dev && V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
    {
        uint32_t bitrate = __DEFAULT_HEVC_BITRATE__;
        ar_element_modify_property_value(handle, context->hevc_enc.element,AR_VIDEO_CODEC_META_BITRATE, &bitrate, sizeof(uint32_t));
    }

    if(NULL != server_l->dev && V4L2_PIX_FMT_H264 == server_l->dev->fcc)
    {
        uint32_t bitrate = __DEFAULT_H264_BITRATE__;
        ar_element_modify_property_value(handle, context->avc_enc.element,AR_VIDEO_CODEC_META_BITRATE, &bitrate, sizeof(uint32_t));
    }

    /* change icc_proxy_sink property */
    ar_element_modify_property_value(handle,context->yuv_0_sink.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth,sizeof(int));
    ar_element_modify_property_value(handle,context->yuv_1_sink.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth,sizeof(int));

    //set the tee copy bit for pad 0
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->yuv_0_tee.element,tee_pad_num),
                               AR_COMMON_META_TEE_COPY_PROP,&tee_copy,sizeof(uint32_t));
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->yuv_0_tee.element, tee_pad_num),
                               AR_COMMON_META_TEE_COPY_BUFFER_COUNT,&tee_copy_bufffer_num,sizeof(uint32_t));

    //add monitor
    ar_mm_message_add_monitor_pipelines(handle, context->pipeline.element, NULL);
    /* add all element to pipeline/subpipe */


    //[4] 将需要的 ar_facotry_element_obj_t 通过 ar_pipeline_add_many 传送至FreeRTOS端进行初始化
    if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc)
        ar_pipeline_add_many(handle,(ar_pipeline_t)context->pipeline.element,
                            context->cam_src.element, context->yuv_0_tee.element, context->yuv_0_sink.element, \
                            context->yuv_1_sink.element, context->comp.element,
                            context->mjpeg_enc.element, context->mjpeg_bs_sink.element, NULL);
    else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
        ar_pipeline_add_many(handle,(ar_pipeline_t)context->pipeline.element,
                            context->cam_src.element, context->yuv_0_tee.element, context->yuv_0_sink.element, \
                            context->yuv_1_sink.element, context->comp.element,
                            context->hevc_enc.element, context->mjpeg_bs_sink.element, NULL);
    else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
        ar_pipeline_add_many(handle,(ar_pipeline_t)context->pipeline.element,
                            context->cam_src.element, context->yuv_0_tee.element, context->yuv_0_sink.element, \
                            context->yuv_1_sink.element, context->comp.element,
                            context->avc_enc.element, context->mjpeg_bs_sink.element, NULL);
    else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc || V4L2_PIX_FMT_YUV420 == server_l->dev->fcc)
        ar_pipeline_add_many(handle,(ar_pipeline_t)context->pipeline.element,
                            context->cam_src.element, context->yuv_0_tee.element, context->yuv_0_sink.element, \
                            context->yuv_1_sink.element, context->comp.element,
                            context->yuv_enc.element, context->mjpeg_bs_sink.element, NULL);
    


    //[5] 通过 ar_pad_link_by_element 将需要的element按需要的顺序进行连接,最终形成pipeline

    /* link pads */
    ar_pad_link_by_element(handle,context->cam_src.element,0,context->yuv_0_tee.element, 0);
    ar_pad_link_by_element(handle,context->yuv_0_tee.element, 0,context->comp.element, 0);


    if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc || 0 == server_l->dev->fcc)
        ar_pad_link_by_element(handle,context->comp.element, 0,context->mjpeg_enc.element, 0);
    else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
        ar_pad_link_by_element(handle,context->comp.element, 0,context->hevc_enc.element, 0);
    else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
        ar_pad_link_by_element(handle,context->comp.element, 0,context->avc_enc.element, 0);
    else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc || V4L2_PIX_FMT_YUV420 == server_l->dev->fcc)
        ar_pad_link_by_element(handle,context->comp.element, 0,context->yuv_enc.element, 0);

    
    ar_pad_link_by_element(handle,context->yuv_0_tee.element, 1,context->yuv_0_sink.element, 0);
    ar_pad_link_by_element(handle,context->cam_src.element, 1,context->yuv_1_sink.element, 0);

    if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc || 0 == server_l->dev->fcc)
        ar_pad_link_by_element(handle,context->mjpeg_enc.element, 0,context->mjpeg_bs_sink.element,0);
    else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
        ar_pad_link_by_element(handle,context->hevc_enc.element, 0,context->mjpeg_bs_sink.element,0);
    else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
        ar_pad_link_by_element(handle,context->avc_enc.element, 0,context->mjpeg_bs_sink.element,0);
    else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc || V4L2_PIX_FMT_YUV420 == server_l->dev->fcc)
        ar_pad_link_by_element(handle,context->yuv_enc.element, 0,context->mjpeg_bs_sink.element,0);

    if(V4L2_PIX_FMT_H264 == server_l->dev->fcc || V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
        uvc_video_set_rotation(handle,server_l->rotation_angle);
		
    //[6] 将这条pipeline状态设置为 ready后, FreeRTOS端将开始推流

    if(0 == server_l->first_inited)
    {
        ar_element_set_state(handle,(ar_pipeline_t)context->pipeline.element,AR_ELEMENT_STATE_READY);
        server_l->first_inited = 1;
    }

    INFO("xavier, create rgb pipeline success!\n");


    //we register a message to detected sensor msg
    /* create message thread */
    int32_t ret = ar_mm_message_thread_create(handle,
                                    NULL,
                                    uvc_process_msg,
                                    (void*)(server_l) );

    if(ret != AR_MULTIMEDIA_SUCCESS){
        ERR("to create msg proc  failed");
    }
}


void uvc_video_set_rotation(ar_mm_handle_t handle, int angle){
    ar_uvc_context_t* context = NULL;
    uint32_t context_size = 0;
    char encoder_dev[20] = { 0 };
    ar_vcodec_handle_t vhandle = NULL;
    uvc_server_t *server_l = get_uvc_server();

    ar_uvc_get_context((void**)&context, &context_size);

    if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
        sprintf(encoder_dev, "/dev/%s", context->avc_enc.object_name);
    else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
        sprintf(encoder_dev, "/dev/%s", context->hevc_enc.object_name);
    else if(V4L2_PIX_FMT_MJPEG == server_l->dev->fcc)
    {
        sprintf(encoder_dev, "/dev/%s", context->mjpeg_enc.object_name);
        while (ar_element_get_state(handle,(ar_pipeline_t)context->pipeline.element)<=AR_ELEMENT_STATE_READY)
        {
            sleep(1);
        }
    }
    else
    {
        printf("invalid format\n");
        return;
    }

    vhandle = ar_video_codec_open(encoder_dev);
    if(!vhandle){
        printf("can not open encoder device\n");
        return;
    }
	
    ar_vcodec_ctrl_rotation_t rotation_t;
    rotation_t.rotation_enable = 1;
    rotation_t.angle = angle;
    printf("%s set rotation angle to %d\n",encoder_dev , angle);
    ar_video_encoder_set_rotation(vhandle, &rotation_t);
    ar_video_codec_close(vhandle);
}

void ar_uvc_deinit(ar_mm_handle_t handle)
{
    //int32_t             ret;
    //int32_t             i;
    ar_uvc_context_t   *context         = NULL;
    uint32_t            context_size    = 0;
    uvc_server_t       *server_l        = get_uvc_server();

    ar_uvc_get_context((void**)&context, &context_size);

    ar_mm_message_thread_destory(handle);

    if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc || 0 == server_l->dev->fcc)
        ar_pad_unlink_by_element(handle,context->mjpeg_enc.element, 0,context->mjpeg_bs_sink.element,0);
    else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
        ar_pad_unlink_by_element(handle,context->hevc_enc.element, 0,context->mjpeg_bs_sink.element,0);
    else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
        ar_pad_unlink_by_element(handle,context->avc_enc.element, 0,context->mjpeg_bs_sink.element,0);
    else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc || V4L2_PIX_FMT_YUV420 == server_l->dev->fcc)
        ar_pad_unlink_by_element(handle,context->yuv_enc.element, 0,context->mjpeg_bs_sink.element,0);

    ar_pad_unlink_by_element(handle,context->cam_src.element, 1,context->yuv_1_sink.element, 0);
    ar_pad_unlink_by_element(handle,context->yuv_0_tee.element, 1,context->yuv_0_sink.element, 0);

    if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc || 0 == server_l->dev->fcc)
        ar_pad_unlink_by_element(handle,context->comp.element, 0,context->mjpeg_enc.element, 0);
    else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
        ar_pad_unlink_by_element(handle,context->comp.element, 0,context->hevc_enc.element, 0);
    else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
        ar_pad_unlink_by_element(handle,context->comp.element, 0,context->avc_enc.element, 0);
    else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc || V4L2_PIX_FMT_YUV420 == server_l->dev->fcc)
        ar_pad_unlink_by_element(handle,context->comp.element, 0,context->yuv_enc.element, 0);


    ar_pad_unlink_by_element(handle,context->yuv_0_tee.element, 0,context->comp.element, 0);
    ar_pad_unlink_by_element(handle,context->cam_src.element,0,context->yuv_0_tee.element, 0);

    ar_pipeline_remove_all(handle,(ar_pipeline_t)context->pipeline.element);

    /*for(i = 0; i < context_size; ++i)
    {
        ar_facotry_element_obj_t* list = (ar_facotry_element_obj_t*)context;
        ar_element_factory_destory(handle, list[i].element);
    }*/
}

int get_fcc_index(struct uvc_format_info *format, int fcc)
{
    int ret = -1, i = 0;
    for(i = 0; i < uvc_formats_num; ++i)
    {
        if(format[i].fcc == fcc)
            return i;
    }
    return ret;
}

int uvc_pipeline_set_format(unsigned int width, unsigned int height, unsigned int fps, unsigned int fcc)
{
    int pipe_fd = -1, ret = -1, den_num = 1;
    uvc_server_t *server_l=get_uvc_server();
    ar_uvc_context_t* context = NULL;
    uint32_t context_size = 0;

    ar_uvc_get_context((void**)&context, &context_size);

    pipe_fd = server_l->pipe_line_fd;
    if(pipe_fd < 0 || NULL == server_l->handle)
    {
        ERR("uvc_pipeline_set_format check failed!(%d %p)\n", pipe_fd, server_l->handle);
        return ret;
    }

    if(server_l->is_hdr)
    {
        fps=25;
    }

    ret = ar_pipeline_terminal_stream(server_l->handle, (ar_pipeline_t)context->pipeline.element);

    if(server_l->dev->fcc != fcc)
    {
        unsigned int                fcc_index;
        struct uvc_format_opt     * format_opt;
        //char *p2 = (char *)&fcc;

        fcc_index = server_l->dev->fcc_index;
        format_opt  = uvc_formats[fcc_index].data->format_opt;

        //printf("change format to %c%c%c%c(%d x %d @%d fps)\n", p2[0], p2[1], p2[2], p2[3], width, height, fps);

        format_opt->format_deinit(uvc_formats[fcc_index].data, server_l->handle);
        server_l->dev->fcc = fcc;
        server_l->dev->fcc_index = get_fcc_index(uvc_formats, fcc);
        fcc_index = server_l->dev->fcc_index;
        format_opt  = uvc_formats[fcc_index].data->format_opt;

        format_opt->format_init(uvc_formats[fcc_index].data, server_l->handle, server_l->argc, server_l->argv);
    }

    //if(V4L2_PIX_FMT_NV12 == fcc || V4L2_PIX_FMT_YUYV == fcc)
    if(V4L2_PIX_FMT_H264 == fcc || V4L2_PIX_FMT_HEVC == fcc)
    {
        struct framebased_priv_data * priv_data = uvc_formats[server_l->dev->fcc_index].data->priv;
        priv_data->i_frame_for_start = 0;
    }

    if(width < height)
    {
        ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_WIDTH_NAME,&height,sizeof(int));
        ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_HEIGHT_NAME,&width,sizeof(int));
    }
    else
    {
        ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_WIDTH_NAME,&width,sizeof(int));
        ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_HEIGHT_NAME,&height,sizeof(int));
    }
    ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&fps,sizeof(int));
    ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den_num,sizeof(int));
    ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&fps,sizeof(int));
    ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den_num,sizeof(int));
    if(V4L2_PIX_FMT_H264 == server_l->dev->fcc || V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
        uvc_video_set_rotation(server_l->handle,server_l->rotation_angle);
    ret = ar_pipeline_start_stream(server_l->handle, (ar_pipeline_t)context->pipeline.element);

    return ret;
}


static int pipeline_clt_stop(pipeline_ctl_server_t *server_l)
{
    uvc_server_t   *server_uvc = get_uvc_server();
    int             pipe_fd = server_uvc->pipe_line_fd;
    int             ret=-1;

    ret = ar_pipeline_ctrl_pause_stream(pipe_fd);
    INFO("ar_pipeline_ctrl_pause_stream ret=%d",ret);
    
    ret = ar_pipeline_ctrl_stop_stream(pipe_fd);
    INFO("ar_pipeline_ctrl_stop_stream ret=%d",ret);
    
    return 0;
}
static int pipeline_clt_start(pipeline_ctl_server_t *server_l)
{
    uvc_server_t   *server_uvc = get_uvc_server();
    int             pipe_fd =server_uvc->pipe_line_fd;
    int             ret=-1;

    ret = ar_pipeline_ctrl_start_stream(pipe_fd);
    INFO("ar_pipeline_ctrl_start_stream ret=%d",ret);
    
    return 0;
}

static int pipeline_clt_set_prop_uvc(pipeline_ctl_server_t *server_l, char *arg, int len)
{
    uvc_server_t   *server_uvc=get_uvc_server();
    cmd_args_t     *args=get_args(arg);
    uint32_t        context_size = 0;
    ar_uvc_context_t* context = NULL;

    ar_uvc_get_context((void**)&context, &context_size);
    int index = find_cmd_pra_index_by_name("--hdr",args);
    if(index>=0)
    {
        int vfe_en = atoi(args->args[index+1]);
        INFO("set_hdr vfe_en=%d multi=%d",vfe_en,server_uvc->multi);
        if(vfe_en)
        {
            if(server_uvc->multi)
            {
                ar_element_modify_property_value(server_uvc->handle,context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
                ar_element_modify_property_value(server_uvc->handle,context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DDR,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
            }
            else
            {
                ar_element_modify_property_value(server_uvc->handle,context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
                ar_element_modify_property_value(server_uvc->handle,context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DDR,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
            }
            ar_element_modify_property_value(server_uvc->handle,context->cam_src.element,AR_VIDEO_CAM_SET_VFE_EN,&vfe_en,sizeof(int));
        }
        else
        {
            if(server_uvc->multi)
            {
                ar_element_modify_property_value(server_uvc->handle,context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
                ar_element_modify_property_value(server_uvc->handle,context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DDR,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
            }
            else
            {
                ar_element_modify_property_value(server_uvc->handle,context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL)+1);
                ar_element_modify_property_value(server_uvc->handle,context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT,strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT)+1);
            }
            ar_element_modify_property_value(server_uvc->handle,context->cam_src.element,AR_VIDEO_CAM_SET_VFE_EN,&vfe_en,sizeof(int));
        }
    }

    index = find_cmd_pra_index_by_name("--fps",args);
    if(index >=0)
    {
        int num = atoi(args->args[index+1]);
        int den = 1;
        INFO("set fps =%d",num);
        ar_pad_modify_meta_value(server_uvc->handle,ar_element_get_src_pad_by_idx(server_uvc->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&num,sizeof(int));
        ar_pad_modify_meta_value(server_uvc->handle,ar_element_get_src_pad_by_idx(server_uvc->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));
        ar_pad_modify_meta_value(server_uvc->handle,ar_element_get_src_pad_by_idx(server_uvc->handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&num,sizeof(int));
        ar_pad_modify_meta_value(server_uvc->handle,ar_element_get_src_pad_by_idx(server_uvc->handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));
    }


    index = find_cmd_pra_index_by_name("--res",args);
	if(index >=0)
	{
         int w= atoi(args->args[index+1]);
         int h= atoi(args->args[index+2]);
		 INFO("set w h =(%d %d)",w,h);
		 ar_pad_modify_meta_value(server_uvc->handle,ar_element_get_src_pad_by_idx(server_uvc->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_WIDTH_NAME,&w,sizeof(int));
		 ar_pad_modify_meta_value(server_uvc->handle,ar_element_get_src_pad_by_idx(server_uvc->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_HEIGHT_NAME,&h,sizeof(int));
	}

    free(args);
    return 0;
}


static int pipeline_clt_set_prop(pipeline_ctl_server_t *server_l,char *arg,int len)
{
    uvc_server_t *server_uvc=get_uvc_server();
    pipeline_clt_set_prop_uvc(server_l,arg,len);

    return 0;
}


server_api_ops_t api_ops = {
    .ar_pipeline_clt_stop=pipeline_clt_stop,
    .ar_pipeline_clt_start=pipeline_clt_start,
    .ar_pipeline_clt_set_prop=pipeline_clt_set_prop,
};

