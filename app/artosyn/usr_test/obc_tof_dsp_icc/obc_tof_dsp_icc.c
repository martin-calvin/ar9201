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
#include "arm_to_dsp_data.h"
#include "dbg_info.h"
#include "tof_dsp_memory_map.h"


extern work icc_msg; // icc 通信结构
extern volatile param_ion_mellc_t ion_mem_info[USE_ION_MEM_NUM];
extern ring_buf_ctrl_t ring_buffer;

/*-----------------dsp arm通信 msg id--------------------*/
#define msg_id_snd_ceva0  	 0xff00ffab
#define msg_id_rcv_ceva0  	 0xff00ffac
#define msg_id_snd_ceva1  	 0xff00ffbb
#define msg_id_rcv_ceva1  	 0xff00ffbc
#define msg_id_snd_ceva2  	 0xff00ffcb
#define msg_id_rcv_ceva2  	 0xff00ffcc
#define msg_id_snd_ceva3  	 0xff00ffdb
#define msg_id_rcv_ceva3  	 0xff00ffdc
/*-----------------dsp arm通信 msg id--------------------*/	

typedef enum
{
	RING_INPUT_DIR = 0,
	RING_OUTPUT_DIR,
}ring_buf_dir_t;

/* 输入输出测试用图 */
#define IN_PIC_1  "/mnt/testpattern_1280_960.raw"
#define OUT_PIC_1  "/mnt/data_out.raw"
#define IN_PIC_2  "/mnt/testpattern_1280_800.raw"
#define OUT_PIC_2  "/mnt/data_out.raw"
#define	DUMP_IN1	"/mnt/dump_data_in.raw"
#define	DUMP_OUT1	"/mnt/dump_data_out.raw"

#define RAW_DATA_PATH_IN	IN_PIC_2
#define	RAW_DATA_PATH_OUT	OUT_PIC_2


static  long long get_current_time(){
      struct  timeval    tv;    
      struct  timezone   tz;    
      long long ncurrent_time = 0x0LL;   
      gettimeofday(&tv,&tz);   
      ncurrent_time = ((long long)tv.tv_sec) * 1000000 + (long long)tv.tv_usec;    
      return ncurrent_time;
}

static int gl_fd_icc;

#define LOCAL_TEST_BGR_IMG_512x512 "/mnt/lena_512x512_400.yuv"
#define LOCAL_TEST_BGR_IMG_5460x3684 "/mnt/desert.yuv"
#define LOCAL_TEST_IMG_250x333 "/mnt/lena_250x333.yuv"
#define LOCAL_TEST_IMG_333x250 "/mnt/lena_333x250.yuv"

typedef struct
{
	unsigned short new_label;
	unsigned int  occurrence;
} label_debug_t;

label_debug_t labelList[1924 * 1080];


// size为0时，返回file size
int ar_load_file(char * path, char * buf, int size)
{
	FILE * pFile = 0;
	int file_len;
	int ret = 0;

	pFile = fopen(path, "rb");
	if (!pFile)
	{
		printf("Open file %s error: %s\r\n", path, strerror(errno));
		return -1;
	}

	file_len = size;
	if (size == 0)
	{
		fseek(pFile, 0, SEEK_END);
		file_len = ftell(pFile);
		rewind(pFile);
	}

	ret = fread(buf, 1, file_len, pFile);
	if (ret < 0)
	{
		printf("Read file %s size %d error: %s\r\n", path, file_len, strerror(errno));
		fclose(pFile);
		return ret;
	}

	fclose(pFile);

	ret = file_len;
	return ret;
}

int ar_dump_file(char * path, char * buf, int size)
{
	int w_fd;

	w_fd = open(path, O_RDWR | O_CREAT);
    if(w_fd < 0){
        printf("open file error\n");
        return ;
    }

	write(w_fd, buf, size);
    // free(buf);
	close(w_fd);
	printf("");
}


//
int updata_dspParams(ObTofDspParams *msg, uint8_t ipcore, uint8_t print_rcv)
{
	uint8_t rl_core_num = ipcore - 8;
	if(!print_rcv){
		// msg->inputs.constInputs.width = 1280 + rl_core_num;// first member of inputs msg struct
		// msg->inputs.constInputs.height = 962 + rl_core_num;
		// msg->inputs.multiplex = 111 + rl_core_num; //last menber of inputs struct
		// msg->outputs.amp_low = 0x91002000 + rl_core_num; //first member of outputs msg struct
		// msg->outputs.dsp_version.build = 1 + rl_core_num;
		// msg->outputs.status = -1 + rl_core_num; //last menber of outputs struct	
	}
	if(print_rcv){
		printf("ar_icc_receive print.......\n");
	}
	// debug_info_tofparams_msg(msg);
	ObTofDspParams *tof = msg;
	printf("[DSP_IN]current consumer_address:0x%x\n", tof->inputs.frameInputs.phase_low_nshl_src);
	// printf("tof->inputs.frameInputs.phase_low_nshl_src = 0x%x\r\n", tof->inputs.frameInputs.phase_low_nshl_src);
	// printf("tof->inputs.frameInputs.phase_low_shl_src = 0x%x\r\n", tof->inputs.frameInputs.phase_low_shl_src);
	// printf("tof->inputs.frameInputs.phase_high_nshl_src = 0x%x\r\n", tof->inputs.frameInputs.phase_high_nshl_src);
    // printf("tof->inputs.frameInputs.phase_high_shl_src = 0x%x\r\n", tof->inputs.frameInputs.phase_high_shl_src);
    
    
    // printf("tof->inputs.frameInputs.tempParams.sensor_temp_high = %.1f\r\n", tof->inputs.frameInputs.tempParams.sensor_temp_high);
    // printf("tof->inputs.frameInputs.tempParams.sensor_temp_low = %.1f\r\n", tof->inputs.frameInputs.tempParams.sensor_temp_low);
    // printf("tof->inputs.frameInputs.tempParams.vcsel_temp_high = %.1f\r\n", tof->inputs.frameInputs.tempParams.vcsel_temp_high);
    // printf("tof->inputs.frameInputs.tempParams.vcsel_temp_low = %.1f\r\n", tof->inputs.frameInputs.tempParams.vcsel_temp_low);
	return 0;
}

int updata_iccMsg(work *msg, uint8_t ipcore, uint8_t print_rcv)
{
	uint8_t rl_core_num = ipcore - 8;

	if(!print_rcv){
		// msg->id = 12345;
		msg->type = ALGORITHM_WORK;
		msg->params.algorithm.type = ALGORITHM_WORK;
		// msg->params.algorithm.packet_phys = 0x97400000;
		// msg->params.algorithm.packet_virt = 0x733c8000;
	}
	if(print_rcv){
		printf("ar_icc_receive print.......\n");
	}
	// debug_info_work_msg(msg);
	return 0;
}

/*
	register all-4ceva msg id
	return : < 0  register failed, fd_icc
*/
int register_tof_icc_msgid(void)
{
	int ret;
	int fd_icc = open("/dev/icc", O_RDWR);
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

	ret = ar_icc_register_msgid(fd_icc, msg_id_snd_ceva1);
	if(ret < 0) {
		printf("register msg id %x fail\n", msg_id_snd_ceva1);
		return -1;
	}
	ret = ar_icc_register_msgid(fd_icc, msg_id_rcv_ceva1);
	if(ret < 0) {
		printf("register msg id %x fail\n", msg_id_rcv_ceva1);
		return -1;
	}

	ret = ar_icc_register_msgid(fd_icc, msg_id_snd_ceva2);
	if(ret < 0) {
		printf("register msg id %x fail\n", msg_id_snd_ceva2);
		return -1;
	}
	ret = ar_icc_register_msgid(fd_icc, msg_id_rcv_ceva2);
	if(ret < 0) {
		printf("register msg id %x fail\n", msg_id_rcv_ceva2);
		return -1;
	}

	ret = ar_icc_register_msgid(fd_icc, msg_id_snd_ceva3);
	if(ret < 0) {
		printf("register msg id %x fail\n", msg_id_snd_ceva3);
		return -1;
	}
	ret = ar_icc_register_msgid(fd_icc, msg_id_rcv_ceva3);
	if(ret < 0) {
		printf("register msg id %x fail\n", msg_id_rcv_ceva3);
		return -1;
	}

	return fd_icc;
}


/* raw_phase input to ION[input] mem 模拟相机图像数据输入 
frame_num 需要缓冲的帧数，每帧1280*960*2 bytes
src_addr 数据来源地址
dst_addr_va arm端维护的地址，随着frame_num增加，dst_addr增加，超过mem规划值[TOF_FrameInputs_LEN]后地址复位
dst_addr_pa 更新给dsp的地址
*/
int getPhaseFrameGroup(char *src_addr, char *dst_addr_va, char *dst_addr_pa, uint32_t frame_num)
{
	static uint32_t cycle_count = 0;
	int frame_size;
	//读取n张1280*960尺寸的图片
	for(int i = 0; i< frame_num; i++){
		frame_size = ar_load_file(src_addr, dst_addr_va, 0);//每次进一帧
		if(frame_size < 0){
			printf("[ERR]:ar_load_file fail\n");
			return -1;
		}
		printf("frame_size:%d\n", frame_size);
		//更新一次dst_addr
		dst_addr_va += frame_size;
		dst_addr_pa += frame_size;
		printf("[DSP_IN]current producter_address_va:0x%x\n", dst_addr_va);
		// 判断当前消耗的size是否超过input buffer size
		if((dst_addr_va - ion_mem_info[TOF_FrameInputs_MEM].va) >= TOF_FrameInputs_LEN){
			dst_addr_va = ion_mem_info[TOF_FrameInputs_MEM].va; //复位地址到in buffer起始地址
			dst_addr_pa = ion_mem_info[TOF_FrameInputs_MEM].pa; //复位地址到in buffer起始地址
			cycle_count++;
			printf("[DSP_IN]-----------producter buffer use cycle %d times\n", cycle_count);
		}
	}
	
	printf("[DSP_IN]current producter_address_pa:0x%x\n", dst_addr_pa);
}


int ring_buffer_handle_callback(ring_buf_dir_t buf_dir, tof_mem_info_t mem_name, ObTofDspParams *pParam)
{
	int ret;
	char *buf_va = NULL;
	uint16_t *buf_pa = NULL;

	switch(buf_dir)
	{
		case RING_INPUT_DIR:
			getPhaseFrameGroup(RAW_DATA_PATH_IN, ring_buffer.input_va_addr, pParam->inputs.frameInputs.phase_low_nshl_src, 4);
			// file_buf = ion_mem_info[mem_name].va;
			// ret = ar_load_file(RAW_DATA_PATH_IN, file_buf, 0);
			// if(ret < 0){
			// 	printf("[ERR]:ar_load_file fail\n");
			// 	return -1;
			// }
			// printf("Load piture path-%s success\n", LOCAL_TEST_BGR_IMG_512x512);

			// ar_dump_file(DUMP_IN1, (uint8_t *)ion_mem_info[mem_name].va, 512*512);
			// printf("dump [IN]piture path-%s success!\n", RAW_DATA_PATH_IN);
			break;
		case RING_OUTPUT_DIR:
			//存图
			ar_dump_file(RAW_DATA_PATH_OUT, (uint8_t *)ion_mem_info[mem_name].va, 512*512);
			printf("dump [OUT]piture path-%s success!\n", RAW_DATA_PATH_OUT);
			break;
	}
	
	return 0;
}


int main(void *arg)
{
	int dsp_id = 0;
	int ret;
	int x,y;
	int i = 0,j = 0;
	unsigned long long start,end;


	/* 初始化ION空间 */
	start = get_current_time();
	if(init_tof_buffer() < 0){
		return -1;
	}
	end = get_current_time();
	printf("[ION]:init_tof_buffer cost time %lluus\n",end-start);

	ObTofDspParams *pMemParam = (ObTofDspParams *)ion_mem_info[TOF_DspParams_MEM].va;

	/* 注册4个CEVA核的 msg id */
	gl_fd_icc = register_tof_icc_msgid();
	if(gl_fd_icc < 0){
		return -1;
	}

	printf("start test!!!\n");
	do
	{
		/* input-Ring-buffer：更新图像数据进buffer，输出接下来处理的图像数据地址 */
		ring_buffer_handle_callback(RING_INPUT_DIR, TOF_FrameInputs_MEM, pMemParam);
		/* 更新dsp计算参数 */
		updata_dspParams(pMemParam, ICC_CORE_CEVA_0, 0); 
		/* 更新icc通信消息 */
		updata_iccMsg(&icc_msg, ICC_CORE_CEVA_0, 0);
		/* 发起icc通信，发送消息，dsp开始处理 */
		start = get_current_time();
		ret = ar_icc_send(gl_fd_icc, (unsigned char *)&icc_msg, sizeof(icc_msg), msg_id_snd_ceva0, ICC_CORE_CEVA_0);
		if(ret < 0) {
			printf("ar_icc_send fail\n");
			return -1;
		}
		printf("wait for dsp response--------------------------\n");




		//receive ack
		ret = ar_icc_receive(gl_fd_icc, (unsigned char *)&icc_msg, sizeof(icc_msg), msg_id_rcv_ceva0);
		if(ret < 0) {
			printf("ar_icc_receive fail\n");
			return -1;
		}
		// updata_iccMsg(&icc_msg, ICC_CORE_CEVA_0, 1); //cat recieve msg
		// updata_dspParams(pMemParam, ICC_CORE_CEVA_0, 0); //cat recieve dsp Params
		// /* output-Ring-buffer：更新图像数据进buffer，输出接下来处理的图像数据地址 */
		// ring_buffer_handle_callback(RING_OUTPUT_DIR, TOF_FrameOutputs_MEM);

		end = get_current_time();
		printf("[DSP]dsp cost time %lluus\n",end-start);
	}while(++i < 100);


	// free(file_buf);
	close(gl_fd_icc);

	return 0;
}
