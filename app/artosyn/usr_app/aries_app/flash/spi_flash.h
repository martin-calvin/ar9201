#ifndef _SPI_FLASH_H_
#define _SPI_FLASH_H_

#include "basic_typedef.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


#define FLASH_DEVICE_NAME                  "/dev/mtd0"


#define DOWNLOAD_FIRMWARE	            0x00000000
#define CALIBRATION_FILE_ADDR               0x00000000                               //深度标定文件在flash中的存放地址，包括文件头
#define ALIGN_34_FILE_ADDR                  0x00300000                               //4:3的对齐标定文件在flash中的存放地址，包括文件头
#define ALIGN_169_FILE_ADDR                 0x00310000                               //16:9的对齐标定文件在flash中的存放地址，包括文件头

#define SECTOR_SIZE	                    0x10000                                  //单次擦除块的大小 64KB
#define WRITE_BLOCK_SIZE	            0x01000                                  //单次写入数据的大小 4KB
#define READ_BLOCK_SIZE	                    0x01000                                  //单次读取数据的大小 4KB

typedef struct erase_info_user {
	uint32_t start;
	uint32_t length;
}erase_info_t;

#define FLASH_CMD_MEMERASE             _IOW('M', 2, struct erase_info_user)


int spi_flash_sector_erase(uint32_t addr, uint32_t data_size);
int spi_flash_block_read(uint32_t addr,uint8_t *data_ptr,int data_size);
int spi_flash_reg_read(uint32_t addr,uint32_t *data_ptr);
int spi_flash_block_write(uint32_t addr,uint8_t *data_ptr,int data_size);
int flash_block_write(uint32_t addr,uint8_t *data_ptr,int data_size);
int flash_block_read(uint32_t addr,uint8_t *data_ptr,int data_size);
int read_buffer_from_device(uint8_t * buf,uint32_t bufsize,uint32_t offset,int blocksize);
int write_file_to_device(const char * filename,uint32_t offset,int blocksize);
int mx6x_load_firmware(const char *filename,int blocksize);
int write_buffer_to_device(uint8_t * buf,uint32_t bufsize,uint32_t offset,int blocksize);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif


