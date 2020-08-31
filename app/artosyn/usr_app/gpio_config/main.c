#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>

#define FILE_NAME_SIZE          4096

#define TOTAL_GPIO_NUM          (139)
#define PIN_SHARE_GLOBAL_REG    (0x60633000)
#define GPIO_BASE_ADDR          (0x40400000)
#define GPIO_GROUP_OFFSET       (0x00020000)
#define GPIO_PORT_OFFSET        (0xc)
#define GPIO_DIR_OFFSET         (0x4)
#define GPIO_DATA_OFFSET        (0x0)
#define GPIO_HIGH               (1)
#define GPIO_LOW                (0)
#define GPIO_OUT_FLAG           (1)
#define GPIO_IN_FLAG            (0)
#define GPIO_OUT_STR            ("output")
#define GPIO_IN_STR             ("input")


static int pad_mode_gpio_array[TOTAL_GPIO_NUM][2] =
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

 static unsigned int read_reg(unsigned int reg_addr)
 {
	 unsigned int fd_mem, reg_read_data;
	 unsigned char *reg_read_addr, *map_address;

	 fd_mem=open("/dev/mem", O_RDWR | O_SYNC);
	 if(fd_mem < 0){
		 printf("open /dev/mem fail line:%d\n", __LINE__);
		 return;
	 }
	 map_address =	mmap(NULL, FILE_NAME_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd_mem, reg_addr&(~(FILE_NAME_SIZE - 1)));
	 reg_read_addr = map_address+(reg_addr & (FILE_NAME_SIZE - 1));
	 reg_read_data = *(unsigned int *)reg_read_addr;
	 munmap(map_address, FILE_NAME_SIZE);
	 close(fd_mem);
	 return reg_read_data;
 }

 static void write_reg(unsigned int reg_data, unsigned int reg_addr)
 {
	 unsigned int fd_mem;
	 unsigned char *reg_write_addr, *map_address;

	 fd_mem=open("/dev/mem", O_RDWR | O_SYNC);
	 if(fd_mem < 0){
		 printf("open /dev/mem fail line:%d\n", __LINE__);
		 return;
	 }
	 map_address =	mmap(NULL, FILE_NAME_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd_mem, reg_addr&(~(FILE_NAME_SIZE - 1)));
	 reg_write_addr = map_address+(reg_addr & (FILE_NAME_SIZE - 1));
	 *(unsigned int *)reg_write_addr = reg_data;
	 munmap(map_address, FILE_NAME_SIZE);
	 close(fd_mem);
 }


 static int find_pra_index_by_name(char *name,int argc, char *argv[])
 {
	 int i=0;
	 for(i=0;i<argc;i++)
	 {
		  if(!strcmp(name,argv[i]))
		  {
			  return i;
		  }
	 }
	 return 0;
 }

static int gpio_config_name_to_num(char* arg)
{
	int gpio_num;

	if(strlen(arg) != 4)
	{
		goto failure;
	}
	if(arg[0] < 'A' || arg[0] > 'D')
	{
		goto failure;
	}
	if(arg[1] < '0' || arg[1] > '4')
	{
		goto failure;
	}
	if(arg[2] != '_')
	{
		goto failure;
	}
	if(arg[3] < '0' || arg[3] > '7')
	{
		goto failure;
	}

	gpio_num = 32 * (arg[1] - '0') + 8 * (arg[0] - 'A') + (arg[3] - '0');

	printf("gpio num of %s is %d\n", arg, gpio_num);
	return gpio_num;

failure:
	printf("gpio group num not right!\n");
	printf("Xm_n : ('A'<=X<='D', 0<=m<=4, 0<=n<=7)!\n");
	return -1;
}

static int gpio_config_judge(int gpio_num)
{
	int pad_num;
	int pad_mode_from_array;
	int pad_mode_from_reg;
	int reg_base = PIN_SHARE_GLOBAL_REG;
	int reg_num, reg_part;
	unsigned int dir_reg_addr;
	int i;
	for(i = 0; i < TOTAL_GPIO_NUM; i++)
	{
		if(pad_mode_gpio_array[i][1] == gpio_num)
		{
			pad_num = i + 2;
			pad_mode_from_array = pad_mode_gpio_array[i][0];
			break;
		}
	}

	reg_num  = pad_num / 3;
	reg_part = pad_num % 3;
	dir_reg_addr = reg_base + 4 * reg_num;
	pad_mode_from_reg = (read_reg(dir_reg_addr) & (0x7 << (reg_part * 10))) >> (reg_part * 10);

	if(pad_mode_from_array != pad_mode_from_reg)
	{
		printf("pad_num %d is not set as gpio %d\n", pad_num, gpio_num);
		return -1;
	}

	return 0;
}
static void gpio_config_check_state(int argc, char* argv[])
{
	int gpio_num;
	int groupno;
	int portno;
	int gpiono;
	unsigned int dir_reg_addr;
	unsigned int data_reg_addr;
	volatile unsigned int direction;
	volatile unsigned int level;
	const char* high = "high";
	const char* low = "low";

	int index = find_pra_index_by_name("-c",argc,argv);
	gpio_num = gpio_config_name_to_num(argv[index+1]);
	if(gpio_num < 0)
	{
		return;
	}
	if(gpio_config_judge(gpio_num) < 0)
	{
		return;
	}

	groupno = gpio_num / 32;
	portno = gpio_num % 32 / 8;
	gpiono = gpio_num % 32 % 8;

	dir_reg_addr = GPIO_BASE_ADDR + groupno * GPIO_GROUP_OFFSET + portno * GPIO_PORT_OFFSET + GPIO_DIR_OFFSET;
	direction = (read_reg(dir_reg_addr) & (1 << gpiono)) >> gpiono;
	if(direction == GPIO_IN_FLAG)
	{
		printf("gpio %d is set as input\n", gpio_num);
		return;
	}
	else
	{
		data_reg_addr = GPIO_BASE_ADDR + groupno * GPIO_GROUP_OFFSET + portno * GPIO_PORT_OFFSET + GPIO_DATA_OFFSET;
		level = (read_reg(data_reg_addr) & (1 << gpiono)) >> gpiono;
		printf("gpio %d is set as output, level is %s\n", gpio_num, level ? high : low );
		return;
	}


}

static void gpio_config_export(int argc, char* argv[])
{
	int gpio_num;
	int index = find_pra_index_by_name("-e",argc,argv);
	gpio_num = gpio_config_name_to_num(argv[index+1]);

	if(gpio_num < 0)
	{
		return;
	}
	if(gpio_config_judge(gpio_num) < 0)
	{
		return;
	}
	if(gpio_export(gpio_num) < 0)
	{
		return;
	}
	printf("gpio %d export success\n", gpio_num);

}


static void gpio_config_unexport(int argc, char* argv[])
{
	int gpio_num;
	int index = find_pra_index_by_name("-u",argc,argv);
	gpio_num = gpio_config_name_to_num(argv[index+1]);
	if(gpio_num < 0)
	{
		return;
	}
	if(gpio_config_judge(gpio_num) < 0)
	{
		return;
	}
	if(gpio_unexport(gpio_num) < 0)
	{
		printf("gpio %d has not been exported\n", gpio_num);
		return;
	}
	printf("gpio %d unexport success\n", gpio_num);
}

static int gpio_config_set_dir(int gpio_num, char* arg)
{
	if(!strcmp(arg, GPIO_OUT_STR))
	{
		if(gpio_set_dir(gpio_num, GPIO_OUT_FLAG) < 0)
		{
			printf("please export gpio %d first\n", gpio_num);
			return -1;
		}
		printf("gpio %d set as output\n", gpio_num);
		return 0;
	}
	if(!strcmp(arg, GPIO_IN_STR))
	{
		if(gpio_set_dir(gpio_num, GPIO_IN_FLAG) < 0)
		{
			printf("please export gpio %d first\n", gpio_num);
			return -1;
		}
		printf("gpio %d set as input\n", gpio_num);
		return 0;
	}

	printf("direction commond not right! use output/input to config\n");
	return -1;
}

static int gpio_config_set_level(int gpio_num, char* arg)
{
	int groupno = gpio_num / 32;
	int portno = gpio_num % 32 / 8;
	int gpiono = gpio_num % 32 % 8;
	int value;
	unsigned int dir_reg_addr;

	dir_reg_addr = GPIO_BASE_ADDR + groupno * GPIO_GROUP_OFFSET + portno * GPIO_PORT_OFFSET + GPIO_DIR_OFFSET;
	if((read_reg(dir_reg_addr) & (1 << gpiono)) >> gpiono == GPIO_IN_FLAG)
	{
		printf("gpio %d is set as input, cannot set level!\n", gpio_num);
		return -1;
	}

	if(!strcmp(arg, "high"))
	{
		if(gpio_set_value(gpio_num, GPIO_HIGH) < 0)
		{
			printf("please export gpio %d first\n", gpio_num);
			return -1;
		}
		printf("gpio %d set to high level\n", gpio_num);
		return 0;
	}
	else if(!strcmp(arg, "low"))
	{
		if(gpio_set_value(gpio_num, GPIO_LOW) < 0)
		{
			printf("please export gpio %d first\n", gpio_num);
			return -1;
		}
		printf("gpio %d set to low level\n", gpio_num);
		return 0;
	}
	else
	{
		printf("level commond not right! use high/low to config\n");
		return -1;
	}

}

static void gpio_config_set(int argc, char* argv[])
{
	int gpio_num;
	int dir_or_level_has_set = 0;
	int index = find_pra_index_by_name("-s",argc,argv);
	gpio_num = gpio_config_name_to_num(argv[index+1]);
	if(gpio_num < 0)
	{
		return;
	}
	if(gpio_config_judge(gpio_num) < 0)
	{
		return;
	}
	index = find_pra_index_by_name("-d",argc,argv);
	if(index > 0)
	{
		if(gpio_config_set_dir(gpio_num, argv[index+1]) < 0)
		{
			return;
		}
		dir_or_level_has_set = 1;
	}

	index = find_pra_index_by_name("-l",argc,argv);
	if(index > 0)
	{
		if(gpio_config_set_level(gpio_num, argv[index+1]) < 0)
		{
			return;
		}
		dir_or_level_has_set = 1;
	}

	if(!dir_or_level_has_set)
	{
		printf("please use -d or -l to set direction or level\n");
	}
}

static void gpio_config_help(const char *argv0)
{
	printf("*--------------------------------------------------*\n");
	printf(" gpio config usage: %s\n", argv0);
	printf(" check gpio state : gpio_config -c [Xm_n]\n");
	printf(" export gpio      : gpio_config -e [Xm_n]\n");
	printf(" unexport gpio    : gpio_config -u [Xm_n]\n");
	printf(" set gpio         : gpio_config -s [Xm_n] -d [output/input] (-l [high/low])\n");
	printf(" example1:export GPIO_A0_1\n");
	printf("         :gpio_config -e A0_1\n");
	printf(" example2:set GPIO_A0_1 output, high level\n");
	printf("         :gpio_config -s A0_1 -d output -l high\n");
	printf(" example3:unexport GPIO_A0_1\n");
	printf("         :gpio_config -u A0_1\n");
	printf("*--------------------------------------------------*\n");
}

int main (int argc, char *argv[])
{
	int gpio_num;
	int index;


	index = find_pra_index_by_name("-c",argc,argv);
	if(index>0)
	{
		gpio_config_check_state(argc,argv);
		return 0;
	}

	index = find_pra_index_by_name("-e",argc,argv);
	if(index>0)
	{
		gpio_config_export(argc,argv);
		return 0;
	}

	index = find_pra_index_by_name("-u",argc,argv);
	if(index>0)
	{
		gpio_config_unexport(argc,argv);
		return 0;
	}

	index = find_pra_index_by_name("-s",argc,argv);
	if(index>0)
	{
		gpio_config_set(argc,argv);
		return 0;
	}

	index= find_pra_index_by_name("-h",argc,argv);
	if(index>0)
	{
		gpio_config_help(argv[0]);
		return 0;
	}
	else
	{
		printf("command wrong!\n");
		gpio_config_help(argv[0]);
	}

	return 0;
}


