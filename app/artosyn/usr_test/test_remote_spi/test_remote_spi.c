#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "ar_log.h"
#include <sys/mman.h>
#include "backtrace.h"
#include "Mx6300.h"
#include "libremote_spi.h"
#include "test_remote_spi.h"

//this test is for smart_usbcam, connection with TOF sensor, use spi 2

#define MX6300_SENSOR_ID 0x6300
#define MX6300_FIRMWARE_ADDR 0x00
#define MX6300_REFERENCE_ADDR 0x800000
#define MX6300_CMD_ID_FAST_READ 0x0B
#define MX6300_CMD_ID_PAGE_PROGRAM 0x02
#define MX6300_CMD_ID_STATUS 0x05
#define MX6300_CMD_ID_SENSOR_ID 0x90
#define MX6300_BASE_ADDR 0xC0
#define MX6300_DEV_ID_ADDR 0x0
#define MX6300_FW_VER_ADDR 0x2
///////////////////////////////////////////////////////////////
typedef struct
{
	int spi_port;
	remote_stru_spi_init spi_init_pra;
} test_spi_context_t;

test_spi_context_t  gp_context ;
unsigned int gfd;
static inline unsigned char BYTE_REVERSE(unsigned char byte_data)
{
	byte_data=((byte_data>>1)&0x55)|((byte_data<<1)&0xAA);
	byte_data=((byte_data>>2)&0x33)|((byte_data<<2)&0xCC);\
	byte_data=(byte_data>>4)|(byte_data<<4);
	return byte_data;
}
uint32_t  MX6300_base_addr;
static void delay_ms(int ms)
{
    usleep(ms * 1000);
}

uint32_t mx6300_register_address_aligned(uint32_t tgt_address, uint8_t *align_offset)
{
    *align_offset = tgt_address % 4;
    return MX6300_base_addr + (tgt_address - *align_offset);
}
int mx6300_write_raw_cmd(int  fd, uint32_t code, uint32_t data)
{
    int ret=0;

    uint32_t offset_addr = MX6300_base_addr + 0xF0;
   spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 16;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0]= MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1]= offset_addr >> 16;
	spi_xfer_param.txbuf[2]= offset_addr >> 8;
	spi_xfer_param.txbuf[3]= offset_addr & 0xff;
    spi_xfer_param.txbuf[4] = 1;
    spi_xfer_param.txbuf[5] = 0;
    spi_xfer_param.txbuf[6] = 4;
    spi_xfer_param.txbuf[7] =  code & 0xFF;
	spi_xfer_param.txbuf[8] = (code & 0xFF00) >> 8;
	spi_xfer_param.txbuf[12] = (data & 0xFF000000) >> 24;
    spi_xfer_param.txbuf[11] = (data & 0xFF0000) >> 16;
    spi_xfer_param.txbuf[10] = (data & 0xFF00) >> 8;
    spi_xfer_param.txbuf[9] = data & 0xFF;

	ret = remote_spi_master_xfer(gfd, &spi_xfer_param);
	if(ret!=0)
	{
		printf("%s failed(code=0x%x,data=0x%x, ret = %d)\n", __func__,code,data,ret);
	}
	return ret;
}
int mx6300_read_raw_cmd(int  fd, uint32_t code)
{
    int ret;
    int recive_data = 0;
    uint32_t offset_addr = MX6300_base_addr + 0xF0;

    spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component =gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TR;
	spi_xfer_param.txlen = 16;
	spi_xfer_param.rxlen = 16;
	spi_xfer_param.txbuf[0]= MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1]= offset_addr >> 16;
	spi_xfer_param.txbuf[2]= offset_addr >> 8;
	spi_xfer_param.txbuf[3]= offset_addr & 0xff;
	spi_xfer_param.txbuf[4]= 0;
	spi_xfer_param.txbuf[5]= 0;
	spi_xfer_param.txbuf[6]= 0;
	spi_xfer_param.txbuf[7]= code & 0xFF; 
    spi_xfer_param.txbuf[8]= (code & 0xFF00) >> 8;
	spi_xfer_param.txbuf[9]= 0;

    delay_ms(10);

	ret = remote_spi_master_xfer(fd, &spi_xfer_param);
	if(0!=ret)
	{
		printf("%s failed(code=0x%x, ret = %d)\n", __func__,code,ret);
		return ret;
	}
    recive_data = (spi_xfer_param.rxbuf[14] << 24) + (spi_xfer_param.rxbuf[13] << 16) + (spi_xfer_param.rxbuf[12] << 8) + spi_xfer_param.rxbuf[11];

    printf("raw cmd recv data: %#x\r\n", recive_data);

    return recive_data;
}
///////////////////////////////////////////////////////////////////
int mx6300_read_align_register(int fd, unsigned int addr)
{
    int ret = 0;
    int recive_data = 0;
    uint8_t align_offset = 0;
    uint32_t offset_addr = mx6300_register_address_aligned(addr & 0xFFFF, &align_offset);


	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component =gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TR;
	spi_xfer_param.txlen = 10;
	spi_xfer_param.rxlen = 10;
	spi_xfer_param.txbuf[0]= MX6300_CMD_ID_FAST_READ;
	spi_xfer_param.txbuf[1]= offset_addr >> 16;
	spi_xfer_param.txbuf[2]= offset_addr >> 8;
	spi_xfer_param.txbuf[3]= offset_addr & 0xff;
	spi_xfer_param.txbuf[4]= 0;
	spi_xfer_param.txbuf[5]= 0;
	spi_xfer_param.txbuf[6]= 0;
	spi_xfer_param.txbuf[7]= 0;
    spi_xfer_param.txbuf[8]= 0;
	spi_xfer_param.txbuf[9]= 0;

	ret = remote_spi_master_xfer(fd, &spi_xfer_param);
	if(0!=ret)
	{
		printf("%s failed(addr=0x%x, ret = %d)\n", __func__,addr,ret);
		return ret;
	}
    recive_data = (spi_xfer_param.rxbuf[6] << 24) + (spi_xfer_param.rxbuf[7] << 16) + (spi_xfer_param.rxbuf[8] << 8) + spi_xfer_param.rxbuf[9];
    printf("w-read:data=0x%x\n", recive_data);
    return recive_data;
}
int mx6300_write_register(int fd,uint32_t addr,  uint32_t data)
//int mx6300_write_register(ISP_DEV ViPipe, UINT32T addr, UINT32T data)
{
	int ret;
	

    uint32_t addr_tmp = addr & 0xFFFF;

    if (addr_tmp >= 0xf000)
    {
        //Raw command
        return mx6300_write_raw_cmd(fd, addr_tmp, data);
    }

    uint32_t cur_val = mx6300_read_align_register(fd, addr & 0xFFFF);
    uint8_t align_offset = 0;
    //int data8bit = addr >> 16;
    uint32_t offset_addr = mx6300_register_address_aligned(addr & 0xFFFF, &align_offset);

    spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 8;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0]= MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1]= offset_addr >> 16;
	spi_xfer_param.txbuf[2]= offset_addr >> 8;
	spi_xfer_param.txbuf[3]= offset_addr & 0xff;
    spi_xfer_param.txbuf[4] = (cur_val & 0xFF000000) >> 24;
    spi_xfer_param.txbuf[5] = (cur_val & 0xFF0000) >> 16;
    spi_xfer_param.txbuf[6] = (cur_val & 0xFF00) >> 8;
    spi_xfer_param.txbuf[7] = (cur_val & 0xFF);
    spi_xfer_param.txbuf[4 + align_offset] = data & 0xFF;
	ret = remote_spi_master_xfer(gfd, &spi_xfer_param);
	if(ret!=0)
	{
		printf("%s failed(addr=0x%x, ret = %d)\n", __func__,addr,ret);
	}
	return ret;
}

int mx6300_read_base_addr(int  fd)
{
    int ret = 0;
   spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component =gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TR;
	spi_xfer_param.txlen = 10;
	spi_xfer_param.rxlen = 10;

	spi_xfer_param.txbuf[0]= MX6300_CMD_ID_FAST_READ;
	spi_xfer_param.txbuf[1]= 0;
	spi_xfer_param.txbuf[2]= 0;
	spi_xfer_param.txbuf[3]= MX6300_BASE_ADDR;
    spi_xfer_param.txbuf[4] = 0;
    spi_xfer_param.txbuf[5] = 0;
    spi_xfer_param.txbuf[6] = 0;
    spi_xfer_param.txbuf[7] = 0;
    spi_xfer_param.txbuf[8] = 0;
    spi_xfer_param.txbuf[9] = 0;
	ret = remote_spi_master_xfer(gfd, &spi_xfer_param);
	if(ret!=0)
	{
		printf("%s failed(ret = %d)\n", __func__,ret);
	}

    MX6300_base_addr = (spi_xfer_param.rxbuf[9] << 24) + (spi_xfer_param.rxbuf[8] << 16) + (spi_xfer_param.rxbuf[7] << 8) + spi_xfer_param.rxbuf[6];
	//MX6300_base_addr=0x15770;
    printf("MX6300_base_addr=0x%x\n", MX6300_base_addr);

   return ret;
}

int mx6300_read_register(int fd, unsigned int addr)
{
    int ret = 0;
    printf("addr=%#x\n", addr);
    uint32_t addr_tmp = addr & 0xFFFF;
    if (addr_tmp >= 0xf000)
    {
        //Raw command
        return mx6300_read_raw_cmd(fd, addr_tmp);
    }
    int recive_data = 0;
    uint8_t align_offset = 0;
    //int data8bit = addr>>16;
    uint32_t offset_addr = mx6300_register_address_aligned(addr & 0xFFFF, &align_offset);

   spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component =gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TR;
	spi_xfer_param.txlen = 10;
	spi_xfer_param.rxlen = 10;

	spi_xfer_param.txbuf[0]= MX6300_CMD_ID_FAST_READ;
	spi_xfer_param.txbuf[1]= offset_addr >> 16;
	spi_xfer_param.txbuf[2]= offset_addr >> 8;
	spi_xfer_param.txbuf[3]= offset_addr &0xff;
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

	 ret = remote_spi_master_xfer(gfd, &spi_xfer_param);
	if(ret!=0)
	{
		printf("%s failed(addr=0x%x,ret = %d)\n", __func__,addr,ret);
	}
    recive_data =   spi_xfer_param.rxbuf[6 + align_offset];
    if (addr == MX6300_DEV_ID_ADDR)
    {
        recive_data = (spi_xfer_param.rxbuf[6] << 8) + spi_xfer_param.rxbuf[7];
    }
    else if (addr == MX6300_FW_VER_ADDR)
    {
        recive_data = (spi_xfer_param.rxbuf[8] << 16) + (spi_xfer_param.rxbuf[9] << 8) + spi_xfer_param.rxbuf[10];
    }

    printf("read:0ffset=%d,receive_data=0x%x\n", align_offset, recive_data);
    return recive_data;
}
static int obc_tof_spi_write(int fd, test_spi_context_t *p_context,  int data)
{
	int ret;
	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = p_context->spi_port;
	spi_xfer_param.pst_spi_init_info = p_context->spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = 4;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0]= 0xF0;
	spi_xfer_param.txbuf[1]= 0x35;
	spi_xfer_param.txbuf[2]=0xAA;
	spi_xfer_param.txbuf[3]= 0x55;

	ret = remote_spi_master_xfer(fd, &spi_xfer_param);
	return ret;
}

char* g_va_sys_reg_base;
int fd_sys_reg_base;
int ar_gpio_register_control()
{
    fd_sys_reg_base=open("/dev/mem", O_RDWR | O_SYNC);
	g_va_sys_reg_base = mmap(NULL,0x100000, PROT_READ | PROT_WRITE, MAP_SHARED,fd_sys_reg_base,0x40460000);//0x40420024

    // ar_write_dsp_reg(g_va_sys_reg_base + 0x24/*CORE_ACU_SLV_ACC*/, 0x80); //
    /* reset pin ctrl */
    (*(g_va_sys_reg_base + 0x10))  |= (1<<6); // dir-output


    (*(g_va_sys_reg_base + 0x0C)) |= (1<<6) ; // low
	 usleep(20000);
    (*(g_va_sys_reg_base + 0x0C)) |= (1<<6) ;//high

     //ar_delay(100);//delay 100ms
     usleep(20000);
   (*(g_va_sys_reg_base + 0x0C)) &= ~(1<<6) ; // low
    /* power pin ctrl */
	usleep(20000);
	//ar_delay(100);
	close(fd_sys_reg_base);
    return 0;
}
static char* firmware_file ="firmware.bin";
#define FIRMWARE_FILE_SIZE 64*1024

static int obc_sl_spi_write_file(uint32_t addr, uint8_t* buf,uint32_t size)
{
     int ret;
	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = gp_context.spi_port;
	spi_xfer_param.pst_spi_init_info = gp_context.spi_init_pra;
	spi_xfer_param.tmod = TO;
	spi_xfer_param.txlen = size+4;
	spi_xfer_param.rxlen = 0;
	spi_xfer_param.txbuf[0]= MX6300_CMD_ID_PAGE_PROGRAM;
	spi_xfer_param.txbuf[1]= addr >> 16;
	spi_xfer_param.txbuf[2]= addr >> 8;
	spi_xfer_param.txbuf[3]= addr & 0xff;
	for(int i=0;i<size;i++)
	{
		spi_xfer_param.txbuf[i+4] =buf[i];
	}

	ret = remote_spi_master_xfer(gfd, &spi_xfer_param);
	return ret;
}
#define MAX_PACKET_SIZE 12
int obc_sl_download_mx6300_firmware( uint8_t* buf,  uint32_t length, uint32_t  address)
{
    uint32_t count = length /MAX_PACKET_SIZE;
	uint8_t left = length%MAX_PACKET_SIZE;
    uint32_t file_addr = address;
    uint32_t file_offset = 0;
	uint8_t* file_buf = buf;
    uint8_t file_left[MAX_PACKET_SIZE]={0};
    for (int offset = 0; offset < count; offset++)
    {
        if (obc_sl_spi_write_file( file_addr, file_buf,MAX_PACKET_SIZE) <0)
        {
            printf("write firmware file failed(offset=0x%x)\n",offset);
			return -1;
        }
       file_buf += MAX_PACKET_SIZE;
		file_addr +=MAX_PACKET_SIZE;
    }
	if(left>0)
	{
       memcpy(file_left,file_buf,left);
     if (obc_sl_spi_write_file( file_addr, file_left,MAX_PACKET_SIZE) <0)
        {
            printf("write firmware file failed(left=0x%x)\n",left);
			return -1;
        }
	}
	
    return 0;
}
static int obc_sl_load_binary(char* file,uint32_t file_size)
{
 
       FILE* fp = fopen(file,"rb");
       if(fp==NULL)
	   {
          printf("load firmwarefile Failed\n");
		  return -1;
 	   }
		uint8_t*  file_buf = calloc(1,file_size);
		uint32_t size = fread(file_buf,1,file_size,fp);
		if(size != file_size)
		{
         printf("file size readed is not matched,size=0x%x\n",size);
		}
        if(obc_sl_download_mx6300_firmware(file_buf,size,MX6300_FIRMWARE_ADDR)==0)
		{
              printf("download firmware file success\n");
		}else{
			   printf("download firmware file failed\n");
		}
		free(file_buf);
		fclose(fp);
		return 0;
}

static int obc_tof_spi_read_id(int fd, test_spi_context_t *p_context)
{
	int ret;
	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = p_context->spi_port;
	spi_xfer_param.pst_spi_init_info = p_context->spi_init_pra;
	spi_xfer_param.tmod = TR;
	spi_xfer_param.txlen = 6;
	spi_xfer_param.rxlen = 6;
	spi_xfer_param.txbuf[0]= MX6300_CMD_ID_SENSOR_ID;
	spi_xfer_param.txbuf[1]= 0; //reg_high
	spi_xfer_param.txbuf[2]= 0;
	spi_xfer_param.txbuf[3]= 0;
	spi_xfer_param.txbuf[4]= 0;
	spi_xfer_param.txbuf[5]= 0; //reg_high

	ret = remote_spi_master_xfer(fd, &spi_xfer_param);
	if(0!=ret)
	{
		printf("obc tof spi first read, ret = %d\n", ret);
		return ret;
	}
	int id = spi_xfer_param.rxbuf[4]<<8+ spi_xfer_param.rxbuf[5];
	printf("ID=0x%x\n",id);
	return ret;
}

/*static int axon_tof_spi_read_reg(int fd, test_spi_context_t *p_context, int reg, int *data)
{
	int ret;

	// ar_printf("[%d:%s] read 0x%x:0x%x\n",__LINE__,__FUNCTION__,reg);

	//start read feedback
	ret = axon_tof_spi_write_reg(fd, p_context, 0xC02B,1);
	if(0!=ret)
	{
		printf("axon tof spi read enable\n");
		return ret;
	}

	spi_rpc_xfer_t spi_xfer_param;
	spi_xfer_param.e_spi_component = p_context->spi_port;
	spi_xfer_param.pst_spi_init_info = p_context->spi_init_pra;
	spi_xfer_param.tmod = TR;
	spi_xfer_param.txlen = 8;
	spi_xfer_param.rxlen = 8;
	spi_xfer_param.txbuf[0]= BYTE_REVERSE( (unsigned char)( reg & 0x00FF) ); //reg_low;
	spi_xfer_param.txbuf[1]= BYTE_REVERSE( (unsigned char)( (reg>>8) & 0x00FF) ); //reg_high
	spi_xfer_param.txbuf[2]= 0;
	spi_xfer_param.txbuf[3]= 0;
	spi_xfer_param.txbuf[4]= BYTE_REVERSE( (unsigned char)( reg & 0x00FF) ); //reg_low;
	spi_xfer_param.txbuf[5]= BYTE_REVERSE( (unsigned char)( (reg>>8) & 0x00FF) ); //reg_high
	spi_xfer_param.txbuf[6]= 0;
	spi_xfer_param.txbuf[7]= 0;

	ret = remote_spi_master_xfer(fd, &spi_xfer_param);
	if(0!=ret)
	{
		printf("axon tof spi first read, ret = %d\n", ret);
		return ret;
	}

	//stop read feedback
	ret = axon_tof_spi_write_reg(fd, p_context, 0xC02B,0);
	if(0!=ret)
	{
		printf("axon tof spi read disable\n");
		return ret;
	}

	return ret;
}*/


int main(int argc, char const *argv[])
{
	/* code */
	back_trace_t *back_trace=creat_back_trace();

	unsigned int fd = remote_spi_open(DEV_REMOTE_SPI_PATH);
	if(0 == fd)
	{
		printf("fail to open %s, exit...\n", DEV_REMOTE_SPI_PATH);
		return -1;
	}

	printf("success to open %s : 0x%x\n",DEV_REMOTE_SPI_PATH,fd);

	spi_rpc_xfer_t spi_xfer = {0};
	spi_xfer.pst_spi_init_info.e_halSpiPhase = HAL_SPI_PHASE_2EDGE;
	spi_xfer.pst_spi_init_info.e_halSpiPolarity = HAL_SPI_POLARITY_HIGH;
	spi_xfer.pst_spi_init_info.u16_halSpiBaudr = 20;

	test_spi_context_t p_context  = {0};
	p_context.spi_init_pra =spi_xfer.pst_spi_init_info;
	p_context.spi_port = 3;
   gp_context = p_context;
   gfd = fd;

	int ret;
	int data = 0;
	//while(1)
	{
		/*ret = axon_tof_spi_write_reg(fd, &p_context, 0xc3cc, data);
		if(ret < 0){
			printf("write error\n");
			break;
		}
		ret = axon_tof_spi_read_reg(fd, &p_context, 0xc3cc, &data);
		if(ret < 0){
			printf("read error\n");
			break;
		}*/
		//obc_tof_spi_write(fd,&p_context,data);
		//ar_gpio_register_control();
		ar_gpio_register_control();
		obc_tof_spi_read_id(fd,&p_context);
		obc_sl_load_binary(firmware_file,FIRMWARE_FILE_SIZE);
		ar_gpio_register_control();
		obc_tof_spi_read_id(fd,&p_context);
		//printf("linux data = 0x%08x\n", data);
		//data++;
		usleep(50000);
		mx6300_read_base_addr(gfd);
	}

    char ch;
   ch = (char)getchar();
   mx6300_read_base_addr(gfd);
   //(void)getchar();
   ch = (char)getchar();
    int addr=0;
	  int value=0;
   while(ch !='q'){

   switch(ch)
   {
     case '0':
	    printf("close stream\n");
       mx6300_write_register(gfd,MX6300_CMD_SET_DEV_CTL_ADDR,0x0);
       break;
     case '1':
     printf("open stream\n");
     mx6300_write_register(gfd,MX6300_CMD_SET_DEV_CTL_ADDR,0x12);
       break;
	 case '2':
	 
	  fflush(stdin);
	  printf("please input addr and value");
        ret = scanf("%x %x",&addr,&value);
		mx6300_write_register(gfd,addr,value);
		break;
      default:
       break;
   }
   ch = (char)getchar();
  }
	if(remote_spi_close(fd))
	{
		printf("fail to close 0x%x, exit...\n",fd);
		return -1;
	}

	printf("test over, exit...\n");
	return 0;
}
