#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <malloc.h>
#include <sys/mman.h>
#include <unistd.h>

#include "ar_dbg.h"

#define MMAP_DEVICE "/dev/mem"

#define PAGE_SIZE 0x1000
#define ALIGN_UP(m, n) ((m + ((n) - 1)) & (~((n) - 1)))
#define ALIGN_DOWN(m, n) ((m) & (~((n) - 1)))


enum {
	AR_DBG_REG_WRITE     = 0x0,
	AR_DBG_REG_WRITE_ACK = 0x1,
	AR_DBG_REG_READ      = 0x2,
	AR_DBG_REG_READ_ACK	 = 0x3,
};

enum {
	AR_DBG_REG_TYPE_PAIR = 0x0,
	AR_DBG_REG_TYPE_TRUN = 0x1,
};

struct register_payload_header {
	uint8_t reg_id;
} __attribute__((packed));

struct register_pair {
	uint32_t addr;
	uint32_t val;
} __attribute__((packed));

struct register_wr_pair_req {
	struct register_payload_header header;
	uint8_t type;
	struct register_pair pair[];
} __attribute__((packed));

struct register_wr_trunk_req {
	struct register_payload_header header;
	uint8_t type;
	uint32_t addr;
	uint16_t reg_num;
	uint32_t val[];
} __attribute__((packed));

struct register_wr_ack {
	struct register_payload_header header;
} __attribute__((packed));

struct register_rd_pair_req {
	struct register_payload_header header;
	uint8_t type;
	uint32_t addr[];
} __attribute__((packed));

struct register_rd_trunk_req {
	struct register_payload_header header;
	uint8_t type;
	uint32_t addr;
	uint16_t reg_num;
} __attribute__((packed));

struct register_rd_pair_ack {
	struct register_payload_header header;
	uint16_t seq_num;
	uint8_t type;
	struct register_pair pair[];
} __attribute__((packed));

struct register_rd_trunk_ack {
	struct register_payload_header header;
	uint16_t seq_num;
	uint8_t type;
	uint32_t addr;
	uint16_t reg_num;
	uint32_t val[];
} __attribute__((packed));

static int dbg_handle_reg_wr(void *client, uint8_t *payload, uint32_t payload_len)
{
	struct register_wr_ack *wr_ack;
	int num, i, fd, ret;
	void *vaddr;
	uint32_t size;
	uint32_t start, end, offs;
	uint8_t type = *(uint8_t *)(payload + sizeof(uint8_t));
	uint8_t ack[64];
	uint32_t ack_len;

	fd = open(MMAP_DEVICE, O_RDWR | O_SYNC);
	if(fd < 0)
		return fd;

	if(type == AR_DBG_REG_TYPE_PAIR) {
		struct register_wr_pair_req *wr_req =
			(struct register_wr_pair_req *)payload;
		struct register_pair *wr_pair = wr_req->pair;

		payload_len -= sizeof(*wr_req);

		num = payload_len / sizeof(*wr_pair);

		for(i = 0; i < num; i++) {
			start = ALIGN_DOWN(wr_pair[i].addr, PAGE_SIZE);
			offs = wr_pair[i].addr - start;

			vaddr = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,
				fd, (off_t)start);
			if(vaddr == (void *)-1) {
				goto error;
			}

			*(volatile uint32_t *)(vaddr + offs) = wr_pair[i].val;

			munmap(vaddr, PAGE_SIZE);
		}
	}
	else if(type == AR_DBG_REG_TYPE_TRUN) {
		struct register_wr_trunk_req *wr_trunk =
			(struct register_wr_trunk_req *)payload;
		uint32_t size;

		size = wr_trunk->reg_num * sizeof(uint32_t);
		start = ALIGN_DOWN(wr_trunk->addr, PAGE_SIZE);
		end = ALIGN_UP(wr_trunk->addr + size, PAGE_SIZE);
		offs = wr_trunk->addr - start;

		vaddr = mmap(NULL, end - start, PROT_READ | PROT_WRITE, MAP_SHARED,
			fd, (off_t)start);
		if(vaddr == (void *)-1) {
			goto error;
		}

		for(i = 0; i <wr_trunk->reg_num; i++) {
			*(volatile uint32_t *)(vaddr + offs + i * sizeof(uint32_t)) = wr_trunk->val[i] ;
		}

		munmap(vaddr, size);
	}
	else {
		goto error;
	}

	/* pack ack buffer */
	wr_ack = (struct register_wr_ack *)ack;
	wr_ack->header.reg_id = AR_DBG_REG_WRITE_ACK;
	ack_len = sizeof(*wr_ack);

	ret = client_send_ack(client, ack, ack_len, AR_DBG_MSG_REG, 1);
	if(ret < 0)
		goto error;

	close(fd);
	return 0;
error:
	close(fd);
	return -EINVAL;
}

static int dbg_handle_reg_rd(void *client, uint8_t *payload, uint32_t payload_len,
		uint16_t seq_num)
{
	int num, i, fd, ret;
	void *vaddr;
	uint32_t size;
	uint32_t start, end, offs;
	uint8_t type = *(uint8_t *)(payload + sizeof(uint8_t));
	uint8_t *ack = NULL;
	uint32_t ack_len;

	fd = open(MMAP_DEVICE, O_RDWR | O_SYNC);
	if(fd < 0)
		return fd;

	if (type == AR_DBG_REG_TYPE_PAIR) {
		struct register_rd_pair_req *rd_req =
			(struct register_rd_pair_req *)payload;
		struct register_rd_pair_ack *rd_ack;
		struct register_pair *rd_pair;

		payload_len -= sizeof(*rd_req);

		num = payload_len / sizeof(uint32_t);

		ack_len = sizeof(*rd_ack) + num * sizeof(*rd_pair);

		ack = malloc(ack_len);
		if(!ack) {
			goto error;
		}

		rd_ack = (struct register_rd_pair_ack *)ack;
		rd_ack->header.reg_id = AR_DBG_REG_READ_ACK;
		rd_ack->seq_num = seq_num;
		rd_ack->type = type;
		rd_pair = rd_ack->pair;

		for(i = 0; i < num; i++) {
			start = ALIGN_DOWN(rd_req->addr[i], PAGE_SIZE);
			offs = rd_req->addr[i] - start;
			vaddr = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,
				fd, (off_t)start);
			if(vaddr == (void *)-1) {
				goto error;
			}
			rd_pair[i].addr = rd_req->addr[i];
			rd_pair[i].val = *(volatile uint32_t *)(vaddr + offs);

			munmap(vaddr, PAGE_SIZE);
		}

		ret = client_send_ack(client, ack, ack_len, AR_DBG_MSG_REG, 1);
		if(ret < 0)
			goto error;
	}
	else if (type == AR_DBG_REG_TYPE_TRUN){
		struct register_rd_trunk_req *rd_trunk =
			(struct register_rd_trunk_req *)payload;
		struct register_rd_trunk_ack *rd_ack;

		num = rd_trunk->reg_num;

		size = rd_trunk->reg_num * sizeof(uint32_t);

		start = ALIGN_DOWN((off_t)rd_trunk->addr, PAGE_SIZE);
		end = ALIGN_UP(rd_trunk->addr + size, PAGE_SIZE);
		offs = rd_trunk->addr - start;

		vaddr = mmap(NULL, end - start, PROT_READ | PROT_WRITE, MAP_SHARED,
			fd, (off_t)start);
		if(vaddr == (void *)-1) {
			goto error;
		}

		ack_len = sizeof(*rd_ack) + rd_trunk->reg_num * sizeof(uint32_t);
		ack = malloc(ack_len);
		if(!ack)
			goto error;

		rd_ack = (struct register_rd_trunk_ack *)ack;
		rd_ack->header.reg_id = AR_DBG_REG_READ_ACK;
		rd_ack->seq_num = seq_num;
		rd_ack->type = type;
		rd_ack->addr = rd_trunk->addr;
		rd_ack->reg_num = rd_trunk->reg_num;

		for (i = 0; i < num; i++) {
			rd_ack->val[i] = *(volatile uint32_t *)(vaddr + offs + i * sizeof(uint32_t));
		}

		munmap(vaddr, size);

		ret = client_send_ack(client, ack, ack_len, AR_DBG_MSG_REG, 1);
		if(ret < 0)
			goto error;
	}

	close(fd);
	return 0;
error:
	if(ack)
		free(ack);
	close(fd);
	return -EINVAL;
}

int dbg_handle_reg(void *client, uint8_t *payload,
		uint32_t payload_len, uint16_t seq_num)

{
	struct register_payload_header *header = (struct register_payload_header *)payload;
	int ret;

	switch(header->reg_id) {
	case AR_DBG_REG_WRITE:
		ret = dbg_handle_reg_wr(client, payload, payload_len);
		break;
	case AR_DBG_REG_READ:
		ret = dbg_handle_reg_rd(client, payload, payload_len, seq_num);
		break;
	default:
		return -EINVAL;
	}
}
