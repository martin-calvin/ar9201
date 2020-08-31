#ifndef __AR_DSP_ALG_H__
#define __AR_DSP_ALG_H__

#ifdef __cplusplus
extern "C"{
#endif

#if defined(WIN32) || defined(X64)
#include "ar_dsp_rpc.h"
#endif

#include "ar_alg_define.h"
//This id is defined in dts, will be used by linux ion system,do not change it
#define AR_DSP_HEAP_ID  27

#define AR_DSP_ALG_RUN_SENSOR_IMG   1
#define AR_DSP_ALG_RUN_LOCAL_FILE   2
#define AR_DSP_DUMP_RESULTS         (1<<0)
#define AR_DSP_DUMP_STATS           (1<<1)
#define AR_DSP_DUMP_OSD           (1<<2)

#if defined(WIN32) || defined(X64)
#define F_OK   0
#define W_OK   2
#define R_OK   4
#define X_OK   6
#endif

#if defined(WIN32) || defined(X64)
#define snprintf _snprintf
#endif

#define REGISTER_BASE_ADDR 0x64570000

//Currently, we suppose max 64 objects per frame
#define AR_DSP_ALG_MAX_DETECT_OBJECTS  (64)

//Max 21 categories for standard mobilenetSSD
#define STD_SSD_MAX_CATEGORIES  (21)

#define FACE_FEATURE_POINT_NUM  5

#define VIDEO_DEVICE_0  "/dev/video_yuv-1"

#ifdef ENABLE_SWEEPER_OPTION
#define COMP_OSD_DEVICE "/dev/user_compositor-1"
#else
#define COMP_OSD_DEVICE "/dev/user_compositor-0"
#endif


#define SWEEPER_VIDEO_DEVICE "/dev/video_yuv-1.2"

#define RGB_RAW_DATA_FILE     1
#define BGR_RAW_DATA_FILE     2
#define JPG_BMP_PNG_IMG_FILE  3
#define INVALID_IMG_FILE      (-1)

#if defined(WIN32) || defined(X64)
#define MEASURE_TIME(x)
#else
#define MEASURE_TIME(x) \
do{ \
	struct timeval tv; \
	gettimeofday(&tv, NULL); \
	x = tv.tv_sec * 1000 + tv.tv_usec / 1000; \
} while (0)
#endif

//Only for test
typedef struct
{
	int input_param;
	int return_val;
} AR_USR_DATA_TEST_st;

//parse ini network structure
typedef struct
{
	//network section name
	char section[32];

	//this is a .txt file which include the local image file name inside it.
	char local_img_directory[FILE_PATH_STR_LEN];

	int input_source; //sensor or local img
	AR_DSP_CNN_CFG_st cnn_cfg;
} INI_CNN_CFG_st;

typedef struct
{
	int dsp_id;
	int dsp_run;
	int demo_type;
	char demo_name[32];
	char inifile[FILE_PATH_STR_LEN]; //ini file name

	//Used by CDNN to accelerate inference
	unsigned long cdnn_sram_heap_start; //sram address, if not available, will malloc from DDR
	unsigned long cdnn_sram_heap_size;
	//The size of external memory used by CDNN lib
	int cdnn_ext_mem_size;

#ifdef ENABLE_SWEEPER_OPTION
	char camera_param_file[FILE_PATH_STR_LEN];
#endif

	INI_CNN_CFG_st ini_cnn_cfg[AR_DSP_ALG_MAX_NN_PER_DSP];
	char dev_name[32];

	//add whatever you want
} THREAD_PARAM_st;

typedef struct
{
	int dump_ctrl;
	int loglevel;

	//0, 1, 2, 3, -1
	int who_load_weight_data;

} SYS_CONFIG_st;

typedef struct
{
	int index;
	int label_index;
	char label[256];
	float score;
	AR_RECT_st rect;
} AR_DSP_DETECT_OBJ_st;

typedef struct
{
	int object_num;
	AR_DSP_DETECT_OBJ_st objects[AR_DSP_ALG_MAX_DETECT_OBJECTS];
} AR_DSP_DETECT_RESULTS_st;

//Sweeper SSD calculated results
typedef struct {
	int index;
	float score;
	float distance;
	float left_angle;
	float right_angle;
} AR_ALG_OBSTACLE_st;


#define AR_GET_ION_MEMORY(VA, PA, SIZE) \
do{ \
	unsigned int flag = 1; \
	VA = (unsigned char *)ar_ion_malloc_ex(SIZE,flag); \
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

#define AR_RELEASE_ION_MEMORY(VA) ar_ion_free(VA)

extern SYS_CONFIG_st g_sys_cfg;
#define AR_PRINTF_ERR(fmt, ...) \
do{\
	if(g_sys_cfg.loglevel>=DSP_LOG_LEVEL_ERR) \
	{\
		printf("[ERR]%s,line %d: "fmt"\n",__FUNCTION__, __LINE__, ##__VA_ARGS__);\
		fflush(stdout);\
	}\
}while(0)

#define AR_PRINTF_DEBUG(fmt, ...) \
do{\
	if(g_sys_cfg.loglevel>=DSP_LOG_LEVEL_DEBUG) \
	{\
		printf("[DBG]%s,line %d: "fmt"\n",__FUNCTION__,__LINE__, ##__VA_ARGS__);\
		fflush(stdout);\
	}\
}while(0)

//=============mtcnn================

#define sample_max(x,y) ((x)>(y)?(x):(y))
#define sample_min(x,y) ((x)>(y)?(y):(x))




	//#define SOURCE_IMAG_SIZE_W		(1280)
	//#define SOURCE_IMAG_SIZE_H		(768)
#define SOURCE_IMAG_SIZE_W 		(640)
#define SOURCE_IMAG_SIZE_H 		(480)

	//#define PNET_ORG_SIZE_140x84_W	(140)
	//#define PNET_ORG_SIZE_140x84_H	(84)
	//#define PNET_OPT_SIZE_110x150_W	(110)
	//#define PNET_OPT_SIZE_110x150_H	(150)
	//pnet re-design
#define PNET_ORG_SIZE_140x84_W    (160)
#define PNET_ORG_SIZE_140x84_H    (120)
#define PNET_OPT_SIZE_110x150_W   (112)
#define PNET_OPT_SIZE_110x150_H   (189)

#define RNET_OPT_SIZE_192x192_W   (192)
#define RNET_OPT_SIZE_192x192_H   (192)

#define ONET_OPT_SIZE_192x192_W   (192)
#define ONET_OPT_SIZE_192x192_H   (192)

#define MAX_RECTBOX_SIZE (500)
#define MAX_BOX_NUM_RNET (64)
#define MAX_RNET_NUM	 (3)
#define MAX_BOX_NUM_ONET (16)
#define MAX_ONET_NUM	 (2)




#define MAX_FEATURE_SIZE (MAX_BOX_NUM_ONET * MAX_ONET_NUM)


#define PNET_FULL_CONVLUTION (0)
#define BOX_MINU_ADJUST (0)
#define ADAPT_FOR_RUIWEI (0)

#if defined(WIN32) || defined(X64)
#define PERF_STATIS      (0)
#define BOXES_SORT_PRINT (1)
#else

#define PERF_STATIS      (0)
#define BOXES_SORT_PRINT (0)
#endif

//#if (PERF_STATIS)
#define DATA_SET_SIZE    (2922)
//#endif



typedef struct {
	int dynamic;
	int width;
	int height;
	int channel;
	int stride;
	int format;
	unsigned char* buffer;
	unsigned char *r;
	unsigned char *g;
	unsigned char *b;
	int size;
}SAMPLE_PICTURE_T;

typedef struct {
	int width;
	int height;
	int channel;
	int format;
}SAMPLE_PICATTR_T;

typedef struct {
	float x;
	float y;
}FEATURE_RECORD_T;

typedef struct {
	FEATURE_RECORD_T records[10];
	float shapes[20];
	int count;
	float score;
}SAMPLE_FEATURE_T;

typedef struct SAMPLE_RECTBOX_T{
	int valid;
	int index;
	float x1;
	float y1;
	float x2;
	float y2;
	float width;
	float height;
	float area;
	float score;
	int label_index;
	char label[32];
	SAMPLE_FEATURE_T* feature;
	struct SAMPLE_RECTBOX_T* parent;
}SAMPLE_RECTBOX_T;

typedef struct {
	int order;
	float score;
} SAMPLE_ODSCORE_T;

typedef struct {

	void* swaped_buffer;
	int swaped_buffer_size;

	/*
#if defined(SIMULATION_WIN) || defined(SIMULATION_XM4)
#else
	yolo_output_st* label_display;
#endif
	 */

	SAMPLE_RECTBOX_T *boxs;
	int box_size;
	int box_count;

	SAMPLE_FEATURE_T *features;
	int feature_size;
	int feature_count;

	SAMPLE_ODSCORE_T *scores;
	int score_size;
	int score_count;

	SAMPLE_RECTBOX_T *temp_boxs;
	int temp_box_size;
	int temp_box_count;

	SAMPLE_FEATURE_T *temp_features;
	int temp_feature_size;
	int temp_feature_count;

	SAMPLE_ODSCORE_T*temp_scores;
	int temp_score_size;
	int temp_score_count;
}SAMPLE_CONTEXT_T;
void * pthread_run_std_mobilenet_ssd(void *arg);
void * pthread_run_network_evaluation(void *arg);
void * pthread_run_face_detect_test(void *arg);
void * pthread_run_mtcnn_test(void *arg);
void * ar_get_img_thread_func(void *arg);



#ifdef __cplusplus
}
#endif

#endif

