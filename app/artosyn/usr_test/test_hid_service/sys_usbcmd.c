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
#include "sys_usbcmd.h"


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

int sys_usbcmd_init()
{
    //image.image_fd = fopen("/tmp/upgrade.img", "wb");
    return 0;
}


int sys_usbcmd_recv(void * data, unsigned int len)
{
	//int ret;
	if(strlen(usbcmd_start_mark) + MAX_CMD_LEN == len)
	{
	    char * pcmd = (char *)data;
		printf("start cmd check! cmd:%c%c%c%c\n", pcmd[0], pcmd[1], pcmd[2], pcmd[3]);
		
		if(0 == check_start_mark((char *)data, usbcmd_start_mark, strlen(usbcmd_start_mark)))
		{
		    //unsigned int data_len = 0;
            char   * cmd_line = ((char *)data + strlen(usbcmd_start_mark));
            //char   cmd_line[512] = {""};
            FILE   * cmd_pipe;		
            unsigned char * buffer = NULL;			
		    
		    //sprintf(cmd_line, "ls -a %s", pathname);
			
			cmd_pipe = popen(cmd_line, "r");
			if(NULL == cmd_pipe)
			{
			    printf("cammend fail!\n");
			    return 0;
			}
			
			while(1)
			{
			    unsigned int max_len = MAX_SEND_PACKET_LEN - sizeof(STRU_USB_HEADER) - sizeof(STRU_HID_HEADER);
			    buffer = get_hid_send_buffer(max_len, INDEX_SYS_USBCMD);
				if(NULL == fgets((char *)buffer, max_len, cmd_pipe))
				{
				    hid_send_data(buffer, max_len, NULL);
					break;
				}
				hid_send_data(buffer, max_len, NULL);
			}
			printf("command success!\n");
			pclose(cmd_pipe);
		}
	}
	
	return 0;
}
