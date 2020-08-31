#include <stdio.h>
#include <stdlib.h>

#ifndef __HID_SERVICE_H__
#define __HID_SERVICE_H__

#define     MAX_SEND_PACKET_LEN     512
#define     MAX_RECV_PACKET_LEN     (MAX_SEND_PACKET_LEN * 2)

#define     RECV_CALLBACK_NUM       256

#define     HID_DEVICE_PATH        "/dev/hidg0"
/******************************USB PROTOCOL DEFINE*****************************/
// #define     HID_PROTOCOL            1
#define     USB_BULK_PROTOCOL          0


/******************************INDEX DEFINE*****************************/
#define     INDEX_SYS_UPGRADE       0
#define     INDEX_SYS_FILETRAN      1
#define     INDEX_SYS_FILEGET       2
#define     INDEX_SYS_USBCMD        3
#define     VERSION   "V1.3.2"


#pragma pack(push)
#pragma pack(1)

typedef enum {
    USB_FILE_TRANSFER_UPGRADE_START = 1,       // USB文件传输开始
    USB_FILE_TRANSFER_UPGRADE_STOP,                   // 传输终止
    USB_FILE_TRANSFER_UPGRADE_FINISH,                 // 传输完成
} UsbFileTransferCmd;

typedef struct
{
    unsigned char        usb_file_magic_header[8];
    UsbFileTransferCmd   cmd;
    unsigned int         file_size;
    unsigned char        md5sum[16];
    unsigned char        target_path[128];
    unsigned char        reserved[3];
}UsbFileTransferBag;

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
}STRU_BULK_HEADER;

#pragma pack(pop)

typedef int(*USB_BULK_INIT_CALLBACK_HANDLER)();//void *, unsigned int
typedef int(*USB_BULK_RECV_CALLBACK_HANDLER)(void *, unsigned int);

typedef struct
{
    unsigned short port_index;
    USB_BULK_INIT_CALLBACK_HANDLER    init_callback;//optional
    USB_BULK_RECV_CALLBACK_HANDLER    recv_callback;
}STRU_USB_BULK_RECV_CALLBACK_HANDLER;

// unsigned char * get_usb_bulk_send_buffer(unsigned int buf_len, unsigned int port);
// int usb_bulk_send_data(void * data, unsigned int buf_len, struct timespec * timeout);

#ifdef __cplusplus
extern "C"
{
#endif

int usb_bulk_init();
int usb_bulk_data_analysis(unsigned char * buffer, unsigned length);

#ifdef __cplusplus
}
#endif

#endif

