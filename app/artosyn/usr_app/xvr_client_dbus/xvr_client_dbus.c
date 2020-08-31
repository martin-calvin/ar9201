#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <stdbool.h>

#include "ar_log.h"
#include "xvr_client_dbus.h"
#include "xvr_gdbus_generated.h"

#define XVR_GDBUS_BUS_NAME 				"com.artosyn.xvr"
#define XVR_GDBUS_OBJECT_PATH 	  		"/com/artosyn/xvr"
#define XVR_GDBUS_INTERFACE 			"com.artosyn.xvr.interface"

typedef struct {
	xvr_camera_state_changed_cb camera_state_change_cb;
	void* camera_state_change_user_data;
    ComArtosynXvrInterface * proxy;
} ar_xvr_gdbus_client_t;


static uint32_t ar_xvr_retreive_variant_to_struct(GVariant * variant, void * structure, uint32_t size)
{
    GVariantIter *iter = NULL;
    gint ivalue = 0;
    uint32_t icount = 0;

    if (!variant || !structure || size == 0){
		log_err("input err");
        return 0;
    }
    g_variant_get(variant, "a(i)", &iter);
    while (g_variant_iter_loop (iter, "(i)", &ivalue) && (icount < size))
    {
        ((uint32_t *)structure)[icount++] = (uint32_t)ivalue;
    }
    g_variant_iter_free (iter);
    return icount;
}

static ar_xvr_gdbus_client_t* ar_xvr_get_gdbus_client() 
{
    static ar_xvr_gdbus_client_t* gdbus_client = NULL;
    GDBusConnection *connection = NULL;
    GError *error = NULL;

    if(gdbus_client)
        return gdbus_client;
    gdbus_client = malloc(sizeof(ar_xvr_gdbus_client_t));
    if(!gdbus_client) {
        log_err("malloc gdbus client failed.");
        return NULL;
    }
    memset(gdbus_client, 0x0, sizeof(ar_xvr_gdbus_client_t));
    connection = g_bus_get_sync(G_BUS_TYPE_SESSION, NULL, &error);
	//printf("==enter ar_xvr_get_gdbus_client connection %d ===\n",connection);
    if(!connection) {
        log_err("Create dbus proxy failed, error msg is: %s\n", (error)?error->message:"NULL");
        goto failed;
    }
    gdbus_client->proxy = com_artosyn_xvr_interface_proxy_new_sync(connection,
                                                            G_DBUS_PROXY_FLAGS_NONE,
                                                            XVR_GDBUS_BUS_NAME, /* bus name */
                                                            XVR_GDBUS_OBJECT_PATH, /* control object_path */
                                                            NULL,
                                                            &error);
    if(!gdbus_client->proxy) {
        log_err("Create dbus proxy failed, error msg is: %s\n", (error)?error->message:"NULL");
        goto failed;
    }
    if(error)
        g_error_free(error);
    return gdbus_client;
failed:
    if(error)
        g_error_free(error);
    if(gdbus_client) {
        free(gdbus_client);
        gdbus_client = NULL;
    }
    return NULL;
}


int ar_xvr_create_pipeline_func(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;
	gdbus_client =  ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to create_pipeline_func, client is NULL.");
        return AR_FAILURE;
    }
	printf("===xvr client create pipeline func:arg %s ====\n",arg);
	
    method_ret = com_artosyn_xvr_interface_call_create_pipeline_func_sync(gdbus_client->proxy, arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("xvr_create_pipeline_func failed, msg is:%s\n", (error)?error->message:"NULL");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}

int ar_xvr_start_pipeline_func(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;
    gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to start pipeline function, client is NULL.");
        return AR_FAILURE;
    }
    method_ret = com_artosyn_xvr_interface_call_start_pipeline_func_sync(gdbus_client->proxy, arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("xvr_start_pipeline_func failed, msg is:%s\n", (error)?error->message:"NULL");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}


int ar_xvr_stop_pipeline_func(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;

	char* p_arg=arg;
	//p_arg = arg;
	printf("cmdlist %s\n",p_arg);
	printf("xvr_stop_pipeline_func......\n");

    gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to stop pipeline function, client is NULL.");
        return AR_FAILURE;
    }
	printf("com_artosyn_xvr_interface_call_stop_pipeline_func_sync......\n");
    method_ret = com_artosyn_xvr_interface_call_stop_pipeline_func_sync(gdbus_client->proxy, p_arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("xvr_stop_pipeline_func failed, msg is:%s\n", (error)?error->message:"NULL");
		printf("com_artosyn_xvr_interface_call_stop_pipeline_func_sync failed......\n");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}


int ar_xvr_play_video_record_func(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;
	
    gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to play_video_record_func, client is NULL.");
        return AR_FAILURE;
    }
    method_ret = com_artosyn_xvr_interface_call_play_video_record_func_sync(gdbus_client->proxy, arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("play_video_record_func failed, msg is:%s\n", (error)?error->message:"NULL");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}


int ar_xvr_start_video_record_func(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;
	
    gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to start_video_record_func, client is NULL.");
        return AR_FAILURE;
    }
    method_ret = com_artosyn_xvr_interface_call_start_video_record_func_sync(gdbus_client->proxy, arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("start_video_record_func failed, msg is:%s\n", (error)?error->message:"NULL");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}


int ar_xvr_stop_video_record_func(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;
	
    gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to stop_video_record_func, client is NULL.");
        return AR_FAILURE;
    }
    method_ret = com_artosyn_xvr_interface_call_stop_video_record_func_sync(gdbus_client->proxy, arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("stop_video_record_func failed, msg is:%s\n", (error)?error->message:"NULL");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}

int ar_xvr_change_stream_param_func(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;
	
    gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to change_stream_param_func, client is NULL.");
        return AR_FAILURE;
    }
    method_ret = com_artosyn_xvr_interface_call_change_stream_param_func_sync(gdbus_client->proxy, arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("change_stream_param_func failed, msg is:%s\n", (error)?error->message:"NULL");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}

int ar_xvr_change_audio_in_param_func(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;
	
    gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to change_stream_param_func, client is NULL.");
        return AR_FAILURE;
    }
    method_ret = com_artosyn_xvr_interface_call_change_audio_in_param_func_sync(gdbus_client->proxy, arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("change_audio_in_param_func failed, msg is:%s\n", (error)?error->message:"NULL");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}


int ar_xvr_change_encode_format_func(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;
	
    gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to change_encode_format_func, client is NULL.");
        return AR_FAILURE;
    }
    method_ret = com_artosyn_xvr_interface_call_change_encode_format_func_sync(gdbus_client->proxy, arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("change_encode_format_func failed, msg is:%s\n", (error)?error->message:"NULL");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}


int ar_xvr_switch_channel_display_func(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;
	
    gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to switch_channel_display_func, client is NULL.");
        return AR_FAILURE;
    }
    method_ret = com_artosyn_xvr_interface_call_switch_channel_display_func_sync(gdbus_client->proxy, arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("switch_channel_display_func failed, msg is:%s\n", (error)?error->message:"NULL");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}



int ar_xvr_switch_anyway_display_func(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;

    gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to switch_channel_display_func, client is NULL.");
        return AR_FAILURE;
    }
    method_ret = com_artosyn_xvr_interface_call_switch_anyway_display_func_sync(gdbus_client->proxy, arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("switch_anyway_display_func failed, msg is:%s\n", (error)?error->message:"NULL");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}


int ar_xvr_change_osd_mode_func(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;
	
    gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to change_osd_mode_func, client is NULL.");
        return AR_FAILURE;
    }
    method_ret = com_artosyn_xvr_interface_call_change_osd_mode_func_sync(gdbus_client->proxy, arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("change_osd_mode_func failed, msg is:%s\n", (error)?error->message:"NULL");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}


int ar_xvr_start_audio_record_func(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;
	
    gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to start_audio_record_func, client is NULL.");
        return AR_FAILURE;
    }
    method_ret = com_artosyn_xvr_interface_call_start_audio_record_func_sync(gdbus_client->proxy, arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("start_audio_record_func failed, msg is:%s\n", (error)?error->message:"NULL");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}


int ar_xvr_stop_audio_record_func(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;
	
    gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to stop_audio_record_func, client is NULL.");
        return AR_FAILURE;
    }
    method_ret = com_artosyn_xvr_interface_call_stop_audio_record_func_sync(gdbus_client->proxy, arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("stop_audio_record_func failed, msg is:%s\n", (error)?error->message:"NULL");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}

int ar_xvr_play_local_audio_func(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;
	
    gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to play_local_audio_func, client is NULL.");
        return AR_FAILURE;
    }
    method_ret = com_artosyn_xvr_interface_call_play_local_audio_func_sync(gdbus_client->proxy, arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("play_local_audio_func failed, msg is:%s\n", (error)?error->message:"NULL");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}

int ar_xvr_save_yuv_func_sync(char* arg)
{
    int ret = AR_SUCCESS;
    bool method_ret = AR_FAILURE;
    GError* error = NULL;
	gint out_ret = AR_SUCCESS;
    ar_xvr_gdbus_client_t* gdbus_client = NULL;
	
    gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) {
        log_err("failed to save_yuv_func_sync, client is NULL.");
        return AR_FAILURE;
    }
    method_ret = com_artosyn_xvr_interface_call_save_yuv_func_sync(gdbus_client->proxy, arg, &out_ret, NULL, &error);
    if (!method_ret) {
        log_err("save_yuv_func_sync failed, msg is:%s\n", (error)?error->message:"NULL");
        ret = AR_FAILURE;
        goto end;
    }
end:
  if (error)
    g_error_free(error);
  return ret;
}




static void handle_camera_state_changed(ComArtosynXvrInterface *object,
                                                       GVariant *arg_status)
{
	
	printf("=====enter handle_camera_state_changed=====\r\n");
    ar_xvr_camera_status_t info = {0};
    ar_xvr_gdbus_client_t* gdbus_client = ar_xvr_get_gdbus_client();
    if(!gdbus_client || !gdbus_client->camera_state_change_cb)
        return;
    ar_xvr_retreive_variant_to_struct(arg_status, (void*)&info, sizeof(ar_xvr_camera_status_t)/sizeof(uint32_t));
	printf("dbus client get camera state: cam_id %d, cam_state %d\n",info.cam_id,info.cam_state);
	gdbus_client->camera_state_change_cb(&info, gdbus_client->camera_state_change_user_data);
	
	printf("=====enter handle_camera_state_changed=====\r\n");
    return;
}
int32_t ar_xvr_register_camera_state_change_handler(xvr_camera_state_changed_cb cb, void* user_data)
{
	printf("=====enter ar_xvr_register_camera_state_change_handler=====\r\n");
	gulong connectHandler;
    ar_xvr_gdbus_client_t* gdbus_client = ar_xvr_get_gdbus_client();
    if((!gdbus_client) || (!gdbus_client->proxy)) 
	{
        log_err("failed to register, client is NULL.");
        return AR_FAILURE;
    }
    gdbus_client->camera_state_change_cb        = cb;
    gdbus_client->camera_state_change_user_data = user_data;
    /* register signal */
    connectHandler = g_signal_connect(gdbus_client->proxy,
                   "camera_state_changed",
                   G_CALLBACK(handle_camera_state_changed),
                   user_data);
	printf("gdbus_client->proxy %d,connectHadler %ld\n",gdbus_client->proxy,connectHandler);

	printf("=====exit ar_xvr_register_camera_state_change_handler=====\r\n");
    return AR_SUCCESS;
}






