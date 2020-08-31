#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>


#ifdef FREERTOS

#include "cmsis_os2.h"
#include "dma_malloc.h"
#include "uart.h"
#include "dbglog.h"


#else

int ar_common_enter_critical() {return 0;}
int ar_common_exit_critical(int mask) {return 0;}

#define dma_free 				free
#define dma_malloc 				malloc

#define uart_put_string 		printf
#define dbg_printf				printf

#define UART_DBG_PORT_BASE		"%s"

#endif


#include "ar_logger.h"


#define LOG_INPUT_ENTRY_SIZE			(128)
#define LOG_INPUT_ENTRY_COUNT			(16)

#define LOG_BUFFER_FULL_OVERWRITE  		(0x01 << 0)
#define LOG_ENTRY_WITH_CHECKSUM			(0x01 << 1)

#define EOVERFLOW						(75)
#define ENOMEM							(11)

#ifndef EINVAL
#define EINVAL							(22)
#endif

/*
 * log entry is the format save in logger buffer.
 */
struct logger_entry {
	/*do not use the dbglog_level_type_e, because sizeof(enum) = 4 */
	uint8_t log_level;
	char    payload[DBGLOG_OUTPUT_BUFF_SIZE-2];
	uint8_t ending;
};


/*
 * struct logger_log - represents a specific log, such as 'main' or 'radio'
 */
struct logger_log {
	char 				name[16];			/* the name of the logger */
	uint8_t 			version;			/* the version of logger header */
	uint8_t 			rsv_0[3];			/* alignment */

	size_t				r_entry_off;		/* current read head buffer offset */
	size_t				w_entry_off;		/* current write head offset */

	size_t				entry_size;			/* sizeof each log entry */
	size_t				entry_num;			/* the number of entry buffer */
	size_t				size;				/* size of the log = (entry_size * entry_num)*/
	uint8_t				flag;				/* */
	uint8_t				buf_full;				/* buffer is buf_full*/
	uint8_t				rsv_1[2];			/* reserved */
	uint32_t			rsv_2[2];			/* reserved */
	char 				buffer[0];			/* the ring buffer itself */
};

struct logger_reader {
	struct              logger_log *log;
	size_t              read_from_entry;
};


struct logger_log *log_input = NULL;
struct logger_log *log_output = NULL;


/* logger_entry_offset - returns index 'n' into the log via (optimized) modulus */
#define logger_entry_offset(n, log)			((n) & (log->entry_num - 1))

/* if log->r_entry_off == log->w_entry_off, can write (log->size - 1) bytes */
//#define logger_buf_free_size(log,)			(((log->size -1) + ((log->r_entry_off - log->w_entry_off) * LOG_OUTPUT_ENTRY_SIZE)) & (log->size - 1))

#define logger_data_entry_size(log, read_from_entry)			(((log->entry_num) + (log->w_entry_off - read_from_entry)) & (log->entry_num - 1))

#define logger_flag_check(log, cap)			((log->flag & cap))

#define min(a,b) ((a) < (b) ? (a):(b))


/*
 * do_read_log: and move r_entry_off
 * return: the offset of for log r_entry_off.
 */
static size_t do_read_from_log(struct logger_reader *reader, void *buf, size_t count)
{
	size_t n;
	size_t i;
	size_t entry = count / LOG_OUTPUT_ENTRY_SIZE;
	struct logger_log *log = reader->log;

	//printf("entry num: %d %d %d %d %d\n\n", entry, logger_data_entry_size(log), count, LOG_OUTPUT_ENTRY_SIZE, log->entry_num);
	entry = min(entry, logger_data_entry_size(log, reader->read_from_entry));

	n = min(entry, log->entry_num - reader->read_from_entry);

	//do entry copy
	struct logger_entry *src_entry, *dst_entry;
	src_entry = (struct logger_entry *)log->buffer + reader->read_from_entry;
	dst_entry = (struct logger_entry *)buf;

	for (i = 0 ; i < n; i++) {
		dst_entry->log_level = src_entry->log_level;
		strncpy(dst_entry->payload, src_entry->payload, sizeof(src_entry->payload));
		dst_entry->ending = '\0';
		src_entry ++;
		dst_entry ++;
	}

	//wrap around
	src_entry = (struct logger_entry *)log->buffer;
	for (i = 0 ; i < (entry - n); i++) {
		dst_entry->log_level = src_entry->log_level;
		strncpy(dst_entry->payload, src_entry->payload, sizeof(src_entry->payload));
		dst_entry->ending = '\0';

		src_entry ++;
		dst_entry ++;
	}

	//get the next read point
	reader->read_from_entry = logger_entry_offset(reader->read_from_entry + entry, log);

	//return the entry read from buffer
	return entry;
}

void logger_print_out_entry(char * buf, size_t entry_count)
{
	int i;
	struct logger_entry *entry = (struct logger_entry *)buf;

	for (i = 0; i < entry_count; i++, entry++) {

		//if PRN_UART, FreeRtos printout the msg directly, ignore it
		if (entry->log_level != PRN_UART)
			uart_put_string(UART_DBG_PORT_BASE, entry->payload);
	}
}

/*
 * logger_read - our log's read() method
 *
 * Behavior:
 *
 * 	- O_NONBLOCK works
 * 	- If there are no log entries to read, return 0
 * 	- Atomically reads exactly one log entry
 *
 * Optimal read size is LOGGER_ENTRY_MAX_LEN. Will set errno to EINVAL if read
 * buffer is insufficient to hold next entry.
 */
int logger_read_entry(struct logger_reader *reader, char *buf,
			   size_t count)
{
	size_t ret = 0;

	if (reader== NULL || reader->read_from_entry < 0 || reader->read_from_entry > reader->log->entry_num) {
		reader->read_from_entry = reader->log->r_entry_off;
		return -EINVAL;
	}

	//check empty
	if (reader->log->w_entry_off == reader->read_from_entry)
		return 0;

	/* get exactly one entry from the log, and move log->r_entry_off */
	if (LOG_OUTPUT_ENTRY_SIZE > count)
		ret = -EOVERFLOW;
	else
		ret = do_read_from_log(reader, buf, count);

	return ret;
}


/* Use static because buf size = 2k, some tasks stack overflow */
static char buf[LOG_OUTPUT_ENTRY_SIZE * 8] = {0};

/*
 * I dont handle the PRN_UART log_level here, because dont want the lock function.
*/
int logger_output(uint8_t log_level, struct logger_log *log, const char *szFormat, va_list ap)
{
	int len, mask;

	if (!log)
		return 0;

	len = vsnprintf(buf, sizeof(buf) - 1, szFormat, ap);
	buf[len] = 0;

	//printf("writing to buffer: %s %d %s %d\n", buf, len, log->buffer, strlen(log->buffer));

	mask = ar_common_enter_critical();

	int copy_size = 0;

	struct logger_entry *entry = (struct logger_entry *)log->buffer + log->w_entry_off;
	while (copy_size < len) {

		int tmp = min(len - copy_size, (sizeof(entry->payload)));
		entry->log_level = log_level;

		//If there is no terminating null byte in the first n bytes of src,
		// strncpy() produces an unterminated string in dest.  You can force termination using something like the following:
		strncpy(entry->payload, buf+copy_size, tmp);
		entry->payload[tmp] = '\0';
		entry->ending = '\0';
		copy_size += tmp;

		//printf("%p %p %p %p: %s | %s\n", entry, entry->payload, log->buffer, log, log->buffer, entry->payload);

		log->w_entry_off = logger_entry_offset(log->w_entry_off + 1, log);
		entry = (struct logger_entry *)log->buffer + log->w_entry_off;

		//fix up read entry, if entry is buf_full
		if (log->buf_full)
			log->r_entry_off = logger_entry_offset(log->w_entry_off + 1, log);
		else
			log->buf_full = (log->w_entry_off == log->r_entry_off);
	}

	ar_common_exit_critical(mask);

	return len;
}


static int inline do_log_init(struct logger_log **log, char *name, size_t entry_count, uint32_t flag)
{
	(*log) = dma_malloc(sizeof(struct logger_log) + entry_count * LOG_OUTPUT_ENTRY_SIZE + 64);

	if ((*log) == NULL)
		return -ENOMEM;

	(*log)->w_entry_off	= 0;
	(*log)->r_entry_off	= 0;
	(*log)->buf_full	= 0;
	(*log)->flag		= flag;

	(*log)->size = entry_count * LOG_OUTPUT_ENTRY_SIZE;
	(*log)->entry_num  = entry_count;
	(*log)->version    = 0;
	(*log)->entry_size = LOG_INPUT_ENTRY_SIZE;

	strncpy((*log)->name, name, sizeof((*log)->name) -1);

	return 0;
}


static int inline logger_deinit(struct logger_log **log)
{
	struct logger_log * p_log = *log;

	if (log == NULL)
		return -1;

	if (p_log) {
		if (p_log->buffer)
			dma_free(p_log->buffer);

		dma_free(p_log);
	}

	p_log = NULL;

	return 0;
}


/*
 * init function for loggers (log_output, log_input, log_backtrace)
 */
int loggers_init(void)
{
	int ret;

	ret = do_log_init(&log_output, LOGGER_LOG_OUTPUT, LOG_OUTPUT_ENTRY_COUNT, LOG_BUFFER_FULL_OVERWRITE);
	if (ret)
		goto out;

#if 0
	ret = do_log_init(&log_input, LOGGER_LOG_INPUT, LOG_INPUT_ENTRY_COUNT, LOG_ENTRY_WITH_CHECKSUM);
	if (ret)
		goto out;
#endif

	dbg_printf(PRN_UART, "loggers_init: log_output = %p %p %p\n\n", \
				log_output, log_output->buffer, (char *)log_output->buffer + LOG_OUTPUT_ENTRY_SIZE * LOG_OUTPUT_ENTRY_COUNT);

	memset((char *)log_output->buffer + LOG_OUTPUT_ENTRY_SIZE * LOG_OUTPUT_ENTRY_COUNT, 'b', 64);

	return 0;

out:
	if (log_output)
		logger_deinit(&log_output);

	return ret;
}

struct logger_log * logger_get_log_from_name(char *name)
{
	if (strcmp(name, LOGGER_LOG_OUTPUT) == 0)
		return log_output;
	else if (strcmp(name, LOGGER_LOG_INPUT) == 0)
		return log_input;

	return NULL;
}

char * logger_get_entry_payload(struct logger_entry *entry)
{
	if (entry)
		return entry->payload;

	return NULL;
}

int logger_get_entry_level(struct logger_entry *entry)
{
	if (entry)
		return entry->log_level;

	return (-1);
}


struct logger_reader * logger_create_reader(char *name)
{
	struct logger_reader * reader = malloc(sizeof(struct logger_reader));
	if (reader == NULL)
		return NULL;

	if (strcmp(name, LOGGER_LOG_OUTPUT) == 0)
		reader->log = log_output;
	else if (strcmp(name, LOGGER_LOG_INPUT) == 0)
		reader->log = log_input;

	reader->read_from_entry = reader->log->r_entry_off;

	return reader;
}


/*
 *
*/
struct logger_reader * logger_create_reader_from_logger(struct logger_log *log)
{
	struct logger_reader * reader = malloc(sizeof(struct logger_reader));

	if (reader == NULL)
		return NULL;

	//print out log info
	printf("logger info: \n");
	printf("\tname: %s\n", log->name);
	printf("\tversion: %d\n", log->version);
	printf("\tentry num: %d\n", log->entry_num);
	printf("\twrite entry off: %d\n", log->w_entry_off);
	printf("\tread entry off: %d\n", log->r_entry_off);

	//sanity check:
	if (strlen(log->name) > sizeof(log->name) || log->r_entry_off >= log->entry_num || log->w_entry_off >= log->entry_num)
		return NULL;

	reader->log = log;
	reader->read_from_entry = reader->log->r_entry_off;

	return reader;
}


void logger_readder_seeek(struct logger_reader *reader, int offset, int where)
{
	if (where == SEEK_END)
		reader->read_from_entry = (reader->log->w_entry_off + offset) & (reader->log->entry_num - 1);
	else if (where == SEEK_CUR)
		reader->read_from_entry = (reader->read_from_entry + offset) & (reader->log->entry_num - 1);
	else if (where == SEEK_SET)
		reader->read_from_entry = (reader->read_from_entry + offset) & (reader->log->entry_num - 1);
}


void print_log(struct logger_log *log)
{
	int i;
	struct logger_entry *entry = (struct logger_entry *)log->buffer;

	printf("dump++\nname:%s r:%d w:%d size:%d num:%d\r\n", log->name ,log->r_entry_off, log->w_entry_off, LOG_OUTPUT_ENTRY_SIZE, log->entry_num);

	for (i = log->r_entry_off; i < log->w_entry_off; i++) {
		printf("|| %d: %d %p: %s", i, entry->log_level, entry->payload, entry->payload);
		entry ++;
	}

	printf("dump--\n");
}

#ifdef __x86_64
int dbg_printf(uint8_t log_level, struct logger_log *log, const char *szFormat, ...)
{
	int ret;
	va_list args;
	va_start(args, szFormat);

	ret = logger_output(log_level, log, szFormat, args);
	va_end(args);

	return ret;
}


int main(int argc, char *argv)
{
	int ret;
	int i;
	char buf[512] = {0};

	ret = loggers_init();

	printf("1: ==========================\r\n");

	struct logger_reader *reader = logger_create_reader(LOGGER_LOG_OUTPUT);
	print_log(reader->log);

	printf("2: ==========================\n\n\n");

	dbg_printf(PRN_BUFF, reader->log, "%s 0x%x\n", "test1", 0x5000);
	print_log(reader->log);
	printf("3: ==========================\n\n\n");

	memset(buf, 0x55, 512);
	buf[511] = 0;
	dbg_printf(PRN_BUFF, reader->log, "%s\n", buf);
	print_log(reader->log);
	printf("4: ==========================\n");

	memset(buf, 0x53, 129);
	buf[129] = 0;
	dbg_printf(PRN_BUFF, reader->log, "%s\n", buf);
	print_log(reader->log);
	printf("4: ==========================\n");

	ret = logger_read_entry(reader, buf, 512);
	printf("get size : %d\n", ret);
	logger_print_out_entry(buf, ret);

	print_log(reader->log);

	printf("5: ==========================\n");

	dbg_printf(PRN_BUFF, reader->log, "%s 0x%x", "test3", 0x5001);
	print_log(reader->log);
	printf("6: ==========================\n");


	ret = logger_read_entry(reader, buf, 512);
	printf("get size : %d %p %p \n", ret, reader, reader->log);

	logger_print_out_entry(buf, ret);

	print_log(reader->log);

	printf("7: ==========================\n");

	return 0;
}
#endif

