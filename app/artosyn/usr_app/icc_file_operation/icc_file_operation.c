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

#define  get_thread_id()  ((uint32_t)pthread_self())

typedef enum
{
	MSG_CEVA_WITH_LINUX_FOPS_0 = 0X1238,
	MSG_CEVA_WITH_LINUX_FOPS_1,
	MSG_CEVA_WITH_LINUX_FOPS_2,
	MSG_CEVA_WITH_LINUX_FOPS_3,
	MSG_FREERTOS_WITH_LINUX_FOPS,
	MSG_FOPS_MAX
} icc_test_msg_id_e;

typedef enum{
	FAILED = 0,
	OPEN_FILE,
	GET_FILE_LEN,
	READ_FILE,
	WRITE_FILE,
	CLOSE_FILE,
	ALLOC,
	FREE,
	DSP_GET_IMAGE_INIT,
	LINUX_GET_DSP_RES_INIT,
	DSP_GET_IMG_PROC,
	DSP_RELEASE_IMG,
	DSP_GET_IMAGE_DEINIT,
	DSP_YOLO_OUTP_DISP,
	DSP_YOLO_OUTP_DISP_INSTALL,
	MAX_DSP_PROXY_TYPE,
	LINUX_GET_DSP_RES
}memssage_type;

enum {
	MEMORY_IS_CACHED = 1,
	MEMORY_IS_NONCACHED,
	MEMORY_IS_UNKWOWN,
};

unsigned int get_file_size(int fd)
{
	struct stat stbuf;
	fstat(fd, &stbuf);
	return stbuf.st_size;
}


//#define LINUX_CEVA_SYNC_BASE (0x30140000)
//#define LINUX_CEVA_FOPS_REG_OFFSET  (0x1C)
#define FILE_NAME_SIZE 4096

void ceva_file_operation_process(void * arg)
{
	int fd_mem, fd_write, fd,file_fd,flag,ret,recv = -1;
	unsigned int msg[6],file_name_address,file_size,file_address,read_size,write_size;
	unsigned char *file_name,*buf_address,*map_address;
	int msg_id, dst_core_id;
	int core_id;
	if(!arg){
		printf("arg is NULL!! line:%d\n", __LINE__);
		return;
	}
	core_id = *(int *)arg;
	if(core_id < 4){
		msg_id = MSG_CEVA_WITH_LINUX_FOPS_0 + core_id;
		dst_core_id = ICC_CORE_CEVA_0 + core_id;
		printf("CEVA file ops task, core %d msg id %d\n", core_id, msg_id);
		fd_mem=open("/dev/mem", O_RDWR | O_SYNC);
	}
	else if(4 == core_id){
		msg_id = MSG_FREERTOS_WITH_LINUX_FOPS;
		dst_core_id = ICC_CORE_A_3;
		printf("freeRtos file ops task, core %d msg id 0x%x\n", core_id, msg_id);
		fd_mem=open("/dev/mem", O_RDWR);
	}
	else{
		printf("core is error! line:%d\n", __LINE__);
		return;
	}

	if(fd_mem < 0){
		printf("open /dev/mem fail line:%d\n", __LINE__);
		return;
	}

	fd = ar_icc_open();
	if(fd < 0) {
		printf("open icc fail %d\n", __LINE__);
		return;
	}
	ret = ar_icc_register_msgid(fd, msg_id);
	if(ret < 0) {
		printf("recv register msg id fail\n");
		return;
	}

	//msg[0]=MAX_DSP_PROXY_TYPE;
	//ar_icc_send(fd, (unsigned char *)&msg, sizeof(unsigned int)*6, MSG_LINUX_TO_FREERTOS, ICC_CORE_A_3);

	//tell ceva that we're ready for file ops

    //ar_ceva_mmapset_reg(AR_DSP_LINUX_FS_RDY_ID, 'A');

	while(1)
	{
		memset(msg, 0, sizeof(msg));

		ret=ar_icc_receive(fd, (unsigned char *)msg, sizeof(unsigned int)*6, msg_id);
		if(ret < 0)
		{
			//printf("receive msg id %d fail\n", msg_id);
			//return 0;
		}
		else
		{   //printf("[%x] file ops=%d\n",get_thread_id(),msg[0]);
			switch(msg[0])
			{
			case OPEN_FILE:
				file_name_address=msg[2];
				file_name_address = file_name_address & (~(FILE_NAME_SIZE - 1));
				map_address = mmap(NULL,FILE_NAME_SIZE*2,PROT_READ | PROT_WRITE,MAP_SHARED,fd_mem,file_name_address);
				file_name=map_address+(msg[2] & (FILE_NAME_SIZE - 1));//for data alignment
				flag=msg[3];
				file_fd=open(file_name,flag);
				msg[2]=file_fd;
				//printf("[%x] OPen file:%s fd %d\n", get_thread_id(),file_name,file_fd);
				ar_icc_send(fd, (unsigned char *)msg, sizeof(unsigned int)*6, msg_id, dst_core_id);
				munmap(map_address,FILE_NAME_SIZE*2);
				break;
			case GET_FILE_LEN:
				file_fd=msg[2];
				msg[2]=get_file_size(file_fd);
				//printf("[%x]Get file len: fd %d len=%d\n", get_thread_id(),file_fd,msg[2]);
				ar_icc_send(fd, (unsigned char *)msg, sizeof(unsigned int)*6, msg_id, dst_core_id);
				break;
			case READ_FILE:
				file_size = msg[3];
				file_address = msg[4];
				map_address = mmap(NULL,(file_size/4096+2)*4096,PROT_READ | PROT_WRITE,MAP_SHARED,fd_mem,file_address&(~(FILE_NAME_SIZE - 1)));
				buf_address=map_address+(file_address & (FILE_NAME_SIZE - 1));
				file_fd = msg[2];
				if (file_fd > 0)
					read_size = read(file_fd,buf_address,file_size);
				msg[2] = read_size;

				//printf("[%x]Read file: fd %d read_size=%d req_size=%d\n",get_thread_id(), file_fd,read_size,file_size);
				ar_icc_send(fd, (unsigned char *)msg, sizeof(unsigned int)*6, msg_id, dst_core_id);
				munmap(map_address,(file_size/4096+2)*4096);
				break;
			case WRITE_FILE:
				file_size = msg[3];
				file_address = msg[4];
				if (core_id == 4) {
					if (msg[5] == MEMORY_IS_CACHED)
						fd_write=open("/dev/mem", O_RDWR);
					else if (msg[5] == MEMORY_IS_NONCACHED)
						fd_write=open("/dev/mem", O_RDWR | O_SYNC);
					else {
						//printf("ar_write use unknown memory type\n");
						break;
					}

					if(fd_write < 0){
						//printf("open /dev/mem fail line:%d\n", __LINE__);
						break;
					}
					map_address = mmap(NULL,(file_size/4096+2)*4096,PROT_READ | PROT_WRITE,MAP_SHARED,fd_write,file_address&(~(FILE_NAME_SIZE - 1)));
				} else
					map_address = mmap(NULL,(file_size/4096+2)*4096,PROT_READ | PROT_WRITE,MAP_SHARED,fd_mem,file_address&(~(FILE_NAME_SIZE - 1)));

				buf_address=map_address+(file_address & (FILE_NAME_SIZE - 1));
				file_fd = msg[2];
				if (file_fd > 0)
					write_size = write(file_fd,buf_address,file_size);
				msg[2] = write_size;

				//printf("[%x]write file: fd %d write_size=%d,req_size=%d",get_thread_id(),file_fd,write_size,file_size);
				ar_icc_send(fd, (unsigned char *)msg, sizeof(unsigned int)*6, msg_id, dst_core_id);
				munmap(map_address,(file_size/4096+2)*4096);
				close(fd_write);
				break;
			case CLOSE_FILE:
				file_fd = msg[2];
				msg[2] = close(file_fd);
				//printf("[%x]close file: fd %d\n",get_thread_id(), file_fd);
				ar_icc_send(fd, (unsigned char *)msg, sizeof(unsigned int)*6, msg_id, dst_core_id);
				file_fd = -1;
				break;

			default:
				//printf("receive error\n");
				break;
			}
		}
	}

}

int main(int argc, char *argv[])
{
	pthread_t thread[5];
	pthread_attr_t attr1;
	cpu_set_t cpu_info;
	int i = 0;
	// 4 is freeRtos core_id, 0 is ceva0 core_id, 1 is ceva1 core_id, 2 is ceva2 core_id, 3 is ceva3 core_id,
	int core_id[5] = {0,1,2,3,4};

	pthread_attr_init(&attr1);
	CPU_ZERO(&cpu_info);
	CPU_SET(0, &cpu_info);
	//init arrt used in pthread
	if(0 != pthread_attr_setaffinity_np(&attr1, sizeof(cpu_set_t), &cpu_info))
	{
		printf("Set thread 1 affinity failed!\n");
		return -1;
	}

	for(i = 0; i < 5; i++)
	{
		if(0 != pthread_create(&thread[i], NULL, ceva_file_operation_process, &core_id[i]))
		{
			printf("Create thread %d failed!\n", core_id[i]);
			return -1;
		}
		printf("ceva file operation thread %d create\n", core_id[i]);
	}

	while(1)
	{
		sleep(1);
	}
}
