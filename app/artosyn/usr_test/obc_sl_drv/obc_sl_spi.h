#pragma once
#ifndef  _OBC_SL_SPI_H_
#define _OBC_SL_SPI_H_
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */
#include "libremote_spi.h"
#define DEV_REMOTE_SPI_PATH ("/dev/remote_spi")
#define SPI_DEV_PORT 3
//typedef unsigned int uint32_t;
//typedef unsigned char  uint8_t;
typedef enum{
    SPI_DEV_NONE= -1,
    SPI_DEV_MX6300 =0,
    SPI_DEV_FLASH =1,
} spi_dev_type;
typedef struct{
   int spi_fd;
   spi_dev_type dev_type;
   uint32_t regaddr; 
   uint8_t* pdata;
   uint32_t dataLen;
}spi_ctrl_msg;
typedef struct
{
	int spi_port;
	remote_stru_spi_init spi_init_pra;
} spi_context_t;

/*typedef struct 
{
    uint8_t bus;
	uint8_t slave_addr;
	uint32_t reg;
	uint8_t reg_len; //register lenth 1->1, 2->2
	uint32_t data;
	uint8_t data_len;//data length 1->,2->2
}mx6300_i2c_ctrl;*/

int obc_sl_spi_open();
int obc_sl_spi_close(int fd);
int obc_sl_spi_write(spi_ctrl_msg* ctrl_msg);
int obc_sl_spi_read(spi_ctrl_msg* ctrl_msg);
int obc_sl_spi_erase_flash(uint32_t addr,uint32_t size);
int obc_sl_spi_write_i2c(uint8_t bus,uint8_t slave_addr,uint32_t reg,uint8_t reg_len,uint32_t data,uint8_t data_len);
int obc_sl_spi_read_i2c(uint8_t bus,uint8_t slave_addr,uint32_t reg,uint8_t reg_len,uint32_t* data,uint8_t data_len);
int obc_sl_spi_params_sync();
int obc_sl_spi_mx6300_setBaseAddr(uint32_t base_addr);
int obc_sl_spi_send_rectify_param();
int obc_spi_write_ldp_calibrate_data(uint8_t* pdata);
int obc_sl_spi_open_mini();

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif