#define _GNU_SOURCE

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

#include "ar_icc.h"

#define DELAY 30*1000

struct recv_data_result
{
	unsigned int recv_cnt;
	
	unsigned int true_cnt;
};
typedef enum
{
    SINGLE_MSG_IN_ONE_CORE_SIM = 0x11,
	MSG_LINUX_TO_CEVA,
	MSG_CEVA_TO_LINUX,
    MAX_MSG_ID
} icc_test_msg_id_e;

static struct recv_data_result result[5] = {0};
static unsigned int send_cnt[5] = {0};
static int error_cnt = 0;
#define GET_TIMER_ID 0


void get_time_recv()
{
	int fd, ret, recv = -1;
	uint32_t send;
	struct timeval start;
	struct timeval end;
	unsigned long timer;  //US

	gettimeofday(&start, NULL);
	int buff[256];

	fd = ar_icc_open();
	if(fd < 0) {
		printf("recv, open icc fail %d\n", __LINE__);
		return;
	}

	ret = ar_icc_register_msgid(fd, 1);
	if(ret < 0) {
		printf("recv register msg id 1 fail\n");
		return 0;
	}

#define MSG_TEST_CEVA_TO_RTOS	(0x1236)
#define MSG_TEST_RTOS_TO_CEVA	(0x1237)

	ret = ar_icc_register_msgid(fd, MSG_TEST_CEVA_TO_RTOS);
	if(ret < 0) {
		printf("recv register msg id 1 fail\n");
		return 0;
	}

	ret = ar_icc_register_msgid(fd, MSG_TEST_RTOS_TO_CEVA);
	if(ret < 0) {
		printf("recv register msg id 1 fail\n");
		return 0;
	}

	send = 21;
	int count_group[13]={0};

	int ii=0;
	int jj=0;
	int low_num=0, high_num=0;
	int rec_error_times=0;

	unsigned int *p = (unsigned int *)buff;
	while(1)
	{
		gettimeofday(&start, NULL);

		ret = ar_icc_receive(fd, buff, 128, 1);
		if(ret < 0) {
			printf("receive msg id fail %d\n", ret);
			return 0;
		}

		ret = ar_icc_send(fd, buff, 8, 0, ICC_CORE_A_3);
		if(ret < 0) {
			printf("send msg id fail %d\n", ret);
			return;
		}



		gettimeofday(&end, NULL);
		timer = 1000000 *(end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
		printf("timer = %ld us\n", timer);

		low_num=5;
		high_num=15;
		if ((timer <= high_num)&&(timer >= low_num)) {
			count_group[timer-low_num+1] = count_group[timer-low_num+1] +1;
		}
		else if (timer < low_num) {
			count_group[0] = count_group[0] +1;
		}
		else if (timer > high_num) {
			count_group[12] = count_group[12] +1;
		}

		if((jj++) == 99)
		{
			printf("count_group is ");
			for(ii=0;ii<=12;ii++)
			{
				printf(" count[%d]=",ii+low_num-1);
				printf("%d ",count_group[ii]);
			}
			printf("\n ");
			printf("rec_error_times = %d\n", rec_error_times);
			jj = 0;
		}
	}
}

 void get_time()
{
	int fd, ret, recv = -1;
	int send;
	struct timeval start;
	struct timeval end;
	unsigned long timer;  //US
	gettimeofday(&start, NULL);
	fd = ar_icc_open();
	if(fd < 0) {
		printf("recv, open icc fail %d\n", __LINE__);
		return;
	}
	ret = ar_icc_register_msgid(fd, 1);
	if(ret < 0) {
		printf("recv register msg id 1 fail\n");
		return 0;
	}
	send = 10;
	ret = ar_icc_send(fd, &send, 4, GET_TIMER_ID, ICC_CORE_A_3);
	if(ret < 0) {
		printf("send msg id 0 fail\n");
		return;
	}
	ret = -1;
	while(ret < 0)
	{
		ret = ar_icc_receive(fd, &recv, 4, 1);
		if(ret < 0) {
			printf("receive msg id 0 fail\n");
			return 0;
		}
	}

	gettimeofday(&end, NULL);
	timer = 1000000 *(end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("timer = %ld us  recv:%d\n", timer, recv);
	send = 13;
	ret = -1;
	while(ret < 0)
	{
		ret = ar_icc_receive(fd, &recv, 4, 1);
		if(ret < 0) {
			printf("receive msg id 0 fail\n");
			return 0;
		}
	}
	ret = ar_icc_send(fd, &send, 4, GET_TIMER_ID, ICC_CORE_A_3);
	if(ret < 0) {
		printf("send msg id 0 fail\n");
		return;
	}
	printf("recv:%d\n", recv);
}

void send_and_receive_with_ceva()
{
	int fd, ret, recv = -1;
	int send;
	struct timeval start;
	struct timeval end;
	unsigned long timer;  //US
	unsigned long whole_timer;
	uint32_t cnt = 0;
	//gettimeofday(&start, NULL);
	fd = ar_icc_open();
	if(fd < 0) {
		printf("recv, open icc fail %d\n", __LINE__);
		return;
	}
	ret = ar_icc_register_msgid(fd, MSG_CEVA_TO_LINUX);
	if(ret < 0) {
		printf("recv register msg id 1 fail\n");
		return 0;
	}
	printf("get_time_recv_from_ceva\n");
	send = 10;
	while(1)
	{
	
		ret = ar_icc_send(fd, &send, 4, MSG_LINUX_TO_CEVA, ICC_CORE_CEVA_0);
		if(ret < 0) {
			printf("send msg id 0 fail\n");
			return;
		}else
		{
			printf("send success\n");
			send++;
		}
		//gettimeofday(&start, NULL);
		usleep(200);
		ret = ar_icc_receive(fd, &recv, 4, MSG_CEVA_TO_LINUX);
		if(ret < 0) {
			printf("receive msg id 0 fail\n");
			//return 0;
		}else{
			printf("receive msg user=%d\n",recv);
		}
	
	}

}

void handle_recv(void *arg, unsigned msg_id, unsigned int value)
{
	struct recv_data_result *result = arg;
	int fd, ret;
	int recv = -1;
	if(!result)
	{
		printf("recv arg is null!\n");
		return;
	}
	
	fd = ar_icc_open();
	if(fd < 0) {
		printf("recv, open icc fail %d\n", __LINE__);
		return;
	}
	ret = ar_icc_register_msgid(fd, msg_id);
	if(ret < 0) {
		printf("recv register msg id 0 fail\n");
		return 0;
	}
	while(1)
	{
		usleep(DELAY);
		ret = ar_icc_receive(fd, &recv, 4, msg_id);
		if(ret < 0) {
			printf("receive msg id 0 fail\n");
			return 0;
		}
		//printf("lqfeng---------->recv:%d \n", recv);
		//result->recv_cnt++;
		if(recv == value) {
			result->true_cnt++;
			//printf("value:%x  result->true_cnt:%x\n", recv, result->true_cnt);
		}
		else
			error_cnt++;
	}
}

void pthread_1_recv(void *arg)
{
	handle_recv(arg, 0, 0);
}

void pthread_2_recv(void *arg)
{
	handle_recv(arg, 1, 1);
}

void pthread_3_recv(void *arg)
{
	handle_recv(arg, 5, 5);
}

void pthread_4_recv(void *arg)
{
	handle_recv(arg, 6, 6);
}

void pthread_5_recv(void *arg)
{
	handle_recv(arg, 7, 7);
}

void hand_send(void *arg, unsigned int msg_id, unsigned int value)
{
	unsigned int *tmp = arg;
	int ret;
	//int send = 2;
	int fd;
	if(!tmp)
	{
		printf("send msg arg is null!\n");
		return;
	}

	fd = ar_icc_open();
	if(fd < 0) {
		printf("send open icc fail %d\n", __LINE__);
		return;
	}
	while(1) {
		usleep(DELAY);
		ret = ar_icc_send(fd, &value, 4, msg_id, ICC_CORE_A_3);
		if(ret < 0) {
			printf("send msg id 0 fail\n");
			return;
		}
		tmp++;
	}

}

void pthread_1_send(void *arg)
{
	printf("pthread_1_send arg :%x\n", *(unsigned int *)arg);
	hand_send(arg, 0, 0);
}

void pthread_2_send(void *arg)
{
	printf("pthread_2_send arg :%x\n", *(unsigned int *)arg);
	hand_send(arg, 1, 1);
}

void pthread_3_send(void *arg)
{
	printf("pthread_3_send arg :%x\n", *(unsigned int *)arg);
	hand_send(arg, 2, 2);
}

void pthread_4_send(void *arg)
{
	printf("pthread_3_send arg :%x\n", *(unsigned int *)arg);
	hand_send(arg, 3, 3);
}

void pthread_5_ceva_test(void *arg)
{
	//hbbai test ceva icc
	char msgdata[32] = "Hello from ARM0";
	char recvdata[32] = {0};
	unsigned int msqid = 0x1122;
	int fd = 0;
	int ret = 0;
	
	//send to ceva
	fd = ar_icc_open();
	if(fd < 0) 
	{
		printf("send open icc fail %d\n", __LINE__);
		return;
	}

	ret = ar_icc_register_msgid(fd, msqid);
	if(ret < 0) {
			printf("recv register msg id 0 fail\n");
			return 0;
	}

	usleep(DELAY);
	ret = ar_icc_send(fd, msgdata, sizeof(msgdata), msqid, ICC_CORE_CEVA_0);
	if(ret < 0) {
		printf("send msg id 0 fail\n");
		return;
	}
	
	ret = ar_icc_receive(fd, &recvdata, 32, msqid);
	if(ret < 0) {
		printf("receive msg id 0 fail\n");
		return 0;
	}

	printf("recv msg : \n");
	for(int i =0; i < 32; i++)
	{
		if(i%8 == 0)
			printf("\n");
		printf("%x ", recvdata[i]);
	}
	
	//printf("pthread_4_send arg :%x\n", *(unsigned int *)arg);
	//hand_send(arg, 4, 4);
}
#define LINUX_CEVA_ICC_TEST 1
int main(int argc, char *argv[])
{
	int i, ret, send, size, fd;
	int tmp;
	int recv;
	unsigned char *ptr_rx, *ptr_tx;
	
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	pthread_t t4;
	pthread_t t5;
	pthread_t t6;
	pthread_t t7;
	pthread_t t8;
	pthread_t t9;
	pthread_t t10;

	pthread_attr_t attr1, attr2, attr3, attr4, attr5;
	pthread_attr_t attr6, attr7, attr8, attr9, attr10;
	cpu_set_t cpu_info;
	
	pthread_attr_init(&attr1);
	pthread_attr_init(&attr2);
	pthread_attr_init(&attr3);
	pthread_attr_init(&attr4);
	pthread_attr_init(&attr5);
	pthread_attr_init(&attr6);
	pthread_attr_init(&attr7);
	pthread_attr_init(&attr8);
	pthread_attr_init(&attr9);
	pthread_attr_init(&attr10);
	
	CPU_ZERO(&cpu_info);

	CPU_SET(0, &cpu_info);

	printf("ok----->\n");
	//init arrt used in pthread

	if(0 != pthread_attr_setaffinity_np(&attr2, sizeof(cpu_set_t), &cpu_info))
	{
		printf("Set thread 2 affinity failed!\n");
		return -1;
	}	
	if(0 != pthread_attr_setaffinity_np(&attr3, sizeof(cpu_set_t), &cpu_info))
	{
		printf("Set thread 3 affinity failed!\n");
		return -1;
	}	
	if(0 != pthread_attr_setaffinity_np(&attr4, sizeof(cpu_set_t), &cpu_info))
	{
		printf("Set thread 4  affinity failed!\n");
		return -1;
	}
	if(0 != pthread_attr_setaffinity_np(&attr5, sizeof(cpu_set_t), &cpu_info))
	{
		printf("Set thread  5 affinity failed!\n");
		return -1;
	}
	if(0 != pthread_attr_setaffinity_np(&attr6, sizeof(cpu_set_t), &cpu_info))
	{
		printf("Set thread 1 affinity failed!\n");
		return -1;
	}
	if(0 != pthread_attr_setaffinity_np(&attr7, sizeof(cpu_set_t), &cpu_info))
	{
		printf("Set thread 2 affinity failed!\n");
		return -1;
	}	
	if(0 != pthread_attr_setaffinity_np(&attr8, sizeof(cpu_set_t), &cpu_info))
	{
		printf("Set thread 3 affinity failed!\n");
		return -1;
	}	
	if(0 != pthread_attr_setaffinity_np(&attr9, sizeof(cpu_set_t), &cpu_info))
	{
		printf("Set thread 4  affinity failed!\n");
		return -1;
	}	
	if(0 != pthread_attr_setaffinity_np(&attr10, sizeof(cpu_set_t), &cpu_info))
	{
		printf("Set thread  5 affinity failed!\n");
		return -1;
	}

	printf("pthread attr init ok!\n");

	if(0 != pthread_create(&t2, &attr2, get_time_recv, NULL))
	{
		printf("Create thread 2 failed!\n");
		return -1;
	}

	while(1)
	{
		sleep(1000);
	}
}
