#ifndef __PIPELINE_SERVICE_H__
#define __PIPELINE_SERVICE_H__

#include "ar_video_stream.h"
#include "ar_pipeline_ctrl.h"
#include "ar_system.h"
#include "ar_meta_define.h"
#include "ar_multimedia_base.h"

#include "uvc_service_sync.h"

int find_pra_index_by_name(char *name,int argc, char *argv[]);
void ar_uvc_get_context(void** context, uint32_t* context_size, uvc_server_t *server_l);
void ar_uvc_init(uvc_server_t *server_l, ar_mm_handle_t handle,int argc, char *argv[]);
void ar_uvc_deinit(uvc_server_t     *server_l, ar_mm_handle_t handle);
int uvc_pipeline_set_format(uvc_server_t *server_l, unsigned int width, unsigned int height, unsigned int fps, unsigned int fcc);
int uvc_pipeline_set_stop(uvc_server_t *server_l);
int uvc_pipeline_set_start(uvc_server_t *server_l);

#endif
