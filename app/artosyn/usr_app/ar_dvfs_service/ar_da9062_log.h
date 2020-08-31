#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH_OF_LINE	1024
#define MAX_LOG_LIMIT		1000
#define DA9062_FAULT_REG	"/sys/kernel/debug/da9062/fault_log"


FILE * open_da9062_fault_log(char * path);
int get_current_index(FILE * log_fd);
int set_current_index(FILE * log_fd, int index);
int read_index_data(FILE * log_fd, int index, char * buffer, int size);
int write_index_data(FILE * log_fd, char * buffer, int size);
int write_da9062_fault_log(FILE * log_fd);
int close_da9062_fault_log(FILE * log_fd);