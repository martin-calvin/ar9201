/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : tof_embedded.cpp
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/6/4
*  Last Modified :
*  Description   : S5K33d embedded数据解析模块
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/6/4
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/

/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <stdio.h>
#include <string.h>

#include "basic_typedef.h"
#include "tof_embedded.h"
#include "logutil.h"



/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
 

/*==============================================*
 *       Enumb define                           *
 *----------------------------------------------*/


// EBD解析偏移地址(byte_index)
typedef enum
{
    ebd_frame_count = 16,     //1byte (0-254轮转)
    ebd_output_format = 180,  //1byte (0x01: 4-tap, single-freq, non-shuffle; 0x0A: 4-tap, dual-freq, shuffle)
    ebd_phase_map = 182,      //1byte (0x10: Non-shuffle; 0x1B: Shuffle)
    ebd_frequency_modulation_index = 184, //1byte 0x00: f1(100MHz), 0x01:f2(80MHz)
    ebd_frame_length_lines = 362, //2bytes
    ebd_line_length_pck = 366, //2bytes
    ebd_rd_sensor_temperature = 28, //2bytes
    ebd_rd_laser_temperature = 190, //2bytes
}ebd_info_t;


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/


/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/

// input 16bit pixels, output data we need
/*
* because cx3 gpif width is 16b, one pixel is raw10 in sensor,but from gpif to DMA is RAW16(high bit 0)
* byte_index - register address
* size - register size, only support size 8it or 16bit
* */
static int UnpackEmbedded10Bit(uint16_t *EBD_10b_addr, uint8_t *EBD_8b, uint16_t byte_index, uint8_t size)
{
    //<1>,高低位交换, msb/lsb exchange。当前大小端方式不需要交换
    //<2>,截取低10bit, low 10bit active  
    //<3>,右移2bit, right shift 2bit
    
    *EBD_8b = ((EBD_10b_addr[byte_index] & 0x3FF) >> 2) & 0xff;

    if(size == 2){
        *(EBD_8b + 1) = ((EBD_10b_addr[byte_index - 2] & 0x3FF) >> 2) & 0xff;
    }

    return 0;
}


/*****************************************************************************
*   Prototype    : tof_embedded_33d_get_PhaseType
*   Description  : api_rd_current_state_time_of_flight_pahse_map
*   Input        : const uint8_t *pEbdData10bit  
*   Output       : None
*   Return Value : ObTofPhaseType
*****************************************************************************/
ObTofPhaseType tof_embedded_33d_get_PhaseType(const uint8_t *pEbdData10bit)
{
    uint8_t value = 0;
    
    if (!pEbdData10bit)
        return PHASE_TYPE_UNKNOW;
     
    UnpackEmbedded10Bit((uint16_t *)pEbdData10bit, &value, ebd_phase_map, 1);

    if (value == PHASE_TYPE_NON_SHUFFLE)
        return PHASE_TYPE_NON_SHUFFLE;
    else if (value == PHASE_TYPE_SHUFFLE)
        return PHASE_TYPE_SHUFFLE;
        
    return PHASE_TYPE_UNKNOW;
}


/*****************************************************************************
*   Prototype    : tof_embedded_33d_get_output_format
*   Description  : api_rd_current_state_tof_output_format
*   Input        : const uint8_t *pEbdData10bit  
*   Output       : None
*   Return Value : ObTofOutMode
*****************************************************************************/
ObTofOutMode tof_embedded_33d_get_output_format(const uint8_t *pEbdData10bit)
{
    uint8_t value = 0;
    
    if (!pEbdData10bit)
        return S5K33D_OUT_MODE_UNKNOW;
     
    UnpackEmbedded10Bit((uint16_t *)pEbdData10bit, &value, ebd_output_format, 1);

    if (value == S5K33D_OUT_MODE_4TAP_SINGLE_FREQ_NON_SHUFFLE)
        return S5K33D_OUT_MODE_4TAP_SINGLE_FREQ_NON_SHUFFLE;
    else if (value == S5K33D_OUT_MODE_4TAP_DUAL_FREQ_SHUFFLE)
        return S5K33D_OUT_MODE_4TAP_DUAL_FREQ_SHUFFLE;
        
    return S5K33D_OUT_MODE_UNKNOW;
}


/*****************************************************************************
*   Prototype    : tof_embedded_33d_get_FrameIndex
*   Description  : api_rd_general_frame_count number of current frame (0~254)
*   Input        : const uint8_t *pEbdData10bit  
*   Output       : None
*   Return Value : uint8_t
*****************************************************************************/
uint8_t tof_embedded_33d_get_FrameIndex(const uint8_t *pEbdData10bit)
{
    uint8_t value = 0;
   
    if (!pEbdData10bit)
        return -1;

    UnpackEmbedded10Bit((uint16_t *)pEbdData10bit, &value, ebd_frame_count, 1);

    return value;
}


/*****************************************************************************
*   Prototype    : tof_embedded_33d_get_Frequency
*   Description  : api_rd_current_state_tof_frequency_modulation_index
*   Input        : const uint8_t *pEbdData10bit  
*   Output       : None
*   Return Value : ObTofModFreq
*****************************************************************************/
ObTofModFreq tof_embedded_33d_get_Frequency(const uint8_t *pEbdData10bit)
{
    uint8_t value = 0;
   
    if (!pEbdData10bit)
        return OB_TOF_MOD_FREQ_UNKNOW;
    
    UnpackEmbedded10Bit((uint16_t *)pEbdData10bit, &value, ebd_frequency_modulation_index, 1);

     if (value == OB_TOF_MOD_FREQ_100MHZ)
        return OB_TOF_MOD_FREQ_100MHZ;
    else if (value == OB_TOF_MOD_FREQ_80MHZ)
        return OB_TOF_MOD_FREQ_80MHZ;
        
    return OB_TOF_MOD_FREQ_UNKNOW;
}


/*****************************************************************************
*   Prototype    : tof_embedded_33d_getDriverICTemp
*   Description  : api_rd_current_state_led_driver_ic_temperature
*   Input        : const uint8_t *pEbdData10bit  
*   Output       : None
*   Return Value : float
*****************************************************************************/
float tof_embedded_33d_getDriverICTemp(const uint8_t *pEbdData10bit)
{
    uint16_t value = 0;
    float temp = 0.0;
    
    if (!pEbdData10bit)
        return temp;
   
    UnpackEmbedded10Bit((uint16_t *)pEbdData10bit, (uint8 *)&value, ebd_rd_laser_temperature, 2);

	temp = 25 + (value - 296) / 5.4;
	if(temp > 100 || temp < 0)
    {
        WARN("tmp:%f, value:0x%X\n", temp, value);
		temp = 0;
	}
    
	return temp;
}


/*****************************************************************************
*   Prototype    : tof_embedded_33d_getSensorTemp
*   Description  : api_rd_general_temperature
*   Input        : const uint8_t *pEbdData10bit  
*   Output       : None
*   Return Value : float
*****************************************************************************/
float tof_embedded_33d_getSensorTemp(const uint8_t *pEbdData10bit)
{
    uint16_t value = 0;
    float temp = 0.0;
    
    if (!pEbdData10bit)
        return temp;
   
    UnpackEmbedded10Bit((uint16_t *)pEbdData10bit, (uint8 *)&value, ebd_rd_sensor_temperature, 2);

    temp = (float)((value >> 8) & 0xFF) + (float)(value & 0xFF)/256.0;

	return temp;   
}



/*
 * input start address of 10bit Embedded data line
 * output 0 when Embedded data is correct.
 * */
int check_EBD_data(uint16_t *EBD_data_start_addr)
{
    uint8_t ebd_check_buf[5];
    const uint8_t ebd_data_head[] = {
        0x0a,
        0xaa,
        0x00,
        0xa5,
    };
    // unpack 10 to 8,and check  output data
    for(int i=0; i<4; i++)
    {
        EBD_data_start_addr[i] &= 0x3ff;//locat at current index-2. middle is '5A'
        ebd_check_buf[i] = (EBD_data_start_addr[i] >> 2) & 0xff;
    }
    
    if (memcmp(ebd_data_head, ebd_check_buf, 4) != 0) {
        return -1;//data check failed
    }
    
    return 0;
}



