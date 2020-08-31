#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <getopt.h>
#include <signal.h>

#include "pwm_operation.h"

int mode_0(ENUM_PWM_PORT pwm_num, unsigned int period, unsigned int duty)
{
	if(pwm_enable_set(pwm_num, 0) < 0)
	{
		printf("mode_0 disable pwm failed!\n");
		return -1;
	}

	if(pwm_period_set(pwm_num, period) < 0)
	{
		printf("mode_0 set period failed!\n");
		return -1;
	}

	if(pwm_duty_cycle_set(pwm_num, duty) < 0)
	{
		printf("mode_0 set duty cycle failed!\n");
		return -1;
	}

	if(pwm_enable_set(pwm_num, 1) < 0)
	{
		printf("mode_0 enable pwm failed!\n");
		return -1;
	}
	return 0;
}

int mode_1(ENUM_PWM_PORT pwm_num, unsigned int period, unsigned char percent)
{
	if(pwm_enable_set(pwm_num, 0) < 0)
	{
		printf("mode_1 disable pwm failed!\n");
		return -1;
	}

	if(pwm_period_set(pwm_num, period) < 0)
	{
		printf("mode_1 set period failed!\n");
		return -1;
	}

	if(pwm_duty_cycle_percent_set(pwm_num, percent) < 0)
	{
		printf("mode_1 set duty cycle percent failed!\n");
		return -1;
	}

	if(pwm_enable_set(pwm_num, 1) < 0)
	{
		printf("mode_1 enable pwm failed!\n");
		return -1;
	}
	return 0;
}

unsigned char g_run_flag = 1;

//capture exit signal
static void sighandler(int signo)
{
	if (signo == SIGINT || signo == SIGQUIT || signo == SIGKILL || signo == SIGTERM)
	{
		g_run_flag = 0;
	}
}

int mode_2(ENUM_PWM_PORT pwm_num, unsigned int period)
{
	unsigned char percent = 0;
	while(g_run_flag)
	{
		mode_1(pwm_num, period, percent);
		percent = ((percent + 1) % 100);
		usleep(1000 * 1000);
	}

	return 0;
}

static void usage(const char *argv0)
{
	printf("Usage: %s [options]\n", argv0);
	printf("Available options are\n");
	printf(" -n N                           Select pwmN, N select from 0 to 7\n");
	printf(" -m N                           Select test mode, N select from 0 to 3\n");
	printf(" -n X -m 0 -p XXX -d XXX        Set pwmX in mode 0, direct set period and duty cycle\n");
	printf(" -n X -m 1 -p XXX -c XX         Set pwmX in mode 1, direct set period and set duty cycle by percent\n");
	printf(" -n X -m 2 -p XXX               Set pwmX in mode 2, direct set period and duty cycle will auto test from 0%% to 100%%\n");
	printf(" -n X -m 3 -e N                 Set pwmX in mode 3, N:0 disable pwmX, 1 enable pwmX\n");
}

int main(int argc , char *argv[])
{
	int 		mode = 0;
	int		opt = 0;
	ENUM_PWM_PORT 	pwm_num = PWM_0;
	unsigned int 	period, period_get = 0;
	unsigned int 	duty, duty_get = 0;
	unsigned char 	percent, percent_get = 0;
	unsigned char	enable, enable_get = 0;
	struct sigaction    action;

	while ((opt = getopt(argc, argv, "n:m:p:d:c:e:h")) != -1)
	{
		switch (opt)
		{
			case 'n':
				pwm_num = atoi(optarg);
				if(pwm_num >= PWM_MAX)
				{
					printf("pwm_num out of range!\n");
					return -1;
				}
				break;
			case 'm':
				mode = atoi(optarg);
				if(mode > 3)
				{
					printf("mode out of range!\n");
					return -1;
				}
				break;
			case 'p':
				period = strtoul(optarg, 0, 0);
				period_get = 1;
				break;
			case 'd':
				duty = strtoul(optarg, 0, 0);
				duty_get = 1;
				break;
			case 'c':
				percent = atoi(optarg);
				if(percent < 0 || percent > 100)
				{
					printf("percent out of range!\n");
					return -1;
				}
				percent_get = 1;
				break;
			case 'e':
				enable = atoi(optarg);
				enable_get = 1;
				break;
			case 'h':
				usage(argv[0]);
				return 0;
			default :
				break;
		}
	}

	if(pwm_export(pwm_num) < 0)
	{
		printf("pwm export failed!\n");
		return -1;
	}

	if(0 == mode)
	{
		if(1 == period_get && 1 == duty_get)
		{
			mode_0(pwm_num, period, duty);	
		}
		else
		{
			printf("please input enough parameter!\n");
		}
	}
	else if(1 == mode)
	{
		if(1 == period_get && 1 == percent_get)
		{
			mode_1(pwm_num, period, percent);
		}
		else
		{
			printf("please input enough parameter!\n");
		}
	}
	else if(2 == mode)
	{
		if(1 == period_get)
		{
			action.sa_flags = 0;
			action.sa_handler = sighandler;
			sigaction(SIGINT, &action, NULL);
			sigaction(SIGKILL, &action, NULL);
			sigaction(SIGTERM, &action, NULL);

			mode_2(pwm_num, period);
		}
		else
		{
			printf("please input enough parameter!\n");
		}
	}
	else if(3 == mode)
	{
		if(1 == enable_get)
		{
			pwm_enable_set(pwm_num, enable);
		}
		else
		{
			printf("please input enough parameter!\n");
		}
	}
	else
	{
		printf("no test mode match!\n");	
	}

	return pwm_unexport(pwm_num);
}
