#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ar_cam_src.h"
#include "pipeline_ctl.h"

typedef enum
{
    CAM_SET_AEC_MODE,
    CAM_GET_AEC_MODE,
    CAM_SET_AWB_MODE,
    CAM_SET_MANU_AEC,
    CAM_SET_MANU_AWB,
    CAM_SET_BRIGHTNESS,
    CAM_SET_CONTRAST,
    CAM_SET_SHARPNESS,
    CAM_SET_SATURABILITY,
    CAM_ENABLE_DE3D,
    CAM_SET_FLIP,
    CAM_GET_FILP,
    CAM_SET_MIRROR,
    CAM_GET_MIRROR,
    CAM_SET_ROI,
    CAM_GET_AE_ROI,
    CAM_SET_SENCE_MODE,
    CAM_GET_SCENE_MODE,
    CAM_SET_SENSE,
    CAM_GET_SCENE,
    CAM_SET_LED,
    CAM_SET_IR_CUTTER,
    CAM_SET_FPS_RANGE,
    CAM_SET_BANDING,
    CAM_GET_BANDING,
    CAM_GET_BRIGHT,
    CAM_GET_SATURABILITY,
    CAM_GET_CONTRAST,
    CAM_GET_SHARPNESS,
    CAM_GET_3A_INFO,
    CAM_GET_3A_INFO_EXT,
    CAM_SET_EXP_LIMIT,
    CAM_SET_FACE_AEC,
    CAM_SET_HDR,
    CAM_GET_HDR,
    CAM_SET_EIS,
    CAM_SET_DVP_NOTIFY,
    CAM_ENDEN_ISP_MODULE,
    CAM_SET_DRC_MODE,
    CAM_GET_DRC_MODE,
    CAM_SET_HDR_AUTO_DETET,
    CAM_GET_HDR_AUTO_DETET,
    CAM_SET_HDR_MODE,
    CAM_GET_HDR_MOE,
    CAM_SET_HDR_PRA_MODE,
    CAM_GET_HDR_PRA_MODE,
    CAM_PIPE_LINE_DBUS_CLT,
    CAM_GET_CAM_INFO,
    CAM_SET_AF_MOD,
    CAM_SET_AF_ROI,
    CAM_SET_ZOOM,
    CAM_SET_CSC,
    CAM_GET_CSC,
    CAM_SET_DE3D_PRA,
    CAM_GET_DE3D_PRA,
    CAM_SET_DE2D_PRA,
    CAM_GET_DE2D_PRA,
    CAM_TRIGGER_ERROR_PROC,
    CMD_MAX_NUM,
}cmd_id_t;

typedef struct
{
  uint32_t  isp_module;
  uint32_t  en_flag;
}cam_isp_module_state;

typedef struct
{
  int code;
  int w;
  int h;
  int num;
  int den;
  int interlace;
  int chanles;
  int format;
  int rate;
}dvp_pra_t;

typedef struct
{
  int mode;
  float gain;
  float k1;
  float k2;
  float k3;
}drc_pra_l_t;

typedef struct
{
   int cmd;
   char args[128];
   char name[256];
}pipeline_ctl_l_t;;

typedef struct
{
  char name[256];
  int hdr_on;
  int num;
}hdr_mode_t;


typedef struct
{
    int     camera_id;
    int     cam_bright;
    int     cam_contrast;
    int     cam_sharpness;
    int     cam_satubility;
    int     de3d_state;
    int     flip_state;
    int     mirror_state;
    cam_roi_t   roi_info;
    int     sense_mode;
    sense_info_t    sense_info;
    int     led_state;
    int     ir_cut_state;
    int     banding_state;
    fps_info_t      fps_info;
    basic_3a_info_t     basic_3a_info;
    int      exp_limit;
	face_aec_t face_roi;
	int hdr_algo_mode;
    cam_eis_t   eis_cfg;
	dvp_pra_t dvp_notify;
    cam_isp_module_state  tuning_req;
	drc_pra_l_t drc_pra;
	pipeline_ctl_l_t ctl;
	int hdr_auto_detect;
	hdr_mode_t hdr_mode;
	hdr_pra_mode_t hdr_pra_mode;
    unsigned int af_mode;
    cam_roi_t   af_roi_info;
	zoom_pra_t zoom;
	csc_pra_t csc;
	denoise_3d_pra_t de3d_pra;
	denoise_2d_pra_t de2d_pra;
    int32_t error_code;
}test_cam_info_t;

static void pra_err()
{
    printf("input pra error\n");
    printf("using --help  tp get info\n");
}

static char *get_cmd_line(int argc, char* argv[])
{
   int i=0;
   int total_len=0,len=0;
   char *cmd_buf=malloc(1024);
   memset(cmd_buf,0,1024);
   for(i=1;i<argc;i++)
   {
     len=strlen(argv[i]);
     strcpy((char *)&cmd_buf[total_len],argv[i]);
	 total_len+=len;
     cmd_buf[total_len]=' ';
     total_len++;
   }
   cmd_buf[total_len]='\0';
   return cmd_buf;
}

static int find_pra_by_name(int argc, char* argv[],char *name)
{
    int i = 0;
    for(i = 0; i < argc; i++){
		if(!strcmp(name, argv[i]))
		{
		   return i;
		}
    }
	return -1;
}

static int cmd_prase(int argc, char* argv[], test_cam_info_t *cam_info)
{
    int i = 0;
    for(i = 0; i < argc; i++){
        printf("pra: %s\n", argv[i]);
        if(!strcmp("--name", argv[i])){
            cam_info->camera_id = atoi(argv[i+1]);
            continue;
        }

        if(!strcmp("--aec_mode", argv[i])){
            if(!strcmp("AUTO", argv[i+1])){
                cam_info->basic_3a_info.aec_info.aec_mode = 0;
            }else if(!strcmp("MANU", argv[i+1])){
                cam_info->basic_3a_info.aec_info.aec_mode = 5;
            }else{
                pra_err();
                return -1;
            }
            return CAM_SET_AEC_MODE;
        }

        if(!strcmp("--awb_mode", argv[i])){
            if(!strcmp("D75", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 0;
            }
            else if(!strcmp("D65", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 1;
            }
            else if(!strcmp("D50", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 2;
            }
            else if(!strcmp("NOON", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 3;
            }
            else if(!strcmp("CW", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 4;
            }
            else if(!strcmp("TL84", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 5;
            }
            else if(!strcmp("A", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 6;
            }
            else if(!strcmp("H", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 7;
            }
            else if(!strcmp("CCUST1", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 8;
            }
            else if(!strcmp("CUST2", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 9;
            }
            else if(!strcmp("AUTO", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 10;
            }
            else if(!strcmp("MANUAL", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 11;
            }
            else{
                pra_err();
                return -1;
            }
            return CAM_SET_AWB_MODE;
        }

        if(!strcmp("--manu_aec", argv[i])){
            if(!strcmp("AUTO", argv[i+1])){
                cam_info->basic_3a_info.aec_info.aec_mode = 0;
            }else if(!strcmp("MANU", argv[i+1])){
                cam_info->basic_3a_info.aec_info.aec_mode = 5;
            }else{
                pra_err();
                return -1;
            }
            cam_info->basic_3a_info.aec_info.gain = atof(argv[i+2]);
            cam_info->basic_3a_info.aec_info.exp_time_us = atof(argv[i+3]);
            cam_info->basic_3a_info.aec_info.luma_target = atoi(argv[i+4]);

            return CAM_SET_MANU_AEC;
        }

        if(!strcmp("--manu_awb", argv[i])){
            if(!strcmp("D75", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 0;
            }
            else if(!strcmp("D65", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 1;
            }
            else if(!strcmp("D50", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 2;
            }
            else if(!strcmp("NOON", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 3;
            }
            else if(!strcmp("CW", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 4;
            }
            else if(!strcmp("TL84", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 5;
            }
            else if(!strcmp("A", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 6;
            }
            else if(!strcmp("H", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 7;
            }
            else if(!strcmp("CCUST1", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 8;
            }
            else if(!strcmp("CUST2", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 9;
            }
            else if(!strcmp("AUTO", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 10;
            }
            else if(!strcmp("MANUAL", argv[i+1])){
                cam_info->basic_3a_info.awb_info.awb_mode = 11;
            }
            else{
                pra_err();
                return -1;
            }

            cam_info->basic_3a_info.awb_info.cct = atoi(argv[i+2]);
            cam_info->basic_3a_info.awb_info.r_gain = atof(argv[i+3]);
            cam_info->basic_3a_info.awb_info.g_gain = atof(argv[i+4]);
            cam_info->basic_3a_info.awb_info.b_gain = atof(argv[i+5]);

            return CAM_SET_MANU_AWB;
        }

        if(!strcmp("--af_mode", argv[i])){
            if(!strcmp("AUTO", argv[i+1])){
                cam_info->af_mode = 0;
            }else if(!strcmp("CAF", argv[i+1])){
                cam_info->af_mode = 1;
            }else if(!strcmp("MACRO", argv[i+1])){
                cam_info->af_mode = 2;
            }else if(!strcmp("INFINITE", argv[i+1])){
                cam_info->af_mode = 3;
            }else if(!strcmp("MANUAL", argv[i+1])){
                cam_info->af_mode = 4;
            }else{
                pra_err();
                return -1;
            }
            return CAM_SET_AF_MOD;
        }
        if(!strcmp("--af_roi", argv[i])){
            cam_info->af_roi_info.x = atof(argv[i+1]);
            cam_info->af_roi_info.y = atof(argv[i+2]);
            cam_info->af_roi_info.width = atof(argv[i+3]);
            cam_info->af_roi_info.height =atof(argv[i+4]);
            return CAM_SET_AF_ROI;
        }

        if(!strcmp("--error_proc", argv[i])){
            if(!strcmp("TIMEOUT", argv[i+1])){
                cam_info->error_code = 1;
            }else{
                pra_err();
                return -1;
            }
            return CAM_TRIGGER_ERROR_PROC;
        }

        if(!strcmp("--set_bright", argv[i])){
            cam_info->cam_bright = atoi(argv[i+1]);
            return CAM_SET_BRIGHTNESS;
        }

        if(!strcmp("--set_contrast", argv[i])){
            cam_info->cam_contrast = atoi(argv[i+1]);
            return CAM_SET_CONTRAST;
        }

        if(!strcmp("--set_sharpness", argv[i])){
            cam_info->cam_sharpness = atoi(argv[i+1]);
            return CAM_SET_SHARPNESS;
        }

        if(!strcmp("--set_satubility", argv[i]))
        {
            cam_info->cam_satubility = atoi(argv[i+1]);
            return CAM_SET_SATURABILITY;
        }

        if(!strcmp("--enable_de3d", argv[i])){
            cam_info->de3d_state = atoi(argv[i+1]);
            return CAM_ENABLE_DE3D;
        }

        if(!strcmp("--enable_flip", argv[i])){
            cam_info->flip_state = atoi(argv[i+1]);
            return CAM_SET_FLIP;
        }

        if(!strcmp("--get_flip", argv[i])){
            return CAM_GET_FILP;
        }

        if(!strcmp("--get_mirror", argv[i])){
            return CAM_GET_MIRROR;
        }

        if(!strcmp("--get_cam_info", argv[i])){
            return CAM_GET_CAM_INFO;
        }

        if(!strcmp("--enable_mirror", argv[i])){
            cam_info->mirror_state =  atoi(argv[i+1]);
            return CAM_SET_MIRROR;
        }

        if(!strcmp("--ae_roi", argv[i])){
            cam_info->roi_info.x = atof(argv[i+1]);
            cam_info->roi_info.y = atof(argv[i+2]);
            cam_info->roi_info.width = atof(argv[i+3]);
            cam_info->roi_info.height =atof(argv[i+4]);
            return CAM_SET_ROI;
        }
        if(!strcmp("--get_ae_roi", argv[i])){
            return CAM_GET_AE_ROI;
        }
        if(!strcmp("--set_scene_mode", argv[i])){
            cam_info->sense_mode = atoi(argv[i+1]);
            return CAM_SET_SENCE_MODE;
        }

        if(!strcmp("--get_scene_mode", argv[i])){
            return CAM_GET_SCENE_MODE;
        }

        if(!strcmp("--get_scene", argv[i])){
            return CAM_GET_SCENE;
        }

        if(!strcmp("--set_scene", argv[i])){
            if(!strcmp("normal", argv[i+1])){
                cam_info->sense_info.sensce = 0;
            }else if(!strcmp("night", argv[i+1])){
                cam_info->sense_info.sensce = 1;
            }else{
                pra_err();
                return -1;
            }

            cam_info->sense_info.led_flag = atoi(argv[i+2]);
            cam_info->sense_info.ir_cut_flag = atoi(argv[i+3]);
            cam_info->sense_info.fps_adjust_flag = atoi(argv[i+4]);
            cam_info->sense_info.fps_rudecue_to = atoi(argv[i+5]);
            return CAM_SET_SENSE;
        }



        if(!strcmp("--enable_led", argv[i])){
            cam_info->led_state = atoi(argv[i+1]);
            return CAM_SET_LED;
        }

        if(!strcmp("--enable_ir_cutter", argv[i])){
            cam_info->ir_cut_state = atoi(argv[i+1]);
            return CAM_SET_IR_CUTTER;
        }

        if(!strcmp("--enable_banding", argv[i])){
            cam_info->banding_state = atoi(argv[i+1]);
            return CAM_SET_BANDING;
        }
        if(!strcmp("--get_banding", argv[i])){
            return CAM_GET_BANDING;
        }
        if(!strcmp("--set_fps_range", argv[i])){
            if(!(strcmp("--fps_min", argv[i+1]))){
                cam_info->fps_info.fps_min = atoi(argv[i+2]);
                if(!(strcmp("--fps_max", argv[i+3]))){
                    cam_info->fps_info.fps_max = atoi(argv[i+4]);
                }else{
                    pra_err();
                    return -1;
                }
            }
            else if(!(strcmp("--fps_max", argv[i+1]))){
                 cam_info->fps_info.fps_max = atoi(argv[i+2]);
                 if(!(strcmp("--fps_min", argv[i+3]))){
                    cam_info->fps_info.fps_min = atoi(argv[i+4]);
                 }else{
                    pra_err();
                    return -1;
                 }
            }
            else{
                pra_err();
                return -1;
            }
            return CAM_SET_FPS_RANGE;
        }
        if(!(strcmp("--set_cam_eis", argv[i]))){
            if(!(strcmp("--eis_algo", argv[i+1]))){
                cam_info->eis_cfg.eis_algo_state = atoi(argv[i+2]);
                if(!(strcmp("--eis_distor", argv[i+3]))){
                    cam_info->eis_cfg.eis_distortion_state = atoi(argv[i+4]);
                }
            }
            else if(!(strcmp("--eis_distor", argv[i+1]))){
                 cam_info->eis_cfg.eis_distortion_state = atoi(argv[i+2]);
                 if(!(strcmp("--eis_algo", argv[i+3]))){
                cam_info->eis_cfg.eis_algo_state = atoi(argv[i+4]);
                 }
            }
            else{
                pra_err();
                return -1;
            }
            return CAM_SET_EIS;
        }

        if(!strcmp("--get_bright", argv[i])){
            return CAM_GET_BRIGHT;
        }

        if(!strcmp("--get_contrast", argv[i])){
            return CAM_GET_CONTRAST;
        }

        if(!strcmp("--get_sharpness", argv[i])){
            return CAM_GET_SHARPNESS;
        }

        if(!strcmp("--get_satubility", argv[i])){
            return CAM_GET_SATURABILITY;
        }

        if(!strcmp("--get_3a_info", argv[i])){
            return CAM_GET_3A_INFO;
        }

        if(!strcmp("--get_3a_info_ext", argv[i])){
            return CAM_GET_3A_INFO_EXT;
        }

        if(!strcmp("--get_aec_mode", argv[i])){
            return CAM_GET_AEC_MODE;
        }

        if(!strcmp("--set_exp_limit", argv[i])){
            cam_info->exp_limit = atoi(argv[i+1]);
            return CAM_SET_EXP_LIMIT;
        }
		if(!strcmp("--set_face_aec",argv[i]))
		{
		    cam_info->face_roi.face_count=atoi(argv[i+1]);
			cam_info->face_roi.face_weight=atof(argv[i+2]);
			cam_info->face_roi.face_target=atoi(argv[i+3]);
			cam_info->face_roi.face_keep_frame_count=atoi(argv[i+4]);
			cam_info->face_roi.face_roi[0].x=atof(argv[i+5]);
			cam_info->face_roi.face_roi[0].y=atof(argv[i+6]);
			cam_info->face_roi.face_roi[0].width=atof(argv[i+7]);
			cam_info->face_roi.face_roi[0].height=atof(argv[i+8]);
		    return CAM_SET_FACE_AEC;
		}
		if(!strcmp("--set_hdr_algo_state", argv[i])){
            cam_info->hdr_algo_mode = atoi(argv[i+1]);
            return CAM_SET_HDR;
        }
        if(!strcmp("--get_hdr_algo_state", argv[i])){
            return CAM_GET_HDR;
        }
        if(!(strcmp("--set_isp_module", argv[i]))){
            if(!(strcmp("--ata", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_ATA;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module ata state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--blc", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_BLC;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module blc state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--cac", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_CAC;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module cac state = %d\n", cam_info->tuning_req.en_flag);

            }
            if(!(strcmp("--ccm1", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_CCM1;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module ccm1 state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--ccm2", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_CCM2;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module ccm2 state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--cm", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_CM;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module cm state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--cnf", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_CNF;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module cnf state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--compander", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_CAMPANDER;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module compander state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--de3d", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_DE3D;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module de3d state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--decompander", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_DECOMPANDER;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module decompander state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--digigain1", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_DIGITAL_GAIN_1;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module digigain1 state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--digigain2", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_DIGITAL_GAIN_2;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module digigain2 state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--dither", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_DITHER;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module dither state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--dpc", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_DPC;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module dpc state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--dpp", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_DPP;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module ata state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--drc", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_DRC;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module drc state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--gamma", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_GAMMA;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module gamma state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--gic", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_GIC;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module gic state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--gtm1", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_GTM1_LUT;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module gtm1 state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--gtm2", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_GTM2_LUT;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module gtm2 state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--lee", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_LNR_LEE;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module lee state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--lsc", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_LSC;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module lsc state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--lut3d", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_3DLUT;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module lut3d state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--crop", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_CROP_RAW;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module crop state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--rgb2yuv", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_RGB2YUV;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module rgb2yuv state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--rnr", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_RNR;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module rnr state = %d\n", cam_info->tuning_req.en_flag);
            }

            if(!(strcmp("--wb", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_AWB;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module wb state = %d\n", cam_info->tuning_req.en_flag);
            }

            if(!(strcmp("--algo_aec", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_ALGO_AEC;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module algo_aec state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--algo_awb", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_ALGO_AWB;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module algo_awb state = %d\n", cam_info->tuning_req.en_flag);
            }
            if(!(strcmp("--algo_af", argv[i+1]))){
                cam_info->tuning_req.isp_module = TUNING_ISP_ALGO_AF;
                cam_info->tuning_req.en_flag = atoi(argv[i+2]);
                printf("set isp module algo_af state = %d\n", cam_info->tuning_req.en_flag);
            }

            return CAM_ENDEN_ISP_MODULE;

        }
	    if(!strcmp("--dvp_notify", argv[i])){
			int index=0;
			index=find_pra_by_name(argc,argv,"--notify_code");
			if(index>0)
			{
			   cam_info->dvp_notify.code=atoi(argv[index +1]);
			}else
			{
			   cam_info->dvp_notify.code=1;
			}
			index=find_pra_by_name(argc,argv,"--w");
			if(index>0)
			{
			   cam_info->dvp_notify.w=atoi(argv[index +1]);
			}else
			{
			   cam_info->dvp_notify.w=1920;
			}
		    index=find_pra_by_name(argc,argv,"--h");
			if(index>0)
			{
			   cam_info->dvp_notify.h=atoi(argv[index +1]);
			}else
			{
			   cam_info->dvp_notify.h=1080;
			}
		    index=find_pra_by_name(argc,argv,"--num");
			if(index>0)
			{
			   cam_info->dvp_notify.num=atoi(argv[index +1]);
			}else
			{
			   cam_info->dvp_notify.num=60;
			}
			index=find_pra_by_name(argc,argv,"--den");
			if(index>0)
			{
			   cam_info->dvp_notify.den=atoi(argv[index +1]);
			}else
			{
			   cam_info->dvp_notify.den=1;
			}
		    index=find_pra_by_name(argc,argv,"--interlace");
			if(index>0)
			{
			   cam_info->dvp_notify.interlace=atoi(argv[index +1]);
			}else
			{
			   cam_info->dvp_notify.interlace=0;
			}
		    index=find_pra_by_name(argc,argv,"--chs");
			if(index>0)
			{
			   cam_info->dvp_notify.chanles=atoi(argv[index +1]);
			}else
			{
			   cam_info->dvp_notify.chanles=2;
			}
		    index=find_pra_by_name(argc,argv,"--format");
			if(index>0)
			{
			   cam_info->dvp_notify.format=atoi(argv[index +1]);
			}else
			{
			   cam_info->dvp_notify.format=16;
			}
		    index=find_pra_by_name(argc,argv,"--rate");
			if(index>0)
			{
			   cam_info->dvp_notify.rate=atoi(argv[index +1]);
			}else
			{
			   cam_info->dvp_notify.rate=48000;
			}
            return CAM_SET_DVP_NOTIFY;
        }
	    if(!strcmp("--drc_mode", argv[i])){
			int index=0;
			index=find_pra_by_name(argc,argv,"--mode");
			if(index>0)
			{
			   cam_info->drc_pra.mode=atoi(argv[index +1]);
			   if(cam_info->drc_pra.mode>DRC_MODE_MANU)
			   {
			      cam_info->drc_pra.mode=DRC_MODE_AUTO;
			   }
			}else
			{
			    cam_info->drc_pra.mode=DRC_MODE_AUTO;
			}
			index=find_pra_by_name(argc,argv,"--gain");
			if(index>0)
			{
			   cam_info->drc_pra.gain=atof(argv[index +1]);
			}else
			{
			    cam_info->drc_pra.gain=0.3;
			}
			index=find_pra_by_name(argc,argv,"--k1");
			if(index>0)
			{
			   cam_info->drc_pra.k1=atof(argv[index +1]);
			}else
			{
			    cam_info->drc_pra.k1=1.0;
			}
			index=find_pra_by_name(argc,argv,"--k2");
			if(index>0)
			{
			   cam_info->drc_pra.k2=atof(argv[index +1]);
			}else
			{
			    cam_info->drc_pra.k2=4.0;
			}
			index=find_pra_by_name(argc,argv,"--k3");
			if(index>0)
			{
			   cam_info->drc_pra.k3=atof(argv[index +1]);
			}else
			{
			    cam_info->drc_pra.k3=1.0;
			}
			return CAM_SET_DRC_MODE;
	    }
	    if(!strcmp("--get_drc_mode", argv[i])){
	        return CAM_GET_DRC_MODE;
	    }
	    if(!strcmp("--dbus_pipeline_ctl", argv[i])){
			int index=0;
			index=find_pra_by_name(argc,argv,"--sername");
			if(index>0)
			{
                sprintf(cam_info->ctl.name,"%s",argv[index+1]);
			}
			index=find_pra_by_name(argc,argv,"--stop");
			if(index>0)
			{
                cam_info->ctl.cmd=PIPELINE_CTL_STOP;
			}
			index=find_pra_by_name(argc,argv,"--start");
			if(index>0)
			{
                cam_info->ctl.cmd=PIPELINE_CTL_START;
			}
			index=find_pra_by_name(argc,argv,"--set_prop");
			if(index>0)
			{
			    char *cmd_buf=get_cmd_line(argc,argv);
				strcpy(cam_info->ctl.args,cmd_buf);
                cam_info->ctl.cmd=PIPELINE_CTL_SET_PROP;
				free(cmd_buf);
			}
			return CAM_PIPE_LINE_DBUS_CLT;
	    }
	    if(!(strcmp("--hdr_auto_detect", argv[i])))
		{
			cam_info->hdr_auto_detect=atoi(argv[i+1]);
            return CAM_SET_HDR_AUTO_DETET;
        }
        if(!(strcmp("--get_hdr_auto_detect", argv[i])))
		{
            return CAM_GET_HDR_AUTO_DETET;
        }
		if(!(strcmp("--hdr_mode", argv[i]))){
			int index=0;
			index=find_pra_by_name(argc,argv,"--sername");
			sprintf(cam_info->hdr_mode.name,"%s","ipcamserver");
			if(index>0)
			{
				sprintf(cam_info->hdr_mode.name,"%s",argv[index+1]);
			}
			cam_info->hdr_mode.hdr_on=atoi(argv[index+2]);
			index=find_pra_by_name(argc,argv,"--fps");
            if(index)
            {
				cam_info->hdr_mode.num=atoi(argv[index+1]);
            }
            return CAM_SET_HDR_MODE;
        }
		if(!(strcmp("--hdr_pra_mode", argv[i]))){
			int index=0;
			cam_info->hdr_pra_mode.mode=0;
			index=find_pra_by_name(argc,argv,"--mode");
			if(index>0)
			{
				cam_info->hdr_pra_mode.mode=atoi(argv[index+1]);
			}
			cam_info->hdr_pra_mode.exp_ration=16;
			index=find_pra_by_name(argc,argv,"--exp_ration");
			if(index>0)
			{
				cam_info->hdr_pra_mode.exp_ration=atoi(argv[index+1]);
			}
			cam_info->hdr_pra_mode.max_short_exp=90;
			index=find_pra_by_name(argc,argv,"--max_short_exp");
			if(index>0)
			{
				cam_info->hdr_pra_mode.max_short_exp=atoi(argv[index+1]);
			}
			index=find_pra_by_name(argc,argv,"--drc1");
			cam_info->hdr_pra_mode.drc1_k[0]=1;
			cam_info->hdr_pra_mode.drc1_k[1]=8;
			cam_info->hdr_pra_mode.drc1_k[2]=0.5;
			if(index>0)
			{
				cam_info->hdr_pra_mode.drc1_k[0]=atoi(argv[index+1]);
				cam_info->hdr_pra_mode.drc1_k[1]=atoi(argv[index+2]);
				cam_info->hdr_pra_mode.drc1_k[2]=atof(argv[index+3]);
			}
			index=find_pra_by_name(argc,argv,"--drc2");
			cam_info->hdr_pra_mode.drc2_k[0]=1;
			cam_info->hdr_pra_mode.drc2_k[1]=8;
			cam_info->hdr_pra_mode.drc2_k[2]=0.5;
			if(index>0)
			{
				cam_info->hdr_pra_mode.drc2_k[0]=atoi(argv[index+1]);
				cam_info->hdr_pra_mode.drc2_k[1]=atoi(argv[index+2]);
				cam_info->hdr_pra_mode.drc2_k[2]=atof(argv[index+3]);
			}
            return CAM_SET_HDR_PRA_MODE;
        }
        if(!(strcmp("--get_hdr_pra_mode", argv[i]))){
            return CAM_GET_HDR_PRA_MODE;
        }
	   if(!(strcmp("--set_zoom", argv[i]))){
			int index=0;
			index=find_pra_by_name(argc,argv,"--mode");
			cam_info->zoom.manual=0;
			if(index>0)
			{
				cam_info->zoom.manual=atoi(argv[index+1]);
			}
			index=find_pra_by_name(argc,argv,"--dig_zoom");
			cam_info->zoom.digital_zoom=1;
			if(index>0)
			{
				cam_info->zoom.digital_zoom=atof(argv[index+1]);
			}
			cam_info->zoom.stream_type=0;
			index=find_pra_by_name(argc,argv,"--stream_index");
			if(index>0)
			{
				cam_info->zoom.stream_type=atof(argv[index+1]);
			}
			index=find_pra_by_name(argc,argv,"--man_pra");
			if(index>0)
			{
				cam_info->zoom.roi.x=atof(argv[index+1]);
				cam_info->zoom.roi.y=atof(argv[index+2]);
				cam_info->zoom.roi.width=atof(argv[index+3]);
				cam_info->zoom.roi.height=atof(argv[index+4]);
			}
            return CAM_SET_ZOOM;
        }
   	   if(!(strcmp("--set_csc", argv[i]))){
     		int index=0;
     		index=find_pra_by_name(argc,argv,"--range");
     		cam_info->csc.full_range=1;
     		if(index>0)
     		{
     			cam_info->csc.full_range=atoi(argv[index+1]);
     		}
     		index=find_pra_by_name(argc,argv,"--type");
     		cam_info->csc.type=1; //601
     		if(index>0)
     		{
     			cam_info->csc.type=atoi(argv[index+1]);
     		}
            index=find_pra_by_name(argc, argv, "--sub_module");
            cam_info->csc.sub_module=0;
            if(index>0)
            {
                cam_info->csc.sub_module=atoi(argv[index+1]);
            }
            return CAM_SET_CSC;
        }
        if(!(strcmp("--set_de3d_pra", argv[i]))){
     		int index=0;
     		index=find_pra_by_name(argc,argv,"--enable");
     		cam_info->de3d_pra.enable=1;
     		if(index>0)
     		{
     			cam_info->de3d_pra.enable=atoi(argv[index+1]);
     		}
     		index=find_pra_by_name(argc,argv,"--mode");
     		cam_info->de3d_pra.mode=0;
     		if(index>0)
     		{
     			cam_info->de3d_pra.mode=atoi(argv[index+1]);
     		}
			index=find_pra_by_name(argc,argv,"--strength");
     		cam_info->de3d_pra.strength=0;
     		if(index>0)
     		{
     			cam_info->de3d_pra.strength=atoi(argv[index+1]);
     		}
			index=find_pra_by_name(argc,argv,"--sigma_cur");
     		cam_info->de3d_pra.denoise_3d_expert_pra.sigma_cur=100;
     		if(index>0)
     		{
     			cam_info->de3d_pra.denoise_3d_expert_pra.sigma_cur=atoi(argv[index+1]);
     		}
		    index=find_pra_by_name(argc,argv,"--sigma_pre");
     		cam_info->de3d_pra.denoise_3d_expert_pra.sigma_pre=100;
     		if(index>0)
     		{
     			cam_info->de3d_pra.denoise_3d_expert_pra.sigma_pre=atoi(argv[index+1]);
     		}
		    index=find_pra_by_name(argc,argv,"--sigma_big_block");
     		cam_info->de3d_pra.denoise_3d_expert_pra.sigma_big_block=100;
     		if(index>0)
     		{
     			cam_info->de3d_pra.denoise_3d_expert_pra.sigma_big_block=atoi(argv[index+1]);
     		}
            return CAM_SET_DE3D_PRA;
        }
		if(!(strcmp("--get_de3d_pra", argv[i]))){
            return CAM_GET_DE3D_PRA;
        }
        if(!(strcmp("--get_csc", argv[i]))){
            int index = find_pra_by_name(argc, argv, "--sub_module");
            if (index > 0)
            {
                cam_info->csc.sub_module = atoi(argv[index + 1]);
            }

            return CAM_GET_CSC;
        }
	    if(!(strcmp("--get_de2d_pra", argv[i]))){
			int index=0;
		    index=find_pra_by_name(argc,argv,"--denoise_type");
     		cam_info->de2d_pra.denoise_type=0;
     		if(index>0)
     		{
     			cam_info->de2d_pra.denoise_type=atoi(argv[index+1]);
     		}
            return CAM_GET_DE2D_PRA;
        }
	    if(!(strcmp("--set_de2d_pra", argv[i]))){
			int index=0;
		    index=find_pra_by_name(argc,argv,"--denoise_type");
     		cam_info->de2d_pra.denoise_type=0;
     		if(index>0)
     		{
     			cam_info->de2d_pra.denoise_type=atoi(argv[index+1]);
     		}
			index=find_pra_by_name(argc,argv,"--enable");
     		cam_info->de2d_pra.enable=1;
     		if(index>0)
     		{
     			cam_info->de2d_pra.enable=atoi(argv[index+1]);
     		}
			index=find_pra_by_name(argc,argv,"--mode");
     		cam_info->de2d_pra.mode=0;
     		if(index>0)
     		{
     			cam_info->de2d_pra.mode=atoi(argv[index+1]);
     		}
			index=find_pra_by_name(argc,argv,"--strength");
     		cam_info->de2d_pra.strength=50;
     		if(index>0)
     		{
     			cam_info->de2d_pra.strength=atoi(argv[index+1]);
     		}
			index=find_pra_by_name(argc,argv,"--dn_level");
     		cam_info->de2d_pra.denoise_2d_expert_pra.denoise_2d_cnf_expert_pra.dn_level=1;
     		if(index>0)
     		{
     			cam_info->de2d_pra.denoise_2d_expert_pra.denoise_2d_cnf_expert_pra.dn_level=atoi(argv[index+1]);
     		}
			index=find_pra_by_name(argc,argv,"--zoom_par");
     		cam_info->de2d_pra.denoise_2d_expert_pra.denoise_2d_cnf_expert_pra.zoom_par=1;
     		if(index>0)
     		{
     			cam_info->de2d_pra.denoise_2d_expert_pra.denoise_2d_cnf_expert_pra.zoom_par=atoi(argv[index+1]);
     		}
            return CAM_SET_DE2D_PRA;
        }
    }
    return -1;
}

static void show_format_info()
{
    printf("cmd format:\n");
    printf("test_cam_src --name [cam_Id] [cmd] [pra0] [pra1] [pra1] ...\n");
    printf("for the detail cmd , using --help to get more info\n");
}

static void usage(int argc, char* argv[])
{

    if (argc == 3){
        if(!(strcmp("name", argv[2]))){
            printf("[cam_id]: 0 for camera 0, 1 for camera 1, if not config --name , default camera 0\n");
            return;
        }
        if(!strcmp("aec_mode", argv[2])){
            printf("[mode]: AUTO  MANU\n");
            printf("eg: test_cam_src --name 0 --aec_mode MANU   [config cam aec to manu mode]\n");
            return;
        }
        if (!strcmp("get_aec_mode", argv[2])){
            printf("eg: test_cam_src --name 0 --get_aec_mode   [get cam aec mode]\n");
            return;
        }
        if(!(strcmp("awb_mode", argv[2]))){
            printf("D75 D65 D50 NOON CW TL84 A H CCUST1 CUST2 AUTO MANUAL\n");
            printf("eg: test_cam_src --name 0 --awb_mode D75  [config cam awb to D75 mode]\n");
            return;
        }
        if(!(strcmp("manu_aec", argv[2]))){

            printf("--manu_aec [mode] [gain] [exp_time] [luma]\n");
            printf("[mode] AUTO  MANU\n");
            printf("eg: test_cam_src --name 0 --manu_aec MANU 10 10 10\n");
            return;
        }
        if(!(strcmp("manu_awb", argv[2]))){
            printf("--manu_awb [mode] [cct] [r_gain] [g_gain] [b_gain]\n");
            printf("D75 D65 D50 NOON CW TL84 A H CCUST1 CUST2 AUTO MANUAL\n");
            printf("eg: test_cam_src --name 0 --manu_awb MANUAL  2000 1  1  1\n");
            return;
        }
        if(!strcmp("af_mode", argv[2])){
            printf("[mode]: AUTO CAF MACRO INFINITE MANUAL\n");
            printf("eg: test_cam_src --name 0 --af_mode CAF   [config cam af to CAF mode]\n");
            return;
        }
        if(!strcmp("af_roi", argv[2])){
            printf("--af_roi [x] [y] [width] [height]\n");
            printf("eg: test_cam_src --name 0 --af_roi  300 300 300 300\n");
            return;
        }
        if(!strcmp("error_proc", argv[2])){
            printf("[error code]: TIMEOUT\n");
            printf("eg: test_cam_src --name 0 --error_proc TIMEOUT   [trigger cam stream time-out error proc]\n");
            return;
        }
        if(!(strcmp("set_bright", argv[2]))){
            printf("--set_bright [val]\n");
            printf("eg: test_cam_src --name 0 --set_bright 80\n");
            return;
        }
        if(!(strcmp("set_contrast", argv[2]))){
            printf("--set_contrast [val]\n");
            printf("eg: test_cam_src --name 0 --set_contrast 80\n");
            return;
        }
        if(!(strcmp("set_sharpness", argv[2]))){
            printf("--set_sharpness [val]\n");
            printf("eg: test_cam_src --name 0 --set_sharpness 80\n");
            return;
        }
        if(!(strcmp("set_satubility", argv[2]))){
            printf("--set_satubility [val]\n");
            printf("eg: test_cam_src --name 0 --set_satubility 80\n");
            return;
        }
        if(!(strcmp("enable_de3d", argv[2]))){
            printf("--enable_de3d [state]\n");
            printf("eg: test_cam_src --name 0 --enable_de3d 0    \n");
            return;
        }
        if(!(strcmp("enable_flip", argv[2]))){
            printf("--enable_flip [state]\n");
            printf("eg: test_cam_src --name 0 --enable_flip 0    \n");
            return;
        }
        if(!(strcmp("enable_mirror", argv[2]))){
            printf("--enable_mirror [state]\n");
            printf("eg: test_cam_src --name 0 --enable_mirror 1  \n");
            return;
        }
        if(!(strcmp("get_flip", argv[2]))){
            printf("--get_flip\n");
            printf("eg: test_cam_src --name 0 --get_flip   \n");
            return;
        }
        if(!(strcmp("get_mirror", argv[2]))){
            printf("--get_mirror\n");
            printf("eg: test_cam_src --name 0 --get_mirror   \n");
            return;
        }
        if(!(strcmp("get_cam_info", argv[2]))){
            printf("--get_cam_info\n");
            printf("eg: test_cam_src --get_cam_info    \n");
            return;
        }
        if(!(strcmp("ae_roi", argv[2]))){
            printf("--ae_roi [x] [y] [width] [height]\n");
            printf("eg: test_cam_src --name 0 --ae_roi  300 300 300 300\n");
            return;
        }
        if(!(strcmp("get_ae_roi", argv[2]))){
            printf("eg: test_cam_src --name 0 --get_ae_roi\n");
            return;
        }
        if(!(strcmp("set_scene_mode", argv[2]))){
            printf("--set_scene_mode [mode]\n");
             printf("eg: test_cam_src --set_scene_mode  0       \n");
            return;
        }
        if(!(strcmp("get scene", argv[2]))){
            printf("--get_scene \n");
            printf("[scene]   normal   night\n");
            printf("eg: test_cam_src --get_scene         \n");
            return;
        }
        if(!(strcmp("get_scene_mode", argv[2]))){
            printf("--get_scene_mode [mode]\n");
            printf("eg: test_cam_src --get_scene_mode          \n");
            return;
        }
        if(!(strcmp("set_scene", argv[2]))){
            printf("--set_scene  [scene] [led_flag] [ir_cut_flag] [fps_dajust_falg] [fps_rudecue]\n");
            printf("[scene]   normal   night\n");
            printf("eg: test_cam_src --set_scene  night  0  0  0   10 \n");
            return;
        }
        if(!(strcmp("enable_led", argv[2]))){
             printf("--enable_led  [state]\n");
             printf("eg: test_cam_src --set_led  0   \n");
            return;
        }
        if(!(strcmp("enable_ir_cutter", argv[2]))){
            printf("--enable_ir_cutter [state]\n");
            printf("eg: test_cam_src --set_ir_cutter  0   \n");
            return;
        }
        if(!(strcmp("enable_banding", argv[2]))){
            printf("--enable_banding   [state]\n");
            printf("eg: test_cam_src --set_banding  0   \n");
            return;
        }
        if(!(strcmp("get_banding", argv[2]))){
            printf("--get_banding   \n");
            printf("eg: test_cam_src --get_banding   \n");
            return;
        }
        if(!(strcmp("set_fps_range", argv[2]))){
            printf("--set_fps_range --fps_min [val] --fps_max [val]\n");
            printf("eg: test_cam_src  --set_fps_range --fps_min 10  --fps_max 20\n");
            return;
        }
        if(!(strcmp("set_exp_limit", argv[2]))){
            printf("--set_exp_limit [val]\n");
            printf("eg: test_cam_src  --set_exp_limit  100\n");
            return;
        }
		if(!(strcmp("set_face_aec", argv[2]))){
            printf("--set_face_aec [face_count] [weight] [face_target] [face_keep_frame_count] [x] [y] [width] [height]\n");
            printf("eg: test_cam_src  --set_face_aec  1 0.9 52 1000 0.25 0.25 0.25 0.25\n");
            return;
        }
	    if(!(strcmp("set_hdr_algo_state", argv[2]))){
            printf("--set_hdr_algo_state [on/off]\n");
            printf("eg: test_cam_src  --set_hdr_algo_state  1 // on the hdr\n");
            return;
        }
        if(!(strcmp("get_hdr_algo_state", argv[2]))){
            printf("--get_hdr_algo_state [on/off]\n");
            printf("eg: test_cam_src --name 0 --get_hdr_algo_state  \n");
            return;
        }
        if(!(strcmp("set_cam_eis", argv[2]))){
            printf("--set_cam_eis --eis_algo [state] --eis_distor [state]\n");
            printf("eis_algo state: 0 for open eis algo, 1 for close\n");
            printf("eis_distor state: 0 for noting, 1 for x, 2 for y , 3 for x and y\n");
            return;
        }
		if(!(strcmp("dvp_notify", argv[2]))){
            printf("--dvp_notify --notify_code[code] --w[w] --h[h] --num[num] --den[den] --interlace[interlace]\n");
            printf("--notify_code: [1:NOTIFY_HDMI_CONNECT] [0:NOTIFY_HDMI_DISCONNECT] [2:NOTIFY_HDMI_FORAMAT_CHANGE]\n");
	        printf("eg: test_cam_src --dvp_notify --notify_code 1 --w 1920 --h 1080 --num 60 --den 1 --interlace 0 --chs 2 --foramt 16 --rate 48000 \n");
            return;
        }

        if(!(strcmp("set_isp_module", argv[2]))){
            printf("isp module list:\n");
            printf("    ata\n");
            printf("    blc\n");
            printf("    cac\n");
            printf("    ccm1\n");
            printf("    ccm2\n");
            printf("    cfa\n");
            printf("    cm\n");
            printf("    cnf\n");
            printf("    compander\n");
            printf("    de3d\n");
            printf("    decompander\n");
            printf("    digigain1\n");
            printf("    digigain2\n");
            printf("    dither\n");
            printf("    dpc\n");
            printf("    dpp\n");
            printf("    drc\n");
            printf("    gamma\n");
            printf("    gic\n");
            printf("    gtm1\n");
            printf("    gtm2\n");
            printf("    hdr\n");
            printf("    lee\n");
            printf("    lsc\n");
            printf("    lut3d\n");
            printf("    crop\n");
            printf("    rgb2yuv\n");
            printf("    rnr\n");
            printf("    wb \n");
            printf("    algo_aec \n");
            printf("    algo_awb\n");
            printf("    algo_af\n");
            printf("eg: test_cam_src --set_isp_module --[isp_module] [on/off]\n");
            return;
        }
		if(!(strcmp("drc_mode", argv[2]))){
            printf("--drc_mode --mode[0:auto/1:off/2:manual] --gain[0.3] --k1[1] --k2[4] --k3[1] \n");
	        printf("eg: test_cam_src --name 0 --drc_mode --mode 2 --gain 0.3 --k1 1.0 --k2 4.0  --k3 1.0 \n");
            return;
        }
        if(!(strcmp("get_drc_mode", argv[2]))){
            printf("--drc_mode [0:auto/1:off]\n");
            printf("eg: test_cam_src --name 0 --drc_mode \n");
            return;
        }
		if(!(strcmp("dbus_pipeline_ctl", argv[2]))){
			printf("--name [name]\n eg:--sername uvcserver0/ipcamserver\n");
            printf("--stop: stop the pipeline\n");
			printf("--start: start the pipeline\n");
			printf("--set_prop: --hdr --fps 25 --res 1920 1080 \n");
            return;
        }
		if(!(strcmp("hdr_auto_detect", argv[2]))){
			printf("--hdr_auto_detect [0/1]\n");
			printf("eg test_cam_src --name 0 --hdr_auto_detect 1\n");
            return;
        }
        if(!(strcmp("get_hdr_auto_detect", argv[2]))){
            printf("eg test_cam_src --name 0 --get_hdr_auto_detect\n");
            return 0;
        }
		if(!(strcmp("hdr_mode", argv[2]))){
			printf("--hdr_mode --name [server_name] [0/1] --fps [fps]eg:--hdr_mode --sername uvc_server/ipcam_server [0/1] [30/25]\n");
            return;
        }
		if(!(strcmp("hdr_pra_mode", argv[2]))){
			printf("--mode [0/1/2] : 0 auto 1 normal 2 expert\n");
			printf("--exp_ration [ration]\n");
			printf("--max_short_exp [max_exp]\n");
			printf("--drc1 k1 k2 k3 \n");
			printf("--drc2 k1 k2 k3 \n");
            return;
        }
        if(!(strcmp("get_hdr_pra_mode", argv[2]))){
			printf("--mode [0/1/2] : 0 auto 1 normal 2 expert\n");
			printf("--exp_ration [ration]\n");
			printf("--max_short_exp [max_exp]\n");
			printf("--drc1 k1 k2 k3 \n");
			printf("--drc2 k1 k2 k3 \n");
			printf("eg: test_cam_src --name 0 --get_hdr_pra_mode\n");
            return;
        }
		if(!(strcmp("set_zoom", argv[2]))){
			printf("--mode [0/1] : 0 auto 1 manual \n");
			printf("--dig_zoom [zoom]\n");
			printf("--stream_index [index]\n");
			printf("--man_pra [x,y,w,h] eg: --man_pra 0 0 0.75 0.75\n");
            return;
        }
	    if(!(strcmp("set_csc", argv[2]))){
			printf("--range [0/1] : 0 limited 1 full \n");
			printf("--type [0/1]: 0:709 1:601 \n");
			printf("--sub_module [0/1]: 0:vif 1: isp\n");
			printf("eg: test_cam_src --name 0 --set_csc --sub_module 0 --range 0 --type 0\n");
            return;
        }
        if(!(strcmp("get_csc", argv[2]))){
            printf("eg: test_cam_src --name 0 --get_csc --sub_module 0\n");
            return;
        }
	   if(!(strcmp("set_de3d_pra", argv[2]))){
			printf("--enable [0/1] : 1 enable the 3d 0:disable \n");
			printf("--mode [0/1/2]: 0:DENOISE_MODE_AUTO 1:DENOISE_MODE_MANUAL 2:DENOISE_MODE_EXPERT \n");
			printf("--strength [0---100]: when mode ==1, the pra is valide, 50 is default ,< 50 decrease the denoise ,> 50 increase base current \n");
		    printf("--sigma_cur [0---1000]: when mode==2, the pra is valide, the larger the value ,more denoise \n");
		    printf("--sigma_pre [0---1000]: when mode==2, the pra is valide, the larger the value ,more denoise \n");
		    printf("--sigma_big_block [0---1000]: when mode==2, the pra is valide, the larger the value ,more denoise \n");
           return;
        }
	    if(!(strcmp("get_de2d_pra", argv[2]))){
			printf("--denoise_type [0/1] : 1 NOISE_TYPE_CHROMA 0:NOISE_TYPE_LUMA \n");
			return;
	    }
	    if(!(strcmp("set_de2d_pra", argv[2]))){
			printf("--denoise_type [0/1] : 0:NOISE_TYPE_LUMA 1:NOISE_TYPE_CHROMA \n");
			printf("--enable [0/1] : 1 enable 0:disable \n");
			printf("--mode [0/1/2] : 0:DENOISE_MODE_AUTO 1:DENOISE_MODE_MANUAL 2:DENOISE_MODE_EXPERT \n");
			printf("--strength [0----100] :50 is default, increat have more noise \n");
			printf("--zoom_par [2----10] :cnf denoise when DENOISE_MODE_EXPERT and denoise_type==NOISE_TYPE_CHROMA\n");
			printf("--dn_level [1----3] :cnf denoise when DENOISE_MODE_EXPERT and denoise_type==NOISE_TYPE_CHROMA\n");
			return;
	    }
    }
    printf("[cmd list]:\n");
    printf("--name               \n");
    printf("--aec_mode           \n");
    printf("--get_aec_mode       \n");
    printf("--awb_mode           \n");
    printf("--manu_aec           \n");
    printf("--manu_awb           \n");
    printf("--af_mode            \n");
    printf("--af_roi             \n");
    printf("--get_ae_roi         \n");
    printf("--error_proc         \n");
    printf("--set_bright         \n");
    printf("--set_contrast       \n");
    printf("--set_sharpness      \n");
    printf("--set_satubility     \n");
    printf("--enable_de3d        \n");
    printf("--enable_flip        \n");
    printf("--enable_mirror      \n");
    printf("--get_mirror      \n");
    printf("--get_flip      \n");
    printf("--ae_roi             \n");
    printf("--set_scene          \n");
    printf("--get_scene          \n");
    printf("--set_scene_mode          \n");
    printf("--get_scene_mode          \n");
    printf("--enable_led         \n");
    printf("--enable_ir_cutter   \n");
    printf("--enable_banding     \n");
    printf("--get_banding     \n");
    printf("--set_fps_range      \n");
    printf("--get_bright\n");
    printf("--get_drc_mode\n");
    printf("--get_contrast\n");
    printf("--get_sharpness\n");
    printf("--get_satubility\n");
    printf("--get_3a_info\n");
	printf("--get_3a_info_ext: display more 3a info\n");
    printf("--set_exp_limit     \n");
	printf("--set_face_aec  \n");
	printf("--set_hdr_algo_state  \n");
	printf("--get_hdr_algo_state \n");
	printf("--set_cam_eis \n");
	printf("--dvp_notify \n");
    printf("--set_isp_module \n");
    printf("--drc_mode \n");
	printf("--dbus_pipeline_ctl \n");
    printf("--hdr_auto_detect \n");
    printf("--get_hdr_auto_detect \n");
    printf("--hdr_mode \n");
    printf("--hdr_pra_mode \n");
    printf("--get_hdr_pra_mode \n");
    printf("--get_cam_info \n");
    printf("--set_zoom \n");
    printf("--set_csc \n");
    printf("--get_csc \n");
    printf("--set_de3d_pra \n");
    printf("--get_de3d_pra \n");
    printf("--set_de2d_pra \n");
    printf("--get_de2d_pra \n");
}

int ar_cam_set_hdr_mode(char * server_name, int val,int num)
{
    int fps=num;
	if(!server_name){
		printf("Invalid server_name\n");
		return -1;
	}

	char cmd[64]={0};
	sprintf(cmd,"--hdr %d --fps %d",val,fps);
	pipeline_ctl_client_t *client=ar_pipeline_clt_creat_client(server_name,NULL);
	printf("stop the pipeline\n");
	ar_pipeline_clt_stop(client);
	printf("set the cmd %s\n",cmd);
	ar_pipeline_clt_set_prop(client,cmd,strlen(cmd)+1);
	printf("restart the pipeline\n");
	ar_pipeline_clt_start(client);
	ar_pipeline_clt_delete_client(client);
}

static int dump_3a_ext_info(algo_3a_get_info_t  *ext_3a_info)
{
   printf("3a ext info: \n");
   printf("gain=%f \n",ext_3a_info->aec_info.gain);
   printf("exp_index=%d \n",ext_3a_info->aec_info.exp_index);
   printf("lux_index=%d \n",ext_3a_info->aec_info.lux_index);
   printf("luma_target=%d \n",ext_3a_info->aec_info.luma_target);
   printf("current_luma=%d \n",ext_3a_info->aec_info.current_luma);
   printf("long_exp_ration=%f \n",ext_3a_info->aec_info.long_exp_ration);
   printf("max_drc_gain=%f \n",ext_3a_info->aec_info.max_drc_gain);
   printf("min_drc_gain=%f \n",ext_3a_info->aec_info.min_drc_gain);
   printf("max_drc_gain1 (ceva max drc gain)=%f \n",ext_3a_info->aec_info.max_drc_gain1);
   printf("ration_time=%f \n",ext_3a_info->aec_info.ration_time);
   printf("ration_gain=%f \n",ext_3a_info->aec_info.ration_gain);
   printf("ration_total=%f \n",ext_3a_info->aec_info.ration_total);
   printf("drc_gain1(ceva gain)=%f \n",ext_3a_info->aec_info.drc_gain1);
   printf("drc_gain2(isp drc gain)=%f \n",ext_3a_info->aec_info.drc_gain2);
   printf("drc_gain=%f \n",ext_3a_info->aec_info.drc_gain);
   printf("cur_real_gain_short=%f \n",ext_3a_info->aec_info.cur_real_gain_short);
   printf("cur_real_gain=%f \n",ext_3a_info->aec_info.cur_real_gain);
   printf("cur_line_cnt_short=%d \n",ext_3a_info->aec_info.cur_line_cnt_short);
   printf("cur_line_cnt=%d \n",ext_3a_info->aec_info.cur_line_cnt);
   printf("short_luma=%d \n",ext_3a_info->aec_info.short_luma);
   printf("short_exp_index=%d \n",ext_3a_info->aec_info.short_exp_index);
   return 0;
}

int main(int argc, char* argv[])
{
	int opt = 0;
	char device_name[64];
	int cmd_id = -1;
	int fd = -1;
    test_cam_info_t  cam_info = {0};
	if(argc < 2){
		printf("input par error\n");
		printf("input eg:\n");
		printf("test_cam-src [device_name] [cmd_id] [pra]...");
		show_format_info();
		return -1;
	}
    if(!strcmp("--help", argv[1])){
        usage(argc, argv);
        return -1;
    }

    cmd_id = cmd_prase(argc, argv, &cam_info);

    if(CAM_GET_CAM_INFO != cmd_id)
    {
        sprintf(device_name, "/dev/cam_src-%d", cam_info.camera_id);

    	fd = ar_cam_src_open(device_name);
    	if(fd < 0){
    		printf("open device %s failed fd=%d\n", device_name,fd);
    		return -1;
    	}
    	printf("[cam src test]: open device success\n");
    }
	printf("[cam src test]:the cmd_id is %d\n", cmd_id);
	switch(cmd_id){
		case CAM_SET_AEC_MODE:
		{
		    ar_cam_aec_set_mode(fd, cam_info.basic_3a_info.aec_info.aec_mode);
		}
		break;
		case CAM_SET_AWB_MODE:
		{
			printf("[cam src test]: set awb mode, mode is %d\n", cam_info.basic_3a_info.awb_info.awb_mode);
			ar_cam_awb_set_mode(fd, cam_info.basic_3a_info.awb_info.awb_mode);
		}
		break;
		case CAM_SET_MANU_AEC:
		{
			printf("[cam src test]: set manu aec, mode is %d, gain is %f, exp_time is %f, luma is %d\n", cam_info.basic_3a_info.aec_info.aec_mode, cam_info.basic_3a_info.aec_info.gain, cam_info.basic_3a_info.aec_info.exp_time_us, cam_info.basic_3a_info.aec_info.luma_target);
			ar_cam_aec_manu_set(fd, cam_info.basic_3a_info.aec_info);
		}
		break;
		case CAM_SET_MANU_AWB:
		{
			printf("[cam_src_test]: set manu awb, mode is %d, cct is %d, rgain is %f, ggain is %f, bgain is %f\n", cam_info.basic_3a_info.awb_info.awb_mode, cam_info.basic_3a_info.awb_info.cct, cam_info.basic_3a_info.awb_info.r_gain, cam_info.basic_3a_info.awb_info.g_gain, cam_info.basic_3a_info.awb_info.b_gain);
			ar_cam_awb_manu_set(fd, cam_info.basic_3a_info.awb_info);
		}
		break;
        case CAM_SET_AF_MOD:
        {
            ar_cam_af_set_mode(fd, cam_info.af_mode);
        }
        break;
        case CAM_SET_AF_ROI:
        {
            printf("[af roi]: x=%f, y=%f, width=%f, height=%f\n", \
            cam_info.af_roi_info.x, cam_info.af_roi_info.y, \
            cam_info.af_roi_info.width, cam_info.af_roi_info.height);
            ar_cam_set_af_roi(fd, cam_info.af_roi_info);
        }
        break;
        case CAM_TRIGGER_ERROR_PROC:
        {
            printf("[error proc]: code 0x%x\n", cam_info.error_code);
            ar_cam_trigger_error_proc(fd, cam_info.error_code);
        }
        break;
		case CAM_SET_BRIGHTNESS:
		{

			printf("[cam src test]: config cam brigtness, the val is %d\n", cam_info.cam_bright);
			ar_cam_set_brightness(fd, cam_info.cam_bright);
		}
		break;
		case CAM_SET_CONTRAST:
		{
			printf("[cam src test]: config cam contrast, the val is %d\n", cam_info.cam_contrast);
			ar_cam_set_contrast(fd, cam_info.cam_contrast);
		}
		break;
		case CAM_SET_SHARPNESS:
		{
			printf("[cam src test]: config cam shapen, the val is %d\n", cam_info.cam_sharpness);
			ar_cam_set_shapeness(fd, cam_info.cam_sharpness);
		}
		break;
		case CAM_SET_SATURABILITY:
		{
			printf("[cam src test]: config cam saturability, the val is %d\n", cam_info.cam_satubility);
			ar_cam_set_saturability(fd, cam_info.cam_satubility);
		}
		break;
		case CAM_ENABLE_DE3D:
		{
			printf("[cam src test]: config the de3d enable, the val is %d\n", cam_info.de3d_state);
			ar_cam_de3d_set_state(fd, cam_info.de3d_state);
		}
		break;
		case CAM_SET_FLIP:
		{
			printf("[cam src test]: cam_flip, the val is %d\n", cam_info.flip_state);
			ar_cam_flip_set_state(fd, cam_info.flip_state);
		}
		break;
		case CAM_SET_MIRROR:
		{
			printf("[cam src test]: cam_mirror the val is %d\n", cam_info.mirror_state);
			ar_cam_mirror_set_state(fd, cam_info.mirror_state);
		}
		break;
		case CAM_GET_MIRROR:
		{
			ar_cam_mirror_get_state(fd, &cam_info.mirror_state);
			printf("[get cam mirror]: the val is %d\n", cam_info.mirror_state);
		}
		break;
		case CAM_GET_FILP:
		{
			ar_cam_flip_get_state(fd, &cam_info.flip_state);
			printf("[get cam flip]: the val is %d\n", cam_info.flip_state);
		}
		break;
        case CAM_GET_CAM_INFO:
        {
            printf("[cam src test]: get_cam_info\n");
            int cam_num = ar_cam_src_get_cam_num();
            int ret;
            printf("  cam num : %d\n",cam_num);
            camera_image_info_t cam_info_context;
            for(int i = 0; i<cam_num;i++)
            {
                memset(&cam_info_context,0, sizeof(ar_cam_src_get_cam_info));

                ret = ar_cam_src_get_cam_info(i, &cam_info_context);
                if(ret)
                {
                    printf("    cam %d : get info failed %d\n",i,ret);
                }
                else
                {
                    printf("    cam %d : \n",i);
                    printf("      cam_id %d\n",cam_info_context.cam_id);
                    printf("      cam_name %s\n",cam_info_context.cam_name);
                    printf("      res num %d\n",cam_info_context.num);
                    for(int j = 0; j<cam_info_context.num; j++)
                    {
                        printf("      res %d : \n",j);
                        printf("        is_hdr %d\n",cam_info_context.image_res_context[j].is_hdr);
                        printf("        width %d\n",cam_info_context.image_res_context[j].width);
                        printf("        height %d\n",cam_info_context.image_res_context[j].height);
                        printf("        hdr_width %d\n",cam_info_context.image_res_context[j].hdr_width);
                        printf("        hdr_height %d\n",cam_info_context.image_res_context[j].hdr_height);
                        printf("        fps %f\n",cam_info_context.image_res_context[j].fps);
                    }
					printf("slave_mode=%d \n",cam_info_context.slave_mode);
					printf("slave_num=%d \n",cam_info_context.slave_num);
					printf("master_sensor=%s \n",cam_info_context.master_sensor);
					for(int j=0;j<cam_info_context.slave_num;j++)
					{
						printf("slave_sensor=%s \n",cam_info_context.slave_sensor[j]);
					}
                }

            }
        }
        break;
		case CAM_SET_ROI:
        {
            printf("[ae roi]: x=%f, y=%f, width=%f, height=%f\n", cam_info.roi_info.x, cam_info.roi_info.y, cam_info.roi_info.width, cam_info.roi_info.height);
			ar_cam_set_ae_roi(fd, cam_info.roi_info);
		}
        break;
        case CAM_GET_AE_ROI:
        {
            ar_cam_get_ae_roi(fd, &cam_info.roi_info);
            printf("[get ae roi]: x=%f, y=%f, width=%f, \
            height=%f\n", cam_info.roi_info.x, cam_info.roi_info.y, \
            cam_info.roi_info.width, cam_info.roi_info.height);
        }
        break;
        case CAM_SET_SENCE_MODE:
        {
            printf("[sencse mode]: %d\n", cam_info.sense_mode);
            ar_cam_set_scene_mode(fd, cam_info.sense_mode);
        }
        break;
        case CAM_GET_SCENE_MODE:
        {
            ar_cam_get_scene_mode(fd, &cam_info.sense_mode);
            printf("get scene mode = %d \n", cam_info.sense_mode);
        }
        break;
        case CAM_SET_SENSE:
        {
            printf("[set sensce]: mode=%d, led_flag=%d, ir_cut_flag=%d,fps_adjust_flag=%d, fps_rudecue_to=%d\n", cam_info.sense_info.sensce, cam_info.sense_info.led_flag, cam_info.sense_info.ir_cut_flag, cam_info.sense_info.fps_adjust_flag, cam_info.sense_info.fps_rudecue_to);
            ar_cam_set_sensce(fd, cam_info.sense_info);
        }
        break;
        case CAM_GET_SCENE:
        {
            ar_cam_get_scene(fd, &cam_info.sense_info.sensce);
            printf("get scene : %d \n", cam_info.sense_info.sensce);
        }
        break;
		case CAM_SET_LED:
        {
            printf("[set led]: %d\n", cam_info.led_state);
			ar_cam_led_set_state(fd, cam_info.led_state);
        }
		break;
		case CAM_SET_IR_CUTTER:
        {
            printf("[set ir cutter]: %d\n", cam_info.ir_cut_state);
			ar_cam_ir_cutter_set_state(fd, cam_info.ir_cut_state);
        }
		break;
		case CAM_SET_FPS_RANGE:
        {
            printf("[fps range]: min_fps=%d, max_fps=%d\n", cam_info.fps_info.fps_min, cam_info.fps_info.fps_max);
			ar_cam_set_fps_range(fd, cam_info.fps_info);
        }
		break;
		case CAM_SET_BANDING:
        {
            printf("[set banding]: %d\n", cam_info.banding_state);
			ar_cam_banding_set_state(fd, cam_info.banding_state);
        }
		break;
        case CAM_GET_BANDING:
        {
            ar_cam_banding_get_state(fd, &cam_info.banding_state);
            printf("get antibanding: %d\n", cam_info.banding_state);
        }
        break;
        case CAM_GET_BRIGHT:
        {
			int val = -1;
			ar_cam_get_brightness(fd, &val);
			printf("the bright =%d\n", val);
        }
        break;
        case CAM_GET_SATURABILITY:
        {
			int val = -1;
			ar_cam_get_saturability(fd, &val);
			printf("the saturability =%d\n", val);
        }
        break;
        case CAM_GET_CONTRAST:
        {
			int val = -1;
			ar_cam_get_contrast(fd, &val);
			printf("the contrast=%d\n", val);
        }
        break;
        case CAM_GET_SHARPNESS:
        {
			int val = -1;
			ar_cam_get_sharpness(fd, &val);
			printf("the sharpness =%d\n", val);
        }
        break;
        case CAM_GET_3A_INFO:
        {
			basic_3a_info_t  basic_3a_info;
			ar_cam_get_3a_info(fd, &basic_3a_info);
			printf("3a info: \n");
			printf("[aec]:mode=%d, gain=%f, exp_time=%f, luma=%d\n", basic_3a_info.aec_info.aec_mode, (basic_3a_info.aec_info.gain), (basic_3a_info.aec_info.exp_time_us)*1000000, basic_3a_info.aec_info.luma_target);
			printf("[awb]:mode=%d, r_gain=%f, g_gain=%f, b_gain=%f cct=%d\n", basic_3a_info.awb_info.awb_mode, (basic_3a_info.awb_info.r_gain), \
				(basic_3a_info.awb_info.g_gain), (basic_3a_info.awb_info.b_gain),basic_3a_info.awb_info.cct);
		}
        break;
        case CAM_GET_3A_INFO_EXT:
        {
			algo_3a_get_info_t  *ext_3a_info=malloc(sizeof(algo_3a_get_info_t));
			ar_cam_get_3a_info_ext(fd, ext_3a_info);
            dump_3a_ext_info(ext_3a_info);
		}
        break;
        case CAM_GET_AEC_MODE:
        {
            int val = -1;
            ar_cam_aec_get_mode(fd, &val);
            if (0 == val)
                printf("get the aec mode = [%d:%s]\n", val, "AUTO");
            else if (5 == val)
                printf("get the aec mode = [%d:%s]\n", val, "MANU");
        }
        break;
        case CAM_SET_EXP_LIMIT:
        {
            printf("the exp limit val = %d\n", cam_info.exp_limit);
            ar_cam_set_exp_limit(fd, cam_info.exp_limit);
        }
		break;
		case CAM_SET_FACE_AEC:
		{
			printf("face_count=%d face_weight=%f face_target=%d face_keep_frame_count=%d %f %f %f %f\n", \
				cam_info.face_roi.face_count,cam_info.face_roi.face_weight,cam_info.face_roi.face_target,cam_info.face_roi.face_keep_frame_count,\
				cam_info.face_roi.face_roi[0].x,cam_info.face_roi.face_roi[0].y,cam_info.face_roi.face_roi[0].width,cam_info.face_roi.face_roi[0].height);
			ar_cam_set_face_aec(fd,&cam_info.face_roi);
		}
        break;
        case CAM_SET_HDR:
        {
            printf("the hdr_mode = %d\n", cam_info.hdr_algo_mode);
            ar_cam_set_hdr_algo_status(fd, cam_info.hdr_algo_mode);
        }
        break;
        case CAM_GET_HDR:
        {
            ar_cam_get_hdr_algo_status(fd, &cam_info.hdr_algo_mode);
            printf("get hdr_mode = %d\n", cam_info.hdr_algo_mode);
        }
        break;
		case CAM_SET_EIS:
        {
            printf("the eis algo = %d, eis distortion = %d\n", cam_info.eis_cfg.eis_algo_state, cam_info.eis_cfg.eis_distortion_state);
            ar_cam_set_eis(fd, cam_info.eis_cfg);
            break;
        }
		case CAM_SET_DVP_NOTIFY:
		{
			printf("[CAM_SET_DVP_NOTIFY]dvp_notify: code=%d w=%d h=%d num=%d den=%d interlace=%d chanles=%d,format=%d rate=%d\n",\
			cam_info.dvp_notify.code,cam_info.dvp_notify.w,cam_info.dvp_notify.h,cam_info.dvp_notify.num,cam_info.dvp_notify.den,cam_info.dvp_notify.interlace,\
			cam_info.dvp_notify.chanles,cam_info.dvp_notify.format,cam_info.dvp_notify.rate);
            ar_dvp_video_in_send_notify(cam_info.dvp_notify.code,cam_info.dvp_notify.w,cam_info.dvp_notify.h,cam_info.dvp_notify.num,cam_info.dvp_notify.den,cam_info.dvp_notify.interlace,\
				cam_info.dvp_notify.chanles,cam_info.dvp_notify.format,cam_info.dvp_notify.rate);
		}
		break;
        case CAM_ENDEN_ISP_MODULE:
        {
            ar_cam_set_cam_isp_submodule_state(fd, cam_info.tuning_req.isp_module, cam_info.tuning_req.en_flag);
        }
        break;
		case CAM_SET_DRC_MODE:
		{
			printf("CAM_SET_DRC_MODE mode=%d gain=%f, k1=%f k2=%f k3=%f \n",cam_info.drc_pra.mode, cam_info.drc_pra.gain,cam_info.drc_pra.k1,cam_info.drc_pra.k2,cam_info.drc_pra.k3);
			ar_cam_set_drc(fd, cam_info.drc_pra.mode, cam_info.drc_pra.gain,cam_info.drc_pra.k1,cam_info.drc_pra.k2,cam_info.drc_pra.k3);
		}
		break;
		case CAM_GET_DRC_MODE:
		{
		    CAM_PRA_SET_DRC_MODE_pra_t drc_pra;
		    ar_cam_get_drc(fd, &drc_pra);
		    cam_info.drc_pra.mode = drc_pra.mode;
		    cam_info.drc_pra.gain = drc_pra.drc_pra.gain;
		    cam_info.drc_pra.k1 = drc_pra.drc_pra.k1;
		    cam_info.drc_pra.k2 = drc_pra.drc_pra.k2;
		    cam_info.drc_pra.k3 = drc_pra.drc_pra.k3;
		    printf("get drc mode=%d gain=%f, k1=%f k2=%f k3=%f \n", \
		    cam_info.drc_pra.mode, cam_info.drc_pra.gain,cam_info.drc_pra.k1, \
		    cam_info.drc_pra.k2,cam_info.drc_pra.k3);
		}
		break;
		case CAM_PIPE_LINE_DBUS_CLT:
		{
            pipeline_ctl_client_t *client=ar_pipeline_clt_creat_client(cam_info.ctl.name,NULL);
			switch(cam_info.ctl.cmd)
			{
			   case PIPELINE_CTL_STOP:
               ar_pipeline_clt_stop(client);
			   break;
			   case PIPELINE_CTL_START:
			   ar_pipeline_clt_start(client);
			   break;
			   case PIPELINE_CTL_SET_PROP:
			   ar_pipeline_clt_set_prop(client,cam_info.ctl.args,strlen(cam_info.ctl.args)+1);
			   break;
			   default:
			   break;
			}
			ar_pipeline_clt_delete_client(client);
		}
		break;
        case CAM_SET_HDR_AUTO_DETET:
		{
		   printf("hdr_auto_detect=%d\n",cam_info.hdr_auto_detect);
		   ar_cam_set_hdr_auto_detect(fd, cam_info.hdr_auto_detect);
        }
		break;
        case CAM_GET_HDR_AUTO_DETET:
        {
            ar_cam_get_hdr_auto_detect(fd, &cam_info.hdr_auto_detect);
            printf("get hdr auto detect=%d\n",cam_info.hdr_auto_detect);
        }
        break;
		case CAM_SET_HDR_MODE:
		{
			printf("name=%s hdr_on=%d num=%d\n",cam_info.hdr_mode.name,cam_info.hdr_mode.hdr_on,cam_info.hdr_mode.num);
			ar_cam_set_hdr_mode(cam_info.hdr_mode.name, cam_info.hdr_mode.hdr_on,cam_info.hdr_mode.num);
		}
		break;
		case CAM_SET_HDR_PRA_MODE:
		{
            printf("mode=%d max_short_exp=%d,exp_ration=%f,ceva_k1 k2 k3 =(%f %f %f), isp k1 k2 k3 =(%f %f %f)\n",\
			cam_info.hdr_pra_mode.mode,cam_info.hdr_pra_mode.max_short_exp,cam_info.hdr_pra_mode.exp_ration,\
			cam_info.hdr_pra_mode.drc1_k[0],cam_info.hdr_pra_mode.drc1_k[1],cam_info.hdr_pra_mode.drc1_k[2],\
			cam_info.hdr_pra_mode.drc2_k[0],cam_info.hdr_pra_mode.drc2_k[1],cam_info.hdr_pra_mode.drc2_k[2]);
		    ar_cam_set_hdr_par_mode(fd,&cam_info.hdr_pra_mode);
		}
		break;
        case CAM_GET_HDR_PRA_MODE:
        {
            ar_cam_get_hdr_par_mode(fd,&cam_info.hdr_pra_mode);
            printf("mode=%d max_short_exp=%d,exp_ration=%f,ceva_k1 k2 k3 =(%f %f %f), isp k1 k2 k3 =(%f %f %f)\n",\
            cam_info.hdr_pra_mode.mode, cam_info.hdr_pra_mode.max_short_exp, cam_info.hdr_pra_mode.exp_ration, \
            cam_info.hdr_pra_mode.drc1_k[0], cam_info.hdr_pra_mode.drc1_k[1], cam_info.hdr_pra_mode.drc1_k[2], \
            cam_info.hdr_pra_mode.drc2_k[0], cam_info.hdr_pra_mode.drc2_k[1], cam_info.hdr_pra_mode.drc2_k[2]);
        }
        break;
	    case CAM_SET_ZOOM:
		{
			printf("stream index=%d zoom=%f man_zoom=%d (x,y w,h)=(%f,%f %f,%f)\n",\
				cam_info.zoom.stream_type,cam_info.zoom.digital_zoom,cam_info.zoom.manual,\
				cam_info.zoom.roi.x,cam_info.zoom.roi.y,cam_info.zoom.roi.width,cam_info.zoom.roi.height);
			ar_cam_set_zoom(fd, cam_info.zoom);
		}
		break;
	    case CAM_SET_CSC:
		{
            csc_pra_t csc;
            csc.sub_module = cam_info.csc.sub_module;
			ar_cam_get_csc(fd, &csc);
			printf("get csc stream type=%d full_range=%d sub_module = %d\n", \
			csc.type, csc.full_range, csc.sub_module);
			printf("set csc stream type=%d full_range=%d sub_module = %d\n", \
			cam_info.csc.type, cam_info.csc.full_range, cam_info.csc.sub_module);
			ar_cam_set_csc(fd, &cam_info.csc);
		}
		break;
		case CAM_GET_CSC:
		{
		    csc_pra_t csc;
		    csc.sub_module = cam_info.csc.sub_module;
		    ar_cam_get_csc(fd, &csc);
			printf("get csc stream type=%d full_range=%d sub_module = %d\n", \
			csc.type, csc.full_range, csc.sub_module);
		}
		break;
	    case CAM_GET_DE3D_PRA:
		{
            denoise_3d_pra_t de3d_pra;
			ar_cam_de3d_get_pra(fd, &de3d_pra);
			printf("ar_cam_de3d_get_pra enable=%d mode=%d strength=%d\n",de3d_pra.enable,de3d_pra.mode,de3d_pra.strength);
			printf("ar_cam_de3d_get_pra sigma_cur=%d sigma_pre=%d sigma_big_block=%d\n",de3d_pra.denoise_3d_expert_pra.sigma_cur,\
				de3d_pra.denoise_3d_expert_pra.sigma_pre,de3d_pra.denoise_3d_expert_pra.sigma_big_block);
		}
		break;
	    case CAM_SET_DE3D_PRA:
		{
            denoise_3d_pra_t de3d_pra=cam_info.de3d_pra;
			ar_cam_de3d_set_pra(fd, &de3d_pra);
			printf("ar_cam_de3d_get_pra enable=%d mode=%d strength=%d\n",de3d_pra.enable,de3d_pra.mode,de3d_pra.strength);
			printf("ar_cam_de3d_get_pra sigma_cur=%d sigma_pre=%d sigma_big_block=%d\n",de3d_pra.denoise_3d_expert_pra.sigma_cur,\
				de3d_pra.denoise_3d_expert_pra.sigma_pre,de3d_pra.denoise_3d_expert_pra.sigma_big_block);
		}
		break;
		case CAM_GET_DE2D_PRA:
		{
            denoise_2d_pra_t de2d_pra;
			ar_cam_de2d_get_pra(fd, &de2d_pra);
			printf("ar_cam_de2d_get_pra noise_type=%d enable=%d mode=%d strength=%d\n",de2d_pra.denoise_type,de2d_pra.enable,de2d_pra.mode,de2d_pra.strength);
			printf("ar_cam_de2d_get_pra dn_level=%d zoom_par=%d\n",de2d_pra.denoise_2d_expert_pra.denoise_2d_cnf_expert_pra.dn_level,\
				de2d_pra.denoise_2d_expert_pra.denoise_2d_cnf_expert_pra.zoom_par);
		}
		break;
	    case CAM_SET_DE2D_PRA:
		{
            denoise_2d_pra_t de2d_pra=cam_info.de2d_pra;
			ar_cam_de2d_set_pra(fd, &de2d_pra);
			printf("ar_cam_de2d_set_pra noise_type=%d enable=%d mode=%d strength=%d\n",de2d_pra.denoise_type,de2d_pra.enable,de2d_pra.mode,de2d_pra.strength);
			printf("ar_cam_de2d_set_pra dn_level=%d zoom_par=%d\n",de2d_pra.denoise_2d_expert_pra.denoise_2d_cnf_expert_pra.dn_level,\
				de2d_pra.denoise_2d_expert_pra.denoise_2d_cnf_expert_pra.zoom_par);
		}
		break;
		default:
		  printf("invalid cmd id %d\n", cmd_id);
		break;
	}
    if(fd>=0)
    {
	   ar_cam_src_close(fd);
    }
	return 0;
}

