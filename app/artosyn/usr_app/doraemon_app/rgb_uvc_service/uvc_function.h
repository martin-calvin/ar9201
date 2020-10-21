#ifndef __UVC_FUNCTION_H__
#define __UVC_FUNCTION_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

void uvc_events_init(struct uvc_device *dev);
int uvc_video_init(struct uvc_device *dev __attribute__((__unused__)));
void uvc_events_process(struct uvc_device *dev);
int uvc_video_process(struct uvc_device *dev);
int uvc_video_send(struct uvc_device *dev, void * data, unsigned int len, unsigned int pts, fd_set wfds, struct timeval tv);
int uvc_video_set_format(struct uvc_device *dev);
void uvc_set_pts_bias(struct uvc_device *dev);
int ob_rgb_stop_stream(void);
int ob_rgb_stream_switch(unsigned int fcc, unsigned int w, unsigned int h, unsigned int fps);
int ob_rgb_get_currrent_stream_param(void *pstParam); //ob_rgb_stream_param


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif
