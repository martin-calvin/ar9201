#ifndef __BOOT_ASSIST_H__
#define __BOOT_ASSIST_H__

#define ALIGNMENT_SIZE         0x1000  //page size

#define A7_CONFIG_BASE         (0x60610000)
#define A7_SECONDARY_ENTRY_REG (0x002C)
#define A7_BOOT_STATUS_REG     (0x0048)

#define GIC_DIST_BASE          (0x2C001000)
#define GIC_DIST_SGI_REG       (0xF00)

#define A7_SGI_BOOT_UP         (0)

/*Common*/
#define BOOT_UP_MAGIC          (0x4152544F)
#define CPU_BOOT_UP_OK         (1)
#define CPU_BOOT_UP_FAIL       (-1)

#define TIMEOUT_MAX            10

#define MEM_REGION_COUNT	(5)

typedef struct mem_malloc_region {
	uint32_t mem_region_start;
	uint32_t mem_region_end;
	uint32_t mem_region_brk;
} mem_malloc_region;


typedef struct mem_malloc_regions {
	char  magic_string[32];
	uint32_t region_count;
	mem_malloc_region mem_region[MEM_REGION_COUNT];
} mem_malloc_regions;

typedef struct {
	uint8_t hw_version_num;
	char  hw_version_string[12];
}hardware_version_str;

typedef struct {
	uint32_t dtb_addr;
	char  dtb_string[12];
} dtb_str;


typedef struct boot_args {
	mem_malloc_regions mem_regions;
	mem_malloc_regions dma_regions;
	hardware_version_str hw_version_str;
	dtb_str dtb_setting;
} boot_args;


#define AR_A7_RTOS_HEAP_ID  (28)

#define AR_SYSTEM_HEAP_ID  (27)

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
}while(0)



#define FDT_MAGIC	0xd00dfeed	/* 4: version, 4: total size */
#define FDT_SW_MAGIC		(~FDT_MAGIC)

#define FDT_ERR_BADSTATE	7
#define FDT_ERR_BADMAGIC	9
#define FDT_ERR_BADVERSION	10
#define FDT_FIRST_SUPPORTED_VERSION	0x10
#define FDT_LAST_SUPPORTED_VERSION	0x11


struct fdt_header {
	uint32_t magic;			 /* magic word FDT_MAGIC */
	uint32_t totalsize;		 /* total size of DT block */
	uint32_t off_dt_struct;		 /* offset to structure */
	uint32_t off_dt_strings;		 /* offset to strings */
	uint32_t off_mem_rsvmap;		 /* offset to memory reserve map */
	uint32_t version;		 /* format version */
	uint32_t last_comp_version;	 /* last compatible version */

	/* version 2 fields below */
	uint32_t boot_cpuid_phys;	 /* Which physical CPU id we're
					    booting on */
	/* version 3 fields below */
	uint32_t size_dt_strings;	 /* size of the strings block */

	/* version 17 fields below */
	uint32_t size_dt_struct;		 /* size of the structure block */
};


#define fdt32_to_cpu(x) \
	((uint32_t)( \
		(((uint32_t)(x) & (uint32_t)0x000000ffUL) << 24) | \
		(((uint32_t)(x) & (uint32_t)0x0000ff00UL) <<  8) | \
		(((uint32_t)(x) & (uint32_t)0x00ff0000UL) >>  8) | \
		(((uint32_t)(x) & (uint32_t)0xff000000UL) >> 24) ))

#define fdt_get_header(fdt, field) \
	(fdt32_to_cpu(((const struct fdt_header *)(fdt))->field))
#define fdt_magic(fdt)			(fdt_get_header(fdt, magic))
#define fdt_totalsize(fdt)		(fdt_get_header(fdt, totalsize))
#define fdt_off_dt_struct(fdt)		(fdt_get_header(fdt, off_dt_struct))
#define fdt_off_dt_strings(fdt)		(fdt_get_header(fdt, off_dt_strings))
#define fdt_off_mem_rsvmap(fdt)		(fdt_get_header(fdt, off_mem_rsvmap))
#define fdt_version(fdt)		(fdt_get_header(fdt, version))
#define fdt_last_comp_version(fdt)	(fdt_get_header(fdt, last_comp_version))
#define fdt_boot_cpuid_phys(fdt)	(fdt_get_header(fdt, boot_cpuid_phys))
#define fdt_size_dt_strings(fdt)	(fdt_get_header(fdt, size_dt_strings))
#define fdt_size_dt_struct(fdt)		(fdt_get_header(fdt, size_dt_struct))


#endif
