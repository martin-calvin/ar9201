#ifndef __ICC_USER_API_H__
#define __ICC_USER_API_H__

#include <stdint.h>

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

/* Get a msgid from a string, the receiver and sender should use the SAME string as a token */
unsigned short ar_icc_ftok(const char *path);
void ar_icc_dump_token_id(void);


int ar_icc_open();
int ar_icc_close(int fd);
int ar_icc_register_msgid(int fd, uint32_t msg_id);
int ar_icc_unregister_msgid(int fd, uint32_t msg_id);
int ar_icc_send(int fd, unsigned char *buf, uint32_t size, uint32_t msg_id, uint32_t core_id);
int ar_icc_receive(int fd, unsigned char *buf, uint32_t size, uint32_t msg_id);
#endif
