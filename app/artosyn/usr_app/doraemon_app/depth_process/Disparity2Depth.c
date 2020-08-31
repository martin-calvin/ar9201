#include "Disparity2Depth.h"
#include <math.h>
#include <arm_neon.h>
#include <omp.h>

#if (defined _WIN32)  || (defined _WIN64)
#include "NEON_2_SSE.h"
#else
#include <arm_neon.h>
#endif

#define BATCH_4 4
#define EPS 1e-6

static volatile const disparity2depthPara para = {
	.fZeroPlaneDistance = 1300.0, // z0
	.fZeroPlanePixelSize = 1300.0/1160.0,   //zpps =z0/fx
	.fEmitterDComsDistance = 60.0, // b基线
	.nParamCoeff = 8,//这个和openni协议视差位数有关：
	.nConstShift = 200,  //固定参数 
	.nShiftScale = 1, //深度单位计算系数:如果单位mm,则为1；如果为0.1mm,则为10
	.nMinDepth = 0, //最小深度 mm
	.nMaxDepth = 8000,//最大深度 mm
};

//外部调用时获取参数指针，只修改需要修改的参数
pParaHandle get_disparity2depthPara_handle(void)
{
    pParaHandle p_handle = &para;
    return  p_handle;              
}
//disparrity:协议视差-----> 这个只用来验证参数，速度太慢
void Dispar2Depth(uint16_t *disparrity, int frame_size, uint16_t *depth)
{
	for (size_t i = 0; i < frame_size; i++)
	{
		uint16_t nShiftValue = disparrity[i];
		if (!nShiftValue) //如果视差为0,则为无效视差
		{
			*depth = 0;
			depth++;
			continue;
		}

		///协议视差转真实视差
		double dFixedRefX = (double)(nShiftValue - para.nParamCoeff * para.nConstShift) / para.nParamCoeff;
		dFixedRefX -= 0.375;

		///计算dMetric = d * zpps
		double dMetric = dFixedRefX * para.fZeroPlanePixelSize;

		///视差计算深度
		double dDepth = ((dMetric * para.fZeroPlaneDistance / (para.fEmitterDComsDistance - dMetric)) + para.fZeroPlaneDistance);

		/// 截断深度，把不需要的深度值置0
		if ((dDepth < para.nMinDepth) || (dDepth >  para.nMaxDepth)) {
			dDepth = 0;
		}

		///根据单位输出深度值
		*depth = (uint16_t)(para.nShiftScale * dDepth);
		depth++;
	}
}

void Disparity2Depth_ArmNeon(uint16_t *disparrity, int frame_size, uint16_t *depth)
{
	float32x4_t nParamCoeff_f32x4 = vdupq_n_f32(para.nParamCoeff);
	float32x4_t nParamCoeffRep_f32x4 = vdupq_n_f32(1.0f/para.nParamCoeff);
	float32x4_t coeffMulConstShift_f32x4 = vdupq_n_f32(para.nParamCoeff*para.nConstShift);
	float32x4_t fZeroPlanePixelSize_f32x4 = vdupq_n_f32(para.fZeroPlanePixelSize);
	float32x4_t fZeroPlaneDistance_f32x4 = vdupq_n_f32(para.fZeroPlaneDistance);
	float32x4_t fEmitterDComsDistance_f32x4 = vdupq_n_f32(para.fEmitterDComsDistance);
	uint16x4_t nMinDepth_u16x4 = vdup_n_u16(para.nMinDepth);
	uint16x4_t nMaxDepth_u16x4 = vdup_n_u16(para.nMaxDepth);

	float32x4_t nShiftScale_f32x4 = vdupq_n_f32(para.nShiftScale);
	float32x4_t eps_f32x4 = vdupq_n_f32(EPS);
	float32x4_t zeroPoint375 = vdupq_n_f32(0.375f);
	uint16x4_t zero_u16x4 = vdup_n_u16(0);
	int32_t fix4_i32 = (frame_size + BATCH_4 - 1) / BATCH_4;
#pragma omp parallel for
	for (int i = 0; i < fix4_i32; i++)
	{
		//if (i == 4105)
		//{
		//	int a = 1;
		//	int b = a + 1;
		//}
		int uStart = i*BATCH_4;
		uint16x4_t disparrity_u16x4 = vld1_u16(disparrity + uStart);
		float32x4_t disparrity_f32x4 = vcvtq_f32_u32(vmovl_u16(disparrity_u16x4));
		uint16x4_t flag1_u16x4 = vcgt_u16(disparrity_u16x4, zero_u16x4);

		float32x4_t dFixedRefX_f32x4 = vmulq_f32(vsubq_f32(disparrity_f32x4, coeffMulConstShift_f32x4) , nParamCoeffRep_f32x4);
		dFixedRefX_f32x4 = vsubq_f32(dFixedRefX_f32x4, zeroPoint375);
		float32x4_t dMetric_f32x4 = vmulq_f32(dFixedRefX_f32x4, fZeroPlanePixelSize_f32x4);
	    
		float32x4_t tempSub_f32x4 = vsubq_f32(fEmitterDComsDistance_f32x4,dMetric_f32x4);
		float32x4_t rep0_f32x4 = vrecpeq_f32(tempSub_f32x4);
		rep0_f32x4 = vmulq_f32(vrecpsq_f32(tempSub_f32x4, rep0_f32x4), rep0_f32x4);
		rep0_f32x4 = vmulq_f32(vrecpsq_f32(tempSub_f32x4, rep0_f32x4), rep0_f32x4);

		float32x4_t tempMul_f32x4 = vmulq_f32(dMetric_f32x4, fZeroPlaneDistance_f32x4);
		float32x4_t dDepth_f32x4 = vmlaq_f32(fZeroPlaneDistance_f32x4, tempMul_f32x4, rep0_f32x4);

		uint16x4_t dDepth_u16x4 = vmovn_u32(vcvtq_u32_f32(dDepth_f32x4));
		uint16x4_t flag2_u16x4=vand_u16(vcgt_u16(dDepth_u16x4, nMinDepth_u16x4),vclt_u16(dDepth_u16x4, nMaxDepth_u16x4));
		uint16x4_t finalDepth_u16x4 = vand_u16(dDepth_u16x4,vand_u16(flag1_u16x4, flag2_u16x4));
		//uint16x4_t temp1 = vand_u16(flag1_u16x4, flag2_u16x4);
		//uint16x4_t temp2 = vand_u16(dDepth_u16x4, temp1);
		vst1_u16(depth+uStart, finalDepth_u16x4);
	}
}
