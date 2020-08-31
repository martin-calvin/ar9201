#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <getopt.h>             /* getopt_long() */
#include <fcntl.h>              /* low-level i/o */
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <stdint.h>

#define PAGE_SIZE 4096

#define GET_PAGE_COUNT(size) (size/4096+2)


static int check_data(char *number)
{
   if(number[0]=='0'&&(number[1]=='x'||number[1]=='X'))
   {
        return 16;
   }else
   {
       return 10;
   }
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
int main(int argc, char **argv)
{
    char name[64];
	FILE *fd=NULL;
	int fd_mm;
	void *addr=NULL;
	uint32_t phy_addr=0;
	uint32_t len=0;
	uint32_t add_offset=0;
	int page_num=0;
	uint32_t start =0;
	uint32_t offset=0;
	int ret=0;
    if(argc <5)
    {
       printf("err,less pra, eg: dump_mem file_name.bin address offset size\n");
	   return -1;
    }
	sprintf(name,"/mnt/%s",argv[1]);
	phy_addr=strtoul(argv[2],NULL,check_data(argv[2]));
	add_offset=strtoul(argv[3],NULL,check_data(argv[3]));
	len=strtoul(argv[4],NULL,check_data(argv[4]));

	printf("dump_mem: %s 0x%x 0x%x 0x%x......\n",name,phy_addr,add_offset,len);

    phy_addr+=add_offset;

    fd= fopen(name, "ab");
	if(!fd){
		printf("err open file %s \n",name);
		return -1;
	}
	fd_mm = open("/dev/mem", O_RDWR | O_SYNC);
    if(fd_mm<0)
	{
	   printf("err open dev/mem \n");
	   fclose(fd);
	   return -1;
	}
	start=phy_addr & ~(PAGE_SIZE-1);
	offset=phy_addr-start;
	page_num=GET_PAGE_COUNT(len);
	addr = mmap(NULL, page_num*PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,fd_mm,start);
    if(addr==NULL)
    {
       printf("err map addr 0x%x",phy_addr);
	   fclose(fd);
	   close(fd_mm);
	   return -1;
    }
    ret = fwrite((void *)((uint32_t)addr+offset), 4, len>>2, fd);
	if(ret<=0)
	{
	   printf("write file err\n");
	}else
	{
	   printf("success dump ok !!!!\n");
	}

	if(argc==6)
	{
       if(strcmp("--regISP",argv[5])==0)
       {
            int i=0;
            uint32_t *p_addr=(uint32_t *)((uint32_t)addr+offset);
            for(i=0;i<len/4;i++)
            {
               printf("`WRITE_APB(`32'h%08x, 32'h%08x);\n",phy_addr+4*i, p_addr[i]);
            }
       }
	   else if(strcmp("--reg",argv[5])==0)
	   {
	        int i=0;
			uint32_t *p_addr=(uint32_t *)((uint32_t)addr+offset);
            for(i=0;i<len/4;i++)
            {
               printf("0x%08x\n",p_addr[i]);
            }
	   }
	}
	munmap(addr, len);
	fclose(fd);
	close(fd_mm);
	return 0;
}
