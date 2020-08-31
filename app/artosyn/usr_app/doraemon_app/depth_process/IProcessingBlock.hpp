// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2020 Orbbec Corporation. All Rights Reserved.

#pragma once

#include "Frame.hpp"
#include "softfilter.h"
#include <cstring>
#include <vector>
namespace libobsensor {
class IProcessingBlock {

public:
    // virtual OBStatus processFrame( std::shared_ptr< Frame > frameIn, std::shared_ptr< Frame > frameOut ) = 0;
    virtual void     init( OBFormat obformat )                       = 0;
    virtual OBStatus processFrame( Frame* frameIn, Frame* frameOut ) = 0;
};

class Disparity2Depth : public IProcessingBlock {
public:
    Disparity2Depth( OBDisparityProcessParameter disparityParam, bool isDualCamera ) : disparityParam_( disparityParam ), isDualCamera_( isDualCamera ) {}
    virtual ~Disparity2Depth() {
    }
    void init( OBFormat obformat ) {
        if ( isDualCamera_ ) {
            dualCameraInit( obformat );
        }
        else {
            singleCameraInit( obformat );
        }
    }
        void dualCameraInit( OBFormat obformat ) {
            double fb = disparityParam_.dualParameter.baseline * disparityParam_.dualParameter.fx;
            double disparityArg;
            m_pShiftToDepthTable.resize( 4096 );
            uint16_t depVal;
            for ( int i = 0; i < 4096; i++ ) {
                disparityArg = ( disparityParam_.dualParameter.disparityCoeff - i ) / disparityParam_.dualParameter.fCoefficient;
                if ( disparityArg < 255 && disparityArg > 0 ) {
                    depVal = ( uint16_t )( disparityParam_.dualParameter.nShiftScale * ( fb / disparityArg ) );
                    if ( depVal < disparityParam_.dualParameter.maxDepthValue && depVal > disparityParam_.dualParameter.minDepthValue ) {
                        m_pShiftToDepthTable[ i ] = depVal;
                    }
                    else {
                        m_pShiftToDepthTable[ i ] = 0;
                    }
                }
                else {
                    m_pShiftToDepthTable[ i ] = 0;
                }
            }
        }
        void singleCameraInit( OBFormat obformat ) {
            uint32_t nIndex          = 0;
            uint16_t nShiftValue     = 0;
            double   dFixedRefX      = 0;
            double   dMetric         = 0;
            double   dDepth          = 0;
            double   dPlanePixelSize = disparityParam_.singleParameter.fZeroPlanePixelSize;  // 0.093750;  // pConfig->fZeroPlanePixelSize;
            double   dPlaneDsr       = disparityParam_.singleParameter.fZeroPlaneDistance;   // 90.0;      // pConfig->fZeroPlaneDistance;
            double   dPlaneDcl       = disparityParam_.singleParameter.fEmitterDComsDistance; //7.5      // pConfig->fEmitterDCmosDistance;
            int32_t nConstShift      = disparityParam_.singleParameter.nParamCoeff * disparityParam_.singleParameter.nConstShift;  // 4 * 200;   // pConfig->nParamCoeff * pConfig->nConstShift;
            uint16_t nShiftScale     = disparityParam_.singleParameter.nShiftScale;        // 1;         //( pConfig->nShiftScale / 10 );
            uint32_t nMinDepth         = disparityParam_.singleParameter.minDepthValue;  // 0;  // pConfig->nDepthMinCutOff * nShiftScale;
            uint32_t nMaxDepth = disparityParam_.singleParameter.maxDepthValue;          // 10000;  // XN_MIN( pConfig->nDeviceMaxDepthValue, nMaxDepth );
            m_pShiftToDepthTable.resize( 4096 );
            for ( nIndex = 1; nIndex < 4095; nIndex++ ) {
                nShiftValue = ( uint16_t )nIndex;
                dFixedRefX  = ( double )( nShiftValue - nConstShift ) / disparityParam_.singleParameter.nParamCoeff;  //( double )pConfig->nParamCoeff;
                dFixedRefX -= 0.375;
                dMetric = dFixedRefX * dPlanePixelSize;
                dDepth  = nShiftScale * ( ( dMetric * dPlaneDsr / ( dPlaneDcl - dMetric ) ) + dPlaneDsr );
                // check cut-offs
                if ( ( dDepth > nMinDepth ) && ( dDepth < nMaxDepth ) ) {
                    m_pShiftToDepthTable[ nIndex ] = ( uint16_t )dDepth;
                }
            }
        }
        
        OBStatus processFrame( Frame * frameIn, Frame * frameOut ) override {
            int frameSize = frameIn->getDataSize() / 2;

        frameOut->setFrameNumber( frameIn->getFrameNumber() );
        uint16_t* pdataIn  = ( uint16_t* )frameIn->getData();
        uint16_t* pdataOut = ( uint16_t* )frameOut->getData();

#if 0
        static int gwritecnt = 0;
        if ( gwritecnt  == 0 ) {
            FILE* fp = fopen( "depthTable.bin", "wb+" );
            fwrite( m_pShiftToDepthTable, 1,8192, fp );
            fclose( fp );
            gwritecnt = 1;
        }
#endif 
            
            while ( frameSize-- ) {

                *pdataOut = m_pShiftToDepthTable[ (*pdataIn)&0x0FFF ];
                pdataOut++;
                pdataIn++;
            }
            return OB_STATUS_OK;
        }
        OBStatus depth_processFrame(uint16_t *pdataIn, uint16_t *pdataOut, uint32_t frameSize)
        {
            int i = 0;
            int frameSize_ = frameSize / 2;
            for (i = 0; i < frameSize_; i += 4)
            {
                *pdataOut = m_pShiftToDepthTable[(*pdataIn)];
                pdataOut++;
                pdataIn++;
                *pdataOut = m_pShiftToDepthTable[(*pdataIn)];
                pdataOut++;
                pdataIn++;
                *pdataOut = m_pShiftToDepthTable[(*pdataIn)];
                pdataOut++;
                pdataIn++;
                *pdataOut = m_pShiftToDepthTable[(*pdataIn)];
                pdataOut++;
                pdataIn++;
            }
            return OB_STATUS_OK;
        }

public:
    OBDisparityProcessParameter disparityParam_;
        bool                        isDualCamera_;
    // uint16_t*                   m_pShiftToDepthTable=nullptr;
    std::vector< uint16_t > m_pShiftToDepthTable;
};
class SoftFilter : public IProcessingBlock {
public:
    SoftFilter( OBSoftFilterParameter softParam ) : softParam_( softParam ) {}
    virtual ~SoftFilter() {}
    void init( OBFormat obformat ) override {
        if ( softParam_.maxSpeckleSize_ <= 0 ) {
            softParam_.maxSpeckleSize_ = 960;
        }
        if ( softParam_.maxDiff_ <= 0 ) {
            softParam_.maxDiff_ = 16;
        }
    }
    OBStatus processFrame( Frame* frameIn, Frame* frameOut ) override {
        int width, height;
        frameIn->getWidthHeight( width, height );
        if ( buf_.size() != width * height * 9 ) {
            buf_.resize( width * height * 9 );
        }
        uint16_t* img      = ( uint16_t* )frameIn->getData();
        uint8_t*  pdataOut = ( uint8_t* )frameOut->getData();
        softfilter( ( uint8_t* )buf_.data(), img, width, height, softParam_.maxDiff_, softParam_.maxSpeckleSize_, 0 );
        memcpy( pdataOut, img, width * height*2 );
        //frameOut->setData(img);
        return OB_STATUS_OK;
    }
    private:
    OBSoftFilterParameter  softParam_{ 0 };
    std::vector< uint8_t > buf_;
};
class NoiseFilter : public IProcessingBlock {
    void     init( OBFormat obformat ) override {}
    OBStatus processFrame( Frame* frameIn, Frame* frameOut ) override {
        int frameSize = frameIn->getDataSize();
        frameOut->setFrameNumber( frameIn->getFrameNumber() );
        uint8_t* pdataIn  = ( uint8_t* )frameIn->getData();
        uint8_t* pdataOut = ( uint8_t* )frameOut->getData();
        memcpy( pdataOut, pdataIn, frameSize );
        return OB_STATUS_OK;
    }
};

}  // namespace libobsensor