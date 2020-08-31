#define _GNU_SOURCE
#define HAVE_SYS_UIO_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <sched.h>
#include <termios.h>
#include <log/log.h>

int dump_fd = -1;
int fd_mem = -1;
unsigned char *dsp_msg_shared_buffer = NULL;
static volatile unsigned int *lock;
static volatile unsigned int *tx_idx;
static volatile unsigned int *dsp_inited_flag;
static volatile unsigned int *linux_inited_flag;
static volatile unsigned int *write_finish;
static volatile char *dspmsg; //128K -128,每个msg 128字节，总共可以存放1023个msg
static unsigned int rx_idx = 0;
static unsigned int received_msg_cnt = 0;

int dump_to_file = 0;
int redirect = 0;
char filename[128] = {0,};
#define LENGTH_FOR_EACH_LOG         (256)
#define MAX_MSG_IDX 2046
#define FILE_NAME_SIZE 4096
#define PRINT_BUFFER_ADDR   (0x85400000)
//#define PRINT(x,...) printf(x, ##__VA_ARGS__)
#define PRINT(x,...) 
void dump_dsp_msg()
{
	unsigned int tx;
	unsigned int v;
	int i, ret;
	char *p;

	tx = *tx_idx;
	if (tx > MAX_MSG_IDX) {
		printf("[proxy] dsp msg buffer abnormal tx_idx %d\n", tx);
		return;
	}


	PRINT("1tx %d\n", tx);


	for (i = 0; i < 4; i++) {
		v = *(write_finish + i);
		if (v != 0 && v != 1) {
			printf("[proxy] dsp msg buffer abnormal write_finish+%d=%d\n", i, v);
			return;
		}
		if (v == 0) { //某个核还在往内存写
			PRINT("@@\n");
			return; //fix，如果有前后2条消息，其中一条完成，一条未完成，没法判断是哪条未完成，等下一次再打
		}
	}
	if (tx == rx_idx) //认为是没有数据更新，而不是绕了一圈
		return;

	//dsp先tx_idx++,再往原来tx_idx写，这里要减1
	if (tx == 0)
		tx = MAX_MSG_IDX;
	else
		tx--;

	PRINT("2tx %d\n", tx);
	//tx DSP发送到哪里，rx_idx，linux接收到哪里
	//linux从上次处理完的idx开始处理，中间DSP可以覆盖

	if (tx >= rx_idx) {
		for (i = rx_idx; i <= tx; i++) {
			p = dspmsg + LENGTH_FOR_EACH_LOG * i;
			//todo 如果dsp跳过一条消息，该buffer未被清0，dump_dspmsg永远在这里返回
			if (p[LENGTH_FOR_EACH_LOG - 1] != 0) {
				PRINT("1possible? i %d p[127] = %d\n", i, p[LENGTH_FOR_EACH_LOG - 1]);
				return;
			}
			//printf("%s\n", dspmsg + 128 * i);
			if (redirect) {
				ALOG(LOG_INFO, "DSP", "%s", (char *)(dspmsg + LENGTH_FOR_EACH_LOG * i));
			} else if (dump_fd != -1) {
				ret = write(dump_fd, dspmsg + LENGTH_FOR_EACH_LOG * i, strlen(dspmsg + LENGTH_FOR_EACH_LOG * i));
				if (ret < 0)
					PRINT("write ret %d\n", ret);
			}
			p[LENGTH_FOR_EACH_LOG - 1] = 57;
		}

	} else {
		//rx_idx -> 1022
		for (i = rx_idx; i <= MAX_MSG_IDX; i++) {
			p = dspmsg + LENGTH_FOR_EACH_LOG * i;
			if (p[LENGTH_FOR_EACH_LOG - 1] != 0) {
				PRINT("2possible? i %d p[255] = %d\n", i, p[LENGTH_FOR_EACH_LOG - 1]);
				return;
			}
			//printf("%s\n", dspmsg + 128 * i);
			if (redirect) {
				ALOG(LOG_INFO, "DSP", "%s", (char *)(dspmsg + LENGTH_FOR_EACH_LOG * i));
			} else if (dump_fd != -1) {
				ret = write(dump_fd, dspmsg + LENGTH_FOR_EACH_LOG * i, strlen(dspmsg + LENGTH_FOR_EACH_LOG * i));
				if (ret < 0)
					PRINT("write ret %d\n", ret);
			}
			p[LENGTH_FOR_EACH_LOG - 1] = 57;
		}
		//0 ->tx_idx
		for (i = 0; i <= tx; i++) {
			p = dspmsg + LENGTH_FOR_EACH_LOG * i;
			if (p[LENGTH_FOR_EACH_LOG - 1] != 0) {
				PRINT("3possible? i %d p[255] = %d\n", i, p[LENGTH_FOR_EACH_LOG - 1]);
				return;
			}
			//printf("%s\n", dspmsg + 128 * i);
			if (redirect) {
				ALOG(LOG_INFO, "DSP", "%s", (char *)(dspmsg + LENGTH_FOR_EACH_LOG * i));
			} else if (dump_fd != -1) {
				ret = write(dump_fd, dspmsg + LENGTH_FOR_EACH_LOG * i, strlen(dspmsg + LENGTH_FOR_EACH_LOG * i));
				if (ret < 0)
					PRINT("write ret %d\n", ret);
			}
			p[LENGTH_FOR_EACH_LOG - 1] = 57;
		}
	}
	rx_idx = tx + 1; //下次从tx+1开始处理
	if (rx_idx > MAX_MSG_IDX)
		rx_idx = 0;

}

static void usage()
{
	printf("\n");
	printf("Usage:\n");
	printf("Examples:\n");
	printf("  dump_dspmsg -m 0 -f /dev/ttyS1 -a print_addr\n");
	printf("  dump_dspmsg -m 1 -f /mnt/uhost/log.txt -a print_addr\n");
	printf("Options:\n");
	printf("  -m mode                         0=dump to serial 1=dump to file\n");
	printf("  -f filename                     \n");
	printf("  -a print_addr                   \n");
	printf("\n");
	exit(0);
}

int main(int argc, char *argv[])
{
	struct termios opt;
	int ret;
	int c;
	int val;
	unsigned int pa_addr = PRINT_BUFFER_ADDR;

	while((c = getopt(argc,argv,"m:f:a:r")) != -1){
		switch(c){
		case 'f':
			strncpy(filename, optarg, 128);
			break;
		case 'm':
			val = atoi(optarg);
			if(val==0){
				dump_to_file = 0;
			} else if (val == 1) {
				dump_to_file = 1;
			} else
				usage();
			break;
		case 'a':	
			if(!argv[6])
				pa_addr = atoi(argv[6]);			
			break;
		case 'r':
			redirect = 1;
			break;
		default:
			usage();
			break;
		}
	}

	if (argc < 5 && !redirect)
		usage();

	if (redirect) {
		printf("redirect dsp log to system log\n");
	} else if (dump_to_file == 0) {
		dump_fd = open(filename, O_RDWR|O_NOCTTY);
		if (dump_fd == -1) {
			printf("fail to open %s\n", filename);
			return 0;
		}

		tcgetattr(dump_fd, &opt);
		cfsetispeed(&opt, B115200);
		cfsetospeed(&opt, B115200);
		ret = tcsetattr(dump_fd, TCSANOW, &opt);
		printf("tcsetattr ret %d\n", ret);

	} else {
		dump_fd = open(filename, O_RDWR|O_CREAT|O_SYNC);
		if (dump_fd == -1) {
			printf("fail to open %s\n", filename);
			return 0;
		}
	}

	fd_mem=open("/dev/mem", O_RDWR | O_SYNC);
	dsp_msg_shared_buffer = mmap(NULL,512*1024,PROT_READ|PROT_WRITE,MAP_SHARED,fd_mem, pa_addr);
	printf("dsp_msg_shared_buffer %x\n", dsp_msg_shared_buffer);
	lock = dsp_msg_shared_buffer;
	tx_idx = dsp_msg_shared_buffer+4;
	dsp_inited_flag = dsp_msg_shared_buffer+8;
	linux_inited_flag = dsp_msg_shared_buffer+12;
	write_finish = dsp_msg_shared_buffer+16;
	dspmsg = dsp_msg_shared_buffer + 256; //512K -256,每个msg 128字节，总共可以存放1023个msg
	*linux_inited_flag = 0x12345678;

	while(1)
	{
		dump_dsp_msg();
		usleep(5000);
	}
}
