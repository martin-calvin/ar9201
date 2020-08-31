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
#include "sys_upgrade.h"
#include "ar_flash.h"
#include "ar_wdt.h"

static image_info image;


int sys_upgrade_init()
{
    //image.image_fd = fopen("/tmp/upgrade.img", "wb");
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

static int show_upgrade(int state, int percent)
{
    printf("Upgrade status: %d, percent:%d\n", state, percent);
    char * buffer = NULL;
    unsigned int buf_len = 64;
    struct timespec ts;

    ts.tv_sec = 1;
    ts.tv_nsec = 0;

    buffer = get_hid_send_buffer(buf_len, INDEX_SYS_UPGRADE);
    if(NULL != buffer)
    {
        sprintf(buffer, "Upgrade status: %d, percent:%d\n", state, percent);
        hid_send_data(buffer, buf_len, &ts);
        buffer = NULL;
    }

    return 0;
}

int upgrade_form_disk(unsigned char * upgrade_img, unsigned int len)
{
        int ret;
        //char * upgrade_img;

        printf("Artosyn Upgrade, Version: %s %s len:%d\n", __DATE__, __TIME__, len);

        /*upgrade_img = (char *)malloc(len);
        if(!upgrade_img)
        {
            printf("malloc failed error %d, %d\n", __LINE__ , errno);
            return -1;
        }

        ret = fread(upgrade_img, 1, len, fp);
        if(ret <= 0)
        {
            printf("error %d, %d, %d\n", __LINE__, ret, errno);
            free(upgrade_img);
            return -1;
        }
        printf("file len: %d\n", ret);*/

        ret = ar_flash_program(upgrade_img, len, show_upgrade);
        if(ret < 0)
        {
            printf("error %d, %d, %d\n", __LINE__, ret, errno);
            //free(upgrade_img);
            return -1;
        }

        //free(upgrade_img);

        printf("upgrade success!\n");
        return 0;
}



int sys_upgrade_recv(void * data, unsigned int len)
{
    char mark[]  = upgrade_start_mark;
    char mark1[] = upgrade_prpa_mark;
    int ret;
    char * buffer = NULL;
    //unsigned int buf_len = 64;

    //printf("len:%d\n", len);

    if(strlen(mark) + sizeof(int) == len)
    {
        char * pcmd = (char *)data;
        printf("upgrade start cmd check! cmd:%c%c%c%c\n", pcmd[0], pcmd[1], pcmd[2], pcmd[3]);
        
        if(0 == check_start_mark((char *)data, mark1, strlen(mark)))
        {
            int sta = system("/tmp/ota-prepare.sh");
            
            buffer = get_hid_send_buffer(16, INDEX_SYS_UPGRADE);
            if(buffer != NULL)
            {
                sprintf(buffer, "prepare:%d", sta);
                hid_send_data(buffer, 16, NULL);
                buffer = NULL;
            }
            return 0;
        }
        

        if(0 == check_start_mark((char *)data, mark, strlen(mark)))
        {
            unsigned int * data_len = (unsigned int *)((char *)data + strlen(upgrade_start_mark));

            if(NULL != image.pimage)
            {
                free(image.pimage);
                //fclose(image.pimage);
                image.pimage = NULL;
            }

            printf("upgrade receive start! len:%d\n", *data_len);

            image.pimage = (unsigned char *)malloc(*data_len);
            
            if(image.pimage == NULL)
            {
                printf("malloc failed: %d\n", data_len);
                buffer = get_hid_send_buffer(16, INDEX_SYS_UPGRADE);
                if(buffer != NULL)
                {
                    sprintf(buffer, "mallocfail");
                    hid_send_data(buffer, 16, NULL);
                    buffer = NULL;
                }
            }
            //image.pimage = fopen("/tmp/upgrade.img", "wb+");
            image.offset = 0;
            image.total_len = *data_len;
            //fseek(image.pimage, 0, SEEK_SET);
            //todo
            return 0;
        }
        else
        {
            printf("upgrade start cmd check failed!\n");
        }
    }

    if(0 != image.total_len && image.offset < image.total_len)
    {
        if(image.pimage == NULL)
        {
            printf("buffer allocate for image is null\n");
            return -1;
        }
    
        memcpy(image.pimage + image.offset, data, len);
        //fwrite((char *)data, 1 , len, image.pimage);
        image.offset += len;

        if(image.offset >= image.total_len)
        {
            int upgrade_ret;
            struct timespec ts;

            buffer = get_hid_send_buffer(64, INDEX_SYS_UPGRADE);
            printf("upgrade receive complete(offset: %d total_len: %d)!\n", image.offset, image.total_len);
            //fflush(image.pimage);
            //fseek(image.pimage, 0, SEEK_SET);

            if((upgrade_ret = upgrade_form_disk(image.pimage, image.total_len)) < 0)
            {
                if(NULL != buffer)
                {
                    sprintf(buffer, "upgrade failed!(ret = %d)\n", upgrade_ret);
                }
                printf("upgrade failed!(ret = %d)\n", upgrade_ret);
            }
            else
            {
                if(NULL != buffer)
                {
                    sprintf(buffer, "upgrade complete\n");
                }
                printf("upgrade complete!\n");
            }

            free(image.pimage);
            //fclose(image.pimage);
            image.offset = 0;
            image.total_len = 0;
            image.pimage = NULL;

            //todo notify host
            if(NULL != buffer)
            {
                ts.tv_sec = 1;
                ts.tv_nsec = 0;
                hid_send_data(buffer, 64, &ts);
                buffer = NULL;
            }

            sleep(10);

            //ar_wdt_reset();//reboot the system
            //system("killall ar_wdt_service");
            // rebootDev();
        }
        ret = 0;
    }
    else
    {
        printf("sys_upgrade_revc no operation!\n");
    }

    return ret;
}
