#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "ar_log.h"


#include "backtrace.h"

#include "libremote_i2c.h"
#include "test_remote_i2c.h"

///////////////////////////////////////////////

int main(int argc, char const *argv[])
{
    /* code */
    back_trace_t *back_trace=creat_back_trace();

    unsigned int i2c_id_7bit = 0x1A;
    unsigned int fd = remote_i2c_open(DEV_REMOTE_I2C_PATH);
    if(0 == fd)
    {
        printf("fail to open %s, exit...\n", DEV_REMOTE_I2C_PATH);
        return -1;
    }

    printf("success to open %s : 0x%x\n",DEV_REMOTE_I2C_PATH,fd);

    ///////////////////////////////////////////////

    if(remote_i2c_config(fd, REMOTE_I2C_COMPONENT_1, REMOTE_I2C_MASTER_MODE, i2c_id_7bit, REMOTE_I2C_STANDARD_SPEED))
    {
        printf("fail to config, exit...\n");
        return -1;
    }

    ///////////////////////////////////////////////

    unsigned int test_addr = 0x3002;
    unsigned int test_data = 0x01;

    unsigned char data_write[3];
    unsigned char data_read[3];

    data_write[0]=(test_addr>>8) & 0xFF;
    data_write[1]=(test_addr) & 0xFF;
    data_write[2]=(test_data) & 0xFF;

    if(remote_i2c_write(fd, data_write, 3) )
    {
        printf("fail to write, exit...\n");
        return -1;
    }

    printf("write 0x%x to 0x%x finished\n", test_addr,test_data);

    data_write[0]=(test_addr>>8) & 0xFF;
    data_write[1]=(test_addr) & 0xFF;
    if(remote_i2c_write_read_ext(fd, data_write, 2 , data_read, 1) )
    {
        printf("fail to write_read_ext, exit...\n");
        return -1;
    }

    printf("write_read_ext 0x%x to 0x%x finished\n", test_addr,data_read[0]);

    test_addr = 0x3010;
    data_write[0]=(test_addr>>8) & 0xFF;
    data_write[1]=(test_addr) & 0xFF;
    if(remote_i2c_write_read_ext(fd, data_write, 2 , data_read, 1) )
    {
        printf("fail to write_read_ext, exit...\n");
        return -1;
    }

    printf("write_read_ext 0x%x to 0x%x finished\n", test_addr,data_read[0]);

    if(remote_i2c_read(fd,data_read,3))
    {
        printf("fail to read, exit...");
        return -1;
    }

    printf("read 0x%x 0x%x 0x%x finished\n",data_read[0],data_read[1],data_read[2]);


    ///////////////////////////////////////////////

    if(remote_i2c_close(fd))
    {
        printf("fail to close 0x%x, exit...\n",fd);
        return -1;
    }

    printf("test over, exit...\n");
    return 0;
}