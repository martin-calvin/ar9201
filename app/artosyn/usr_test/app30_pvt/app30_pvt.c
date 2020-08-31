#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include <malloc.h>
#include <pthread.h>
#include "ar_common_define.h"
#include "ar_meta_define.h"
#include "ar_multimedia_base.h"
#include "icc_proxy_rpc_def.h"

int icc_proxy_rpc_to_linux_open_dev(const char *name);
int icc_proxy_rpc_to_linux_acquire_buffer(int fd,struct icc_proxy_rpc_to_linux_element_t *buffer_info);
int icc_proxy_rpc_to_linux_release_buffer(int fd,struct icc_proxy_rpc_to_linux_element_t *usr_buffer);
int icc_proxy_rpc_to_linux_exit(int usr_fd);

typedef struct {
    ar_facotry_element_obj_t pipeline;
    ar_facotry_element_obj_t audio_out;
	ar_facotry_element_obj_t aac_decoder;
	ar_facotry_element_obj_t i2s_sink;
	ar_facotry_element_obj_t tee;
}ipcam_audio_out_context_t;

typedef struct {
    ar_facotry_element_obj_t pipeline;
    ar_facotry_element_obj_t audio_in;
    ar_facotry_element_obj_t aac_encoder;
    ar_facotry_element_obj_t i2s_src;
}ipcam_audio_in_context_t;

#define AUDIO_FRAME_LEN (256*1024)



#define ARTOSYN_PIN_SHARE_CFG		     0x60633000
#define GPIO_BASE_ADDR                  (0x40400000)
#define GPIO_BASE_ADDR_OFFSET           (0x00020000)

#define GPIO_CTRL_SOFTWARE				(0)
#define GPIO_CTRL_HARDWARE				(1)


#define GPIO_DATA_DIRECT_A_OFFSET       (0x04)
#define GPIO_DATA_DIRECT_B_OFFSET       (0x10)
#define GPIO_DATA_DIRECT_C_OFFSET       (0x1C)
#define GPIO_DATA_DIRECT_D_OFFSET       (0x28)

#define GPIO_CTRL_A_OFFSET              (0x08)
#define GPIO_CTRL_B_OFFSET              (0x14)
#define GPIO_CTRL_C_OFFSET              (0x20)
#define GPIO_CTRL_D_OFFSET              (0x2C)

#define GPIO_DATA_A_OFFSET              (0x00)
#define GPIO_DATA_B_OFFSET              (0x0C)
#define GPIO_DATA_C_OFFSET              (0x18)
#define GPIO_DATA_D_OFFSET              (0x24)

#define GPIO_EXTERN_A_OFFSET            (0x50)
#define GPIO_EXTERN_B_OFFSET            (0x54)
#define GPIO_EXTERN_C_OFFSET            (0x58)
#define GPIO_EXTERN_D_OFFSET            (0x5C)


#define GPIO_DATA_DIRECT_INPUT          (0)
#define GPIO_DATA_DIRECT_OUTPUT         (1)


static char mod_gpiopin[139][2] =
{{4,0},  {0,1},  {0,2},  {0,3},  {0,4},  {0,5},  {0,6},  {0,7},  {1,16}, {1,17},
 {1,18}, {1,19}, {1,20}, {1,21}, {1,22}, {1,23}, {1,24}, {1,25}, {1,26}, {1,27},
 {1,32}, {1,33}, {1,34}, {1,35}, {1,36}, {1,37}, {1,38}, {1,39}, {1,40}, {1,41},
 {1,42}, {1,43}, {1,44}, {1,45}, {1,46}, {1,47}, {1,28}, {1,29}, {1,48}, {1,49},
 {1,50}, {1,51}, {1,52}, {1,53}, {1,54}, {1,55}, {1,30}, {1,31}, {1,56}, {1,57},
 {1,58}, {1,59}, {1,60}, {1,61}, {1,62}, {1,63}, {1,64}, {1,65}, {1,72}, {1,73},
 {1,74}, {1,75}, {1,76}, {1,77}, {1,78}, {1,79}, {1,80}, {1,81}, {1,82}, {1,83},
 {1,84}, {1,85}, {1,86}, {1,87}, {2,88}, {2,89}, {0,90}, {0,91}, {2,92}, {2,93},
 {2,94}, {2,95}, {1,66}, {1,67}, {1,68}, {1,69}, {1,96}, {1,97}, {1,98}, {1,99},
 {1,100},{1,101},{1,102},{1,103},{1,70}, {1,71}, {1,8},  {1,9},  {1,104},{1,105},
 {1,106},{1,107},{1,108},{1,109},{1,110},{1,111},{1,10}, {1,11}, {1,12}, {1,112},
 {1,113},{1,114},{1,115},{1,116},{1,117},{1,118},{1,119},{1,13}, {1,14}, {1,120},
 {1,121},{1,122},{1,123},{1,124},{1,125},{1,126},{1,127},{1,136},{1,137},{1,138},
 {1,139},{1,140},{1,141},{1,128},{1,129},{1,15}, {1,130},{1,131},{1,132} };


int test_ping_dbg = 0;
unsigned char test_result[32];

typedef struct _TEST_PIN{

    unsigned char *name;
    unsigned int mode;
    unsigned int id;

}TEST_PIN;


TEST_PIN test_pin[] = {

//  name        mod     id
    {"d0_2",     1,     20},
    {"d0_0",     1,     18},
    {"d0_3",     1,     21},
    {"d0_7",     1,     49},
    {"c2_1",     1,     69},
    {"a0_5",     0,     7},
    {"a2_1",     1,     59},
    {"d0_1",     1,     19},
    {"a1_6",     1,     28},
    {"d0_6",     1,     48},
    {"d0_7",     1,     49},
    {"a2_1",     1,     59},
    {"d2_3",     0,     79},
    {"a0_6",     0,     8},
    {"a0_7",     0,     9},
    {"a1_2",     1,     24},
    
    {"D0_2",     1,     20},
    {"D0_0",     1,     18},
    {"D0_3",     1,     21},
    {"D0_7",     1,     49},
    {"C2_1",     1,     69},
    {"A0_5",     0,     7},
    {"A2_1",     1,     59},
    {"D0_1",     1,     19},
    {"A1_6",     1,     28},
    {"D0_6",     1,     48},
    {"D0_7",     1,     49},
    {"A2_1",     1,     59},
    {"D2_3",     0,     79},
    {"A0_6",     0,     8},
    {"A0_7",     0,     9},
    {"A1_2",     1,     24},
};

typedef struct PIN_BAK{

    unsigned int pin;
    unsigned int mul_reg;
    unsigned int ctrl_reg;
    unsigned int dir_reg;
    unsigned int value_reg;

}PIN_BAK;

PIN_BAK pin_bak[64];
int pin_bak_inc = 0;

int phy_read(unsigned int addr)
{

        void *map_base, *virt_addr;
        unsigned int read_result;
        off_t target;
        unsigned page_size, mapped_size, offset_in_page;
        int fd;
	unsigned width = 8 * sizeof(int);

	target = addr;
        fd = open("/dev/mem",(O_RDWR | O_SYNC),0);
        mapped_size = page_size = getpagesize();
        offset_in_page = (unsigned)target & (page_size - 1);
        if (offset_in_page + width > page_size) {
                mapped_size *= 2;
        }

        map_base = mmap(NULL,
                        mapped_size,
                       (PROT_READ | PROT_WRITE),
                        MAP_SHARED,
                        fd,
                        target & ~(off_t)(page_size - 1));

        virt_addr = (char*)map_base + offset_in_page;
	read_result = *(volatile unsigned int*)virt_addr;
        if (munmap(map_base, mapped_size) == -1)
            printf("err unmap\n");
        close(fd);
	return read_result;
}

int phy_write(unsigned int addr,unsigned int writeval)
{

        void *map_base, *virt_addr;
        unsigned int read_result;
        off_t target;
        unsigned page_size, mapped_size, offset_in_page;
        int fd;
	unsigned width = 8 * sizeof(int);

	target = addr;
        fd = open("/dev/mem",(O_RDWR | O_SYNC),0);
        mapped_size = page_size = getpagesize();
        offset_in_page = (unsigned)target & (page_size - 1);
        if (offset_in_page + width > page_size) {
                mapped_size *= 2;
        }
        map_base = mmap(NULL,
                        mapped_size,
                       (PROT_READ | PROT_WRITE),
                        MAP_SHARED,
                        fd,
                        target & ~(off_t)(page_size - 1));

        virt_addr = (char*)map_base + offset_in_page;

        *(volatile unsigned int*)virt_addr = writeval;
        if (munmap(map_base, mapped_size) == -1)
            printf("err unmap\n");
        close(fd);
        return 0;
}


int reg_read(unsigned int addr)
{return phy_read(addr);}
void reg_write(unsigned int addr, unsigned int value)
{phy_write(addr,value);}
void reg_write_mask(unsigned int addr, unsigned int msk, unsigned int lsb, unsigned int value)
{
	phy_write(addr, (phy_read(addr) & ~(msk)) | ((value) << (lsb)));
}

//#define reg_read(addr)  (*(volatile unsigned int *)(addr))
//#define reg_write(addr, value) ((*(volatile unsigned int *)(addr)) = value)
//#define reg_write_mask(addr, msk, lsb, value) do {\

struct gpio_st{
    unsigned char  u8_gpio_num;
    unsigned char  u8_regno;
    unsigned int u32_gpio_addr;
};


//unsigned int pad_mode range: 000~111
//unsigned int driver_strong_or_weak  range:00~11
//unsigned int pull_up_or_down  range: for 1.8v pad, 10~11; for SD pad or RGM pad, 01~10.

//1. pin share
static void pad_setmode(unsigned int pinnum, unsigned int pad_mode, unsigned int driver_strong_or_weak, unsigned int pull_up_or_down)
{
	unsigned int rd_tmp;
	unsigned int reg_num;
	unsigned int reg_part; //[9:0]-part 0;  [19:10]-part 1; [29:10]-part 2
	unsigned int wr_data;
	unsigned int input_para_sum = 0;
	volatile unsigned int *reg_base = (volatile unsigned int *)ARTOSYN_PIN_SHARE_CFG;

	reg_num  = pinnum/3;
	reg_part = pinnum%3;

	rd_tmp   = phy_read(reg_base + reg_num);
	if(driver_strong_or_weak > 3){
		driver_strong_or_weak = (rd_tmp & (0x18 << (reg_part*10))) >> ((reg_part*10) + 3);
	}
	if(pull_up_or_down > 3){
		pull_up_or_down = (rd_tmp & (0x60 << (reg_part*10))) >> ((reg_part*10) + 5);
	}
	input_para_sum = pad_mode + (driver_strong_or_weak << 3) + (pull_up_or_down << 5);
	wr_data  = (rd_tmp & ~(0x7F << (reg_part*10))) | (input_para_sum & 0x7F) << (reg_part*10);
	phy_write(reg_base + reg_num,wr_data);
}


static void gpio_get_addr(unsigned int gpionum, struct gpio_st *gpio)
{
	unsigned char u8_groupno = (gpionum>>5);
	gpio->u8_regno = (gpionum%32)>>3;

	gpio->u8_gpio_num = (gpionum%32)%8;
	gpio->u32_gpio_addr = (u8_groupno*GPIO_BASE_ADDR_OFFSET + GPIO_BASE_ADDR);
}

static void gpio_setpin_direct(unsigned int gpionum, unsigned int mode)
{
    struct gpio_st gpio;
    unsigned char offset;
    gpio_get_addr(gpionum, &gpio);

    switch(gpio.u8_regno) {
        case 0:
        offset = GPIO_DATA_DIRECT_A_OFFSET;
        break;

        case 1:
        offset = GPIO_DATA_DIRECT_B_OFFSET;
        break;

        case 2:
        offset = GPIO_DATA_DIRECT_C_OFFSET;
        break;

        case 3:
        offset = GPIO_DATA_DIRECT_D_OFFSET;
        break;
    }
    if(test_ping_dbg == 1)
        printf("addr : %x gpio_num : %x mode : %x\n",gpio.u32_gpio_addr+offset,gpio.u8_gpio_num,mode);
    reg_write_mask(gpio.u32_gpio_addr+offset, 1 << gpio.u8_gpio_num, gpio.u8_gpio_num, mode);
}

static void gpio_setpin_ctrl(unsigned int gpionum, unsigned int mode)
{
    struct gpio_st gpio;
    unsigned char offset;
    gpio_get_addr(gpionum, &gpio);
    switch(gpio.u8_regno) {
        case 0:
        offset = GPIO_CTRL_A_OFFSET;
        break;

        case 1:
        offset = GPIO_CTRL_B_OFFSET;
        break;

        case 2:
        offset = GPIO_CTRL_C_OFFSET;
        break;

        case 3:
        offset = GPIO_CTRL_D_OFFSET;
        break;
    }

    reg_write_mask(gpio.u32_gpio_addr+offset, 1 << gpio.u8_gpio_num, gpio.u8_gpio_num, mode);
}

static int gpio_set_output(unsigned int gpiopin)
{
    gpio_setpin_direct(gpiopin, GPIO_DATA_DIRECT_OUTPUT);
    gpio_setpin_ctrl(gpiopin, GPIO_CTRL_SOFTWARE);

    return 0;
}
static int gpio_set_input(unsigned int gpiopin)
{    
    gpio_setpin_direct(gpiopin, GPIO_DATA_DIRECT_INPUT);    
    gpio_setpin_ctrl(gpiopin, GPIO_CTRL_SOFTWARE);    
    return 0;
}

static void gpio_setpin(unsigned int gpionum, unsigned int value)
{
	struct gpio_st gpio;
	unsigned char offset;
	gpio_get_addr(gpionum, &gpio);
	switch(gpio.u8_regno) {
		case 0:
	    	offset = GPIO_DATA_A_OFFSET;
	    	break;

	    	case 1:
	    	offset = GPIO_DATA_B_OFFSET;
	    	break;

	    	case 2:
	    	offset = GPIO_DATA_C_OFFSET;
	    	break;

	    	case 3:
	    	offset = GPIO_DATA_D_OFFSET;
	    	break;
	}
    if(test_ping_dbg == 1)
        printf("addr : %x gpio_num : %x mode : %x\n",gpio.u32_gpio_addr+offset,gpio.u8_gpio_num,value);

	reg_write_mask(gpio.u32_gpio_addr+offset, 1 << gpio.u8_gpio_num, gpio.u8_gpio_num, value);
}

static void gpio_getpin(unsigned int gpionum, unsigned int *value)
{
	struct gpio_st gpio;
	unsigned char offset;
	unsigned int ret;
	gpio_get_addr(gpionum, &gpio);
	switch(gpio.u8_regno) {
		case 0:
	    	offset = GPIO_EXTERN_A_OFFSET;
	    	break;

	    	case 1:
	    	offset = GPIO_EXTERN_B_OFFSET;
	    	break;

	    	case 2:
	    	offset = GPIO_EXTERN_C_OFFSET;
	    	break;

	    	case 3:
	    	offset = GPIO_EXTERN_D_OFFSET;
	    	break;
	}

    ret = reg_read(gpio.u32_gpio_addr+offset);

    if(test_ping_dbg == 1)
        printf("addr : %x ,ret : %x\n",gpio.u32_gpio_addr+offset,ret);
    
    ret = ret >> gpio.u8_gpio_num;
    ret = ret & 0x01;
    *value = ret;
    
}


void ar_set_padmode_gpiopin(unsigned int pinnum, unsigned int pad_mode,
								unsigned int driver_strong_or_weak, unsigned int pull_up_or_down, unsigned int value)
{
	unsigned int gpiopin = 0;

	pad_setmode(pinnum, pad_mode, driver_strong_or_weak, pull_up_or_down);
	if((value >= 0)&&(value <= 1)){
        if((pinnum >= 2)&&(pinnum <= 140)){
            if(pad_mode == mod_gpiopin[pinnum-2][0])
                gpiopin = mod_gpiopin[pinnum-2][1];
        }
        gpio_set_input(gpiopin);
	}
}

void ar_gpio_set_input(unsigned int pinnum)
{
	unsigned int gpiopin = 0;
    if((pinnum >= 2)&&(pinnum <= 140))
    {
        gpiopin = mod_gpiopin[pinnum-2][1];
    }
    gpio_set_input(gpiopin);
}

void ar_gpio_set_output(unsigned int pinnum)
{
    unsigned int gpiopin = 0;
    if((pinnum >= 2)&&(pinnum <= 140))
    {
        gpiopin = mod_gpiopin[pinnum-2][1];
    }
    gpio_set_output(gpiopin);
}

void ar_gpio_setpin(unsigned int pinnum, unsigned int value)
{
    unsigned int gpiopin = 0;
    if((pinnum >= 2)&&(pinnum <= 140))
    {
        gpiopin = mod_gpiopin[pinnum-2][1];
    }
    gpio_setpin(gpiopin, value);
}

static void ar_gpio_getpin(unsigned int pinnum, unsigned int *value)
{
    unsigned int gpiopin = 0;
    if((pinnum >= 2)&&(pinnum <= 140))
    {
        gpiopin = mod_gpiopin[pinnum-2][1];
    }
    gpio_getpin(gpiopin, value);
}


static void pad_mode_bak(unsigned int pinnum)
{
    unsigned int rd_tmp;
    unsigned int reg_num;
    unsigned int input_para_sum = 0;
    volatile unsigned int *reg_base = (volatile unsigned int *)ARTOSYN_PIN_SHARE_CFG;
    
    reg_num  = pinnum/3;
    
    pin_bak[pin_bak_inc].mul_reg   = phy_read(reg_base + reg_num);
}

static void pad_mode_gobak(unsigned int pinnum)
{
    unsigned int rd_tmp;
    unsigned int reg_num;
    unsigned int input_para_sum = 0;
    volatile unsigned int *reg_base = (volatile unsigned int *)ARTOSYN_PIN_SHARE_CFG;
    
    reg_num  = pinnum/3;
    phy_write(reg_base + reg_num,pin_bak[pin_bak_inc].mul_reg);
       
}

static void pin_direct_bak(unsigned int gpionum)
{
    struct gpio_st gpio;
    unsigned char offset;
    gpio_get_addr(gpionum, &gpio);
    
    switch(gpio.u8_regno) {
        case 0:
        offset = GPIO_DATA_DIRECT_A_OFFSET;
        break;
    
        case 1:
        offset = GPIO_DATA_DIRECT_B_OFFSET;
        break;
    
        case 2:
        offset = GPIO_DATA_DIRECT_C_OFFSET;
        break;
    
        case 3:
        offset = GPIO_DATA_DIRECT_D_OFFSET;
        break;
    }
    pin_bak[pin_bak_inc].dir_reg = phy_read(gpio.u32_gpio_addr+offset); 
}

static void pin_direct_gobak(unsigned int gpionum)
{
    struct gpio_st gpio;
    unsigned char offset;
    gpio_get_addr(gpionum, &gpio);

    switch(gpio.u8_regno) {
        case 0:
        offset = GPIO_DATA_DIRECT_A_OFFSET;
        break;

        case 1:
        offset = GPIO_DATA_DIRECT_B_OFFSET;
        break;

        case 2:
        offset = GPIO_DATA_DIRECT_C_OFFSET;
        break;

        case 3:
        offset = GPIO_DATA_DIRECT_D_OFFSET;
        break;
    }
    phy_write(gpio.u32_gpio_addr+offset,pin_bak[pin_bak_inc].dir_reg);
}

static void pin_ctrl_bak(unsigned int gpionum)
{
    struct gpio_st gpio;
    unsigned char offset;
    gpio_get_addr(gpionum, &gpio);
    switch(gpio.u8_regno) {
        case 0:
        offset = GPIO_CTRL_A_OFFSET;
        break;

        case 1:
        offset = GPIO_CTRL_B_OFFSET;
        break;

        case 2:
        offset = GPIO_CTRL_C_OFFSET;
        break;

        case 3:
        offset = GPIO_CTRL_D_OFFSET;
        break;
    }
    pin_bak[pin_bak_inc].ctrl_reg = phy_read(gpio.u32_gpio_addr+offset);
}

static void pin_ctrl_gobak(unsigned int gpionum)
{   
    struct gpio_st gpio;
    unsigned char offset;
    gpio_get_addr(gpionum, &gpio);
    switch(gpio.u8_regno) {
        case 0:
        offset = GPIO_CTRL_A_OFFSET;
        break;
        
        case 1:
        offset = GPIO_CTRL_B_OFFSET;
        break;
        
        case 2:
        offset = GPIO_CTRL_C_OFFSET;
        break;
        
        case 3:
        offset = GPIO_CTRL_D_OFFSET;
        break;
    }
    phy_write(gpio.u32_gpio_addr+offset,pin_bak[pin_bak_inc].ctrl_reg);
}

static void pin_set_bak(unsigned int gpionum)
{
        struct gpio_st gpio;
        unsigned char offset;
        gpio_get_addr(gpionum, &gpio);
        switch(gpio.u8_regno) {
                case 0:
                offset = GPIO_DATA_A_OFFSET;
                break;

                case 1:
                offset = GPIO_DATA_B_OFFSET;
                break;

                case 2:
                offset = GPIO_DATA_C_OFFSET;
                break;

                case 3:
                offset = GPIO_DATA_D_OFFSET;
                break;
        }
	pin_bak[pin_bak_inc].value_reg = phy_read(gpio.u32_gpio_addr+offset);
}

static void pin_set_gobak(unsigned int gpionum)
{       
        struct gpio_st gpio;
        unsigned char offset;
        gpio_get_addr(gpionum, &gpio);
        switch(gpio.u8_regno) {
                case 0:
                offset = GPIO_DATA_A_OFFSET;
                break;
                
                case 1:
                offset = GPIO_DATA_B_OFFSET;
                break;
                
                case 2:
                offset = GPIO_DATA_C_OFFSET;
                break;
                
                case 3:
                offset = GPIO_DATA_D_OFFSET;
                break;
        }
	phy_write(gpio.u32_gpio_addr+offset,pin_bak[pin_bak_inc].value_reg);
}

void ar_pin_state_bak(unsigned int pinnum)
{
    unsigned int gpiopin = 0;
    unsigned int pad_mode = 1;
    pin_bak[pin_bak_inc].pin = pinnum;
    pad_mode_bak(pinnum);
    if((pinnum >= 2)&&(pinnum <= 140)){
        if(pad_mode == mod_gpiopin[pinnum-2][0])
            gpiopin = mod_gpiopin[pinnum-2][1];
    }
    pin_direct_bak(gpiopin);
    pin_ctrl_bak(gpiopin);
    pin_set_bak(gpiopin);
    pin_bak_inc ++;
}

void ar_pin_state_gobak(void)
{      
	int i; 
	unsigned int pinnum;
        unsigned int gpiopin = 0;
	unsigned int pad_mode = 1;

	for(pin_bak_inc=pin_bak_inc-1;pin_bak_inc >=0; pin_bak_inc --)
	{
		pinnum = pin_bak[pin_bak_inc].pin;        
        	pad_mode_gobak(pinnum);
        	if((pinnum >= 2)&&(pinnum <= 140)){
            		if(pad_mode == mod_gpiopin[pinnum-2][0])
                	gpiopin = mod_gpiopin[pinnum-2][1];
        	}
        	pin_direct_gobak(gpiopin);
        	pin_ctrl_gobak(gpiopin);
        	pin_set_gobak(gpiopin);
	}
	pin_bak_inc = 0;
}

int find_pra_index_by_name(char *name,int argc, char *argv[])
{
    int i=0;
    for(i=0;i<argc;i++)
    {
        if(!strcmp(name,argv[i]))
        {
            return i;
        }
    }
    return -1;
}

static void * ipcam_audio_out_get_context(void **context, uint32_t *context_size)
{
    void *context_p = NULL;
    ar_facotry_element_obj_t ipcam_audio_init_list[] =
    {
        {"pipeline",{"pipeline_audio_out"},NULL},
        {"icc_proxy_rpc_src",{"audio_out"},NULL},
        {"aac_decoder","",NULL},
        {"i2s_sink",{""},NULL},
        {"tee",{""},NULL},
    };

    context_p = malloc(sizeof(ipcam_audio_init_list));
	if (context_p == NULL)
	{
		return NULL;
	}
    memcpy(context_p, ipcam_audio_init_list, sizeof(ipcam_audio_init_list));
    *context_size = sizeof(ipcam_audio_init_list)/sizeof(ar_facotry_element_obj_t);
    *context = context_p;
    return context_p;
}

static void * ipcam_audioin_get_context(void **context, uint32_t *context_size)
{   
    void *context_p = NULL;
    ar_facotry_element_obj_t ipcam_audio_init_list[] =
    {   
        {"pipeline",{"pipeline_audio_in"},NULL},
        {"icc_proxy_rpc_sink",{"audio_in"},NULL},
        {"aac_encoder","",NULL},
        {"i2s_src",{""},NULL},
    };
    
    context_p = malloc(sizeof(ipcam_audio_init_list));
    if (context_p == NULL)
    {       
        return NULL;
    }
    memcpy(context_p, ipcam_audio_init_list, sizeof(ipcam_audio_init_list));
    *context_size = sizeof(ipcam_audio_init_list)/sizeof(ar_facotry_element_obj_t);
    *context = context_p;
    return context_p;
}

int ipcam_audio_out_init(void)
{
    int i2s_id = 2;
    int audio_context_size = 0;
    ipcam_audio_out_context_t *audio_context = NULL;
    ar_mm_handle_t handle = NULL;
    int copy = 1;
    handle = ar_multimedia_core_device_open();
    if(!handle)
    {
	printf("%s, open multimedia core device failed.\r\n", __FUNCTION__);
	return -1;
    }

    audio_context = ipcam_audio_out_get_context((void**)(&audio_context), &audio_context_size);
    if (audio_context == NULL)
    {
    	printf("%s, ipcam_audio_out_get_context failed.\r\n", __FUNCTION__);
	ar_multimedia_core_device_close(handle);
	return -1;
    }

    if(ar_element_factory_make_many(handle, audio_context_size, audio_context) != AR_MULTIMEDIA_SUCCESS)
    {
	printf("Make element failed!\r\n");
	ar_multimedia_core_device_close(handle);
	free(audio_context);
	audio_context = NULL;
	return -1;
    }

    ar_element_modify_property_value(handle, audio_context->i2s_sink.element, AR_AUDIO_I2S_SET_ID, &i2s_id, sizeof(uint32_t));
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, audio_context->tee.element, 0),
								AR_COMMON_META_TEE_COPY_PROP,&copy,sizeof(unsigned int));

    ar_pipeline_add_many(handle, (ar_pipeline_t)audio_context->pipeline.element,audio_context->audio_out.element, 
                                  audio_context->tee.element, audio_context->i2s_sink.element, NULL);

    ar_pad_link_by_element(handle, audio_context->audio_out.element, 0, audio_context->tee.element, 0);
    ar_pad_link_by_element(handle, audio_context->tee.element, 0, audio_context->i2s_sink.element, 0);
    //ar_pad_link_by_element(handle, audio_context->aac_decoder.element, 0, audio_context->i2s_sink.element, 0);
    ar_element_set_state(handle, (ar_pipeline_t)audio_context->pipeline.element, AR_ELEMENT_STATE_READY);

    ar_multimedia_core_device_close(handle);


    return 0;
}

int ipcam_audio_in_init(void)
{
    int i2s_id = 2;
    int audio_context_size = 0;
    ipcam_audio_in_context_t *audio_context = NULL;
    ar_mm_handle_t handle = NULL;
    int i2s_devide_mode_on = 0;
    
    
    handle = ar_multimedia_core_device_open();
    if(!handle)
    {
    	printf("%s, open multimedia core device failed.\r\n", __FUNCTION__);
    	return -1;
    }

    audio_context = ipcam_audioin_get_context((void**)(&audio_context), &audio_context_size);
    if (audio_context == NULL)
    {
        printf("%s, ipcam_audio_in_get_context failed.\r\n", __FUNCTION__);
        ar_multimedia_core_device_close(handle);
        return -1;
    }

    if(ar_element_factory_make_many(handle, audio_context_size, audio_context) != AR_MULTIMEDIA_SUCCESS)
    {
        printf("Make element failed!\r\n");
        ar_multimedia_core_device_close(handle);
        free(audio_context);
        audio_context = NULL;
        return -1;
    }

    ar_element_modify_property_value(handle, audio_context->i2s_src.element, AR_AUDIO_I2S_SET_ID, &i2s_id, sizeof(uint32_t));
    ar_element_modify_property_value(handle, audio_context->i2s_src.element, AR_AUDIO_I2S_SET_DEVIDE_MODE_ON, &i2s_devide_mode_on, sizeof(uint32_t));

    ar_pipeline_add_many(handle, (ar_pipeline_t)audio_context->pipeline.element,audio_context->audio_in.element, 
                                  audio_context->i2s_src.element, NULL);

    ar_pad_link_by_element(handle, audio_context->i2s_src.element, 0, audio_context->audio_in.element, 0);
    ar_element_set_state(handle, (ar_pipeline_t)audio_context->pipeline.element, AR_ELEMENT_STATE_READY);

    ar_multimedia_core_device_close(handle);


    return 0;
}

int main(int argc, char *argv[])
{
    int i;
    int index;
    int ret;
    int fp,fp_ai,fp_ao;
    int data_len,curr_len,frame_len;
    unsigned int val;
    struct icc_proxy_rpc_to_linux_element_t *buffer_info = NULL;
    int data_size = 0;
    char *pbuf;
    FILE *stream;
    char buf[4096 * 1024];
    pthread_t thread_get_buf_0;

    index = find_pra_index_by_name("--help", argc, argv);
    if(index > 0)
    {
	printf("\n");
        printf("--detect                  : print sys mod ( normal / test ) , eg normal \n");
        printf("--gpio_in [gpio]          : print io level, eg --gpio_in d0_1 \n");
        printf("--gpio_out [gpio] [value] : output io level, eg --gpio_out d0_2 1 \n");
        printf("--usb                     : print usb enumeration information, eg  \n");
        printf("--wifi                    : print ping info\n");
        printf("--audio_in [fname]        : audio recorde, eg --audio_in ai_file.bin\n");
        printf("--audio_out [fname]       : audio playback, eg --audio_out ao_file.bin\n");
        printf("--tp                      : NULL\n");
        printf("--key                     : NULL \n");
        return 0;
    }

    index = find_pra_index_by_name("--detect",argc,argv);
    if(index>0)
    {
        
        ar_pin_state_bak(7);
        ar_pin_state_bak(59);
        
        ar_set_padmode_gpiopin(7,0,0xff,0xff,0xff);
        ar_set_padmode_gpiopin(59,1,0xff,0xff,0xff);
        
        ar_gpio_set_input(7);
        ar_gpio_getpin(7,(unsigned int *)(&val));
        if(val == 0)
        {
            ar_gpio_set_input(59);
            ar_gpio_getpin(59,(unsigned int *)(&val));
            if(val == 0)
                printf("test\n");
            else
                printf("normal\n");
        }
        else
            printf("normal\n");
        
        ar_pin_state_gobak();
    }
        
    index = find_pra_index_by_name("--gpio_in",argc,argv);
    if(index>0)
    {
        for(i = 0; i < (sizeof(test_pin)/sizeof(TEST_PIN)); i ++)
        {
            if(!strcmp(argv[index+1],test_pin[i].name))
            {
                ar_set_padmode_gpiopin(test_pin[i].id, test_pin[i].mode,0xff,0xff,0xff);
                
                ar_gpio_set_input(test_pin[i].id);
                ar_gpio_getpin(test_pin[i].id,(unsigned int *)(&val));
                
                printf("gpio test ---> name : %s mode : input level : %s\n",test_pin[i].name,val==1?"hig":"low");
            }
        }
        
    }
    
    index = find_pra_index_by_name("--gpio_out",argc,argv);
    if(index>0)
    {
        for(i = 0; i < (sizeof(test_pin)/sizeof(TEST_PIN)); i ++)
        {
            if(!strcmp(argv[index+1],test_pin[i].name))
            {
                ar_set_padmode_gpiopin(test_pin[i].id, test_pin[i].mode,0xff,0xff,0xff);
                
                ar_gpio_set_output(test_pin[i].id);
                ret = atoi(argv[index + 2]);
                ar_gpio_setpin(test_pin[i].id, ret);
                
                printf("gpio test ---> name : %s mode : output level : %s\n",test_pin[i].name,ret==1?"hig":"low");
            }
        }
    }
    
    index = find_pra_index_by_name("--usb",argc,argv);
    if(index>0)
    {
        ret = access("/sys/devices/platform/soc/60500000.dwc3/xhci-hcd.0.auto/usb1/1-1/1-1.1", 0);
        if(ret != -1)
            printf("usb1 detect ok\n");
        else
            printf("usb1 detect err\n");
            
        ret = access("/sys/devices/platform/soc/60500000.dwc3/xhci-hcd.0.auto/usb1/1-1/1-1.2", 0);
        if(ret != -1)
            printf("usb2 detect ok\n",ret);
        else
            printf("usb2 detect err\n",ret);
    }
    
    index = find_pra_index_by_name("--wifi",argc,argv);
    if(index>0)
    {

    	//step1
    	stream = popen( "/usrdata/usr/data/arstack/araccess/wifi/start_usbwifi.sh >> /dev/null 2>&1", "r" );
    	pclose( stream );
    	//step2
    	for(i = 0; i < 10; i++)
    	{
            memset(buf,0,sizeof(buf));
            stream = popen( "ifconfig | grep wlan0 | sed -n \"s/\ /\\n/gp\" | grep wlan0 | sed \"s/\\n//g\"", "r" );
            fread( buf, sizeof(char), sizeof(buf), stream);
            pclose( stream );
            if(!strcmp(buf,"wlan0\n"))
    			break;
    		usleep(500000);
    	}
        //step3
        memset(buf,0,sizeof(buf));
        stream = popen( "/usrdata/usr/data/arstack/araccess/wifi/iwlist wlan0 scanning | grep Artosyn-AP | sed -n \"s/\ /\\n/gp\" | grep Artosyn-AP", "r" );
        fread( buf, sizeof(char), sizeof(buf), stream);
        pclose( stream );
        printf("%s",buf);	
    }


    index = find_pra_index_by_name("--audio_in",argc,argv);
    if(index>0)
    {
	ipcam_audio_in_init();
	usleep(100000);

        fp_ai = icc_proxy_rpc_to_linux_open_dev("/dev/audio_in");
        printf("audio in file : %s\n",argv[index + 1]);
        fp = open(argv[index + 1],O_WRONLY|O_CREAT);
        if(!fp || fp_ai < 0)
        {
            printf("audio in test err : no file\n");
        }
        else
        {
            buffer_info = malloc(sizeof(struct icc_proxy_rpc_to_linux_element_t));
            while(1)
            {
                ret = icc_proxy_rpc_to_linux_acquire_buffer(fp_ai,buffer_info);
                if(ret)
                {
                    printf("audio in test err : malloc fail %d\n",ret);
                    break;
                }
                else
                {
                    data_len = buffer_info->mem_info[0].len;
                    pbuf = (void *)buffer_info->mem_info[0].map_addr;
                    data_size += data_len;
                    
                    if(data_size > 100 * 1024 * 1024)
                    {
                        printf("get data over !!\n");
                        fsync(fp);
                        close(fp);
                        break;                 
                    }
                    
                    ret = write(fp, pbuf, data_len);
                    if(ret <= 0)
                    {
                        icc_proxy_rpc_to_linux_release_buffer(fp_ai,buffer_info);
                        break; 
                        
                    }
                    ret = icc_proxy_rpc_to_linux_release_buffer(fp_ai,buffer_info);
                    if(ret)
                    {
                        printf("release buffer fail !!\n");   
                        break;
                    }
                } 
            }
        }  
    }

    index = find_pra_index_by_name("--audio_out",argc,argv);
    if(index>0)
    {
	ipcam_audio_out_init();
	usleep(100000);

        fp_ao = open("/dev/audio_out",O_RDWR);
        fp = open(argv[index + 1],O_RDONLY|O_CREAT);
        if(!fp || fp_ao < 0)
        {
            printf("audio out test err : no file\n");
        }
        else
        {
            if(icc_proxy_rpc_init(fp_ao, AUDIO_FRAME_LEN, 8))
            {
                printf("rpc init fail!!\n");
                close(fp_ao);
                close(fp);
            }
            else
            {
                while(1)
                {
                    ret = icc_proxy_rpc_acquire_buffer(fp_ao,&pbuf);
                    if(ret)
                    {
                        printf("audio out test err : malloc fail\n");
                    }
                    else
                    {
                        curr_len = read(fp,pbuf,AUDIO_FRAME_LEN);
                        
                        if(curr_len > 0)
                        {

                            icc_proxy_rpc_push_buffer(fp_ao, pbuf, curr_len);
                        }
                        else
                        {
                            break;   
                        }
                    } 
                }
            }
        }
    }
}


