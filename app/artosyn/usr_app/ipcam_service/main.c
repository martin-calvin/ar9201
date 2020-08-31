#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "ipcam.h"
// media process server
static int find_pra_index_by_name(char *name,int argc, char *argv[])
{
    int i=0;
    for(i=0;i<argc;i++)
    {
         if(!strcmp(name,argv[i]))
         {
             return i;
         }
    }
    return 0;
}
typedef struct
{
 int args_num;
 char args[16][128];
}cmd_args_t;
static int find_cmd_pra_index_by_name(char *name,cmd_args_t *argv)
{
    int i=0;
    for(i=0;i<argv->args_num;i++)
    {
         if(!strcmp(name,argv->args[i]))
         {
             return i;
         }
    }
    return -1;
}
cmd_args_t *get_args(const char *cmd)
{
  cmd_args_t * args=(cmd_args_t *)malloc(sizeof(cmd_args_t));
  char *p_cmd=(char *)malloc(1024);
  char *p_str=NULL;
  char  *split_char=" ";
  char *p_free_p_cmd=p_cmd;
  memset(args,0,sizeof(cmd_args_t));
  strcpy(p_cmd,cmd);
  p_str=strtok(p_cmd,split_char);
  if(p_str)
  {
    strcpy(&args->args[args->args_num][0],p_str);
    args->args_num++;
  }
  while(p_str)
  {
    p_str=strtok(NULL,split_char);
    if(p_str)
    {
      strcpy(&args->args[args->args_num][0],p_str);
      args->args_num++;
    }
  }
  free(p_free_p_cmd);
  return args;
}

static void usage(const char *argv0)
{
    fprintf(stderr, "Usage: %s [options]\n", argv0);
    fprintf(stderr, "Available options are\n");
    fprintf(stderr, " -t codec_type. 0: hevc; 1: avc \n");
    fprintf(stderr, " -n sensor num. 1, 2...;\n");
    fprintf(stderr, " --hdr start as hdr mode;\n");
    fprintf(stderr, " --fps [fps] start as fps;\n");
    fprintf(stderr, " -w1 [width] main stream's width;\n");
    fprintf(stderr, " -h1 [height] main stream's height;\n");
    fprintf(stderr, " -w2 [width] subordinate stream's width;\n");
    fprintf(stderr, " -h2 [height] subordinate stream's height;\n");
    fprintf(stderr, " -angle bitstream's rotation angle;\n");
    fprintf(stderr, " -index camera's index, such as 0,1;\n");
    fprintf(stderr, " --multi vif support multi cameras;\n");
    fprintf(stderr, " --display : sart with display\n");
    fprintf(stderr, " --face_stats : sart with face software stats\n");
    fprintf(stderr, " --tee_copy [src_pad_index] [buffer_count]: enable tee copy with buffer count\n");
    fprintf(stderr, " --bitrate : main stream's bitrate(k)\n");
    fprintf(stderr, " --hw_eis_ldc : use the hw eis ldc modle \n");
    fprintf(stderr, " --raw_debug : set the app can to dump raw img use cmd line \n");
    fprintf(stderr, " --err_proc : restart the pipeline when sensor not out \n");
    fprintf(stderr, " --transcode : decode the bitstream encoded by encoder, enable with display \n");

    return;
}

ipcam_server_t *get_ipcam_server(void)
{
   static ipcam_server_t *server_handle = NULL;

   if(NULL==server_handle)
   {
      server_handle=(ipcam_server_t *)malloc(sizeof(ipcam_server_t));
      if(server_handle){
         memset(server_handle,0,sizeof(ipcam_server_t));
         server_handle->fps=30;
         server_handle->hdr_mode=0;
         server_handle->cam_num=1;
      }else
      {
        log_err("err malloc ipcamera server");
      }
   }
   return server_handle;
}

static int pipeline_clt_stop(pipeline_ctl_server_t *server_l)
{
    ipcam_server_t *server_ipcam=get_ipcam_server();
    int ret=-1;
    ret = ar_pipeline_ctrl_pause_stream(server_ipcam->pipe_fd);
    ret = ar_pipeline_ctrl_stop_stream(server_ipcam->pipe_fd);
    return 0;
}
static int pipeline_clt_start(pipeline_ctl_server_t *server_l)
{
    ipcam_server_t *server_ipcam=get_ipcam_server();
    int ret=-1;
    ret = ar_pipeline_ctrl_start_stream(server_ipcam->pipe_fd);
    return 0;

}
static int pipeline_clt_set_prop(pipeline_ctl_server_t *server_l,char *arg,int len)
{
     ipcam_server_t *server_ipcam=get_ipcam_server();
     cmd_args_t *args=get_args(arg);
     int index=find_cmd_pra_index_by_name("--hdr",args);
     if(index>=0)
     {
            int vfe_en=atoi(args->args[index+1]);
            log_always("vfe_en=%d",vfe_en);
            if(vfe_en)
            {
                ar_element_modify_property_value(server_ipcam->handle,server_ipcam->ipcam_context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
                ar_element_modify_property_value(server_ipcam->handle,server_ipcam->ipcam_context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DDR,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_OFFLINE)+1);
                ar_element_modify_property_value(server_ipcam->handle,server_ipcam->ipcam_context->cam_src.element,AR_VIDEO_CAM_SET_VFE_EN,&vfe_en,sizeof(int));
            }else
            {
                ar_element_modify_property_value(server_ipcam->handle,server_ipcam->ipcam_context->cam_src.element,AR_VIDEO_CAM_MODE,AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL,strlen(AR_VIDEO_CAM_MODE_SING_CAMERA_NORMAL)+1);
                ar_element_modify_property_value(server_ipcam->handle,server_ipcam->ipcam_context->cam_src.element,AR_VIDEO_CAM_VIF_ISP_MOD,AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT,strlen(AR_VIDEO_CAM_VIF_ISP_MOD_DIRECT)+1);
                ar_element_modify_property_value(server_ipcam->handle,server_ipcam->ipcam_context->cam_src.element,AR_VIDEO_CAM_SET_VFE_EN,&vfe_en,sizeof(int));
            }
    }
    index = find_cmd_pra_index_by_name("--csc", args);
    if(index > 0)
    {
        int csc = atoi(args->args[index + 1]);
        log_always("set csc %d\n", csc);
        ar_element_modify_property_value(server_ipcam->handle, server_ipcam->ipcam_context->display.element,
        AR_DISPLAY_META_DVP_OUT_CSC, &csc, sizeof(int));

    }
    index=find_cmd_pra_index_by_name("--fps",args);
    if(index>=0)
    {
        int num=atoi(args->args[index+1]);
        int den=1;
        log_always("set fps =%d",num);
        ar_pad_modify_meta_value(server_ipcam->handle,ar_element_get_src_pad_by_idx(server_ipcam->handle,server_ipcam->ipcam_context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&num,sizeof(int));
        ar_pad_modify_meta_value(server_ipcam->handle,ar_element_get_src_pad_by_idx(server_ipcam->handle,server_ipcam->ipcam_context->cam_src.element, 0),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));
        ar_pad_modify_meta_value(server_ipcam->handle,ar_element_get_src_pad_by_idx(server_ipcam->handle,server_ipcam->ipcam_context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_NUM_NAME,&num,sizeof(int));
        ar_pad_modify_meta_value(server_ipcam->handle,ar_element_get_src_pad_by_idx(server_ipcam->handle,server_ipcam->ipcam_context->cam_src.element, 1),AR_COMMON_META_VIDEO_FPS_DEN_NAME,&den,sizeof(int));
    }
    index=find_cmd_pra_index_by_name("--zoom",args);
    if(index>=0)
    {
      int input_zoom = atoi(args->args[index+1]);
      double zoom = ((double)input_zoom)/1000;
      log_always("set zoom =%f", zoom );
      ar_pad_modify_meta_value(server_ipcam->handle\
        ,ar_element_get_src_pad_by_idx(server_ipcam->handle,server_ipcam->ipcam_context->cam_src.element, 0)\
        ,AR_COMMON_META_VIDEO_DIGITAL_ZOOM_NAME\
        ,&zoom,sizeof(double));

    }
    index = find_cmd_pra_index_by_name("--set_vcodec", args);
    if (index >= 0) {
        unsigned int codec_type = atoi(args->args[index+1]) + 1;
        ar_element_modify_property_value(server_ipcam->handle,server_ipcam->ipcam_context->video_enc.element,AR_VIDEO_CODEC_META_TYPE, &codec_type, sizeof(uint32_t));
    }
    free(args);
    return 0;
}

server_api_ops_t api_ops_ipcam={
      .ar_pipeline_clt_stop=pipeline_clt_stop,
      .ar_pipeline_clt_start=pipeline_clt_start,
      .ar_pipeline_clt_set_prop=pipeline_clt_set_prop,
};

int main (int argc, char *argv[])
{
    int opt = 0, camera_num = 1, camera_idx = 0, angle = 0;
    int width1 = 0, height1 = 0, width2 = 0, height2 = 0;
    ipcam_codec_type_t codec_type = 0;
    void *context = NULL;
    ipcam_server_t *ipcam_server = NULL;
    #if 0
    fprintf(stderr, " -w1 [width] main stream's width;\n");
    fprintf(stderr, " -h1 [height] main stream's height;\n");
    fprintf(stderr, " -w2 [width] subordinate stream's width;\n");
    fprintf(stderr, " -h2 [height] subordinate stream's height;\n");
    fprintf(stderr, " -angle bitstream's rotation angle,such as 0, 90, 270;\n");
    fprintf(stderr, " -index camera's index, such as 0,1;\n");
    #endif
    char *optString = "t:n:w1:h1:w2:h2:angle:index";
    char server_name[20] = { 0 }, dev_name[20] = { 0 };
    int index=0;
    int wait_delay=10 * 1000;
    int count=5000000/wait_delay;
    index=find_pra_index_by_name("--help",argc,argv);
    if(index>0)
    {
        usage(argv[0]);
        return 0;
    }
    ipcam_server=get_ipcam_server();
    index=find_pra_index_by_name("-index",argc,argv);
    if(index>0)
    {
        camera_idx = atoi(argv[index+1]);
    }
    index=find_pra_index_by_name("-t",argc,argv);
    if(index>0)
    {
        codec_type = atoi(argv[index+1]);
    }
    index=find_pra_index_by_name("--multi",argc,argv);
    if(index>0)
    {
        ipcam_server->cam_num = 2;
    }
    index=find_pra_index_by_name("--hdr",argc,argv);
    if(index>0)
    {
        ipcam_server->hdr_mode=1;
    }
    index=find_pra_index_by_name("--fps",argc,argv);
    if(index>0)
    {
        ipcam_server->fps=atoi(argv[index+1]);
    }
    index=find_pra_index_by_name("-w1",argc,argv);
    if(index>0)
    {
        width1 = atoi(argv[index+1]);
    }
    index=find_pra_index_by_name("-h1",argc,argv);
    if(index>0)
    {
        height1 = atoi(argv[index+1]);
    }
    index=find_pra_index_by_name("-w2",argc,argv);
    if(index>0)
    {
        width2 = atoi(argv[index+1]);
    }
    index=find_pra_index_by_name("-h2",argc,argv);
    if(index>0)
    {
        height2 = atoi(argv[index+1]);
    }
    index=find_pra_index_by_name("-angle",argc,argv);
    if(index>0)
    {
        angle = atoi(argv[index+1]);
    }
    ipcam_server->need_display=0;
    ipcam_server->w=1920;
    ipcam_server->h=1080;
    ipcam_server->dis_fps=60;
  ipcam_server->bitrate=3*1024;
    index=find_pra_index_by_name("--display",argc,argv);
    if(index>0)
    {
         ipcam_server->need_display=1;
         index=find_pra_index_by_name("-w",argc,argv);
         if(index>0)
         {
            ipcam_server->w=atoi(argv[index+1]);
         }
         index=find_pra_index_by_name("-h",argc,argv);
         if(index>0)
         {
            ipcam_server->h=atoi(argv[index+1]);
         }
         index=find_pra_index_by_name("-fps",argc,argv);
         if(index>0)
         {
            ipcam_server->dis_fps=atoi(argv[index+1]);
         }
    }
    index=find_pra_index_by_name("--face_stats",argc,argv);
    if(index>0)
    {
        ipcam_server->face_stats=1;
    }
    ipcam_server->tee_copy=0;
    index=find_pra_index_by_name("--tee_copy",argc,argv);
    if(index>0)
    {
        ipcam_server->tee_copy=1;
        ipcam_server->tee_src_pad_index=atoi(argv[index+1]);
        ipcam_server->tee_copy_buffer_count=atoi(argv[index+2]);
    }
    index=find_pra_index_by_name("--bitrate",argc,argv);
    if(index>0)
    {
        ipcam_server->bitrate = atoi(argv[index+1]);
    }

    ipcam_server->use_hw_eis_ldc = 0;
    index=find_pra_index_by_name("--hw_eis_ldc",argc,argv);
    if(index>0)
    {
        ipcam_server->use_hw_eis_ldc = 1;
    }

    ipcam_server->force_isp_ddr_mode = 0;
    index=find_pra_index_by_name("--raw_debug",argc,argv);
    if(index>0)
    {
        ipcam_server->force_isp_ddr_mode = 1;
    }

    ipcam_server->err_proc = 0;
    index=find_pra_index_by_name("--err_proc",argc,argv);
    if(index>0)
    {
        ipcam_server->err_proc = 1;
    }
    ipcam_server->transcode = 0;
    index=find_pra_index_by_name("--transcode",argc,argv);
    if(index>0)
    {
        ipcam_server->transcode = 1;
    }

    do{
       usleep(wait_delay);
       ipcam_server->handle = ar_multimedia_core_device_open();
       count--;
    }while(!ipcam_server->handle && count>0);

    if(!ipcam_server->handle)
    {
         log_err("can not open multicore 5s,exit the app, please checkout your frame work !!!!");
         return -1;
    }

    printf("camera num %d codec_type %u camera_idx %d\n", camera_num, codec_type, camera_idx);
    printf("resolution %dx%d %dx%d fps=%d angle=%d hdr=%d\n", width1, height1, width2, height2,
            ipcam_server->fps, angle, ipcam_server->hdr_mode);
    context = ipcam_init(codec_type, width1, height1, width2, height2, angle, camera_idx);
    ipcam_server->ipcam_context=(ipcam_context_t *)context;
    sprintf(server_name, "ipcamserver_%d", camera_idx);
    ipcam_server->server_l=creat_pipeline_clt_server(server_name,&api_ops_ipcam,ipcam_server);
    sprintf(dev_name, "/dev/ipcam_server-%d", camera_idx);
    ipcam_server->pipe_fd=ar_pipeline_ctrl_open(dev_name);
    if (ipcam_server->pipe_fd < 0) {
       printf("open pipeline error\n");
    }
    wait_pipeline_ctl_main_loop_end(ipcam_server->server_l);
    ar_pipeline_ctrl_close(ipcam_server->pipe_fd);
    /* never get here */
    /* TODO: move final to thread signal process */
    ipcam_final();

    return 0;
}
