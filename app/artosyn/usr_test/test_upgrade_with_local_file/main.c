#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <malloc.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "ar_flash.h"


static int show_upgrade(int state, int percent)
{
    printf("Upgrade status: %d, percent:%d\n", state, percent);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("请输入升级文件名(**.img)\n");
        exit(0);
    }
    

	printf("Artosyn Upgrade, Version: %s %s\n", __DATE__, __TIME__);

    int ret;
    char * upgrade_img_file = argv[1];
    long len = 0;

    FILE * pFile;

    pFile = fopen (upgrade_img_file, "rb");
    if (pFile==NULL){
        perror ("Error opening file");
        exit(0);
    }else {
        fseek (pFile, 0, SEEK_END);   ///将文件指针移动文件结尾
        len = ftell (pFile); ///求出当前文件指针距离文件开始的字节数
        fseek(pFile, 0, SEEK_SET);
        // fclose (pFile);
    }

    printf("upgrade_img file = %s, file size = %ld\n", upgrade_img_file, len);

    char * upgrade_img = (char *)malloc(len);
    if(!upgrade_img)
    {
        printf("malloc failed error %d, %d\n", __LINE__ , errno);
        return -1;
    }

    ret = fread(upgrade_img, 1, len, pFile);
    if(ret <= 0)
    {
        printf("error %d, %d, %d\n", __LINE__, ret, errno);
        free(upgrade_img);
        return -1;
    }
    printf("file len: %d\n", ret);
    fclose (pFile);

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