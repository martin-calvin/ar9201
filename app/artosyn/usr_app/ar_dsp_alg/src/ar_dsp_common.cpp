//Artosyn DSP middleware APIs.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

//#include <sys/time.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <math.h>

#include "minIni.h"

#include "ar_icc.h"
#include "ar_ion.h"
//#include "ar_alg.h"
#include "ar_dsp_alg.h"
#include "comp_osd.h"
#include "alphanum.h"
#include "ar_dsp_common.h"


#ifdef __cplusplus
extern "C"{
#endif

struct weight_file_status
{
	char name[FILE_PATH_STR_LEN];
	unsigned long pa;
	unsigned long va;
	int len;
	int ready;
};

static struct weight_file_status g_weight_file[MAX_DSP_ID][AR_DSP_ALG_MAX_NN_PER_DSP] = {0};
static pthread_mutex_t g_weight_lock = PTHREAD_MUTEX_INITIALIZER;

#define IN_RANGE(x, min, max) ((min) <= (x) && (x) <= (max))

int ar_alphasort(const struct dirent **a, const struct dirent **b)
{
	return (doj::alphanum_comp((char*)(*a)->d_name, (char*)(*b)->d_name)> 0);
}


static int _ar_get_file_len(char * path)
{
	FILE * pFile = 0;
	int file_len;

	pFile = fopen(path, "rb");
	if (!pFile)
	{
		AR_PRINTF_ERR("Open file %s error: %s\r\n", path, strerror(errno));
		return -1;
	}

	fseek(pFile, 0, SEEK_END);
	file_len = ftell(pFile);
	rewind(pFile);
	fclose(pFile);

	return file_len;

}

int ar_load_file(char * path, char * buf, int size)
{
	FILE * pFile = 0;
	int file_len;
	int ret = 0;

	pFile = fopen(path, "rb");
	if (!pFile)
	{
		AR_PRINTF_ERR("Open file %s error: %s\r\n", path, strerror(errno));
		return -1;
	}

	file_len = size;
	if (size == 0)
	{
		fseek(pFile, 0, SEEK_END);
		file_len = ftell(pFile);
		rewind(pFile);
	}

	ret = fread(buf, 1, file_len, pFile);
	if (ret < 0)
	{
		AR_PRINTF_ERR("Read file %s size %d error: %s\r\n", path, file_len, strerror(errno));
		fclose(pFile);
		return ret;
	}

	fclose(pFile);

	return ret;
}


int ar_parse_ini(char * inifile, THREAD_PARAM_st * p_t_param, SYS_CONFIG_st * p_sys_cfg)
{
	char section[32] = {0};
	char input_section[32] = {0};
	char str_value[FILE_PATH_STR_LEN*16] = {0};
	char * substr = 0;
	INI_CNN_CFG_st ini_cnn_cfg[AR_DSP_ALG_MAX_NN_PER_DSP * MAX_DSP_ID] = {0};
	char * pDelimiter = ", ";

	int nid = 0, did = 0; //network id, dsp id
	int ret = 0;
	int i = 0;

	if(!inifile || !p_t_param || !p_sys_cfg)
	{
		AR_PRINTF_ERR("Null input parameters!\r\n");
		return -1;
	}

	//1. parse global system cfg
	p_sys_cfg->loglevel = ini_getl("system", "loglevel", 0, inifile);

	p_sys_cfg->who_load_weight_data = ini_getl("system", "who_load_weight_data", 0, inifile);

	if(p_sys_cfg->who_load_weight_data != DSP_ID_0 && p_sys_cfg->who_load_weight_data != DSP_ID_1
		&& p_sys_cfg->who_load_weight_data != DSP_ID_2 && p_sys_cfg->who_load_weight_data != DSP_ID_3
		&& p_sys_cfg->who_load_weight_data != -1)
	{
		AR_PRINTF_ERR("Who will load the weight data ? [0,1,2,3,-1]\r\n");
		return -1;
	}

	memset(str_value, 0, sizeof(str_value));
	ret = ini_gets("system", "dump_results", "dummy", str_value, sizeof(str_value), inifile);
	if(ret == 2 && strcmp(str_value, "ON") == 0)
	{
		p_sys_cfg->dump_ctrl |= AR_DSP_DUMP_RESULTS;
	}

	memset(str_value, 0, sizeof(str_value));
	ret = ini_gets("system", "dump_statistics", "dummy", str_value, sizeof(str_value), inifile);
	if(ret == 2 && strcmp(str_value, "ON") == 0)
	{
		p_sys_cfg->dump_ctrl |= AR_DSP_DUMP_STATS;
	}

	memset(str_value, 0, sizeof(str_value));
	ret = ini_gets("system", "draw_osd", "dummy", str_value, sizeof(str_value), inifile);
	if(ret == 2 && strcmp(str_value, "ON") == 0)
	{
		p_sys_cfg->dump_ctrl |= AR_DSP_DUMP_OSD;
	}

	//2. parse network cfg
	for(nid = 0; nid < AR_DSP_ALG_MAX_NN_PER_DSP * MAX_DSP_ID; nid++)
	{
		sprintf(section, "%s%d", "network_", nid);

		ini_cnn_cfg[nid].cnn_cfg.network_id = ini_getl(section, "network_id", 0, inifile);
		//if no section or network not configured
		if(!ini_cnn_cfg[nid].cnn_cfg.network_id)
		{
			continue;
		}

		strcpy(ini_cnn_cfg[nid].section, section);
		ini_cnn_cfg[nid].cnn_cfg.network_type = ini_getl(section, "network_type", 0, inifile);
		ini_cnn_cfg[nid].cnn_cfg.do_debug_logging = ini_getl(section, "do_debug_logging", 0, inifile);
		ini_cnn_cfg[nid].cnn_cfg.do_profiling = ini_getl(section, "do_profiling", 0, inifile);
		ini_cnn_cfg[nid].cnn_cfg.channel_swap = ini_getl(section, "channel_swap", 0, inifile);
		ini_cnn_cfg[nid].cnn_cfg.raw_scale = ini_getl(section, "raw_scale", 0, inifile);
		ini_cnn_cfg[nid].cnn_cfg.resize_input = ini_getl(section, "resize_input", 0, inifile);
		ini_cnn_cfg[nid].cnn_cfg.bw_reduction = ini_getl(section, "bw_reduction", 0, inifile);
		ini_cnn_cfg[nid].cnn_cfg.bw_reduction_ratio = ini_getl(section, "bw_reduction_ratio", 0, inifile);
		ini_cnn_cfg[nid].cnn_cfg.resize_by_dsp = ini_getl(section, "resize_by_dsp", 0, inifile);
		//Params for MTCNN
		ini_cnn_cfg[nid].cnn_cfg.amend_flag = ini_getl(section, "amend_flag", 0, inifile);
		ini_cnn_cfg[nid].cnn_cfg.block_size = ini_getl(section, "block_size", 0, inifile);
		ini_cnn_cfg[nid].cnn_cfg.block_number = ini_getl(section, "block_number", 0, inifile);
		ini_cnn_cfg[nid].cnn_cfg.block_interval = ini_getl(section, "block_interval", 0, inifile);

		//Params for FCN
		ini_cnn_cfg[nid].cnn_cfg.num_of_inference = ini_getl(section, "num_of_inference", 0, inifile);
		ini_cnn_cfg[nid].cnn_cfg.max_width = ini_getl(section, "max_width", 0, inifile);
		ini_cnn_cfg[nid].cnn_cfg.max_height = ini_getl(section, "max_height", 0, inifile);

		//parse softmax threshold
		int thr_num = 0;
		char str_float[FILE_PATH_STR_LEN] = {0};
		char * sub_float = 0;

		memset(str_value, 0, sizeof(str_value));
		ini_gets(section, "softmax_threshold_names", "dummy", str_value, sizeof(str_value), inifile);
		substr = strtok(str_value, pDelimiter);
		while(substr)
		{
			if(thr_num >= AR_DSP_ALG_MAX_SOFTMAX_THRD_NUM)
			{
				AR_PRINTF_ERR("Assign too many softmax threshold %d to dsp %d\r\n", thr_num, did);
				return -1;
			}

			strncpy(ini_cnn_cfg[nid].cnn_cfg.softmax_thrd[thr_num].name, substr, 128);
			ini_cnn_cfg[nid].cnn_cfg.softmax_thrd[thr_num].name[127] = 0;
			thr_num++;

			substr = strtok(NULL, pDelimiter);
		}

		thr_num = 0;
		ini_gets(section, "softmax_threshold_values", "dummy", str_float, sizeof(str_float), inifile);
		sub_float = strtok(str_float, pDelimiter);
		while(sub_float)
		{
			if(thr_num >= AR_DSP_ALG_MAX_SOFTMAX_THRD_NUM)
			{
				return -1;
			}

			if(strlen(ini_cnn_cfg[nid].cnn_cfg.softmax_thrd[thr_num].name) > 0)
			{
				ini_cnn_cfg[nid].cnn_cfg.softmax_thrd[thr_num].threshold = atof(sub_float);
				AR_PRINTF_DEBUG("softmax value: %f\r\n", ini_cnn_cfg[nid].cnn_cfg.softmax_thrd[thr_num].threshold);
				thr_num++;
			}

			sub_float = strtok(NULL, pDelimiter);
		}

		ini_cnn_cfg[nid].cnn_cfg.num_inputs = ini_getl(section, "num_inputs", 0, inifile);

		for(i = 0; i < ini_cnn_cfg[nid].cnn_cfg.num_inputs; i++)
		{
			sprintf(input_section, "%s_input_%d", section, i);

			ini_cnn_cfg[nid].cnn_cfg.input_buf_len[i] = ini_getl(input_section, "input_buffer_len", 0, inifile);
			ini_cnn_cfg[nid].cnn_cfg.input_format[i] = ini_getl(input_section, "input_format", 0, inifile);

			//get layer name
			memset(str_value, 0, sizeof(str_value));
			ret = ini_gets(input_section, "layerName", "dummy", str_value, sizeof(str_value), inifile);
			if(ret > 0)
			{
				strcpy(ini_cnn_cfg[nid].cnn_cfg.input_params[i].pLayerName, str_value);
			}

			ini_cnn_cfg[nid].cnn_cfg.input_params[i].bufferId = ini_getl(input_section, "bufferId", 0, inifile);
			ini_cnn_cfg[nid].cnn_cfg.input_params[i].width = ini_getl(input_section, "width", 0, inifile);
			ini_cnn_cfg[nid].cnn_cfg.input_params[i].height = ini_getl(input_section, "height", 0, inifile);
			ini_cnn_cfg[nid].cnn_cfg.input_params[i].nChannels = ini_getl(input_section, "nChannels", 0, inifile);
			ini_cnn_cfg[nid].cnn_cfg.input_params[i].dataType = ini_getl(input_section, "dataType", 0, inifile);
			ini_cnn_cfg[nid].cnn_cfg.input_params[i].depth = ini_getl(input_section, "depth", 0, inifile);
			ini_cnn_cfg[nid].cnn_cfg.input_params[i].dataOrder = ini_getl(input_section, "dataOrder", 0, inifile);
			ini_cnn_cfg[nid].cnn_cfg.input_params[i].nInputs = ini_getl(input_section, "nInputs", 0, inifile);
			ini_cnn_cfg[nid].cnn_cfg.input_params[i].scaleFactor = ini_getf(input_section, "scaleFactor", 0, inifile);
			ini_cnn_cfg[nid].cnn_cfg.input_params[i].dataFlipped = ini_getl(input_section, "dataFlipped", 0, inifile);
			ini_cnn_cfg[nid].cnn_cfg.input_params[i].dataTransposed = ini_getl(input_section, "dataTransposed", 0, inifile);
		}

		ini_cnn_cfg[nid].cnn_cfg.output_threshold = ini_getf(section, "output_threshold", 0, inifile);
		ini_cnn_cfg[nid].cnn_cfg.len_of_buffer_for_pdata = ini_getl(section, "len_of_buffer_for_pdata", 0, inifile);

		//weight data
		memset(str_value, 0, sizeof(str_value));
#if defined(WIN32) || defined(X64)
		ret = ini_gets(section, "weight_file_path_win32", "dummy", str_value, sizeof(str_value), inifile);
#else
		ret = ini_gets(section, "weight_file_path", "dummy", str_value, sizeof(str_value), inifile);
#endif
		if(ret > 0)
		{
			strncpy(ini_cnn_cfg[nid].cnn_cfg.weight_file_path, str_value, FILE_PATH_STR_LEN);
		}

		memset(str_value, 0, sizeof(str_value));
		ret = ini_gets(section, "input_source", "dummy", str_value, sizeof(str_value), inifile);
		if(ret > 0 && strcmp(str_value, "sensor") == 0)
		{
			ini_cnn_cfg[nid].input_source = AR_DSP_ALG_RUN_SENSOR_IMG;
		}
		else
		{
			ini_cnn_cfg[nid].input_source = AR_DSP_ALG_RUN_LOCAL_FILE;
		}

		//if local mode, get the file list
		if(ini_cnn_cfg[nid].input_source == AR_DSP_ALG_RUN_LOCAL_FILE)
		{
			memset(str_value, 0, sizeof(str_value));
		#if defined(WIN32) || defined(X64)
			ret = ini_gets(section, "local_img_directory_win32", "dummy", str_value, sizeof(str_value), inifile);
		#else
			ret = ini_gets(section, "local_img_directory", "dummy", str_value, sizeof(str_value), inifile);
		#endif
			if(ret > 0)
			{
				strncpy(ini_cnn_cfg[nid].local_img_directory, str_value, FILE_PATH_STR_LEN);
			}
		}
	}

	//3. parse DSP cfg
	for(did = 0; did < MAX_DSP_ID; did++)
	{
		sprintf(section, "%s%d", "DSP", did);

		//if dsp is enabled
		memset(str_value, 0, sizeof(str_value));
		ret = ini_gets(section, "DSP_enable", "dummy", str_value, sizeof(str_value), inifile);
		if(ret > 0 && strcmp(str_value, "ON") == 0)
		{
			p_t_param[did].dsp_run = 1;
		}
		else
		{
			p_t_param[did].dsp_run = 0;
		}

		if(p_t_param[did].dsp_run == 0)
		{
			continue;
		}

		memset(str_value, 0, sizeof(str_value));
		ret = ini_gets(section, "demo_name", "dummy", str_value, sizeof(str_value), inifile);
		if(ret > 0)
		{
			strncpy(p_t_param[did].demo_name, str_value, 32);
		}

		p_t_param[did].cdnn_sram_heap_start = ini_getl(section, "cdnn_sram_heap_start", 0, inifile);
		p_t_param[did].cdnn_sram_heap_size = ini_getl(section, "cdnn_sram_heap_size", 0, inifile);
		p_t_param[did].cdnn_ext_mem_size = ini_getl(section, "cdnn_ext_mem_size", 0, inifile);

#ifdef ENABLE_SWEEPER_OPTION
		ret = ini_gets(section, "camera_param_file", "dummy", str_value, sizeof(str_value), inifile);
		if(ret > 0)
		{
			strncpy(p_t_param[did].camera_param_file, str_value, FILE_PATH_STR_LEN);
		}
#endif

		//To see which networks are cfged to this DSP
		memset(str_value, 0, sizeof(str_value));
		ret = ini_gets(section, "network", "dummy", str_value, sizeof(str_value), inifile);
		if(ret <= 0)
		{
			AR_PRINTF_ERR("No network is configured to DSP%d, please check your ini file.\r\n", did);
			return -1;
		}

		//copy network cfgs to this DSP
		int nid_per_dsp = 0;
		substr = strtok(str_value, pDelimiter);

		while(substr)
		{
			for(i = 0; i < sizeof(ini_cnn_cfg)/sizeof(ini_cnn_cfg[0]); i++)
			{
				if(strcmp(substr, ini_cnn_cfg[i].section) == 0)
				{
					if(nid_per_dsp >= AR_DSP_ALG_MAX_NN_PER_DSP)
					{
						AR_PRINTF_ERR("Assign too many networks %d to dsp %d\r\n", nid_per_dsp, did);
						return -1;
					}

					memcpy(&p_t_param[did].ini_cnn_cfg[nid_per_dsp], &ini_cnn_cfg[i], sizeof(INI_CNN_CFG_st));
					nid_per_dsp++;
				}
			}

			substr = strtok(NULL, pDelimiter);
		}

		if(nid_per_dsp == 0)
		{
			AR_PRINTF_ERR("Not match network for DSP %d\r\n", did);
			return -1;
		}

	}

	return 0;
}

//load file and save VA to a global array
int ar_prepare_weight_file(int dsp_id, INI_CNN_CFG_st * ini_cfg)
{
	int ret = 0;
	int i = 0, j = 0;
	unsigned char * va = 0;
	unsigned char * pa = 0;

	for(i = 0; i < AR_DSP_ALG_MAX_NN_PER_DSP; i++)
	{
		if(ini_cfg[i].cnn_cfg.network_id)
		{
			ret = _ar_get_file_len(ini_cfg[i].cnn_cfg.weight_file_path);
			if(ret < 0)
			{
				AR_PRINTF_ERR("[DSP%d]Invalid file len, return;\r\n", dsp_id);
				goto _free_and_exit;
			}

			ini_cfg[i].cnn_cfg.file_len = ret;

			//Load weight files
			AR_GET_ION_MEMORY(va, pa, ini_cfg[i].cnn_cfg.file_len);

			AR_PRINTF_DEBUG("[DSP%d]Load file %s to %x\r\n", dsp_id, ini_cfg[i].cnn_cfg.weight_file_path, (unsigned int)va);

			ret = ar_load_file(ini_cfg[i].cnn_cfg.weight_file_path, (char *)va, ini_cfg[i].cnn_cfg.file_len);
			if(ret < 0)
			{
				AR_PRINTF_ERR("[DSP%d]Load weight file %s failed.\r\n", dsp_id, ini_cfg[i].cnn_cfg.weight_file_path);
				ar_ion_free(va);
				goto _free_and_exit;
			}

			ini_cfg[i].cnn_cfg.load_addr = (unsigned long)pa;

			//save status
			pthread_mutex_lock(&g_weight_lock);
			g_weight_file[dsp_id][i].pa = (unsigned long)pa;
			g_weight_file[dsp_id][i].va = (unsigned long)va;
			strcpy(g_weight_file[dsp_id][i].name, ini_cfg[i].cnn_cfg.weight_file_path);
			g_weight_file[dsp_id][i].len = ini_cfg[i].cnn_cfg.file_len;
			g_weight_file[dsp_id][i].ready = 1;
			pthread_mutex_unlock(&g_weight_lock);
		}
	}

	return 0;

_free_and_exit:
	pthread_mutex_lock(&g_weight_lock);
	for(i = 0; i < AR_DSP_ALG_MAX_NN_PER_DSP; i++)
	{
		if(g_weight_file[dsp_id][i].va)
		{
			ar_ion_free((unsigned char *)g_weight_file[dsp_id][j].va);
			ini_cfg[i].cnn_cfg.load_addr = 0;
		}

		g_weight_file[dsp_id][i].ready = -1;
	}
	pthread_mutex_unlock(&g_weight_lock);
	return -1;
}

int ar_copy_weight_load_addr(int from_dsp_id, INI_CNN_CFG_st * ini_cfg)
{
	int i = 0;

	//maybe other DSP is loading the file and not finished yet, so keep waiting
	while(i < AR_DSP_ALG_MAX_NN_PER_DSP)
	{
		if(ini_cfg[i].cnn_cfg.network_id)
		{
			pthread_mutex_lock(&g_weight_lock);
			//load weight failed, so don't wait
			if(g_weight_file[from_dsp_id][i].ready < 0)
			{
				pthread_mutex_unlock(&g_weight_lock);
				return -1;
			}
			else if(g_weight_file[from_dsp_id][i].ready == 0)
			{
			    pthread_mutex_unlock(&g_weight_lock);
			    //not ready, keep waiting
				continue;
			}
			else
			{
				//ready, copy this one and continue to next one
				if(strcmp(ini_cfg[i].cnn_cfg.weight_file_path, g_weight_file[from_dsp_id][i].name) == 0)
				{
					ini_cfg[i].cnn_cfg.file_len = g_weight_file[from_dsp_id][i].len;
					ini_cfg[i].cnn_cfg.load_addr = g_weight_file[from_dsp_id][i].pa;

					//search next one if it exists
					i++;
					pthread_mutex_unlock(&g_weight_lock);
					continue;
				}

				pthread_mutex_unlock(&g_weight_lock);
				//Different weight file, return error
				return -2;
			}

		}

		i++;
	}

	return 0;

}

int ar_save_output_to_file(char * path, char * img_file, AR_DSP_OUTPUT_st * p_output)
{
	FILE * pFile = 0;
	int i = 0, j = 0;
	int buffer_size = 0;

	pFile = fopen(path, "a+");
	if (!pFile)
	{
		AR_PRINTF_ERR("Open file %s error: %s\r\n", path, strerror(errno));
		return -1;
	}

	fprintf(pFile, "%s:\r\n", img_file);

	for(i = 0; i < p_output->buffer_num; i++)
	{
		buffer_size = p_output->output_buffer[i].buffer_size;
		for(j = 0; j < buffer_size; j++)
		{
			fprintf(pFile, "%f ", p_output->output_buffer[i].pdata[j]);
		}

		fprintf(pFile, "\r\n");
	}

	fclose(pFile);

	return 0;
}



int ar_save_detect_output_to_file(char * path, char * img_file, AR_DSP_DETECT_RESULTS_st * p_output)
{
	FILE * pFile = 0;
	int i = 0;

	pFile = fopen(path, "a+");
	if (!pFile)
	{
		AR_PRINTF_ERR("Open file %s error: %s\r\n", path, strerror(errno));
		return -1;
	}

	fprintf(pFile, "%s:\r\n", img_file);

	for(i = 0; i < p_output->object_num; i++)
	{

		fprintf(pFile, "%d,%f,%d,%d,%d,%d", p_output->objects[i].label_index, \
			 p_output->objects[i].score, \
			 p_output->objects[i].rect.x, p_output->objects[i].rect.y, \
			 p_output->objects[i].rect.x + p_output->objects[i].rect.width,  p_output->objects[i].rect.y + p_output->objects[i].rect.height);

		fprintf(pFile, "\r\n");
	}

	fclose(pFile);

	return 0;
}


int get_image_file_type(char * filename)
{
	char * p_ext = NULL;
	char * p_tmp = NULL;
	int ret = 0;

	if(!filename)
	{
		ret = INVALID_IMG_FILE;
		return ret;
	}

	//ignore "." ".." and any non-image files
	if(strcmp(filename, ".") == 0 || strcmp(filename, "..") == 0)
	{
		ret = INVALID_IMG_FILE;
		return ret;
	}

	p_ext = strrchr(filename, '.');
	if(!p_ext || p_ext == filename)
	{
		ret = INVALID_IMG_FILE;
		return ret;
	}

	//convert to lowercase
	p_tmp = p_ext;
	for(; *p_tmp; ++p_tmp) *p_tmp = tolower(*p_tmp);

	if(strcmp(p_ext, ".rgb") == 0)
	{
		ret = RGB_RAW_DATA_FILE;
	}
	else if(strcmp(p_ext, ".bgr") == 0)
	{
		ret = BGR_RAW_DATA_FILE;
	}
	else if(strcmp(p_ext, ".jpg") == 0 || strcmp(p_ext, ".bmp") == 0 || strcmp(p_ext, ".png") == 0)
	{
		ret = JPG_BMP_PNG_IMG_FILE;
	}
	else
	{
		AR_PRINTF_ERR("Skip %s\r\n", filename);
		ret = INVALID_IMG_FILE;
	}

	return ret;

}

int cut_ini_file_name(char * whole_path, char * filename)
{
	char * substr = 0;
	char * pDelimiter = "/\\"; //'/' or '\'
	char path[FILE_PATH_STR_LEN] = {0};

	if(!filename || !whole_path)
	{
		return -1;
	}

	strncpy(path, whole_path, FILE_PATH_STR_LEN);

	substr = strtok(path, pDelimiter);

	while(substr)
	{
		if(strcmp(substr + strlen(substr) - 4, ".ini") == 0)
		{
			strncpy(filename, substr, strlen(substr) - 4);
			filename[strlen(substr) - 4] = 0;
			return 0;
		}

		substr = strtok(NULL, pDelimiter);
	}

	return -1;
}

int ar_fill_osd_layer(int comp_fd, AR_DSP_DETECT_OBJ_st * p_obj, AR_POINT_st * p_point, int point_num,
	int my_width, int my_height, layer_user_t * p_osd_layer)
{
#if !defined(WIN32) && !defined(X64)
	int i = 0, ret = 0;
	int cur_frame = 0;
	int cur_label = 0;
	ar_cv_point p1, p2 ;
	char scores[32] = {0};
	comp_res_t disp_res = {0};
	float x_scaler = 0.0, y_scaler = 0.0;

	ret = comp_get_res(comp_fd, &disp_res);
	if(ret < 0)
	{
		AR_PRINTF_ERR("Get comp resolution fail %d\r\n", ret);
		return -1;
	}

	x_scaler = ((float)disp_res.width)/((float)my_width);
	y_scaler = ((float)disp_res.height)/((float)my_height);

	if(p_obj)
	{
		cur_frame = p_osd_layer->frame_num;
		cur_label = p_osd_layer->label_num;

		if(cur_frame >= COMP_MAX_NUM || cur_label >= COMP_MAX_NUM)
		{
			AR_PRINTF_ERR("OSD overflow, frame: %d, lable: %d.\r\n", cur_frame, cur_label);
			return -1;
		}

	    p1.x = (int)(x_scaler * p_obj->rect.x);
	    p1.y = (int)(y_scaler * p_obj->rect.y);

	    p2.x = p1.x +(int)(x_scaler * p_obj->rect.width);
	    p2.y = p1.y +(int)(y_scaler * p_obj->rect.height);

	    p_osd_layer->frames[cur_frame].color = RED;
	    p_osd_layer->frames[cur_frame].frameLineWidth = 3;

		p1.x = p1.x > 0 ? p1.x : 0;
		p1.y = p1.y > 0 ? p1.y : 0;
		p2.x = p2.x > 0 ? p2.x : 0;
		p2.y = p2.y > 0 ? p2.y : 0;

		int x_end = disp_res.width - 1 - p_osd_layer->frames[cur_frame].frameLineWidth;
		int y_end = disp_res.height - 1 - p_osd_layer->frames[cur_frame].frameLineWidth;

		p1.x = p1.x > x_end ? x_end : p1.x;
		p1.y = p1.y > y_end ? y_end : p1.y;
		p2.x = p2.x > x_end ? x_end : p2.x;
		p2.y = p2.y > y_end ? y_end : p2.y;

	    p_osd_layer->frames[cur_frame].start = p1;
	    p_osd_layer->frames[cur_frame].end = p2;
		p1.x += p_osd_layer->frames[cur_frame].frameLineWidth + 5;
		p1.y += 5;

		p1.x = p1.x > (disp_res.width-1) ? (disp_res.width-1) : p1.x;
		p1.y = p1.y > (disp_res.height-1) ? (disp_res.height-1) : p1.y;

		p_osd_layer->labels[cur_label].position = p1;

		//limit the string to 32Bytes according to osd
	    sprintf(scores, "%s: %f", p_obj->label, p_obj->score);
		scores[31] = 0;
		strcpy((char*)(p_osd_layer->labels[cur_label].label),scores);

		p_osd_layer->labels[cur_label].color = YELLOW;

		p_osd_layer->frame_num++;
		p_osd_layer->label_num++;
	}

	if(p_point)
	{

		//draw a point
		for(i = 0; i < point_num; i++)
		{
		    cur_frame = p_osd_layer->frame_num;

			if(cur_frame >= COMP_MAX_NUM)
			{
				AR_PRINTF_ERR("OSD overflow, frame: %d, lable: %d.\r\n", cur_frame, cur_label);
				return -1;
			}

			p1.x = (int)(x_scaler * p_point[i].x);
		    p1.y = (int)(y_scaler * p_point[i].y);

		    p2.x = p1.x + 3;
		    p2.y = p1.y + 3;

			p1.x = p1.x > 0 ? p1.x : 0;
			p1.y = p1.y > 0 ? p1.y : 0;
			p2.x = p2.x > 0 ? p2.x : 0;
			p2.y = p2.y > 0 ? p2.y : 0;

			p1.x = p1.x > (disp_res.width-1) ? (disp_res.width-1) : p1.x;
			p1.y = p1.y > (disp_res.height-1) ? (disp_res.height-1) : p1.y;
			p2.x = p2.x > (disp_res.width-1) ? (disp_res.width-1) : p2.x;
			p2.y = p2.y > (disp_res.height-1) ? (disp_res.height-1) : p2.y;

			//AR_PRINTF_DEBUG("x1:%d, y1:%d, x2:%d, y2:%d \r\n",p1.x,p1.y, p2.x, p2.y);

		    p_osd_layer->frames[cur_frame].start = p1;
		    p_osd_layer->frames[cur_frame].end = p2;
		    p_osd_layer->frames[cur_frame].color = BLUE;
		    p_osd_layer->frames[cur_frame].frameLineWidth = 3;

		    p_osd_layer->frame_num++;
		}
	}
#endif
	return 0;
}

int ar_update_osd(int comp_fd, layer_user_t * p_osd_layer)
{
#if !defined(WIN32) && !defined(X64)
	comp_ceva_update(comp_fd, p_osd_layer);
#endif
	return 0;
}

int ar_draw_ssd_output(int comp_fd, AR_DSP_DETECT_RESULTS_st * p_result, int my_width, int my_height)
{
	int i = 0;
	layer_user_t osd = {0};

	for(i = 0; i < p_result->object_num; i++)
	{
		ar_fill_osd_layer(comp_fd, &p_result->objects[i], NULL, 0,
			my_width, my_height, &osd);
	}

	ar_update_osd(comp_fd, &osd);

	return 0;
}

void ar_dump_ssd_output(int dsp_id, AR_DSP_DETECT_RESULTS_st * p_result)
{
	int i = 0;

	AR_PRINTF_DEBUG("[DSP%d]============Detect Output===========\r\n", dsp_id);
	AR_PRINTF_DEBUG("[DSP%d]Detected %d objects: \r\n", dsp_id, p_result->object_num);

	for(i = 0; i < p_result->object_num; i++)
	{
		AR_PRINTF_DEBUG("[DSP%d][%s]: %f, [%d, %d],[%d, %d]\r\n", dsp_id,
			p_result->objects[i].label, p_result->objects[i].score,
			p_result->objects[i].rect.x, p_result->objects[i].rect.y,
			p_result->objects[i].rect.x + p_result->objects[i].rect.width,
			p_result->objects[i].rect.y + p_result->objects[i].rect.height);
	}

	AR_PRINTF_DEBUG("[DSP%d]================ End ===============\r\n",dsp_id);
}

void ar_dump_onet_output(int dsp_id, AR_DSP_OUTPUT_st * dsp_output)
{
	int i = 0, j = 0;

	AR_PRINTF_DEBUG("[DSP%d]============Onet Output===========\r\n",dsp_id);

	for(i = 0; i < dsp_output->buffer_num; i++)
	{
		AR_PRINTF_DEBUG("[DSP%d]Buffer: %s\r\n", dsp_id, dsp_output->output_buffer[i].buffer_name);
		for(j = 0; j < 10; j++)
		{
			AR_PRINTF_DEBUG("%f ", dsp_output->output_buffer[i].pdata[j]);
		}
		AR_PRINTF_DEBUG("\r\n");

	}
	AR_PRINTF_DEBUG("[DSP%d]================ End ===============\r\n", dsp_id);

}

void ar_dump_m114_output(int dsp_id, AR_DSP_OUTPUT_st * dsp_output)
{
	int i = 0, j = 0;

	AR_PRINTF_DEBUG("[DSP%d]============Mobilenet114 Output===========\r\n",dsp_id);

	for(i = 0; i < dsp_output->buffer_num; i++)
	{
		AR_PRINTF_DEBUG("[DSP%d]Buffer: %s\r\n", dsp_id, dsp_output->output_buffer[i].buffer_name);
		for(j = 0; j < 10; j++)
		{
			AR_PRINTF_DEBUG("%f ", dsp_output->output_buffer[i].pdata[j]);
		}

		AR_PRINTF_DEBUG("\r\n");

	}
	AR_PRINTF_DEBUG("[DSP%d]================ End ===============\r\n", dsp_id);

}
void ar_dump_statistics(int dsp_id, AR_DSP_STATS_st * p_stats)
{
	AR_PRINTF_DEBUG("[DSP%d]============Statistics==============\r\n", dsp_id);
	AR_PRINTF_DEBUG("[DSP%d]Initialization time: %lu cycles.\r\n", dsp_id, p_stats->cdnn_init_time);
	AR_PRINTF_DEBUG("[DSP%d]Pre-process time:    %lu cycles.\r\n", dsp_id, p_stats->cdnn_pre_proc_time);
	AR_PRINTF_DEBUG("[DSP%d]Inference time:      %lu cycles.\r\n", dsp_id, p_stats->cdnn_inference_time);
	AR_PRINTF_DEBUG("[DSP%d]Post-process time:   %lu cycles.\r\n", dsp_id, p_stats->cdnn_post_proc_time);
	AR_PRINTF_DEBUG("[DSP%d]============== End =================\r\n", dsp_id);
}

#define MAX_STD_SSD_OBJECTS_CATEGORY  21
/*You may have your own post process, change it as you like*/
int ar_mobilenetssd_post_process(
	AR_DSP_OUTPUT_st * dsp_output, AR_DSP_DETECT_RESULTS_st * p_detect_results,
	int img_width, int img_height, float output_threshold, const char * ssd_labels[])
{
	int i = 0;
	int num = 0, object_num = 0;
	float score = 0.0;

	if(!dsp_output || !p_detect_results)
	{
		AR_PRINTF_ERR("%s: Null pointer!\r\n", __FUNCTION__);
		return -1;
	}

	//cdnn will have 2 buffers, width is 1/5
	num = dsp_output->output_buffer[0].height;
	//we pick up 64 objects at most for demo
	num = (num > AR_DSP_ALG_MAX_DETECT_OBJECTS) ? AR_DSP_ALG_MAX_DETECT_OBJECTS : num;
	for(i = 0; i < num; i++)
	{
		//the valid index should be >= 1
		if(dsp_output->output_buffer[0].pdata[i] < 1.0 || dsp_output->output_buffer[0].pdata[i] > MAX_STD_SSD_OBJECTS_CATEGORY)
		{
			continue;
		}

		score = dsp_output->output_buffer[1].pdata[i * 5];
		if(score < output_threshold)
		{
			continue;
		}
		//printf("num: %d, i %d, label index %f\r\n", num, i, dsp_output->output_buffer[0].pdata[i]);
		p_detect_results->objects[object_num].label_index = dsp_output->output_buffer[0].pdata[i];
		if(p_detect_results->objects[object_num].label_index >= STD_SSD_MAX_CATEGORIES)
		{
			sprintf(p_detect_results->objects[object_num].label, "%s","Invalid");
		}
		else
		{
			strcpy(p_detect_results->objects[object_num].label, ssd_labels[p_detect_results->objects[object_num].label_index]);
		}

		p_detect_results->objects[object_num].score = dsp_output->output_buffer[1].pdata[i * 5];
		p_detect_results->objects[object_num].rect.x = dsp_output->output_buffer[1].pdata[i * 5 + 1] * img_width;
		p_detect_results->objects[object_num].rect.y = dsp_output->output_buffer[1].pdata[i * 5 + 2] * img_height;
		p_detect_results->objects[object_num].rect.width =
		dsp_output->output_buffer[1].pdata[i * 5 + 3] * img_width - p_detect_results->objects[object_num].rect.x + 1;
		p_detect_results->objects[object_num].rect.height =
		dsp_output->output_buffer[1].pdata[i * 5 + 4] * img_height - p_detect_results->objects[object_num].rect.y + 1;

		//in range ?
		p_detect_results->objects[object_num].rect.x = p_detect_results->objects[object_num].rect.x > 0 ? p_detect_results->objects[object_num].rect.x : 0;
		p_detect_results->objects[object_num].rect.y = p_detect_results->objects[object_num].rect.y > 0 ? p_detect_results->objects[object_num].rect.y : 0;
		p_detect_results->objects[object_num].rect.x = p_detect_results->objects[object_num].rect.x > img_width ? img_width : p_detect_results->objects[object_num].rect.x;
		p_detect_results->objects[object_num].rect.y = p_detect_results->objects[object_num].rect.y > img_height ? img_height : p_detect_results->objects[object_num].rect.y;

		p_detect_results->objects[object_num].rect.width = p_detect_results->objects[object_num].rect.width > 0 ? p_detect_results->objects[object_num].rect.width : 0;
		p_detect_results->objects[object_num].rect.height = p_detect_results->objects[object_num].rect.height > 0 ? p_detect_results->objects[object_num].rect.height : 0;
		p_detect_results->objects[object_num].rect.width = p_detect_results->objects[object_num].rect.width > img_width ? img_width : p_detect_results->objects[object_num].rect.width;
		p_detect_results->objects[object_num].rect.height = p_detect_results->objects[object_num].rect.height > img_height ? img_height : p_detect_results->objects[object_num].rect.height;

		object_num++;

	}

	p_detect_results->object_num = object_num;

	//ar_dump_ssd_output(p_detect_results);

	return 0;
}

int ar_mobilenetssd_post_process_v6(
	AR_DSP_OUTPUT_st * dsp_output, AR_DSP_DETECT_RESULTS_st * p_detect_results,
	int img_width, int img_height, float output_threshold, const char * ssd_labels[])
{
	int i = 0;
	int num = 0, object_num = 0;
	float score = 0.0;

	if(!dsp_output || !p_detect_results)
	{
		AR_PRINTF_ERR("%s: Null pointer!\r\n", __FUNCTION__);
		return -1;
	}

	//cdnn V6 has 3 buffers, buffer 0 for index, 1 for score, 2 for box
	num = dsp_output->output_buffer[0].height;
	//we pick up 64 objects at most for demo
	num = (num > AR_DSP_ALG_MAX_DETECT_OBJECTS) ? AR_DSP_ALG_MAX_DETECT_OBJECTS : num;
	for(i = 0; i < num; i++)
	{
		//the valid index should be >= 1
		if(dsp_output->output_buffer[0].pdata[i] < 1.0 || dsp_output->output_buffer[0].pdata[i] > MAX_STD_SSD_OBJECTS_CATEGORY)
		{
			continue;
		}

		score = dsp_output->output_buffer[1].pdata[i];
		if(score < output_threshold)
		{
			continue;
		}
		//printf("num: %d, i %d, label index %f\r\n", num, i, dsp_output->output_buffer[0].pdata[i]);
		p_detect_results->objects[object_num].label_index = dsp_output->output_buffer[0].pdata[i];
		if(p_detect_results->objects[object_num].label_index >= STD_SSD_MAX_CATEGORIES)
		{
			sprintf(p_detect_results->objects[object_num].label, "%s","Invalid");
		}
		else
		{
			strcpy(p_detect_results->objects[object_num].label, ssd_labels[p_detect_results->objects[object_num].label_index]);
		}

		p_detect_results->objects[object_num].score = dsp_output->output_buffer[1].pdata[i];
		p_detect_results->objects[object_num].rect.x = dsp_output->output_buffer[2].pdata[i * 4] * img_width;
		p_detect_results->objects[object_num].rect.y = dsp_output->output_buffer[2].pdata[i * 4 + 1] * img_height;
		p_detect_results->objects[object_num].rect.width =
		dsp_output->output_buffer[2].pdata[i * 4 + 2] * img_width - p_detect_results->objects[object_num].rect.x + 1;
		p_detect_results->objects[object_num].rect.height =
		dsp_output->output_buffer[2].pdata[i * 4 + 3] * img_height - p_detect_results->objects[object_num].rect.y + 1;

		//in range ?
		p_detect_results->objects[object_num].rect.x = p_detect_results->objects[object_num].rect.x > 0 ? p_detect_results->objects[object_num].rect.x : 0;
		p_detect_results->objects[object_num].rect.y = p_detect_results->objects[object_num].rect.y > 0 ? p_detect_results->objects[object_num].rect.y : 0;
		p_detect_results->objects[object_num].rect.x = p_detect_results->objects[object_num].rect.x > img_width ? img_width : p_detect_results->objects[object_num].rect.x;
		p_detect_results->objects[object_num].rect.y = p_detect_results->objects[object_num].rect.y > img_height ? img_height : p_detect_results->objects[object_num].rect.y;

		p_detect_results->objects[object_num].rect.width = p_detect_results->objects[object_num].rect.width > 0 ? p_detect_results->objects[object_num].rect.width : 0;
		p_detect_results->objects[object_num].rect.height = p_detect_results->objects[object_num].rect.height > 0 ? p_detect_results->objects[object_num].rect.height : 0;
		p_detect_results->objects[object_num].rect.width = p_detect_results->objects[object_num].rect.width > img_width ? img_width : p_detect_results->objects[object_num].rect.width;
		p_detect_results->objects[object_num].rect.height = p_detect_results->objects[object_num].rect.height > img_height ? img_height : p_detect_results->objects[object_num].rect.height;

		object_num++;

	}

	p_detect_results->object_num = object_num;

	//ar_dump_ssd_output(p_detect_results);

	return 0;
}

int ar_alg_onet_post_process(AR_DSP_OUTPUT_st * dsp_output)
{

	if(!dsp_output)
	{
		AR_PRINTF_ERR("%s: Null pointer!\r\n", __FUNCTION__);
		return -1;
	}

	return 0;

}

int ar_mobilenet114_post_process()
{
	return 0;
}

void dump_dsp_config(THREAD_PARAM_st * p_t_param)
{
	int i = 0, j = 0;

	if(!p_t_param)
	{
		return;
	}

	if(p_t_param->dsp_run == 0)
	{
		return;
	}

	AR_PRINTF_DEBUG("DSP %d configuration: \r\n", p_t_param->dsp_id);
	AR_PRINTF_DEBUG("Enabled : %d\r\n", p_t_param->dsp_run);
	AR_PRINTF_DEBUG("Demo : %s\r\n", p_t_param->demo_name);

	AR_PRINTF_DEBUG("sram start: 0x%lx, size: 0x%lx\r\n", p_t_param->cdnn_sram_heap_start, p_t_param->cdnn_sram_heap_size);
	AR_PRINTF_DEBUG("ext_mem size: 0x%x\r\n", p_t_param->cdnn_ext_mem_size);

	for(i = 0; i < AR_DSP_ALG_MAX_NN_PER_DSP; i++)
	{
		if(strlen(p_t_param->ini_cnn_cfg[i].section) <= 0)
		{
			continue;
		}

		AR_PRINTF_DEBUG("network name: %s\r\n", p_t_param->ini_cnn_cfg[i].section);
		AR_PRINTF_DEBUG("input source: %d\r\n", p_t_param->ini_cnn_cfg[i].input_source);
		AR_PRINTF_DEBUG("local_img_directory: %s\r\n", p_t_param->ini_cnn_cfg[i].local_img_directory);

		AR_PRINTF_DEBUG("network id: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.network_id);
		AR_PRINTF_DEBUG("network type: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.network_type);
		AR_PRINTF_DEBUG("channel swap: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.channel_swap);
		AR_PRINTF_DEBUG("resize input: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.resize_input);
		AR_PRINTF_DEBUG("amend_flag: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.amend_flag);
		AR_PRINTF_DEBUG("block_size: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.block_size);
		AR_PRINTF_DEBUG("block_number: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.block_number);
		AR_PRINTF_DEBUG("block_interval: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.block_interval);
		AR_PRINTF_DEBUG("raw scale: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.raw_scale);
		AR_PRINTF_DEBUG("output threshold: %f\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.output_threshold);
		AR_PRINTF_DEBUG("weight: %s\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.weight_file_path);
		AR_PRINTF_DEBUG("len for pdata: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.len_of_buffer_for_pdata);
		AR_PRINTF_DEBUG("resize_by_dsp: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.resize_by_dsp);
		AR_PRINTF_DEBUG("softmax_threshold: \r\n");
		for(j = 0; j < AR_DSP_ALG_MAX_SOFTMAX_THRD_NUM; j++)
		{
			if(strlen(p_t_param->ini_cnn_cfg[i].cnn_cfg.softmax_thrd[j].name))
			{
				AR_PRINTF_DEBUG("name: %s value: %f\r\n",
					p_t_param->ini_cnn_cfg[i].cnn_cfg.softmax_thrd[j].name, p_t_param->ini_cnn_cfg[i].cnn_cfg.softmax_thrd[j].threshold);
			}
		}

		AR_PRINTF_DEBUG("num_inputs: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.num_inputs);
		for(j = 0; j < p_t_param->ini_cnn_cfg[i].cnn_cfg.num_inputs; j++)
		{
			AR_PRINTF_DEBUG("input layer %d [%s/%d]: \r\n", j,
				p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[j].pLayerName, p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[j].bufferId);

			AR_PRINTF_DEBUG("input format: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.input_format[j]);
			AR_PRINTF_DEBUG("input buf len: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.input_buf_len[j]);

			AR_PRINTF_DEBUG("width: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[j].width);
			AR_PRINTF_DEBUG("height: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[j].height);
			AR_PRINTF_DEBUG("nchannels: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[j].nChannels);
			AR_PRINTF_DEBUG("dataOrder: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[j].dataOrder);
			AR_PRINTF_DEBUG("dataType: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[j].dataType);
			AR_PRINTF_DEBUG("depth: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[j].depth);
			AR_PRINTF_DEBUG("nInputs: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[j].nInputs);
			AR_PRINTF_DEBUG("scaleFactor: %f\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[j].scaleFactor);
			AR_PRINTF_DEBUG("dataFlipped: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[j].dataFlipped);
			AR_PRINTF_DEBUG("dataTransposed: %d\r\n", p_t_param->ini_cnn_cfg[i].cnn_cfg.input_params[j].dataTransposed);
		}

	}

}

int ar_get_max_input_len(THREAD_PARAM_st * p_t_param, int input_id)
{
	int max_len = 0, len = 0;
	int i = 0;

	for(i = 0; i < AR_DSP_ALG_MAX_NN_PER_DSP; i++)
	{
		if(p_t_param->ini_cnn_cfg[i].cnn_cfg.network_id == 0)
		{
			continue;
		}

		len = p_t_param->ini_cnn_cfg[i].cnn_cfg.input_buf_len[input_id];
		if(len > max_len)
		{
			max_len = len;
		}

	}

	return max_len;
}

int ar_get_max_pdata_len(THREAD_PARAM_st * p_t_param)
{
	int max_len = 0, len = 0;
	int i = 0;

	for(i = 0; i < AR_DSP_ALG_MAX_NN_PER_DSP; i++)
	{
		if(p_t_param->ini_cnn_cfg[i].cnn_cfg.network_id == 0)
		{
			continue;
		}

		len = p_t_param->ini_cnn_cfg[i].cnn_cfg.len_of_buffer_for_pdata;
		if(len > max_len)
		{
			max_len = len;
		}

	}

	return max_len;

}

//For sweeper ssd
//extern pthread_mutex_t g_alg_obstacle_mutex;
//extern AR_ALG_OBSTACLE_st g_alg_obstacle;
int ar_get_detect_results(AR_ALG_OBSTACLE_st * p_obstacle)
{
	if(!p_obstacle)
	{
		return -1;
	}

	pthread_mutex_lock(&g_alg_obstacle_mutex);
	memcpy(p_obstacle, &g_alg_obstacle, sizeof(AR_ALG_OBSTACLE_st));
	pthread_mutex_unlock(&g_alg_obstacle_mutex);

	return 0;
}


#ifdef __cplusplus
}
#endif


