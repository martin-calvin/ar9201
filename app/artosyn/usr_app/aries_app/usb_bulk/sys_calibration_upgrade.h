#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef     __SYS_CALIB_UPGRADE_H__
#define     __SYS_CALIB_UPGRADE_H__

typedef enum{
        CALIB_STAT_DONE               = 3,
        CALIB_STAT_START              = 2,
        CALIB_STAT_IN_PROGRESS        = 1,
        CALIB_STAT_PREPAR             = 0,
        CALIB_ERR_DDR                 = -1,
        CALIB_ERR_NOT_ENOUGH_SPACE    = -2,
        CALIB_ERR_PATH_NOT_WRITABLE   = -3,
        CALIB_ERR_MD5_ERROR           = -4
} Calibration_UpgradeStatus;

#ifdef __cplusplus
extern "C"
{
#endif

void get_calibration_upgrade_status(int16_t *status, int16_t *percentage, unsigned char *message);
int sys_calibration_upgrade_init();
int sys_calibration_upgrade_recv(void * data, unsigned int len);

#ifdef __cplusplus
}
#endif

#endif

