/****************************************************************************
 * Copyright (C) 2019 Shanghai Artosyn Microelectronics Limited.            *
 ****************************************************************************/
/** \addtogroup alg 
 *  @{
 */

/**
 * @file ar_alg.h
 * @author Artosyn
 * @date 9 May 2019
 * @brief File containing the APIs to do CNN inference on ARSDK, these can be called on VS platform or on board.
 *        Users can refer to app/artosyn/usr_app/ar_dsp_alg/ for sample code, or contact Artosyn for help.
 * @example <app/artosyn/usr_app/ar_dsp_alg/src/ar_std_mobilenet_ssd.cpp>
 */

#ifndef __AR_ALG_H__
#define __AR_ALG_H__

#ifdef __cplusplus
extern "C"{
#endif

typedef enum WIN32_TARGET_TYPE_e
{
	VS_SIMULATION = 0,
	HARDWARE_SIMULATION
};

#ifdef WIN32_PY_DLL
#define EXPORTFUNC _declspec(dllexport)
#else
#define EXPORTFUNC extern
#endif

/**
* @brief Init system environment to do VS simulation or hardware simulation, only used on Windows, it's a NULL function for arm linux
* @param 	target  run mode 0: vs simulation 1: hardware simulation
*           host    board ip address
* @retval 0    success
* @retval !0   fail
*/
EXPORTFUNC int ar_runtime_init(int target, char * host);
/**
* @brief Deinit system, only used on Windows, it's a NULL function for arm linux
* @param none
* @retval 0    success
* @retval !0   fail
*/
EXPORTFUNC int ar_runtime_deinit(void);
/**
* @brief Configure DSP, including set input/output buffer, weights, etc.
* @param dsp_id  dsp core id
*        p_dsp_cfg_data  AR_DSP_CFG_st pointer
*        data_size AR_DSP_CFG_st size
* @retval 0    success
* @retval !0   fail
*
*/
EXPORTFUNC int ar_alg_cfg_dsp(int dsp_id, char * p_dsp_cfg_data, int data_size);
/**
* @brief Let DSP to run CNN, the output results will be in p_alg_st->output. This is a block API, timeout is 5 seconds.
* @param p_alg_st AR_DSP_ALG_st pointer
* @return return the cfg results
* 	@retval 0    success
*	@retval !0   fail or timeout
*
*/
EXPORTFUNC int ar_do_algrithom(AR_DSP_ALG_st * p_alg_st);
/**
* @brief Let DSP to run CNN, the output results will be in p_alg_st->output. This is a block API, timeout can be set by timeout_ms params, default is 5s.
* @param  p_alg_st algrithom struct pointer
*         timeout_ms timeout value(ms)
* @retval 0    success
* @retval !0   fail
*/
EXPORTFUNC int ar_do_algrithom_with_timeout(AR_DSP_ALG_st * p_alg_st, unsigned long timeout_ms);
/**
* @brief Let DSP to run CNN, the output results will be in p_alg_st->output. This is a non-block API, will return immediately.
* @param p_alg_st RA_DSP_ALG_st pointer
* @retval 0    success
* @retval !0   fail
*/
EXPORTFUNC int ar_do_algrithom_nonblock(AR_DSP_ALG_st * p_alg_st);
/**
* @brief After calling ar_do_algrithom_nonblock, use this API to wait for dsp to finish.
*		 When DSP finishes, the output is still put in p_alg_st->output.
* @param dsp_id dsp core id
* @retval 0    success
* @retval !0   fail
*/
EXPORTFUNC int ar_wait_for_dsp_finish(int dsp_id);
/**
* @brief This is an API for python to call on Windows platform.
* @param size malloc size
* @retval 0    success
* @retval !0   fail
*/
EXPORTFUNC int ar_malloc_py(int size);
/**
* @brief This is an API for python to call on Windows platform.
* @param 	data image addr
*           data_size  image size
*			max_size   max input buffer size
* @retval 0    success
* @retval !0   fail
*/
EXPORTFUNC int ar_load_image_py(char * data, int data_size, int max_size);
/**
* @brief This is an API for python to call on Windows platform.
* @param addr  addr
* @retval 0    success
* @retval !0   fail
*/
EXPORTFUNC int ar_free_image_py(unsigned long addr);
#ifdef __cplusplus
}
#endif

#endif //__AR_ALG_H__
/** @}*/
