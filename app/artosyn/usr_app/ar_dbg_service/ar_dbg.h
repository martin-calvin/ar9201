#ifndef __AR_DBG_H__
#define __AR_DBG_H__

#include <stdint.h>

enum {
	AR_DBG_MSG_SYS = 0x0,
	AR_DBG_MSG_REG = 0x1,
	AR_DBG_MSG_BB  = 0x2,
	AR_DBG_MSG_CMR = 0x3,
};

int dbg_handle_reg(void *client, uint8_t *payload,
		uint32_t payload_len, uint16_t seq_num);

int dbg_handle_sys(void *client,
		uint8_t *payload, uint32_t payload_len);

int dbg_handle_bb(void *client,
		uint8_t *payload, uint32_t payload_len);
void bb_osd_mutex_unlock_callback(void* client);
void bb_osd_mutex_lock_callback(void);

int client_send_ack(void *client, uint8_t *payload,
		uint32_t payload_size, uint8_t msg_id, uint8_t need_checksum);
#endif
