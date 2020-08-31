#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "libremote_spi.h"
#include <pthread.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>
#include "v4ar_dev.h"

#define SPI_MAX_DEV 8

remote_stru_spi_dev_data* spi_dev_data = NULL;
enum {
	SPI_RPC_MASTER_XFER = 0,
};

unsigned int remote_spi_open(const char *name)
{
	if(!name) {
		printf("{%d:%s} [error] Invalid device name, it is NULL \n", __LINE__, __FUNCTION__);
		return 0;
	}
	unsigned int fd = open(name, O_RDWR | O_SYNC);
	if(NULL == fd)
	{
		printf("{%d:%s} [error] to open %s \n", __LINE__, __FUNCTION__, name);
		return 0;
	}

	spi_dev_data = malloc(sizeof(remote_stru_spi_dev_data));
	if(NULL == spi_dev_data)
	{
		printf("{%d:%s} [error] spi_dev_data create\n", __LINE__, __FUNCTION__);
		return 0;
	}
	pthread_mutex_init(&spi_dev_data->m_mutex_lock, NULL);

	return fd;
}

int remote_spi_close(unsigned int fd)
{
	if(0 == fd) {
		printf("{%d:%s} [error] Invalid fd 0x%x \n", __LINE__, __FUNCTION__, fd);
		return -1;
	}

	pthread_mutex_destroy(&spi_dev_data->m_mutex_lock);
	free(spi_dev_data);

	close(fd);

	return 0;

}

int remote_spi_master_xfer(unsigned int fd, spi_rpc_xfer_t* spi_rpc_xfer)
{
	int ret;
	int ret_lock = pthread_mutex_lock(&spi_dev_data->m_mutex_lock);
	if(ret_lock) {
		printf("{%d:%s} [error] mutex lock fail 0x%x\n",__LINE__,__FUNCTION__,ret_lock);
		return -1;
	}

	if(0 == fd) {
		printf("{%d:%s} [error] Invalid fd 0x%x \n", __LINE__, __FUNCTION__, fd);
		return -1;
	}

	v4ar_common_ctl_ext_t ctl = {0};
	ctl.ctl_code = SPI_RPC_MASTER_XFER,
	ctl.len = sizeof(spi_rpc_xfer_t);
	ctl.data = spi_rpc_xfer;

	ret = ioctl(fd, VIDIOC_V4AR_DEV_COMMON_CTL_EXT, &ctl);

	ret_lock = pthread_mutex_unlock(&spi_dev_data->m_mutex_lock);
	if(0 != ret_lock)
	{
		printf("{%d:%s} [error] mutex unlock fail 0x%x\n",__LINE__,__FUNCTION__,ret_lock);
		return -1;
	}

	return ret;
}


