#include <stdio.h>
#include <stdlib.h>

#ifndef     __SYS_USBCMD_H__
#define     __SYS_USBCMD_H__

#define usbcmd_start_mark         "ucmd"

#define MAX_CMD_LEN                256

int sys_usbcmd_init();
int sys_usbcmd_recv(void * data, unsigned int len);

#endif
