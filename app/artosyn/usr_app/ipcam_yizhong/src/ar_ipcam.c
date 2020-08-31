#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "ar_meta_define.h"
#include "ar_multimedia_base.h"
#include "ar_ipcam_type.h"
#include "ar_ipcam.h"
#define ENABALE_ALL_LOG
#include "ar_log.h"

static void ipcam_get_context(void** context, uint32_t* context_size)
{
    static ar_facotry_element_obj_t ipcam_init_list[] =
    {
        /* shoule match with context */
        {"pipeline",{"ipcam_pipeline"},NULL},
        {"cam_src",{""},NULL},
        {"tee",{""},NULL},
        {"tee",{""},NULL},
        {"user_compositor",{""},NULL},
        {"hevc_encoder",{""},NULL},
        {"hevc_encoder",{""},NULL},
        {"avc_encoder",{""},NULL},
        {"avc_encoder",{""},NULL},
        {"icc_proxy_rpc_sink",{""},NULL},
        {"icc_proxy_rpc_sink",{""},NULL},
        {"icc_proxy_rpc_sink",{"video_yuv-0"},NULL},
        {"icc_proxy_rpc_sink",{"video_yuv-1"},NULL},
    };
    *context = (void*)&ipcam_init_list;
    *context_size = sizeof(ipcam_init_list)/sizeof(ar_facotry_element_obj_t);
}

ipcam_obj_t *ipcam_init(void)
{
    ipcam_obj_t *obj = NULL;
    unsigned int width = 1920, height = 1080, context_size = 0;
    int cam_id=0;
    ipcam_context_t *context = NULL;

    obj = malloc(sizeof(ipcam_obj_t));
    if (!obj) {
        printf("malloc obj failed");
        return NULL;
    }

    memset(obj, 0, sizeof(ipcam_obj_t));
    obj->handle = ar_multimedia_core_device_open();
    ipcam_get_context((void**)&context, &context_size);
    if(ar_element_factory_make_many(obj->handle, context_size, (ar_facotry_element_obj_t*)context) != AR_MULTIMEDIA_SUCCESS){
        printf("make element failed");
        free(obj);
        return NULL;
    }
    /* set default parameters */
    obj->enc_type = IPCAM_CODEC_HEVC;
    obj->cam_num = 1;
    obj->hdr_mode = 0;
    obj->fps = 30;
    obj->width[IPCAM_MAIN] = 1920;
    obj->height[IPCAM_MAIN] = 1080;
    obj->width[IPCAM_MINOR] = 1280;
    obj->height[IPCAM_MINOR] = 720;
    obj->bitrate[IPCAM_MAIN] = 3*1024;
    obj->bitrate[IPCAM_MINOR] = 2*1024;
    obj->ipcam_context = context;

    return obj;
}
int ipcam_start_stream_impl(void *ipcam_obj)
{
    unsigned int cam_id = 0, queue_depth = 10;
    ipcam_context_t *context = NULL;
    ipcam_obj_t *obj = ipcam_obj;

    if (!obj || !obj->ipcam_context) {
        printf("ipcam start stream obj error");
        return -1;
    }
    /* change cam src property */
    if (obj->cam_num == 1)
        cam_id = 0;
    else
        printf("not support %d cameras", obj->cam_num);
    context = obj->ipcam_context;

    ar_element_modify_property_value(obj->handle, context->cam_src.element, AR_VIDEO_CAM_SET_ID, &cam_id, sizeof(uint32_t));
    //set fps
    int vfe_en = obj->hdr_mode;
    if (vfe_en) {
        ar_element_modify_property_value(obj->handle,context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
        ar_element_modify_property_value(obj->handle,context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DDR,strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DDR)+1);
        ar_element_modify_property_value(obj->handle,context->cam_src.element,AR_VIDEO_CAM_SET_VFE_EN,&vfe_en,sizeof(int));
    } else {
        ar_element_modify_property_value(obj->handle,context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL)+1);
        ar_element_modify_property_value(obj->handle,context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT,strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT)+1);
        ar_element_modify_property_value(obj->handle,context->cam_src.element,AR_VIDEO_CAM_SET_VFE_EN,&vfe_en,sizeof(int));
    }

    ar_pad_modify_meta_value(obj->handle, ar_element_get_src_pad_by_idx(obj->handle, context->cam_src.element, 0),
                            AR_COMMON_META_VIDEO_WIDTH_NAME,&obj->width[IPCAM_MAIN], sizeof(uint32_t));
    ar_pad_modify_meta_value(obj->handle, ar_element_get_src_pad_by_idx(obj->handle, context->cam_src.element, 0),
                            AR_COMMON_META_VIDEO_HEIGHT_NAME, &obj->height[IPCAM_MAIN], sizeof(uint32_t));
    ar_pad_modify_meta_value(obj->handle, ar_element_get_src_pad_by_idx(obj->handle, context->cam_src.element, 1),
                            AR_COMMON_META_VIDEO_WIDTH_NAME, &obj->width[IPCAM_MINOR], sizeof(uint32_t));
    ar_pad_modify_meta_value(obj->handle, ar_element_get_src_pad_by_idx(obj->handle, context->cam_src.element, 1),
                            AR_COMMON_META_VIDEO_HEIGHT_NAME, &obj->height[IPCAM_MINOR], sizeof(uint32_t));

    int den = 1;
    ar_pad_modify_meta_value(obj->handle,ar_element_get_src_pad_by_idx(obj->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&obj->fps,sizeof(int));
    ar_pad_modify_meta_value(obj->handle,ar_element_get_src_pad_by_idx(obj->handle,context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));
    ar_pad_modify_meta_value(obj->handle,ar_element_get_src_pad_by_idx(obj->handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&obj->fps,sizeof(int));
    ar_pad_modify_meta_value(obj->handle,ar_element_get_src_pad_by_idx(obj->handle,context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));

    /* change icc_proxy_sink property */
    ar_element_modify_property_value(obj->handle, context->video_bs_sink1.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth, sizeof(uint32_t));
    ar_element_modify_property_value(obj->handle, context->video_bs_sink2.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth, sizeof(uint32_t));
    ar_element_modify_property_value(obj->handle, context->yuv_0_sink.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth, sizeof(uint32_t));
    ar_element_modify_property_value(obj->handle, context->yuv_1_sink.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH,&queue_depth, sizeof(uint32_t));
  /* add all element to pipeline/subpipe */

    ar_pipeline_add_many(obj->handle, (ar_pipeline_t)context->pipeline.element,\
                        context->cam_src.element, context->yuv1_tee.element, \
                        context->yuv2_tee.element, context->comp1.element, \
                        context->video_bs_sink1.element, \
                        context->video_bs_sink2.element, \
                        context->yuv_0_sink.element, \
                        context->yuv_1_sink.element, NULL);
    /* set bit rate */
    ar_element_modify_property_value(obj->handle, context->hevc_enc1.element,AR_VIDEO_CODEC_META_BITRATE, &obj->bitrate[IPCAM_MAIN], sizeof(uint32_t));
    ar_element_modify_property_value(obj->handle, context->hevc_enc2.element,AR_VIDEO_CODEC_META_BITRATE, &obj->bitrate[IPCAM_MINOR], sizeof(uint32_t));
    ar_element_modify_property_value(obj->handle, context->avc_enc1.element, AR_VIDEO_CODEC_META_BITRATE, &obj->bitrate[IPCAM_MAIN], sizeof(uint32_t));
    ar_element_modify_property_value(obj->handle, context->avc_enc2.element,AR_VIDEO_CODEC_META_BITRATE, &obj->bitrate[IPCAM_MINOR], sizeof(uint32_t));
    if (obj->enc_type == IPCAM_CODEC_HEVC) {
        ar_pipeline_add_many(obj->handle, (ar_pipeline_t)context->pipeline.element, \
            context->hevc_enc1.element, context->hevc_enc2.element, NULL);
    } else {
        ar_pipeline_add_many(obj->handle, (ar_pipeline_t)context->pipeline.element, \
            context->avc_enc1.element, context->avc_enc2.element, NULL);
    }
    /* link pads */
    ar_pad_link_by_element(obj->handle, context->cam_src.element, 0, context->yuv1_tee.element, 0);
    ar_pad_link_by_element(obj->handle, context->cam_src.element, 1, context->yuv2_tee.element, 0);
    ar_pad_link_by_element(obj->handle, context->yuv1_tee.element, 0, context->yuv_0_sink.element, 0);
    ar_pad_link_by_element(obj->handle, context->yuv1_tee.element, 1, context->comp1.element, 0);
    ar_pad_link_by_element(obj->handle, context->yuv2_tee.element, 0, context->yuv_1_sink.element, 0);
    //ar_pad_link_by_element(obj->handle, context->yuv2_tee.element, 1, context->comp2.element, 0);
    if (obj->enc_type == IPCAM_CODEC_HEVC) {
        ar_pad_link_by_element(obj->handle, context->comp1.element, 0, context->hevc_enc1.element, 0);
        ar_pad_link_by_element(obj->handle, context->hevc_enc1.element, 0, context->video_bs_sink1.element, 0);
        ar_pad_link_by_element(obj->handle, context->yuv2_tee.element, 1, context->hevc_enc2.element, 0);
        ar_pad_link_by_element(obj->handle, context->hevc_enc2.element, 0, context->video_bs_sink2.element, 0);
    } else {
        ar_pad_link_by_element(obj->handle, context->comp1.element, 0, context->avc_enc1.element, 0);
        ar_pad_link_by_element(obj->handle, context->avc_enc1.element, 0, context->video_bs_sink1.element, 0);
        ar_pad_link_by_element(obj->handle, context->yuv2_tee.element, 1, context->avc_enc2.element, 0);
        ar_pad_link_by_element(obj->handle, context->avc_enc2.element, 0, context->video_bs_sink2.element, 0);
    }

    return ar_pipeline_start_stream(obj->handle, context->pipeline.element);
}
int ipcam_stop_stream_impl(void *ipcam_obj)
{
    ipcam_obj_t *obj = ipcam_obj;
    ipcam_context_t *context = NULL;
    if (!obj || !obj->ipcam_context) {
        printf("invaild obj");
        return -1;
    }
    context = obj->ipcam_context;
    return ar_pipeline_terminal_stream(obj->handle, (ar_pipeline_t)context->pipeline.element);
}

int ipcam_change_codec_impl(void * ipcam_obj, unsigned int new_codec)
{
    ipcam_obj_t *obj = ipcam_obj;
    ipcam_context_t *context = NULL;
    if (!obj || !obj->ipcam_context) {
        printf("invaild obj");
        return AR_MULTIMEDIA_INVALID_PARAM;
    }
    context = obj->ipcam_context;
    if (obj->enc_type == new_codec) {
        printf("change codec: current encoder is right no need change\n");
        return AR_MULTIMEDIA_SUCCESS;
    }
    printf("change codec new codec %u\n", new_codec);
    obj->enc_type = new_codec;
    if (ipcam_stop_stream_impl(ipcam_obj) != AR_MULTIMEDIA_SUCCESS)
        return AR_MULTIMEDIA_FAILURE;
    if (new_codec == IPCAM_CODEC_HEVC) {
        ar_pad_unlink_by_element(obj->handle, context->comp1.element, 0, context->avc_enc1.element, 0);
        ar_pad_unlink_by_element(obj->handle, context->avc_enc1.element, 0, context->video_bs_sink1.element, 0);
        ar_pad_unlink_by_element(obj->handle, context->yuv2_tee.element, 1, context->avc_enc2.element, 0);
        ar_pad_unlink_by_element(obj->handle, context->avc_enc2.element, 0, context->video_bs_sink2.element, 0);
        ar_pipeline_remove_element(obj->handle, (ar_pipeline_t)context->pipeline.element, \
                                  context->avc_enc1.element);
        ar_pipeline_remove_element(obj->handle, (ar_pipeline_t)context->pipeline.element, \
                                  context->avc_enc2.element);
        ar_pipeline_add_many(obj->handle, (ar_pipeline_t)context->pipeline.element, \
                                  context->hevc_enc1.element, context->hevc_enc2.element, NULL);
        ar_pad_link_by_element(obj->handle, context->comp1.element, 0, context->hevc_enc1.element, 0);
        ar_pad_link_by_element(obj->handle, context->hevc_enc1.element, 0, context->video_bs_sink1.element, 0);
        ar_pad_link_by_element(obj->handle, context->yuv2_tee.element, 1, context->hevc_enc2.element, 0);
        ar_pad_link_by_element(obj->handle, context->hevc_enc2.element, 0, context->video_bs_sink2.element, 0);
    } else if (new_codec == IPCAM_CODEC_AVC) {
        ar_pad_unlink_by_element(obj->handle, context->comp1.element, 0, context->hevc_enc1.element, 0);
        ar_pad_unlink_by_element(obj->handle, context->hevc_enc1.element, 0, context->video_bs_sink1.element, 0);
        ar_pad_unlink_by_element(obj->handle, context->yuv2_tee.element, 1, context->hevc_enc2.element, 0);
        ar_pad_unlink_by_element(obj->handle, context->hevc_enc2.element, 0, context->video_bs_sink2.element, 0);
        ar_pipeline_remove_element(obj->handle, (ar_pipeline_t)context->pipeline.element, \
                                  context->hevc_enc1.element);
        ar_pipeline_remove_element(obj->handle, (ar_pipeline_t)context->pipeline.element, \
                                  context->hevc_enc2.element);
        ar_pipeline_add_many(obj->handle, (ar_pipeline_t)context->pipeline.element, \
                                  context->avc_enc1.element, context->avc_enc2.element, NULL);
        ar_pad_link_by_element(obj->handle, context->comp1.element, 0, context->avc_enc1.element, 0);
        ar_pad_link_by_element(obj->handle, context->avc_enc1.element, 0, context->video_bs_sink1.element, 0);
        ar_pad_link_by_element(obj->handle, context->yuv2_tee.element, 1, context->avc_enc2.element, 0);
        ar_pad_link_by_element(obj->handle, context->avc_enc2.element, 0, context->video_bs_sink2.element, 0);
    }
    return ar_pipeline_start_stream(obj->handle, (ar_pipeline_t)context->pipeline.element);
}
int ipcam_change_bitrate_impl(void *ipcam_obj, unsigned int idx, unsigned int max_bitrate, unsigned int avg_bitrate)
{
    ipcam_obj_t *obj = ipcam_obj;
    ipcam_context_t *context = NULL;
    int32_t ret1 = AR_MULTIMEDIA_SUCCESS, ret2 = AR_MULTIMEDIA_SUCCESS;

    if (!obj || !obj->ipcam_context) {
        printf("invaild obj");
        return AR_MULTIMEDIA_INVALID_PARAM;
    }
    context = obj->ipcam_context;
    if (obj->bitrate[idx] == avg_bitrate)
        return AR_MULTIMEDIA_SUCCESS;
    obj->bitrate[idx] = avg_bitrate;
    if (idx == IPCAM_MAIN) {
        ret1 = ar_element_modify_property_value(obj->handle, context->hevc_enc1.element,AR_VIDEO_CODEC_META_BITRATE, &avg_bitrate, sizeof(uint32_t));
        ret2 = ar_element_modify_property_value(obj->handle, context->avc_enc1.element,AR_VIDEO_CODEC_META_BITRATE, &avg_bitrate, sizeof(uint32_t));
    } else {
        ret1 = ar_element_modify_property_value(obj->handle, context->avc_enc2.element,AR_VIDEO_CODEC_META_BITRATE, &avg_bitrate, sizeof(uint32_t));
        ret2 = ar_element_modify_property_value(obj->handle, context->hevc_enc2.element,AR_VIDEO_CODEC_META_BITRATE, &avg_bitrate, sizeof(uint32_t));
    }
    if (ret1 != AR_MULTIMEDIA_SUCCESS || ret2 != AR_MULTIMEDIA_SUCCESS)
        return AR_MULTIMEDIA_FAILURE;
    return AR_MULTIMEDIA_SUCCESS;
}

int ipcam_change_resolution_impl(void *ipcam_obj, unsigned int idx, unsigned int width, unsigned int height)
{
    ipcam_obj_t *obj = ipcam_obj;
    ipcam_context_t *context = NULL;
    int32_t ret1 = AR_MULTIMEDIA_SUCCESS, ret2 = AR_MULTIMEDIA_SUCCESS;

    if (!obj || !obj->ipcam_context) {
        printf("invaild obj");
        return AR_MULTIMEDIA_INVALID_PARAM;
    }
    context = obj->ipcam_context;
    if (obj->width[idx] == width && obj->height == height)
        return AR_MULTIMEDIA_SUCCESS;
    obj->width[idx] = width;
    obj->height[idx] = height;
    if (ipcam_stop_stream_impl(ipcam_obj) != AR_MULTIMEDIA_SUCCESS)
        return AR_MULTIMEDIA_FAILURE;
    if (idx == IPCAM_MAIN) {
        ret1 = ar_pad_modify_meta_value(obj->handle, ar_element_get_src_pad_by_idx(obj->handle, context->cam_src.element, 0),
                            AR_COMMON_META_VIDEO_WIDTH_NAME,&obj->width[IPCAM_MAIN], sizeof(uint32_t));
        ret2 = ar_pad_modify_meta_value(obj->handle, ar_element_get_src_pad_by_idx(obj->handle, context->cam_src.element, 0),
                            AR_COMMON_META_VIDEO_HEIGHT_NAME, &obj->height[IPCAM_MAIN], sizeof(uint32_t));
    } else {
        ret1 = ar_pad_modify_meta_value(obj->handle, ar_element_get_src_pad_by_idx(obj->handle, context->cam_src.element, 1),
                            AR_COMMON_META_VIDEO_WIDTH_NAME, &obj->width[IPCAM_MINOR], sizeof(uint32_t));
        ret2 = ar_pad_modify_meta_value(obj->handle, ar_element_get_src_pad_by_idx(obj->handle, context->cam_src.element, 1),
                            AR_COMMON_META_VIDEO_HEIGHT_NAME, &obj->height[IPCAM_MINOR], sizeof(uint32_t));
    }
    if (ret1 != AR_MULTIMEDIA_SUCCESS || ret2 != AR_MULTIMEDIA_SUCCESS)
        return AR_MULTIMEDIA_FAILURE;
    return ar_pipeline_start_stream(obj->handle, (ar_pipeline_t)context->pipeline.element);
}

