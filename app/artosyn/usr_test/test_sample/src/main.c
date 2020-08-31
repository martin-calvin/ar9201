#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "ar_sample_test.h"
// input file name 
static const char* bin_file = "/mnt/h264_test_output.h264";
static const char* yuv_file = "/mnt/yuv420_1920.bin";
static const char* devmem = "/dev/mem";
#define PAGE_SIZE 4096UL
#define MAP_MASK (PAGE_SIZE - 1)

static int load_yuv(int mem_fd, unsigned int paddr)
{
	void *yuv_base, *yuv_vaddr;
	unsigned int len_size, load_cnt;
	int yuv_fd = 0;
	/* two 1920x1080 picture */
	len_size = ((1920*1080*3 + 4095)/4096 * 4096);
	printf("load yuv: paddr = 0x%x len_round = %u.\n",
		paddr, len_size);
	yuv_base = mmap(0, len_size, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, paddr & ~MAP_MASK);
	if (yuv_base == (void *)-1) {
		printf("memory map error %p\n", yuv_base);
		return -1;
	}
	yuv_vaddr = yuv_base + (paddr & MAP_MASK);
	printf("memory map base addr %p, vaddr %p\n",
		yuv_base, yuv_vaddr);
	yuv_fd = open(yuv_file, O_RDWR);
	if (yuv_fd == -1) {
		printf("open yuv file error\n");
		munmap(yuv_base, len_size);
		return -1;
	}
	load_cnt = read(yuv_fd, yuv_vaddr, len_size);
	
	printf("load yuv file length %u byte %u y = 0x%x u = 0x%x v = 0x%x\n",
		load_cnt, len_size, *(unsigned int *)(yuv_vaddr+640),
		*(unsigned int *)(yuv_vaddr+1280*768+320),
		*(unsigned int *)(yuv_vaddr+1280*768*5/4+320));
	fsync(yuv_fd);
	munmap(yuv_base, len_size);
	close(yuv_fd);
	return 0;
}

static int dump_bitstream(int mem_fd, unsigned int paddr, unsigned int length)
{
	void *map_base, *virt_addr;
	unsigned int len_round = 0;
	int bin_fd, i = 0, count;
	unsigned char *wr_ptr;
	/* dump bitstream from mem */
	len_round = ((length*4 + 4095)/4096 * 4096);
	printf("dump bitstream paddr = 0x%x len = %u len_round = %u.\n",
		paddr, length, len_round);
	map_base = mmap(0, len_round, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, paddr & ~MAP_MASK);
	if (map_base == (void *)-1) {
		printf("memory map error %p\n", map_base);
		return -1;
	}
	virt_addr = map_base + (paddr & MAP_MASK);
	printf("memory map base addr %p, vaddr %p\n",
		map_base, virt_addr);
	bin_fd = open(bin_file, O_RDWR | O_CREAT);
    	if(bin_fd == -1) {
      		printf("open output file %d failed.\n", bin_fd);
		if(munmap(map_base, len_round) == -1)
			printf("umap error.\n");
       		return -1;
	}
	wr_ptr = (unsigned char *)virt_addr;
	printf("test first u32 = 0x%x.\n",
		*(wr_ptr+3)|*(wr_ptr+2)|*(wr_ptr+1)|*wr_ptr);
	for (i = 0; i < length; i += 4) {
		count = 0;
		count += write(bin_fd, (wr_ptr+i+3), 1);
		count += write(bin_fd, (wr_ptr+i+2), 1);
		count += write(bin_fd, (wr_ptr+i+1), 1);
		count += write(bin_fd, (wr_ptr+i), 1);
		if (count < 4)
			printf("error dump bitstream %u to file < %u\n",
				(count+ i*4), length);
	}
	fsync(bin_fd);
	munmap(map_base, length);
	close(bin_fd);
	return 0;
} 
int main (int argc, char *argv[]){
	unsigned int len = 0,  cmd = 0;
	int mem_fd = 0;
	off_t target;

	mem_fd = open(devmem,  O_RDWR | O_SYNC);
    	if(mem_fd == -1) {
      		printf("open output file %d failed.\n", mem_fd);
       		return -1;
    	}
	/* 1: load yuv file 2: dump bitstream*/	
	cmd = strtoul(argv[1], 0, 0);
	target = strtoul(argv[2], 0, 0);
	len = strtoul(argv[3], NULL, 10);
	if (cmd == 1)
		load_yuv(mem_fd, target);
	else if (cmd == 2)
		dump_bitstream(mem_fd, target, len);
	close(mem_fd);

	return 0;
}
#if 0
int main() 
{ 
    int fd, num; 

    ar_sample_test();

    // Open device
    fd = open("/dev/sample_device", O_RDWR, S_IRUSR | S_IWUSR); 
    if (fd != -1 ) 
    { 
        // Read global_var 
        read(fd, &num, sizeof(int)); 
        printf("The globalvar is %d\n", num); 
 
        // Write global_var 
        printf("Please input the num written to globalvar\n"); 
        scanf("%d", &num); 
        write(fd, &num, sizeof(int)); 
 
        // Read global_var again
        read(fd, &num, sizeof(int)); 
        printf("The globalvar is %d\n", num); 
 
        // Close device
        close(fd); 
    } 
    else 
    { 
        printf("Device open failure\n"); 
    }

    return 0;
}
#endif
