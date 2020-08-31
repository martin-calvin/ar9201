#ifndef __AR_DSP_BOOTUP_H__
#define __AR_DSP_BOOTUP_H__

typedef int boot_status_t;
typedef int int_32_t;
typedef unsigned int uint_32_t;
typedef unsigned int uint32_t;
typedef char int_8_t;
typedef char uint_8_t;
typedef unsigned char u_int_8_t;
typedef unsigned int addr_t;
typedef unsigned int offset_t;
typedef unsigned int addr_len_t;
typedef void *icc_client_t;

typedef enum
{
    C0_BIN = 0,
    D0_BIN,
    C1_BIN,
    D1_BIN,
    D12_BIN,
    MAX_BIN_TYPE
} dsp_bin_type_e;

typedef enum
{
    input_file_err = -1,
    open_file_err = -2,
    alloc_err = -3,
    read_file_err = -4,
    write_file_err = -5,
    dsp_id_err = -6,
    parse_img_err = -7
} dsp_bin_error_e;

typedef enum
{
    DSP_CORE0 = 0,
    DSP_CORE1,
    DSP_CORE2,
    DSP_CORE3,
    MAX_DSP_CORE
} dsp_core_id_t;

typedef struct ceva_img_header_st
{
    int_32_t header_len;
    offset_t offset[MAX_BIN_TYPE];
    addr_t start_addr[MAX_BIN_TYPE];
    int_32_t bin_len[MAX_BIN_TYPE];
} ceva_img_header_t __attribute__((aligned(4)));

typedef struct ceva_bootloader_header_st
{
    int_32_t magic;
	int_32_t version;
	int_32_t image_type;
	uint32_t spl_addr;
	int_32_t spl_len;
	uint32_t troot_fw_addr;
	uint32_t troot_fw_len;
	uint32_t sig_addr;
	int_32_t sig_len;
	uint32_t checksum;
	int_32_t rsv0;
	int_32_t rsv1;
	int_32_t rsv2;
	int_32_t rsv3;
	int_32_t rsv4;
	int_32_t rsv5;
} ceva_bootloader_header_t __attribute__((aligned(4)));

typedef struct ceva_bootloader_layout_header_st
{
	ceva_bootloader_header_t boot_loader_header;
	ceva_img_header_t  ceva_img_header;
}ceva_bootloader_layout_header_t __attribute__((aligned(4)));

typedef struct ceva_parse_addr_st
{
	addr_t C0_src_addr;
	addr_t D0_src_addr;
	addr_t C1_src_addr;
	addr_t D1_src_addr;
	addr_t D12_src_addr;
	addr_t C0_dst_addr;
	addr_t D0_dst_addr;
	addr_t C1_dst_addr;
	addr_t D1_dst_addr;
	addr_t D12_dst_addr;
	uint32_t C0_len;
	uint32_t D0_len;
	uint32_t C1_len;
	uint32_t D1_len;
	uint32_t D12_len;
	uint32_t offset;
}ceva_parse_info_t __attribute__((aligned(4)));

typedef int boot_status_t;

typedef enum
{
    NOT_BOOT = 0,
    HAS_BOOT,
    BOOT_ERROR
} boot_status_e;

#define BOOTLOADER_HEADER 0x4152544f
#define CEVA_BIN_HEADER 0x00000040

#define AR_DSP_ION_HEAP_ID   (27)

//this is same with dump_dspmsg and dsp prj
#define AR_DSP_PRINT_BUFFER_ADDR (CEVA_ADDR_START+0x400000)
#define AR_DSP_PRINT_BUFFER_LEN  (512 * 1024)

#endif
