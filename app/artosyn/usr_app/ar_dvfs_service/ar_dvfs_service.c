
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#include "ar_dvfs.h"
#include "ar_da9062_log.h"
#include "ar_thermal.h"

#define TEMP_STEP_1 1.2     //the smallest unit of temperature detection is 0.4.
#define TEMP_STEP_2 2     //the smallest unit of temperature detection is 1.
#define TIME_STEP 30
#define CEVA_FREQ_STEP 2   //every temperature unit corresponds to 20MHz (CEVA_FREQ)
#define CORE_VOL_STEP 10000  // every temperature unit corresponds to 0.01V (CORE_VOL_STEP)

#define CORE_VOL_MIN 850000
#define CEVA_FREQ_MAX 80
#define CEVA_FREQ_MIN 60
#define CEVA_FREQ_WARNING 20

enum pvt_flag{
	PVT_ZERO = 0,
	PVT_ONE,
	PVT_TWO,
	PVT_THREE,
    PVT_FOUR
};

enum temperature_flag{
	TEMP_MIN_STAGE = 1,
	TEMP_ADJUST_STAGE,
	TEMP_WARNING_STAGE
};

typedef struct read_tsensor_delta_fd_t {
	int t_iter;
	float t_last;
	float T_delta[3];
	float t_delta_average;
}read_tsensor_delta_fd;

typedef struct
{
	char thermal_path[256];
	FILE * log_fd;
}thermal_parm;

int T_target = 95;
int T_target_low = 90;
int T_target_up = 100;
static int g_run_flag = 1;

read_tsensor_delta_fd ar_dvfs_read_core_tsensor_delta(void *tsensor_f, read_tsensor_delta_fd t_delta_fd)
{
	float T_delta_average = 0;
	read_tsensor_fd *tsensor_fd = (read_tsensor_fd *)tsensor_f;
	float temperature = ar_dvfs_read_core_tsensor(tsensor_fd->addr);

	int i = t_delta_fd.t_iter;
	if((i >= 0)&&(i <= 2)){
		t_delta_fd.T_delta[i] = temperature - t_delta_fd.t_last;
		//printf("T_delta[%d] = %f \n", i, t_delta_fd.T_delta[i]);
	}else if(i == 3){
		t_delta_fd.T_delta[i-3] = t_delta_fd.T_delta[i-2];
		t_delta_fd.T_delta[i-2] = t_delta_fd.T_delta[i-1];
		t_delta_fd.T_delta[i-1] = temperature - t_delta_fd.t_last;
		T_delta_average = (t_delta_fd.T_delta[i-3] + t_delta_fd.T_delta[i-2] + t_delta_fd.T_delta[i-1])/3.0;
		//printf("T_delta[%d] = %f \n", i-1, t_delta_fd.T_delta[i-1]);
	}

	if(i <= 2)
		i++;

	t_delta_fd.t_iter = i;
	t_delta_fd.t_last = temperature;
	t_delta_fd.t_delta_average = T_delta_average;

	return t_delta_fd;
}

int ar_dvfs_vol_freq_adjust(int *vol_freq_set, int core_volt_regulate, int ceva_freq_regulate, unsigned int core_vol_max)
{
	int core_voltage = vol_freq_set[0], ceva_freq = vol_freq_set[1];
	int flag = -1;

	vol_freq_set[0] = vol_freq_set[0] - core_volt_regulate;

	//limit voltage, a7 freq, ceva freq to a safe range.
	if(vol_freq_set[0] > core_vol_max)
		vol_freq_set[0] = core_vol_max;
	if(vol_freq_set[0] < CORE_VOL_MIN)
		vol_freq_set[0] = CORE_VOL_MIN;

	//printf("vol_freq_set[0] = %d \n", vol_freq_set[0]);

	if(vol_freq_set[0] == CORE_VOL_MIN){
		vol_freq_set[1] = vol_freq_set[1] - ceva_freq_regulate;
		//printf("vol_freq_set[1] = %d \n", vol_freq_set[1]);
	}else if((vol_freq_set[0] > CORE_VOL_MIN)&&(vol_freq_set[0] <= core_vol_max))
		vol_freq_set[1] = CEVA_FREQ_MAX - (core_vol_max - vol_freq_set[0]) * CEVA_FREQ_STEP * 1e-4 ;//limit the frequency  according to voltage.
	else if(vol_freq_set[0] > core_vol_max)
		vol_freq_set[1] = CEVA_FREQ_MAX;


	if(vol_freq_set[1] > CEVA_FREQ_MAX)
		vol_freq_set[1] = CEVA_FREQ_MAX;
	if(vol_freq_set[1] < CEVA_FREQ_MIN)
		vol_freq_set[1] = CEVA_FREQ_MIN;

	if((core_voltage != vol_freq_set[0])||(ceva_freq != vol_freq_set[1]))
		flag = 1;
	return flag;
}


void ar_dvfs_handle()
{
	int T_min = (T_target_low - 10);
	int T_max = (T_target_up + 10);
	enum temperature_flag stage_flag = TEMP_MIN_STAGE, last_stage_flag = TEMP_ADJUST_STAGE; // last_stage_flag different from stage_flag
	int ceva_freq_regulate = 0, core_volt_regulate = 0;
	float temperature = 0, tem_differ_low = 0, tem_differ_up = 0;
	void *tsensor_fd;
	read_tsensor_delta_fd t_delta_fd;
	t_delta_fd.t_iter = -1;
	float temp_delta_ave = 0;
	int adjust_flag = 0;//whether the program needs to adjust.
	unsigned int pvt_value = 0;
	ar_dvfs_set_core_voltage(900000); //need to read pvt when the voltage is 0.9v.
	unsigned int ceva_pvt_900mv = ar_dvfs_read_ceva_pvt();
	unsigned int core_vol_max = 10000*((unsigned int)((900 + (ceva_pvt_900mv - 540/5.016)/0.243)/10 + 1));

	if(core_vol_max > 900000)
		core_vol_max = 900000;
	else if(core_vol_max < 850000)
		core_vol_max = 850000;

	printf("artosyn dvfs test 2.0 \n");
	printf("core_vol_max = %d \n", core_vol_max );
	int vol_freq_in_min_stage[2] = {core_vol_max, CEVA_FREQ_MAX};
	int vol_freq_in_adjust_stage[2] = {core_vol_max, CEVA_FREQ_MAX};
	int vol_freq_in_warn_stage[2] = { CORE_VOL_MIN, CEVA_FREQ_WARNING};

	printf("     T      ceva_freq(MHz)   voltage(v)    PVT \n");
	ar_dvfs_set_core_voltage(core_vol_max);
	tsensor_fd = ar_dvfs_read_core_tsensor_start();

	while(g_run_flag){
		t_delta_fd = ar_dvfs_read_core_tsensor_delta(tsensor_fd, t_delta_fd);
		temperature = t_delta_fd.t_last;

		temp_delta_ave = t_delta_fd.t_delta_average;
		tem_differ_low = temperature - T_target_low;
		tem_differ_up = temperature - T_target_up;

		ceva_freq_regulate = 0;
		core_volt_regulate = 0;

		if((tem_differ_up > 0)){
			ceva_freq_regulate = CEVA_FREQ_STEP * (int)(tem_differ_up/TEMP_STEP_1);	//temp 0.4 , freq 2; 20MHz
			core_volt_regulate = CORE_VOL_STEP * (int)(tem_differ_up/TEMP_STEP_1); // temp 0.4 ; 0.01V;
		}else if((tem_differ_low < 0)&&(temp_delta_ave <= 0)){
			ceva_freq_regulate = CEVA_FREQ_STEP *(int)(tem_differ_low/TEMP_STEP_2);	//temp 1 , freq 2; 20MHz
			core_volt_regulate = CORE_VOL_STEP * (int)(tem_differ_low/TEMP_STEP_2); // temp 1 ; 0.01V;
		}

		pvt_value = ar_dvfs_read_ceva_pvt();

		if(temperature < T_min){
			stage_flag = TEMP_MIN_STAGE;
			printf(" %f       %d          %f     %d \n",
				temperature, vol_freq_in_min_stage[1]*10 ,vol_freq_in_min_stage[0]*1.0/1e6,	pvt_value );

		}else if((temperature >= T_min)&&(temperature < T_max)){
			stage_flag = TEMP_ADJUST_STAGE;
			if(((temperature >= T_min)&&(temperature < T_target_low))||((temperature >= T_target_up)&&(temperature < T_max)))
				adjust_flag = ar_dvfs_vol_freq_adjust(vol_freq_in_adjust_stage, core_volt_regulate, ceva_freq_regulate, core_vol_max);

			printf(" %f       %d          %f     %d \n",
				temperature, vol_freq_in_adjust_stage[1]*10 ,vol_freq_in_adjust_stage[0]*1.0/1e6, pvt_value);

		}else if(temperature >= T_max){
			stage_flag = TEMP_WARNING_STAGE;

			printf(" %f       %d          %f     %d \n",
					temperature, vol_freq_in_warn_stage[1]*10 ,vol_freq_in_warn_stage[0]*1.0/1e6, pvt_value);

		}

		if((last_stage_flag != stage_flag)||((stage_flag == TEMP_ADJUST_STAGE)&&(adjust_flag == 1))){
			last_stage_flag = stage_flag;
			switch(stage_flag){
			case TEMP_MIN_STAGE:
				if(ceva_freq_regulate < 0)
					ar_dvfs_set_core_voltage(vol_freq_in_min_stage[0]);
					ar_dvfs_set_ceva_freq(vol_freq_in_min_stage[1]);
				if(ceva_freq_regulate > 0)
					ar_dvfs_set_core_voltage(vol_freq_in_min_stage[0]);
				break;
			case TEMP_ADJUST_STAGE:
				if(ceva_freq_regulate < 0)
					ar_dvfs_set_core_voltage(vol_freq_in_adjust_stage[0]);
					ar_dvfs_set_ceva_freq(vol_freq_in_adjust_stage[1]);
				if(ceva_freq_regulate > 0)
					ar_dvfs_set_core_voltage(vol_freq_in_adjust_stage[0]);
				break;
			case TEMP_WARNING_STAGE:
				if(ceva_freq_regulate < 0)
					ar_dvfs_set_core_voltage(vol_freq_in_warn_stage[0]);
					ar_dvfs_set_ceva_freq(vol_freq_in_warn_stage[1]);
				if(ceva_freq_regulate > 0)
					ar_dvfs_set_core_voltage(vol_freq_in_warn_stage[0]);
				break;
			default:
				printf("voltage and freq is not adjusted.\n");
				break;
			}
		}
		sleep(TIME_STEP);
	}
	ar_dvfs_read_core_tsensor_stop(tsensor_fd);
}

static void print_usage(void)
{
	printf("\n Usage:\n");
	printf("execute dvfs, Example: .\\ar_dvfs_service \n");
	printf("set temperature 90 Celsius, Example: .\\ar_dvfs_service target 90\n");
	printf("set voltage to 0.95v, Example: .\\ar_dvfs_service test 950 mv\n");
	printf("open log to wirte thermal mode ar_dvfs_service target 90 -l noonly\n");
	printf("only open log to wirte thermal(no dvfs) mode ar_dvfs_service target 90 -l only\n");
	printf("\n");
}

//capture exit signal
static void sighandler(int signo)
{
    if (signo == SIGINT || signo == SIGQUIT || signo == SIGKILL || signo == SIGTERM)
    {
        g_run_flag = 0;
        printf("thermal prepare to exit\n");
    }
}

int write_da9062_thermal_log(FILE * log_fd, thermal_fd * t_fd, int * warn_on)
{
	if(read_thermal_all(t_fd) < 0)
	{
		printf("read thermal failed!\n");
		return -1;
	}
	
	if(0 == *warn_on)
	{
		if(t_fd->thermal_curr_temp >= t_fd->thermal_temp)
		{
			char buffer[128] = "";
			int ret = -1;
			snprintf(buffer, 128, "DA9062 TJUNC temperature over %d(%d)", t_fd->thermal_curr_temp, t_fd->thermal_temp);			
			ret = write_index_data(log_fd, buffer, strlen(buffer));
			if(ret >= 0)
			{
				*warn_on = 1;
			}
			else
			{
				printf("0.da9062_thermal_log write failed!\n");
			}
		}
	}
	else
	{
		if(t_fd->thermal_curr_temp < t_fd->thermal_temp)
		{
			char buffer[128] = "";
			int ret = -1;
			snprintf(buffer, 128, "DA9062 TJUNC temperature decrease to %d", t_fd->thermal_curr_temp);			
			ret = write_index_data(log_fd, buffer, strlen(buffer));
			if(ret >= 0)
			{
				*warn_on = 0;
			}
			else
			{
				printf("1.da9062_thermal_log write failed!\n");
			}
		}
	}
	
	return 0;
}

void * thermal_log(void * para)
{
	thermal_parm		* p_th;
	thermal_fd 			* t_fd;
	int					warn_on = 0;
	
	if(NULL == para)
	{
		printf("thermal para is NULL!\n");
		return NULL;
	}
	
	p_th = (thermal_parm *)para;
	t_fd = (thermal_fd *)open_thermal_fd(p_th->thermal_path);
	if(t_fd->thermal_temp_fd >= 0 && t_fd->thermal_curr_temp_fd >= 0)
	{
		while(g_run_flag)
		{
			write_da9062_thermal_log(p_th->log_fd, t_fd, &warn_on);
			sleep(2);
		}
		close_thermal_fd(t_fd);
	}
	else
	{
		printf("open %s failed!\n", p_th->thermal_path);
	}

	printf("thermal_log exit!\n");
	
	return NULL;
}

main(int argc, char *argv[])
{
	int 				log_mode = 0;
	int 				log_only = 0;
	int					opt;
	char				* mode = NULL;
	FILE 				* log_fd = NULL;
	pthread_t           thread_thermal_log;
	thermal_parm		p_th;
	struct sigaction    action;
	int					para_num = 0;

	print_usage();

    //get parm
	while ((opt = getopt(argc, argv, "l:")) != -1)
	{
		switch (opt) {
		case 'l':
			log_mode = 1;
			mode = optarg;
			if(strcmp(mode, "only") == 0)
			{
				log_only = 1;
			}
			para_num = 2;
			break;
			
		default:
			break;
		}
	}

    if(1 == log_mode)
    {
        log_fd = open_da9062_fault_log("/usrdata/usr/data/data_example/da9062_fault.log");
        if(NULL != log_fd)
        {
            if(write_da9062_fault_log(log_fd) < 0)
            {
                printf("da9062_fault_log write failed!\n");
            }
            else
            {
                printf("da9062_fault_log write successed!\n");
            }
        }
		
		action.sa_flags = 0;
		action.sa_handler = sighandler;
		sigaction(SIGINT, &action, NULL);
		sigaction(SIGKILL, &action, NULL);
		sigaction(SIGTERM, &action, NULL);
		
		snprintf(p_th.thermal_path, 256, "/sys/class/thermal/thermal_zone0");
		p_th.log_fd = log_fd;
		pthread_create(&thread_thermal_log, NULL, (void *)thermal_log, (void *)(&p_th));
    }

    if(0 == log_only)
    {

        if(argc <=3 + para_num){
            if(argv[1]){
                if((strcmp(argv[1], "target") == 0)) {
                    printf("argv[2] is %s \n", argv[2]);
                    T_target = atoi(argv[2]);
                    T_target_low = T_target - 5;
                    T_target_up = T_target + 5;
                    printf("T_target %d \n",T_target);
                }
            }
            ar_dvfs_handle();
        }

        if(argc >= 4 + para_num) {
            printf("adjust voltage start.\n");
            if((strcmp(argv[1], "test") == 0)&&(strcmp(argv[3], "mv") == 0)) {
                int core_voltage = 1e3 * atoi(argv[2]);
                printf("core_voltage is %d \n", core_voltage);
                ar_dvfs_set_core_voltage(core_voltage);
            }
        }
    }

    if(1 == log_mode)
    {
		pthread_join(thread_thermal_log, NULL);
        close_da9062_fault_log(log_fd);		
    }
}

