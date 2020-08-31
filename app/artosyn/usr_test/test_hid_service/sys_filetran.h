#include <stdio.h>
#include <stdlib.h>

#ifndef     __SYS_FILETRAN_H__
#define     __SYS_FILETRAN_H__

#define filetran_start_mark         "file"
#define fileget_start_mark          "fget"
//#define filelist_start_mark         "list"

#define ROOT_PATH                   "/tmp"
#define MAX_FILE_LEN                256

#pragma pack(push)
#pragma pack(1)

typedef struct
{

    unsigned int    total_len;
    FILE *          pfile;
    int             offset;
}file_info;

#pragma pack(pop)

int sys_filetran_init();
int sys_filetran_recv(void * data, unsigned int len);

int sys_fileget_init();
int sys_fileget_recv(void * data, unsigned int len);

//int sys_filelist_init();
//int sys_filelist_recv(void * data, unsigned int len);

#endif

