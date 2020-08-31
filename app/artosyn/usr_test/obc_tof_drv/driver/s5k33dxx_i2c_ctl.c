#include "s5k33dxx_i2c_ctl.h"
#include "s5k33dxx_setting.h"
#include <math.h>


#define IMX291_ADDR             (0X1A)
#define OV02K10_ADDR            (0x36)
#define S5K33D_ADDR             (0x20 >> 1) //  7bit address
#define I2C_SLAVE_ADDRESS_8BIT  (S5K33D_ADDR)

static int first = 1;
uint8_t start_streaming_called = 0;
static int duty_cycle = 15;

static laser_list_t laser_setting_cfg = {.laser_type = DRIVER_IC_NONE,};
static sensor_list_t sensor_setting_cfg = {.sensor_type = SENSOR_LIST_NONE,};

static uint32_t exp_max = 800;
static uint32_t exp_min = 20;


// ld power set default
#define LD_POW_A_DEFAULT				(0xff)
#define LD_POW_B_DEFAULT				(0x00)
static int laser_power_val_A = LD_POW_A_DEFAULT;
static int laser_power_val_B = LD_POW_B_DEFAULT;


static i2c_dev_t obc_i2c_device = 
{
    -1,                         /* i2c_fd */
    I2C_SLAVE_ADDRESS_8BIT,     /* 7bit-slave addr */
    REMOTE_I2C_STANDARD_SPEED,  /* i2c speed */
    REMOTE_I2C_COMPONENT_1,     /* i2c bus */
    2,                          /* i2c register widt */
    2,                          /* i2c data width */
};

/* 
 open remote i2c 
 return -1 : open failed
 return 0 : open success
 return 1 ：re-opened
*/
int s5k33d_i2c_open(void)
{
    /* only config i2c once */
    if (!first) {
		return 1; // re-open
	}
	first = 0;
    /* init i2c_dev config params */
    tof_i2c_init(&obc_i2c_device);
    if (obc_i2c_device.i2c_fd < 0) {
        printf("Open %s error!\n",obc_i2c_device.bus);
        return -1;
    }
    return 0;
}

/* 
    close remote i2c 
    return < 0 is err
*/
int s5k33d_i2c_close(void)
{
    int ret = 0;

    if(obc_i2c_device.i2c_fd < 0)
        return -1;

    ret = remote_i2c_close(obc_i2c_device.i2c_fd);
    if(ret < 0)
        printf("Close %s error!\n",obc_i2c_device.i2c_fd);
    first = 1;
    return ret;
}


/* 
    get remote i2c status
    return <0 :closed
*/
int get_s5k33d_i2c_status(void)
{
    if(obc_i2c_device.i2c_fd < 0){
        return -1;
    }   

    return 0;
}

/*
    i2c write 16bit reg_addr, 16bit data
    return < 0 is err
*/
int s5k33d_i2c_write16(uint32_t reg_addr, uint32_t data)
{
    int ret = 0;

    obc_i2c_device.reg_width = 2;
    obc_i2c_device.data_width = 2;
    obc_i2c_device.reg = reg_addr;
    obc_i2c_device.data = data;
    // write to remote i2c
    ret = tof_i2c_write(&obc_i2c_device); 

    return ret;       
}

/*
    i2c read 16bit reg_addr, 16bit data
    return < 0 is err
*/
int s5k33d_i2c_read16(uint32_t reg_addr, uint32_t *data)
{
    int ret = 0;

    obc_i2c_device.reg_width = 2;
    obc_i2c_device.data_width = 2;
    obc_i2c_device.reg = reg_addr;
    obc_i2c_device.rd_data = data;
    // write to remote i2c
    ret = tof_i2c_read(&obc_i2c_device); 

    return ret;       
}

/*
    i2c write 16bit reg_addr, 8bit data
    return < 0 is err
*/
int s5k33d_i2c_write8(uint32_t reg_addr, uint32_t data)
{
    int ret = 0;

    obc_i2c_device.reg_width = 2;
    obc_i2c_device.data_width = 1;
    obc_i2c_device.reg = reg_addr;
    obc_i2c_device.data = data;
    // write to remote i2c
    ret = tof_i2c_write(&obc_i2c_device); 

    return ret;       
}

/*
    i2c read 16bit reg_addr, 8bit data
    return < 0 is err
*/
int s5k33d_i2c_read8(uint32_t reg_addr, uint8_t *data)
{
    int ret = 0;
	uint32_t buf;

    obc_i2c_device.reg_width = 2;
    obc_i2c_device.data_width = 1;
    obc_i2c_device.reg = reg_addr;
    obc_i2c_device.rd_data = &buf;
    // write to remote i2c
    ret = tof_i2c_read(&obc_i2c_device); 

	*data = buf;
    return ret;       
}

/* laser driver reg write */
int cxa4016_reg_write(uint16_t reg, uint8_t data)
{
    int ret;

    ret = s5k33d_i2c_write16(0x6028, 0x2000);
    if (ret < 0)
        return ret;
    ret = s5k33d_i2c_write16(0x602A, reg);
    if (ret < 0)
        return ret;
    ret = s5k33d_i2c_write8(0x6F12, data);

    return ret;
}

/* only for test */
int cxa4016_reg_write2(uint16_t reg, uint8_t data)
{
    int ret;
	/* fix to 33d-wt address */
	uint16_t reg_num = 1; // always write 1 register
	uint16_t drv_reg_addr = reg;
	uint16_t tof_wt_reg =  (reg_num << 8)|(drv_reg_addr & 0xff);
	uint16_t tof_wt_val =  data;
	printf("tof_wt_reg: 0x%x, tof_wt_val: 0x%x\n", tof_wt_reg, tof_wt_val);
	
	// ret |= s5k33d_i2c_write16(0x6028, 0x2000);

	ret |= s5k33d_i2c_write16(0x602a, 0x1f90); //address switch
	ret |= s5k33d_i2c_write16(0x6f12, 0x0225); //total 1, addr reg
	ret |= s5k33d_i2c_write16(0x6f12, (reg&0xff << 8)); //total 1, addr reg
	// ret |= s5k33d_i2c_write16(0x6f12, tof_wt_reg); //total 1, addr reg
	

	ret |= s5k33d_i2c_write16(0x602a, 0x1fc0); //address switch
	ret |= s5k33d_i2c_write16(0x6f12, 0x0001); //address switch
	ret |= s5k33d_i2c_write16(0x6f12, (tof_wt_val << 8)); //write

    return ret;
}


/* laser driver reg read */
int cxa4016_reg_read(uint16_t reg, uint8_t *data)
{
    int ret;

    ret = s5k33d_i2c_write16(0x602C, 0x2000);
    if (ret < 0)
        return ret;
    ret = s5k33d_i2c_write16(0x602E, reg);
    if (ret < 0)
        return ret;
    ret = s5k33d_i2c_read8(0x6F12, data);

    return ret;
}

double fixed2float(uint32_t fp, uint32_t wl, uint32_t frac, bool is_signed)
{
    uint64_t m_fp = fp;
    double val;

    int s = (m_fp&((uint64_t)1 << (wl - 1))) >> (wl - 1);

    if (s == 1)//signed
    {
        uint64_t v1 = (~(m_fp - 1)&~(((uint64_t)0xFFFFFFFFFFFFFFFF) << (wl - 1)));
        val = -((double)v1) / (double)powf((double)2.0f, (double)(frac));
    }
    else//unsigned
    {
        val = ((double)m_fp) / (double)powf((double)2.0f, (double)(frac));
    }

    return val;
}

/* support of laser setting list */
static laser_list_t tof_laser_setting_list[] = 
{
	{DRIVER_IC_CXA4016, 		cxa4016_reglist, 		sizeof(cxa4016_reglist)},
	{DRIVER_IC_PHX3D_3021_AA, 	phx3d_3021_aa_reglist, 	sizeof(phx3d_3021_aa_reglist)},
	{DRIVER_IC_PHX3D_3021_CB, 	phx3d_3021_cb_reglist, 	sizeof(phx3d_3021_cb_reglist)},	
};

/* support of sensor setting list */
static sensor_list_t tof_sensor_setting_list[] = 
{
	{SENSOR_LIST_BURST_MASTER, 	s5k33d_reglist_Burst, 		sizeof(s5k33d_reglist_Burst)},
	{SENSOR_LIST_RV1108, 		s5k33d_reglist_from1108, 	sizeof(s5k33d_reglist_from1108)},
	{SENSOR_LIST_MODE3, 		s5k33d_reglist_mode3, 		sizeof(s5k33d_reglist_mode3)},
	{SENSOR_LIST_MEIZU, 		meizu_reglist, 				sizeof(meizu_reglist)},
	{SENSOR_LIST_BURST_SLAVE, 	s5k33d_reglist_Burst_Slave, sizeof(s5k33d_reglist_Burst_Slave)},
	{SENSOR_LIST_SLAVE_1TRG1, 	SlaveMode_1_trigg_1, 		sizeof(SlaveMode_1_trigg_1)},
	{SENSOR_LIST_SLAVE_1TRG2, 	SlaveMode_1_trigg_2, 		sizeof(SlaveMode_1_trigg_2)},
	{SENSOR_LIST_SLAVE_1TRG4, 	SlaveMode_1_trigg_4, 		sizeof(SlaveMode_1_trigg_4)},	
};

//select sensor and laser_driver settings
int sensor_list_setup(uint32_t laser_type, uint32_t sensor_type)
{
	memset(&laser_setting_cfg, 0, sizeof(laser_setting_cfg));
	memset(&sensor_setting_cfg, 0, sizeof(sensor_setting_cfg));

	//1.find laser settings
	laser_list_t *pl = NULL;
	for(int i = 0; i < sizeof(tof_laser_setting_list)/sizeof(tof_laser_setting_list[1]); i++){
		if(laser_type == tof_laser_setting_list[i].laser_type){
			pl = &tof_laser_setting_list[i];
			break;
		}
	}
	if(!pl){
		printf("sensor_list_setup failed, laser setting list not found!!\n");
		return -1;
	}
	laser_setting_cfg.laser_type = pl->laser_type;
	laser_setting_cfg.laser_settings = pl->laser_settings;
	laser_setting_cfg.laser_list_size = pl->laser_list_size;

	//2.find sensor settings
	sensor_list_t *ps = NULL;
	for(int i=0; i<sizeof(tof_sensor_setting_list)/sizeof(tof_sensor_setting_list[1]); i++)
	{
		if(sensor_type == tof_sensor_setting_list[i].sensor_type){
			ps = &tof_sensor_setting_list[i];
			break;
		}
	}
	if(!ps){
		printf("sensor_list_setup failed, sensor setting list not found!!\n");
		return -1;
	}
	sensor_setting_cfg.sensor_type = ps->sensor_type;
	sensor_setting_cfg.sensor_settings = ps->sensor_settings;
	sensor_setting_cfg.sensor_list_size = ps->sensor_list_size;

	printf("sensor_list_setup success.\n");
	return 0;
}

int driver_ic_detect()
{
	int ret = 0;
	// judge sensor cfg settings
	if(sensor_setting_cfg.sensor_type == SENSOR_LIST_NONE || laser_setting_cfg.laser_type == DRIVER_IC_NONE){
		//app not select,use default
		sensor_list_setup(DRIVER_IC_CXA4016, SENSOR_LIST_BURST_MASTER);
	}
	// execution sensor setting
	for (int i = 0; i < laser_setting_cfg.laser_list_size / sizeof(struct regList); i++) {
		ret = s5k33d_i2c_write16(laser_setting_cfg.laser_settings[i].reg, laser_setting_cfg.laser_settings[i].val);
		if(ret < 0){
			printf("write s5k33d_reglist failed!\n");
			return -1;
		}
	}
	printf("[tof_drv]sensor setting use: %d\n",  sensor_setting_cfg.sensor_type);

	usleep(100000); // todo :from star

	// execution laser setting
	for (int i = 0; i < sensor_setting_cfg.sensor_list_size / sizeof(struct regList); i++) {
		ret = s5k33d_i2c_write16(sensor_setting_cfg.sensor_settings[i].reg, sensor_setting_cfg.sensor_settings[i].val);
		if(ret < 0){
			printf("write s5k33d_reglist failed!\n");
			return -1;
		}
	}
	printf("[tof_drv]laser setting use: %d\n",  laser_setting_cfg.laser_type);

	return ret;
}


/**
* @brief  s5k33dxx_sensor_init 寄存器初始化
* @return int
*/
int s5k33dxx_sensor_init()
{
	int ret;
	ret = driver_ic_detect();
	if(!ret)
		printf("s5k33dxx_sensor_init success!\n");
	return ret;
}


/**
* @brief  s5k33dxx_group_hold setup grouped parameter hold
* @return int
*/
int s5k33dxx_group_hold(bool enable)
{
    int ret = 0;
    if(enable)
        ret = s5k33d_i2c_write8(0x0104, 0x01);
    else
        ret = s5k33d_i2c_write8(0x0104, 0x00);

    return ret;
}

/**
* @brief  s5k33dxx_get_sensor_id 获取sensor设备ID
* @param  [out] uint16_t *id
* @return int
*/
int s5k33dxx_get_sensor_id(uint16_t *id)
{
    int ret = 0;
    uint32_t value = 0;

    ret = s5k33d_i2c_read16(0x0000, &value);
    if (ret < 0)
        *id = 0xFFFF;

    *id = value;
    return ret;
}


/**
* @brief  s5k33d_get_chip_id 获取sensor设备CHIP_ID
* @param  [out] uint16_t *id
* @return int
*/
int s5k33d_get_chip_id()
{
	int ret;/**/
	usleep(1000);
	ret = s5k33d_i2c_write16(0x0A02, 0x0000); // select page 0
	ret = s5k33d_i2c_write16(0x0A00, 0x0100); // NVM read enable
	// After this sequence, data is ready in bytes 0x0A04-0x0A43
	uint16_t chip_id[5]; // 0A24-0A28 is chip id
	int i = 0;
	for (i = 0; i < 5; i++){
		ret = s5k33d_i2c_read16(0x0A22 + i*2, &chip_id[i]);
		printf("\r\nchip id: %x \r\n", chip_id[i]);
	}
	ret = s5k33d_i2c_write16(0x0A00, 0x0000); // NVM read disable
	return ret;
}


/**
* @brief  s5k33dxx_video_streaming 开关数据流
* @param  [in] bool enable
* @return int
* [0x0100] is RW/SR ,change cause entering stand-by/soft reset
*/
int s5k33dxx_video_streaming(bool enable)
{
    int ret;
    if (enable){  		
        ret = s5k33d_i2c_write16(0x0100, 0x0100);
		start_streaming_called = 1;
		//s5k33d_get_chip_id();
    }
    else{   	
        ret = s5k33d_i2c_write16(0x0100, 0x0000);
		start_streaming_called = 0;
		
    }
	
    return ret;
}

/**
* @brief  s5k33dxx_AE 自动AE开关
* @param  [in] bool enable
* @return int
*/
int s5k33dxx_AE(bool enable)
{
	int ret = 0;
	ret = s5k33d_i2c_write8(0x0100, 0x00);
	if (enable) {
		ret = s5k33d_i2c_write16(0x602A, 0x2052);
		ret = s5k33d_i2c_write16(0x6F12, 0x0001);
		//ret = s5k33d_i2c_write16(0x602A, 0x2056);
		//ret = s5k33d_i2c_write16(0x6F12, 0x07FF);
	}
	else {
		ret = s5k33d_i2c_write16(0x602A, 0x2052);
		ret = s5k33d_i2c_write16(0x6F12, 0x0000);
	}
	usleep(100000);//fixme : now test steady
	if(start_streaming_called)
		ret = s5k33d_i2c_write8(0x0100, 0x01);

	return ret;
}


/**
* @brief  s5k33dxx_set_hts line_length_pck
* @param  [in] uint8_t fps
* @return int
*/
int s5k33dxx_set_hts(uint16_t hts)
{
	if(s5k33d_i2c_write16(0x342, hts) < 0)
		return -1;
	return 0;
}
/**
* @brief  s5k33dxx_set_vts frame_length_lines
* @param  [in] uint8_t fps
* @return int
*/
int s5k33dxx_set_vts(uint16_t vts)
{
	if(s5k33d_i2c_write16(0x340, vts) < 0)
		return -1;
	return 0;
}

/**
* @brief  s5k33dxx_set_hts line_length_pck
* @param  [in] uint8_t fps
* @return int
*/
int s5k33dxx_get_hts(uint16_t hts)
{
	if(s5k33d_i2c_read16(0x342, (uint32_t *)&hts) < 0)
		return -1;
	return 0;
}
/**
* @brief  s5k33dxx_set_vts frame_length_lines
* @param  [in] uint8_t fps
* @return int
*/
int s5k33dxx_get_vts(uint16_t vts)
{
	if(s5k33d_i2c_read16(0x340, (uint32_t *)&vts) < 0)
		return -1;
	return 0;
}



/**
* @brief  s5k33dxx_set_fps 帧率设置
* @param  [in] uint8_t fps
* @return int
*/
int s5k33dxx_set_fps(uint8_t fps)
{
    int ret = 0;
	uint32_t vt_pll_multi, vt_pre_pll_clk_div, vt_sys_clk_div, vt_pix_clk_div;
    uint32_t vt_pix_clk_freq, frame_length_lines, line_length_pck;

#if 1


    ret = s5k33d_i2c_read16(0x0306, &vt_pll_multi);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0304, &vt_pre_pll_clk_div);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0302, &vt_sys_clk_div);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0300, &vt_pix_clk_div);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0342, &line_length_pck);
    if (ret < 0) {
        return ret;
    }

    vt_pix_clk_freq = 24 * (vt_pll_multi * 4) / (vt_pre_pll_clk_div * vt_sys_clk_div * vt_pix_clk_div);

    frame_length_lines = (uint16_t)((1000000 * vt_pix_clk_freq) / (line_length_pck * fps));

    ret = s5k33d_i2c_write16(0x0340, frame_length_lines);

    return ret;

#else
    line_length_pck = (uint16_t)(SENSOR_33D_HTS/(fps/30.0));
    frame_length_lines = SENSOR_33D_VTS;

    printf("fps:%d, vts:0x%x, hts:0x%x\n", fps, frame_length_lines, line_length_pck);

    ret |= s5k33d_i2c_write16(0x0340, frame_length_lines); // never change
    ret |= s5k33d_i2c_write16(0x0342, line_length_pck);

    return ret;
#endif
}

/**
* @brief  s5k33dxx_get_fps 获取当前帧率
* @param  [out] uint8_t* fps
* @return int
*/
int s5k33dxx_get_fps(uint8_t* fps)
{
    int ret;

    uint32_t vt_pll_multi, vt_pre_pll_clk_div, vt_sys_clk_div, vt_pix_clk_div;
    uint32_t vt_pix_clk_freq, frame_length_lines, line_length_pck;

    ret = s5k33d_i2c_read16(0x0306, &vt_pll_multi);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0304, &vt_pre_pll_clk_div);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0302, &vt_sys_clk_div);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0300, &vt_pix_clk_div);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0340, &frame_length_lines);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0342, &line_length_pck);
    if (ret < 0) {
        return ret;
    }

    vt_pix_clk_freq = 24 * (vt_pll_multi * 4) / (vt_pre_pll_clk_div * vt_sys_clk_div * vt_pix_clk_div);

    *fps = (uint8_t)((1000000 * vt_pix_clk_freq) / (frame_length_lines * line_length_pck));

    return ret;
}

int s5k33dxx_get_data_output_mode(uint8_t *mode)
{
    return 0;
}

int s5k33dxx_set_data_output_mode(uint8_t mode)
{
    return 0;
}


/**
* @brief  s5k33dxx_get_rx_temp 获取sensor温度
* @param  temperature
* @return int
*/
int s5k33dxx_get_rx_temp(float *temperature)
{
    //TODO rx
    int ret;
    uint16_t value;

    ret = s5k33d_i2c_read16(0x000A, &value);
    if (ret < 0)
        return ret;

    //printf("value =%d\n", value);
    *temperature = (float)fixed2float(value, 16, 8, 1);

    return 0;
}

/**
* @brief  s5k33dxx_get_tx_temp 获取laser温度
* @param  temperature
* @return int
*/
int s5k33dxx_get_tx_temp(float *temperature)
{
    int ret;
    uint16_t value;
	uint16_t temp = 296;
    uint8_t RefTemp = 25;
    float param = 5.4;

    //usleep(1000);
    ret = s5k33d_i2c_read16(0x00F4, &value);
	//printf("tx temp read value: %d\r\n", value);

	*temperature = 25 + ((value - 296)) / 5.4f;

    return ret;
}


int s5k33dxx_set_illum_duty_cycle(uint8_t duty)
{
    int ret = 0;
    uint16_t value = 0;
    uint16_t inc_value, dec_value;

    duty_cycle = duty;

    if (duty == 15)
    {
        ret = s5k33d_i2c_write16(0xF49C, 0x0000);
        if (ret < 0)
            return ret;
        ret = s5k33d_i2c_write16(0xF4AC, 0x0000);
        if (ret < 0)
            return ret;
    }
    else if (duty > 15)
    {
        value = (uint16_t)(duty - 15);
        ret = s5k33d_i2c_write16(0xF4AC, 0x0000);
        if (ret < 0)
            return ret;
        ret = s5k33d_i2c_write16(0xF49C, value);
        if (ret < 0)
            return ret;
    }
    else if (duty < 15)
    {
        value = (uint16_t)(15 - duty);
        ret = s5k33d_i2c_write16(0xF49C, 0x0000);
        if (ret < 0)
            return ret;
        ret = s5k33d_i2c_write16(0xF4AC, value);
        if (ret < 0)
            return ret;
    }

    return ret;
}

int s5k33dxx_get_illum_duty_cycle(uint8_t *duty)
{
    int ret;
    uint32_t inc_value, dec_value;

    ret = s5k33d_i2c_read16(0xF4AC, &dec_value);
    if (ret < 0)
        return ret;

    ret = s5k33d_i2c_read16(0xF49C, &inc_value);
    if (ret < 0)
        return ret;

    if ((inc_value == 0) && (dec_value != 0))
    {
        *duty = (uint8_t)(15 - dec_value);
    }
    else if ((inc_value != 0) && (dec_value == 0))
    {
        *duty = (uint8_t)(15 + inc_value);
    }
    else if ((inc_value == 0) && (dec_value == 0))
    {
        *duty = 15;
    }

#if 1 //test
	*duty = duty_cycle;
#endif

    return ret;
}



/**
* @brief  s5k33dxx_get_illum_power 控制激光电流，只使用了一个APC，只看Value_A即可
* @param  value_A APC1 Isw current 14.8mA/step, 0-0xff
* @param  value_B 现在没有用。设置为0
* @return int
*/
int s5k33dxx_set_illum_power(uint8_t value_A, uint8_t value_B)
{
    int ret = 0;
	
	//update register
	if(value_A != 0){ //开关激光接口使用设置电流为0实现时，这里不更新，下次打开激光时使用之前set的值，不更新则为默认值
		laser_power_val_A = value_A;
		laser_power_val_B = value_B;
		ret |= cxa4016_reg_write(0x4B06, laser_power_val_A);
		ret |= cxa4016_reg_write(0x4B07, 0x08);//Fixme: 4016的0f寄存器目前按照缪工推荐值设置死。
	}
	else{
		ret |= cxa4016_reg_write(0x4B06, 0x0);
		ret |= cxa4016_reg_write(0x4B07, 0x00);//Fixme: 设置激光电流为0时，这个寄存器必须设置为0，否则激光关不死
	}

    return ret;
}


/**
* @brief  s5k33dxx_get_illum_power 控制激光电流，只使用了一个APC，只看Value_A即可
* @param  value_A APC1 Isw current 14.8mA/step
* @return int
*/
int s5k33dxx_get_illum_power(uint8_t *value_A, uint8_t *value_B)
{
    int ret = 0;

	//ret = cxa4016_reg_read(0x2891, value_A);
	ret = cxa4016_reg_read(0x4B06, value_A);
	if (ret < 0)
		return ret;

	ret = cxa4016_reg_read(0x288F, value_B);
	if (ret < 0)
		return ret;


    // uint8_t buf[140];

//    fm24c128d_eeprom_block_write(0x0000, test, sizeof(test));

//    fm24c128d_eeprom_block_read(0x0000, buf, sizeof(test));

    // fm24c128d_eeprom_sector_write(0x0000, buf, 1);
    return ret;
}

/**
* @brief  s5k33dxx_illum_power_control 控制激光开关，目前只能通过配置laser供电或者s5k33dxx_set_illum_power(0)实现
* @param  enable
* @return int
*/
int s5k33dxx_illum_power_control(bool enable)
{

	if(!enable){
		s5k33dxx_set_illum_power(0, 0);
	}
	else{
		s5k33dxx_set_illum_power(laser_power_val_A, laser_power_val_B);
	}
	
    return 0;
}


/**
* @brief  s5k33dxx_set_integration_threshold 设置积分时间调整区间
* @param  max 积分时间上限us
* @param  min 积分时间下限us
* @return <0 failed
*/
int s5k33dxx_set_integration_threshold(uint16_t max, uint16_t min)
{
	int ret = 0;
	// max_exp with hts ??
	if(max > 1000 || min < 20){
		printf("set integration threshold failed, the range is %d - %d\n", 20, 1000);
		return -1;
	}
		
	exp_max = max;
	exp_min = min;
	ret = s5k33d_i2c_write16(0x602A, 0x4ac6);
	if (ret < 0) {
        return ret;
    }
	ret = s5k33d_i2c_write16(0x6f12, max);
	if (ret < 0) {
        return ret;
    }
	ret = s5k33d_i2c_write16(0x6f12, min);
	if (ret < 0) {
        return ret;
    }
	return ret;
}

/**
* @brief  s5k33dxx_set_integration_threshold 获取积分时间调整区间
* @param  max 积分时间上限us
* @param  min 积分时间下限us
* @return <0 failed
*/
int s5k33dxx_get_integration_threshold(uint16_t *max, uint16_t *min)
{
	int ret = 0;

	*max = exp_max;
	*min = exp_min;

	return ret ;
}


/**
* @brief  s5k33dxx_set_integration_time 积分时间设置
* @param  [in] uint16_t integrationTime (us)
* @return int
*/
int s5k33dxx_set_integration_time(uint16_t integrationTime)
{
    int ret;

    uint32_t vt_pll_multi, vt_pre_pll_clk_div, vt_sys_clk_div, vt_pix_clk_div;
    uint32_t vt_pix_clk_freq, coarse_integration_time, line_length_pck;

    ret = s5k33d_i2c_read16(0x0306, &vt_pll_multi);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0304, &vt_pre_pll_clk_div);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0302, &vt_sys_clk_div);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0300, &vt_pix_clk_div);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0342, &line_length_pck);
    if (ret < 0) {
        return ret;
    }

    vt_pix_clk_freq = 24 * (vt_pll_multi * 4) / (vt_pre_pll_clk_div * vt_sys_clk_div * vt_pix_clk_div);
	printf("vt_pix_clk_freq = %d\n", vt_pix_clk_freq);

    coarse_integration_time = (vt_pix_clk_freq * integrationTime) / line_length_pck;
	printf("coarse_integration_time= %d\n", coarse_integration_time);

    ret = s5k33d_i2c_write16(0x0202, coarse_integration_time);

    // s5k33d_reglist[1606].val = coarse_integration_time;

    return ret;
}

/**
* @brief  s5k33dxx_get_integration_time 获取当前积分时间
* @param  [out] uint16_t *integrationTime (us)
* @return int
*/
int s5k33dxx_get_integration_time(uint16_t *integrationTime)
{
    int ret;

    uint32_t vt_pll_multi, vt_pre_pll_clk_div, vt_sys_clk_div, vt_pix_clk_div;
    uint32_t vt_pix_clk_freq, coarse_integration_time, line_length_pck;

    ret = s5k33d_i2c_read16(0x0306, &vt_pll_multi);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0304, &vt_pre_pll_clk_div);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0302, &vt_sys_clk_div);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0300, &vt_pix_clk_div);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0342, &line_length_pck);
    if (ret < 0) {
        return ret;
    }
    ret = s5k33d_i2c_read16(0x0202, &coarse_integration_time);
    if (ret < 0) {
        return ret;
    }

    vt_pix_clk_freq = 24 * (vt_pll_multi * 4) / (vt_pre_pll_clk_div * vt_sys_clk_div * vt_pix_clk_div);

    *integrationTime = (coarse_integration_time * line_length_pck) / vt_pix_clk_freq;

    return ret;
}

/**
* @brief  s5k33dxx_get_modulation_frequency 获取双频调制频率
* @param  modFreq freq0/freq1,support-list[100,95,80,70,60,20,15,10]
* @return int
*/
int s5k33dxx_get_modulation_frequency(uint16_t *modFreq)
{
    int ret;
    uint32_t freq_0, freq_1;
	uint32_t P, M, S, D;

	ret = s5k33d_i2c_read16(0x02F0, &P);
    ret = s5k33d_i2c_read16(0x02F2, &M);
	ret = s5k33d_i2c_read16(0x02F4, &S);
	ret = s5k33d_i2c_read16(0x02F6, &D);
	freq_0 = 24 * M / (4*P*D*pow(2, S));
	//printf("freq_0:%d, P:%x, M:%x, S:%x, D:%x \r\n", freq_0, P, M, S, D);

	ret = s5k33d_i2c_read16(0x02F8, &P);
	ret = s5k33d_i2c_read16(0x02FA, &M);
	ret = s5k33d_i2c_read16(0x02FC, &S);
	ret = s5k33d_i2c_read16(0x02FE, &D);
	freq_1 = 24 * M / (4 * P*D*pow(2, S));

    *modFreq = ((freq_0 << 8) | freq_1);

    return ret;
}

/**
* @brief  s5k33dxx_set_modulation_frequency 设置双频调制频率
* @param  modFreq freq0/freq1,support-list[100,95,80,70,60,20,15,10]
* @return int
*/
int s5k33dxx_set_modulation_frequency(uint16_t modFreq)
{
    int ret;
    uint16_t freq_0, freq_1;

    freq_0 = (modFreq >> 8) & 0xFF;
    freq_1 = modFreq & 0xFF;
#if 0
	/*
	ret = s5k33dxx_sensor_init();
	if (ret < 0)
		return ret;

	usleep(5);*/
	ret = s5k33d_i2c_write16(0x02F2, freq_0);
	if (ret < 0)
		return ret;

	ret = s5k33d_i2c_write16(0x02FA, freq_1);
	if (ret < 0)
		return ret;

	//ret = s5k33d_i2c_write8(0x0100, 0x01);
#else

	ret = s5k33d_i2c_write8(0x0100, 0x00); // should stop streaming first

	switch (freq_0) { // PLL M can not set too large, so we change PLL S and D to get target frequency
	case 100:
		ret = s5k33d_i2c_write16(0x02F0, 0x0003);
		ret = s5k33d_i2c_write16(0x02F2, 0x0064);
		ret = s5k33d_i2c_write16(0x02F4, 0x0000);
		ret = s5k33d_i2c_write16(0x02F6, 0x0002);
		break;
	case 95:
		ret = s5k33d_i2c_write16(0x02F0, 0x0003);
		ret = s5k33d_i2c_write16(0x02F2, 0x005F);
		ret = s5k33d_i2c_write16(0x02F4, 0x0000);
		ret = s5k33d_i2c_write16(0x02F6, 0x0002);
		break;
	case 80:
		ret = s5k33d_i2c_write16(0x02F0, 0x0003);
		ret = s5k33d_i2c_write16(0x02F2, 0x0050);
		ret = s5k33d_i2c_write16(0x02F4, 0x0000);
		ret = s5k33d_i2c_write16(0x02F6, 0x0002);
		break;
	case 70:
		ret = s5k33d_i2c_write16(0x02F0, 0x0003);
		ret = s5k33d_i2c_write16(0x02F2, 0x0046);
		ret = s5k33d_i2c_write16(0x02F4, 0x0000);
		ret = s5k33d_i2c_write16(0x02F6, 0x0002);
		break;
	case 60:
		ret = s5k33d_i2c_write16(0x02F0, 0x0003);
		ret = s5k33d_i2c_write16(0x02F2, 0x0078);
		ret = s5k33d_i2c_write16(0x02F4, 0x0000);
		ret = s5k33d_i2c_write16(0x02F6, 0x0004);
		break;
	case 20:
		ret = s5k33d_i2c_write16(0x02F0, 0x0003);
		ret = s5k33d_i2c_write16(0x02F2, 0x0050);
		ret = s5k33d_i2c_write16(0x02F4, 0x0000);
		ret = s5k33d_i2c_write16(0x02F6, 0x0008);
		break;
	case 15:
		ret = s5k33d_i2c_write16(0x02F0, 0x0003);
		ret = s5k33d_i2c_write16(0x02F2, 0x0078);
		ret = s5k33d_i2c_write16(0x02F4, 0x0002);
		ret = s5k33d_i2c_write16(0x02F6, 0x0004);
		break;
	case 10:
		ret = s5k33d_i2c_write16(0x02F0, 0x0003);
		ret = s5k33d_i2c_write16(0x02F2, 0x0050);
		ret = s5k33d_i2c_write16(0x02F4, 0x0001);
		ret = s5k33d_i2c_write16(0x02F6, 0x0008);
		break;
	default:
		break;
	}

	switch (freq_1) {
	case 100:
		ret = s5k33d_i2c_write16(0x02F8, 0x0003);
		ret = s5k33d_i2c_write16(0x02FA, 0x0064);
		ret = s5k33d_i2c_write16(0x02FC, 0x0000);
		ret = s5k33d_i2c_write16(0x02FE, 0x0002);
		break;
	case 95:
		ret = s5k33d_i2c_write16(0x02F8, 0x0003);
		ret = s5k33d_i2c_write16(0x02FA, 0x005F);
		ret = s5k33d_i2c_write16(0x02FC, 0x0000);
		ret = s5k33d_i2c_write16(0x02FE, 0x0002);
		break;
	case 80:
		ret = s5k33d_i2c_write16(0x02F8, 0x0003);
		ret = s5k33d_i2c_write16(0x02FA, 0x0050);
		ret = s5k33d_i2c_write16(0x02FC, 0x0000);
		ret = s5k33d_i2c_write16(0x02FE, 0x0002);
		break;
	case 70:
		ret = s5k33d_i2c_write16(0x02F8, 0x0003);
		ret = s5k33d_i2c_write16(0x02FA, 0x0046);
		ret = s5k33d_i2c_write16(0x02FC, 0x0000);
		ret = s5k33d_i2c_write16(0x02FE, 0x0002);
		break;
	case 60:
		ret = s5k33d_i2c_write16(0x02F8, 0x0003);
		ret = s5k33d_i2c_write16(0x02FA, 0x0078);
		ret = s5k33d_i2c_write16(0x02FC, 0x0000);
		ret = s5k33d_i2c_write16(0x02FE, 0x0004);
		break;
	case 20:
		ret = s5k33d_i2c_write16(0x02F8, 0x0003);
		ret = s5k33d_i2c_write16(0x02FA, 0x0050);
		ret = s5k33d_i2c_write16(0x02FC, 0x0000);
		ret = s5k33d_i2c_write16(0x02FE, 0x0008);
		break;
	case 15:
		ret = s5k33d_i2c_write16(0x02F8, 0x0003);
		ret = s5k33d_i2c_write16(0x02FA, 0x0078);
		ret = s5k33d_i2c_write16(0x02FC, 0x0002);
		ret = s5k33d_i2c_write16(0x02FE, 0x0004);
		break;
	case 10:
		ret = s5k33d_i2c_write16(0x02F8, 0x0003);
		ret = s5k33d_i2c_write16(0x02FA, 0x0050);
		ret = s5k33d_i2c_write16(0x02FC, 0x0001);
		ret = s5k33d_i2c_write16(0x02FE, 0x0008);
		break;
	default:
		break;
}

	if (start_streaming_called)
		ret = s5k33d_i2c_write8(0x0100, 0x01);

#endif
    //s5k33dxx_set_illum_duty_cycle(duty_cycle);

    return ret;
}

/**
* @brief  s5k33dxx_set_img_mirror_flip 设置sensor镜像
* @param  [in] uint8_t mode
* @code 
* typedef enum 
* {
*     IMAGE_NORMAL = 0,
*     IMAGE_H_MIRROR,
*     IMAGE_V_MIRROR,
*     IMAGE_HV_MIRROR
* }img_rotation_t;
* @code 
* @return int
*/
int s5k33dxx_set_img_mirror_flip(img_rotation_t mode)
{
    int ret;

    switch (mode)
    {
    case IMAGE_NORMAL:
        ret = s5k33d_i2c_write8(0x0101, 0);
        break;
    case IMAGE_H_MIRROR:
        ret = s5k33d_i2c_write8(0x0101, 1);
        break;
    case IMAGE_V_MIRROR:
        ret = s5k33d_i2c_write8(0x0101, 2);
        break;
    case IMAGE_HV_MIRROR:
        ret = s5k33d_i2c_write8(0x0101, 3);
        break;
    default:
        ret = -1;
        break;
    }

    return ret;
}

/**
* @brief  s5k33dxx_get_img_mirror_flip 获取当前镜像状态
* @param  [out] uint8_t* mode
* @return int
*/
int s5k33dxx_get_img_mirror_flip(img_rotation_t* mode)
{
    int ret;

    ret = s5k33d_i2c_read8(0x0101, mode);

    return ret;
}

/**
* @brief  s5k33dxx_test_pattern test pattern设置
* @param  [in] uint8_t mode
* @code
* typedef enum 
* {
*     IMAGE_NO_PATTERN = 0,
*     IMAGE_GRADIENT_PATTERN,
*     IMAGE_SOLID_PATTERN,
* }test_pattern_t; 
* @code
* @return int
*/
int s5k33dxx_test_pattern(test_pattern_t mode)
{
    int ret;

    switch (mode)
    {
    case IMAGE_NO_PATTERN:
        ret = s5k33d_i2c_write16(0x0600, 0x0000);
        break;
    case IMAGE_SOLID_PATTERN:
        ret = s5k33d_i2c_write16(0x0600, 0x0301);
        if (ret < 0) {
            break;
        }
        ret = s5k33d_i2c_write16(0x0602, 0x0000);
        if (ret < 0) {
            break;
        }
        ret = s5k33d_i2c_write16(0x0604, 0x0000);
        if (ret < 0) {
            break;
        }
        ret = s5k33d_i2c_write16(0x0606, 0x0000);
        if (ret < 0) {
            break;
        }
        ret = s5k33d_i2c_write16(0x0608, 0x0000);
        break;
    case IMAGE_GRADIENT_PATTERN:
        ret = s5k33d_i2c_write16(0x0600, 0x0302);
        if (ret < 0) {
            break;
        }
        ret = s5k33d_i2c_write8(0x0615, 0x03);
        if (ret < 0) {
            break;
        }
        ret = s5k33d_i2c_write8(0x0616, 0x00);
        if (ret < 0) {
            break;
        }
        ret = s5k33d_i2c_write8(0x0617, 0x00);
        if (ret < 0) {
            break;
        }
        ret = s5k33d_i2c_write8(0x0618, 0x00);
        break;
    default:
        ret = -1;
        break;
    }

    return ret;
}

// 2x2 binning, resolution changed from 1280*960 to 640*480
int s5k33d_set_pixel_binning(uint8_t mode)
{
    int ret;
    ret = s5k33d_i2c_write8(0x0900, mode&0x1);
    if (ret < 0)
        return ret;
    ret = s5k33d_i2c_write8(0x0901, 0x22);
    if (ret < 0)
        return ret;
    ret = s5k33d_i2c_write8(0x0902, 0x01);
    if (ret < 0)
        return ret;
    return ret;
}

// 2x2 binning, resolution changed from 1280*960 to 640*480
int s5k33d_get_pixel_binning(uint8_t *mode)
{
    int ret;
    ret = s5k33d_i2c_write8(0x0900, 0x01);
    if (ret < 0)
        return ret;
    ret = s5k33d_i2c_write8(0x0901, 0x22);
    if (ret < 0)
        return ret;
    ret = s5k33d_i2c_write8(0x0902, 0x00);
    if (ret < 0)
        return ret;
    return ret;
}