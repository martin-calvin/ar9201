#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef     __SYS_UPGRADE_H__
#define     __SYS_UPGRADE_H__

#pragma pack(push)
#pragma pack(1)

// typedef unsigned short uint16_t;

typedef struct
{

    unsigned int    total_len;
    unsigned char * pimage;
    int             offset;
}image_info;

#pragma pack(pop)

// typedef enum{
//         STAT_DONE = 3,
//         STAT_IN_PROGRESS = 2,
//         STAT_START = 1,
//         STAT_VERIFY_IMAGE    = 0,
//         ERR_VERIFY     = -1,
//         ERR_PROGRAM    = -2,
//         ERR_ERASE      = -3,
//         ERR_FLASH_TYPE = -4,
//         ERR_IMG_SIZE   = -5,
//         ERR_OTHER      = -6,
//         ERR_DDR        = -7,
// } UpgradeStatus;

#ifdef __cplusplus
extern "C"
{
#endif


void get_firmware_upgrade_status(int16_t *status, int16_t *percentage, unsigned char *message);
int sys_upgrade_init();
int sys_upgrade_recv(void * data, unsigned int len);

#ifdef __cplusplus
}
#endif

#endif

