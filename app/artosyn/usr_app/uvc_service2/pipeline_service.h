#ifndef __PIPELINE_SERVICE_H__
#define __PIPELINE_SERVICE_H__

#include "ar_video_stream.h"
#include "ar_pipeline_ctrl.h"
#include "ar_system.h"
#include "ar_meta_define.h"
#include "ar_multimedia_base.h"
#include "pipeline_ctl.h"

typedef struct
{
    ar_facotry_element_obj_t pipeline;
    ar_facotry_element_obj_t cam_src;
    //ar_facotry_element_obj_t tee;
    ar_facotry_element_obj_t comp;
    ar_facotry_element_obj_t hevc_enc;
    ar_facotry_element_obj_t avc_enc;
    ar_facotry_element_obj_t mjpeg_enc;
    ar_facotry_element_obj_t yuv_enc;
    ar_facotry_element_obj_t mjpeg_bs_sink;
    /* yuv pipeline */
    ar_facotry_element_obj_t yuv_0_tee;
    ar_facotry_element_obj_t yuv_0_sink;
    ar_facotry_element_obj_t yuv_1_tee;
    ar_facotry_element_obj_t yuv_1_sink;
    ar_facotry_element_obj_t display_tee;
    ar_facotry_element_obj_t display;
    pipeline_ctl_server_t *server_l;
} ar_uvc_context_t;

typedef struct {
    ar_facotry_element_obj_t pipeline;
    ar_facotry_element_obj_t cam_src;
    ar_facotry_element_obj_t tee;
    ar_facotry_element_obj_t comp;
    ar_facotry_element_obj_t display;
    /* jpeg sub pipeline */
    ar_facotry_element_obj_t on_off;
    ar_facotry_element_obj_t jpeg_enc;
    ar_facotry_element_obj_t jpeg_bs_sink;

    /* yuv pipeline */
    ar_facotry_element_obj_t yuv_0_tee;
    ar_facotry_element_obj_t yuv_0_sink;
    ar_facotry_element_obj_t yuv_1_tee;
    ar_facotry_element_obj_t yuv_1_sink;
    pipeline_ctl_server_t *server_l;
} ar_uvc_hdmi_context_t;


int find_pra_index_by_name(char *name,int argc, char *argv[]);
void ar_uvc_get_context(void** context, uint32_t* context_size);
void ar_uvc_hdmi_context(void** context, uint32_t* context_size);
void ar_uvc_init(ar_mm_handle_t handle,int argc, char *argv[]);
void ar_uvc_deinit(ar_mm_handle_t handle);
int uvc_pipeline_set_format(unsigned int width, unsigned int height, unsigned int fps, unsigned int format);
void ar_uvc_hdmi_init(ar_mm_handle_t handle,int argc, char *argv[]);
#endif
