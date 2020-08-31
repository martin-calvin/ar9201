#include "ar_arm_pdma_interface.h"
#include "ar_dsp_bootup.h"


dsp_rgu_t dsp_rgu;

void ar_set_dsp_reg_bit(unsigned int addr,unsigned int bit)
{
	*(volatile long*)(addr) = *(volatile long*)(addr)|(0x01<<bit);
}


int ar_single_dsp_start(unsigned int dsp_core_id)
{

	ar_write_dsp_reg(/*CORE0_CACHE_INVALIDATE_REG */g_va_sys_reg_base + 0x300C + ARB_REG_INT_CORE_OFFSET * (dsp_core_id), 1);

	dsp_rgu.global_reset = 0x1;
	dsp_rgu.system_reset = 0x1;
	dsp_rgu.core_reset   = 0x1;
	dsp_rgu.ocem_reset   = 0x1;

	ar_write_dsp_reg(/*GLOBAL_RESET_ADDR */g_va_sys_reg_base + 0x1000 , dsp_rgu.global_reset);

	ar_write_dsp_reg(/*CORE0_GLOBAL_RESET_ADDR*/ g_va_sys_reg_base + 0x1004 + (RGU_ADDR_INC_INTER_CORE * dsp_core_id), dsp_rgu.global_reset);
	ar_write_dsp_reg(/*CORE0_SYSTEM_RESET_ADDR*/ g_va_sys_reg_base + 0x1008 + (RGU_ADDR_INC_INTER_CORE * dsp_core_id), dsp_rgu.system_reset);
	ar_write_dsp_reg(/*CORE0_CORE_RESET_ADDR*/ g_va_sys_reg_base + 0x100C + (RGU_ADDR_INC_INTER_CORE * dsp_core_id), dsp_rgu.core_reset);
	ar_write_dsp_reg(/*CORE0_OCEM_RESET_ADDR*/ g_va_sys_reg_base + 0x1010 + (RGU_ADDR_INC_INTER_CORE * dsp_core_id), dsp_rgu.ocem_reset);
	ar_write_dsp_reg(/*DSP_NOC_RESET_ADDR*/ g_va_sys_reg_base + 0x1044, 0xf);


	return 0;
}


void arm_load_dsp_internal_program(const unsigned int dsp_id, unsigned int int_address, unsigned int ext_address, unsigned int size)
{
	DSP_MSS_pdma_transfer_control_reg_t pdtc;

	do
	{
		ar_read_dsp_reg(/*CORE0_MCCI_OFFSET_ADDR */g_va_core0_reg_base + CPM_OFFSET  /*+ CORE_OFFSET * (dsp_id) */+ DSP_MSS_PMSS_PDTC_ADDR);

	} while (pdtc.field.pdst);   //check pdst status ,if set ,not writable!!

	pdtc.field.pdtc = size;

	ar_write_dsp_reg(/*CORE0_MCCI_OFFSET_ADDR */g_va_core0_reg_base + CPM_OFFSET /*+ CORE_OFFSET * (dsp_id)*/ + DSP_MSS_PMSS_PDEA_ADDR, ext_address);

	ar_write_dsp_reg(/*CORE0_MCCI_OFFSET_ADDR */g_va_core0_reg_base + CPM_OFFSET /*+ CORE_OFFSET * (dsp_id)*/ + DSP_MSS_PMSS_PDIA_ADDR, int_address);

	ar_write_dsp_reg(/*CORE0_MCCI_OFFSET_ADDR */g_va_core0_reg_base + CPM_OFFSET /*+ CORE_OFFSET * (dsp_id) */+ DSP_MSS_PMSS_PDTC_ADDR, (unsigned int)pdtc.overlay);
	do
	{
		ar_read_dsp_reg(/*CORE0_MCCI_OFFSET_ADDR */g_va_core0_reg_base + CPM_OFFSET /* + CORE_OFFSET * (dsp_id)*/ + DSP_MSS_PMSS_PDTC_ADDR);
	} while (pdtc.field.pdst);

}



int arm_load_dsp_ext_data(int dsp_id, ceva_parse_info_t* parse_info)
{
	char * C1_addr_dst_va;
	char * D1_addr_dst_va ;
	char * D12_addr_dst_va ;
	int tmp_len = 0;

	uint32_t start =0;
	uint32_t offset=0;

    int fd = open("/dev/mem",O_RDWR | O_SYNC);
	if(fd<0)
	{
		printf("arm_load_dsp_internal_data:open /dev/mem failed!\r\n");
		return;
	}

	start=parse_info->C1_dst_addr & ~(MEM_PAGE_SIZE-1);
	offset=parse_info->C1_dst_addr-start;

	tmp_len = (parse_info->C1_len / MEM_PAGE_SIZE + 1) * MEM_PAGE_SIZE;
	C1_addr_dst_va = mmap(NULL,tmp_len, PROT_READ | PROT_WRITE, MAP_SHARED,fd,start);
	C1_addr_dst_va = ((uint32_t)C1_addr_dst_va +offset);

	memcpy((char*)C1_addr_dst_va,(char*)parse_info->C1_src_addr,parse_info->C1_len);
	munmap(C1_addr_dst_va, tmp_len);

	start=parse_info->D1_dst_addr & ~(MEM_PAGE_SIZE-1);
	offset=parse_info->D1_dst_addr-start;
	tmp_len = (parse_info->D1_len / MEM_PAGE_SIZE + 1) * MEM_PAGE_SIZE;
	D1_addr_dst_va = mmap(NULL,tmp_len, PROT_READ | PROT_WRITE, MAP_SHARED,fd,start);
	D1_addr_dst_va = ((uint32_t)D1_addr_dst_va +offset);

	memcpy((char*)D1_addr_dst_va,(char*)parse_info->D1_src_addr,parse_info->D1_len);
	munmap(D1_addr_dst_va,tmp_len);

	start=parse_info->D12_dst_addr & ~(MEM_PAGE_SIZE-1);
	offset=parse_info->D12_dst_addr-start;

	tmp_len = (parse_info->D12_len / MEM_PAGE_SIZE + 1) * MEM_PAGE_SIZE;
	D12_addr_dst_va = mmap(NULL,tmp_len, PROT_READ | PROT_WRITE, MAP_SHARED,fd,parse_info->D12_dst_addr);
	D12_addr_dst_va = ((uint32_t)D12_addr_dst_va +offset);

	memcpy((char*)D12_addr_dst_va,(char*)parse_info->D12_src_addr,parse_info->D12_len);
	munmap(D12_addr_dst_va,tmp_len);

	close(fd);

	return 0;
}



int arm_load_dsp_internal_data(int dsp_id, unsigned int dst_addr, unsigned int src_addr, unsigned int size )
{
	dst_addr = dst_addr + /*CORE0_DTCM_ADDR*/ g_va_core0_reg_base + DTCM_ADDR /* + dsp_id * CORE_OFFSET*/;

	memcpy((void*)dst_addr,(void*)src_addr,size);

	return 0;
}


void ar_write_dsp_reg(unsigned int addr,unsigned int value)
{
	*(volatile long*)(addr) = (long)value;
}




long ar_read_dsp_reg(long addr)
{
    long value;
	value = *(long*)(addr);
	return value;
}







