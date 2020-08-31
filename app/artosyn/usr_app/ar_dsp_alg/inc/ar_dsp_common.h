#ifndef __AR_DSP_COMMON_H__
#define __AR_DSP_COMMON_H__
#ifdef __cplusplus
extern "C"{
#endif
#include "ar_alg_define.h"
#include "ar_dsp_alg.h"
#include "comp_osd.h"
extern pthread_mutex_t g_alg_obstacle_mutex;
extern AR_ALG_OBSTACLE_st g_alg_obstacle;
extern int ar_alphasort(const struct dirent **a, const struct dirent **b);
extern int ar_parse_ini(char * inifile, THREAD_PARAM_st * p_t_param, SYS_CONFIG_st * p_sys_cfg);
extern int ar_prepare_weight_file(int dsp_id, INI_CNN_CFG_st * ini_cfg);
extern int ar_copy_weight_load_addr(int from_dsp_id, INI_CNN_CFG_st * ini_cfg);
extern int ar_load_file(char * path, char * buf, int size);
extern int ar_mobilenetssd_post_process(AR_DSP_OUTPUT_st * output_buffer, AR_DSP_DETECT_RESULTS_st * p_detect_results,
	int img_width, int img_height, float output_threshold, const char * ssd_labels[]);
extern int ar_mobilenetssd_post_process_v6(AR_DSP_OUTPUT_st * output_buffer, AR_DSP_DETECT_RESULTS_st * p_detect_results,
	int img_width, int img_height, float output_threshold, const char * ssd_labels[]);

extern int ar_fill_osd_layer(int comp_fd, AR_DSP_DETECT_OBJ_st * p_obj, AR_POINT_st * p_point, int point_num,
	int my_width, int my_height, layer_user_t * p_osd_layer);
extern int ar_update_osd(int comp_fd, layer_user_t * p_osd_layer);
extern int ar_draw_ssd_output(int comp_fd, AR_DSP_DETECT_RESULTS_st * p_result, int my_width, int my_height);
extern void ar_dump_ssd_output(int dsp_id, AR_DSP_DETECT_RESULTS_st * p_result);
extern void ar_dump_statistics(int dsp_id, AR_DSP_STATS_st * p_stats);
extern int ar_save_output_to_file(char * path, char * img_file, AR_DSP_OUTPUT_st * p_output);
extern int ar_save_detect_output_to_file(char * path, char * img_file, AR_DSP_DETECT_RESULTS_st * p_output);
extern int ar_get_max_input_len(THREAD_PARAM_st * p_t_param, int input_id);
extern int ar_get_max_pdata_len(THREAD_PARAM_st * p_t_param);
extern int ar_alg_onet_post_process(AR_DSP_OUTPUT_st * dsp_output);
extern void ar_dump_onet_output(int dsp_id, AR_DSP_OUTPUT_st * dsp_output);
extern int get_image_file_type(char * filename);
extern void dump_dsp_config(THREAD_PARAM_st * p_t_param);
extern int cut_ini_file_name(char * whole_path, char * filename);
extern int ar_get_detect_results(AR_ALG_OBSTACLE_st * p_obstacle);

#ifdef __cplusplus
}
#endif

#endif
