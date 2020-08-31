#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "ar_dsp_bootup.h"
#include "arm_dsp_io.h"
#include "ar_ion.h"

char* g_va_sys_reg_base;
char* g_va_core0_reg_base;
int fd_sys_reg_base;
int fd_core0_reg_base;

static void ar_clear_dsp_print_buffer(unsigned long addr, unsigned long len)
{
	int fd_mem = 0;
	int offset = 0;
	unsigned long addr_aligned = 0;
	unsigned long len_aligned = 0;

	char * buffer_virt = 0;

	//alignment to 4k
	offset = addr % 0x1000;
	addr_aligned = addr & 0xFFFFF000;
	len_aligned = (len/0x1000 + 1) * 0x1000;

	fd_mem = open("/dev/mem", O_RDWR | O_SYNC);
	if(fd_mem < 0)
	{
		printf("%s %d: open /dev/mem error: %s\r\n", __FUNCTION__, __LINE__, strerror(errno));
		return;
	}

	buffer_virt = mmap(NULL,len_aligned, PROT_READ | PROT_WRITE, MAP_SHARED,fd_mem, addr_aligned);
	if(!buffer_virt)
	{
		printf("%s %d: mmap error: %s\r\n", __FUNCTION__, __LINE__, strerror(errno));
		return;
	}

	memset(buffer_virt+offset, 0, len);

	munmap(buffer_virt, len_aligned);
	close(fd_mem);

}

int sirius_boot_ceva(char* filepath,int dsp_id)
{
    int len,ret;
	int map_size;

	unsigned int  img_addr_pa;
	ceva_parse_info_t ceva_parse_info;

	//hbbai: Clear print buffer first to avoid garbage
	printf("AR_DSP_PRINT_BUFFER_ADDR: %x\r\n",AR_DSP_PRINT_BUFFER_ADDR);
	if(dsp_id == DSP_CORE0)
	{
		ar_clear_dsp_print_buffer(AR_DSP_PRINT_BUFFER_ADDR, AR_DSP_PRINT_BUFFER_LEN);
	}

	ar_ion_init(AR_DSP_ION_HEAP_ID);
	map_size = ar_read_file_len(filepath);
	unsigned int * img_addr_va = (unsigned int*)ar_ion_malloc(sizeof(unsigned int)*map_size);
	if(!img_addr_va)
	{
		printf("ar_ion_malloc img_addr_va failed!\r\n");
		return -1;
	}

	//To be confirmed, should be pa =  ar_ion_virt_to_phy(va);
	img_addr_pa = ar_ion_virt_to_phy(img_addr_va);
	//ret = ar_ion_virt_to_phy(img_addr_va, &img_addr_pa, &len);
	//if(ret < 0)
	if(NULL == img_addr_pa)
	{
		printf("addr_va 2 addr_pa failed!\r\n");
		return -1;
	}

	ret = load_ceva_bin(img_addr_va, filepath);
	if(ret < 0)
	{
		printf("load ceva bin/img file failed!\r\n");
	}

	if( *(unsigned int*)img_addr_va == BOOTLOADER_HEADER)
	{
		ret = parse_dsp_img(&ceva_parse_info, img_addr_va, dsp_id);
	}
	else if( *(unsigned int*)img_addr_va == CEVA_BIN_HEADER)
	{
		ret = parse_dsp_bin(&ceva_parse_info, img_addr_va, dsp_id);
	}
	else
	{
		printf("parse file failed!\r\n");
		ret = -1;
	}

	//Use physical address when loading(PDMA) C0, use virtual address when loading(memcpy) D0/D1/D12
	if(ret == 0 )
	{
		dsp_boot(&ceva_parse_info, img_addr_pa, dsp_id);   //&img_addr_pa cannot access correct addr  ??
	}

	ar_ion_free(img_addr_va);

	return ret;

}

int load_ceva_bin(unsigned int img_addr, char* filepath)
{
	 int ret;
     ret = ar_read_file(img_addr,filepath);
	 return ret;
}

int parse_dsp_bin(ceva_parse_info_t* parse_info, unsigned int img_addr, int dsp_id)
{
    ceva_img_header_t *img_header = NULL;
    img_header = (ceva_img_header_t *)img_addr;

    parse_info->C0_dst_addr  = img_header->start_addr[C0_BIN];
    parse_info->D0_dst_addr  = img_header->start_addr[D0_BIN];
    parse_info->C1_dst_addr  = img_header->start_addr[C1_BIN];
    parse_info->D1_dst_addr  = img_header->start_addr[D1_BIN];
    parse_info->D12_dst_addr = img_header->start_addr[D12_BIN];

    parse_info->C0_src_addr  = (int)img_header        + (int)sizeof(ceva_img_header_t);
    parse_info->D0_src_addr  = parse_info->C0_src_addr + img_header->bin_len[C0_BIN];
    parse_info->C1_src_addr  = parse_info->D0_src_addr + img_header->bin_len[D0_BIN];
    parse_info->D1_src_addr  = parse_info->C1_src_addr + img_header->bin_len[C1_BIN];
    parse_info->D12_src_addr = parse_info->D1_src_addr + img_header->bin_len[D1_BIN];

	parse_info->C0_len  = img_header->bin_len[C0_BIN];
	parse_info->D0_len  = img_header->bin_len[D0_BIN];
	parse_info->C1_len  = img_header->bin_len[C1_BIN];
	parse_info->D1_len  = img_header->bin_len[D1_BIN];
	parse_info->D12_len = img_header->bin_len[D12_BIN];

	parse_info->offset  = sizeof(ceva_img_header_t);

    return 0;

}

unsigned int checksum(unsigned char *buf, int len)
{
	unsigned int checksum = 0;
	int i;
	unsigned int *addr = (unsigned int *)buf;
	unsigned int val = 0;

	while(len>4)
	{
		val = *addr++;
		checksum += (val & 0x0ff) + ((val >> 8)&0x0ff) + ((val >> 16)&0x0ff) + ((val >> 24)&0x0ff);
		len -=4;
	}

	buf = addr;
	while(len--)
	{
		checksum += *buf++;
	}

	return checksum;
}

int parse_dsp_img(ceva_parse_info_t* parse_info, unsigned int img_addr, int dsp_id)
{
    unsigned int calc_check_sum = 0,rdbk_check_sum = 0;
	unsigned int len = 0;
	ceva_bootloader_layout_header_t *img_header = NULL;
    img_header = (ceva_bootloader_layout_header_t *)img_addr;

	rdbk_check_sum = img_header->boot_loader_header.checksum;

	len = (int)sizeof(ceva_img_header_t)  + img_header->ceva_img_header.bin_len[C0_BIN] + img_header->ceva_img_header.bin_len[D0_BIN] \
		  + img_header->ceva_img_header.bin_len[C1_BIN] + img_header->ceva_img_header.bin_len[D1_BIN] + img_header->ceva_img_header.bin_len[D12_BIN];

	calc_check_sum = checksum(&img_header->ceva_img_header, len);

	if( (rdbk_check_sum == calc_check_sum)&&(img_header->boot_loader_header.magic == BOOTLOADER_HEADER) )
	{
		parse_info->C0_dst_addr  = img_header->ceva_img_header.start_addr[C0_BIN];
	    parse_info->D0_dst_addr  = img_header->ceva_img_header.start_addr[D0_BIN];
	    parse_info->C1_dst_addr  = img_header->ceva_img_header.start_addr[C1_BIN];
	    parse_info->D1_dst_addr  = img_header->ceva_img_header.start_addr[D1_BIN];
	    parse_info->D12_dst_addr = img_header->ceva_img_header.start_addr[D12_BIN];

	    parse_info->C0_src_addr  = (int)img_header + (int)sizeof(ceva_bootloader_header_t) + (int)sizeof(ceva_img_header_t);
	    parse_info->D0_src_addr  = parse_info->C0_src_addr + img_header->ceva_img_header.bin_len[C0_BIN];
	    parse_info->C1_src_addr  = parse_info->D0_src_addr + img_header->ceva_img_header.bin_len[D0_BIN];
	    parse_info->D1_src_addr  = parse_info->C1_src_addr + img_header->ceva_img_header.bin_len[C1_BIN];
	    parse_info->D12_src_addr = parse_info->D1_src_addr + img_header->ceva_img_header.bin_len[D1_BIN];

		parse_info->C0_len  = img_header->ceva_img_header.bin_len[C0_BIN];
		parse_info->D0_len  = img_header->ceva_img_header.bin_len[D0_BIN];
		parse_info->C1_len  = img_header->ceva_img_header.bin_len[C1_BIN];
		parse_info->D1_len  = img_header->ceva_img_header.bin_len[D1_BIN];
		parse_info->D12_len = img_header->ceva_img_header.bin_len[D12_BIN];

		parse_info->offset  = (int)sizeof(ceva_bootloader_header_t) + sizeof(ceva_img_header_t);

		return 0;
	}

	return -1;

}

void ar_set_ceva_reg(int dsp_id)
{
 	//unlock ceva power
	ar_write_dsp_reg(/*DSP_POWER_LOCK_REG_ADDR*/ g_va_sys_reg_base + 0x3408, 0x4c43544d);

	//ceva wait
	ar_write_dsp_reg(/*CORE0_WAIT_ADDR*/ g_va_sys_reg_base + 0x3020 + (dsp_id * ARB_REG_INT_CORE_OFFSET), 1);

	//poweron ceva
	ar_set_dsp_reg_bit(g_va_sys_reg_base + 0x3400,(4 + dsp_id));
	ar_set_dsp_reg_bit(g_va_sys_reg_base + 0x3400,(8 + dsp_id));
	ar_set_dsp_reg_bit(g_va_sys_reg_base + 0x3400,(0 + dsp_id));

	ar_write_dsp_reg(/*DSP_POWER_LOCK_REG_ADDR */g_va_sys_reg_base + 0x3408, 0x1234);

	//ceva reset
	 ar_single_dsp_start(dsp_id);

}

int dsp_boot(ceva_parse_info_t* parse_info, unsigned int *addr_pa, int dsp_id)
{
	unsigned int C0_src_addr_pa;

	ar_dsp_reg_init(dsp_id);

	//reset cpu
	ar_dsp_reset(dsp_id);

	//write regs status
	ar_set_ceva_reg(dsp_id);

	//load int data D0
	arm_load_dsp_internal_data(dsp_id, parse_info->D0_dst_addr, parse_info->D0_src_addr, parse_info->D0_len);

	//load int C0 program
	C0_src_addr_pa = (int)addr_pa + (int)parse_info->offset;

	arm_load_dsp_internal_program(dsp_id, parse_info->C0_dst_addr, C0_src_addr_pa, parse_info->C0_len-1);

	arm_load_dsp_ext_data(dsp_id, parse_info);

	ar_write_dsp_reg(/*CORE0_MCCI_OFFSET_ADDR*/ g_va_core0_reg_base + CPM_OFFSET /*+ CORE_OFFSET * (dsp_id)*/ + DBG_GEN_MASK, 0x10000000);

	//ceva wait release
	ar_write_dsp_reg(/*CORE0_WAIT_ADDR*/ g_va_sys_reg_base + 0x3020 + (dsp_id * ARB_REG_INT_CORE_OFFSET), 0);

    	ar_dsp_reg_uninit(dsp_id);

	return 0;

}




 int ar_read_file_len(char* filepath)
{
	int len;
	int fd = open(filepath,O_RDONLY);
	if(fd<0)
	{
		printf("ar_read_file_size error!\r\n");
		return -1;
	}

    len = lseek(fd,0,SEEK_END);
	close(fd);

	return len;

}

int ar_read_file(char* addr,char *filepath)
{
	int nbytes,nread;
	struct stat buf;
	//char * filedata = addr;
	int fd;
	nbytes = ar_read_file_len(filepath);

	fd = open(filepath,O_RDONLY);
	if(fd<0)
	{
	   printf("open file error!\r\n");
	   return -1;
	}

	nread = read(fd,addr,nbytes);
	if(nread<0)
	{
	   printf("read error!\r\n");
	   close(fd);
	   return -1;
	}
	close(fd);
	return 0;
}


void ar_dsp_reg_init(int dsp_id)
{
	fd_sys_reg_base=open("/dev/mem", O_RDWR | O_SYNC);
	g_va_sys_reg_base = mmap(NULL,0x100000, PROT_READ | PROT_WRITE, MAP_SHARED,fd_sys_reg_base,REGISTER_BASE_ADDR);

	fd_core0_reg_base=open("/dev/mem", O_RDWR | O_SYNC);
	g_va_core0_reg_base = mmap(NULL,0x800000, PROT_READ | PROT_WRITE, MAP_SHARED,fd_core0_reg_base,CORE0_OFFSET_ADDR + CORE_OFFSET * (dsp_id));

	ar_write_dsp_reg(g_va_sys_reg_base + ARB_REG_INT_CORE_OFFSET * dsp_id + 0x302C/*CORE_ACU_SLV_ACC*/, 1);
}

void ar_dsp_reg_uninit(int dsp_id)
{
	ar_write_dsp_reg(g_va_sys_reg_base + ARB_REG_INT_CORE_OFFSET * dsp_id + 0x302C/*CORE_ACU_SLV_ACC*/, 0);

	munmap(g_va_sys_reg_base,0x100000);
	close(fd_sys_reg_base);

	munmap(g_va_core0_reg_base,0x800000);
	close(fd_core0_reg_base);
}


int ar_dsp_reset(int dsp_id)
{

	//Pull wait signal
#if 0
	*(volatile long *)(g_va_sys_reg_base + /*DSP_CACHE_START*/0x300C 	 + dsp_id * 0x100) = 0x1;

    *(volatile long *)(g_va_sys_reg_base + 0x1000) = 0x1;
#endif
	*(volatile long *)(g_va_sys_reg_base + /*DSP_WAIT_START*/0x3020   + dsp_id * 0x100) = 0x1;

	//clear reset signal, delay, pull reset
	//global reset
	*(volatile long *)(g_va_sys_reg_base + /*DSP_GLOBAL_RST_START*/0x1004 + dsp_id * 16) = 0x0;

	//core reset
	*(volatile long *)(g_va_sys_reg_base + 0x100c /*Core reset*/ + dsp_id * 16) = 0x0;

#if 0
	*(volatile long *)(g_va_sys_reg_base + /*DSP_GLOBAL_RST_START */0x1004 + dsp_id * 16) = 0x1;

	*(volatile long *)(g_va_sys_reg_base + 0x100c /*Core reset*/ + dsp_id * 16) = 0x1;

	//Invalidate cache
	*(volatile long *)(g_va_sys_reg_base + /*DSP_CACHE_START*/0x300C 	 + dsp_id * 0x100) = 0x1;

	//clear wait signal
	*(volatile long *)(g_va_sys_reg_base + /*DSP_WAIT_START */0x3020+ dsp_id * 0x100) = 0x0;
#endif
	return 0;

}



