/******************************************************************************

  Copyright (C), 2020, orbbec Tech. Co., Ltd.

 ******************************************************************************
  File Name     : tof_stream.cpp

  Version       : 1.0.0
  Author        : Martin
  Created       : 2020/07/02
  Description   :
  History       :
  
******************************************************************************/

/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/prctl.h>
#include <sys/time.h>

#include <linux/usb/video.h>
#include <linux/videodev2.h>
#include <linux/usb/uvc.h>
#include <arm_neon.h>
extern "C"
{
#include "uvc_service2.h"
    //#include "uvc_function.h"
    //#include "uvc_configfs.h"
}

#include "utils.h"
#include "logutil.h"
#include "tof_uvc_op.h"
#include "orbbec_gadget_types.h"
#include "tof_gadget.h"
#include "tof_stream.h"
#include "message_queue.h"
#include "buff_queue.h"
#include "tof_embedded.h"
#include "obc_tof_drv.h"
#include "obc_tof_i2c.h"
#include "s5k33dxx_i2c_ctl.h"
#include "time_util.h"
#include "obc_tof_dsp_icc.h"
#include "tof_dsp_memory_map.h"
#include "ob_dsp_test.h"
#include <new>

#include "obc_sl_drv.h"
#include "softfilter.h"
#include "IProcessingBlock.hpp"
#include "ObTypes.h"
#include "d2c_arith.h"
#include "Disparity2Depth.h"

/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
#define TEST_MODE                        0
#define MX6300_ENABLE                    1
#define DSP_D2C_ENABLE                   1
#define ARM_SOFTFITER_ENABLE             0


#define BIT_TOF_STREAM_FOR_RAW_UVC       (0)
#define BIT_TOF_STREAM_FOR_DEPTH         (1)
#define BIT_TOF_STREAM_FOR_IR            (2)

#define UVC_RAW_PHASE_INTERVAL_US        (68000)
#define EXLINE_DATA_BYTE_INDEX_IN_FRAME  (1280 * 1 * 2)

#define ORBBEC_STREAM_TYPE_NONE          0
#define ORBBEC_STREAM_TYPE_DEPTH         1
#define ORBBEC_STREAM_TYPE_IR            2

#define ORBBEC_SUCCESS                   0
#define ORBBEC_FAILED                   -1

/*==============================================*
 *      struct define                           *
 *----------------------------------------------*/
// typedef struct _cam_raw_context_t
// {
//     ar_facotry_element_obj_t pipeline;
//     ar_facotry_element_obj_t cam_src;
//     ar_facotry_element_obj_t buf_sink_0;
// }cam_raw_context_t;

extern volatile param_ion_mellc_t ion_mem_info[USE_ION_MEM_NUM];

ob_streamcontrol ob_streamControl;
softfilterParam softfilter_Param;
/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/
static const char *pTofStreamManageStr[MSG_TOF_STREAM_MAX] =
    {
        "PhaseUVC request tof stream",
        "Depth request tof stream",
        "IR phase request tof stream",

        "PhaseUVC release tof stream",
        "Depth release tof stream",
        "IR phase release tof stream"};

/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/

extern "C"{
bool get_softfilter_status(void)
{
    return ob_streamControl.softfilter_Param.softfilterEnable;
}
}

/*****************************************************************************
*   Prototype    : ob_tof_stream_get_handle
*   Description  : orbbec tof stream 操作句柄建立/获取
*   Input        : void  
*   Output       : None
*   Return Value : static ob_tof_camera_handle *
*****************************************************************************/
static ob_tof_camera_handle *ob_tof_stream_get_handle(void)
{
    static ob_tof_camera_handle *pHandle = NULL;

    if (!pHandle)
    {
        WARN("pHandle is note inited, so malloc it here!\n");
        pHandle = (ob_tof_camera_handle *)malloc(sizeof(ob_tof_camera_handle));
        if (!pHandle)
        {
            ERR("memeory out!\n");
            return NULL;
        }
        memset(pHandle, 0, sizeof(ob_tof_camera_handle));
    }

    return pHandle;
}

//load still image
static void image_load(struct tof_uvc_device *dev, const char *img)
{
    int fd = -1;
    tof_uvc_service *server_l = dev->pService;

    if (img == NULL)
        return;

    fd = open(img, O_RDONLY);
    if (fd == -1)
    {
        ERR("Unable to open MJPEG image '%s'\n", img);
        return;
    }

    dev->imgsize = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    dev->imgdata = malloc(TOF_UVC_MAX_BUFFER_SIZE);
    if (dev->imgdata == NULL)
    {
        ERR("Unable to allocate memory for MJPEG image\n");
        dev->imgsize = 0;
        return;
    }

    read(fd, dev->imgdata, dev->imgsize);

    server_l->first_image_data = dev->imgdata;
    server_l->first_image_size = dev->imgsize;

    close(fd);
}
/*****************************************************************************
*   Prototype    : image_save
*   Description  : 
*   Input        : const void *p, int size, int image_count 
*   Output       : None
*   Return Value : void
*****************************************************************************/
static void image_save(const void *p, int size, int image_count)
{
    FILE *fp;
    char workDir[] = "./pic/";
    char file_name[] = "display.raw";
    static uint8_t saveCount = 0;

    if (saveCount < image_count)
    {
        uint8_t *irBuf = (uint8_t *)malloc(size);
        if (irBuf == NULL)
        {
            ERR("malloc failed!\n");
            return;
        }
        memset(irBuf, 0, size);
        snprintf(file_name, 100, "%srecord_%d.raw", workDir, saveCount);
        if (!strcmp(file_name, "-"))
        {
            fp = stdout;
        }
        else if ((fp = fopen(file_name, "w")) == NULL)
        {
            perror("Creat file failed");
            exit(0);
        }
        fwrite(p, size, 1, fp);
        fflush(fp);
        fclose(fp);
        saveCount++;
        free(irBuf);
        INFO("save %s image done!\n", file_name);
    }
}
/*****************************************************************************
*   Prototype    : ob_tof_stream_send_depth_img_thd
*   Description  : 深度或者rawphase图uvc发送测试
*   Input        : void * param  
*   Output       : None
*   Return Value : static void *
*****************************************************************************/
static void *ob_tof_stream_send_depth_img_thd(void *param)
{
    int ret = -1;
    fd_set fds;
    struct timeval tv;
    tof_uvc_service *pService = tof_uvc_gadget_get_device_handle(OB_UVC_DEVICE_NODE_NUM_DEPTH);

    //image_load(pService->dev, "/nfs_share/testdata/tof_raw_data_1280_962.raw");
    //image_load(pService->dev, "/nfs_share/testdata/480p_16bit_depth.raw");
    //image_load(pService->dev, "/usrdata/usr/data/orbbec/testdata/tof_raw_data_1280_962.raw");
    image_load(pService->dev, "/nfs_share/testdata/tof_raw_data_1280_970.raw");
    //image_load(pService->dev, "/usrdata/usr/data/orbbec/testdata/480p_16bit_depth.raw");

    tv.tv_sec = 0;
    tv.tv_usec = 10000;

    FD_ZERO(&fds);
    FD_SET(pService->dev->fd, &fds);

    while (pService->run_flag)
    {
        //ret = ob_tof_uvc_video_send(pService->dev, (void *)pService->dev->imgdata, pService->dev->imgsize, 0, fds, tv);
        ret = uvc_video_send_process(pService->dev, (void *)pService->dev->imgdata, pService->dev->imgsize, 0);
        if (ret < 0)
        {
            //ERR("uvc send failed.\n");
        }

        usleep(30 * 1000);
    }

    return NULL;
}

/*****************************************************************************
*   Prototype    : ob_tof_stream_send_ir_img_thd
*   Description  : ir图uvc发送测试
*   Input        : void * param  
*   Output       : None
*   Return Value : static void *
*****************************************************************************/
static void *ob_tof_stream_send_ir_img_thd(void *param)
{
    int ret = -1;
    fd_set fds;
    struct timeval tv;
    tof_uvc_service *pService = tof_uvc_gadget_get_device_handle(OB_UVC_DEVICE_NODE_NUM_IR);

    //image_load(pService->dev, "/nfs_share/testdata/480p_16bit_ir.raw");
    image_load(pService->dev, "/usrdata/usr/data/orbbec/testdata/480p_16bit_ir.raw");

    tv.tv_sec = 0;
    tv.tv_usec = 10000;

    FD_ZERO(&fds);
    FD_SET(pService->dev->fd, &fds);

    while (pService->run_flag)
    {
        //ret = ob_tof_uvc_video_send(pService->dev, (void *)pService->dev->imgdata, pService->dev->imgsize, 0, fds, tv);
        ret = uvc_video_send_process(pService->dev, (void *)pService->dev->imgdata, pService->dev->imgsize, 0);
        if (ret < 0)
        {
            //ERR("uvc send failed.\n");
        }

        usleep(30 * 1000);
    }

    return NULL;
}




/*****************************************************************************
*   Prototype    : ob_tof_stream_get_data_from_rtos_thd
*   Description  : camera数据流采集线程
*   Input        : void * param  
*   Output       : None
*   Return Value : static void *

*****************************************************************************/
static void *ob_tof_stream_get_data_from_rtos_thd(void *arg)
{
    int ret = 0;
    int i = 0;

    ar_picture_buffer_t *pRtosRawBuff = NULL; //采集到rtos端给的rawPhase数据buff
    ar_picture_handle sink_handle = NULL;

    struct timeval FPS_start, FPS_stop;
    double FPS_time;

    ob_tof_camera_handle *pTofCamHandle = (ob_tof_camera_handle *)arg;
    if (!pTofCamHandle)
    {
        ERR("pTofCamHandle is NULL. \n");
        return NULL;
    }

    DBG("Start capture mx6300 stream thread.\n");
    //ob_streamControl.cameraSwitchType = STREAM_TYPE_NONE;

    pTofCamHandle->buf_sink_fd = ar_picture_open("/dev/icc_proxy_rpc_sink-0");
    if (pTofCamHandle->buf_sink_fd <= 0)
    {
        ERR("open /dev/icc_proxy_rpc_sink-0 error. ret:%d\n", pTofCamHandle->buf_sink_fd);
        return NULL;
    }

    sink_handle = (ar_picture_handle)(pTofCamHandle->buf_sink_fd);
    if (!sink_handle)
    {
        ERR("handle is null. \n");
        return NULL;
    }

    ret = ar_video_stream_set_min_align_size(sink_handle, ob_streamControl.mx6300_recevieBuf_size);
    if (ret != 0)
    {
        ERR("pid %d set ar_video_stream min align failed!\n", getpid());
    }


    while(1)
    {
        sem_wait(&pTofCamHandle->semRtosCaptureStart);  // <=== ob_ir_data_process_start

        INFO("Start Capture stream!\n");
        while (pTofCamHandle->bSensorCaptureRunFlag)
        {
            //[1] capture raw data
            pRtosRawBuff = ar_picture_get_img(pTofCamHandle->buf_sink_fd); //blocking api
            if (!pRtosRawBuff)
            {
                ERR("get sink 0 buffer error\n");
                continue;
            }

            //[2] get an buff from pool to save the raw data address
            ObTofFrame *pPoolBuff = pTofCamHandle->pRawDataQueue->pool_get_buffer();
            if (NULL == pPoolBuff){
                //WARN("Dqbuff failed, maybe consumer thread is blocking.\n");
                if (ar_picture_release_img(sink_handle, pRtosRawBuff)){
                    ERR("release buffer failed\n");
                    return NULL;
                }
                continue;
            }

            if (pPoolBuff->hold_flag){
                ar_picture_release_img(sink_handle, pPoolBuff->pRawBuff); //release old buffer
                pPoolBuff->hold_flag = false;
            }
            
            //[3] save raw data
            pPoolBuff->frame_id    = pRtosRawBuff->frame_id;
            pPoolBuff->pts         = pRtosRawBuff->pts;
            pPoolBuff->width       = pRtosRawBuff->format.width;
            pPoolBuff->height      = pRtosRawBuff->format.height;
            pPoolBuff->buffer_size = pRtosRawBuff->mem[0].len;
            pPoolBuff->pRawBuff    = pRtosRawBuff;
            pPoolBuff->hold_flag   = true;

            //[4] add buff to process queue
            pTofCamHandle->pRawDataQueue->queue_push(pPoolBuff);
        } 

        INFO("Stop Capture stream!\n");

        //must release all buff(queue and pool) be holded to rtos if stop capture stream
        while(!pTofCamHandle->pRawDataQueue->queue_empty()){
            ObTofFrame *pBuff = NULL;
            pTofCamHandle->pRawDataQueue->queue_try_pop(&pBuff);            
            pTofCamHandle->pRawDataQueue->pool_put_buffer(pBuff);
        } 
        for (i = 0; i < pTofCamHandle->pRawDataQueue->pool_size(); i++){
            ObTofFrame *pBuff = pTofCamHandle->pRawDataQueue->pool_get_buffer();
            if (NULL != pBuff && pBuff->hold_flag){
                if(ar_picture_release_img(sink_handle, pBuff->pRawBuff)){
                    ERR("release buffer failed\n");
                } 
                pBuff->hold_flag = false;
            }
            pTofCamHandle->pRawDataQueue->pool_put_buffer(pBuff);
        }

        sem_post(&pTofCamHandle->semRtosCaptureStop);
        
        INFO("Exit current capture Loop and start wait next capture loop!\n");
    } 

    return NULL;
}


static void cam_raw_get_context(void **context, uint32_t *context_size)
{
    int32_t idx = 0;
    static ar_facotry_element_obj_t cam_raw_init_list[] =
        {
            {"pipeline", NULL, NULL},
            {"cam_src", NULL, NULL},
            {"icc_proxy_rpc_sink", "icc_proxy_rpc_sink-0", NULL},
        };
    *context = (void *)&cam_raw_init_list;
    *context_size = sizeof(cam_raw_init_list) / sizeof(ar_facotry_element_obj_t);

    return;
}


/*****************************************************************************
*   Prototype    : rawShift12bit
*   Description  : 
*   Input        :  
*   Output       : 
*   Return Value : 
*****************************************************************************/
static void rawShift12bit(unsigned short *pInput, unsigned int nInputSize, unsigned short *pOutput)
{
    unsigned short *pInputTmp = (uint16_t *)pInput;
    unsigned short *pOutputTmp = (uint16_t *)pOutput;
    //unsigned int num8Times = nInputSize & 0xfffffff8;  
    /*if not extenting loop by 8 times,this statement needs do corresponding modifications.   */
 
    unsigned int num32Times = nInputSize & 0xffffffe0; 
    /*if not extenting loop by 8 times,this statement needs do corresponding 
    modificatunsigned int resNum = nInputSize - num8Times;*/
    unsigned int i, j;
    unsigned char high;
    unsigned char low;
    unsigned short nIr;

    uint16x8_t u16x8_TmpVal0, u16x8_TmpVal1, u16x8_TmpVal2, u16x8_TmpVal3;
    //uint16x8_t u16x8_TmpVal4,u16x8_TmpVal5,u16x8_TmpVal6,u16x8_TmpVal9;
    //uint8x8_t u8x8_TmpVal0,u8x8_TmpVal1;
    uint16x8_t u16x8_0X0F, u16x8_0X00FF;
    uint16x8_t u16x8_Result;

    u16x8_0X0F = vdupq_n_u16(0x000F);
    u16x8_0X00FF = vdupq_n_u16(0x00FF);

    for (i = 0; i < num32Times;)
    {

        u16x8_TmpVal0 = vld1q_u16(pInputTmp + i);
        u16x8_TmpVal1 = vshlq_n_u16(vandq_u16(u16x8_TmpVal0, u16x8_0X00FF), 4);

        u16x8_TmpVal2 = vandq_u16(vshrq_n_u16(u16x8_TmpVal0, 12), u16x8_0X0F);

        u16x8_Result = vorrq_u16(u16x8_TmpVal1, u16x8_TmpVal2);

        vst1q_u16(pOutputTmp + i, u16x8_Result);

        /////////////////////////////////////////////////
        i += 8;
        u16x8_TmpVal0 = vld1q_u16(pInputTmp + i);
        u16x8_TmpVal1 = vshlq_n_u16(vandq_u16(u16x8_TmpVal0, u16x8_0X00FF), 4);

        u16x8_TmpVal2 = vandq_u16(vshrq_n_u16(u16x8_TmpVal0, 12), u16x8_0X0F);

        u16x8_Result = vorrq_u16(u16x8_TmpVal1, u16x8_TmpVal2);

        vst1q_u16(pOutputTmp + i, u16x8_Result);

        /////////////////////////////////////////////////
        i += 8;
        u16x8_TmpVal0 = vld1q_u16(pInputTmp + i);
        u16x8_TmpVal1 = vshlq_n_u16(vandq_u16(u16x8_TmpVal0, u16x8_0X00FF), 4);

        u16x8_TmpVal2 = vandq_u16(vshrq_n_u16(u16x8_TmpVal0, 12), u16x8_0X0F);

        u16x8_Result = vorrq_u16(u16x8_TmpVal1, u16x8_TmpVal2);

        vst1q_u16(pOutputTmp + i, u16x8_Result);

        /////////////////////////////////////////////////
        i += 8;
        u16x8_TmpVal0 = vld1q_u16(pInputTmp + i);
        u16x8_TmpVal1 = vshlq_n_u16(vandq_u16(u16x8_TmpVal0, u16x8_0X00FF), 4);

        u16x8_TmpVal2 = vandq_u16(vshrq_n_u16(u16x8_TmpVal0, 12), u16x8_0X0F);

        u16x8_Result = vorrq_u16(u16x8_TmpVal1, u16x8_TmpVal2);

        vst1q_u16(pOutputTmp + i, u16x8_Result);

        /////////////////////////////////////////////////
        i += 8;
    }

    for (i = num32Times; i < nInputSize; i++)
    {
        high = (unsigned char)(*(pInputTmp + i) & 0xFF);
        low = (unsigned char)((*(pInputTmp + i) >> 12) & 0x0F);
        nIr = (high << 4) | low;
        *(pOutputTmp + i) = nIr;
    }
}
/*****************************************************************************
*   Prototype    : orbbec_softfiter_process
*   Description  : 
*   Input        :  
*   Output       : 
*   Return Value : 
*****************************************************************************/
static int orbbec_softfiter_process(uint16_t *process_buf, int width,
                                    int height, uint8_t *middle_buf, uint16_t *softfiter_buf,
                                    softfilterParam softfilter_Param)
{
    if (softfiter_buf == NULL || middle_buf == NULL)
    {
        ERR("malloc softfiter_buf failed!\n");
        return ORBBEC_FAILED;
    }
    memset(middle_buf, 0, 9 * width * height);
    memset(softfiter_buf, 0, width * height);

    memcpy(softfiter_buf, process_buf, width * height * 2);

    softfilter(middle_buf, softfiter_buf, width, height,
               softfilter_Param.maxDiff, softfilter_Param.maxSpeckleSize, 1);

    memcpy(process_buf, softfiter_buf, width * height * 2);

    return ORBBEC_SUCCESS;
}
/*****************************************************************************
*   Prototype    : Disparity2DepthParam_init
*   Description  : Disparity2DepthParam_init
*   Input        : OBDepthProcessParameter *DepthProcessParameter
*   Output       : None
*   Return Value : static void *
*****************************************************************************/
static int Disparity2DepthParam_init(OBDepthProcessParameter *DepthProcessParameter)
{
    BaselineCalibrationPara BaselineCali;

    //FILE *Param_data = fopen("./BaselineCali.bin", "rb");
    FILE *Param_data = fopen(cfgParameter_960_1280, "rb");
    float sensor_fx = 0;
    if (Param_data == NULL)
    {
        INFO("calibration param file cannot be found!\n");
        DepthProcessParameter->disparityParameter_.singleParameter.fZeroPlaneDistance = 1300.0;       //Z0
        DepthProcessParameter->disparityParameter_.singleParameter.fEmitterDComsDistance = 60.0;      //baseline
        DepthProcessParameter->disparityParameter_.singleParameter.fZeroPlanePixelSize = 1300 / 1160; //ZPPS
    }
    else
    {
        // fread(&BaselineCali, sizeof(char), sizeof(BaselineCalibrationPara), Param_data);
        // DepthProcessParameter->disparityParameter_.singleParameter.fZeroPlaneDistance = BaselineCali.fZ0;
        // DepthProcessParameter->disparityParameter_.singleParameter.fEmitterDComsDistance = BaselineCali.fBaseline;
        // DepthProcessParameter->disparityParameter_.singleParameter.fZeroPlanePixelSize = BaselineCali.fZ0 / 1160; //ZPPS
        Doraemon_Content_t *doraemon_d2c_param = (Doraemon_Content_t *)malloc(sizeof(Doraemon_Content_t));
        memset(doraemon_d2c_param, 0, sizeof(doraemon_d2c_param));

        fread(doraemon_d2c_param, sizeof(char), sizeof(Doraemon_Content_t), Param_data);
        // sensor_fx=doraemon_d2c_param->soft_d2c.d_intr_p[0];

        // if (sensor_fx == 0)
        // {
        //     ERR("sensor fx is zero! setting default fx.\n");
        //     sensor_fx = 1160;
        // }
        // DepthProcessParameter->disparityParameter_.singleParameter.fZeroPlaneDistance = 1300.0;           //Z0
        // DepthProcessParameter->disparityParameter_.singleParameter.fEmitterDComsDistance = 60.0;          //baseline
        // DepthProcessParameter->disparityParameter_.singleParameter.fZeroPlanePixelSize = 1300 / sensor_fx; //ZPPS
        DepthProcessParameter->disparityParameter_.singleParameter.fZeroPlaneDistance =
            doraemon_d2c_param->disparity2depthparams.fZeroPlaneDistance;
        DepthProcessParameter->disparityParameter_.singleParameter.fEmitterDComsDistance =
            doraemon_d2c_param->disparity2depthparams.fEmitterDComsDistance;
        DepthProcessParameter->disparityParameter_.singleParameter.fZeroPlanePixelSize =
            doraemon_d2c_param->disparity2depthparams.fZeroPlanePixelSize;
        // INFO("------------Z0:%f,baseline:%f,ZPPS:%f\n",
        //      DepthProcessParameter->disparityParameter_.singleParameter.fZeroPlaneDistance,
        //      DepthProcessParameter->disparityParameter_.singleParameter.fEmitterDComsDistance,
        //      DepthProcessParameter->disparityParameter_.singleParameter.fZeroPlanePixelSize);
        fclose(Param_data);
        free(doraemon_d2c_param);
    }
    DepthProcessParameter->disparityParameter_.singleParameter.nParamCoeff = 8;   //12bit
    DepthProcessParameter->disparityParameter_.singleParameter.nConstShift = 200; //const
    DepthProcessParameter->disparityParameter_.singleParameter.minDepthValue = ob_streamControl.depth_MinValue;
    DepthProcessParameter->disparityParameter_.singleParameter.maxDepthValue = ob_streamControl.depth_MaxValue;
    DepthProcessParameter->disparityParameter_.singleParameter.nPixelSizeFactor = 1; //const
    DepthProcessParameter->disparityParameter_.singleParameter.nShiftScale = 1;      //1:mm
    DepthProcessParameter->isDualCamera = false;
}

/*****************************************************************************
*   Prototype    : ob_mx6300_depth_stream_process_thd
*   Description  : mx6300 depth process
*   Input        : void * param  
*   Output       : None
*   Return Value : static void *
*****************************************************************************/
static void *ob_mx6300_depth_stream_process_thd(void *arg)
{
    fd_set fds;
    struct timeval tv;
    uint64_t t1,t2,t3,t4;
    int timestamp = 0;
    tof_uvc_service *pService = tof_uvc_gadget_get_device_handle(OB_UVC_DEVICE_NODE_NUM_DEPTH);
    uint32_t depthBuf_length;

    ob_tof_camera_handle *pHandler = (ob_tof_camera_handle *)arg;
    if (!pHandler) {
        ERR("pHandler is NULL!\n");
        return NULL;
    }

    uint8_t depth_loopCount = 0;

    tv.tv_sec = 0;
    tv.tv_usec = 10000;

    FD_ZERO(&fds);
    FD_SET(pService->dev->fd, &fds);

    uint32_t depthBuf_width = 960;
    uint32_t depthBuf_height = 1280;

    //ob_streamControl.depth_inputImage_width = 1024;
    //ob_streamControl.depth_inputImage_height = 1280;
    
    ob_streamControl.depth_MinValue = 450;
    ob_streamControl.depth_MaxValue = 3500;

    // ob_streamControl.depthSoftD2C_enable = 1;//这个由上位机下发

    OBDepthProcessParameter *DepthProcessParameter =
        (OBDepthProcessParameter *)malloc(sizeof(OBDepthProcessParameter));
    if (DepthProcessParameter == NULL)
    {
        ERR("DepthProcessParameter malloc failed!\n");
        return NULL;
    }
    Disparity2DepthParam_init(DepthProcessParameter);

    libobsensor::Disparity2Depth *ob_Disparity2Depth =
        new libobsensor::Disparity2Depth(DepthProcessParameter->disparityParameter_,
                                         DepthProcessParameter->isDualCamera);
    if (ob_Disparity2Depth == NULL)
    {
        ERR("ob_Disparity2Depth malloc failed!\n");
        return NULL;
    }
    ob_Disparity2Depth->init(OB_FORMAT_NV12);


#if ARM_SOFTFITER_ENABLE
    uint8_t *middle_buf = (uint8_t *)malloc(9 * depthBuf_width * depthBuf_height);
    if (middle_buf == NULL)
    {
        ERR("malloc middle_buf failed!\n");
        return NULL;
    }
    memset(middle_buf, 0, depthBuf_width * depthBuf_height * 2);
    uint16_t *softfiter_buf = (uint16_t *)malloc(depthBuf_width * depthBuf_height * 2);
    if (softfiter_buf == NULL)
    {
        ERR("malloc softfiter_buf failed!\n");
        return NULL;
    }
    memset(softfiter_buf, 0, depthBuf_width * depthBuf_height * 2);

    OBIR2DISP_VER version;
    version = postflt_version();
    INFO("softfilter version:%d.%d.%d.%d\n", version.major, version.minor, version.maintenance, version.build);
#endif


    sem_wait(&pHandler->semDepthConsumeProcessStart);

    uint32_t depth_in_w = ob_streamControl.depth_inputImage_width;
    uint32_t depth_in_h = ob_streamControl.depth_inputImage_height;
    uint32_t depth_out_w = ob_streamControl.depth_ouputImage_width;
    uint32_t depth_out_h = ob_streamControl.depth_ouputImage_height;
    uint32_t depth_in_len = depth_in_w * depth_in_h * 2;
    uint32_t depth_out_len = depth_out_w * depth_out_h * 2;

    INFO("curr depth_in format:%d(w) * %d(h)\n",depth_in_w, depth_in_h);
    INFO("curr uvc_send format:%d(w) * %d(h)\n",depth_out_w, depth_out_h);

    param_ion_mellc_t *depthBuf_0 = (param_ion_mellc_t *)&ion_mem_info[D2C_input_buf_0];
    param_ion_mellc_t *depthBuf_1 = (param_ion_mellc_t *)&ion_mem_info[D2C_input_buf_1];
    param_ion_mellc_t *depthBuf_2 = (param_ion_mellc_t *)&ion_mem_info[D2C_input_buf_2];
    param_ion_mellc_t *depthBuf_3 = (param_ion_mellc_t *)&ion_mem_info[D2C_input_buf_3];


    ar_picture_buffer_t *depth_queue = (ar_picture_buffer_t *)malloc(sizeof(ar_picture_buffer_t));
    if (depth_queue == NULL)
    {
        ERR("depth_queue malloc error!\n");
        return NULL;
    }
    memset(depth_queue, 0, sizeof(ar_picture_buffer_t));


    while (pHandler->bDepthConsumeRunFlag)
    {
        // gettimeofday(&tv, NULL);
        // t1 = tv.tv_sec * 1000000ULL + tv.tv_usec;

        ObTofFrame *pFrame = pHandler->pRawDataQueue->queue_wait_and_pop();
        u32 pts = pFrame->pts;

        if (pFrame->pRawBuff->mem[0].len > 0)
        {
            /*视差转深度*/
            uint8_t *DisparityBuf = (uint8_t *)pFrame->pRawBuff->mem[0].addr;//视差直接从rtosbuffer中拿
#if 1 // 使用老的查找表
            switch (depth_loopCount)
            {
                case 0:
                    ob_Disparity2Depth->depth_processFrame((uint16_t *)DisparityBuf,
                                                        (uint16_t *)depthBuf_0->va, depth_in_len);
                    depth_queue->mem[0].addr = (uint32_t)depthBuf_0;
                    depth_queue->mem[0].len = depth_in_len;
                    depth_loopCount = 1;
                    break;
                case 1:
                    ob_Disparity2Depth->depth_processFrame((uint16_t *)DisparityBuf,
                                                        (uint16_t *)depthBuf_1->va, depth_in_len);
                    depth_queue->mem[0].addr = (uint32_t)depthBuf_1;
                    depth_queue->mem[0].len = depth_in_len;
                    depth_loopCount = 2;
                    break;
                case 2:
                    ob_Disparity2Depth->depth_processFrame((uint16_t *)DisparityBuf,
                                                        (uint16_t *)depthBuf_2->va, depth_in_len);
                    depth_queue->mem[0].addr = (uint32_t)depthBuf_2;
                    depth_queue->mem[0].len = depth_in_len;
                    depth_loopCount = 3;
                    break;
                case 3:
                    ob_Disparity2Depth->depth_processFrame((uint16_t *)DisparityBuf,
                                                        (uint16_t *)depthBuf_3->va, depth_in_len);
                    depth_queue->mem[0].addr = (uint32_t)depthBuf_3;
                    depth_queue->mem[0].len = depth_in_len;
                    depth_loopCount = 0;
                    break;
                default:
                    break;
            }

#else // 使用新的视差计算方法
            pParaHandle Pdpara = get_disparity2depthPara_handle();
            Pdpara->nMaxDepth = 8000;//如需修改直接在这里修改参数
            // Dispar2Depth((uint16_t *)(pFrame->pRawBuff->mem[0].addr), depth_in_len/2, (uint16_t *)depthBuf);
            Disparity2Depth_ArmNeon((uint16_t *)(pFrame->pRawBuff->mem[0].addr), depth_in_len/2, (uint16_t *)depthBuf);
#endif       
            ObTofFrame *pPoolBuff = pHandler->pDSPQueue->pool_get_buffer();
            if (NULL != pPoolBuff)
            {
                pPoolBuff->pRawBuff = depth_queue;
                pPoolBuff->frame_id = pFrame->frame_id;
                pPoolBuff->pts = pts;
                pPoolBuff->width = pFrame->width;
                pPoolBuff->height = pFrame->height;
                pPoolBuff->buffer_size = pFrame->buffer_size;
                pPoolBuff->hold_flag = true;
                pHandler->pDSPQueue->queue_push(pPoolBuff);
            }
        }
        pHandler->pRawDataQueue->pool_put_buffer(pFrame); //==> ob_tof_stream_get_data_from_rtos_thd
    }

    //put all buff to pool
    while (!pHandler->pDSPQueue->queue_empty())
    {
        ObTofFrame *pBuff = NULL;
        pHandler->pDSPQueue->queue_try_pop(&pBuff);
        pHandler->pDSPQueue->pool_put_buffer(pBuff);
    }

    free(depth_queue);

    free(DepthProcessParameter);
#if ARM_SOFTFITER_ENABLE
    free(middle_buf);
    free(softfiter_buf);
#endif

    delete(ob_Disparity2Depth);

    INFO("Exit Depth data consume process thread.\n");
    pthread_exit(NULL);
}
/*****************************************************************************
*   Prototype    : ob_mx6300_depth_dsp_process_thd
*   Description  : dsp process
*   Input        : void * param  
*   Output       : None
*   Return Value : static void *
*****************************************************************************/
static void *ob_mx6300_depth_dsp_process_thd(void *arg)
{
    ob_tof_camera_handle *pHandler = (ob_tof_camera_handle *)arg;
    if (!pHandler)
    {
        ERR("pHandler is NULL!\n");
        return NULL;
    }
    tof_uvc_service *pService = tof_uvc_gadget_get_device_handle(OB_UVC_DEVICE_NODE_NUM_DEPTH);

    uint32_t depth_in_w = ob_streamControl.depth_inputImage_width;
    uint32_t depth_in_h = ob_streamControl.depth_inputImage_height;
    uint32_t depth_out_w = ob_streamControl.depth_ouputImage_width;
    uint32_t depth_out_h = ob_streamControl.depth_ouputImage_height;
    uint32_t depth_in_len = depth_in_w * depth_in_h * 2;
    uint32_t depth_out_len = depth_out_w * depth_out_h * 2;

    param_ion_mellc_t *D2C_buf = (param_ion_mellc_t *)&ion_mem_info[TOF_depth1_MEM];

    param_ion_mellc_t *dspBuf_0 = (param_ion_mellc_t *)&ion_mem_info[DSP_input_buf_0];
    param_ion_mellc_t *dspBuf_1 = (param_ion_mellc_t *)&ion_mem_info[DSP_input_buf_1];
    param_ion_mellc_t *dspBuf_2 = (param_ion_mellc_t *)&ion_mem_info[DSP_input_buf_2];
    param_ion_mellc_t *dspBuf_3 = (param_ion_mellc_t *)&ion_mem_info[DSP_input_buf_3];

    uint8_t dsp_loopCount = 0;
    u32 pts = 0;

    sem_wait(&pHandler->semDepthDSPProcessStart);

    ar_picture_buffer_t *dsp_queue = (ar_picture_buffer_t *)malloc(sizeof(ar_picture_buffer_t));
    if (dsp_queue == NULL)
    {
        ERR("dsp_queue malloc error!\n");
        return NULL;
    }
    memset(dsp_queue, 0, sizeof(ar_picture_buffer_t));

    while (pHandler->bDepthDSPRunFlag)
    {
        ObTofFrame *pFrame = pHandler->pDSPQueue->queue_wait_and_pop();
        pts = pFrame->pts;

        if (pFrame->pRawBuff->mem[0].len > 0)
        {
            param_ion_mellc_t *ion_mem = (param_ion_mellc_t *)pFrame->pRawBuff->mem[0].addr;

            switch (dsp_loopCount)
            {
                case 0:
                    if (!(ob_streamControl.softfilter_Param.softfilterEnable) &&
                        !(ob_streamControl.depthSoftD2C_enable))
                    {
                        dspBuf_0 = ion_mem;
                    }
                    else
                    {
                        ob_dsp_data_process(ion_mem, depth_in_w, depth_in_h,
                                            dspBuf_0, depth_out_w, depth_out_h);
                    }
                    dsp_queue->mem[0].addr = (uint32_t)dspBuf_0;
                    dsp_queue->mem[0].len = depth_in_len;
                    dsp_loopCount = 1;
                    break;
                case 1:
                    if (!(ob_streamControl.softfilter_Param.softfilterEnable) &&
                        !(ob_streamControl.depthSoftD2C_enable))
                    {
                        dspBuf_1 = ion_mem;
                    }
                    else
                    {
                        ob_dsp_data_process(ion_mem, depth_in_w, depth_in_h,
                                            dspBuf_1, depth_out_w, depth_out_h);
                    }
                    dsp_queue->mem[0].addr = (uint32_t)dspBuf_1;
                    dsp_queue->mem[0].len = depth_in_len;
                    dsp_loopCount = 2;
                    break;
                case 2:
                    if (!(ob_streamControl.softfilter_Param.softfilterEnable) &&
                        !(ob_streamControl.depthSoftD2C_enable))
                    {
                        dspBuf_2 = ion_mem;
                    }
                    else
                    {
                        ob_dsp_data_process(ion_mem, depth_in_w, depth_in_h,
                                            dspBuf_2, depth_out_w, depth_out_h);
                    }
                    dsp_queue->mem[0].addr = (uint32_t)dspBuf_2;
                    dsp_queue->mem[0].len = depth_in_len;
                    dsp_loopCount = 3;
                    break;
                case 3:
                    if (!(ob_streamControl.softfilter_Param.softfilterEnable) &&
                        !(ob_streamControl.depthSoftD2C_enable))
                    {
                        dspBuf_3 = ion_mem;
                    }
                    else
                    {
                        ob_dsp_data_process(ion_mem, depth_in_w, depth_in_h,
                                            dspBuf_3, depth_out_w, depth_out_h);
                    }
                    dsp_queue->mem[0].addr = (uint32_t)dspBuf_3;
                    dsp_queue->mem[0].len = depth_in_len;
                    dsp_loopCount = 0;
                    break;
                default:
                    break;
            }

            ObTofFrame *pPoolBuff = pHandler->pUVCQueue->pool_get_buffer();
            if (NULL != pPoolBuff)
            {
                pPoolBuff->pRawBuff = dsp_queue;
                pPoolBuff->frame_id = pFrame->frame_id;
                pPoolBuff->pts = pts;
                pPoolBuff->width = pFrame->width;
                pPoolBuff->height = pFrame->height;
                pPoolBuff->buffer_size = pFrame->buffer_size;
                pPoolBuff->hold_flag = true;
                pHandler->pUVCQueue->queue_push(pPoolBuff);
            }            
        }
        pHandler->pDSPQueue->pool_put_buffer(pFrame);
    }
    while (!pHandler->pUVCQueue->queue_empty())
    {
        ObTofFrame *pBuff = NULL;
        pHandler->pUVCQueue->queue_try_pop(&pBuff);
        pHandler->pUVCQueue->pool_put_buffer(pBuff);
    }

    free(dsp_queue);
    return NULL;
}
/*****************************************************************************
*   Prototype    : ob_mx6300_depth_uvc_process_thd
*   Description  : mx6300 depth process
*   Input        : void * param  
*   Output       : None
*   Return Value : static void *
*****************************************************************************/
static void *ob_mx6300_depth_uvc_process_thd(void *arg)
{
    ob_tof_camera_handle *pHandler = (ob_tof_camera_handle *)arg;
    if (!pHandler)
    {
        ERR("pHandler is NULL!\n");
        return NULL;
    }
    tof_uvc_service *pService = tof_uvc_gadget_get_device_handle(OB_UVC_DEVICE_NODE_NUM_DEPTH);

    uint32_t depth_in_w = ob_streamControl.depth_inputImage_width;
    uint32_t depth_in_h = ob_streamControl.depth_inputImage_height;
    uint32_t depth_out_w = ob_streamControl.depth_ouputImage_width;
    uint32_t depth_out_h = ob_streamControl.depth_ouputImage_height;
    uint32_t depth_in_len = depth_in_w * depth_in_h * 2;
    uint32_t depth_out_len = depth_out_w * depth_out_h * 2;

    param_ion_mellc_t *D2C_buf = (param_ion_mellc_t *)&ion_mem_info[TOF_depth1_MEM];   

    sem_wait(&pHandler->semDepthUVCProcessStart);
    u32 pts = 0;

    while (pHandler->bDepthUVCRunFlag)
    {
        ObTofFrame *pFrame = pHandler->pUVCQueue->queue_wait_and_pop();
        pts = pFrame->pts;

        param_ion_mellc_t *ion_mem = (param_ion_mellc_t *)pFrame->pRawBuff->mem[0].addr;

        if (uvc_video_send_process(pService->dev, ion_mem->va, depth_out_len, pts) < 0)
        {
            ERR("uvc send depth data failed.\n");
        }

        pHandler->pUVCQueue->pool_put_buffer(pFrame);
    }
    return NULL;
}
/*****************************************************************************
*   Prototype    : ob_mx6300_ir_stream_process_thd
*   Description  : mx6300 depth process
*   Input        : void * param  
*   Output       : None
*   Return Value : static void *
*****************************************************************************/
static void *ob_mx6300_ir_stream_process_thd(void *arg)
{
    fd_set fds;
    struct timeval tv;
    int timestamp = 0;

    struct timeval FPS_start, FPS_stop;
    double FPS_time;

    tof_uvc_service *pService = tof_uvc_gadget_get_device_handle(OB_UVC_DEVICE_NODE_NUM_IR);    
    ob_tof_camera_handle *pHandler = (ob_tof_camera_handle *)arg;
    if (!pHandler) {
        ERR("pHandler is NULL!\n");
        return NULL;
    }

    INFO("Enter orbbec mx6300 ir process thread!\n");

    tv.tv_sec = 0;
    tv.tv_usec = 10000;

    FD_ZERO(&fds);
    FD_SET(pService->dev->fd, &fds);

#if 0
    uint32_t irBuf_width = 1280;
    uint32_t irBuf_height = 1024;

    //ob_streamControl.irImage_width = 1280;
    //ob_streamControl.irImage_height = 1024;

    uint8_t *irBuf = (uint8_t *)malloc(irBuf_width * irBuf_height * 2);
    if (irBuf == NULL)
    {
        ERR("malloc failed!\n");
        return NULL;
    }
    memset(irBuf, 0, irBuf_width * irBuf_height * 2);
#endif

    sem_wait(&pHandler->semIRConsumeProcessStart);

    while (pHandler->bIRConsumeRunFlag)
    {
        ObTofFrame *pFrame = pHandler->pRawDataQueue->queue_wait_and_pop();

        if (uvc_video_send_process(pService->dev, (void *)(pFrame->pRawBuff->mem[0].addr),
                                   pFrame->pRawBuff->mem[0].len, pFrame->pRawBuff->pts) < 0)
        {
            //ERR("uvc send ir data failed.\n");
        }

        pHandler->pRawDataQueue->pool_put_buffer(pFrame); //==> ob_tof_stream_get_data_from_rtos_thd
    }

    INFO("Exit ir data consume process thread.\n");
    pthread_exit(NULL);
}


/*****************************************************************************
*   Prototype    : ob_ir_data_process_start
*   Description  : IR data consume start
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_ir_data_process_start(void)
{
    ob_tof_camera_handle *pHandle = ob_tof_stream_get_handle();
    if (!pHandle){
        ERR("pHandle is NULL.\n");
        return -1;
    }

    pthread_mutex_lock(&pHandle->op_mutex);

    if (pHandle->bIRConsumeRunFlag){
        WARN("is already start\n");
        return -1;
    }

    //[1] 启动消费端
    start_new_thread_join("ir process thread", &pHandle->IRConsumeThdId,
                          ob_mx6300_ir_stream_process_thd, (void *)pHandle);
    pHandle->bIRConsumeRunFlag = true;
    sem_post(&pHandle->semIRConsumeProcessStart);

    //[2] 启动生产端
    pHandle->bSensorCaptureRunFlag = true;
    sem_post(&pHandle->semRtosCaptureStart); // ==> ob_tof_stream_get_data_from_rtos_thd

    DBG("Star IR stream Done!\n");
    pthread_mutex_unlock(&pHandle->op_mutex);

    return 0;
}


/*****************************************************************************
*   Prototype    : ob_ir_data_process_stop
*   Description  : ir data consume stop
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_ir_data_process_stop(void)
{
    ob_tof_camera_handle *pHandle = ob_tof_stream_get_handle();
    if (!pHandle){
        ERR("pHandle is NULL.\n");
        return -1;
    }

    pthread_mutex_lock(&pHandle->op_mutex);

    if (!pHandle->bIRConsumeRunFlag){
        WARN("is already stop\n");
        return -1;
    }

    //[1] 停止消费
    pHandle->bIRConsumeRunFlag = false;  //==> ob_mx6300_ir_stream_process_thd
    if (0 != pHandle->IRConsumeThdId){
        pthread_join(pHandle->IRConsumeThdId, NULL);
        pHandle->IRConsumeThdId = 0;    
    }

    //[2]停止流采集
    pHandle->bSensorCaptureRunFlag = false; // ==> ob_tof_stream_get_data_from_rtos_thd
    sem_wait(&pHandle->semRtosCaptureStop); 
    
    DBG("Stop IR Preview Done!\n");
    pthread_mutex_unlock(&pHandle->op_mutex);

    return 0;
}


/*****************************************************************************
*   Prototype    : ob_depth_data_process_start
*   Description  : Depth data consume start
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_depth_data_process_start(void)
{
    ob_tof_camera_handle *pHandle = ob_tof_stream_get_handle();
    if (!pHandle){
        ERR("pHandle is NULL.\n");
        return -1;
    }

    pthread_mutex_lock(&pHandle->op_mutex);

    if (pHandle->bDepthConsumeRunFlag){
        WARN("is already start\n");
        return -1;
    }

    //[1] -------depth data consume thread create-------
    start_new_thread_join("depth UVC thread", &pHandle->DepthUVCThdId,
                          ob_mx6300_depth_uvc_process_thd, (void *)pHandle);
    pHandle->bDepthUVCRunFlag = true;
    sem_post(&pHandle->semDepthUVCProcessStart);

    //[1] -------depth data consume thread create-------
    start_new_thread_join("depth DSP thread", &pHandle->DepthDSPThdId,
                          ob_mx6300_depth_dsp_process_thd, (void *)pHandle);
    pHandle->bDepthDSPRunFlag = true;
    sem_post(&pHandle->semDepthDSPProcessStart);

    //[2] -------depth data consume thread create-------
    start_new_thread_join("depth process thread", &pHandle->DepthConsumeThdId,
                          ob_mx6300_depth_stream_process_thd, (void *)pHandle);
    pHandle->bDepthConsumeRunFlag = true;
    sem_post(&pHandle->semDepthConsumeProcessStart);

    //[3]启动生产端
    pHandle->bSensorCaptureRunFlag = true;
    sem_post(&pHandle->semRtosCaptureStart); // ==> ob_tof_stream_get_data_from_rtos_thd

    DBG("Star Depth stream Done!\n");
    pthread_mutex_unlock(&pHandle->op_mutex);

    return 0;
}


/*****************************************************************************
*   Prototype    : ob_depth_data_process_stop
*   Description  : depth data consume stop
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_depth_data_process_stop(void)
{
    ob_tof_camera_handle *pHandle = ob_tof_stream_get_handle();
    if (!pHandle){
        ERR("pHandle is NULL.\n");
        return -1;
    }

    pthread_mutex_lock(&pHandle->op_mutex);

    if (!pHandle->bDepthConsumeRunFlag){
        WARN("is already stop\n");
        return -1;
    }

    //[1]停止depth uvc消费
    pHandle->bDepthUVCRunFlag = false;   //==> ob_mx6300_depth_uvc_process_thd
    if (0 != pHandle->DepthUVCThdId){
        pthread_join(pHandle->DepthUVCThdId, NULL);
        pHandle->DepthUVCThdId = 0;
    }

    //[2]停止depth dsp消费
    pHandle->bDepthDSPRunFlag = false;   //==> ob_mx6300_depth_dsp_process_thd
    if (0 != pHandle->DepthDSPThdId){
        pthread_join(pHandle->DepthDSPThdId, NULL);
        pHandle->DepthDSPThdId = 0;
    }

    //[3]停止depth消费
    pHandle->bDepthConsumeRunFlag = false;  //==> ob_mx6300_depth_stream_process_thd
    if (0 != pHandle->DepthConsumeThdId){
        pthread_join(pHandle->DepthConsumeThdId, NULL);
        pHandle->DepthConsumeThdId = 0;
    }
    
    //[4]停止流采集
    pHandle->bSensorCaptureRunFlag = false; // ==> ob_tof_stream_get_data_from_rtos_thd
    sem_wait(&pHandle->semRtosCaptureStop);

    DBG("Stop Depth Preview Done!\n");
    pthread_mutex_unlock(&pHandle->op_mutex);

    return 0;
}


/*****************************************************************************
*   Prototype    : ob_mx6300_init
*   Description  : 
*   Input        :  
*   Output       : 
*   Return Value : int32_t
*****************************************************************************/
static int32_t ob_mx6300_init(void)
{
    sl_usr_cfg_ppl_t sl_usr_cfg;
    sl_usr_cfg.cam_id = 0;
    //sl_usr_cfg.stream_type = STREAM_IR;
    sl_usr_cfg.stream_type = STREAM_DEPTH;
    sl_usr_cfg.input_vidio_res.width = 960;
    sl_usr_cfg.input_vidio_res.height = 1280;
    sl_usr_cfg.subsample_rate = 15;
    sl_usr_cfg.fps = 30;

    if (init_sl_cam(&sl_usr_cfg) < 0) //init mx6300
    {
        ERR("mx6300 init failed!\n");
        return ORBBEC_FAILED;
    }
    return ORBBEC_SUCCESS;
}


/*****************************************************************************
*   Prototype    : ob_tof_stream_module_init
*   Description  : tof 数据流模块初始化
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_tof_stream_module_init(void)
{
    ob_tof_camera_handle *pHandle = ob_tof_stream_get_handle();
    if (!pHandle)
    {
        ERR("pHandle is NULL.\n");
        return ORBBEC_FAILED;
    }

    pHandle->pMsgQueue = new (std::nothrow) MessageQueue<TOF_STREAM_MSG_ID>();
    if (!pHandle->pMsgQueue)
    {
        ERR("pMsgQueue is NULL.\n");
        return ORBBEC_FAILED;
    }

    pthread_mutex_init(&pHandle->op_mutex, NULL);

    //生产端控制变量
    pHandle->bSensorCaptureRunFlag = false;
    sem_init(&pHandle->semRtosCaptureStart, 0, 0);
    sem_init(&pHandle->semRtosCaptureStop, 0, 0);

    //IR消费端控制变量
    pHandle->bIRConsumeRunFlag = false;
    pHandle->IRConsumeThdId = 0;
	sem_init(&pHandle->semIRConsumeProcessStart, 0, 0);

    //Depth消费端控制变量
    pHandle->bDepthConsumeRunFlag = false;
    pHandle->DepthConsumeThdId = 0;
	sem_init(&pHandle->semDepthConsumeProcessStart, 0, 0);

    //Depth dsp消费
    pHandle->bDepthDSPRunFlag = false;
    pHandle->DepthDSPThdId = 0;
	sem_init(&pHandle->semDepthDSPProcessStart, 0, 0);

    //Depth uvc消费
    pHandle->bDepthUVCRunFlag = false;
    pHandle->DepthUVCThdId = 0;
	sem_init(&pHandle->semDepthUVCProcessStart, 0, 0);


    //pthread_mutex_init(&pHandle->mutex_group_opt, NULL);
    //pHandle->pGroupOpt = &ob_tof_group_op;
    //pHandle->pGroupOpt->init_group(); //ob_tof_init_group_queue

    //malloc buff pool
    pHandle->pRawDataQueue = CommonQueue<ObTofFrame>::create(4, 4);
    if (NULL == pHandle->pRawDataQueue)
    {
        ERR("Create pBuffQueue failed.\n");
        return ORBBEC_FAILED;
    }
    for (int i = 0; i < pHandle->pRawDataQueue->pool_size(); i++)
    {
        ObTofFrame *pBuff = pHandle->pRawDataQueue->pool_get_buffer();
        pBuff->hold_flag = false;
        pHandle->pRawDataQueue->pool_put_buffer(pBuff);
    }

    pHandle->pDSPQueue = CommonQueue<ObTofFrame>::create(4, 4);
    if (NULL == pHandle->pDSPQueue)
    {
        ERR("Create pDSPQueue failed.\n");
        return ORBBEC_FAILED;
    }
    for (int i = 0; i < pHandle->pDSPQueue->pool_size(); i++)
    {
        ObTofFrame *pBuff = pHandle->pDSPQueue->pool_get_buffer();
        pBuff->hold_flag = false;
        pHandle->pDSPQueue->pool_put_buffer(pBuff);
    }

    pHandle->pUVCQueue = CommonQueue<ObTofFrame>::create(4, 4);
    if (NULL == pHandle->pUVCQueue)
    {
        ERR("Create pUVCQueue failed.\n");
        return ORBBEC_FAILED;
    }
    for (int i = 0; i < pHandle->pUVCQueue->pool_size(); i++)
    {
        ObTofFrame *pBuff = pHandle->pUVCQueue->pool_get_buffer();
        pBuff->hold_flag = false;
        pHandle->pUVCQueue->pool_put_buffer(pBuff);
    }

#if DSP_D2C_ENABLE

    ob_streamControl.d2c_pixFormat.color_width = 960;
    ob_streamControl.d2c_pixFormat.color_height = 1280;
    ob_streamControl.d2c_pixFormat.depth_width = 960;
    ob_streamControl.d2c_pixFormat.depth_height = 1280;

    ob_streamControl.depthSoftD2C_enable = true;

    ob_streamControl.softfilter_Param.maxDiff = 120;
    ob_streamControl.softfilter_Param.maxSpeckleSize = 800;
    ob_streamControl.softfilter_Param.softfilterEnable = true;

    ob_dsp_init(ob_streamControl.d2c_pixFormat,
                ob_streamControl.depthSoftD2C_enable, ob_streamControl.softfilter_Param);
#endif

#if MX6300_ENABLE
    if (ob_mx6300_init() < 0) //init mx6300
    {
        ERR("mx6300 init failed!\n");
        return ORBBEC_FAILED;
    }
#endif

    ob_streamControl.irStopStream = false;
    ob_streamControl.depthStopStream = false;
    ob_streamControl.typeSwitch_Enable = false;
    ob_streamControl.mx6300_recevieBuf_size = 960 * 1280 * 2;
    ob_streamControl.mx6300_stream_type = ORBBEC_STREAM_TYPE_NONE;

    //start_new_thread("capture tof stream thread", NULL, ob_tof_stream_msg_process_thd, (void *)pHandle);
    //start_new_thread("tof data process thread", NULL, ob_tof_stream_rawdata_process_thd, (void *)pHandle);
    start_new_thread("tof stream capture thread", NULL, ob_tof_stream_get_data_from_rtos_thd, (void *)pHandle);
    //start_new_thread("Test Depth Data send thread", NULL, ob_tof_stream_send_depth_img_thd, (void *)pHandle);
    //start_new_thread("Test IR Data send thread", NULL, ob_tof_stream_send_ir_img_thd, (void *)pHandle);
    //start_new_thread("mx6300 depth stream capture thread", NULL, ob_mx6300_depth_stream_process_thd, (void *)pHandle);
    //start_new_thread("mx6300 ir stream capture thread", NULL, ob_mx6300_ir_stream_process_thd, (void *)pHandle); 

    return ORBBEC_SUCCESS;
}


/*****************************************************************************
*   Prototype    : ob_tof_stream_module_uninit
*   Description  : tof 数据流模块去初始化
*   Input        : void  
*   Output       : None
*   Return Value : int32_t
*****************************************************************************/
int32_t ob_tof_stream_module_uninit(void)
{
    ob_tof_camera_handle *pHandle = ob_tof_stream_get_handle();

    if (pHandle->pMsgQueue)
    {
        free(pHandle->pMsgQueue);
        pHandle->pMsgQueue = NULL;
    }

    if (pHandle)
    {
        free(pHandle);
        pHandle = NULL;
    }

    //TODO
}
