

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <libspi_seic.h>


#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

#define GPIO_CS 19
#define GPIO_VKEY 64
#define OUTPUT 1
#define INPUT 0
#define T0 200
#define T1 20
#define T2 30
#define T3 100
#define T4 20
#define T5 30
#define T6 5*1000
#define T7 500*1000

#define RESERVE 0
#define DATA_LEN 8

#define MAX_DATA_SIZE 255

static uint16_t delay = 0;
static struct spi_ioc_transfer *spi_xfrs = NULL;
static int ntransfers = 0;
static int toggle_cs = 0;
static int block_length = 0;
static int quiet = 0;


typedef struct {
	unsigned char class;
	unsigned char ins;
	unsigned char p1;
	unsigned char p2;
	unsigned char lc;
	unsigned char data[MAX_DATA_SIZE];
	unsigned char le;
} command_t;


static void config_spi_and_gpio(void)
{
	init_spi_and_gpio();
}

static int test_reset_seic(void)
{
	int ret = cmd_reset_seic(NULL);
	if(ret){
		printf("reset ret = %d\n", ret);
		return 1;
	}
	return 0;
}

static int test_atr_seic(void)
{
	int ret = cmd_rats_seic(NULL);
	if(ret){
		printf("reset ret = %d\n", ret);
		return 1;
	}
	return 0;
}


static int test_ecb_enc(unsigned char* msg, unsigned int msg_len,unsigned char* output, unsigned int* output_len)
{
	unsigned int p1 = 0;
	unsigned int p2 = 0;
	unsigned int out_len = 0;
	unsigned int off = 0;
	unsigned char* buffer = NULL;
	unsigned char* resbuf = NULL;
	unsigned int buffer_len = 0;
	int ret;
	command_t* command_data = NULL;
/*
	printf("enc msg: ");
	for(int i= 0;i < msg_len;i++)
		printf("%02x ", msg[i]);
	printf("\n");
*/
	command_data = (command_t*)malloc(sizeof(command_t));
	if(command_data == NULL){
		return 1;
	}
	buffer = (unsigned char*)malloc((0x105)*sizeof(unsigned char));
	if(!buffer){
		return 2;
	}
	resbuf = (unsigned char*)malloc((0x105)*sizeof(unsigned char));
	if(!resbuf){
		free(buffer);
		return 2;
	}
	buffer[0] = 0x51;
	buffer[1] = 0x01;
	buffer[2] = 0x01;
	while(msg_len > 240){
		if(p1 == 0){
			buffer[3] = ((msg_len) >> 8) & 0xff;
			buffer[4] = (msg_len) & 0xff;
			memcpy(buffer + 5, msg + (p1 * 240), 0xf0);
			buffer_len = 245;
		}
		else{
			memcpy(buffer, msg + (p1 * 240), 0xf0);
			buffer_len = 240;
		}
		command_data->class = 0x80;
		command_data->ins = 0xf6;
		command_data->p1 = p1;
		command_data->p2 = p2;
		command_data->lc = buffer_len;
		memcpy(command_data->data, buffer, buffer_len);
		command_data->le = 0 & 0xff;
		ret = cmd_transmit_seic(NULL, command_data, command_data->lc + 5, resbuf, &out_len);
		if(ret){
			printf("cmd_transmit_seic ret = %d\n", ret);
			free(buffer);
			free(resbuf);
			return 1;
		}
		msg_len -= 240;

		if(p1 == 0){
			memcpy(output, resbuf, out_len - 2);
		}
		else{
			memcpy(output + off, resbuf, out_len - 2);

		}
		off += out_len - 2;
		p1++;
	}
	p2 = 1;
	if(p1 == 0){
		buffer[3] = ((msg_len) >> 8) & 0xff;
		buffer[4] = (msg_len) & 0xff;
		memcpy(buffer + 5, msg + (p1 * 240), msg_len);
		buffer_len = msg_len + 5;
	}
	else{
		memcpy(buffer, msg + (p1 * 240), msg_len);
		buffer_len = msg_len;
	}
/*
	printf("enc buffer: ");
	for(int i= 0;i < buffer_len;i++)
		printf("%02x ", buffer[i]);
	printf("\n");
*/
	command_data->class = 0x80;
	command_data->ins = 0xf6;
	command_data->p1 = p1;
	command_data->p2 = p2;
	command_data->lc = buffer_len;
	memcpy(command_data->data, buffer, buffer_len);
	command_data->le = 0 & 0xff;
	ret = cmd_transmit_seic(NULL, command_data, command_data->lc + 5, resbuf, &out_len);
	if(ret){
		printf("cmd_transmit_seic ret = %d\n", ret);
		free(buffer);
		free(resbuf);
		return 1;
	}

	memcpy(output + off, resbuf, out_len - 2);
	*output_len = off + out_len - 2;
/*
	printf("enc output: ");
	for(int i= 0;i < *(output_len);i++)
		printf("%02x ", output[i]);
	printf("\n");
*/

	free(buffer);
	free(resbuf);
	return 0;
}

static int test_ecb_dec(unsigned char* msg, unsigned int msg_len,unsigned char* output, unsigned int* output_len)
{
	unsigned int p1 = 0;
	unsigned int p2 = 0;
	unsigned int out_len = 0;
	unsigned int off = 0;
	unsigned char* buffer = NULL;
	unsigned char* resbuf = NULL;
	unsigned int buffer_len = 0;
	int ret;
	command_t* command_data = NULL;
	command_data = (command_t*)malloc(sizeof(command_t));
	if(command_data == NULL){
		return 1;
	}
	buffer = (unsigned char*)malloc((0x105)*sizeof(unsigned char));
	if(!buffer){
		return 2;
	}
	resbuf = (unsigned char*)malloc((0x105)*sizeof(unsigned char));
	if(!resbuf){
		free(buffer);
		return 2;
	}

/*
	printf("dec msg: ");
	for(int i= 0;i < msg_len;i++)
		printf("%02x ", msg[i]);
	printf("\n");
*/
	buffer[0] = 0x52;
	buffer[1] = 0x01;
	buffer[2] = 0x01;
	while(msg_len > 240){
		if(p1 == 0){
			buffer[3] = ((msg_len) >> 8) & 0xff;
			buffer[4] = (msg_len) & 0xff;
			memcpy(buffer + 5, msg + (p1 * 240), 0xf0);
			buffer_len = 245;
		}
		else{
			memcpy(buffer, msg + (p1 * 240), 0xf0);
			buffer_len = 240;
		}
		command_data->class = 0x80;
		command_data->ins = 0xf6;
		command_data->p1 = p1;
		command_data->p2 = p2;
		command_data->lc = buffer_len;
		memcpy(command_data->data, buffer, buffer_len);
		command_data->le = 0 & 0xff;

		ret = cmd_transmit_seic(NULL, command_data, command_data->lc + 5, resbuf, &out_len);
		if(ret){
			printf("cmd_transmit_seic ret = %d\n", ret);
			free(buffer);
			free(resbuf);
			return 1;
		}
		msg_len -= 240;

		if(p1 == 0){
			memcpy(output, resbuf, out_len - 2);
		}
		else{
			memcpy(output + off, resbuf, out_len - 2);

		}
		off += out_len - 2;
		p1++;
	}
	p2 = 1;

	if(p1 == 0){
		buffer[3] = ((msg_len) >> 8) & 0xff;
		buffer[4] = (msg_len) & 0xff;
		memcpy(buffer + 5, msg + (p1 * 240), 0xf0);
		buffer_len = msg_len + 5;
	}
	else{
		memcpy(buffer, msg + (p1 * 240), 0xf0);
		buffer_len = msg_len;
	}
/*
	printf("dec buffer: ");
	for(int i= 0;i < buffer_len;i++)
		printf("%02x ", buffer[i]);
	printf("\n");
*/
	command_data->class = 0x80;
	command_data->ins = 0xf6;
	command_data->p1 = p1;
	command_data->p2 = p2;
	command_data->lc = buffer_len;
	memcpy(command_data->data, buffer, buffer_len);
	command_data->le = 0 & 0xff;

	ret = cmd_transmit_seic(NULL, command_data, command_data->lc + 5, resbuf, &out_len);
	if(ret){
		printf("cmd_transmit_seic ret = %d\n", ret);
		free(buffer);
		free(resbuf);
		return 1;
	}

	memcpy(output + off, resbuf, out_len - 2);
	*output_len = off + out_len - 2;
/*
	printf("dec output: ");
	for(int i= 0;i < *(output_len);i++)
		printf("%02x ", output[i]);
	printf("\n");
*/
	free(buffer);
	free(resbuf);
	return 0;

}

static void test_ecb_seic(char* argv[])
{
	unsigned char* msg = NULL;
	unsigned int msg_len = 0;
	unsigned char* enc_msg = NULL;
	unsigned int enc_msg_len = NULL;
	unsigned char* dec_msg = NULL;
	unsigned int dec_msg_len = NULL;
	unsigned int i;
	unsigned int test_time = 0;
	unsigned int wrong_data = 0;
	unsigned int wrong_len = 0;
	unsigned int wrong_call_enc = 0;
	unsigned int wrong_call_dec = 0;
	int ret;

	msg_len = atoi(argv[2]);
	printf("msg_len %d\n",msg_len);
	while(1){
		//msg_len = rand() % 1024;
		msg_len = msg_len - msg_len % 8;
		printf("-------------------------------------------------------------------------\n");
		printf("time %d, msglen %d, lenwrong %d, datawrong %d, callencwrong %d, calldecwrong %d\n", test_time++, msg_len, wrong_len, wrong_data, wrong_call_enc, wrong_call_dec);
		msg = malloc(msg_len);
		if(!msg){
			printf("msg malloc failed!\n");
			continue;
		}
		enc_msg = malloc(msg_len);
		if(!enc_msg){
			printf("enc_msg malloc failed!\n");
			continue;
		}
		dec_msg = malloc(msg_len);
		if(!dec_msg){
			printf("dec_msg malloc failed!\n");
			continue;
		}

		for(i = 0;i < msg_len; i++){
			msg[i] = rand() % 256;
		}
		if(test_ecb_enc(msg, msg_len, enc_msg, &enc_msg_len)){
			wrong_call_enc ++;
			free(msg);
			continue;
		}
		if(test_ecb_dec(enc_msg, enc_msg_len, dec_msg, &dec_msg_len)){
			wrong_call_dec ++;
			free(msg);
			continue;
		}
		if(dec_msg_len != enc_msg_len){
			printf("wrong len! msg_len = %d, dec_msg_len = %d\n", msg_len, dec_msg_len);
			wrong_len ++;
			free(msg);
			continue;
		}
		for(i = 0; i < msg_len; i++){
			if(msg[i] != dec_msg[i]){
				printf("wrong data! msg[%d] = %02x, dec_msg[%d] = %02x\n", i, msg[i], i, dec_msg[i]);
				wrong_data ++;
				break;
			}
		}
		free(msg);
		free(enc_msg);
		free(dec_msg);
	}


}

static void parse_opts(int argc, char *argv[])
{
		static const struct option lopts[] = {
			{ "config",  0, 0, 'c' },
			{ "reset",   0, 0, 'r' },
			{ "atr",   0, 0, 'a' },
			{ "ecb",     0, 0, 'e' },
			{ NULL, 0, 0, 0 },
		};
		int c;

		c = getopt_long(argc, argv, "crae", lopts, NULL);

		if (c == -1)
			return;

		switch (c) {
		case 'c':
				config_spi_and_gpio();
				break;
		case 'r':
				test_reset_seic();
				break;
		case 'a':
				test_atr_seic();
				break;
		case 'e':
				test_ecb_seic(argv);
				break;
		default:
			break;
		}
}


int main(int argc, char *argv[])
{
	parse_opts(argc, argv);
	return 0;
}
