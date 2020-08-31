// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2020 Orbbec Corporation. All Rights Reserved.

#pragma once

#include "ObSensor.h"

#include <atomic>
#include <memory>
#include <mutex>

namespace libobsensor {
class Frame {
public:
    Frame() {}
    Frame( const Frame& other ) {
        refCount_.store( other.refCount_.load() );
        // refCount_         = other.refCount_;
        mOBFrame_         = other.mOBFrame_;
        frameBackToQueue_ = other.frameBackToQueue_;
        pCookie_          = other.pCookie_;
        addRef();
    }
    Frame& operator=( const Frame& other ) {
        refCount_.store( other.refCount_.load() );
        // refCount_         = other.refCount_;
        mOBFrame_         = other.mOBFrame_;
        frameBackToQueue_ = other.frameBackToQueue_;
        pCookie_          = other.pCookie_;
        addRef();
        return *this;
    }
    Frame( Frame&& other ) {
        refCount_.store( other.refCount_.load() );
        // refCount_         = other.refCount_;
        mOBFrame_         = other.mOBFrame_;
        frameBackToQueue_ = other.frameBackToQueue_;
        pCookie_          = other.pCookie_;
        other.mOBFrame_         = { 0 };
        other.frameBackToQueue_ = nullptr;
        other.pCookie_          = nullptr;
    }
    Frame& operator=( Frame&& other ) {
        refCount_.store( other.refCount_.load() );
        // refCount_         = other.refCount_;
        mOBFrame_         = other.mOBFrame_;
        frameBackToQueue_ = other.frameBackToQueue_;
        pCookie_          = other.pCookie_;
        other.mOBFrame_         = { 0 };
        other.frameBackToQueue_ = nullptr;
        other.pCookie_          = nullptr;
        return *this;
    }
    void* getData() const {
        return mOBFrame_.data;
    }
    void setData( void* pdata ) {
        mOBFrame_.data = pdata;
    }
    double getTimeStamp() const {
        return mOBFrame_.timestamp;
    }
    void setTimeStamp( const double& timestamp ) {
        mOBFrame_.timestamp = timestamp;
    }
    unsigned long long getFrameNumber() const {
        return mOBFrame_.frameIndex;
    }
    void setFrameNumber( const unsigned long long& frameNumber ) {
        mOBFrame_.frameIndex = frameNumber;
    }
    std::shared_ptr< OBFrame > applyProcessingBlock();
    void                       getStreamConfig() const {}
    void                       getMetaData() const {}

    int getDataSize() const {
        return mOBFrame_.dataSize;
    }
    void setDataSize( const int& dataSize ) {
        mOBFrame_.dataSize = dataSize;
    }
    void addRef() {
        std::lock_guard< std::mutex > lock_( frameMutex_ );
        ++refCount_;
    }
    void subRef() {
        std::lock_guard< std::mutex > lock_( frameMutex_ );
        if ( --refCount_ == 0 ) {
            frameBackToQueue_( this, pCookie_ );
        }
    }
    int getRefCnt() const {
        return refCount_;
    }
    OBFrameType getFrameType() const {
        return mOBFrame_.frameType;
    }
    void setFrameType( const OBFrameType& frameType ) {
        mOBFrame_.frameType = frameType;
    }
    void getWidthHeight( int& width, int& height ) const {
        width  = mOBFrame_.width;
        height = mOBFrame_.height;
    }
    void setWidthHeight( const int width, const int height ) {
        mOBFrame_.width = width;
        mOBFrame_.height = height;
    }
    int getFPS(  ) {
       return mOBFrame_.fps;
    }
    void setFPS(const int fps) {
        mOBFrame_.fps = fps;
    }
    void setOBFrame( const OBFrame& obFrame ) {
        mOBFrame_ = obFrame;
    }
    void getOBFrame( OBFrame& obFrame ) const {
        obFrame = mOBFrame_;
    }
    void setFrameFormat( const OBFormat& pFormat ) {
        mOBFrame_.pixelFormat = pFormat;
    }
    OBFormat getFrameFormat() {
        return mOBFrame_.pixelFormat;
    }
    ~Frame() {
        subRef();
    }
    typedef void ( *backToAvailableQueueFun )( Frame* pFrame, void* pCookie );
    void addReleaseCallback( backToAvailableQueueFun pfun, void* pCookie ) {
        pCookie_          = pCookie;
        frameBackToQueue_ = pfun;
    }

private:
    std::atomic_int         refCount_{ 0 };
    OBFrame                 mOBFrame_{ 0 };
    backToAvailableQueueFun frameBackToQueue_;
    void*                   pCookie_;
    std::mutex              frameMutex_;
};

}  // namespace libobsensor
