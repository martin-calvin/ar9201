#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <errno.h>
#include <pthread.h>
#include <sched.h>
#include <signal.h>
#include <sys/types.h>

#include "pipe_transfer_framework.h"

#include "uvc_service2.h"

//#define MAX_BUFFER_SIZE         (1000 * 1024)
//#define __IPC_KEY__             0x1234

int main()
{
	int 		ret;
	int 		len = 50 * 1024;
	void 		* share_mem;
	transfer_id     trans_id;

	ret = user_data_shr_mem_create(__IPC_CEVA_KEY__, MAX_BUFFER_SIZE, __IPC_CEVA_BUF_NUM__, &trans_id);
	if(ret < 0)
	{
		printf("share memory create failed!\n");
	}

	while(1)
	{
		ret = user_data_shr_mem_get_ptr(trans_id, &share_mem, len, 0);
		if(ret >= 0)
		{
			printf("share_mem: %p\n", share_mem);
			memset((unsigned char *)share_mem, 0x5a, len);
			printf("send buffer %d\n", len);
			user_data_shr_mem_send(&trans_id, &share_mem);
		}
		else
		{
			//printf("get buffer failed %d\n", ret);
		}

		usleep(50 * 1000);
	}
}
