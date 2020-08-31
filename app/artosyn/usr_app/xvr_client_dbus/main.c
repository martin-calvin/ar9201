#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <errno.h>
#include <gio/gio.h>
#include "xvr_client_dbus.h"
#include "xvr_gdbus_generated.h"
#include "xvr_client_cmdline.h"

static void ar_xvr_camera_state_cb(ar_xvr_camera_status_t* info,  void* user_data)
{
	printf("xvr_camera_state: cam_id [0 7],cam_state:0 plugin, 1 plugout\n");
	printf("get camera state info: cam_id %d, get camera state: %d\n", info->cam_id,info->cam_state);	
	return;
}

int main(int argc, char *argv[])
{
	pthread_t thread_ar_get_camera_status;
	pthread_t thread_xvr_cmdline;
	int ret = AR_SUCCESS;
	
	GMainLoop* main_loop = g_main_loop_new(NULL, FALSE);	

	/* get camera state event*/
	ar_xvr_register_camera_state_change_handler(ar_xvr_camera_state_cb,NULL);
	
	pthread_create(&thread_xvr_cmdline,NULL,func_cmdline_ctrl,NULL);
	
	g_main_loop_run(main_loop);


	while(1);

	return 0;
}





