#include "sample_comm.h"
#include "common_def.h"
#ifndef _MX6300_CTL_H_
#define _MX6300_CTL_H_
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */
//##############################################################################
// SysInfo
//##############################################################################

/**
* HI_S32 Mx6300_get_device_id(); 获取设备ID
* return： -1 失败 <TBD>设备ID
*/
HI_S32 Mx6300_get_device_id(HI_U16 *dev_Id); //0x00

/**
* HI_S32 Mx6300_read_fw_version(); 获取版本号

* return： -1 失败
*  高16位为固件版本号， 低16位为硬件版本号
*/
HI_S32 Mx6300_read_fw_version(HI_CHAR *fw);
HI_S32 Mx6300_read_hw_version(HI_U8 *hw_ver);
/**
* char * Mx6300_get_serial_number(); 获取SN号
* return： NULL 失败， Others:16Byte的SN
* 注意： 调用该函数要注意释放内存, 如：
*  char *sn = Mx6300_get_serial_number();
*  if(sn != NULL) free(sn);
*/

HI_S32 Mx6300_get_sn(HI_S8 *sn);

//##############################################################################
// CameraParams
//##############################################################################
HI_S32 Mx6300_get_depth_baseline(HI_FLOAT *res);
HI_S32 Mx6300_get_depth_zpd(HI_FLOAT *res);
HI_S32 Mx6300_get_depth_zzps(HI_FLOAT *res);
HI_S32 Mx6300_get_depth_fx(HI_FLOAT *res); //32bit Get Fx.

HI_S32 Mx6300_get_depth_resolution(HI_U8 *res);
HI_S32 Mx6300_get_ir_resolution(HI_U8 *res);
HI_S32 Mx6300_get_depth_fps(HI_U8 *res);
HI_S32 Mx6300_get_ir_fps(HI_U8 *res);

HI_S32 Mx6300_set_depth_resolution(HI_U8 res);
HI_S32 Mx6300_set_ir_resolution(HI_U8 res);
HI_S32 Mx6300_set_depth_fps(HI_U8 value);
HI_S32 Mx6300_set_ir_fps(HI_U8 value);
typedef enum _Resolution_State
{
  RES_1280X800 = 0x0,
  RES_640X400 = 0x1,
  RES_800X1280 = 0x2,
  RES_400X640 = 0x3,
} Resolution_State;
typedef struct _OBCameraParams
{
    HI_FLOAT l_intr_p[4]; //[fx,fy,cx,cy]
    HI_FLOAT r_intr_p[4]; //[fx,fy,cx,cy]
    HI_FLOAT r2l_r[9];    //[r00,r01,r02;r10,r11,r12;r20,r21,r22]
    HI_FLOAT r2l_t[3];    //[t1,t2,t3]
    HI_FLOAT l_k[5];      //[k1,k2,p1,p2,k3]
    HI_FLOAT r_k[5];
    //intis_mirror;
} OBCameraParams;

OBCameraParams Mx6300_read_param();

//#pragma pack(push)
//#pragma pack(1)

/**
* @brief Dual相机内外参
*/
typedef struct _OBIntrinsicRefinement
{
	HI_U8     refinement_[2016];
}OBIntrinsicRefinement;

typedef struct _OBCameraIntrinsic
{
	HI_U32    vc_mode_;       /// AF摄像头的VC值
	HI_U32    img_height_;    /// 图像高
	HI_U32    img_width_;     /// 图像宽
	HI_FLOAT       focal_x_;       /// x方向焦距
	HI_FLOAT       focal_y_;       /// y方向焦距
	HI_FLOAT       cx_;            /// 主点x坐标
	HI_FLOAT       cy_;            /// 主点y坐标
	HI_FLOAT       k1_;            /// 径向畸变系数k1-k4
	HI_FLOAT       k2_;
	HI_FLOAT       k3_;
	HI_FLOAT       k4_;
	HI_FLOAT       p1_;            /// 切向畸变系数p1-p2
	HI_FLOAT       p2_;
	OBIntrinsicRefinement refine_;    // refinement参数
}OBCameraIntrinsic;

typedef struct _OBRelativePose
{
	HI_FLOAT   rx_;    // x方向旋转分量
	HI_FLOAT   ry_;    // y方向旋转分量
	HI_FLOAT   rz_;    // z方向旋转分量
	HI_FLOAT   tx_;    // x方向平移分量
	HI_FLOAT   ty_;    // y方向平移分量
	HI_FLOAT   tz_;    // z方向平移分量
}OBRelativePose;

typedef struct _OBCameraDualPara {
	struct {
		struct {
			HI_U32 buf_pos : 12;		//0-11
			HI_U32 totalBufRows : 12;	//12-23
			HI_U32 rsv0 : 6;			//24-29
			HI_U32 dep_sign : 1;		//30
			HI_U32 shft_dep : 1;		//31

			HI_U32 iZ0;
			HI_U32 PBF;
			HI_U32 W[12];
		}dep2color;
		struct {
			HI_U32 k[9];
			HI_U32 r[9];
			HI_U32 fx;
			HI_U32 fy;
			HI_U32 cx;
			HI_U32 cy;
		}mdlCamL;
		struct {
			HI_U32 k[9];
			HI_U32 r[9];
			HI_U32 fx;
			HI_U32 fy;
			HI_U32 cx;
			HI_U32 cy;
		}mdlCamR;
		struct {
			HI_U32 dY;
			HI_U32 dT;
			HI_U32 iRow;
			HI_U32 img_size;
		}mdlRef;
		struct {
			HI_U32 cam : 16;
			HI_U32 ref : 16;
		}startPixBuf;
	}DPU;
	struct {
		struct {
			HI_U32 w, h;
			HI_FLOAT fx, fy, cx, cy, bl;
			HI_FLOAT rotL[3];
			HI_FLOAT rotR[3];
		}virCam;
		struct {
			OBCameraIntrinsic	irL;
			OBCameraIntrinsic	irR;
			OBCameraIntrinsic	rgb;
			OBRelativePose		irL_pose;
			OBRelativePose		irR_pose;
			OBRelativePose		rgb_pose;

		}camera_params;
		struct {
			HI_FLOAT d_intr_p[4];//[fx,fy,cx,cy]
			HI_FLOAT c_intr_p[4];//[fx,fy,cx,cy]
			HI_FLOAT d2c_r[9];//[r00,r01,r02;r10,r11,r12;r20,r21,r22]
			HI_FLOAT d2c_t[3];//[t1,t2,t3]
			HI_FLOAT d_k[5];//[k1,k2,k3,p1,p2]
			HI_FLOAT c_k[5];
			//HI_FLOAT pixelsize;
		}soft_d2c;
	}HOST;
}OBCameraDualPara;

OBCameraDualPara Mx6300_read_dual_param();


HI_S32 Mx6300_Stream_control(HI_U8 value); //0x18 1=on, 0=off

//##############################################################################
// laser * flood * ldp
//##############################################################################
HI_S32 Mx6300_laser_control(HI_U8 value); 				// 0xd8  1为打开， 0为关闭
HI_S32 Mx6300_get_laser_status(HI_U8 *res); 						//  0 关闭  1 打开 Others: <TBD>

HI_S32 Mx6300_set_laser_current(HI_U32 value); 		// 0xda 32位激光电流值
HI_S32 Mx6300_get_laser_current(HI_U32 *res); 					// register只支持写，不支持读  获取激光电流值

HI_S32 Mx6300_set_laser_time(HI_U32 value);
HI_S32 Mx6300_get_laser_time(HI_U32 *res);

HI_S32 Mx6300_set_laser_ldmp_current(HI_U32 value); 	//32bit Set Laser current (uA)

HI_S32 Mx6300_flood_control(HI_U8 value); 				// 0xd9  1为打开， 0为关闭
HI_S32 Mx6300_get_flood_status(HI_U8 *res); 						// 0 关闭  1 打开 Others: <TBD>

HI_S32 Mx6300_set_laser_flood_led_current(HI_U32 value); //32bit Set LED current (uA)
HI_S32 Mx6300_get_ldp_protect_status(HI_U8 *res); 		//8bit Get LDP work status(protect or not)

HI_S32 Mx6300_set_ldp_enable(HI_U8 value); 			//8bit Set LDP work or not work
HI_S32 Mx6300_get_ldp_enable(HI_U8 *res); 				//8bit Get LDP work status(work or not)

HI_S32 Mx6300_get_ldp_data(HI_U32 *res); 					//32bit Get LDP output data

HI_S32 Mx6300_get_ldp_scale(HI_U32 *res); 				//32bit Set LDP scale value
HI_S32 Mx6300_set_ldp_scale(HI_U32 value); 			//32bit Get LDP scale value

HI_S32 Mx6300_get_pd_data(HI_U32 *res);
HI_S32 Mx6300_get_pd_enable(HI_U8 *res);
HI_S32 Mx6300_get_pd_status(HI_U8 *res);
HI_S32 Mx6300_get_pd_threshold_high(HI_U32 *res);
HI_S32 Mx6300_get_pd_threshold_low(HI_U32 *res);
HI_S32 Mx6300_set_pd_enable(HI_U8 value);
HI_S32 Mx6300_set_pd_status(HI_U8 value);
HI_S32 Mx6300_set_pd_threshold_high(HI_U32 value);
HI_S32 Mx6300_set_pd_threshold_low(HI_U32 value);

HI_S32 Mx6300_get_tca_enable(HI_U8 *res); 					//32bit Get TEC

HI_S32 Mx6300_set_tca_enable(HI_U8 value); 					//32bit Get TEC

//##############################################################################
// IR
//##############################################################################
HI_S32 Mx6300_set_ir_gain(HI_U32 value); 			//32bit Set IR sensor Gain
HI_S32 Mx6300_get_ir_gain(HI_U32 *res); 					//32bit Get IR sensor Gain

HI_S32 Mx6300_set_ir_exposure(HI_U32 value); 		//32bit Set IR sensor Exposure, 1 enable, 0 disable
HI_S32 Mx6300_get_ir_exposure(HI_U32 *res); 				//32bit Get IR sensor Exposure

HI_S32 Mx6300_set_ir_flip(HI_U8 value); 				//8bit Set IR sensor Flip or not Flip 0 disable 1 enable

HI_S32 Mx6300_set_ir_mirror(HI_U8 value); 			//8bit Set IR sensor Mirror or not Mirror
HI_S32 Mx6300_get_ir_mirror(HI_U8 *res); 				//8bit Get IR sensor Mirror state

//##############################################################################
// Depth
//##############################################################################
HI_S32 Mx6300_set_depth_hole_filter(HI_U32 value); 	//32bit Set DEPTH HOLE_FILTER , 1 enable, 0 disable

HI_S32 Mx6300_set_depth_mirror(HI_U8 value); 		//8bit Set DEPTH Mirror or not Mirror
HI_S32 Mx6300_get_depth_mirror(HI_U8 *res);

HI_S32 Mx6300_set_depth_d2c_mode(HI_U8 value); 			//8bit Set DEPTH D2C ON or OFF 0 disable 1 enable
HI_S32 Mx6300_get_depth_d2c_mode(HI_U8 *res);

//##############################################################################
// Filter
//##############################################################################
HI_S32 Mx6300_set_postfilter_ncost_thresh(HI_U32 value); //32bit Set DEPPOSTFILTER_NCOST_THRESH

HI_S32 Mx6300_set_threshfilter(HI_U32 value); 		//32bit Set DEPTH THRESHFILTER 0 disable 1 enable
HI_S32 Mx6300_set_threshfilter_thresh(HI_U32 value); //32bit Set DEPTH THRESHFILTER_THRESH

HI_S32 Mx6300_set_postfilter(HI_U32 value); 			//32bit Set DEPTH POSTFILTER 0 disable 1 enable

HI_S32 Mx6300_set_depth_postfilter_threshhold(HI_U32 value); //32bit Set DEPTH POSTFILTER_THRESHOLD ??
HI_S32 Mx6300_get_depth_postfilter_threshhold(HI_U32 *res); 	//32bit Get DEPTH POSTFILTER_THRESHOLD

HI_S32 Mx6300_set_rectify_enable(HI_U8 value); //32bit
HI_S32 Mx6300_get_rectify_enable(HI_U8 *res); //32bit



//##############################################################################
// Not support
//##############################################################################
//HI_S32 Mx6300_get_ir_chip_id(HI_S32 *res);			 	//32bit Get IR sensor chip ID
//HI_S32 Mx6300_get_depth_d2c_param(HI_S32 *res); 		//32bit Get left and right camera parameters



HI_S32 Mx6300_set_ir_ae_status(HI_U32 status); 		// 发1打开， 发0 关闭
HI_S32 Mx6300_set_ir_ae(HI_U32 value); 				// 32位曝光时间值

HI_S32 Mx6300_set_ir_hts(HI_U32 value); 				//32bit Set IR sensor H_blanking time
HI_S32 Mx6300_set_ir_vts(HI_U32 value); 				//32bit Set IR sensor V_blanking time
HI_S32 Mx6300_get_ir_hts(HI_U32 *res); 				//32bit Set IR sensor H_blanking time
HI_S32 Mx6300_get_ir_vts(HI_U32 *res); 				//32bit Set IR sensor V_blanking time
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif
