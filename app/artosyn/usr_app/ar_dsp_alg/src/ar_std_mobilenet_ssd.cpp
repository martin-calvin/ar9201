/*********Standard MobilenetSSD process***********/
#if !defined(WIN32) && !defined(X64)
#include <unistd.h>
#else
#include<io.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <dirent.h>
#if !defined(WIN32) && !defined(X64)
#include <sys/time.h>
#ifdef ENABLE_SWEEPER_OPTION
#include "ar_distance_calc.h"
#endif
#endif

#include "opencv2/opencv.hpp"

//#define YUV_IMG_DUMP
#ifdef YUV_IMG_DUMP
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#endif

#include "ar_icc.h"
#include "ar_ion.h"
#include "ar_alg_define.h"
#if defined(WIN32) || defined(X64)
#include "ar_dsp_rpc.h"
#endif
#include "ar_alg.h"

#include "ar_dsp_common.h"
#include "ar_dsp_alg.h"

#include "comp_osd.h"
#include "ar_get_img_list.h"

extern SYS_CONFIG_st g_sys_cfg;
extern int g_app_quit_flag;
extern int g_thread_exit_cnt;
extern int g_osd_fd;

//for sweeper ssd
extern "C"
{
	pthread_mutex_t g_alg_obstacle_mutex;
	AR_ALG_OBSTACLE_st g_alg_obstacle = { 0 };
}

static const char * std_ssd_labels[] =
{
	"__background__",
	"aeroplane",
	"bicycle",
	"bird",
	"boat",
	"bottle",
	"bus",
	"car",
	"cat",
	"chair",
	"cow",
	"diningtable",
	"dog",
	"horse",
	"motorbike",
	"person",
	"pottedplant",
	"sheep",
	"sofa",
	"train",
	"tvmonitor"
};

static const char * sweeper_ssd_labels[] =
{
	"__background__",
	"slipper",
	"wire",
	"sock",
	"charger",
	"NA",
	"NA",
	"NA",
	"NA",
	"NA",
	"NA",
	"NA",
	"NA",
	"NA",
	"NA",
	"NA",
	"NA",
	"NA",
	"NA",
	"NA",
	"NA"
};

using namespace cv;
using namespace std;

void * pthread_run_std_mobilenet_ssd(void *arg)
{
	AR_DSP_ALG_st * p_dsp_alg = 0;
	THREAD_PARAM_st * p_t_param = 0;

	int ret = 0;
	int input_len = 0;
	unsigned char * input_va = 0;
	unsigned char * input_pa = 0;
	int output_pdata_len = 0;
	unsigned char * ext_mem_addr_va = 0;
	unsigned char * ext_mem_addr_pa = 0;
	unsigned char * sram_addr_va = 0;
	unsigned char * sram_addr_pa = 0;

	unsigned char * output_pdata_va = 0;
	unsigned char * output_pdata_pa = 0;
	int dsp_id = 0;

	AR_DSP_DETECT_RESULTS_st detect_results = {0};
	AR_DSP_CFG_st  * p_dsp_cfg = 0;

	struct dirent **in_file;
	char file_name[FILE_PATH_STR_LEN];
	char result_file_name[FILE_PATH_STR_LEN];
	char ini_file_name[FILE_PATH_STR_LEN];
	int file_type = INVALID_IMG_FILE;
	//will load w x h x c to input buffer, if the src img has different size, user should do resize before send it to CDNN
	int img_width, img_height, img_channel;
	int img_size = 0;

	int scandir_num = 0;
	int scandir_count = 0;
    //unsigned long long localpic_processed = 0;
	unsigned long long frame_processed = 0;
	unsigned long start_time = 0, curr_time = 0;

	struct img_list * entry_ptr = NULL;

	cv::Mat src_img;
	cv::Mat dst_img;
	//cv::Mat resize_img;
	#ifdef YUV_IMG_DUMP
	char  yuv_dump_path[64];
	#endif

#ifdef ENABLE_SWEEPER_OPTION
	extern int start_gdbus_server(void);
	start_gdbus_server();
#endif

	pthread_mutex_init(&g_alg_obstacle_mutex, NULL);

	p_t_param = (THREAD_PARAM_st *)arg;

	ar_ion_init(AR_DSP_HEAP_ID);

	dsp_id = p_t_param->dsp_id;
	AR_PRINTF_DEBUG("[DSP%d]Start running std mobilenetssd...\r\n", dsp_id);

	//Malloc input buffer
	input_len = p_t_param->ini_cnn_cfg[0].cnn_cfg.input_buf_len[0];
	AR_PRINTF_DEBUG("[DSP%d]Malloc input buf len %d\r\n", dsp_id, input_len);
	AR_GET_ION_MEMORY(input_va, input_pa, input_len);
	AR_PRINTF_DEBUG("[DSP%d]Input va %x pa %x\r\n", dsp_id, (unsigned int)input_va, (unsigned int)input_pa);

	//Malloc output pdata buffer for dsp, make sure the buffer is big enough
	output_pdata_len = p_t_param->ini_cnn_cfg[0].cnn_cfg.len_of_buffer_for_pdata;
	AR_PRINTF_DEBUG("[DSP%d]Malloc output pdata buf len %d\r\n", dsp_id, output_pdata_len);
	AR_GET_ION_MEMORY(output_pdata_va, output_pdata_pa, output_pdata_len);
	AR_PRINTF_DEBUG("[DSP%d]Output_pdata va %x pa %x\r\n", dsp_id, (unsigned int)output_pdata_va, (unsigned int)output_pdata_pa);

	//Malloc ext memory for cdnn lib
	AR_PRINTF_DEBUG("[DSP%d]Malloc ext mem len %d\r\n", dsp_id, p_t_param->cdnn_ext_mem_size);
	AR_GET_ION_MEMORY(ext_mem_addr_va, ext_mem_addr_pa, p_t_param->cdnn_ext_mem_size);
	AR_PRINTF_DEBUG("[DSP%d]Ext va %x pa %x\r\n", dsp_id, (unsigned int)ext_mem_addr_va, (unsigned int)ext_mem_addr_pa);

	//check if sram is configured
	if(!p_t_param->cdnn_sram_heap_start && p_t_param->cdnn_sram_heap_size)
	{
		AR_GET_ION_MEMORY(sram_addr_va, sram_addr_pa, p_t_param->cdnn_sram_heap_size);
		p_t_param->cdnn_sram_heap_start = (unsigned long)sram_addr_pa;
	}

	AR_PRINTF_DEBUG("[DSP%d]Sram pa %lx size 0x%lx\r\n", dsp_id, p_t_param->cdnn_sram_heap_start, p_t_param->cdnn_sram_heap_size);

#ifdef USER_DEFINED_TEST
	unsigned char * user_test_va = 0;
	unsigned char * user_test_pa = 0;

	//Malloc user defined data, only for test
	AR_GET_ION_MEMORY(user_test_va, user_test_pa, sizeof(AR_USR_DATA_TEST_st));
	((AR_USR_DATA_TEST_st *)user_test_va)->input_param = 0x1234;
	((AR_USR_DATA_TEST_st *)user_test_va)->return_val = 0;
#endif

	//if I need load weight file ?
	ar_ion_cache_flush(ext_mem_addr_va);
	if(g_sys_cfg.who_load_weight_data == p_t_param->dsp_id || g_sys_cfg.who_load_weight_data == -1)
	{
		ret = ar_prepare_weight_file(p_t_param->dsp_id, p_t_param->ini_cnn_cfg);
		if(ret < 0)
		{
			AR_PRINTF_ERR("[DSP%d]Prepare weight file error!\r\n", dsp_id);
			goto _free_and_exit;
		}
	}
	else
	{
		ret = ar_copy_weight_load_addr(g_sys_cfg.who_load_weight_data, p_t_param->ini_cnn_cfg);
		if(ret < 0)
		{
			AR_PRINTF_ERR("[DSP%d]Prepare weight file error, ret = %d!\r\n", dsp_id, ret);
			goto _free_and_exit;
		}
	}

	p_dsp_cfg = (AR_DSP_CFG_st *)malloc(sizeof(*p_dsp_cfg));
	if (!p_dsp_cfg)
	{
		AR_PRINTF_ERR("Malloc dsp cfg failed.\r\n");
		goto _free_and_exit;
	}
	memset(p_dsp_cfg, 0, sizeof(*p_dsp_cfg));

	//set the parameters and send to dsp, only one network (std ssd) in this simple demo
	if(p_t_param->ini_cnn_cfg[0].cnn_cfg.network_id)
	{
		memcpy(&p_dsp_cfg->cnn_cfg[0], &p_t_param->ini_cnn_cfg[0].cnn_cfg, sizeof(AR_DSP_CNN_CFG_st));
		p_dsp_cfg->cnn_cfg[0].input_buf[0] = (unsigned long)input_pa;
		p_dsp_cfg->cnn_cfg[0].buffer_pa_for_pdata = (unsigned long)output_pdata_pa;
		p_dsp_cfg->cnn_cfg[0].buffer_va_for_pdata = (unsigned long)output_pdata_va;

		p_dsp_cfg->cdnn_sram_heap_start = p_t_param->cdnn_sram_heap_start;
		p_dsp_cfg->cdnn_sram_heap_size = p_t_param->cdnn_sram_heap_size;
		p_dsp_cfg->cdnn_ext_mem_addr = (unsigned long)ext_mem_addr_pa;
		p_dsp_cfg->cdnn_ext_mem_size = p_t_param->cdnn_ext_mem_size;
		p_dsp_cfg->dsp_log_level = g_sys_cfg.loglevel;
	}
	else
	{
		AR_PRINTF_ERR("[DSP%d]No invalid network ? \r\n", dsp_id);
		goto _free_and_exit;
	}

#ifdef USER_DEFINED_TEST
	//only for user cfg test
	p_dsp_cfg->user_cfg[0].operation_id = 0x1234;
	p_dsp_cfg->user_cfg[0].params = user_test_pa;
#endif

	AR_PRINTF_DEBUG("[DSP%d]Configuring DSP...\r\n", dsp_id);
	ret = ar_alg_cfg_dsp(p_t_param->dsp_id, (char *)p_dsp_cfg, sizeof(*p_dsp_cfg));
	if(ret < 0)
	{
		AR_PRINTF_ERR("[DSP%d]Configuration failed!\r\n", dsp_id);
		goto _free_and_exit;
	}
	AR_PRINTF_DEBUG("[DSP%d]Configuration succeed!\r\n", dsp_id);

	//Construct an algrithom struct
	p_dsp_alg = (AR_DSP_ALG_st *)malloc(sizeof(*p_dsp_alg));
	if (!p_dsp_alg)
	{
		AR_PRINTF_ERR("Malloc dsp alg failed.\r\n");
		goto _free_and_exit;
	}
	memset(p_dsp_alg, 0, sizeof(*p_dsp_alg));

	p_dsp_alg->dsp_id = p_t_param->dsp_id;
	p_dsp_alg->alg_type = p_dsp_cfg->cnn_cfg[0].network_id;

	p_dsp_alg->input[0].size = p_dsp_cfg->cnn_cfg[0].input_buf_len[0];
	p_dsp_alg->input[0].rgbbuff = (char *)input_pa;

	//if test local file, get the file list first
	if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_LOCAL_FILE)
	{

		scandir_num = scandir( p_t_param->ini_cnn_cfg[0].local_img_directory, &in_file, 0, ar_alphasort);
		if(scandir_num < 0)
		{
			AR_PRINTF_ERR("Scan local dir %s error: %s\r\n", p_t_param->ini_cnn_cfg[0].local_img_directory, strerror(errno));
			goto _free_and_exit;
		}

		ret = cut_ini_file_name(p_t_param->inifile, ini_file_name);
		if(ret < 0)
		{
			strcpy(ini_file_name, "unknown");
		}

		snprintf(result_file_name, FILE_PATH_STR_LEN, "%s%s_results_dsp%d.txt", p_t_param->ini_cnn_cfg[0].local_img_directory, ini_file_name, dsp_id);
		if(access(result_file_name, F_OK) != -1)
		{
			remove(result_file_name);
		}

	}

	AR_PRINTF_DEBUG("[DSP%d]== Start process ==\r\n", dsp_id);
	MEASURE_TIME(start_time);

	while(1)
	{
		if(g_app_quit_flag)
			break;

		//measure time
		unsigned long start1 = 0, start2 = 0, start3 = 0, start4 = 0;

		MEASURE_TIME(start1);

		memset(&detect_results, 0, sizeof(detect_results));
		memset(input_va, 0, input_len);
		ar_ion_cache_flush(input_va);

		if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_LOCAL_FILE)
		{
			//get local file
			if(scandir_count == scandir_num)
			{
				break;
			}

			//currently, we don't support recursive DIR
			if(in_file[scandir_count]->d_type != DT_REG)
			{
				free(in_file[scandir_count]);
				scandir_count ++;
				continue;
			}

			snprintf(file_name, FILE_PATH_STR_LEN, "%s%s", p_t_param->ini_cnn_cfg[0].local_img_directory, in_file[scandir_count]->d_name);
			//printf("%s%s \r\n", p_t_param->ini_cnn_cfg[0].local_img_directory, in_file[scandir_count]->d_name);
            free(in_file[scandir_count]);
			scandir_count ++;

			file_type = get_image_file_type(file_name);
			if(file_type == RGB_RAW_DATA_FILE || file_type == BGR_RAW_DATA_FILE)
			{
				ret = ar_load_file(file_name, (char *)input_va, input_len);
				if(ret < 0)
				{
					AR_PRINTF_ERR("Load file error: %s\r\n", file_name);
					continue;
				}
			}
			else if(file_type == JPG_BMP_PNG_IMG_FILE)
			{
				//call cv
				//read image and resize it, TBD
				dst_img = cv::imread(file_name, cv::IMREAD_ANYCOLOR);
				if(dst_img.empty())
				{
				   AR_PRINTF_ERR("[DSP%d]Imread file failed!\r\n", dsp_id);
				   continue;
				}

				if(!p_t_param->ini_cnn_cfg[0].cnn_cfg.resize_by_dsp)
				{
					img_width = p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].width;
					img_height = p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].height;
					img_channel = p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].nChannels;

					if(dst_img.cols != img_width || dst_img.rows != img_height)
					{
						cv::Mat resize_img;
						if(dst_img.channels() == 1)
						{
							resize_img.create(img_height, img_width, CV_8UC1);
						}
						else if(dst_img.channels() == 3)
						{
							resize_img.create(img_height, img_width, CV_8UC3);
						}
						else
						{
							AR_PRINTF_ERR("[DSP%d]Check the input image format!\r\n", dsp_id);
							continue;
						}

						cv::resize(dst_img, resize_img, Size(img_width, img_height));

						if(input_len < resize_img.rows * resize_img.cols * resize_img.channels())
						{
							AR_PRINTF_ERR("[DSP%d]Input_len < Resize_img.size.\r\n", dsp_id);
							continue;
						}

						memcpy(input_va, resize_img.data, resize_img.rows * resize_img.cols * resize_img.channels());
						ar_ion_cache_flush(input_va);

					}
					else
					{
						//no need to resize
						memcpy(input_va, dst_img.data, img_width * img_height * img_channel);
						ar_ion_cache_flush(input_va);
					}
				}
				else
				{
					img_width = dst_img.cols;
					img_height = dst_img.rows;
					img_channel = dst_img.elemSize();

					if(input_len < img_width * img_height * img_channel)
					{
						AR_PRINTF_ERR("[DSP%d]Input_len < Dst_img.size.\r\n", dsp_id);
						continue;
					}

					memcpy(input_va, dst_img.data, img_width * img_height * img_channel);
					ar_ion_cache_flush(input_va);

					//Use outside resize before sending data to input layer
					if((unsigned int)img_width != p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].width
						|| (unsigned int)img_height != p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].height)
					{
						p_dsp_alg->cv_ops.cv_ops_bmp |= AR_CV_CROP_BITMAP;

						//crop the whole image and resize it to network size
						p_dsp_alg->cv_ops.roi.x = 0;
						p_dsp_alg->cv_ops.roi.y = 0;
						p_dsp_alg->cv_ops.roi.width = img_width;
						p_dsp_alg->cv_ops.roi.height = img_height;
					}
				}
			}
			else
			{
				continue;
			}
		}
		else //sensor mode, DSP will convert YUV to RGB if format = AR_DSP_IMG_FMT_YUV
		{
			entry_ptr = ar_get_img_from_list();
			if(!entry_ptr)
			{
				 continue;
			}

			memcpy(input_va,(unsigned char*)entry_ptr->rsz_img.data,
				entry_ptr->rsz_img.cols*entry_ptr->rsz_img.rows*entry_ptr->rsz_img.channels());
			ar_ion_cache_flush(input_va);

			img_width = entry_ptr->rsz_img.cols;
			img_height = entry_ptr->rsz_img.rows;
			img_channel = entry_ptr->rsz_img.channels();

			frame_processed++;

			#ifdef YUV_IMG_DUMP
			sprintf(yuv_dump_path,"/mnt/yuv_%d.bmp",frame_processed);
			imwrite(yuv_dump_path,entry_ptr->rsz_img);
			#endif

		}

		MEASURE_TIME(start2);
		//memset(&p_dsp_alg->cv_ops, 0, sizeof(p_dsp_alg->cv_ops));
		memset(&p_dsp_alg->output, 0, sizeof(p_dsp_alg->output));

		img_size = img_width * img_height * img_channel;
		p_dsp_alg->alg_type = p_t_param->ini_cnn_cfg[0].cnn_cfg.network_id;
		p_dsp_alg->input[0].width = img_width;
		p_dsp_alg->input[0].height =  img_height;
		p_dsp_alg->input[0].channel =  img_channel;
		p_dsp_alg->input[0].format = p_t_param->ini_cnn_cfg[0].cnn_cfg.input_format[0];
		p_dsp_alg->input[0].size = img_size;

		ret = ar_do_algrithom(p_dsp_alg);
		if(ret < 0)
		{
			AR_PRINTF_ERR("[DSP%d]Error calling ar_do_algrithom: %d, quit!\r\n", dsp_id, ret);
			goto _free_and_exit;
		}
		if(p_dsp_alg->exit_code < 0)
		{
			AR_PRINTF_ERR("[DSP%d]DSP returns %d, continue...\r\n!\r\n", dsp_id, p_dsp_alg->exit_code);
			if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_SENSOR_IMG)
			{
				ar_release_img_to_list(entry_ptr);
				entry_ptr = NULL;
			}
			continue;
		}

		MEASURE_TIME(start3);
		ar_ion_cache_invalid(output_pdata_va);

		if(strcmp(p_t_param->demo_name, "std_ssd_test") == 0)
		{
			//For 3.6.x CDNN
			if(p_dsp_alg->output.buffer_num == 3)
			{
				ar_mobilenetssd_post_process_v6((AR_DSP_OUTPUT_st *)&p_dsp_alg->output, &detect_results,
					p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].width, p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].height,
					p_t_param->ini_cnn_cfg[0].cnn_cfg.output_threshold, std_ssd_labels);
			}
			else
			{    //For 3.5.x CDNN
				ar_mobilenetssd_post_process((AR_DSP_OUTPUT_st *)&p_dsp_alg->output, &detect_results,
					p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].width, p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].height,
					p_t_param->ini_cnn_cfg[0].cnn_cfg.output_threshold, std_ssd_labels);
			}
		}
		else
		{
			//For 3.6.x CDNN
			if(p_dsp_alg->output.buffer_num == 3)
			{
				ar_mobilenetssd_post_process_v6((AR_DSP_OUTPUT_st *)&p_dsp_alg->output, &detect_results,
					p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].width, p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].height,
					p_t_param->ini_cnn_cfg[0].cnn_cfg.output_threshold, sweeper_ssd_labels);
			}
			else
			{
				ar_mobilenetssd_post_process((AR_DSP_OUTPUT_st *)&p_dsp_alg->output, &detect_results,
					p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].width, p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].height,
					p_t_param->ini_cnn_cfg[0].cnn_cfg.output_threshold, sweeper_ssd_labels);
			}
			#ifdef ENABLE_SWEEPER_OPTION
				//calculate distance and save, for other process to get
				if(1)
				{
					AR_Obstacle_Info_st obstacle = {0};
					AR_Calc_Results_st  calc_results = {0};
					obstacle.img_width = img_width;
					obstacle.img_height = img_height;

					//get the nearest objective
					int y = 0, y_max = 0;
					for(int i = 0; i < detect_results.object_num; i++)
					{
						y = detect_results.objects[i].rect.y + detect_results.objects[i].rect.height;
						if(y > y_max)
						{
							y_max = y;
							obstacle.u = detect_results.objects[i].rect.x;
							obstacle.v = detect_results.objects[i].rect.y;
							obstacle.w = detect_results.objects[i].rect.width;
							obstacle.h = detect_results.objects[i].rect.height;

							obstacle.index = detect_results.objects[i].label_index;
							obstacle.score = detect_results.objects[i].score;
							strncpy(obstacle.name, detect_results.objects[i].label, 32);
						}
					}

					AR_PRINTF_DEBUG("detect_results.object_num: %d \r\n", detect_results.object_num);
					AR_PRINTF_DEBUG("obstacle.u: %d \r\n", obstacle.u);
					AR_PRINTF_DEBUG("obstacle.v: %d \r\n", obstacle.v);
					AR_PRINTF_DEBUG("obstacle.w: %d \r\n", obstacle.w);
					AR_PRINTF_DEBUG("obstacle.h: %d \r\n", obstacle.h);
					AR_PRINTF_DEBUG("obstacle.index: %d \r\n", obstacle.index);
					AR_PRINTF_DEBUG("obstacle.score: %f \r\n", obstacle.score);

					ar_distance_calc(p_t_param->camera_param_file, &obstacle, &calc_results);

					pthread_mutex_lock(&g_alg_obstacle_mutex);
					g_alg_obstacle.index = calc_results.index;
					g_alg_obstacle.score = calc_results.score;
					g_alg_obstacle.distance = calc_results.distance;
					g_alg_obstacle.left_angle = calc_results.left_angle;
					g_alg_obstacle.right_angle = calc_results.right_angle;
					pthread_mutex_unlock(&g_alg_obstacle_mutex);

					AR_PRINTF_DEBUG("Find an obstacle: \r\n");
					AR_PRINTF_DEBUG("Distance: %f m\r\n", calc_results.distance);
					AR_PRINTF_DEBUG("Angle(L/R): %f %f\r\n", calc_results.left_angle, calc_results.right_angle);
					AR_PRINTF_DEBUG("Name: %s\r\n", calc_results.name);

				}

			#endif
		}

		if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_RESULTS)
		{
			ar_dump_ssd_output(p_t_param->dsp_id, &detect_results);
		}

		if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_STATS)
		{
			ar_dump_statistics(p_t_param->dsp_id, &p_dsp_alg->statistics);
		}

		if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_LOCAL_FILE)
		{
			//ar_save_output_to_file(result_file_name, file_name, (AR_DSP_OUTPUT_st *)&p_dsp_alg->output);
			ar_save_detect_output_to_file(result_file_name, file_name, (AR_DSP_DETECT_RESULTS_st *)&detect_results);
		}
		else
		{
			ar_release_img_to_list(entry_ptr);
			entry_ptr = NULL;
			if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_OSD)
			{
		    	ar_draw_ssd_output(g_osd_fd, &detect_results,
					p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].width, p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].height);
			}
		}

#ifdef USER_DEFINED_TEST
		//test user defined operation
		p_dsp_alg->alg_type = 0x1234;
		p_dsp_alg->user_data_pa = user_test_pa;
		ret = ar_do_algrithom(p_dsp_alg);
		if(ret < 0)
		{
			AR_PRINTF_ERR("[DSP%d]Error calling ar_do_algrithom: %d\r\n",ret);

			continue;
		}

		AR_PRINTF_DEBUG("[DSP%d]User test done with ret: %d\r\n", dsp_id, ((AR_USR_DATA_TEST_st *)user_test_va)->return_val);
#endif

		MEASURE_TIME(curr_time);

		MEASURE_TIME(start4);
		AR_PRINTF_DEBUG("[DSP%d]APP stats: total: %ld, Pre: %ld, Process: %ld, Post: %ld\r\n", dsp_id,
			start4 - start1, start2 - start1, start3 - start2, start4 - start3);

		AR_PRINTF_DEBUG("[DSP%d]Time elapsed: %ld ms, processed frame: %lld\r\n", dsp_id, curr_time - start_time, frame_processed);

	}

	AR_PRINTF_DEBUG("[DSP%d] Test finished...\r\n", dsp_id);

_free_and_exit:
	if (p_dsp_alg)
	{
		free(p_dsp_alg);
	}

	if (p_dsp_cfg)
	{
		free(p_dsp_cfg);
	}

	if(entry_ptr)
	{
		ar_release_img_to_list(entry_ptr);
	}

	if(input_va)
	{
		AR_RELEASE_ION_MEMORY(input_va);
	}

	if(ext_mem_addr_va)
	{
		AR_RELEASE_ION_MEMORY(ext_mem_addr_va);
	}

	if(sram_addr_va)
	{
		AR_RELEASE_ION_MEMORY(sram_addr_va);
	}

	//ar_alg_free_weight_file(dsp_id);

	if(strcmp(p_t_param->demo_name, "sweeper_ssd") == 0)
	{
	#ifdef ENABLE_SWEEPER_OPTION
		extern int stop_gdbus_server();
		stop_gdbus_server();
	#endif
	}

	g_thread_exit_cnt++;

	return NULL;

}

