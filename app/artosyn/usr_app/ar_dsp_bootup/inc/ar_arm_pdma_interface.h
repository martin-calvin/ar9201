#ifndef __AR_DMA_PDMA_INTERFACE_H__
#define __AR_DMA_PDMA_INTERFACE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

#define MEM_PAGE_SIZE 4096

#define ON_CHIP_PROGRAM_SIZE (32 * 1024)
#define ON_CHIP_DATA_SIZE (128 * 1024)


#define REGISTER_BASE_ADDR 0x64570000
#define ARB_REG_INT_CORE_OFFSET (0x100)
#define CORE0_CACHE_INVALIDATE_REG (REGISTER_BASE_ADDR + 0x300C)

#define ACU_SLV_ACC (REGISTER_BASE_ADDR + 0x302c)
#define REG_CORE_OFFSET (0X100)

#define UART_CONFIG_ADDR 0X8000
#define UART_DATA_ADDR 0x8004
#define UART_TRAN_ADDR 0x8014


#define UART_CONFIG_OFFSET (REGISTER_BASE_ADDR + UART_CONFIG_ADDR)
#define UART_DATA_OFFSET (REGISTER_BASE_ADDR + UART_DATA_ADDR)
#define UART_TRAN_OFFSET (REGISTER_BASE_ADDR + UART_TRAN_ADDR)


#define CORE0_OFFSET_ADDR 0x62000000
#define CORE1_OFFSET_ADDR 0x62800000
#define CORE2_OFFSET_ADDR 0x63000000
#define CORE3_OFFSET_ADDR 0x63800000


#define DBG_GEN_MASK (0Xd28)

#define CORE_OFFSET 0x800000

#define CPM_OFFSET 0x400000

#define DTCM_ADDR (0x0)

#define CORE0_DTCM_ADDR (CORE0_OFFSET_ADDR + DTCM_ADDR)


#define CORE0_MCCI_OFFSET_ADDR (CORE0_OFFSET_ADDR + CPM_OFFSET)
#define CORE1_MCCI_OFFSET_ADDR (CORE1_OFFSET_ADDR + CPM_OFFSET)
#define CORE2_MCCI_OFFSET_ADDR (CORE2_OFFSET_ADDR + CPM_OFFSET)
#define CORE3_MCCI_OFFSET_ADDR (CORE3_OFFSET_ADDR + CPM_OFFSET)


#define DSP_NOC_RESET_ADDR (REGISTER_BASE_ADDR + 0x1044)
#define GLOBAL_RESET_ADDR (REGISTER_BASE_ADDR + 0x1000)
#define CORE0_GLOBAL_RESET_ADDR (REGISTER_BASE_ADDR + 0x1004)
#define CORE0_SYSTEM_RESET_ADDR (REGISTER_BASE_ADDR + 0x1008)
#define CORE0_CORE_RESET_ADDR (REGISTER_BASE_ADDR + 0x100c)
#define CORE0_OCEM_RESET_ADDR (REGISTER_BASE_ADDR + 0x1010)
#define RGU_ADDR_INC_INTER_CORE (0x10)

#define CORE0_WAIT_ADDR (REGISTER_BASE_ADDR + 0x3020)

#define DSP_POWER_REG_ADDR (REGISTER_BASE_ADDR + 0x3400)
#define DSP_POWER_LOCK_REG_ADDR (REGISTER_BASE_ADDR + 0x3408)
#define DSP_POWER_INT_CORE_OFFSET (4)


void ar_write_dsp_reg(unsigned int addr,unsigned int value);
long ar_read_dsp_reg(long addr);
//void ar_set_dsp_reg_bit(unsigned long addr,unsigned int bit);


#define ar_set_dsp_apb_reset(value) ar_write_dsp_reg(GLOBAL_RESET_ADDR, value)
#define ar_set_dsp_cache_invalidate(core_id) ar_write_dsp_reg(CORE0_CACHE_INVALIDATE_REG + ARB_REG_INT_CORE_OFFSET * (core_id), 1)
#define ar_set_dsp_global_reset(core_id, value) ar_write_dsp_reg(CORE0_GLOBAL_RESET_ADDR + (RGU_ADDR_INC_INTER_CORE * core_id), value)
#define ar_set_dsp_system_reset(core_id, value) ar_write_dsp_reg(CORE0_SYSTEM_RESET_ADDR + (RGU_ADDR_INC_INTER_CORE * core_id), value)
#define ar_set_dsp_core_reset(core_id, value) ar_write_dsp_reg(CORE0_CORE_RESET_ADDR + (RGU_ADDR_INC_INTER_CORE * core_id), value)
#define ar_set_dsp_ocem_reset(core_id, value) ar_write_dsp_reg(CORE0_OCEM_RESET_ADDR + (RGU_ADDR_INC_INTER_CORE * core_id), value)
#define ar_reset_noc() ar_write_dsp_reg(DSP_NOC_RESET_ADDR, 0xf)

#define ar_write_dsp_pdea_value(core_id, value) ar_write_dsp_reg(CORE0_MCCI_OFFSET_ADDR + CORE_OFFSET * (core_id) + DSP_MSS_PMSS_PDEA_ADDR, value)

#define ar_write_dsp_pdia_value(core_id, value) ar_write_dsp_reg(CORE0_MCCI_OFFSET_ADDR + CORE_OFFSET * (core_id) + DSP_MSS_PMSS_PDIA_ADDR, value)

#define ar_write_dsp_pdtc_value(core_id, value) ar_write_dsp_reg(CORE0_MCCI_OFFSET_ADDR + CORE_OFFSET * (core_id) + DSP_MSS_PMSS_PDTC_ADDR, value)

#define ar_read_dsp_pdtc_value(core_id, value)  value = ar_read_dsp_reg(CORE0_MCCI_OFFSET_ADDR + CORE_OFFSET * (core_id) + DSP_MSS_PMSS_PDTC_ADDR)

#define ar_set_dsp_wait_macro(core_id) ar_write_dsp_reg(CORE0_WAIT_ADDR + (core_id * ARB_REG_INT_CORE_OFFSET), 1)
#define ar_clear_dsp_wait_macro(core_id) ar_write_dsp_reg(CORE0_WAIT_ADDR + (core_id * ARB_REG_INT_CORE_OFFSET), 0)

#define ar_lock_ceva() ar_write_dsp_reg(DSP_POWER_LOCK_REG_ADDR, 0x1234)
#define ar_unlock_ceva() ar_write_dsp_reg(DSP_POWER_LOCK_REG_ADDR, 0x4c43544d)
#define ar_set_dsp_cache_invalidate(core_id) ar_write_dsp_reg(CORE0_CACHE_INVALIDATE_REG + ARB_REG_INT_CORE_OFFSET * (core_id), 1)

#define ar_set_dsp_apb_reset(value) ar_write_dsp_reg(GLOBAL_RESET_ADDR, value)
#define ar_set_dsp_global_reset(core_id, value) ar_write_dsp_reg(CORE0_GLOBAL_RESET_ADDR + (RGU_ADDR_INC_INTER_CORE * core_id), value)
#define ar_set_dsp_system_reset(core_id, value) ar_write_dsp_reg(CORE0_SYSTEM_RESET_ADDR + (RGU_ADDR_INC_INTER_CORE * core_id), value)
#define ar_set_dsp_core_reset(core_id, value) ar_write_dsp_reg(CORE0_CORE_RESET_ADDR + (RGU_ADDR_INC_INTER_CORE * core_id), value)
#define ar_set_dsp_ocem_reset(core_id, value) ar_write_dsp_reg(CORE0_OCEM_RESET_ADDR + (RGU_ADDR_INC_INTER_CORE * core_id), value)

#define GET_PAGE_COUNT(size) (size/4096+2)


typedef union {
	struct {
		/**
		PDMA transfer count: The number of program bytes to be transferred in a frame.<BR>
		The written value is rounded by the instruction fetch-line width (Bits [4:0] are always zero).<BR>
		This field is decremented by one fetch-line width after each IPM write access.<BR>
		Writing a value to this register starts the DMA transfer.<BR>
		Note: PDIA + PDTC must not exceed the TCM size. */
		unsigned int pdtc			:17;
		unsigned int reserved1		:12;			 /**< Reserved */
		/**
		PDMA status. This read-only bit indicates the PDMA status.<BR>
		When set, the Program DMA is busy, which means that a frame is currently being transferred.<BR>
		When cleared, the DMA is not busy.<BR>
		This bit is automatically set by hardware when a frame transfer starts, and is cleared when the frame transfer has been completed. */
		unsigned int pdst			:1;
		unsigned int reserved2		:1; 			/**< Reserved */
		unsigned int pdie			:1; 			/**< Program DMA interrupt enable.<BR> When set, the program DMA interrupt at the end of transfer is enabled. */
	} field;		  /**< Fields view */
	unsigned int	  overlay;		  /**< Overlay view */
} DSP_MSS_pdma_transfer_control_reg_t;

typedef enum
{
	DSP_MSS_PMSS_PCR_ADDR				= 0x404,	  /**< PDSP_MSS PDMA Program Control Register */
	DSP_MSS_PMSS_PDEA_ADDR				= 0x408,	  /**< PDSP_MSS PDMA External Address Register */
	DSP_MSS_PMSS_PDIA_ADDR				= 0x40C,	  /**< PDSP_MSS PDMA Internal Address Register */
	DSP_MSS_PMSS_PDTC_ADDR				= 0x410,	  /**< PDSP_MSS PDMA Transfer Control */
	DSP_MSS_PMSS_PADD_START_BASE_ADDR	= 0x414,	  /**< PDSP_MSS Memory Region Start Base Address Register*/
	DSP_MSS_PMSS_PADD_ATT0_BASE_ADDR	= 0x418,	  /**< PDSP_MSS Memory Region Attribute Base Register*/
	DSP_MSS_PMSS_CCOSAR_ADDR			= 0x514,	  /**< PDSP_MSS Instruction Cache Operations Start Address Register*/
	DSP_MSS_PMSS_CCOCR_ADDR 			= 0x518,	  /**< PDSP_MSS Instruction Cache Operations Configuration Register*/
	DSP_MSS_PMSS_ECADD_ADDR 			= 0x51C,	  /**< PDSP_MSS ECC Error Address Register*/
	DSP_MSS_PMSS_MAPAR_ADDR 			= 0x520,	  /**< PDSP_MSS Program Memory Access Protection Address Register*/
	DSP_MSS_PMSS_MAPSR_ADDR 			= 0x524,	  /**< PDSP_MSS Program Memory Access Protection Status Register*/
	DSP_MSS_PMSS_AXI_OU_C_ADDR			= 0x528,	  /**< PDSP_MSS PDMA Outstanding And Burst Size Configuration Register*/
	DSP_MSS_PMSS_MECCCOR_ADDR			= 0x530,	  /**< PDSP_MSS AXI Master ECC COR Data Address Register*/
	DSP_MSS_PMSS_PDSP_MSSACS_ADDR			= 0x540,	  /**< PDSP_MSS Enable Access To PDSP_MSS Shadow Registers Register*/
	
	DSP_MSS_DMSS_DMBA_ADDR				= 0x614,	  /**< DDSP_MSS Data Memory Base Address Register*/
	DSP_MSS_DMSS_DMBE_ADDR				= 0x618,	  /**< DDSP_MSS Data Memory Status Register*/
	DSP_MSS_DMSS_HDCFG_ADDR 			= 0x630,	  /**< DDSP_MSS Hardware Memory Configuration Register*/
	DSP_MSS_DMSS_DACC_ADDR				= 0x63c,	  /**< DDSP_MSS ACE Interface Data Protection And DMA Outstanding Configuration Register*/
	DSP_MSS_DMSS_SDCFG_ADDR 			= 0x640,	  /**< DDSP_MSS Single Dimension Memory Configuration Register*/
	DSP_MSS_DMSS_2DCFG1_ADDR			= 0x644,	  /**< DDSP_MSS 2D Memory Configuration First Register*/
	DSP_MSS_DMSS_2DCFG2_ADDR			= 0x648,	  /**< DDSP_MSS 2D Memory Configuration Second Register*/
	
	DSP_MSS_DDMA_DBG_GEN_ADDR			= 0xD14,	  /**< DDMA General Violation First Register*/
	DSP_MSS_DDMA_DBG_GEN2_ADDR			= 0xD24,	  /**< DDMA General Violation Second Register*/
	DSP_MSS_DDMA_DBG_GEN_MASK_ADDR		= 0xD28,	  /**< DDMA General Violation First Mask Register*/
	DSP_MSS_DDMA_DBG_GEN2_MASK_ADDR 	= 0xD2C,	  /**< DDMA General Violation Second Mask Register*/
	
	DSP_MSS_PSU_PSVM_ADDR				= 0xE50,	  /**< PSU Save Mode Register*/
	DSP_MSS_PSU_PGR_ADDR				= 0xE54,	  /**< PSU General Register*/
	
	DSP_MSS_AP_MAPAR_ADDR				= 0xC80,	  /**< AP Memory Access Protection Address Register*/
	DSP_MSS_AP_MAPSR_ADDR				= 0xC84,	  /**< AP Memory Access Protection Status Register*/
	DSP_MSS_AP_DTAP_ADDR				= 0xC88,	  /**< AP TCM Access Protection Register*/
	
	DSP_MSS_IC_ADD_START_BASE_ADDR		= 0x720,	  /**< IC Interface Configuration Memory Region Start Base Address Register*/
	DSP_MSS_IC_ADD_ATT0_BASE_ADDR		= 0x724,	  /**< IC Interface Configuration Memory Region Attribute 0 Base Register*/
	DSP_MSS_IC_ADD_ATT1_BASE_ADDR		= 0x728,	  /**< IC Interface Configuration Memory Region Attribute 1 Base Register*/
	
	DSP_MSS_WD_SYSTIML_ADDR 			= 0x680,	  /**< WD DSP_MSS System Clock LSB Register*/
	DSP_MSS_WD_SYSTIMH_ADDR 			= 0x684 	  /**< WD DSP_MSS System Clock MSB Register*/
}	DSP_MSS_regs_addr_e;

typedef struct
{
	unsigned int global_reset;
	unsigned int system_reset;
	unsigned int core_reset;
	unsigned int ocem_reset;
} dsp_rgu_t;

extern char* g_va_sys_reg_base;
extern char* g_va_core0_reg_base;
extern int fd_sys_reg_base;
extern int fd_core0_reg_base;

extern void arm_load_dsp_internal_program(const unsigned int dsp_id, unsigned int int_address, unsigned int ext_address, unsigned int size);

#endif


