#include "obc_tof_i2c.h"
// #include "ar_clk.h"

char* g_va_sys_reg_base;
int fd_sys_reg_base;

// gpio control sensor power and reset pin 
int ar_gpio_register_control()
{
    fd_sys_reg_base=open("/dev/mem", O_RDWR | O_SYNC);
	g_va_sys_reg_base = mmap(NULL,0x100000, PROT_READ | PROT_WRITE, MAP_SHARED,fd_sys_reg_base,0x40420000);//0x40420024

    // ar_write_dsp_reg(g_va_sys_reg_base + 0x24/*CORE_ACU_SLV_ACC*/, 0x80); //
    /* reset pin ctrl */
    *(g_va_sys_reg_base + 0x24) = 0x80; // dir-output

    *(g_va_sys_reg_base + 0x28) = 0x00; // low
    // ar_delay(100);//delay 100ms
    usleep(1000);
    *(g_va_sys_reg_base + 0x28) = 0x80; // high
    /* power pin ctrl */

    return 0;
}

int tof_i2c_init(i2c_dev_t *msg)
{
	msg->i2c_fd = -1;
    /* code */
    back_trace_t *back_trace=creat_back_trace();
    /* sensor power and reset ctrl, use this when sensor not probe */
    // ar_gpio_register_control();
    /* sensor clock cfg, use this when sensor not probe */
    // ar_clk_set_i2s_clock_for_sensor_double(mclk); 

    msg->i2c_fd = remote_i2c_open(DEV_REMOTE_I2C_PATH);
    if(0 == msg->i2c_fd)
    {
        printf("fail to open %s, exit...\n", DEV_REMOTE_I2C_PATH);
        return -1;
    }
    printf("success to open %s : 0x%x\n",DEV_REMOTE_I2C_PATH,msg->i2c_fd);

    /* config i2c */
    if(remote_i2c_config(msg->i2c_fd, msg->bus, REMOTE_I2C_MASTER_MODE, msg->saddr, msg->speed))
    {
        printf("fail to config, exit...\n");
        return -1;
    }
    printf("i2c config success: i2c_bus=%d slave_addr=0x%x i2c_speed=%d\n", 
            msg->bus,  msg->saddr, msg->speed);

    return msg->i2c_fd;
}


/* 
i2c driver write
*/
int tof_i2c_write(i2c_dev_t *msg)
{
	uint8_t buf[4];
	int index = 0;
	int retval = 0;

	if(msg->i2c_fd < 0){
		retval = -1;
		printf("err:i2c_wirte have no fd\n");
		goto end1;
	}

	if (msg->reg_width == 2) {
		buf[index] = (msg->reg >> 8) & 0xff;
		index++;
		buf[index] = msg->reg & 0xff;
		index++;
	} else {
		buf[index] = msg->reg & 0xff;
		index++;
	}

	if (msg->data_width == 2) {
		buf[index] = (msg->data >> 8) & 0xff;
		index++;
		buf[index] = msg->data & 0xff;
		index++;
	} else {
		buf[index] = msg->data & 0xff;
		index++;
	}

    retval = remote_i2c_write(msg->i2c_fd, buf, (msg->reg_width + msg->data_width));
	if(retval < 0) {
		printf("i2c write error!\n");
		retval = -1;
		goto end1;
	}

	// printf("[RemoteI2C_write]0x%x: 0x%x\n", msg->reg, msg->data);
	retval = 0;

end1:
	// remote_i2c_close(fd);
end0:
	return retval;
}


/* 
i2c driver read
*/
int tof_i2c_read(i2c_dev_t *msg)
{
	uint8_t buf[4];
	int index = 0;
	int retval = 0;

	if(msg->i2c_fd < 0){
		retval = -1;
		printf("err:i2c_read have no fd\n");
		goto end1;
	}

/* i2c read data */
	if (msg->reg_width == 2) {
		buf[0] = (msg->reg >> 8) & 0xff;
		buf[1] = msg->reg & 0xff;
	} else
		buf[0] = msg->reg & 0xff;

	retval = remote_i2c_write_read_ext(msg->i2c_fd, buf, msg->reg_width, buf,  msg->data_width);
	if (retval < 0) {
		printf("CMD_I2C_READ error!\n");
		retval = -1;
		goto end1;
	}

	if (msg->data_width == 2) {
		*msg->rd_data = buf[1] | (buf[0] << 8);
	} else
		*msg->rd_data = buf[0];

	//printf("[RemoteI2C_read]0x%x: 0x%x\n", msg->reg, *msg->rd_data);
	retval = 0;

end1:
    // remote_i2c_close(fd);
end0:
	return retval;
}