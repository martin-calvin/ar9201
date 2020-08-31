#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#include "ar_meta_define.h"
#include "ar_multimedia_base.h"
#include "icc_proxy_rpc_def.h"
#include "icc_proxy_rpc_to_linux.c"

typedef struct {
    ar_facotry_element_obj_t pipeline;
    ar_facotry_element_obj_t audio_in;
	ar_facotry_element_obj_t audio_in2;
	ar_facotry_element_obj_t aac_encoder;
	ar_facotry_element_obj_t aac_encoder2;
	ar_facotry_element_obj_t i2s_src;
} record_context_t;

typedef struct {
    ar_facotry_element_obj_t pipeline;
    ar_facotry_element_obj_t audio_out;
	ar_facotry_element_obj_t audio_out2;
	ar_facotry_element_obj_t aac_decoder;
	ar_facotry_element_obj_t aac_decoder2;
	ar_facotry_element_obj_t i2s_sink;
	ar_facotry_element_obj_t audioplay_middle;
	ar_facotry_element_obj_t audioplay_middle2;
} play_context_t;

typedef struct{
	int argc;
	char argv[16][128];
}thread_arg;

typedef struct{
	int argc;
	char* argv[64];
}thread_arg_p;

typedef struct{
	ar_mm_handle_t record_handle;
	ar_mm_handle_t play_handle;
	ar_mm_handle_t play_handle2;
	record_context_t* record_context;
	play_context_t* play_context;
}ctl_param;

typedef struct
{
	const char* name;
	void(*function)();

}cmdStruct_t;

#define AUDIO_FRAME_LEN 2*1024
#define AUDIO_CASE_NUM 16
#define AUDIO_CASE_MAX 100
#define CONFIG_SYS_PROMPT          "=>"

