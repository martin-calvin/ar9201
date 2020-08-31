#include <stdio.h>
#include <stdint.h>
#include "tuning_def.h"
#include <sys/stat.h>
#include <fcntl.h>
//gc2385_0_tuning_preview.h  1
static algo_isp_tuning_t gc2385_0_tuning_preview={
   #include "./inc/gc2385_0_tuning_preview.h"
};
//gc2385_tuning_preview.h  2
static algo_isp_tuning_t gc2385_tuning_preview={
   #include "./inc/gc2385_tuning_preview.h"
};
//imx290_hdr_tuning_preview.h 3
static algo_isp_tuning_t imx290_hdr_tuning_preview={
   #include "./inc/imx290_hdr_tuning_preview.h"
};
//imx291_0_tuning_preview.h  4
static algo_isp_tuning_t imx291_0_tuning_preview={
   #include "./inc/imx291_0_tuning_preview.h"
};
//imx290_tuning_preview.h 5
static algo_isp_tuning_t imx290_tuning_preview={
   #include "./inc/imx290_tuning_preview.h"
};
//imx377_tuning_preview.h 6
static algo_isp_tuning_t imx377_tuning_preview={
   #include "./inc/imx377_tuning_preview.h"
};
static algo_isp_tuning_t imx378_tuning_preview={
   #include "./inc/imx378_tuning_preview.h"
};
static algo_isp_tuning_t imx415_tuning_preview_aobi1080binning={
   #include "./inc/imx415_tuning_preview_aobi1080binning.h"
};
static algo_isp_tuning_t imx415_tuning_preview_aobi4k={
   #include "./inc/imx415_tuning_preview_aobi4k.h"
};
static algo_isp_tuning_t imx415_tuning_preview={
   #include "./inc/imx415_tuning_preview.h"
};
static algo_isp_tuning_t imx415_tuning_preview_dwt120={
   #include "./inc/imx415_tuning_preview_dwt120.h"
};
static algo_isp_tuning_t imx415_tuning_preview_hj5136={
   #include "./inc/imx415_tuning_preview_hj5136.h"
};
static algo_isp_tuning_t imx307_tuning_preview_dwt_80={
   #include "./inc/imx307_tuning_preview_dwt_80.h"
};
//sc2310_tuning_preview.h 7
static algo_isp_tuning_t sc2310_tuning_preview={
   #include "./inc/sc2310_tuning_preview.h"
};

static algo_isp_tuning_t sc2210_tuning_preview={
   #include "./inc/sc2210_tuning_preview.h"
};


//imx291_tuning_preview.h 8
static algo_isp_tuning_t imx291_tuning_preview={
   #include "./inc/imx291_tuning_preview.h"
};
//sensor_sim_tuning_preview.h 9
static algo_isp_tuning_t sensor_sim_tuning_preview={
   #include "./inc/sensor_sim_tuning_preview.h"
};
//imx307_tuning_preview.h 10
static algo_isp_tuning_t imx307_tuning_preview={
   #include "./inc/imx307_tuning_preview.h"
};
///ov13850_tuning_preview.h 11
static algo_isp_tuning_t ov13850_tuning_preview={
   #include "./inc/ov13850_tuning_preview.h"
};
//sc2310_hdr_tuning_preview.h 12
static algo_isp_tuning_t sc2310_hdr_tuning_preview={
   #include "./inc/sc2310_hdr_tuning_preview.h"
};

static algo_isp_tuning_t sc2210_hdr_tuning_preview={
   #include "./inc/sc2210_hdr_tuning_preview.h"
};

//imx291_tuning_night.h 13
static algo_isp_tuning_t imx291_tuning_night={
   #include "./inc/imx291_tuning_night.h"
};
static algo_isp_tuning_t imx307_tuning_preview_133={
  #include "./inc/imx307_tuning_preview_133.h"
};
static algo_isp_tuning_t imx307_tuning_preview_80={
  #include "./inc/imx307_tuning_preview_80.h"
};

static algo_isp_tuning_t imx307_hdr_tuning_preview={
  #include "./inc/imx307_hdr_tuning_preview.h"
};
static algo_isp_tuning_t imx307_hdr_off_tuning_preview={
  #include "./inc/imx307_hdr_off_tuning_preview.h"
};

static algo_isp_tuning_t imx290_hdr_off_tuning_preview={
   #include "./inc/imx290_hdr_off_tuning_preview.h"
};

static algo_isp_tuning_t imx307_tuning_preview_133_100ms={
  #include "./inc/imx307_tuning_preview_133_100ms.h"
};

static algo_isp_tuning_t imx307_tuning_preview_133_10ms={
  #include "./inc/imx307_tuning_preview_133_10ms.h"
};

static algo_isp_tuning_t imx307_tuning_preview_6mm_fov60={
  #include "./inc/imx307_tuning_preview_6mm_fov60.h"
};


static algo_isp_tuning_t imx307_tuning_preview_80_100ms={
  #include "./inc/imx307_tuning_preview_80_100ms.h"
};


static algo_isp_tuning_t imx307_tuning_preview_80_10ms={
  #include "./inc/imx307_tuning_preview_80_10ms.h"
};

static algo_isp_tuning_t imx307_tuning_preview_f1_0_drc_off={
  #include "./inc/imx307_tuning_preview_f1_0_drc_off.h"
};

static algo_isp_tuning_t imx307_tuning_preview_f1_0_drc_on={
  #include "./inc/imx307_tuning_preview_f1_0_drc_on.h"
};

static algo_isp_tuning_t ov9712_tuning_preview={
  #include "./inc/ov9712_tuning_preview.h"
};


static algo_isp_tuning_t imx307_ir_tuning_preview={
   #include "./inc/imx307_ir_tuning_preview.h"
};


static algo_isp_tuning_t imx307_tuning_preview_f1_0_drc_off_10ms={
  #include "./inc/imx307_tuning_preview_f1_0_drc_off_10ms.h"
};

static algo_isp_tuning_t imx307_tuning_preview_f1_0_drc_on_10ms={
  #include "./inc/imx307_tuning_preview_f1_0_drc_on_10ms.h"
};
static algo_isp_tuning_t imx307_tuning_preview_f1_0_drc_on_100ms={
  #include "./inc/imx307_tuning_preview_f1_0_drc_on_100ms.h"
};

static algo_isp_tuning_t imx307_tuning_preview_150_10ms_tsl={
  #include "./inc/imx307_tuning_preview_150_10ms_tsl.h"
};
static algo_isp_tuning_t imx307_hdr_tuning_preview_f1_0={
  #include "./inc/imx307_hdr_tuning_preview_f1_0.h"
};
static algo_isp_tuning_t imx307_hdr_off_tuning_preview_f1_0={
  #include "./inc/imx307_hdr_off_tuning_preview_f1_0.h"
};

///////////////////////
static algo_isp_tuning_t imx307_tuning_preview_12mm_f1_6_10ms={
  #include "./inc/imx307_tuning_preview_12mm_f1_6_10ms.h"
};
static algo_isp_tuning_t imx307_tuning_preview_yt_f1_0_10ms={
  #include "./inc/imx307_tuning_preview_yt_f1_0_10ms.h"
};
////////////////////////////////
static algo_isp_tuning_t imx307_hdr_tuning_preview_80_30ms={
  #include "./inc/imx307_hdr_tuning_preview_80_30ms.h"
};
static algo_isp_tuning_t imx307_tuning_preview_133_100ms_infra_red_mode={
  #include "./inc/imx307_tuning_preview_133_100ms_infra-red-mode.h"
};

static algo_isp_tuning_t imx307_tuning_preview_ir_80={
  #include "./inc/imx307_tuning_preview_ir_80.h"
};

static algo_isp_tuning_t imx307_hdr_tuning_preview_80={
  #include "./inc/imx307_hdr_tuning_preview_80.h"
};

static algo_isp_tuning_t imx307_hdr_tuning_preview_8mm={
#include "./inc/imx307_hdr_tuning_preview_8mm.h"
};

static algo_isp_tuning_t imx307_tuning_preview_8mm_10ms={
#include "./inc/imx307_tuning_preview_8mm_10ms.h"
};

static algo_isp_tuning_t ov02k10_tuning_preview={
#include "./inc/ov02k10_tuning_preview.h"
};

static algo_isp_tuning_t imx307_tuning_preview_linux_face_machine={
#include "./inc/imx307_tuning_preview_linux_face_machine.h"
};

static algo_isp_tuning_t imx307_tuning_preview_ir_linux_face_machine={
#include "./inc/imx307_tuning_preview_ir_linux_face_machine.h"
};





struct dump_tuning_file
{
   char *name;
   algo_isp_tuning_t *p_tuning;
};

struct dump_tuning_file dump[]=
{
//1
    {
       "gc2385_0_tuning_preview.bin",
        &gc2385_0_tuning_preview,
    },
//2
    {
       "gc2385_tuning_preview.bin",
        &gc2385_tuning_preview,
    },
//3
    {
       "imx290_hdr_tuning_preview.bin",
        &imx290_hdr_tuning_preview,
    },
//4
    {
       "imx290_tuning_preview.bin",
        &imx290_tuning_preview,
    },
//5
    {
       "imx291_0_tuning_preview.bin",
        &imx291_0_tuning_preview,
    },
//6
    {
       "imx377_tuning_preview.bin",
        &imx377_tuning_preview,
    },
//7
    {
       "sc2310_tuning_preview.bin",
        &sc2310_tuning_preview,
    },

    {
       "sc2210_tuning_preview.bin",
        &sc2210_tuning_preview,
    },

//8
    {
       "imx291_tuning_preview.bin",
        &imx291_tuning_preview,
    },
//9
    {
       "sensor_sim_tuning_preview.bin",
        &sensor_sim_tuning_preview,
    },
//10
    {
       "imx307_tuning_preview.bin",
        &imx307_tuning_preview,
    },
//11
    {
       "ov13850_tuning_preview.bin",
        &ov13850_tuning_preview,
    },
//12
    {
       "sc2310_hdr_tuning_preview.bin",
        &sc2310_hdr_tuning_preview,
    },

    {
       "sc2210_hdr_tuning_preview.bin",
        &sc2210_hdr_tuning_preview,
    },

//13
    {
       "imx291_tuning_night.bin",
        &imx291_tuning_night,
    },
    {
        "imx307_tuning_preview_133.bin",
        &imx307_tuning_preview_133,
    },
    {
        "imx307_tuning_preview_80.bin",
        &imx307_tuning_preview_80,
    },
    {
        "imx307_hdr_tuning_preview.bin",
        &imx307_hdr_tuning_preview,
    },
    {
        "imx307_hdr_off_tuning_preview.bin",
        &imx307_hdr_off_tuning_preview,
    },
    {
      "imx290_hdr_off_tuning_preview.bin",
       &imx290_hdr_off_tuning_preview,
    },
    {
       "imx307_tuning_preview_133_100ms.bin",
        &imx307_tuning_preview_133_100ms,
    },
    {
       "imx307_tuning_preview_133_10ms.bin",
        &imx307_tuning_preview_133_10ms,
    },
    {
       "imx307_tuning_preview_6mm_fov60.bin",
        &imx307_tuning_preview_6mm_fov60,
    },
    {
       "imx307_tuning_preview_80_100ms.bin",
        &imx307_tuning_preview_80_100ms,
    },
    {
       "imx307_tuning_preview_80_10ms.bin",
        &imx307_tuning_preview_80_10ms,
    },
    {
       "imx307_tuning_preview_f1_0_drc_off.bin",
        &imx307_tuning_preview_f1_0_drc_off,
    },
    {
       "imx307_tuning_preview_f1_0_drc_on.bin",
        &imx307_tuning_preview_f1_0_drc_on,
    },
    {
       "ov9712_tuning_preview.bin",
        &ov9712_tuning_preview,
    },
    {
       "imx307_ir_tuning_preview.bin",
        &imx307_ir_tuning_preview,
    },
    {
       "imx307_tuning_preview_f1_0_drc_off_10ms.bin",
        &imx307_tuning_preview_f1_0_drc_off_10ms,
    },
    {
       "imx307_tuning_preview_f1_0_drc_on_10ms.bin",
        &imx307_tuning_preview_f1_0_drc_on_10ms,
    },
    {
       "imx307_tuning_preview_f1_0_drc_on_100ms.bin",
        &imx307_tuning_preview_f1_0_drc_on_100ms,
    },
    {
       "imx307_tuning_preview_150_10ms_tsl.bin",
        &imx307_tuning_preview_150_10ms_tsl,
    },
    {
       "imx307_hdr_tuning_preview_f1_0.bin",
        &imx307_hdr_tuning_preview_f1_0,
    },
    {
       "imx307_hdr_off_tuning_preview_f1_0.bin",
        &imx307_hdr_off_tuning_preview_f1_0,
    },
    //////////////////////////////////////////////
    {
       "imx307_tuning_preview_12mm_f1_6_10ms.bin",
        &imx307_tuning_preview_12mm_f1_6_10ms,
    },
    {
       "imx307_tuning_preview_yt_f1_0_10ms.bin",
        &imx307_tuning_preview_yt_f1_0_10ms,
    },
    ////////////////////////////////////////////////
    {
       "imx307_hdr_tuning_preview_80_30ms.bin",
        &imx307_hdr_tuning_preview_80_30ms,
    },
    {
       "imx307_tuning_preview_133_100ms_infra_red_mode.bin",
        &imx307_tuning_preview_133_100ms_infra_red_mode,
    },
    {
       "imx378_tuning_preview.bin",
        &imx378_tuning_preview,
    },
	{
       "imx415_tuning_preview_aobi4k.bin",
        &imx415_tuning_preview_aobi4k,
    },
	    {
       "imx415_tuning_preview_aobi1080binning.bin",
        &imx415_tuning_preview_aobi1080binning,
    },
    {
       "imx415_tuning_preview.bin",
        &imx415_tuning_preview,
    },
    {
       "imx415_tuning_preview_dwt120.bin",
        &imx415_tuning_preview_dwt120,
    },
	{
       "imx415_tuning_preview_hj5136.bin",
        &imx415_tuning_preview_hj5136,
    },
    {
       "imx307_tuning_preview_dwt_80.bin",
        &imx307_tuning_preview_dwt_80,
    },
    {
       "imx307_tuning_preview_ir_80.bin",
        &imx307_tuning_preview_ir_80,
    },
    {
       "imx307_hdr_tuning_preview_80.bin",
        &imx307_hdr_tuning_preview_80,
    },
	{
	    "imx307_hdr_tuning_preview_8mm.bin",
	    &imx307_hdr_tuning_preview_8mm,
    },
    {
	    "imx307_tuning_preview_8mm_10ms.bin",
	    &imx307_tuning_preview_8mm_10ms,
    },
     {
	    "ov02k10_tuning_preview.bin",
	    &ov02k10_tuning_preview,
    },   
	{
	    "imx307_tuning_preview_linux_face_machine.bin",
	    &imx307_tuning_preview_linux_face_machine,
    },
	{
	    "imx307_tuning_preview_ir_linux_face_machine.bin",
	    &imx307_tuning_preview_ir_linux_face_machine,
    },
};

int main(int argc,void *argv[])
{
  int i=0;
  int size=sizeof(dump)/sizeof(struct dump_tuning_file);
  int fd=-1;
  char name[128];
  for(i=0;i<size;i++){
     sprintf(name,"./bin/%s",dump[i].name);
     fd=open(name,O_CREAT|O_RDWR, 0644);
     if(fd>=0){
         write(fd,dump[i].p_tuning,sizeof(algo_isp_tuning_t));
         close(fd);
     }
  }
  return 0;
}


