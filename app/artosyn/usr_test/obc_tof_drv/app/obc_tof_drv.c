#define ENABALE_ALL_LOG

#include "obc_tof_drv.h"

static ar_mm_handle_t handle_gl = NULL;

volatile tof_cam_ctrl_t tof_sensor;
volatile cam_handle_t g_dev = 
{
    STOP,               /* pipline can only init once */
    0,                  /* cam_id in driver,default use 0 */
    -1,                 /* cam_fd */
    {
        0,              /* cam_id in dts */    
        {
            1280,       /* input vidio width and height */
            970,        /* input vidio width and height */
        },
        15,             /* rtos vip subsample_rate <0-15> */
        30,              /* vidio fps */
    },
};

static int atoul(char *str, int * pulValue)
{
	int ulResult=0;

	while (*str)
	{
		if (isdigit((int)*str))
		{
			if ((ulResult<429496729) || ((ulResult==429496729) && (*str<'6')))
			{
				ulResult = ulResult*10 + (*str)-48;
			}
			else
			{
				*pulValue = ulResult;
				return -1;
			}
		}
		else
		{
			*pulValue=ulResult;
			return -1;
		}
		str++;
	}
	*pulValue=ulResult;
	return 0;
}

#define ASC2NUM(ch) (ch - '0')
#define HEXASC2NUM(ch) (ch - 'A' + 10)

static int  atoulx(char *str, int * pulValue)
{
	int   ulResult=0;
	char ch;

	while (*str)
	{
		ch=toupper(*str);
		if (isdigit(ch) || ((ch >= 'A') && (ch <= 'F' )))
		{
			if (ulResult < 0x10000000)
			{
				ulResult = ((unsigned int)ulResult << 4) + ((ch<='9')?(ASC2NUM(ch)):(HEXASC2NUM(ch)));
			}
			else
			{
				*pulValue=ulResult;
				return -1;
			}
		}
		else
		{
			*pulValue=ulResult;
			return -1;
		}
		str++;
	}

	*pulValue=ulResult;
	return 0;
}

static int StrToNumber(char *str , int *pulValue)
{
	if ( *str == '0' && (*(str+1) == 'x' || *(str+1) == 'X') )
	{
		if (*(str+2) == '\0')
		{
			return -1;
		}
		else
		{
			return atoulx(str+2,pulValue);
		}
	}
	else
	{
		return atoul(str,pulValue);
	}
}



static int find_pra_index_by_name(char *name,int argc, char *argv[])
{
    int i=0;
	for(i=0;i<argc;i++)
	{
         if(!strcmp(name,argv[i]))
         {
            log_always("find pra %s @ %d",name,i);
            return i;
         }
	}
	return 0;
}

static void cam_raw_get_context(void** context, uint32_t* context_size)
{
    int32_t idx = 0;
#if 0
    static ar_facotry_element_obj_t cam_raw_init_list[] =
    {
        {"pipeline",NULL,NULL},
        {"cam_src",NULL,NULL},
        {"icc_proxy_rpc_sink","icc_proxy_rpc_sink-0",NULL},
    };
#else
    static ar_facotry_element_obj_t cam_raw_init_list[] =
    {
        {"pipeline","pipeline-tof",NULL},
        {"cam_src","cam_src_tof-0",NULL},
        {"icc_proxy_rpc_sink","icc_proxy_rpc_sink-0",NULL},
    };
#endif
    *context = (void*)&cam_raw_init_list;
    *context_size = sizeof(cam_raw_init_list)/sizeof(ar_facotry_element_obj_t);
    return;
}

int32_t cam_get_usr_cfg(int argc, char *argv[])
{
    int pra_index=0;
    usr_cfg_ppl_t *cam_raw_pipeline = &g_dev.cam_pipeline_cfg;

    pra_index=find_pra_index_by_name("--cam_id",argc,argv);
    if(pra_index>0)
    {
        cam_raw_pipeline->cam_id=atoi(argv[pra_index+1]);
		log_always("cam_id=%d",cam_raw_pipeline->cam_id);
    }
	pra_index=find_pra_index_by_name("--size",argc,argv);
    if(pra_index>0)
    {
        cam_raw_pipeline->input_vidio_res.width=atoi(argv[pra_index+1]);
		cam_raw_pipeline->input_vidio_res.height=atoi(argv[pra_index+2]);
		log_always("width=%d height=%d",cam_raw_pipeline->input_vidio_res.width,cam_raw_pipeline->input_vidio_res.height);
    }
     pra_index=find_pra_index_by_name("--subsample_rate",argc,argv);
    if(pra_index>0)
    {
        cam_raw_pipeline->subsample_rate=atoi(argv[pra_index+1]);
		log_always("subsample_rate=%d",cam_raw_pipeline->subsample_rate);
    }

	pra_index=find_pra_index_by_name("--pipefps",argc,argv);
    if(pra_index>0)
    {
        cam_raw_pipeline->fps=atoi(argv[pra_index+1]);
		log_always("fps=%d",cam_raw_pipeline->fps);
    }
    return 0;
}

static ar_mm_handle_t multimedia_handle = NULL;
ar_mm_handle_t get_ar_multimedia_core_device_handle(void)
{
    if(multimedia_handle == NULL){
        multimedia_handle = ar_multimedia_core_device_open();
        if(!multimedia_handle) {
            printf("%s, open multimedia core device failed.", __FUNCTION__);
            // return NULL;
        }
    }
    
    return multimedia_handle;
}

/*
 这个在初始化执行一次，ar_element_factory_make_many API只能执行一次，第二次报错
*/
int ar_make_factory(void)
{
    cam_raw_context_t* context = NULL;
    uint32_t context_size = 0;

    ar_mm_handle_t handle = get_ar_multimedia_core_device_handle();
    cam_raw_get_context((void**)&context, &context_size);
    if(ar_element_factory_make_many(handle, context_size, (ar_facotry_element_obj_t*)context) != AR_MULTIMEDIA_SUCCESS){
        return -1;
    }            
    return 0;
}

/*
    这个API使能后rtos开始采集sensor数据流
*/
int cam_set_element_state(bool state)
{
    cam_raw_context_t* context = NULL;
    uint32_t context_size = 0;
    uint32_t status;

    ar_mm_handle_t handle = get_ar_multimedia_core_device_handle();
    cam_raw_get_context((void**)&context, &context_size);

    if(state){
        status = AR_ELEMENT_STATE_READY;
        ar_element_set_state(handle, (ar_pipeline_t)context->pipeline.element,status);
        /* check rots pipeline status,test if rtos thread run over */
        uint32_t set_count = 0;
        do{
            set_count++;
            usleep(10000);//delay 10ms
        }while(ar_element_get_state(handle, (ar_pipeline_t)context->pipeline.element) != AR_ELEMENT_STATE_PLAYING);
        printf("rots element set complete! %d\n", set_count);
    }
    else{
        status = AR_ELEMENT_STATE_PAUSED;
        ar_element_set_state(handle, (ar_pipeline_t)context->pipeline.element,status);
    }

    printf("ar_element_set_state : %d\n", status);
    return 0;
}

/*
    在个里面建立 element_factory，不启动rtos采集数据流
*/
static int32_t cam_raw_init_impl(cam_handle_t *cam_handle)
{
    usr_cfg_ppl_t *usr_cfg_ppl = &cam_handle->cam_pipeline_cfg;
    ar_mm_handle_t handle = NULL;
    // uint32_t width = 1280, height = 962;
	uint32_t scaler_2_width=1920,scaler_2_height=1080;
    // int cam_id=0;
    cam_raw_context_t* context = NULL;
    uint32_t context_size = 0;
    // int pra_index=0;
    char *cam_mod=AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE;
	char *vif_isp_mode=AR_VIDEO_CAM_VIF_ISP_MOD_DDR;
	// int fps=30;
	int use_meta=0;
	int use_scaler2=0;
	int queue_depth=2;
	int no_display=0;
    int den=1;

    printf("cam set input width:%d height:%d\n", usr_cfg_ppl->input_vidio_res.width, usr_cfg_ppl->input_vidio_res.height);

    /* ar_element_factory only can be make once */
    if(START == cam_handle->tof_ppl_status){
        printf("[err]Cam Initialized!\n");
        return AR_MULTIMEDIA_FAILURE;
    }
    cam_handle->tof_ppl_status = START;

	handle = get_ar_multimedia_core_device_handle();
    if(!handle) {
        printf("%s, open multimedia core device failed.", __FUNCTION__);
        return AR_MULTIMEDIA_FAILURE;
    }

    cam_raw_get_context((void**)&context, &context_size);

    if(ar_make_factory() < 0)
            return AR_MULTIMEDIA_FAILURE;

    /* change cam src property */
    ar_element_modify_property_value(handle, context->cam_src.element,AR_VIDEO_CAM_SET_ID,&usr_cfg_ppl->cam_id, sizeof(uint32_t));


    ar_element_modify_property_value(handle, context->cam_src.element,
                                   AR_VIDEO_CAM_MODE,
                                   cam_mod,
                                   strlen(cam_mod)+1);
    ar_element_modify_property_value(handle, context->cam_src.element,
                                   AR_VIDEO_CAM_VIF_ISP_MOD,
                                   vif_isp_mode,
                                   strlen(vif_isp_mode)+1);
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 3),
                            AR_COMMON_META_VIDEO_WIDTH_NAME,&usr_cfg_ppl->input_vidio_res.width, sizeof(uint32_t));
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 3),
                            AR_COMMON_META_VIDEO_HEIGHT_NAME,&usr_cfg_ppl->input_vidio_res.height, sizeof(uint32_t));

	ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 3),
								AR_COMMON_META_VIDEO_FPS_NUM_NAME,&usr_cfg_ppl->fps, sizeof(uint32_t));
	ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 3),
								AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den, sizeof(uint32_t));

    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 3),
                            AR_COMMON_META_VIDEO_SUBSUMPLE_RATE,&usr_cfg_ppl->subsample_rate, sizeof(uint32_t));

	/* change icc_proxy_sink property */
	ar_element_modify_property_value(handle, context->buf_sink_0.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth, sizeof(uint32_t));


	/* add all element to pipeline/subpipe */
    ar_pipeline_add_many(handle, (ar_pipeline_t)context->pipeline.element,context->cam_src.element,NULL);
    ar_pipeline_add_many(handle,(ar_pipeline_t)context->pipeline.element,context->buf_sink_0.element,NULL);

    ar_pad_link_by_element(handle, context->cam_src.element, 3, context->buf_sink_0.element, 0);

    cam_set_element_state(1);
    
    return AR_MULTIMEDIA_SUCCESS;
}



static void *process_sink_buf_0_thread(void *arg)
{
    cam_raw_config_t *obj = (cam_raw_config_t*)arg;
    cam_buffer_t *buf = NULL;
    void *mem = NULL;
    int   length = 0;
    int count = 0;
    while(obj->frame_count > 0){
        pthread_mutex_lock(&obj->mutex);
        obj->buf_que->queue_pop(obj->buf_que, &buf);
        while(!buf){
            pthread_cond_wait(&obj->buf_signal, &obj->mutex);
            obj->buf_que->queue_pop(obj->buf_que, &buf);
        }
        mem = buf->buf_mem;
        length = buf->buf_len;
        pthread_mutex_unlock(&obj->mutex);
        if(!mem){
            printf("buf mem is NULL\n");
            free(buf);
            continue;
        }
        write(obj->fd, mem, length);
        free(mem);
        free(buf);
        obj->frame_count--;
        count++;
        printf("buf 0 count = %d\n", count);
        buf = NULL;
    }
    printf("process_sink_buf_0\r\n");
    close(obj->fd);
}

void get_sink_buf_0_thread(void *arg)
{
    struct timeval start, end;
    ar_picture_buffer_t *buffer = NULL;
    ar_picture_handle img_handle = NULL;
    int fd ;
    cam_raw_config_t *obj = (cam_raw_config_t*)arg;
    int data_len = 0;
    cam_buffer_t *buf;
    obj->buf_sink_fd = ar_picture_open("/dev/icc_proxy_rpc_sink-0");
    if(obj->buf_sink_fd < 0){
        printf("open sink 0 error\n");
        return ;
    }

    img_handle = (ar_picture_handle)(obj->buf_sink_fd);
    if(!img_handle){
        printf("handle is null\n");
        return;
    }
    obj->fd = open(RAW_DATA_PATH, O_RDWR | O_CREAT);
    if(obj->fd < 0){
        printf("open file error\n");
        return ;
    }

    while(obj->frame_count > 0){
        buffer = NULL;
        buffer = ar_picture_get_img(obj->buf_sink_fd);
        if(!buffer){
            printf("get sink 0 buffer error\n");
            continue ;
        }
        printf("the mem count = %d\n", buffer->mem_num);
        printf("frame id = %d\n", buffer->frame_id);
        printf("pts = %d\n", buffer->pts);
        data_len = buffer->mem[0].len;
        //buf = (void*)buffer->mem[0].addr;
        buf = (cam_buffer_t*)malloc(sizeof(cam_buffer_t));
        if(buf == NULL){
            printf("malloc buf 0 error\n");
        }
        buf->buf_mem = (char*)malloc(data_len);
        if(!buf->buf_mem){
            printf("malloc buf mem error\n");
        }
        buf->buf_len = data_len;
        printf("buf len = %d, %d, %d\n", buffer->mem[0].len, buffer->mem[1].len, buffer->mem[2].len);
        gettimeofday(&start, NULL);
        memcpy(buf->buf_mem, buffer->mem[0].addr, data_len);
        gettimeofday(&end, NULL);
        pthread_mutex_lock(&obj->mutex);
        if(obj->buf_que->queue_insert(obj->buf_que, buf)){
            printf("insert queue err\n");
        }
        pthread_cond_signal(&obj->buf_signal);
        pthread_mutex_unlock(&obj->mutex);
        if(ar_picture_release_img(img_handle, buffer)){
            printf("release buffer failed\n");
            return;
        }
    }
    close(obj->fd);
    printf("buf 0 write finish\n");
}


int tof_sensor_api_init(void)
{
    memset(&tof_sensor, 0, sizeof(tof_sensor));

    tof_sensor.init = s5k33dxx_sensor_init;
    tof_sensor.get_sensor_id = s5k33dxx_get_sensor_id;
    tof_sensor.video_streaming = s5k33dxx_video_streaming;
    tof_sensor.get_fps = s5k33dxx_get_fps;
    tof_sensor.set_fps = s5k33dxx_set_fps;
    tof_sensor.set_illum_power = s5k33dxx_set_illum_power;
    tof_sensor.get_illum_power = s5k33dxx_get_illum_power;
    tof_sensor.illum_power_control = s5k33dxx_illum_power_control;
    tof_sensor.get_integration_time = s5k33dxx_get_integration_time;
    tof_sensor.set_integration_time = s5k33dxx_set_integration_time;
    tof_sensor.get_modulation_frequency = s5k33dxx_get_modulation_frequency;
    tof_sensor.set_modulation_frequency = s5k33dxx_set_modulation_frequency;
    tof_sensor.get_illum_duty_cycle = s5k33dxx_get_illum_duty_cycle;
    tof_sensor.set_illum_duty_cycle = s5k33dxx_set_illum_duty_cycle;
    tof_sensor.get_data_output_mode = s5k33dxx_get_data_output_mode;
    tof_sensor.set_data_output_mode = s5k33dxx_set_data_output_mode;
    tof_sensor.get_img_mirror_flip = s5k33dxx_get_img_mirror_flip;
    tof_sensor.set_img_mirror_flip = s5k33dxx_set_img_mirror_flip;
    tof_sensor.get_pixel_binning = s5k33d_get_pixel_binning;
    tof_sensor.set_pixel_binning = s5k33d_set_pixel_binning;
    tof_sensor.test_pattern = s5k33dxx_test_pattern;
    tof_sensor.set_AE_enable = s5k33dxx_AE;
    tof_sensor.get_rx_temp = s5k33dxx_get_rx_temp;
    tof_sensor.get_tx_temp = s5k33dxx_get_tx_temp;
    tof_sensor.sel_setting = sensor_list_setup;
    tof_sensor.set_exp_threshold = s5k33dxx_set_integration_threshold;
    tof_sensor.get_exp_threshold = s5k33dxx_get_integration_threshold;
    tof_sensor.set_hts = s5k33dxx_set_hts;
    tof_sensor.get_hts = s5k33dxx_get_hts;
    tof_sensor.set_vts = s5k33dxx_set_vts;
    tof_sensor.get_vts = s5k33dxx_get_vts;
    tof_sensor.sensor_i2c_read = s5k33d_i2c_read16;
    tof_sensor.sensor_i2c_write = s5k33d_i2c_write16;
    tof_sensor.laser_i2c_read = cxa4016_reg_read;
    tof_sensor.laser_i2c_write = cxa4016_reg_write;
    tof_sensor.i2c_open = s5k33d_i2c_open;
    tof_sensor.i2c_close = s5k33d_i2c_close;

    // tof_sensor.init();
    return 0;
}


/*
    获取驱动配置参数结构默认值，init以及open时可以根据需要修改
*/
obc_cam_handle_t get_ob_cam_handle(void)
{
    obc_cam_handle_t p_handle = &g_dev;
    return  p_handle;              
}

/*
    obc cam init
    return < null err;
    return struct *obc_cam_handle
*/
int init_tof_cam(obc_cam_handle_t p_handle)
{
    int ret = 0;
    /* init tof_sensor API */
    ret = tof_sensor_api_init();
    if(ret < 0)
        goto fail_end;

    /* rtos pipeline setup */
    ret = cam_raw_init_impl(p_handle);
    if(ret)
        goto fail_end;

    /* open remote-i2c for sensor ctrol */
    ret = s5k33d_i2c_open(); 
    if(ret < 0)
        goto fail_end;
    /* force sensor stop streamming */
    ret = s5k33d_i2c_write16(0x0100, 0x0000);
    if(ret < 0)
        goto fail_end;

    printf("init_tof_cam Success!\n");
    return 0;

fail_end:
    printf("init_tof_cam failed!\n");
    return -1;
}


/*
    obc cam open
    return < 0 err;
*/
int open_tof_cam(int cam_id)
{
    int ret;
    char device_name[64];

    /* open camera source node */
    sprintf(device_name, "/dev/cam_src_tof-%d", g_dev.tof_cam_id);
    g_dev.tof_cam_fd = ar_cam_src_open(device_name);//"/dev/cam_src-0"
    if(g_dev.tof_cam_fd < 0){
        printf("open cam_src error\n");
        return -1;
    }

    /* open remote-i2c for sensor ctrol */
    if(s5k33d_i2c_open() < 0){
        printf("open s5k33d remote_i2c error\n");
        return -1;
    }

#if 0
    //sel settings
    ret = tof_sensor.sel_setting(DRIVER_IC_CXA4016, SENSOR_LIST_BURST_MASTER);
    if(ret)
        return -1;
#endif

    //load settings, if not select settings ,use default
    ret = tof_sensor.init();
    if(ret){
        printf("[err]load setting failed\n");
        return -1;
    }
        
    // sensor deault config if need
    tof_sensor.set_exp_threshold(800, 20);
    tof_sensor.set_hts(0x5f8);
    tof_sensor.set_vts(0x4a0);

    printf("OpenSuccess!\n");
    return g_dev.tof_cam_fd;
}

/*
    obc cam open
    return < 0 err;
*/
int close_tof_cam(int fd)
{
    /* close cam_src */
    if(ar_cam_src_close(fd) != 0){
        printf("close tof_cam_src error\n");
        return -1;
    }
    g_dev.tof_cam_fd = -1;

    /* close sensor */
    if(tof_sensor.video_streaming(0) < 0){
        printf("close s5k33d remote_i2c error\n");
        return -1;
    }
    tof_sensor.streaming_en = 0;

    /* close remote-i2c for sensor ctrol */
    if(s5k33d_i2c_close() < 0){
        printf("close s5k33d remote_i2c error\n");
        return -1;
    }

    printf("CloseSuccess!\n");
    return 0;
}


//test terminal stream
void tof_switch_stream(int w, int h)
{
    uint32_t fps=30, den=1, queue_depth =2;
    int ret = 0;
    cam_raw_context_t* context = NULL;
    uint32_t context_size = 0;
    uint32_t status;
    int log = 0;

    ar_mm_handle_t handle = get_ar_multimedia_core_device_handle();
    cam_raw_get_context((void**)&context, &context_size);

    //stop sensor streaming
    ret |= tof_sensor.video_streaming(0);
    if(ret < 0){
        return -1;
    }
    printf("stop_stream success\n");
    //stop rtos pipeline
    if(ar_pipeline_terminal_stream(handle, (ar_pipeline_t)context->pipeline.element) != 0){
        printf("pipeline_terminal fail!\n");
        return -1;
    }
    printf("terminal_stream success\n");
    //modify pad 
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 3),
                                AR_COMMON_META_VIDEO_WIDTH_NAME     ,&w     , sizeof(uint32_t));
    printf("%d\n", log++);
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 3),
                                AR_COMMON_META_VIDEO_HEIGHT_NAME    ,&h     , sizeof(uint32_t));
    printf("%d\n", log++);
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 3),
								AR_COMMON_META_VIDEO_FPS_NUM_NAME   ,&fps   , sizeof(uint32_t));
    printf("%d\n", log++);
	ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 3),
								AR_COMMON_META_VIDEO_FPS_DEN_NAME   ,&den   , sizeof(uint32_t));
    printf("%d\n", log++);
    // ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src.element, 3),
    //                         AR_COMMON_META_VIDEO_SUBSUMPLE_RATE,&usr_cfg_ppl->subsample_rate, sizeof(uint32_t));

	    /* change icc_proxy_sink property */
	ar_element_modify_property_value(handle, context->buf_sink_0.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth, sizeof(uint32_t));
    printf("%d\n", log++);
    //set pipeline state ready
    ar_element_set_state(handle, (ar_pipeline_t)context->pipeline.element,AR_ELEMENT_STATE_READY);
    printf("%d\n", log++);


    int set_count;
    do{
            usleep(10000);//delay 10ms
            printf("delay100ms\n");
    }while(++set_count<10 && ar_element_get_state(handle, (ar_pipeline_t)context->pipeline.element) != AR_ELEMENT_STATE_PLAYING);

    //start sensor stream.(tof start stream in rtos use pipeline auto.)
    //

    printf("ar_element swich res success\n");
    return 0;    
}


/*
    obc cam start stream
    return < 0 err;
*/
int tof_cam_stream_on(void)
{
    int ret = 0;

    ret |= tof_sensor.video_streaming(1);
    if(!ret) tof_sensor.streaming_en = 1;

    printf("sensor stream on\n");

    return ret;
}

/*
    obc cam close stream
    return < 0 err;
*/
int tof_cam_stream_off(void)
{
    int ret = 0;

    /* close sensor */
    ret |= tof_sensor.video_streaming(0);
    if(!ret) tof_sensor.streaming_en = 0;

    printf("sensor stream off\n");
    // ret |= s5k33d_i2c_close();
    return ret;
}

/* sensor cci ctl */
/* laser driver ctl */


/*
    obc cam capture mipi raw data
    return < 0 err;
*/
int capture_cam_raw(uint32_t frame_cnt)
{
    cam_raw_config_t obj;

    obj.frame_count =  frame_cnt;
    pthread_cond_init(&obj.buf_signal,NULL);
    pthread_mutex_init(&obj.mutex, NULL);
    obj.buf_que = ar_creat_queue(MAX_MEM_FIFO, "buf_sink_0");
    pthread_create(&obj.thread_id, NULL, (void*)get_sink_buf_0_thread, (void*)&obj);
    pthread_create(&obj.thread_process_id, NULL, (void*)process_sink_buf_0_thread, (void*)&obj);   
    sleep(1);
    
    return 0;
}


//sensor api test
int sensor_api_test(void)
{
    int ret = 0;
    uint8_t val_A, val_B;

    // ret |= s5k33dxx_video_streaming(0);

    uint16_t id;
    ret |= s5k33dxx_get_sensor_id(&id);
    printf("sensor id:0x%x\n", id);

    uint8_t fps = 90;
    ret |= s5k33dxx_set_fps(fps);
    ret |= s5k33dxx_get_fps(&fps);
    printf("fps:%d\n", fps);

    uint16_t integrationTime = 999;
    ret |= s5k33dxx_set_integration_time(integrationTime);
    ret |= s5k33dxx_get_integration_time(&integrationTime);
    printf("integrationTime:%d\n",integrationTime);

    uint8_t mirror = 1;
    ret |= s5k33dxx_set_img_mirror_flip(mirror);
    ret |= s5k33dxx_get_img_mirror_flip(&mirror);
    printf("mirror:%d\n", mirror);
    
    ret |= s5k33dxx_video_streaming(1);

    s5k33dxx_get_illum_power(&val_A, &val_B);
    printf("get def illum_power A:0x%x, B:0x%x\n",val_A, val_B);

    uint8_t duty = 55; //有问题，设置下去之后，寄存器读出来一直为0
    ret |= s5k33dxx_set_illum_duty_cycle(duty);
    ret |= s5k33dxx_get_illum_duty_cycle(&duty);
    printf("illum_duty:0x%x\n", duty);

    uint8_t bin_mode = 1;
    ret |= s5k33d_set_pixel_binning(bin_mode);
    ret |= s5k33d_get_pixel_binning(&bin_mode);
    printf("binning mode:0x%x\n", bin_mode);

    uint16_t modFreq;
    ret |= s5k33dxx_get_modulation_frequency(&modFreq);
    printf("get_frequency: modFreq:0x%x, freq0:%d, freq1:%d\n", modFreq, modFreq>>8, modFreq&0xff);

    uint16_t freq_0 = 100, freq_1 = 70;
    modFreq = ((freq_0 << 8) | freq_1);
    ret |= s5k33dxx_set_modulation_frequency(modFreq);
    printf("set_modulation_frequency: freq0:%d, freq1:%d\n", freq_0, freq_1);

    ret |= s5k33dxx_get_modulation_frequency(&modFreq);
    printf("get_frequency: modFreq:0x%x, freq0:%d, freq1:%d\n", modFreq, modFreq>>8, modFreq&0xff);


    val_A = 0x0;
    val_B = 0x0;
    s5k33dxx_set_illum_power(val_A, val_B);
    printf("set_illum_power A:0x%x, B:0x%x\n",val_A, val_B);
    s5k33dxx_get_illum_power(&val_A, &val_B);
    printf("get_illum_power A:0x%x, B:0x%x\n",val_A, val_B);

    usleep(5000000);
    s5k33dxx_illum_power_control(1);
    s5k33dxx_get_illum_power(&val_A, &val_B);
    printf("get def illum_power A:0x%x, B:0x%x\n",val_A, val_B);

    usleep(5000000);
    s5k33dxx_illum_power_control(0);
    s5k33dxx_get_illum_power(&val_A, &val_B);
    printf("get def illum_power A:0x%x, B:0x%x\n",val_A, val_B);

    // ret |= s5k33dxx_video_streaming(0);
    return ret;
}

/*
    obc cam close stream
    return < 0 err;
*/
int one_thread_test(int argc, char *argv[])
{
    int ret = 0;

    /* 0。 cat usr config params */
    cam_get_usr_cfg(argc, argv);

    /* 1. init tof cam_src pipeline */
    cam_handle_t *handle = get_ob_cam_handle();
    ret |= init_tof_cam(handle);

    
    /* 2. open tof cam_src pipeline to READY */
    ret |= open_tof_cam(handle->tof_cam_id);

    /* 3. sensor cfg */


    /* sensor start stream */
    ret |= tof_cam_stream_on();
    /* save raw piture */
    ret |= capture_cam_raw(1); // fixme : get capture over time!
    sleep(2);
    /* close tof camera */
    ret |= close_tof_cam(handle->tof_cam_fd);

    return ret;
}


/*
lib调试/测试方法：
编译出执行文件后，在设备执行：
1，上电首次执行：/ # /media/usbsda1/obc_tof_drv  --init&
2，已经执行过init之后，执行/ # /media/usbsda1/obc_tof_drv  --open --on --save&， 可以存raw图
3，已经执行过init之后，执行/ # /media/usbsda1/obc_tof_drv  --open --api&, 测试api接口
4，已经执行过init之后，执行/ # /media/usbsda1/obc_tof_drv  --open --close& 关闭camera
*/
int main (int argc, char *argv[])
{
    int pra_index=0;
    cam_raw_config_t obj;
    uint32_t frame_count = 1;
    uint32_t exp_time = 0;
    ar_mm_handle_t cur_handle = NULL;
    int cam_fd;
    int camera_id = 0;
    int cam_status = 0;
    int ret;
    volatile static uint16_t reg, val;


    pra_index=find_pra_index_by_name("--help",argc,argv);
	if(pra_index>0)
	{
	    printf("--help: show this help info\n");
		printf("--size w h: set cam out w && h,default is 1280 962\n");
		printf("--cam_id id: set cam id,default is 0\n");
		printf("--count frame_count: set the dump frames,the default is 1\n");
		printf("--subsample_rate  [rate]: set vif view subsample \n");
        printf("--open: open obc_camera \n");
        printf("--close: close obc_camera \n");
        printf("--on: stream on \n");
        printf("--off: stream off \n");
        printf("--save: capture raw stream \n");
        printf("--init: init cam_src pipeline \n");
        printf("--remove: remove cam_src pipeline \n");
        printf("--test1: test all API in one thread \n");
        printf("--api: api test (usage: --open --api) \n");
        printf("--pipfps: rtos pipeline parames of fps \n");
        printf("--fps: api test (usage: --open --fps --on) \n");
        printf("--i2c_read: (usage: --i2c_read reg) \n");
        printf("--i2c_write: (usage: --i2c_write reg val) \n");
        printf("--laser_read: (usage: --laser_read reg) \n");
        printf("--laser_write: (usage: --laser_write reg val) \n");
        printf("--switch: w h ,switch resolution to w * h\n");
        printf("--set_laser_current: current(mA) set laser current\n");
        printf("--sel_setting: laser_type(4016) sensor_type(0), select setting of tof\n");
		return 0;
	}

    /* save picture counts */
    pra_index = find_pra_index_by_name("--count", argc, argv);
    if(pra_index > 0){
        frame_count = atoi(argv[pra_index + 1]);
        printf("frame count: %d\n", frame_count);
    }

    /* camera_src init test */
    pra_index = find_pra_index_by_name("--init", argc, argv);
    if(pra_index > 0){
        cam_get_usr_cfg(argc, argv);
        cam_handle_t *handle = get_ob_cam_handle();
        ret |= init_tof_cam(handle);
        if(ret < 0){
            printf("init camera failed!\n");
        }
        // return 0;
    }

    /* select tof setting , 开机app起来后不开流情况下直接使用*/
    pra_index = find_pra_index_by_name("--sel_setting", argc, argv);
    if(pra_index > 0){
        uint32_t laser_tp, sensor_tp;
        if (StrToNumber(argv[pra_index + 1], &laser_tp) != 0) 
            goto end0;

        if (StrToNumber(argv[pra_index + 2], &sensor_tp) != 0) 
            goto end0;

        sensor_list_setup(laser_tp, sensor_tp);

        tof_sensor_api_init();
        tof_sensor.i2c_open();

        ret = tof_sensor.init();
        if(ret){
            printf("[err]load setting failed\n");
            goto end0;
        }
        tof_sensor.video_streaming(1);//todo: start stream when app not send stream start
        // tof_sensor.i2c_close();
    }

    //tof_switch_stream
    pra_index = find_pra_index_by_name("--switch", argc, argv);
    if(pra_index > 0){
        uint32_t w = atoi(argv[pra_index + 1]);
        uint32_t h = atoi(argv[pra_index + 2]);
        int dl = 10;
        do{
            usleep(1000 * 1000);
            printf("delay 1s\n");
        }while(--dl > 0);
        tof_switch_stream(w, h);
        // return 0;
    }

    /* camera open test */
    pra_index = find_pra_index_by_name("--open", argc, argv);
    if(pra_index > 0){
        cam_handle_t *handle = get_ob_cam_handle();
        if(open_tof_cam(handle->tof_cam_id) < 0){
            printf("Open camera failed!\n");
            // return -1;
        }
        // return 0;
    }

    /* i2c read */
    pra_index = find_pra_index_by_name("--i2c_read", argc, argv);
    if(pra_index > 0){
        tof_sensor_api_init();
        tof_sensor.i2c_open();

        if (StrToNumber(argv[pra_index + 1], &reg) != 0) {
			// print_r_usage();
			ret = -1;
			goto end0;
		}

        // reg = atoi(argv[pra_index + 1]);


        ret = tof_sensor.sensor_i2c_read(reg, &val);
        if(ret < 0) 
            printf("sensor_i2c_read failed!\n");
        else
            printf("sensor i2c read 0x%x : 0x%x\n", reg, val);

        tof_sensor.i2c_close();
    }
    /* i2c write */
    pra_index = find_pra_index_by_name("--i2c_write", argc, argv);
    if(pra_index > 0){
        tof_sensor_api_init();
        tof_sensor.i2c_open();

        if (StrToNumber(argv[pra_index + 1], &reg) != 0) {
            // print_r_usage();
            ret = -1;   
            goto end0;
		}
        if (StrToNumber(argv[pra_index + 2], &val) != 0) {
            // print_r_usage();
            ret = -1;   
            goto end0;
		}
        ret = tof_sensor.sensor_i2c_write(reg, val);
        if(ret < 0) 
            printf("sensor_i2c_write failed!\n");
        else
            printf("sensor i2c write 0x%x : 0x%x\n", reg, val);

        tof_sensor.i2c_close();
    }
    /* laser read */
    pra_index = find_pra_index_by_name("--laser_read", argc, argv);
    if(pra_index > 0){
        tof_sensor_api_init();
        tof_sensor.i2c_open();

        if (StrToNumber(argv[pra_index + 1], &reg) != 0) {
            // print_r_usage();
            ret = -1;   
            goto end0;
		}

        ret = tof_sensor.laser_i2c_read(reg, &val);
        if(ret < 0) 
            printf("laser_i2c_read failed!\n");
        else
            printf("laser_i2c_read 0x%x : 0x%x\n", reg, val);

        tof_sensor.i2c_close();
    }
    /* laser write */
    pra_index = find_pra_index_by_name("--laser_write", argc, argv);
    if(pra_index > 0){
        tof_sensor_api_init();
        tof_sensor.i2c_open();

        if (StrToNumber(argv[pra_index + 1], &reg) != 0) {
            // print_r_usage();
            ret = -1;   
            goto end0;
		}
        if (StrToNumber(argv[pra_index + 2], &val) != 0) {
            // print_r_usage();
            ret = -1;   
            goto end0;
		}
        ret = tof_sensor.laser_i2c_write(reg, val);
        if(ret < 0) 
            printf("laser_i2c_write failed!\n");
        else
            printf("laser_i2c_write 0x%x : 0x%x\n", reg, val);

        tof_sensor.i2c_close();
    }

    /* camera close test */
    pra_index = find_pra_index_by_name("--close", argc, argv);
    if(pra_index > 0){
        cam_handle_t *handle = get_ob_cam_handle();
        if(close_tof_cam(handle->tof_cam_fd) < 0){
            printf("Close camera failed!\n");
            // return -1;
        }
        // return 0;
    }

    pra_index = find_pra_index_by_name("--fps", argc, argv);
    if(pra_index > 0){
        tof_sensor_api_init();
        tof_sensor.i2c_open();

        int fps = atoi(argv[pra_index+1]);
        printf("sensor test set fps: %d\n", fps);
        if(tof_sensor.set_fps(fps) < 0){
            printf("sensor_api_test failed!\n");
        }
        tof_sensor.i2c_close();
    }

    /* set laser current */
    pra_index = find_pra_index_by_name("--set_laser_current", argc, argv);
    if(pra_index > 0){
    uint32_t value = atoi(argv[pra_index + 1]);
    printf("set laser current to ..%dmA\n", value);

    tof_sensor_api_init();
    tof_sensor.i2c_open();
    uint8_t value_A = (uint8_t)((float)value/14.8);
    uint8_t value_B = 0;
    printf("value A set to 0x%x\n", value_A);
    ret = tof_sensor.set_illum_power(value_A , value_B);  //设置激光电流，B通道的值为0，只设置A通道
    tof_sensor.i2c_close();
    }

    /* camera stream on test */
    pra_index = find_pra_index_by_name("--on", argc, argv);
    if(pra_index > 0){
        tof_sensor_api_init();
        tof_sensor.i2c_open();

        tof_sensor.video_streaming(1);

        tof_sensor.i2c_close();
    }

    /* camera stream off test */
    pra_index = find_pra_index_by_name("--off", argc, argv);
    if(pra_index > 0){
        tof_sensor_api_init();
        tof_sensor.i2c_open();

        tof_sensor.video_streaming(0);
        
        tof_sensor.i2c_close();
    }

    /* camera_src remove test */
    pra_index = find_pra_index_by_name("--remove", argc, argv);
    if(pra_index > 0){
       
        // return 0;
    }

    /* camera_src test all API */
    pra_index = find_pra_index_by_name("--test1", argc, argv);
    if(pra_index > 0){
        if(one_thread_test(argc,argv) < 0){
            printf("one_thread_test failed!\n");
        }
    }

    /* camera_src test all API */
    pra_index = find_pra_index_by_name("--api", argc, argv);
    if(pra_index > 0){
        if(sensor_api_test() < 0){
            printf("sensor_api_test failed!\n");
        }
    }

    /* camera capture picture test */
    pra_index = find_pra_index_by_name("--save", argc, argv);
    if(pra_index > 0){

        capture_cam_raw(frame_count);
 
    }
end0:
    return 0;
}
