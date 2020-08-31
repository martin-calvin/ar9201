#include "tof_dsp_memory_map.h"
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include "dbg_info.h"
#include "logutil.h"

/*-----------------dsp arm通信结构-----------------------*/
volatile param_ion_mellc_t ion_mem_info[USE_ION_MEM_NUM];
work icc_msg; // icc 通信结构
/*-----------------dsp arm通信结构-----------------------*/

struct mem_list_t mem_list[] =
    {
        /* ar-dsp共享参数结构体，根据机构体长度申请 */
        {TOF_DspParams_MEM, 1 * 1024 * 1024},
        /* dsp output buffer memory，使用rtos imgbuff，这里做测试使用 */
        {TOF_phase_low_nshl_MEM, 1280 * 960 * 2},
        {TOF_phase_low_shl_MEM, 1280 * 960 * 2},
        {TOF_phase_high_nshl_MEM, 1280 * 960 * 2},
        {TOF_phase_high_shl_MEM, 1280 * 960 * 2},
        /* dsp output buffer memory */
        {TOF_amp_low_MEM, 1280 * 960 * 2 * 4},
        {TOF_amp_high_MEM, 1280 * 960 * 2 * 4},
        {TOF_depth0_MEM, 1280 * 960 * 2 * 4},
        {TOF_depth1_MEM, 1280 * 960 * 2 * 4},
        {TOF_ir_0_MEM, 1280 * 960 * 2 * 4},
        {TOF_ir_1_MEM, 1280 * 960 * 2 * 4},
        /* dsp use */
        {TOF_DspUse_MEM, 64 * 1024 * 1024},
        /* arm 解析标定参数,临时空间接口内部申请-并释放 */
        {TOF_temp_MEM, 10 * 1024 * 1024}, //根据标定内参大小申请，目前不释放
};

//fixme: icc send之前刷新所有开辟ION cache
int all_ion_cache_flush(uint8_t usr_ion_mem_num)
{
    int ret = 0;
#if 0 //flush all
    for (int i = 0; i < sizeof(mem_list) / sizeof(struct mem_list_t); i++)
    {
        ret = ar_ion_cache_flush_by_range(ion_mem_info[mem_list[i].mem_name].va, 
                                    ion_mem_info[mem_list[i].mem_name].va, 
                                    ion_mem_info[mem_list[i].mem_name].len);
        if(ret < 0){
            printf("ion_cache_flush filed. mem is %d\n", i);
            return ret;
        }
    }
#else
    ret = ar_ion_cache_flush_by_range(ion_mem_info[mem_list[usr_ion_mem_num].mem_name].va, 
                                    ion_mem_info[mem_list[usr_ion_mem_num].mem_name].va, 
                                    ion_mem_info[mem_list[usr_ion_mem_num].mem_name].len);
    if(ret < 0){
        printf("ion_cache_flush filed. mem is %d\n", usr_ion_mem_num);
        return ret;
    }
#endif
    return ret;
}

//fixme: icc receive之后刷新所有开辟ION cache
int all_ion_cache_invalid(uint8_t usr_ion_mem_num)
{
    int ret = 0;
#if 0 //flush all
    for (int i = 0; i < sizeof(mem_list) / sizeof(struct mem_list_t); i++)
    {
        ret = ar_ion_cache_invalid_by_range(ion_mem_info[mem_list[i].mem_name].va, 
                                    ion_mem_info[mem_list[i].mem_name].va, 
                                    ion_mem_info[mem_list[i].mem_name].len);
        if(ret < 0){
            printf("cache_invalid filed. mem is %d\n", i);
            return ret;
        }
    }
#else
    ret = ar_ion_cache_invalid_by_range(ion_mem_info[mem_list[usr_ion_mem_num].mem_name].va, 
                                    ion_mem_info[mem_list[usr_ion_mem_num].mem_name].va, 
                                    ion_mem_info[mem_list[usr_ion_mem_num].mem_name].len);
    if(ret < 0){
        printf("cache_invalid filed. mem is %d\n", usr_ion_mem_num);
        return ret;
    }
#endif
    return ret;
}



/* 
    ION mem 底层执行申请 
    申请成功后得到memory的虚拟地址(va)和物理地址(pa),并清空一次mem
    返回值: -1:失败，0：成功
*/
int do_alloc_ion(param_ion_mellc_t *mem, uint32_t len)
{
    mem->len = len;

    if (mem->len)
    {
        //allocte mem
        AR_GET_ION_MEMORY(mem->va, mem->pa, mem->len);
        if (NULL == mem->va || NULL == mem->pa)
        {
            printf("Unable to allocate memory,length is 0x%x\n", mem->len);
            return -1;
        }
        // clear mem
        memset(mem->va, 0, len);
        printf("input va %x pa %x length %x\r\n\n", mem->va, mem->pa, mem->len);
    }
    return 0;
}

// size为0时，返回file size
int ar_load_file(char *path, char *buf, int size)
{
    FILE *pFile = 0;
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

int ar_dump_file(char *path, char *buf, int size)
{
    int w_fd;

    w_fd = open(path, O_RDWR | O_CREAT);
    if (w_fd < 0)
    {
        printf("open file error\n");
        return -1;
    }

    write(w_fd, buf, size);
    // free(buf);
    close(w_fd);
    printf("");
    return 0;
}

static int load_calib_file_t(char *calibParamFile)
{
    char *calibFile;
    int count = 0;
    CALIB_PARAM_FILE_ST_t *ar9201_tof_param_ptr = (CALIB_PARAM_FILE_ST_t *)ion_mem_info[TOF_temp_MEM].va;

    calibFile = (char *)calibParamFile;
    FILE *fp = fopen(calibFile, "rb");
    if (fp == NULL)
    {
        printf("open %s fail!\n", calibFile);
        return -1;
    }

    count = fread(ar9201_tof_param_ptr, 1, sizeof(CALIB_PARAM_FILE_ST_t), fp);
    fclose(fp);
    printf("OB_DSP_LOAD_REF cmd ok,read file size=%d,need size=%d.\n", count, sizeof(CALIB_PARAM_FILE_ST_t));
    return 0;
}

//计算depth coef
#define Q22_IDENTY        (0x01 << 22) //4094304
#define Q22_INV_FLOAT      (0.0000002384185791015625‬f)
#define Q22_SHIGT_BIT      (28)
#define Q22_IDENTY_HALF      (0x01 << 21) //4094304/2
#define FLOAT2Q22(x)      (int)((x * (float)Q22_IDENTY + 0.5f))

int dist2DepthCof(void *depth_coef,void *g_tof_params)
{
  ObToFParam *tof_param_ = (ObToFParam *)g_tof_params;
  //<-----------------------------------------------------------
  uint32_t *depth_coef_q22  = (uint32_t *)depth_coef;
  float       f        = sqrtf(tof_param_->ir_intrin.fx*tof_param_->ir_intrin.fy);
  int        width      = tof_param_->ir_intrin.width;
  int        height      = tof_param_->ir_intrin.height;
  float      fr        = 0;

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
       int delta_u = j - tof_param_->ir_intrin.cx;
         int delta_v = i - tof_param_->ir_intrin.cy;

      fr = sqrtf(delta_u*delta_u + delta_v*delta_v + f*f);
      *depth_coef_q22++ = FLOAT2Q22(f/fr);
    }
  }
  //-------------------------- --------------------------------->
//   tof_param_->depthCof = depth_coef;
  printf("dist2DepthCof success!\n");
  return 0;
}

//解析标定文件, DepthParams.bin大小1.2M，解析后得到TOF所有标定内参
#define depth_file_name "/usrdata/usr/data/arstack/dsp_parms/DepthParams.bin"
int parser_depth_parms(char *fname, void *dst_buf)
{
    ObToFParam *tof_param = (ObToFParam *)dst_buf;
    ParamParseErr ret = LoadToFCalibrationParams(fname, tof_param);
    if (PARAM_PARSE_OK != ret)
    {
        return -1;
    }
    printf("parser success!\n");
    return 0;
}

/* 将解析后的ObToFParam参数存放为数组，保证指针的物理地址正确 */
#define check_file_name "/usrdata/usr/data/arstack/dsp_parms/checkParams.bin"
void saveParam(void *ionbuf, void *tof_param, uint32_t *depth_coef, int dstWidth, int dstHeight, char *path)
{
    int dbg;
    CALIB_PARAM_FILE_ST_t *calib_param_for_dsp = ionbuf;//数组保存ionbuffer
    ObToFParam *tof_param_ = tof_param;

    calib_param_for_dsp->width = 1280;
    calib_param_for_dsp->height = 960;

    memcpy(&calib_param_for_dsp->hdr,               &tof_param_->hdr, sizeof(ObTofHeader));
    memcpy(&calib_param_for_dsp->dev_info,          &tof_param_->dev_info, sizeof(ObToFDeviceInfo));
    memcpy(&calib_param_for_dsp->ir_intrin,         &tof_param_->ir_intrin, sizeof(ObToFIRIntrinsic));
    memcpy(&calib_param_for_dsp->distort,           &tof_param_->distort, sizeof(ObDistoCoeffs));
    memcpy(&calib_param_for_dsp->sensor_param[0],   &tof_param_->sensor_param[0], 2 * sizeof(ObToFSensorParams));

    //ObToFTempCompensation temp_comp[0];
    calib_param_for_dsp->vcsel_coeff_size_0             = tof_param_->temp_comp[0].vcsel_coeff_size;
    calib_param_for_dsp->sensor_coeff_size_0            = tof_param_->temp_comp[0].sensor_coeff_size;
    calib_param_for_dsp->vcsel_temp_comp_coeff_0[0]     = tof_param_->temp_comp[0].vcsel_temp_comp_coeff[0];
    calib_param_for_dsp->sensor_temp_comp_coeff_0[0]    = tof_param_->temp_comp[0].sensor_temp_comp_coeff[0];
    calib_param_for_dsp->temp_dist_offset_0             = tof_param_->temp_comp[0].temp_dist_offset;

    //ObToFTempCompensation temp_comp[1];
    calib_param_for_dsp->vcsel_coeff_size_1             = tof_param_->temp_comp[1].vcsel_coeff_size;
    calib_param_for_dsp->sensor_coeff_size_1            = tof_param_->temp_comp[1].sensor_coeff_size;
    calib_param_for_dsp->vcsel_temp_comp_coeff_1[0]     = tof_param_->temp_comp[1].vcsel_temp_comp_coeff[0];
    calib_param_for_dsp->sensor_temp_comp_coeff_1[0]    = tof_param_->temp_comp[1].sensor_temp_comp_coeff[0];
    calib_param_for_dsp->temp_dist_offset_1             = tof_param_->temp_comp[1].temp_dist_offset;

	//ObToFDistanceCalib dist_calib[0];// ==> 转化为连续内存
    calib_param_for_dsp->phase_offset0                  = tof_param_->dist_calib[0].phase_offset; 
    calib_param_for_dsp->wiggling_lut_size0             = tof_param_->dist_calib[0].wiggling_lut_size; 
    calib_param_for_dsp->fppn_lut_size0                 = tof_param_->dist_calib[0].fppn_lut_size;
    calib_param_for_dsp->fppn_lut_size0                 = tof_param_->dist_calib[0].fppn_lut_size; 
    calib_param_for_dsp->fppn_offset0                   = tof_param_->dist_calib[0].fppn_offset;
    calib_param_for_dsp->fppn_slope_lut_size0           = tof_param_->dist_calib[0].fppn_slope_lut_size;
    memcpy(calib_param_for_dsp->wiggling_lut0,  tof_param_->dist_calib[0].wiggling_lut,     tof_param_->dist_calib[0].wiggling_lut_size * sizeof(int16_t));
    memcpy(calib_param_for_dsp->fppn_lut0,      tof_param_->dist_calib[0].fppn_lut,         tof_param_->dist_calib[0].fppn_lut_size * sizeof(int16_t));
    #if 0 //have no fppn_slope
    if(tof_param_->dist_calib[0].fppn_slope_lut) //没有倾斜参数时，防止内存泄露
        memcpy(calib_param_for_dsp->fppn_slop_lut0, tof_param_->dist_calib[0].fppn_slope_lut,   tof_param_->dist_calib[0].fppn_slope_lut_size * sizeof(int16_t));
    #endif

    //ObToFDistanceCalib dist_calib[1];// ==> 转化为连续内存
    calib_param_for_dsp->phase_offset1                  = tof_param_->dist_calib[0].phase_offset; 
    calib_param_for_dsp->wiggling_lut_size1             = tof_param_->dist_calib[0].wiggling_lut_size; 
    calib_param_for_dsp->fppn_lut_size1                 = tof_param_->dist_calib[0].fppn_lut_size;
    calib_param_for_dsp->fppn_lut_size1                 = tof_param_->dist_calib[0].fppn_lut_size; 
    calib_param_for_dsp->fppn_offset1                   = tof_param_->dist_calib[0].fppn_offset;
    calib_param_for_dsp->fppn_slope_lut_size1           = tof_param_->dist_calib[0].fppn_slope_lut_size;
    memcpy(calib_param_for_dsp->wiggling_lut1,  tof_param_->dist_calib[1].wiggling_lut,     tof_param_->dist_calib[1].wiggling_lut_size * sizeof(int16_t));
    memcpy(calib_param_for_dsp->fppn_lut1,      tof_param_->dist_calib[1].fppn_lut,         tof_param_->dist_calib[1].fppn_lut_size * sizeof(int16_t));
    #if 0 //have no fppn_slope
    if(tof_param_->dist_calib[0].fppn_slope_lut) //没有倾斜参数时，防止内存泄露
        memcpy(calib_param_for_dsp->fppn_slop_lut1, tof_param_->dist_calib[1].fppn_slope_lut,   tof_param_->dist_calib[1].fppn_slope_lut_size * sizeof(int16_t));
    #endif
    
    //ObTofFilterConfig
    memset(&calib_param_for_dsp->filterCfg, 0, sizeof(ObTofFilterConfig));
    //depthCfg
    memset(&calib_param_for_dsp->depthCfg, 0, sizeof(DepthConfigParam));
    calib_param_for_dsp->depthCfg.depth_uint = 0.1;
    calib_param_for_dsp->depthCfg.max_depth = 6000.0;
    calib_param_for_dsp->depthCfg.min_depth = 150.0;
    //depth coef
    memcpy(&calib_param_for_dsp->depth_coff[0], depth_coef, dstWidth * dstHeight * sizeof(int32_t));
    //ionbuffer
    calib_param_for_dsp->buf = ion_mem_info[TOF_DspUse_MEM].pa;
    //
    calib_param_for_dsp->phase_low_nshl_src = NULL;		// 低频non_shuffle相位帧数据
	calib_param_for_dsp->phase_low_shl_src = NULL;		// 低频shuffle相位帧数据
	calib_param_for_dsp->phase_high_nshl_src = NULL;	// 高频non_shuffle相位帧数据
	calib_param_for_dsp->phase_high_shl_src = NULL;		// 高频shuffle相位帧数据
    memset(&calib_param_for_dsp->tempParams, 0, sizeof(ObTofTempParams));// 相位帧组中温度参数
    calib_param_for_dsp->integration_time = 0;          //积分时间，实时更新
	calib_param_for_dsp->multiplex = 0;// 是否开启帧复用， 1 复用， 0 非复用

    //ObTofOutputs
    calib_param_for_dsp->amp_low	= ion_mem_info[TOF_amp_low_MEM].pa; 		// 低频幅值帧数据
	calib_param_for_dsp->amp_high	= ion_mem_info[TOF_amp_high_MEM].pa;		// 高频幅值帧数据
	calib_param_for_dsp->depth0		= ion_mem_info[TOF_depth0_MEM].pa;  		// 深度帧数据第一帧
	calib_param_for_dsp->depth1		= ion_mem_info[TOF_depth1_MEM].pa;  		// 深度帧数据第二帧
	calib_param_for_dsp->ir_0       = ion_mem_info[TOF_ir_0_MEM].pa;          	// ir数据第一帧
	calib_param_for_dsp->ir_1       = ion_mem_info[TOF_ir_1_MEM].pa;            // ir数据第二帧
    
    calib_param_for_dsp->status = -1;				    // dsp状态信息，初始化为-1，正确输出为0	
	calib_param_for_dsp->cost_times = 0;			// dsp每计算一个深度耗费的时间，单位是us，初始化为0
    memset(&calib_param_for_dsp->dsp_version, 0, sizeof(ob_version_t));// dsp版本号
    calib_param_for_dsp->dsp_version.major          = 1;
    calib_param_for_dsp->dsp_version.minor          = 0;
    calib_param_for_dsp->dsp_version.patch_level    = 0;
    calib_param_for_dsp->dsp_version.build          = 1;
	
#if 1 // if need check params
    ar_dump_file(path, (char *)calib_param_for_dsp, sizeof(CALIB_PARAM_FILE_ST_t));
#endif
}


/* 标定参数解析并保存ION内存 */
int dspParam2ion(char *fname, void *ionmem, char *cfname)
{
    int ret;
    ObToFParam tof_param_;
    uint32_t  *depth_coef = NULL;

    //1，从标定文件解析出内参 tof_param_
    ret = parser_depth_parms(fname, &tof_param_);
    if(ret < 0){
        printf("parser failed!\n");
        return ret;
    }
    //2，根据标定内参计算 depth_coef
    depth_coef = (uint32_t *)malloc(640 * 480 * sizeof(int32_t));//fixme: 2020-07-18，current dsp need size
    if(!depth_coef){
        printf("depth_coef malloc memeory out!\n");
        return -1;
    }
    dist2DepthCof(depth_coef, &tof_param_);
    //3，将tof_param_，depth_coef保存为数组(指针地址连续)
    //4，将数组保存到ION内存
    saveParam(ionmem, &tof_param_, depth_coef, 640, 480, cfname);
    //5，释放 tof_param_
    ObToFParamsFree();
    free(depth_coef);
    printf("dspParam2ion complete!\n");
    return 0;
}

/*	
	先写文件(到本地)再读文件(到ion),写多少读多少
	ion_pa 存入ion时的物理地址
    size /byte
*/
int dspParams_handle(void *src, size_t size, FILE * stream, void *ionbuf, uint32_t *pa)
{
	static long int offset = 0; //每次读完更新一次
	param_ion_mellc_t *ion_mem = (param_ion_mellc_t *)ionbuf;
	
	offset = ftell(stream);//update cur file ptr
	//DBG("start write file locate at %d\n", offset);
	
	//1,save to local-->write
	fseek(stream, offset, SEEK_SET);
    if(1 != fwrite(src, size, 1, stream))
	{
		ERR("fwrite failed.\n");
		return -1;
	}
	//2,save to ion--->read
    fseek(stream, offset, SEEK_SET);
	//DBG("start read file locate at %d\n", ftell(stream));
    char *va = ion_mem->va + offset;
    if(1 != fread(va, size, 1, stream))
    {
        ERR("fread failed.\n");
		return -1;
    }
	//3,save physic address to pa
	*pa = ion_mem->pa + offset;
    //DBG("src virtual address in ION is %p\n", va);
	//DBG("src physic address in ION is %p\n", *pa);
	
	offset = ftell(stream);//update cur file ptr
	//DBG("after read file locate at %d\n", offset);
    //printf("------------------------end\n");
	return 0;
}


/* tofdspParams 默认初始化一次 */
int dsp_params_deinit(ObTofDspParams *p_dsp_params)
{
    int ret;
    int o_hei = 960;
    int o_wid = 1280;
    int test;

    ObToFParam *tof_param_ = &p_dsp_params->inputs.constInputs.calibParams;

    memset(p_dsp_params, 0, sizeof(ObTofDspParams)); // if allocted mem has been cleaned, no need to do this
    //-----------------------解析标定内参.bin文件-------------------------------------------
#if 0
    ret = dspParam2ion(depth_file_name, ion_mem_info[TOF_temp_MEM].va, check_file_name);
    if(ret < 0)
        return ret;

    CALIB_PARAM_FILE_ST_t *calib_params_buf_v = ion_mem_info[TOF_temp_MEM].va;
    CALIB_PARAM_FILE_ST_t *calib_params_buf_p = ion_mem_info[TOF_temp_MEM].pa;
    //------------------------------p_dsp_params->inputs-----------------------------------

    //calibParams
    p_dsp_params->inputs.constInputs.width = calib_params_buf_v->width;
    p_dsp_params->inputs.constInputs.height = calib_params_buf_v->height;

    //ObTofHeader ..to ObToFSensorParams 
    memcpy(&tof_param_->hdr,            &calib_params_buf_v->hdr,                sizeof(ObTofHeader));
    memcpy(&tof_param_->dev_info,       &calib_params_buf_v->dev_info,           sizeof(ObToFDeviceInfo));
    memcpy(&tof_param_->ir_intrin,      &calib_params_buf_v->ir_intrin,          sizeof(ObToFIRIntrinsic));
    memcpy(&tof_param_->distort,        &calib_params_buf_v->distort,            sizeof(ObDistoCoeffs));
    memcpy(&tof_param_->sensor_param[0],&calib_params_buf_v->sensor_param[0],    2 * sizeof(ObToFSensorParams));

    //ObToFTempCompensation temp_comp[0];
    tof_param_->temp_comp[0].vcsel_coeff_size          =    calib_params_buf_v->vcsel_coeff_size_0;            
    tof_param_->temp_comp[0].sensor_coeff_size         =    calib_params_buf_v->sensor_coeff_size_0;          
    tof_param_->temp_comp[0].vcsel_temp_comp_coeff     =    calib_params_buf_p->vcsel_temp_comp_coeff_0;    
    tof_param_->temp_comp[0].sensor_temp_comp_coeff    =    calib_params_buf_p->sensor_temp_comp_coeff_0;   
    tof_param_->temp_comp[0].temp_dist_offset          =    calib_params_buf_v->temp_dist_offset_0;
    //ObToFTempCompensation temp_comp[1];
    tof_param_->temp_comp[1].vcsel_coeff_size          =    calib_params_buf_v->vcsel_coeff_size_1;            
    tof_param_->temp_comp[1].sensor_coeff_size         =    calib_params_buf_v->sensor_coeff_size_1;          
    tof_param_->temp_comp[1].vcsel_temp_comp_coeff     =    calib_params_buf_p->vcsel_temp_comp_coeff_1;    
    tof_param_->temp_comp[1].sensor_temp_comp_coeff    =    calib_params_buf_p->sensor_temp_comp_coeff_1;   
    tof_param_->temp_comp[1].temp_dist_offset          =    calib_params_buf_v->temp_dist_offset_1; 

    //ObToFDistanceCalib dist_calib[0];
    tof_param_->dist_calib[0].phase_offset          =     calib_params_buf_v->phase_offset0;      
    tof_param_->dist_calib[0].wiggling_lut_size     =     calib_params_buf_v->wiggling_lut_size0;
    tof_param_->dist_calib[0].fppn_lut_size         =     calib_params_buf_v->fppn_lut_size0;      
    tof_param_->dist_calib[0].fppn_lut_size         =     calib_params_buf_v->fppn_lut_size0;     
    tof_param_->dist_calib[0].fppn_offset           =     calib_params_buf_v->fppn_offset0;        
    tof_param_->dist_calib[0].fppn_slope_lut_size   =     calib_params_buf_v->fppn_slope_lut_size0;
    // ****use pysical address****
    tof_param_->dist_calib[0].wiggling_lut          =     calib_params_buf_p->wiggling_lut0;
    tof_param_->dist_calib[0].fppn_lut              =     calib_params_buf_p->fppn_lut0;
    // tof_param_->dist_calib[0].fppn_slope_lut        =     calib_params_buf_p->fppn_slop_lut0;

    //ObToFDistanceCalib dist_calib[0];
    tof_param_->dist_calib[1].phase_offset          =     calib_params_buf_v->phase_offset1;      
    tof_param_->dist_calib[1].wiggling_lut_size     =     calib_params_buf_v->wiggling_lut_size1;
    tof_param_->dist_calib[1].fppn_lut_size         =     calib_params_buf_v->fppn_lut_size1;      
    tof_param_->dist_calib[1].fppn_lut_size         =     calib_params_buf_v->fppn_lut_size1;     
    tof_param_->dist_calib[1].fppn_offset           =     calib_params_buf_v->fppn_offset1;        
    tof_param_->dist_calib[1].fppn_slope_lut_size   =     calib_params_buf_v->fppn_slope_lut_size1;
    // ****use pysical address****
    tof_param_->dist_calib[1].wiggling_lut          =     calib_params_buf_p->wiggling_lut1;
    tof_param_->dist_calib[1].fppn_lut              =     calib_params_buf_p->fppn_lut1;
    // tof_param_->dist_calib[1].fppn_slope_lut        =     calib_params_buf_p->fppn_slop_lut1;


    //depthcfg
    p_dsp_params->inputs.constInputs.depthCfg.depth_uint = calib_params_buf_v->depthCfg.depth_uint;
    p_dsp_params->inputs.constInputs.depthCfg.max_depth = calib_params_buf_v->depthCfg.max_depth;
    p_dsp_params->inputs.constInputs.depthCfg.min_depth = calib_params_buf_v->depthCfg.min_depth;
    //filtercfg
    memcpy(&p_dsp_params->inputs.constInputs.filterCfg, &calib_params_buf_v->filterCfg, sizeof(ObTofFilterConfig));


    //depth coef
    p_dsp_params->inputs.constInputs.depth_coef     =     calib_params_buf_p->depth_coff;

    // dsp 使用空间
    p_dsp_params->inputs.constInputs.buf = calib_params_buf_v->buf;//ion_mem_info[TOF_DspUse_MEM].pa; 

    //**frameInputs
    //1 temperature
    p_dsp_params->inputs.frameInputs.tempParams.sensor_temp_high    = calib_params_buf_v->tempParams.sensor_temp_high;//49.6365; //要实时更新
    p_dsp_params->inputs.frameInputs.tempParams.sensor_temp_low     = calib_params_buf_v->tempParams.sensor_temp_low;//49.6365;  //要实时更新
    p_dsp_params->inputs.frameInputs.tempParams.vcsel_temp_high     = calib_params_buf_v->tempParams.vcsel_temp_high;//49.6365;  //要实时更新
    p_dsp_params->inputs.frameInputs.tempParams.vcsel_temp_low      = calib_params_buf_v->tempParams.vcsel_temp_low;//49.6365;   //要实时更新
    p_dsp_params->inputs.frameInputs.integration_time               = calib_params_buf_v->integration_time;
    //2 phase cam source*
    p_dsp_params->inputs.frameInputs.phase_high_nshl_src    = calib_params_buf_v->phase_high_nshl_src; //初始地址，通过ring-buffer管理
    p_dsp_params->inputs.frameInputs.phase_high_shl_src     = calib_params_buf_v->phase_high_shl_src;  //初始地址，通过ring-buffer管理
    p_dsp_params->inputs.frameInputs.phase_low_nshl_src     = calib_params_buf_v->phase_low_nshl_src;  //初始地址，通过ring-buffer管理
    p_dsp_params->inputs.frameInputs.phase_low_shl_src      = calib_params_buf_v->phase_low_shl_src;   //初始地址，通过ring-buffer管理

    //**multiplex帧复用
    p_dsp_params->inputs.multiplex = calib_params_buf_v->multiplex; //无复用

    //------------------------------p_dsp_params->outputs-----------------------------------
    p_dsp_params->outputs.status = calib_params_buf_v->status;
    p_dsp_params->outputs.cost_times = calib_params_buf_v->cost_times;
    memcpy(&p_dsp_params->outputs.dsp_version, &calib_params_buf_v->dsp_version, sizeof(ob_version_t));

    p_dsp_params->outputs.amp_low   = calib_params_buf_v->amp_low;  //初始地址，通过ring-buffer管理
    p_dsp_params->outputs.amp_high  = calib_params_buf_v->amp_high; //初始地址，通过ring-buffer管理
    p_dsp_params->outputs.depth0    = calib_params_buf_v->depth0;   //初始地址，通过ring-buffer管理
    p_dsp_params->outputs.depth1    = calib_params_buf_v->depth1;   //初始地址，通过ring-buffer管理
    p_dsp_params->outputs.ir_0      = calib_params_buf_v->ir_0;     //初始地址，通过ring-buffer管理
    p_dsp_params->outputs.ir_1      = calib_params_buf_v->ir_1;     //初始地址，通过ring-buffer管理
#else
    //2020-08-06 new method
    /*
        1，按照ObTofDspParams结构初始化
        2，将非指针变量直接赋值(或者用.bin解析后的变量赋值)
        3，按通信结构顺序存文件ObTofDspParams_ExpandFile，操作包括：
            3.1，非指针变量赋值后，直接存
            3.2，指针变量展开，按照size大小存入文件
        4，展开的通信结构全部存储成文件之后，将文件读取到ION内存：ION_dsp_all_params_mem，一直不要释放
        5，给通信结构ObTofDspParams中的指针赋值(上面步骤常量已经赋值)，注意定位到 ION_dsp_all_params_mem 的指针展开的起始地址(这个地址在写文件时记录偏移值)
        6，发送带指针的ObTofDspParams给dsp
    */

    //------------------------------p_dsp_params->inputs-----------------------------------
    #define filename "/mnt/ObTofDspParams_ExpandFile.bin" //save params local address 
    void *load_ion = &ion_mem_info[TOF_temp_MEM];//save params ION memory
    uint32_t parames_pa;//ion params Physic address
    ObToFParam tof_param_par;
    uint32_t  *depth_coef = NULL;
    
    //-----------------------解析标定文件以及计算depth coef-----------------------------
    //1，从标定文件解析出内参 tof_param_
    ret = parser_depth_parms(depth_file_name, &tof_param_par);
    if(ret < 0){
        ERR("parser failed!\n");
        return ret;
    }
    //2，根据标定内参计算 depth_coef
    depth_coef = (uint32_t *)malloc(640 * 480 * sizeof(int32_t));//fixme: 2020-07-18，current dsp need size
    if(!depth_coef){
        ERR("depth_coef malloc memeory out!\n");
        return -1;
    }
    dist2DepthCof(depth_coef, &tof_param_par);
    //---------------------------解析end----------------------------------------------
    //参数校对
    FILE *fp_w = NULL; // open file for write ObTofDspParams_ExpandFile
    fp_w = fopen(filename, "a+b");//a+b 追加方式，重启最好删除文件
    if (fp_w == NULL)
    {
        ERR("open %s fail.\n", filename);
        return -1;
    }
    fseek(fp_w, 0L, SEEK_SET);

//ObTofConstInputs
    p_dsp_params->inputs.constInputs.width = 1280;
    p_dsp_params->inputs.constInputs.height = 960;
//ObToFParam
    memcpy(&tof_param_->hdr,            &tof_param_par.hdr,                sizeof(ObTofHeader));
    memcpy(&tof_param_->dev_info,       &tof_param_par.dev_info,           sizeof(ObToFDeviceInfo));
    memcpy(&tof_param_->ir_intrin,      &tof_param_par.ir_intrin,          sizeof(ObToFIRIntrinsic));
    memcpy(&tof_param_->distort,        &tof_param_par.distort,            sizeof(ObDistoCoeffs));
    memcpy(&tof_param_->sensor_param[0],&tof_param_par.sensor_param[0],    2 * sizeof(ObToFSensorParams));

    int this_size = 2 * sizeof(int) + sizeof(ObTofHeader) + sizeof(ObToFDeviceInfo) + 
                    sizeof(ObToFIRIntrinsic) + sizeof(ObDistoCoeffs) + 2 * sizeof(ObToFSensorParams);
    dspParams_handle(&p_dsp_params->inputs.constInputs.width, this_size, fp_w, load_ion, &parames_pa);
    
//ObToFTempCompensation temp_comp[2];
    for(int arr_nub = 0; arr_nub < 2; arr_nub++){
        this_size = 2 * sizeof(uint16_t);
        dspParams_handle(&tof_param_par.temp_comp[arr_nub].vcsel_coeff_size, this_size, fp_w, load_ion, &parames_pa);
        tof_param_->temp_comp[arr_nub].vcsel_coeff_size  = tof_param_par.temp_comp[arr_nub].vcsel_coeff_size;            
        tof_param_->temp_comp[arr_nub].sensor_coeff_size = tof_param_par.temp_comp[arr_nub].sensor_coeff_size;

        //展开vcsel_temp_comp_coeff指针
        this_size = tof_param_par.temp_comp[arr_nub].vcsel_coeff_size*sizeof(float);
        dspParams_handle(tof_param_par.temp_comp[arr_nub].vcsel_temp_comp_coeff, this_size, fp_w, load_ion, &parames_pa);
        tof_param_->temp_comp[arr_nub].vcsel_temp_comp_coeff = parames_pa;//通信结构指针-->物理地址
        //展开sensor_temp_comp_coeff指针
        this_size = tof_param_par.temp_comp[arr_nub].sensor_coeff_size*sizeof(float);
        dspParams_handle(tof_param_par.temp_comp[arr_nub].sensor_temp_comp_coeff, this_size, fp_w, load_ion, &parames_pa);
        tof_param_->temp_comp[arr_nub].sensor_temp_comp_coeff = parames_pa;//通信结构指针-->物理地址
    
        this_size = sizeof(float);
        dspParams_handle(&tof_param_par.temp_comp[arr_nub].temp_dist_offset, this_size, fp_w, load_ion, &parames_pa);
        tof_param_->temp_comp[arr_nub].temp_dist_offset = tof_param_par.temp_comp[arr_nub].temp_dist_offset;
    }

//ObToFDistanceCalib dist_calib[2];
    for(int arr_nub = 0; arr_nub < 2; arr_nub++){
        this_size = sizeof(float) + sizeof(uint32_t) + sizeof(uint32_t);
        dspParams_handle(&tof_param_par.dist_calib[arr_nub].phase_offset, this_size, fp_w, load_ion, &parames_pa);
        tof_param_->dist_calib[arr_nub].phase_offset          =     tof_param_par.dist_calib[arr_nub].phase_offset;      
        tof_param_->dist_calib[arr_nub].wiggling_lut_size     =     tof_param_par.dist_calib[arr_nub].wiggling_lut_size;
        tof_param_->dist_calib[arr_nub].fppn_lut_size         =     tof_param_par.dist_calib[arr_nub].fppn_lut_size;      
        //展开wiggling_lut指针
        this_size = tof_param_par.dist_calib[arr_nub].wiggling_lut_size * sizeof(int16_t);
        dspParams_handle(tof_param_par.dist_calib[arr_nub].wiggling_lut, this_size, fp_w, load_ion, &parames_pa);
        tof_param_->dist_calib[arr_nub].wiggling_lut = parames_pa;//通信结构指针-->物理地址
        //展开fppn_lut指针
        this_size = tof_param_par.dist_calib[arr_nub].fppn_lut_size * sizeof(int16_t);
        dspParams_handle(tof_param_par.dist_calib[arr_nub].fppn_lut, this_size, fp_w, load_ion, &parames_pa);
        tof_param_->dist_calib[arr_nub].fppn_lut = parames_pa;//通信结构指针-->物理地址

        this_size = sizeof(float) + sizeof(uint32_t);
        dspParams_handle(&tof_param_par.dist_calib[arr_nub].fppn_offset, this_size, fp_w, load_ion, &parames_pa);
        tof_param_->dist_calib[arr_nub].fppn_offset           =     tof_param_par.dist_calib[arr_nub].fppn_offset;        
        tof_param_->dist_calib[arr_nub].fppn_slope_lut_size   =     tof_param_par.dist_calib[arr_nub].fppn_slope_lut_size;
        //展开倾斜指针
        if(tof_param_par.dist_calib[arr_nub].fppn_slope_lut_size != 0){ //倾斜参数没有则不进行保存
            this_size = tof_param_par.dist_calib[arr_nub].fppn_slope_lut_size * sizeof(int16_t);
            dspParams_handle(tof_param_par.dist_calib[arr_nub].fppn_lut, this_size, fp_w, load_ion, &parames_pa);
            tof_param_->dist_calib[arr_nub].fppn_slope_lut  = parames_pa;//通信结构指针-->物理地址
        }
    }

//filtercfg, current no use,default 0
    this_size = sizeof(ObTofFilterConfig);
    dspParams_handle(&p_dsp_params->inputs.constInputs.filterCfg, this_size, fp_w, load_ion, &parames_pa);

//depthcfg
    p_dsp_params->inputs.constInputs.depthCfg.depth_uint =  0.1;
    p_dsp_params->inputs.constInputs.depthCfg.max_depth =   6000.0;
    p_dsp_params->inputs.constInputs.depthCfg.min_depth =   150.0;
    this_size = sizeof(ObTofFilterConfig);
    dspParams_handle(&p_dsp_params->inputs.constInputs.depthCfg, this_size, fp_w, load_ion, &parames_pa);

//depth coef
    this_size = 640 * 480 * sizeof(int32_t);
    dspParams_handle(depth_coef, this_size, fp_w, load_ion, &parames_pa);
    p_dsp_params->inputs.constInputs.depth_coef = parames_pa;

// dsp 使用空间
    p_dsp_params->inputs.constInputs.buf = ion_mem_info[TOF_DspUse_MEM].pa; 
    uint32_t dsp_buf_pa = p_dsp_params->inputs.constInputs.buf;
    this_size = sizeof(uint32_t);
    dspParams_handle(&dsp_buf_pa, this_size, fp_w, load_ion, &parames_pa);

//**frameInputs
    //1 temperature
    p_dsp_params->inputs.frameInputs.tempParams.sensor_temp_high    = 0; //不需要初始化，实时更新
    p_dsp_params->inputs.frameInputs.tempParams.sensor_temp_low     = 0; //不需要初始化，实时更新
    p_dsp_params->inputs.frameInputs.tempParams.vcsel_temp_high     = 0; //不需要初始化，实时更新
    p_dsp_params->inputs.frameInputs.tempParams.vcsel_temp_low      = 0; //不需要初始化，实时更新
    p_dsp_params->inputs.frameInputs.integration_time               = 0; //不需要初始化，实时更新
    this_size = sizeof(uint32_t) + sizeof(float) * 4;
    dspParams_handle(&p_dsp_params->inputs.frameInputs.tempParams.vcsel_temp_low, this_size, fp_w, load_ion, &parames_pa);

    //2 phase cam source*
    p_dsp_params->inputs.frameInputs.phase_high_nshl_src    = NULL; //不需要初始化，应用时指定
    p_dsp_params->inputs.frameInputs.phase_high_shl_src     = NULL; //不需要初始化，应用时指定
    p_dsp_params->inputs.frameInputs.phase_low_nshl_src     = NULL; //不需要初始化，应用时指定
    p_dsp_params->inputs.frameInputs.phase_low_shl_src      = NULL; //不需要初始化，应用时指定
    uint32_t phase_pa[4] = {0};
    this_size = sizeof(uint32_t) * 4;
    dspParams_handle(&phase_pa[0], this_size, fp_w, load_ion, &parames_pa);

    //**multiplex帧复用
    p_dsp_params->inputs.multiplex = 0; //无复用
    this_size = sizeof(int) * 4;
    dspParams_handle(&p_dsp_params->inputs.multiplex, this_size, fp_w, load_ion, &parames_pa);

    //------------------------------p_dsp_params->outputs-----------------------------------
    p_dsp_params->outputs.amp_low   = NULL; //不需要初始化，应用时指定
    p_dsp_params->outputs.amp_high  = NULL; //不需要初始化，应用时指定
    p_dsp_params->outputs.depth0    = NULL; //不需要初始化，应用时指定
    p_dsp_params->outputs.depth1    = NULL; //不需要初始化，应用时指定
    p_dsp_params->outputs.ir_0      = NULL; //不需要初始化，应用时指定
    p_dsp_params->outputs.ir_1      = NULL; //不需要初始化，应用时指定
    uint32_t output_pa[6] = {0};
    this_size = sizeof(uint32_t) * 6;
    dspParams_handle(&output_pa[0], this_size, fp_w, load_ion, &parames_pa);

    p_dsp_params->outputs.cost_times = 0;
    //p_dsp_params->outputs.dsp_version；//dsp version信息从dsp获取，默认初始化为0
    p_dsp_params->outputs.status = -1;
    this_size = sizeof(uint32_t) + sizeof(int32_t) + sizeof(ob_version_t);
    dspParams_handle(&p_dsp_params->outputs.cost_times, this_size, fp_w, load_ion, &parames_pa);

    fclose(fp_w);
    ObToFParamsFree();
    free(depth_coef);
#endif
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
    /* 申请并清空memory */
    for (int i = 0; i < sizeof(mem_list) / sizeof(struct mem_list_t); i++)
    {
        if (do_alloc_ion(&ion_mem_info[mem_list[i].mem_name], mem_list[i].mem_len) < 0)
        {
            printf("[err]ION memory alloc failed!\n");
            return -1;
        }
    }
    printf("[ION] memory alloc Success!\n");

    /* --------------更新 tofdspParams------------------------ */
    dsp_params_deinit((ObTofDspParams *)ion_mem_info[TOF_DspParams_MEM].va);
    debug_info_tofparams_msg(ion_mem_info[TOF_DspParams_MEM].va); //printf and check

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

    return 0;
}

/* 释放所有申请的ION MEMORY */
int release_tof_buffer(void)
{
    /* 申请并清空memory */
    for (int i = 0; i < sizeof(mem_list) / sizeof(struct mem_list_t); i++)
    {
        if (AR_RELEASE_ION_MEMORY(ion_mem_info[mem_list[i].mem_name].va) < 0)
        {
            printf("[err]ION memory release failed!\n");
            return -1;
        }
    }
    printf("[ION] memory release Success!\n");
}

