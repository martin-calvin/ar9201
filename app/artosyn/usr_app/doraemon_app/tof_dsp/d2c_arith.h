/******************************************************************************

  Copyright (C), 2020, orbbec Tech. Co., Ltd.

 ******************************************************************************
  File Name     : d2c_arith.h

  Version       : 1.0.0
  Author        : 
  Created       : 2020/08/08
  Description   :
  History       :
  
******************************************************************************/
#ifndef __ARITH_H__
#define __ARITH_H__

#ifdef __cplusplus 
extern "C" { 
#endif

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push)
#pragma pack(4) // 4-byte alignment

typedef struct
{
    uint32_t width;
    uint32_t height;
} img_size;

typedef struct _reg_val{
    uint32_t reg;
    uint32_t val;
} RegVal;

typedef struct
{
    uint8_t chart_version;
    RegVal rectify_regs[44];
    RegVal hw_d2c_regs[15];
    struct
    {
        float d_intr_p[4]; //[fx,fy,cx,cy]
        float c_intr_p[4]; //[fx,fy,cx,cy]
        float d2c_r[9];    //[r00,r01,r02;r10,r11,r12;r20,r21,r22]
        float d2c_t[3];    //[t1,t2,t3]
        float d_k[5];      // [k1 k2 p1 p2 k3] gbb 2018.11.19 (Consistent with the technical documentation)
        float c_k[5];
        img_size colorimg_size;
        img_size IRimg_size;
    } soft_d2c;
    struct Disparity2DepthParams
    {
        float unit;                  // unit:z0 and baseline unit
        float fZeroPlaneDistance;    // z0
        double fZeroPlanePixelSize;  // zpps=z0/fx
        float fEmitterDComsDistance; // baseline
    } disparity2depthparams;
    uint8_t checksum_;
} Doraemon_Content_t;

typedef struct
{
    float d_intr_p[4]; //[fx,fy,cx,cy]
    float c_intr_p[4]; //[fx,fy,cx,cy]
    float d2c_r[9];    //[r00,r01,r02;r10,r11,r12;r20,r21,r22]
    float d2c_t[3];    //[t1,t2,t3]
    float d_k[5];      // [k1 k2 p1 p2 k3] gbb 2018.11.19 (Consistent with the technical documentation)
    float c_k[5];
    img_size colorimg_size;
    img_size IRimg_size;
} soft_d2c;

#pragma pack(pop) // restore alignment


#endif


int initD2C_param(soft_d2c *input, int *linear_rot_coeff_ht_, int *trans_coeff_,
                  int *color_y_max_lut_, int *color_y_min_lut_, int *rows, int *out_rows);



#ifdef __cplusplus 
} 
#endif 