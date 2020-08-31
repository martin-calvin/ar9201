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
#include <pthread.h>

/* C */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include<malloc.h>

#include <sys/stat.h>

#include "usb_bulk_protocol.h"
#include "sys_upgrade.h"
#include "sys_filetran.h"
#include "sys_usbcmd.h"
#include "sys_calibration_upgrade.h"
#include "sys_align_upgrade.h"


#pragma pack(push)
#pragma pack(1)

typedef struct
{
    unsigned int    cur_len;
    unsigned int    fragment_idx;
    unsigned short  port_index;
    unsigned short  header_len;
    unsigned int    data_len;
}STRU_USB_FRAGMENT_INFO;

typedef struct
{
    int             hid_fd;
    pthread_mutex_t wrt_hid_mutex;
}STRU_HID_DEVICE_INFO;

#pragma pack(pop)

STRU_USB_BULK_RECV_CALLBACK_HANDLER g_hid_recv_callback[RECV_CALLBACK_NUM] =
{
    {INDEX_SYS_UPGRADE, sys_upgrade_init, sys_upgrade_recv},                            //Firmware升级
    {INDEX_SYS_FILEGET, sys_calibration_upgrade_init, sys_calibration_upgrade_recv},    //写入标定文件
    {INDEX_SYS_FILETRAN, sys_filetran_init, sys_filetran_recv},                         //上位机普通文件传输到设备
    {INDEX_SYS_ALIGN, sys_align_upgrade_init, sys_align_upgrade_recv},  
    {INDEX_SYS_USBCMD, sys_usbcmd_init, sys_usbcmd_recv},
    {}
};

unsigned char magic_header[8] = {0xff, 0x55, 0xff, 0xaa, 0x41, 0x52, 0x54, 0x4f};
STRU_USB_FRAGMENT_INFO  fragment_info;
STRU_HID_DEVICE_INFO    hid_device;


static unsigned int get_checksum(unsigned char * data, unsigned int len)
{
    unsigned int checksum = 0;
    while(len)
    {
        checksum += *data++;
        --len;
    }
    return checksum;
}


static int magic_num_check(unsigned char * data)
{
    unsigned int i;
    for(i = 0; i < sizeof(magic_header); ++i)
    {
        if(data[i] != magic_header[i])
            return -1;
    }
    return 0;
}


static int usb_bulk_protocol_analysis(unsigned char * data, unsigned len, unsigned int frame_idx, unsigned int left_frame)
{
    STRU_BULK_HEADER *   phid_header;
    int ret;

    if(0 == frame_idx)//first fragment
    {
        phid_header = (STRU_BULK_HEADER *)data;

        if(phid_header->port_index >= RECV_CALLBACK_NUM)
        {
            printf("port_index too big(%d)!\n", phid_header->port_index);
            return 1;
        }

        if(phid_header->header_len < sizeof(STRU_BULK_HEADER))
        {
            printf("header_len too small(%d)!\n", phid_header->header_len);
            return 1;
        }

        if(NULL != g_hid_recv_callback[phid_header->port_index].recv_callback)//call back check
        {
            if(left_frame > 0)//more fragment
            {
                fragment_info.port_index = phid_header->port_index;//record port index
                fragment_info.data_len = phid_header->data_len;
            }

            ret = g_hid_recv_callback[phid_header->port_index].recv_callback(data + phid_header->header_len,
                                                                             len - phid_header->header_len);

            return ret;
        }
        else//no call back
        {
            printf("unregistered port(%d)!\n", phid_header->port_index);
            return 1;
        }
    }
    else//other fragment(no hid header)
    {
        if(0 != fragment_info.data_len)
        {
            ret = g_hid_recv_callback[fragment_info.port_index].recv_callback(data, len);
        }
        else
        {
            printf("no header!\n");
            ret = 1;
        }
        return ret;
    }
}


int checkVer(char* ver)
{
    FILE *tmpFile;
    char sdkVer[128];
    char *pToken = NULL;
    char *pSave = NULL;
    char *pDel = "-";
    int len;
    
    tmpFile = fopen("/etc/sdk.version", "r");
    if(tmpFile == NULL)
    {
        printf("open failed\n");
        return 1;
    }
    
    len = fread(sdkVer, 1, 128, tmpFile);
    sdkVer[len-1] = '\0';
    
    //printf("sdkVer = %s , len = %d\n", sdkVer, len);
    
    pToken = strtok_r(sdkVer, pDel, &pSave);
    
    while(pToken)
    {
        if(strcmp(pToken, ver) == 0)
        {
            return 0;
        }
        //printf("pToken[%s]; pSave[%s]\n", pToken, pSave);
        pToken = strtok_r(NULL, pDel, &pSave);
    }
    
    return 1;
}

unsigned char * get_usb_bulk_send_buffer(unsigned int buf_len, unsigned int port)
{
    unsigned char * buff = NULL;
    STRU_BULK_HEADER * phead;

    buff = (unsigned char *)malloc(buf_len + sizeof(STRU_BULK_HEADER) + sizeof(STRU_USB_HEADER));
    if(NULL == buff)
    {
        printf("malloc buffer failed!\n");
        return NULL;
    }
    memset(buff, 0, buf_len + sizeof(STRU_BULK_HEADER) + sizeof(STRU_USB_HEADER));

    phead = (STRU_BULK_HEADER *)(buff + sizeof(STRU_USB_HEADER));
    phead->data_len     = buf_len;
    phead->header_len   = sizeof(STRU_BULK_HEADER);
    phead->port_index   = port;
    phead->status       = 0;
    phead->reserved[0]  = 0;
    phead->reserved[1]  = 0;
    phead->reserved[2]  = 0;

    return buff + sizeof(STRU_BULK_HEADER) + sizeof(STRU_USB_HEADER);
}


int usb_bulk_write(int fd, unsigned char * data, unsigned int buf_len, struct timespec * timeout)
{
    fd_set wfds;
    int ret;

    FD_ZERO(&wfds);
    FD_SET(fd, &wfds);

    ret = pselect(fd + 1, NULL, &wfds, NULL, timeout, NULL);

    if(ret > 0)
    {
        ret = write(fd, (unsigned char *)data, buf_len);        
    }
    else if(ret == 0)
    {
        printf("hid write timeout!\n");
    }
    else
    {
        printf("hid write pselect error!\n");
    }
    
    return ret;
}


int usb_bulk_send_data(void * data, unsigned int buf_len, struct timespec * timeout)
{
    int ret, index;
    //unsigned char usb_buf[MAX_SEND_PACKET_LEN];
    if(NULL == data)
    {
        printf("data is NULL\n");
        return -1;
    }

    STRU_BULK_HEADER  * phid = (STRU_BULK_HEADER *)((char *)data - sizeof(STRU_BULK_HEADER));
    STRU_USB_HEADER  * pusb = (STRU_USB_HEADER *)((char *)phid - sizeof(STRU_USB_HEADER));

    int offset = 0;
    int step = MAX_SEND_PACKET_LEN - sizeof(STRU_USB_HEADER);
    int fragment_num = ((phid->header_len + phid->data_len) % step) ? 
                        ((phid->header_len + phid->data_len) / step) + 1 : 
                        ((phid->header_len + phid->data_len) / step);

    if(buf_len == phid->data_len)
    {
        if(hid_device.hid_fd >= 0)
        {
            pthread_mutex_lock(&(hid_device.wrt_hid_mutex));
            for(offset = 0, index = 0; (offset + step) < (phid->header_len + phid->data_len); offset += step, pusb = (STRU_USB_HEADER  *)((unsigned char *)pusb + step), ++index)
            {
                memcpy(pusb->magic_num, magic_header, 8);
                pusb->header_len = 36;
                pusb->total_len = phid->header_len + phid->data_len;
                pusb->payload_len = step;
                pusb->fragment_idx = index;
                pusb->fragment_num = fragment_num;
                pusb->sub_proto = USB_BULK_PROTOCOL;
                pusb->reserved[0] = 0;
                pusb->reserved[1] = 0;
                pusb->reserved[2] = 0;
                pusb->checksum = get_checksum(((unsigned char *)pusb + sizeof(STRU_USB_HEADER)),
                                                                pusb->payload_len);

                ret = usb_bulk_write(hid_device.hid_fd, (unsigned char *)pusb, MAX_SEND_PACKET_LEN, timeout);
                //ret = write(hid_device.hid_fd, (unsigned char *)pusb, MAX_SEND_PACKET_LEN);
                if(ret < 0)
                {
                    printf("write hid failed!\n");
                    free(data - sizeof(STRU_BULK_HEADER) - sizeof(STRU_USB_HEADER));
                    pthread_mutex_unlock(&(hid_device.wrt_hid_mutex));
                    return -1;
                }
                //printf("i:%d offset:%d total:%d\n", pusb->fragment_idx, offset, pusb->total_len);
            }

            memcpy(pusb->magic_num, magic_header, 8);
            pusb->header_len = 36;
            pusb->total_len = phid->header_len + phid->data_len;
            pusb->payload_len = pusb->total_len - offset;
            pusb->fragment_idx = index;
            pusb->fragment_num = fragment_num;
            pusb->sub_proto = USB_BULK_PROTOCOL;
            pusb->reserved[0] = 0;
            pusb->reserved[1] = 0;
            pusb->reserved[2] = 0;
            pusb->checksum = get_checksum(((unsigned char *)pusb + sizeof(STRU_USB_HEADER)),
                                                            pusb->payload_len);

            ret = usb_bulk_write(hid_device.hid_fd, (unsigned char *)pusb, pusb->payload_len + pusb->header_len, timeout);
            //ret = write(hid_device.hid_fd, (unsigned char *)pusb, pusb->payload_len + pusb->header_len);
            if(ret < 0)
            {
                printf("write hid failed!\n");
                free(data - sizeof(STRU_BULK_HEADER) - sizeof(STRU_USB_HEADER));
                pthread_mutex_unlock(&(hid_device.wrt_hid_mutex));
                return -1;
            }
            
            //printf("i:%d offset:%d total:%d\n", pusb->fragment_idx, offset, pusb->total_len);
            pthread_mutex_unlock(&(hid_device.wrt_hid_mutex));

        }
        else
        {
            ret = -1;
        }

        free(data - sizeof(STRU_BULK_HEADER) - sizeof(STRU_USB_HEADER));
    }
    else
    {
        printf("memory buffer len no match(%d %d), can not free memory!\n", buf_len, phid->data_len);
        ret = -1;
    }

    return ret;
}

int usb_bulk_init()
{
     int index = 0;
	  
     for(index = 0; index < RECV_CALLBACK_NUM; index++)
     {
          if(index != g_hid_recv_callback[index].port_index ||
                NULL == g_hid_recv_callback[index].recv_callback)
          {
                continue;
          }

          if(NULL != g_hid_recv_callback[index].init_callback)
          {
              g_hid_recv_callback[index].init_callback();
          }
    }

    return 0;
}

int usb_bulk_data_analysis(unsigned char * buffer, unsigned length)
{
    int ret;
    STRU_USB_HEADER * pusb_header = (STRU_USB_HEADER *)buffer;

    if(0 == magic_num_check(pusb_header->magic_num))//header check
    {
        if(USB_BULK_PROTOCOL == pusb_header->sub_proto)//usb protocol check
        {
            if(pusb_header->payload_len <= MAX_RECV_PACKET_LEN)//mtu check
            {
                if(pusb_header->fragment_num > 1)//more fragment
                {
                    if(pusb_header->fragment_idx == 0)//first fragment
                    {
                        fragment_info.fragment_idx = 0;
                    }
                    else if(fragment_info.fragment_idx != pusb_header->fragment_idx)//check fragment index
                    {
                        printf("index no match!\n");
                    }

                    ret = usb_bulk_protocol_analysis(buffer + sizeof(STRU_USB_HEADER),
                                                length - sizeof(STRU_USB_HEADER),
                                                pusb_header->fragment_idx,
                                                pusb_header->fragment_num - 1 - pusb_header->fragment_idx);

                    ++fragment_info.fragment_idx;//next fragment index

                    if(pusb_header->fragment_idx == pusb_header->fragment_num - 1)
                    {
                        memset(&fragment_info, 0, sizeof(STRU_USB_FRAGMENT_INFO));
                    }
                }
                else//one fragment
                {
                    usb_bulk_protocol_analysis(buffer + sizeof(STRU_USB_HEADER),
                                          length - sizeof(STRU_USB_HEADER),
                                          0, 0);
                }
            }
            else
            {
                printf("size out of mtu %d(%d)!\n", MAX_RECV_PACKET_LEN, pusb_header->payload_len);
            }
        }
        else
        {
            printf("sub_proto no match hid(0x%x)! (0x%x)\n", USB_BULK_PROTOCOL, pusb_header->sub_proto);
        }
    }
    else
    {
        printf("magic num error!\n");
    }

    return ret;
}

int64_t get_file_size(const char *file_path)
{
    int64_t filesize = -1;
    struct stat statbuff;
    if(stat(file_path, &statbuff) < 0){
        return filesize;
    } else {
        filesize = statbuff.st_size;
    }
    return filesize;
}

// 测试从文件中读数据模拟通讯过程
int main_this(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("请带上测试包路径作为参数，例如： ./test_hid_service_2 /nfs_share/send_data\n");
        return 0;
    }
    
    printf("param: %s\n", argv[argc-1]);

    int                 i, read_len = 0;
    unsigned char       buffer[MAX_RECV_PACKET_LEN];
    STRU_USB_HEADER *   pusb_header;
    int                 ret = 0;
    int                 try = 0;
    char                versionInfo[128];

    int index = 0;
    while (1)
    {
        char file_name[128];
        memset(file_name, 0x00, sizeof(file_name));
        // sprintf(file_name, file_mode, index);
        sprintf(file_name, "%s/fragment_%05d.raw", argv[1], index);

        int64_t file_length = 0;
        file_length = get_file_size(file_name);
        if (file_length < 0)
        {
            printf("file is not ex\n");
            break;
        }
        
        FILE *fp1;
        if((fp1=fopen(file_name, "rb"))!=NULL)
        {
            printf("check_fragment_data(), read from file %s, len = %d\n", file_name, file_length);

            // char *buffer = new char[file_length];
            char *buffer = malloc(file_length);
            fread(buffer, sizeof(char), file_length, fp1);
            
            // printf("File: %c, len = %d\n", *buffer, file_length);

            pusb_header = (STRU_USB_HEADER *)buffer;

            if(0 == magic_num_check(pusb_header->magic_num))//header check
            {
                if(USB_BULK_PROTOCOL == pusb_header->sub_proto)//usb protocol check
                {
                    if(pusb_header->payload_len <= MAX_RECV_PACKET_LEN)//mtu check
                    {
                        if(pusb_header->fragment_num > 1)//more fragment
                        {
                            if(pusb_header->fragment_idx == 0)//first fragment
                            {
                                fragment_info.fragment_idx = 0;
                            }
                            else if(fragment_info.fragment_idx != pusb_header->fragment_idx)//check fragment index
                            {
                                printf("index no match!\n");
                            }

                            ret = usb_bulk_protocol_analysis(buffer + sizeof(STRU_USB_HEADER),
                                                        file_length - sizeof(STRU_USB_HEADER),
                                                        pusb_header->fragment_idx,
                                                        pusb_header->fragment_num - 1 - pusb_header->fragment_idx);

                            ++fragment_info.fragment_idx;//next fragment index

                            if(pusb_header->fragment_idx == pusb_header->fragment_num - 1)
                            {
                                memset(&fragment_info, 0, sizeof(STRU_USB_FRAGMENT_INFO));
                            }
                        }
                        else//one fragment
                        {
                            usb_bulk_protocol_analysis(buffer + sizeof(STRU_USB_HEADER),
                                                  file_length - sizeof(STRU_USB_HEADER),
                                                  0, 0);
                        }
                    }
                    else
                    {
                        printf("size out of mtu %d(%d)!\n", MAX_RECV_PACKET_LEN, pusb_header->payload_len);
                    }
                }
                else
                {
                    printf("sub_proto no match hid(0x%x)! (0x%x)\n", USB_BULK_PROTOCOL, pusb_header->sub_proto);
                }
            }
            else
            {
                printf("magic num error!\n");
            }


            // delete(buffer);
            free(buffer);
            fclose(fp1);
        }else{
            printf("read file fail !!!\n");
            break;
        }
        index ++;
    }
    
    printf("finish ...\n");
    return 0;
}

int main_back()
{
        //int                 hid_fd;
        int                 i, read_len = 0;
        unsigned char       buffer[MAX_RECV_PACKET_LEN];
        STRU_USB_HEADER *   pusb_header;
        int                 ret = 0;
        int                 try = 0;
        char                versionInfo[128];
        
        sprintf(versionInfo, "HID_SERVICE Version: %s, build time: %s %s", VERSION, __DATE__, __TIME__);
        printf("\n%s\n", versionInfo);

        memset(buffer, 0x5a, MAX_RECV_PACKET_LEN);
        memset(&fragment_info, 0, sizeof(STRU_USB_FRAGMENT_INFO));
        pthread_mutex_init(&hid_device.wrt_hid_mutex, NULL);

        while(1)
        {
            hid_device.hid_fd = open(HID_DEVICE_PATH, O_RDWR);//|O_NONBLOCK);
            if(hid_device.hid_fd < 0 && try < 5)
            {
                ++try;
                printf("open hid device %s failed!\n", HID_DEVICE_PATH);
                sleep(1);
            }
            else if(hid_device.hid_fd >= 0)
            {
                break;
            }
            else
            {
                return -1;
            }
        }

        //init register port
        for(i = 0; i < RECV_CALLBACK_NUM; ++i)
        {
            if(i != g_hid_recv_callback[i].port_index ||
                NULL == g_hid_recv_callback[i].recv_callback)
            {
                continue;
            }

            if(NULL != g_hid_recv_callback[i].init_callback)
            {
                g_hid_recv_callback[i].init_callback();
            }
        }

        while(1)
        {
            read_len = read(hid_device.hid_fd, buffer, MAX_RECV_PACKET_LEN);
            if(read_len <= 0)
            {
                printf("read error! ret:%d \n", read_len);
                break;
            }

            //printf("%x%x%x%x len:%d(%d)\n", buffer[0], buffer[1], buffer[2], buffer[3], read_len, MAX_RECV_PACKET_LEN);

            pusb_header = (STRU_USB_HEADER *)buffer;

            if(0 == magic_num_check(pusb_header->magic_num))//header check
            {
                if(USB_BULK_PROTOCOL == pusb_header->sub_proto)//usb protocol check
                {
                    if(pusb_header->payload_len <= MAX_RECV_PACKET_LEN)//mtu check
                    {
                        if(pusb_header->fragment_num > 1)//more fragment
                        {
                            if(pusb_header->fragment_idx == 0)//first fragment
                            {
                                fragment_info.fragment_idx = 0;
                            }
                            else if(fragment_info.fragment_idx != pusb_header->fragment_idx)//check fragment index
                            {
                                printf("index no match!\n");
                            }

                            ret = usb_bulk_protocol_analysis(buffer + sizeof(STRU_USB_HEADER),
                                                        read_len - sizeof(STRU_USB_HEADER),
                                                        pusb_header->fragment_idx,
                                                        pusb_header->fragment_num - 1 - pusb_header->fragment_idx);

                            ++fragment_info.fragment_idx;//next fragment index

                            if(pusb_header->fragment_idx == pusb_header->fragment_num - 1)
                            {
                                memset(&fragment_info, 0, sizeof(STRU_USB_FRAGMENT_INFO));
                            }
                        }
                        else//one fragment
                        {
                            usb_bulk_protocol_analysis(buffer + sizeof(STRU_USB_HEADER),
                                                  read_len - sizeof(STRU_USB_HEADER),
                                                  0, 0);
                        }
                    }
                    else
                    {
                        printf("size out of mtu %d(%d)!\n", MAX_RECV_PACKET_LEN, pusb_header->payload_len);
                    }
                }
                else
                {
                    printf("sub_proto no match hid(0x%x)! (0x%x)\n", USB_BULK_PROTOCOL, pusb_header->sub_proto);
                }
            }
            else
            {
                printf("magic num error!\n");
            }
        }
        return ret;
}

