#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <time.h>
#include <linux/spi/spidev.h>
#include <pthread.h>
#include <errno.h>
#include <sys/time.h>
static int find_pra_index_by_name(char *name,int argc, char *argv[])
{
    int i=0;
	for(i=0;i<argc;i++)
	{
         if(!strcmp(name,argv[i]))
         {
             return i;
         }
	}
	return 0;
}

static void pabort(const char *s)
{
	perror(s);
	abort();
}


static uint8_t mode = 0;
static uint8_t bits = 8;
static uint32_t speed = 10000000;
static uint16_t delay = 0;
static struct spi_ioc_transfer *spi_xfrs = NULL;
static int ntransfers = 0;
static int toggle_cs = 0;
static int block_length = 0;
static int quiet = 0;


char *spimasterwrite_arg[2] = {"/dev/spidev32766.0", "/local/usr/bin/aac_test.bin"};
char *spislaveread_arg[2] = {"/dev/spidev32765.0", "/local/usr/bin/aac_test_recieve.bin"};
char *spimasterread_arg[2] = {"/dev/spidev32766.0", "/local/usr/bin/aac_test_recieve.bin"};
char *spislavewrite_arg[2] = {"/dev/spidev32765.0", "/local/usr/bin/aac_test.bin"};

static void config_spi(int fd)
{
	int ret;

	ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
	if (ret == -1)
		pabort("can't set spi mode master");

	ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
	if (ret == -1)
		pabort("can't get spi mode master");

	/*
	 * bits per word
	 */
	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("can't set bits per word master");

	ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("can't get bits per word master");

	/*
	 * max speed hz
	 */
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("can't set max speed hz master");

	ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("can't get max speed hz master");

}

void spi_slave_read_thread(void *arg)
{
	uint32_t data_len =64*1024;
	int index;
	int fd_spislave = -1;
	size_t ret;
	int data_size = 0;

	unsigned char *buf = malloc(4*1024*1024 * sizeof(unsigned char));
	struct timeval tv;
	struct timezone tz;

	printf("spislave test func start-----\n");

	fd_spislave = open((char*)(*(char**)arg), O_RDWR);
	if(fd_spislave < 0)
	{
		printf("Open fd_spislave failed: %s\r: %s\r\n", strerror(errno), (char*)(*(char**)arg));
		return -1;
	}
	config_spi(fd_spislave);

	int fp = open((char*)(*((char**)arg+1)), O_RDWR|O_CREAT);
	if(!fp){
		printf("open file fail!!  %s line:%d\n", __func__, __LINE__);
		return;
	}

	while(1){
		read(fd_spislave, buf, data_len);

		//write(fp, buf, data_len);
		buf += data_len;

		data_size += data_len;

		printf("spislave has recieve datasize %d\n", data_size);

		if(data_size >= 4*1024*1024){
			printf("%s finish spislave recieve!!\n", (char*)(*((char**)arg+1)));
			fsync(fp);
			close(fp);
			//return;
			break;
		}
	}
	free(buf);
}

void spi_master_write_thread(void *arg)
{
	int fd_spimaster = 0;
	FILE * fp = 0;
	char * buf = 0;
	char * file_buffer = 0;
	int file_len = 0;
	int i = 0;
	int cnt = 0;
	int per_transmit_len = 64*1024;
	char * p_curr;
	printf("spimaster test func start-----\n");

	fd_spimaster = open((char*)(*(char**)arg), O_RDWR);
	if(fd_spimaster < 0)
	{
		printf("Open fd_spimaster failed: %s\r: %s\r\n", strerror(errno), (char*)(*(char**)arg));
		return -1;
	}
	config_spi(fd_spimaster);

	fp = fopen((char*)(*((char**)arg+1)), "ab+");
	if(!fp)
	{
		printf("open aac file failed: %s\r\n", strerror(errno));
		close(fd_spimaster);
		return -1;
	}

	fseek(fp, 0, SEEK_END);
	file_len = ftell(fp);
	rewind(fp);

	file_buffer = malloc(file_len);
	if(!file_buffer)
	{
		printf("Malloc buffer error!\r\n");
		return -1;
	}

	fread(file_buffer, 1, file_len, fp);
	fclose(fp);

	p_curr = file_buffer;

	//push to spimaster
	while(file_len > per_transmit_len)
	{
		write(fd_spimaster, p_curr, per_transmit_len);
		p_curr += per_transmit_len;
		file_len -= per_transmit_len;
		printf("spimaster remain to transmit datasize %d \n", file_len);
		usleep(10*1000);

	}
/*
	if(file_len)
	{
		write(fd_spimaster, p_curr, file_len);
		file_len -= file_len;
		printf("spimaster remain to transmit datasize %d \n", file_len);
	}
*/
	printf("%s finish spimaster transmit!!\n", (char*)(*((char**)arg+1)));

	close(fd_spimaster);
	fclose(fp);
	return 0;
}


void spi_master_read_thread(void *arg)
{
	uint32_t data_len =64*1024;
	int index;
	int fd_spimaster = -1;
	size_t ret;
	int data_size = 0;

	unsigned char *buf = malloc(data_len * sizeof(unsigned char));

	printf("spimaster test func start-----\n");

	fd_spimaster = open((char*)(*(char**)arg), O_RDWR);
	if(fd_spimaster < 0)
	{
		printf("Open fd_spimaster failed: %s\r: %s\r\n", strerror(errno), (char*)(*(char**)arg));
		return -1;
	}
	config_spi(fd_spimaster);

	int fp = open((char*)(*((char**)arg+1)), O_RDWR|O_CREAT);
	if(!fp){
		printf("open file fail!!  %s line:%d\n", __func__, __LINE__);
		return;
	}

	while(1){
		read(fd_spimaster, buf, data_len);

		write(fp, buf, data_len);

		data_size += data_len;

		printf("spimaster has recieve datasize %d\n", data_size);

		if(data_size >= 4*1024*1024){
			printf("%s finish spimaster recieve!!\n", (char*)(*((char**)arg+1)));
			fsync(fp);
			close(fp);
			//return;
			break;
		}
		usleep(10*1000);

	}
	free(buf);
}

void spi_slave_write_thread(void *arg)
{
	int fd_spislave = 0;
	FILE * fp = 0;
	char * buf = 0;
	char * file_buffer = 0;
	int file_len = 0;
	int i = 0;
	int cnt = 0;
	int per_transmit_len = 64*1024;
	char * p_curr;
	printf("spislave test func start-----\n");

	fd_spislave = open((char*)(*(char**)arg), O_RDWR);
	if(fd_spislave < 0)
	{
		printf("Open fd_spislave failed: %s\r: %s\r\n", strerror(errno), (char*)(*(char**)arg));
		return -1;
	}
	config_spi(fd_spislave);

	fp = fopen((char*)(*((char**)arg+1)), "ab+");
	if(!fp)
	{
		printf("open aac file failed: %s\r\n", strerror(errno));
		close(fd_spislave);
		return -1;
	}

	fseek(fp, 0, SEEK_END);
	file_len = ftell(fp);
	rewind(fp);

	file_buffer = malloc(file_len);
	if(!file_buffer)
	{
		printf("Malloc buffer error!\r\n");
		return -1;
	}

	fread(file_buffer, 1, file_len, fp);
	fclose(fp);

	p_curr = file_buffer;

	//push to spislave
	while(file_len > per_transmit_len)
	{
		write(fd_spislave, p_curr, per_transmit_len);
		p_curr += per_transmit_len;
		file_len -= per_transmit_len;
		printf("spislave remain to transmit datasize %d \n", file_len);

	}
/*
	if(file_len)
	{
		write(fd_spislave, p_curr, file_len);
		file_len -= file_len;
		printf("spislave remain to transmit datasize %d \n", file_len);
	}
*/
	printf("%s finish spislave transmit!!\n", (char*)(*((char**)arg+1)));

	close(fd_spislave);
	fclose(fp);
	return 0;
}

void spi_slave_duplex_thread(void *argw,void *argr)
{
	uint32_t per_transmit_len =64*1024;
	int index;
	int fd_spislave = -1;
	char * file_buffer = 0;
	int file_len = 0;
	char * p_curr;
	size_t ret;
	int data_size = 0;
	struct spi_ioc_transfer *xfr = malloc(sizeof(struct spi_ioc_transfer));
	unsigned char *bufr = NULL;

	printf("spislave duplex func start-----\n");

	fd_spislave = open((char*)(*(char**)argw), O_RDWR);
	if(fd_spislave < 0)
	{
		printf("Open fd_spislave failed: %s\r: %s\r\n", strerror(errno), (char*)(*(char**)argw));
		return -1;
	}
	config_spi(fd_spislave);

	int fpw = fopen((char*)(*((char**)argw+1)), "ab+");
	if(!fpw)
	{
		printf("open write file failed: %s\r\n", strerror(errno));
		close(fd_spislave);
		return -1;
	}


	int fpr = open((char*)(*((char**)argr+1)), O_RDWR|O_CREAT);
	if(!fpr){
		printf("open read file fail!!  %s line:%d\n", __func__, __LINE__);
		return;
	}

	fseek(fpw, 0, SEEK_END);
	file_len = ftell(fpw);
	bufr = malloc(file_len * sizeof(unsigned char));
	rewind(fpw);

	file_buffer = malloc(file_len);
	if(!file_buffer)
	{
		printf("Malloc buffer error!\r\n");
		return -1;
	}

	fread(file_buffer, 1, file_len, fpw);
	fclose(fpw);

	p_curr = file_buffer;

	while(file_len > per_transmit_len){
		xfr->tx_buf = (unsigned long)p_curr;
		xfr->rx_buf = (unsigned long)bufr;
		xfr->len = per_transmit_len;
		xfr->speed_hz = speed;
		xfr->delay_usecs = delay;
		xfr->bits_per_word = bits;
		xfr->cs_change =  toggle_cs;
		xfr->pad = 0;

		ret = ioctl(fd_spislave, SPI_IOC_MESSAGE(1), xfr);

		write(fpr, bufr, per_transmit_len);

		p_curr += per_transmit_len;
		file_len -= per_transmit_len;
		bufr += per_transmit_len;
		data_size += per_transmit_len;

		printf("spislave has xfer datasize %d\n", data_size);
		//break;
	}

	if(file_len)
	{
		xfr->tx_buf = (unsigned long)p_curr;
		xfr->rx_buf = (unsigned long)bufr;
		xfr->len = per_transmit_len;
		xfr->speed_hz = speed;
		xfr->delay_usecs = delay;
		xfr->bits_per_word = bits;
		xfr->cs_change =  toggle_cs;
		xfr->pad = 0;

		ret = ioctl(fd_spislave, SPI_IOC_MESSAGE(1), xfr);

		write(fpr, bufr, file_len);

		p_curr += file_len;
		file_len -= file_len;
		bufr += file_len;
		data_size += per_transmit_len;

		printf("spislave has xfer datasize %d\n", data_size);
	}

	printf("%s finish spislave xfer!!\n", (char*)(*((char**)argr+1)));
	fsync(fpr);
	close(fpr);
	free(bufr);
	free(xfr);
}

void spi_master_duplex_thread(void *argw,void *argr)
{
	uint32_t per_transmit_len =64*1024;
	int index;
	int fd_spimaster = -1;
	char * file_buffer = 0;
	int file_len = 0;
	char * p_curr;
	size_t ret;
	int data_size = 0;
	struct spi_ioc_transfer *xfr = malloc(sizeof(struct spi_ioc_transfer));
	unsigned char *bufr = NULL;

	printf("spimaster duplex func start-----\n");

	fd_spimaster = open((char*)(*(char**)argw), O_RDWR);
	if(fd_spimaster < 0)
	{
		printf("Open fd_spimaster failed: %s\r: %s\r\n", strerror(errno), (char*)(*(char**)argw));
		return -1;
	}
	config_spi(fd_spimaster);

	int fpw = fopen((char*)(*((char**)argw+1)), "ab+");
	if(!fpw)
	{
		printf("open write file failed: %s\r\n", strerror(errno));
		close(fd_spimaster);
		return -1;
	}


	int fpr = open((char*)(*((char**)argr+1)), O_RDWR|O_CREAT);
	if(!fpr){
		printf("open read file fail!!  %s line:%d\n", __func__, __LINE__);
		return;
	}

	fseek(fpw, 0, SEEK_END);
	file_len = ftell(fpw);
	bufr = malloc(file_len * sizeof(unsigned char));
	rewind(fpw);

	file_buffer = malloc(file_len);
	if(!file_buffer)
	{
		printf("Malloc buffer error!\r\n");
		return -1;
	}

	fread(file_buffer, 1, file_len, fpw);
	fclose(fpw);

	p_curr = file_buffer;

	while(file_len > per_transmit_len){

		xfr->tx_buf = (unsigned long)p_curr;
		xfr->rx_buf = (unsigned long)bufr;
		xfr->len = per_transmit_len;
		xfr->speed_hz = speed;
		xfr->delay_usecs = delay;
		xfr->bits_per_word = bits;
		xfr->cs_change =  toggle_cs;
		xfr->pad = 0;

		ret = ioctl(fd_spimaster, SPI_IOC_MESSAGE(1), xfr);

		write(fpr, bufr, per_transmit_len);

		p_curr += per_transmit_len;
		file_len -= per_transmit_len;
		bufr += per_transmit_len;
		data_size += per_transmit_len;

		printf("spimaster has xfer datasize %d\n", data_size);
		//break;
		usleep(1000*1000);
	}

	if(file_len)
	{
		xfr->tx_buf = (unsigned long)p_curr;
		xfr->rx_buf = (unsigned long)bufr;
		xfr->len = per_transmit_len;
		xfr->speed_hz = speed;
		xfr->delay_usecs = delay;
		xfr->bits_per_word = bits;
		xfr->cs_change =  toggle_cs;
		xfr->pad = 0;

		ret = ioctl(fd_spimaster, SPI_IOC_MESSAGE(1), xfr);

		write(fpr, bufr, file_len);

		p_curr += file_len;
		file_len -= file_len;
		bufr += file_len;
		data_size += per_transmit_len;

		printf("spimaster has xfer datasize %d\n", data_size);
	}

	printf("%s finish spimaster xfer!!\n", (char*)(*((char**)argr+1)));
	fsync(fpr);
	close(fpr);
	free(bufr);
	free(xfr);

}


int spi_slave_read_func()
{
	spi_slave_read_thread((void *)spislaveread_arg);
	return 0;
}

int spi_master_write_func()
{
	spi_master_write_thread((void *)spimasterwrite_arg);
	return 0;
}

int spi_slave_write_func()
{
	spi_slave_write_thread((void *)spislavewrite_arg);
	return 0;
}

int spi_master_read_func()
{
	spi_master_read_thread((void *)spimasterread_arg);
	return 0;
}

int spi_slave_duplex_func()
{
	spi_slave_duplex_thread((void *)spislavewrite_arg, (void *)spislaveread_arg);
	return 0;
}

int spi_master_duplex_func()
{
	spi_master_duplex_thread((void *)spimasterwrite_arg, (void *)spimasterread_arg);
	return 0;
}

int main(int argc, char *argv[])
{
	int index;
	int ret;
	index = find_pra_index_by_name("-mw",argc,argv);
	if(index>0)
	{
		ret = spi_master_write_func();
		return 0;
	}

	index = find_pra_index_by_name("-sr",argc,argv);
	if(index>0)
	{
		ret = spi_slave_read_func();
		return 0;
	}

	index = find_pra_index_by_name("-mr",argc,argv);
	if(index>0)
	{
		ret = spi_master_read_func();
		return 0;
	}

	index = find_pra_index_by_name("-sw",argc,argv);
	if(index>0)
	{
		ret = spi_slave_write_func();
		return 0;
	}

	index = find_pra_index_by_name("-sd",argc,argv);
	if(index>0)
	{
		ret = spi_slave_duplex_func();
		return 0;
	}

	index = find_pra_index_by_name("-md",argc,argv);
	if(index>0)
	{
		ret = spi_master_duplex_func();
		return 0;
	}

	return 0;
}
