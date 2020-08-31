#include <stdio.h>
#include <stdlib.h>



#ifndef __HID_SERVICE_H__
#define __HID_SERVICE_H__

#define     MAX_SEND_PACKET_LEN     512
#define     MAX_RECV_PACKET_LEN     (MAX_SEND_PACKET_LEN * 2)

#define     RECV_CALLBACK_NUM       256

#define     HID_DEVICE_PATH        "/dev/hidg0"
/******************************USB PROTOCOL DEFINE*****************************/
#define     HID_PROTOCOL            1


/******************************INDEX DEFINE*****************************/
#define     INDEX_SYS_UPGRADE       0
#define     INDEX_SYS_FILETRAN      1
#define     INDEX_SYS_FILEGET       2
#define     INDEX_SYS_USBCMD        3
#define     VERSION   "V1.3.2"


#pragma pack(push)
#pragma pack(1)

typedef struct
{
    unsigned char   magic_num[8];
    unsigned int    header_len;
    unsigned int    total_len;
    unsigned int    payload_len;
    unsigned int    fragment_num;
    unsigned int    fragment_idx;
    unsigned char   sub_proto;
    unsigned char   reserved[3];
    unsigned int    checksum;
}STRU_USB_HEADER;


typedef struct
{
    unsigned short  port_index;
    unsigned short  header_len;
    unsigned int    data_len;
    unsigned char   status;
    unsigned char   reserved[3];
}STRU_HID_HEADER;

#pragma pack(pop)

typedef int(*HID_INIT_CALLBACK_HANDLER)();//void *, unsigned int
typedef int(*HID_RECV_CALLBACK_HANDLER)(void *, unsigned int);

typedef struct
{
    unsigned short port_index;
    HID_INIT_CALLBACK_HANDLER    init_callback;//optional
    HID_RECV_CALLBACK_HANDLER    recv_callback;
}STRU_HID_RECV_CALLBACK_HANDLER;

unsigned char * get_hid_send_buffer(unsigned int buf_len, unsigned int port);
int hid_send_data(void * data, unsigned int buf_len, struct timespec * timeout);


#endif

