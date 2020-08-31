/* Linux */
#include <linux/types.h>
#include <linux/input.h>
#include <linux/hidraw.h>

/* Unix */
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* C */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "hid_service.h"
#include "sys_filetran.h"

static file_info fileinfo;
static file_info fgetinfo;


static int check_start_mark(char * data, char * mark, unsigned int len)
{
    int i;
    for(i = 0; i < strlen(mark); ++i)
    {
        if(data[i] != mark[i])
            return -1;
    }
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////
int sys_filetran_init()
{
    //image.image_fd = fopen("/tmp/upgrade.img", "wb");
    return 0;
}


int sys_filetran_recv(void * data, unsigned int len)
{
    int ret;

    //printf("len:%d\n", len);

    if(strlen(filetran_start_mark) + sizeof(int) + MAX_FILE_LEN == len)
    {
        char * pcmd = (char *)data;
        printf("fileRecv start cmd check! cmd:%c%c%c%c\n", pcmd[0], pcmd[1], pcmd[2], pcmd[3]);

        if(0 == check_start_mark((char *)data, filetran_start_mark, strlen(filetran_start_mark)))
        {
            unsigned int * data_len = (unsigned int *)((char *)data + strlen(filetran_start_mark));
            char   * filename = ((char *)data + strlen(filetran_start_mark) + sizeof(int));
            char   path[512] = {""};

            if(NULL != fileinfo.pfile)
            {
                fclose(fileinfo.pfile);
                fileinfo.pfile = NULL;
            }

            sprintf(path, "%s/%s", ROOT_PATH, filename);
            printf("file transfer receive start! len:%d name:%s\n", *data_len, path);

            fileinfo.pfile = fopen(path, "wb");
            fileinfo.offset = 0;
            fileinfo.total_len = *data_len;
            fseek(fileinfo.pfile, 0, SEEK_SET);
            return 0;
        }
        else
        {
            printf("file transfer start cmd check failed!\n");
        }
    }

    if(0 != fileinfo.total_len && fileinfo.offset < fileinfo.total_len)
    {
        fwrite((char *)data, 1 , len, fileinfo.pfile);
        fileinfo.offset += len;

        if(fileinfo.offset >= fileinfo.total_len)
        {
            printf("file transfer receive complete!\n");
            fclose(fileinfo.pfile);
            fileinfo.offset = 0;
            fileinfo.total_len = 0;
            fileinfo.pfile = NULL;
        }
        ret = 0;
    }
    else
    {
        printf("sys_filetran_revc no operation!\n");
    }

    return ret;
}


/////////////////////////////////////////////////////////////////////////////////////////////////
int sys_fileget_init()
{
    //image.image_fd = fopen("/tmp/upgrade.img", "wb");
    return 0;
}


int sys_fileget_recv(void * data, unsigned int len)
{
	//int ret;
	if(strlen(fileget_start_mark) + MAX_FILE_LEN == len)
	{
	    char * pcmd = (char *)data;
		printf("start cmd check! cmd:%c%c%c%c\n", pcmd[0], pcmd[1], pcmd[2], pcmd[3]);
		
		if(0 == check_start_mark((char *)data, fileget_start_mark, strlen(fileget_start_mark)))
		{
		    unsigned int data_len = 0;
            char   * filename = ((char *)data + strlen(fileget_start_mark));
            char   path[512] = {""};		
			
			if(NULL != fgetinfo.pfile)
            {
                fclose(fgetinfo.pfile);
                fgetinfo.pfile = NULL;
            }
		    
		    sprintf(path, "%s", filename);
		    
		    fgetinfo.pfile = fopen(path, "rb");
            if(NULL == fgetinfo.pfile)
            {
		        unsigned char * buffer = NULL;
                printf("open file failed!\n");
		    	buffer = get_hid_send_buffer(64, INDEX_SYS_FILEGET);
                if(NULL != buffer)
                {
                    sprintf((char *)buffer, "open file failed!\n");
                    hid_send_data(buffer, 64, NULL);
                    buffer = NULL;
                }
		    	return 0;
            }
            else
		    {
				unsigned char * buffer = NULL;
				
		        fseek(fgetinfo.pfile, 0, SEEK_END);
		    	data_len = ftell(fgetinfo.pfile);
		    	fseek(fgetinfo.pfile, 0, SEEK_SET);
				
				fgetinfo.offset = 0;
                fgetinfo.total_len = data_len;
		    	
		    	printf("file get start! len:%d name:%s\n", data_len, path);
		    	buffer = get_hid_send_buffer(64, INDEX_SYS_FILEGET);
                if(NULL != buffer)
                {
				    unsigned int *len = NULL;
				    memset(buffer, 0, 64);
                    buffer[0] = 'f';
					buffer[1] = 'g';
					buffer[2] = 'e';
					buffer[3] = 't';
					len = (unsigned int *)(buffer + 4);
					*len = data_len;
					
					//send size
                    hid_send_data(buffer, 64, NULL);
                    buffer = NULL;
		    		
					//send file data
		    		buffer = get_hid_send_buffer(data_len, INDEX_SYS_FILEGET);
					if(buffer == NULL)
						printf("buffer NULL\n");
						
					fread((char *)buffer, 1 , data_len, fgetinfo.pfile);
					hid_send_data(buffer, data_len, NULL);
					buffer = NULL;		
					printf("fget commplete!\n");
                }
				
				fclose(fgetinfo.pfile);
                fgetinfo.pfile = NULL;
		    }
		}
	}
	return 0;
}

#if 0
/////////////////////////////////////////////////////////////////////////////////////////////////
int sys_filelist_init()
{
    //image.image_fd = fopen("/tmp/upgrade.img", "wb");
    return 0;
}


int sys_filelist_recv(void * data, unsigned int len)
{
	//int ret;
	if(strlen(filelist_start_mark) + MAX_FILE_LEN == len)
	{
	    char * pcmd = (char *)data;
		printf("start cmd check! cmd:%c%c%c%c\n", pcmd[0], pcmd[1], pcmd[2], pcmd[3]);
		
		if(0 == check_start_mark((char *)data, filelist_start_mark, strlen(filelist_start_mark)))
		{
		    //unsigned int data_len = 0;
            char   * pathname = ((char *)data + strlen(filelist_start_mark));
            char   cmd_line[512] = {""};
            FILE   * cmd_pipe;		
            unsigned char * buffer = NULL;			
		    
		    sprintf(cmd_line, "ls -a %s", pathname);
			
			cmd_pipe = popen(cmd_line, "r");
			if(NULL == cmd_pipe)
			{
			    printf("cammend fail!\n");
			    return 0;
			}
			
			while(1)
			{
			    unsigned int max_len = MAX_SEND_PACKET_LEN - sizeof(STRU_USB_HEADER) - sizeof(STRU_HID_HEADER);
			    buffer = get_hid_send_buffer(max_len, INDEX_SYS_FILELIST);
				if(NULL != fgets(buffer, max_len, cmd_pipe))
				{
				    hid_send_data(buffer, max_len, NULL);
					break;
				}
				hid_send_data(buffer, max_len, NULL);
			}
			
			pclose(cmd_pipe);
		}
	}
	
	return 0;
}
#endif