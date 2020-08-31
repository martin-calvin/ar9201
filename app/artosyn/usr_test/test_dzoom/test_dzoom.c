#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "ar_common_define.h"
#include "ar_meta_define.h"
#include "ar_multimedia_base.h"
#include "ar_log.h"
// #include "ar_gui.h"

#include "backtrace.h"
#include "test_dzoom.h"

///////////////////////////////////////////////
typedef struct
{
    int m_cam_id;
    int m_video_format;
    int m_width[3];
    int m_height[3];
    int m_fps_num;
    int m_fps_den;
    double m_zoom[3];
} test_video_param_context_t;

typedef struct
{
     ar_mm_handle_t m_handle_multimedia;
     test_video_param_context_t m_video_param_context;
}test_context_t;

typedef struct {
    ar_facotry_element_obj_t pipeline;
    ar_facotry_element_obj_t cam_src;
    ar_facotry_element_obj_t sink;
} test_path_context_t;

static void test_path_context_init(void** context, uint32_t* context_size)
{
    static ar_facotry_element_obj_t test_path_init_list[] =
    {
        /* shoule match with context */
        {"pipeline",{0},NULL},
        {"cam_src",{0},NULL},
        {"display_sink",{0},NULL},
    };
    *context = (void*)&test_path_init_list;
    *context_size = sizeof(test_path_init_list)/sizeof(ar_facotry_element_obj_t);
    return;
}

int test_path_init(test_context_t *p_test_context)
{
    unsigned int context_size = 0;
    test_path_context_t *context = NULL;

    log_always("yuv path context init");

    test_path_context_init((void**)&context, &context_size);

    if(ar_element_factory_make_many(p_test_context->m_handle_multimedia\
        ,context_size,(ar_facotry_element_obj_t*)context) != AR_SUCCESS)
    {
        return -1;
    }

    //video
    int cam_id=p_test_context->m_video_param_context.m_cam_id;

    log_always("AR_VIDEO_CAM_SET_ID : %d",cam_id);
    ar_element_modify_property_value(p_test_context->m_handle_multimedia\
        ,context->cam_src.element,AR_VIDEO_CAM_SET_ID,&cam_id,sizeof(int));

    log_always("AR_VIDEO_CAM_MODE : %s",AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL);
    ar_element_modify_property_value(p_test_context->m_handle_multimedia\
        ,context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL)+1);

    int video_format = p_test_context->m_video_param_context.m_video_format;
    log_always("AR_COMMON_META_VIDEO_FORMAT_NAME : %d",video_format);
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 0)\
        ,AR_COMMON_META_VIDEO_FORMAT_NAME,&video_format,sizeof(int));
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 1)\
        ,AR_COMMON_META_VIDEO_FORMAT_NAME,&video_format,sizeof(int));
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 2)\
        ,AR_COMMON_META_VIDEO_FORMAT_NAME,&video_format,sizeof(int));

    int width =p_test_context->m_video_param_context.m_width[0];
    int height = p_test_context->m_video_param_context.m_height[0];
    log_always("0 AR_COMMON_META_VIDEO_WIDTH_NAME : %d",width);
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 0)\
        ,AR_COMMON_META_VIDEO_WIDTH_NAME,&width,sizeof(int));
    log_always("0 AR_COMMON_META_VIDEO_HEIGHT_NAME : %d",height);
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 0)\
        ,AR_COMMON_META_VIDEO_HEIGHT_NAME,&height,sizeof(int));

    width =p_test_context->m_video_param_context.m_width[1];
    height = p_test_context->m_video_param_context.m_height[1];
    log_always("1 AR_COMMON_META_VIDEO_WIDTH_NAME : %d",width);
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 1)\
        ,AR_COMMON_META_VIDEO_WIDTH_NAME,&width,sizeof(int));
    log_always("1 AR_COMMON_META_VIDEO_HEIGHT_NAME : %d",height);
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 1)\
        ,AR_COMMON_META_VIDEO_HEIGHT_NAME,&height,sizeof(int));

    width =p_test_context->m_video_param_context.m_width[2];
    height = p_test_context->m_video_param_context.m_height[2];
    log_always("2 AR_COMMON_META_VIDEO_WIDTH_NAME : %d",width);
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 2)\
        ,AR_COMMON_META_VIDEO_WIDTH_NAME,&width,sizeof(int));
    log_always("2 AR_COMMON_META_VIDEO_HEIGHT_NAME : %d",height);
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 2)\
        ,AR_COMMON_META_VIDEO_HEIGHT_NAME,&height,sizeof(int));


    int fps_num = p_test_context->m_video_param_context.m_fps_num;
    int fps_den = p_test_context->m_video_param_context.m_fps_den;
    log_always("FPS : %d/%d", fps_num, fps_den);
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 0)\
        ,AR_COMMON_META_VIDEO_FPS_NUM_NAME,&fps_num,sizeof(int));
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 1)\
        ,AR_COMMON_META_VIDEO_FPS_NUM_NAME,&fps_num,sizeof(int));
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 2)\
        ,AR_COMMON_META_VIDEO_FPS_NUM_NAME,&fps_num,sizeof(int));

    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 0)\
        ,AR_COMMON_META_VIDEO_FPS_DEN_NAME,&fps_den,sizeof(int));
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 1)\
        ,AR_COMMON_META_VIDEO_FPS_DEN_NAME,&fps_den,sizeof(int));
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 2)\
        ,AR_COMMON_META_VIDEO_FPS_DEN_NAME,&fps_den,sizeof(int));

    double zoom = p_test_context->m_video_param_context.m_zoom[0];
    log_always("0 zoom : %f", zoom);
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 0)\
        ,AR_COMMON_META_VIDEO_DIGITAL_ZOOM_NAME,&zoom,sizeof(double));

    zoom = p_test_context->m_video_param_context.m_zoom[1];
    log_always("1 zoom : %f", zoom);
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 1)\
        ,AR_COMMON_META_VIDEO_DIGITAL_ZOOM_NAME,&zoom,sizeof(double));

    zoom = p_test_context->m_video_param_context.m_zoom[2];
    log_always("2 zoom : %f", zoom);
    ar_pad_modify_meta_value(p_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(p_test_context->m_handle_multimedia,context->cam_src.element, 2)\
        ,AR_COMMON_META_VIDEO_DIGITAL_ZOOM_NAME,&zoom,sizeof(double));

    int disp_width = 1920;
    int disp_height = 1080;
    int display_fix_fps = 60;
    ar_element_modify_property_value(p_test_context->m_handle_multimedia\
        ,context->sink.element,AR_DISPLAY_META_OUT_WIDTH,&disp_width,sizeof(int));
    ar_element_modify_property_value(p_test_context->m_handle_multimedia\
        ,context->sink.element,AR_DISPLAY_META_OUT_HEIGHT,&disp_height,sizeof(int));
    ar_element_modify_property_value(p_test_context->m_handle_multimedia\
        ,context->sink.element,AR_DISPLAY_META_FIX_FPS,&display_fix_fps,sizeof(int));

    /* add all element to pipeline/subpipe */
    log_always("pipeline add");
    ar_pipeline_add_many(p_test_context->m_handle_multimedia\
        , context->pipeline.element\
        , context->cam_src.element\
        , context->sink.element\
        , NULL);

    /* link pads */
    log_always("pipeline link");
    ar_pad_link_by_element(p_test_context->m_handle_multimedia\
        , context->cam_src.element, 0\
        , context->sink.element, 0);
    ar_pad_link_by_element(p_test_context->m_handle_multimedia\
        , context->cam_src.element, 1\
        , context->sink.element, 1);
    ar_pad_link_by_element(p_test_context->m_handle_multimedia\
        , context->cam_src.element, 2\
        , context->sink.element, 2);

    //ready
    log_always("pipeline set ready");
    ar_element_set_state(p_test_context->m_handle_multimedia\
        ,(ar_pipeline_t)context->pipeline.element,AR_ELEMENT_STATE_READY);

    return 0;
}

void fun_endless_loop(void *arg)
{
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();

    log_always("start pid %u tid %u (0x%x) endless\n",(unsigned int) pid\
        ,(unsigned int)tid, (unsigned int)tid);

    while(1)
    {
        usleep(10000);
    }
}

int parse_param(char *cmd)
{
    if(!(strcmp(cmd, "--720P"))){
        return 1;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    back_trace_t *back_trace=creat_back_trace();

    test_context_t test_context = {
        .m_handle_multimedia = NULL,
        .m_video_param_context = {
            .m_cam_id=0,
            .m_video_format = AR_VIDEO_FORMAT_I420,
            .m_width ={
                [0] = 1920,
                [1] = 1280,
                [2] = 640,
            },
            .m_height = {
                [0] = 1080,
                [1] = 720,
                [2] = 480,
            },
            .m_fps_num = 30,
            .m_fps_den = 1,
            .m_zoom = {
                [0] = 1.0,
                [1] = 1.0,
                [2] = 1.0,
            },
        },
    };

    int count=5;

    log_always("multimedia core device open");
    do{
        usleep(1000*1000);
        test_context.m_handle_multimedia = ar_multimedia_core_device_open();
        count--;
    }while(!test_context.m_handle_multimedia && count>0);

    if(!test_context.m_handle_multimedia)
    {
         log_err("can not open multicore try 5000 times dur 5s,exit the app, please checkout your frame work !!!!");
         return -1;
    }

    log_always("path init");
    if(test_path_init(&test_context))
    {
        log_err("path create\n");
        ar_multimedia_core_device_close(test_context.m_handle_multimedia);
        return -1;
    }
    else
    {
        log_always("path init over");
    }

    pthread_t pid_endless_loop;
    int err;

    err = pthread_create(&pid_endless_loop,NULL,fun_endless_loop, NULL);
    if(0 != err)
    {
        log_err("can't create thread show date : %s\n",strerror(err));
    }

    pthread_join(pid_endless_loop,NULL);

    ar_multimedia_core_device_close(test_context.m_handle_multimedia);
    log_always("{%d:%s} [info] test exit...\n",__LINE__,__FUNCTION__);

    return 0;
}