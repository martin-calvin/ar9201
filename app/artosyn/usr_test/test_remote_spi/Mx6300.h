#ifndef _MX6300_H_
#define _MX6300_H_
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */
typedef uint32_t HI_U32;
typedef uint16_t HI_U16;
typedef struct _MX6300_Cmd_Addr_Val{
	HI_U32 Cmd;
	HI_U16 Addr;
}MX6300_CMD_ADDR_VAL;

#define DATA_WIDTH8_FLAG  0x10000
#define MX6300_CMD_GET_DEVICE_ID_ADDR 0x00
#define MX6300_CMD_GET_FW_VER_ADDR 0x02
#define MX6300_CMD_GET_HD_VER_ADDR 0x05

#define MX6300_CMD_SET_DEV_CTL_ADDR 0x18
#define MX6300_CMD_SET_AE_STATE_ADDR 0x1A
//depth
#define MX6300_CMD_SET_DEPTH_STATE_ADDR 0x2C
#define MX6300_CMD_GET_DEPTH_STATE_ADDR 0x2C

#define MX6300_CMD_SET_DEPTH_LOAD_ADDR 0x2D
#define MX6300_CMD_GET_DEPTH_RES_ADDR 0x2F
#define MX6300_CMD_GET_DEPTH_PIXFMT_ADDR 0x30
#define MX6300_CMD_GET_DEPTH_FPS_ADDR 0x31

#define MX6300_CMD_SET_DEPTH_RES_ADDR 0x33
#define MX6300_CMD_SET_DEPTH_PIXFMT_ADDR 0x34
#define MX6300_CMD_SET_DEPTH_FPS_ADDR 0x35

#define MX6300_CMD_SET_DEPTH_BYPASS_ADDR 0x38

//ir
#define MX6300_CMD_SET_IR_STATE_ADDR 0x54
#define MX6300_CMD_GET_IR_STATE_ADDR 0x54

#define MX6300_CMD_SET_IR_LOAD_ADDR 0x55
#define MX6300_CMD_GET_IR_RES_ADDR 0x57
#define MX6300_CMD_GET_IR_PIXFMT_ADDR 0x58
#define MX6300_CMD_GET_IR_FPS_ADDR 0x59

#define MX6300_CMD_SET_IR_RES_ADDR 0x5B
#define MX6300_CMD_SET_IR_PIXFMT_ADDR 0x5C
#define MX6300_CMD_SET_IR_FPS_ADDR 0x5D

//laser
#define MX6300_CMD_GET_LASER_MODE_ADDR 0xD8
#define MX6300_CMD_SET_LASER_MODE_ADDR 0xD8

//flood led
#define MX6300_CMD_GET_FLOOD_MODE_ADDR 0xD9
#define MX6300_CMD_SET_FLOOD_MODE_ADDR 0xD9

#define MX6300_CMD_GET_PULSE_WIDTH_ADDR 0xEA
#define MX6300_CMD_SET_PULSE_WIDTH_ADDR 0xEA

//raw cmd
#define MX6300_RAW_CMD_GET_IR_HTS_ADDR 0xF000
#define MX6300_RAW_CMD_SET_IR_HTS_ADDR 0xF000

#define MX6300_RAW_CMD_GET_IR_VTS_ADDR 0xF004
#define MX6300_RAW_CMD_SET_IR_VTS_ADDR 0xF004

#define MX6300_RAW_CMD_GET_IR_GAIN_ADDR 0xF018
#define MX6300_RAW_CMD_SET_IR_GAIN_ADDR 0xF008

#define MX6300_RAW_CMD_GET_IR_EXPO_ADDR 0xF01C
#define MX6300_RAW_CMD_SET_IR_EXPO_ADDR 0xF00C

#define MX6300_RAW_CMD_GET_IR_FLIP_ADDR 0xF010
#define MX6300_RAW_CMD_SET_IR_FLIP_ADDR 0xF010

#define MX6300_RAW_CMD_GET_IR_MIRROR_ADDR 0xF02C
#define MX6300_RAW_CMD_SET_IR_MIRROR_ADDR 0xF014

#define MX6300_RAW_CMD_GET_POSTFILTER 0xF100
#define MX6300_RAW_CMD_SET_POSTFILTER 0xF100

#define MX6300_RAW_CMD_GET_POSTFILTER_NCOST_THRESH 0xF104
#define MX6300_RAW_CMD_SET_POSTFILTER_NCOST_THRESH  0xF104

#define MX6300_RAW_CMD_GET_THRESHFILTER 0xF108
#define MX6300_RAW_CMD_SET_THRESHFILTER 0xF108

#define MX6300_RAW_CMD_GET_THRESHFILTER_THRESH 0xF10C
#define MX6300_RAW_CMD_SET_THRESHFILTER_THRESH 0xF10C

#define MX6300_RAW_CMD_GET_DEPTH_MIRROR 0xF134
#define MX6300_RAW_CMD_SET_DEPTH_MIRROR 0xF110

#define MX6300_RAW_CMD_GET_DEPTH_D2C 0xF114
#define MX6300_RAW_CMD_SET_DEPTH_D2C 0xF114


#define MX6300_RAW_CMD_GET_DEPTH_HOLE_FILTER 0xF118
#define MX6300_RAW_CMD_SET_DEPTH_HOLE_FILTER 0xF118

#define MX6300_RAW_CMD_GET_DEPTH_BASELINE 0xF11C
#define MX6300_RAW_CMD_GET_DEPTH_ZPD 0xF120
#define MX6300_RAW_CMD_GET_DEPTH_DEFAULT_ZZPS 0xF124
#define MX6300_RAW_CMD_GET_DEPTH_FX 0xF128

#define MX6300_RAW_CMD_GET_DEPTH_POSTFILTER_THRESHOLD 0xF12C
#define MX6300_RAW_CMD_SET_DEPTH_POSTFILTER_THRESHOLD 0xF12C

#define MX6300_RAW_CMD_GET_DEPTH_D2C_PARAM 0xF130

#define MX6300_RAW_CMD_GET_LASER_LDMP_CURRENT 0xF200
#define MX6300_RAW_CMD_SET_LASER_LDMP_CURRENT 0xF200

#define MX6300_RAW_CMD_GET_FLOOD_LED_CURRENT 0xF204
#define MX6300_RAW_CMD_SET_FLOOD_LED_CURRENT 0xF204

#define MX6300_RAW_CMD_GET_LDP_PROTECT_STATUS 0xF208
#define MX6300_RAW_CMD_SET_LDP_ENALBE_STATUS 0xF20C
#define MX6300_RAW_CMD_GET_LDP_ENALBE_STATUS 0xF210
#define MX6300_RAW_CMD_GET_LDP_DATA  0xF214
#define MX6300_RAW_CMD_GET_LDP_SCALE  0xF218
#define MX6300_RAW_CMD_SET_LDP_SCALE 0xF21C

#define MX6300_RAW_CMD_SET_RECTIFY_ENABLE  0xF240
#define MX6300_RAW_CMD_GET_RECTIFY_ENABLE  0xF244
#define MX6300_RAW_CMD_SET_TCA_ENABLE  0xF26C
#define MX6300_RAW_CMD_GET_TCA_ENABLE  0xF26C

typedef enum hiMAPI_ORBBEC_CMD_TYPE_E {
    HI_MAPI_ORBBRC_CMD_TYPE_GET_DEV_ID = 0,
    HI_MAPI_ORBBRC_CMD_TYPE_GET_FW_VER = 1,
    HI_MAPI_ORBBRC_CMD_TYPE_GET_HD_VER = 2,

    HI_MAPI_ORBBRC_CMD_TYPE_DEPTH_STATE = 3,
    HI_MAPI_ORBBRC_CMD_TYPE_DEPTH_ON = 3,
    HI_MAPI_ORBBRC_CMD_TYPE_DEPTH_RES = 4,
    HI_MAPI_ORBBRC_CMD_TYPE_DEPTH_FPS = 5,
    HI_MAPI_ORBBRC_CMD_TYPE_DEPTH_PIXFMT = 6,

    HI_MAPI_ORBBRC_CMD_TYPE_IR_STATE = 7,
    HI_MAPI_ORBBRC_CMD_TYPE_IR_RES = 8,
    HI_MAPI_ORBBRC_CMD_TYPE_IR_FPS = 9,
    HI_MAPI_ORBBRC_CMD_TYPE_IR_PIXFMT = 10,

    HI_MAPI_ORBBRC_CMD_TYPE_LASER_STATE = 11,
    HI_MAPI_ORBBRC_CMD_TYPE_LASER_CURRENT = 12,
    HI_MAPI_ORBBRC_CMD_TYPE_LASER_PULSE_WIDTH = 13,



	  HI_MAPI_ORBBRC_CMD_TYPE_FLOODLED_STATE = 17,
    HI_MAPI_ORBBRC_CMD_TYPE_FLOODLED_CURRENT = 18,

    HI_MAPI_ORBBRC_CMD_TYPE_IR_HTS = 19,
    HI_MAPI_ORBBRC_CMD_TYPE_IR_VTS = 20,
    HI_MAPI_ORBBRC_CMD_TYPE_IR_GAIN = 21,
    HI_MAPI_ORBBRC_CMD_TYPE_IR_EXPO = 22,
    HI_MAPI_ORBBRC_CMD_TYPE_IR_FLIP = 23,
    HI_MAPI_ORBBRC_CMD_TYPE_IR_MIRROR = 24,
    HI_MAPI_ORBBRC_CMD_TYPE_THRESHFILTER = 25,
    HI_MAPI_ORBBRC_CMD_TYPE_THRESHFILTER_THRESH = 26,
    HI_MAPI_ORBBRC_CMD_TYPE_DEP_HOLE_FILTER = 27,
    HI_MAPI_ORBBRC_CMD_TYPE_DEPTH_BASELINE = 28,
    HI_MAPI_ORBBRC_CMD_TYPE_DEPTH_ZPD = 29,
    HI_MAPI_ORBBRC_CMD_TYPE_DEPTH_DEFAULT_ZZPS = 30,
    HI_MAPI_ORBBRC_CMD_TYPE_DEPTH_FX = 31,
    HI_MAPI_ORBBRC_CMD_TYPE_DEPTH_POSTFILTER_THRESHOLD = 32,
    HI_MAPI_ORBBRC_CMD_TYPE_DEPTH_D2C_PARAM = 33,
    HI_MAPI_ORBBRC_CMD_TYPE_LASER_LDMP_CURRENT = 34,

	HI_MAPI_ORBBRC_CMD_TYPE_LDP_PROTECT_STATUS = 35,
	HI_MAPI_ORBBRC_CMD_TYPE_LDP_ENABLE_STATUS = 36,
	HI_MAPI_ORBBRC_CMD_TYPE_LDP_DATA = 37,
	HI_MAPI_ORBBRC_CMD_TYPE_LDP_SCALE = 38,


} HI_MAPI_ORBBEC_CMD_TYPE_E;
typedef enum _mx6000_vc0_params {
    DISABLE_STREAM = 0x00,
    DEPTH_STREAM_ON_VC0 = 0x01,
    IR_STREAM_ON_VC0 = 0x02,
    BYPASS_ON_VC0 = 0x03,
    TEST_PATTERN_ON_VC0 = 0x04,
    IR_DEPTH_INTERLEAVE_VC0 = 0x10,
    DEPTH_VC0_IR_VC1 = 0x11,
    IR_VC0_DEPTH_VC1 = 0x12
} mx6000_vc0_params_t;

typedef enum _mx6300_ir_stream_status {
    IR_STREAM_STATUS_INIT = 0x00,
    IR_STREAM_STATUS_STANDBY = 0x01,
    IR_STREAM_STATUS_STREAMING = 0x02,
    IR_STREAM_STATUS_SLEEP = 0x03
} mx6300_ir_stream_status_t;

typedef enum _mx6300_depth_stream_status {
    DEPTH_STREAM_STATUS_INIT = 0x00,
    DEPTH_STREAM_STATUS_STANDBY = 0x01,
    DEPTH_STREAM_STATUS_STREAMING = 0x02,
    DEPTH_STREAM_STATUS_SLEEP = 0x03
} mx6300_depth_stream_status_t;

typedef enum _mx6300_ae_state {
  AE_DISABLE = 0x0,
  AE_INITIAL = 0x01,
  AE_STATISTICS = 0x02,
  AE_APPLY = 0x03
} mx6300_ae_state;
typedef enum _mx6300_ir_stream_resolution {
  IR_STREAM_RES_1280X800 = 0x10,
  IR_STREAM_RES_640X400 = 0x11,
  IR_STREAM_RES_800X1280 = 0x12,
  IR_STREAM_RES_400X640 = 0x13
} mx6300_ir_stream_resolution_t;

typedef enum _mx6300_depth_stream_resolution {
    DEPTH_STREAM_RES_1280X800 = 0x10,
    DEPTH_STREAM_RES_640X400 = 0x11,
    DEPTH_STREAM_RES_800X1280 = 0x12,
    DEPTH_STREAM_RES_400X640 = 0x13
} mx6300_depth_stream_resolution_t;

typedef enum _mx6300_ir_pixel_format {
    IR_PIXEL_FORMAT_RAW12 = 0x04,
    IR_PIXEL_FORMAT_RAW10 = 0x1E
} mx6300_ir_pixel_format_t;

typedef enum _mx6300_depth_pixel_format {
    DEPTH_PIXEL_FORMAT_RAW12 = 0x04,
    DEPTH_PIXEL_FORMAT_RAW10 = 0x1E
} mx6300_depth_pixel_format_t;

typedef enum _mx6300_ir_load {
    IR_LOAD_PARAMETERS = 0x01
} mx6300_ir_load_t;

typedef enum _mx6300_depth_load {
    DEPTH_LOAD_PARAMETERS = 0x01
} mx6300_depth_load_t;

typedef enum _mx6300_depth_bypass_selection {
    BYPASS_SEL_NONE = 0x00,
    BYPASS_SEL_DREF = 0x01,
    BYPASS_SEL_DORI = 0x02
} mx6300_depth_bypass_selection_t;


/*int32_t mx6300_get_status(uint16_t regaddr,uint8_t *status);

int32_t mx6300_flash_read_n_doubleword(uint32_t flashaddr,uint8_t len,uint32_t *val);

int32_t mx6300_flash_write_n_doubleword(uint32_t flashaddr,uint8_t len,uint32_t *val);

int32_t mx6300_flash_erase(uint32_t flashaddr,uint32_t len);

int32_t mx6300_ahb_read(uint32_t addr,uint32_t *val);

int32_t mx6300_ahb_write(uint32_t addr,uint32_t val);

int32_t mx6300_get_firmware_version(uint8_t *fwver);

int32_t mx6300_set_out_stream_source(mx6300_vc0_params_t val);

int32_t mx6300_depth_load(mx6300_depth_load_t val);

int32_t mx6300_depth_get_stream_status(mx6300_depth_stream_status_t *val);

int32_t mx6300_depth_set_resolution(mx6300_depth_stream_resolution_t val);

int32_t mx6300_depth_get_resolution(mx6300_depth_stream_resolution_t *val);

int32_t mx6300_depth_set_pixel_format(mx6300_depth_pixel_format_t val);

int32_t mx6300_depth_get_pixel_format(mx6300_depth_pixel_format_t *val);

int32_t mx6300_depth_set_framerate(uint32_t val);

int32_t mx6300_depth_get_framerate(uint32_t *val);

int32_t mx6300_depth_set_bypass_selection(mx6300_depth_bypass_selection_t val);

int32_t mx6300_depth_get_bypass_selection(mx6300_depth_bypass_selection_t *val);

int32_t mx6300_ir_get_stream_status(mx6300_ir_stream_status_t *val);

int32_t mx6300_ir_set_resolution(mx6300_ir_stream_resolution_t val);

int32_t mx6300_ir_get_resolution(mx6300_ir_stream_resolution_t *val);

int32_t mx6300_ir_set_pixel_format(mx6300_ir_pixel_format_t val);

int32_t mx6300_ir_get_pixel_format(mx6300_ir_pixel_format_t *val);

int32_t mx6300_ir_load(mx6300_ir_load_t val);

int32_t mx6300_ir_set_framerate(uint32_t val);

int32_t mx6300_ir_get_framerate(uint32_t *val);

*/

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif
