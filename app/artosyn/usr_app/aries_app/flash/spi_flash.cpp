#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <signal.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <sys/time.h>
#include "spi_flash.h"


int g_SpiFd = -1;

//erase flash parameter.
int spi_flash_sector_erase(uint32_t addr, uint32_t data_size) 
{
    int i = 0;
    int ret = -1;
    erase_info_t erase;
    uint32_t num_sector=data_size/SECTOR_SIZE;   ///4k擦除
    uint32_t lastsize =data_size%SECTOR_SIZE;
	
    erase.length = SECTOR_SIZE;
    erase.start = addr;
	
    if (g_SpiFd == -1) 
    {
         //printf("%s, open device\n", __func__);
         g_SpiFd = open(FLASH_DEVICE_NAME, O_RDWR);
         if (g_SpiFd == -1) 
	  {
              printf("%s, failed to open device %s. err: %s\n", __func__, FLASH_DEVICE_NAME, strerror(errno));
              return -1;
         }
    }

    for (i = 0; i < num_sector; i++) 
    {
          ret = ioctl(g_SpiFd, FLASH_CMD_MEMERASE, &erase);
          erase.start += SECTOR_SIZE;
    }

    if(lastsize != 0)
    {
         ret = ioctl(g_SpiFd, FLASH_CMD_MEMERASE, &erase);
    }
	
    return ret;
}

int spi_flash_block_read(uint32_t addr,uint8_t *data_ptr,int data_size)
{
    int rc = -1;
    int file_length = data_size;
    int read_len = 0;
	
    if (g_SpiFd == -1) 
    {
         g_SpiFd = open(FLASH_DEVICE_NAME,O_RDWR);
         if (g_SpiFd == -1)	
	  {
             printf("%s, failed to open device %s. err: %s\n",__func__,FLASH_DEVICE_NAME, strerror(errno));
             return -1;
         }
    }
	
    rc = lseek(g_SpiFd ,addr, SEEK_SET);
    read_len = read(g_SpiFd,data_ptr,file_length);
    if(read_len == file_length) 
    {
         //printf("spi_flash_block_read is ok\n");
         rc = 0;
    }
    return rc;
}

int spi_flash_reg_read(uint32_t addr,uint32_t *data_ptr) 
{
    int rc = -1;
    int file_length = 4;
    int read_len = 0;
	
    if (g_SpiFd == -1) 
    {
         g_SpiFd = open(FLASH_DEVICE_NAME,O_RDWR);
         if (g_SpiFd == -1)	
	  {
             printf("%s, failed to open device %s. err: %s\n",__func__,FLASH_DEVICE_NAME, strerror(errno));
             return -1;
         }
    }
	
    rc = lseek(g_SpiFd ,addr, SEEK_SET);
    read_len = read(g_SpiFd,data_ptr,file_length);
    if (read_len == file_length) 
    {
         printf("spi_flash_reg_read is ok\n");
         rc = 0;
    } 
    else 
    {
         printf("%s: spi_flash_reg_read id failed read_len:%d\n",__func__,read_len);
         rc = -1;
    }

    return rc;
}

int spi_flash_block_write(uint32_t addr,uint8_t *data_ptr,int data_size) 
{
    int rc = -1;
    int file_length = data_size;
    int write_len = 0;
	
    if (g_SpiFd == -1) 
    {
        g_SpiFd = open(FLASH_DEVICE_NAME,O_RDWR);
        if (g_SpiFd == -1)	
	 {
            printf("%s, failed to open device %s. err: %s\n",__func__,FLASH_DEVICE_NAME, strerror(errno));
            return -1;
        }
    }
	
    rc = lseek(g_SpiFd ,addr, SEEK_SET);
    write_len = write(g_SpiFd,data_ptr,file_length);
    if(write_len > 0) 
    {
         //printf("spi_flash_block_write is ok\n");
         rc = 0;
    }
    return rc;
}

int flash_block_write(uint32_t addr,uint8_t *data_ptr,int data_size)
{
    uint32_t orb_addr ;

    orb_addr = addr;
    spi_flash_block_write(orb_addr,data_ptr,data_size);

    return 0;
}

int flash_block_read(uint32_t addr,uint8_t *data_ptr,int data_size)
{
    uint32_t orb_addr ;

    orb_addr = addr; 
    spi_flash_block_read(orb_addr,data_ptr, data_size);

    return 0;
}

int write_buffer_to_device(uint8_t * buf,uint32_t bufsize,uint32_t offset,int blocksize)
{
    int prog_time=bufsize/blocksize;
    int lastsize =bufsize%blocksize;
    uint32_t addr=offset;
    uint8_t * buf_ptr_r=buf;
    int ret = -1;
    int i;
	
    printf("write to device:0x%x @ 0x%x ,0x%x,bs:%d,blocksize:%d\n",prog_time,blocksize,lastsize,bufsize,blocksize);

    ret = spi_flash_sector_erase(offset, bufsize);     //写flash前先擦除flash
    if(ret < 0)
    {
         printf("spi_flash_sector_erase failed\n");
         return -1;
    }
	
    for(i=0;i<prog_time;i++)
    {
         flash_block_write(addr,buf_ptr_r,blocksize);
         addr+=blocksize;
         buf_ptr_r+=blocksize;
    }
    if(lastsize!=0)
    {
         flash_block_write(addr,buf_ptr_r,lastsize);
    }

    printf("write_buffer_to_device success\n");
	
    return 0;
}

int read_buffer_from_device(uint8_t * buf,uint32_t bufsize,uint32_t offset,int blocksize)
{
     // download the file
     int prog_time=bufsize/blocksize;
     int lastsize =bufsize%blocksize;
     uint8_t * buf_ptr_r=buf;
     uint32_t addr=offset;
     int i;
	 
     for(i=0;i<prog_time;i++)
     {
         flash_block_read(addr,buf_ptr_r,blocksize);
         addr+=blocksize;
         buf_ptr_r+=blocksize;
     }
     if(lastsize!=0)
     {
         flash_block_read(addr,buf_ptr_r,lastsize);
     }
     return 0;
}


/*flash读写测试，先从指定文件读入数据，然后写入flash，再读出数据，最后将
写入的数据和读出的数据按单个字节比对校验，测试时将该函数放于main主循环调用*/
int write_file_to_device(const char * filename,uint32_t offset,int blocksize)
{
    //1. open the device
    FILE *fp=NULL;
    int filesize = 0;
    uint8_t *buf;
    uint8_t *buf_bk;
    int ret = 0;
    int i;
    struct timeval tv1;
    struct timeval tv2;


    printf("filename: %s\n", filename);
    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Can not open file\n");
        return -1;
    }

    //2. check the file size
    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);


    //3. read file to buffer
    buf = (uint8_t*)malloc(filesize);
    buf_bk = (uint8_t*)malloc(filesize);
    printf("alloc buffers\n");
    memset(buf, 0, filesize);
    memset(buf_bk, 0, filesize);
    printf("buffer alloc ok\n");
    fread(buf, 1,filesize, fp);
    fclose(fp);


    //4. download
    gettimeofday(&tv1,NULL);
    
    write_buffer_to_device(buf,filesize,offset,blocksize);
	
    gettimeofday(&tv2,NULL);
    printf("time-consuming to write data:%ld\n",tv2.tv_sec - tv1.tv_sec);  //秒

    //5. verify the ram
    printf("Verify \n");
    ret = read_buffer_from_device(buf_bk,filesize,offset,blocksize);
    if (ret != 0)
    {
        free(buf);
        free(buf_bk);
        return -3;
    }


    for (i = 0; i < filesize; i++)
    {

        if (buf[i] != buf_bk[i])
        {

            printf("Flash Verify Failed : [0x%08x]: 0x%02x(File) != 0x%02x(Flash)\n", offset + i , buf[i], buf_bk[i]);
	    		
            fp = fopen("/mnt/read.bin", "wa");       //保存出错的文件
            if (fp == NULL)
            {
                printf("Can not open /mnt/read.bin\n");
                return -1;
            }
            fwrite(buf_bk, 1,filesize, fp);
            fclose(fp);
	
	    free(buf);
            free(buf_bk);
            return -4;
        }

    }
    printf("Verify Success\n");

    free(buf);
    free(buf_bk);
	
    return 0;
}

int mx6x_load_firmware(const char *filename,int blocksize)
{
    int ret = 0;

    printf("loading firmware from file\n");
    if(filename)
    {
         ret=write_file_to_device(filename, DOWNLOAD_FIRMWARE, blocksize);
    }

    if(ret!=0)
    {
         printf("Download fireware Failed\n");
    }
    else
    {
         printf("Download fireware Success\n");
    }

    return ret;
}


#if 0

typedef struct OBCameraParams
{
   float l_intr_p[4];           //[fx,fy,cx,cy]
   float r_intr_p[4];          //[fx,fy,cx,cy]
   float r2l_r[9];               //[r00,r01,r02;r10,r11,r12;r20,r21,r22]
   float r2l_t[3];               //[t1,t2,t3]
   float l_k[5];                 //[k1,k2,p1,p2,k3]
   float r_k[5];
}OBCameraParams;

static uint8_t* read_camera_par()
{
    uint8_t *buf = NULL;
	
    buf = (uint8_t *)malloc(sizeof(uint8_t) * 120);
    read_buffer_from_device(buf, 120, DOWNLOAD_FIRMWARE, 256);
    printf("buf[0] = %d, buf[119] = %d\n", buf[0], buf[119]);
	
    return buf;
}

int main(void){

    uint8_t *buf = NULL;
    OBCameraParams *cameraParams = NULL;
    mx6x_load_firmware("/sdcard/spi_bt_128.bin", 128);
}
#endif

