#ifndef _XVR_CLIENT_DBUS_H_
#define _XVR_CLIENT_DBUS_H_

#ifdef __cplusplus
extern "C" {
#endif


typedef struct{
   int cam_id;
   int cam_state;
}ar_xvr_camera_status_t;


#ifndef AR_FAILURE
#define AR_FAILURE  -1
#endif

#ifndef AR_SUCCESS
#define AR_SUCCESS  0
#endif

typedef void (*xvr_camera_state_changed_cb)(ar_xvr_camera_status_t* state,void* user_data);
int32_t ar_xvr_register_camera_state_change_handler(xvr_camera_state_changed_cb cb, void* user_data);


int ar_xvr_create_pipeline_func(char* arg);
int ar_xvr_start_pipeline_func(char* arg);
int ar_xvr_stop_pipeline_func(char* arg);
int ar_xvr_play_video_record_func(char* arg);
int ar_xvr_start_video_record_func(char* arg);
int ar_xvr_stop_video_record_func(char* arg);
int ar_xvr_change_stream_param_func(char* arg);
int ar_xvr_change_audio_in_param_func(char* arg);
int ar_xvr_change_encode_format_func(char* arg);
int ar_xvr_change_osd_mode_func(char* arg);
int ar_xvr_start_audio_record_func(char* arg);
int ar_xvr_stop_audio_record_func(char* arg);
int ar_xvr_play_local_audio_func(char* arg);
int ar_xvr_save_yuv_func_sync(char* arg);
int ar_xvr_switch_channel_display_func(char* arg);
int ar_xvr_switch_anyway_display_func(char* arg);

#ifdef __cplusplus
}
#endif


#endif
