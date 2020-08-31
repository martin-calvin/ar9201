/*********Standard MobilenetSSD process***********/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

#include "ar_icc.h"
#include "ar_ion.h"

#include <sys/time.h>
#include <time.h>

static  long long get_current_time(){
      struct  timeval    tv;    
      struct  timezone   tz;    
      long long ncurrent_time = 0x0LL;   
      gettimeofday(&tv,&tz);   
      ncurrent_time = ((long long)tv.tv_sec) * 1000000 + (long long)tv.tv_usec;    
      return ncurrent_time;
}

#define AR_DSP_HEAP_ID  27
#define MAX_WIDTH 5460
#define MAX_HEIGHT 3684

static int fd_icc;
#define LOCAL_TEST_BGR_IMG_512x512 "/mnt/lena_512x512_400.yuv"
#define LOCAL_TEST_BGR_IMG_5460x3684 "/mnt/desert.yuv"
#define LOCAL_TEST_IMG_250x333 "/mnt/lena_250x333.yuv"
#define LOCAL_TEST_IMG_333x250 "/mnt/lena_333x250.yuv"

#define AR_GET_ION_MEMORY(VA, PA, SIZE) \
do{ \
	VA = ar_ion_malloc(SIZE); \
	if(!VA) \
	{ \
		printf("%s %d: Malloc memory failed, exit!\r\n", __FUNCTION__, __LINE__); \
	} \
	PA = ar_ion_virt_to_phy(VA); \
	if(!PA) \
	{ \
		printf("%s %d: Virt to phy failed, exit!\r\n", __FUNCTION__, __LINE__); \
	} \
}while(0)

#define AR_RELEASE_ION_MEMORY(VA) ar_ion_free(VA)


typedef struct 
{
	char * va;	// 输入结构体参数的虚拟地址
	char * pa;	// 输入结构体参数的物理地址
	int  len;		// 申请输入数据结构体的长度
}param_ion_mellc_t;

typedef enum{
	DSP_OUT_MEM = 0,
	DSP_IN_MEM,

	DSP_OUT_MEM_LEN = 10*1024*1024,//10M test
}ion_use_mem_list;


/* 
    ION mem 底层执行申请 
    申请成功后得到memory的虚拟地址(va)和物理地址(pa),并清空一次mem
    返回值: -1:失败，0：成功
*/
int do_alloc_ion(param_ion_mellc_t *mem, uint32_t len)
{
    mem->len = len;

	if(mem->len){
        //allocte mem
		AR_GET_ION_MEMORY(mem->va, mem->pa, mem->len);
        if(NULL == mem->va || NULL == mem->pa){
            printf("Unable to allocate memory,length is 0x%x\n", mem->len);
            return -1;
        } 
        // clear mem
        memset(mem->va, 0, len);
		printf("input va %x pa %x length %x\r\n\n", mem->va, mem->pa, mem->len);
	}
    return 0;
}


static int fd_icc = -1;
volatile  param_ion_mellc_t ion_mem_info[10];
static int msg_id_snd_ceva0 = 0xff00ffab;
static int msg_id_rcv_ceva0 = 0xff00ffac;
static int msg_id_snd_ceva1 = 0xff00ffbb;
static int msg_id_rcv_ceva1 = 0xff00ffbc;
static int msg_id_snd_ceva2 = 0xff00ffcb;
static int msg_id_rcv_ceva2 = 0xff00ffcc;
static int msg_id_snd_ceva3 = 0xff00ffdb;
static int msg_id_rcv_ceva3 = 0xff00ffdc;

int dsp_test_init(void)
{
	int dsp_id = 0;
	int ret;
	int x,y;
	int i,j;

	ar_ion_init(AR_DSP_HEAP_ID);
	/* 申请DSP输出的mem空间 */
    printf("\r\n[ION]:allocate DSP_OUT_MEM...\n");
	if(do_alloc_ion(&ion_mem_info[DSP_OUT_MEM], DSP_OUT_MEM_LEN) < 0)
        return -1;
	
	fd_icc = open("/dev/icc", O_RDWR);
	if (fd_icc < 0) {
		printf("open icc fail\n");
		return -1;
	}
	ret = ar_icc_register_msgid(fd_icc, msg_id_snd_ceva0);
	if(ret < 0) {
		printf("register msg id %x fail\n", msg_id_snd_ceva0);
		return -1;
	}
	ret = ar_icc_register_msgid(fd_icc, msg_id_rcv_ceva0);
	if(ret < 0) {
		printf("register msg id %x fail\n", msg_id_rcv_ceva0);
		return -1;
	}

	return 0;
}

// dsp从dsp_input_pa地址copy img_len长度数据到dsp_out_va地址
// dsp_input_va: 输入数据的va地址
// dsp_input_pa:输入数据的pa地址给dsp
// dsp_out_va:dsp输出数据的va地址传出
// img_len dsp copy的数据长度
int dsp_test(void *dsp_input_va, void *dsp_input_pa, void *dsp_out_va, int img_len)
{
	int ret;
	unsigned int msg[5];
	unsigned long long start,end;

	if(fd_icc < 0){
		printf("dsp icc err: icc_msgid no register\n");
		return -1;
	}

	msg[0] = dsp_input_pa;
	msg[1] = ion_mem_info[DSP_OUT_MEM].pa;
	msg[2] = img_len;
	printf("msg[0]=0x%x\n", msg[0]);
	printf("msg[1]=0x%x\n", msg[1]);
	printf("msg[2]=0x%x\n", msg[2]);

	start = get_current_time();

	printf("\ndsp_input_va data:\n");
	uint8_t *pdata = dsp_input_va;
	for(int i=0; i<20; i++){
		printf("data[%d]:0x%x\n", i, pdata[i]);
	}

	ret = ar_icc_send(fd_icc, (unsigned char *)&msg,
		sizeof(msg), msg_id_snd_ceva0, ICC_CORE_CEVA_0);
	if(ret < 0) {
		printf("ar_icc_send fail\n");
		return -1;
	}


	//receive ack
	ret = ar_icc_receive(fd_icc, (unsigned char *)&msg,
		sizeof(msg), msg_id_rcv_ceva0);
	if(ret < 0) {
		printf("ar_icc_receive fail\n");
		return -1;
	}

	dsp_out_va = ion_mem_info[DSP_OUT_MEM].va;

	end = get_current_time();
	printf("\n[dsp_test]cost time %lluus\n",end-start);

	close(fd_icc);
	return 0;
}
