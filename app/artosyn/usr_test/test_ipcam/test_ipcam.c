#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "ar_ipcam_client.h"
#include <gio/gio.h>

static void test_ipcam_err_cb(int err_code, void* user_data)
{
    printf("%s error code %d.\n",__FUNCTION__,err_code);
}

int main(int argc, char *argv[])
{
    int32_t ret = 0;
    GMainLoop* main_loop = g_main_loop_new(NULL, FALSE);
    ret = ar_ipcam_start_stream();
    if(ret != 0) {
        printf("ipcam start stream error");
    }
    ar_ipcam_register_err_handler(test_ipcam_err_cb, NULL);
    while(1) {
        sleep(5);
        ar_ipcam_set_codec_type(AR_IPCAM_AVC);
        sleep(5);
        ar_ipcam_set_resolution(0, 1280, 720);
        sleep(5);
        ar_ipcam_set_resolution(1, 640, 480);
        sleep(1);
        ar_ipcam_set_bitrate(0, 5120, 5120);
        sleep(1);
        ar_ipcam_set_codec_type(AR_IPCAM_HEVC);
        ar_ipcam_set_bitrate(1, 4096, 4096);
  }
    g_main_loop_run(main_loop);
    return 0;
}
