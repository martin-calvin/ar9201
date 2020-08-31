/******Artosyn DSP Alg demo******/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>
#include <pthread.h>

#if !defined(WIN32) && !defined(X64)
#include <sched.h>
#include <fcntl.h>
#include <sys/mman.h>

#include <sys/time.h>
#include <unistd.h>
#else
#include <sched.h>
#include <semaphore.h>
#include <Windows.h>
typedef int cpu_set_t;
#endif

#include "ar_alg_define.h"
#if defined(WIN32) || defined(X64)
#include "ar_dsp_rpc.h"
#endif
#include "ar_alg.h"
#include "ar_dsp_alg.h"
#include "ar_dsp_common.h"
#include "ar_get_img_list.h"



using namespace std;
int g_osd_fd = 0;
int g_app_quit_flag = 0;
int g_thread_exit_cnt = 0;
int g_img_thread_is_running = 0;
pthread_t gdbus_thread;
SYS_CONFIG_st g_sys_cfg = {0};

extern int ar_parse_ini(char * inifile, THREAD_PARAM_st * p_t_param, SYS_CONFIG_st * p_sys_cfg);
extern void dump_dsp_config(THREAD_PARAM_st * p_t_param);


#if !defined(WIN32) && !defined(X64)
int ar_bootup_dsp_check(int dsp_id)
{
    int ret = 0;
    int dsp_wait_flag = 0;
	int dsp_core_rst_flag = 0;
	int dsp_global_rst_flag = 0;


	int fd_sys_reg_base=open("/dev/mem", O_RDWR | O_SYNC);
	char* g_va_sys_reg_base = (char*)mmap(NULL,0x100000, PROT_READ | PROT_WRITE, MAP_SHARED,fd_sys_reg_base,REGISTER_BASE_ADDR);

	dsp_core_rst_flag = *(volatile long *)(g_va_sys_reg_base + 0x100c  + dsp_id * 16);
	if((dsp_core_rst_flag& 0x1) != 1)
	{
        ret = -1;
		goto exit;
	}

	dsp_global_rst_flag = *(volatile long *)(g_va_sys_reg_base + 0x1004 + dsp_id * 16);
	if((dsp_global_rst_flag & 0x1)!= 1)
	{
        ret = -1;
		goto exit;

	}

	dsp_wait_flag = *(volatile long *)(g_va_sys_reg_base + 0x3020  + dsp_id * 0x100);
	if((dsp_wait_flag & 0x1) != 0)
	{
        ret = -1;
		goto exit;
	}


	AR_PRINTF_DEBUG("DSP%d BootUP Succeed...\r\n", dsp_id);


exit:
	munmap(g_va_sys_reg_base,0x100000);
	close(fd_sys_reg_base);

	return ret;

}


int ar_bootup_dsp_sync(int dsp_id)
{
    int ret = 0;
    int dsp_wait_flag = 0;
	int dsp_core_rst_flag = 0;
	int dsp_global_rst_flag = 0;


	int fd_sys_reg_base=open("/dev/mem", O_RDWR | O_SYNC);
	char* g_va_sys_reg_base = (char*)mmap(NULL,0x100000, PROT_READ | PROT_WRITE, MAP_SHARED,fd_sys_reg_base,REGISTER_BASE_ADDR);

	dsp_core_rst_flag = *(volatile long *)(g_va_sys_reg_base + 0x0034);

	AR_PRINTF_DEBUG("DO_PRINT *(int*)0x64570034:%x\r\n",dsp_core_rst_flag);
	while ('A' != ((dsp_core_rst_flag>>(8*dsp_id))&0xff))
    {
        usleep(1000);
    }
	AR_PRINTF_DEBUG("DONE_PRINT *(int*)0x64570034:%x\r\n",dsp_core_rst_flag);

	AR_PRINTF_DEBUG("DSP%d SYNC READY...\r\n", dsp_id);


exit:
	munmap(g_va_sys_reg_base,0x100000);
	close(fd_sys_reg_base);

	return ret;

}

#else
__inline int ar_bootup_dsp_check(int dsp_id)
{
    return 1;
}

__inline int ar_bootup_dsp_sync(int dsp_id)
{
    return 1;
}

#endif

void print_usage(char * name)
{
	printf("\r\n");

	printf("Usage: %s [config.ini] [hardware | windows] [ip]\r\n", name);
	printf("Examples:\r\n");
	printf("VS simulation: %s std_ssd_config.ini \r\n", name);
	printf("Hardware simulation: %s std_ssd_config.ini hardware 192.168.199.100\r\n", name);
}

void exit_handler(int sig)
{
	printf("Get signal %d\r\n", sig);

	g_app_quit_flag = 1;
#if !defined(WIN32) && !defined(X64)
	if(gdbus_thread)
	{
		pthread_cancel(gdbus_thread);
	}
#endif
}


int main(int argc, char * argv[])
{
	pthread_t thread[MAX_DSP_ID] = {0};
	pthread_attr_t attr[MAX_DSP_ID] = {0};
	THREAD_PARAM_st t_param[MAX_DSP_ID] = {0};
	cpu_set_t cpu_info[MAX_DSP_ID]; //max 3 arm cores in sirius
	int i = 0, ret = 0;
	char inifile[128] = {0};
	int run_dsp_num = 0;
    char osd_file_name[128] = {0};

	void * (* thread_func_ptr[MAX_DSP_ID])(void *) = {NULL};

	//get_pthread
	pthread_t get_thread;
	pthread_attr_t get_attr;
	THREAD_PARAM_st get_t_param;
	cpu_set_t get_cpu_info;
	void * (* thread_get_func_ptr)(void *) = NULL;


	signal(SIGTERM, exit_handler);
	signal(SIGINT, exit_handler);

	if(argc < 2)
	{
		print_usage(argv[0]);
		return -1;
	}

#if !defined(WIN32) && !defined(X64)
	for(i = 0; i < MAX_DSP_ID; i++)
	{
		CPU_ZERO(&cpu_info[i]);
	}

	//bind core 0 to arm 1, core 1 to arm 2, core2/3 to arm0
	CPU_SET(1, &cpu_info[0]);
	CPU_SET(2, &cpu_info[1]);
	CPU_SET(0, &cpu_info[2]);
	CPU_SET(0, &cpu_info[3]);
	//get_pthread
	CPU_ZERO(&get_cpu_info);
	CPU_SET(0, &get_cpu_info);
#endif

	for(i = 0; i < MAX_DSP_ID; i++)
	{
		t_param[i].dsp_id = DSP_ID_0 + i;

		pthread_attr_init(&attr[i]);
#if !defined(WIN32) && !defined(X64)
		if(0 != pthread_attr_setaffinity_np(&attr[i], sizeof(cpu_set_t), &cpu_info[i]))
		{
			AR_PRINTF_ERR("Set thread %d affinity failed!\n", i);
			return -1;
		}
#endif
	}

	//get_pthread
    memset(&get_t_param, 0 ,sizeof(get_t_param));
    pthread_attr_init(&get_attr);
#if !defined(WIN32) && !defined(X64)
	if(0 != pthread_attr_setaffinity_np(&get_attr, sizeof(cpu_set_t), &get_cpu_info))
	{
		AR_PRINTF_ERR("Set thread %d affinity failed!\n", i);
		return -1;
	}
#endif

	strcpy(inifile, argv[1]);
	printf("Parse ini file: %s\r\n", inifile);
	ret = ar_parse_ini(inifile, t_param, &g_sys_cfg);
	if(ret < 0)
	{
		printf("Configuration error, exit.\r\n");
		goto _free_and_exit;
	}

     strcpy(osd_file_name, COMP_OSD_DEVICE);
#if defined(WIN32) || defined(X64)
	if (argc >= 4 && strcmp(argv[2], "hardware") == 0)
	{
		ar_runtime_init(HARDWARE_SIMULATION, argv[3]);
		printf("Run hardware simulation, client is on %s\r\n", argv[3]);
	}
	else
	{
		ar_runtime_init(VS_SIMULATION, NULL);
	}
#else
    if(argc > 3)
    {
        strcpy(osd_file_name, argv[3]);
    }
    else
    {
        strcpy(osd_file_name, COMP_OSD_DEVICE);
    }
#endif

    g_osd_fd = comp_osd_open(osd_file_name);
	if(g_osd_fd <= 0)
	{
		printf("Open %s failed\n", osd_file_name);
		goto _free_and_exit;
	}

	printf("System cfg: loglevel %d, dump_ctrl 0x%x, DSP %d will load weight file.\r\n",
	g_sys_cfg.loglevel, g_sys_cfg.dump_ctrl, g_sys_cfg.who_load_weight_data);

	for(i = 0; i < MAX_DSP_ID; i++)
	{
		dump_dsp_config(&t_param[i]);
	}

	for(int i = 0; i < MAX_DSP_ID; i++)
	{
		if(!t_param[i].dsp_run)
		{
			continue;
		}
		memcpy(&get_t_param, &t_param[i], sizeof(get_t_param));
		if(argc >= 3)
		{
			strcpy(get_t_param.dev_name, argv[2]);
		}
		break;
	}

	if(get_t_param.ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_SENSOR_IMG)
	{
		ar_init_img_list();
		//get_pthread
		thread_get_func_ptr = ar_get_img_thread_func;
		if(thread_get_func_ptr)
		{
			if(0 != pthread_create(&get_thread, &get_attr, thread_get_func_ptr, &get_t_param))
			{
				AR_PRINTF_ERR("Create get_img thread 0 failed!\n");
				goto _free_and_exit;
			}

			g_img_thread_is_running = 1;
		}
	}


	for(i = 0; i < MAX_DSP_ID; i++)
	{
		if(!t_param[i].dsp_run)
		{
			continue;
		}

		if(ar_bootup_dsp_check(DSP_ID_0 + i) < 0)
		{
		    AR_PRINTF_ERR("DSP %d is not alive, please boot it up first.\r\n", i);
            continue;
		}

		ar_bootup_dsp_sync(DSP_ID_0 + i);

		AR_PRINTF_DEBUG("DSP %d will run %s\r\n", i, t_param[i].demo_name);

		if(strcmp(t_param[i].demo_name, "std_ssd_test") == 0
			|| strcmp(t_param[i].demo_name, "sweeper_ssd") == 0)
		{
			thread_func_ptr[i] = pthread_run_std_mobilenet_ssd;
		}
		else if(strcmp(t_param[i].demo_name, "network_evaluation") == 0)
		{
			thread_func_ptr[i] = pthread_run_network_evaluation;
		}
		else if(strcmp(t_param[i].demo_name, "face_detect_test") == 0)
		{
			thread_func_ptr[i] = pthread_run_face_detect_test;
		}
		else if(strcmp(t_param[i].demo_name, "mtcnn_detect_test") == 0)
		{
			thread_func_ptr[i] = pthread_run_mtcnn_test;
		}
		else
		{
			AR_PRINTF_ERR("This demo is not supported yet...\r\n");
			continue;
		}

		strcpy(t_param[i].inifile, inifile);

		if(thread_func_ptr[i])
		{
			if(0 != pthread_create(&thread[i], &attr[i], thread_func_ptr[i], &t_param[i]))
			{
				AR_PRINTF_ERR("Create thread 0 failed!\n");
				goto _free_and_exit;
			}
		}

		run_dsp_num++;

	}

	while(1)
	{
		if(g_thread_exit_cnt == run_dsp_num && !g_img_thread_is_running)
		{
			break;
		}
#if !defined(WIN32) && !defined(X64)
	sleep(1);
#else
	_sleep(1);
#endif
	}

_free_and_exit:
	if(g_osd_fd)
	{
		comp_osd_close(g_osd_fd);
	}

	printf("Byebye...\r\n");

	ar_runtime_deinit();
	pthread_attr_destroy(&get_attr);

	for(i = 0; i < MAX_DSP_ID; i++)
	{
		pthread_attr_destroy(&attr[i]);
	}
	return 0;
}
