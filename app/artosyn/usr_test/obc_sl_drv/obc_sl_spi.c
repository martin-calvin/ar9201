#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <mtd/mtd-user.h>
#include "ar_log.h"
#include <sys/mman.h>
#include <time.h>
#include "backtrace.h"
#include "Mx6300.h"
#include "libremote_spi.h"
#include "obc_sl_spi.h"
#include "flash_data_types.h"
#include "obrefparser.h"
#define MX6300_SENSOR_ID 0x6300
#define MX6300_FIRMWARE_ADDR 0x00
#define MX6300_RECTIFYREG_ADDR 0x10000
#define MX6300_REFERENCE_ADDR 0x800000
#define MX6300_CMD_ID_FAST_READ 0x0B
#define MX6300_CMD_ID_PAGE_PROGRAM 0x02
#define MX6300_CMD_ID_STATUS 0x05
#define MX6300_CMD_ID_SENSOR_ID 0x90
#define MX6300_BASE_ADDR 0xC0
#define MX6300_STATUS_ADDR 0xC4
#define MX6300_DEV_ID_ADDR 0x0
#define MX6300_FW_VER_ADDR 0x2

#define AHB_ADDR_FLOOR 0x50000000
#define AHB_ADDR_CEIL 0x5001D000
#define MX6300_INIT_OK 18
//0->mx6300,1->flash
#define MX6300_DEV 0
#define FLASH_DEV 1
unsigned int gspi_fd;
pthread_mutex_t gspi_lock = PTHREAD_MUTEX_INITIALIZER;
back_trace_t *back_trace;
spi_context_t gp_context = {0};
uint32_t MX6300_base_addr;
uint32_t MX6300_status;
int current_devtype = -1;
#define DEVICE_CONFIG_ADDR 0x10000
#define DISTORTION_PARAMS_ADDR 0x20000
#define CONFIG_VALID_ADDR 0x30000
#define SOFT_D2C_PARAMS_ADDR 0x60000
#define REFERENCE_ADDR 0x80000

#define FIRMWARE_FILE_SIZE 64 * 1024
#define REFERENCE_FILE_SIZE 500 * 1024
char *config_file = "/factory/doraemon/config.bin";
char *distortion_d2c4x3 = "/factory/doraemon/distortion_d2c4x3.bin";
char *d2c_16x9 = "/factory/doraemon/d2c_16x9.bin";
char *reference_file = "/factory/doraemon/reference.bin";
static char *firmware_file = "firmware.bin";

static const uint8_t crc_table[] =
	{
		0x00, 0x31, 0x62, 0x53, 0xc4, 0xf5, 0xa6, 0x97, 0xb9, 0x88, 0xdb, 0xea, 0x7d, 0x4c, 0x1f, 0x2e,
		0x43, 0x72, 0x21, 0x10, 0x87, 0xb6, 0xe5, 0xd4, 0xfa, 0xcb, 0x98, 0xa9, 0x3e, 0x0f, 0x5c, 0x6d,
		0x86, 0xb7, 0xe4, 0xd5, 0x42, 0x73, 0x20, 0x11, 0x3f, 0x0e, 0x5d, 0x6c, 0xfb, 0xca, 0x99, 0xa8,
		0xc5, 0xf4, 0xa7, 0x96, 0x01, 0x30, 0x63, 0x52, 0x7c, 0x4d, 0x1e, 0x2f, 0xb8, 0x89, 0xda, 0xeb,
		0x3d, 0x0c, 0x5f, 0x6e, 0xf9, 0xc8, 0x9b, 0xaa, 0x84, 0xb5, 0xe6, 0xd7, 0x40, 0x71, 0x22, 0x13,
		0x7e, 0x4f, 0x1c, 0x2d, 0xba, 0x8b, 0xd8, 0xe9, 0xc7, 0xf6, 0xa5, 0x94, 0x03, 0x32, 0x61, 0x50,
		0xbb, 0x8a, 0xd9, 0xe8, 0x7f, 0x4e, 0x1d, 0x2c, 0x02, 0x33, 0x60, 0x51, 0xc6, 0xf7, 0xa4, 0x95,
		0xf8, 0xc9, 0x9a, 0xab, 0x3c, 0x0d, 0x5e, 0x6f, 0x41, 0x70, 0x23, 0x12, 0x85, 0xb4, 0xe7, 0xd6,
		0x7a, 0x4b, 0x18, 0x29, 0xbe, 0x8f, 0xdc, 0xed, 0xc3, 0xf2, 0xa1, 0x90, 0x07, 0x36, 0x65, 0x54,
		0x39, 0x08, 0x5b, 0x6a, 0xfd, 0xcc, 0x9f, 0xae, 0x80, 0xb1, 0xe2, 0xd3, 0x44, 0x75, 0x26, 0x17,
		0xfc, 0xcd, 0x9e, 0xaf, 0x38, 0x09, 0x5a, 0x6b, 0x45, 0x74, 0x27, 0x16, 0x81, 0xb0, 0xe3, 0xd2,
		0xbf, 0x8e, 0xdd, 0xec, 0x7b, 0x4a, 0x19, 0x28, 0x06, 0x37, 0x64, 0x55, 0xc2, 0xf3, 0xa0, 0x91,
		0x47, 0x76, 0x25, 0x14, 0x83, 0xb2, 0xe1, 0xd0, 0xfe, 0xcf, 0x9c, 0xad, 0x3a, 0x0b, 0x58, 0x69,
		0x04, 0x35, 0x66, 0x57, 0xc0, 0xf1, 0xa2, 0x93, 0xbd, 0x8c, 0xdf, 0xee, 0x79, 0x48, 0x1b, 0x2a,
		0xc1, 0xf0, 0xa3, 0x92, 0x05, 0x34, 0x67, 0x56, 0x78, 0x49, 0x1a, 0x2b, 0xbc, 0x8d, 0xde, 0xef,
		0x82, 0xb3, 0xe0, 0xd1, 0x46, 0x77, 0x24, 0x15, 0x3b, 0x0a, 0x59, 0x68, 0xff, 0xce, 0x9d, 0xac};

uint8_t cal_crc_table(uint8_t *ptr, uint32_t len)
{
	uint8_t crc = 0x00;

	while (len--)
	{
		crc = crc_table[crc ^ *ptr++];
	}
	return crc;
}
static void delay_ms(int ms)
{
	usleep(ms * 1000);
}

uint32_t get_mx6300_aligned_addr(uint32_t tgt_address, uint8_t *align_offset)
{
	*align_offset = tgt_address % 4;
	return MX6300_base_addr + (tgt_address - *align_offset);
}

int mx6300_raw_cmd_rx(uint32_t code, uint32_t *pdata)
{
	int ret;
	uint32_t recive_data = 0;
	uint32_t offset_addr = MX6300_base_addr + 0xF8;

	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TR;
	spi_xfer_param.txlen = 10;
	spi_xfer_param.rxlen = 10;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_FAST_READ;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 0;
	spi_xfer_param.txbuf[7] = 0;
	spi_xfer_param.txbuf[8] = 0;
	spi_xfer_param.txbuf[9] = 0;
	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (0 != ret)
	{
		printf("%s failed(code=0x%x, ret = %d)\n", __func__, code, ret);
		return ret;
	}
	recive_data = (spi_xfer_param.rxbuf[9] << 24) + (spi_xfer_param.rxbuf[8] << 16) + (spi_xfer_param.rxbuf[7] << 8) + spi_xfer_param.rxbuf[6];

	printf("raw cmd recv data: %#x\r\n", recive_data);
	*pdata = recive_data;
	return ret;
}
int mx6300_raw_cmd_set_start(uint32_t code)
{
	int ret;
	int recive_data = 0;
	uint32_t offset_addr = MX6300_base_addr + 0xF0;

	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 8;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 1;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 2;
	spi_xfer_param.txbuf[7] = 0;
	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (0 != ret)
	{
		printf("%s failed(code=0x%x, ret = %d)\n", __func__, code, ret);
		return ret;
	}
	// recive_data = (spi_xfer_param.rxbuf[3] << 24) + (spi_xfer_param.rxbuf[2] << 16) + (spi_xfer_param.rxbuf[1] << 8) + spi_xfer_param.rxbuf[0];

	//printf("raw cmd recv data: %#x\r\n", recive_data);
	return 0;
}
int obc_spi_read_mx6300_raw_cmd(uint32_t code, uint32_t *pdata)
{
	int ret;
	uint32_t offset_addr = MX6300_base_addr + 0xF0;

	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 12;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 0;
	spi_xfer_param.txbuf[7] = 0;
	spi_xfer_param.txbuf[8] = code & 0xFF;
	spi_xfer_param.txbuf[9] = (code & 0xFF00) >> 8;
	spi_xfer_param.txbuf[10] = 0;
	spi_xfer_param.txbuf[11] = 0;

	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (0 != ret)
	{
		printf("%s failed(code=0x%x, ret = %d)\n", __func__, code, ret);
		return 0;
	}
	delay_ms(10);
	//recive_data = (spi_xfer_param.rxbuf[14] << 24) + (spi_xfer_param.rxbuf[13] << 16) + (spi_xfer_param.rxbuf[12] << 8) + spi_xfer_param.rxbuf[11];
	mx6300_raw_cmd_set_start(code);
	delay_ms(10);
	return mx6300_raw_cmd_rx(code, pdata);
}

int obc_spi_write_mx6300_raw_cmd(uint32_t code, uint32_t data)
{
	int ret = 0;

	uint32_t offset_addr = MX6300_base_addr + 0xF0;
	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 16;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 4;
	spi_xfer_param.txbuf[7] = 0;
	spi_xfer_param.txbuf[8] = code & 0xFF;
	spi_xfer_param.txbuf[9] = (code & 0xFF00) >> 8;
	spi_xfer_param.txbuf[10] = 0;
	spi_xfer_param.txbuf[11] = 0;
	spi_xfer_param.txbuf[15] = (data & 0xFF000000) >> 24;
	spi_xfer_param.txbuf[14] = (data & 0xFF0000) >> 16;
	spi_xfer_param.txbuf[13] = (data & 0xFF00) >> 8;
	spi_xfer_param.txbuf[12] = data & 0xFF;

	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (ret != 0)
	{
		printf("%s failed(code=0x%x,data=0x%x, ret = %d)\n", __func__, code, data, ret);
		return ret;
	}
	delay_ms(1);
	mx6300_raw_cmd_set_start(code);
	delay_ms(1);
	return ret;
}
int obc_spi_write_ldp_calibrate_data(uint8_t *pdata)
{
	int ret = 0;
	uint32_t offset_addr = MX6300_base_addr + 0xF0;
	uint8_t data[16];
	uint32_t code = MX6300_RAW_CMD_LDP_CALIBRATE;
	memcpy(data, pdata, 16);
	//start calibrate
	obc_spi_control(MX6300_DEV);
	spi_rpc_xfer_t spi_xfer_param;

	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 16;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 4;
	spi_xfer_param.txbuf[7] = 0;
	spi_xfer_param.txbuf[8] = code & 0xFF;
	spi_xfer_param.txbuf[9] = (code & 0xFF00) >> 8;
	for (int i = 0; i < 4; i++)
	{
		//int i=0;
		spi_xfer_param.txbuf[10] = 0x21 + i;
		spi_xfer_param.txbuf[11] = 0;
		spi_xfer_param.txbuf[12] = data[i * 4];
		spi_xfer_param.txbuf[13] = data[i * 4 + 1];
		spi_xfer_param.txbuf[14] = data[i * 4 + 2];
		spi_xfer_param.txbuf[15] = data[i * 4 + 3];

		ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
		if (ret != 0)
		{
			printf("%s failed(code=0x%x,data=0x%x, ret = %d)\n", __func__, code, data, ret);
			return ret;
		}
		delay_ms(1);
		mx6300_raw_cmd_set_start(code);
		delay_ms(50);
	}

	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 12;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 4;
	spi_xfer_param.txbuf[7] = 0;
	spi_xfer_param.txbuf[8] = code & 0xFF;
	spi_xfer_param.txbuf[9] = (code & 0xFF00) >> 8;
	spi_xfer_param.txbuf[10] = 0x20;
	spi_xfer_param.txbuf[11] = 0;
	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (ret != 0)
	{
		printf("%s failed(code=0x%x,data=0x%x, ret = %d)\n", __func__, code, ret);
		return ret;
	}
	delay_ms(2);
	mx6300_raw_cmd_set_start(code);
	delay_ms(5);
	return ret;
}
int obc_save_ldp_params(uint8_t *ldp_param)
{
	//write to local file
	int ret;
	FILE *fp = fopen(config_file, "wb");
	if (fp == NULL)
	{
		printf("open %s Failed\n", config_file);
		return -1;
	}
	DeviceConfig config = {0};
	fread(&config, 1, sizeof(config), fp);
	uint32_t ldp_crc = cal_crc_table(ldp_param, 16);
	printf("ldp_crc=0x%x", ldp_crc);
	config.ldp_crc = ldp_crc;
	memcpy(config.ldp_params, ldp_param, 16);
	fwrite(&config, 1, sizeof(config), fp);
	fclose(fp);
	system("sync");
	//write to flash
	obc_spi_control(FLASH_DEV);
	ret = obc_sl_spi_read_flash(DEVICE_CONFIG_ADDR, &config, sizeof(DeviceConfig));
	if (ret < 0)
	{
		printf("%s:read config failed\n", __FUNCTION__);
		return -1;
	}
	memcpy(config.ldp_params, ldp_param, 16);
	ret = obc_sl_spi_write_flash(DEVICE_CONFIG_ADDR, &config, sizeof(DeviceConfig));
	if (ret < 0)
	{
		printf("%s:write config failed\n", __FUNCTION__);
		return -1;
	}
	ConfigValidFlag configValid = {0};
	spi_ctrl_msg ctrl_msg = {0};
	ctrl_msg.spi_fd = gspi_fd;
	ctrl_msg.dev_type = SPI_DEV_FLASH;
	ctrl_msg.regaddr = CONFIG_VALID_ADDR;
	ctrl_msg.pdata = &configValid;
	ctrl_msg.dataLen = sizeof(ConfigValidFlag);
	ret = obc_sl_spi_read(&ctrl_msg);
	if (ret < 0)
	{
		printf("%s:read config valid flag failed\n", __FUNCTION__);
		return -1;
	}
	configValid.ldp_valid = VALUE_VALID;
	ret = obc_sl_spi_write(&ctrl_msg);
	if (ret < 0)
	{
		printf("%s:write config valid flag failed\n", __FUNCTION__);
		return -1;
	}
	return 0;
}
int obc_spi_set_ldp_calibrate(uint32_t code, uint32_t pdata)
{
	int ret = 0;

	uint32_t offset_addr = MX6300_base_addr + 0xF0;
	uint8_t data[16];
	//start calibrate
	spi_rpc_xfer_t spi_xfer_param;

	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 12;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 4;
	spi_xfer_param.txbuf[7] = 0;
	spi_xfer_param.txbuf[8] = code & 0xFF;
	spi_xfer_param.txbuf[9] = (code & 0xFF00) >> 8;
	spi_xfer_param.txbuf[10] = 0x10;
	spi_xfer_param.txbuf[11] = 0;
	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (ret != 0)
	{
		printf("%s failed(code=0x%x,data=0x%x, ret = %d)\n", __func__, code, ret);
		return ret;
	}
	delay_ms(1);
	mx6300_raw_cmd_set_start(code);
	delay_ms(5000);
	//start to read data
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 12;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 4;
	spi_xfer_param.txbuf[7] = 0;
	spi_xfer_param.txbuf[8] = code & 0xFF;
	spi_xfer_param.txbuf[9] = (code & 0xFF00) >> 8;
	spi_xfer_param.txbuf[11] = 0;
	spi_xfer_param.txbuf[15] = 0;
	spi_xfer_param.txbuf[14] = 0;
	spi_xfer_param.txbuf[13] = 0;
	spi_xfer_param.txbuf[12] = 0;
	for (int i = 0; i < 4; i++)
	{
		spi_xfer_param.txbuf[10] = 0x11 + i;
		ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
		if (ret != 0)
		{
			printf("%s failed(code=0x%x,data=0x%x, ret = %d)\n", __func__, code, data, ret);
			return ret;
		}
		delay_ms(1);
		mx6300_raw_cmd_set_start(code);
		delay_ms(10);
		mx6300_raw_cmd_rx(code, data + i * 4);
	}
	//start to read data
	for (int j = 0; j < 16; j++)
	{
		printf("calib data[%d]=0x%x\n", j, data[j]);
	}
	ret = obc_save_ldp_params(data);
	if (ret < 0)
	{
		printf("save ldp calibration params failed\n");
	}
	return ret;
}
int mx6300_ahb_rx(uint32_t code, uint32_t *pdata)
{
	int ret;
	uint32_t recive_data = 0;
	uint32_t offset_addr = MX6300_base_addr + 0x78;

	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TR;
	spi_xfer_param.txlen = 10;
	spi_xfer_param.rxlen = 10;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_FAST_READ;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 0;
	spi_xfer_param.txbuf[7] = 0;
	spi_xfer_param.txbuf[8] = 0;
	spi_xfer_param.txbuf[9] = 0;
	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (0 != ret)
	{
		printf("%s failed(code=0x%x, ret = %d)\n", __func__, code, ret);
		return ret;
	}
	recive_data = (spi_xfer_param.rxbuf[9] << 24) + (spi_xfer_param.rxbuf[8] << 16) + (spi_xfer_param.rxbuf[7] << 8) + spi_xfer_param.rxbuf[6];

	printf("ahb recv data: %#x\r\n", recive_data);
	*pdata = recive_data;
	return ret;
}
int mx6300_ahb_set_start(uint32_t code, int rw)
{
	int ret;
	int recive_data = 0;
	uint32_t offset_addr = MX6300_base_addr + 0x70;

	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 8;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 1;
	spi_xfer_param.txbuf[5] = 0;
	if (rw)
	{
		spi_xfer_param.txbuf[6] = 1;
	}
	else
	{
		spi_xfer_param.txbuf[6] = 0;
	}

	spi_xfer_param.txbuf[7] = 4;
	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (0 != ret)
	{
		printf("%s failed(code=0x%x, ret = %d)\n", __func__, code, ret);
		return ret;
	}
	// recive_data = (spi_xfer_param.rxbuf[3] << 24) + (spi_xfer_param.rxbuf[2] << 16) + (spi_xfer_param.rxbuf[1] << 8) + spi_xfer_param.rxbuf[0];

	//printf("raw cmd recv data: %#x\r\n", recive_data);

	return 0;
}
int obc_spi_write_mx6300_ahb(uint32_t addr, uint32_t data)
{
	int ret = 0;

	uint32_t offset_addr = MX6300_base_addr + 0x70;
	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 16;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 1;
	spi_xfer_param.txbuf[7] = 4;
	spi_xfer_param.txbuf[8] = addr & 0xFF;
	spi_xfer_param.txbuf[9] = (addr & 0xFF00) >> 8;
	spi_xfer_param.txbuf[10] = (addr & 0xFF0000) >> 16;
	spi_xfer_param.txbuf[11] = (addr & 0xFF000000) >> 24;

	spi_xfer_param.txbuf[15] = (data & 0xFF000000) >> 24;
	spi_xfer_param.txbuf[14] = (data & 0xFF0000) >> 16;
	spi_xfer_param.txbuf[13] = (data & 0xFF00) >> 8;
	spi_xfer_param.txbuf[12] = data & 0xFF;

	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (ret != 0)
	{
		printf("%s failed(code=0x%x,data=0x%x, ret = %d)\n", __func__, addr, data, ret);
		return ret;
	}
	delay_ms(1);
	mx6300_ahb_set_start(addr, 0);
	delay_ms(1);
	return ret;
}
int obc_spi_read_mx6300_ahb(uint32_t addr, uint32_t *pdata)
{
	int ret;
	uint32_t offset_addr = MX6300_base_addr + 0x70;
	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 12;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 1;
	spi_xfer_param.txbuf[7] = 4;
	spi_xfer_param.txbuf[8] = addr & 0xFF;
	spi_xfer_param.txbuf[9] = (addr & 0xFF00) >> 8;
	spi_xfer_param.txbuf[10] = (addr & 0xFF0000) >> 16;
	spi_xfer_param.txbuf[11] = (addr & 0xFF000000) >> 24;
	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (0 != ret)
	{
		printf("%s failed(code=0x%x, ret = %d)\n", __func__, addr, ret);
		return ret;
	}
	mx6300_ahb_set_start(addr, 1);
	delay_ms(10);
	return mx6300_ahb_rx(addr, pdata);
}

int mx6300_i2c_rx(uint32_t slave_addr, int len, uint32_t *pdata)
{
	int ret;
	uint32_t recive_data = 0;
	uint32_t offset_addr = MX6300_base_addr + 0x94;
	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TR;
	spi_xfer_param.txlen = 10;
	spi_xfer_param.rxlen = 10;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_FAST_READ;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 0;
	spi_xfer_param.txbuf[7] = 0;
	spi_xfer_param.txbuf[8] = 0;
	spi_xfer_param.txbuf[9] = 0;
	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (0 != ret)
	{
		printf("%s failed(code=0x%x, ret = %d)\n", __func__, slave_addr, ret);
		return ret;
	}
	if (len == 2)
	{
		recive_data = (spi_xfer_param.rxbuf[8] << 8) + (spi_xfer_param.rxbuf[9]);
	}
	else
	{
		recive_data = spi_xfer_param.rxbuf[8];
	}

	printf("i2c recv data: %#x\r\n", recive_data);
	*pdata = recive_data;
	return ret;
}
int mx6300_i2c_set_start(uint8_t reg_len, uint8_t data_len, int rw)
{
	int ret;
	int recive_data = 0;
	uint32_t offset_addr = MX6300_base_addr + 0x90;

	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 8;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 1;
	spi_xfer_param.txbuf[5] = 0;
	if (rw)
	{
		spi_xfer_param.txbuf[6] = 1;
		spi_xfer_param.txbuf[7] = data_len;
	}
	else
	{
		spi_xfer_param.txbuf[6] = 0;
		spi_xfer_param.txbuf[7] = reg_len + data_len;
	}

	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (0 != ret)
	{
		printf("%s failed(ret = %d)\n", __func__, ret);
		return ret;
	}
	return ret;
}
int obc_spi_write_mx6300_i2c(uint8_t bus, uint8_t slave_addr, uint32_t reg, uint8_t reg_len, uint32_t data, uint8_t data_len)
{
	int ret = 0;

	uint32_t offset_addr = MX6300_base_addr + 0x90;
	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 16;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 0;

	spi_xfer_param.txbuf[7] = reg_len + data_len;
	spi_xfer_param.txbuf[8] = bus;
	spi_xfer_param.txbuf[9] = slave_addr & 0xFF;
	spi_xfer_param.txbuf[10] = 0;
	spi_xfer_param.txbuf[11] = 0;
	spi_xfer_param.txbuf[12] = 0;
	spi_xfer_param.txbuf[13] = 0;
	spi_xfer_param.txbuf[14] = 0;
	spi_xfer_param.txbuf[15] = 0;
	if (reg_len == 1)
	{
		spi_xfer_param.txbuf[10] = reg & 0xFF;
		if (data_len == 1)
		{
			spi_xfer_param.txbuf[11] = data & 0xFF;
		}
		else if (data_len == 2)
		{
			spi_xfer_param.txbuf[11] = (data & 0xFF00) >> 8;
			spi_xfer_param.txbuf[12] = data & 0xFF;
		}
	}
	else if (reg_len == 2)
	{
		spi_xfer_param.txbuf[11] = reg & 0xFF;
		spi_xfer_param.txbuf[10] = (reg & 0xFF00) >> 8;
		if (data_len == 1)
		{
			spi_xfer_param.txbuf[12] = data & 0xFF;
		}
		else if (data_len == 2)
		{
			spi_xfer_param.txbuf[12] = (data & 0xFF00) >> 8;
			spi_xfer_param.txbuf[13] = data & 0xFF;
		}
	}

	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (ret != 0)
	{
		printf("%s failed(code=0x%x,data=0x%x, ret = %d)\n", __func__, slave_addr, data, ret);
		return ret;
	}
	delay_ms(1);
	mx6300_i2c_set_start(reg_len, data_len, 0);
	delay_ms(1);
	return ret;
}
uint32_t obc_spi_read_mx6300_i2c(uint8_t bus, uint8_t slave_addr, uint32_t reg, uint8_t reg_len, uint32_t *data, uint8_t data_len)
{
	int ret = 0;

	uint32_t offset_addr = MX6300_base_addr + 0x90;
	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 12;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 1;
	spi_xfer_param.txbuf[7] = data_len;
	spi_xfer_param.txbuf[8] = bus;
	spi_xfer_param.txbuf[9] = slave_addr & 0xFF;
	spi_xfer_param.txbuf[10] = 0;
	spi_xfer_param.txbuf[11] = 0;

	ret = obc_spi_write_mx6300_i2c(bus, slave_addr, reg, reg_len, 0, 0);
	if (0 != ret)
	{
		printf("%s failed(code=0x%x, ret = %d,data_len=0)\n", __func__, slave_addr, ret);
		return ret;
	}
	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (0 != ret)
	{
		printf("%s failed(code=0x%x, ret = %d)\n", __func__, slave_addr, ret);
		return ret;
	}
	//recive_data = (spi_xfer_param.rxbuf[14] << 24) + (spi_xfer_param.rxbuf[13] << 16) + (spi_xfer_param.rxbuf[12] << 8) + spi_xfer_param.rxbuf[11];
	mx6300_i2c_set_start(0, data_len, 1);
	delay_ms(10);
	return mx6300_i2c_rx(slave_addr, data_len, data);
	// printf("raw cmd recv data: %#x\r\n", recive_data);
}
///////////////////////////////////////////////////////////////////
uint32_t obc_spi_read_mx6300_align_register(unsigned int addr)
{
	int ret = 0;
	uint32_t recive_data = 0;
	uint8_t align_offset = 0;
	uint32_t offset_addr = get_mx6300_aligned_addr(addr & 0xFFFF, &align_offset);
	printf("addr=0x%x,offset_addr=0x%x\n", addr, offset_addr);

	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TR;
	spi_xfer_param.txlen = 10;
	spi_xfer_param.rxlen = 10;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_FAST_READ;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 0;
	spi_xfer_param.txbuf[7] = 0;
	spi_xfer_param.txbuf[8] = 0;
	spi_xfer_param.txbuf[9] = 0;

	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (0 != ret)
	{
		printf("%s failed(addr=0x%x, ret = %d)\n", __func__, addr, ret);
		return ret;
	}
	recive_data = (spi_xfer_param.rxbuf[6] << 24) + (spi_xfer_param.rxbuf[7] << 16) + (spi_xfer_param.rxbuf[8] << 8) + spi_xfer_param.rxbuf[9];
	printf("w-read:data=0x%x\n", recive_data);
	return recive_data;
}
int obc_spi_write_mx6300(uint32_t addr, uint32_t data)
{
	int ret;
	if (addr >= AHB_ADDR_FLOOR)
	{
		return obc_spi_write_mx6300_ahb(addr, data);
	}
	uint32_t addr_tmp = addr & 0xFFFF;

	if (addr_tmp >= 0xf000)
	{
		//Raw command
		if (addr_tmp == MX6300_RAW_CMD_LDP_CALIBRATE)
		{
			return obc_spi_set_ldp_calibrate(addr_tmp, data);
		}
		return obc_spi_write_mx6300_raw_cmd(addr_tmp, data);
	}

	uint32_t cur_val = obc_spi_read_mx6300_align_register(addr & 0xFFFF);
	uint8_t align_offset = 0;
	uint32_t offset_addr = get_mx6300_aligned_addr(addr & 0xFFFF, &align_offset);

	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 8;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = (cur_val & 0xFF000000) >> 24;
	spi_xfer_param.txbuf[5] = (cur_val & 0xFF0000) >> 16;
	spi_xfer_param.txbuf[6] = (cur_val & 0xFF00) >> 8;
	spi_xfer_param.txbuf[7] = (cur_val & 0xFF);
	spi_xfer_param.txbuf[4 + align_offset] = data & 0xFF;
	printf("align_offset=%d,data=0x%x\n", align_offset, data);
	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (ret != 0)
	{
		printf("%s failed(addr=0x%x, ret = %d)\n", __func__, addr, ret);
		return -1;
	}
	return ret;
}

int obc_spi_read_mx6300_base_addr()
{
	int ret = 0;
	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TR;
	spi_xfer_param.txlen = 10;
	spi_xfer_param.rxlen = 10;

	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_FAST_READ;
	spi_xfer_param.txbuf[1] = 0;
	spi_xfer_param.txbuf[2] = 0;
	spi_xfer_param.txbuf[3] = MX6300_BASE_ADDR;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 0;
	spi_xfer_param.txbuf[7] = 0;
	spi_xfer_param.txbuf[8] = 0;
	spi_xfer_param.txbuf[9] = 0;
	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (ret != 0)
	{
		printf("%s failed(ret = %d)\n", __func__, ret);
		return -1;
	}

	MX6300_base_addr = (spi_xfer_param.rxbuf[9] << 24) + (spi_xfer_param.rxbuf[8] << 16) + (spi_xfer_param.rxbuf[7] << 8) + spi_xfer_param.rxbuf[6];
	printf("MX6300_base_addr=0x%x\n", MX6300_base_addr);

	return ret;
}

int obc_spi_read_mx6300(uint32_t addr, uint32_t *pdata)
{
	int ret = 0;
	printf("addr=%#x\n", addr);
	if (addr >= AHB_ADDR_FLOOR)
	{
		return obc_spi_read_mx6300_ahb(addr, pdata);
	}
	uint32_t addr_tmp = addr & 0xFFFF;
	if (addr_tmp >= 0xf000)
	{
		//Raw command
		return obc_spi_read_mx6300_raw_cmd(addr_tmp, pdata);
	}
	uint32_t recive_data = 0;
	uint8_t align_offset = 0;
	//int data8bit = addr>>16;
	uint32_t offset_addr = get_mx6300_aligned_addr(addr & 0xFFFF, &align_offset);

	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TR;
	spi_xfer_param.txlen = 10;
	spi_xfer_param.rxlen = 10;

	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_FAST_READ;
	spi_xfer_param.txbuf[1] = offset_addr >> 16;
	spi_xfer_param.txbuf[2] = offset_addr >> 8;
	spi_xfer_param.txbuf[3] = offset_addr & 0xff;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 0;
	spi_xfer_param.txbuf[7] = 0;
	spi_xfer_param.txbuf[8] = 0;
	spi_xfer_param.txbuf[9] = 0;

	if (addr == MX6300_FW_VER_ADDR)
	{
		spi_xfer_param.txlen = 14;
		spi_xfer_param.rxlen = 14;
		spi_xfer_param.txbuf[10] = 0;
		spi_xfer_param.txbuf[11] = 0;
		spi_xfer_param.txbuf[12] = 0;
		spi_xfer_param.txbuf[13] = 0;
	}
	printf("obc_spi_read_mx6300 aaa\n");
	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (ret != 0)
	{
		printf("%s failed(addr=0x%x,ret = %d)\n", __func__, addr, ret);
		return -1;
	}
	printf("obc_spi_read_mx6300 bbb\n");
	recive_data = spi_xfer_param.rxbuf[6 + align_offset];
	if (addr == MX6300_DEV_ID_ADDR)
	{
		recive_data = (spi_xfer_param.rxbuf[6] << 8) + spi_xfer_param.rxbuf[7];
	}
	else if (addr == MX6300_FW_VER_ADDR)
	{
		recive_data = (spi_xfer_param.rxbuf[8] << 16) + (spi_xfer_param.rxbuf[9] << 8) + spi_xfer_param.rxbuf[10];
	}

	printf("read:0ffset=%d,receive_data=0x%x\n", align_offset, recive_data);
	*pdata = recive_data;
	return ret;
}
char *g_va_sys_reg_base;
int fd_sys_reg_base;
int obc_mx6300_reset_control()
{
	fd_sys_reg_base = open("/dev/mem", O_RDWR | O_SYNC);
	g_va_sys_reg_base = mmap(NULL, 0x100000, PROT_READ | PROT_WRITE, MAP_SHARED, fd_sys_reg_base, 0x40460000); //0x40420024

	/* reset pin ctrl */
	(*(g_va_sys_reg_base + 0x10)) |= (1 << 6); // dir-output

	(*(g_va_sys_reg_base + 0x0C)) |= (1 << 6); //high

	usleep(20000);
	(*(g_va_sys_reg_base + 0x0C)) &= ~(1 << 6); // low
	usleep(20000);
	close(fd_sys_reg_base);
	return 0;
}
int obc_ldp_control(int enable)
{
	fd_sys_reg_base = open("/dev/mem", O_RDWR | O_SYNC);
	g_va_sys_reg_base = mmap(NULL, 0x100000, PROT_READ | PROT_WRITE, MAP_SHARED, fd_sys_reg_base, 0x40440000); //0x40420024

	/* ldp-en pin ctrl */
	(*(g_va_sys_reg_base + 0x04)) |= (1 << 7); // dir-output

	if (enable)
	{
		(*(g_va_sys_reg_base + 0x0)) |= (1 << 7); //high
	}
	else
	{
		(*(g_va_sys_reg_base + 0x0)) &= ~(1 << 7); // low
	}

	usleep(2000);

	close(fd_sys_reg_base);
	return 0;
}

int obc_spi_control(int dev)
{
	if (current_devtype == dev)
	{
		return 0;
	}
	fd_sys_reg_base = open("/dev/mem", O_RDWR | O_SYNC);
	g_va_sys_reg_base = mmap(NULL, 0x100000, PROT_READ | PROT_WRITE, MAP_SHARED, fd_sys_reg_base, 0x40420000); //0x40420024

	/* spi ctrl pin */
	(*(g_va_sys_reg_base + 0x28)) |= (1 << 4); // dir-output

	if (dev == MX6300_DEV)
	{
		(*(g_va_sys_reg_base + 0x24)) |= (1 << 4); // high
		current_devtype = MX6300_DEV;
	}
	else
	{
		(*(g_va_sys_reg_base + 0x24)) &= ~(1 << 4); // low
		current_devtype = FLASH_DEV;
	}
	usleep(1000);
	close(fd_sys_reg_base);
	return 0;
}
static int obc_sl_spi_download(uint32_t addr, uint8_t *buf, uint32_t size)
{
	int ret;
	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = size + 4;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1] = addr >> 16;
	spi_xfer_param.txbuf[2] = addr >> 8;
	spi_xfer_param.txbuf[3] = addr & 0xff;
	for (int i = 0; i < size; i++)
	{
		spi_xfer_param.txbuf[i + 4] = buf[i];
	}

	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	return ret;
}
static int obc_sl_spi_upload(uint32_t addr, uint8_t *buf, uint32_t size)
{
	int ret;
	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TR;
	spi_xfer_param.txlen = size + 6;
	spi_xfer_param.rxlen = size + 6;
	memset(spi_xfer_param.txbuf, 0, size + 6);
	memset(spi_xfer_param.rxbuf, 0, size + 6);
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_FAST_READ;
	spi_xfer_param.txbuf[1] = addr >> 16;
	spi_xfer_param.txbuf[2] = addr >> 8;
	spi_xfer_param.txbuf[3] = addr & 0xff;

	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	memcpy(buf, spi_xfer_param.rxbuf + 6, size);
	printf("buf[0]=0x%x,buf[1]=0x%x,buf[2]=0x%x,buf[3]=0x%x,\n", buf[0], buf[1], buf[2], buf[3]);
	return ret;
}
#define MAX_PACKET_SIZE 12
int obc_download_mx6300_firmware(uint8_t *buf, uint32_t length, uint32_t address)
{
	uint32_t count = length / MAX_PACKET_SIZE;
	uint8_t left = length % MAX_PACKET_SIZE;
	uint32_t file_addr = address;
	uint32_t file_offset = 0;
	uint8_t *file_buf = buf;
	uint8_t file_left[MAX_PACKET_SIZE] = {0};
	for (int offset = 0; offset < count; offset++)
	{
		if (obc_sl_spi_download(file_addr, file_buf, MAX_PACKET_SIZE) < 0)
		{
			printf("write firmware file failed(offset=0x%x)\n", offset);
			return -1;
		}
		file_buf += MAX_PACKET_SIZE;
		file_addr += MAX_PACKET_SIZE;
	}
	if (left > 0)
	{
		memcpy(file_left, file_buf, left);
		if (obc_sl_spi_download(file_addr, file_left, MAX_PACKET_SIZE) < 0)
		{
			printf("write firmware file failed(left=0x%x)\n", left);
			return -1;
		}
	}

	return 0;
}
static int obc_load_binary(char *file, uint32_t file_size, uint32_t load_addr)
{

	FILE *fp = fopen(file, "rb");
	if (fp == NULL)
	{
		printf("load file (%s) Failed\n", file);
		return -1;
	}
	uint8_t *file_buf = calloc(1, file_size);
	uint32_t size = fread(file_buf, 1, file_size, fp);
	fclose(fp);
	uint8_t *buffer = file_buf;
	ObRefInfo ref = {0};
	if (load_addr == MX6300_REFERENCE_ADDR)
	{
		ObDepthCfg depthcfg = {0};
		uint32_t version = obref_version();
		char *p = (char *)&version;
		printf("====== obrefparser version: %d.%d.%d ======\n", p[3], p[2], p[1]);
		int ret = obref_parser(file_buf, size, &ref, &depthcfg);
		if (0 != ret)
		{
			/**按照旧流程处理*/
			if (4096 == ret)
			{
				/**处理buffer*/
			}
			printf("clear reference data\n");
			buffer = file_buf;
		}
		else
		{
			printf("unit:%d, baseline: %f, z0: %f, zpps: %f, fx: %f\n",
				   depthcfg.unit, depthcfg.calib.baseline, depthcfg.calib.z0, depthcfg.calib.zpps, depthcfg.intrinsic.fx);
			buffer = ref.ref_buf;
		}
	}
	if (size != file_size)
	{
		printf("file size readed is not matched,size=0x%x\n", size);
	}
	pthread_mutex_lock(&gspi_lock);
	obc_spi_control(MX6300_DEV);
	if (obc_download_mx6300_firmware(buffer, size, load_addr) == 0)
	{
		printf("download  file (%s) success\n", file);
	}
	else
	{
		printf("download  file (%s) failed\n", file);
	}
	pthread_mutex_unlock(&gspi_lock);
	free(file_buf);
	if (load_addr == MX6300_REFERENCE_ADDR)
	{
		obref_release(&ref);
	}
	return 0;
}
typedef struct _Componet_temperature
{
	float ldm_temp;
	float ir_temp;
	float rgb_temp;
} Componet_temp;
int get_componet_temp(Componet_temp *temp)
{
	int ret;
	uint32_t tmp;
	float tmpf;
	spi_ctrl_msg ctrl_msg = {0};
	ctrl_msg.spi_fd = gspi_fd;
	ctrl_msg.dev_type = SPI_DEV_MX6300;
	ctrl_msg.regaddr = MX6300_RAW_CMD_GET_LDM_TEMP;
	ctrl_msg.pdata = &tmp;
	ctrl_msg.dataLen = 4;
	ret = obc_sl_spi_read(&ctrl_msg);
	if (ret < 0)
	{
		printf("%s: get ldm temperature failed\n", __FUNCTION__);
		return -1;
	}
	memcpy(&tmpf, &tmp, 4);
	temp->ldm_temp = tmpf;
	ctrl_msg.regaddr = MX6300_RAW_CMD_GET_IR_TEMP;
	ctrl_msg.pdata = &tmp;
	ret = obc_sl_spi_read(&ctrl_msg);
	if (ret < 0)
	{
		printf("%s: get ir temperature failed\n", __FUNCTION__);
		return -1;
	}
	memcpy(&tmpf, &tmp, 4);
	temp->ir_temp = tmpf;
	ctrl_msg.regaddr = MX6300_RAW_CMD_GET_RGB_TEMP;
	ctrl_msg.pdata = &tmp;
	ret = obc_sl_spi_read(&ctrl_msg);
	if (ret < 0)
	{
		printf("%s: get rgb temperature failed\n", __FUNCTION__);
		return -1;
	}
	memcpy(&tmpf, &tmp, 4);
	temp->rgb_temp = tmpf;
	return 0;
}
int obc_spi_read_mx6300_status()
{
	int ret = 0;
	pthread_mutex_lock(&gspi_lock);
	obc_spi_control(SPI_DEV_MX6300);
	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TR;
	spi_xfer_param.txlen = 10;
	spi_xfer_param.rxlen = 10;

	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_FAST_READ;
	spi_xfer_param.txbuf[1] = 0;
	spi_xfer_param.txbuf[2] = 0;
	spi_xfer_param.txbuf[3] = MX6300_STATUS_ADDR;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0;
	spi_xfer_param.txbuf[6] = 0;
	spi_xfer_param.txbuf[7] = 0;
	spi_xfer_param.txbuf[8] = 0;
	spi_xfer_param.txbuf[9] = 0;
	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	pthread_mutex_unlock(&gspi_lock);
	if (ret != 0)
	{
		printf("%s failed(ret = %d)\n", __func__, ret);
		return -1;
	}

	MX6300_status = (spi_xfer_param.rxbuf[9] << 24) + (spi_xfer_param.rxbuf[8] << 16) + (spi_xfer_param.rxbuf[7] << 8) + spi_xfer_param.rxbuf[6];
	// printf("MX6300_status=0x%x\n", MX6300_status);

	return ret;
}

static int obc_spi_read_mx6300_id()
{
	int ret;
	pthread_mutex_lock(&gspi_lock);
	obc_spi_control(MX6300_DEV);
	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TR;
	spi_xfer_param.txlen = 6;
	spi_xfer_param.rxlen = 6;
	spi_xfer_param.txbuf[0] = MX6300_CMD_ID_SENSOR_ID;
	spi_xfer_param.txbuf[1] = 0; //reg_high
	spi_xfer_param.txbuf[2] = 0;
	spi_xfer_param.txbuf[3] = 0;
	spi_xfer_param.txbuf[4] = 0;
	spi_xfer_param.txbuf[5] = 0; //reg_high

	ret = remote_spi_master_xfer(gspi_fd, &spi_xfer_param);
	if (0 != ret)
	{
		printf("obc tof spi first read, ret = %d\n", ret);
		return ret;
	}
	int id = spi_xfer_param.rxbuf[4] << 8 + spi_xfer_param.rxbuf[5];
	printf("ID=0x%x\n", id);
	pthread_mutex_unlock(&gspi_lock);
	return ret;
}
int obc_sl_spi_erase_flash(uint32_t addr, uint32_t size)
{
	mtd_info_t mtd_info; // the MTD structure
	erase_info_t ei;	 // the erase block structure
	obc_spi_control(FLASH_DEV);
	int nwrite;
	int fd = open("/dev/mtd0", O_RDWR | O_SYNC);
	if (fd < 0)
	{
		printf("open /dev/mtd0 failed\n");
		return -1;
	}
	ioctl(fd, MEMGETINFO, &mtd_info); // get the device info

	// dump it for a sanity check, should match what's in /proc/mtd
	printf("MTD Type: %x\nMTD total size: %x bytes\nMTD erase size: %x bytes\nMTD write size:%x bytes\n",
		   mtd_info.type, mtd_info.size, mtd_info.erasesize, mtd_info.writesize);

	ei.length = mtd_info.erasesize; //set the erase block size
	for (ei.start = addr; ei.start < addr + size; ei.start += ei.length)
	{
		if (ioctl(fd, MEMERASE, &ei) < 0)
		{
			printf("[Flash] Can erase MTD (MEMERASE, errno=%d)!n", errno);
			close(fd);
			return -1;
		}
	}
	return 0;
}
int obc_sl_spi_read_flash(uint32_t offset_addr, uint8_t *pdatabuf, uint32_t len)
{
	mtd_info_t mtd_info; // the MTD structure
	erase_info_t ei;	 // the erase block structure
	int nread;
	int fd = open("/dev/mtd0", O_RDONLY);
	lseek(fd, offset_addr, SEEK_SET);
	nread = read(fd, pdatabuf, len);
	if (nread <= 0)
	{
		printf("read flash failed (MEMREAD, errno=%d)!n", errno);
		close(fd);
		return -1;
	}
	close(fd);
}
int obc_sl_spi_write_flash(uint32_t offset_addr, uint8_t *pdatabuf, uint32_t len)
{
	mtd_info_t mtd_info; // the MTD structure
	erase_info_t ei;	 // the erase block structure
	int nwrite;
	int fd = open("/dev/mtd0", O_RDWR | O_SYNC);
	if (fd < 0)
	{
		printf("open /dev/mtd0 failed\n");
		return -1;
	}
	ioctl(fd, MEMGETINFO, &mtd_info); // get the device info

	// dump it for a sanity check, should match what's in /proc/mtd
	/*printf("MTD Type: %x\nMTD total size: %x bytes\nMTD erase size: %x bytes\nMTD write size:%x bytes\n",
		   mtd_info.type, mtd_info.size, mtd_info.erasesize, mtd_info.writesize);*/

	ei.length = mtd_info.erasesize; //set the erase block size
	for (ei.start = offset_addr; ei.start < offset_addr + len; ei.start += ei.length)
	{
		if (ioctl(fd, MEMERASE, &ei) < 0)
		{
			printf("[Flash] Can erase MTD (MEMERASE, errno=%d)!n", errno);
			close(fd);
			return -1;
		}
	}
	lseek(fd, offset_addr, SEEK_SET); // go to the first block
	nwrite = write(fd, pdatabuf, len);
	if (nwrite <= 0)
	{
		close(fd);
		return -1;
	}
	close(fd);
}
unsigned long GetTickCount()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
static int mx6300_monitor = 1;
void *obc_sl_monitor_mx6300()
{
	Componet_temp temp;
	while (mx6300_monitor)
	{
#if 0
		get_componet_temp(&temp);
		printf("temperature(ldm=%f, ir=%f, rgb=%f)\n",temp.ldm_temp,temp.ir_temp,temp.rgb_temp);
#endif
		usleep(10 * 1000 * 1000);
		obc_spi_read_mx6300_status();
	}
}
void obc_sl_create_mx6300_monitor()
{
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&tid, &attr, &obc_sl_monitor_mx6300, NULL);
	pthread_attr_destroy(&attr);
}
int obc_sl_spi_send_ldp_params()
{
	int ret;
	uint8_t ldp_param[16] = {0};
	FILE *fp = fopen(config_file, "rb");
	if (fp == NULL)
	{
		printf("open %s Failed\n", config_file);
		return -1;
	}
	DeviceConfig config = {0};
	fread(&config, 1, sizeof(config), fp);
	memcpy(ldp_param, config.ldp_params, 16);
	uint32_t ldp_crc = cal_crc_table(config.ldp_params, 16);
	fclose(fp);
	if (ldp_crc != config.ldp_crc)
	{
		printf("Invalid ldp parameter\n");
		return -1;
	}
	pthread_mutex_lock(&gspi_lock);
	ret = obc_spi_write_ldp_calibrate_data(ldp_param);
	if (ret < 0)
	{
		printf("write ldp calibration params to mx6300 failed\n");
	}
	pthread_mutex_unlock(&gspi_lock);
	return ret;
}
int obc_sl_spi_open_mini()
{
	back_trace = creat_back_trace();

	gspi_fd = remote_spi_open(DEV_REMOTE_SPI_PATH);
	if (0 == gspi_fd)
	{
		printf("fail to open %s, exit...\n", DEV_REMOTE_SPI_PATH);
		return -1;
	}
	printf("success to open %s : 0x%x\n", DEV_REMOTE_SPI_PATH, gspi_fd);
	spi_rpc_xfer_t spi_xfer = {0};
	spi_xfer.pst_spi_init_info.e_halSpiPhase = HAL_SPI_PHASE_2EDGE;
	spi_xfer.pst_spi_init_info.e_halSpiPolarity = HAL_SPI_POLARITY_HIGH;
	spi_xfer.pst_spi_init_info.u16_halSpiBaudr = 36;
	gp_context.spi_init_pra = spi_xfer.pst_spi_init_info;
	gp_context.spi_port = SPI_DEV_PORT;
	obc_spi_read_mx6300_base_addr();
	return gspi_fd;
}
int obc_sl_spi_open()
{
	back_trace = creat_back_trace();

	gspi_fd = remote_spi_open(DEV_REMOTE_SPI_PATH);
	if (0 == gspi_fd)
	{
		printf("fail to open %s, exit...\n", DEV_REMOTE_SPI_PATH);
		return -1;
	}
	printf("success to open %s : 0x%x\n", DEV_REMOTE_SPI_PATH, gspi_fd);
	spi_rpc_xfer_t spi_xfer = {0};
	spi_xfer.pst_spi_init_info.e_halSpiPhase = HAL_SPI_PHASE_2EDGE;
	spi_xfer.pst_spi_init_info.e_halSpiPolarity = HAL_SPI_POLARITY_HIGH;
	spi_xfer.pst_spi_init_info.u16_halSpiBaudr = 36;
	gp_context.spi_init_pra = spi_xfer.pst_spi_init_info;
	gp_context.spi_port = SPI_DEV_PORT;
	obc_ldp_control(1);
	obc_spi_control(MX6300_DEV);
	obc_spi_read_mx6300_id();
	obc_sl_spi_params_sync();
	obc_spi_control(MX6300_DEV);
	obc_load_binary(firmware_file, FIRMWARE_FILE_SIZE, MX6300_FIRMWARE_ADDR);
	long start, end;
	start = GetTickCount();
	obc_load_binary(reference_file, REFERENCE_FILE_SIZE, MX6300_REFERENCE_ADDR);
	end = GetTickCount();
	printf("time elapsed:%ld ms\n", end - start);
	int reset_cnt = 3;
mx6300_reset:
	obc_mx6300_reset_control();
	obc_spi_read_mx6300_id();
#if 1
	int wait6300Cnt = 25;
	while (wait6300Cnt > 0)
	{
		delay_ms(200);
		obc_spi_read_mx6300_status();
		if (((MX6300_status & 0xFF00) >> 8) != MX6300_INIT_OK)
		{
			printf("MX6300 is initing....(status=0x%x)\n", MX6300_status);
		}
		else
		{
			printf("MX6300 inited OK(status=0x%x)\n", MX6300_status);
			break;
		}
		wait6300Cnt--;
	}
#endif
	obc_spi_read_mx6300_base_addr();
	if (((MX6300_base_addr & 0xFF000000) > 0) || (MX6300_base_addr == 0))
	{
		printf("invalid base addr(0x%x)\n", MX6300_base_addr);
#if 1
		reset_cnt--;
		if (reset_cnt != 0)
		{
			goto mx6300_reset;
		}
#endif
	}
	obc_sl_spi_send_rectify_param();
	obc_sl_spi_send_ldp_params();
#if 0
	obc_sl_create_mx6300_monitor();
#endif
	//switch to 1280x800
	/*int ret;
    uint32_t res_ = 0x11;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspi_fd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_IR_RES_ADDR;
    ctrl_msg.pdata = &res_;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set ir resolution failed\n", __FUNCTION__);
      return -1;
    }
    uint32_t load=0x01;
    ctrl_msg.spi_fd = gspi_fd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_IR_LOAD_ADDR;
    ctrl_msg.pdata = &load;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:load ir resolution failed\n", __FUNCTION__);
      return -1;
    }*/
	return gspi_fd;
}
int obc_sl_spi_close(int fd)
{
	if (remote_spi_close(fd))
	{
		printf("fail to close 0x%x, exit...\n", fd);
		return -1;
	}
	destroy_back_trace(back_trace);
	return 0;
}
int obc_sl_spi_write(spi_ctrl_msg *ctrl_msg)
{
	int ret = 0;
	if (ctrl_msg->dev_type == SPI_DEV_MX6300)
	{
		pthread_mutex_lock(&gspi_lock);
		obc_spi_control(SPI_DEV_MX6300);
		uint32_t data = *(uint32_t *)(ctrl_msg->pdata);
		ret = obc_spi_write_mx6300(ctrl_msg->regaddr, data);
		if (ret < 0)
		{
			printf("%s failed(addr=0x%x,data=0x%x)\n", __FUNCTION__, ctrl_msg->regaddr, data);
		}
		pthread_mutex_unlock(&gspi_lock);
		return ret;
	}
	else if (ctrl_msg->dev_type == SPI_DEV_FLASH)
	{
		pthread_mutex_lock(&gspi_lock);
		obc_spi_control(SPI_DEV_FLASH);
		ret = obc_sl_spi_write_flash(ctrl_msg->regaddr, ctrl_msg->pdata, ctrl_msg->dataLen);
		pthread_mutex_unlock(&gspi_lock);
		return ret;
	}
	return -1;
}
int obc_sl_spi_read(spi_ctrl_msg *ctrl_msg)
{
	int ret = 0;
	if (ctrl_msg->dev_type == SPI_DEV_MX6300)
	{
		pthread_mutex_lock(&gspi_lock);
		obc_spi_control(SPI_DEV_MX6300);
		ret = obc_spi_read_mx6300(ctrl_msg->regaddr, ctrl_msg->pdata);
		if (ret < 0)
		{
			printf("%s failed(addr=0x%x)\n", __FUNCTION__, ctrl_msg->regaddr);
		}
		ctrl_msg->dataLen = 4;
		pthread_mutex_unlock(&gspi_lock);
		return ret;
	}
	else if (ctrl_msg->dev_type == SPI_DEV_FLASH)
	{
		pthread_mutex_lock(&gspi_lock);
		obc_spi_control(SPI_DEV_FLASH);
		ret = obc_sl_spi_read_flash(ctrl_msg->regaddr, ctrl_msg->pdata, ctrl_msg->dataLen);
		pthread_mutex_unlock(&gspi_lock);
		return ret;
	}
	return -1;
}
int obc_sl_spi_write_i2c(uint8_t bus, uint8_t slave_addr, uint32_t reg, uint8_t reg_len, uint32_t data, uint8_t data_len)
{
	int ret = 0;
	pthread_mutex_lock(&gspi_lock);
	ret = obc_spi_write_mx6300_i2c(bus, slave_addr, reg, reg_len, data, data_len);
	if (ret < 0)
	{
		printf("%s failed(slave_addr=0x%x,reg=0x%x)\n", __FUNCTION__, slave_addr, reg);
	}
	pthread_mutex_unlock(&gspi_lock);
	return ret;
}
int obc_sl_spi_read_i2c(uint8_t bus, uint8_t slave_addr, uint32_t reg, uint8_t reg_len, uint32_t *data, uint8_t data_len)
{
	int ret = 0;
	pthread_mutex_lock(&gspi_lock);
	ret = obc_spi_read_mx6300_i2c(bus, slave_addr, reg, reg_len, data, data_len);
	if (ret < 0)
	{
		printf("%s failed(slave_addr=0x%x,reg=0x%x)\n", __FUNCTION__, slave_addr, reg);
	}
	pthread_mutex_unlock(&gspi_lock);
	return ret;
}

int obc_sl_sync(char *file, uint32_t flash_addr, uint32_t len)
{
	int ret;
	spi_ctrl_msg ctrl_msg = {0};
	uint32_t length = len;
	if (flash_addr == REFERENCE_ADDR)
	{
		ctrl_msg.spi_fd = gspi_fd;
		ctrl_msg.dev_type = SPI_DEV_FLASH;
		ctrl_msg.regaddr = flash_addr;
		ctrl_msg.pdata = &length;
		ctrl_msg.dataLen = 4;
		ret = obc_sl_spi_read(&ctrl_msg);
		if (ret < 0)
		{
			printf("%s:read reference length failed\n", __FUNCTION__);
			return -1;
		}
		printf("%s:length(%s)=%d\n", __FUNCTION__, file, length);
		if (length <= 0)
		{
			return -1;
		}
		length += 4;
	}
	uint8_t *buf = calloc(1, length);
	if (flash_addr == REFERENCE_ADDR)
	{
#if 1
		length -= 4;
		int cnt = length / 4096;
		int left = length % 4096;
		flash_addr += 4;
		if (cnt > 0)
		{
			for (int i = 0; i < cnt; i++)
			{
				ctrl_msg.spi_fd = gspi_fd;
				ctrl_msg.dev_type = SPI_DEV_FLASH;
				ctrl_msg.regaddr = flash_addr + i * 4096;
				ctrl_msg.pdata = buf + i * 4096;
				ctrl_msg.dataLen = 4096;
				ret = obc_sl_spi_read(&ctrl_msg);
				if (ret < 0)
				{
					printf("%s:read %s from flash failed(index =%d)\n", __FUNCTION__, file, i);
					free(buf);
					return -1;
				}
				else
				{
					printf("read %s from flash completed(index =%d)\n", file, i);
				}
				usleep(5000);
			}
		}

		if (left)
		{
			ctrl_msg.spi_fd = gspi_fd;
			ctrl_msg.dev_type = SPI_DEV_FLASH;
			ctrl_msg.regaddr = flash_addr + cnt * 4096;
			ctrl_msg.pdata = buf + cnt * 4096;
			ctrl_msg.dataLen = left;
			ret = obc_sl_spi_read(&ctrl_msg);
			if (ret < 0)
			{
				printf("%s:read %s left from flash failed\n", __FUNCTION__, file);
				free(buf);
				return -1;
			}
			else
			{
				printf("read %s from flash completed(left)\n", file);
			}
		}
#else
		ctrl_msg.spi_fd = gspi_fd;
		ctrl_msg.dev_type = SPI_DEV_FLASH;
		ctrl_msg.regaddr = flash_addr;
		ctrl_msg.pdata = buf;
		ctrl_msg.dataLen = length;
		ret = obc_sl_spi_read(&ctrl_msg);
		if (ret < 0)
		{
			printf("%s:read %s left from flash failed\n", __FUNCTION__, file);
			free(buf);
			return -1;
		}
		else
		{
			printf("read %s(len=%d) from flash completed\n", file, length);
		}
#endif
	}
	else
	{
		ctrl_msg.spi_fd = gspi_fd;
		ctrl_msg.dev_type = SPI_DEV_FLASH;
		ctrl_msg.regaddr = flash_addr;
		ctrl_msg.pdata = buf;
		ctrl_msg.dataLen = length;
		printf("%s:length(%s)=%d\n", __FUNCTION__, file, length);
		ret = obc_sl_spi_read(&ctrl_msg);
		if (ret < 0)
		{
			printf("%s:read %s from flash failed\n", __FUNCTION__, file);
			free(buf);
			return -1;
		}
		else
		{
			printf("read %s from flash completed\n", file);
		}
	}

	FILE *fp = fopen(file, "wb");
	if (fp == NULL)
	{
		printf("open %s Failed\n", file);
		return -1;
	}
	fwrite(buf, 1, length, fp);
	free(buf);
	fclose(fp);
	system("sync");
	return 0;
}
int obc_sl_sync_bin()
{
	int ret;
	ConfigValidFlag configValid = {0};
	spi_ctrl_msg ctrl_msg = {0};
	ctrl_msg.spi_fd = gspi_fd;
	ctrl_msg.dev_type = SPI_DEV_FLASH;
	ctrl_msg.regaddr = CONFIG_VALID_ADDR;
	ctrl_msg.pdata = &configValid;
	ctrl_msg.dataLen = sizeof(ConfigValidFlag);
	ret = obc_sl_spi_read(&ctrl_msg);
	if (ret < 0)
	{
		printf("%s:read config valid flag failed\n", __FUNCTION__);
		return -1;
	}
	//sync sn
	//if (configValid.sn_valid == VALUE_VALID && configValid.ldp_valid == VALUE_VALID)
	if (configValid.sn_valid == VALUE_VALID)
	{
		obc_sl_sync(config_file, DEVICE_CONFIG_ADDR, sizeof(DeviceConfig));
		usleep(5000);
	}

	if (configValid.distortion_d2c4x3_valid == VALUE_VALID)
	{
		obc_sl_sync(distortion_d2c4x3, DISTORTION_PARAMS_ADDR, sizeof(Doraemon_Content_t));
		usleep(5000);
	}

	if (configValid.d2c_16x9_valid == VALUE_VALID)
	{
		obc_sl_sync(d2c_16x9, SOFT_D2C_PARAMS_ADDR, sizeof(Doraemon_Content_t));
		usleep(5000);
	}
	if (configValid.reference_valid == VALUE_VALID)
	{
		obc_sl_sync(reference_file, REFERENCE_ADDR, 0);
		usleep(5000);
	}
	return 0;
}
int obc_sl_isLocalFileExistent()
{

	if (access(config_file, F_OK) != 0)
	{
		printf("%s:there is no  sn file in local\n", __FUNCTION__);
		return -1;
	}
	if (access(distortion_d2c4x3, F_OK) != 0)
	{
		printf("%s:there is no distortion file in local\n", __FUNCTION__);
		return -1;
	}
	if (access(d2c_16x9, F_OK) != 0)
	{
		printf("%s:there is no local sn file in local\n", __FUNCTION__);
		return -1;
	}
	if (access(reference_file, F_OK) != 0)
	{
		printf("%s:there is no local sn file in local\n", __FUNCTION__);
		return -1;
	}
	return 0;
}
int obc_sl_compare_sn(char *sn)
{

	FILE *fp = fopen(config_file, "rb");
	if (fp == NULL)
	{
		printf("open local sn file failed\n");
		return -1;
	}
	DeviceConfig config = {0};
	uint32_t size = fread(&config, 1, sizeof(DeviceConfig), fp);
	printf("sn_flash=%s\nsn_local=%s\n", sn, config.sn);
	if (size == 0)
	{
		fclose(fp);
		return -1;
	}
	fclose(fp);
	return strcmp(sn, config.sn);
}
int obc_sl_send_param2mx6300()
{
	int ret;
	Doraemon_Content_t doraemon_t = {0};
	spi_ctrl_msg ctrl_msg = {0};
	FILE *fp = fopen(reference_file, "rb");
	if (fp == NULL)
	{
		printf("open local parameter file failed\n");
		return -1;
	}
	uint32_t size = fread(&doraemon_t, 1, sizeof(doraemon_t), fp);
	if (size == 0)
	{
		fclose(fp);
		return -1;
	}
	fclose(fp);
	uint32_t tmp;
	for (int i = 0; i < 44; i++)
	{
		ctrl_msg.spi_fd = gspi_fd;
		ctrl_msg.dev_type = SPI_DEV_MX6300;
		ctrl_msg.regaddr = doraemon_t.rectify_regs[i].reg;
		tmp = doraemon_t.rectify_regs[i].val;
		ctrl_msg.pdata = &tmp;
		ctrl_msg.dataLen = 4;
		ret = obc_sl_spi_write(&ctrl_msg);
		if (ret < 0)
		{
			printf("%s:write rectify regs  failed\n", __FUNCTION__);
			return -1;
		}
	}
	for (int i = 0; i < 15; i++)
	{
		ctrl_msg.spi_fd = gspi_fd;
		ctrl_msg.dev_type = SPI_DEV_MX6300;
		ctrl_msg.regaddr = doraemon_t.hw_d2c_regs[i].reg;
		tmp = doraemon_t.hw_d2c_regs[i].val;
		ctrl_msg.pdata = &tmp;
		ctrl_msg.dataLen = 4;
		ret = obc_sl_spi_write(&ctrl_msg);
		if (ret < 0)
		{
			printf("%s:write hw d2c regs  failed\n", __FUNCTION__);
			return -1;
		}
	}
}
int obc_sl_spi_params_sync()
{
	int ret;
	ConfigValidFlag configValid = {0};

	spi_ctrl_msg ctrl_msg = {0};
	ctrl_msg.spi_fd = gspi_fd;
	ctrl_msg.dev_type = SPI_DEV_FLASH;
	ctrl_msg.regaddr = CONFIG_VALID_ADDR;
	ctrl_msg.pdata = &configValid;
	ctrl_msg.dataLen = sizeof(ConfigValidFlag);
	ret = obc_sl_spi_read(&ctrl_msg);
	if (ret < 0)
	{
		printf("%s:read config valid flag failed\n", __FUNCTION__);
		return -1;
	}
	DeviceConfig config = {0};
	ctrl_msg.spi_fd = gspi_fd;
	ctrl_msg.dev_type = SPI_DEV_FLASH;
	ctrl_msg.regaddr = DEVICE_CONFIG_ADDR;
	ctrl_msg.pdata = &config;
	ctrl_msg.dataLen = sizeof(DeviceConfig);
	ret = obc_sl_spi_read(&ctrl_msg);
	if (ret < 0)
	{
		printf("%s:read sn failed\n", __FUNCTION__);
		return -1;
	}
	if ((configValid.sn_valid != VALUE_VALID) || (config.sn[0] == 0xFF && config.sn[5] == 0xFF && config.sn[11] == 0xFF))
	{
		printf("%s:there is no sn on flash\n", __FUNCTION__);
		return 1;
	}
	if ((obc_sl_isLocalFileExistent() == 0) && (obc_sl_compare_sn(config.sn) == 0))
	{
		printf("The sn of flash is same to local and all local file exist\n");
	}
	else
	{
		printf("sync bin from flash to local\n");
		obc_sl_sync_bin();
	}
	return 0;
}
int obc_sl_spi_mx6300_setBaseAddr(uint32_t base_addr)
{
	MX6300_base_addr = base_addr;
	return 0;
}
int obc_sl_spi_send_rectify_param()
{
	int ret;
	FILE *fp = fopen(distortion_d2c4x3, "rb");
	if (fp == NULL)
	{
		printf("load file (%s) Failed\n", distortion_d2c4x3);
		return -1;
	}
	uint32_t binsize = sizeof(Doraemon_Content_t);
	Doraemon_Content_t *params = (Doraemon_Content_t *)calloc(1, binsize);
	uint32_t size = fread(params, 1, binsize, fp);
	if (size != binsize)
	{
		printf("file size readed is not matched,size=0x%x\n", size);
		fclose(fp);
		free(params);
	}
	uint32_t tmp, tmpr;
	uint32_t addr;
	RegVal d2ctmp[] = {
		{0x50001204, 0x00418937},
		{0x50001208, 0x00027b19},
		{0x50001210, 0x012c93f8},
		{0x50001214, 0xfffdce0e},
		{0x50001218, 0xc9beb90b},
		{0x5000121C, 0xfca87ef1},
		{0x50001220, 0x0003663f},
		{0x50001224, 0x012d9961},
		{0x50001228, 0x0a6e7748},
		{0x5000122C, 0x00405c72},
		{0x50001230, 0xfffffffd},
		{0x50001234, 0x00000101},
		{0x50001238, 0x00ff3afe},
		{0x5000123C, 0x00003759},
		{0x50001200, 0x20080042},
	};
#define D2C_CTRL_ADDR 0x50001200
//hardware d2c regs
#if 1
	pthread_mutex_lock(&gspi_lock);
	for (int i = 0; i < 15; i++)
	{
#if 0
		//addr =  MX6300_RECTIFYREG_ADDR+ (params->rectify_regs[i].reg & 0xFF);
		addr=MX6300_RECTIFYREG_ADDR+ i*8;
		printf("addr=0x%x,value=0x%x\n", addr, params->rectify_regs[i].val);
		tmp = params->rectify_regs[i].reg;
		//tmp =0x12345678;
		int loop = 0;
		while (loop < 10)
		{
			if (obc_sl_spi_download(addr, &tmp, 4) < 0)
			{
				printf("write distortion file failed(i=%d)\n", i);
				fclose(fp);
				free(params);
				return -1;
			}
			obc_sl_spi_upload(addr, &tmpr, 4);
			printf("tmpr==0x%x\n",tmpr);
			loop++;
			if (tmpr == tmp)
			{
				break;
			}
		}
		tmp = params->rectify_regs[i].val;
		while (loop < 10)
		{
			if (obc_sl_spi_download(addr+4, &tmp, 4) < 0)
			{
				printf("write distortion file failed(i=%d)\n", i);
				fclose(fp);
				free(params);
				return -1;
			}
			obc_sl_spi_upload(addr+4, &tmpr, 4);
			printf("tmpr==0x%x\n",tmpr);
			loop++;
			if (tmpr == tmp)
			{
				break;
			}
		}
#else
		int loop = 0;
		while (loop < 10)
		{
			ret = obc_spi_write_mx6300(params->hw_d2c_regs[i].reg, params->hw_d2c_regs[i].val);
			//ret = obc_spi_write_mx6300(d2ctmp[i].reg,d2ctmp[i].val);
			if (ret < 0)
			{
				printf("%s:write hard d2c params(i=%d) failed\n", __FUNCTION__, i);
				fclose(fp);
				free(params);
				pthread_mutex_unlock(&gspi_lock);
				return -1;
			}
			usleep(500);
			ret = obc_spi_read_mx6300(params->hw_d2c_regs[i].reg, &tmpr);
			//ret = obc_spi_read_mx6300(d2ctmp[i].reg, &tmpr);
			if (ret < 0)
			{
				printf("%s:read hard d2c params(i=%d) failed\n", __FUNCTION__, i);
				fclose(fp);
				free(params);
				pthread_mutex_unlock(&gspi_lock);
				return -1;
			}
			printf("hard d2c:addr=0x%x,value=0x%x,read_value=0x%x\n", params->hw_d2c_regs[i].reg, params->hw_d2c_regs[i].val, tmpr);
			//printf("hard d2c:addr=0x%x,value=0x%x,read_value=0x%x\n", d2ctmp[i].reg, d2ctmp[i].val, tmpr);
			if (tmpr == params->hw_d2c_regs[i].val)
			//if (tmpr == d2ctmp[i].val)
			{
				break;
			}
			loop++;
		}
		usleep(1000);
#endif
	}
#endif
	//rectify reg
//enable rectify reg
#define MX6300_RECTIFY_ENABLE_ADDR 0x50001174
	ret = obc_spi_write_mx6300(MX6300_RECTIFY_ENABLE_ADDR, 0x1);
	if (ret < 0)
	{
		printf("%s:enable rectify failed\n", __FUNCTION__);
		fclose(fp);
		free(params);
		pthread_mutex_unlock(&gspi_lock);
		return -1;
	}
	usleep(200);
	//only write single camera
	for (int i = 0; i < 22; i++)
	{
#if 0
		//addr =  MX6300_RECTIFYREG_ADDR+ (params->rectify_regs[i].reg & 0xFF);
		addr=MX6300_RECTIFYREG_ADDR+ i*8;
		printf("addr=0x%x,value=0x%x\n", addr, params->rectify_regs[i].val);
		tmp = params->rectify_regs[i].reg;
		//tmp =0x12345678;
		int loop = 0;
		while (loop < 10)
		{
			if (obc_sl_spi_download(addr, &tmp, 4) < 0)
			{
				printf("write distortion file failed(i=%d)\n", i);
				fclose(fp);
				free(params);
				return -1;
			}
			obc_sl_spi_upload(addr, &tmpr, 4);
			printf("tmpr==0x%x\n",tmpr);
			loop++;
			if (tmpr == tmp)
			{
				break;
			}
		}
		tmp = params->rectify_regs[i].val;
		while (loop < 10)
		{
			if (obc_sl_spi_download(addr+4, &tmp, 4) < 0)
			{
				printf("write distortion file failed(i=%d)\n", i);
				fclose(fp);
				free(params);
				return -1;
			}
			obc_sl_spi_upload(addr+4, &tmpr, 4);
			printf("tmpr==0x%x\n",tmpr);
			loop++;
			if (tmpr == tmp)
			{
				break;
			}
		}
#else
		int loop = 0;
		while (loop < 10)
		{
			ret = obc_spi_write_mx6300(params->rectify_regs[i].reg, params->rectify_regs[i].val);
			if (ret < 0)
			{
				printf("%s:write rectify params(i=%d) failed\n", __FUNCTION__, i);
				fclose(fp);
				free(params);
				pthread_mutex_unlock(&gspi_lock);
				return -1;
			}
			usleep(200);
			ret = obc_spi_read_mx6300(params->rectify_regs[i].reg, &tmpr);
			if (ret < 0)
			{
				printf("%s:read rectify params(i=%d) failed\n", __FUNCTION__, i);
				fclose(fp);
				free(params);
				pthread_mutex_unlock(&gspi_lock);
				return -1;
			}
			printf("addr=0x%x,value=0x%x,read_value=0x%x\n", params->rectify_regs[i].reg, params->rectify_regs[i].val, tmpr);
			if (tmpr == params->rectify_regs[i].val)
			{
				break;
			}
			loop++;
		}
		usleep(1000);
#endif
	}
	ret = obc_spi_write_mx6300(0x50001170, 0x5000);
	if (ret < 0)
	{
		printf("%s:enable rectify failed\n", __FUNCTION__);
		fclose(fp);
		free(params);
		pthread_mutex_unlock(&gspi_lock);
		return -1;
	}
	usleep(1000);

	ret = obc_spi_write_mx6300(MX6300_RECTIFY_ENABLE_ADDR, 0x1);
	if (ret < 0)
	{
		printf("%s:enable rectify failed\n", __FUNCTION__);
		fclose(fp);
		free(params);
		pthread_mutex_unlock(&gspi_lock);
		return -1;
	}
	usleep(1000);
	ret = obc_spi_write_mx6300(0x50001178, 0x1);
	if (ret < 0)
	{
		printf("%s:enable rectify failed\n", __FUNCTION__);
		fclose(fp);
		free(params);
		pthread_mutex_unlock(&gspi_lock);
		return -1;
	}
	fclose(fp);
	free(params);
	pthread_mutex_unlock(&gspi_lock);
	return 0;
}