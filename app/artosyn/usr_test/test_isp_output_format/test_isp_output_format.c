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
#include "test_isp_output_format.h"

///////////////////////////////////////////////
typedef struct
{
    int cam_id;
    int video_format;
    int width;
    int height;
    int fps_num;
    int fps_den;
	int use_display;
} test_video_param_context_t;


typedef struct
{
     ar_mm_handle_t m_handle_multimedia;
     test_video_param_context_t m_video_param_context;
}test_isp_output_format_context_t;

typedef struct {
    ar_facotry_element_obj_t pipeline;
    ar_facotry_element_obj_t cam_src;
    ar_facotry_element_obj_t sink;
    ar_facotry_element_obj_t display;
} test_isp_output_format_path_context_t;

static void isp_output_format_context_init(void** context, uint32_t* context_size)
{
    static ar_facotry_element_obj_t l_path_init_list[] =
    {
        /* shoule match with context */
        {"pipeline",{0},NULL},
        {"cam_src",{0},NULL},
        {"icc_proxy_rpc_sink",{0},NULL},
        {"display_sink",{0},NULL},
    };
    *context = (void*)&l_path_init_list;
    *context_size = sizeof(l_path_init_list)/sizeof(ar_facotry_element_obj_t);
    return;
}

int test_isp_output_foramt_path_init(test_isp_output_format_context_t *yuv_sensor_test_context)
{
    unsigned int context_size = 0;
    test_isp_output_format_path_context_t *context = NULL;

    log_always("yuv path context init");

    isp_output_format_context_init((void**)&context, &context_size);

    if(ar_element_factory_make_many(yuv_sensor_test_context->m_handle_multimedia\
        ,context_size,(ar_facotry_element_obj_t*)context) != AR_SUCCESS)
    {
        return -1;
    }

    //video
    int cam_id=yuv_sensor_test_context->m_video_param_context.cam_id;

    log_always("AR_VIDEO_CAM_SET_ID : %d",cam_id);
    ar_element_modify_property_value(yuv_sensor_test_context->m_handle_multimedia\
        ,context->cam_src.element,AR_VIDEO_CAM_SET_ID,&cam_id,sizeof(int));

    log_always("AR_VIDEO_CAM_MODE : %s",AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL);
    ar_element_modify_property_value(yuv_sensor_test_context->m_handle_multimedia\
        ,context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL)+1);

    log_always("AR_VIDEO_CAM_VIF_ISP_MOD : %s",AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT);
    ar_element_modify_property_value(yuv_sensor_test_context->m_handle_multimedia\
        ,context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT,strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT)+1);


    int video_format = yuv_sensor_test_context->m_video_param_context.video_format;
    log_always("AR_COMMON_META_VIDEO_FORMAT_NAME : %d",video_format);

    ar_pad_modify_meta_value(yuv_sensor_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(yuv_sensor_test_context->m_handle_multimedia,context->cam_src.element, 0)\
        ,AR_COMMON_META_VIDEO_FORMAT_NAME,&video_format,sizeof(int));
#if 0
    ar_pad_modify_meta_value(yuv_sensor_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(yuv_sensor_test_context->m_handle_multimedia,context->cam_src.element, 1)\
        ,AR_COMMON_META_VIDEO_FORMAT_NAME,&video_format,sizeof(int));
#endif


    int width = yuv_sensor_test_context->m_video_param_context.width;
    int height = yuv_sensor_test_context->m_video_param_context.height;
    log_always("AR_COMMON_META_VIDEO_WIDTH_NAME : %d",width);
    ar_pad_modify_meta_value(yuv_sensor_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(yuv_sensor_test_context->m_handle_multimedia,context->cam_src.element, 0)\
        ,AR_COMMON_META_VIDEO_WIDTH_NAME,&width,sizeof(int));
#if 0
    ar_pad_modify_meta_value(yuv_sensor_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(yuv_sensor_test_context->m_handle_multimedia,context->cam_src.element, 1)\
        ,AR_COMMON_META_VIDEO_WIDTH_NAME,&width,sizeof(int));
#endif

    log_always("AR_COMMON_META_VIDEO_HEIGHT_NAME : %d",height);
    ar_pad_modify_meta_value(yuv_sensor_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(yuv_sensor_test_context->m_handle_multimedia,context->cam_src.element, 0)\
        ,AR_COMMON_META_VIDEO_HEIGHT_NAME,&height,sizeof(int));
#if 0
    ar_pad_modify_meta_value(yuv_sensor_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(yuv_sensor_test_context->m_handle_multimedia,context->cam_src.element, 1)\
        ,AR_COMMON_META_VIDEO_HEIGHT_NAME,&height,sizeof(int));
#endif

    int fps_num = yuv_sensor_test_context->m_video_param_context.fps_num;
    int fps_den = yuv_sensor_test_context->m_video_param_context.fps_den;
    log_always("FPS : %d/%d", fps_num, fps_den);
    ar_pad_modify_meta_value(yuv_sensor_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(yuv_sensor_test_context->m_handle_multimedia,context->cam_src.element, 0)\
        ,AR_COMMON_META_VIDEO_FPS_NUM_NAME,&fps_num,sizeof(int));
#if 0
    ar_pad_modify_meta_value(yuv_sensor_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(yuv_sensor_test_context->m_handle_multimedia,context->cam_src.element, 1)\
        ,AR_COMMON_META_VIDEO_FPS_NUM_NAME,&fps_num,sizeof(int));
#endif

    ar_pad_modify_meta_value(yuv_sensor_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(yuv_sensor_test_context->m_handle_multimedia,context->cam_src.element, 0)\
        ,AR_COMMON_META_VIDEO_FPS_DEN_NAME,&fps_den,sizeof(int));
#if 0
    ar_pad_modify_meta_value(yuv_sensor_test_context->m_handle_multimedia\
        ,ar_element_get_src_pad_by_idx(yuv_sensor_test_context->m_handle_multimedia,context->cam_src.element, 1)\
        ,AR_COMMON_META_VIDEO_FPS_DEN_NAME,&fps_den,sizeof(int));
#endif

    int use_display=yuv_sensor_test_context->m_video_param_context.use_display;
	int disp_width =1920;
	int disp_height = 1080;
	int fix_fps =60;
	ar_element_modify_property_value(yuv_sensor_test_context->m_handle_multimedia,context->display.element,AR_DISPLAY_META_OUT_WIDTH,&disp_width,sizeof(int));
	ar_element_modify_property_value(yuv_sensor_test_context->m_handle_multimedia,context->display.element,AR_DISPLAY_META_OUT_HEIGHT,&disp_height,sizeof(int));
	ar_element_modify_property_value(yuv_sensor_test_context->m_handle_multimedia,context->display.element,AR_DISPLAY_META_FIX_FPS,&fix_fps,sizeof(int));

    /* add all element to pipeline/subpipe */
    log_always("pipeline add");
	if(use_display)
	{
		ar_pipeline_add_many(yuv_sensor_test_context->m_handle_multimedia\
		, context->pipeline.element\
		, context->cam_src.element\
		, context->display.element\
		, NULL);

	}else
	{
	       ar_pipeline_add_many(yuv_sensor_test_context->m_handle_multimedia\
           , context->pipeline.element\
           , context->cam_src.element\
           , context->sink.element\
           , NULL);
	}

    /* link pads */
    log_always("pipeline link");

    if(use_display){
        ar_pad_link_by_element(yuv_sensor_test_context->m_handle_multimedia\
        , context->cam_src.element, 0 \
        , context->display.element, 0);
	}else{
        ar_pad_link_by_element(yuv_sensor_test_context->m_handle_multimedia\
        , context->cam_src.element, 0 \
        , context->sink.element, 0);
	}
#if 0
    ar_pad_link_by_element(yuv_sensor_test_context->m_handle_multimedia\
        , context->cam_src.element, 1 \
        , context->sink.element, 1);
#endif
    //ready
    log_always("pipeline set ready");
    ar_element_set_state(yuv_sensor_test_context->m_handle_multimedia\
        ,(ar_pipeline_t)context->pipeline.element,AR_ELEMENT_STATE_READY);

    return 0;
}

void *fun_main_thread(void *arg)
{
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();

    log_always("start pid %u tid %u (0x%x) yuv sensor test\n",(unsigned int) pid\
        ,(unsigned int)tid, (unsigned int)tid);

    while(1)
    {
        usleep(10000);
    }

    return NULL;
}

static int find_pra_index_by_name(char *name,int argc, char *argv[])
{
    for(int i=0;i<argc;i++)
    {
         if(!strcmp(name,argv[i]))
         {
             return i;
         }
    }
    return 0;
}
#define MAX_SUPPORT_OUTPUT_MODE (18)
#define DEFAULT_OUTPUT_MODE (1)
int parse_param(int argc, char const *argv[], test_isp_output_format_context_t *p_context)
{
    static const int output_mode[MAX_SUPPORT_OUTPUT_MODE]={

        [0] = AR_VIDEO_FORMAT_I400, // AR_VIDEO_FORMAT_I400  ->  STREAM_FORMAT_YUV400_8BIT_Plannar  ->  ISP_OUTPUT_YUV400_8BIT_Plannar,
        [1] = AR_VIDEO_FORMAT_I420, // AR_VIDEO_FORMAT_I420  ->  STREAM_FORMAT_YUV420_8BIT_Plannar  ->  ISP_OUTPUT_YUV420_8BIT_Plannar,
        [2] = AR_VIDEO_FORMAT_Y42B, // AR_VIDEO_FORMAT_Y42B  ->  STREAM_FORMAT_YUV422_8BIT_Plannar  ->  ISP_OUTPUT_YUV422_8BIT_Plannar,
        [3] = AR_VIDEO_FORMAT_Y444, // AR_VIDEO_FORMAT_Y444  ->  STREAM_FORMAT_YUV444_8BIT_Plannar  ->  ISP_OUTPUT_YUV444_8BIT_Plannar,
        //new
        [4] = AR_VIDEO_FORMAT_YUV422_SEMI_PLANNAR,// AR_VIDEO_FORMAT_YUV422_SEMI_PLANNAR  ->  STREAM_FORMAT_YUV422_8BIT_semiPlannar  ->  ISP_OUTPUT_YUV422_8BIT_semiPlannar,
        //new
        [5] = AR_VIDEO_FORMAT_Y420_CF50_P8_PLANNAR,//AR_VIDEO_FORMAT_Y420_CF50_P8_PLANNAR -> STREAM_FORMAT_YUV420_CF50_8BIT_Plannar -> ISP_OUTPUT_YUV420_CF50_8BIT_Plannar

        [6] = AR_VIDEO_FORMAT_NV12_P10_32BIT_LE,// AR_VIDEO_FORMAT_NV12_P10_32BIT_LE  ->  STREAM_FORMAT_YUV420_10BIT_semiPlannar_packed  ->  ISP_OUTPUT_YUV420_10BIT_semiPlannar_packed,
        //new
        [7] = AR_VIDEO_FORMAT_YUV422_SEMI_PLANNAR_P10_32BIT_LE, // AR_VIDEO_FORMAT_YUV422_SEMI_PLANNAR_P10_32BIT_LE  ->  STREAM_FORMAT_YUV422_10BIT_semiPlannar_packed  ->  ISP_OUTPUT_YUV422_10BIT_semiPlannar_packed,
        [8] = AR_VIDEO_FORMAT_NV12_P10_16BIT_LE, // AR_VIDEO_FORMAT_NV12_P10_16BIT_LE  ->  STREAM_FORMAT_YUV420_10BIT_semiPlannar_unpacked  ->  ISP_OUTPUT_YUV420_10BIT_semiPlannar_unpacked,
        //new
        [9] = AR_VIDEO_FORMAT_YUV422_SEMI_PLANNAR_P10_16BIT_LE, // AR_VIDEO_FORMAT_YUV422_SEMI_PLANNAR_P10_16BIT_LE  ->  STREAM_FORMAT_YUV422_10BIT_semiPlannar_unpacked  ->  ISP_OUTPUT_YUV422_10BIT_semiPlannar_unpacked,
        //new
        [10] = AR_VIDEO_FORMAT_YUV444_SEMI_PLANNAR_P10_16BIT_LE, // AR_VIDEO_FORMAT_YUV444_SEMI_PLANNAR_P10_16BIT_LE  ->  STREAM_FORMAT_YUV444_10BIT_semiPlannar_unpacked  ->  ISP_OUTPUT_YUV444_10BIT_semiPlannar_unpacked,
        //new
        [11] = AR_VIDEO_FORMAT_Y420_CF50_P10_PLANNAR,//AR_VIDEO_FORMAT_Y420_CF50_P10_PLANNAR -> STREAM_FORMAT_YUV420_CF50_10BIT_Plannar -> ISP_OUTPUT_YUV420_CF50_10BIT_Plannar

        [12] = AR_VIDEO_FORMAT_I420_P10_32BIT_LE,//AR_VIDEO_FORMAT_I420_P10_32BIT_LE -> STREAM_FORMAT_YUV420_10BIT_Plannar_packed -> ISP_OUTPUT_YUV420_10BIT_Plannar_packed
        [13] = AR_VIDEO_FORMAT_Y42B_P10_32BIT_LE,//AR_VIDEO_FORMAT_Y42B_P10_32BIT_LE -> STREAM_FORMAT_YUV422_10BIT_Plannar_packed -> ISP_OUTPUT_YUV422_10BIT_Plannar_packed

        [14] = AR_VIDEO_FORMAT_I420_P10_16BIT_LE,//AR_VIDEO_FORMAT_I420_P10_16BIT_LE -> STREAM_FORMAT_YUV420_10BIT_Plannar_unpacked -> ISP_OUTPUT_YUV420_10BIT_Plannar_unpacked
        [15] = AR_VIDEO_FORMAT_Y42B_P10_16BIT_LE,//AR_VIDEO_FORMAT_Y42B_P10_16BIT_LE -> STREAM_FORMAT_YUV422_10BIT_Plannar_unpacked -> ISP_OUTPUT_YUV422_10BIT_Plannar_unpacked
        [16] = AR_VIDEO_FORMAT_Y444_P10_16BIT_LE,//AR_VIDEO_FORMAT_Y444_P10_16BIT_LE -> STREAM_FORMAT_YUV444_10BIT_Plannar_unpacked -> ISP_OUTPUT_YUV444_10BIT_Plannar_unpacked

        [17] = AR_VIDEO_FORMAT_Y444_P10_32BIT_LE,// AR_VIDEO_FORMAT_Y444_P10_32BIT_LE -> STREAM_FORMAT_YUV444_10BIT_Plannar_packed -> ISP_OUTPUT_YUV444_10BIT_Plannar_packed
    };

    int index;
    int tmp_data;

    index = find_pra_index_by_name("--help",argc, argv);
    if(index)
    {
       printf("--help: show this help \n");
       printf("--mod [mode]: isp out mode for format \n");
	   printf("      0:AR_VIDEO_FORMAT_I400 //AR_VIDEO_FORMAT_I400  ->  STREAM_FORMAT_YUV400_8BIT_Plannar  ->  ISP_OUTPUT_YUV400_8BIT_Plannar\n");
	   printf("      1:AR_VIDEO_FORMAT_I420 // AR_VIDEO_FORMAT_I420  ->  STREAM_FORMAT_YUV420_8BIT_Plannar  ->  ISP_OUTPUT_YUV420_8BIT_Plannar,\n");
	   printf("      2:AR_VIDEO_FORMAT_Y42B // AR_VIDEO_FORMAT_Y42B  ->  STREAM_FORMAT_YUV422_8BIT_Plannar  ->  ISP_OUTPUT_YUV422_8BIT_Plannar,\n");
	   printf("      3:AR_VIDEO_FORMAT_Y444 // AR_VIDEO_FORMAT_Y444  ->  STREAM_FORMAT_YUV444_8BIT_Plannar  ->  ISP_OUTPUT_YUV444_8BIT_Plannar,\n");
	   printf("      4:AR_VIDEO_FORMAT_YUV422_SEMI_PLANNAR // AR_VIDEO_FORMAT_YUV422_SEMI_PLANNAR  ->  STREAM_FORMAT_YUV422_8BIT_semiPlannar  ->  ISP_OUTPUT_YUV422_8BIT_semiPlannar,\n");
	   printf("      5:AR_VIDEO_FORMAT_Y420_CF50_P8_PLANNAR //AR_VIDEO_FORMAT_Y420_CF50_P8_PLANNAR -> STREAM_FORMAT_YUV420_CF50_8BIT_Plannar -> ISP_OUTPUT_YUV420_CF50_8BIT_Plannar\n");
	   printf("      6:AR_VIDEO_FORMAT_NV12_P10_32BIT_LE // AR_VIDEO_FORMAT_NV12_P10_32BIT_LE  ->  STREAM_FORMAT_YUV420_10BIT_semiPlannar_packed  ->  ISP_OUTPUT_YUV420_10BIT_semiPlannar_packed,\n");
	   printf("      7:AR_VIDEO_FORMAT_YUV422_SEMI_PLANNAR_P10_32BIT_LE // AR_VIDEO_FORMAT_YUV422_SEMI_PLANNAR_P10_32BIT_LE  ->  STREAM_FORMAT_YUV422_10BIT_semiPlannar_packed  ->  ISP_OUTPUT_YUV422_10BIT_semiPlannar_packed,\n");
	   printf("      8:AR_VIDEO_FORMAT_NV12_P10_16BIT_LE // AR_VIDEO_FORMAT_NV12_P10_16BIT_LE  ->  STREAM_FORMAT_YUV420_10BIT_semiPlannar_unpacked  ->  ISP_OUTPUT_YUV420_10BIT_semiPlannar_unpacked,\n");
	   printf("      9:AR_VIDEO_FORMAT_YUV422_SEMI_PLANNAR_P10_16BIT_LE // AR_VIDEO_FORMAT_YUV422_SEMI_PLANNAR_P10_16BIT_LE  ->  STREAM_FORMAT_YUV422_10BIT_semiPlannar_unpacked  ->  ISP_OUTPUT_YUV422_10BIT_semiPlannar_unpacked,\n");
	   printf("      10:AR_VIDEO_FORMAT_YUV444_SEMI_PLANNAR_P10_16BIT_LE // AR_VIDEO_FORMAT_YUV444_SEMI_PLANNAR_P10_16BIT_LE  ->  STREAM_FORMAT_YUV444_10BIT_semiPlannar_unpacked  ->  ISP_OUTPUT_YUV444_10BIT_semiPlannar_unpacked,\n");
	   printf("      11:AR_VIDEO_FORMAT_Y420_CF50_P10_PLANNAR //AR_VIDEO_FORMAT_Y420_CF50_P10_PLANNAR -> STREAM_FORMAT_YUV420_CF50_10BIT_Plannar -> ISP_OUTPUT_YUV420_CF50_10BIT_Plannar\n");
	   printf("      12:AR_VIDEO_FORMAT_I420_P10_32BIT_LE //AR_VIDEO_FORMAT_I420_P10_32BIT_LE -> STREAM_FORMAT_YUV420_10BIT_Plannar_packed -> ISP_OUTPUT_YUV420_10BIT_Plannar_packed\n");
	   printf("      13:AR_VIDEO_FORMAT_Y42B_P10_32BIT_LE //AR_VIDEO_FORMAT_Y42B_P10_32BIT_LE -> STREAM_FORMAT_YUV422_10BIT_Plannar_packed -> ISP_OUTPUT_YUV422_10BIT_Plannar_packed\n");
	   printf("      14:AR_VIDEO_FORMAT_I420_P10_16BIT_LE //AR_VIDEO_FORMAT_I420_P10_16BIT_LE -> STREAM_FORMAT_YUV420_10BIT_Plannar_unpacked -> ISP_OUTPUT_YUV420_10BIT_Plannar_unpacked\n");
	   printf("      15:AR_VIDEO_FORMAT_Y42B_P10_16BIT_LE //AR_VIDEO_FORMAT_Y42B_P10_16BIT_LE -> STREAM_FORMAT_YUV422_10BIT_Plannar_unpacked -> ISP_OUTPUT_YUV422_10BIT_Plannar_unpacked\n");
	   printf("      16:AR_VIDEO_FORMAT_Y444_P10_16BIT_LE //AR_VIDEO_FORMAT_Y444_P10_16BIT_LE -> STREAM_FORMAT_YUV444_10BIT_Plannar_unpacked -> ISP_OUTPUT_YUV444_10BIT_Plannar_unpacked\n");
	   printf("      17:AR_VIDEO_FORMAT_Y444_P10_32BIT_LE // AR_VIDEO_FORMAT_Y444_P10_32BIT_LE -> STREAM_FORMAT_YUV444_10BIT_Plannar_packed -> ISP_OUTPUT_YUV444_10BIT_Plannar_packed\n");
	   printf("--res [w] [h]: set isp out w h\n");
       printf("--display: out to the display \n");
       return -1;
    }


    index = find_pra_index_by_name("--mod",argc, argv);
    if(index){
        tmp_data = strtol(argv[index+1], NULL, 0);
        if(tmp_data<MAX_SUPPORT_OUTPUT_MODE && tmp_data>=0)
        {
            log_always("set mode %d", tmp_data);
            p_context->m_video_param_context.video_format = output_mode[tmp_data];
        }
        else
        {
            log_err("out-of-range input %d>%d, use default %d",index,MAX_SUPPORT_OUTPUT_MODE, DEFAULT_OUTPUT_MODE);
            p_context->m_video_param_context.video_format = output_mode[DEFAULT_OUTPUT_MODE];
        }
    }

    index = find_pra_index_by_name("--res",argc, argv);
    if(index){
        tmp_data = strtol(argv[index+1], NULL, 0);
        if(tmp_data>=0)
        {
            log_always("set width %d", tmp_data);
            p_context->m_video_param_context.width = tmp_data;
        }
        else
        {
            log_err("out-of-range , use width %d",p_context->m_video_param_context.width);
        }

        tmp_data = strtol(argv[index+2], NULL, 0);
        if(tmp_data>=0)
        {
            log_always("set height %d", tmp_data);
            p_context->m_video_param_context.height = tmp_data;
        }
        else
        {
            log_err("out-of-range , use height %d",p_context->m_video_param_context.height);
        }
    }
	p_context->m_video_param_context.use_display= 0;
    index = find_pra_index_by_name("--display",argc, argv);
	if(index>0)
	{
		p_context->m_video_param_context.use_display=1;
	}
    return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    creat_back_trace();

    test_isp_output_format_context_t l_test_context={
        .m_handle_multimedia = NULL,
        .m_video_param_context = {
            .cam_id=0,
            .video_format = AR_VIDEO_FORMAT_Y42B,
            .width =1920,
            .height = 1080,
            .fps_num = 30,
            .fps_den = 1,
        },
    };

    if(argc > 1)
    {
        //parse input pararmeter
        int ret=parse_param(argc, argv, &l_test_context);
		if(ret<0)
		{
		  return 0;
		}
    }

    int count=5;

    log_always("multimedia core device open");
    do{
        usleep(1000*1000);
        l_test_context.m_handle_multimedia = ar_multimedia_core_device_open();
        count--;
    }while(!l_test_context.m_handle_multimedia && count>0);

    if(!l_test_context.m_handle_multimedia)
    {
         log_err("can not open multicore try 5000 times dur 5s,exit the app, please checkout your frame work !!!!");
         return -1;
    }
    log_always("path init");
    if( test_isp_output_foramt_path_init(&l_test_context) )
    {
        log_err("path create\n");
        ar_multimedia_core_device_close(l_test_context.m_handle_multimedia);
        return -1;
    }
    else
    {
        log_always("path init over");
    }

    pthread_t pid_main_thread;
    int err;

    err = pthread_create(&pid_main_thread,NULL,fun_main_thread, NULL);
    if(0 != err)
    {
        log_err("can't create thread show date : %s\n",strerror(err));
    }

    pthread_join(pid_main_thread,NULL);

    ar_multimedia_core_device_close(l_test_context.m_handle_multimedia);
    log_always("{%d:%s} [info] test exit...\n",__LINE__,__FUNCTION__);

    return 0;
}
