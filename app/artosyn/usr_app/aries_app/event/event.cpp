/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : event.cpp
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/7/10
*  Last Modified :
*  Description   : event.cpp
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/7/10
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/

/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include <sys/statfs.h>
#include <linux/input.h>
#include <sys/prctl.h>

#include "utils.h"
#include "logutil.h"


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/

struct _uevent
{
	char *strs[30];
	int size;
};



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/
    
/*
 ACTION=add
 DEVPATH=/devices/30180000.usb/gadget/video4linux/video6
 SUBSYSTEM=video4linux
 MAJOR=81
 MINOR=7
 DEVNAME=video6
 SEQNUM=586

 ACTION=change
 DEVPATH=/devices/virtual/android_usb/android0
 SUBSYSTEM=android_usb
 USB_STATE=CONNECTED
 SEQNUM=587

 */
static void event_parse_message(const struct _uevent *event)
{
    char *sysfs = NULL;
    if (event->size <= 0){
        ERR("event size error\n");
        return;
    }

    sysfs = event->strs[2] + 10;  //解析: SUBSYSTEM=xxxx

    DBG("sysfs:%s\n", sysfs);

#if 0
    if (!strcmp(sysfs, "video4linux")) //uvc
    {
        video_event(event);
    }
    else if (!strcmp(sysfs, "android_usb")) /* USB 插拔事件 */
    {
        INFO("usb connected event!\n");
    }
    else if (!strcmp(sysfs, "block")) //SD卡 情况: SUBSYSTEM=block
    {
        INFO("SD card connected event!\n");
    }
#endif
}


/*****************************************************************************
*   Prototype    : event_check_hotplug_thd
*   Description  : event montior thread
*   Input        : void *arg  
*   Output       : None
*   Return Value : static void *
*****************************************************************************/
static void *event_check_hotplug_thd(void *arg)
{
	int sockfd;
    int i, j;
    int len;
    char buf[512];
    struct iovec iov;
    struct msghdr msg;
    struct sockaddr_nl sa;
    struct _uevent event;
	char acThreadName[32] = {0};
	pid_t ThreadID = syscall(SYS_gettid);
	snprintf(acThreadName, 32 - 1, "HotPlug:%u", ThreadID);
	prctl(PR_SET_NAME, acThreadName);

	INFO("Enter Hot plug event Monitor thread, ID: %u\n", ThreadID);

	memset(&sa, 0, sizeof(sa));
    sa.nl_family = AF_NETLINK;
    sa.nl_groups = NETLINK_KOBJECT_UEVENT;
    sa.nl_pid = 0; //getpid():  both is ok: 孔平抄了RK的，还不太懂

    memset(&msg, 0, sizeof(msg));
    iov.iov_base = (void *)buf;
    iov.iov_len = sizeof(buf);
    msg.msg_name = (void *)&sa;
    msg.msg_namelen = sizeof(sa);
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    sockfd = socket(AF_NETLINK, SOCK_RAW, NETLINK_KOBJECT_UEVENT);
    if (sockfd == -1)
    {
        ERR("Socket creating failed, Error no: %d(%s)\n", errno, strerror(errno));
        return NULL;
    }

    if (bind(sockfd, (struct sockaddr *)&sa, sizeof(sa)) == -1)
    {
        ERR("Bind Socket %d failed, Error no: %d(%s)\n", sockfd, errno, strerror(errno));
        close(sockfd);
        return NULL;
    }

	while (true)
	{
        event.size = 0;
		len = recvmsg(sockfd, &msg, 0); //never timeout
		if (len < 0)
		{
			ERR("recvmsg fail\n");
			continue;
		}
		else if (len < 32 || len > sizeof(buf))
		{
			ERR("invalid message");
			continue;
		}
		else
		{
            for (i = 0, j = 0; i < len; i++) //buf[]:"xxxxxx\0yyyyyy\0......zzzzz\0"以\0为分隔符一一解析出来
            {
                if (*(buf + i) == '\0' && (i + 1) != len) //以\0为分隔符一一解析出来
                {
                    event.strs[j] = buf + i + 1;
                    j++;
                    event.size = j;
                }
            }
    	}

#if 1
        printf("\n==========uevent========\n");
        for (int i = 0; i < event.size; i++)
        {
            printf("%s\n", event.strs[i]);
        }
        printf("========================\n\n");
#endif
        printf("event:%s size:%d\n\n", buf, event.size);

        event_parse_message(&event);
   }
}


/*****************************************************************************
*   Prototype    : event_module_init
*   Description  : event module init
*   Input        : void  
*   Output       : None
*   Return Value : void
*****************************************************************************/
void event_module_init(void)
{
    start_new_thread("HotPlug_thd", NULL, event_check_hotplug_thd, NULL);
}

