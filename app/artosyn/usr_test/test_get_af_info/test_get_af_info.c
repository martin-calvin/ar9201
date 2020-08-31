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

#include "backtrace.h"
#include "cam_type_def.h"
#include "ar_cam_src.h"
#include "test_get_af_info.h"

///////////////////////////////////////////////

typedef struct
{
    int fd_cam;
    int fd_mem;
    int cam_id;
} test_context_t;

///////////////////////////////////////////////

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

int parse_param(int argc, char const *argv[], test_context_t *p_context)
{
    int index;
    int tmp_data;

    index = find_pra_index_by_name("--cam",argc, argv);
    if(index){
        tmp_data = strtol(argv[index+1], NULL, 0);
        log_always("set cam id %d", tmp_data);
        p_context->cam_id = tmp_data;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    creat_back_trace();

    test_context_t test_context={
        .fd_cam = 0,
        .fd_mem = 0,
        .cam_id = 0,
    };

    parse_param(argc, argv, &test_context);

    char dev_cam_name[32];

    snprintf(dev_cam_name,32,"/dev/cam_src-%d", test_context.cam_id);
    test_context.fd_cam = ar_cam_src_open(dev_cam_name);
    if(test_context.fd_cam <= 0)
    {
        printf("[err] to open %s",dev_cam_name);
        goto __test_exit;
    }

    test_context.fd_mem = open("/dev/mem", O_RDWR | O_SYNC);
    if(test_context.fd_mem <= 0)
    {
        printf("[err] to open /dev/mem");
        goto __test_exit;
    }

    int ret;
    cam_af_statistic_param_t af_info_param;
    int h_count, v_count;

    // struct timeval test_ts_now;
    // struct timeval test_ts_old;
    float sharp_result;
    float iir_result;
    float fir_result;

    printf("{%d:%s} [info] start get af info test ...\n",__LINE__,__FUNCTION__);
    while(1)
    {
        // gettimeofday(&test_ts_old, NULL);
        ret = ar_cam_get_af_statistic_info(test_context.fd_cam, &af_info_param, test_context.fd_mem);
        if(ret)
        {
            printf("{%d:%s} [err] fail to get af info %d\n",__LINE__,__FUNCTION__, ret);
            goto __test_exit;
        }

        // gettimeofday(&test_ts_now, NULL);

        // printf("\n\n now %ld : old %ld : use %ld usec\n",test_ts_now.tv_usec, test_ts_old.tv_usec, test_ts_now.tv_usec - test_ts_old.tv_usec);

        // printf("frame id 0x%x\n",af_info_param.frame_id);

        sharp_result = 0;
        iir_result = 0;
        fir_result = 0;

        for(v_count = 0 ; v_count<9; v_count++)
        {
            for(h_count = 0 ;h_count<16; h_count++)
            {
                sharp_result += af_info_param.focus_value_sharpness[h_count][v_count];
                fir_result += af_info_param.focus_value_fir[h_count][v_count];
                iir_result += af_info_param.focus_value_iir[h_count][v_count];
#if 0
                printf("[%d][%d] shp 0x%x : fir 0x%x : iir 0x%x : luma 0x%x : high 0x%x\n" \
                    , h_count, v_count\
                    , af_info_param.focus_value_sharpness[h_count][v_count]\
                    , af_info_param.focus_value_fir[h_count][v_count]\
                    , af_info_param.focus_value_iir[h_count][v_count]\
                    , af_info_param.af_luma_info[h_count][v_count]\
                    , af_info_param.af_high_num_info[h_count][v_count]);
#endif
            }
        }

        sharp_result /= 16*9;
        iir_result /= 16*9;
        fir_result /= 16*9;
        printf("sharp_result %f, iir_result %f, fir_result %f\n", sharp_result, iir_result, fir_result);
    }

__test_exit:
    if(test_context.fd_cam>0)
    {
        ar_cam_src_close(test_context.fd_cam);
    }
    if(test_context.fd_mem>0)
    {
        close(test_context.fd_mem);
    }

    printf("{%d:%s} [info] test exit...\n",__LINE__,__FUNCTION__);
    return 0;
}
