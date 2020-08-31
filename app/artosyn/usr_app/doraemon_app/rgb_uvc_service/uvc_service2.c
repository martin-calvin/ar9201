#define _GNU_SOURCE
#define ENABALE_ALL_LOG
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <sched.h>
#include <linux/usb/ch9.h>
#include <linux/usb/video.h>
#include <linux/videodev2.h>
#include <linux/usb/uvc.h>
#include <pthread.h>

#include "ar_pipeline_ctrl.h"
#include "ar_system.h"

#include "ar_log.h"
#include "pipeline_ctl.h"
#include "ar_lancher.h"

#include "uvc_service2.h"
#include "pipeline_service.h"
#include "uvc_configfs.h"
#include "uvc_function.h"
#include "logutil.h"
#include "basic_typedef.h"
#include "orbbec_gadget_types.h"


/* 格式顺序: H265 H264 Mjpeg YUYV */
struct uvc_format_info *uvc_formats = NULL; //通过 getConfigfsFormat 获取的数据格式支持列表
int uvc_formats_num = 0;
int g_rgb_crop_flag = false; //rgb裁剪标志(rw)

extern server_api_ops_t api_ops;

/*****************************************************************************
*   Prototype    : ob_rgb_get_res_mode
*   Description  : get resolution mode by width and height
*   Input        : unsigned int w  
*                  unsigned int h  
*   Output       : None
*   Return Value : static EM_RES_MODE
*****************************************************************************/
static EM_RES_MODE ob_rgb_get_res_mode(unsigned int w, unsigned int h)
{
    if (w > h)
    {         
        if (h*4 == w*3)
            return RES_MODE_4_3;
        else
            return RES_MODE_16_9;  
    }
    else
    {
        if (w*4 == h*3)
            return RES_MODE_4_3;
        else
            return RES_MODE_16_9;
    }   
}


/*****************************************************************************
*   Prototype    : get_uvc_server
*   Description  : get rgb uvc service, just for rgb only
*   Input        : None
*   Output       : None
*   Return Value : uvc_server_t *
*****************************************************************************/
uvc_server_t *get_uvc_server()
{
    static uvc_server_t *p_uvc_server = NULL;
    if(!p_uvc_server)
    {
        WARN("p_uvc_server is not inited, so malloc it here\n");
        p_uvc_server = malloc(sizeof(uvc_server_t));
        memset(p_uvc_server, 0, sizeof(uvc_server_t));
        p_uvc_server->pipe_line_fd = -1;
        p_uvc_server->run_flag = 1;
    }
    return p_uvc_server;
}


//find output device
static int uvc_dev_recognition(char* buf, int len, int mode)
{
    int i = 0, j = 0;
    char* uvc_flag = __OUTPUT_DEVICE_NAME__;

    if(1 == mode)
    {
        uvc_flag = __OUTPUT_DEVICE_NAME2__;
    }

    for(i = 0; i < strlen(__OUTPUT_DEVICE_NAME__) - 1; i++)
    {
        while(j < len && uvc_flag[i] != buf[j])
            j++;
        if(j == len)
            return -1;
    }
    return 0;
}


/*****************************************************************************
*   Prototype    : ob_rgb_uvc_open
*   Description  : open a rgb uvc device
*   Input        : const char *devname  
*                  int fps              
*   Output       : None
*   Return Value : static struct uvc_device *
*****************************************************************************/
static struct uvc_device *ob_rgb_uvc_open(const char *devname, int fps)  //just for rgb device
{
    struct uvc_device *dev;
    struct v4l2_capability cap;
    int ret;
    int fd = -1;
    uvc_server_t *server_l = get_uvc_server();

    fd = open(devname, O_RDWR | O_NONBLOCK);
    if (fd < 0) {
        ERR("v4l2 open failed: %s (%d)\n", strerror(errno), errno);
        return NULL;
    }
    INFO("open %s succeeded, file descriptor = %d\n", devname, fd);

    ret = ioctl(fd, VIDIOC_QUERYCAP, &cap);
    if (ret < 0) {
        ERR("unable to query device: %s (%d)\n", strerror(errno), errno);
        close(fd);
        return NULL;
    }

    log_printf("***********************Device info*********************\n");
    log_printf("device is %s on bus %s\n", cap.card, cap.bus_info);
    log_printf("device driver      : \t%s\n", cap.driver);
    log_printf("device card        : \t%s\n", cap.card);
    log_printf("device capabilities: \t0x%08x\n", cap.capabilities);
    log_printf("device device_caps : \t0x%08x\n", cap.device_caps);
    log_printf("*******************************************************\n");

    dev = malloc(sizeof *dev);
    if (dev == NULL) {
        close(fd);
        return NULL;
    }

    memset(dev, 0, sizeof *dev);
    dev->fd = fd;
    dev->width  = server_l->width[0];
    dev->height = server_l->height[0];
    dev->frame_interval = (10000000 / fps);
    dev->fcc = uvc_formats[0].fcc;
    dev->fcc_index = 0;
    dev->camera_fd = -1;

    return dev;
}


/*****************************************************************************
*   Prototype    : ob_rgb_uvc_close
*   Description  : close a uvc device
*   Input        : struct uvc_device *dev  
*   Output       : None
*   Return Value : static void
*****************************************************************************/
static void ob_rgb_uvc_close(struct uvc_device *dev)
{
    if(dev)
    {
       close(dev->fd);
       //free(dev->imgdata);
       free(dev->mem);
       free(dev);
    }
}


/*****************************************************************************
*   Prototype    : ob_rgb_get_stream_form_rtos
*   Description  : get rgb stream from rtos
*   Input        : void * para  
*   Output       : None
*   Return Value : void *
*****************************************************************************/
void *ob_rgb_get_stream_form_rtos(void *para)
{
    uvc_server_t                    *server_l               = get_uvc_server();
    struct uvc_frame_buf_info       *buf_info[BUFFER_COUNT] = {0};
    int                             count                   = 500;
    int                             lancher_fd              = -1;
    char                            path[128]               = {""};
    basic_3a_info_t                 info;
    fd_set                          fds;
    struct timeval                  tv;
    unsigned int                    tmp_index, fcc_index;
    struct uvc_format_opt           *format_opt;
    int                             ret = -1;
    ar_uvc_context_t                *context = NULL;
    uint32_t                        context_size = 0;
    int                             get_frame_succ = 0;
	static int fd = -1;
	zoom_pra_t zoom;	
	static int zoom_count = 0;
    static bool D2Cchangeflag = 0;
	
    while(server_l->run_flag)
    {
        switch(server_l->status)
        {
            case UVC_STATUS_IDLE:
                server_l->status = UVC_STATUS_INIT;
                break;
            
            case UVC_STATUS_INIT:
                //[1] 开启multimedia_core节点
                do{
                    usleep(10*1000);
                    server_l->handle = ar_multimedia_core_device_open();
                    count--;
                }while(!server_l->handle && count > 0 && server_l->run_flag);

                if(!server_l->handle)
                {
                    ERR("can not open multicore try 500 times dur 5s,exit the app, please checkout your frame work !!!!");
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                //[2] 开启lancher节点
                count = 500;
                do{
                    lancher_fd = ar_lancher_open();
                    if(lancher_fd < 0)
                        usleep(10*1000);
                    count--;
                }while(lancher_fd < 0 && count > 0 && server_l->run_flag);

                if(lancher_fd < 0)
                {
                    ERR("can not open lancher try 500 times dur 5s,exit the app, please checkout your frame work !!!!");
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                ar_lancher_creat_app(lancher_fd, "jpeg_service");
                ar_lancher_close(lancher_fd);

                //[3] 初始化默认格式pipeline
                if(NULL == uvc_formats[server_l->dev->fcc_index].data || NULL == uvc_formats[server_l->dev->fcc_index].data->format_opt)
                {
                    ERR("uvc_formats get error!\n");
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                if(uvc_formats[server_l->dev->fcc_index].data->format_opt->format_init(  //uvc_mjpeg_init, uvc_h264_init
                                                            uvc_formats[0].data,
                                                            server_l->handle,
                                                            server_l->argc,
                                                            server_l->argv))
                {
                    ERR("uvc_formats init error!\n");
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                INFO("pipe_index=%d\n", server_l->pipe_index);

                //[4] 开启pipeline控制节点
                sprintf(path, "/dev/uvc_path-%d", server_l->pipe_index);
                server_l->pipe_line_fd = ar_pipeline_ctrl_open(path);
                if(server_l->pipe_line_fd < 0)
                {
                    ERR("open pipeline error pipe_index=%d\n",server_l->pipe_index);
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                //[4] 开启camera控制节点
                sprintf(path, "/dev/cam_src-%d", server_l->pipe_index);
                server_l->dev->camera_fd = open(path, O_RDWR | O_SYNC);
                if(server_l->dev->camera_fd < 0)
                {
                    ERR("open device %s failed fd=%d\n", path, server_l->dev->camera_fd);
                    server_l->dev->camera_fd = -1;
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                FD_ZERO(&fds);
                FD_SET(server_l->dev->fd, &fds);
                server_l->status = UVC_STATUS_INIT_COMPLETE;
                break;

            case UVC_STATUS_INIT_COMPLETE:
                ar_uvc_get_context((void**)&context, &context_size);
                if(NULL != context && AR_ELEMENT_STATE_PLAYING == ar_element_get_state(server_l->handle,(ar_pipeline_t)context->pipeline.element))
                {
                    ar_cam_get_3a_info(server_l->dev->camera_fd, &info);
                    server_l->dev->camera_terminal.exposure_time_absolute_val = info.aec_info.exp_time_us * 10000;//server_l->CT_BRIGHTNESS_DEFAULT_VAL;
                    server_l->dev->camera_terminal.auto_exposure_aec_info     = info.aec_info;
                    server_l->status = UVC_STATUS_RELEASE_FRAME;
                    if(V4L2_PIX_FMT_MJPEG == server_l->dev->fcc)
                        uvc_video_set_rotation(server_l->handle,server_l->rotation_angle);
                }
                else
                {
                    INFO("init complete and wait playing state!\n");
                    usleep(1000000);
                }
				fd =server_l->dev->camera_fd;	
				//printf("-----UVC_STATUS_INIT_COMPLETE: camera_fd fd=%d\n",  fd);
/*	
				if(RES_MODE_4_3 == ob_rgb_get_res_mode(server_l->dev->width, server_l->dev->height))// 分辨率 4:3，需要裁剪
				{
					zoom.manual=1;
					zoom.digital_zoom=1;
					zoom.stream_type=0;
			
					zoom.roi.x=0.127605;  //y:490  //0.130730： x502  y 24  w 2848  h 2136 
					zoom.roi.y=0;
					zoom.roi.width=0.741667;
					zoom.roi.height=0.988886;	
					//printf("UVC_STATUS_INIT_COMPLETE: ---fd==%d, stream type=%d zoom=%f man_zoom=%d (x,y w,h)=(%f,%f %f,%f)\n",\
    					//fd,zoom.stream_type,zoom.digital_zoom,zoom.manual,\
    					//zoom.roi.x,zoom.roi.y,zoom.roi.width,zoom.roi.height);
					ar_cam_set_zoom(fd, zoom);
				}	
				else  // 16:9
				{
					zoom.manual=1;
					zoom.digital_zoom=1;
					zoom.stream_type=0;
			
					zoom.roi.x=0;  // 00
					zoom.roi.y=0;
					zoom.roi.width=1;
					zoom.roi.height=1;	
					//printf("UVC_STATUS_INIT_COMPLETE: ---fd==%d, stream type=%d zoom=%f man_zoom=%d (x,y w,h)=(%f,%f %f,%f)\n",\
    					//fd,zoom.stream_type,zoom.digital_zoom,zoom.manual,\
    					//zoom.roi.x,zoom.roi.y,zoom.roi.width,zoom.roi.height);
					ar_cam_set_zoom(fd, zoom);
				}	
*/
	//	printf("UVC_STATUS_INIT_COMPLETE: frame_interval==%d height==%d  width%d \n",server_l->dev->frame_interval,server_l->dev->height,server_l->dev->width);
	/*
			 if(RES_MODE_4_3 == ob_rgb_get_res_mode(server_l->dev->width, server_l->dev->height))// 分辨率 4:3，需要裁剪
				{
				  zoom.manual=1;
				  zoom.digital_zoom=1;
				  zoom.stream_type=0;
			  
				  zoom.roi.x=0.166667;       //x.start 640(0.166667) 
				  zoom.roi.y=0.044445;       //  y.start  96 (0.044445 )( 94 0.04351852)    y.start 144   (0.066667)    
				  zoom.roi.width=0.666667;    //  w 2560 (0.666667) 
				  zoom.roi.height=0.888889;  //  h 1920 (0.8888889) 
			//	  printf("UVC_STATUS_INIT_COMPLETE: ---fd==%d, stream type=%d zoom=%f man_zoom=%d (x,y w,h)=(%f,%f %f,%f)\n",\
			//		  fd,zoom.stream_type,zoom.digital_zoom,zoom.manual,\
			//		  zoom.roi.x,zoom.roi.y,zoom.roi.width,zoom.roi.height);
				  ar_cam_set_zoom(fd, zoom);
				}  
				else if(((server_l->dev->frame_interval==166667)||(server_l->dev->frame_interval==166666))&&(server_l->dev->width==1080)||(server_l->dev->height==1080)) // 1080P 60 
				{				
				  	zoom.manual=1;
					zoom.digital_zoom=1;
					zoom.stream_type=0;
			
					zoom.roi.x=0;  // 00
					zoom.roi.y=0;
					zoom.roi.width=1;
					zoom.roi.height=1;	
				//	printf("UVC_STATUS_INIT_COMPLETE 1080p 60 no zoom: ---fd==%d, stream type=%d zoom=%f man_zoom=%d (x,y w,h)=(%f,%f %f,%f) height=%d\n",\
    			//		fd,zoom.stream_type,zoom.digital_zoom,zoom.manual,\
    			//		zoom.roi.x,zoom.roi.y,zoom.roi.width,zoom.roi.height,server_l->dev->height);
					ar_cam_set_zoom(fd, zoom);
					
				} 
				else  // 其他 16:9
				{
					
				  zoom.manual=1;
				  zoom.digital_zoom=1;
				  zoom.stream_type=0;
			  
				  zoom.roi.x=0.033333;   //x.start 128 (0.0333334) 
				  zoom.roi.y=0.022222;       //  y.start 48   (0.022222223)    y.start 96  (0.044445)    
				  zoom.roi.width=0.933333;    //  w 3584 (0.933333333) 
				  zoom.roi.height=0.933333;   //  h 2016 (0.933333333) 
			//	  printf("UVC_STATUS_INIT_COMPLETE: ---fd==%d, stream type=%d zoom=%f man_zoom=%d (x,y w,h)=(%f,%f %f,%f)\n",\
			//		  fd,zoom.stream_type,zoom.digital_zoom,zoom.manual,\
			//		  zoom.roi.x,zoom.roi.y,zoom.roi.width,zoom.roi.height);
				  ar_cam_set_zoom(fd, zoom);
				} 
*/				
                break;				

            case UVC_STATUS_RELEASE_FRAME:

                tmp_index   = server_l->idx % BUFFER_COUNT;
                fcc_index   = server_l->dev->fcc_index;
                format_opt  = uvc_formats[fcc_index].data->format_opt;

                if(NULL != buf_info[tmp_index])
                {
                    if(format_opt->release_frame(uvc_formats[fcc_index].data, buf_info[tmp_index]))
                    {
                        ERR("release buffer fail!!\n");
                        server_l->status = UVC_STATUS_EXIT;
                        break;
                    }

                    buf_info[tmp_index] = NULL;
                }

                if(1 == server_l->g_chg_fmt_flag) {
                    server_l->status = UVC_STATUS_CHANGE_FORMAT;
                }else{
                    server_l->status = UVC_STATUS_GET_FRAME;
                }

                break;

            case UVC_STATUS_GET_FRAME:

                ret = -1;
                tv.tv_sec   = 0;
                tv.tv_usec  = 10000;

                tmp_index   = server_l->idx % BUFFER_COUNT;
                fcc_index   = server_l->dev->fcc_index;
                format_opt  = uvc_formats[fcc_index].data->format_opt;

                buf_info[tmp_index] = format_opt->get_frame(uvc_formats[fcc_index].data);
                if(!buf_info[tmp_index])
                {
                    ERR("get buffer fail!! %s line:%d\n", __func__, __LINE__);
                }
                else
                {
                    if (server_l->idx == 0 && get_frame_succ == 0)
                    {
                        log_printf("UVC get frame success\n");
                        get_frame_succ = 1;
                    }
                    if (buf_info[tmp_index]->len > MAX_BUFFER_SIZE)
                    {
                        ERR("error package length over max buffer size %d bytes(%d bytes)\n", MAX_BUFFER_SIZE, buf_info[tmp_index]->len);
                        ret = uvc_video_send(server_l->dev, (void *)buf_info[tmp_index]->addr, MAX_BUFFER_SIZE, buf_info[tmp_index]->pts, fds, tv);
                    }
                    else
                    {
                        ret = uvc_video_send(server_l->dev, (void *)buf_info[tmp_index]->addr, buf_info[tmp_index]->len, buf_info[tmp_index]->pts, fds, tv);
                    }
                }

                if(ret < 0)
                {
                    //ERR("uvc_video_send failed!\n");
                }
                else
                {
                    server_l->idx++;
                }

                if(1 == server_l->g_chg_fmt_flag){
                    server_l->status = UVC_STATUS_CHANGE_FORMAT;
                }else{
                    server_l->status = UVC_STATUS_RELEASE_FRAME;
                }

#if 0 //just for debug test!!
				if(zoom_count>1200)   // 分辨率 16:9，恢复原始比例
				{
					zoom.manual=1;
					zoom.digital_zoom=1;
					zoom.stream_type=0;

					zoom.roi.x=0;
					zoom.roi.y=0;
					zoom.roi.width=1;
					zoom.roi.height=1;

					printf("UVC_STATUS_GET_FRAME： ---fd==%d, stream type=%d zoom=%f man_zoom=%d (x,y w,h)=(%f,%f %f,%f)\n",\
    					fd,zoom.stream_type,zoom.digital_zoom,zoom.manual,\
    					zoom.roi.x,zoom.roi.y,zoom.roi.width,zoom.roi.height);
                    
    			    ar_cam_set_zoom(fd, zoom);
					zoom_count =0;
					
				}
				else if(zoom_count==900)   // 分辨率 4:3， (x.start:640   y.start: 60  width:2800  height:2100)
				{
					zoom.manual=1;
					zoom.digital_zoom=1;
					zoom.stream_type=0;
			
					zoom.roi.x=0.166667;   //  // x.640   y.60
					zoom.roi.y=0.027778;
					zoom.roi.width=0.729166;
					zoom.roi.height=0.972222;	
					printf("UVC_STATUS_GET_FRAME： ---fd==%d, stream type=%d zoom=%f man_zoom=%d (x,y w,h)=(%f,%f %f,%f)\n",\
					fd,zoom.stream_type,zoom.digital_zoom,zoom.manual,\
					zoom.roi.x,zoom.roi.y,zoom.roi.width,zoom.roi.height);
					ar_cam_set_zoom(fd, zoom);
				
				}	
				else if(zoom_count==600)   // 分辨率 4:3， (x.start:540   y.start: 60  width:2800  height:2100)
				{
					zoom.manual=1;
					zoom.digital_zoom=1;
					zoom.stream_type=0;
			
					zoom.roi.x=0.140625;  // x.540   y.60  w 2800 h 2100
					zoom.roi.y=0.027778;
					zoom.roi.width=0.729166;
					zoom.roi.height=0.972222;

					printf("UVC_STATUS_GET_FRAME： ---fd==%d, stream type=%d zoom=%f man_zoom=%d (x,y w,h)=(%f,%f %f,%f)\n",\
					fd,zoom.stream_type,zoom.digital_zoom,zoom.manual,\
					zoom.roi.x,zoom.roi.y,zoom.roi.width,zoom.roi.height);
					ar_cam_set_zoom(fd, zoom);
				
				}				
				else if(zoom_count==300)  // 分辨率 4:3， (x.start:502   y.start: 24   width:2846  height:2136)
				{
					zoom.manual=1;
					zoom.digital_zoom=1;
					zoom.stream_type=0;
			
					zoom.roi.x=0.130730;  // x502  y 24  w 2846  h 2136 
					zoom.roi.y=0.011113;
					zoom.roi.width=0.741667;
					zoom.roi.height=0.988886;	
					printf("UVC_STATUS_GET_FRAME： ---fd==%d, stream type=%d zoom=%f man_zoom=%d (x,y w,h)=(%f,%f %f,%f)\n",\
					fd,zoom.stream_type,zoom.digital_zoom,zoom.manual,\
					zoom.roi.x,zoom.roi.y,zoom.roi.width,zoom.roi.height);
					ar_cam_set_zoom(fd, zoom);
				
				}							
				zoom_count++;	
#endif				
        
                // printf("g_rgb_crop_flag:%d\n", g_rgb_crop_flag);
                 if(g_rgb_crop_flag==1)  // 做裁剪缩放， 后续还需要增加硬件D2C变量
                {
                      if(D2Cchangeflag==0)
                      {
                      //sensor 最终需要先配置为4K （这里需要酷芯微给接口）
                        if(RES_MODE_4_3 == ob_rgb_get_res_mode(server_l->dev->width, server_l->dev->height))// 分辨率 4:3，需要裁剪
                         {
                              zoom.manual=1;
                              zoom.digital_zoom=1;
                              zoom.stream_type=0;      
                              zoom.roi.x=0.166667;       //x.start 640(0.166667) 
                              zoom.roi.y=0.044445;       //  y.start  96 (0.044445 )( 94 0.04351852)    y.start 144   (0.066667)    
                              zoom.roi.width=0.666667;    //  w 2560 (0.666667) 
                              zoom.roi.height=0.888889;  //  h 1920 (0.8888889) 
                              printf("UVC_43: ---fd==%d, stream type=%d zoom=%f man_zoom=%d (x,y w,h)=(%f,%f %f,%f)\n",\
                                fd,zoom.stream_type,zoom.digital_zoom,zoom.manual,\
                                zoom.roi.x,zoom.roi.y,zoom.roi.width,zoom.roi.height);        
                         }
                         else   //16:9
                         {
                              zoom.manual=1;
                              zoom.digital_zoom=1;
                              zoom.stream_type=0;
                            
                              zoom.roi.x=0.033333;   //x.start 128 (0.0333334) 
                              zoom.roi.y=0.022222;       //  y.start 48   (0.022222223)    y.start 96  (0.044445)    
                              zoom.roi.width=0.933333;    //  w 3584 (0.933333333) 
                              zoom.roi.height=0.933333;   //  h 2016 (0.933333333) 
                              printf("UVC_16 9: ---fd==%d, stream type=%d zoom=%f man_zoom=%d (x,y w,h)=(%f,%f %f,%f)\n",\
                                fd,zoom.stream_type,zoom.digital_zoom,zoom.manual,\
                                zoom.roi.x,zoom.roi.y,zoom.roi.width,zoom.roi.height);   
                         }
                         ar_cam_set_zoom(fd, zoom); 
                         D2Cchangeflag=1;
                      }      
                }
                else  // if(ob_streamControl.depthSoftD2C_enable==0)  //关闭d2c后 不做裁剪缩放
                {
                      if(D2Cchangeflag==1)
                      {
                            zoom.manual=1;   
                            zoom.digital_zoom=1;
                            zoom.stream_type=0;
                        
                            zoom.roi.x=0;  // 00
                            zoom.roi.y=0;
                            zoom.roi.width=1;
                            zoom.roi.height=1;  
                            printf("UVC_close D2C: ---fd==%d, stream type=%d zoom=%f man_zoom=%d (x,y w,h)=(%f,%f %f,%f)\n",\
                            fd,zoom.stream_type,zoom.digital_zoom,zoom.manual,\
                                zoom.roi.x,zoom.roi.y,zoom.roi.width,zoom.roi.height);  
                            ar_cam_set_zoom(fd, zoom);
                              D2Cchangeflag=0;    
                      }      
                }          

                break;

            case UVC_STATUS_CHANGE_FORMAT:
                INFO("UVC_STATUS_CHANGE_FORMAT\n");
                if(server_l->dev->new_fcc != server_l->dev->fcc)
                {
                    //release frame
                    fcc_index   = server_l->dev->fcc_index;
                    format_opt  = uvc_formats[fcc_index].data->format_opt;
                    for(int i = 0; i < BUFFER_COUNT; ++i)
                    {
                        if(NULL != buf_info[i])
                        {
                            if(format_opt->release_frame(uvc_formats[fcc_index].data, buf_info[i]))
                            {
                                ERR("release buffer fail!!\n");
                            }
                            buf_info[i] = NULL;
                        }
                    }
                    INFO("release buffer success!\n");
                }

                D2Cchangeflag = 0;
                uvc_pipeline_set_format(server_l->dev->width, server_l->dev->height, 10000000/server_l->dev->frame_interval, server_l->dev->new_fcc);

                uvc_video_set_format(server_l->dev);

                server_l->g_chg_fmt_flag = 0;
                sem_post(&server_l->g_chg_fmt_sem);//release lock

                server_l->status = UVC_STATUS_INIT_COMPLETE;
                break;

            case UVC_STATUS_EXIT:
            case UVC_STATUS_MAX:
            default:
                goto EXIT; //fix: usb automatic disconnect if unconnected rgb sensor 
                if(1 == server_l->run_flag)
                    server_l->run_flag = 0;

                break;
        }
    }

EXIT:
    while(NULL != buf_info[server_l->idx % BUFFER_COUNT])
    {
        struct uvc_format_opt * format_opt;
        unsigned int            fcc_index;

        fcc_index   = server_l->dev->fcc_index;
        format_opt  = uvc_formats[fcc_index].data->format_opt;

        if(format_opt->release_frame(uvc_formats[fcc_index].data, buf_info[server_l->idx % BUFFER_COUNT]))
        {
            log_err("release buffer fail!! %s line:%d\n", __func__, __LINE__);
            break;
        }

        buf_info[server_l->idx % BUFFER_COUNT] = NULL;

        server_l->idx++;
    }

    if(1 == server_l->g_chg_fmt_flag)
    {
        server_l->g_chg_fmt_flag = 0;
        sem_post(&server_l->g_chg_fmt_sem);//release lock
    }

    ERR("Exit!\n");

    return NULL;
}


static int ob_rgb_start_uvc_trans(void)
{
    int index           = 0;
    int len             = 0;
    int i, j;
    int ret             = 0;
    pthread_attr_t      attr;
    char devName[32];              /* /dev/video0 */
    int                 bulk_mode       = 1; //bulk传输模式
    int                 cdns_mode       = 0;
    char                namebuf[32]     = {""};
    int                 fd              = -1;
    int                 fps             = 30;
    fd_set              fds;
    struct timeval      tv;
    pthread_t           thread_getbuf;  //采集sensor数据线程
    cpu_set_t           cpu_info;
    char                path[128]       = {""};

    uvc_server_t *server_l = get_uvc_server();

    pthread_mutex_init(&server_l->g_wrt_com_mutex, NULL);
    sem_init(&server_l->g_chg_fmt_sem, 0, 1);
    pthread_attr_init(&attr);

    uvc_formats_num = getConfigfsFormat(&uvc_formats, server_l->dev_index);
    if(uvc_formats_num < 0)
    {
        ERR("UVC configfs info get failed!\n");
        return -1;
    }

#if 0
    printf("***********************uvc_formats_num: %d***********************\n", uvc_formats_num);
    for(i = 0; i < uvc_formats_num; ++i)
    {
        char * p = (char *)&(uvc_formats[i].fcc);
        printf("format: %c%c%c%c\n", p[0], p[1], p[2], p[3]);
        j = 0;
        for(j = 0; 0 != uvc_formats[i].frames[j].height; ++j)
        {
            int k;
            printf("    %d. %d * %d:\n", j, uvc_formats[i].frames[j].width, uvc_formats[i].frames[j].height);
            printf("        interval: ");
            for(k = 0; k < 8; ++k)
            {
                printf("%d ", uvc_formats[i].frames[j].intervals[k]);
            }
            printf("\n");
        }
    }
    printf("*****************************************************************\n");
#endif

    memset(devName, 0, sizeof(devName));
    snprintf(devName, sizeof(devName), "/dev/video%d", server_l->dev_index);
    if (0 != access(devName, F_OK))  {
        ERR("not found %s\n", devName);
        return -1;
    }

    server_l->dev = ob_rgb_uvc_open(devName, fps);
    if (NULL == server_l->dev)
    {
        ERR("ob_rgb_uvc_open failed.\n");
        return -1;
    }

    server_l->dev->camera_terminal.auto_exposure_mode_control       = CT_AUTO_EXPOSURE_MODE_DEFAULF_VAL;
    server_l->dev->camera_terminal.zoom_absolute_val                = CT_ZOOM_ABSOLUTE_DEFAULT_VAL;
    server_l->dev->camera_terminal.roll_absolute_val                = CT_ROLL_ABSOLUTE_DEFAULT_VAL;
    server_l->dev->processing_unit.brightness_val                   = PU_BRIGHTNESS_DEFAULT_VAL;
    server_l->dev->processing_unit.contrast_val                     = PU_CONTRAST_DEFAULT_VAL;
    server_l->dev->processing_unit.hue_val                          = PU_HUE_DEFAULT_VAL;
    server_l->dev->processing_unit.saturation_val                   = PU_SATURATION_DEFAULT_VAL;
    server_l->dev->processing_unit.sharpness_val                    = PU_SHARPNESS_DEFAULT_VAL;
    server_l->dev->processing_unit.gamma_val                        = PU_GAMMA_DEFAULT_VAL;
    server_l->dev->processing_unit.white_balance_temperature_val    = PU_WHITE_BALANCE_TEMPERATURE_DEFAULT_VAL;
    server_l->dev->processing_unit.white_balance_component_val      = 0;
    server_l->dev->processing_unit.backlight_compensation_val       = PU_BACKLIGHT_COMPENSATION_DEFAULT_VAL;
    server_l->dev->processing_unit.gain_val                         = PU_GAIN_DEFAULT_VAL;
    server_l->dev->processing_unit.power_line_frequency_val         = PU_POWER_LINE_FREQUENCY_DEFAULT_VAL;
    server_l->dev->processing_unit.hue_auto_val                     = PU_HUE_AUTO_DEFAULT_VAL;
    server_l->dev->processing_unit.white_balance_temperature_auto_val = WHITE_BALANCE_TEMPERATURE_AUTO_DEFAULT_VAL;

    server_l->dev->bulk = bulk_mode;

    //find usb device's interface number(control interface and stream interface)
    if((server_l->dev->control_interface = getCtrlInterfaceNum(server_l->dev_index)) < 0) {
        ERR("auto get control interface failed!\n");
    }else{
        INFO("get rgb uvc control bInterfaceNumber:%d\n", server_l->dev->control_interface);
    }

    if((server_l->dev->streaming_interface = getStreamInterfaceNum(server_l->dev_index)) < 0){
        ERR("auto get stream interface failed!\n");
    }else{
        INFO("get rgb uvc streaming bInterfaceNumber:%d\n", server_l->dev->streaming_interface);
    }

    //init uvc
    uvc_events_init(server_l->dev);
    uvc_video_init(server_l->dev);

    /* avoid broken frame in plugin */
    server_l->first_image_size = MAX_BUFFER_SIZE / (1024 * 16);
    server_l->first_image_data = (void *)malloc(MAX_BUFFER_SIZE * sizeof(char));
    memset(server_l->first_image_data, 0x0, MAX_BUFFER_SIZE);
    server_l->status = UVC_STATUS_IDLE;

    //线程绑定cpu核
    //CPU_ZERO(&cpu_info);
    //CPU_SET(1, &cpu_info); //绑定第一个核（从0开始）
    //if(pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &cpu_info)){
     //   ERR("attr fail\n");
    //}

    //RGB数据流采集线程
    pthread_create(&thread_getbuf, &attr, (void *)ob_rgb_get_stream_form_rtos, (void *)server_l->dev);

    //uvc contorl loop
    FD_ZERO(&fds);
    FD_SET(server_l->dev->fd, &fds);
    while (server_l->run_flag)
    {
        fd_set efds = fds;
        fd_set wfds = fds;

        /* Timeout. */
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        ret = select(server_l->dev->fd + 1, NULL, NULL, &efds, &tv);
        if(ret > 0)
        {
            if (FD_ISSET(server_l->dev->fd, &efds))
                uvc_events_process(server_l->dev);
        }
    }
    INFO("exit rgb uvc event monitor loop.\n");

    //clean up
    if(NULL != server_l->first_image_data)
    {
        free(server_l->first_image_data);
        server_l->first_image_data = NULL;
    }
 
auto_find_fail:

    user_data_shr_mem_close(server_l->trans_ceva_id);
    user_data_shr_mem_close(server_l->trans_log_id);

    ar_video_stream_close(uvc_formats[server_l->dev->fcc_index].data->vs_handle);

    ob_rgb_uvc_close(server_l->dev);

    freeConfigfsFormat(&uvc_formats, uvc_formats_num);
    
    return 0;
}


/*****************************************************************************
*   Prototype    : ob_rgb_uvc_service
*   Description  : rgb uvc service
*   Input        : void    
*   Output       : None
*   Return Value : int

*****************************************************************************/
static int ob_rgb_uvc_service(void)
{
    uvc_server_t *server_l = get_uvc_server();

    //初始化参数
    server_l->pipe_index = RGB_PIPELINE_INDEX;
    server_l->dev_index  = OB_UVC_DEVICE_NODE_NUM_RGB; // /dev/video0 for rgb
    server_l->width[0]   = RGB_SENSOR_WIDTH;
    server_l->height[0]  = RGB_SENSOR_HEIGHT;
    server_l->width[1]   = 640;
    server_l->height[1]  = 480;
    server_l->multi          = 0;  //多路pipeline时需要设置为1
    server_l->rotation_angle = 90;
    server_l->force_isp_ddr_mode = 0;
    server_l->err_process = 0;
    server_l->hw_sync     = 0;   

    //this function will block on uvc request
    uint32_t context_size = 0;
    ar_uvc_context_t* context = NULL;
    ar_uvc_get_context((void**)&context, &context_size);

    char name[64] = {0};
    sprintf(name, "uvcserver%d", server_l->pipe_index);
    context->server_l = creat_pipeline_clt_server(name, &api_ops, server_l);

    //rgb uvc start
    ob_rgb_start_uvc_trans();

    //wait_pipeline_ctl_main_loop_end(context->server_l);
    ar_pipeline_ctrl_close(server_l->pipe_line_fd);

    INFO("Exit !\n");
    return 0;
}


/*****************************************************************************
*   Prototype    : ob_rgb_uvc_module_init
*   Description  : rgb uvc模块初始化
*   Input        : void   
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_rgb_uvc_module_init(void)
{
    pthread_t thread;
	pthread_create(&thread, NULL, (void *)ob_rgb_uvc_service, NULL);

    return 0;
}


