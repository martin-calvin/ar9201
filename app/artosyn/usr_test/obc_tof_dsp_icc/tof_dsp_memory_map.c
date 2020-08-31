#include "tof_dsp_memory_map.h"


/*-----------------dsp arm通信结构-----------------------*/
volatile param_ion_mellc_t ion_mem_info[USE_ION_MEM_NUM];
work icc_msg; // icc 通信结构
ring_buf_ctrl_t ring_buffer;
/*-----------------dsp arm通信结构-----------------------*/


/* tofdspParams 默认初始化一次 */
int dsp_params_deinit(ObTofDspParams *p_dsp_params)
{
    memset(p_dsp_params, 0, sizeof(ObTofDspParams));// if allocted mem has been cleaned, no need to do this

    //------------------------------p_dsp_params->inputs-----------------------------------
    p_dsp_params->inputs.constInputs.buf = ion_mem_info[TOF_DspTemporaryUse_MEM].pa; // dsp 使用空间，结构体中未定义长度？
    p_dsp_params->inputs.constInputs.depth_coef = ion_mem_info[TOF_DepthCoef_MEM].pa; // DepthCoef 使用的空间，结构体中未定义长度？
    p_dsp_params->inputs.constInputs.width = 1280;
    p_dsp_params->inputs.constInputs.height = 962;
    //cameraIntrincfg
    p_dsp_params->inputs.constInputs.cameraIntrin.cx = 0;
    p_dsp_params->inputs.constInputs.cameraIntrin.cy = 0;
    p_dsp_params->inputs.constInputs.cameraIntrin.fx = 0;
    p_dsp_params->inputs.constInputs.cameraIntrin.fy = 0;
    //depthcfg
    p_dsp_params->inputs.constInputs.depthCfg.depth_uint = 0.1; //单位mm
    p_dsp_params->inputs.constInputs.depthCfg.max_depth = 10000.0;//10m
    p_dsp_params->inputs.constInputs.depthCfg.min_depth = 0.0;//0m
    //filtercfg
    p_dsp_params->inputs.constInputs.filterCfg.fly_bypass = 0.0;
    //calibParams
    p_dsp_params->inputs.constInputs.calibParams.headerType = 0;
    p_dsp_params->inputs.constInputs.calibParams.freq_mod[0] = 80; //低频
    p_dsp_params->inputs.constInputs.calibParams.freq_mod[1] = 100; //高频
    p_dsp_params->inputs.constInputs.calibParams.res1 = 0;
    p_dsp_params->inputs.constInputs.calibParams.res2 = 0;
    //calibParams.temp_comp
    p_dsp_params->inputs.constInputs.calibParams.temp_comp[0].sensor_temp_comp_coeff = 1.0;
    p_dsp_params->inputs.constInputs.calibParams.temp_comp[0].temp_dist_offset = 0.0;
    p_dsp_params->inputs.constInputs.calibParams.temp_comp[0].vcsel_temp_comp_coeff = 1.0;
    p_dsp_params->inputs.constInputs.calibParams.temp_comp[1].sensor_temp_comp_coeff = 1.0;
    p_dsp_params->inputs.constInputs.calibParams.temp_comp[1].temp_dist_offset = 0.0;
    p_dsp_params->inputs.constInputs.calibParams.temp_comp[1].vcsel_temp_comp_coeff = 1.0;
    
    //calibParams.dist_slop_calib
    p_dsp_params->inputs.constInputs.calibParams.dist_slop_calib.scale =  1;
    p_dsp_params->inputs.constInputs.calibParams.dist_slop_calib.fppn_offset = ion_mem_info[TOF_CalibParam_MEM].pa; //fppn_offset mem
    p_dsp_params->inputs.constInputs.calibParams.dist_slop_calib.fppn_slop_lut_high = ion_mem_info[TOF_CalibParam_MEM].pa + 3*1024*1024;//3MB
    p_dsp_params->inputs.constInputs.calibParams.dist_slop_calib.fppn_slop_lut_high = ion_mem_info[TOF_CalibParam_MEM].pa + 6*1024*1024;//3MB
    //calibParams.dist_calib
    p_dsp_params->inputs.constInputs.calibParams.dist_calib[0].phase_offset = 80.0;
    p_dsp_params->inputs.constInputs.calibParams.dist_calib[0].fppn_lut_size = 3*1024*1024; //3M
    p_dsp_params->inputs.constInputs.calibParams.dist_calib[0].fppn_lut = ion_mem_info[TOF_CalibParam_MEM].pa + 9*1024*1024;
    p_dsp_params->inputs.constInputs.calibParams.dist_calib[0].wiggling_lut_size = 3*1024*1024; //3M
    p_dsp_params->inputs.constInputs.calibParams.dist_calib[0].wiggling_lut = ion_mem_info[TOF_CalibParam_MEM].pa + 12*1024*1024;

    p_dsp_params->inputs.constInputs.calibParams.dist_calib[1].phase_offset = 100.0;
    p_dsp_params->inputs.constInputs.calibParams.dist_calib[1].fppn_lut_size = 3*1024*1024; //3M
    p_dsp_params->inputs.constInputs.calibParams.dist_calib[1].fppn_lut = ion_mem_info[TOF_CalibParam_MEM].pa + 15*1024*1024;
    p_dsp_params->inputs.constInputs.calibParams.dist_calib[1].wiggling_lut_size = 3*1024*1024; //3M
    p_dsp_params->inputs.constInputs.calibParams.dist_calib[1].wiggling_lut = ion_mem_info[TOF_CalibParam_MEM].pa + 18*1024*1024; 

    //**frameInputs
    //1 temperature
    p_dsp_params->inputs.frameInputs.tempParams.sensor_temp_high = 30.0; //要实时更新
    p_dsp_params->inputs.frameInputs.tempParams.sensor_temp_low = 31.0; //要实时更新
    p_dsp_params->inputs.frameInputs.tempParams.vcsel_temp_high = 32.0; //要实时更新
    p_dsp_params->inputs.frameInputs.tempParams.vcsel_temp_low = 33.0; //要实时更新
    //2 phase cam source*
    p_dsp_params->inputs.frameInputs.phase_high_nshl_src = ion_mem_info[TOF_FrameInputs_MEM].pa;//初始地址，通过ring-buffer管理
    p_dsp_params->inputs.frameInputs.phase_high_shl_src = ion_mem_info[TOF_FrameInputs_MEM].pa;//初始地址，通过ring-buffer管理
    p_dsp_params->inputs.frameInputs.phase_low_nshl_src = ion_mem_info[TOF_FrameInputs_MEM].pa;//初始地址，通过ring-buffer管理
    p_dsp_params->inputs.frameInputs.phase_low_shl_src = ion_mem_info[TOF_FrameInputs_MEM].pa;//初始地址，通过ring-buffer管理

    //**multiplex帧复用
    p_dsp_params->inputs.multiplex = 0;//无复用
		
    //------------------------------p_dsp_params->outputs-----------------------------------
    p_dsp_params->outputs.status = -1;
    p_dsp_params->outputs.cost_times = 0;
    p_dsp_params->outputs.dsp_version.major = 0;
    p_dsp_params->outputs.dsp_version.minor = 0;
    p_dsp_params->outputs.dsp_version.patch_level = 0;
    p_dsp_params->outputs.dsp_version.build = 1;
    p_dsp_params->outputs.amp_low = ion_mem_info[TOF_FrameOutputs_MEM].pa;//初始地址，通过ring-buffer管理
    p_dsp_params->outputs.amp_high = ion_mem_info[TOF_FrameOutputs_MEM].pa;//初始地址，通过ring-buffer管理
    p_dsp_params->outputs.depth0 = ion_mem_info[TOF_FrameOutputs_MEM].pa;//初始地址，通过ring-buffer管理
    p_dsp_params->outputs.depth1 = ion_mem_info[TOF_FrameOutputs_MEM].pa;//初始地址，通过ring-buffer管理
    p_dsp_params->outputs.ir_0 = ion_mem_info[TOF_FrameOutputs_MEM].pa;//初始地址，通过ring-buffer管理
    p_dsp_params->outputs.ir_1 = ion_mem_info[TOF_FrameOutputs_MEM].pa;//初始地址，通过ring-buffer管理

    return 0;
}

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

/*
	申请-初始化buffer空间
    初始化 ObTofDspParams
    初始化 icc_msg
*/
int init_tof_buffer()
{
	/* 初始化ION空间 */
	ar_ion_init(AR_DSP_HEAP_ID);
	/* 清空icc通信消息队列 */
	memset(&icc_msg, 0, sizeof(icc_msg));

/* 申请tofdspParams数据结构使用的ION空间 [全局永久使用，不需要释放] */
    printf("\r\n[ION]:allocate TOF_DspParams_MEM...\n");
	if(do_alloc_ion(&ion_mem_info[TOF_DspParams_MEM], TOF_DspParams_LEN) < 0)
        return -1;

/* 申请ObTofFrameInputs图像数据输入缓冲buffer [全局永久使用，不需要放] */
    printf("[ION]:allocate TOF_FrameInputs_MEM...\n");
	if(do_alloc_ion(&ion_mem_info[TOF_FrameInputs_MEM], TOF_FrameInputs_LEN) < 0)
        return -1;

/* 申请ObTofOutputs图像数据输出缓冲buffer [全局永久使用，不需要释放] */
    printf("[ION]:allocate TOF_FrameOutputs_MEM...\n");
	if(do_alloc_ion(&ion_mem_info[TOF_FrameOutputs_MEM], TOF_FrameOutputs_LEN) < 0)
        return -1;

/* 申请dsp算法使用的临时ionbuf，len = 64MB [全局永久使用，不需要释放]  ObTofConstInputs.buf */
    printf("[ION]:allocate TOF_DspTemporaryUse_MEM...\n");
	if(do_alloc_ion(&ion_mem_info[TOF_DspTemporaryUse_MEM], TOF_DspTemporaryUse_LEN) < 0)
        return -1;

/* 申请距离转深度系数所需buf [全局永久使用，不需要释放] ObTofConstInputs.depth_coef */
    printf("[ION]:allocate TOF_DepthCoef_MEM...\n");
	if(do_alloc_ion(&ion_mem_info[TOF_DepthCoef_MEM], TOF_DepthCoef_LEN) < 0)
        return -1;

/* 申请标定所需的临时buffer [只读取一次传给dsp，之后释放] */
    printf("[ION]:allocate TOF_CalibParam_MEM...\n");
	if(do_alloc_ion(&ion_mem_info[TOF_CalibParam_MEM], TOF_CalibParam_LEN) < 0)
        return -1;

    printf("[ION] Init Success!\n");

/* --------------更新 tofdspParams,操作TOF_DspParams_MEM虚拟地址----------------------- */
    dsp_params_deinit((ObTofDspParams *)ion_mem_info[TOF_DspParams_MEM].va);

/* --------------更新 icc_msg---------------------------- */
    icc_msg.id = 0;
    icc_msg.type = 1;
    icc_msg.cycles = 2;
    icc_msg.rate = 10;
    icc_msg.result = 1;
    icc_msg.params.algorithm.type = 1;
    icc_msg.params.algorithm.size = sizeof(ObTofDspParams);
    icc_msg.params.algorithm.packet_phys = ion_mem_info[TOF_DspParams_MEM].pa;
    icc_msg.params.algorithm.packet_virt = ion_mem_info[TOF_DspParams_MEM].va;

/* ring buffer 管理 */
    ring_buffer.input_va_addr = ion_mem_info[TOF_FrameInputs_MEM].va;
    ring_buffer.input_pa_addr = ion_mem_info[TOF_FrameInputs_MEM].pa;
    ring_buffer.output_va_addr = ion_mem_info[TOF_FrameOutputs_MEM].va;
    ring_buffer.output_pa_addr = ion_mem_info[TOF_FrameOutputs_MEM].pa;

    return 0;
}

