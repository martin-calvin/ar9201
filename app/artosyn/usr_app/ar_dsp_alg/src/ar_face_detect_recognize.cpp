/****************************************************************
* Multiple CNN examples, this shows you how you can concate several networks.
* MobilenetSSD
* Onet
* Mobilenet114
****************************************************************/
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
#endif

#include "opencv2/opencv.hpp"

#include "ar_icc.h"
#include "ar_ion.h"
#include "ar_alg_define.h"
#if defined(WIN32) || defined(X64)
#include "ar_dsp_rpc.h"
#endif

#include "ar_alg.h"
#include "comp_osd.h"
#include "ar_dsp_common.h"
#include "ar_dsp_alg.h"

#include "ar_get_img_list.h"


extern int g_app_quit_flag;
extern int g_thread_exit_cnt;
extern int g_osd_fd;

const char * face_ssd_labels[] =
	{
		"__background__",
		"face",
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
		"NA",
		"NA",
		"NA",
		"NA"
	};

using namespace cv;
using namespace std;

void * pthread_run_face_detect_test(void *arg)
{
	AR_DSP_ALG_st * p_dsp_alg = 0;
	THREAD_PARAM_st * p_t_param = 0;

	AR_DSP_DETECT_RESULTS_st detect_results = {0};
	AR_DSP_OUTPUT_st * p_onet_output = 0;
	AR_POINT_st points[5] = {0};
	layer_user_t osd_layer = {0};

	int ret = 0;
	int input_len[AR_DSP_ALG_MAX_INPUT_NUM] = {0};
	unsigned char * input_va[AR_DSP_ALG_MAX_INPUT_NUM] = {0};
	unsigned char * input_pa[AR_DSP_ALG_MAX_INPUT_NUM] = {0};
	int output_pdata_len = 0;
	unsigned char * output_pdata_va = 0;
	unsigned char * output_pdata_pa = 0;
	unsigned char * sram_addr_va = 0;
	unsigned char * sram_addr_pa = 0;

	int detect_num = 0;
	//const int onet_input_size = ONET_IMAGE_WIDTH * ONET_IMAGE_HEIGHT * 3;
	int i = 0, j = 0, output_layer = 0;
	float onet_prob = 0.0;
	int dsp_id = 0;

	int scandir_num = 0;
	int scandir_count = 0;

	unsigned char * ext_mem_addr_va = 0;
	unsigned char * ext_mem_addr_pa = 0;

	AR_DSP_CFG_st  * p_dsp_cfg = 0;

	struct dirent **in_file;

	char file_name[FILE_PATH_STR_LEN];
	char result_file_name[FILE_PATH_STR_LEN];
	char ini_file_name[FILE_PATH_STR_LEN];
	int sensor_width = 0, sensor_height = 0;
	int file_type = INVALID_IMG_FILE;
	//will load w x h x c to input buffer, if the src img has different size, user should do resize before send it to CDNN
	int img_width, img_height, img_channel;
	int img_size = 0;

	unsigned long start_time = 0, curr_time = 0;
	unsigned long long frame_processed = 0;

	struct img_list * entry_ptr = NULL;

	cv::Mat src_img;
	cv::Mat dst_img;

	p_t_param = (THREAD_PARAM_st *)arg;

	ar_ion_init(AR_DSP_HEAP_ID);

	dsp_id = p_t_param->dsp_id;
	AR_PRINTF_DEBUG("[DSP%d]Start running face_detect test...\r\n", dsp_id);
	p_dsp_cfg = (AR_DSP_CFG_st *)malloc(sizeof(*p_dsp_cfg));
	if (!p_dsp_cfg)
	{
		AR_PRINTF_ERR("Malloc dsp cfg failed.\r\n");
		goto _free_and_exit;
	}
	memset(p_dsp_cfg, 0, sizeof(*p_dsp_cfg));

	p_dsp_alg = (AR_DSP_ALG_st *)malloc(sizeof(*p_dsp_alg));
	if (!p_dsp_alg)
	{
		AR_PRINTF_ERR("Malloc dsp alg failed.\r\n");
		goto _free_and_exit;
	}
	memset(p_dsp_alg, 0, sizeof(*p_dsp_alg));

	//Malloc input buffer, shared by all networks
	for(i = 0; i < AR_DSP_ALG_MAX_INPUT_NUM; i++)
	{
		input_len[i] = ar_get_max_input_len(p_t_param, i);
		if(input_len[i] <= 0)
		{
			continue;
		}

		AR_PRINTF_DEBUG("[DSP%d]Malloc input buf len %d\r\n", dsp_id, input_len[i]);
		AR_GET_ION_MEMORY(input_va[i], input_pa[i], input_len[i]);
		AR_PRINTF_DEBUG("[DSP%d]Input va %x pa %x\r\n", dsp_id, (unsigned int)input_va[i], (unsigned int)input_pa[i]);
	}

	//Malloc output pdata buffer for dsp, make sure the buffer is big enough
	//it can be shared by all networks
	output_pdata_len = ar_get_max_pdata_len(p_t_param);
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

	//set the parameters and send to dsp
	for(i = 0; i < AR_DSP_ALG_MAX_NN_PER_DSP; i++)
	{
		memcpy(&p_dsp_cfg->cnn_cfg[i], &p_t_param->ini_cnn_cfg[i].cnn_cfg, sizeof(AR_DSP_CNN_CFG_st));
		if(p_dsp_cfg->cnn_cfg[i].network_id)
		{
			AR_PRINTF_DEBUG("[DSP%d]DSP Cfg %d : network id: %d\r\n",dsp_id, i, p_dsp_cfg->cnn_cfg[i].network_id);
			p_dsp_cfg->cnn_cfg[i].input_buf[0] = (unsigned long)input_pa[0];
			p_dsp_cfg->cnn_cfg[i].input_buf[1] = (unsigned long)input_pa[1];
			p_dsp_cfg->cnn_cfg[i].input_buf[2] = (unsigned long)input_pa[2];
			p_dsp_cfg->cnn_cfg[i].input_buf[3] = (unsigned long)input_pa[3];

			p_dsp_cfg->cnn_cfg[i].buffer_pa_for_pdata = (unsigned long)output_pdata_pa;
			p_dsp_cfg->cnn_cfg[i].buffer_va_for_pdata = (unsigned long)output_pdata_va;
		}
	}
	p_dsp_cfg->cdnn_sram_heap_start = p_t_param->cdnn_sram_heap_start;
	p_dsp_cfg->cdnn_sram_heap_size = p_t_param->cdnn_sram_heap_size;
	p_dsp_cfg->cdnn_ext_mem_addr = (unsigned long)ext_mem_addr_pa;
	p_dsp_cfg->cdnn_ext_mem_size = p_t_param->cdnn_ext_mem_size;
	p_dsp_cfg->dsp_log_level = g_sys_cfg.loglevel;

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
	p_dsp_alg->dsp_id = p_t_param->dsp_id;
	p_dsp_alg->alg_type = p_dsp_cfg->cnn_cfg[0].network_id;

	p_dsp_alg->input[0].size = p_dsp_cfg->cnn_cfg[0].input_buf_len[0];
	p_dsp_alg->input[0].rgbbuff = (char *)input_pa[0];

	//open local image list, in this demo, we get an image and pass the results to next network
	//this is different from multi networks
	if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_LOCAL_FILE)
	{
		scandir_num = scandir( p_t_param->ini_cnn_cfg[0].local_img_directory, &in_file, 0, ar_alphasort);
	}

	for(i = 0; i < AR_DSP_ALG_MAX_NN_PER_DSP; i++)
	{
		if(p_t_param->ini_cnn_cfg[i].input_source == AR_DSP_ALG_RUN_LOCAL_FILE)
		{
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
	}

	AR_PRINTF_DEBUG("[DSP%d]== Start process ==\r\n", dsp_id);

	MEASURE_TIME(start_time);

	//run network_0 (ssd), then network_1 (onet) in this demo
	while(1)
	{
		if(g_app_quit_flag)
			break;

		//measure time
		unsigned long start1 = 0, start2 = 0, start3 = 0, start4 = 0;

		MEASURE_TIME(start1);

		memset(input_va[0], 0, input_len[0]);

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
				//read file to dst_img directly, make sure the img size is the same as network input.
				dst_img.create(p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].height,
				p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].width, CV_8UC3);

				ret = ar_load_file(file_name, (char *)input_va[0], input_len[0]);
				if(ret < 0)
				{
					AR_PRINTF_ERR("[DSP%d]Load file error: %s\r\n",dsp_id, file_name);
					continue;
				}

				if(ret > dst_img.cols * dst_img.rows * dst_img.channels())
				{
					AR_PRINTF_ERR("[DSP%d]Dst_img.size < Load file size.\r\n", dsp_id);
					continue;
				}

				img_width = p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].width;
				img_height = p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].height;
				img_channel = p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].nChannels;

				memcpy(dst_img.data, input_va[0],
				p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].height * p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].width * 3);
			}
			else if(file_type == JPG_BMP_PNG_IMG_FILE)
			{
				//call cv
				//read image and resize it, TBD
				dst_img = cv::imread(file_name);
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
						cv::Mat resize_img(img_height, img_width, CV_8UC3);
						cv::resize(dst_img, resize_img, Size(img_width, img_height));

						if(input_len[0] < resize_img.rows * resize_img.cols * resize_img.channels())
						{
							AR_PRINTF_ERR("[DSP%d]Input_len[0] < Resize_img.size.\r\n", dsp_id);
							continue;
						}
						memcpy(input_va[0], resize_img.data, resize_img.rows * resize_img.cols * resize_img.channels());
					}
					else
					{
						//no need to resize
						memcpy(input_va[0], dst_img.data, img_width * img_height * img_channel);
					}
				}
				else
				{
					img_width = dst_img.cols;
					img_height = dst_img.rows;
					img_channel = dst_img.channels();

					if(input_len[0] < img_width * img_height * img_channel)
					{
						AR_PRINTF_ERR("[DSP%d]Input_len[0] < Dst_img.size.\r\n", dsp_id);
						continue;
					}

					memcpy(input_va[0], dst_img.data, img_width * img_height * img_channel);

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
		else
		{
			entry_ptr = ar_get_img_from_list();
			if(!entry_ptr)
			{
				 continue;
			}

			if(dst_img.empty())
			{
				dst_img.create(entry_ptr->img.rows, entry_ptr->img.cols, CV_8UC3);
			}

			dst_img.data  = entry_ptr->img.data;
			dst_img.cols  = entry_ptr->img.cols;
			dst_img.rows  = entry_ptr->img.rows;

			sensor_width = entry_ptr->img.cols;
			sensor_height = entry_ptr->img.rows;

			memcpy(input_va[0],(unsigned char*)entry_ptr->rsz_img.data,
				entry_ptr->rsz_img.cols*entry_ptr->rsz_img.rows*entry_ptr->rsz_img.channels());

			img_width = entry_ptr->rsz_img.cols;
			img_height = entry_ptr->rsz_img.rows;
			img_channel = entry_ptr->rsz_img.channels();

			frame_processed++;
		}

		MEASURE_TIME(start2);

		//Clear OSD first
		memset(&osd_layer, 0, sizeof(osd_layer));

		//1. Detect faces in mobilenetSSD
		memset(&detect_results, 0, sizeof(detect_results));

		p_dsp_alg->alg_type = p_t_param->ini_cnn_cfg[0].cnn_cfg.network_id;
		//memset(&p_dsp_alg->cv_ops, 0, sizeof(p_dsp_alg->cv_ops));
		memset(&p_dsp_alg->output, 0, sizeof(p_dsp_alg->output));

		img_size = img_width * img_height * img_channel;
		p_dsp_alg->input[0].width = img_width;
		p_dsp_alg->input[0].height =  img_height;
		p_dsp_alg->input[0].channel =  img_channel;
		p_dsp_alg->input[0].format = p_t_param->ini_cnn_cfg[0].cnn_cfg.input_format[0];
		p_dsp_alg->input[0].size = img_size;

		//printf("==Start call dsp with input: %x output: %x\r\n", input_pa, output_pa);

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

		if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_LOCAL_FILE)
		{
			//save results to local file
			ar_save_output_to_file(result_file_name, file_name, (AR_DSP_OUTPUT_st *)&p_dsp_alg->output);

			//for local picture, src_img has RGB data, use it to calc x,y
			//For 3.6.x cdnn
			if(p_dsp_alg->output.buffer_num == 3)
			{
				ar_mobilenetssd_post_process_v6((AR_DSP_OUTPUT_st *)&p_dsp_alg->output, &detect_results,
					dst_img.cols, dst_img.rows,
					p_t_param->ini_cnn_cfg[0].cnn_cfg.output_threshold, face_ssd_labels);
			}
			else
			{    //for 3.5.x cdnn
				ar_mobilenetssd_post_process((AR_DSP_OUTPUT_st *)&p_dsp_alg->output, &detect_results,
					dst_img.cols, dst_img.rows,
					p_t_param->ini_cnn_cfg[0].cnn_cfg.output_threshold, face_ssd_labels);
			}
		}
		else
		{
			//for sensor input, use it to calc x,y
			//For 3.6.x cdnn
			if(p_dsp_alg->output.buffer_num == 3)
			{
				ar_mobilenetssd_post_process_v6((AR_DSP_OUTPUT_st *)&p_dsp_alg->output, &detect_results,
					sensor_width, sensor_height,
					p_t_param->ini_cnn_cfg[0].cnn_cfg.output_threshold, face_ssd_labels);
			}
			else
			{
				ar_mobilenetssd_post_process((AR_DSP_OUTPUT_st *)&p_dsp_alg->output, &detect_results,
					sensor_width, sensor_height,
					p_t_param->ini_cnn_cfg[0].cnn_cfg.output_threshold, face_ssd_labels);
			}
		}

		if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_RESULTS)
		{
			ar_dump_ssd_output(p_t_param->dsp_id, &detect_results);
		}

		if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_STATS)
		{
			ar_dump_statistics(p_t_param->dsp_id, &p_dsp_alg->statistics);
		}

		MEASURE_TIME(start3);

		//2. Run Onet to detect landmarks
		//DSP has done YUV to RGB, and put them into rgbbuff(input_va)
		//save input img in case next network need it to crop/resize or ...
		detect_num = detect_results.object_num;

		for(i = 0; i < detect_num; i++)
		{
			if(detect_results.objects[i].label_index != 1)
			{
				continue;
			}

			p_dsp_alg->alg_type = p_t_param->ini_cnn_cfg[1].cnn_cfg.network_id;
			p_dsp_alg->input[0].format = AR_DSP_IMG_FMT_RGB;

			int roi_x1,roi_y1,roi_w,roi_h;
			roi_x1 = detect_results.objects[i].rect.x;
			roi_y1 = detect_results.objects[i].rect.y;
			roi_w = detect_results.objects[i].rect.width;
			roi_h = detect_results.objects[i].rect.height;

			if(p_t_param->ini_cnn_cfg[1].cnn_cfg.resize_by_dsp)
			{
				img_width = dst_img.cols;
				img_height = dst_img.rows;
				img_channel = dst_img.channels();

				p_dsp_alg->cv_ops.cv_ops_bmp = AR_CV_CROP_BITMAP;
				memcpy(&p_dsp_alg->cv_ops.roi, &detect_results.objects[i].rect, sizeof(AR_RECT_st));
				onet_prob = 0.0;

				//restore input img for dsp to crop
				memcpy(input_va[0], dst_img.data, dst_img.rows * dst_img.cols * dst_img.channels());
			}
			else
			{
				//ARM do crop and resize
				img_width = p_t_param->ini_cnn_cfg[1].cnn_cfg.input_params[0].width;
				img_height = p_t_param->ini_cnn_cfg[1].cnn_cfg.input_params[0].height;
				img_channel = p_t_param->ini_cnn_cfg[1].cnn_cfg.input_params[0].nChannels;

				if(roi_x1 < 0 || roi_y1 < 0 || roi_w <= 0 || roi_h <= 0)
				{
					continue;
				}

				if((roi_x1 + roi_w) > dst_img.cols || (roi_y1 + roi_h) > dst_img.rows)
				{
					roi_w = dst_img.cols - roi_x1;
					roi_h = dst_img.rows - roi_y1;
				}

				cv::Rect roi(roi_x1, roi_y1, roi_w, roi_h);
				cv::Mat crop_img(roi_h, roi_w, CV_8UC3);

				//dst_img has the rgb data
				crop_img = dst_img(roi);
				if(crop_img.empty())
				{
					continue;
				}

				cv::Mat resize_img(img_height, img_width, CV_8UC3);
				cv::resize(crop_img, resize_img, Size(img_width, img_height));

				memcpy(input_va[0], resize_img.data, resize_img.rows * resize_img.cols * resize_img.channels());

			}

			img_size = img_width * img_height * img_channel;
			p_dsp_alg->input[0].width = img_width;
			p_dsp_alg->input[0].height =  img_height;
			p_dsp_alg->input[0].channel =  img_channel;
			p_dsp_alg->input[0].format = p_t_param->ini_cnn_cfg[1].cnn_cfg.input_format[0];
			p_dsp_alg->input[0].size = img_size;

			memset(&p_dsp_alg->output, 0, sizeof(p_dsp_alg->output));

			ret = ar_do_algrithom(p_dsp_alg);
			if(ret < 0)
			{
				AR_PRINTF_ERR("[DSP%d]Error calling ar_do_algrithom: %d, quit!\r\n", dsp_id, ret);
				goto _free_and_exit;
			}
			if(p_dsp_alg->exit_code < 0)
			{
				AR_PRINTF_ERR("[DSP%d]DSP returns %d, continue...\r\n!\r\n", dsp_id, p_dsp_alg->exit_code);
				continue;
			}

			ar_alg_onet_post_process((AR_DSP_OUTPUT_st *)&p_dsp_alg->output);
			//calc point coordinate
			memset(points, 0, sizeof(points));

			p_onet_output = (AR_DSP_OUTPUT_st *)&p_dsp_alg->output;
			for(output_layer = 0; output_layer < p_onet_output->buffer_num; output_layer++)
			{
				if(strcmp(p_onet_output->output_buffer[output_layer].buffer_name, "conv6-3") == 0)
				{
					for(j = 0; j < 5; j++)
					{
						points[j].x =
						p_onet_output->output_buffer[output_layer].pdata[j] * roi_w + roi_x1;
						points[j].y =
						p_onet_output->output_buffer[output_layer].pdata[j + 5] * roi_h + roi_y1;

						//printf("x:%d y:%d \r\n",points[j].x,points[j].y);

					}
				}
				if(strcmp(p_onet_output->output_buffer[output_layer].buffer_name, "prob1") == 0)
				{
					onet_prob = p_onet_output->output_buffer[output_layer].pdata[1];
				}
			}
			//depends on the first network input is sensor or local images
			if(p_t_param->ini_cnn_cfg[1].input_source == AR_DSP_ALG_RUN_LOCAL_FILE)
			{
				//save results to local file
				//sprintf(result_file_name, "%s%s", file_name, ".onet.res.txt");
				ar_save_output_to_file(result_file_name, file_name, (AR_DSP_OUTPUT_st *)&p_dsp_alg->output);
			}
			else
			{
				//printf("%s %d: prob %f thresh %f\r\n", __FUNCTION__, __LINE__, onet_prob ,p_t_param->ini_cnn_cfg[1].cnn_cfg.output_threshold);
				if(onet_prob < p_t_param->ini_cnn_cfg[1].cnn_cfg.output_threshold)
				{
					continue;
				}

				if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_OSD)
				{
					//The w, h is the SSD init size to calculate the points, so we use cfg[0].input_parmas.
					ar_fill_osd_layer(g_osd_fd, &detect_results.objects[i], points, 5,
						sensor_width, sensor_height, &osd_layer);
				}
			}

			if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_RESULTS)
			{
				ar_dump_onet_output(p_t_param->dsp_id, p_onet_output);
			}
			if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_STATS)
			{
				ar_dump_statistics(p_t_param->dsp_id, &p_dsp_alg->statistics);
			}

		}

		if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_SENSOR_IMG)
		{
			ar_release_img_to_list(entry_ptr);
			entry_ptr = NULL;
		}

		if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_OSD)
		{
			ar_update_osd(g_osd_fd, &osd_layer);
		}

		MEASURE_TIME(curr_time);

		MEASURE_TIME(start4);

		AR_PRINTF_DEBUG("[DSP%d]APP stats: total: %ld, get_img: %ld, ssd: %ld, onet: %ld\r\n", dsp_id,
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

	for(i = 0; i < AR_DSP_ALG_MAX_INPUT_NUM; i++)
	{
		if(input_va[i])
		{
			AR_RELEASE_ION_MEMORY(input_va[i]);
		}
	}

	if(output_pdata_va)
	{
		AR_RELEASE_ION_MEMORY((output_pdata_va));
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

	g_thread_exit_cnt++;

	return NULL;
}

