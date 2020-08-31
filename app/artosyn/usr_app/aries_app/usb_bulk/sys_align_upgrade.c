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
#include "sys_align_upgrade.h"
#include "sys_utils.h"
#include "spi_flash.h"


static align_file_info alignimage;

static pthread_mutex_t mutex;

typedef struct m_AlignUpgradeStatus {
    int16_t    status;
    int16_t    percentage;
    unsigned char  message[ 256 ];
} m_AlignUpgradeStatus;

static m_AlignUpgradeStatus align_upgrade_status;

/******************************************
该函数用于区分对齐标定文件
包含字符串:
align_43   :   4 : 3 对齐标定文件
align_169 :   16:9对齐标定文件

******************************************/
int32_t match_align_file(int8_t *src,int8_t *ref,uint32_t size)
{
        int8_t *tmp = src;

        if((src == NULL)||(ref == NULL))
        {
             printf("Please enter a non-empty string\n");
             return -1;
        }

        while(*src++ != '\0')
        {
             if(strncmp(src,ref,size) == 0)
             {
                 printf("find align file:%s\n",tmp);
                 return 0;
             }
        }
        return -1;
}

void get_align_upgrade_status(int16_t *status, int16_t *percentage, unsigned char *message)
{
    pthread_mutex_lock(&mutex);

    *status = align_upgrade_status.status;
    *percentage = align_upgrade_status.percentage;
    memcpy(message, align_upgrade_status.message, sizeof(align_upgrade_status.message));
    memset(&align_upgrade_status, 0, sizeof(m_AlignUpgradeStatus));

    pthread_mutex_unlock(&mutex);
}

int upgrade_align_status(int state, int percent)
{               
    printf(">> Upgrade status: %d, percent:%d\n", state, percent);

    pthread_mutex_lock(&mutex);

    align_upgrade_status.status = state;
    align_upgrade_status.percentage = percent;

    switch(state)
    {
        case ALIGN_STAT_PREPAR:
            strcpy(align_upgrade_status.message, "Prepar ...");
            break;
        case ALIGN_ERR_DDR:
            strcpy(align_upgrade_status.message, "Out of memory space !");
            break;
        case ALIGN_ERR_NOT_ENOUGH_SPACE:
            strcpy(align_upgrade_status.message, "Not enough flash space !");
            break;
        case ALIGN_ERR_PATH_NOT_WRITABLE:
            strcpy(align_upgrade_status.message, "The target file is not writable !");
            break;
        case ALIGN_STAT_DONE:
            strcpy(align_upgrade_status.message, "Update Completed !");
            break;
	    case ALIGN_ERR_MD5_ERROR:
            strcpy(align_upgrade_status.message, "File md5 check error !");
            break;
    }

    pthread_mutex_unlock(&mutex);
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
int sys_align_upgrade_init()
{
        printf("--------sys_align_upgrade_init-----------\n");

    memset(&align_upgrade_status, 0x00, sizeof(m_AlignUpgradeStatus));
    pthread_mutex_init(&mutex, NULL);
    return 0;
}


int sys_align_upgrade_recv(void * data, unsigned int len)
{

    int ret = -1;
    static CAL_FILE_HEADER AlignFileHeader;

    if (len == sizeof(UsbFileTransferBag) && magic_num_check(data) == 0)
    {
        /* Start or Finish or Stop */
        UsbFileTransferBag *usb_file_bag = data;
        switch (usb_file_bag->cmd)
        {
        case USB_FILE_TRANSFER_UPGRADE_START:
            // USB文件传输开始
            printf(">>> Upgrade receive start! len : %d\n", usb_file_bag->file_size);
            printf("file transfer receive start! name:%s\n", usb_file_bag->target_path);

            if(NULL != alignimage.pimage)
            {
                free(alignimage.pimage);
                alignimage.pimage = NULL;
            }
            alignimage.total_len = usb_file_bag->file_size + sizeof(CAL_FILE_HEADER);             //buffer大小为数据长度加上标定文件头的长度
            alignimage.pimage = (unsigned char *)malloc(alignimage.total_len);
            alignimage.offset = sizeof(CAL_FILE_HEADER);                                          //标定文件从标定文件头后的位置开始缓存
            memset(alignimage.file_path, 0x00, sizeof(alignimage.file_path));
            
	    if(!match_align_file(usb_file_bag->target_path,"align_34",strlen("align_34")))        //标定文件含有"align_34"字段表示3:4的标定文件
            {
                strcpy(alignimage.file_path, ALIGN_34_FILE_PATH);                                 //3:4标定文件存放位置:"/factory/align_34.bin"
                AlignFileHeader.file_addr = ALIGN_34_FILE_ADDR + sizeof(CAL_FILE_HEADER); 
	    }
	    else if(!match_align_file(usb_file_bag->target_path,"align_169",strlen("align_169"))) //标定文件含有"align_169"字段表示16:9的标定文件
            {
                strcpy(alignimage.file_path, ALIGN_169_FILE_PATH);                                //16:9标定文件存放位置:"/factory/align_169.bin"
	        AlignFileHeader.file_addr = ALIGN_169_FILE_ADDR + sizeof(CAL_FILE_HEADER); 
	    }
			
	    AlignFileHeader.file_size = usb_file_bag->file_size;
	    memcpy(AlignFileHeader.md5sum, usb_file_bag->md5sum, 16);               
	    memcpy(alignimage.pimage, &AlignFileHeader, sizeof(CAL_FILE_HEADER));                 //把文件头拷贝到buffer中    
            memcpy(alignimage.md5sum, usb_file_bag->md5sum, 16);

            if(alignimage.pimage == NULL)
            {
                printf("malloc failed: %d\n", alignimage.total_len);
                upgrade_align_status(ALIGN_ERR_DDR, 0);
                ret = -1;
            }else{
                upgrade_align_status(0, 0);
                ret = 0;
            }
            break;
        case USB_FILE_TRANSFER_UPGRADE_STOP:
            // 传输终止
            printf(">>> Upgrade receive Stop!\n");
            if(NULL != alignimage.pimage)
            {
                free(alignimage.pimage);
                alignimage.pimage = NULL;
            }
            alignimage.offset = 0;
            alignimage.total_len = 0;
            ret = 0;
            break;
        case USB_FILE_TRANSFER_UPGRADE_FINISH:
            // 传输完成
            printf(">>> Upgrade receive Finish!\n");

            if(alignimage.offset >= alignimage.total_len)
            {
                unsigned char decrypt[17];
                memset(decrypt, 0x00, sizeof(decrypt));
                //alignimage.pimage前面存放的是文件头
                md5_sum(alignimage.pimage + sizeof(CAL_FILE_HEADER), alignimage.total_len-sizeof(CAL_FILE_HEADER), decrypt);    

                if (compare_chars(alignimage.md5sum, decrypt, 16) == 0)
                {
                    //
                    ret = write_to_file(alignimage.pimage, alignimage.file_path, alignimage.total_len);     //先存到/factory目录下
                    if (ret == 0)
                    {
                        //把标定文件和文件头写入Flash
                        ret = write_buffer_to_device(alignimage.pimage,alignimage.total_len,AlignFileHeader.file_addr-sizeof(CAL_FILE_HEADER) ,WRITE_BLOCK_SIZE);
                        if(ret == 0)
                        {
                            memset(alignimage.pimage, 0x00, alignimage.total_len);
                            memset(decrypt, 0x00, sizeof(decrypt));

                            //读出写入flash的数据用于校验，包括文件头
                            read_buffer_from_device(alignimage.pimage,alignimage.total_len,AlignFileHeader.file_addr-sizeof(CAL_FILE_HEADER),READ_BLOCK_SIZE);
                            CAL_FILE_HEADER *AlignFileHeaderTmp = (CAL_FILE_HEADER *)alignimage.pimage;     //从读出的buffer中取出文件头
                            printf("the length of align file is:%d\n",AlignFileHeaderTmp->file_size);                            
                            printf("the address of align file is:0x%x\n",AlignFileHeaderTmp->file_addr);      

                            //校验从flash中读出的数据，要减去文件头的长度
                            md5_sum(alignimage.pimage + sizeof(CAL_FILE_HEADER), alignimage.total_len-sizeof(CAL_FILE_HEADER), decrypt);   

                            if (compare_chars(AlignFileHeaderTmp->md5sum, decrypt, 16) == 0)
                            {
                                upgrade_align_status(ALIGN_STAT_DONE, 100);
                            }
                            else
                            {
                                upgrade_align_status(ALIGN_ERR_MD5_ERROR, 0);
                            }
                        }                           

                        if (alignimage.pimage != NULL){
                            free(alignimage.pimage);
                            alignimage.offset = 0;
                            alignimage.total_len = 0;
                            alignimage.pimage = NULL;
                        }
                    }else{
                        upgrade_align_status(ALIGN_ERR_PATH_NOT_WRITABLE, 100);
                    }
                }else{
                    upgrade_align_status(ALIGN_ERR_MD5_ERROR, 0);
                }
            }else{
                printf(">>> The file transfer is complete, but the length is incorrect !");
            }
            ret = 0;
            break;
        default:
            break;
        }
    }else{
        if(0 != alignimage.total_len && alignimage.offset < alignimage.total_len)
        {
            if(alignimage.pimage == NULL)
            {
                printf("buffer allocate for alignimage is null\n");
                upgrade_align_status(ALIGN_ERR_DDR, 0);
                return -1;
            }

            memcpy(alignimage.pimage + alignimage.offset, data, len);
            alignimage.offset += len;
            ret = 0;
        }
        else
        {
            printf("sys_calibration_upgrade_recv no operation!\n");
        }
    }
    return ret;
}






