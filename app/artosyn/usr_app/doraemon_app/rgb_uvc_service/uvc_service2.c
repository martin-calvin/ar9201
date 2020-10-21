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
#include "obshareDataType.h"



/* 格式顺序: H265 H264 Mjpeg YUYV */
struct uvc_format_info *uvc_formats = NULL; //通过 getConfigfsFormat 获取的数据格式支持列表
int uvc_formats_num = 0;

//bit0: calibra
//bit1: d2c(SW)
//bit2: d2c(HW)
//由于默认开软件d2c,所以在此默认将bit1赋值
u16 g_rgb_crop_flag = 0x02; //rgb裁剪标志(rw)


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
*   Prototype    : ob_rgb_crop_op
*   Description  : rgb zoom operation
*   Input        : uvc_server_t *pServer  
*                  bool crop_flag         
*   Output       : None
*   Return Value : static int
*****************************************************************************/
inline static int ob_rgb_crop_op(uvc_server_t *p1Server, bool crop_flag)
{
    zoom_pra_t zoom;
    memset(&zoom, 0, sizeof(zoom));
    uvc_server_t  *pServer = get_uvc_server();

    if (NULL == pServer){
        ERR("pServer is NULL.\n");
        return -1;
    }


    if (crop_flag)  //裁剪
    {
        if(RES_MODE_4_3 == ob_rgb_get_res_mode(pServer->dev->width, pServer->dev->height))
        {
            zoom.manual=1;
            zoom.digital_zoom=1;
            zoom.stream_type=1;        //从辅路拿数据    
            zoom.roi.x=0.166667;       //x.start 640(0.166667) 
            zoom.roi.y=0.044445;       //y.start  96 (0.044445 )( 94 0.04351852)    y.start 144   (0.066667)    
            zoom.roi.width=0.666667;   //w 2560 (0.666667) 
            zoom.roi.height=0.888889;  //h 1920 (0.8888889)     
        }
        else //16:9
        {
            zoom.manual=1;
            zoom.digital_zoom=1;

            //uvc 4k从主路拿数据, 非4k从辅路拿数据
            if (pServer->dev->width == RGB_SENSOR_WIDTH || pServer->dev->width == RGB_SENSOR_HEIGHT)
            {
                //需求: uvc 4k不做裁剪,恢复原图输出
                zoom.stream_type = 0;        
                zoom.roi.x = 0;
                zoom.roi.y = 0;
                zoom.roi.width = 1;
                zoom.roi.height = 1;  
            }
            else 
            {
                zoom.stream_type = 1;  
                zoom.roi.x=0.033333;   //x.start 128 (0.0333334) 
                zoom.roi.y=0.022222;       //  y.start 48   (0.022222223)    y.start 96  (0.044445)    
                zoom.roi.width=0.933333;    //  w 3584 (0.933333333) 
                zoom.roi.height=0.933333;   //  h 2016 (0.933333333) 
            }
        }
    }
    else
    {
        zoom.manual = 1;   
        zoom.digital_zoom = 1;
        
        //uvc 4k从主路拿数据, 非4k从辅路拿数据
        if (pServer->dev->width == RGB_SENSOR_WIDTH || pServer->dev->width == RGB_SENSOR_HEIGHT)
            zoom.stream_type = 0;
        else 
            zoom.stream_type = 1; 
        
        zoom.roi.x = 0;
        zoom.roi.y = 0;
        zoom.roi.width  = 1;
        zoom.roi.height = 1;  
    }

    INFO("==> zoom: stream_type:%d, roi ratio(x:%.6f, y:%.6f, w:%.6f, h:%.6f)\n",
                        zoom.stream_type,
                        zoom.roi.x, zoom.roi.y,
                        zoom.roi.width, zoom.roi.height);
    
    INFO("==> zoom: stream_type:%d, roi(x:%d, y:%d, w:%d, h:%d)\n",
                        zoom.stream_type,
                        (int)(3840*zoom.roi.x), (int)(2160*zoom.roi.y),
                        (int)(3840*zoom.roi.width), (int)(2160*zoom.roi.height));
    
    ar_cam_set_zoom(pServer->dev->camera_fd, zoom);  

    return 0;
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
    dev->width  = server_l->width[1];
    dev->height = server_l->height[1];
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
    int                             ret = -1;
    struct uvc_frame_buf_info       *buf_info[BUFFER_COUNT] = {0};
    int                             count                   = 500;
    int                             lancher_fd              = -1;
    char                            path[128]               = {""};
    basic_3a_info_t                 info;
    fd_set                          fds;
    struct timeval                  tv;
    unsigned int                    tmp_index, fcc_index;
    struct uvc_format_opt           *format_opt;
    ar_uvc_context_t                *context = NULL;
    uint32_t                        context_size = 0;
    int                             get_frame_succ = 0;
    static volatile bool            bRgbCropOpFlag = false; //是否已下发了zoom参数(rw)
	uvc_server_t                    *server_l               = get_uvc_server();

    
    while(server_l->run_flag)
    {
        switch(server_l->status)
        {
            case UVC_STATUS_IDLE:
                server_l->status = UVC_STATUS_INIT;
                break;
            case UVC_STATUS_INIT:
            {
                //[1] 开启multimedia_core节点
                do{
                    usleep(10*1000);
                    server_l->handle = ar_multimedia_core_device_open();
                    count--;
                }while(!server_l->handle && count > 0 && server_l->run_flag);

                if(!server_l->handle){
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
                
                if(lancher_fd < 0){
                    ERR("can not open lancher try 500 times dur 5s,exit the app, please checkout your frame work !!!!");
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                ar_lancher_creat_app(lancher_fd, "jpeg_service");
                ar_lancher_close(lancher_fd);


                //[3] 初始化默认格式pipeline
                if(NULL == uvc_formats[server_l->dev->fcc_index].data || NULL == uvc_formats[server_l->dev->fcc_index].data->format_opt){
                    ERR("uvc_formats get error!\n");
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                //uvc_mjpeg_init, uvc_h264_init, uvc_i420_init
                if(uvc_formats[server_l->dev->fcc_index].data->format_opt->format_init(uvc_formats[0].data,server_l->handle,server_l->argc,server_l->argv)) 
                {
                    ERR("uvc_formats init error!\n");
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                ar_uvc_get_context((void**)&context, &context_size);
                while (AR_ELEMENT_STATE_PLAYING != ar_element_get_state(server_l->handle,(ar_pipeline_t)context->pipeline.element)){
                    //INFO("wait first playing state!\n");
                    usleep(10*1000);
                }

                //开机后保持流关闭状态,等待上位机请求开流
                ret = ar_pipeline_terminal_stream(server_l->handle, (ar_pipeline_t)context->pipeline.element); //ANY --> NULL
                if (0 != ret)                {
                    ERR("xavier, terminal stream failed!\n");                    
                    server_l->status = UVC_STATUS_EXIT;
                    break;                    
                }
                INFO("terminal stream, then wait host trigger stream start!\n");

                //[4] 开启pipeline控制节点
                INFO("pipe_index=%d\n", server_l->pipe_index);
                sprintf(path, "/dev/uvc_path-%d", server_l->pipe_index);
                server_l->pipe_line_fd = ar_pipeline_ctrl_open(path);
                if(server_l->pipe_line_fd < 0) {
                    ERR("open pipeline error pipe_index=%d\n",server_l->pipe_index);
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }
                
                //[5] 开启camera控制节点
                sprintf(path, "/dev/cam_src-%d", server_l->pipe_index);
                server_l->dev->camera_fd = open(path, O_RDWR | O_SYNC);
                if(server_l->dev->camera_fd < 0){
                    ERR("open device %s failed fd=%d\n", path, server_l->dev->camera_fd);
                    server_l->dev->camera_fd = -1;
                    server_l->status = UVC_STATUS_EXIT;
                    break;
                }

                FD_ZERO(&fds);
                FD_SET(server_l->dev->fd, &fds);
                
                server_l->status = UVC_STATUS_INIT_COMPLETE;
                break;
            }
            
            case UVC_STATUS_INIT_COMPLETE:
            {
                fcc_index   = server_l->dev->fcc_index;
                format_opt  = uvc_formats[fcc_index].data->format_opt;
                for(int i = 0; i < BUFFER_COUNT; ++i){
                    if(NULL != buf_info[i]){
                        if(format_opt->release_frame(uvc_formats[fcc_index].data, buf_info[i])){ // uvc_mjpeg_release_frame
                            ERR("release buffer fail!!\n");
                        }
                        buf_info[i] = NULL;
                    }
                }
                INFO("wait playing by host!\n");
                
                ar_uvc_get_context((void**)&context, &context_size);
                while (AR_ELEMENT_STATE_PLAYING != ar_element_get_state(server_l->handle,(ar_pipeline_t)context->pipeline.element))
                {
                    //INFO("init complete and wait playing state, current state:%d\n", ar_element_get_state(server_l->handle,(ar_pipeline_t)context->pipeline.element));
                    usleep(5*1000);

                    //等待host触发开流:
                    if (STREAM_CTL_ON == server_l->g_stream_ctl_flag || UVC_CHG_FMT_CHANGE == server_l->g_chg_fmt_flag)
                    {
                        uvc_set_pts_bias(server_l->dev);
                        int ret = ar_pipeline_start_stream(server_l->handle, (ar_pipeline_t)context->pipeline.element); //NULL --> playing
                        if (0 != ret){
                            ERR("xavier, start stream failed!\n");                    
                        }
                        server_l->g_stream_ctl_flag = STREAM_CTL_IDLE;
                    }
                }
                
                if(0 != g_rgb_crop_flag){
                    ob_rgb_crop_op(server_l, true);
                }else{
                    ob_rgb_crop_op(server_l, false);
                }
     
                ar_cam_get_3a_info(server_l->dev->camera_fd, &info);
                server_l->dev->camera_terminal.exposure_time_absolute_val = info.aec_info.exp_time_us * 10000;//server_l->CT_BRIGHTNESS_DEFAULT_VAL;
                server_l->dev->camera_terminal.auto_exposure_aec_info     = info.aec_info;
                
                server_l->status = UVC_STATUS_RELEASE_FRAME;

                /* 根据酷芯微sdk要求: mjpeg的旋转参数配置在pipeline开启之后配置生效(这是与h264,265有区别的地方) */
                if ((V4L2_PIX_FMT_MJPEG == server_l->dev->new_fcc) && (V4L2_PIX_FMT_MJPEG == server_l->dev->fcc)) {
                    INFO("Mjpeg Set rotation!\n");
                    uvc_video_set_rotation(server_l->handle,server_l->rotation_angle);
                }

                INFO("UVC_STATUS_INIT_COMPLETE, AR_ELEMENT_STATE_PLAYING!!!\n\n");
                bRgbCropOpFlag = false;
                
                break;				
            }
            
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

                //触发停流
                if (STREAM_CTL_OFF == server_l->g_stream_ctl_flag) //host触发停流
                { 
                    //必须先release linux端hold的所有buff,然后再去terminal stream.
                    fcc_index   = server_l->dev->fcc_index;
                    format_opt  = uvc_formats[fcc_index].data->format_opt;
                    for(int i = 0; i < BUFFER_COUNT; ++i){
                        if(NULL != buf_info[i]){
                            if(format_opt->release_frame(uvc_formats[fcc_index].data, buf_info[i])){
                                ERR("release buffer fail!!\n");
                            }
                            buf_info[i] = NULL;
                        }
                    }
                    
                    INFO("terminal stream start.\n");
                    ret = ar_pipeline_terminal_stream(server_l->handle, (ar_pipeline_t)context->pipeline.element); //ANY --> NULL
                    if (0 != ret)                {
                        ERR("xavier, terminal stream failed!\n");                    
                        server_l->status = UVC_STATUS_EXIT;
                    }else{
                        server_l->status = UVC_STATUS_INIT_COMPLETE;
                    }
                    INFO("terminal stream end.\n");

                    while (AR_ELEMENT_STATE_NULL != ar_element_get_state(server_l->handle,(ar_pipeline_t)context->pipeline.element)){
                        INFO("wait NULL state, current state:%d\n", ar_element_get_state(server_l->handle,(ar_pipeline_t)context->pipeline.element));
                        usleep(100*1000);
                    }
                                        
                    break;
                }

                //触发分辨率/格式切换
                if(UVC_CHG_FMT_CHANGE == server_l->g_chg_fmt_flag) {  // <== uvc_events_process_data
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
                        INFO("UVC get frame success!\n");
                        get_frame_succ = 1;
                    }
                    if (buf_info[tmp_index]->len > MAX_BUFFER_SIZE)
                    {
                        ERR("error package length over max buffer size %d bytes(%d bytes)\n", MAX_BUFFER_SIZE, buf_info[tmp_index]->len);
                        ret = uvc_video_send(server_l->dev, (void *)buf_info[tmp_index]->addr, MAX_BUFFER_SIZE, buf_info[tmp_index]->pts, fds, tv);
                    }
                    else
                    {
                        server_l->dev->pts = buf_info[tmp_index]->pts;
                        server_l->dev->frame_id = buf_info[tmp_index]->frame_id;
                        ret = uvc_video_send(server_l->dev, (void *)buf_info[tmp_index]->addr, buf_info[tmp_index]->len, buf_info[tmp_index]->pts, fds, tv);
                    }
                }

                if(ret < 0){
                    //ERR("uvc_video_send failed!\n");
                }else{
                    server_l->idx++;
                }

                //触发停流
                if (STREAM_CTL_OFF == server_l->g_stream_ctl_flag)  //上位机触发停流
                {
                    //必须先release linux端hold的所有buff,然后再去terminal stream.
                    fcc_index   = server_l->dev->fcc_index;
                    format_opt  = uvc_formats[fcc_index].data->format_opt;
                    for(int i = 0; i < BUFFER_COUNT; ++i) {
                        if(NULL != buf_info[i]){
                            if(format_opt->release_frame(uvc_formats[fcc_index].data, buf_info[i])){
                                ERR("release buffer fail!!\n");
                            }
                            buf_info[i] = NULL;
                        }
                    }
                    
                    INFO("terminal stream start.\n");
                    ret = ar_pipeline_terminal_stream(server_l->handle, (ar_pipeline_t)context->pipeline.element); //ANY --> NULL
                    if (0 != ret)                {
                        ERR("xavier, terminal stream failed!\n");                    
                        server_l->status = UVC_STATUS_EXIT;
                    }else{
                        server_l->status = UVC_STATUS_INIT_COMPLETE;
                    }
                    INFO("terminal stream end.\n");

                    while (AR_ELEMENT_STATE_NULL != ar_element_get_state(server_l->handle,(ar_pipeline_t)context->pipeline.element)){
                        INFO("wait NULL state, current state:%d\n", ar_element_get_state(server_l->handle,(ar_pipeline_t)context->pipeline.element));
                        usleep(100*1000);
                    }
                    
                    break;
                }

                //触发分辨率/格式切换
                if(UVC_CHG_FMT_CHANGE == server_l->g_chg_fmt_flag){
                    server_l->status = UVC_STATUS_CHANGE_FORMAT;
                }else{
                    server_l->status = UVC_STATUS_RELEASE_FRAME;
                }

                //做裁剪缩放
                if(g_rgb_crop_flag != 0){
                    if(!bRgbCropOpFlag){
                        ob_rgb_crop_op(server_l, true);
                        bRgbCropOpFlag = true;
                    }      
                }else{
                    if(bRgbCropOpFlag){
                        ob_rgb_crop_op(server_l, false);
                        bRgbCropOpFlag = false;    
                    }      
                }          

                break;

            case UVC_STATUS_CHANGE_FORMAT:

                fcc_index   = server_l->dev->fcc_index;
                format_opt  = uvc_formats[fcc_index].data->format_opt;
                for(int i = 0; i < BUFFER_COUNT; ++i)
                {
                    if(NULL != buf_info[i]){
                        if(format_opt->release_frame(uvc_formats[fcc_index].data, buf_info[i])){ // uvc_mjpeg_release_frame
                            ERR("release buffer fail!!\n");
                        }
                        buf_info[i] = NULL;
                    }
                }
                INFO("release last stream buffer list success!\n");
                
                uvc_pipeline_set_format(server_l->dev->width, server_l->dev->height, 10000000/server_l->dev->frame_interval, server_l->dev->new_fcc);
                uvc_video_set_format(server_l->dev);

                server_l->g_chg_fmt_flag = UVC_CHG_FMT_IDLE;
                server_l->status = UVC_STATUS_INIT_COMPLETE;
                sem_post(&server_l->g_chg_fmt_sem);//==>  uvc_events_process_data
                
                break;

            case UVC_STATUS_EXIT:
            case UVC_STATUS_MAX:
            default:
                ERR("server_l->status:%d\n", server_l->status);
                goto EXIT; //fix: usb automatic disconnect if unconnected rgb sensor 
                if(1 == server_l->run_flag)
                    server_l->run_flag = 0;

                break;
        }
    }
    
    ERR("Enter Exit branch, flag:%d, status:%d\n", server_l->run_flag, server_l->status);

EXIT:
    while(NULL != buf_info[server_l->idx % BUFFER_COUNT])
    {
        struct uvc_format_opt * format_opt;
        unsigned int            fcc_index;

        fcc_index   = server_l->dev->fcc_index;
        format_opt  = uvc_formats[fcc_index].data->format_opt;

        if(format_opt->release_frame(uvc_formats[fcc_index].data, buf_info[server_l->idx % BUFFER_COUNT]))
        {
            ERR("release buffer fail!! %s line:%d\n", __func__, __LINE__);
            break;
        }

        buf_info[server_l->idx % BUFFER_COUNT] = NULL;

        server_l->idx++;
    }

    if(UVC_CHG_FMT_CHANGE == server_l->g_chg_fmt_flag)
    {
        server_l->g_chg_fmt_flag = UVC_CHG_FMT_IDLE;
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
    pthread_mutex_init(&server_l->g_uvc_frame_drop_mutex, NULL);
    sem_init(&server_l->g_chg_fmt_sem, 0, 0);
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
    server_l->width[0]   = 3840;  //默认主路分辨率
    server_l->height[0]  = 2160;
    server_l->width[1]   = 1280;  //默认辅路分辨率(默认配置客户需求分辨率)
    server_l->height[1]  = 720;
    server_l->default_man_res = 0x16; //默认配置3480*2160@30fps的setting
    server_l->multi          = 0;    //多路pipeline时需要设置为1
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
*   Prototype    : ob_host_control_callback
*   Description  : callback function
*   Input        : OB_RGB_SERVICE_CMD_EM cmd  
*                  void *data                 
*   Output       : None
*   Return Value : void *
*****************************************************************************/
void *ob_host_control_callback(OB_RGB_SERVICE_CMD_EM cmd, void *data)
{    
    uvc_server_t *pService = get_uvc_server();
    if (!pService){
        ERR("pService is NULL.\n");
        return NULL;
    } 

    zoom_pra_t zoom;
    memset(&zoom, 0, sizeof(zoom));

    switch (cmd)
    {
        case OB_SW_D2C_SWITCH:
        {        
            break;
        }
        
        case OB_CROP_OPRATION:  //客户需求i420 720p 的裁剪(包含d2c)
        {
            ob_ptz_control val = *((ob_ptz_control *)data);
            INFO("[from host] enable:%d, x:%d, y:%d, w:%d, h:%d, speed:%.2f\n", val.enable, val.x, val.y, val.width, val.height, val.speed);


            /* 机器猫16:9 D2C裁剪方案:
                 从原始分辨率3840x2160开始裁剪: 上裁剪48, 下裁剪96,
                 左右各裁剪 128，到分辨率3584x2016，再缩放到 1280x720
             */
            if (val.enable == 1) //4k算法的裁剪+客户需求裁剪 两个裁剪叠加后出1280*720
            {
                u32 x = 128 + ((3584 * val.x) / val.width);
                u32 y = 48 + ((2016 * val.y) / val.height);
                u32 width = val.width;
                u32 height = val.height;
                INFO("[3840*2160] crop x:%d, y:%d, w:%d, h:%d\n", x, y, width, height);

                if ((x + width > 3840) || (y + height) > 2160){
                    ERR("coordinates is out of range!\n");
                    break;
                } 


                zoom.manual = 1;
                zoom.digital_zoom = 1;
                zoom.stream_type  = 1; //pipeline辅路
                zoom.roi.x = (float)x/3840;
                zoom.roi.y = (float)y/2160;    
                zoom.roi.width  = (float)width/3840;
                zoom.roi.height = (float)height/2160;
                INFO("roi, x:%f, y:%f, w:%f, h:%f\n", zoom.roi.x, zoom.roi.y, zoom.roi.width, zoom.roi.height);
            }
            else  //4k仅经过算法的裁剪需求裁剪后, 直接scale出1280*720
            {
                zoom.manual = 1;   
                zoom.digital_zoom = 1;
                zoom.stream_type  = 1;       //pipeline辅路
                zoom.roi.x = 0.033333;       //x.start 128 (0.0333334) 
                zoom.roi.y = 0.022222;       //y.start 48  (0.022222223)    
                zoom.roi.width  = 0.933333;  //w 3584     (0.933333333) 
                zoom.roi.height = 0.933333;  //h 2016    (0.933333333) 
                INFO("scale to 720p!\n");
            }

            ar_cam_set_zoom(pService->dev->camera_fd, zoom);
            INFO("xavier, zoom!!!\n\n");         
            break;
        }

        case OB_RGB_TIMESTAMP_OFFSET_SET:
        {
            int val = *((int *)data);

            pService->g_uvc_time_bias = val;
            INFO("set rgb timestamp offset:%dms\n", val);
            break;
        }
            
        case OB_RGB_TIMESTAMP_OFFSET_GET:
        {
            int *pVal = (int *)data;
            *pVal = pService->g_uvc_time_bias;
            INFO("get rgb timestamp offset:%dms\n", *pVal);
            break;
        }

        default:
        {
            ERR("cmd is error, cmd:%d\n", cmd);
            break;
        }
    }

    return NULL;
}


/*****************************************************************************
*   Prototype    : ob_rgb_register_host_cmd_callback
*   Description  : register callback
*   Input        : ob_host_control_cb_for_rgb cb  
*   Output       : None
*   Return Value : static void
*****************************************************************************/
static void ob_rgb_register_host_cmd_callback(ob_host_control_cb_for_rgb cb)
{
    uvc_server_t *pService = get_uvc_server();
    if (!pService){
        ERR("pService is NULL.\n");
        return;
    } 

    if (NULL != cb)
        pService->cmd_cb = cb;
    else
       ERR("cb is NULL.\n");
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
    uvc_server_t *server_l = get_uvc_server();
	pthread_create(&thread, NULL, (void *)ob_rgb_uvc_service, NULL);

    ob_rgb_register_host_cmd_callback(ob_host_control_callback);

    return 0;
}


