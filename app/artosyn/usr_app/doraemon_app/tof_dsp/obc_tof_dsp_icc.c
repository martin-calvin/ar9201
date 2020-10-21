/******************************************************************************

  Copyright (C), 2020, orbbec Tech. Co., Ltd.

 ******************************************************************************
  File Name     : obc_tof_dsp_icc.c

  Version       : 1.0.0
  Author        : martin
  Created       : 2020/07/02
  Description   :
  History       :
  
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

#include "ar_icc.h"
#include "ar_ion.h"
#include "ar_dsp_rpc.h"
#include <sys/mman.h>


#include <sys/time.h>
#include <time.h>
#include "dbg_info.h"
#include "tof_dsp_memory_map.h"
#include "obc_tof_dsp_icc.h"
#include "logutil.h"
// #include "tof_stream.h"

static int gl_fd_icc = -1;
extern work icc_msg; // icc 通信结构
extern volatile param_ion_mellc_t ion_mem_info[USE_ION_MEM_NUM];

#define DSP_CORE_NUM 4
static uint32_t msg_id_snd_tab[DSP_CORE_NUM] = {0xff00ffab, 0xff00ffbb, 0xff00ffcb, 0xff00ffdb};
static uint32_t msg_id_rcv_tab[DSP_CORE_NUM] = {0xff00ffac, 0xff00ffbc, 0xff00ffcc, 0xff00ffdc};

/*****************************************************************************
*   Prototype    : get_current_time
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
static long long get_current_time()
{
    struct timeval tv;
    struct timezone tz;
    long long ncurrent_time = 0x0LL;
    gettimeofday(&tv, &tz);
    ncurrent_time = ((long long)tv.tv_sec) * 1000000 + (long long)tv.tv_usec;
    return ncurrent_time;
}
/*****************************************************************************
*   Prototype    : ar9201_icc_init
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
int ar9201_icc_init()
{
    gl_fd_icc = open("/dev/icc", O_RDWR);
    if (gl_fd_icc < 0)
    {
        ERR("host open icc fail.\n");
        return -1;
    }
    INFO("host open icc success.\n");
    return 0;
}
/*****************************************************************************
*   Prototype    : ar9201_icc_deinit
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
int ar9201_icc_deinit()
{
    close(gl_fd_icc);
    INFO("host close icc success.\n");
    return 0;
}

/*****************************************************************************
*   Prototype    : ar9201_icc_register_msgid
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
int ar9201_icc_register_msgid(int core_id)
{
    int ret = -1;
    if (core_id >= 0 && core_id < DSP_CORE_NUM)
    {
        ret = ar_icc_register_msgid(gl_fd_icc, msg_id_snd_tab[core_id]);
        if (ret < 0)
        {
            ERR("host iic snd msgid register for core %d fail!\n", core_id);
            return -1;
        }

        ret = ar_icc_register_msgid(gl_fd_icc, msg_id_rcv_tab[core_id]);
        if (ret < 0)
        {
            ERR("host iic rcv msgid register for core %d fail!\n", core_id);
            return -1;
        }
    }
    else
    {
        ERR("host core_id input =%d err!\n", core_id);
        return -1;
    }

    return 0;
}
/*****************************************************************************
*   Prototype    : ar9201_icc_snd_msg
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
int ar9201_icc_snd_msg(int core_id, void *msg_ptr, int msg_len)
{
    //flush cache
    int ret = ar_icc_send(gl_fd_icc, (unsigned char *)msg_ptr, msg_len, msg_id_snd_tab[core_id], ICC_CORE_CEVA_0 + core_id); //ICC_CORE_CEVA_0
    if (ret < 0)
    {
        ERR("host ar_icc_send fail\n");
        return -1;
    }
    //INFO("host ar_icc_send success\n");
    return 0;
}
/*****************************************************************************
*   Prototype    : ar9201_icc_rev_msg
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
int ar9201_icc_rev_msg(int core_id, void *msg_ptr, int msg_len)
{
    int ret = ar_icc_receive(gl_fd_icc, (unsigned char *)msg_ptr, msg_len, msg_id_rcv_tab[core_id]);
    if (ret < 0)
    {
        ERR("host ar_icc_receive fail\n");
        return -1;
    }
    //INFO("host ar_icc_receive success\n");
    return 0;
}

/*****************************************************************************
*   Prototype    : ob_arm_version
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
int ob_arm_version(ob_version_t *version)
{
    ObTofDspParams *pMemParam = (ObTofDspParams *)ion_mem_info[TOF_DspParams_MEM].va; // 存放dspParams的ION空间
    version = &pMemParam->outputs.dsp_version;
    return 0;
}

/*****************************************************************************
*   Prototype    : ob_dsp_version
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
int ob_dsp_version(ob_version_t *version)
{
    ObTofDspParams *pMemParam = (ObTofDspParams *)ion_mem_info[TOF_DspParams_MEM].va; // 存放dspParams的ION空间
    version = &pMemParam->outputs.dsp_version;
    return 0;
}
/*****************************************************************************
*   Prototype    : ob_dsp_sendParam
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
int ob_dsp_sendParam(void)
{
    // 发送一次msg，通知dsp标定内参已经准备好
    ob_dsp_msg_t msg;
    memset(&msg, 0, sizeof(msg));
    msg.cmd = OB_DSP_LOAD_REF;
    ob_dsp_sendcmd(&msg);

    return 0;
}
/*****************************************************************************
*   Prototype    : ob_dsp_loadParam
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
int ob_dsp_loadParam(Depth2Color_pixFormat pixFormat, bool d2c_enable,
                     softfilterParam softfilter_param)
{
    // unsigned long long t1, t2;

    // t1 = get_current_time();
    if (dsp_D2Cparams_init((ObTofDspParams *)ion_mem_info[TOF_DspParams_MEM].va,
                           pixFormat, d2c_enable, softfilter_param) < 0)
        return -1;
    // t2 = get_current_time();

    // INFO("dspParams init cost time %lluus\n", t2 - t1);
    INFO("D2C Format set to :cw(%d) ch(%d) dw(%d) dh(%d)\n",
         pixFormat.color_width, pixFormat.color_height, pixFormat.depth_width,
         pixFormat.depth_height);
    ob_dsp_sendParam();
    return 0;
}
/*****************************************************************************
*   Prototype    : checkDspBootup
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
bool checkDspBootup(int dspid)
{
#define REGISTER_BASE_ADDR 0x64570000
    int bootup_status[16] = {0};
    if (dspid >= ICC_CORE_CEVA_0 && dspid <= ICC_CORE_CEVA_3)
    {
        dspid -= ICC_CORE_CEVA_0;
    }
    if (dspid < DSP_ID_0 || dspid > DSP_ID_3)
    {
        return false;
    }

    do
    {
        if (bootup_status[dspid] == 0)
        {
            int ret = 0;
            int flag = 0;
            int fd = open("/dev/mem", O_RDWR | O_SYNC);
            if (fd < 0)
            {
                ERR("cannot open /dev/mem \n");
                break;
            }
            char *va = (char *)mmap(NULL, 0x100000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, REGISTER_BASE_ADDR);
            if ((void *)va == MAP_FAILED)
            {
                close(fd);
                break;
            }

            flag = *(volatile long *)(va + 0x100c + dspid * 16);
            if ((flag & 0x01) == 0)
            {
                bootup_status[dspid] = 1;
                munmap(va, 0x100000);
                close(fd);
                break;
            }

            flag = *(volatile long *)(va + 0x1004 + dspid * 16);
            if ((flag & 0x1) == 0)
            {
                bootup_status[dspid] = 1;
                munmap(va, 0x100000);
                close(fd);
                break;
            }

            flag = *(volatile long *)(va + 0x3020 + dspid * 0x100);
            if ((flag & 0x1) == 1)
            {
                bootup_status[dspid] = 1;
                munmap(va, 0x100000);
                close(fd);
                break;
            }

            bootup_status[dspid] = 2;
            munmap(va, 0x100000);
            close(fd);
        }
    } while (0);

    if (bootup_status[dspid] == 0 || bootup_status[dspid] == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
/*****************************************************************************
*   Prototype    : ar_dsp_reset
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
int ar_dsp_reset(int dsp_id)
{
    int fd_sys_reg_base = open("/dev/mem", O_RDWR | O_SYNC);
    char *g_va_sys_reg_base = mmap(NULL, 0x100000, PROT_READ | PROT_WRITE,
                                   MAP_SHARED, fd_sys_reg_base, REGISTER_BASE_ADDR);

    *(volatile long *)(g_va_sys_reg_base + /*DSP_WAIT_START*/ 0x3020 + dsp_id * 0x100) = 0x1;

    //clear reset signal, delay, pull reset
    //global reset
    *(volatile long *)(g_va_sys_reg_base + /*DSP_GLOBAL_RST_START*/ 0x1004 + dsp_id * 16) = 0x0;

    //core reset
    *(volatile long *)(g_va_sys_reg_base + 0x100c /*Core reset*/ + dsp_id * 16) = 0x0;

    return 0;
}
/*****************************************************************************
*   Prototype    : ob_dsp_init
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
int ob_dsp_init(Depth2Color_pixFormat pixFormat, bool d2c_enable, softfilterParam softfilter_Param)
{
    int ret;
    // struct timeval time_start, time_stop;
    // double time;

    // gettimeofday(&time_start,NULL);

    system("ar_dsp_bootup 0 /usrdata/usr/data/doraemon/ceva0_me.bin&");
    system("ar_dsp_bootup 1 /usrdata/usr/data/doraemon/ceva1_me.bin&");
    system("ar_dsp_bootup 2 /usrdata/usr/data/doraemon/ceva2_me.bin&");
    system("ar_dsp_bootup 3 /usrdata/usr/data/doraemon/ceva3_me.bin&");

    /* 注册4个CEVA核的 msg id */
    ar9201_icc_init();
    ar9201_icc_register_msgid(0);
    ar9201_icc_register_msgid(1);
    ar9201_icc_register_msgid(2);
    ar9201_icc_register_msgid(3);

    do
    {
        ret = checkDspBootup(ICC_CORE_CEVA_0);        
    } while (!ret);
    INFO("CEVA 0 has started normaly\n");
    do
    {
        ret = checkDspBootup(ICC_CORE_CEVA_1);
        
    } while (!ret);
    INFO("CEVA 1 has started normaly\n");
    do
    {
        ret = checkDspBootup(ICC_CORE_CEVA_2);
        
    } while (!ret);
    INFO("CEVA 2 has started normaly\n");
    do
    {
        ret = checkDspBootup(ICC_CORE_CEVA_3);
        
    } while (!ret);
    INFO("CEVA 3 has started normaly\n");
    /* 初始化ION空间 */
    ret = init_tof_buffer(pixFormat, d2c_enable, softfilter_Param);
    if (ret < 0)
        return -1;

    ob_dsp_sendParam();

#if DEPTH_CALC_FROM_PICTURES
    dsp_init_t(); // 使用图片测试dsp深度计算
#endif
    INFO("DSP init success!\n");
    // gettimeofday(&time_stop,NULL);
    // time = (double)(time_stop.tv_sec - time_start.tv_sec) * 1e3 +
    //                     (double)((time_stop.tv_usec - time_start.tv_usec)) * 1.e-3;
    // INFO("----------time:%f\n",time);
    return 0;
}

/*****************************************************************************
*   Prototype    : ob_dsp_deinit
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
int ob_dsp_deinit(void)
{
    int ret = -1;

    if (gl_fd_icc < 0)
    {
        ERR("Did not open ion device.\n");
        return -1;
    }
    ar9201_icc_deinit();

    // 释放ion buf
    //ret |= release_tof_buffer();

    // 关闭ion
    //ret |= ar_ion_uninit();

    ar_dsp_reset(ICC_CORE_CEVA_0);
    ar_dsp_reset(ICC_CORE_CEVA_1);
    ar_dsp_reset(ICC_CORE_CEVA_2);
    ar_dsp_reset(ICC_CORE_CEVA_3);

    return ret;
}
/*****************************************************************************
*   Prototype    : ob_dsp_sendcmd
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
int ob_dsp_sendcmd(ob_dsp_msg_t *msg)
{
    int ret;

    //work->type置为CONSTPARAMS_SET，发起通信命令。
    icc_msg.type = CONSTPARAMS_SET;

    /* 发起icc通信，发送消息，dsp开始处理 */
    all_ion_cache_flush(TOF_DspParams_MEM);
    all_ion_cache_flush(TOF_temp_MEM);
    all_ion_cache_flush(D2C_linear_rot_coeff_ht);
    all_ion_cache_flush(D2C_linear_color_y_max_lut);
    all_ion_cache_flush(D2C_linear_color_y_min_lut);
    ret |= ar9201_icc_snd_msg(0, (unsigned char *)&icc_msg, sizeof(icc_msg));
    ret |= ar9201_icc_rev_msg(0, (unsigned char *)&icc_msg, sizeof(icc_msg));
    all_ion_cache_invalid(TOF_DspParams_MEM);

    return ret;
}

/*****************************************************************************
*   Prototype    : dsp_out_check
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
int dsp_out_check(void *dsp_in_va, void *dsp_out_va, int size)
{
    uint8_t *pData1 = dsp_in_va;
    uint8_t *pData2 = dsp_out_va;
    //对比帧空间
    uint32_t cap_mem_count = 20;
    //对比前3行，不一样时打印前两行的一些数据
    if (memcmp(pData1, pData2, size))
    {
        INFO("dsp_in_va:0x%x, dsp_out_va:0x%x\n", pData1, pData2);
        //打印第一行
        for (int x = 0; x < cap_mem_count; x++)
        {
            INFO("%x ", pData1[x]);
        }
        INFO("\n");
        for (int x = 0; x < cap_mem_count; x++)
        {
            INFO("%x ", pData2[x]);
        }
        INFO("\n");
        return -1;
    }
    return 0;
}

/**
 * @brief  close the camera which open_cam
 * @param  group raw_phase group 
 * @param  needAmp if need dsp calc Amp
 * @param  amp out amp img VA addr
 * @param  needDepth if need dsp calc Depth
 * @param  depth out dep img VA addr
 * @return 0 success !0 failed
 * @note null
 */
int ob_depth_calc(void *group, int needAmp, void *amp, int needDepth, void *depth)
{
    int dsp_id = 0;
    int ret;
    volatile int phase_active;
    static unsigned long long start, start1, end, end1;

    imgSendDsp_t imgSendDspAddr; //送dsp处理的图象数的修正地址
    volatile static int frame_cnt_last = 0, frame_cnt_cur = 0;
    ObTofDspParams *pMemParam = (ObTofDspParams *)ion_mem_info[TOF_DspParams_MEM].va; // 存放dspParams的ION空间
    ObTofFrameGroup *pGroupBuff = (ObTofFrameGroup *)group;                           //输入相位帧组

#define ACTIVE_PIX_OFFSET (2) //行，代表图像地址修正的行数，地址的计算和stride相关
#define RTOS_FIFO_FRAME_SIZE (1280 * 970 * 2)
#define EXLINE_DATA_BYTE_INDEX_IN_FRAME (0) //行，解析后的EBDdata的行数，地址的计算和stride相关

    if (gl_fd_icc < 0)
    {
        ERR("dsp icc err: icc_msgid no register\n");
        return -1;
    }

    start1 = get_current_time();

#if (DEPTH_CALC_FROM_PICTURES == 0)

    /*
	1，arm端给dsp使用的物理地址是rtos端的buffer物理地址，*data->[pa]
	2，data的帧格式是1280*962，2行EBD，其中第二行为解析后的有效数据，tx/rx温度信息可以从中获取，更新到dspParams结构体
	3，送给dsp的处理数据应该为1280*960的有效像素，所以需要修正data的地址到有效像素起始地址[data + 1280*2*2]，更新到dspParams结构体
	4, 每次送4帧进dsp，需要将修正4个物理地址

	*/
    // 修正4帧raw phase地址为有效像素的起始地址，更新给dsp使用 **注意顺序必须对应起来
    phase_active = 0;
    for (int i = 0; i < pGroupBuff->real_count; i++)
    {
        ObTofFrame *pFrame = pGroupBuff->frames[i];
        uint32_t pData = pFrame->pRawBuff->mem[0].pa;      // fixme:dsp用物理地址
        uint32_t pData_va = pFrame->pRawBuff->mem[0].addr; // 图像数据虚拟地址
        uint32_t tof_stride = 1280;                        //pFrame->pRawBuff->format.luma_stride; //stride *****这个结构体打印是错误的，不要使用。实际stride=行长

#if 0
		//检查帧是否连续，是否丢帧
		frame_cnt_cur = pFrame->frame_id;
		frame_cnt_last++;
		if(frame_cnt_cur != frame_cnt_last){
			ERR("[err]****frame id expect %d but get %d *******\n",frame_cnt_last, frame_cnt_cur);
			frame_cnt_last = frame_cnt_cur;
		}
#endif

        //将4帧rawphase和dsp需要的帧顺序对应
        if (pFrame->phaseType == PHASE_TYPE_NON_SHUFFLE && pFrame->frequency == OB_TOF_MOD_FREQ_80MHZ)
        {
            imgSendDspAddr.phase_low_nshl.pa = pData + (ACTIVE_PIX_OFFSET * tof_stride * 2);
            imgSendDspAddr.phase_low_nshl.va = pData_va + (ACTIVE_PIX_OFFSET * tof_stride * 2);
            pMemParam->inputs.frameInputs.phase_low_nshl_src = imgSendDspAddr.phase_low_nshl.pa;
            // INFO("input img pa:0x%x, va:0x%x, stride:%d\n", imgSendDspAddr.phase_low_nshl.pa, imgSendDspAddr.phase_low_nshl.va, tof_stride);
            //保存低频f1温度值
            pMemParam->inputs.frameInputs.tempParams.sensor_temp_low = pFrame->temp_rx;
            pMemParam->inputs.frameInputs.tempParams.vcsel_temp_low = pFrame->temp_tx;
            //update integreation time
            pMemParam->inputs.frameInputs.integration_time = pFrame->intergration_time;
            INFO("exp:%dus\n", pMemParam->inputs.frameInputs.integration_time);
            phase_active++;
        }
        else if (pFrame->phaseType == PHASE_TYPE_SHUFFLE && pFrame->frequency == OB_TOF_MOD_FREQ_80MHZ)
        {
            imgSendDspAddr.phase_low_shl.pa = pData + (ACTIVE_PIX_OFFSET * tof_stride * 2);
            imgSendDspAddr.phase_low_shl.va = pData_va + (ACTIVE_PIX_OFFSET * tof_stride * 2);
            pMemParam->inputs.frameInputs.phase_low_shl_src = imgSendDspAddr.phase_low_shl.pa;
            phase_active++;
        }
        else if (pFrame->phaseType == PHASE_TYPE_NON_SHUFFLE && pFrame->frequency == OB_TOF_MOD_FREQ_100MHZ)
        {
            imgSendDspAddr.phase_high_nshl.pa = pData + (ACTIVE_PIX_OFFSET * tof_stride * 2);
            imgSendDspAddr.phase_high_nshl.va = pData_va + (ACTIVE_PIX_OFFSET * tof_stride * 2);
            pMemParam->inputs.frameInputs.phase_high_nshl_src = imgSendDspAddr.phase_high_nshl.pa;
            //保存高频f2温度值
            pMemParam->inputs.frameInputs.tempParams.sensor_temp_high = pFrame->temp_rx;
            pMemParam->inputs.frameInputs.tempParams.vcsel_temp_high = pFrame->temp_tx;
            phase_active++;
        }
        else if (pFrame->phaseType == PHASE_TYPE_SHUFFLE && pFrame->frequency == OB_TOF_MOD_FREQ_100MHZ)
        {
            imgSendDspAddr.phase_high_shl.pa = pData + (ACTIVE_PIX_OFFSET * tof_stride * 2);
            imgSendDspAddr.phase_high_shl.va = pData_va + (ACTIVE_PIX_OFFSET * tof_stride * 2);
            pMemParam->inputs.frameInputs.phase_high_shl_src = imgSendDspAddr.phase_high_shl.pa;
            phase_active++;
        }
    }

    //判断是否有没有对应上的，如果有则证明有丢帧/错帧，这次通信返回失败(dsp处理时间最短，不影响下一帧进入fifo)
    if (phase_active != 4)
    {
        INFO("[err]input dsp phase Drop frames, discard!:%d!\n", phase_active);
        return -1;
    }
#else
    //give piture pa address to dsp
    pMemParam->inputs.frameInputs.phase_low_nshl_src = ion_mem_info[TOF_phase_low_nshl_MEM].pa;
    pMemParam->inputs.frameInputs.phase_low_shl_src = ion_mem_info[TOF_phase_low_shl_MEM].pa;
    pMemParam->inputs.frameInputs.phase_high_nshl_src = ion_mem_info[TOF_phase_high_nshl_MEM].pa;
    pMemParam->inputs.frameInputs.phase_high_shl_src = ion_mem_info[TOF_phase_high_shl_MEM].pa;

    //update temper to dsp
    pMemParam->inputs.frameInputs.tempParams.sensor_temp_high = 33.739998;
    pMemParam->inputs.frameInputs.tempParams.sensor_temp_low = 33.739998;
    pMemParam->inputs.frameInputs.tempParams.vcsel_temp_high = 39.239998;
    pMemParam->inputs.frameInputs.tempParams.vcsel_temp_low = 39.239998;
    //integration time
    pMemParam->inputs.frameInputs.integration_time = 600; //pFrame->intergration_time;
#endif

    /* 更新icc通信消息 */
    //pMemParam->outputs.depth0 = (uint16_t *)depth; // update depth out physic address.
    void *pDepth_pa = (void *)ion_mem_info[TOF_depth0_MEM].pa;
    pMemParam->outputs.aligned_depth = (uint16_t *)pDepth_pa; // update depth out physic address.
    icc_msg.type = ALGORITHM_WORK;
    icc_msg.params.algorithm.type = ALGORITHM_WORK;

    /* 发起icc通信,dsp开始处理 */
    start = get_current_time();
    //INFO("[DSP]time1 %lluus\n",start-end);

    ret |= ar9201_icc_snd_msg(0, (unsigned char *)&icc_msg, sizeof(icc_msg));
    ret |= ar9201_icc_rev_msg(0, (unsigned char *)&icc_msg, sizeof(icc_msg));
    end = get_current_time();
    if (ret < 0)
    {
        return -1;
    }
    // INFO("[DSP]arm-copy cost time %lluus\n",start-start1);
    //INFO("[DSP]dsp cost time %lluus\n",end-start);

#if (ARM_DSP_DBG_INFO)
    /*验证dsp输出空间*/

    dsp_out_check(imgSendDspAddr.phase_low_nshl.va, ion_mem_info[TOF_amp_low_MEM].va, 1536 * 3 * 2); //对比3 line
    dsp_out_check(imgSendDspAddr.phase_low_shl.va, ion_mem_info[TOF_amp_high_MEM].va, 1536 * 3 * 2); //对比3 line
    dsp_out_check(imgSendDspAddr.phase_high_nshl.va, ion_mem_info[TOF_depth0_MEM].va, 1536 * 3 * 2); //对比3 line
    dsp_out_check(imgSendDspAddr.phase_high_shl.va, ion_mem_info[TOF_depth1_MEM].va, 1536 * 3 * 2);  //对比3 line

#endif

    /*输出空间的buffer管理*/

    // end1 = get_current_time();
    // INFO("\n[DSP]arm check cost time %lluus\n",end1-end);

    return 0;
}

/*****************************************************************************
*   Prototype    : ob_dsp_data_process
*   Description  :
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
int ob_dsp_data_process(param_ion_mellc_t *inputBuf, uint32_t inputBuf_weith, uint32_t inputBuf_height,
                       param_ion_mellc_t *outputBuf, uint32_t outputBuf_weith, uint32_t outputBuf_height)
{
    int ret;

#if 0 //dsp picture test
#define test_file_name "/usrdata/usr/data/doraemon/dsp_parms/d2c_test/depth.raw"
	ar_load_file(test_file_name, inputBuf, 0);
	memcpy(ion_mem_info[TOF_phase_low_nshl_MEM].va, inputBuf, inputBuf_weith * inputBuf_height * 2);
#endif

    ObTofDspParams *dspParams = (ObTofDspParams *)ion_mem_info[TOF_DspParams_MEM].va;
    //give piture pa address to dsp
    dspParams->inputs.frameInputs.phase_low_nshl_src = inputBuf->pa;
    dspParams->outputs.aligned_depth = outputBuf->pa;

    icc_msg.type = ALGORITHM_WORK;
    icc_msg.params.algorithm.type = ALGORITHM_WORK;

    // t1 = get_current_time();
    /* 发起icc通信,dsp开始处理 */
    all_ion_cache_flush(TOF_DspParams_MEM);
    ar_ion_cache_flush_by_range(inputBuf->va, inputBuf->va, inputBuf_weith * inputBuf_height * 2);
    ret |= ar9201_icc_snd_msg(0, (unsigned char *)&icc_msg, sizeof(icc_msg));
    ret |= ar9201_icc_rev_msg(0, (unsigned char *)&icc_msg, sizeof(icc_msg));
    ar_ion_cache_invalid_by_range(outputBuf->va, outputBuf->va, outputBuf_weith * outputBuf_height * 2);
    // t2 = get_current_time();

    // INFO("[DSP]dsp cost time %lluus\n",t2-t1);

    return 0;
}
