/*************************************************
* Artosyn Co.,ltd.
* Boot up one A7, one M7 and 4 CEVA in AMP way
**************************************************/
#define _GNU_SOURCE

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <pthread.h>
#include <sched.h>
#include <signal.h>
#include "cJSON.h"
#include "boot_assist.h"
#include "ar_adc.h"

#define DMA_PA_SAVE_PATH	"/tmp/dma_pa.config"

struct img_header
{
	uint32_t magic;
	uint32_t version;
	uint32_t image_type;
	uint32_t spl_addr;
	uint32_t spl_len;
	uint32_t troot_fw_addr;
	uint32_t troot_fw_len;
	uint32_t sig_addr;
	uint32_t sig_len;
	uint32_t checksum;
	uint32_t reserved[6];
} __attribute__((packed));

typedef struct
{
  int argc;
  char **argv;
}boot_assist_t;

static int timeout = 0;

void timer_func(void)
{
	timeout = 1;
}

int boot_checksum(int cs, unsigned char *img, unsigned int size)
{
	int cs_calc = 0;
	int i = 0;

	while(i < size)
		cs_calc += img[i++];

	if(cs_calc == cs)
		return 0;
	return -1;
}

int boot_start_a7(unsigned int entry)
{
	int fd, map_size = 0x1000;
	int timeout = 0;
	unsigned int status;
	void *a7_cfg_base = NULL;
	void *gic_dist_base = NULL;

	fd = open("/dev/mem", O_RDWR | O_SYNC);
	if (fd < 0) {
		printf("Open /dev/mem fail\n");
		return -1;
	}

	a7_cfg_base = mmap(NULL, map_size,
			PROT_READ | PROT_WRITE, MAP_SHARED,
			fd, A7_CONFIG_BASE);
	if (a7_cfg_base == -1) {
		printf("Map config register space failed.\n");
		goto error_mmap_a7;
	}

	/* save entry to register */
	*(volatile unsigned int *)(a7_cfg_base + A7_SECONDARY_ENTRY_REG) = entry;

	/*clear boot up flag*/
	*(volatile unsigned int *)(a7_cfg_base + A7_BOOT_STATUS_REG) = 0;

	gic_dist_base = mmap(NULL, map_size,
		PROT_READ | PROT_WRITE, MAP_SHARED,
		fd, GIC_DIST_BASE);
	if (gic_dist_base == -1) {
		printf("Map GIC register space failed.\n");
		goto error_mmap_gic;
	}

	/* trigger SGI #0 for CPU #3 */
	*(volatile unsigned int *)(gic_dist_base + GIC_DIST_SGI_REG) = (0x8 << 16 | A7_SGI_BOOT_UP);

	signal(SIGALRM, timer_func);

	alarm(TIMEOUT_MAX);

	/* wait for boot up */
	do {
		status = *(volatile unsigned int *)(a7_cfg_base + A7_BOOT_STATUS_REG);
		if (status != 0) {
			break;
		}
	} while(!timeout);

	munmap(a7_cfg_base, map_size);
	munmap(gic_dist_base, map_size);

	if(status != 0) {
		printf("Boot success\n");
		save_pa_2_file(status);
	}
	else {
		printf("Boot fail\n");
	}

	return 0;

error_mmap_gic:
	munmap(a7_cfg_base, map_size);
error_mmap_a7:
	close(fd);
	return -1;
}

int boot_load_img(boot_assist_t *boot, unsigned char **a7_va_adr, uint32_t *a7_pa_adr)
{
	int fd0, fd1, ret;
	void *img;
	size_t size;
	struct img_header hdr;
	unsigned char * buf;

	fd0 = open(boot->argv[1], O_RDONLY);
	if(fd0 < 0) {
		printf("open %s fail\n", boot->argv[1]);
		return -1;
	}

	ret = read(fd0, &hdr, sizeof(hdr));
	if(ret < 0) {
		printf("read header fail\n");
		goto error_read_header;
	}

	if(hdr.magic != BOOT_UP_MAGIC) {
		return -1;
	}

	size = (hdr.spl_len + ALIGNMENT_SIZE - 1) & ~(ALIGNMENT_SIZE - 1);

	fd1 = open("/dev/mem", O_RDWR | O_SYNC);
	if (fd1 < 0) {
		printf("Open /dev/mem fail\n");
		goto error_read_header;
	}

	img = mmap(NULL, size,
			PROT_READ | PROT_WRITE,
			MAP_SHARED,
			fd1, hdr.spl_addr);

	if(img == -1) {
		printf("Mmap phy addr %x fail\n", hdr.spl_addr);
		return -1;
	}

	buf = (unsigned char *)malloc(hdr.spl_len);
	if(NULL == buf){
		printf("Buff malloc fail\n");
		return -1;
	}

	ret = read(fd0, buf, hdr.spl_len);
	if(ret < 0) {
		printf("Read img fail\n");
		free(buf);
        	buf = NULL;
		return -1;
	}

	ret = boot_checksum(hdr.checksum, buf, hdr.spl_len);
	if(ret < 0) {
		printf("Checksum img fail\n");
		free(buf);
		buf = NULL;
		return -1;
	}

	memcpy(img, buf, hdr.spl_len);
	free(buf);
	buf = NULL;

	*a7_va_adr  = img;
	*a7_pa_adr  = hdr.spl_addr;

	close(fd0);
	close(fd1);
	return 0;

error_mmap:
	close(fd1);
error_read_header:
	close(fd0);
	return -1;
}


char* read_file(const char *filename) {
    FILE *file = NULL;
    long length = 0;
    char *content = NULL;
    size_t read_chars = 0;

    /* open in read binary mode */
    file = fopen(filename, "rb");
    if (file == NULL)
    {
        goto cleanup;
    }

    /* get the length */
    if (fseek(file, 0, SEEK_END) != 0)
    {
        goto cleanup;
    }
    length = ftell(file);
    if (length < 0)
    {
        goto cleanup;
    }
    if (fseek(file, 0, SEEK_SET) != 0)
    {
        goto cleanup;
    }

    /* allocate content buffer */
    content = (char*)malloc((size_t)length + sizeof(""));
    if (content == NULL)
    {
        goto cleanup;
    }

    /* read the file into memory */
    read_chars = fread(content, sizeof(char), (size_t)length, file);
    if ((long)read_chars != length)
    {
        free(content);
        content = NULL;
        goto cleanup;
    }
    content[read_chars] = '\0';


cleanup:
    if (file != NULL)
    {
        fclose(file);
    }

    return content;
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

int save_pa_2_file(unsigned int dma_pa)
{
	FILE * fp = NULL;
	int ret = -1;
	fp = fopen(DMA_PA_SAVE_PATH, "wb");
	if(NULL == fp)
	{
		printf("create %s file failed!\n", DMA_PA_SAVE_PATH);
		return -1;
	}
	ret = fwrite(&dma_pa, sizeof(dma_pa), 1, fp);
	if(1 != ret)
	{
		printf("wrtie %s file failed!\n", DMA_PA_SAVE_PATH);
                return ret;
	}

	ret = fclose(fp);
	if(0 != ret)
	{
		printf("close %s file failed!\n", DMA_PA_SAVE_PATH);
                return ret;
	}

	return 0;
}

int boot_set_boot_args(boot_args * args, boot_assist_t *boot, uint32_t dtb_pa)
{
	void *malloc_va = NULL;
	unsigned int malloc_pa = 0;
	int ret;

	void *dma_va = NULL;
	unsigned int dma_pa = 0;
	unsigned int malloc_size[MEM_REGION_COUNT] = {0};
	unsigned int malloc_heap_id[MEM_REGION_COUNT] = {0};
	unsigned int malloc_count = 0;
	unsigned int dma_malloc_size[MEM_REGION_COUNT] = {0};
	unsigned int dma_malloc_heap_id[MEM_REGION_COUNT] = {0};
	unsigned int dma_malloc_count = 0;
	unsigned int i = 0;
	char *mem_layout_file=boot->argv[2];
	printf("boot_set_boot_args\n");

	char *content;
	int size = 0;
	cJSON *parsed = NULL;
	const cJSON *compatible = NULL;

	printf("parser file: %s\n", mem_layout_file);

	content = read_file(mem_layout_file);

	parsed = cJSON_Parse(content);
	if (!parsed)
	{
		printf("cJSON_Parse fail\n");
	}

	size = cJSON_GetArraySize(parsed);
	printf("get cJSON objects size = %d\n", size);

	/*get compatible*/
	malloc_count = 0;
    compatible = cJSON_GetObjectItemCaseSensitive(parsed, "compatible1");
	if (compatible)
	{
		cJSON *mem_malloc_string = cJSON_GetObjectItemCaseSensitive(compatible, "mem_malloc_string");
		if (mem_malloc_string)
		{
			printf("mem_malloc_string = %s\n", mem_malloc_string->valuestring);
		}

		/*get node*/
		{
			cJSON *node = cJSON_GetObjectItemCaseSensitive(compatible, "mem_malloc_str");
			if (node)
			{
				{
					cJSON *int_value = NULL;
					int_value = cJSON_GetObjectItemCaseSensitive(node, "region_count");
					if (int_value)
					{
						malloc_count = int_value->valueint;
						printf("region_count: %d\n", int_value->valueint);
					}
				}

				{
					cJSON *str_array = NULL;
					cJSON *str_value_in_array = NULL;
					int array_count = 0;
					str_array = cJSON_GetObjectItemCaseSensitive(node, "mem_region");
					array_count = cJSON_GetArraySize(str_array);
					printf("cJSON_GetArraySize = %d\n", array_count);

					if (array_count < malloc_count)
						malloc_count = array_count;

					if(str_array){
						{
							cJSON *str_value1 = cJSON_GetObjectItemCaseSensitive(str_array, "region_1");
							if (str_value1)
							{
								str_value_in_array = (str_value1)->child;
								malloc_heap_id[0] = strtol(str_value_in_array->valuestring, NULL, 0);
								str_value_in_array = str_value_in_array->next;
								malloc_size[0] = strtol(str_value_in_array->valuestring, NULL, 16);

							}
						}
						{
							cJSON *str_value2 = cJSON_GetObjectItemCaseSensitive(str_array, "region_2");
							if (str_value2)
							{
								str_value_in_array = (str_value2)->child;
								malloc_heap_id[1] = strtol(str_value_in_array->valuestring, NULL, 0);
								str_value_in_array = str_value_in_array->next;
								malloc_size[1] = strtol(str_value_in_array->valuestring, NULL, 16);

							}
						}
						{
							cJSON *str_value3 = cJSON_GetObjectItemCaseSensitive(str_array, "region_3");
							if (str_value3)
							{
								str_value_in_array = (str_value3)->child;
								malloc_heap_id[2] = strtol(str_value_in_array->valuestring, NULL, 0);
								str_value_in_array = str_value_in_array->next;
								malloc_size[2] = strtol(str_value_in_array->valuestring, NULL, 16);

							}
						}
						{
							cJSON *str_value4 = cJSON_GetObjectItemCaseSensitive(str_array, "region_4");
							if (str_value4)
							{
								str_value_in_array = (str_value4)->child;
								malloc_heap_id[3] = strtol(str_value_in_array->valuestring, NULL, 0);
								str_value_in_array = str_value_in_array->next;
								malloc_size[3] = strtol(str_value_in_array->valuestring, NULL, 16);

							}
						}
						{
							cJSON *str_value5 = cJSON_GetObjectItemCaseSensitive(str_array, "region_5");
							if (str_value5)
							{
								str_value_in_array = (str_value5)->child;
								malloc_heap_id[4] = strtol(str_value_in_array->valuestring, NULL, 0);
								str_value_in_array = str_value_in_array->next;
								malloc_size[4] = strtol(str_value_in_array->valuestring, NULL, 16);

							}
						}

					}
				}
			}
		}
	}

	dma_malloc_count = 0;
	compatible = cJSON_GetObjectItemCaseSensitive(parsed, "compatible2");
	if (compatible)
	{
		cJSON *test2 = cJSON_GetObjectItemCaseSensitive(compatible, "dma_malloc_string");
		if (test2)
		{
			printf("dma_malloc_string = %s\n", test2->valuestring);
		}

		/*get node*/
		{
			cJSON *node = cJSON_GetObjectItemCaseSensitive(compatible, "dma_malloc_str");
			if (node)
			{
				{
					cJSON *int_value = NULL;
					int_value = cJSON_GetObjectItemCaseSensitive(node, "region_count");
					if (int_value)
					{
						dma_malloc_count = int_value->valueint;
						printf("region_count: %d\n", int_value->valueint);
					}
				}

				{
					int arraycount = 0;
					cJSON *str_array = NULL;
					cJSON *str_value_in_array = NULL;
					str_array = cJSON_GetObjectItemCaseSensitive(node, "mem_region");
					arraycount = cJSON_GetArraySize(str_array);
					printf("cJSON_GetArraySize = %d\n", dma_malloc_count);

					if (arraycount < dma_malloc_count)
						dma_malloc_count = arraycount;

					if(str_array){
						{
							cJSON *str_value1 = cJSON_GetObjectItemCaseSensitive(str_array, "region_1");
							if (str_value1)	{
								str_value_in_array = (str_value1)->child;
								dma_malloc_heap_id[0] = strtol(str_value_in_array->valuestring, NULL, 0);
								str_value_in_array = str_value_in_array->next;
								dma_malloc_size[0] = strtol(str_value_in_array->valuestring, NULL, 16);
							}
						}
						{
							cJSON *str_value2 = cJSON_GetObjectItemCaseSensitive(str_array, "region_2");
							if (str_value2)	{
								str_value_in_array = (str_value2)->child;
								dma_malloc_heap_id[1] = strtol(str_value_in_array->valuestring, NULL, 0);
								str_value_in_array = str_value_in_array->next;
								dma_malloc_size[1] = strtol(str_value_in_array->valuestring, NULL, 16);
							}
						}
						{
							cJSON *str_value3 = cJSON_GetObjectItemCaseSensitive(str_array, "region_3");
							if (str_value3)	{
								str_value_in_array = (str_value3)->child;
								dma_malloc_heap_id[2] = strtol(str_value_in_array->valuestring, NULL, 0);
								str_value_in_array = str_value_in_array->next;
								dma_malloc_size[2] = strtol(str_value_in_array->valuestring, NULL, 16);
							}
						}
						{
							cJSON *str_value4 = cJSON_GetObjectItemCaseSensitive(str_array, "region_4");
							if (str_value4)	{
								str_value_in_array = (str_value4)->child;
								dma_malloc_heap_id[3] = strtol(str_value_in_array->valuestring, NULL, 0);
								str_value_in_array = str_value_in_array->next;
								dma_malloc_size[3] = strtol(str_value_in_array->valuestring, NULL, 16);
							}
						}
						{
							cJSON *str_value5 = cJSON_GetObjectItemCaseSensitive(str_array, "region_5");
							if (str_value5)	{
								str_value_in_array = (str_value5)->child;
								dma_malloc_heap_id[4] = strtol(str_value_in_array->valuestring, NULL, 0);
								str_value_in_array = str_value_in_array->next;
								dma_malloc_size[4] = strtol(str_value_in_array->valuestring, NULL, 16);
							}
						}
					}
				}
			}
		}
	}

	int index=0;
	uint32_t mem_size=0;
	//here we find if have some pra to overwrtie mem size
	index=find_pra_index_by_name("--size0",boot->argc,boot->argv);
	if(index>0)
	{
        mem_size=strtoul(boot->argv[index+1],NULL,16);
		printf("mem_size=0x%x \n",mem_size);
	}

	if(mem_size > dma_malloc_size[0])
	{
		printf("mem_size=0x%x dma_malloc_size[0]=0x%x\n",mem_size,dma_malloc_size[0]);
		dma_malloc_size[0]=mem_size;
	}

	for (i = 0; i < dma_malloc_count; i++)
	{
		ret = ar_ion_init(dma_malloc_heap_id[i]);
		if (ret) {
			printf("ar_ion_init line:%d  heap id=%d ret = %d \n", __LINE__, dma_malloc_heap_id[i], ret);
			goto _free_and_exit;
		}

		printf("dma_malloc_heap_id[%d] = %ld, dma_malloc_size[%d] = 0x%x \n",
			i, dma_malloc_heap_id[i], i, dma_malloc_size[i]);

		//alloc buffer for dma malloc
		AR_GET_ION_MEMORY(dma_va, dma_pa, dma_malloc_size[i]);

		printf("dma_va:%p dma_pa:%p", dma_va, dma_pa);

		args->dma_regions.mem_region[i].mem_region_start = dma_pa;
		args->dma_regions.mem_region[i].mem_region_end = (dma_pa + dma_malloc_size[i] - 1);
		args->dma_regions.mem_region[i].mem_region_brk = dma_pa;

		printf("ar_ion_uninit %d\n\n", __LINE__);
		ar_ion_uninit();
	}

	strcpy(args->dma_regions.magic_string, "dma malloc region");
	args->dma_regions.region_count = dma_malloc_count;

	printf("malloc_count = %d\n\n", malloc_count);

	for (i = 0; i < malloc_count; i++)
	{
		ret = ar_ion_init(malloc_heap_id[i]);
		if (ret) {
			printf("ar_ion_init line:%d  heap id=%d ret = %d \n", __LINE__, malloc_heap_id[i], ret);
			goto _free_and_exit;
		}

		printf("malloc_heap_id[%d] = %ld, malloc_size[%d] = %ld \n", i, malloc_heap_id[i], i, malloc_size[i]);

		//alloc buffer for malloc
		AR_GET_ION_MEMORY(malloc_va, malloc_pa, malloc_size[i]);

		args->mem_regions.mem_region[i].mem_region_start = malloc_pa;
		args->mem_regions.mem_region[i].mem_region_end   = (malloc_pa + malloc_size[i] - 1);
		args->mem_regions.mem_region[i].mem_region_brk = malloc_pa;

		printf("ar_ion_uninit %d\n\n", __LINE__);
		ar_ion_uninit();
	}

	strcpy(args->mem_regions.magic_string, "mem malloc region");
	args->mem_regions.region_count = malloc_count;

	args->hw_version_str.hw_version_num = ar_adc_read();
	strcpy(args->hw_version_str.hw_version_string, "hw_version");

	args->dtb_setting.dtb_addr  = dtb_pa;
	strcpy(args->dtb_setting.dtb_string, "dtb_addr");

	printf("args->hw_version_str.hw_version_num !!!= 0x%x \ndtb address: 0x%x \n", args->hw_version_str.hw_version_num,
			args->dtb_setting.dtb_addr);

	printf("\nset args: %p \n""malloc region count:%d pa:va (0x%x : 0x%x)\n""dma count:%d pa:va (0x%x : 0x%x)\n",
			args,
			malloc_count,
			malloc_pa, malloc_va,
			dma_malloc_count,
			dma_pa, dma_va);

	return 0;

_free_and_exit:

	printf("Get ion memory fail \n");
	if (malloc_va != NULL)
		ar_ion_free(malloc_va);

	if (dma_va != NULL)
		ar_ion_free(dma_va);

	return -1;
}

void *boot_up_a7(int * entry)
{
	int ret = 0;

	ret = boot_start_a7(*entry);
	if(ret < 0) {
		printf("boot_start_a7 fail ret %d\n", ret);
		return 0;
	}

	return 0;
}


static int fdt_check_header(const void *fdt)
{
	if (fdt_magic(fdt) == FDT_MAGIC) {
		/* Complete tree */
		if (fdt_version(fdt) < FDT_FIRST_SUPPORTED_VERSION)
			return -FDT_ERR_BADVERSION;
		if (fdt_last_comp_version(fdt) > FDT_LAST_SUPPORTED_VERSION)
			return -FDT_ERR_BADVERSION;
	} else if (fdt_magic(fdt) == FDT_SW_MAGIC) {
		/* Unfinished sequential-write blob */
		if (fdt_size_dt_struct(fdt) == 0)
			return -FDT_ERR_BADSTATE;
	} else {
		return -FDT_ERR_BADMAGIC;
	}

	return 0;
}


int boot_load_dtb(char *filename, int *load_pa)
{
	struct stat st = {0};

	void *dtb_va = NULL;
	unsigned int dtb_pa = 0;
	void *fdt = NULL;

	int ret = stat(filename, &st);
	if(ret < 0 || st.st_size <= 0) {
		printf("error %d, %d, %d %s %d\n", __LINE__, ret, st.st_size, filename, errno);
		goto exit;
	}


	int fd0 = open(filename, O_RDONLY);
	if (fd0 < 0) {
		printf("open failed\n");
		goto exit;
	}

	fdt = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd0, 0);
	if (fdt == MAP_FAILED) {
		printf("error %d, %d, %d\n", __LINE__, ret, errno);
		goto _ummap_fail;
	}

	if (fdt_check_header(fdt)) {
		printf("error %d, %d, %d\n", __LINE__, ret, errno);
		goto fdt_check_fail;
	}

	ret = ar_ion_init(AR_SYSTEM_HEAP_ID);
	if (ret) {
		printf("ar_ion_init line:%d  heap id=%d ret = %d \n", __LINE__, AR_SYSTEM_HEAP_ID, ret);
		goto _free_and_exit;
	}

	AR_GET_ION_MEMORY(dtb_va, dtb_pa, st.st_size);
	/*
	 * load dtb to address
	*/
	memcpy(dtb_va, fdt, st.st_size);
	*load_pa = dtb_pa;

	return 0;

_free_and_exit:

	ar_ion_uninit();
	printf("Get ion memory fail for dtb \n");

fdt_check_fail:
	munmap(fdt, st.st_size);

_ummap_fail:
	close(fd0);

exit:
	printf("open dtb file fail\n");
	return -1;
}

/*
 *
 */
int main(int argc, char * argv[])
{
	int ret = 0;
	pthread_t thread;
	pthread_attr_t attr;
	cpu_set_t cpu_info;
	char *a7_va_adr = 0;
	uint32_t a7_pa_addr = 0;

	int index = 0;
	int dtb_pa = 0;

	boot_assist_t boot={0};
	if(argc < 3) {
		printf("%s: image file or image dev path, memory layout cjson file \n", argv[0]);
		return 0;
	}

	boot.argc=argc;
	boot.argv=argv;

	/*
	 * if dtb in command line, load dtb to ion.
	*/
	index=find_pra_index_by_name("--dtb", argc, argv);
	if (index>0)
	{
		char *dtb_fname = argv[index + 1];
		ret = boot_load_dtb(dtb_fname, &dtb_pa);
		if (ret < 0) {
			printf("Load dtb img fail ret: %s %d \n", dtb_fname, ret);
			return -1;
		}
	}

	ret = boot_load_img(&boot, &a7_va_adr, &a7_pa_addr);
	if(ret < 0) {
		printf("Load img fail ret: %d\n", ret);
		return -1;
	}

	ret = boot_set_boot_args((boot_args *)a7_va_adr, &boot, dtb_pa);
	if(ret < 0) {
		printf("boot_set_boot_args fail ret %d\n", ret);
		return 0;
	}

#define BOOT_ARGS_SIZE (0x200)
	uint32_t pa_entry = a7_pa_addr + BOOT_ARGS_SIZE;
	printf("loading img end: img=%p pa=0x%x dtb=0x%x \n", a7_va_adr, a7_pa_addr, dtb_pa);

	pthread_attr_init(&attr);
	CPU_ZERO(&cpu_info);
	CPU_SET(0, &cpu_info);

	ret = pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &cpu_info);
	if(ret) {
		printf("Set thread affinity failed %d\n", __LINE__);
		return -1;
	}

	ret = pthread_create(&thread, &attr, boot_up_a7, (void *)&pa_entry);
	if(ret != 0) {
		printf("Create thread failed %d\n", __LINE__);
		return -1;
	}

	pthread_join(thread, NULL);

	while (1) {
		usleep(1000 * 1000 * 8);
	}

	return 0;
}

