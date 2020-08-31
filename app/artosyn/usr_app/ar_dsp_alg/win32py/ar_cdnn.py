from ctypes import *
import os.path
import sys


# AR_DSP_CFG_STRUCT DEFINE

class AR_CDNN_INPUT_PARAMS_st(Structure):
    _fields_=[  ("width",c_uint),
                ("height",c_uint),
                ("dataType",c_uint),
                ("depth",c_uint),
                ("nChannels",c_uint),
                ("scaleFactor",c_float),
                ("dataOrder",c_uint),
                ("nInputs",c_uint),
                ("dataFlipped",c_uint),
                ("dataTransposed",c_uint),
                ("padding",c_int*4),
                ("pLayerName",c_char*32),
                ("bufferId",c_uint)
              ]

class AR_SOFTMAX_THRD_st(Structure):
    _fields_=[  ("name",c_char*128),
                ("threshold",c_float)
             ]

class AR_DSP_CNN_CFG_st(Structure):
     _fields_=[ ("network_id",c_int),
                ("network_type",c_int),
                ("do_debug_logging",c_int),
                ("do_profiling",c_int),
                ("channel_swap",c_int),
                ("raw_scale",c_int),
                ("bw_reduction",c_int),
                ("resize_input",c_int),
                ("amend_flag",c_int),
                ("block_size",c_int),
                ("block_number",c_int),
                ("block_interval",c_int),
                
                ("num_of_inference",c_int),
                ("max_width",c_int),
                ("max_height",c_int),
                ("bw_reduction_ratio",c_float),

                ("num_inputs",c_int),
                ("input_format",c_int*4),
                ("input_buf_len",c_int*4),
                ("input_buf",c_ulong*4),

                ("input_params",AR_CDNN_INPUT_PARAMS_st*4),
                ("output_threshold",c_float),
                ("weight_file_path",c_char*128),
                ("file_len",c_ulong),
                ("load_addr",c_ulong),
                
                ("len_of_buffer_for_pdata",c_int),
                ("buffer_pa_for_pdata",c_ulong),
                ("buffer_va_for_pdata",c_ulong),

                ("softmax_thrd",AR_SOFTMAX_THRD_st*8),
                ("resize_by_dsp",c_int),
                ("other_parameters",c_void_p)
               ]

class AR_DSP_USR_CFG_st(Structure):
    _fields_=[  ("operation_id",c_int),
                ("params",c_void_p)
             ]


class AR_DSP_CFG_st(Structure):
    _fields_=[  ("cdnn_sram_heap_start",c_ulong),
                ("cdnn_sram_heap_size",c_int),
                ("cdnn_ext_mem_addr",c_ulong),
                ("cdnn_ext_mem_size",c_int),
                ("dsp_log_level",c_int),
                ("reserved",c_int),
                ("cnn_cfg",AR_DSP_CNN_CFG_st*16),
                ("user_cfg",AR_DSP_USR_CFG_st*16)
             ]


# NECESSARY LIB FUN FOT CFG  
pthreadVC2 = CDLL("..\\win32lib\\pthreads_compiled\\pthreadVC2.dll");
ar_dsp_lib_prc = CDLL("..\\win32lib\\libartosyn.dll");
ar_dsp_lib_prc.ar_runtime_init.argtypes = [ c_int, c_char_p]
ar_dsp_lib_prc.ar_runtime_init.restype = c_int

ar_dsp_lib_prc.ar_malloc_py.argtypes = [c_int]
ar_dsp_lib_prc.ar_malloc_py.restype = c_int

pdata_addr= ar_dsp_lib_prc.ar_malloc_py(8388608)
ext_mem_addr= ar_dsp_lib_prc.ar_malloc_py(73400320)

ar_dsp_lib_prc.ar_alg_cfg_dsp.argtypes = [ c_int, POINTER(AR_DSP_CFG_st), c_int]
ar_dsp_lib_prc.ar_alg_cfg_dsp.restype = c_int

ar_dsp_lib_prc.ar_load_image_py.argtypes = [ c_char_p, c_int, c_int]
ar_dsp_lib_prc.ar_load_image_py.restype = c_int

ar_dsp_lib_prc.ar_free_image_py.argtypes = [ c_ulong]
ar_dsp_lib_prc.ar_free_image_py.restype = c_int

# AR_DSP_CFG_STRUCT VARIABLE     
input_params_sub = AR_CDNN_INPUT_PARAMS_st()
input_params_sub.width = 300
input_params_sub.height = 300
input_params_sub.dataType = 1
input_params_sub.depth = 8
input_params_sub.nChannels = 3
input_params_sub.scaleFactor = c_float(0)
input_params_sub.dataOrder = 1
input_params_sub.nInputs = 1 
input_params_sub.dataFlipped = 0
input_params_sub.dataTransposed = 0
input_params_sub.padding = (c_long*4)()
input_params_sub.pLayerName = bytes("data_original",'utf-8')
input_params_sub.bufferId = 0

softmax_thrd_sub_0 = AR_SOFTMAX_THRD_st()
softmax_thrd_sub_0.name = bytes("name1",'utf-8')
softmax_thrd_sub_0.threshold = 0.1
softmax_thrd_sub_1 = AR_SOFTMAX_THRD_st()
softmax_thrd_sub_1.name = bytes("name2",'utf-8')
softmax_thrd_sub_1.threshold = 0.2

ar_dsp_cnn_cfg = AR_DSP_CNN_CFG_st()
ar_dsp_cnn_cfg.network_id = 200
ar_dsp_cnn_cfg.network_type = 1
ar_dsp_cnn_cfg.do_debug_logging = 0
ar_dsp_cnn_cfg.do_profiling = 0
ar_dsp_cnn_cfg.channel_swap = 0
ar_dsp_cnn_cfg.raw_scale = 0
ar_dsp_cnn_cfg.bw_reduction = 0
ar_dsp_cnn_cfg.resize_input = 1
ar_dsp_cnn_cfg.amend_flag = 0
ar_dsp_cnn_cfg.block_size = 0
ar_dsp_cnn_cfg.block_number = 0
ar_dsp_cnn_cfg.block_interval = 0
ar_dsp_cnn_cfg.num_of_inference = 0
ar_dsp_cnn_cfg.max_width = 0
ar_dsp_cnn_cfg.max_height = 0
ar_dsp_cnn_cfg.bw_reduction_ratio = 0
ar_dsp_cnn_cfg.num_inputs = 1
ar_dsp_cnn_cfg.input_format = (c_int*4)()
ar_dsp_cnn_cfg.input_format[0] = 513
ar_dsp_cnn_cfg.input_buf_len = (c_int*4)()
ar_dsp_cnn_cfg.input_buf_len[0] = 921600
ar_dsp_cnn_cfg.input_buf = (c_ulong*4)()
ar_dsp_cnn_cfg.input_buf[0] = 0

ar_dsp_cnn_cfg.input_params = (AR_CDNN_INPUT_PARAMS_st*4)()
ar_dsp_cnn_cfg.input_params[0] = input_params_sub

ar_dsp_cnn_cfg.output_threshold = 0.6
ar_dsp_cnn_cfg.weight_file_path = bytes(0)
ar_dsp_cnn_cfg.file_len = 0
ar_dsp_cnn_cfg.load_addr = 0
ar_dsp_cnn_cfg.len_of_buffer_for_pdata = 8388608
ar_dsp_cnn_cfg.buffer_pa_for_pdata = pdata_addr
ar_dsp_cnn_cfg.buffer_va_for_pdata = pdata_addr

ar_dsp_cnn_cfg.softmax_thrd = (AR_SOFTMAX_THRD_st*8)()
ar_dsp_cnn_cfg.softmax_thrd[0] = softmax_thrd_sub_0
ar_dsp_cnn_cfg.softmax_thrd[1] = softmax_thrd_sub_1

ar_dsp_cnn_cfg.resize_by_dsp = 0
ar_dsp_cnn_cfg.other_parameters = None


ar_dsp_usr_cfg = AR_DSP_USR_CFG_st()
ar_dsp_usr_cfg.operation_id = 0
ar_dsp_usr_cfg.params = 0

ar_dsp_cfg = AR_DSP_CFG_st()
ar_dsp_cfg.cdnn_sram_heap_start = 0 
ar_dsp_cfg.cdnn_sram_heap_size = 1048576
ar_dsp_cfg.cdnn_ext_mem_addr = ext_mem_addr
ar_dsp_cfg.cdnn_ext_mem_size = 73400320
ar_dsp_cfg.dsp_log_level = 3
ar_dsp_cfg.reserved = 0
ar_dsp_cfg.cnn_cfg = (AR_DSP_CNN_CFG_st*16)()
ar_dsp_cfg.cnn_cfg[0]= ar_dsp_cnn_cfg
ar_dsp_cfg.user_cfg = (AR_DSP_USR_CFG_st*16)()
ar_dsp_cfg.user_cfg[0]= ar_dsp_usr_cfg



# AR_DSP_TASK_STRUCT DEFINE
class AR_IMG_FMT_st(Structure):
	_fields_=[  ("width",c_int),
		    ("height",c_int),
		    ("channel",c_int),
		    ("format",c_int),
				
		    ("y_stride",c_int),
		    ("u_stride",c_int),
		    ("v_stride",c_int),
		    ("y_addr",c_char_p),
		    ("u_addr",c_char_p),
		    ("v_addr",c_char_p),
				
		    ("size",c_int),
		    ("rgbbuff",c_char_p)
		  ]

class AR_RECT_st(Structure):
	_fields_=[  ("x",c_int),
				("y",c_int),
				("width",c_int),
				("height",c_int)
			 ]


class AR_CV_OPS_st(Structure):
	_fields_=[  ("cv_ops_bmp",c_int),
				("roi",AR_RECT_st),
				("landmark",c_float*64)
			 ]

class ArCdnnOutputBuffer(Structure):
	_fields_=[  ("width",c_int),
				("height",c_int),
				("nchannels",c_int),
				("nInputs",c_int),
				
				("buffer_name",c_char*128),
				("buffer_size",c_int),
				("pdata",POINTER(c_float)),
			  ] 

class AR_DSP_OUTPUT_st(Structure):
	_fields_=[  ("buffer_num",c_int),
				("output_buffer",ArCdnnOutputBuffer*16),
			 ]


class AR_DSP_STATS_st(Structure):
	_fields_=[  ("cdnn_init_time",c_ulong),
				("cdnn_pre_proc_time",c_ulong),
				("cdnn_inference_time",c_ulong),
				("cdnn_post_proc_time",c_ulong)
			 ]


c_void_p_para = c_void_p(None)

def ar_callback_func(c_void_p_para):  
	return c_void_p_para



class AR_DSP_ALG_st(Structure):
	_fields_=[  ("dsp_id",c_int),
				("alg_type",c_int),
				("exit_code",c_int),
				("input",AR_IMG_FMT_st*4),
				
				("cv_ops",AR_CV_OPS_st),
				("output",AR_DSP_OUTPUT_st),
				("statistics",AR_DSP_STATS_st),
				("cb",c_void_p),
				("data",c_void_p),
				("user_data_pa",c_void_p)
			]


# NECESSARY LIB FUN FOT TASK
ar_dsp_lib_prc.ar_do_algrithom.argtypes = [ POINTER(AR_DSP_ALG_st)]
ar_dsp_lib_prc.ar_do_algrithom.restype = c_int


# AR_DSP_TASK_STRUCT VARABLE
ar_img_fmt_sub = AR_IMG_FMT_st()
ar_img_fmt_sub.width = 300
ar_img_fmt_sub.height = 300
ar_img_fmt_sub.channel = 3
ar_img_fmt_sub.format = ar_dsp_cfg.cnn_cfg[0].input_format[0] 
ar_img_fmt_sub.y_stride = 0
ar_img_fmt_sub.u_stride = 0
ar_img_fmt_sub.v_stride = 0
ar_img_fmt_sub.y_addr = 0
ar_img_fmt_sub.u_addr = 0
ar_img_fmt_sub.v_addr = 0
ar_img_fmt_sub.size = 300*300*3
ar_img_fmt_sub.rgbbuff = ar_dsp_cfg.cnn_cfg[0].input_buf[0]


ar_rect_sub = AR_RECT_st()
ar_rect_sub.x = 0
ar_rect_sub.y = 0
ar_rect_sub.width = 0
ar_rect_sub.height = 0

ar_cv_ops = AR_CV_OPS_st()
ar_cv_ops.cv_ops_bmp = 0
ar_cv_ops.roi = ar_rect_sub
ar_cv_ops.landmark = (c_float*64)()


arcdnnoutputbuffer = ArCdnnOutputBuffer()
arcdnnoutputbuffer.width = 0
arcdnnoutputbuffer.height = 0
arcdnnoutputbuffer.nchannels = 0
arcdnnoutputbuffer.nInputs = 0
arcdnnoutputbuffer.buffer_name = bytes(0)
arcdnnoutputbuffer.buffer_size = 0
arcdnnoutputbuffer.pdata = None

ar_dsp_output = AR_DSP_OUTPUT_st()
ar_dsp_output.buffer_num = 0
ar_dsp_output.output_buffer = (ArCdnnOutputBuffer*16)()
ar_dsp_output.output_buffer[0] = arcdnnoutputbuffer

ar_dsp_stats = AR_DSP_STATS_st()
ar_dsp_stats.cdnn_init_time = 0
ar_dsp_stats.cdnn_pre_proc_time = 0
ar_dsp_stats.cdnn_inference_time = 0
ar_dsp_stats.cdnn_post_proc_time = 0


ar_dsp_alg = AR_DSP_ALG_st()
ar_dsp_alg.dsp_id = 0
ar_dsp_alg.alg_type = ar_dsp_cfg.cnn_cfg[0].network_id
ar_dsp_alg.exit_code = 0
ar_dsp_alg.input = (AR_IMG_FMT_st*4)()
ar_dsp_alg.input[0]= ar_img_fmt_sub
ar_dsp_alg.cv_ops = ar_cv_ops
ar_dsp_alg.output = ar_dsp_output
ar_dsp_alg.statistics = ar_dsp_stats
ar_dsp_alg.cb = None
ar_dsp_alg.data =None
ar_dsp_alg.user_data_pa =None


#AR_CDNN CLASS DEFINE

class AR_CDNN:
    def __init__ (self, ar_dsp_cfg_self = ar_dsp_cfg , ar_dsp_alg_self = ar_dsp_alg):
        self.ar_dsp_cfg_self = ar_dsp_cfg_self
        self.ar_dsp_alg_self = ar_dsp_alg_self

    def Init(self, run_mode, ip_addr):       
        runtime_init_retval= ar_dsp_lib_prc.ar_runtime_init(run_mode, ip_addr)
        print("Init dsp done")
        
    def ConfigDSP(self, wight_path):
        #load weight
        size = 0
        load_wight_len = os.path.getsize(wight_path)
        #self.ar_dsp_cfg_self.cnn_cfg[0].weight_file_path = bytes("..\\","utf-8")+ wight_path
        self.ar_dsp_cfg_self.cnn_cfg[0].weight_file_path = wight_path
        self.ar_dsp_cfg_self.cnn_cfg[0].file_len = load_wight_len
        print(wight_path)
        #config dsp
        default = 0
        cfg_size = 10000 #sys.getsizeof(self.ar_dsp_cfg_self)
        print(cfg_size)
        ar_alg_cfg_dsp_retval= ar_dsp_lib_prc.ar_alg_cfg_dsp( default, byref(self.ar_dsp_cfg_self), cfg_size)
        print("Config dsp done")

    def DoAlgrithom(self, img_data):
        #load img
        num = 0
        max_size = 921600
        img_array = (c_char*max_size)()
        for i in range(img_data.shape[0]): #height
            for j in range(img_data.shape[1]): #width
                for k in range(img_data.shape[2]): #channels
                    img_array[num] = int(img_data[i][j][k])
                    num=num+1
        
        load_img_addr= ar_dsp_lib_prc.ar_load_image_py(img_array,img_data.size, max_size)
        self.ar_dsp_alg_self.input[0].rgbbuff = load_img_addr
        ar_do_algrithom_retval= ar_dsp_lib_prc.ar_do_algrithom( byref(self.ar_dsp_alg_self))
        ar_dsp_lib_prc.ar_free_image_py(load_img_addr)  
        print("DoAlgrithom done")

    def GetResult(self):
        return  self.ar_dsp_alg_self


             
  

