#ifndef __DISPARITY2DEPTH_H__
#define __DISPARITY2DEPTH_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include <stdio.h>
#include <stdint.h>

typedef struct 
{
	float   fZeroPlaneDistance;
	float   fZeroPlanePixelSize;
	float   fEmitterDComsDistance;
	float   nParamCoeff;
	int nConstShift;
	int nShiftScale;
	int nMinDepth;
	int nMaxDepth;
}disparity2depthPara;

typedef disparity2depthPara* pParaHandle;

pParaHandle get_disparity2depthPara_handle(void);
void Dispar2Depth(uint16_t *disparrity, int frame_size, uint16_t *depth);
void Disparity2Depth_ArmNeon(uint16_t *disparrity, int frame_size, uint16_t *depth);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif