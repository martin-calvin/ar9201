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

    static ar_facotry_element_obj_t uvc_init_list[] = //refer to. ar_uvc_context_t
    {
        /* shoule match with context */
        {"pipeline", "uvc_path", NULL},
        {"cam_src",{0},NULL},
         
        //{"tee",NULL,NULL},
        //{"user_compositor",{0},NULL},
        
        {"hevc_encoder",{0},NULL}, //cam_src pad0 h265 encoder
        {"hevc_encoder",{0},NULL}, //cam_src pad1 h265 encoder
        
        {"avc_encoder",{0},NULL},  //cam_src pad0 h264 encoder
        {"avc_encoder",{0},NULL},  //cam_src pad1 h264 encoder
        
        {"jpeg_encoder",{0},NULL}, //cam_src pad0 mjpeg encoder
        {"jpeg_encoder",{0},NULL}, //cam_src pad1 mjpeg encoder
        
        {"tee",{0},NULL},          //cam_src pad0 yuv encoder for yuy2 and nv12
        {"tee",{0},NULL},          //cam_src pad1 yuv encoder for yuy2 and nv12
        
        {"icc_proxy_rpc_sink","uvc_sink-0",NULL},  //cam_src pad0 sink
        {"icc_proxy_rpc_sink","uvc_sink-1",NULL},  //cam_src pad1 sink
            
        {"on_off",{""},NULL},      //switch for cam_src pad0
        {"on_off",{""},NULL},      //switch for cam_src pad1
            
        /* yuv element */
        {"tee",{0},NULL},          //yuv_0_tee
        //{"icc_proxy_rpc_sink","video_yuv-0",NULL},
        //{"tee",{0},NULL},
        //{"icc_proxy_rpc_sink","video_yuv-1",NULL},
        //{"tee",{0},NULL},
        //{"display_sink",{0},NULL},
    };
        
    uvc_server_t *server_l = get_uvc_server();

    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->pipeline.object_name, "uvc_path-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->cam_src.object_name, "cam_src-%d", server_l->pipe_index);
    
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->hevc_enc_0.object_name, "hevc_encoder_0-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->hevc_enc_1.object_name, "hevc_encoder_1-%d", server_l->pipe_index);
    
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->avc_enc_0.object_name, "avc_encoder_0-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->avc_enc_1.object_name, "avc_encoder_1-%d", server_l->pipe_index);
    
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->mjpeg_enc_0.object_name, "jpeg_encoder_0-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->mjpeg_enc_1.object_name, "jpeg_encoder_1-%d", server_l->pipe_index);
    
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->yuv_enc_0.object_name, "yuv_encoder_0-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->yuv_enc_1.object_name, "yuv_encoder_1-%d", server_l->pipe_index);
    
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->mjpeg_bs_sink_0.object_name, "uvc_sink_0-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->mjpeg_bs_sink_1.object_name, "uvc_sink_1-%d", server_l->pipe_index);

    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->on_off_0.object_name, "on_off_0-%d", server_l->pipe_index);
    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->on_off_1.object_name, "on_off_1-%d", server_l->pipe_index);

    sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->yuv_0_tee.object_name, "tee_0-%d", server_l->pipe_index);
    //sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->yuv_0_sink.object_name, "video_yuv-0-%d", server_l->pipe_index);
    //sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->yuv_1_tee.object_name, "tee_1-%d", server_l->pipe_index);
    //sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->display_tee.object_name, "display_tee-%d", server_l->pipe_index);

    if (server_l->osd == 0) {
        //sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->comp.object_name, "user_compositor-noosd-%d", server_l->pipe_index);
        //sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->yuv_1_sink.object_name, "video_yuv-1-noosd-%d", server_l->pipe_index);
        //INFO("pid %d pipe line %d disable osd.\n", getpid(), server_l->pipe_index);
    } else {
        //sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->comp.object_name, "user_compositor-0");
        //sprintf((char *)&((ar_uvc_context_t *)&uvc_init_list)->yuv_1_sink.object_name, "video_yuv-1");
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

static void uvc_process_msg(ar_multimedia_message_t* msg, void* user_data) //xx
{
    INFO("got msg type:%d, msg id:0x%x\n", msg->type, msg->msg_id);

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
    uint32_t width = 1920, height = 1080;
    int queue_depth = 3;
    ar_uvc_context_t *context = NULL;
    uint32_t context_size = 0;
    int vfe_en = 0; //使能HDR
    int num = 30;   //fps
    int den = 1;
    int qp_coef = 3;  //Mjpeg编码qp值
    int tee_copy = 0; //是否做tee copy
    int tee_pad_num = 0;
    int tee_copy_bufffer_num = 5; //做tee copy分配的buffe深度
    int face_stats = 0;  //face ae使能
    int onoff_state = 0;
    
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


    //[3] 通过 ar_element_modify_property_value 设置属性 && 通过 ar_pad_modify_meta_value 设置meta value
    /* change cam src property */
    ar_element_modify_property_value(handle, context->cam_src.element, AR_VIDEO_CAM_SET_ID, &server_l->pipe_index, sizeof(server_l->pipe_index));
    if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc || 0 == server_l->dev->fcc)
    {
        ar_element_modify_property_value(handle, context->mjpeg_enc_0.element, AR_VIDEO_CODEC_META_QP, &qp_coef, sizeof(qp_coef));
        ar_element_modify_property_value(handle, context->mjpeg_enc_1.element, AR_VIDEO_CODEC_META_QP, &qp_coef, sizeof(qp_coef));
    }
    //else if(V4L2_PIX_FMT_YUV420 == server_l->dev->fcc || V4L2_PIX_FMT_NV12 == server_l->dev->fcc)
    else if(V4L2_PIX_FMT_YUV420 == server_l->dev->fcc)
    {
        //针对YUV相关数据配置为三个分量连续地址
        int is_contiune = 0;
        int yuv_format  = 0;

        is_contiune = 1;
        ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_MEM_CONTINUE,&is_contiune,sizeof(int));
        ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_MEM_CONTINUE,&is_contiune,sizeof(int));
        
        if (V4L2_PIX_FMT_YUV420 == server_l->dev->fcc)
        {
            INFO("I420 config format name!\n");
            yuv_format = AR_VIDEO_FORMAT_I420;
            ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FORMAT_NAME,&yuv_format,sizeof(int));
            ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FORMAT_NAME,&yuv_format,sizeof(int));
        }
        /*
        if (V4L2_PIX_FMT_NV12 == server_l->dev->fcc)
        {
            DBG("NV12 config format name!\n");
            yuv_format = AR_VIDEO_FORMAT_NV12;
            ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FORMAT_NAME,&yuv_format,sizeof(int));
            ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FORMAT_NAME,&yuv_format,sizeof(int));
        }
        */
    }

    //INFO("vfe_en=%d multi=%d\n", vfe_en, server_l->multi);
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
            else //here!
            {
               ar_element_modify_property_value(handle,context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL)+1);
               ar_element_modify_property_value(handle,context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT,strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT)+1);
            }
        }
        ar_element_modify_property_value(handle,context->cam_src.element,AR_VIDEO_CAM_SET_VFE_EN,&vfe_en,sizeof(vfe_en));
        ar_element_modify_property_value(handle,context->cam_src.element,AR_VIDEO_SET_SOFTWARE_FACE_STATS,&face_stats,sizeof(int));
    }
    
    //isp setting choice
    uint32_t man_res = server_l->default_man_res;  //sensor setting的索引, bit4:enable, bit[0--3]: res
    //INFO("man_res: 0x%x\n", man_res);
	ar_element_modify_property_value(handle,context->cam_src.element,AR_VIDEO_SET_MAN_RES,&man_res,sizeof(int));

    //此处只配置一个默认的分辨率,uvc在请求数据流的时候会再次配置分辨率的
    width  = server_l->width[0];
    height = server_l->height[0];
    //INFO("res0 w=%d h=%d\n", width, height);
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_WIDTH_NAME,&width,sizeof(int));
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_HEIGHT_NAME,&height,sizeof(int));

    width = server_l->width[1];
    height = server_l->height[1];
    //INFO("res1 w=%d h=%d\n",width, height);
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_WIDTH_NAME,&width,sizeof(int));
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_HEIGHT_NAME,&height,sizeof(int));

    //set fps
    //INFO("fps=%d\n", num);
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&num,sizeof(int));
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));
    
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&num,sizeof(int));
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));

    //h264,h265码率配置
    if(NULL != server_l->dev && V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
    {
        uint32_t bitrate = __DEFAULT_HEVC_BITRATE__;
        ar_element_modify_property_value(handle, context->hevc_enc_0.element,AR_VIDEO_CODEC_META_BITRATE, &bitrate, sizeof(uint32_t));
        ar_element_modify_property_value(handle, context->hevc_enc_1.element,AR_VIDEO_CODEC_META_BITRATE, &bitrate, sizeof(uint32_t));
    }

    if(NULL != server_l->dev && V4L2_PIX_FMT_H264 == server_l->dev->fcc)
    {
        uint32_t bitrate = __DEFAULT_H264_BITRATE__;
        ar_element_modify_property_value(handle, context->avc_enc_0.element,AR_VIDEO_CODEC_META_BITRATE, &bitrate, sizeof(uint32_t));
        ar_element_modify_property_value(handle, context->avc_enc_1.element,AR_VIDEO_CODEC_META_BITRATE, &bitrate, sizeof(uint32_t));
    }

    /* change icc_proxy_sink property */
    //ar_element_modify_property_value(handle,context->yuv_0_sink.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth,sizeof(int));
    //ar_element_modify_property_value(handle,context->yuv_1_sink.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth,sizeof(int));

    //set the tee copy bit for pad 0
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->yuv_0_tee.element,tee_pad_num),
                               AR_COMMON_META_TEE_COPY_PROP,&tee_copy,sizeof(uint32_t));
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->yuv_0_tee.element, tee_pad_num),
                               AR_COMMON_META_TEE_COPY_BUFFER_COUNT,&tee_copy_bufffer_num,sizeof(uint32_t));
    
    //set onoff
    onoff_state = 0;
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->on_off_0.element, 0),
                            AR_COMMON_META_ONOFF_STATE,&onoff_state,sizeof(uint32_t));
    onoff_state = 1;
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->on_off_1.element, 0),
                            AR_COMMON_META_ONOFF_STATE,&onoff_state,sizeof(uint32_t));

    //add monitor
    ar_mm_message_add_monitor_pipelines(handle, context->pipeline.element, NULL);
    /* add all element to pipeline/subpipe */


    //[4] 将需要的 ar_facotry_element_obj_t 通过 ar_pipeline_add_many 传送至FreeRTOS端进行初始化
    if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc)
        ar_pipeline_add_many(handle,(ar_pipeline_t)context->pipeline.element,
                            context->cam_src.element, context->yuv_0_tee.element, \
                            context->on_off_0.element,context->on_off_1.element, \
                            context->mjpeg_enc_0.element, context->mjpeg_bs_sink_0.element,  \
                            context->mjpeg_enc_1.element, context->mjpeg_bs_sink_1.element,NULL);
    else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
        ar_pipeline_add_many(handle,(ar_pipeline_t)context->pipeline.element,
                            context->cam_src.element, context->yuv_0_tee.element, \
                            context->on_off_0.element,context->on_off_1.element, \
                            context->hevc_enc_0.element, context->mjpeg_bs_sink_0.element,  \
                            context->hevc_enc_1.element, context->mjpeg_bs_sink_1.element,NULL);

    else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
        ar_pipeline_add_many(handle,(ar_pipeline_t)context->pipeline.element,
                            context->cam_src.element, context->yuv_0_tee.element, \
                            context->on_off_0.element,context->on_off_1.element, \
                            context->avc_enc_0.element, context->mjpeg_bs_sink_0.element,  \
                            context->avc_enc_1.element, context->mjpeg_bs_sink_1.element,NULL);

    else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc || V4L2_PIX_FMT_YUV420 == server_l->dev->fcc || V4L2_PIX_FMT_NV21 == server_l->dev->fcc)
        ar_pipeline_add_many(handle,(ar_pipeline_t)context->pipeline.element,
                            context->cam_src.element, context->yuv_0_tee.element, \
                            context->on_off_0.element,context->on_off_1.element, \
                            context->yuv_enc_0.element, context->mjpeg_bs_sink_0.element,  \
                            context->yuv_enc_1.element, context->mjpeg_bs_sink_1.element,NULL);
    else
        ERR("should not go here!\n");

    //[5] 通过 ar_pad_link_by_element 将需要的element按需要的顺序进行连接,最终形成pipeline

    /* link pads */
    if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc || 0 == server_l->dev->fcc)
    {
         ar_pad_link_by_element(handle,context->cam_src.element,1,context->yuv_0_tee.element, 0);
         ar_pad_link_by_element(handle,context->yuv_0_tee.element, 0,context->on_off_1.element, 0);
         ar_pad_link_by_element(handle,context->on_off_1.element, 0,context->mjpeg_enc_1.element, 0);
         ar_pad_link_by_element(handle,context->mjpeg_enc_1.element, 0,context->mjpeg_bs_sink_1.element, 0);
         
         ar_pad_link_by_element(handle,context->cam_src.element,0,context->on_off_0.element, 0);
         ar_pad_link_by_element(handle,context->on_off_0.element, 0,context->mjpeg_enc_0.element, 0);
         ar_pad_link_by_element(handle,context->mjpeg_enc_0.element, 0,context->mjpeg_bs_sink_0.element, 0);
    }
    else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
    {
        ar_pad_link_by_element(handle,context->cam_src.element,1,context->yuv_0_tee.element, 0);
        ar_pad_link_by_element(handle,context->yuv_0_tee.element, 0,context->on_off_1.element, 0);
        ar_pad_link_by_element(handle,context->on_off_1.element, 0,context->hevc_enc_1.element, 0);
        ar_pad_link_by_element(handle,context->hevc_enc_1.element, 0,context->mjpeg_bs_sink_1.element, 0);
        
        ar_pad_link_by_element(handle,context->cam_src.element,0,context->on_off_0.element, 0);
        ar_pad_link_by_element(handle,context->on_off_0.element, 0,context->hevc_enc_0.element, 0);
        ar_pad_link_by_element(handle,context->hevc_enc_0.element, 0,context->mjpeg_bs_sink_0.element, 0);
    }
    else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
    {
        ar_pad_link_by_element(handle,context->cam_src.element,1,context->yuv_0_tee.element, 0);
        ar_pad_link_by_element(handle,context->yuv_0_tee.element, 0,context->on_off_1.element, 0);
        ar_pad_link_by_element(handle,context->on_off_1.element, 0,context->avc_enc_1.element, 0);
        ar_pad_link_by_element(handle,context->avc_enc_1.element, 0,context->mjpeg_bs_sink_1.element, 0);
        
        ar_pad_link_by_element(handle,context->cam_src.element,0,context->on_off_0.element, 0);
        ar_pad_link_by_element(handle,context->on_off_0.element, 0,context->avc_enc_0.element, 0);
        ar_pad_link_by_element(handle,context->avc_enc_0.element, 0,context->mjpeg_bs_sink_0.element, 0);
    }
    else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc || V4L2_PIX_FMT_YUV420 == server_l->dev->fcc || V4L2_PIX_FMT_NV21 == server_l->dev->fcc)
    {
        ar_pad_link_by_element(handle,context->cam_src.element,1,context->yuv_0_tee.element, 0);
        ar_pad_link_by_element(handle,context->yuv_0_tee.element, 0,context->on_off_1.element, 0);
        ar_pad_link_by_element(handle,context->on_off_1.element, 0,context->yuv_enc_1.element, 0);
        ar_pad_link_by_element(handle,context->yuv_enc_1.element, 0,context->mjpeg_bs_sink_1.element, 0);
        
        ar_pad_link_by_element(handle,context->cam_src.element,0,context->on_off_0.element, 0);
        ar_pad_link_by_element(handle,context->on_off_0.element, 0,context->yuv_enc_0.element, 0);
        ar_pad_link_by_element(handle,context->yuv_enc_0.element, 0,context->mjpeg_bs_sink_0.element, 0);
    }
    else
    {
        ERR("should not go here!\n");
    }


    if(V4L2_PIX_FMT_H264 == server_l->dev->fcc || V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
        uvc_video_set_rotation(handle, server_l->rotation_angle);
		
    //[6] 将这条pipeline状态设置为 ready后, FreeRTOS端将开始推流
    if(0 == server_l->first_inited)
    {
        ar_element_set_state(handle,(ar_pipeline_t)context->pipeline.element,AR_ELEMENT_STATE_READY);
        server_l->first_inited = 1;
        server_l->preview_pad_output = 0;
    }

    char *p = (char *)&server_l->dev->fcc;
    INFO("xavier, create rgb pipeline success!  %c%c%c%c\n", p[0], p[1], p[2], p[3]);
	

#if 0
    //we register a message to detected sensor msg
    /* create message thread */
    int32_t ret = ar_mm_message_thread_create(handle,
                                    NULL,
                                    uvc_process_msg,
                                    (void*)(server_l) );

    if(ret != AR_MULTIMEDIA_SUCCESS){
        ERR("to create msg proc  failed");
    }
#endif
}


void uvc_video_set_rotation(ar_mm_handle_t handle, int angle){
    ar_uvc_context_t* context = NULL;
    uint32_t context_size = 0;
    char encoder_dev[20] = { 0 };
    ar_vcodec_handle_t vhandle = NULL;
    uvc_server_t *server_l = get_uvc_server();

    ar_uvc_get_context((void**)&context, &context_size);

    if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
        sprintf(encoder_dev, "/dev/%s", (1 == server_l->preview_pad_output) ? context->avc_enc_0.object_name : context->avc_enc_1.object_name);
    else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
        sprintf(encoder_dev, "/dev/%s", (1 == server_l->preview_pad_output) ? context->hevc_enc_0.object_name : context->hevc_enc_1.object_name);
    else if(V4L2_PIX_FMT_MJPEG == server_l->dev->fcc)
    {
        sprintf(encoder_dev, "/dev/%s", (1 == server_l->preview_pad_output) ? context->mjpeg_enc_0.object_name : context->mjpeg_enc_1.object_name);
        while (ar_element_get_state(handle,(ar_pipeline_t)context->pipeline.element) <= AR_ELEMENT_STATE_READY)
        {
            sleep(1);
            INFO("wait AR_ELEMENT_STATE_READY!\n");
        }
    }
    else
    {
        ERR("invalid format\n");
        return;
    }

    INFO("encoder_dev is:%s\n", encoder_dev);
    vhandle = ar_video_codec_open(encoder_dev);
    if(!vhandle){
        ERR("can not open encoder device\n");
        return;
    }
	
    ar_vcodec_ctrl_rotation_t rotation_t;
    rotation_t.rotation_enable = 1;
    rotation_t.angle = angle;
    INFO("%s set rotation angle to %d\n",encoder_dev , angle);
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
    //ar_mm_message_thread_destory(handle); //maybe block here!


    if(NULL == server_l->dev || V4L2_PIX_FMT_MJPEG == server_l->dev->fcc || 0 == server_l->dev->fcc)
    {
        ar_pad_unlink_by_element(handle,context->mjpeg_enc_0.element, 0, context->mjpeg_bs_sink_0.element,0);
        ar_pad_unlink_by_element(handle,context->on_off_0.element, 0, context->mjpeg_enc_0.element,0);
        ar_pad_unlink_by_element(handle,context->cam_src.element, 0, context->on_off_0.element,0);

        ar_pad_unlink_by_element(handle,context->mjpeg_enc_1.element, 0, context->mjpeg_bs_sink_1.element,0);
        ar_pad_unlink_by_element(handle,context->on_off_1.element, 0, context->mjpeg_enc_1.element,0);
        ar_pad_unlink_by_element(handle,context->yuv_0_tee.element, 0, context->on_off_1.element,0);
        ar_pad_unlink_by_element(handle,context->cam_src.element, 1, context->yuv_0_tee.element,0);
    }
    else if(V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
    {
        ar_pad_unlink_by_element(handle,context->hevc_enc_0.element, 0, context->mjpeg_bs_sink_0.element,0);
        ar_pad_unlink_by_element(handle,context->on_off_0.element, 0, context->hevc_enc_0.element,0);
        ar_pad_unlink_by_element(handle,context->cam_src.element, 0, context->on_off_0.element,0);

        ar_pad_unlink_by_element(handle,context->hevc_enc_1.element, 0, context->mjpeg_bs_sink_1.element,0);
        ar_pad_unlink_by_element(handle,context->on_off_1.element, 0, context->hevc_enc_1.element,0);
        ar_pad_unlink_by_element(handle,context->yuv_0_tee.element, 0, context->on_off_1.element,0);
        ar_pad_unlink_by_element(handle,context->cam_src.element, 1, context->yuv_0_tee.element,0);
    }
    else if(V4L2_PIX_FMT_H264 == server_l->dev->fcc)
    {
        ar_pad_unlink_by_element(handle,context->avc_enc_0.element, 0, context->mjpeg_bs_sink_0.element,0);
        ar_pad_unlink_by_element(handle,context->on_off_0.element, 0, context->avc_enc_0.element,0);
        ar_pad_unlink_by_element(handle,context->cam_src.element, 0, context->on_off_0.element,0);

        ar_pad_unlink_by_element(handle,context->avc_enc_1.element, 0, context->mjpeg_bs_sink_1.element,0);
        ar_pad_unlink_by_element(handle,context->on_off_1.element, 0, context->avc_enc_1.element,0);
        ar_pad_unlink_by_element(handle,context->yuv_0_tee.element, 0, context->on_off_1.element,0);
        ar_pad_unlink_by_element(handle,context->cam_src.element, 1, context->yuv_0_tee.element,0);
    }
    else if(V4L2_PIX_FMT_NV12 == server_l->dev->fcc || V4L2_PIX_FMT_YUYV == server_l->dev->fcc || V4L2_PIX_FMT_YUV420 == server_l->dev->fcc || V4L2_PIX_FMT_NV21 == server_l->dev->fcc)
    {
        ar_pad_unlink_by_element(handle,context->yuv_enc_0.element, 0, context->mjpeg_bs_sink_0.element,0);
        ar_pad_unlink_by_element(handle,context->on_off_0.element, 0, context->yuv_enc_0.element,0);
        ar_pad_unlink_by_element(handle,context->cam_src.element, 0, context->on_off_0.element,0);

        ar_pad_unlink_by_element(handle,context->yuv_enc_1.element, 0, context->mjpeg_bs_sink_1.element,0);
        ar_pad_unlink_by_element(handle,context->on_off_1.element, 0, context->yuv_enc_1.element,0);
        ar_pad_unlink_by_element(handle,context->yuv_0_tee.element, 0, context->on_off_1.element,0);
        ar_pad_unlink_by_element(handle,context->cam_src.element, 1, context->yuv_0_tee.element,0);
    }
    else
    {
        ERR("should not go here!\n");
    }

   
    ar_pipeline_remove_all(handle,(ar_pipeline_t)context->pipeline.element);

    /*for(i = 0; i < context_size; ++i)
    {
        ar_facotry_element_obj_t* list = (ar_facotry_element_obj_t*)context;
        ar_element_factory_destory(handle, list[i].element);
    }*/

    INFO("uvc deinit complete!\n");
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


/*****************************************************************************
*   Prototype    : uvc_pipeline_set_format
*   Description  : 调整分辨率和格式
*   Input        : unsigned int width   
*                  unsigned int height  
*                  unsigned int fps     
*                  unsigned int fcc     
*   Output       : None
*   Return Value : int

    (1)如果要输出4K去噪的话,需要在pad0上先接入一个on/off的 element, 
    后面再接入encoder和uvc_sink,  非4K输出的时候, on/off关闭, 
    且uvc从pad1的sink处拿,  4K的时候on/off打开,从pad0的sink处拿

    (2)目前可手动选择不同的setting: 
    ar9201_tof\firmwares\cam_bb_fw\library\ar_cam\camera_server\harware\peripherals\sensor\lib\imx415\imx415.h
    g_res_config_setting[]
    共有7组isp setting:
    
    res0: 1920 1080 20fps
    res1: 1920 1080 25fps
    res2: 1920 1080 30fps
    res3: 1920 1080 60fps 
    res4: 3840 2160 20fps
    res5: 3840 2160 25fps
    res6: 3840 2160 30fps

*****************************************************************************/
int uvc_pipeline_set_format(unsigned int width, unsigned int height, unsigned int fps, unsigned int fcc) //fcc is server_l->dev->new_fcc
{
    int pipe_fd = -1, ret = -1, den_num = 1;
    uvc_server_t *server_l=get_uvc_server();
    ar_uvc_context_t* context = NULL;
    uint32_t context_size = 0;
    uint32_t man_res = 0;  //sensor setting的索引, bit4:enable, bit[0--3]: res
    uint32_t main_width =0;
    uint32_t main_height = 0;
    uint32_t on_off_0 =0;
    uint32_t on_off_1 =0;
    int preview_pad_output_last = 0;

    ar_uvc_get_context((void**)&context, &context_size);

    pipe_fd = server_l->pipe_line_fd;
    if(pipe_fd < 0 || NULL == server_l->handle){
        ERR("uvc_pipeline_set_format check failed!(%d %p)\n", pipe_fd, server_l->handle);
        return ret;
    }

    if(server_l->is_hdr){
        fps = 25;
    }

    ret = ar_pipeline_terminal_stream(server_l->handle, (ar_pipeline_t)context->pipeline.element);
    while (AR_ELEMENT_STATE_NULL != ar_element_get_state(server_l->handle,(ar_pipeline_t)context->pipeline.element)){
        INFO("wait NULL state, current state:%d\n", ar_element_get_state(server_l->handle,(ar_pipeline_t)context->pipeline.element));
        usleep(100*1000);
    }


    char *p1 = (char *)&server_l->dev->fcc; //old fcc
    char *p2 = (char *)&fcc;                //new fcc
    INFO("xavier, change format from %c%c%c%c to %c%c%c%c-%ux%u@%ufps\n", p1[0], p1[1], p1[2], p1[3], p2[0], p2[1], p2[2], p2[3], width, height, fps);


    /* [1] 配置pipeline on_off开关以选择对应的pipeline */
    preview_pad_output_last = server_l->preview_pad_output; //save old
    if ((width == 3840 && height == 2160) || (width == 2160 && height == 3840)) 
    {
        server_l->preview_pad_output = 1; // 走4K取图pipeline路线
        on_off_0 = 1;
        on_off_1 = 0;
        INFO("preview port(cam_src pad 0) output\n");
    }
    else
    {
        server_l->preview_pad_output = 0;
        on_off_0 = 0;
        on_off_1 = 1;
        INFO("video port(cam_src pad 1) output\n");
    }
    

    /* [2] 配置rgb setting */

    if ((width <= 1920 && height <= 1080 && fps <= 20) || (width <= 1080 && height <= 1920 && fps <= 20))
    {           
        man_res = 0x10;
        main_width = 1920;
        main_height = 1080;
        INFO("xavier, isp setting is res0: 1920*1080@20fps\n"); 
    }
    else if ((width <= 1920 && height <= 1080 && fps == 25) || (width <= 1080 && height <= 1920 && fps == 25))
    {           
        man_res = 0x11;
        main_width = 1920;
        main_height = 1080;
        INFO("xavier, isp setting is res1: 1920*1080@25fps\n"); 
    }
    else if ((width <= 1920 && height <= 1080 && fps == 30) || (width <= 1080 && height <= 1920 && fps == 30))
    {           
        man_res = 0x12;
        main_width = 1920;
        main_height = 1080;
        INFO("xavier, isp setting is res2: 1920*1080@30fps\n"); 
    }
    else if ((width <= 1920 && height <= 1080 && fps == 60) || (width <= 1080 && height <= 1920 && fps == 60))
    {           
        man_res = 0x13;
        main_width = 1920;
        main_height = 1080;
        INFO("xavier, isp setting is res3: 1920*1080@60fps\n");     
    }
    else if ((width >= 1920 && height > 1080 && fps <= 20) || (width > 1080 && height >= 1920 && fps <= 20))
    {
        man_res = 0x14;
        main_width = 3840;
        main_height = 2160;
        if ((width == 3840 && height == 2160) || (width == 2160 && height == 3840)){
            width = 1920;
            height = 1080;
        }
        INFO("xavier, isp setting is res4: 3840*2160@20fps\n"); 
    }
    else if ((width >= 1920 && height > 1080 && fps == 25) || (width > 1080 && height >= 1920 && fps == 25))
    {
        man_res = 0x15;
        main_width = 3840;
        main_height = 2160;
        if ((width == 3840 && height == 2160) || (width == 2160 && height == 3840)){
            width = 1920;
            height = 1080;
        }
        INFO("xavier, isp setting is res5: 3840*2160@25fps\n"); 
    }
    else if ((width >= 1920 && height > 1080 && fps == 30) || (width > 1080 && height >= 1920 && fps == 30))
    {
        man_res = 0x16;
        main_width = 3840;
        main_height = 2160;
        if ((width == 3840 && height == 2160) || (width == 2160 && height == 3840)){
            width = 1920;
            height = 1080;
        }
        INFO("xavier, isp setting is res6: 3840*2160@30fps\n"); 
    }
    else
    {
        ERR("width:%d, height:%d, fps:%d, fcc:0x%x\n", width, height, fps, fcc);
    }


    //特殊情况重新配置(客户新需求 i420 720p需要指定4k setting)
    if ((V4L2_PIX_FMT_YUV420 == fcc) && ((width == 1280 && height == 720 && fps == 20) || (width ==720 && height == 1280 && fps == 20)))
    {
        man_res = 0x14;
        main_width = 3840;
        main_height = 2160;
        if ((width == 3840 && height == 2160) || (width == 2160 && height == 3840)){
            width = 1920;
            height = 1080;
        }
        INFO("xavier, change isp setting to res4: 3840*2160@20fps\n"); 
    }
    else if ((V4L2_PIX_FMT_YUV420 == fcc) && ((width == 1280 && height == 720 && fps == 25) || (width ==720 && height == 1280 && fps == 25)))
    {
        man_res = 0x15;
        main_width = 3840;
        main_height = 2160;
        if ((width == 3840 && height == 2160) || (width == 2160 && height == 3840)){
            width = 1920;
            height = 1080;
        }
        INFO("xavier, change isp setting to res5: 3840*2160@25fps\n"); 
    }    
    else if ((V4L2_PIX_FMT_YUV420 == fcc) && ((width == 1280 && height == 720 && fps == 30) || (width ==720 && height == 1280 && fps == 30)))
    {
        man_res = 0x16;
        main_width = 3840;
        main_height = 2160;
        if ((width == 3840 && height == 2160) || (width == 2160 && height == 3840)){
            width = 1920;
            height = 1080;
        }
        INFO("xavier, change isp setting to res6: 3840*2160@30fps\n"); 
    }


    /* [3] 根据参数重建pipeline */

    if (1)//((server_l->dev->fcc != fcc) || (preview_pad_output_last != server_l->preview_pad_output))
    {
        unsigned int                fcc_index;
        struct uvc_format_opt     * format_opt;

        fcc_index = server_l->dev->fcc_index;
        format_opt  = uvc_formats[fcc_index].data->format_opt;

        format_opt->format_deinit(uvc_formats[fcc_index].data, server_l->handle); // ==> uvc_mjpeg_deinit, uvc_h264_deinit, uvc_i420_deinit
        
        server_l->dev->fcc = fcc;  //更新fcc!!!
        server_l->dev->fcc_index = get_fcc_index(uvc_formats, fcc);
        fcc_index = server_l->dev->fcc_index;
        format_opt  = uvc_formats[fcc_index].data->format_opt;

        format_opt->format_init(uvc_formats[fcc_index].data, server_l->handle, server_l->argc, server_l->argv);// uvc_mjpeg_init, uvc_h264_init, uvc_i420_init
    }

    if(V4L2_PIX_FMT_H264 == fcc || V4L2_PIX_FMT_HEVC == fcc)
    {
        struct framebased_priv_data * priv_data = uvc_formats[server_l->dev->fcc_index].data->priv;
        priv_data->i_frame_for_start = 0;
    }


    /* [4] 设置分辨率 */
    ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_WIDTH_NAME,&main_width,sizeof(int));
    ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_HEIGHT_NAME,&main_height,sizeof(int));
    if(width < height) {
        ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_WIDTH_NAME,&height,sizeof(int));
        ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_HEIGHT_NAME,&width,sizeof(int));
    }else{
        ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_WIDTH_NAME,&width,sizeof(int));
        ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_HEIGHT_NAME,&height,sizeof(int));
    }

    /* [5] 设置fps */
    ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&fps,sizeof(int));
    ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den_num,sizeof(int));
    ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&fps,sizeof(int));
    ar_pad_modify_meta_value(server_l->handle,ar_element_get_src_pad_by_idx(server_l->handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den_num,sizeof(int));


    /* [5] 设置on_off开关 */
    ar_pad_modify_meta_value(server_l->handle, ar_element_get_src_pad_by_idx(server_l->handle,context->on_off_0.element, 0),AR_COMMON_META_ONOFF_STATE,&on_off_0,sizeof(uint32_t));
    ar_pad_modify_meta_value(server_l->handle, ar_element_get_src_pad_by_idx(server_l->handle,context->on_off_1.element, 0),AR_COMMON_META_ONOFF_STATE,&on_off_1,sizeof(uint32_t));	

    /* [6] 选择rgb的setting */
	INFO("man_res is 0x%x\n",man_res);
	ar_element_modify_property_value(server_l->handle,context->cam_src.element, AR_VIDEO_SET_MAN_RES, &man_res,sizeof(int));

    //h264,h265旋转方式配置
    //if(V4L2_PIX_FMT_H264 == server_l->dev->fcc || V4L2_PIX_FMT_HEVC == server_l->dev->fcc)
        //uvc_video_set_rotation(server_l->handle,server_l->rotation_angle); //crash when set rotation here!

    /* [7] 启动pipeline,出流! */
    INFO("pipeline start stream.\n");
    ret = ar_pipeline_start_stream(server_l->handle, (ar_pipeline_t)context->pipeline.element); //500ms
    if (0 != ret){
        ERR("ar_pipeline_start_stream failed!\n");
    }else{
        INFO("pipeline start stream success.\n");
    }

    return ret;
}


static int pipeline_clt_stop(pipeline_ctl_server_t *server_l) //xx
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
static int pipeline_clt_start(pipeline_ctl_server_t *server_l) //xx
{
    uvc_server_t   *server_uvc = get_uvc_server();
    int             pipe_fd =server_uvc->pipe_line_fd;
    int             ret=-1;

    ret = ar_pipeline_ctrl_start_stream(pipe_fd);
    INFO("ar_pipeline_ctrl_start_stream ret=%d",ret);
    
    return 0;
}

static int pipeline_clt_set_prop_uvc(pipeline_ctl_server_t *server_l, char *arg, int len) //xx
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

