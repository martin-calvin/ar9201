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

#include "opencv2/opencv.hpp"

#include "ar_icc.h"
#include "ar_ion.h"
#include "ar_alg_define.h"
#if defined(WIN32) || defined(X64)
#include "ar_dsp_rpc.h"
#endif

#include "ar_alg.h"
#include "ar_dsp_common.h"
#include "ar_dsp_alg.h"

extern int g_app_quit_flag;
extern int g_thread_exit_cnt;

using namespace cv;
using namespace std;

void * pthread_run_network_evaluation(void *arg)
{

	AR_DSP_ALG_st * p_dsp_alg = 0;
	THREAD_PARAM_st * p_t_param = 0;

	int ret = 0;
	int input_len[AR_DSP_ALG_MAX_INPUT_NUM] = {0};
	unsigned char * input_va[AR_DSP_ALG_MAX_INPUT_NUM] = {0};
	unsigned char * input_pa[AR_DSP_ALG_MAX_INPUT_NUM] = {0};
	int output_pdata_len = 0;
	unsigned char * output_pdata_va = 0;
	unsigned char * output_pdata_pa = 0;
	unsigned char * sram_addr_va = 0;
	unsigned char * sram_addr_pa = 0;


	int i = 0;
	unsigned char * ext_mem_addr_va = 0;
	unsigned char * ext_mem_addr_pa = 0;
	int dsp_id = 0;
	//int test_finished[AR_DSP_ALG_MAX_NN_PER_DSP] = {0};

	AR_DSP_CFG_st  * p_dsp_cfg = 0;

	struct dirent ** in_file;

	char file_name[FILE_PATH_STR_LEN];
	char result_file_name[AR_DSP_ALG_MAX_NN_PER_DSP][FILE_PATH_STR_LEN];
	char ini_file_name[FILE_PATH_STR_LEN];
	int file_type = INVALID_IMG_FILE;
	//will load w x h x c to input buffer, if the src img has different size, user should do resize before send it to CDNN
	int img_width, img_height, img_channel;
	int img_size = 0;

	cv::Mat src_img;
	//cv::Mat dst_img;

	p_t_param = (THREAD_PARAM_st *)arg;

	ar_ion_init(AR_DSP_HEAP_ID);

	dsp_id = p_t_param->dsp_id;
	AR_PRINTF_DEBUG("[DSP%d]Start running network evaluation...\r\n", dsp_id);

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
		p_dsp_cfg->cnn_cfg[i].input_buf[0] = (unsigned long)input_pa[0];
		p_dsp_cfg->cnn_cfg[i].input_buf[1] = (unsigned long)input_pa[1];
		p_dsp_cfg->cnn_cfg[i].input_buf[2] = (unsigned long)input_pa[2];
		p_dsp_cfg->cnn_cfg[i].input_buf[3] = (unsigned long)input_pa[3];

		p_dsp_cfg->cnn_cfg[i].buffer_pa_for_pdata = (unsigned long)output_pdata_pa;
		p_dsp_cfg->cnn_cfg[i].buffer_va_for_pdata = (unsigned long)output_pdata_va;
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

    //Users should fill the input 1/2/3 data if CNN init needs this.
    {
        //Set input_va[1]
        //Set input_va[2]
        //Set input_va[3]
    }
	AR_PRINTF_DEBUG("[DSP%d]Configuring DSP...\r\n", dsp_id);
	ret = ar_alg_cfg_dsp(p_t_param->dsp_id, (char *)p_dsp_cfg, sizeof(*p_dsp_cfg));
	if(ret < 0)
	{
		AR_PRINTF_ERR("[DSP%d]Configuration failed!\r\n", dsp_id);
		goto _free_and_exit;
	}
	AR_PRINTF_DEBUG("[DSP%d]Configuration succeed!\r\n", dsp_id);

	//open local image list
	for(i = 0; i < AR_DSP_ALG_MAX_NN_PER_DSP; i++)
	{
		if(p_t_param->ini_cnn_cfg[i].input_source == AR_DSP_ALG_RUN_LOCAL_FILE)
		{
			ret = cut_ini_file_name(p_t_param->inifile, ini_file_name);
			if(ret < 0)
			{
				strcpy(ini_file_name, "unknown");
			}

			snprintf(result_file_name[i], FILE_PATH_STR_LEN, "%s%s_results_dsp%d.txt", p_t_param->ini_cnn_cfg[i].local_img_directory, ini_file_name, dsp_id);
			if(access(result_file_name[i], F_OK) != -1)
			{
				remove(result_file_name[i]);
			}

		}
	}

	AR_PRINTF_DEBUG("[DSP%d]== Start process ==\r\n", dsp_id);

	for(i = 0; i < AR_DSP_ALG_MAX_NN_PER_DSP; i++)
	{
		if(p_dsp_cfg->cnn_cfg[i].network_id <= 0)
		{
			continue;
		}
	    int scandir_num = 0;
	    int scandir_count = 0;

		scandir_num = scandir( p_t_param->ini_cnn_cfg[i].local_img_directory, &in_file, 0, ar_alphasort);

		if(scandir_num < 0)
		{
			AR_PRINTF_ERR("Scan local dir %s error: %s\r\n", p_t_param->ini_cnn_cfg[0].local_img_directory, strerror(errno));
			goto _free_and_exit;
		}

		while(1)
		{
			if(g_app_quit_flag)
				break;

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

			snprintf(file_name, FILE_PATH_STR_LEN, "%s%s", p_t_param->ini_cnn_cfg[i].local_img_directory, in_file[scandir_count]->d_name);
			printf("%s%s \r\n", p_t_param->ini_cnn_cfg[i].local_img_directory, in_file[scandir_count]->d_name);
			free(in_file[scandir_count]);
			scandir_count ++;

			memset(input_va[0], 0, input_len[0]);

			file_type = get_image_file_type(file_name);
			if(file_type == RGB_RAW_DATA_FILE || file_type == BGR_RAW_DATA_FILE)
			{
				ret = ar_load_file(file_name, (char *)input_va[0], input_len[0]);
				if(ret < 0)
				{
					AR_PRINTF_ERR("[DSP%d]Load file error: %s\r\n", dsp_id, file_name);
					continue;
				}

				img_width = p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[0].width;
				img_height = p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[0].height;
				img_channel = p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[0].nChannels;
			}
			else if(file_type == JPG_BMP_PNG_IMG_FILE)
			{
				//read image and resize it, TBD
				src_img = cv::imread(file_name, cv::IMREAD_ANYCOLOR);
				if(src_img.empty())
				{
				   AR_PRINTF_ERR("[DSP%d]Imread file failed!\r\n", dsp_id);
				   continue;
				}

				AR_PRINTF_DEBUG("src cols/row/ch: %d/%d/%d\r\n", src_img.cols, src_img.rows, src_img.channels());

				if(!p_t_param->ini_cnn_cfg[i].cnn_cfg.resize_by_dsp)
				{
					img_width = p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[0].width;
					img_height = p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[0].height;
					img_channel = p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[0].nChannels;

					if(src_img.cols != img_width || src_img.rows != img_height)
					{
						cv::Mat dst_img;
#if 0
						if(src_img.channels() == 1)
						{
							dst_img.create(img_height, img_width, CV_8UC1);
						}
						else if(src_img.channels() == 3)
						{
							dst_img.create(img_height, img_width, CV_8UC3);
						}
						else
						{
							AR_PRINTF_ERR("[DSP%d]Check the input image format!\r\n", dsp_id);
							continue;
						}

						if(dst_img.empty())
						{
							continue;
						}
#endif
						cv::resize(src_img, dst_img, Size(img_width, img_height));

						if(input_len[0] < dst_img.rows * dst_img.cols * dst_img.channels())
						{
							AR_PRINTF_ERR("[DSP%d]Input_len[0] < Dst_img.size.\r\n", dsp_id);
							continue;
						}

						memcpy(input_va[0], dst_img.data, dst_img.rows * dst_img.cols * dst_img.channels());
					}
					else
					{
						//no need to resize
						memcpy(input_va[0], src_img.data, img_width * img_height * img_channel);
					}

				}
				else
				{
					img_width = src_img.cols;
					img_height = src_img.rows;
					img_channel = src_img.channels();

                    if(img_channel != 3)
                    {
                        AR_PRINTF_ERR("[DSP%d]DSP only support BRG 3-channel resize, please do it at ARM side before sending to DSP!\r\n", dsp_id);
                        continue;
                    }

					if(input_len[0] < img_width * img_height * img_channel)
					{
						AR_PRINTF_ERR("[DSP%d]Input_len[0] < Src_img.size.\r\n", dsp_id);
						continue;
					}

					memcpy(input_va[0], src_img.data, img_width * img_height * img_channel);
					if((unsigned int)img_width != p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[0].width
					|| (unsigned int)img_height != p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[0].height)
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

			img_size = img_width * img_height * img_channel;
			p_dsp_alg->input[0].width = img_width;
			p_dsp_alg->input[0].height =  img_height;
			p_dsp_alg->input[0].channel =  img_channel;
			p_dsp_alg->input[0].format = p_t_param->ini_cnn_cfg[i].cnn_cfg.input_format[0];
			p_dsp_alg->input[0].size = img_size;
            p_dsp_alg->input[0].rgbbuff = (char *)input_pa[0];

			p_dsp_alg->dsp_id = p_t_param->dsp_id;
			p_dsp_alg->alg_type = p_dsp_cfg->cnn_cfg[i].network_id;

            //Users must fill in the input 1/2/3 based on their specific CNN
            for(int inputIdx = 1; inputIdx < p_dsp_cfg->cnn_cfg[i].num_inputs; inputIdx++)
            {
                p_dsp_alg->input[inputIdx].width = p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[inputIdx].width;
    			p_dsp_alg->input[inputIdx].height =  p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[inputIdx].height;
    			p_dsp_alg->input[inputIdx].channel =  p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[inputIdx].nChannels;
    			p_dsp_alg->input[inputIdx].format = p_t_param->ini_cnn_cfg[i].cnn_cfg.input_format[inputIdx];
    			p_dsp_alg->input[inputIdx].size =
                    p_dsp_alg->input[inputIdx].width * p_dsp_alg->input[inputIdx].height * p_dsp_alg->input[inputIdx].channel;

    			p_dsp_alg->input[inputIdx].rgbbuff = (char *)input_pa[inputIdx];
            }

			//memset(&p_dsp_alg->cv_ops, 0, sizeof(p_dsp_alg->cv_ops));
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

			if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_STATS)
			{
				ar_dump_statistics(dsp_id, &p_dsp_alg->statistics);
			}

			//save results to local file
			//sprintf(result_file_name[i], "%s%s", file_name, ".res.txt");
			ar_save_output_to_file(result_file_name[i], file_name, (AR_DSP_OUTPUT_st *)&p_dsp_alg->output);
		}
	}

	AR_PRINTF_DEBUG("[DSP%d] Test finished...\r\n", dsp_id);

#ifdef USER_DEFINED_TEST
		//test user defined operation
		p_dsp_alg->alg_type = 0x1234;
		p_dsp_alg->user_data_pa = user_test_pa;
		ret = ar_do_algrithom(p_dsp_alg);
		if(ret < 0)
		{
			AR_PRINTF_ERR("[DSP%d]Error calling ar_do_algrithom: %d\r\n",dsp_id, ret);

			continue;
		}

		AR_PRINTF_DEBUG("[DSP%d]User test done with ret: %d\r\n", dsp_id, ((AR_USR_DATA_TEST_st *)user_test_va)->return_val);
#endif

_free_and_exit:
	if (p_dsp_alg)
	{
		free(p_dsp_alg);
	}

	if (p_dsp_cfg)
	{
		free(p_dsp_cfg);
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

	//pthread_exit((void *)"Terminate");

}

