#ifndef _LINUX_LOGGER_H
#define _LINUX_LOGGER_H

#define LOGGER_LOG_INPUT			"log_input"
#define LOGGER_LOG_OUTPUT			"log_output"


#define DBGLOG_OUTPUT_BUFF_SIZE			(256)

#define LOG_OUTPUT_ENTRY_SIZE			(DBGLOG_OUTPUT_BUFF_SIZE)
#define LOG_OUTPUT_ENTRY_COUNT			(4096)

#define LOG_INFO_CMD_ID				(0x01)

struct logger_log;

struct logger_reader;

struct logger_entry;


#define		NONE                 "\e[0m"
#define		BLACK                "\e[0;30m"
#define		L_BLACK              "\e[1;30m"
#define		RED                  "\e[0;31m"
#define		L_RED                "\e[1;31m"
#define		GREEN                "\e[0;32m"
#define		L_GREEN              "\e[1;32m"
#define		BROWN                "\e[0;33m"
#define		YELLOW               "\e[1;33m"
#define		BLUE                 "\e[0;34m"
#define		L_BLUE               "\e[1;34m"
#define		PURPLE               "\e[0;35m"
#define		L_PURPLE             "\e[1;35m"
#define		CYAN                 "\e[0;36m"
#define		L_CYAN               "\e[1;36m"
#define		GRAY                 "\e[0;37m"
#define		WHITE                "\e[1;37m"

#define		BOLD                 "\e[1m"
#define		UNDERLINE            "\e[4m"
#define		BLINK                "\e[5m"
#define		REVERSE              "\e[7m"
#define		HIDE                 "\e[8m"
#define		CLEAR                "\e[2J"


struct log_info {
	uint32_t 	pa;
	char 		name[32];
};

typedef enum
{
    PRN_UART=0,
    PRN_ERR,
    PRN_RES,
    PRN_BUFF,
}dbglog_level_type_e;


int loggers_init(void);

/*
 * logger_write - write buffer to logger
 */
int logger_write(struct logger_log *log, const void *buf,
			 size_t len);
/*
 */
int logger_read_entry(struct logger_reader *reader, char *buf,
				   size_t count);

struct logger_log * logger_get_log_from_name(char *name);


struct logger_reader * logger_create_reader(char *name);

int logger_output(uint8_t log_level, struct logger_log *log, const char *szFormat, va_list ap);

void logger_print_out_entry(char * buf, size_t entry_count);

struct logger_reader * logger_create_reader_from_logger(struct logger_log *log);


#endif /* _LINUX_LOGGER_H */

