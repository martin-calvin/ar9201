#include "../../../../output/staging/target/include/ar_alg_define.h"

const MAX_INPUT_IMG_BUF_SIZE = 2097152;
const MAX_OUTPUT_PDATA_SIZE = 1048576;
const FILE_CHUNK_DATA_SIZE = 1048576;

struct AR_DSP_CFG_RPC_st
{
	int dsp_id;
	AR_DSP_CFG_st dsp_cfg_st;
};

typedef struct AR_DSP_CFG_RPC_st AR_DSP_CFG_RPC_st;

struct AR_IMG_FMT_RPC_st
{
	int width;
	int height;
	int channel;
	int format;

	int y_stride;
	int u_stride;
	int v_stride;
	char * y_addr;
	char * u_addr;
	char * v_addr;

	int size;
	char rgbbuff[MAX_INPUT_IMG_BUF_SIZE];
} ;
typedef struct AR_IMG_FMT_RPC_st AR_IMG_FMT_RPC_st;

/*******Output buffer struct, same with dsp cdnn********/
struct ArCdnnOutputBuffer_RPC_st
{
	int width;
	int height;
	int nchannels;
	int nInputs;
	char buffer_name[128];
	int buffer_size;
	float pdata[MAX_OUTPUT_PDATA_SIZE];
};

typedef struct ArCdnnOutputBuffer_RPC_st ArCdnnOutputBuffer_RPC_st;

struct AR_DSP_OUTPUT_RPC_st
{
	int buffer_num;
	ArCdnnOutputBuffer_RPC_st output_buffer[AR_DSP_ALG_MAX_OUTPUT_NUM];
} ;

typedef struct AR_DSP_OUTPUT_RPC_st AR_DSP_OUTPUT_RPC_st;

struct AR_DSP_ALG_RPC_IN_st
{
        int dsp_id;
        int alg_type;
        int exit_code;
        AR_IMG_FMT_RPC_st input[AR_DSP_ALG_MAX_INPUT_NUM];
        AR_CV_OPS_st   cv_ops;
};

typedef struct AR_DSP_ALG_RPC_IN_st AR_DSP_ALG_RPC_IN_st;

struct AR_DSP_ALG_RPC_OUT_st
{
        int dsp_id;
        int alg_type;
        int exit_code;
        AR_DSP_OUTPUT_RPC_st output;
        AR_DSP_STATS_st statistics;
};

typedef struct AR_DSP_ALG_RPC_OUT_st AR_DSP_ALG_RPC_OUT_st;

struct AR_DSP_ALG_TO_RPC_IN_st
{
	AR_DSP_ALG_RPC_IN_st ar_alg_rpc_st;
	int timeout;
};

typedef struct AR_DSP_ALG_TO_RPC_IN_st AR_DSP_ALG_TO_RPC_IN_st;

struct AR_FILE_CHUNK_st
{
	char name[128];
	char data[FILE_CHUNK_DATA_SIZE];
	int chunk_bytes;
	int total_len;
};

typedef struct AR_FILE_CHUNK_st AR_FILE_CHUNK_st;

program AR_DSP_RPC_PROG{
version VERSION{
int AR_ALG_CFG_DSP(AR_DSP_CFG_RPC_st) = 1;
AR_DSP_ALG_RPC_OUT_st AR_DO_ALGRITHOM(AR_DSP_ALG_RPC_IN_st)=2; 
AR_DSP_ALG_RPC_OUT_st AR_DO_ALGRITHOM_WITH_TIMEOUT(AR_DSP_ALG_TO_RPC_IN_st)=3;
int AR_SEND_FILE(AR_FILE_CHUNK_st)=4;
}=1;
}=12345678;
