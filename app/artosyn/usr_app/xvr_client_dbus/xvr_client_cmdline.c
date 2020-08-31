#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <pthread.h>
#include "xvr_gdbus_generated.h"
#include "xvr_client_dbus.h"
#include "xvr_client_cmdline.h"

cmdStruct_t cmd_lists[CMD_LIST_LEN]=
{
	{"cmd_ctrl_none",NULL},
	{"create_pipeline",ar_xvr_create_pipeline_func},
	{"start_pipeline",ar_xvr_start_pipeline_func},
	{"stop_pipeline",ar_xvr_stop_pipeline_func},
	{"play_video_record",ar_xvr_play_video_record_func},
	{"start_video_record",ar_xvr_start_video_record_func},
	{"stop_video_record",ar_xvr_stop_video_record_func},
	{"change_stream_param",ar_xvr_change_stream_param_func},
	{"change_encode_format",ar_xvr_change_encode_format_func},
	{"switch_channel_display",ar_xvr_switch_channel_display_func},
	{"switch_anyway_display",ar_xvr_switch_anyway_display_func},
	{"change_osd_mode",ar_xvr_change_osd_mode_func},
	{"change_audio_in_param",ar_xvr_change_audio_in_param_func},
	{"start_audio_record",ar_xvr_start_audio_record_func},
	{"stop_audio_record",ar_xvr_stop_audio_record_func},
	{"play_local_audio",ar_xvr_play_local_audio_func},
	{"save_yuv",ar_xvr_save_yuv_func_sync},
	{"help",NULL},
};


void debug_cmd_usage(void)
{
	fprintf(stderr, " use CTRL+C to quit debug mode:\n");
	fprintf(stderr, " debug cmd lists:\n");
	fprintf(stderr, " create_pipeline          - create pipeline;\n");
	fprintf(stderr, " start_pipeline           - start[pipeline-name] pipeline name;\n");
	fprintf(stderr, " stop_pipeline            - stop [pipeline-name] pipeline name;\n");
	fprintf(stderr, " play_video_record        - play video record files from USB stick;\n");
	fprintf(stderr, " start_video_record       - start record Main/sub video stream to USB stick;\n");
	fprintf(stderr, " stop_video_record        - stop record Main/sub video stream  to USB stick;\n");
	fprintf(stderr, " change_stream_param      - change Main/sub video stream param,such as frame rate/resolution/bit rate;\n");
	fprintf(stderr, " change_encode_format     - change Main/sub video stream  to encode format(H264/Hevc);\n");
	fprintf(stderr, " switch_channel_display   - switch video channel to display;\n");
	fprintf(stderr, " switch_anyway_display    - switch video anyway to display;\n");
	fprintf(stderr, " change_osd_mode          - change osd on 1-9 cameras(channel name,state);\n");
	fprintf(stderr, " change_audio_in_param    - change audio in channel;\n");
	fprintf(stderr, " start_audio_record       - start record audio input;\n");
	fprintf(stderr, " stop_audio_record        - stop record audio input;\n");
	fprintf(stderr, " play_local_audio         - play local audio files(audio output);\n");
	fprintf(stderr, " save_yuv                 - get a yuv and save to file;\n");
	fprintf(stderr, " help                     - show debug cmd usage;\n");
	//print_subcmd_usage();
	fprintf(stderr, " see subcmd usage:         cmdname -h\n \t\t\t  ex: create_pipeline -h\n");
    return;
}


int find_cmd_list_index_by_name(char* arg)
{
	int index = MAX_INIT_VAL;
	int tmp = NULL;
	for(int i=0; i<CMD_LIST_LEN; i++)
	{
		tmp = NULL;
		tmp = strstr(arg,cmd_lists[i].name);
		if(tmp!=NULL)
		{
			return i;
		}
	}
	return index;

}



void debug_sub_cmd_usage(char *arg)
{

	char *tmp;
	int cnt = 0;
	for(int i=0;i<CMD_LIST_LEN;i++)
	{
	    tmp = NULL;
		tmp = strstr(arg,cmd_lists[i].name);

		if(tmp!=NULL)
		{
			switch(i)
			{
				case CMD_CTL_CREATE_PIPELINE:
					printf("create_pipeline usage:\n");
					printf("\tcreate_pipeline  [pipeline_idx]\n");
					printf("\tcreate_pipeline  [pipeline_idx] -cam [cam_type] -t [codec_type] -n [cam_num] -res [1080p/720p] -fps [frame_rate] -br [bitrate] -ao -ai -disp [width height fps]\n");
					printf("\t              1  create_xvr_pipeline\n");
					printf("\t              2  create_video_playback_pipeline\n");
					printf("\t              3  create_audio_playback_pipeline\n");
					printf("\t              4  create_audio_record_pipeline\n");
					printf("\tcam_type      0   MIPI\n");
					printf("\t              1   AHD\n");
					printf("\t              2   MIPI_PSEUDO8\n");
					printf("\tcodec_type:   0   H265\n");
					printf("\t              1   H264\n");
					printf("\tai            enable audio input\n");
					printf("\tao            enable audio output\n");
					printf("\tdisp          disp_width disp_height fix_fps \n");
					printf("\t\n");
					break;
				case CMD_CTL_START_PIPELINE:
					printf("start_pipeline usage:\n");
					printf("\tstart_pipeline [/dev/pipeline_name]\n");
					break;
				case CMD_CTL_STOP_PIPELINE:
					printf("stop_pipeline usage:\n");
					printf("\tstop_pipeline [/dev/pipeline_name]\n");
					break;
				case CMD_CTL_PLAY_VIDEO_RECORD:
					printf("play_video_record usage:\n");
					printf("\tplay_video_record -n [playback_sum_ch] [display_ch1] [video_file_path1]...[display_chn] [video_file_pathn]\n");
					printf("\tdisplay_ch1~n		0-7\n");
					break;
				case CMD_CTL_START_VIDEO_RECORD:
					printf("start_video_record usage:\n");
					printf("\tstart_video_record [/dev/dev_name] [file_path] [specified_size(MB)]\n");
					break;
				case CMD_CTL_STOP_VIDEO_RECORD:
					printf("stop_video_record usage:\n");
					printf("\tstop_video_record [/dev/dev_name] [file_path]\n");
					printf("\t0 :Main video stream\n");
					printf("\t1 :Sub video stream\n");
					break;
				case CMD_CTL_CHANGE_STREAM_PARAM:
					printf("change_stream_param usage(optinal):\n");
					printf("\tchange_stream_param [/dev/pipeline_name] -cam [cam_type] -cam_ch [cam_ch] -ch [video_stream_channel]-fps [frame_rate] -opfps [frame_rate] -res [width heiht] -br [bitrate] \n");
					printf("\tcam_type		0	MIPI\n");
					printf("\ 				1	AHD\n");
					printf("\tcam_ch        pipeline_idx:0..7\n");
					printf("\tcodec_type    0   H265\n");
					printf("\t              1   H264\n");
					printf("\t-ch           0   Main video stream\n");
					printf("\t              1   Sub video stream\n");
					printf("\t-fps          25bps,30bps...cam_src fps\n");
					printf("\t-opfps        25bps,30bps...main/sub stream encoder fps\n");
					printf("\t-res          [1920 1080],[1280 720],[640 480]...\n");
					printf("\t-br           bitrate...\n");
					break;
				case CMD_CTL_CHANGE_ENCODE_FORMAT:
					printf("change_encode_format usage:\n");
					printf("\tchange_encode_format  [/dev/pipeline_name] -cam_ch [cam_ch] -cam [cam_type] -t [video_format]\n");
					printf("\tcam_ch		0-7\n");
					printf("\tcam_type		0	MIPI\n");
					printf("\ 				1	AHD\n");
					printf("\tcodec_type\n");
					printf("\t0   			H265\n");
					printf("\t1   			H264\n");
					break;
				case CMD_CTL_SWITCH_CHANNEL_DISPLAY:
					printf("switch_channel_display usage:\n");
					printf("\tswitch_channel_display -cam [cam_type] -ch [video_stream_channel] [0/1]\n");
					printf("\tcam_type		 0	MIPI\n");
					printf("\ 				 1	AHD\n");
					printf("\tvideo_stream_channel [0-7]\n");
					printf("\t[0/1] 		 0: disable full screen 1:enable full screen\n");
					break;
				case CMD_CTL_SWITCH_ANYWAY_DISPLAY:
					printf("switch_anyway_display usage:\n");
					printf("\tswitch_channel_display -cam [0/1] -num [0-8] -des [ch0 p0x p0y s0x s0y,,ch7 p7x p7y s7x s7y]\n");
					printf("\t-cam [0/1] \n");
					printf("\t [0/1]				0:MIPI	1:AHD\n");
					printf("\t-num [0-8] \n");
					printf("\t [0-8] 				sum of channel num for display\n");
					printf("\t-des [ch0 p0x p0y s0x s0y,,ch7 p7x p7y s7x s7y] \n");
					printf("\t [ch0,,ch7]	chi:    ith channel num for display\n");
					printf("\t [p0x p0y,,p7x p7y]	pix piy: coordinate of ith channel for display\n");
					printf("\t [s0x s0y,,s7x s7y]	six siy: width & height of ith channel for display\n");
					break;
				case CMD_CTL_CHANGE_OSD_MODE:
					printf("change_osd_mode usage:(-bmp is optional)\n");
					printf("\tchange_osd_mode [pipeline_id] [specifiy_channel_name] -bmp [state_bmp_file_path]\n");
					printf("\tpipeline_id [0-8]\n");
					break;
				case CMD_CTL_CHANGE_AUDIO_IN_PARAM:
					printf("change_audio_in_param usage:\n");
					printf("\tchange_audio_in_param [channel_id] \n");
					printf("\tchannel_id [0-7]\n");
					break;
				case CMD_CTL_START_AUDIO_RECORD:
					printf("start_audio_record usage:\n");
					printf("\tstart_audio_record [/dev/device_name] [audio_file_path]\n");
					break;
				case CMD_CTL_STOP_AUDIO_RECORD:
					printf("stop_audio_record usage:\n");
					printf("stop_audio_record\n");
					break;
				case CMD_CTL_PLAY_LOCAL_AUDIO:
					printf("play_local_audio usage:\n");
					printf("\tplay_local_audio [/dev/device_name] [local_audio_file_path]\n");
					break;
				case CMD_CTL_SAVE_YUV:
					printf("save_yuv usage:\n");
					printf("\tsave_yuv [/dev/yuv_name] [yuv_file_path]\n");
					break;
				case CMD_CTL_HELP:
					//debug_cmd_usage();
					break;
				default:
					printf("Do nothing,please check your command.\n");
					break;

			}

			//break;
		}
		else
		{
			cnt ++;
		}
	}
	if(cnt>=CMD_LIST_LEN)
	{
		printf("Invlaid command...\n");
	}

    //return;
}


void func_cmdline_ctrl()
{
	size_t size =0;
	ssize_t read;
	char *tmp;
	char *buffer = NULL;
	debug_cmd_usage();
	printf(CONFIG_SYS_PROMPT);
	int cmd_idx = MAX_INIT_VAL;
	while((read = getline(&buffer,&size,stdin))!=-1)
	{
		buffer[read-1] = '\0';
		printf("\r\n=>");
		if(strstr(buffer,"help")!=NULL)
		{
			debug_cmd_usage();
			printf("\r\n=>");
			continue ;
		}

		cmd_idx = find_cmd_list_index_by_name(buffer);
		if(cmd_idx<MAX_INIT_VAL)
		{
			if(strstr(buffer,"-h")!=NULL)
			{
				debug_sub_cmd_usage(buffer);
				printf("\r\n=>");
				continue ;
			}

			cmd_lists[cmd_idx].function(buffer);

		}


	}

	if(buffer)
	{
		free(buffer);
	}
}















