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
#include "dbg_info.h"
#include "tof_dsp_memory_map.h"
#include "obc_tof_dsp_icc.h"
#include "ob_dsp_test.h"


#define DSP_CORE_NUM    4

static int fd_icc=-1;
static uint32_t msg_id_snd_tab[DSP_CORE_NUM]={0xff00ffab,0xff00ffbb,0xff00ffcb,0xff00ffdb};
static uint32_t msg_id_rcv_tab[DSP_CORE_NUM]={0xff00ffac,0xff00ffbc,0xff00ffcc,0xff00ffdc};

extern work icc_msg; // icc 通信结构
extern volatile param_ion_mellc_t ion_mem_info[USE_ION_MEM_NUM];



static  long long get_current_time(){
      struct  timeval    tv;    
      struct  timezone   tz;    
      long long ncurrent_time = 0x0LL;   
      gettimeofday(&tv,&tz);   
      ncurrent_time = ((long long)tv.tv_sec) * 1000000 + (long long)tv.tv_usec;    
      return ncurrent_time;
}


static int  write_bin_file(unsigned char *buf,long len, const char *file_name)
{	
	FILE *fid=NULL;
	int rc=1;

	if(len<=0)
	{
		printf("write len=0,err!\n");
		return -1;
	}

	fid = fopen(file_name,"wb");
	if(fid == NULL)
	{
		printf("open %s file to write fail!\n",file_name);
		return -1;
	}

	rc=(int)fwrite(buf,  sizeof(unsigned char), len, fid);
    fclose(fid);

	if (rc == len){
		return 0;
	}
	else
		return -1;
}

/*获取4帧rawphase到申请的ION内存，如果是图片的话就读取图片到申请的ION内存*/
static int read_bin_file(const char* file_name, char* buf, int buf_size)
{
	FILE*fp = fopen(file_name, "rb");
	if (fp == NULL){
		printf("open %s fail!\n", file_name);
		return -1;
	}
	
	fread(buf, 1, buf_size, fp);
	fclose(fp);
	
	return 0;
}
#define CALIB_BIN  "/usrdata/usr/data/arstack/hontao_dsp_param.bin"
#define N_SHF_LF_PH  "/usrdata/usr/data/arstack/dsp_parms/raw_phs_test/nshfl_f_low_freq_src.raw"
#define SHF_LF_PH  "/usrdata/usr/data/arstack/dsp_parms/raw_phs_test/shfl_f_low_freq_src.raw"
#define N_SHF_HF_PH  "/usrdata/usr/data/arstack/dsp_parms/raw_phs_test/nshfl_f_high_freq_src.raw"
#define SHF_HF_PH  "/usrdata/usr/data/arstack/dsp_parms/raw_phs_test/shfl_f_high_freq_src.raw"



/*读取内参到申请的ION内存*/
static int load_calib_file_t(char* calibParamFile)
{
    char* calibFile;
    int count=0;
    CALIB_PARAM_FILE_ST_t *ar9201_tof_param_ptr=(CALIB_PARAM_FILE_ST_t*)ion_mem_info[TOF_temp_MEM].va;

    calibFile = (char*)calibParamFile;							
    FILE*fp = fopen(calibFile, "rb");
    if (fp == NULL){
        printf("open %s fail!\n", calibFile);
        return -1;
    }
    
    count=fread(ar9201_tof_param_ptr, 1, sizeof(CALIB_PARAM_FILE_ST_t), fp);
    fclose(fp);
    printf("OB_DSP_LOAD_REF cmd ok,read file size=%d,need size=%d.\n",count,sizeof(CALIB_PARAM_FILE_ST_t));
    return 0;
}

/*初始化icc,申请ION内存片区*/
int dsp_init_t(void)
{
    int ret = 0;
    int raw_phase_size=1280*960*sizeof(uint16_t);//bytes

    /*仅测试：读取4张图片地址到 TOF_phase_xx_MEM*/
    ret+=read_bin_file(SHF_LF_PH,   ion_mem_info[TOF_phase_low_shl_MEM].va,   raw_phase_size);
	ret+=read_bin_file(N_SHF_LF_PH,  ion_mem_info[TOF_phase_low_nshl_MEM].va,  raw_phase_size);
	ret+=read_bin_file(SHF_HF_PH,  ion_mem_info[TOF_phase_high_shl_MEM].va,  raw_phase_size);
	ret+=read_bin_file(N_SHF_HF_PH, ion_mem_info[TOF_phase_high_nshl_MEM].va, raw_phase_size);

	printf("DSP init success!\n");
	return 0;
}

//最终深度计算api，调用一次计算一次，阻塞型api，阻塞时间取决于收到dsp回应msg的时间
int depth_calc_t(void *group, int needAmp, void* amp, int needDepth, void* depth)
{

    dsp_work_t   dsp_work;
    int core_id=0;
	int ret=0;
    int output_size=640*480*sizeof(uint16_t);	 //bytes
    

    dsp_work.magic_num	=MAGIC_NUM;
	dsp_work.cmd_type	=DSP_WORK_TOF_DEPTH;

    dsp_work.tof_input_buf_pa.nshufl_low_buf_pa	=(uint32_t)ion_mem_info[TOF_phase_low_nshl_MEM].pa;
	dsp_work.tof_input_buf_pa.shufl_low_buf_pa	=(uint32_t)ion_mem_info[TOF_phase_low_shl_MEM].pa;
	dsp_work.tof_input_buf_pa.nshufl_high_buf_pa=(uint32_t)ion_mem_info[TOF_phase_high_nshl_MEM].pa;
	dsp_work.tof_input_buf_pa.shufl_high_buf_pa	=(uint32_t)ion_mem_info[TOF_phase_high_shl_MEM].pa;

	dsp_work.tof_output_buf_pa.amp_out_buf_pa[0]	=(uint32_t)ion_mem_info[TOF_amp_low_MEM].pa;
	dsp_work.tof_output_buf_pa.ir_out_buf_pa[0]		=(uint32_t)ion_mem_info[TOF_ir_0_MEM].pa;
	dsp_work.tof_output_buf_pa.depth_out_buf_pa[0]	=(uint32_t)ion_mem_info[TOF_depth0_MEM].pa;

	dsp_work.tof_output_buf_pa.amp_out_buf_pa[1]	=(uint32_t)ion_mem_info[TOF_amp_high_MEM].pa;
	dsp_work.tof_output_buf_pa.ir_out_buf_pa[1]		=(uint32_t)ion_mem_info[TOF_ir_1_MEM].pa;
	dsp_work.tof_output_buf_pa.depth_out_buf_pa[1]	=(uint32_t)ion_mem_info[TOF_depth1_MEM].pa;

	// dsp_work.tof_output_buf_pa.trace_buf_pa		=(uint32_t)tof_buf_inf_ptr->trace_buf.pa;
	
	dsp_work.params_packet.packet_virt_addr		=(uint32_t)ion_mem_info[TOF_temp_MEM].va;
	dsp_work.params_packet.packet_phys_addr		=(uint32_t)ion_mem_info[TOF_temp_MEM].pa;
	dsp_work.params_packet.packet_bytes			=sizeof(CALIB_PARAM_FILE_ST_t);
	dsp_work.dsp_times	=0;
	dsp_work.dsp_result	=0;


    if(needAmp){
        printf("Amp now is .TBD\n");
    }
    else if(needDepth){

        ret=ar9201_icc_snd_msg(core_id,(void*)&dsp_work,sizeof(dsp_work_t));	
	    ret+=ar9201_icc_rev_msg(core_id,(void*)&dsp_work,sizeof(dsp_work_t));
    }

    printf("calcDepth end,cost time=%u us, dsp status=%d.\n", dsp_work.dsp_times,dsp_work.dsp_result);

    // write_bin_file((unsigned char*)ion_mem_info[TOF_depth0_MEM].va,(long)output_size,"/mnt/tof_depth0_out.raw"); //存图
    return 0;
}

