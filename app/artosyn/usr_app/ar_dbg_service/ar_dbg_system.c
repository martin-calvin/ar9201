#include <string.h>
#include <stdint.h>
#include <errno.h>

#include "ar_dbg.h"

enum {
	AR_DBG_SYS_CONNECT     = 0x0,
	AR_DBG_SYS_CONNECT_ACK = 0x1,
	AR_DBG_SYS_WRITE       = 0x2,
	AR_DBG_SYS_WRITE_ACK   = 0x3,
	AR_DBG_SYS_READ        = 0x4,
	AR_DBG_SYS_READ_ACK	   = 0x5,
	AR_DBG_SYS_ADB         = 0x6,
};

struct system_req_header {
	uint8_t sys_id;
} __attribute__((packed));

struct system_connect_req {
	struct system_req_header header;
	uint8_t usr_id[16];
	uint8_t usr_pwd[8];
} __attribute__((packed));

struct system_connect_ack {
	struct system_req_header header;
	uint8_t usr_id[16];
} __attribute__((packed));

union dbg_sys_req {
	struct system_connect_req *connect_req;
};

union dbg_sys_ack {
	struct system_connect_ack *connect_ack;
};

int dbg_handle_sys(void *client,
		uint8_t *payload, uint32_t payload_len)
{
	struct system_req_header *header =
		(struct system_req_header *)payload;
	union dbg_sys_req sys_req;
	union dbg_sys_ack sys_ack;
	int ret;
	uint8_t ack[1024];
	uint32_t ack_len;

	switch(header->sys_id) {
	case AR_DBG_SYS_CONNECT:
		sys_req.connect_req = (struct system_connect_req *)payload;
		sys_ack.connect_ack = (struct system_connect_ack *)ack;

		sys_ack.connect_ack->header.sys_id = AR_DBG_SYS_CONNECT_ACK;
		memcpy(sys_ack.connect_ack->usr_id,
			sys_req.connect_req->usr_id,
			16);
		ack_len = sizeof(struct system_connect_ack);
		break;
	default:
		return -EINVAL;
	}

	ret = client_send_ack(client, ack, ack_len, AR_DBG_MSG_SYS, 1);
	if(ret < 0) {
		return ret;
	}
	return 0;
}

