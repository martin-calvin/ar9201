#ifndef __AR_DSP_ALG_DEFINE_H__
#define __AR_DSP_ALG_DEFINE_H__

/** \addtogroup alg 
 *  @{
 */

/**
 * @file ar_alg_define.h
 * @author Artosyn
 * @date 9 May 2018
 * @brief artosyn alg define
 */

#ifdef __cplusplus
extern "C"{
#endif

#if defined(_MSC_VER)
#define ALIGNED_(x) __declspec(align(x))
#endif

#if defined(__GNUC__)
#define ALIGNED_(x) __attribute__ ((aligned(x)))
#endif

#define AR_DSP_ALG_MAX_NN_PER_DSP   16
#define AR_DSP_ALG_MAX_USER_CFG_PER_DSP     16

#define AR_DSP_ALG_MAX_INPUT_NUM     4
#define AR_DSP_ALG_MAX_OUTPUT_NUM     16
#define AR_DSP_ALG_MAX_SOFTMAX_THRD_NUM 8

#define FILE_PATH_STR_LEN       128

#define AR_CV_CROP_BITMAP   	(1<<0)
#define AR_CV_ROTATE_BITMAP     (1<<1)
#define AR_CV_RESIZE_BITMAP     (1<<2)

#define AR_DSP_CHANNEL_SWAP_ON   1
#define AR_DSP_CHANNEL_SWAP_OFF   0


#if !defined(WIN32) && !defined(X64)

enum AR_DSP_IMG_FMT_ID_e ///AR_DSP_IMG_FMT enum
{
	AR_DSP_IMG_FMT_YUV = 0x200, /*YUV420,3 planar format*/
	AR_DSP_IMG_FMT_BGR, ///<IMG FORMAT BGR
	AR_DSP_IMG_FMT_RGB, ///<IMG FORMAT RGB
	AR_DSP_IMG_FMT_MAX_ID
};
typedef enum AR_DSP_IMG_FMT_ID_e AR_DSP_IMG_FMT_ID_e;

enum AR_DSP_LOG_LVL_e /// AR_DSP_LOG_LVL enum
{
	DSP_LOG_LEVEL_ERR = 0, ///<log level error
	DSP_LOG_LEVEL_WARNING, ///<log level warning
	DSP_LOG_LEVEL_NOTICE, ///<log level notice
	DSP_LOG_LEVEL_DEBUG, ///<log level debug
	DSP_LOG_LEVEL_MAX

};
typedef enum AR_DSP_LOG_LVL_e  AR_DSP_LOG_LVL_e;

enum AR_DSP_ID_e
{
	DSP_ID_0 = 0,
	DSP_ID_1,
	DSP_ID_2,
	DSP_ID_3,
	MAX_DSP_ID
};
typedef enum AR_DSP_ID_e AR_DSP_ID_e;

enum AR_CDNN_MEMORY_DATA_ORDER_e
{
	/*! \brief Sets the data dimension order: inputs, width, height, channels */
	AR_CDNN_MEMORY_DATAORDER_NWHC,
	/*! \brief Sets the data dimension order: inputs, height, width, channels */
	AR_CDNN_MEMORY_DATAORDER_NHWC,
	/*! \brief Sets the data dimension order: channels, width, height, inputs */
	AR_CDNN_MEMORY_DATAORDER_CWHN,
	/*! \brief Sets the data dimension order: channels, height, width, inputs */
	AR_CDNN_MEMORY_DATAORDER_CHWN,
	/*! \brief Sets the data dimension order: inputs, channels, width, height */
	AR_CDNN_MEMORY_DATAORDER_NCWH,
	/*! \brief Sets the data dimension order: inputs, channels, height, width */
	AR_CDNN_MEMORY_DATAORDER_NCHW,
	/*! \brief Sets the data dimension order: channels, inputs, width, height */
	AR_CDNN_MEMORY_DATAORDER_CNWH,
	/*! \brief Sets the data dimension order: channels, inputs, height, width */
	AR_CDNN_MEMORY_DATAORDER_CNHW,
	/*! \brief Sets the data dimension order: width, height, channels, inputs */
	AR_CDNN_MEMORY_DATAORDER_WHCN,
	/*! \brief Sets the data dimension order: height, width, channels, inputs */
	AR_CDNN_MEMORY_DATAORDER_HWCN,
	/*! \brief Sets the data dimension order: width, height, inputs, channels */
	AR_CDNN_MEMORY_DATAORDER_WHNC,
	/*! \brief Sets the data dimension order: height, width, inputs, channels */
	AR_CDNN_MEMORY_DATAORDER_HWNC,
	/*! \brief Gets the data order enum size */
	AR_CDNN_MEMORY_DATAORDER_PUBLIC_SIZE
};
typedef enum AR_CDNN_MEMORY_DATA_ORDER_e AR_CDNN_MEMORY_DATA_ORDER_e;

enum AR_CDNN_BUFFER_DATA_TYPE_e
{
	/*! \brief Sets an 8-bit unsigned data type*/
	AR_CDNN_DATATYPE_U8 = 1,
	/*! \brief Sets an 8-bit signed data type*/
	AR_CDNN_DATATYPE_S8 = 2,
	/*! \brief Sets a 16-bit unsigned data type*/
	AR_CDNN_DATATYPE_U16 = 4,
	/*! \brief Sets a 16-bit signed data type*/
	AR_CDNN_DATATYPE_S16 = 8,
	/*! \brief Sets a 32-bit unsigned data type*/
	AR_CDNN_DATATYPE_U32 = 16,
	/*! \brief Sets a 32-bit signed data type*/
	AR_CDNN_DATATYPE_S32 = 32,
	/*! \brief Sets a floating single precision data type  */
	AR_CDNN_DATATYPE_F32 = 64,
	/*! \brief Sets a floating double precision data type  */
    AR_CDNN_DATATYPE_F64 = 128
};
typedef enum AR_CDNN_BUFFER_DATA_TYPE_e AR_CDNN_BUFFER_DATA_TYPE_e;

enum AR_CDNN_BUFFER_BIT_PRECISION_TYPE_e
{
	/*! \brief Sets an 8-bit element size */
	AR_CDNN_PRECISION_8BIT = 8,
	/*! \brief Sets a 16-bit element size */
	AR_CDNN_PRECISION_16BIT = 16,
	/*! \brief Sets a 32-bit element size */
	AR_CDNN_PRECISION_32BIT = 32,
	/*! \brief Sets a 64-bit element size */
	AR_CDNN_PRECISION_64BIT = 64
};
typedef enum AR_CDNN_BUFFER_BIT_PRECISION_TYPE_e AR_CDNN_BUFFER_BIT_PRECISION_TYPE_e;
/*! \brief AR_POINT struct */
struct AR_POINT_st
{
	int x;
	int y;
};
typedef struct AR_POINT_st AR_POINT_st;
/*! \brief AR_RECT struct */
struct AR_RECT_st
{
	int x;
	int y;
	int width;
	int height;
};
typedef struct AR_RECT_st AR_RECT_st;
/*! \brief AR_IMG_FMT struct */
struct AR_IMG_FMT_st
{
	int width;
	int height;
	int channel;
	int format;

	int y_stride;
	int u_stride;
	int v_stride;
	char * y_addr; /*!< YUV data address from sensor */
	char * u_addr;
	char * v_addr;

	int size; /*!< Input size, optional */
	char * rgbbuff; /*!< input data buffer, if the fmt is RGB/BGR etc.. */

} ;
typedef struct AR_IMG_FMT_st AR_IMG_FMT_st;

/*! \brief CDNN Output buffer struct */
struct ArCdnnOutputBuffer
{
	int width;
	int height;
	int nchannels;
	int nInputs;
	char buffer_name[128];
	int buffer_size;
	float * pdata; /*!< Points to the output data */
} ;
typedef struct ArCdnnOutputBuffer ArCdnnOutputBuffer;
/*! \brief AR_SOFTMAX_THRD struct */
struct AR_SOFTMAX_THRD_st
{
	char name[128];
	float threshold;
};
typedef struct AR_SOFTMAX_THRD_st AR_SOFTMAX_THRD_st;
/*! \brief AR_DSP_OUTPUT struct */
struct AR_DSP_OUTPUT_st
{
	int buffer_num;
	ArCdnnOutputBuffer output_buffer[AR_DSP_ALG_MAX_OUTPUT_NUM];
} ;
typedef struct AR_DSP_OUTPUT_st AR_DSP_OUTPUT_st;

/*! \brief  AR_DSP_STATS struct */
struct AR_DSP_STATS_st
{
	unsigned long cdnn_init_time; ///<cdnn init time
	unsigned long cdnn_pre_proc_time; ///<cdnn pre_proc time
	unsigned long cdnn_inference_time; ///<cdnn interface time
	unsigned long cdnn_post_proc_time; ///<cdnn post proc time
} ;
typedef struct AR_DSP_STATS_st AR_DSP_STATS_st;

/*! \brief This struct is to ctrol dsp to do crop/warpaffine(rotate/translation/scale/flip/shear..)etc..
* ROI is used for crop, landmark is the feature points for face, gestures, etc..
* DSP should use the feature points to decide whether to do some warpaffine.
*/
struct AR_CV_OPS_st
{
	int cv_ops_bmp; /*!< bitmap for cv ops */
	AR_RECT_st roi; /*!< roi for crop */
	float landmark[64]; /*!< not used */
} ;
typedef struct AR_CV_OPS_st AR_CV_OPS_st;

#ifndef RPC_CALL
typedef char * (* ar_callback_func)(char *);
#else
typedef char * ar_callback_func;
#endif

struct AR_DSP_ALG_st
{
	int dsp_id;
	int alg_type;
	int exit_code;
	AR_IMG_FMT_st input[AR_DSP_ALG_MAX_INPUT_NUM];
	AR_CV_OPS_st   cv_ops;
	AR_DSP_OUTPUT_st output;
	AR_DSP_STATS_st statistics;
	ar_callback_func cb;
	/*! \brief args to cb*/
	char * data;
	/*! \brief user defined data, must be physical address */
	char * user_data_pa;

} ;
typedef struct AR_DSP_ALG_st AR_DSP_ALG_st;

/*! \brief Copy from CDNN defination */
struct AR_CDNN_INPUT_PARAMS_st
{
		/*! Buffer width (in elements) */
		unsigned int width;
		/*! \brief Buffer height (in elements) */
		unsigned int height;
		/*! \brief Buffer element data type (for example, single precision float, singed short, and so on) */
		unsigned int dataType;
		/*! \brief Element size (in bits) */
		unsigned int depth;
		/*! \brief Number of channels */
		unsigned int nChannels;
		/*! \brief Represents the scale factor in which the fixed point output is represented.*/
		float scaleFactor;

		/*! \brief enum of data order: NCHW, NCWH, and so on*/
		unsigned int dataOrder;
		/*! \brief Number of input maps */
		unsigned int nInputs;
		/*! \brief Flips the data*/
		unsigned int dataFlipped;
		/*! \brief Transposes the data*/
		unsigned int dataTransposed;
		/*! \brief Margin dimensions (in elements), where 0 = left, 1 = right, 2 = top, 3 = bottom */
		int padding[4];
		/*! \brief The name of the layer the buffer belongs to. The name must be the same as the name of the layer as described in the network file provided by the developer.*/
		char pLayerName[32];
		/*! \brief The buffer parameter index in the layer it belongs to  */
		unsigned int bufferId;
};
typedef struct AR_CDNN_INPUT_PARAMS_st AR_CDNN_INPUT_PARAMS_st;

/*! \brief user defined operations */
struct AR_DSP_USR_CFG_st
{
	int operation_id;
	char * params; /*! \brief This must be physical address and should use ar_ion_malloc to get it.*/
} ;
typedef struct AR_DSP_USR_CFG_st AR_DSP_USR_CFG_st;

/*! \brief See ini file in SDK for the parameter defination and reference value */
struct AR_DSP_CNN_CFG_st
{
	/*! \brief Every CNN has a unique ID, must be non-zero */
	int network_id;
	/*! \brief Detect or classify, just set it to detect */
	int network_type;
	int do_debug_logging;
	int do_profiling;
	/*! \brief Enable channel swap */
	int channel_swap;
	int raw_scale;
	int bw_reduction;
	/*! \brief Just set it to '1' */
	int resize_input;

	/*! \brief below 3 parmas for mtcnn, contact for Artosyn for help */
	int amend_flag;
	int block_size;
	int block_number;
	int block_interval;

	/*! \brief Below 3 parmas are for FCN */
	int num_of_inference;
	int max_width;
	int max_height;

	float bw_reduction_ratio;

	/*! \brief input numbers, usually is '1' */
	int num_inputs;
	/*! \brief format of each input, could be YUV/RGB/BGR or NULL if the input is not a image */
	int input_format[AR_DSP_ALG_MAX_INPUT_NUM];
	/*! \brief Length of input buffer allocated by Linux by ar_ion_malloc */
	int input_buf_len[AR_DSP_ALG_MAX_INPUT_NUM];
	/*! \brief input buffer physical address, allocated by Linux by ar_ion_malloc */
	unsigned long input_buf[AR_DSP_ALG_MAX_INPUT_NUM];
	/*! \brief CDNN input layer parameters*/
	AR_CDNN_INPUT_PARAMS_st input_params[AR_DSP_ALG_MAX_INPUT_NUM];

	/*! \brief this may only be used in Linux APP to filter the final output */
	float output_threshold;
	/*! \brief the weight file path, Linux APP should load the weiths to load_addr */
	char weight_file_path[FILE_PATH_STR_LEN];
	unsigned long file_len;
	/*! \brief The physical addr of weight file in DDR, allocated by ar_ion_malloc */
	unsigned long load_addr;

	/*! \brief we malloc a memory for cdnn output pdata. */
	int    len_of_buffer_for_pdata;
	unsigned long buffer_pa_for_pdata;  /*! \brief pdata physical address, used at DSP side */
	unsigned long buffer_va_for_pdata;  /*! \brief pdata virtual address, used at linux side. */

	/*! \brief CNN softmax layer threshold */
	AR_SOFTMAX_THRD_st softmax_thrd[AR_DSP_ALG_MAX_SOFTMAX_THRD_NUM];

	/*! \brief this is used by user app to decide which one(arm or DSP) will do resize */
	int resize_by_dsp;

	/*! \brief other parameters that initialization needs in DSP can be passed via this ptr, it's a physical address; */
	char * other_parameters;
};
typedef struct AR_DSP_CNN_CFG_st AR_DSP_CNN_CFG_st;

/*!\brief This is the parameters that ceva API needs to init a network */
struct AR_DSP_CFG_st
{
	/*!\brief SRAM can be used by CDNN to accelerate inference speed.
	* users have to give it a SRAM address or DDR address, please follow the reference configuration in X.ini file in SDK
	*/
	unsigned long cdnn_sram_heap_start;
	int cdnn_sram_heap_size;

	/*!\brief The physical addr of external memory used by CDNN lib, must be allocated by ar_ion_malloc */
	unsigned long cdnn_ext_mem_addr;
	int cdnn_ext_mem_size;

	int dsp_log_level;
	int reserved;

	/*!\brief CDNN parameters, defines the CNN network configurations, see X.ini files for reference.*/
	AR_DSP_CNN_CFG_st cnn_cfg[AR_DSP_ALG_MAX_NN_PER_DSP];
	/*!\brief User defined parameters */
	AR_DSP_USR_CFG_st user_cfg[AR_DSP_ALG_MAX_USER_CFG_PER_DSP];
} ;
typedef struct AR_DSP_CFG_st AR_DSP_CFG_st;
#endif

#ifdef __cplusplus
}
#endif

#endif /*__AR_DSP_ALG_DEFINE_H__ */
/** @}*/
