#include "ion.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define DEV_PATH "/dev/ion"
/* Heap 21 */
#define HEAP_MASK    (1 << 21)
#define LENTH        (0x100000)
#define PROT         (PROT_READ | PROT_WRITE)
#define MAP_FLAGS    (MAP_SHARED)
int main()
{
	int fd, ret;
	int fd_map;
	int i;
	int pa;
	int va;
	int length;
	ion_user_handle_t handle;
	unsigned char *ptr = 0;

	fd = ion_open();
	if(fd < 0) {
		printf("open %s fail\n", "ion");
		return 0;
	}

	ret = ion_alloc(fd, LENTH, 0x1000, HEAP_MASK, 0, &handle);
	if(ret < 0) {
		printf("alloc %s fail\n", "ion");
		return 0;
	}

	ret = ion_map(fd, handle, LENTH, PROT, MAP_FLAGS, 0, &ptr, &fd_map);
	if(ret < 0) {
		printf("map %s fail\n", "ion");
		return 0;
	}

	printf("map fd=%d, va=0x%lx\n", fd_map, (unsigned long)ptr);

	for(i = 0; i < 0x1000; i++) {
		printf("%02x ", *(ptr + i));
		if((i + 1) % 16 ==0)
			printf("\n");
	}

	memset(ptr, 'B', 0x1000);

	for(i = 0; i < 0x1000; i++) {
		printf("%02x ", *(ptr + i));
		if((i + 1) % 16 ==0)
			printf("\n");
	}
	printf("\n");
	printf("\n");

	ret = ion_query_buffer_handle(fd, handle, &va, &pa, &length);
	if(ret < 0) {
		printf("get pa %s fail\n", "ion");
		return 0;
	}
	printf("va=%x, pa=%x, length=%x\n", va, pa, length);

	ret = ion_va2pa(fd, handle, (int)ptr, (int)ptr + 0x100, &pa);
	if(ret < 0) {
		printf("get pa %s fail\n", "ion");
		return 0;
	}
	printf("va=%x, pa=%x\n", (int)ptr + 0x100, pa);

	munmap(ptr, LENTH);
	close(fd_map);
	ion_free(fd, handle);
	close(fd);

	return 0;
}


