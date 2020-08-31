#define ENABALE_ALL_LOG
#include "ar_system.h"
#include "ar_meta_define.h"
#include "ar_multimedia_base.h"
#include "ipcam.h"
#include "ar_lancher.h"
#include "ar_video_codec.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "ar_customize_msg_type.h"

#define AR_IPCAM_CAM_SRC_STREAM_NUMBER           2  // Pipeline only use scaler 0/1 in current pipeline

static void ipcam_get_context(void** context, uint32_t* context_size)
{
    static ar_facotry_element_obj_t ipcam_init_list[] =
    {
        /* shoule match with context */
        {"pipeline",{"ipcam_server"},NULL},
        {"cam_src",{""},NULL},
        {"tee",{""},NULL},
        {"user_compositor",{""},NULL},
        {"tee",{""},NULL},
        {"video_encoder",{""},NULL}, /* default hevc_encoder */
        {"icc_proxy_rpc_sink",{""},NULL},
        {"icc_proxy_rpc_sink",{""},NULL},
        {"icc_proxy_rpc_sink",{""},NULL},
        {"tee",{""},NULL},
        {"video_parser",{""},NULL},
        {"video_decoder",{""},NULL},
        {"display_sink",{""},NULL},
    };
    *context = (void*)&ipcam_init_list;
    *context_size = sizeof(ipcam_init_list)/sizeof(ar_facotry_element_obj_t);
    return;
}

static void ipcam_process_msg(ar_multimedia_message_t* msg, void* user_data)
{
    //printf("got msg\n");

    ipcam_server_t *ipcam_server=get_ipcam_server();
    if(!ipcam_server || !msg)
    {
        printf("error : empty input\n");
        return;
    }

    if(AR_MM_MESSAGE_CUSTOMIZE != msg->type)
    {
        return;
    }

    ar_pipeline_t p_pipeline = ( ar_pipeline_t )msg->from_pipeline;
    ar_element_t p_trigger_element = ( ar_element_t )msg->from_element;

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

            if(ipcam_server->err_proc)
            {
                printf("!!!!!!!!!!!!pipeline terminal\n");
                ar_pipeline_terminal_stream(ipcam_server->handle, p_pipeline);
                log_always("!!!!!!!!!!!!pipeline set ready");
                ar_element_set_state(ipcam_server->handle\
                    ,p_pipeline,AR_ELEMENT_STATE_READY);
            }else
            {
               log_always("no err proc");
            }
       break;
       default:
       break;
     }
     return;
}


static void *ipcam_init_impl(ipcam_codec_type_t codec_type, int width1, int height1, int width2, int height2, int angle, int camera_idx)

{
    ar_mm_handle_t handle = NULL;
    ar_vcodec_handle_t vhandle = NULL;
    uint32_t snapshot_qp = 0, mjpeg_type = 0, context_size = 0, enc_type = 1;
    int onoff_state = 0, queue_depth = 10;
    ipcam_context_t* context = NULL;
    char encoder_dev[20] = { 0 };

    ipcam_server_t *ipcam_server=get_ipcam_server();
    handle=ipcam_server->handle;
    ipcam_get_context((void**)&context, &context_size);
    sprintf(context->pipeline.object_name, "%s-%d", "ipcam_server", camera_idx);
    sprintf(context->video_bs_sink.object_name, "icc_proxy_rpc_sink-%d", camera_idx);

    sprintf(context->yuv_0_sink.object_name, "video_yuv-%d.1", camera_idx);
    sprintf(context->yuv_1_sink.object_name, "video_yuv-%d.2", camera_idx);
    if(ar_element_factory_make_many(handle, context_size, (ar_facotry_element_obj_t*)context) != AR_MULTIMEDIA_SUCCESS){
        return 0;
    }

    enc_type = codec_type + 1;
    ar_element_modify_property_value(handle, context->video_enc.element, AR_VIDEO_CODEC_META_TYPE, &enc_type, sizeof(uint32_t));
    ar_element_modify_property_value(handle, context->video_parser.element, AR_VIDEO_CODEC_META_TYPE, &enc_type, sizeof(uint32_t));
    ar_element_modify_property_value(handle, context->video_dec.element, AR_VIDEO_CODEC_META_TYPE, &enc_type, sizeof(uint32_t));
    /* change cam src property */
    ar_element_modify_property_value(handle, context->cam_src.element,AR_VIDEO_CAM_SET_ID,&camera_idx, sizeof(uint32_t));
    //set multi camera mode
    if (ipcam_server->cam_num > 1) {
        ar_element_modify_property_value(handle, context->cam_src.element,
                                       AR_VIDEO_CAM_MODE,
                                       AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE,
                                       strlen(AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE)+1);
        ar_element_modify_property_value(handle, context->cam_src.element,
                                       AR_VIDEO_CAM_VIF_ISP_MOD,
                                       AR_VIDEO_CAM_VIF_ISP_MOD_DDR,
                                       strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DDR)+1);
    } else {
        ar_element_modify_property_value(handle,context->cam_src.element,
                                       AR_VIDEO_CAM_MODE,
                                       AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL,
                                       strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL)+1);
        ar_element_modify_property_value(handle,context->cam_src.element,
                                       AR_VIDEO_CAM_VIF_ISP_MOD,
                                       AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT,
                                       strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT)+1);
    }
    int vfe_en = ipcam_server->hdr_mode;
    if(vfe_en || ipcam_server->face_stats ||ipcam_server->force_isp_ddr_mode)
    {

        if(ipcam_server->cam_num > 1)
        {

           ar_element_modify_property_value(handle, context->cam_src.element,
                                          AR_VIDEO_CAM_MODE,
                                          AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE,
                                          strlen(AR_VIDEO_CAM_MODE_MUILTI_CMAERA_MODE)+1);
           ar_element_modify_property_value(handle, context->cam_src.element,
                                          AR_VIDEO_CAM_VIF_ISP_MOD,
                                          AR_VIDEO_CAM_VIF_ISP_MOD_DDR,
                                          strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DDR)+1);
        }else
        {
            ar_element_modify_property_value(handle,context->cam_src.element,
                                       AR_VIDEO_CAM_MODE,
                                       AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE,
                                       strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
            ar_element_modify_property_value(handle,context->cam_src.element,
                                       AR_VIDEO_CAM_VIF_ISP_MOD,
                                       AR_VIDEO_CAM_VIF_ISP_MOD_DDR,
                                       strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DDR)+1);
        }
        if(vfe_en)
        {
           ar_element_modify_property_value(handle,context->cam_src.element,AR_VIDEO_CAM_SET_VFE_EN,&vfe_en,sizeof(int));
        }
        if(ipcam_server->face_stats)
        {
            ar_element_modify_property_value(handle,context->cam_src.element,AR_VIDEO_SET_SOFTWARE_FACE_STATS,&ipcam_server->face_stats,sizeof(int));
        }
    }
    else
    {
        ar_element_modify_property_value(handle,context->cam_src.element,AR_VIDEO_CAM_SET_VFE_EN,&vfe_en,sizeof(int));
    }

    ar_element_modify_property_value(handle,context->cam_src.element,AR_VIDEO_SET_HW_EIS_LDC,&ipcam_server->use_hw_eis_ldc,sizeof(int));

    #if 0
    /* 10bit video format config */
    unsigned int video_format = AR_VIDEO_FORMAT_I420_P10_32BIT_LE;
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 0),
                                AR_COMMON_META_VIDEO_FORMAT_NAME,&video_format, sizeof(uint32_t));
    #endif
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 0),
                            AR_COMMON_META_VIDEO_WIDTH_NAME,&width1, sizeof(uint32_t));
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 0),
                            AR_COMMON_META_VIDEO_HEIGHT_NAME,&height1, sizeof(uint32_t));
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 1),
                            AR_COMMON_META_VIDEO_WIDTH_NAME,&width2, sizeof(uint32_t));
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 1),
                            AR_COMMON_META_VIDEO_HEIGHT_NAME,&height2, sizeof(uint32_t));

    int num=ipcam_server->fps;
    int den=1;
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&num,sizeof(int));
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&num,sizeof(int));
    ar_pad_modify_meta_value(handle,ar_element_get_src_pad_by_idx(handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));


    uint32_t bitrate = ipcam_server->bitrate;//3*1024;
    ar_element_modify_property_value(handle, context->video_enc.element,AR_VIDEO_CODEC_META_BITRATE, &bitrate, sizeof(uint32_t));
    /* change icc_proxy_sink property */
    ar_element_modify_property_value(handle, context->yuv_0_sink.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth, sizeof(uint32_t));
    ar_element_modify_property_value(handle, context->yuv_1_sink.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH,&queue_depth, sizeof(uint32_t));

    //set the tee copy bit for pad 0
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->tee.element, ipcam_server->tee_src_pad_index),
                               AR_COMMON_META_TEE_COPY_PROP,&ipcam_server->tee_copy,sizeof(uint32_t));
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->tee.element, ipcam_server->tee_src_pad_index),
                               AR_COMMON_META_TEE_COPY_BUFFER_COUNT,&ipcam_server->tee_copy_buffer_count,sizeof(uint32_t));

    //add monitor
    ar_mm_message_add_monitor_pipelines(handle, context->pipeline.element, NULL);
    /* add all element to pipeline/subpipe */
    if(!ipcam_server->need_display)
    {
        ar_pipeline_add_many(handle, (ar_pipeline_t)context->pipeline.element,
                        context->cam_src.element, context->tee.element, context->yuv_0_sink.element, \
                        context->yuv_1_sink.element, context->comp.element, \
                        context->video_enc.element, context->video_bs_sink.element,\
                        NULL);
    }else
    {
         ar_pipeline_add_many(handle, (ar_pipeline_t)context->pipeline.element,
                        context->cam_src.element, context->tee.element, context->yuv_0_sink.element, \
                        context->yuv_1_sink.element, context->comp.element, \
                        context->video_enc.element, context->video_bs_sink.element,\

                        context->display.element,context->tee_to_en_disp.element,NULL);
         if(ipcam_server->transcode) {
             ar_pipeline_add_many(handle, (ar_pipeline_t)context->pipeline.element,
                        context->bs_tee.element, context->video_parser.element, context->video_dec.element, NULL);
         }
         //set dispaly out put
         int disp_width = ipcam_server->w;
         int disp_height = ipcam_server->h;
         int fix_fps =ipcam_server->dis_fps;
         ar_element_modify_property_value(handle,context->display.element,AR_DISPLAY_META_OUT_WIDTH,&disp_width,sizeof(int));
         ar_element_modify_property_value(handle,context->display.element,AR_DISPLAY_META_OUT_HEIGHT,&disp_height,sizeof(int));
         ar_element_modify_property_value(handle,context->display.element,AR_DISPLAY_META_FIX_FPS,&fix_fps,sizeof(int));
    }
    /* link pads */
    ar_pad_link_by_element(handle, context->cam_src.element, 0, context->tee.element, 0);
    ar_pad_link_by_element(handle, context->cam_src.element, 1, context->yuv_1_sink.element, 0);
    ar_pad_link_by_element(handle, context->tee.element, 0, context->yuv_0_sink.element, 0);
    ar_pad_link_by_element(handle, context->tee.element, 1, context->comp.element, 0);
    if(ipcam_server->need_display)
    {
        ar_pad_link_by_element(handle, context->comp.element, 0, context->tee_to_en_disp.element, 0);
        ar_pad_link_by_element(handle, context->tee_to_en_disp.element, 0, context->video_enc.element, 0);
        if (ipcam_server->transcode) {
            ar_pad_link_by_element(handle, context->video_enc.element, 0, context->bs_tee.element, 0);
            ar_pad_link_by_element(handle, context->bs_tee.element, 0, context->video_bs_sink.element, 0);
            ar_pad_link_by_element(handle, context->bs_tee.element, 1, context->video_parser.element, 0);
            ar_pad_link_by_element(handle, context->video_parser.element, 0, context->video_dec.element, 0);
            ar_pad_link_by_element(handle, context->video_dec.element, 0, context->display.element, 0);
        } else {
            ar_pad_link_by_element(handle, context->tee_to_en_disp.element, 1, context->display.element, 0);
            ar_pad_link_by_element(handle, context->video_enc.element, 0, context->video_bs_sink.element, 0);
        }
    }else
    {
        ar_pad_link_by_element(handle, context->comp.element, 0, context->video_enc.element, 0);
        ar_pad_link_by_element(handle, context->video_enc.element, 0, context->video_bs_sink.element, 0);
    }
    sprintf(encoder_dev, "/dev/%s", context->video_enc.object_name);
    do {
        sleep(1);
        vhandle = ar_video_codec_open(encoder_dev);
    } while (vhandle == NULL);
    ar_vcodec_ctrl_rotation_t rotation_t;
    rotation_t.rotation_enable = 1;
    rotation_t.angle = angle;
    ar_video_encoder_set_rotation(vhandle, &rotation_t);
    ar_video_codec_close(vhandle);

    ar_element_set_state(handle, (ar_pipeline_t)context->pipeline.element,AR_ELEMENT_STATE_READY);

    log_always("we register a message to detected sensor msg");
       /* create message thread */
    int32_t ret = ar_mm_message_thread_create(handle,
                                    NULL,
                                    ipcam_process_msg,
                                    (void*)(ipcam_server) );

    if(ret != AR_MULTIMEDIA_SUCCESS){
        log_err("to create msg proc  failed");
    }
    return (void*)context;
}

void *ipcam_init(ipcam_codec_type_t codec_type, int width1, int height1, int width2, int height2, int angle, int camera_idx)
{
    if (width1 == 0)
        width1 = 1920;
    if (height1 == 0)
        height1 = 1080;
    if (width2 == 0)
        width2 = 1280;
    if (height2 == 0)
        height2 = 720;
    if (angle % 90 != 0) {
        angle = 0;
        printf("angle=%d must be divided by 90", angle);
    }
    return ipcam_init_impl(codec_type, width1, height1, width2, height2, angle, camera_idx);
}

void ipcam_final(void)
{
    return;
}
