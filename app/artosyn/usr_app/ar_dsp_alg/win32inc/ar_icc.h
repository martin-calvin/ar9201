/****************************************************************************
 * Copyright (C) 2019 Shanghai Artosyn Microelectronics Limited.            *
 ****************************************************************************/

/** \addtogroup bsp 
 *  @{
 */

/**
 * @file ar_icc.h
 * @author Artosyn
 * @date 9 May 2019
 * @brief Inter-core communication(ICC) api
 */

#ifndef __ICC_USER_API_H__
#define __ICC_USER_API_H__

#include <stdint.h>
#ifdef __cplusplus
extern "C"{
#endif

enum {
	ICC_CORE_A_0,
	ICC_CORE_A_1,
	ICC_CORE_A_2,
	ICC_CORE_A_3,

	ICC_CORE_M_0,
	ICC_CORE_M_1,
	ICC_CORE_M_2,
	ICC_CORE_M_3,

	ICC_CORE_CEVA_0,
	ICC_CORE_CEVA_1,
	ICC_CORE_CEVA_2,
	ICC_CORE_CEVA_3,

	ICC_CORE_TOTAL,
};

/**
* @brief Open icc device node to create an icc client
* @param 	none
*           host    board ip address
* @retval >=0    icc device fd
* @retval !0   fail
*/
int ar_icc_open();

/**
* @brief Close icc device fd
* @param 	fd icc device fd returned in ar_icc_open()
* @retval 0    success
* @retval !0   fail
*/
int ar_icc_close(int fd);

/**
* @brief Get a msgid from a string, the receiver and sender should use the SAME string as a token
* @param 	path input string for hash
* @retval !0    message id generated from hased string
* @retval 0   fail
*/
unsigned short ar_icc_ftok(const char *path);

/**
* @brief Register a message id for the icc client to receive message
* @param fd  icc client fd
*        msg_id message id that is going to be registered
* @retval 0    success
* @retval !0   fail
*/
int ar_icc_register_msgid(int fd, uint32_t msg_id);

/**
* @brief Unregister a message id for the icc client to to stop receiving message
* @param fd  icc client fd
*        msg_id message id that is going to be unregistered
* @retval 0    success
* @retval !0   fail
*/
int ar_icc_unregister_msgid(int fd, uint32_t msg_id);

/**
* @brief Send a message throught the given icc client
* @param fd  icc client fd
*        buf message buffer pointer
*        size message buffer size
*        msg_id message id
*        core id target core id
* @retval 0    success
* @retval !0   fail
*/
int ar_icc_send(int fd, unsigned char *buf, uint32_t size, uint32_t msg_id, uint32_t core_id);

/**
* @brief Receive a message throught the given icc client
* @param fd  icc client fd
*        buf message buffer pointer
*        size message buffer size
*        msg_id message id
* @retval >0    received message size
* @retval <=0   fail
*/
int ar_icc_receive(int fd, unsigned char *buf, uint32_t size, uint32_t msg_id);

/**
* @brief Receive a message throught the given icc client
* @param fd  icc client fd
*        buf message buffer pointer
*        size message buffer size(input) and received message size(output)
*        msg_id message id
*        core_id core id from which the message is received
* @retval 0        success
* @retval <=0   fail
*/
int ar_icc_receive2(int fd, unsigned char *buf, uint32_t *size, uint32_t msg_id, uint32_t *core_id);

/**
* @brief Set time out when receive message
* @param fd  icc client fd
*        timeout time out value in millisecond
* @retval 0        success
* @retval <=0   fail
*/
int ar_icc_set_timeout(int fd, uint32_t timeout);

/**
* @brief Dump all icc token
* @param none
* @retval 0       success
* @retval <=0   fail
*/
void ar_icc_dump_token_id(void);

#ifdef __cplusplus
}
#endif

#endif
/** @}*/
