#ifndef __UVC_SERVICE2_H__
#define __UVC_SERVICE2_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <semaphore.h>

#include <linux/usb/video.h>
#include <linux/videodev2.h>
#include <linux/usb/uvc.h>

#include "ar_cam_src.h"
#include "ar_meta_define.h"
#include "ar_multimedia_base.h"
#include "ar_video_stream.h"
#include "ar_picture_common_api.h"
#include "pipe_transfer_framework.h"
#include "ob_config_define.h"

#define USE_CMD_LINE_PARAM      0

#define clamp(val, min, max) ({                 \
        typeof(val) __val = (val);              \
        typeof(min) __min = (min);              \
        typeof(max) __max = (max);              \
        (void) (&__val == &__min);              \
        (void) (&__val == &__max);              \
        __val = __val < __min ? __min: __val;   \
        __val > __max ? __max: __val; })

#define ARRAY_SIZE(a)                           ((sizeof(a) / sizeof(a[0])))
#define MAX_BUFFER_SIZE                         (4 * 1024 * 1024) //uvc service中所有buff的大小(4MB)
#define BUFFER_COUNT                            (4) //hold住freeRTOS buff的数量
#define CAM_NUM_MAX                             (6) //最大自动检测/dev/videoN的数量
#define USB_30_VALUE                            (0x0300)
#define USB_20_VALUE                            (0x0200)

#define __RESOLUTION_NUM__                      256 //自动检测的分辨率个数(0-2560p)

#define __IPC_CEVA_KEY__                        (0x1234) //接收CEVA数据的key
#define __IPC_CEVA_BUF_NUM__                    BUFFER_COUNT       // >= BUFFER_COUNT

#define __IPC_LOG_KEY__                         (0x4321) //接收CEVA log的key
#define __IPC_LOG_BUF_NUM__                     BUFFER_COUNT       // >= BUFFER_COUNT

#define __OUTPUT_DEVICE_NAME__                  "dwc3"  //自动检测设备的名字
#define __OUTPUT_DEVICE_NAME2__                 "usb-"

#define __DEFAULT_HEVC_BITRATE__                (20 * 1024) //默认h265的码率(20Mbps)
#define __DEFAULT_H264_BITRATE__                (20 * 1024) //默认h264的码率(20Mbps)

#define __UVC_SINK_PATH__                       "/dev/uvc_sink-%d"  //UVC sink的格式

#define __MAX_I_FRAME_FOR_H264_START__          (1)  //每次切换h264流后发送的i帧数量
#define __MAX_I_FRAME_FOR_H265_START__          (1)  //每次切换h265流后发送的i帧数量


//自动曝光模式相关设置
#define CT_AUTO_EXPOSURE_MODE_DEFAULF_VAL       2
#define CT_AUTO_EXPOSURE_MODE_AUTO_MODE         (1 << 1)
#define CT_AUTO_EXPOSURE_MODE_SHUTTER_MODE      (1 << 2)
#define CT_AUTO_EXPOSURE_MODE_RES               (CT_AUTO_EXPOSURE_MODE_AUTO_MODE | CT_AUTO_EXPOSURE_MODE_SHUTTER_MODE)

//绝对曝光时间相关设置
#define CT_EXPOSURE_TIME_ABSOLUTE_MIN_VAL       1
#define CT_EXPOSURE_TIME_ABSOLUTE_MAX_VAL       300
#define CT_EXPOSURE_TIME_ABSOLUTE_STEP_SIZE     1

//缩放相关设置
#define CT_ZOOM_ABSOLUTE_MIN_VAL                100
#define CT_ZOOM_ABSOLUTE_MAX_VAL                200
#define CT_ZOOM_ABSOLUTE_STEP_SIZE              1
#define CT_ZOOM_ABSOLUTE_DEFAULT_VAL            100

//旋转相关设置
#define CT_ROLL_ABSOLUTE_MIN_VAL                0
#define CT_ROLL_ABSOLUTE_MAX_VAL                3
#define CT_ROLL_ABSOLUTE_STEP_SIZE              1
#define CT_ROLL_ABSOLUTE_DEFAULT_VAL            0
#define CT_ROLL_ABSOLUTE_MIRROR                 (1 << 0)
#define CT_ROLL_ABSOLUTE_FLIP                   (1 << 1)

//亮度相关设置
#define PU_BRIGHTNESS_MIN_VAL                   0
#define PU_BRIGHTNESS_MAX_VAL                   100
#define PU_BRIGHTNESS_STEP_SIZE                 1
#define PU_BRIGHTNESS_DEFAULT_VAL               50

//对比度相关设置
#define PU_CONTRAST_MIN_VAL                     0
#define PU_CONTRAST_MAX_VAL                     100
#define PU_CONTRAST_STEP_SIZE                   1
#define PU_CONTRAST_DEFAULT_VAL                 50

//色度相关设置(当前不支持)
#define PU_HUE_MIN_VAL                          0
#define PU_HUE_MAX_VAL                          100
#define PU_HUE_STEP_SIZE                        1
#define PU_HUE_DEFAULT_VAL                      50

//饱和度相关设置
#define PU_SATURATION_MIN_VAL                   0
#define PU_SATURATION_MAX_VAL                   100
#define PU_SATURATION_STEP_SIZE                 1
#define PU_SATURATION_DEFAULT_VAL               50

//锐度相关设置
#define PU_SHARPNESS_MIN_VAL                    0
#define PU_SHARPNESS_MAX_VAL                    100
#define PU_SHARPNESS_STEP_SIZE                  1
#define PU_SHARPNESS_DEFAULT_VAL                50

//伽马相关设置
#define PU_GAMMA_MIN_VAL                        0
#define PU_GAMMA_MAX_VAL                        100
#define PU_GAMMA_STEP_SIZE                      1
#define PU_GAMMA_DEFAULT_VAL                    50

//白平衡相关设置
#define PU_WHITE_BALANCE_TEMPERATURE_MIN_VAL        2800
#define PU_WHITE_BALANCE_TEMPERATURE_MAX_VAL        6800
#define PU_WHITE_BALANCE_TEMPERATURE_STEP_SIZE      1
#define PU_WHITE_BALANCE_TEMPERATURE_DEFAULT_VAL    5000
#define PU_WHITE_BALANCE_TEMPERATURE_AUTO_VAL       10

//逆光补偿相关设置(当前不支持)
#define PU_BACKLIGHT_COMPENSATION_MIN_VAL           0
#define PU_BACKLIGHT_COMPENSATION_MAX_VAL           100
#define PU_BACKLIGHT_COMPENSATION_STEP_SIZE         1
#define PU_BACKLIGHT_COMPENSATION_DEFAULT_VAL       50

//增益相关设置
#define PU_GAIN_MIN_VAL                         0
#define PU_GAIN_MAX_VAL                         255
#define PU_GAIN_STEP_SIZE                       1
#define PU_GAIN_DEFAULT_VAL                     127

//电力线频率相关设置
#define PU_POWER_LINE_FREQUENCY_MIN_VAL         0
#define PU_POWER_LINE_FREQUENCY_MAX_VAL         3
#define PU_POWER_LINE_FREQUENCY_DEFAULT_VAL     3

//自动色度相关设置(当前不支持)
#define PU_HUE_AUTO_MIN_VAL                     0
#define PU_HUE_AUTO_MAX_VAL                     255
#define PU_HUE_AUTO_STEP_SIZE                   1
#define PU_HUE_AUTO_DEFAULT_VAL                 1

//自动白平衡相关设置
#define WHITE_BALANCE_TEMPERATURE_AUTO_MIN_VAL      0
#define WHITE_BALANCE_TEMPERATURE_AUTO_MAX_VAL      1
#define WHITE_BALANCE_TEMPERATURE_AUTO_STEP_SIZE    1
#define WHITE_BALANCE_TEMPERATURE_AUTO_DEFAULT_VAL  1

typedef enum RES_MODE{
    RES_MODE_16_9,   //16:9的分辨率模式(default)
    RES_MODE_4_3,    //4:3的分辨率模式
}EM_RES_MODE;

struct uvc_frame_info
{
    unsigned int width;
    unsigned int height;
    unsigned int intervals[8];
};

struct uvc_frame_buf_info
{
    unsigned int addr;  //虚拟地址
    unsigned int len;
    uint32_t frame_id; /**< frame id */
    uint32_t pts;      /**< timestamps*/ 
    union
    {
        unsigned int index;
        void * ptr; //ar_video_stream_buffer_t or ar_picture_buffer_t
    };
};

struct raw_data_buf_info
{
    void * ptr;
    unsigned int len;
    uint32_t pts;    /**< timestamps*/
};


typedef struct uvc_format_data  uvc_format_data_t;

struct uvc_format_opt
{
    /*
        数据格式的初始化,主要是pipeline搭建和初始化(调用ar_uvc_init函数), vs_handle的获取
        以及该格式私有数据初始化(除非压缩格式外,所有格式需要设置对齐参数,对齐大小与
        MAX_BUFFER_SIZE 相同)
    */
    int (*format_init)(uvc_format_data_t *data, ar_mm_handle_t handle, int argc, char *argv[]);

    /*
        数据格式的反初始化,主要是pipeline反初始化(调用ar_uvc_deinit), vs_handle关闭
        以及该格式的私有数据销毁
    */
    int (*format_deinit)(uvc_format_data_t *data, ar_mm_handle_t handle);

    //获取一帧
    struct uvc_frame_buf_info * (*get_frame)(uvc_format_data_t *data);

    //释放一帧
    int (*release_frame)(uvc_format_data_t *data, struct uvc_frame_buf_info * buf_info);
};

struct uvc_format_data
{
    void * vs_handle; 
    struct uvc_format_opt * format_opt;
    void * priv;
};

struct uvc_format_info
{
    unsigned int fcc; //数据格式
    struct uvc_frame_info *frames;
    uvc_format_data_t *data;
};

typedef struct
{
    unsigned char           auto_exposure_mode_control;
    aec_set_info_t          auto_exposure_aec_info;
    unsigned int            exposure_time_absolute_val;
    short                   zoom_absolute_val;
    short                   roll_absolute_val;
}uvc_camera_terminal;

typedef struct
{
    unsigned int            brightness_val;
    unsigned short          contrast_val;
    unsigned int            hue_val;
    unsigned int            saturation_val;
    unsigned int            sharpness_val;
    unsigned int            gamma_val;
    unsigned int            white_balance_temperature_val;
    unsigned int            white_balance_component_val;
    unsigned int            backlight_compensation_val;
    unsigned int            gain_val;
    unsigned char           power_line_frequency_val;
    unsigned int            hue_auto_val;
    unsigned int            white_balance_temperature_auto_val;
}uvc_processing_unit;

struct uvc_device
{
    int                     fd;        //uvc fd:    "/dev/videoN"
    int                     camera_fd; //camera fd: "/dev/cam_src-%d"

    struct uvc_streaming_control probe;
    struct uvc_streaming_control commit;
    unsigned int            control_interface;   //rgb uvc control interface number
    unsigned int            streaming_interface; //rgb uvc stream interface number

    int                     control;

    struct uvc_request_data request_error_code;
    uvc_camera_terminal     camera_terminal;
    uvc_processing_unit     processing_unit;
    unsigned char           cs;
    unsigned char           entity_id;

    unsigned int            fcc;            //当前帧格式如: V4L2_PIX_FMT_MJPEG
    unsigned int            new_fcc;        //host设置新的数据格式, uvc_pipeline_set_format 中更新到fcc
    unsigned int            fcc_index;      //由 get_fcc_index 获得
    unsigned int            width;          //current w
    unsigned int            height;         //current h
    unsigned int            frame_interval; //(10000000/fps)

    void                    **mem;
    unsigned int            nbufs;
    unsigned int            bufsize;

    unsigned int            bulk;           //bulk传输模式,否则为ISOC模式
    uint8_t                 color;
    unsigned int            imgsize;
    void                    *imgdata;       //uvc发送buff

    unsigned int            pts; /*unit: ms*/
};

typedef enum
{
    UVC_STATUS_IDLE = 0,
    UVC_STATUS_INIT,
    UVC_STATUS_INIT_COMPLETE,
    UVC_STATUS_RELEASE_FRAME,
    UVC_STATUS_GET_FRAME,
    UVC_STATUS_CHANGE_FORMAT,
    UVC_STATUS_EXIT,
    UVC_STATUS_MAX
}uvc_status;


typedef struct
{
    pthread_mutex_t        g_wrt_com_mutex;
    sem_t                  g_chg_fmt_sem;
    volatile int           g_chg_fmt_flag;  //uvc分辨率切换的标志
    volatile int           g_stream_on;     //uvc stream on的标志
    unsigned long long     g_uvc_timestamp; //ms
    int                    g_uvc_time_bias; //ms(时间戳偏差)
    volatile unsigned int  idx;             //buff's index(hold rtos)
    void                  *first_image_data;
    unsigned int           first_image_size;
    void                  *g_ceva_data_buffer[BUFFER_COUNT];
    void                  *g_log_data_buffer;
    
    struct uvc_device     *dev;
    
    ar_mm_handle_t         handle;          //multimedia control
    transfer_id            trans_ceva_id;   //arm与dsp共享内存传输数据句柄
    transfer_id            trans_log_id;    //arm与dsp共享内存传输log句柄
    int                    run_flag;        //uvc run flag
    int                    dev_index;       //uvc.usb0 uvc.usb1 uvc.usb2
    int                    pipe_index;      //数据流pipeline编号, 从0开始
    int                    pipe_line_fd;    //uvc-path, /dev/uvc_path-%d
    int                    osd;             //osd显示标志
    int                    width[2];        //主路(uvc)和辅路(用于ceva)的初始化分辨率
    int                    height[2];
    int                    multi;           //多路uvc需要开启
    int                    is_hdr;
    int                    rotation_angle;  //0, 90, 180, 270
    int                    disp_w;
    int                    disp_h;
    int                    fix_fps;
    
    int                    force_isp_ddr_mode;
    struct uvc_frame_buf_info  **buf_info;  //for no use!
    unsigned int           now_format;      //for no use!
    int                    argc;
    char                 **argv;
    int                    first_inited;    //rgb uvc pipeline初始化标志
    int                    err_process;     //出错是否需要处理
    int                    hw_sync;         //是否启用hdr
    uvc_status             status;          //uvc状态机
}uvc_server_t;

struct framebased_priv_data
{
    unsigned int    i_frame_for_start;
};

extern uvc_format_data_t uvc_h265_data;
extern uvc_format_data_t uvc_h264_data;
extern uvc_format_data_t uvc_mjpeg_data;
extern uvc_format_data_t uvc_nv12_data;
extern uvc_format_data_t uvc_yuy2_data;
extern uvc_format_data_t uvc_z16_data;
extern uvc_format_data_t uvc_y16_data;
extern uvc_format_data_t uvc_y8_data;
extern uvc_format_data_t uvc_i420_data;

extern struct uvc_format_info *uvc_formats;
extern int uvc_formats_num;

uvc_server_t * get_uvc_server();


/*****************************************************************************
*   Prototype    : ob_rgb_uvc_module_init
*   Description  : rgb uvc模块初始化
*   Input        : None
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
extern int32_t ob_rgb_uvc_module_init(void);


#endif

