#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <getopt.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/klog.h>
#include <pthread.h>
#include <ar_log.h>
#include "ar_logger.h"
#include "v4ar_dev.h"
#include <log/log.h>


#define PAGE_SIZE 		(0x1000)

#define DMA_PA_SAVE_PATH        "/tmp/dma_pa.config"
#define LOG_DEV_RPC 		"/dev/remote_cmd"

static char * color_string[] = {
	[PRN_UART] = BROWN,
	[PRN_ERR]  = L_RED,
	[PRN_RES]  = CYAN,
	[PRN_BUFF] = NONE,
};

static void print_usage(char *program)
{
	printf("\n Usage:\n");

	printf("\n %s -a address -f filename -e offset -s start\n", program);

	printf("Options:\n");
	printf("  -f filename						\n");
	printf("  -a logger_pa_addr					\n");
	printf("  -h print usage 					\n");
	printf("  -e start from end - offset 		\n");
	printf("  -s start from start + offset 		\n");
	printf("  -r redirection rtos and kernel log to system logcat   \n");

	printf("\n");

	exit(0);
}

//capture exit signal
static void sighandler(int signo)
{
	if (signo == SIGINT || signo == SIGQUIT || signo == SIGKILL || signo == SIGTERM)
	{
		log_err("logcat exit signal = %d\n", signo);
		exit(signo);
	}
}

unsigned int get_pa_from_config(char * pathname)
{
	FILE * fp = NULL;
	unsigned int dma_pa = 0;
	int ret = -1;
	fp = fopen(pathname, "rb");
	if(NULL == fp)
	{
		printf("open %s failed!\n", pathname);
		return 0;
	}

	ret = fread(&dma_pa, sizeof(dma_pa), 1, fp);
	if(ret <= 0)
	{
		printf("read %s failed!\n", pathname);
                return 0;
	}

	ret = fclose(fp);
	if(ret != 0)
	{
		printf("close %s failed!\n", pathname);
	}

	return dma_pa;
}

static void print_kernel_log()
{
	char kLogBuf[2048] = {0};
	int msgLen;

	if (klogctl(9, kLogBuf, sizeof(kLogBuf) > 0)) {
		msgLen = klogctl(2, kLogBuf, sizeof(kLogBuf));
		if (msgLen > 0)
			ALOG(LOG_INFO, "KERNEL", "%s", (char *)kLogBuf);
	}

	return;
}

int main(int argc, char **argv)
{
	int		ret 	= 0;
	int		opt 	= 0;
	int		log_fd 	= -1;

	unsigned int 	logger_pa_addr	= 0;
	unsigned int 	pa_aligned 		= 0;
	int 			fd_mem 			= -1;
	char			filename[128] = {0};
	int				flag_seek_end = 0;
	int				flag_seek_set = 0;
	int				seek_offset = 0;

	int		redirect = 0;
	int		clormode = 0;
	struct logger_log    * logger = NULL;
	struct logger_reader * reader = NULL;

	struct sigaction	action;

	action.sa_flags = 0;
	action.sa_handler = sighandler;
	sigaction(SIGINT, &action, NULL);
	sigaction(SIGKILL, &action, NULL);
	sigaction(SIGTERM, &action, NULL);

	//get PA from args
	while ((opt = getopt(argc, argv, "a:f:e:s:h:rc")) != -1) {
		switch (opt) {
			case 'a':
				logger_pa_addr = strtoul(optarg, 0, 0);
				break;

			case 'f':
				if (optarg != NULL) {
					strncpy(filename, optarg, sizeof(filename) -1);
					filename[sizeof(filename) -1] = '\0';
				}
				break;

			case 'h':
				print_usage(argv[0]);
				break;

			case 'e':
				flag_seek_end = 1;
				seek_offset = strtoul(optarg, 0, 0);
				break;

			case 's':
				flag_seek_set = 1;
				seek_offset = strtoul(optarg, 0, 0);
				break;

			case 'r':
				redirect = 1;
				break;

			case 'c':
				clormode = 1;
				break;

			default:
				break;
		}
	}

	if (strlen(filename) == 0)
		log_fd = STDOUT_FILENO;
	else
		log_fd = open(filename, O_RDWR|O_CREAT);

	if (log_fd == -1) {
		printf("fail to open %s\n", filename);
		ret = -1;
		return 0;
	}

	//frist get PA from config data
	logger_pa_addr = get_pa_from_config(DMA_PA_SAVE_PATH);

	if (!logger_pa_addr) {
		int rc = -1;
		int fd = -1;
		v4ar_common_ctl_t ctl = {
			.ctl_code = LOG_INFO_CMD_ID,
			.len 	  = sizeof(struct log_info ),
		};

		printf("try to get PA from device %s\n", LOG_DEV_RPC);

		//check if the device is avail
		do {
			rc = access(LOG_DEV_RPC, R_OK | W_OK);
			usleep(100 * 1000);
		}while (rc != 0);

		//get pa address from firmware
		fd = open(LOG_DEV_RPC, O_RDWR);
		rc = ioctl(fd, VIDIOC_V4AR_DEV_COMMON_CTL, &ctl);
		if (rc == 0)
			logger_pa_addr = ((struct log_info *)(ctl.data))->pa;
		else  {
			printf("ioctl fd: %d cmd: %d rc: %d\n", fd, LOG_INFO_CMD_ID, rc);
			ret = -1;
		}

		close(fd);

		if (ret)
			goto out;
	}

	pa_aligned = (logger_pa_addr & (~(PAGE_SIZE - 1)));

	//mmap
	fd_mem = open("/dev/mem", O_RDWR);
	if (fd_mem < 0) {
		log_err("open %s failed ret=%d\n", "/dev/mem", fd_mem);
		goto out;
	}

	void * va_aligned = mmap(NULL, (LOG_OUTPUT_ENTRY_SIZE * LOG_OUTPUT_ENTRY_COUNT) + PAGE_SIZE, \
							PROT_READ|PROT_WRITE, MAP_SHARED, fd_mem, pa_aligned);
	if (va_aligned == NULL) {
		log_err("va_aligned == NULL \n");
		goto out;
	}

	logger = (struct logger_log *)((unsigned int)va_aligned + (logger_pa_addr & (PAGE_SIZE - 1)));
	reader = logger_create_reader_from_logger(logger);

	printf("\nstarting log %s:\n" \
		   "\tAligned address:(0x%x:%p), logger Address:(0x%x:%p)\n" \
		   "\tfile: %s fd:%d\n", \
			(char *)logger,
			pa_aligned, 	va_aligned,\
			logger_pa_addr, logger, \
			strlen(filename)?filename:"stdout", log_fd);

	if (!reader) {
			printf("creater logger reader fail \n");
			goto out;
	}

	if (flag_seek_set)
		logger_readder_seeek(reader, seek_offset, SEEK_SET);
	else if (flag_seek_end)
		logger_readder_seeek(reader, -seek_offset, SEEK_END);

	while (1) {
		int i		=  0;
		int cnt		= 0;

		char buf[LOG_OUTPUT_ENTRY_SIZE + 16] = {0};

		if (redirect)
			print_kernel_log();

		cnt = logger_read_entry(reader, buf, sizeof(buf));

		if (cnt > 0) {
			void *p = logger_get_entry_payload((struct entry *)buf);
			int level = logger_get_entry_level((struct entry *)buf);
			if (redirect) {
				ALOG(LOG_INFO, "RTOS", "%s", (char *)p);
			} else {
				if (clormode)
					dprintf(log_fd, "%s""%s""%s", color_string[level], p, NONE);
				else
					dprintf(log_fd,"%s", p);
			}
		} else {
			usleep(500 * 1000);
		}
	}

	return 0;

out:
	log_err("%s exit ret = %d \n", argv[1], ret);
	/*
	 *todo: more error handler
	 */
	return -1;
}

