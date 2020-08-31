#include <test_audio.h>


ctl_param audio_test_param = {0};

int find_cmd_pra_index_by_name(char *name,thread_arg *argv)
{
    int index=-1;
	for(int i=0;i<argv->argc;i++)
	{
         if(!strcmp(name,argv->argv[i]))
         {
             index = i;
			 break;
         }
	}
	return index;
}


static thread_arg *get_args(const char *cmd)
{
  thread_arg * args=(thread_arg *)malloc(sizeof(thread_arg));
  char *p_cmd=(char *)malloc(1024);
  char *p_str=NULL;
  char  *split_char=" ";
  char *p_free_p_cmd=p_cmd;
  memset(args,0,sizeof(thread_arg));
  strcpy(p_cmd,cmd);
  p_str=strtok(p_cmd,split_char);
  if(p_str)
  {
    strcpy(&args->argv[args->argc][0],p_str);
    args->argc++;
  }
  while(p_str)
  {
    p_str=strtok(NULL,split_char);
    if(p_str)
    {
      strcpy(&args->argv[args->argc][0],p_str);
      args->argc++;
    }
  }
  free(p_free_p_cmd);
  return args;
}




static void print_help(void){
	printf("create_record_pipeline: -i2s [0~3] -as [8000/48000] -aenc [yes/no] -avol [0~255] -pch [1/2]\n");
	printf("create_single_record_pipeline: -i2s [0~3] (-clkdev [0~3]) -as [8000/48000] -aenc [yes/no] -avol [0~255] -pch [1/2]\n");
	printf("create_play_pipeline: -i2s [0~3]-as [8000/48000] -adec [yes/no] -avol [0~255] -pch [1/2]\n");
	printf("start_record: [/dev/audio_in] [/dev/audio_in2] [pcm/aac] [record_path1] [record_path2] [record_size(k)]\n");
	printf("start_single_record: [/dev/audio_in] [pcm/aac] [record_path1] [record_size(k)]\n");
	printf("start_play: [/dev/audio_out] [/dev/audio_out2] [pcm/aac] [path1] [path2]\n");
	printf("start_audio_pipeline : [/dev/pipeline_audio_in / /dev/pipeline_audio_out]\n");
	printf("stop_audio_pipeline : [/dev/pipeline_audio_in / /dev/pipeline_audio_out]\n");
	printf("change_audio_sample_rate : [/dev/pipeline_audio_in / /dev/pipeline_audio_out] [aac/pcm] [8000/44100/48000]\n");
	printf("change_audio_volume : [/dev/pipeline_audio_in / /dev/pipeline_audio_out] [0~255]\n");
}

static void * record_get_context(void **context, uint32_t *context_size)
{
    void *context_p = NULL;
    ar_facotry_element_obj_t record_list[] =
    {
        {"pipeline",{"pipeline_audio_in"},NULL},
        {"icc_proxy_rpc_sink",{"audio_in"},NULL},
        {"icc_proxy_rpc_sink",{"audio_in2"},NULL},
        {"aac_encoder","aac_encoder",NULL},
        {"aac_encoder","aac_encoder2",NULL},
        {"i2s_src",{""},NULL},
    };

    context_p = malloc(sizeof(record_list));
    memcpy(context_p, record_list, sizeof(record_list));
    *context_size = sizeof(record_list)/sizeof(ar_facotry_element_obj_t);
    *context = context_p;
    return context_p;

}

void * play_get_context(void **context, uint32_t *context_size)
{
    void *context_p = NULL;
    ar_facotry_element_obj_t play_list[] =
    {
        {"pipeline",{"pipeline_audio_out"},NULL},
        {"icc_proxy_rpc_src",{"audio_out"},NULL},
        {"icc_proxy_rpc_src",{"audio_out2"},NULL},
        {"aac_decoder","aac_decoder",NULL},
        {"aac_decoder","aac_decoder2",NULL},
        {"i2s_sink",{""},NULL},
		{"audioplay_middle",{"audioplay_middle"},NULL},
		{"audioplay_middle",{"audioplay_middle2"},NULL},
    };

    context_p = malloc(sizeof(play_list));
    memcpy(context_p, play_list, sizeof(play_list));
    *context_size = sizeof(play_list)/sizeof(ar_facotry_element_obj_t);
    *context = context_p;
    return context_p;
}

static void create_record_pipeline(char* arg){
	int i2s_id = 0;
	int audio_sample_rate;
	int audio_vol;
	int pcm_ch;
	char* audio_enc = malloc(16*sizeof(char));
	ar_mm_handle_t handle = NULL;
	record_context_t * audio_context = NULL;
	int audio_context_size;
	int i2s_devide_mode_on = 1;
	thread_arg *parg = get_args(arg);

	int index = find_cmd_pra_index_by_name("-i2s",parg);//audio sample rate(8000 44100 48000)
	if(index >= 0)
	{
		i2s_id = atoi(parg->argv[index+1]);
	}

	index = find_cmd_pra_index_by_name("-as",parg);//audio sample rate(8000 44100 48000)
	if(index >= 0)
	{
		audio_sample_rate = atoi(parg->argv[index+1]);
	}

	index = find_cmd_pra_index_by_name("-avol",parg);//audio vol(0-255)
	if(index >= 0)
	{
		audio_vol = atoi(parg->argv[index+1]);
	}

	index = find_cmd_pra_index_by_name("-pch",parg);//only for pcm mode
	if(index >= 0)
	{
		pcm_ch = atoi(parg->argv[index+1]);
	}

	index = find_cmd_pra_index_by_name("-aenc",parg);//yes/no, if record pcm,add -aenc no
	if(index >= 0)
	{
		audio_enc = parg->argv[index+1];
	}

//========================================================
	handle = ar_multimedia_core_device_open();
    if(!handle)
    {
	    printf("%s: open multimedia core device failed\ns", __func__);
	    return;
    }
	audio_test_param.record_handle = handle;
    audio_context = record_get_context((void**)(&audio_context), &audio_context_size);
	audio_test_param.record_context = audio_context;

    if(ar_element_factory_make_many(handle, audio_context_size, audio_context) != AR_MULTIMEDIA_SUCCESS)
	{
		printf("%s: Make element failed!\n", __func__);
		ar_multimedia_core_device_close(handle);
		return;
    }
	ar_element_modify_property_value(handle, audio_context->i2s_src.element, AR_AUDIO_I2S_SET_ID, &i2s_id, sizeof(uint32_t));
	ar_element_modify_property_value(handle, audio_context->i2s_src.element, AR_AUDIO_I2S_SET_DEVIDE_MODE_ON, &i2s_devide_mode_on, sizeof(uint32_t));
	ar_element_modify_property_value(handle, audio_context->i2s_src.element, AR_AUDIO_I2S_SET_SAMPLE_RATE, &audio_sample_rate, sizeof(uint32_t));
	ar_element_modify_property_value(handle, audio_context->i2s_src.element, AR_AUDIO_I2S_SET_CODEC_VOL, &audio_vol, sizeof(int));
	ar_element_modify_property_value(handle, audio_context->i2s_src.element, AR_AUDIO_I2S_SET_PCM_CH,  &pcm_ch, sizeof(uint32_t));
	if(!strcmp(audio_enc, "yes")){
		ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, audio_context->i2s_src.element, 0),
									AR_COMMON_META_AUDIO_SAMPLE_RATE_NAME,&audio_sample_rate,sizeof(unsigned int));
		ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, audio_context->i2s_src.element, 1),
									AR_COMMON_META_AUDIO_SAMPLE_RATE_NAME,&audio_sample_rate,sizeof(unsigned int));
		ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, audio_context->i2s_src.element, 0),
									AR_COMMON_META_AUDIO_CHANNEL_NAME,&pcm_ch,sizeof(unsigned int));
		ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, audio_context->i2s_src.element, 1),
									AR_COMMON_META_AUDIO_CHANNEL_NAME,&pcm_ch,sizeof(unsigned int));
		ar_pipeline_add_many(handle, (ar_pipeline_t)audio_context->pipeline.element,
					audio_context->audio_in.element,
					audio_context->audio_in2.element,
					audio_context->aac_encoder.element,
					audio_context->aac_encoder2.element,
					audio_context->i2s_src.element,
					NULL);

		ar_pad_link_by_element(handle, audio_context->i2s_src.element, 0, audio_context->aac_encoder.element, 0);
		ar_pad_link_by_element(handle, audio_context->i2s_src.element, 1, audio_context->aac_encoder2.element, 0);
		ar_pad_link_by_element(handle, audio_context->aac_encoder.element, 0, audio_context->audio_in.element, 0);
		ar_pad_link_by_element(handle, audio_context->aac_encoder2.element, 0, audio_context->audio_in2.element, 0);
	}else{
	    ar_pipeline_add_many(handle, (ar_pipeline_t)audio_context->pipeline.element,
	                audio_context->audio_in.element,
	                audio_context->audio_in2.element,
	                audio_context->i2s_src.element,
					NULL);

		ar_pad_link_by_element(handle, audio_context->i2s_src.element, 0, audio_context->audio_in.element, 0);
		ar_pad_link_by_element(handle, audio_context->i2s_src.element, 1, audio_context->audio_in2.element, 0);
	}

	int ret = ar_pipeline_start_stream_nonblocking(handle,(ar_pipeline_t)audio_context->pipeline.element);
	if(ret < 0)
	{
		printf("%s: pipeline start stream blocking failed!\n", __func__);
	}
	//ar_multimedia_core_device_close(handle);

}

static void create_single_record_pipeline(char* arg){
	int i2s_id = 0;
	int i2s_clk_device = -1;
	int audio_sample_rate;
	int audio_vol;
	int pcm_ch = 2;
	char* audio_enc = malloc(16*sizeof(char));
	ar_mm_handle_t handle = NULL;
	record_context_t * audio_context = NULL;
	int audio_context_size;
	thread_arg *parg = get_args(arg);

	int index = find_cmd_pra_index_by_name("-i2s",parg);//i2s bus(0~3)
	if(index >= 0)
	{
		i2s_id = atoi(parg->argv[index+1]);
	}

	index = find_cmd_pra_index_by_name("-clkdev",parg);//clk device(0~3)
	if(index >= 0)
	{
		i2s_clk_device = atoi(parg->argv[index+1]);
	}

	index = find_cmd_pra_index_by_name("-as",parg);//audio sample rate(8000 44100 48000)
	if(index >= 0)
	{
		audio_sample_rate = atoi(parg->argv[index+1]);
	}

	index = find_cmd_pra_index_by_name("-avol",parg);//audio vol(0-255)
	if(index >= 0)
	{
		audio_vol = atoi(parg->argv[index+1]);
	}

	index = find_cmd_pra_index_by_name("-aenc",parg);//pcm no, aac/729 yes
	if(index >= 0)
	{
		audio_enc = parg->argv[index+1];
	}

//========================================================
	handle = ar_multimedia_core_device_open();
    if(!handle)
    {
	    printf("%s: open multimedia core device failed\ns", __func__);
	    return;
    }
	audio_test_param.record_handle = handle;
    audio_context = record_get_context((void**)(&audio_context), &audio_context_size);
	audio_test_param.record_context = audio_context;

    if(ar_element_factory_make_many(handle, audio_context_size, audio_context) != AR_MULTIMEDIA_SUCCESS)
	{
		printf("%s: Make element failed!\n", __func__);
		ar_multimedia_core_device_close(handle);
		return;
    }
	ar_element_modify_property_value(handle, audio_context->i2s_src.element, AR_AUDIO_I2S_SET_ID, &i2s_id, sizeof(uint32_t));
	if(i2s_clk_device >= 0)
		ar_element_modify_property_value(handle, audio_context->i2s_src.element, AR_AUDIO_I2S_GENERATE_BCLK, &i2s_clk_device, sizeof(uint32_t));
	ar_element_modify_property_value(handle, audio_context->i2s_src.element, AR_AUDIO_I2S_SET_SAMPLE_RATE, &audio_sample_rate, sizeof(uint32_t));
	ar_element_modify_property_value(handle, audio_context->i2s_src.element, AR_AUDIO_I2S_SET_CODEC_VOL, &audio_vol, sizeof(int));
	if(!strcmp(audio_enc, "yes")){
		ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, audio_context->i2s_src.element, 0),
									AR_COMMON_META_AUDIO_SAMPLE_RATE_NAME,&audio_sample_rate,sizeof(unsigned int));
		ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, audio_context->i2s_src.element, 0),
									AR_COMMON_META_AUDIO_CHANNEL_NAME,&pcm_ch,sizeof(unsigned int));

		ar_pipeline_add_many(handle, (ar_pipeline_t)audio_context->pipeline.element,
					audio_context->audio_in.element,
					audio_context->aac_encoder.element,
					audio_context->i2s_src.element,
					NULL);

		ar_pad_link_by_element(handle, audio_context->i2s_src.element, 0, audio_context->aac_encoder.element, 0);
		ar_pad_link_by_element(handle, audio_context->aac_encoder.element, 0, audio_context->audio_in.element, 0);
	}else{
	    ar_pipeline_add_many(handle, (ar_pipeline_t)audio_context->pipeline.element,
	                audio_context->audio_in.element,
	                audio_context->i2s_src.element,
					NULL);

		ar_pad_link_by_element(handle, audio_context->i2s_src.element, 0, audio_context->audio_in.element, 0);
	}
    ar_element_set_state(handle, (ar_pipeline_t)audio_context->pipeline.element, AR_ELEMENT_STATE_READY);
#if 0
	int ret = ar_pipeline_start_stream_nonblocking(handle,(ar_pipeline_t)audio_context->pipeline.element);
	if(ret < 0)
	{
		printf("%s: pipeline start stream blocking failed!\n", __func__);
	}
#endif
	//ar_multimedia_core_device_close(handle);

}

static void create_play_pipeline(char *arg)
{
    ar_mm_handle_t handle = NULL;
    ar_mm_handle_t handle2 = NULL;
    play_context_t * audio_context = NULL;
    int audio_context_size = 0;
    int i2s_id = 0;
	int audio_sample_rate;
	int audio_vol;
	int pcm_ch;
	char* audio_dec = malloc(16*sizeof(char));
    int i2s_devide_mode_on = 1;
	int copy = 1;
	thread_arg *parg = get_args(arg);

	int index = find_cmd_pra_index_by_name("-i2s",parg);//audio sample rate(8000 44100 48000)
	if(index >= 0)
	{
		i2s_id = atoi(parg->argv[index+1]);
	}

	index = find_cmd_pra_index_by_name("-as",parg);//audio sample rate(8000 44100 48000)
	if(index >= 0)
	{
		audio_sample_rate = atoi(parg->argv[index+1]);
	}

	index = find_cmd_pra_index_by_name("-avol",parg);//audio vol(0-255)
	if(index >= 0)
	{
		audio_vol = atoi(parg->argv[index+1]);
	}

	index = find_cmd_pra_index_by_name("-pch",parg);//only for pcm mode
	if(index >= 0)
	{
		pcm_ch = atoi(parg->argv[index+1]);
	}

	index = find_cmd_pra_index_by_name("-adec",parg);//yes/no, if record pcm,add -aenc no
	if(index >= 0)
	{
		audio_dec = parg->argv[index+1];
	}

//========================================================

    handle = ar_multimedia_core_device_open();
    if(!handle)
    {
	    printf("%s, open multimedia core device failed.", __FUNCTION__);
	    return;
    }
	audio_test_param.play_handle = handle;
    handle2 = ar_multimedia_core_device_open();
    if(!handle2)
    {
	    printf("%s, open multimedia core device failed.", __FUNCTION__);
	    return;
    }
	audio_test_param.play_handle2 = handle2;

    audio_context = play_get_context((void**)(&audio_context), &audio_context_size);
    if(ar_element_factory_make_many(handle, audio_context_size, audio_context) != AR_MULTIMEDIA_SUCCESS)
    {
		printf("Make element failed!\r\n");
		ar_multimedia_core_device_close(handle);
		return;
    }
	audio_test_param.play_context = audio_context;

	if(!strcmp(audio_dec, "yes")){
		ar_element_modify_property_value(handle, audio_context->i2s_sink.element, AR_AUDIO_I2S_SET_ID, &i2s_id, sizeof(uint32_t));
		ar_element_modify_property_value(handle, audio_context->i2s_sink.element, AR_AUDIO_I2S_SET_DEVIDE_MODE_ON, &i2s_devide_mode_on, sizeof(uint32_t));
		ar_element_modify_property_value(handle, audio_context->i2s_sink.element, AR_AUDIO_I2S_SET_SAMPLE_RATE, &audio_sample_rate, sizeof(uint32_t));
		ar_element_modify_property_value(handle, audio_context->i2s_sink.element, AR_AUDIO_I2S_SET_CODEC_VOL, &audio_vol, sizeof(uint32_t));
		ar_element_modify_property_value(handle, audio_context->i2s_sink.element, AR_AUDIO_I2S_SET_PCM_CH, &pcm_ch, sizeof(uint32_t));
		ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, audio_context->aac_decoder.element, 0),
									AR_COMMON_META_AUDIO_SAMPLE_RATE_NAME,&audio_sample_rate,sizeof(unsigned int));
		ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, audio_context->aac_decoder2.element, 0),
									AR_COMMON_META_AUDIO_SAMPLE_RATE_NAME,&audio_sample_rate,sizeof(unsigned int));
		ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, audio_context->aac_decoder.element, 0),
									AR_COMMON_META_AUDIO_CHANNEL_NAME,&audio_sample_rate,sizeof(unsigned int));
		ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, audio_context->aac_decoder2.element, 0),
									AR_COMMON_META_AUDIO_CHANNEL_NAME,&audio_sample_rate,sizeof(unsigned int));
        uint32_t auto_start_event = 1;
        ar_element_modify_property_value(handle, audio_context->audio_out2.element, AR_COMMON_META_AUTO_START_EVENT, (void*)&auto_start_event, sizeof(uint32_t));

	    ar_pipeline_add_many(handle, (ar_pipeline_t)audio_context->pipeline.element,
	                audio_context->audio_out.element, \
	                audio_context->audio_out2.element, \
	                audio_context->aac_decoder.element,\
	                audio_context->aac_decoder2.element, \
	                audio_context->i2s_sink.element, \
					NULL);

	    ar_pad_link_by_element(handle, audio_context->audio_out.element, 0, audio_context->aac_decoder.element, 0);
	    ar_pad_link_by_element(handle, audio_context->audio_out2.element, 0, audio_context->aac_decoder2.element, 0);
	    ar_pad_link_by_element(handle, audio_context->aac_decoder.element, 0, audio_context->i2s_sink.element, 0);
	    ar_pad_link_by_element(handle, audio_context->aac_decoder2.element, 0, audio_context->i2s_sink.element, 1);
	}else{
		ar_element_modify_property_value(handle, audio_context->i2s_sink.element, AR_AUDIO_I2S_SET_ID, &i2s_id, sizeof(uint32_t));
		ar_element_modify_property_value(handle, audio_context->i2s_sink.element, AR_AUDIO_I2S_SET_DEVIDE_MODE_ON, &i2s_devide_mode_on, sizeof(uint32_t));
		ar_element_modify_property_value(handle, audio_context->i2s_sink.element, AR_AUDIO_I2S_SET_SAMPLE_RATE, &audio_sample_rate, sizeof(uint32_t));
		ar_element_modify_property_value(handle, audio_context->i2s_sink.element, AR_AUDIO_I2S_SET_CODEC_VOL, &audio_vol, sizeof(uint32_t));
		ar_element_modify_property_value(handle, audio_context->i2s_sink.element, AR_AUDIO_I2S_SET_PCM_CH, &pcm_ch, sizeof(uint32_t));
		uint32_t auto_start_event = 1;
		ar_element_modify_property_value(handle, audio_context->audio_out2.element, AR_COMMON_META_AUTO_START_EVENT, (void*)&auto_start_event, sizeof(uint32_t));
		//printf("set audio auto_start_event = %d\n", auto_start_event);

	    ar_pipeline_add_many(handle, (ar_pipeline_t)audio_context->pipeline.element,
	                audio_context->audio_out.element, \
	                audio_context->audio_out2.element,
	                audio_context->i2s_sink.element, \
	                audio_context->audioplay_middle.element,\
					audio_context->audioplay_middle2.element,
					NULL);
	    //ar_pad_link_by_element(handle, audio_context->audio_out.element, 0, audio_context->i2s_sink.element, 0);

	    ar_pad_link_by_element(handle, audio_context->audio_out.element, 0, audio_context->audioplay_middle.element, 0);
	    ar_pad_link_by_element(handle, audio_context->audio_out2.element, 0, audio_context->audioplay_middle2.element, 0);
	    ar_pad_link_by_element(handle, audio_context->audioplay_middle.element, 0, audio_context->i2s_sink.element, 0);
	    ar_pad_link_by_element(handle, audio_context->audioplay_middle2.element, 0, audio_context->i2s_sink.element, 1);
	}

   // ar_element_set_state(handle, (ar_pipeline_t)audio_context->pipeline.element, AR_ELEMENT_STATE_READY);
	int ret = ar_pipeline_start_stream_nonblocking(handle,(ar_pipeline_t)audio_context->pipeline.element);
	if(ret < 0)
	{
		printf("pipeline start stream blocking failed!\n");
	}
    //ar_multimedia_core_device_close(handle);
    //ar_multimedia_core_device_close(handle2);
}

void record_thread(char* arg)
{
	void *buf;
	uint32_t data_len;
	int fd = -1, index;
	int fd_ai = -1;
	size_t ret;
	int data_size = 0;
	int cnt = 0;
	struct icc_proxy_rpc_to_linux_element_t *buffer_info = NULL;
	char file_name[64];
	thread_arg_p *p_args = (thread_arg_p *)arg;

	fd_ai = icc_proxy_rpc_to_linux_open_dev(p_args->argv[1]);
	if (fd_ai < 0){
		printf("open %s failed!\n", p_args->argv[1]);
        free(p_args);
		return;
	}
	sprintf(file_name,"%s",p_args->argv[2]);
	int fp = open(file_name, O_RDWR|O_CREAT);
	if(!fp){
		printf("open %s fail!!\n", p_args->argv[2]);
        close(fd_ai);
        free(p_args);
		return;
	}
	buffer_info = malloc(sizeof(struct icc_proxy_rpc_to_linux_element_t));
    printf("%s start audio record...\r\n", p_args->argv[1]);

	while(1){
		ret = icc_proxy_rpc_to_linux_acquire_buffer(fd_ai, buffer_info);
		if(ret)
		{
			printf("icc_proxy_rpc_to_linux_acquire_buffer fail!! \n");
            break;
		}

		data_len = buffer_info->mem_info[0].len;
		buf = (void *)buffer_info->mem_info[0].map_addr;
		data_size += data_len;
		if(data_size > atoi(p_args->argv[3]) * 1024){
			printf("%s record get data %d kb over!!\n", p_args->argv[1], atoi(p_args->argv[3]));
			fsync(fp);
			close(fp);
			icc_proxy_rpc_to_linux_release_buffer(fd_ai, buffer_info);
			close(fd_ai);
			break;
		}
		ret = write(fp, buf, data_len);
		ret =  icc_proxy_rpc_to_linux_release_buffer(fd_ai, buffer_info);
		if(ret){
			printf("release buffer fail!!!\n");
			break;
		}
	}
}

static void start_record(char* arg){
	thread_arg_p* arg1 = malloc(sizeof(thread_arg_p));
	thread_arg_p* arg2 = malloc(sizeof(thread_arg_p));
	thread_arg* parg = get_args(arg);
	pthread_t pid_record1;
	pthread_t pid_record2;


	arg1->argc = 4;
	arg1->argv[0] = parg->argv[0];
	arg1->argv[1] = parg->argv[1];
	arg1->argv[2] = parg->argv[4];
	arg1->argv[3] = parg->argv[6];
	arg2->argc = 4;
	arg2->argv[0] = parg->argv[0];
	arg2->argv[1] = parg->argv[2];
	arg2->argv[2] = parg->argv[5];
	arg2->argv[3] = parg->argv[6];

	if(!strcmp(parg->argv[3], "aac") || !strcmp(parg->argv[3], "pcm") ){
		if(pthread_create(&pid_record1, NULL, record_thread,(void *)arg1)){
			printf("create thread 1 failed\n");
			return;
		}
		if(pthread_create(&pid_record2, NULL, record_thread,(void *)arg2)){
			printf("create thread 2 failed\n");
			return;
		}
	}else{
		print_help();
		return;
	}

}

static void start_single_record(char* arg){
	thread_arg_p* arg1 = malloc(sizeof(thread_arg_p));
	thread_arg* parg = get_args(arg);
	pthread_t pid_record1;


	arg1->argc = 4;
	arg1->argv[0] = parg->argv[0];
	arg1->argv[1] = parg->argv[1];
	arg1->argv[2] = parg->argv[3];
	arg1->argv[3] = parg->argv[4];
	printf("%s %s %s %s %s\n", parg->argv[0],parg->argv[1],parg->argv[2],parg->argv[3],parg->argv[4]);
	if(!strcmp(parg->argv[2], "aac") || !strcmp(parg->argv[2], "pcm") ){
		if(pthread_create(&pid_record1, NULL, record_thread,(void *)arg1)){
			printf("create thread 1 failed\n");
			return;
		}
	}else{
		print_help();
		return;
	}

}

void play_thread_aac(char* arg)
{
	int fd_ao = 0;
	FILE * fp = 0;
	char * buf = 0;
	char * file_buffer = 0;
	int file_len = 0;
	int cnt = 0;
	int aac_frame_len = 0;
	char * p_curr;
	thread_arg_p *p_args = (thread_arg_p*)(arg);
	char file_name[64];
	char* dev_name = NULL;
	play_context_t * audio_out_context = NULL;
	ar_mm_handle_t handle = NULL;
	int valid = 1;
	int invalid = 0;

	dev_name = p_args->argv[1];
	fd_ao = open(dev_name, O_RDWR);
	if(fd_ao < 0)
	{
		printf("Open audio_out failed: %s\r\n", strerror(errno));
        free(p_args);
		return -1;
	}
	sprintf(file_name,"%s",p_args->argv[2]);
	if(access(file_name, F_OK) == -1)
	{
		printf("audio file not exist: %s\n",file_name);
		close(fd_ao);
        free(p_args);
		return -1;
	}
	fp = fopen(file_name, "ab+");
	if(!fp)
	{
		printf("open aac file failed: %s\r\n", strerror(errno));
		close(fd_ao);
        free(p_args);
		return -1;
	}
	fseek(fp, 0, SEEK_END);
	file_len = ftell(fp);
	rewind(fp);
	file_buffer = malloc(file_len);
	if(!file_buffer)
	{
		printf("Malloc buffer error!\r\n");
        close(fd_ao);
        free(p_args);
		return -1;
	}
	fread(file_buffer, 1, file_len, fp);
	fclose(fp);
	if(icc_proxy_rpc_init(fd_ao, AUDIO_FRAME_LEN, 1))
	{
		printf("Rpc init fail!!\n");
		free(file_buffer);
		close(fd_ao);
        free(p_args);
		return -1;
	}

    printf("%s start audio playback...\r\n", dev_name);

	audio_out_context = audio_test_param.play_context;
	if(!audio_out_context){
		printf("null pointer!!\n");
		return -1;
	}

	if(!strcmp(dev_name, "/dev/audio_out")){
		handle = audio_test_param.play_handle;
		if(!handle){
			printf("null pointer!!\n");
			return -1;
		}
		ar_element_modify_property_value(handle, audio_out_context->i2s_sink.element, AR_AUDIO_I2S_SINK_LEFT_VALID, &(valid), sizeof(uint32_t));
	}else if(!strcmp(dev_name, "/dev/audio_out2")){
		handle = audio_test_param.play_handle2;
		if(!handle){
			printf("null pointer!!\n");
			return -1;
		}
		ar_element_modify_property_value(handle, audio_out_context->i2s_sink.element, AR_AUDIO_I2S_SINK_RIGHT_VALID, &(valid), sizeof(uint32_t));
	}else{
		printf("dev %s not correct!!\n", dev_name);
		return -1;
	}


	p_curr = file_buffer;
	while(1)
	{
		if(*(unsigned char *)p_curr == 0xff &&
			(*(unsigned char *)(p_curr + 1) == 0xf1 || *(unsigned char *)(p_curr + 1) == 0xf9 || *(unsigned char *)(p_curr + 1) == 0xf0 ) &&
			(*(unsigned char *)(p_curr + 2) == 0x50 || *(unsigned char *)(p_curr + 2) == 0x4c || *(unsigned char *)(p_curr + 2) == 0x6c) &&
			(*(unsigned char *)(p_curr + 3) == 0x80 || *(unsigned char *)(p_curr + 3) == 0x40 ))
		{
			int len_h = *(unsigned char *)(p_curr + 3) & 0x3;
			int len_m = *(unsigned char *)(p_curr + 4);
			int len_l = *(unsigned char *)(p_curr + 5) & 0xe0;

			aac_frame_len = (len_h << 11) + (len_m << 3) + (len_l >> 5);
			//printf("Find aac frame len: %d\r\n", aac_frame_len);

			if(icc_proxy_rpc_acquire_buffer(fd_ao, &buf))
			{
				printf("acquire_buffer fail!!\n");
				close(fd_ao);
				free(p_args);
				break;
			}
			memcpy(buf, p_curr, aac_frame_len);
			icc_proxy_rpc_push_buffer(fd_ao, buf, aac_frame_len);
			p_curr += aac_frame_len;
			usleep(12000);
			cnt++;
		}
		else
		{
			p_curr++;
		}

		if(p_curr >= file_buffer + file_len)
			break;
	}

	printf("%s playback finished, cnt %d frames!\r\n",dev_name, cnt);
	if(!strcmp(dev_name, "/dev/audio_out"))
		ar_element_modify_property_value(handle, audio_out_context->i2s_sink.element, AR_AUDIO_I2S_SINK_LEFT_VALID, &(invalid), sizeof(uint32_t));
	else if(!strcmp(dev_name, "/dev/audio_out2"))
		ar_element_modify_property_value(handle, audio_out_context->i2s_sink.element, AR_AUDIO_I2S_SINK_RIGHT_VALID, &(invalid), sizeof(uint32_t));
	icc_proxy_rpc_linux_exit(fd_ao);
	close(fd_ao);
    free(p_args);
}

void play_thread_pcm(char* arg)
{
	int fd_ao = 0;
	FILE * fp = 0;
	char * buf = 0;
	char * file_buffer = 0;
	int file_len = 0;
	int cnt = 0;
	int aac_frame_len = 0;
	char * p_curr;
	thread_arg_p *p_args = (thread_arg_p*)(arg);
	char file_name[64];
    int len, offset;
	char* dev_name = NULL;
	play_context_t * audio_out_context = NULL;
	ar_mm_handle_t handle = NULL;
	int valid = 1;
	int invalid = 0;

	dev_name = p_args->argv[1];
	fd_ao = open(dev_name, O_RDWR);
	if(fd_ao < 0)
	{
		printf("Open audio_out failed: %s\r\n", strerror(errno));
        free(p_args);
		return -1;
	}
	sprintf(file_name,"%s",p_args->argv[2]);
	if(access(file_name, F_OK) == -1)
	{
		printf("audio file not exist: %s\n",file_name);
		close(fd_ao);
        free(p_args);
		return -1;
	}
	fp = fopen(file_name, "ab+");
	if(!fp)
	{
		printf("open aac file failed: %s\r\n", strerror(errno));
		close(fd_ao);
        free(p_args);
		return -1;
	}
	fseek(fp, 0, SEEK_END);
	file_len = ftell(fp);
	rewind(fp);
	file_buffer = malloc(file_len);
	if(!file_buffer)
	{
		printf("Malloc buffer error!\r\n");
        close(fd_ao);
        free(p_args);
		return -1;
	}
	fread(file_buffer, 1, file_len, fp);
	fclose(fp);

	if(icc_proxy_rpc_init(fd_ao, AUDIO_FRAME_LEN, 1))
	{
		printf("Rpc init fail!!\n");
		free(file_buffer);
		close(fd_ao);
        free(p_args);
		return -1;
	}

	audio_out_context = audio_test_param.play_context;
	if(!audio_out_context){
		printf("null pointer!! line:%d\n", __LINE__);
		return -1;
	}

	if(!strcmp(dev_name, "/dev/audio_out")){
		handle = audio_test_param.play_handle;
		if(!handle){
			printf("null pointer!! line:%d\n", __LINE__);
			return -1;
		}
		ar_element_modify_property_value(handle, audio_out_context->i2s_sink.element, AR_AUDIO_I2S_SINK_LEFT_VALID, &(valid), sizeof(uint32_t));
	}else if(!strcmp(dev_name, "/dev/audio_out2")){
		handle = audio_test_param.play_handle2;
		if(!handle){
			printf("null pointer!! line:%d\n", __LINE__);
			return -1;
		}
		ar_element_modify_property_value(handle, audio_out_context->i2s_sink.element, AR_AUDIO_I2S_SINK_RIGHT_VALID, &(valid), sizeof(uint32_t));
	}else{
		printf("dev %s not correct!!\n", dev_name);
		return -1;
	}
	len = 0;
    offset = 0;
    printf("%s start audio playback...\r\n", dev_name);
	while(1)
	{
		if(icc_proxy_rpc_acquire_buffer(fd_ao, &buf))
		{
			printf("acquire_buffer fail!!\n");
			close(fd_ao);
			free(file_buffer);
			return -1;
		}

        len = (file_len - offset - AUDIO_FRAME_LEN) > 0 ? AUDIO_FRAME_LEN : (file_len - offset);		printf("####################len %d\n", len);
		memcpy(buf, file_buffer + offset, len);
		icc_proxy_rpc_push_buffer(fd_ao, buf, len);

        offset += len;
        if(offset >= file_len)
        {
            break;
        }
		usleep(10*1000);
	}

	printf("%s playback finished, play %d kb!\r\n",dev_name, offset/1024);
	if(!strcmp(dev_name, "/dev/audio_out"))
		ar_element_modify_property_value(handle, audio_out_context->i2s_sink.element, AR_AUDIO_I2S_SINK_LEFT_VALID, &(invalid), sizeof(uint32_t));
	else if(!strcmp(dev_name, "/dev/audio_out2"))
		ar_element_modify_property_value(handle, audio_out_context->i2s_sink.element, AR_AUDIO_I2S_SINK_RIGHT_VALID, &(invalid), sizeof(uint32_t));
	icc_proxy_rpc_linux_exit(fd_ao);
	close(fd_ao);
    free(p_args);
	return 0;
}

int start_play(char* arg)
{
	thread_arg_p* arg1 = malloc(sizeof(thread_arg_p));
	thread_arg_p* arg2 = malloc(sizeof(thread_arg_p));
	thread_arg* parg = get_args(arg);
	pthread_t pid_record1;
	pthread_t pid_record2;


	arg1->argc = 3;
	arg1->argv[0] = parg->argv[0];
	arg1->argv[1] = parg->argv[1];
	arg1->argv[2] = parg->argv[4];
	arg2->argc = 3;
	arg2->argv[0] = parg->argv[0];
	arg2->argv[1] = parg->argv[2];
	arg2->argv[2] = parg->argv[5];

	if(!strcmp(parg->argv[3], "aac")){
		if(pthread_create(&pid_record1, NULL, play_thread_aac,(void *)arg1)){
			printf("create thread 1 failed\n");
			return;
		}
		if(pthread_create(&pid_record2, NULL, play_thread_aac,(void *)arg2)){
			printf("create thread 2 failed\n");
			return;
		}
	}else if(!strcmp(parg->argv[3], "pcm")){
		if(pthread_create(&pid_record1, NULL, play_thread_pcm,(void *)arg1)){
			printf("create thread 1 failed\n");
			return;
		}
		if(pthread_create(&pid_record2, NULL, play_thread_pcm,(void *)arg2)){
			printf("create thread 2 failed\n");
			return;
		}
	}else{
		print_help();
		return;
	}

}


int start_audio_pipeline(char* arg)
{
	char * dev_name = NULL;
	record_context_t * audio_in_context = NULL;
	play_context_t * audio_out_context = NULL;
	ar_mm_handle_t handle = NULL;
	thread_arg *parg = get_args(arg);
	dev_name = parg->argv[1];

	if(strcmp(dev_name,"/dev/pipeline_audio_in")==0)
	{
		printf("start %s\n",dev_name);
		audio_in_context = audio_test_param.record_context;
		handle = audio_test_param.record_handle;
		if(ar_pipeline_start_stream_nonblocking(handle,audio_in_context->pipeline.element) < 0){
			printf("%s start pipeline failed\n", dev_name);
			return;
		}
	}else if(strcmp(dev_name,"/dev/pipeline_audio_out")==0)
	{
		printf("start %s\n",dev_name);
		audio_out_context = audio_test_param.play_context;
		handle = audio_test_param.play_handle;
		if(ar_pipeline_start_stream_nonblocking(handle,audio_out_context->pipeline.element) < 0){
			printf("%s start pipeline failed\n", dev_name);
			return;
		}
	}else{
		print_help();
		return;
	}

}


int stop_audio_pipeline(char* arg)
{
	char * dev_name = NULL;
	record_context_t * audio_in_context = NULL;
	play_context_t * audio_out_context = NULL;
	ar_mm_handle_t handle = NULL;
	thread_arg *parg = get_args(arg);
	dev_name = parg->argv[1];

	printf("%p %p\n", audio_test_param.record_context, audio_test_param.record_handle);
	if(strcmp(dev_name,"/dev/pipeline_audio_in")==0)
	{
		printf("stop %s\n",dev_name);
		audio_in_context = audio_test_param.record_context;
		handle = audio_test_param.record_handle;
		if(ar_pipeline_terminal_stream(handle,audio_in_context->pipeline.element) < 0){
			printf("%s stop pipeline failed\n", dev_name);
			return;
		}
	}else if(strcmp(dev_name,"/dev/pipeline_audio_out")==0)
	{
		printf("stop %s\n",dev_name);
		audio_out_context = audio_test_param.play_context;
		handle = audio_test_param.play_handle;
		if(ar_pipeline_terminal_stream(handle,audio_out_context->pipeline.element) < 0){
			printf("%s stop pipeline failed\n", dev_name);
			return;
		}
	}else{
		print_help();
		return;
	}
}


int change_audio_sample_rate(char* arg)
{
	thread_arg *p_args = get_args(arg);
	char * dev_name = NULL;
	char * format = NULL;
	unsigned int new_rate;
	record_context_t * audio_in_context = NULL;
	play_context_t * audio_out_context = NULL;
	ar_mm_handle_t handle = NULL;

	dev_name = p_args->argv[1];
	format = p_args->argv[2];
	new_rate = atoi(p_args->argv[3]);

	if(strcmp(dev_name, "/dev/pipeline_audio_in") && strcmp(dev_name, "/dev/pipeline_audio_out")){
		printf("pipeline %s not support!\n", dev_name);
		return -1;
	}
	if(strcmp(format, "aac") && strcmp(format, "pcm")){
		printf("format %s not support!\n", format);
		return -1;
	}
	if(new_rate != 8000 && new_rate != 44100 && new_rate != 48000){
		printf("sample rate %dHz not support!\n", new_rate);
		return -1;
	}

	if(strcmp(dev_name,"/dev/pipeline_audio_in")==0)
	{
		audio_in_context = audio_test_param.record_context;
		if(!audio_in_context){
			printf("null pointer!!\n");
			return -1;
		}
		handle = audio_test_param.record_handle;
		if(!handle){
			printf("null pointer!!\n");
			return -1;
		}
		ar_element_modify_property_value(handle, audio_in_context->i2s_src.element, AR_AUDIO_I2S_SET_SAMPLE_RATE, &new_rate, sizeof(uint32_t));
		if(!strcmp(format, "aac")){
			ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, audio_in_context->i2s_src.element, 0),
										AR_COMMON_META_AUDIO_SAMPLE_RATE_NAME,&new_rate,sizeof(unsigned int));
			ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, audio_in_context->i2s_src.element, 1),
										AR_COMMON_META_AUDIO_SAMPLE_RATE_NAME,&new_rate,sizeof(unsigned int));
		}
	}else if(strcmp(dev_name,"/dev/pipeline_audio_out")==0){
		audio_out_context = audio_test_param.play_context;
		if(!audio_out_context){
			printf("null pointer!!\n");
			return -1;
		}
		handle = audio_test_param.play_handle;
		if(!handle){
			printf("null pointer!!\n");
			return -1;
		}
		ar_element_modify_property_value(handle, audio_out_context->i2s_sink.element, AR_AUDIO_I2S_SET_SAMPLE_RATE, &new_rate, sizeof(uint32_t));
		if(!strcmp(format, "aac")){
			ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, audio_out_context->aac_decoder.element, 0),
										AR_COMMON_META_AUDIO_SAMPLE_RATE_NAME,&new_rate,sizeof(unsigned int));
			ar_pad_modify_meta_value(handle, ar_element_get_src_pad_by_idx(handle, audio_out_context->aac_decoder2.element, 0),
										AR_COMMON_META_AUDIO_SAMPLE_RATE_NAME,&new_rate,sizeof(unsigned int));
		}
	}
	printf("%s has change sample rate to %dHz %s\n", dev_name, new_rate, format);
}

int change_audio_volume(char* arg)
{
	thread_arg *p_args = get_args(arg);
	char * dev_name = NULL;
	char * format = NULL;
	unsigned int new_rate;
	record_context_t * audio_in_context = NULL;
	play_context_t * audio_out_context = NULL;
	ar_mm_handle_t handle = NULL;
	int new_vol;

	dev_name = p_args->argv[1];
	new_vol = atoi(p_args->argv[2]);
	if(strcmp(dev_name, "/dev/pipeline_audio_in") && strcmp(dev_name, "/dev/pipeline_audio_out")){
		printf("pipeline %s not support!\n", dev_name);
		return -1;
	}
	if(new_vol > 255 || new_vol < 0){
		printf("volume %d out limit!\n", new_vol);
		return -1;
	}

	if(strcmp(dev_name,"/dev/pipeline_audio_in")==0)
	{
		audio_in_context = audio_test_param.record_context;
		if(!audio_in_context){
			printf("null pointer!!\n");
			return -1;
		}
		handle = audio_test_param.record_handle;
		if(!handle){
			printf("null pointer!!\n");
			return -1;
		}
		ar_element_modify_property_value(handle, audio_in_context->i2s_src.element, AR_AUDIO_I2S_SET_CODEC_VOL, &new_vol, sizeof(uint32_t));
	}else if(strcmp(dev_name,"/dev/pipeline_audio_out")==0){
		audio_out_context = audio_test_param.play_context;
		if(!audio_out_context){
			printf("null pointer!!\n");
			return -1;
		}
		handle = audio_test_param.play_handle;
		if(!handle){
			printf("null pointer!!\n");
			return -1;
		}
		ar_element_modify_property_value(handle, audio_out_context->i2s_sink.element, AR_AUDIO_I2S_SET_CODEC_VOL, &new_vol, sizeof(uint32_t));
	}
	printf("%s has change volume to %d\n", dev_name, new_vol);
}

cmdStruct_t audio_test_lists[AUDIO_CASE_NUM]=
{
	{"cmd_ctrl_none",NULL},
	{"create_record_pipeline",create_record_pipeline},
	{"create_single_record_pipeline",create_single_record_pipeline},
	{"create_play_pipeline",create_play_pipeline},
	{"start_record",start_record},
	{"start_single_record",start_single_record},
	{"start_play",start_play},
	{"start_audio_pipeline",start_audio_pipeline},
	{"stop_audio_pipeline",stop_audio_pipeline},
	{"change_audio_sample_rate",change_audio_sample_rate},
	{"change_audio_volume",change_audio_volume},
	{"stop_audio_pipeline",stop_audio_pipeline},
	{"help",NULL},
};

static int find_cmd_list_index_by_name(char* arg)
{
	int index = AUDIO_CASE_MAX;
	int tmp = NULL;
	for(int i=0; i<AUDIO_CASE_NUM; i++)
	{
		tmp = NULL;
		if(audio_test_lists[i].name)
			tmp = strstr(arg,audio_test_lists[i].name);
		if(tmp!=NULL)
		{
			return i;
		}
	}
	return index;
}

void func_cmdline_ctrl()
{
	size_t size =0;
	ssize_t read;
	char *tmp;
	char *buffer = NULL;
	int cmd_idx = AUDIO_CASE_MAX;

	while(1)
	{
		printf("=>");
		read = getline(&buffer,&size,stdin);
		if(read == -1)
			break;
		buffer[read-1] = '\0';
		cmd_idx = find_cmd_list_index_by_name(buffer);
		if(cmd_idx<AUDIO_CASE_MAX)
		{
			if(!strcmp(audio_test_lists[cmd_idx].name, "help"))
			{
				print_help();
				continue ;
			}
			if(strstr(buffer,"-h")!=NULL)
			{
				print_help();
				continue ;
			}
			audio_test_lists[cmd_idx].function(buffer);
		}
	}

	if(buffer)
	{
		free(buffer);
	}
}


int main ()
{

	pthread_t pid_ctrl;
	pthread_create(&pid_ctrl, NULL, func_cmdline_ctrl,NULL);
	pthread_join(pid_ctrl, NULL);
	while(1)
		sleep(1);

	return 0;
}



