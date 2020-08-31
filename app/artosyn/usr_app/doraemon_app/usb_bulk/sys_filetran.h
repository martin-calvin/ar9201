#include <stdio.h>
#include <stdlib.h>

#ifndef __SYS_FILETRAN_H__
#define __SYS_FILETRAN_H__

#define filetran_start_mark "file"
#define fileget_start_mark "fget"
//#define filelist_start_mark         "list"

#define ROOT_PATH "/tmp"
#define MAX_FILE_LEN 256

typedef enum
{
    FILE_TRAN_STAT_DONE             = 1,
    FILE_TRAN_STAT_PREPAR           = 0,
    FILE_TRAN_ERR_DDR               = -1,
    FILE_TRAN_ERR_NOT_ENOUGH_SPACE  = -2,
    FILE_TRAN_ERR_PATH_NOT_WRITABLE = -3,
    FILE_TRAN_ERR_MD5_ERROR         = -4
} FileTranStatus;

#pragma pack(push)
#pragma pack(1)

typedef struct
{
    unsigned int total_len;
    unsigned char file_path[128];
    unsigned char md5_sum[16];
    FILE *pfile;
    int offset;
} file_info;

#pragma pack(pop)

#ifdef __cplusplus
extern "C"
{
#endif

    void get_filetran_status(int16_t *status, int16_t *percentage, unsigned char *message);
    int sys_filetran_init();
    int sys_filetran_recv(void *data, unsigned int len);

#ifdef __cplusplus
}
#endif

// int sys_fileget_init();
// int sys_fileget_recv(void * data, unsigned int len);

//int sys_filelist_init();
//int sys_filelist_recv(void * data, unsigned int len);

#endif
