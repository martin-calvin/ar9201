#ifndef _MX6300_CTL_H_
#define _MX6300_CTL_H_
#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* __cplusplus */
#define OB_SUCCESS 0
#define OB_FAILURE -1
	typedef enum _Stream_ctl_State
	{
		STREAM_CLOSE = 0x0,
		STREAM_DEPTH_OPEN = 0x01,
		STREAM_IR_OPEN = 0x02,
	} Stream_ctl_State;
	typedef enum _Resolution_State
	{
		RES_1280X800 = 0x10,
		RES_640X400 = 0x11,
		RES_800X1280 = 0x12,
		RES_400X640 = 0x13,
	} Resolution_State;
	typedef enum Resolutions
	{
		RES_CUSTOM = -1,
		RES_QVGA = 0,		// 320x240
		RES_VGA = 1,		// 640x480
		RES_SXGA = 2,		// 1280x1024
		RES_UXGA = 3,		// 1600x1200
		RES_QQVGA = 4,		// 160x120
		RES_QCIF = 5,		// 176x144
		RES_240P = 6,		// 432x240
		RES_CIF = 7,		// 352x288
		RES_WVGA = 8,		// 640x360
		RES_480P = 9,		// 864x480
		RES_800_448 = 10,	// 800x448
		RES_SVGA = 11,		// 800x600
		RES_576P = 12,		// 1024x576
		RES_DV = 13,		// 960x720
		RES_720P = 14,		// 1280x720
		RES_1280_960 = 15,	// 1280x960
		RES_1280_800 = 16,	// 1280x800
		RES_640_400 = 17,	// 640x400
		RES_800_1280 = 18,	// 800x1280
		RES_400_640 = 19,	// 400x640
		RES_320_200 = 20,	// 320x200
		RES_480_640 = 21,	// 480x640
		RES_1080_1280 = 22, // 1080x1280
		RES_540_640 = 23,	// 540x640
		RES_960_1280 = 25,	// 960x1280
		RES_720_960 = 28,	// 720x960
		RES_1024_1280 = 29, // 1024x1280
		RES_640_512 = 30,	// 640x512
		RES_512_640 = 31,	// 512x640
	} Resolution;
	typedef struct _OBCameraParams
	{
		float l_intr_p[4]; //[fx,fy,cx,cy]
		float r_intr_p[4]; //[fx,fy,cx,cy]
		float r2l_r[9];	   //[r00,r01,r02;r10,r11,r12;r20,r21,r22]
		float r2l_t[3];	   //[t1,t2,t3]
		float l_k[5];	   //[k1,k2,p1,p2,k3]
		float r_k[5];
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
		uint8_t refinement_[2016];
	} OBIntrinsicRefinement;

	typedef struct _OBCameraIntrinsic
	{
		uint32_t vc_mode_;	  /// AF摄像头的VC值
		uint32_t img_height_; /// 图像高
		uint32_t img_width_;  /// 图像宽
		float focal_x_;		  /// x方向焦距
		float focal_y_;		  /// y方向焦距
		float cx_;			  /// 主点x坐标
		float cy_;			  /// 主点y坐标
		float k1_;			  /// 径向畸变系数k1-k4
		float k2_;
		float k3_;
		float k4_;
		float p1_; /// 切向畸变系数p1-p2
		float p2_;
		OBIntrinsicRefinement refine_; // refinement参数
	} OBCameraIntrinsic;

	typedef struct _Componet_temperature
	{
		float ldm_temp;
		float ir_temp;
		float rgb_temp;
	} Componet_temp;
	typedef struct _OBRelativePose
	{
		float rx_; // x方向旋转分量
		float ry_; // y方向旋转分量
		float rz_; // z方向旋转分量
		float tx_; // x方向平移分量
		float ty_; // y方向平移分量
		float tz_; // z方向平移分量
	} OBRelativePose;

	typedef struct _OBCameraDualPara
	{
		struct
		{
			struct
			{
				uint32_t buf_pos : 12;		//0-11
				uint32_t totalBufRows : 12; //12-23
				uint32_t rsv0 : 6;			//24-29
				uint32_t dep_sign : 1;		//30
				uint32_t shft_dep : 1;		//31

				uint32_t iZ0;
				uint32_t PBF;
				uint32_t W[12];
			} dep2color;
			struct
			{
				uint32_t k[9];
				uint32_t r[9];
				uint32_t fx;
				uint32_t fy;
				uint32_t cx;
				uint32_t cy;
			} mdlCamL;
			struct
			{
				uint32_t k[9];
				uint32_t r[9];
				uint32_t fx;
				uint32_t fy;
				uint32_t cx;
				uint32_t cy;
			} mdlCamR;
			struct
			{
				uint32_t dY;
				uint32_t dT;
				uint32_t iRow;
				uint32_t img_size;
			} mdlRef;
			struct
			{
				uint32_t cam : 16;
				uint32_t ref : 16;
			} startPixBuf;
		} DPU;
		struct
		{
			struct
			{
				uint32_t w, h;
				float fx, fy, cx, cy, bl;
				float rotL[3];
				float rotR[3];
			} virCam;
			struct
			{
				OBCameraIntrinsic irL;
				OBCameraIntrinsic irR;
				OBCameraIntrinsic rgb;
				OBRelativePose irL_pose;
				OBRelativePose irR_pose;
				OBRelativePose rgb_pose;

			} camera_params;
			struct
			{
				float d_intr_p[4]; //[fx,fy,cx,cy]
				float c_intr_p[4]; //[fx,fy,cx,cy]
				float d2c_r[9];	   //[r00,r01,r02;r10,r11,r12;r20,r21,r22]
				float d2c_t[3];	   //[t1,t2,t3]
				float d_k[5];	   //[k1,k2,k3,p1,p2]
				float c_k[5];
				//float pixelsize;
			} soft_d2c;
		} HOST;
	} OBCameraDualPara;
	//##############################################################################
	// SysInfo
	//##############################################################################

	/**
* int Mx6300_get_device_id(); 获取设备ID
* return： -1 失败 <TBD>设备ID
*/
	int Mx6300_get_device_id(uint16_t *dev_Id); //0x00

	/**
* int Mx6300_read_fw_version(); 获取版本号

* return： -1 失败
*  高16位为固件版本号， 低16位为硬件版本号
*/
	int Mx6300_read_fw_version(char *fw);
	int Mx6300_get_firmware_ver(uint32_t *fw_ver);
	int Mx6300_read_hw_version(uint8_t *hw_ver);
	/**
* char * Mx6300_get_serial_number(); 获取SN号
* return： NULL 失败， Others:16Byte的SN
* 注意： 调用该函数要注意释放内存, 如：
*  char *sn = Mx6300_get_serial_number();
*  if(sn != NULL) free(sn);
*/

	int Mx6300_get_sn(char *sn);

	//##############################################################################
	// CameraParams
	//##############################################################################
	int Mx6300_get_depth_baseline(float *res);
	int Mx6300_get_depth_zpd(float *res);
	int Mx6300_get_depth_zzps(float *res);
	int Mx6300_get_depth_fx(float *res); //32bit Get Fx.

	int Mx6300_get_depth_resolution(uint8_t *res);
	int Mx6300_get_ir_resolution(uint8_t *res);
	int Mx6300_get_depth_fps(uint8_t *res);
	int Mx6300_get_ir_fps(uint8_t *res);

    int Mx6300_set_depth_video_mode(Resolution res, uint8_t fps);
	int Mx6300_set_depth_resolution(Resolution res);
	int Mx6300_set_ir_resolution(Resolution res);
	int Mx6300_set_depth_fps(uint8_t value);
	int Mx6300_set_ir_fps(uint8_t value);
	int Mx6300_set_ir_video_mode(Resolution res, uint8_t fps);

	OBCameraDualPara Mx6300_read_dual_param();

	int Mx6300_Stream_control(Stream_ctl_State state); //0x18 1=on, 0=off

	//##############################################################################
	// laser * flood * ldp
	//##############################################################################
	int Mx6300_laser_control(uint8_t value);   // 0xd8  1为打开， 0为关闭
	int Mx6300_get_laser_status(uint8_t *res); //  0 关闭  1 打开 Others: <TBD>

	int Mx6300_set_laser_current(uint32_t value); // 0xda 32位激光电流值
	int Mx6300_get_laser_current(uint32_t *res);  // register只支持写，不支持读  获取激光电流值

	int Mx6300_set_laser_time(uint32_t value);
	int Mx6300_get_laser_time(uint32_t *res);

	int Mx6300_set_laser_ldmp_current(uint32_t value); //32bit Set Laser current (uA)

	int Mx6300_flood_control(uint8_t value);   // 0xd9  1为打开， 0为关闭
	int Mx6300_get_flood_status(uint8_t *res); // 0 关闭  1 打开 Others: <TBD>

	int Mx6300_set_laser_flood_led_current(uint32_t value); //32bit Set LED current (uA)
	int Mx6300_get_ldp_protect_status(uint8_t *res);		//8bit Get LDP work status(protect or not)

	int Mx6300_set_ldp_enable(uint8_t value);			 //8bit Set LDP work or not work
	int Mx6300_get_ldp_enable(uint8_t *res);			 //8bit Get LDP work status(work or not)
	int Mx6300_set_ldp_calibrate(uint8_t ldp_calibrate); //set ldp calibrate
	int Mx6300_write_ldp_calibrate_data(uint8_t *pdata);

	int Mx6300_get_ldp_data(uint32_t *res); //32bit Get LDP output data

	int Mx6300_get_ldp_scale(uint32_t *res);  //32bit Set LDP scale value
	int Mx6300_set_ldp_scale(uint32_t value); //32bit Get LDP scale value

	int Mx6300_get_pd_data(uint32_t *res);
	int Mx6300_get_pd_enable(uint8_t *res);
	int Mx6300_get_pd_status(uint8_t *res);
	int Mx6300_get_pd_threshold_high(uint32_t *res);
	int Mx6300_get_pd_threshold_low(uint32_t *res);
	int Mx6300_set_pd_enable(uint8_t value);
	int Mx6300_set_pd_status(uint8_t value);
	int Mx6300_set_pd_threshold_high(uint32_t value);
	int Mx6300_set_pd_threshold_low(uint32_t value);

	int Mx6300_get_tca_enable(uint8_t *res); //get TCA enable status

	int Mx6300_set_tca_enable(uint8_t value); //set TCA enable status

	int Mx6300_get_tec_enable(uint8_t *res);  //get TEC enable status
	int Mx6300_set_tec_enable(uint8_t value); //set TEC enable status
	//##############################################################################
	// IR
	//##############################################################################
	int Mx6300_set_ir_gain(uint32_t value); //32bit Set IR sensor Gain
	int Mx6300_get_ir_gain(uint32_t *res);	//32bit Get IR sensor Gain

	int Mx6300_set_ir_exposure(uint32_t value); //32bit Set IR sensor Exposure, 1 enable, 0 disable
	int Mx6300_get_ir_exposure(uint32_t *res);	//32bit Get IR sensor Exposure

	int Mx6300_set_ir_flip(uint8_t value); //8bit Set IR sensor Flip or not Flip 0 disable 1 enable

	int Mx6300_set_ir_mirror(uint8_t value); //8bit Set IR sensor Mirror or not Mirror
	int Mx6300_get_ir_mirror(uint8_t *res);	 //8bit Get IR sensor Mirror state

	//##############################################################################
	// Depth
	//##############################################################################
	int Mx6300_set_depth_hole_filter(uint32_t value); //32bit Set DEPTH HOLE_FILTER , 1 enable, 0 disable

	int Mx6300_set_depth_mirror(uint8_t value); //8bit Set DEPTH Mirror or not Mirror
	int Mx6300_get_depth_mirror(uint8_t *res);

	int Mx6300_set_depth_d2c_mode(uint8_t value); //8bit Set DEPTH D2C ON or OFF 0 disable 1 enable
	int Mx6300_get_depth_d2c_mode(uint8_t *res);

	//##############################################################################
	// Filter
	//##############################################################################
	int Mx6300_set_postfilter_ncost_thresh(uint32_t value); //32bit Set DEPPOSTFILTER_NCOST_THRESH

	int Mx6300_set_threshfilter(uint32_t value);		//32bit Set DEPTH THRESHFILTER 0 disable 1 enable
	int Mx6300_set_threshfilter_thresh(uint32_t value); //32bit Set DEPTH THRESHFILTER_THRESH

	int Mx6300_set_postfilter(uint32_t value); //32bit Set DEPTH POSTFILTER 0 disable 1 enable

	int Mx6300_set_depth_postfilter_threshhold(uint32_t value); //32bit Set DEPTH POSTFILTER_THRESHOLD ??
	int Mx6300_get_depth_postfilter_threshhold(uint32_t *res);	//32bit Get DEPTH POSTFILTER_THRESHOLD

	int Mx6300_set_rectify_enable(uint8_t value); //32bit
	int Mx6300_get_rectify_enable(uint8_t *res);  //32bit

	int Mx6300_get_componet_temp(Componet_temp *temp);

	//##############################################################################
	// Not support
	//##############################################################################
	//int Mx6300_get_ir_chip_id(int *res);			 	//32bit Get IR sensor chip ID
	//int Mx6300_get_depth_d2c_param(int *res); 		//32bit Get left and right camera parameters

	int Mx6300_set_ir_ae_status(uint32_t status); // 发1打开， 发0 关闭
	int Mx6300_set_ir_ae(uint32_t value);		  // 32位曝光时间值

	int Mx6300_set_ir_hts(uint32_t value); //32bit Set IR sensor H_blanking time
	int Mx6300_set_ir_vts(uint32_t value); //32bit Set IR sensor V_blanking time
	int Mx6300_get_ir_hts(uint32_t *res);  //32bit Set IR sensor H_blanking time
	int Mx6300_get_ir_vts(uint32_t *res);  //32bit Set IR sensor V_blanking time

	int Mx6300_read_ahb(uint32_t addr, uint32_t *data); //ahb read
	int Mx6300_write_ahb(uint32_t addr, uint32_t data); //ahb write
	typedef struct
	{
		uint8_t bus;
		uint8_t slave_addr;
		uint32_t reg;
		uint8_t reg_len; //register lenth 1->1, 2->2
		uint32_t data;
		uint8_t data_len; //data length 1->,2->2
	} mx6300_i2c_ctrl;
	int Mx6300_read_i2c(mx6300_i2c_ctrl *i2c_ctrl);	 //i2c read
	int Mx6300_write_i2c(mx6300_i2c_ctrl *i2c_ctrl); //i2c write
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif
