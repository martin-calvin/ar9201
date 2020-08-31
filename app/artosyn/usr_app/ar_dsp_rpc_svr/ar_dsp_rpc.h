/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _AR_DSP_RPC_H_RPCGEN
#define _AR_DSP_RPC_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


enum AR_DSP_IMG_FMT_ID_e {
	AR_DSP_IMG_FMT_YUV = 0x200,
	AR_DSP_IMG_FMT_BGR = 0x200 + 1,
	AR_DSP_IMG_FMT_RGB = 0x200 + 2,
	AR_DSP_IMG_FMT_MAX_ID = 0x200 + 3,
};
typedef enum AR_DSP_IMG_FMT_ID_e AR_DSP_IMG_FMT_ID_e;


enum AR_DSP_LOG_LVL_e {
	DSP_LOG_LEVEL_ERR = 0,
	DSP_LOG_LEVEL_WARNING = 0 + 1,
	DSP_LOG_LEVEL_NOTICE = 0 + 2,
	DSP_LOG_LEVEL_DEBUG = 0 + 3,
	DSP_LOG_LEVEL_MAX = 0 + 4,
};
typedef enum AR_DSP_LOG_LVL_e AR_DSP_LOG_LVL_e;


enum AR_DSP_ID_e {
	DSP_ID_0 = 0,
	DSP_ID_1 = 0 + 1,
	DSP_ID_2 = 0 + 2,
	DSP_ID_3 = 0 + 3,
	MAX_DSP_ID = 0 + 4,
};
typedef enum AR_DSP_ID_e AR_DSP_ID_e;


enum AR_CDNN_MEMORY_DATA_ORDER_e {
	AR_CDNN_MEMORY_DATAORDER_NWHC = 0,
	AR_CDNN_MEMORY_DATAORDER_NHWC = 1,
	AR_CDNN_MEMORY_DATAORDER_CWHN = 2,
	AR_CDNN_MEMORY_DATAORDER_CHWN = 3,
	AR_CDNN_MEMORY_DATAORDER_NCWH = 4,
	AR_CDNN_MEMORY_DATAORDER_NCHW = 5,
	AR_CDNN_MEMORY_DATAORDER_CNWH = 6,
	AR_CDNN_MEMORY_DATAORDER_CNHW = 7,
	AR_CDNN_MEMORY_DATAORDER_WHCN = 8,
	AR_CDNN_MEMORY_DATAORDER_HWCN = 9,
	AR_CDNN_MEMORY_DATAORDER_WHNC = 10,
	AR_CDNN_MEMORY_DATAORDER_HWNC = 11,
	AR_CDNN_MEMORY_DATAORDER_PUBLIC_SIZE = 12,
};
typedef enum AR_CDNN_MEMORY_DATA_ORDER_e AR_CDNN_MEMORY_DATA_ORDER_e;


enum AR_CDNN_BUFFER_DATA_TYPE_e {
	AR_CDNN_DATATYPE_U8 = 1,
	AR_CDNN_DATATYPE_S8 = 2,
	AR_CDNN_DATATYPE_U16 = 4,
	AR_CDNN_DATATYPE_S16 = 8,
	AR_CDNN_DATATYPE_U32 = 16,
	AR_CDNN_DATATYPE_S32 = 32,
	AR_CDNN_DATATYPE_F32 = 64,
	AR_CDNN_DATATYPE_F64 = 128,
};
typedef enum AR_CDNN_BUFFER_DATA_TYPE_e AR_CDNN_BUFFER_DATA_TYPE_e;


enum AR_CDNN_BUFFER_BIT_PRECISION_TYPE_e {
	AR_CDNN_PRECISION_8BIT = 8,
	AR_CDNN_PRECISION_16BIT = 16,
	AR_CDNN_PRECISION_32BIT = 32,
	AR_CDNN_PRECISION_64BIT = 64,
};
typedef enum AR_CDNN_BUFFER_BIT_PRECISION_TYPE_e AR_CDNN_BUFFER_BIT_PRECISION_TYPE_e;


struct AR_POINT_st {
	int x;
	int y;
};
typedef struct AR_POINT_st AR_POINT_st;


struct AR_RECT_st {
	int x;
	int y;
	int width;
	int height;
};
typedef struct AR_RECT_st AR_RECT_st;


struct AR_IMG_FMT_st {
	int width;
	int height;
	int channel;
	int format;
	int y_stride;
	int u_stride;
	int v_stride;
	char *y_addr;
	char *u_addr;
	char *v_addr;
	int size;
	char *rgbbuff;
};
typedef struct AR_IMG_FMT_st AR_IMG_FMT_st;


struct ArCdnnOutputBuffer {
	int width;
	int height;
	int nchannels;
	int nInputs;
	char buffer_name[128];
	int buffer_size;
	float *pdata;
};
typedef struct ArCdnnOutputBuffer ArCdnnOutputBuffer;


struct AR_SOFTMAX_THRD_st {
	char name[128];
	float threshold;
};
typedef struct AR_SOFTMAX_THRD_st AR_SOFTMAX_THRD_st;


struct AR_DSP_OUTPUT_st {
	int buffer_num;
	ArCdnnOutputBuffer output_buffer[16];
};
typedef struct AR_DSP_OUTPUT_st AR_DSP_OUTPUT_st;


struct AR_DSP_STATS_st {
	u_long cdnn_init_time;
	u_long cdnn_pre_proc_time;
	u_long cdnn_inference_time;
	u_long cdnn_post_proc_time;
};
typedef struct AR_DSP_STATS_st AR_DSP_STATS_st;


struct AR_CV_OPS_st {
	int cv_ops_bmp;
	AR_RECT_st roi;
	float landmark[64];
};
typedef struct AR_CV_OPS_st AR_CV_OPS_st;


typedef char *ar_callback_func;

struct AR_DSP_ALG_st {
	int dsp_id;
	int alg_type;
	int exit_code;
	AR_IMG_FMT_st input[4];
	AR_CV_OPS_st cv_ops;
	AR_DSP_OUTPUT_st output;
	AR_DSP_STATS_st statistics;
	ar_callback_func cb;
	char *data;
	char *user_data_pa;
};
typedef struct AR_DSP_ALG_st AR_DSP_ALG_st;


struct AR_CDNN_INPUT_PARAMS_st {
	u_int width;
	u_int height;
	u_int dataType;
	u_int depth;
	u_int nChannels;
	float scaleFactor;
	u_int dataOrder;
	u_int nInputs;
	u_int dataFlipped;
	u_int dataTransposed;
	int padding[4];
	char pLayerName[32];
	u_int bufferId;
};
typedef struct AR_CDNN_INPUT_PARAMS_st AR_CDNN_INPUT_PARAMS_st;


struct AR_DSP_USR_CFG_st {
	int operation_id;
	char *params;
};
typedef struct AR_DSP_USR_CFG_st AR_DSP_USR_CFG_st;


struct AR_DSP_CNN_CFG_st {
	int network_id;
	int network_type;
	int do_debug_logging;
	int do_profiling;
	int channel_swap;
	int raw_scale;
	int bw_reduction;
	int resize_input;
	int amend_flag;
	int block_size;
	int block_number;
	int block_interval;
	int num_of_inference;
	int max_width;
	int max_height;
	float bw_reduction_ratio;
	int num_inputs;
	int input_format[4];
	int input_buf_len[4];
	u_long input_buf[4];
	AR_CDNN_INPUT_PARAMS_st input_params[4];
	float output_threshold;
	char weight_file_path[128];
	u_long file_len;
	u_long load_addr;
	int len_of_buffer_for_pdata;
	u_long buffer_pa_for_pdata;
	u_long buffer_va_for_pdata;
	AR_SOFTMAX_THRD_st softmax_thrd[8];
	int resize_by_dsp;
	char *other_parameters;
};
typedef struct AR_DSP_CNN_CFG_st AR_DSP_CNN_CFG_st;


struct AR_DSP_CFG_st {
	u_long cdnn_sram_heap_start;
	int cdnn_sram_heap_size;
	u_long cdnn_ext_mem_addr;
	int cdnn_ext_mem_size;
	int dsp_log_level;
	int reserved;
	AR_DSP_CNN_CFG_st cnn_cfg[16];
	AR_DSP_USR_CFG_st user_cfg[16];
};
typedef struct AR_DSP_CFG_st AR_DSP_CFG_st;

#define MAX_INPUT_IMG_BUF_SIZE 2097152
#define MAX_OUTPUT_PDATA_SIZE 1048576
#define FILE_CHUNK_DATA_SIZE 1048576

struct AR_DSP_CFG_RPC_st {
	int dsp_id;
	AR_DSP_CFG_st dsp_cfg_st;
};
typedef struct AR_DSP_CFG_RPC_st AR_DSP_CFG_RPC_st;


struct AR_IMG_FMT_RPC_st {
	int width;
	int height;
	int channel;
	int format;
	int y_stride;
	int u_stride;
	int v_stride;
	char *y_addr;
	char *u_addr;
	char *v_addr;
	int size;
	char rgbbuff[MAX_INPUT_IMG_BUF_SIZE];
};
typedef struct AR_IMG_FMT_RPC_st AR_IMG_FMT_RPC_st;


struct ArCdnnOutputBuffer_RPC_st {
	int width;
	int height;
	int nchannels;
	int nInputs;
	char buffer_name[128];
	int buffer_size;
	float pdata[MAX_OUTPUT_PDATA_SIZE];
};
typedef struct ArCdnnOutputBuffer_RPC_st ArCdnnOutputBuffer_RPC_st;


struct AR_DSP_OUTPUT_RPC_st {
	int buffer_num;
	ArCdnnOutputBuffer_RPC_st output_buffer[16];
};
typedef struct AR_DSP_OUTPUT_RPC_st AR_DSP_OUTPUT_RPC_st;


struct AR_DSP_ALG_RPC_IN_st {
	int dsp_id;
	int alg_type;
	int exit_code;
	AR_IMG_FMT_RPC_st input[4];
	AR_CV_OPS_st cv_ops;
};
typedef struct AR_DSP_ALG_RPC_IN_st AR_DSP_ALG_RPC_IN_st;


struct AR_DSP_ALG_RPC_OUT_st {
	int dsp_id;
	int alg_type;
	int exit_code;
	AR_DSP_OUTPUT_RPC_st output;
	AR_DSP_STATS_st statistics;
};
typedef struct AR_DSP_ALG_RPC_OUT_st AR_DSP_ALG_RPC_OUT_st;


struct AR_DSP_ALG_TO_RPC_IN_st {
	AR_DSP_ALG_RPC_IN_st ar_alg_rpc_st;
	int timeout;
};
typedef struct AR_DSP_ALG_TO_RPC_IN_st AR_DSP_ALG_TO_RPC_IN_st;


struct AR_FILE_CHUNK_st {
	char name[128];
	char data[FILE_CHUNK_DATA_SIZE];
	int chunk_bytes;
	int total_len;
};
typedef struct AR_FILE_CHUNK_st AR_FILE_CHUNK_st;


#define AR_DSP_RPC_PROG 12345678
#define VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define AR_ALG_CFG_DSP 1
extern  int * ar_alg_cfg_dsp_1(AR_DSP_CFG_RPC_st *, CLIENT *);
extern  int * ar_alg_cfg_dsp_1_svc(AR_DSP_CFG_RPC_st *, struct svc_req *);
#define AR_DO_ALGRITHOM 2
extern  AR_DSP_ALG_RPC_OUT_st * ar_do_algrithom_1(AR_DSP_ALG_RPC_IN_st *, CLIENT *);
extern  AR_DSP_ALG_RPC_OUT_st * ar_do_algrithom_1_svc(AR_DSP_ALG_RPC_IN_st *, struct svc_req *);
#define AR_DO_ALGRITHOM_WITH_TIMEOUT 3
extern  AR_DSP_ALG_RPC_OUT_st * ar_do_algrithom_with_timeout_1(AR_DSP_ALG_TO_RPC_IN_st *, CLIENT *);
extern  AR_DSP_ALG_RPC_OUT_st * ar_do_algrithom_with_timeout_1_svc(AR_DSP_ALG_TO_RPC_IN_st *, struct svc_req *);
#define AR_SEND_FILE 4
extern  int * ar_send_file_1(AR_FILE_CHUNK_st *, CLIENT *);
extern  int * ar_send_file_1_svc(AR_FILE_CHUNK_st *, struct svc_req *);
extern int ar_dsp_rpc_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define AR_ALG_CFG_DSP 1
extern  int * ar_alg_cfg_dsp_1();
extern  int * ar_alg_cfg_dsp_1_svc();
#define AR_DO_ALGRITHOM 2
extern  AR_DSP_ALG_RPC_OUT_st * ar_do_algrithom_1();
extern  AR_DSP_ALG_RPC_OUT_st * ar_do_algrithom_1_svc();
#define AR_DO_ALGRITHOM_WITH_TIMEOUT 3
extern  AR_DSP_ALG_RPC_OUT_st * ar_do_algrithom_with_timeout_1();
extern  AR_DSP_ALG_RPC_OUT_st * ar_do_algrithom_with_timeout_1_svc();
#define AR_SEND_FILE 4
extern  int * ar_send_file_1();
extern  int * ar_send_file_1_svc();
extern int ar_dsp_rpc_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_AR_DSP_IMG_FMT_ID_e (XDR *, AR_DSP_IMG_FMT_ID_e*);
extern  bool_t xdr_AR_DSP_IMG_FMT_ID_e (XDR *, AR_DSP_IMG_FMT_ID_e*);
extern  bool_t xdr_AR_DSP_LOG_LVL_e (XDR *, AR_DSP_LOG_LVL_e*);
extern  bool_t xdr_AR_DSP_LOG_LVL_e (XDR *, AR_DSP_LOG_LVL_e*);
extern  bool_t xdr_AR_DSP_ID_e (XDR *, AR_DSP_ID_e*);
extern  bool_t xdr_AR_DSP_ID_e (XDR *, AR_DSP_ID_e*);
extern  bool_t xdr_AR_CDNN_MEMORY_DATA_ORDER_e (XDR *, AR_CDNN_MEMORY_DATA_ORDER_e*);
extern  bool_t xdr_AR_CDNN_MEMORY_DATA_ORDER_e (XDR *, AR_CDNN_MEMORY_DATA_ORDER_e*);
extern  bool_t xdr_AR_CDNN_BUFFER_DATA_TYPE_e (XDR *, AR_CDNN_BUFFER_DATA_TYPE_e*);
extern  bool_t xdr_AR_CDNN_BUFFER_DATA_TYPE_e (XDR *, AR_CDNN_BUFFER_DATA_TYPE_e*);
extern  bool_t xdr_AR_CDNN_BUFFER_BIT_PRECISION_TYPE_e (XDR *, AR_CDNN_BUFFER_BIT_PRECISION_TYPE_e*);
extern  bool_t xdr_AR_CDNN_BUFFER_BIT_PRECISION_TYPE_e (XDR *, AR_CDNN_BUFFER_BIT_PRECISION_TYPE_e*);
extern  bool_t xdr_AR_POINT_st (XDR *, AR_POINT_st*);
extern  bool_t xdr_AR_POINT_st (XDR *, AR_POINT_st*);
extern  bool_t xdr_AR_RECT_st (XDR *, AR_RECT_st*);
extern  bool_t xdr_AR_RECT_st (XDR *, AR_RECT_st*);
extern  bool_t xdr_AR_IMG_FMT_st (XDR *, AR_IMG_FMT_st*);
extern  bool_t xdr_AR_IMG_FMT_st (XDR *, AR_IMG_FMT_st*);
extern  bool_t xdr_ArCdnnOutputBuffer (XDR *, ArCdnnOutputBuffer*);
extern  bool_t xdr_ArCdnnOutputBuffer (XDR *, ArCdnnOutputBuffer*);
extern  bool_t xdr_AR_SOFTMAX_THRD_st (XDR *, AR_SOFTMAX_THRD_st*);
extern  bool_t xdr_AR_SOFTMAX_THRD_st (XDR *, AR_SOFTMAX_THRD_st*);
extern  bool_t xdr_AR_DSP_OUTPUT_st (XDR *, AR_DSP_OUTPUT_st*);
extern  bool_t xdr_AR_DSP_OUTPUT_st (XDR *, AR_DSP_OUTPUT_st*);
extern  bool_t xdr_AR_DSP_STATS_st (XDR *, AR_DSP_STATS_st*);
extern  bool_t xdr_AR_DSP_STATS_st (XDR *, AR_DSP_STATS_st*);
extern  bool_t xdr_AR_CV_OPS_st (XDR *, AR_CV_OPS_st*);
extern  bool_t xdr_AR_CV_OPS_st (XDR *, AR_CV_OPS_st*);
extern  bool_t xdr_ar_callback_func (XDR *, ar_callback_func*);
extern  bool_t xdr_AR_DSP_ALG_st (XDR *, AR_DSP_ALG_st*);
extern  bool_t xdr_AR_DSP_ALG_st (XDR *, AR_DSP_ALG_st*);
extern  bool_t xdr_AR_CDNN_INPUT_PARAMS_st (XDR *, AR_CDNN_INPUT_PARAMS_st*);
extern  bool_t xdr_AR_CDNN_INPUT_PARAMS_st (XDR *, AR_CDNN_INPUT_PARAMS_st*);
extern  bool_t xdr_AR_DSP_USR_CFG_st (XDR *, AR_DSP_USR_CFG_st*);
extern  bool_t xdr_AR_DSP_USR_CFG_st (XDR *, AR_DSP_USR_CFG_st*);
extern  bool_t xdr_AR_DSP_CNN_CFG_st (XDR *, AR_DSP_CNN_CFG_st*);
extern  bool_t xdr_AR_DSP_CNN_CFG_st (XDR *, AR_DSP_CNN_CFG_st*);
extern  bool_t xdr_AR_DSP_CFG_st (XDR *, AR_DSP_CFG_st*);
extern  bool_t xdr_AR_DSP_CFG_st (XDR *, AR_DSP_CFG_st*);
extern  bool_t xdr_AR_DSP_CFG_RPC_st (XDR *, AR_DSP_CFG_RPC_st*);
extern  bool_t xdr_AR_DSP_CFG_RPC_st (XDR *, AR_DSP_CFG_RPC_st*);
extern  bool_t xdr_AR_IMG_FMT_RPC_st (XDR *, AR_IMG_FMT_RPC_st*);
extern  bool_t xdr_AR_IMG_FMT_RPC_st (XDR *, AR_IMG_FMT_RPC_st*);
extern  bool_t xdr_ArCdnnOutputBuffer_RPC_st (XDR *, ArCdnnOutputBuffer_RPC_st*);
extern  bool_t xdr_ArCdnnOutputBuffer_RPC_st (XDR *, ArCdnnOutputBuffer_RPC_st*);
extern  bool_t xdr_AR_DSP_OUTPUT_RPC_st (XDR *, AR_DSP_OUTPUT_RPC_st*);
extern  bool_t xdr_AR_DSP_OUTPUT_RPC_st (XDR *, AR_DSP_OUTPUT_RPC_st*);
extern  bool_t xdr_AR_DSP_ALG_RPC_IN_st (XDR *, AR_DSP_ALG_RPC_IN_st*);
extern  bool_t xdr_AR_DSP_ALG_RPC_IN_st (XDR *, AR_DSP_ALG_RPC_IN_st*);
extern  bool_t xdr_AR_DSP_ALG_RPC_OUT_st (XDR *, AR_DSP_ALG_RPC_OUT_st*);
extern  bool_t xdr_AR_DSP_ALG_RPC_OUT_st (XDR *, AR_DSP_ALG_RPC_OUT_st*);
extern  bool_t xdr_AR_DSP_ALG_TO_RPC_IN_st (XDR *, AR_DSP_ALG_TO_RPC_IN_st*);
extern  bool_t xdr_AR_DSP_ALG_TO_RPC_IN_st (XDR *, AR_DSP_ALG_TO_RPC_IN_st*);
extern  bool_t xdr_AR_FILE_CHUNK_st (XDR *, AR_FILE_CHUNK_st*);
extern  bool_t xdr_AR_FILE_CHUNK_st (XDR *, AR_FILE_CHUNK_st*);

#else /* K&R C */
extern bool_t xdr_AR_DSP_IMG_FMT_ID_e ();
extern bool_t xdr_AR_DSP_IMG_FMT_ID_e ();
extern bool_t xdr_AR_DSP_LOG_LVL_e ();
extern bool_t xdr_AR_DSP_LOG_LVL_e ();
extern bool_t xdr_AR_DSP_ID_e ();
extern bool_t xdr_AR_DSP_ID_e ();
extern bool_t xdr_AR_CDNN_MEMORY_DATA_ORDER_e ();
extern bool_t xdr_AR_CDNN_MEMORY_DATA_ORDER_e ();
extern bool_t xdr_AR_CDNN_BUFFER_DATA_TYPE_e ();
extern bool_t xdr_AR_CDNN_BUFFER_DATA_TYPE_e ();
extern bool_t xdr_AR_CDNN_BUFFER_BIT_PRECISION_TYPE_e ();
extern bool_t xdr_AR_CDNN_BUFFER_BIT_PRECISION_TYPE_e ();
extern bool_t xdr_AR_POINT_st ();
extern bool_t xdr_AR_POINT_st ();
extern bool_t xdr_AR_RECT_st ();
extern bool_t xdr_AR_RECT_st ();
extern bool_t xdr_AR_IMG_FMT_st ();
extern bool_t xdr_AR_IMG_FMT_st ();
extern bool_t xdr_ArCdnnOutputBuffer ();
extern bool_t xdr_ArCdnnOutputBuffer ();
extern bool_t xdr_AR_SOFTMAX_THRD_st ();
extern bool_t xdr_AR_SOFTMAX_THRD_st ();
extern bool_t xdr_AR_DSP_OUTPUT_st ();
extern bool_t xdr_AR_DSP_OUTPUT_st ();
extern bool_t xdr_AR_DSP_STATS_st ();
extern bool_t xdr_AR_DSP_STATS_st ();
extern bool_t xdr_AR_CV_OPS_st ();
extern bool_t xdr_AR_CV_OPS_st ();
extern bool_t xdr_ar_callback_func ();
extern bool_t xdr_AR_DSP_ALG_st ();
extern bool_t xdr_AR_DSP_ALG_st ();
extern bool_t xdr_AR_CDNN_INPUT_PARAMS_st ();
extern bool_t xdr_AR_CDNN_INPUT_PARAMS_st ();
extern bool_t xdr_AR_DSP_USR_CFG_st ();
extern bool_t xdr_AR_DSP_USR_CFG_st ();
extern bool_t xdr_AR_DSP_CNN_CFG_st ();
extern bool_t xdr_AR_DSP_CNN_CFG_st ();
extern bool_t xdr_AR_DSP_CFG_st ();
extern bool_t xdr_AR_DSP_CFG_st ();
extern bool_t xdr_AR_DSP_CFG_RPC_st ();
extern bool_t xdr_AR_DSP_CFG_RPC_st ();
extern bool_t xdr_AR_IMG_FMT_RPC_st ();
extern bool_t xdr_AR_IMG_FMT_RPC_st ();
extern bool_t xdr_ArCdnnOutputBuffer_RPC_st ();
extern bool_t xdr_ArCdnnOutputBuffer_RPC_st ();
extern bool_t xdr_AR_DSP_OUTPUT_RPC_st ();
extern bool_t xdr_AR_DSP_OUTPUT_RPC_st ();
extern bool_t xdr_AR_DSP_ALG_RPC_IN_st ();
extern bool_t xdr_AR_DSP_ALG_RPC_IN_st ();
extern bool_t xdr_AR_DSP_ALG_RPC_OUT_st ();
extern bool_t xdr_AR_DSP_ALG_RPC_OUT_st ();
extern bool_t xdr_AR_DSP_ALG_TO_RPC_IN_st ();
extern bool_t xdr_AR_DSP_ALG_TO_RPC_IN_st ();
extern bool_t xdr_AR_FILE_CHUNK_st ();
extern bool_t xdr_AR_FILE_CHUNK_st ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_AR_DSP_RPC_H_RPCGEN */
