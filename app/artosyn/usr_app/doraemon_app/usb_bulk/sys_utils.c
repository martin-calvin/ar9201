#include "sys_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "md5.h"


unsigned int write_to_file(char * data, unsigned char * path, unsigned int len)
{
    FILE *fp1;
    if((fp1=fopen(path, "w"))!=NULL)
    {
        fwrite(data, sizeof(char), len, fp1);

        printf("write to file, len = %d\n", len);
        fclose(fp1);
        return 0;
    }
    return -1;
}

int magic_num_check(unsigned char * data)
{
    unsigned char usb_file_magic_header[8] = {0xff, 0x08, 0xff, 0xaa, 0xcc, 0x52, 0x54, 0x3c};
    unsigned int i;
    for(i = 0; i < sizeof(usb_file_magic_header); ++i)
    {
        if(data[i] != usb_file_magic_header[i])
            return -1;
    }
    return 0;
}

int compare_chars(unsigned char * data1, unsigned char * data2, int len)
{
    unsigned int i;
    for(i = 0; i < len; ++i)
    {
        if(data1[i] != data2[i])
            return -1;
    }
    return 0;
}

int md5_sum(unsigned char *encrypt, int len, unsigned char *decrypt)
{
    MD5_CTX md5;
    MD5Init(&md5);
    MD5Update(&md5, encrypt, len);
    MD5Final(decrypt, &md5);

    for(int i=0;i<16;i++)
        printf("%2x",decrypt[i]);
    printf("\n");
}