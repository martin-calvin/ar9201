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
#include <pthread.h>

#include "usb_bulk_protocol.h"
#include "sys_filetran.h"
#include "sys_utils.h"
#include "usb_op_test.h"

static file_info fileinfo;
static file_info fgetinfo;


pthread_mutex_t mutex;

typedef struct m_FileTranStatus {
    int16_t    status;
    int16_t    percentage;
    unsigned char  message[ 256 ];
} m_FileTranStatus;

m_FileTranStatus upgrade_status;

void get_filetran_status(int16_t *status, int16_t *percentage, unsigned char *message)
{
    pthread_mutex_lock(&mutex);

    *status = upgrade_status.status;
    *percentage = upgrade_status.percentage;
    memcpy(message, upgrade_status.message, sizeof(upgrade_status.message));

    pthread_mutex_unlock(&mutex);
}

int upgrade_filetran_status(int state, int percent)
{               
    printf(">> Upgrade status: %d, percent:%d\n", state, percent);

    pthread_mutex_lock(&mutex);

    upgrade_status.status = state;
    upgrade_status.percentage = percent;

    switch(state)
    {
        case FILE_TRAN_STAT_PREPAR:
            strcpy(upgrade_status.message, "Prepar ...");
            break;
        case FILE_TRAN_ERR_DDR:
            strcpy(upgrade_status.message, "Out of memory space !");
            break;
        case FILE_TRAN_ERR_NOT_ENOUGH_SPACE:
            strcpy(upgrade_status.message, "Not enough flash space !");
            break;
        case FILE_TRAN_ERR_PATH_NOT_WRITABLE:
            strcpy(upgrade_status.message, "The target file is not writable !");
            break;
        case FILE_TRAN_STAT_DONE:
            strcpy(upgrade_status.message, "Update Completed !");
            break;
    }

    pthread_mutex_unlock(&mutex);
    return 0;
}


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
    return 0;
}


int sys_filetran_recv(void * data, unsigned int len)
{
    int ret = -1;
    // char * buffer = NULL;

    if (len == sizeof(UsbFileTransferBag) && magic_num_check(data) == 0)
    {
        /* Start or Finish or Stop */
        UsbFileTransferBag *usb_file_bag = data;
        switch (usb_file_bag->cmd)
        {
        case USB_FILE_TRANSFER_UPGRADE_START:
            // USB文件传输开始
            printf("file transfer receive start! name:%s\n", usb_file_bag->target_path);
            memset(fileinfo.file_path, 0x00, sizeof(fileinfo.file_path));
            strcpy(fileinfo.file_path, usb_file_bag->target_path);
            memcpy(fileinfo.md5_sum, usb_file_bag->md5sum, 16);

            fileinfo.pfile = fopen(usb_file_bag->target_path, "wb");
            fileinfo.offset = 0;
            fileinfo.total_len = usb_file_bag->file_size;
            fseek(fileinfo.pfile, 0, SEEK_SET);
            
            usb_op_test_process(usb_file_bag->target_path); //just for test
            upgrade_filetran_status(FILE_TRAN_STAT_PREPAR, 0);
            break;
        case USB_FILE_TRANSFER_UPGRADE_STOP:
            // 传输终止
            printf(">>> Upgrade receive Stop!\n");
            
            fclose(fileinfo.pfile);
            fileinfo.offset = 0;
            fileinfo.total_len = 0;
            fileinfo.pfile = NULL;

            remove(fileinfo.file_path);
            break;
        case USB_FILE_TRANSFER_UPGRADE_FINISH:
            // 传输完成
            printf(">>> Upgrade receive Finish!\n");

            fclose(fileinfo.pfile);
            if(fileinfo.offset >= fileinfo.total_len)
            {
                char * upgrade_img;
                upgrade_img = (char *)malloc(fileinfo.total_len);
                if(!upgrade_img)
                {
                    upgrade_status_update(FILE_TRAN_ERR_MD5_ERROR, 0);
                    break;
                }

                FILE *fp;
                fp = fopen(fileinfo.file_path, "r");
                if(NULL == fp)
                {
                    upgrade_status_update(FILE_TRAN_ERR_MD5_ERROR, 0);
                    break;
                }
                ret = fread(upgrade_img, 1, fileinfo.total_len, fp);
                if(ret <= 0)
                {
                    free(upgrade_img);
                    upgrade_status_update(FILE_TRAN_ERR_MD5_ERROR, 0);
                    break;
                }

                unsigned char decrypt[17];
                memset(decrypt, 0x00, sizeof(decrypt));
                md5_sum(upgrade_img, fileinfo.total_len, decrypt);

                
	            printf("last: %2x\n", upgrade_img[fileinfo.total_len - 1]);

                free(upgrade_img);

                if (compare_chars(fileinfo.md5_sum, decrypt, 16) == 0)
                {
                    printf("file transfer receive complete!\n");
                    
                    fileinfo.offset = 0;
                    fileinfo.total_len = 0;
                    fileinfo.pfile = NULL;
                    upgrade_filetran_status(FILE_TRAN_STAT_DONE, 0);
                }else{
                    upgrade_status_update(FILE_TRAN_ERR_MD5_ERROR, 0);
                }
            }else{
                printf(">>> The file transfer is complete, but the length is incorrect !");
                upgrade_status_update(FILE_TRAN_ERR_MD5_ERROR, 0);
            }
            ret = 0;
            break;
        default:
            break;
        }
    }else{
        if(0 != fileinfo.total_len && fileinfo.offset < fileinfo.total_len)
        {
            fwrite((char *)data, 1 , len, fileinfo.pfile);
            fileinfo.offset += len;
        }
        else
        {
            printf("sys_calibration_upgrade_recv no operation!\n");
        }
    }
    return ret;



    ////////////// Old ///////////////

    // int ret;
    // if(strlen(filetran_start_mark) + sizeof(int) + MAX_FILE_LEN == len)
    // {
    //     char * pcmd = (char *)data;
    //     printf("fileRecv start cmd check! cmd:%c%c%c%c\n", pcmd[0], pcmd[1], pcmd[2], pcmd[3]);

    //     if(0 == check_start_mark((char *)data, filetran_start_mark, strlen(filetran_start_mark)))
    //     {
    //         unsigned int * data_len = (unsigned int *)((char *)data + strlen(filetran_start_mark));
    //         char   * filename = ((char *)data + strlen(filetran_start_mark) + sizeof(int));
    //         char   path[512] = {""};

    //         if(NULL != fileinfo.pfile)
    //         {
    //             fclose(fileinfo.pfile);
    //             fileinfo.pfile = NULL;
    //         }

    //         sprintf(path, "%s/%s", ROOT_PATH, filename);
    //         printf("file transfer receive start! len:%d name:%s\n", *data_len, path);

    //         fileinfo.pfile = fopen(path, "wb");
    //         fileinfo.offset = 0;
    //         fileinfo.total_len = *data_len;
    //         fseek(fileinfo.pfile, 0, SEEK_SET);
    //         return 0;
    //     }
    //     else
    //     {
    //         printf("file transfer start cmd check failed!\n");
    //     }
    // }

    // if(0 != fileinfo.total_len && fileinfo.offset < fileinfo.total_len)
    // {
    //     fwrite((char *)data, 1 , len, fileinfo.pfile);
    //     fileinfo.offset += len;

    //     if(fileinfo.offset >= fileinfo.total_len)
    //     {
    //         printf("file transfer receive complete!\n");
    //         fclose(fileinfo.pfile);
    //         fileinfo.offset = 0;
    //         fileinfo.total_len = 0;
    //         fileinfo.pfile = NULL;
    //     }
    //     ret = 0;
    // }
    // else
    // {
    //     printf("sys_filetran_revc no operation!\n");
    // }

    // return ret;
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
		    	buffer = get_usb_bulk_send_buffer(64, INDEX_SYS_FILEGET);
                if(NULL != buffer)
                {
                    sprintf((char *)buffer, "open file failed!\n");
                    usb_bulk_send_data(buffer, 64, NULL);
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
		    	buffer = get_usb_bulk_send_buffer(64, INDEX_SYS_FILEGET);
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
                    usb_bulk_send_data(buffer, 64, NULL);
                    buffer = NULL;
		    		
					//send file data
		    		buffer = get_usb_bulk_send_buffer(data_len, INDEX_SYS_FILEGET);
					if(buffer == NULL)
						printf("buffer NULL\n");
						
					fread((char *)buffer, 1 , data_len, fgetinfo.pfile);
					usb_bulk_send_data(buffer, data_len, NULL);
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
			    unsigned int max_len = MAX_SEND_PACKET_LEN - sizeof(STRU_USB_HEADER) - sizeof(STRU_BULK_HEADER);
			    buffer = get_usb_bulk_send_buffer(max_len, INDEX_SYS_FILELIST);
				if(NULL != fgets(buffer, max_len, cmd_pipe))
				{
				    usb_bulk_send_data(buffer, max_len, NULL);
					break;
				}
				usb_bulk_send_data(buffer, max_len, NULL);
			}
			
			pclose(cmd_pipe);
		}
	}
	
	return 0;
}
#endif