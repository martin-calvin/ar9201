#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <assert.h>
#include "ion.h"
#include "ar_ion.h"
#include "ar_axi_dma.h"

#define AR_SYSTEM_HEAP_ID  (27)

#define AR_GET_ION_MEMORY_0(VA, PA, SIZE) \
do{ \
		VA = (unsigned char *)ar_ion_malloc(SIZE); \
		if(!VA) \
		{ \
			printf("%s %d: Malloc memory failed, exit!\r\n", __FUNCTION__, __LINE__); \
			goto _free_and_exit; \
		} \
		PA = (unsigned char *)ar_ion_virt_to_phy(VA); \
		if(!PA) \
		{ \
			printf("%s %d: Virt to phy failed, exit!\r\n", __FUNCTION__, __LINE__); \
			goto _free_and_exit; \
		} \
		memset(VA, 0, SIZE); \
}while(0)



#define AR_GET_ION_MEMORY(VA, PA, SIZE) \
do{ \
		VA = (unsigned char *)ar_ion_malloc_ex(SIZE, 1); \
		if(!VA) \
		{ \
			printf("%s %d: Malloc memory failed, exit!\r\n", __FUNCTION__, __LINE__); \
			goto _free_and_exit; \
		} \
		PA = (unsigned char *)ar_ion_virt_to_phy(VA); \
		if(!PA) \
		{ \
			printf("%s %d: Virt to phy failed, exit!\r\n", __FUNCTION__, __LINE__); \
			goto _free_and_exit; \
		} \
		memset(VA, 0, SIZE); \
}while(0)


static int get_time_ms()
{
	struct timeval tv;
	gettimeofday (&tv , NULL);

	return (tv.tv_sec*1000+tv.tv_usec/1000);
}

static void usage() 
{
	printf("usage: test_axi_dma  memsize count\n");
	printf("       count =0 means infinity\n");
	printf("eg: test_axi_dma 0x100000 10\n");
}

int main(int argc, char *argv[])
{
	unsigned int loop = 0, errCnt=0; 
	unsigned int idx;

	volatile unsigned int src_pa, dst_pa;
	volatile unsigned char *src_va, *dst_va;

	unsigned int size = 10*1024*1024;  //default test memory size
	unsigned int count = 1 ; //default test count, 0 means infinity

	if(argc == 3) {
		size = strtoul(argv[1], NULL, 0);
		if(size==0) {
			usage();
			return -1;
		}
		count = strtoul(argv[2], NULL, 0);
		printf("Test memsize:%08x count:%d\n", size, count);
	} else if(argc == 1) {
		printf("Use the default test memsize:%08x count:%d\n", size, count);
	} else {
	 	usage();
		return -1;
	}

	printf("Before test, need to set freertos axi dma write/read to Noncache mode in ch_ctl_l[26:29] and [22:25] to 0x0.... \n");

	ar_ion_init(AR_SYSTEM_HEAP_ID);

	//Get Noncache buffer
	AR_GET_ION_MEMORY(src_va, src_pa, size);
	//Get cache buffer
	AR_GET_ION_MEMORY(dst_va, dst_pa, size);

	printf("dst dst_pa src_pa 0x%x 0x%x\n", src_pa, dst_pa);

	if (src_va == NULL || dst_va == NULL) {
		fprintf(stderr, "src_va=%p dst_va=%p", src_va, dst_va);
		goto out;
	}

	int fd = ar_axi_dma_open();

	unsigned int start, stop;
	tran_inf transfer = {0};

	srandom(get_time_ms());
	unsigned char key = random();

	while (loop++ < count || count == 0)
	{
		transfer.tran_cnt_sum = 1;
		transfer.addr_size[0].dst_pa = dst_pa;
		transfer.addr_size[0].src_pa = src_pa;
		transfer.addr_size[0].size   = size;

		for (idx = 0; idx < size; idx++) {
			src_va[idx] = (key + idx);
		}
		key += 1;	
		
		ar_ion_cache_flush_by_range(src_va, src_va, size);		
		ar_ion_cache_invalid_by_range(dst_va, dst_va, size);

		//printf("axi dma copy start fd=%d time:%d ms\n", start);
		printf("axi dma copy start from:(%p,0x%lx) to:(%p,0x%lx) size = 0x%x\n", \
				src_va, transfer.addr_size[0].src_pa, \
				dst_va, transfer.addr_size[0].dst_pa, size);
		start = get_time_ms();
		int rc = ar_axi_dma_transfer(fd, &transfer);
		if (rc < 0) {
			fprintf(stderr, "ar_axi_dma_transfer rc = %d loop:%d\n", rc, loop);
			errCnt++;
			continue;
		}

		stop = get_time_ms();
		if(stop != start) {
			printf("axi dma copy time: %d ms throughput=%d KBps\n", stop-start, size/(stop-start));
		} else {
			printf("axi dma copy time: %d ms throughput = unknown\n", stop-start);
		}
		

		ar_ion_cache_invalid_by_range(dst_va, dst_va, size);
		if(memcmp(src_va, dst_va, size) != 0) {
			fprintf(stderr, "src and dst content differ\n");
			errCnt++;
		}
		
		for (idx = 0; idx < 10 && idx < size; idx++) {
			if(size>=10+4096)
				printf("0x%x 0x%x\n", dst_va[idx], dst_va[idx+4096]);
			else
				printf("0x%x 0x%x\n", dst_va[idx], dst_va[size-idx-1]);
		}

		printf("test loop:%d key:0x%x\n", loop, key-1);
	}

	printf("total test: %d  error times:%d\n", loop-1, errCnt);
	return 0;

_free_and_exit:
out:
	return -1;
}

