#ifndef __UVC_FUNCTION_H__
#define __UVC_FUNCTION_H__

#include "uvc_service_sync.h"


void uvc_events_init(uvc_server_t *server_l, struct uvc_device *dev);
int uvc_video_init(uvc_server_t *server_l, struct uvc_device *dev __attribute__((__unused__)));
void uvc_events_process(uvc_server_t *server_l, struct uvc_device *dev);
int uvc_video_process(uvc_server_t *server_l, struct uvc_device *dev);
int uvc_video_send(uvc_server_t *server_l, struct uvc_device *dev, void * data, unsigned int len, fd_set wfds, struct timeval tv);
int uvc_video_set_format(uvc_server_t *server_l, struct uvc_device *dev);

#endif
