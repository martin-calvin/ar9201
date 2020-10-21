/******************************************************************************

  Copyright (C), 2020, orbbec Tech. Co., Ltd.

 ******************************************************************************
  File Name     : d2c_arith.cpp

  Version       : 1.0.0
  Author        : Martin
  Created       : 2020/08/09
  Description   :
  History       :
  
******************************************************************************/
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
#include <string.h> //for memcpy()
#include <math.h>   //for floor()、ceil()
#include <stdbool.h>

#include "d2c_arith.h"
#include "logutil.h"


double depth_near = 450, depth_far = 3500;

char firmwareFile[] = "./firmware.bin";
char referencePictureFile[] = "/factory/doraemon/reference.bin";
char cfgParameter_960_1280[] = "/factory/doraemon/distortion_d2c4x3.bin";
char cfgParameter_720_1280[] = "/factory/doraemon/d2c_16x9.bin";
char DeviceConfig_file[] = "/factory/doraemon/config.bin";

/*****************************************************************************
*   Prototype    : calc_rows
*   Description  : 
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
void calc_rows(int *color_y_max, int *color_y_min, int depth_width, int depth_height,
               int color_width, int color_height, int *rows, int *out_rows)
{
    int max_size = 112 * 1024; //max size of dsp sram

    int out_bytesize = 2;

    if (color_width == 480)
    {
        *rows = 10;
    }
    else if (color_width == 720)
    {
        *rows = 5;
    }
    else if (color_width == 960)
    {
        *rows = 4;
    }
    else
    {
        ERR("Error! Unsupported resolution!");
        return;
    }

    int min_row = 0;

    for (int i = 0; i < depth_height - (*rows); ++i)
    {
        int tmp = color_y_max[i + (*rows) - 1] - color_y_min[i];
        min_row = min_row > tmp ? min_row : tmp;
    }

    /********************************************************
    row * 14 * depth_width + out_rows * 2 * color_width + 2 * depth_height * 4 < max_size

    row * 14 * depth_width:         输入depth 所占空间  sizeof(float) * 3 + sizeof(uint_16_t) = 14

    out_rows * 2 * color_width:     输出color depth 所占空间

    2 * depth_height * 4:           color_y_max_lut 和color_y_min_lut 所占空间

    保证 out_rows > color_y_max[] - color_y_min
    **********************************************************/
    int left_size = max_size - (*rows) * 14 * depth_width - 2 * depth_height * 4;
    *out_rows = (left_size / (out_bytesize * color_width));

    while ((*out_rows) <= min_row)
    {
        do
        {
            (*rows)--;
        } while (depth_height % (*rows) != 0 && (*rows) >= 1);

        min_row = 0;
        for (int i = 0; i < depth_height - (*rows); ++i)
        {
            int tmp = color_y_max[i + (*rows) - 1] - color_y_min[i];
            min_row = min_row > tmp ? min_row : tmp;
        }

        left_size = max_size - (*rows) * 14 * depth_width - 2 * depth_height * 4;
        *out_rows = (int)(left_size / (out_bytesize * color_width));
    }
}

/*****************************************************************************
*   Prototype    : project_point
*   Description  : 
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
void project_point(soft_d2c *input, float depth_x, float depth_y, float *color_y, float depth, bool color_distort_switch)
{
    float x, y, z;
    z = depth;
    float xc = 0;
    float yc = 0;
    float wc = 0;

    x = z * (depth_x - input->d_intr_p[2]) / input->d_intr_p[0];
    y = z * (depth_y - input->d_intr_p[3]) / input->d_intr_p[1];

    xc = input->d2c_r[0] * x + input->d2c_r[1] * y + input->d2c_r[2] * z + input->d2c_t[0];
    yc = input->d2c_r[3] * x + input->d2c_r[4] * y + input->d2c_r[5] * z + input->d2c_t[1];
    wc = input->d2c_r[6] * x + input->d2c_r[7] * y + input->d2c_r[8] * z + input->d2c_t[2];

    x = xc / wc;
    y = yc / wc;

    float distx = 0, disty = 0;
    if (color_distort_switch) // 增加rgb加畸变
    {
        float k[5];
        float x2 = x * x;
        float y2 = y * y;
        float xy = x * y;
        float r2 = x2 + y2;
        float r4 = r2 * r2;
        float r6 = r2 * r2 * r2;
        float radDistK = input->c_k[0] * r2 + input->c_k[1] * r4 + input->c_k[4] * r6;
        float tanDistX = input->c_k[3] * (2 * x2 + r2) + 2 * input->c_k[2] * xy;
        float tanDistY = input->c_k[2] * (2 * y2 + r2) + 2 * input->c_k[3] * xy;
        //distx = x * radDistK + tanDistX;
        disty = y * radDistK + tanDistY;
    }

    //仅考虑y即可
    float yd = (y + disty) * input->c_intr_p[1] + input->c_intr_p[3];
    if (color_y != NULL)
    {
        *color_y = yd;
    }
}

/*****************************************************************************
*   Prototype    : calc_params_ymin_ymax
*   Description  : 
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
void calc_params_ymin_ymax(soft_d2c *input, bool color_distort_switch, int *color_y_max_lut, int *color_y_min_lut)
{
    for (int v = 0; v < input->IRimg_size.height; ++v)
    {
        float color_y_min_500 = 10000.0, color_y_max_500 = -10000.0;
        for (int u = 0; u < input->IRimg_size.width; ++u)
        {
            float point_rgb_x = 0, point_rgb_y = 0;
            project_point(input, u, v, &point_rgb_y, depth_near, color_distort_switch);
            if (color_y_min_500 > point_rgb_y)
                color_y_min_500 = point_rgb_y;
            if (color_y_max_500 < point_rgb_y)
                color_y_max_500 = point_rgb_y;
        }

        float color_y_min_3000 = 10000.0, color_y_max_3000 = -10000.0;
        for (int u = 0; u < input->IRimg_size.width; ++u)
        {
            float point_rgb_x = 0, point_rgb_y = 0;
            project_point(input, u, v, &point_rgb_y, depth_far, color_distort_switch);
            if (color_y_min_3000 > point_rgb_y)
                color_y_min_3000 = point_rgb_y;
            if (color_y_max_3000 < point_rgb_y)
                color_y_max_3000 = point_rgb_y;
        }

        float color_y_min = (color_y_min_500 < color_y_min_3000) ? color_y_min_500 : color_y_min_3000;
        float color_y_max = (color_y_max_500 > color_y_max_3000) ? color_y_max_500 : color_y_max_3000;
        color_y_min -= 3; //拓展3行
        color_y_max += 3;
        if (color_y_min < 0)
            color_y_min = 0;
        if (color_y_max < 0)
            color_y_max = 0;
        if (color_y_min > input->colorimg_size.height) //若大于Color的Y方向最大值
            color_y_min = input->colorimg_size.height;
        if (color_y_max > input->colorimg_size.height)
            color_y_max = input->colorimg_size.height;

        color_y_min_lut[v] = floor(color_y_min);
        color_y_max_lut[v] = ceil(color_y_max);
    }
}
/*****************************************************************************
*   Prototype    : initD2C_param
*   Description  : DSP D2C param init
*   Input        : soft_d2c *input, bool color_distort_switch
*   Output       : float *rot_coeff_ht_, int *trans_coeff_,
                   int *color_y_max_lut_, int *color_y_min_lut_, 
                   int *rows, int *out_rows
*   Return Value :
*****************************************************************************/
int initD2C_param(soft_d2c *input, bool color_distort_switch, float *rot_coeff_ht_, float *trans_coeff_,
                   int *color_y_max_lut_, int *color_y_min_lut_, int *rows, int *out_rows)
{
    //从软件d2c参数中获取ir图的宽高和内外参
    uint32_t depth_width = input->IRimg_size.width; //width of depth image
    uint32_t depth_height = input->IRimg_size.height;

    uint32_t color_width = input->colorimg_size.width; //width of color image
    uint32_t color_height = input->colorimg_size.height;

    float depth_K_[4];
    memcpy(depth_K_, input->d_intr_p, 4 * sizeof(float));
    float color_K_[4];
    memcpy(color_K_, input->c_intr_p, 4 * sizeof(float));
    float rot_[9];
    memcpy(rot_, input->d2c_r, 9 * sizeof(float));
    float trans_[3];
    memcpy(trans_, input->d2c_t, 3 * sizeof(float));

    //这几个表需要在函数外分配内存
    if (!rot_coeff_ht_ || !trans_coeff_ || !color_y_max_lut_ || !color_y_min_lut_)
    {
        return -1;
    }

    memset(trans_coeff_, 0, 3 * sizeof(float));
    for (int v = 0; v < depth_height; ++v)
    {
        float *dst_0 = rot_coeff_ht_ + v * depth_width;
        float *dst_1 = (rot_coeff_ht_ + depth_width * depth_height) + v * depth_width;
        float *dst_2 = (rot_coeff_ht_ + 2 * depth_width * depth_height) + v * depth_width;
        float y = (v - input->d_intr_p[3]) / input->d_intr_p[1]; // X = K^{-1}_{ir} * [u,v,1]^T
        for (int u = 0; u < depth_width; ++u)
        {
            int uu = u;
            float x = (uu - input->d_intr_p[2]) / input->d_intr_p[0];

            // R_{c2d} * X
            float rx = input->d2c_r[0] * x + input->d2c_r[1] * y + input->d2c_r[2];
            float ry = input->d2c_r[3] * x + input->d2c_r[4] * y + input->d2c_r[5];
            float rz = input->d2c_r[6] * x + input->d2c_r[7] * y + input->d2c_r[8];

            if (color_distort_switch)
            {
                *dst_0++ = rx;
                *dst_1++ = ry;
                *dst_2++ = rz;
            }
            else
            {
                *dst_0++ = (rx * input->c_intr_p[0] + rz * input->c_intr_p[2]);
                *dst_1++ = (ry * input->c_intr_p[1] + rz * input->c_intr_p[3]);
                *dst_2++ = (rz);
            }
        }
    }

    if (!color_distort_switch) //如果rgb开启畸变开关，则不需要计算trans_coff
    {
        trans_coeff_[0] = (input->d2c_t[0] * input->c_intr_p[0] + input->d2c_t[2] * input->c_intr_p[2]);
        trans_coeff_[1] = (input->d2c_t[1] * input->c_intr_p[1] + input->d2c_t[2] * input->c_intr_p[3]);
        trans_coeff_[2] = (input->d2c_t[2]);
    }

    calc_params_ymin_ymax(input, color_distort_switch, color_y_max_lut_, color_y_min_lut_);

    calc_rows(color_y_max_lut_, color_y_min_lut_, depth_width, depth_height, color_width, color_height, rows, out_rows);

    return 0;
}
