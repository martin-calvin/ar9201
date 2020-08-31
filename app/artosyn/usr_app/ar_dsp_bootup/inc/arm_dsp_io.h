#ifndef ARM_DSP_IO_H
#define ARM_DSP_IO_H

#include "dsp_mss_addr.h"
#include "register_addr.h"

extern int set_dsp_reg_bit(long *addr, int bit);

#define write_dsp_mcci_reg(addr, value) *(long *)addr = value
#define write_dsp_reg(addr, value) *(long *)(addr) = value
#define read_dsp_reg(addr) (*(long *)(addr))

#define set_dsp_wait(core_id) write_dsp_reg(core_id *TO_ARM_INTERRUPT_CORE_OFFSET + TO_ARM_INTERRUPT0_BASE, 1)
#define clear_dsp_wait(core_id) write_dsp_reg(core_id *TO_ARM_INTERRUPT_CORE_OFFSET + TO_ARM_INTERRUPT0_BASE, 1)

#define trigger_to_arm_interrupt0(core_id) write_dsp_reg(core_id *TO_ARM_INTERRUPT_CORE_OFFSET + TO_ARM_INTERRUPT0_BASE, 1)
#define clear_to_arm_interrupt0(core_id) write_dsp_reg(core_id *TO_ARM_INTERRUPT_CORE_OFFSET + TO_ARM_INTERRUPT0_BASE, 0)
#define read_to_arm_interrupt0(core_id) read_dsp_reg(core_id *TO_ARM_INTERRUPT_CORE_OFFSET + TO_ARM_INTERRUPT0_BASE)
#define enable_to_arm_interrupt0(core_id) write_dsp_reg(core_id *TO_ARM_INTERRUPT_CORE_OFFSET + TO_ARM_INTERRUPT0_MASK_BASE, 1)
#define read_to_arm_interrupt0_mask(core_id) read_dsp_reg(core_id *TO_ARM_INTERRUPT_CORE_OFFSET + TO_ARM_INTERRUPT0_MASK_BASE)

#define trigger_to_arm_interrupt1(core_id) write_dsp_reg(core_id *TO_ARM_INTERRUPT_CORE_OFFSET + TO_ARM_INTERRUPT1_BASE, 1)
#define clear_to_arm_interrupt1(core_id) write_dsp_reg(core_id *TO_ARM_INTERRUPT_CORE_OFFSET + TO_ARM_INTERRUPT1_BASE, 0)
#define read_to_arm_interrupt1(core_id) read_dsp_reg(core_id *TO_ARM_INTERRUPT_CORE_OFFSET + TO_ARM_INTERRUPT1_BASE)
#define enable_to_arm_interrupt1(core_id) write_dsp_reg(core_id *TO_ARM_INTERRUPT_CORE_OFFSET + TO_ARM_INTERRUPT1_MASK_BASE, 1)
#define read_to_arm_interrupt1_mask(core_id) read_dsp_reg(core_id *TO_ARM_INTERRUPT_CORE_OFFSET + TO_ARM_INTERRUPT1_MASK_BASE)

#define read_cevaxm4_idle_status(core_id) read_dsp_reg(CORE0_DSP_IDLE_ADDR + IDLE_REG_OFFSET_INTER_CORE * core_id)
#define read_dsp_core_idle_status(core_id) read_dsp_reg(CORE0_CORE_IDLE_ADDR + IDLE_REG_OFFSET_INTER_CORE * core_id)

#define read_dsp_pdtc_value(core_id) read_dsp_reg(CORE0_MCCI_OFFSET_ADDR + CORE_OFFSET * (core_id) + DSP_MSS_PMSS_PDTC_ADDR)
#define write_dsp_pdtc_value(core_id, value) write_dsp_reg(CORE0_MCCI_OFFSET_ADDR + CORE_OFFSET * (core_id) + DSP_MSS_PMSS_PDTC_ADDR, value)
#define read_dsp_pdia_value(core_id) read_dsp_reg(CORE0_MCCI_OFFSET_ADDR + CORE_OFFSET * (core_id) + DSP_MSS_PMSS_PDIA_ADDR)
#define write_dsp_pdia_value(core_id, value) write_dsp_reg(CORE0_MCCI_OFFSET_ADDR + CORE_OFFSET * (core_id) + DSP_MSS_PMSS_PDIA_ADDR, value)
#define read_dsp_pdea_value(core_id) read_dsp_reg(CORE0_MCCI_OFFSET_ADDR + CORE_OFFSET * (core_id) + DSP_MSS_PMSS_PDEA_ADDR)
#define write_dsp_pdea_value(core_id, value) write_dsp_reg(CORE0_MCCI_OFFSET_ADDR + CORE_OFFSET * (core_id) + DSP_MSS_PMSS_PDEA_ADDR, value)

#define is_dsp_mcci_free(core_id) (unsigned char)read_dsp_reg(CORE0_MCCI_STS_OFFSET_ADDR + (CORE_OFFSET * core_id))
#define reset_noc() write_dsp_reg(DSP_NOC_RESET_ADDR, 0xf)
#define set_dsp_apb_reset(value) write_dsp_reg(GLOBAL_RESET_ADDR, value)
#define set_dsp_global_reset(core_id, value) write_dsp_reg(CORE0_GLOBAL_RESET_ADDR + (RGU_ADDR_INC_INTER_CORE * core_id), value)
#define set_dsp_system_reset(core_id, value) write_dsp_reg(CORE0_SYSTEM_RESET_ADDR + (RGU_ADDR_INC_INTER_CORE * core_id), value)
#define set_dsp_core_reset(core_id, value) write_dsp_reg(CORE0_CORE_RESET_ADDR + (RGU_ADDR_INC_INTER_CORE * core_id), value)
#define set_dsp_ocem_reset(core_id, value) write_dsp_reg(CORE0_OCEM_RESET_ADDR + (RGU_ADDR_INC_INTER_CORE * core_id), value)

#define read_dsp_timeL_value(core_id) read_dsp_reg(CORE0_SYSTIML + CORE_OFFSET * (core_id))
#define read_dsp_timeH_value(core_id) read_dsp_reg(CORE0_SYSTIMH + CORE_OFFSET * (core_id))

//set ceva p_cache_strap pin
#define set_dsp_cache_invalidate(core_id) write_dsp_reg(CORE0_CACHE_INVALIDATE_REG + ARB_REG_INT_CORE_OFFSET * (core_id), 1)

#define set_dsp_wait_macro(core_id) write_dsp_reg(CORE0_WAIT_ADDR + (core_id * ARB_REG_INT_CORE_OFFSET), 1)
#define clear_dsp_wait_macro(core_id) write_dsp_reg(CORE0_WAIT_ADDR + (core_id * ARB_REG_INT_CORE_OFFSET), 0)
#define set_ceva_isloation_ctrl(core_id) set_dsp_reg_bit(DSP_POWER_REG_ADDR, (8 + core_id))
#define set_ceva_power_ctrl(core_id) set_dsp_reg_bit(DSP_POWER_REG_ADDR, (4 + core_id))
#define set_ceva_jtag_ctrl(core_id) set_dsp_reg_bit(DSP_POWER_REG_ADDR, (0 + core_id))
#define lock_ceva() write_dsp_reg(DSP_POWER_LOCK_REG_ADDR, 0x1234)
#define unlock_ceva() write_dsp_reg(DSP_POWER_LOCK_REG_ADDR, 0x4c43544d)

#define mask_dbg_gen(core_id) write_dsp_reg(CORE0_MCCI_OFFSET_ADDR + CORE_OFFSET * (core_id) + DBG_GEN_MASK, 0x10000000)
//#define mask_dbg_gen(core_id) write_dsp_reg(CORE0_MCCI_OFFSET_ADDR + CORE_OFFSET * (core_id) + DBG_GEN_MASK, 0xffffffff)


#endif
