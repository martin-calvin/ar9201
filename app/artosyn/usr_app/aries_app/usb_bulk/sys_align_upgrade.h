#include <stdio.h>
#include <stdlib.h>

#ifndef __SYS_ALIGN_H__
#define __SYS_ALIGN_H__

#define align_start_mark "file"
#define align_get_start_mark "fget"

#define ROOT_PATH "/tmp"
#define MAX_FILE_LEN 256

static char * ALIGN_34_FILE_PATH = "/factory/align_34.bin";
static char * ALIGN_169_FILE_PATH = "/factory/align_169.bin";

typedef enum
{
    ALIGN_STAT_DONE             = 1,
    ALIGN_STAT_PREPAR           = 0,
    ALIGN_ERR_DDR               = -1,
    ALIGN_ERR_NOT_ENOUGH_SPACE  = -2,
    ALIGN_ERR_PATH_NOT_WRITABLE = -3,
    ALIGN_ERR_MD5_ERROR         = -4
} AlignStatus;

#pragma pack(push)
#pragma pack(1)

typedef struct
{
    unsigned int    total_len;
    unsigned char   file_path[128];
    unsigned char   md5sum[16]; 
    unsigned char * pimage;
    int             offset;
}align_file_info;

#pragma pack(pop)

#ifdef __cplusplus
extern "C"
{
#endif

void get_align_upgrade_status(int16_t *status, int16_t *percentage, unsigned char *message);
int sys_align_upgrade_init();
int sys_align_upgrade_recv(void *data, unsigned int len);

#ifdef __cplusplus
}
#endif

#endif


