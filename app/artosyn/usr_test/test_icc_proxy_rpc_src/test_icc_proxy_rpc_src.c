#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "icc_proxy_rpc_to_freertos.h"
#include "ar_media_buffer_proxy.h"

#define BUF_SIZE 1024*8
#define BUF_NUM  8
#define READ_UNIT 8192
#if 0
static int flag = 0;
static char *buf_head;
int main(int argc, char **argv)
{
	//struct buf_info buf;
	char *buf;
	int data_size = 0;
	int fd = -1;
	int ret;
	fd = open("/dev/icc_proxy_rpc_src-0", O_RDWR);
	FILE *fp = NULL;
	if (fd < 0){
		printf("open /dev/icc_proxy failed!\n");
		return -1;
	}
	fp = fopen("/tmp/in.wav", "ab+");
	printf("line:%d\n", __LINE__);
	if (fp < 0){
		printf("open /dev/icc_proxy failed!\n");
		return -1;
	}
	if(icc_proxy_rpc_init(fd, BUF_SIZE, BUF_NUM)){
		printf("rpc init fail!!\n");
		goto err;
	}
	printf("line:%d\n", __LINE__);
	while(1){
		if(icc_proxy_rpc_acquire_buffer(fd, &buf)){
			printf("acquire_buffer fail!!\n");
			goto err;
		}
		data_size = fread(buf, 1, READ_UNIT, fp);
		if(data_size != READ_UNIT){
			fclose(fp);
			printf("send over!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		}
		icc_proxy_rpc_push_buffer(fd, buf, data_size);
		usleep(1000*30);
	}

err:
    close(fd);
	icc_proxy_rpc_linux_exit(fd);
    return 0;
}
#endif
int main(int argc, char **argv)
{
	//struct buf_info buf;
	ar_buffer_proxy_handle_t handle = NULL;
    ar_buffer_proxy_buffer_t* buffer = NULL;
	int ret;
	FILE *fp = NULL;
    ar_buffer_proxy_params_t params = {0};
    handle = ar_media_buffer_proxy_open("/dev/icc_proxy_rpc_src-0");
	if (!handle){
		printf("open /dev/icc_proxy failed!\n");
		return -1;
	}
	fp = fopen("/mnt/test", "ab+");
	printf("line:%d\n", __LINE__);
	if (fp < 0){
		printf("open /dev/icc_proxy failed!\n");
		return -1;
	}

    params.buffer_nr = 10;
    params.planar_nr = 1;
    params.planar_align = 1024;
    params.planar_size[0] = 10*1024;

    ret = ar_media_buffer_proxy_set_params(handle, &params);
	if(ret != 0){
		printf("rpc init fail!!\n");
		goto err;
	}
    ar_media_buffer_proxy_set_remote_keep_buffer_nr(handle, 5);
	printf("line:%d\n", __LINE__);
    int count = 0;
	while(1){
        buffer = ar_media_buffer_proxy_acquire_buffer(handle);
        if(!buffer) {
            printf("acquire buffer failed.");
            sleep(1);
            continue;
        }
        buffer->mem[0].used = READ_UNIT;
		//buffer->mem[0].used= fread(buffer->mem[0].addr, 1, READ_UNIT, fp);
		if(buffer->mem[0].used != READ_UNIT){
            buffer->mem[0].used = 0;
            ar_media_buffer_proxy_put_buffer(handle, buffer);
			printf("send over!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            goto err;
		}
		ar_media_buffer_proxy_put_buffer(handle, buffer);
        count++;
		sleep(1);
        if(count > 10)
            break;
	}
 	ar_media_buffer_proxy_close(handle);
    fclose(fp);
    printf("done \n");
    while(1) {
        sleep(1);
    }
    return 0;
err:
	ar_media_buffer_proxy_close(handle);
    fclose(fp);
    return 0;
}
