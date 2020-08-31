#ifndef __OBC_TOF_I2C_H__
#define __OBC_TOF_I2C_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "ar_log.h"
#include <sys/mman.h>
// #include <ar_osal.h>
#include <unistd.h>
#include "backtrace.h"
#include "libremote_i2c.h"

typedef struct
{
    int i2c_fd;         /* i2c_fd */
    uint8_t saddr;      /* 7bit-slave addr */
    uint8_t speed;      /* i2c speed */
    uint8_t bus;        /* i2c bus */
    uint8_t reg_width;  /* i2c register width */
    uint8_t data_width; /* i2c data width */
    uint32_t reg;       /* i2c register addr */
    uint32_t data;      /* i2c write data */
    uint32_t *rd_data;  /* i2c read data */
}i2c_dev_t;
///////////////////////////////////////////////

#define DEV_REMOTE_I2C_PATH ("/dev/remote_i2c")


///////////////////////////////////////////////

int ar_gpio_register_control();
int tof_i2c_init(i2c_dev_t *msg);
int tof_i2c_write(i2c_dev_t *msg);
int tof_i2c_read(i2c_dev_t *msg);

#endif
