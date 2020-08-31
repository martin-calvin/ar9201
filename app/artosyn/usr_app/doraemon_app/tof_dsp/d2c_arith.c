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

#define Q10_IDENTY (0x01 << 10) //1024
#define FLOAT2Q10(x) (int)((x) > 0 ? ((x) * (float)Q10_IDENTY + 0.5f) : ((x) * (float)Q10_IDENTY - 0.5f))

#define Q16_IDENTY (0x01 << 16) //65536
#define FLOAT2Q16(x) (int)((x) > 0 ? ((x) * (float)Q16_IDENTY + 0.5f) : ((x) * (float)Q16_IDENTY - 0.5f))

#define Q30_IDENTY (0x01 << 30)
#define FLOAT2Q30(x) (int)((x > 0) ? ((x) * (float)Q30_IDENTY + 0.5f) : ((x) * (float)Q30_IDENTY - 0.5f))

float depth_near = 500, depth_far = 3000;

/*****************************************************************************
*   Prototype    : project_point
*   Description  : 
*   Input        :
*   Output       :
*   Return Value :
*****************************************************************************/
void project_point(float *K_depth, float *K_color, float *rot,
                   float *trans, float depth_x, float depth_y, float *color_x, float *color_y, float depth)
{
    // float w = 0;
    float x, y, z;
    z = depth;
    float xc = 0;
    float yc = 0;
    float wc = 0;

    x = z * (depth_x - *(K_depth + 2)) / *(K_depth + 0);
    y = z * (depth_y - *(K_depth + 3)) / *(K_depth + 1);

    xc = *(rot + 0) * x + *(rot + 1) * y + *(rot + 2) * z + *(trans);
    yc = *(rot + 3) * x + *(rot + 4) * y + *(rot + 5) * z + *(trans + 1);
    wc = *(rot + 6) * x + *(rot + 7) * y + *(rot + 8) * z + *(trans + 2);

    x = xc / wc;
    y = yc / wc;

    float xd = x * (*(K_color + 0)) + *(K_color + 2);
    float yd = y * (*(K_color + 1)) + *(K_color + 3);

    *color_x = xd;
    *color_y = yd;
}
/*****************************************************************************
*   Prototype    : initD2C_param
*   Description  : DSP D2C param init
*   Input        : soft_d2c *input
*   Output       : int *linear_rot_coeff_ht_, int *trans_coeff_,
                   int *color_y_max_lut_, int *color_y_min_lut_, 
                   int *rows, int *out_rows
*   Return Value :
*****************************************************************************/
int initD2C_param(soft_d2c *input, int *linear_rot_coeff_ht_, int *trans_coeff_,
                  int *color_y_max_lut_, int *color_y_min_lut_, int *rows, int *out_rows)
{
    //从软件D2C参数中读取IR图的宽高和内外参
    uint32_t depth_width = input->IRimg_size.width;       //width of depth image
    uint32_t depth_height = input->IRimg_size.height;

    uint32_t color_width = input->colorimg_size.width;    //width of color image
    uint32_t color_height = input->colorimg_size.height;

    float depth_K_[4];
    memcpy(depth_K_, input->d_intr_p, 4 * sizeof(float));
    float color_K_[4];
    memcpy(color_K_, input->c_intr_p, 4 * sizeof(float));
    float rot_[9];
    memcpy(rot_, input->d2c_r, 9 * sizeof(float));
    float trans_[3];
    memcpy(trans_, input->d2c_t, 3 * sizeof(float));

    // int *rot_coeff = (int *)malloc(3 * depth_width * depth_height * sizeof(int));
    // memset(rot_coeff, 0, 3 * depth_width * depth_height * sizeof(int));
    int *trans_coeff = (int *)malloc(3 * sizeof(int));
    memset(trans_coeff, 0, 3 * sizeof(int));

    for (int v = 0; v < depth_height; ++v)
    {
        // int *dst_0 = rot_coeff + v * depth_width;
        // int *dst_1 = (rot_coeff + depth_width * depth_height) + v * depth_width;
        // int *dst_2 = (rot_coeff + 2 * depth_width * depth_height) + v * depth_width;
        int *dst_0 = linear_rot_coeff_ht_ + v * depth_width;
        int *dst_1 = (linear_rot_coeff_ht_ + depth_width * depth_height) + v * depth_width;
        int *dst_2 = (linear_rot_coeff_ht_ + 2 * depth_width * depth_height) + v * depth_width;
        float y = (v - input->d_intr_p[3]) / input->d_intr_p[1]; // X = K^{-1}_{ir} * [u,v,1]^T
        for (int u = 0; u < depth_width; ++u)
        {
            int uu = u;
            // if (input->d2c_param_.isDepthMirror)
            //     uu = width - 1 - u;
            float x = (uu - input->d_intr_p[2]) / input->d_intr_p[0];

            // R_{c2d} * X
            float rx = input->d2c_r[0] * x + input->d2c_r[1] * y + input->d2c_r[2];
            float ry = input->d2c_r[3] * x + input->d2c_r[4] * y + input->d2c_r[5];
            float rz = input->d2c_r[6] * x + input->d2c_r[7] * y + input->d2c_r[8];

            // K_{rgb} * Y
            *dst_0++ = FLOAT2Q16(rx * input->c_intr_p[0] + rz * input->c_intr_p[2]);
            *dst_1++ = FLOAT2Q16(ry * input->c_intr_p[1] + rz * input->c_intr_p[3]);
            *dst_2++ = FLOAT2Q16(rz);
        }
    }

    trans_coeff_[0] = FLOAT2Q10(input->d2c_t[0] * input->c_intr_p[0] + input->d2c_t[2] * input->c_intr_p[2]);
    trans_coeff_[1] = FLOAT2Q10(input->d2c_t[1] * input->c_intr_p[1] + input->d2c_t[2] * input->c_intr_p[3]);
    trans_coeff_[2] = FLOAT2Q10(input->d2c_t[2]);

    for (int v = 0; v < depth_height; ++v)
    {
        float color_y_min_500 = 10000.0, color_y_max_500 = -10000.0;
        for (int u = 0; u < depth_width; ++u)
        {
            float point_rgb_x = 0, point_rgb_y = 0;
            project_point(depth_K_, color_K_, rot_, trans_, u, v, &point_rgb_x, &point_rgb_y, depth_near);
            if (color_y_min_500 > point_rgb_y)
                color_y_min_500 = point_rgb_y;
            if (color_y_max_500 < point_rgb_y)
                color_y_max_500 = point_rgb_y;
        }

        float color_y_min_3000 = 10000.0, color_y_max_3000 = -10000.0;
        for (int u = 0; u < depth_width; ++u)
        {
            float point_rgb_x = 0, point_rgb_y = 0;
            project_point(depth_K_,color_K_, rot_, trans_, u, v, &point_rgb_x, &point_rgb_y, depth_far);
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
        if (color_y_min > color_height) //若大于Color的Y方向最大值
            color_y_min = color_height;
        if (color_y_max > color_height)
            color_y_max = color_height;

        color_y_min_lut_[v] = floor(color_y_min);
        color_y_max_lut_[v] = ceil(color_y_max);
    }

    int max_size = 112 * 1024; //max size of dsp sram

    if (color_width == 480)
    {
        *rows = 10; //init
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
        printf("Error! Unsupported resolution!");
        return -1;
    }

    int min_row = color_y_max_lut_[depth_height / 2 + *rows - 1] - color_y_min_lut_[depth_height / 2] + 5;

    int left_size = max_size - *rows * 14 * depth_width - 2 * depth_height * 4;
    *out_rows = (left_size / (2 * color_width)) - 1;

    while (*out_rows <= min_row)
    {
        do
        {
            *rows--;
        } while (depth_height % *rows != 0 && *rows >= 1);
        min_row = color_y_max_lut_[depth_height / 2 + *rows - 1] - color_y_min_lut_[depth_height / 2] + 2;
        left_size = max_size - *rows * 14 * depth_width - 2 * depth_height * 4;
        *out_rows = floor(left_size / (2 * color_width)) - 1;
    }

    return 0;
}
