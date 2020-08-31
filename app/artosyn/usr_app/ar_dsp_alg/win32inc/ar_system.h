/*
 * =====================================================================================
 *
 *   Filename:  ar_message_id.h
 *   Description:  wrap to broadcast freertos messages
 *   Author:  Qiuyc (qiuyc), yongchengq@artosyn.cn
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef _AR_SYSTEM_H_
#define _AR_SYSTEM_H_
#include <stdint.h>
#include <stdbool.h>

#define AR_FRAME_BUFFER_PANELS_MAX     3

/* video width or height stride */
#define AR_VIDEO_BURST_LENGTH                       16
#define AR_VIDEO_LUMA_ALIGN                        (AR_VIDEO_BURST_LENGTH*2*16)
#define AR_VIDEO_CHROMA_ALIGN                      (AR_VIDEO_BURST_LENGTH*16)


#define AR_VIDEO_FORMAT_SUPPORT_NUM_MAX       32
#define AR_AUDIO_FORMAT_SUPPORT_NUM_MAX       32

typedef enum {
    AR_VIDEO_FORMAT_UNKNOWN = 0,  //
    /* YUV 8 bit*/
    AR_VIDEO_FORMAT_I400,
    AR_VIDEO_FORMAT_I420,  // Planar 4:2:0 YUV
    AR_VIDEO_FORMAT_YV12,  // Planar 4:2:0 YVU (like I420 but UV swapped)
    AR_VIDEO_FORMAT_NV12,  // Planar 4:2:0 YUV with interleaved UV plane
    AR_VIDEO_FORMAT_NV21,  // Planar 4:2:0 YUV with interleaved VU plane
    AR_VIDEO_FORMAT_Y42B,  // Planar 4:2:2 YUV
    AR_VIDEO_FORMAT_YUYV,  // Packed 4:2:2 YUV(Y0-U0-Y1-V0 Y2-U1-Y3-V1 ....)
    AR_VIDEO_FORMAT_YVYU,  // Packed 4:2:2 YUV(Y0-V0-Y1-U0 Y2-V1-Y3-U1 ....)
    AR_VIDEO_FORMAT_Y444,  // Planar 4:4:4 YUV

    /* YUV 10 bit, save as 16bit for per component, little endian */
    AR_VIDEO_FORMAT_I420_P10_16BIT_LE,  // Planar 4:2:0 YUV
    AR_VIDEO_FORMAT_YV12_P10_16BIT_LE,  // Planar 4:2:0 YVU (like I420 but UV swapped)
    AR_VIDEO_FORMAT_NV12_P10_16BIT_LE,  // Planar 4:2:0 YUV with interleaved UV plane
    AR_VIDEO_FORMAT_NV21_P10_16BIT_LE,  // Planar 4:2:0 YUV with interleaved VU plane
    AR_VIDEO_FORMAT_Y42B_P10_16BIT_LE,  // Planar 4:2:2 YUV
    AR_VIDEO_FORMAT_YUYV_P10_16BIT_LE,  // Packed 4:2:2 YUV(Y0-U0-Y1-V0 Y2-U1-Y3-V1 ....)
    AR_VIDEO_FORMAT_YVYU_P10_16BIT_LE,  // Packed 4:2:2 YUV(Y0-V0-Y1-U0 Y2-V1-Y3-U1 ....)
    AR_VIDEO_FORMAT_Y444_P10_16BIT_LE,  // Planar 4:4:4 YUV
    /* YUV 10 bit, save as 16bit for per component, big endian */
    AR_VIDEO_FORMAT_I420_P10_16BIT_BE,  // Planar 4:2:0 YUV
    AR_VIDEO_FORMAT_YV12_P10_16BIT_BE,  // Planar 4:2:0 YVU (like I420 but UV swapped)
    AR_VIDEO_FORMAT_NV12_P10_16BIT_BE,  // Planar 4:2:0 YUV with interleaved UV plane
    AR_VIDEO_FORMAT_NV21_P10_16BIT_BE,  // Planar 4:2:0 YUV with interleaved VU plane
    AR_VIDEO_FORMAT_Y42B_P10_16BIT_BE,  // Planar 4:2:2 YUV
    AR_VIDEO_FORMAT_YUYV_P10_16BIT_BE,  // Packed 4:2:2 YUV(Y0-U0-Y1-V0 Y2-U1-Y3-V1 ....)
    AR_VIDEO_FORMAT_YVYU_P10_16BIT_BE,  // Packed 4:2:2 YUV(Y0-V0-Y1-U0 Y2-V1-Y3-U1 ....)
    AR_VIDEO_FORMAT_Y444_P10_16BIT_BE,  // Planar 4:4:4 YUV

    /* YUV 10 bit, save as 32bit for 3 components, little endian */
    AR_VIDEO_FORMAT_I420_P10_32BIT_LE,  // Planar 4:2:0 YUV
    AR_VIDEO_FORMAT_YV12_P10_32BIT_LE,  // Planar 4:2:0 YVU (like I420 but UV swapped)
    AR_VIDEO_FORMAT_NV12_P10_32BIT_LE,  // Planar 4:2:0 YUV with interleaved UV plane
    AR_VIDEO_FORMAT_NV21_P10_32BIT_LE,  // Planar 4:2:0 YUV with interleaved VU plane
    AR_VIDEO_FORMAT_Y42B_P10_32BIT_LE,  // Planar 4:2:2 YUV
    AR_VIDEO_FORMAT_YUYV_P10_32BIT_LE,  // Packed 4:2:2 YUV(Y0-U0-Y1-V0 Y2-U1-Y3-V1 ....)
    AR_VIDEO_FORMAT_YVYU_P10_32BIT_LE,  // Packed 4:2:2 YUV(Y0-V0-Y1-U0 Y2-V1-Y3-U1 ....)
    AR_VIDEO_FORMAT_Y444_P10_32BIT_LE,  // Planar 4:4:4 YUV
    /* YUV 10 bit, save as 32bit for 3 components, big endian */
    AR_VIDEO_FORMAT_I420_P10_32BIT_BE,  // Planar 4:2:0 YUV
    AR_VIDEO_FORMAT_YV12_P10_32BIT_BE,  // Planar 4:2:0 YVU (like I420 but UV swapped)
    AR_VIDEO_FORMAT_NV12_P10_32BIT_BE,  // Planar 4:2:0 YUV with interleaved UV plane
    AR_VIDEO_FORMAT_NV21_P10_32BIT_BE,  // Planar 4:2:0 YUV with interleaved VU plane
    AR_VIDEO_FORMAT_Y42B_P10_32BIT_BE,  // Planar 4:2:2 YUV
    AR_VIDEO_FORMAT_YUYV_P10_32BIT_BE,  // Packed 4:2:2 YUV(Y0-U0-Y1-V0 Y2-U1-Y3-V1 ....)
    AR_VIDEO_FORMAT_YVYU_P10_32BIT_BE,  // Packed 4:2:2 YUV(Y0-V0-Y1-U0 Y2-V1-Y3-U1 ....)
    AR_VIDEO_FORMAT_Y444_P10_32BIT_BE,  // Planar 4:4:4 YUV

    /* RGB */
    AR_VIDEO_FORMAT_RGB, //
    /* RGB 10 bit, save as 16bit for per component */
    AR_VIDEO_FORMAT_RGB_P10_16BIT_LE,
    AR_VIDEO_FORMAT_RGB_P10_16BIT_BE,
    /* RGB 10 bit, save as 32bit for 3 components */
    AR_VIDEO_FORMAT_RGB_P10_32BIT_LE,
    AR_VIDEO_FORMAT_RGB_P10_32BIT_BE,

    /* RAW */
    AR_VIDEO_FORMAT_RAW_RGGB_P8,
    AR_VIDEO_FORMAT_RAW_BGGR_P8,
    AR_VIDEO_FORMAT_RAW_GRBG_P8,
    AR_VIDEO_FORMAT_RAW_GBRG_P8,


    AR_VIDEO_FORMAT_RAW_RGGB_P10,
    AR_VIDEO_FORMAT_RAW_BGGR_P10,
    AR_VIDEO_FORMAT_RAW_GRBG_P10,
    AR_VIDEO_FORMAT_RAW_GBRG_P10,

    AR_VIDEO_FORMAT_RAW_RGGB_P12,
    AR_VIDEO_FORMAT_RAW_BGGR_P12,
    AR_VIDEO_FORMAT_RAW_GRBG_P12,
    AR_VIDEO_FORMAT_RAW_GBRG_P12,

    AR_VIDEO_FORMAT_RAW_RGGB_P14,
    AR_VIDEO_FORMAT_RAW_BGGR_P14,
    AR_VIDEO_FORMAT_RAW_GRBG_P14,
    AR_VIDEO_FORMAT_RAW_GBRG_P14,

    /* RAW 10 bit, save as 16bit for per component, little endian */
    AR_VIDEO_FORMAT_RAW_RGGB_P10_16BIT_LE,
    AR_VIDEO_FORMAT_RAW_BGGR_P10_16BIT_LE,
    AR_VIDEO_FORMAT_RAW_GRBG_P10_16BIT_LE,
    AR_VIDEO_FORMAT_RAW_GBRG_P10_16BIT_LE,
    /* RAW 10 bit, save as 32 bit for 3 components, little endian */
    AR_VIDEO_FORMAT_RAW_RGGB_P10_32BIT_LE,
    AR_VIDEO_FORMAT_RAW_BGGR_P10_32BIT_LE,
    AR_VIDEO_FORMAT_RAW_GRBG_P10_32BIT_LE,
    AR_VIDEO_FORMAT_RAW_GBRG_P10_32BIT_LE,

    AR_VIDEO_FORMAT_YUV422_SEMI_PLANNAR,  // Planar 4:2:2 YUV with interleaved UV plane
    AR_VIDEO_FORMAT_YUV422_SEMI_PLANNAR_P10_16BIT_LE,  // Planar 4:2:2 YUV with interleaved UV plane
    AR_VIDEO_FORMAT_YUV444_SEMI_PLANNAR_P10_16BIT_LE,  // Planar 4:4:4 YUV with interleaved UV plane
    AR_VIDEO_FORMAT_YUV422_SEMI_PLANNAR_P10_32BIT_LE,  // Planar 4:2:2 YUV with interleaved UV plane

    AR_VIDEO_FORMAT_Y420_CF50_P8_PLANNAR,
    AR_VIDEO_FORMAT_Y420_CF50_P10_PLANNAR,

    AR_VIDEO_FORMAT_MAX
} ar_video_format_t;

typedef enum {
    AR_VIDEO_MATRIX_BT601_FULL,
    AR_VIDEO_MATRIX_BT601_LIMIT,
    AR_VIDEO_MATRIX_BT709_FULL,
    AR_VIDEO_MATRIX_BT709_LIMIT,
    AR_VIDEO_MATRIX_MAX,
} ar_video_matrix_t;

typedef enum {
    AR_AUDIO_FORMAT_UNKNOWN = 0,
    /* 8 bit */
    AR_AUDIO_FORMAT_PCM_S8,   // 8 bit in 8 bit, signed
    AR_AUDIO_FORMAT_PCM_U8,   // 8 bit in 8 bit, unsigned
    /* 16bit */
    AR_AUDIO_FORMAT_PCM_S16LE,   // 16 bit in 16 bit, signed, little endian
    AR_AUDIO_FORMAT_PCM_S16BE,   // 16 bit in 16 bit, signed, big endian
    AR_AUDIO_FORMAT_PCM_U16LE,   // 16 bit in 16 bit, unsigned, little endian
    AR_AUDIO_FORMAT_PCM_U16BE,   // 16 bit in 16 bit, unsigned, big endian
    /* 24bit in low 3 bytes of 32bit */
    AR_AUDIO_FORMAT_PCM_S24_32LE,   // 24 bit in 32 bit, signed, little endian
    AR_AUDIO_FORMAT_PCM_S24_32BE,   // 24 bit in 32 bit, signed, big endian
    AR_AUDIO_FORMAT_PCM_U24_32LE,   // 24 bit in 32 bit, unsigned, little endian
    AR_AUDIO_FORMAT_PCM_U24_32BE,   // 24 bit in 32 bit, unsigned, big endian
    /* 32bit */
    AR_AUDIO_FORMAT_PCM_S32LE,   // 32 bit in 32 bit, signed, little endian
    AR_AUDIO_FORMAT_PCM_S32BE,   // 32 bit in 32 bit, signed, big endian
    AR_AUDIO_FORMAT_PCM_U32LE,   // 32 bit in 32 bit, unsigned, little endian
    AR_AUDIO_FORMAT_PCM_U32BE,   // 32 bit in 32 bit, unsigned, big endian

    AR_AUDIO_FORMAT_MAX
} ar_audio_format_t;

typedef enum {
    AR_STREAM_TYPE_UNKNOWN = 0,
    AR_STREAM_TYPE_VIDEO,
    AR_STREAM_TYPE_AUDIO,
    AR_STREAM_TYPE_USER_DATA
} ar_stream_type_t;

typedef enum {
    AR_SYSTEM_AV_MODE_BOTH_AV        = 0,
    AR_SYSTEM_AV_MODE_VIDEO_ONLY   = 1,
    AR_SYSTEM_AV_MODE_AUDIO_ONLY  = 2,
} ar_system_av_mode_t;

typedef enum {
    AR_SYSTEM_ENDPOINT_UNKNOWN     = 0,
    AR_SYSTEM_ENDPOINT_SRC                  = 1,
    AR_SYSTEM_ENDPOINT_SINK                = 2,
} ar_system_endpoint_t;

typedef enum  {
    AR_SYSTEM_LOWDELAY_SRC_INVALID = 0,
    AR_SYSTEM_LOWDELAY_SRC_ISP = 1,
    AR_SYSTEM_LOWDELAY_SRC_VIF = 2,
} ar_system_lowdelay_src_t;

typedef enum
{
   AR_SYSTEM_INTERLACE_FILED_NULL,
   AR_SYSTEM_INTERLACE_FILED_ODD,
   AR_SYSTEM_INTERLACE_FILED_EVEN,
   AR_SYSTEM_INTERLACE_FILED_INVAILD,
} ar_video_field_type_t;

enum{
    AR_SYSTEM_INTERLACE_MOD_1080I,
    AR_SYSTEM_INTERLACE_MOD_720_576I_PAL,
    AR_SYSTEM_INTERLACE_MOD_720_480I_NTSC,
    AR_SYSTEM_INTERLACE_MOD_NULL,
};

typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t fps_num;
    uint32_t fps_den;
    /* todo add other field */
} ar_video_timing_info_t;

typedef struct {
    uint32_t format; /* refer to different color space definition ar_video_format_t in ar_system.h */
    uint32_t width;
    uint32_t height;
    uint32_t fps_num;
    uint32_t fps_den;
    uint32_t luma_stride;
    uint32_t chroma_stride;
    uint32_t is_interlace;
} ar_video_format_info_t; /* for encoder to config cam */

typedef struct {
    uint32_t format;
    uint32_t rate;
    uint32_t channels;
} ar_audio_format_info_t;

typedef struct {
    uint8_t* addr;
    uint32_t length;
} ar_mem_t;

typedef struct __ar_frame_buffer_t__ ar_frame_buffer_t;

struct __ar_frame_buffer_t__{
    uint32_t frame_idx;
    uint32_t lowdelay_id;
    int pannel_count;
    ar_mem_t buffer[AR_FRAME_BUFFER_PANELS_MAX];
    uint64_t pts;
    void* user_data;
    void (*postprocess)(ar_frame_buffer_t *frame_buffer, void* user_data);
};
typedef struct __ar_audio_buffer_t__ ar_audio_buffer_t;

struct __ar_audio_buffer_t__{
    ar_mem_t buffer;
    uint64_t pts;
    void* user_data;
    void (*postprocess)(ar_audio_buffer_t *audio_buf, void* user_data);
};

#endif // _AR_SYSTEM_H_
