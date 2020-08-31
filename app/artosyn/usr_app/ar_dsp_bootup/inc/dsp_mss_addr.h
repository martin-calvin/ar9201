/******************************************************************************
* Copyright (C), artosyn 
* File name: DSP_MSS_addr.h    
* Author : jianliu    Version:Initial Draft     Create: 2017年6月26日
* Description : DSP_MSS_addr.c header file
* Others :
* History :
* 1.Date : 2017年6月26日   Author : jianliu   Modify content : Create File
* 
******************************************************************************/
#ifndef _DSP_MSS_ADDR_H_
#define _DSP_MSS_ADDR_H_

/*----------------------------------------------*
 * header file                                   *
 *----------------------------------------------*/

/*----------------------------------------------*
 * macro                                        *
 *----------------------------------------------*/

/*----------------------------------------------*
 * global types                                 *
 *----------------------------------------------*/
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

/**
 * @brief Program memory access protection enable <BR>
 */
typedef enum
{
	DSP_MSS_PROGRAM_ACCESS_PROTECTION_DISABLE = 0,	  /**< Access protection checking disabled */
	DSP_MSS_PROGRAM_ACCESS_PROTECTION_ENABLE		  /**< Access protection checking enabled */
} DSP_MSS_program_access_protection_e;

/**
 * @brief Internal program memory enable
 */
typedef enum
{
	DSP_MSS_INTERNAL_PROGRAM_MEMORY_DISABLE = 0,	 /**< Internal program memory is disabled */
	DSP_MSS_INTERNAL_PROGRAM_MEMORY_ENABLE			 /**< Internal program memory is enabled */
} DSP_MSS_internal_program_memory_enable_e;

/**
 * @brief CACHE pre-fetch enable
 */
typedef enum
{
	DSP_MSS_CACHE_PREFETCH_DISABLE = 0,   /**< Cache pre-fetch is disabled */
	DSP_MSS_CACHE_PREFETCH_ENABLE		  /**< Cache pre-fetch is enabled */
} DSP_MSS_cache_prefetch_enable_e;


/**
 * @brief Memory regions enumeration<BR>In program memory only 16 memory regions are available
 */
typedef enum
{
	DSP_MSS_MEMORY_REGION_0 = 0x0,				/**< Memory region number 0. */
	DSP_MSS_MEMORY_REGION_1 = 0x10, 			/**< Memory region number 1. */
	DSP_MSS_MEMORY_REGION_2 = 0x20, 			/**< Memory region number 2. */
	DSP_MSS_MEMORY_REGION_3 = 0x30, 			/**< Memory region number 3. */
	DSP_MSS_MEMORY_REGION_4 = 0x40, 			/**< Memory region number 4. */
	DSP_MSS_MEMORY_REGION_5 = 0x50, 			/**< Memory region number 5. */
	DSP_MSS_MEMORY_REGION_6 = 0x60, 			/**< Memory region number 6. */
	DSP_MSS_MEMORY_REGION_7 = 0x70, 			/**< Memory region number 7. */
	DSP_MSS_MEMORY_REGION_8 = 0x80, 			/**< Memory region number 8. */
	DSP_MSS_MEMORY_REGION_9 = 0x90, 			/**< Memory region number 9. */
	DSP_MSS_MEMORY_REGION_10 = 0xA0,			/**< Memory region number 10. */
	DSP_MSS_MEMORY_REGION_11 = 0xB0,			/**< Memory region number 11. */
	DSP_MSS_MEMORY_REGION_12 = 0xC0,			/**< Memory region number 12. */
	DSP_MSS_MEMORY_REGION_13 = 0xD0,			/**< Memory region number 13. */
	DSP_MSS_MEMORY_REGION_14 = 0xE0,			/**< Memory region number 14. */
	DSP_MSS_MEMORY_REGION_15 = 0xF0,			/**< Memory region number 15. */
	DSP_MSS_MEMORY_REGION_16 = 0x100,			/**< Memory region number 16 - Data only. */
	DSP_MSS_MEMORY_REGION_17 = 0x110,			/**< Memory region number 17 - Data only. */
	DSP_MSS_MEMORY_REGION_18 = 0x120,			/**< Memory region number 18 - Data only. */
	DSP_MSS_MEMORY_REGION_19 = 0x130,			/**< Memory region number 19 - Data only. */
	DSP_MSS_MEMORY_REGION_20 = 0x140,			/**< Memory region number 20 - Data only. */
	DSP_MSS_MEMORY_REGION_21 = 0x150,			/**< Memory region number 21 - Data only. */
	DSP_MSS_MEMORY_REGION_22 = 0x160,			/**< Memory region number 22 - Data only. */
	DSP_MSS_MEMORY_REGION_23 = 0x170,			/**< Memory region number 23 - Data only. */
	DSP_MSS_MEMORY_REGION_24 = 0x180,			/**< Memory region number 24 - Data only. */
	DSP_MSS_MEMORY_REGION_25 = 0x190,			/**< Memory region number 25 - Data only. */
	DSP_MSS_MEMORY_REGION_26 = 0x1A0,			/**< Memory region number 26 - Data only. */
	DSP_MSS_MEMORY_REGION_27 = 0x1B0,			/**< Memory region number 27 - Data only. */
	DSP_MSS_MEMORY_REGION_28 = 0x1C0,			/**< Memory region number 28 - Data only. */
	DSP_MSS_MEMORY_REGION_29 = 0x1D0,			/**< Memory region number 29 - Data only. */
	DSP_MSS_MEMORY_REGION_30 = 0x1E0,			/**< Memory region number 30 - Data only. */
	DSP_MSS_MEMORY_REGION_31 = 0x1F0			/**< Memory region number 31 - Data only. */
} DSP_MSS_mem_region_e;

/**
 * @brief Memory region active state
 */
typedef enum
{
	DSP_MSS_MEMORY_REGION_ACTIVE = 0,	   /**< The region is active. */
	DSP_MSS_MEMORY_REGION_INACTIVE		   /**< This region is in active. */
} DSP_MSS_mem_region_active_e;

/**
 * @brief PDSP_MSS Memory region cache ability attribute
 */
typedef enum
{
	DSP_MSS_PROGRAM_MEM_REGION_CACHE_DISABLE = 0,	/**< Not cacheable in L1LC */
	DSP_MSS_PROGRAM_MEM_REGION_CACHE_ENABLE 		/**< Cacheable in L1LC */
} DSP_MSS_program_mem_region_cacheability_e;

/**
 * @brief PDSP_MSS Memory region lock after cache-line fill attribute
 */
typedef enum
{
	DSP_MSS_PROGRAM_MEM_REGION_LOCK_AFTER_FILL_DISABLE = 0,   /**< No effect after cache-line fill */
	DSP_MSS_PROGRAM_MEM_REGION_LOCK_AFTER_FILL_ENABLE		  /**< Lock after cache-line fill */
} DSP_MSS_program_mem_region_lock_after_line_fill_e;

/**
 * @brief Memory access protection
 *	0 -  Supervisor: Read/Write User0: Read/Write User1: Read/Write
 *	1 -  Supervisor: Read/Write User0: Read/Write User1: Read	   
 *	2 -  Supervisor: Read/Write User0: Read 	  User1: Read		
 *	3 -  Supervisor: Read/Write User0: Read/Write User1: No Access 
 *	4 -  Supervisor: Read/Write User0: No Access  User1: No Access 
 *	5 -  Supervisor: Read		User0: Read 	  User1: Read	   
 *	6 -  Supervisor: Read		User0: No Access  User1: No Access 
 *	7 -  Supervisor: No Access	User0: No Access  User1: No Access 
 *
 */
typedef unsigned int DSP_MSS_access_protection_t;

/**
 * @brief AXI Cache Policy flags
 */
typedef enum {
	DSP_MSS_AXI_CACHE_POLICY_BUFFERABLE = 1,
	DSP_MSS_AXI_CACHE_POLICY_CACHEABLE = 2,
	DSP_MSS_AXI_CACHE_POLICY_READ_ALLOC = 4,
	DSP_MSS_AXI_CACHE_POLICY_WRITE_ALLOC = 8
} DSP_MSS_axi_cache_policy_e;

/**
 * @brief L2 Cache Policy for read accesses - bit-mask of DSP_MSS_axi_cache_policy_e values
 */
typedef unsigned int DSP_MSS_mem_region_l2_cache_policy_t;

/**
* @brief PDSP_MSS L1 Program Cache Operation Type
*/
typedef enum
{
	DSP_MSS_PROGRAM_CACHE_OPERATION_PREFETCH = 1,	/**< Prefetch */
	DSP_MSS_PROGRAM_CACHE_OPERATION_LOCK	 = 2,	/**< Lock */
	DSP_MSS_PROGRAM_CACHE_OPERATION_UNLOCK	 = 3,	/**< Unlock */
	DSP_MSS_PROGRAM_CACHE_OPERATION_INVALIDATE	= 4    /**< Invalidate */
} DSP_MSS_program_cache_operation_type_e;

/**
* @brief PDSP_MSS L1 Program Cache Operation Size
*/
typedef enum
{
	DSP_MSS_PROGRAM_CACHE_OPERATION_SIZE_BY_ADDRESS = 0,   /**< Address-based */
	DSP_MSS_PROGRAM_CACHE_OPERATION_SIZE_FULL		= 1    /**< Entire cache */
} DSP_MSS_program_cache_operation_size_e;

/**
* @brief DDMA Maximum Burst Size
*/
typedef enum
{
	DSP_MSS_DDMA_MAX_BURST_SIZE_DDTC	 = 0x0,    /**< Maximum burst size is configured at DDMA task (see the Data DMA Transfer Control register (DSP_MSS_DDTC))  */
	DSP_MSS_DDMA_MAX_BURST_SIZE_1_FIXED  = 0x1,    /**< 1 transfer with fixed address(FIXED).  */
	DSP_MSS_DDMA_MAX_BURST_SIZE_4_FIXED  = 0x2,    /**< 4 transfers(FIXED).  */
	DSP_MSS_DDMA_MAX_BURST_SIZE_8_FIXED  = 0x3,    /**< 8 transfers(FIXED).  */
	DSP_MSS_DDMA_MAX_BURST_SIZE_16_FIXED = 0x4,    /**< 16 transfers(FIXED).  */
	DSP_MSS_DDMA_MAX_BURST_SIZE_1_INCR	 = 0x8,    /**< 1 transfer with incrementing addresses(INCR).  */
	DSP_MSS_DDMA_MAX_BURST_SIZE_4_INCR	 = 0x9,    /**< 4 transfers(INCR).	*/
	DSP_MSS_DDMA_MAX_BURST_SIZE_8_INCR	 = 0xA,    /**< 8 transfers(INCR).	*/
	DSP_MSS_DDMA_MAX_BURST_SIZE_16_INCR  = 0xB,    /**< 16 transfers(INCR).  */
	DSP_MSS_DDMA_MAX_BURST_SIZE_32_INCR  = 0xC,    /**< 32 transfers(INCR).  */
	DSP_MSS_DDMA_MAX_BURST_SIZE_64_INCR  = 0xD,    /**< 64 transfers(INCR) (AXI4 only).  */
	DSP_MSS_DDMA_MAX_BURST_SIZE_128_INCR = 0xE,    /**< 128 transfers(INCR) (AXI4 only).  */
	DSP_MSS_DDMA_MAX_BURST_SIZE_256_INCR = 0xF	   /**< 256 transfers(INCR) (128 - bits wide AXI4 only).  */
} DSP_MSS_data_mem_region_max_burst_size_e;

/**
* @brief DDMA AXI Download Outstanding Global Limit
*/
typedef enum
{
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_READ_4	= 0x0,	  /**< DDMA Can issue up to 4 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_READ_5	= 0x1,	  /**< DDMA Can issue up to 5 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_READ_6	= 0x2,	  /**< DDMA Can issue up to 6 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_READ_7	= 0x3,	  /**< DDMA Can issue up to 7 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_READ_8	= 0x4,	  /**< DDMA Can issue up to 8 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_READ_9	= 0x5,	  /**< DDMA Can issue up to 9 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_READ_10 = 0x6,	  /**< DDMA Can issue up to 10 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_READ_11 = 0x7,	  /**< DDMA Can issue up to 11 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_READ_12 = 0x8,	  /**< DDMA Can issue up to 12 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_READ_13 = 0x9,	  /**< DDMA Can issue up to 13 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_READ_14 = 0xA,	  /**< DDMA Can issue up to 14 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_READ_15 = 0xB,	  /**< DDMA Can issue up to 15 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_READ_16 = 0xC	  /**< DDMA Can issue up to 16 outstanding AXI read bursts	*/
} DSP_MSS_ddma_global_max_outstanding_read_e;

/**
* @brief DDMA Upload Outstanding Global Limit when using EDP
*/
typedef enum
{
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_WRITE_4  = 0x0,    /**< DDMA Can issue up to 4 outstanding AXI write bursts   */
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_WRITE_8  = 0x1,    /**< DDMA Can issue up to 8 outstanding AXI write bursts   */
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_WRITE_16 = 0x2,    /**< DDMA Can issue up to 16 outstanding AXI write bursts   */
	DSP_MSS_DDMA_GLOBAL_MAX_OUTSTANDING_WRITE_32 = 0x3	   /**< DDMA Can issue up to 32 outstanding AXI write bursts   */
} DSP_MSS_ddma_global_max_outstanding_write_e;

/**
* @brief DDMA AXI Download Outstanding Specific Region Limit
*/
typedef enum
{
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_USE_GLOBAL = 0x0,	  /**< Download Outstanding limit is taken from DOL field at DSP_MSS_DACC register	 */
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_2			= 0x1,	  /**< DDMA Can issue up to 2 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_3			= 0x2,	  /**< DDMA Can issue up to 3 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_4			= 0x3,	  /**< DDMA Can issue up to 4 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_5			= 0x4,	  /**< DDMA Can issue up to 5 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_6			= 0x5,	  /**< DDMA Can issue up to 6 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_7			= 0x6,	  /**< DDMA Can issue up to 7 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_8			= 0x7,	  /**< DDMA Can issue up to 8 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_9			= 0x8,	  /**< DDMA Can issue up to 9 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_10 		= 0x9,	  /**< DDMA Can issue up to 10 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_11 		= 0xA,	  /**< DDMA Can issue up to 11 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_12 		= 0xB,	  /**< DDMA Can issue up to 12 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_13 		= 0xC,	  /**< DDMA Can issue up to 13 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_14 		= 0xD,	  /**< DDMA Can issue up to 14 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_15 		= 0xE,	  /**< DDMA Can issue up to 15 outstanding AXI read bursts	*/
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_READ_16 		= 0xF	  /**< DDMA Can issue up to 16 outstanding AXI read bursts	*/
} DSP_MSS_ddma_region_max_outstanding_read_e;

/**
* @brief DDMA AXI Upload Outstanding Specific Region Limit
*/
typedef enum
{
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_WRITE_USE_GLOBAL = 0x0,    /**< Upload Outstanding limit is taken from UOL field at DSP_MSS_DACC register	*/
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_WRITE_4 		 = 0x2,    /**< DDMA Can issue up to 4 outstanding AXI read bursts	 */
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_WRITE_8 		 = 0x3,    /**< DDMA Can issue up to 8 outstanding AXI read bursts	 */
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_WRITE_16		 = 0x4,    /**< DDMA Can issue up to 16 outstanding AXI read bursts  */
	DSP_MSS_DDMA_REGION_MAX_OUTSTANDING_WRITE_32		 = 0x5	   /**< DDMA Can issue up to 32 outstanding AXI read bursts  */
} DSP_MSS_ddma_region_max_outstanding_write_e;


/**
* @brief PSU power save modes
*/
typedef enum
{
	DSP_MSS_POWER_SAVE_MODE_FREE_RUN = 0,				/**< All clocks are enabled */
	DSP_MSS_POWER_SAVE_MODE_DYNAMIC 	,				/**< Dynamic Power Save - automatic clock gating for active units */
	DSP_MSS_POWER_SAVE_MODE_LIGHT_SLEEP ,				/**< The core and WB clocks are shut down */
	DSP_MSS_POWER_SAVE_MODE_STANDBY 					/**< All clock are shut down and can also be shut down externally */
} DSP_MSS_power_save_mode_e;

/**
* @brief Data memory access protection enable
*/
typedef enum
{
	DSP_MSS_DATA_ACCESS_PROTECTION_DISABLED = 0,	/**< Access protection checking disabled */
	DSP_MSS_DATA_ACCESS_PROTECTION_ENABLED			/**< Access protection checking enabled */
} DSP_MSS_data_access_protection_e;

/**
* @brief Enable access to core core from EDAP (External Data Access Port)
*/
typedef enum
{
	DSP_MSS_EDAP_ACCESS_ENABLE = 0, 	/**< EDAP port accesses are enabled*/
	DSP_MSS_EDAP_ACCESS_DISABLE 		/**< EDAP port accesses are disabled*/
} DSP_MSS_edap_access_enable_e;

/**
* @brief Enable access to the core from AXI slave port
*/
typedef enum
{
	DSP_MSS_AXI_SLAVE_PORT_ACCESS_ENABLE = 0,	  /**< AXIs slave port accesses to the core are enabled*/
	DSP_MSS_AXI_SLAVE_PORT_ACCESS_DISABLE		  /**< AXIs slave port accesses to the core are disabled*/
} DSP_MSS_axi_slave_access_e;

/**
* @brief DDMA external port read policy
*/
typedef enum
{
	DSP_MSS_DDMA_READ_POLICY_MIN_CYCLES = 0,	 /**< DDMA pursues minimal cycle count resulting in possible over reading of data from the external address*/
	DSP_MSS_DDMA_READ_POLICY_EXACT_READ 		/**< DDMA pursues exact read resulting is possible additional read cycles on the external bus used*/
} DSP_MSS_ddma_read_policy_e;

/**
* @brief Data Region Master ID
*/
typedef enum
{
	DSP_MSS_DATA_MEM_REGION_MASTER_EDP	 = 0x1, 	/**< EDP*/
	DSP_MSS_DATA_MEM_REGION_MASTER_AXIM0 = 0x2, 	/**< AXIm0*/
	DSP_MSS_DATA_MEM_REGION_MASTER_AXIM1 = 0x4, 	/**< AXIm1*/
	DSP_MSS_DATA_MEM_REGION_MASTER_BLANK = 0x80 	/**< Blank Region*/
} DSP_MSS_data_mem_region_master_id_e;

/**
* @brief Memory Ordering Model
*/
typedef enum
{
	DSP_MSS_DATA_MEM_ORDERING_MODEL_TOTAL_STORE = 0,	 /**< Total Store Ordering*/
	DSP_MSS_DATA_MEM_ORDERING_MODEL_STRONG_ORDER		 /**< Strong Ordering*/
} DSP_MSS_data_memory_ordering_model_e;

/**
 * @brief Program Memory Configuration Register
 */
typedef union {
	struct {
		unsigned access_prot_enable 		  :1;			  /**< Access Protection Enable:<BR> 1: Enabled<BR> 0: Disabled */
		unsigned reserved1					  :1;			  /**< Reserved */
		unsigned cache_prefetch_enable		  :1;			  /**< Cache Pre-fetch Enable:<BR> 1: Enabled<BR> 0: Disabled */
		unsigned tcm_enable 				  :1;			  /**< TCM Enable:<BR> 1: Enabled<BR> 0: Disabled */
		unsigned reserved2					  :28;			  /**< Reserved */
	} field;												/**< Fields view */
	unsigned int   overlay; 		/**< Overlay view */
} DSP_MSS_program_mem_config_reg_t;

/**
 * @brief PDMA Transfer Control 
 */
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

/**
 * @brief Program Address Region Start 
 */
typedef union {
	struct {
		/**
		4KB start block of address region.<BR>
		For ADD0_START, this field is read-only and is hardwired to the value of 0x0_0000.*/
		unsigned p_region_start :19;
		unsigned reserved1		:8; 			/**< Reserved */
		/** See DSP_MSS_mem_region_active_e. For ADD0_START, this field is read-only, and is hardwired to the value of 0x0 (active).*/
		unsigned inactive		:1; 
		unsigned reserved2		:3; 			/**< Reserved */
	} field;		  /**< Fields view */
	unsigned int	  overlay;		  /**< Overlay view */
} DSP_MSS_program_mem_region_start_reg_t;

/**
 * @brief Program Address Region Attributes 
 */
typedef union {
	struct {
		unsigned cacheable			  :1;		/**< Cacheability - see DSP_MSS_program_mem_region_cacheability_e */
		unsigned lock_after_line_fill :1;		/**< Lock after cache-line fill - see DSP_MSS_program_mem_region_lock_after_line_fill_e */
		unsigned reserved1			  :2;		/**< Reserved */
		unsigned access_prot		  :3;		/**< Access Protection. <BR>See DSP_MSS_program_access_protection_e. */
		unsigned reserved2			  :1;		/**< Reserved */
		unsigned l2_cache_policy	  :4;		/**< L2 Cache Policy for read accesses - see DSP_MSS_program_mem_region_l2_cache_policy_t. */
		unsigned reserved3			  :12;		/**< Reserved */
		unsigned read_qos			  :4;		/**< Read transaction Quality of Service, QoS. <BR>Used only if AXI4 is supported. */
		unsigned reserved4			  :1;		/**< Reserved */
	}	field;								/**< Fields view */
	unsigned int	  overlay;		   /**< Overlay view */
} DSP_MSS_program_mem_region_attrib_t;

/**
 * @brief L1 Program Cache Software Operation 
 */
typedef union {
	struct {
	unsigned reserved1		:1; 			/**< Reserved */
		/**
		L1 Instruction Cache operation:<BR>
		0: No operation or operation completed.<BR>
		1: Operation performed on L1 instruction cache.<BR>
		This bit is cleared by hardware after the operation completes.*/
		unsigned operation_status :1;
		/** See DSP_MSS_program_cache_operation_type_e */
		unsigned operation_type   :4;
		unsigned reserved2		  :1;			  /**< Reserved */
		/** See DSP_MSS_program_cache_operation_size_e */
		unsigned operation_size   :1;
		unsigned reserved3		  :8;			  /**< Reserved */
		unsigned num_cache_lines  :16;			  /**< Number of cache-lines per line. */
	}  field;			/**< Fields view */
	unsigned int		overlay;		 /**< Overlay view */
} DSP_MSS_program_cache_software_operation_reg_t;


/**
* @brief Hardware Memory Configuration
*/
typedef union {
	struct	{
		/**
		IDM number of blocks:<BR>
		0: 4 blocks.<BR>
		1: Reserved.<BR>
		This bit is cleared by hardware after the operation completes.*/
		unsigned num_data_tcm_blocks : 1;
		unsigned reserved1 : 1; 			/**< Reserved */
		/**
		IDM size:<BR>
		000: Reserved<BR>
		001: 128 KB<BR>
		010: Reserved<BR>
		011: 256 KB<BR>
		100: 512 KB<BR>
		101: 1,024 KB<BR>
		110-111: Reserved*/
		unsigned data_tcm_size : 3;
		/**
		EDAP AXI slave port width:<BR>
		0: 128 bits<BR>
		1: Reserved*/
		unsigned edap_axi_width : 1;
		unsigned reserved2 : 1; 			/**< Reserved */
		/**
		AXI master port width:<BR>
		00 128 bits<BR>
		01 256 bits<BR>
		10 Reserved<BR>
		11 Reserved*/
		unsigned edp_axi_width : 2;
		/**
		Program TCM memory size:<BR>
		000: 0KB (No TCM)<BR>
		001: 32 KB<BR>
		010: 64 KB<BR>
		011: 128 KB<BR>
		100: 256 KB<BR>
		101-111: Reserved*/
		unsigned prog_tcm_size : 3;
		/**
		Program cache size:<BR>
		000: Reserved<BR>
		001: 32 KB cache<BR>
		010: 64 KB cache<BR>
		011: 128 KB cache<BR>
		100-111: Reserved*/
		unsigned prog_cache_size : 3;
		unsigned other : 17;			   /**< Other fields */
	} field;		   /**< Fields view */
	unsigned int		overlay;		 /**< Overlay view */
} DSP_MSS_hardware_memory_config_reg_t;

/**
* @brief Read After Write Protection and DDMA Outstanding Configuration 
*/
typedef union {
	struct {
		/**
		Data protection RAW/SO indication:<BR>
		This bit should not be modified during AXI write or read transfers.BR>
		Note: this option must be set when using the ACE interface.*/
		unsigned dpraw : 1;
		unsigned reserved1 : 3; 			/**< Reserved */
		/** DDMA AXI Download Outstanding Limit - see DSP_MSS_ddma_global_max_outstanding_read_e <BR>
		The number of outstanding DDMA transactions is unlimited when<BR>
		the DDMA is downloading using a FIC port for accessing external memory.*/
		unsigned ddma_max_outstanding_read : 4;
		/** DDMA Upload Outstanding Limit when using EDP - see DSP_MSS_ddma_global_max_outstanding_write_e */
		unsigned ddma_max_outstanding_write : 3;
		unsigned reserved2 : 21;			 /**< Reserved */
	}	field;			 /**< Fields view */
	unsigned int   overlay; 		/**< Overlay view */
} DSP_MSS_ddma_max_outstanding_config_reg_t;

/**
* @brief Power Save Mode 
*/
typedef union {
	struct {
		unsigned power_save_mode : 2; /**< Power save mode - see DSP_MSS_power_save_mode_e*/
		/** Debug Block Configuration:<BR>
		0: Operational Production - the Debug Block power and clocks are shut down regardless of the Power Save mode configurations.*/
		unsigned debug_config : 1;
		unsigned reserved1 : 1; 			/**< Reserved */
		/**
		Retention Indication bus :<BR>
		When clear, indicates that the physical memory is in retention :<BR>
		1: PDSP_MSS TCM retention indication *<BR>
		2: PDSP_MSS cache and tag retention indication *<BR>
		3: DDSP_MSS block 0 retention indication<BR>
		4: DDSP_MSS block 1 retention indication<BR>
		5: DDSP_MSS block 2 retention indication<BR>
		6: DDSP_MSS block 3 retention indication<BR>
		* This field is only present if the PSU Power Gating is set.*/
		unsigned mem_retention : 5;
		/**
		Shutdown Indications bus.<BR>
		When clear, indicates that the physical memory is in shutdown (no voltage is supplied):<BR>
		1: Core and DSP_MSS shutdown indication<BR>
		2: PDSP_MSS TCM shutdown indication*<BR>
		3: PDSP_MSS cache shutdown indication*<BR>
		4: DDSP_MSS block 0 shutdown indication<BR>
		5: DDSP_MSS block 1 shutdown indication<BR>
		6: DDSP_MSS block 2 shutdown indication<BR>
		7: DDSP_MSS block 3 shutdown indication<BR>
		* This field is only present if the PSU Power Gating is set.*/
		unsigned shutdown : 7;
		unsigned reserved : 15; 		   /**< Reserved */
	} field;		  /**< Fields view */
	unsigned int	  overlay;		  /**< Overlay view */
} DSP_MSS_power_save_mode_reg_t;

/**
* @brief DSP_MSS Memory Access Configuration (DSP_MSS_SDCFG)
*/
typedef union {
	struct {
		unsigned reserved1 : 22;			/**< Reserved */
		unsigned data_access_prot : 1;		/**<	Data Access Protection Enable - see DSP_MSS_data_access_protection_e */
		unsigned reserved2 : 2; 			/**< Reserved */
		unsigned edap_access_en : 1;		/**<	Enable EDAP port accesses to the core - see DSP_MSS_edap_access_enable_e */
		unsigned axi_slave_access_en : 1;	/**<	Enable AXI slave port accesses to the core - see DSP_MSS_axi_slave_access_e */
		unsigned reserved3 : 4; 			/**< Reserved */
	}	field;			/**< Fields view */
	unsigned int   overlay; 	   /**< Overlay view */
} DSP_MSS_memory_access_config_reg_t;

/**
* @brief Data Region configuration
*/
typedef union {
	struct {
		/** 
		4KB start block of address region.<BR>
		For ADD0_START, this field is read-only and is hardwired to the value of 0x0_0000.*/
		unsigned region_start : 20;
		/** Master ID of region 0 - see DSP_MSS_data_mem_region_master_id_e */
		unsigned master_id : 8;
		/** Set if this region is active/inactive - see DSP_MSS_mem_region_active_e<BR>
		For ADD0_START, this field is read-only, and is hardwired to the value of 0x0.*/
		unsigned inactive : 1;
		unsigned reserved : 3;			   /**< Reserved */
	}	field;			/**< Fields view */
	unsigned int  overlay;		  /**< Overlay view */
} DSP_MSS_data_mem_region_reg_t;

/**
* @brief Data Address Region Attributes 0 
*/
typedef union {
	struct {
		unsigned reserved1		 : 16;			  /**< Reserved */
		unsigned memory_ordering : 1;			  /**< Memory Ordering Model - see DSP_MSS_data_memory_ordering_model_e. */
		unsigned access_prot	 : 3;			  /**< Access Protection = see DSP_MSS_access_protection_e. */
		unsigned reserved2		 : 4;			  /**< Reserved */
		unsigned read_qos		 : 4;			  /**< Read transaction Quality of Service, used only if AXI4 is supported. */
		unsigned write_qos		 : 4;			  /**< Write transaction Quality of Service, used only if AXI4 is supported. */
	}	  field;		   /**< Fields view */
	unsigned int		   overlay; 		/**< Overlay view */
} DSP_MSS_data_mem_region_attrib0_reg_t;

/**
* @brief Data Address Region Attributes 1
*/
typedef union {
	struct {
		unsigned ddma_read_policy		 : 1;			 /**< DDMA external port read policy - see DSP_MSS_ddma_read_policy_e. */
		unsigned l2_cache_write_policy	 : 4;			 /**< L2 Cache Policy for write accesses - see DSP_MSS_axi_cache_policy_e. */
		unsigned l2_cache_read_policy	 : 4;			 /**< L2 Cache Policy for read accesses  - see DSP_MSS_axi_cache_policy_e. */
		unsigned ddma_max_burst_size	 : 4;			 /**< Data DMA maximum burst size - see DSP_MSS_data_mem_region_max_burst_size_e. */
		unsigned ddma_max_outstanding_read	: 4;		 /**< DDMA download outstanding limit when using this region - see DSP_MSS_ddma_region_max_outstanding_read_e.*/
		unsigned reserved1 : 1; 						 /**< Reserved */
		unsigned ddma_max_outstanding_write : 3;		 /**< DDMA upload outstanding limit when using this region - see DSP_MSS_ddma_region_max_outstanding_write_e.*/
		unsigned reserved2 : 11;						 /**< Reserved */
	} field;		   /**< Fields view */
	unsigned int		   overlay; 		/**< Overlay view */
} DSP_MSS_data_mem_region_attrib1_reg_t;

/**
* @brief Program Memory Region Settings structure
*
* Used as input to DSP_MSS_set_program_memory_region function
*/
typedef struct {
 /**< start_address - Memory region start address<BR>
	end address is defined by next memory region start address*/
	unsigned int start_address;
	/**< The memory region for which the desired address and attributes are to be set<BR>
	Memory region must not exceed DSP_MSS_MEMORY_REGION_15 */
	DSP_MSS_mem_region_e memory_region;
	/**< Activate/deactivate the defined memory region*/
	DSP_MSS_mem_region_active_e active;
	/**< Enable/disable cache for memory region*/
	DSP_MSS_program_mem_region_cacheability_e cache_enable;
	/**< Lock after cache-line fill */
	DSP_MSS_program_mem_region_lock_after_line_fill_e cache_lock;
	/**< Memory access protection */
	DSP_MSS_access_protection_t access_protection;
	/**< l2_cache_policy - L2 Cache Policy for read accesses*/
	DSP_MSS_mem_region_l2_cache_policy_t l2_cache_policy;
	/**< Quality of Service - QoS is used as a priority indicator for the associated read transaction<BR>
	QoS range is 0 - 15. A higher value indicates a higher priority transaction<BR>
	Note: The AMBA4 protocol does not specify the exact use of the QoS identifier*/
	unsigned int qos;
} DSP_MSS_program_memory_region_t;

/**
* @brief Data Memory Region Settings structure
* 
* Used as input to DSP_MSS_set_data_memory_region function
*/
typedef struct {

	/**< The memory region start address. The end address is defined by the next memory region start address.*/
	unsigned int start_address;
	/**< The memory region for which the desired address and attributes are to be set.*/
	DSP_MSS_mem_region_e memory_region;
	/**< The memory region master id.*/
	DSP_MSS_data_mem_region_master_id_e master_id;
	/**< Activate/deactivate the defined memory region.*/
	DSP_MSS_mem_region_active_e active;
	/**< Memory ordering model for region - total store or strong ordering.*/
	DSP_MSS_data_memory_ordering_model_e memory_ordering;
	/**< Memory access protection.*/
	DSP_MSS_access_protection_t access_protection;
	/**< Read Quality of Service. QoS is used as a priority indicator for the associated read transaction.<BR>
	QoS range is 0-15. A higher value indicates a higher priority transaction.<BR>
	Note: The AMBA4 protocol does not specify the exact use of the QoS identifier.*/
	unsigned int read_qos;
	/**< write_qos - QoS is used as a priority indicator for the associated write transaction.*/
	unsigned int write_qos;
	/**< DDMA external port read policy.*/
	DSP_MSS_ddma_read_policy_e ddma_read_policy;
	/**< L2 Cache Policy for write accesses.*/
	DSP_MSS_mem_region_l2_cache_policy_t l2_cache_write_policy;
	/**< L2 Cache Policy for read accesses.*/
	DSP_MSS_mem_region_l2_cache_policy_t l2_cache_read_policy;
	/**< Memory region burst size for DDMA.*/
	DSP_MSS_data_mem_region_max_burst_size_e ddma_max_burst_size;
	/**< Max number of outstanding read transactions for DDMA.*/
	DSP_MSS_ddma_region_max_outstanding_read_e ddma_max_outstanding_read;
	/**< Max number of outstanding write transactions for DDMA.*/
	DSP_MSS_ddma_region_max_outstanding_write_e ddma_max_outstanding_write;
} DSP_MSS_data_memory_region_t;

/*----------------------------------------------*
 * global variable                              *
 *----------------------------------------------*/

/*----------------------------------------------*
 * global constant variables                    *
 *----------------------------------------------*/

/*----------------------------------------------*
 * global function                              *
 *----------------------------------------------*/



#endif // _DSP_MSS_ADDR_H_

