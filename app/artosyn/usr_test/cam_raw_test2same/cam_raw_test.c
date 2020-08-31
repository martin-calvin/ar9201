#define ENABALE_ALL_LOG

#include "cam_raw_test.h"
#include "ar_cam_src.h"

//#define PRINT(x,...) printf(x, ##__VA_ARGS__)
#define PRINT(x,...) 


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
    static ar_facotry_element_obj_t cam_raw_init_list[] =
    {
        {"pipeline",NULL,NULL},
        {"cam_src","cam_src-0",NULL},
        {"icc_proxy_rpc_sink","icc_proxy_rpc_sink-0",NULL},
        {"cam_src","cam_src-1",NULL},
        {"icc_proxy_rpc_sink","icc_proxy_rpc_sink-1",NULL},
    };
    *context = (void*)&cam_raw_init_list;
    *context_size = sizeof(cam_raw_init_list)/sizeof(ar_facotry_element_obj_t);
    return;
}

typedef struct {
    uint32_t width;
    uint32_t height;
}Type_cam_res;

static int32_t cam_raw_init_impl(int argc, char *argv[])

{
    ar_mm_handle_t handle = NULL;

    Type_cam_res cam0_res = {1280, 970}; // first probe camera resulotion
    Type_cam_res cam1_res = {1920, 1080};// second probe camera resulotion

    uint32_t width = 1920, height = 1080;
	uint32_t scaler_2_width=1280,scaler_2_height=800;
    int cam_id=0;
    cam_raw_context_t* context = NULL;
    uint32_t context_size = 0;
    int pra_index=0;
    char *cam_mod=AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE;
	char *vif_isp_mode=AR_VIDEO_CAM_VIF_ISP_MOD_DDR;
	int fps=30;
	int use_meta=0;
	int use_scaler2=0;
	int queue_depth=2;
	int no_display=0;
    int den=1;
	int subsample_rate=15;
	pra_index=find_pra_index_by_name("--cam_id",argc,argv);
    if(pra_index>0)
    {
        cam_id=atoi(argv[pra_index+1]);
		log_always("cam_id=%d",cam_id);
    }
#if 0
	pra_index=find_pra_index_by_name("--size",argc,argv);
    if(pra_index>0)
    {
        width=atoi(argv[pra_index+1]);
		height=atoi(argv[pra_index+2]);
		log_always("width=%d height=%d",width,height);
    }
#endif
     pra_index=find_pra_index_by_name("--subsample_rate",argc,argv);
    if(pra_index>0)
    {
        subsample_rate=atoi(argv[pra_index+1]);
		log_always("subsample_rate=%d",subsample_rate);
    }

	pra_index=find_pra_index_by_name("--fps",argc,argv);
    if(pra_index>0)
    {
        fps=atoi(argv[pra_index+1]);
		log_always("fps=%d",fps);
    }

    handle = ar_multimedia_core_device_open();
    if(!handle) {
        printf("%s, open multimedia core device failed.", __FUNCTION__);
        return AR_MULTIMEDIA_FAILURE;
    }
    cam_raw_get_context((void**)&context, &context_size);
    if(ar_element_factory_make_many(handle, context_size, (ar_facotry_element_obj_t*)context) != AR_MULTIMEDIA_SUCCESS)
        return AR_MULTIMEDIA_FAILURE;
    /* change cam src property */
    cam_id=0;
    ar_element_modify_property_value(handle, context->cam_src_0.element,AR_VIDEO_CAM_SET_ID,&cam_id, sizeof(uint32_t));
    cam_id=1;
    ar_element_modify_property_value(handle, context->cam_src_1.element,AR_VIDEO_CAM_SET_ID,&cam_id, sizeof(uint32_t));


    ar_element_modify_property_value(handle, context->cam_src_0.element,
                                   AR_VIDEO_CAM_MODE,
                                   cam_mod,
                                   strlen(cam_mod)+1);
    ar_element_modify_property_value(handle, context->cam_src_0.element,
                                   AR_VIDEO_CAM_VIF_ISP_MOD,
                                   vif_isp_mode,
                                   strlen(vif_isp_mode)+1);
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src_0.element, 3),
                            AR_COMMON_META_VIDEO_WIDTH_NAME,&cam0_res.width, sizeof(uint32_t));
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src_0.element, 3),
                            AR_COMMON_META_VIDEO_HEIGHT_NAME,&cam0_res.height, sizeof(uint32_t));

	ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src_0.element, 3),
								AR_COMMON_META_VIDEO_FPS_NUM_NAME,&fps, sizeof(uint32_t));
	ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src_0.element, 3),
								AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den, sizeof(uint32_t));

    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src_0.element, 3),
                            AR_COMMON_META_VIDEO_SUBSUMPLE_RATE,&subsample_rate, sizeof(uint32_t));




    ar_element_modify_property_value(handle, context->cam_src_1.element,
                                   AR_VIDEO_CAM_MODE,
                                   cam_mod,
                                   strlen(cam_mod)+1);
    ar_element_modify_property_value(handle, context->cam_src_1.element,
                                   AR_VIDEO_CAM_VIF_ISP_MOD,
                                   vif_isp_mode,
                                   strlen(vif_isp_mode)+1);
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src_1.element, 3),
                            AR_COMMON_META_VIDEO_WIDTH_NAME,&cam1_res.width, sizeof(uint32_t));
    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src_1.element, 3),
                            AR_COMMON_META_VIDEO_HEIGHT_NAME,&cam1_res.height, sizeof(uint32_t));

	ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src_1.element, 3),
								AR_COMMON_META_VIDEO_FPS_NUM_NAME,&fps, sizeof(uint32_t));
	ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src_1.element, 3),
								AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den, sizeof(uint32_t));

    ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, context->cam_src_1.element, 3),
                            AR_COMMON_META_VIDEO_SUBSUMPLE_RATE,&subsample_rate, sizeof(uint32_t));







	/* change icc_proxy_sink property */
	ar_element_modify_property_value(handle, context->buf_sink_0.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth, sizeof(uint32_t));
	ar_element_modify_property_value(handle, context->buf_sink_1.element, AR_ICC_PROXY_SINK_QUEUE_DEPTH, &queue_depth, sizeof(uint32_t));


	/* add all element to pipeline/subpipe */
    ar_pipeline_add_many(handle, (ar_pipeline_t)context->pipeline.element,context->cam_src_0.element,NULL);
    ar_pipeline_add_many(handle,(ar_pipeline_t)context->pipeline.element,context->buf_sink_0.element,NULL);
    ar_pipeline_add_many(handle, (ar_pipeline_t)context->pipeline.element,context->cam_src_1.element,NULL);
    ar_pipeline_add_many(handle,(ar_pipeline_t)context->pipeline.element,context->buf_sink_1.element,NULL);


    ar_pad_link_by_element(handle, context->cam_src_0.element, 3, context->buf_sink_0.element, 0);
    ar_pad_link_by_element(handle, context->cam_src_1.element, 3, context->buf_sink_1.element, 0);

    ar_element_set_state(handle, (ar_pipeline_t)context->pipeline.element,AR_ELEMENT_STATE_READY);

#if 1
    uint32_t set_count = 0;
    do{
        printf("Wait Pipeline Ready...\n");
        set_count++;
        usleep(100000);//delay 100ms
    }while(ar_element_get_state(handle, (ar_pipeline_t)context->pipeline.element) != AR_ELEMENT_STATE_PLAYING);
    printf("rots element set complete! %d\n", set_count);
#endif
    return AR_MULTIMEDIA_SUCCESS;
}

int32_t cam_raw_init(int argc, char *argv[])
{
    return cam_raw_init_impl(argc,argv);
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
        unsigned int fetched_count=0;
        
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
    obj->fd = open(RAW_DATA_PATH0, O_RDWR | O_CREAT);
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
        printf("sink0:the mem count = %d\n", buffer->mem_num);
        printf("sink0:frame id = %d\n", buffer->frame_id);
        printf("sink0:pts = %d\n", buffer->pts);
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
        PRINT("sink0:buf len = %d, %d, %d\n", buffer->mem[0].len, buffer->mem[1].len, buffer->mem[2].len);
        gettimeofday(&start, NULL);
        memcpy(buf->buf_mem, buffer->mem[0].addr, data_len);
        gettimeofday(&end, NULL);
        pthread_mutex_lock(&obj->mutex);
        if(obj->buf_que->queue_insert(obj->buf_que, buf)){
            printf("sink0:insert queue err\n");
        }
        pthread_cond_signal(&obj->buf_signal);
        pthread_mutex_unlock(&obj->mutex);
        if(ar_picture_release_img(img_handle, buffer)){
            printf("sink0:release buffer failed\n");
            return;
        }
                if (fetched_count%1200==0) {
            gettimeofday(&start, NULL);
            printf("thread0:%u.%06u\n",start.tv_sec,start.tv_usec);
        }
        fetched_count++;
        
    }
    printf("sink0:buf 0 write finish\n");
}


void get_sink_buf_1_thread(void *arg)
{
    struct timeval start, end;
    ar_picture_buffer_t *buffer = NULL;
    ar_picture_handle img_handle = NULL;
    int fd ;
    cam_raw_config_t *obj = (cam_raw_config_t*)arg;
    int data_len = 0;
    cam_buffer_t *buf;
    unsigned int fetched_count=0;
    obj->buf_sink_fd = ar_picture_open("/dev/icc_proxy_rpc_sink-1");
    if(obj->buf_sink_fd < 0){
        printf("open sink 0 error\n");
        return ;
    }

    img_handle = (ar_picture_handle)(obj->buf_sink_fd);
    if(!img_handle){
        printf("handle is null\n");
        return;
    }
    obj->fd = open(RAW_DATA_PATH1, O_RDWR | O_CREAT);
    if(obj->fd < 0){
        printf("open file error\n");
        return ;
    }

    while(obj->frame_count > 0){
        buffer = NULL;
        buffer = ar_picture_get_img(obj->buf_sink_fd);
        if(!buffer){
            printf("get sink 1 buffer error\n");
            continue ;
        }
        printf("sink1:the mem count = %d\n", buffer->mem_num);
        printf("sink1:frame id = %d\n", buffer->frame_id);
        printf("sink1:pts = %d\n", buffer->pts);
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
        printf("sink1:buf len = %d, %d, %d\n", buffer->mem[0].len, buffer->mem[1].len, buffer->mem[2].len);
        gettimeofday(&start, NULL);
        memcpy(buf->buf_mem, buffer->mem[0].addr, data_len);
        gettimeofday(&end, NULL);
        pthread_mutex_lock(&obj->mutex);
        if(obj->buf_que->queue_insert(obj->buf_que, buf)){
            printf("sink1:insert queue err\n");
        }
        pthread_cond_signal(&obj->buf_signal);
        pthread_mutex_unlock(&obj->mutex);
        if(ar_picture_release_img(img_handle, buffer)){
            printf("sink1:release buffer failed\n");
            return;
        }
        
        if (fetched_count%1200==0) {
            gettimeofday(&start, NULL);
            printf("thread1:%u.%06u\n",start.tv_sec,start.tv_usec);
        }
        fetched_count++;
        
    }
    printf("sink1:buf 1 write finish\n");
}



int main (int argc, char *argv[])
{
    int pra_index=0;
    cam_raw_config_t obj0;
    cam_raw_config_t obj1;
    uint32_t frame_count = 1;
    uint32_t exp_time = 0;
    int cam_fd;
    int camera_id = 0;
    char device_name[64];

    pra_index=find_pra_index_by_name("--help",argc,argv);
	if(pra_index>0)
	{
	    printf("--help: show this help info\n");
		printf("--size w h: set cam out w && h,default is 1920 1080\n");
		printf("--cam_id id: set cam id,default is 0\n");
		printf("--count frame_count: set the dump frames,the default is 1\n");
		printf("--subsample_rate  [rate]: set vif view subsample \n");
        printf("--fps: fps of camera \n");
		return 0;
	}
    pra_index = find_pra_index_by_name("--count", argc, argv);
    if(pra_index > 0){
        frame_count = atoi(argv[pra_index + 1]);
        printf("frame count: %d\n", frame_count);
    }

    if(cam_raw_init(argc,argv)!=AR_MULTIMEDIA_SUCCESS)
    {
       return 0;
    }

    camera_id=0;
    sprintf(device_name, "/dev/cam_src-%d", camera_id);
    cam_fd = ar_cam_src_open(device_name);
    if(cam_fd < 0){
        printf("open cam element error\n");
        return -1;
    }

#if 1
    camera_id=1;
    sprintf(device_name, "/dev/cam_src-%d", camera_id);
    cam_fd = ar_cam_src_open(device_name);
    if(cam_fd < 0){
        printf("open cam element error\n");
        return -1;
    }
#endif

    obj0.frame_count =  frame_count;
    pthread_cond_init(&obj0.buf_signal,NULL);
    pthread_mutex_init(&obj0.mutex, NULL);
    obj0.buf_que = ar_creat_queue(MAX_MEM_FIFO, "buf_sink_0");
    pthread_create(&obj0.thread_id, NULL, (void*)get_sink_buf_0_thread, (void*)&obj0);
    pthread_create(&obj0.thread_process_id, NULL, (void*)process_sink_buf_0_thread, (void*)&obj0);

#if 1
    obj1.frame_count =  frame_count;
    pthread_cond_init(&obj1.buf_signal,NULL);
    pthread_mutex_init(&obj1.mutex, NULL);
    obj1.buf_que = ar_creat_queue(MAX_MEM_FIFO, "buf_sink_1");
    pthread_create(&obj1.thread_id, NULL, (void*)get_sink_buf_1_thread, (void*)&obj1);
    pthread_create(&obj1.thread_process_id, NULL, (void*)process_sink_buf_0_thread, (void*)&obj1);
#endif



    while(1){
        sleep(1);
    }

    return 0;
}
