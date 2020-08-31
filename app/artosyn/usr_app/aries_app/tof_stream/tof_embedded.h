/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : tof_embedded.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/6/4
*  Last Modified :
*  Description   : tof_embedded.cpp header file
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
#ifndef __TOF_EMBEDDED_H__
#define __TOF_EMBEDDED_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/



/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/

typedef enum {
	S5K33D_OUT_MODE_4TAP_SINGLE_FREQ_NON_SHUFFLE = 0x01,
	S5K33D_OUT_MODE_4TAP_DUAL_FREQ_SHUFFLE = 0x0A,
	S5K33D_OUT_MODE_UNKNOW = -1
}ObTofOutMode;


typedef enum {
	PHASE_TYPE_NON_SHUFFLE = 0x10,
	PHASE_TYPE_SHUFFLE     = 0x1B,
	PHASE_TYPE_UNKNOW      = -1
}ObTofPhaseType;


typedef enum {
	OB_TOF_MOD_FREQ_100MHZ = 0x00,
	OB_TOF_MOD_FREQ_80MHZ  = 0x01,
	OB_TOF_MOD_FREQ_UNKNOW = -1
}ObTofModFreq;


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/


/*****************************************************************************
*   Prototype    : tof_embedded_33d_get_PhaseType
*   Description  : api_rd_current_state_time_of_flight_pahse_map
*   Input        : const uint8_t *pEbdData10bit  
*   Output       : None
*   Return Value : ObTofPhaseType
*****************************************************************************/
extern ObTofPhaseType tof_embedded_33d_get_PhaseType(const uint8_t *pEbdData10bit);


/*****************************************************************************
*   Prototype    : tof_embedded_33d_get_output_format
*   Description  : api_rd_current_state_tof_output_format
*   Input        : const uint8_t *pEbdData10bit  
*   Output       : None
*   Return Value : ObTofOutMode
*****************************************************************************/
extern ObTofOutMode tof_embedded_33d_get_output_format(const uint8_t *pEbdData10bit);


/*****************************************************************************
*   Prototype    : tof_embedded_33d_get_FrameIndex
*   Description  : api_rd_general_frame_count number of current frame (0~254)
*   Input        : const uint8_t *pEbdData10bit  
*   Output       : None
*   Return Value : uint8_t
*****************************************************************************/
extern uint8_t tof_embedded_33d_get_FrameIndex(const uint8_t *pEbdData10bit);


/*****************************************************************************
*   Prototype    : tof_embedded_33d_get_Frequency
*   Description  : api_rd_current_state_tof_frequency_modulation_index
*   Input        : const uint8_t *pEbdData10bit  
*   Output       : None
*   Return Value : uint32_t
*****************************************************************************/
extern ObTofModFreq tof_embedded_33d_get_Frequency(const uint8_t *pEbdData10bit);


/*****************************************************************************
*   Prototype    : tof_embedded_33d_getDriverICTemp
*   Description  : api_rd_current_state_led_driver_ic_temperature
*   Input        : const uint8_t *pEbdData10bit  
*   Output       : None
*   Return Value : float
*****************************************************************************/
extern float tof_embedded_33d_getDriverICTemp(const uint8_t *pEbdData10bit);


/*****************************************************************************
*   Prototype    : tof_embedded_33d_getSensorTemp
*   Description  : api_rd_general_temperature
*   Input        : const uint8_t *pEbdData10bit  
*   Output       : None
*   Return Value : float
*****************************************************************************/
extern float tof_embedded_33d_getSensorTemp(const uint8_t *pEbdData10bit);

/*****************************************************************************
*   Prototype    : tof_embedded_33d_getIntegrationTime
*   Description  : api_rd_general_IntegrationTime
*   Input        : const uint8_t *pEbdData10bit  
*   Output       : None
*   Return Value : uint32_t
*****************************************************************************/
extern uint16_t tof_embedded_33d_getIntegrationTime(const uint8_t *pEbdData10bit);

extern int check_EBD_data(uint16_t *EBD_data_start_addr);



#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __TOF_EMBEDDED_H__ */

