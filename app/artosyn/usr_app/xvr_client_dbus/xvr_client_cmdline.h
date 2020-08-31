#ifndef _XVR_CLIENT_CMDLINE_H_
#define _XVR_CLIENT_CMDLINE_H_


#define CONFIG_SYS_PROMPT          "=>"
#define CONFIG_SYS_PROMPT_HUSH_PS2 "=>>"

#define CMD_LIST_LEN 18
#define MAX_INIT_VAL 100


typedef struct
{
	const char* name;
	void(*function)();

}cmdStruct_t;


enum 
{
	CMD_CTL_NONE = 0,
	CMD_CTL_CREATE_PIPELINE,
	CMD_CTL_START_PIPELINE,
	CMD_CTL_STOP_PIPELINE,
	CMD_CTL_PLAY_VIDEO_RECORD,
	CMD_CTL_START_VIDEO_RECORD,
	CMD_CTL_STOP_VIDEO_RECORD,
	CMD_CTL_CHANGE_STREAM_PARAM,
	CMD_CTL_CHANGE_ENCODE_FORMAT,
	CMD_CTL_SWITCH_CHANNEL_DISPLAY,
	CMD_CTL_SWITCH_ANYWAY_DISPLAY,
	CMD_CTL_CHANGE_OSD_MODE,
	CMD_CTL_CHANGE_AUDIO_IN_PARAM,
	CMD_CTL_START_AUDIO_RECORD,
	CMD_CTL_STOP_AUDIO_RECORD,
	CMD_CTL_PLAY_LOCAL_AUDIO,
	CMD_CTL_SAVE_YUV,
	//CMD_CTL_DRAW_COMP_LINE,
	CMD_CTL_HELP,
	CMD_CTL_MAX
};

enum
{
	CREATE_PIPELINE_NONE = 0,
	CREATE_XVR_PIPELINE,
	CREATE_VIDEO_PLAYBACK_PIPELINE,
	CREATE_AUDIO_PLAYBACK_PIPELINE,
	CREATE_PIPELINE_MAX
};

extern cmdStruct_t cmd_lists[CMD_LIST_LEN];
void debug_cmd_usage(void);
int find_cmd_list_index_by_name(char* arg);
void debug_sub_cmd_usage(char *arg);
void func_cmdline_ctrl();


#endif