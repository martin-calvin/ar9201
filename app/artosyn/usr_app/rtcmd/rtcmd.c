#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <getopt.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include "ion.h"
#include "ar_log.h"

static int total_len = 0;
static char cmd_buf[1024];

void rtcmd_thread_func(void)
{
    pthread_detach(pthread_self());
    
    //open the remote_cmd dev to send cmd
    int fd = open("/dev/remote_cmd", O_RDWR);
    if (fd < 0){
        log_err("open /dev/remote_cmd failed!\n");
        return;
    }
    
    int ret = write(fd,cmd_buf,total_len);
    if(ret != total_len) {
        log_err("send command failed\n");
    }
    
    close(fd);
}

int main(int argc, char **argv)
{
    //char *cmd_buf;
    int len;
    pthread_t thread;
     
    if(argc < 2) {
        log_err("please input the command.\n");
        return -1;
    }
    
    for(int i=1; i<argc; i++) {
        len = strlen(argv[i]);
        strcpy((char *)&cmd_buf[total_len],argv[i]);
        total_len+=len;
        cmd_buf[total_len]=' ';
        total_len++;
    }
    cmd_buf[total_len]='\0';
    total_len++;
    printf("%s \n",cmd_buf);

    int pid = fork(); 
    if(pid <0 ) {
        log_err("internel error\n");
    } else if (pid == 0) {
        rtcmd_thread_func();
    }
}

