#include <stdio.h>
#include <stdlib.h>

#ifndef     __SYS_UPGRADE_H__
#define     __SYS_UPGRADE_H__

#define upgrade_start_mark      "upgd"
#define upgrade_prpa_mark       "prpaupgd"

#pragma pack(push)
#pragma pack(1)

typedef struct
{

    unsigned int    total_len;
    unsigned char * pimage;
    int             offset;
}image_info;

#pragma pack(pop)

int sys_upgrade_init();
int sys_upgrade_recv(void * data, unsigned int len);

#endif

