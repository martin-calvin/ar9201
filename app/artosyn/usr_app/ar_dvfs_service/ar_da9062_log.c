#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "ar_da9062_log.h"

FILE * open_da9062_fault_log(char * path)
{
    FILE * log_fd = NULL;
    if(NULL != path)
    {
		if(access(path, F_OK) >= 0)
		{
            log_fd = fopen(path, "r+");
			printf("file is no empty\n");
		}
		else
		{
		    log_fd = fopen(path, "w+");
			if(NULL != log_fd)
			{
			    printf("file is empty, init log file!\n");
                fprintf(log_fd, "%-16d\n", 0);// init file index
                fflush(log_fd);
			}
		}
    }

    return log_fd;
}

    

int get_current_index(FILE * log_fd)
{
    int index = -1;
    if(NULL != log_fd)
    {
        fseek(log_fd, 0, SEEK_SET);
        fscanf(log_fd, "%d", &index);        
    }

    return index;
}



int set_current_index(FILE * log_fd, int index)
{
    if(NULL != log_fd)
    {
        if(index < 0)// if index beyond int limited reset to zero
        {
            index = 0;
        }

        fseek(log_fd, 0, SEEK_SET);
        fprintf(log_fd, "%-16d\n", index);
        fflush(log_fd);
    }

    return index;
}



static int local_index_position(FILE * log_fd, int index)
{
    int row = 0;
    int position = index % MAX_LOG_LIMIT + 1;//add one for the frist line
    char buf[MAX_LENGTH_OF_LINE];

    if(NULL == log_fd || index < 0)
    {
        return -1;
    }

	fseek(log_fd, 0, SEEK_SET);
	
    for(row = 0; row < position; ++row)
    {
        fgets(buf, MAX_LENGTH_OF_LINE, log_fd);
    }

    return row;
}


int read_index_data(FILE * log_fd, int index, char * buffer, int size)
{
    int row = 0;
    int position = index % MAX_LOG_LIMIT + 1;//add one for the frist line

    if(NULL == log_fd || index < 0 || NULL == buffer)
    {
        return -1;
    }

    if(size > MAX_LENGTH_OF_LINE)
    {
        size = MAX_LENGTH_OF_LINE;
    }

    for(row = 0; row < position; ++row)
    {
        fgets(buffer, MAX_LENGTH_OF_LINE, log_fd);
    }

    return row;
}



int write_index_data(FILE * log_fd, char * buffer, int size)
{
    int index = get_current_index(log_fd); 
    int ret = -1;

    if(NULL == log_fd || size > MAX_LENGTH_OF_LINE || NULL == buffer)
    {
        return -1;
    }

    ret = local_index_position(log_fd, index);
    if(ret >= 0)
    {
        ret = fprintf(log_fd, "%d. fault log: %s\n", index, buffer);
        if(ret < 0)
        {
            return ret;
        }
        else
        {
			fflush(log_fd);
            ret = set_current_index(log_fd, index + 1);            
        }
    }
    
    return ret;
}



int write_da9062_fault_log(FILE * log_fd)
{
    FILE * reg_fd = fopen(DA9062_FAULT_REG, "r");
    int ret = -1;

    if(NULL != log_fd && NULL != reg_fd)
    {
        char log[MAX_LENGTH_OF_LINE] = {""};
        fscanf(reg_fd, "%s", log);
        ret = write_index_data(log_fd, log, strlen(log));
        fclose(reg_fd);
    }

    return ret;
}



int close_da9062_fault_log(FILE * log_fd)
{
    if(NULL != log_fd)
    {
        fclose(log_fd);
	    log_fd = NULL;
    }
}
