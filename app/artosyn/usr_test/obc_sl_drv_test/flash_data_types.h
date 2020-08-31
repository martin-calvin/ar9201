#ifndef FLASH_DATA_TYPE_H
#define FLASH_DATA_TYPE_H

//#include "calibration_params.h"
//#include "mx6000_cfg.h"
#include <stdint.h>

#pragma pack(push)
#pragma pack (4) // 4-byte alignment

typedef struct {
	uint32_t width;
	uint32_t hight;
}img_size;

typedef struct {
    uint32_t reg;
    uint32_t val;
} RegVal;

typedef struct  {
    float fZ0;
    float fBaseline;
} BaselineCalibrationPara;
typedef struct {
    uint8_t sn[12];
	uint8_t ldp_params[16];
	uint8_t ldp_crc;
}DeviceConfig;
#define VALUE_VALID 0x5A

typedef struct{
uint32_t sn_valid;
uint32_t ldp_valid;
uint32_t distortion_d2c4x3_valid;
uint32_t d2c_16x9_valid;
uint32_t reference_valid;
}ConfigValidFlag;

typedef struct {
    uint8_t sn[12];
    uint8_t pn[12];
    uint8_t device_string[128];
}DeviceInfo;

typedef struct {
    uint8_t chart_version;
    RegVal rectify_regs[44];
    RegVal hw_d2c_regs[15];
    struct {
        float d_intr_p[4]; //[fx,fy,cx,cy]
        float c_intr_p[4]; //[fx,fy,cx,cy]
        float d2c_r[9];    //[r00,r01,r02;r10,r11,r12;r20,r21,r22]
        float d2c_t[3];    //[t1,t2,t3]
        float d_k[5];      // [k1 k2 p1 p2 k3] gbb 2018.11.19 (Consistent with the technical documentation)
        float c_k[5];
        img_size colorimg_size;
        img_size IRimg_size;
    } soft_d2c;
    struct Disparity2DepthParams {
        float unit;                  // unit:z0 and baseline unit
        float fZeroPlaneDistance;    // z0
        double fZeroPlanePixelSize;  // zpps=z0/fx
        float fEmitterDComsDistance; // baseline
    } disparity2depthparams;
    uint8_t checksum_;
} Doraemon_Content_t;


#pragma pack(pop) // restore alignment

#endif // !FLASH_DATA_TYPE_H