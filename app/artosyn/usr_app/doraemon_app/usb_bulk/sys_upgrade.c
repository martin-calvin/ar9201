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
#include <linux/unistd.h>
#include <sys/syscall.h>

/* C */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

#include "usb_bulk_protocol.h"
#include "sys_upgrade.h"
#include "ar_flash.h"
#include "ar_wdt.h"

static image_info image;

pthread_mutex_t mutex;

typedef struct m_UpgradeStatus { 
    int16_t    status;
    int16_t    percentage;
    unsigned char  message[ 256 ];
} m_UpgradeStatus;

m_UpgradeStatus upgrade_status;

int sys_upgrade_init()
{
    //image.image_fd = fopen("/tmp/upgrade.img", "wb");
    memset(&upgrade_status, 0x00, sizeof(m_UpgradeStatus));

    pthread_mutex_init(&mutex, NULL);
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

void get_firmware_upgrade_status(int16_t *status, int16_t *percentage, unsigned char *message)
{
    pthread_mutex_lock(&mutex);

    // FixMe: 有余升级进度到 state = 2, percent = 99 后就会重启，所以这里做一个临时的转换
    if (upgrade_status.status == 2 && upgrade_status.percentage >= 90)
    {
        *status = STAT_DONE;
        *percentage = 100;
        strcpy(message, "Update Completed !");
    }else{
        *status = upgrade_status.status;
        *percentage = upgrade_status.percentage;
        memcpy(message, upgrade_status.message, sizeof(upgrade_status.message));
    }
    pthread_mutex_unlock(&mutex);
}

static int vsystem(const char *command)
{
	int status, ret = 0;
	pid_t pid;

	pid = vfork();
	if (pid < 0) {
		printf("vfork failed\n");
		return -1;
	} else if (pid == 0) {
		ret = execl("/bin/sh", "sh", "-c", command, (char *)0);
		if (ret < 0) {
			printf("execl failed, errno = %d\n", errno);
			return -1;
		}
	}
	ret = waitpid(pid, &status, 0);
	if (ret != pid) {
		printf("waitpid failed, ret = %d\n", ret);
		return -1;
	}

	if (WIFEXITED(status)) {
		if (WEXITSTATUS(status)) {
			printf("exit status = %d\n", WEXITSTATUS(status));
			return -1;
		}
	} else {
		printf("abort exceptly\n");
		return -1;
	}

	return 0;
}

void to_reboot(void *time_s)
{
    if (image.pimage != NULL){
        free(image.pimage);
        image.offset = 0;
        image.total_len = 0;
        image.pimage = NULL;
    }

    float *s = (float *)time_s;
    printf("Update Finish, Restart in %.2f seconds ... \n", *s);
    sleep(*s);
    vsystem("/etc/init.d/arcastpro_restart.sh");
}

void countdown_reboot(float time_s)
{
    pthread_t thread;
	int ret_thrd1 = pthread_create(&thread, NULL, (void *)&to_reboot, (void *) &time_s);
}

static int upgrade_status_update(int status, int percent)
{               
    printf(">> Upgrade status: %d, percent:%d\n", status, percent);

    pthread_mutex_lock(&mutex);    

    upgrade_status.status = status;
    upgrade_status.percentage = percent;

    switch(status)
    {
        case STAT_VERIFY_IMAGE:
            strcpy(upgrade_status.message, "Starting ...");
            break;
        case STAT_START:
            strcpy(upgrade_status.message, "Verify upgrade image ...");
            break;
        case STAT_IN_PROGRESS:
            strcpy(upgrade_status.message, "Upgrading ...");
            break;
        case STAT_DONE:
            strcpy(upgrade_status.message, "Update Completed !");
            break;
        case ERR_VERIFY:
        case ERR_PROGRAM:
        case ERR_ERASE:
        case ERR_FLASH_TYPE:
        case ERR_IMG_SIZE:
        case ERR_OTHER:
        case ERR_DDR:
            strcpy(upgrade_status.message, "Update ERROR !!!");
            break;
    }

    pthread_mutex_unlock(&mutex);

    
    if (status < 0 || status == STAT_DONE)
    {
        
        if (status == STAT_DONE)
        {
            countdown_reboot(10.0f);
        }
    }

    return 0;
}

void upgrade_image(void *p)
{
    image_info *upgrade_img = &image; // (image_info *)p;
    printf("upgrade_image run in thread ...\n");
//    int ret = ar_flash_program(upgrade_img->pimage, upgrade_img->total_len, upgrade_status_update);
	int ret = ar_upgrade(upgrade_img->pimage, upgrade_img->total_len, upgrade_status_update);
    if(ret < 0)
    {
        printf("error %d, %d, %d\n", __LINE__, ret, errno);
        upgrade_status_update(ret, 0);
    }else{
        printf("upgrade finish!\n");
    }
}

int start_upgrade_thread(image_info *upgrade_img)
{
    pthread_t thread;
	int ret_thrd1 = pthread_create(&thread, NULL, (void *)&upgrade_image, (void *) upgrade_img);
    return ret_thrd1;
}

int sys_upgrade_recv(void * data, unsigned int len)
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
            printf(">>> Upgrade receive start! len : %d\n", usb_file_bag->file_size);

            if(NULL != image.pimage)
            {
                free(image.pimage);
                image.pimage = NULL;
            }
            image.pimage = (unsigned char *)malloc(usb_file_bag->file_size);
            
            if(image.pimage == NULL)
            {
                printf("malloc failed: %d\n", usb_file_bag->file_size);

                // FixMe: 发送错误信息到上位机
                // buffer = get_usb_bulk_send_buffer(16, INDEX_SYS_UPGRADE);
                // if(buffer != NULL)
                // {
                //     sprintf(buffer, "mallocfail");
                //     usb_bulk_send_data(buffer, 16, NULL);
                //     buffer = NULL;
                // }
                ret = -1;
            }else{
                image.offset = 0;
                image.total_len = usb_file_bag->file_size;
                ret = 0;
            }
            break;
        case USB_FILE_TRANSFER_UPGRADE_STOP:
            // 传输终止
            printf(">>> Upgrade receive Stop!\n");
            
            if(NULL != image.pimage)
            {
                free(image.pimage);
                image.pimage = NULL;
            }
            image.offset = 0;
            image.total_len = 0;
            ret = 0;
            break;
        case USB_FILE_TRANSFER_UPGRADE_FINISH:
            // 传输完成
            printf(">>> Upgrade receive Finish!\n");

            if(image.offset >= image.total_len)
            {
                int upgrade_ret;
                struct timespec ts;

                // buffer = get_usb_bulk_send_buffer(64, INDEX_SYS_UPGRADE);
                printf("upgrade receive complete(offset: %d total_len: %d)!\n", image.offset, image.total_len);
                //fflush(image.pimage);
                //fseek(image.pimage, 0, SEEK_SET);

                // FixMe: 升级
                if((upgrade_ret = start_upgrade_thread(&image)) < 0)
                {
                    // if(NULL != buffer)
                    // {
                    //     sprintf(buffer, "upgrade failed!(ret = %d)\n", upgrade_ret);
                    // }
                    printf("upgrade failed!(ret = %d)\n", upgrade_ret);
                }
                else
                {
                    // if(NULL != buffer)
                    // {
                    //     sprintf(buffer, "upgrade complete\n");
                    // }
                    printf("upgrade complete!\n");
                }

                //todo notify host
                // if(NULL != buffer)
                // {
                //     ts.tv_sec = 1;
                //     ts.tv_nsec = 0;
                //     usb_bulk_send_data(buffer, 64, &ts);
                //     buffer = NULL;
                // }

                // sleep(10);

                //ar_wdt_reset();//reboot the system
                //system("killall ar_wdt_service");

                // FixMe: 重启
                // rebootDev();
            }else{
                printf(">>> The file transfer is complete, but the length is incorrect !");
            }
            ret = 0;
            break;
        default:
            break;
        }
    }else{
        if(0 != image.total_len && image.offset < image.total_len)
        {
            if(image.pimage == NULL)
            {
                printf("buffer allocate for image is null\n");
                return -1;
            }
        
            memcpy(image.pimage + image.offset, data, len);
            image.offset += len;
            ret = 0;
        }
        else
        {
            printf("sys_upgrade_revc no operation!\n");
        }
    }

    // FixMe: 查询升级进度
    // int sta = system("/tmp/ota-prepare.sh");     
    // buffer = get_usb_bulk_send_buffer(16, INDEX_SYS_UPGRADE);
    // if(buffer != NULL)
    // {
    //     sprintf(buffer, "prepare:%d", sta);
    //     usb_bulk_send_data(buffer, 16, NULL);
    //     buffer = NULL;
    // }



    return ret;
}
