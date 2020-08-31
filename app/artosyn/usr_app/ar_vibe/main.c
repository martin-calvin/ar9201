/**
  * @file your-main-file-sequential.c
  * \brief Shows how to use ViBe in your own C/C++ project
  *
  
  This file contains an example of a main functions that uses the ViBe algorithm
  implemented in vibe-background-sequential.{o, h}. You should read vibe-background-sequential.h for
  more information.

  Full documentation is available online at:
     http://www.ulg.ac.be/telecom/research/vibe/doc

  vibe-background.o was compiled by <tt>gcc</tt> using the following command
  \verbatim
  $> gcc -std=c99 -O3 -Wall -Werror -pedantic -Wno-unused-function -Wno-unused-parameter -Wno-deprecated -Wno-deprecated-declarations -Wno-sign-compare -Wno-unused-but-set-parameter -c vibe-background-sequential.c
  \endverbatim

  This file can be compiled using the following command
  \verbatim
  $> gcc -o main -std=c99 -O3 -Wall -Werror -pedantic your-main-file.c vibe-background-sequential.o
  \endverbatim

  * @date July 2014
  * @author Marc Van Droogenbroeck 
*/

#ifdef __cplusplus
extern "C"
{
#endif 


#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <errno.h>
#include <signal.h>


#include "ar_vibe.h"
#include "vibe-background-sequential.h"
#include "ar_common_define.h"
#include "ar_meta_define.h"
#include "ar_multimedia_base.h"
#include "ar_picture_common_api.h"
#include "ar_img_api.h"
#include "ar_gui.h"
#include "ar_log.h"
#include "icc_proxy_rpc_def.h"

#define MEASURE_TIME(x) \
do{ \
	struct timeval tv; \
	gettimeofday(&tv, NULL); \
	x = tv.tv_sec * 1000 + tv.tv_usec / 1000; \
} while (0)



#ifdef __cplusplus
}
#endif


static int32_t get_image_width(void *stream)
{
  /* Put your own code here. */
  return(1920);
}

static int32_t get_image_height(void *stream)
{
  /* Put your own code here. */
  return(1080);
}

static int32_t *acquire_image_C1R(void *stream, uint8_t *image_data, int32_t width, int32_t height)
{
  /* Put your own code here. */
  //memset(image_data, 127, width * height); // Fills the image with the 127 value.
  memcpy(image_data,stream,width*height);
  return(0);
}

static int32_t *acquire_image_C3R(void *stream, uint8_t *image_data, int32_t width, int32_t height)
{
  /* Put your own code here. */
  memset(image_data, 127, (3 * width) * height); // Fills the image with the 127 value.
  return(0);
}

/* Simulates a condition to stop after 100 frames. */
static int32_t finished(void *stream)
{
  /* Put your own code here. */
  static int32_t counter = 0;
  return(!(counter++ < 300));
}
#define VIBE_MEM_SIZE  8294400 //(3840 * 2160)

#define NUM_SAMPLES      20    //
#define MATCHING_THREADS 20
#define MATCHING_NUMBER  2
#define UPDATE_FACTOR    16   //2~64


int acquire_image(char * device_name, motion_detect_param_t *param, char * image_data)
{
	ar_picture_handle *handle = NULL;
	ar_picture_buffer_t *picture_buffer = NULL;
	char *tmp_buffer = NULL;
	int row =0,col =0;
	char *stream = NULL; 
	handle = ar_picture_open(device_name);
	printf("picture handle %d .....\n",handle);
	if(!handle)
	{
	 printf("open %s failed!\n", device_name);
	 return -1;
	}
	picture_buffer = NULL;
	picture_buffer = ar_picture_get_img(handle);
	if(!picture_buffer)
	{
	  printf("get buffer fail!! %s line:%d\n", __func__, __LINE__);
	  ar_picture_release_img(handle, picture_buffer);
	  ar_picture_close(handle);
	  return -1;
	}
	printf("ar_picture_get_img finished %d .....\n");


	/* copy video_buffer y*/
	int data_len = (picture_buffer->format.width)*(picture_buffer->format.height);
	printf("data_len %d, luma_stride %d, width %d, height %d\n",data_len,picture_buffer->format.luma_stride,picture_buffer->format.width,picture_buffer->format.height);  
	int data_len1 = (picture_buffer->format.luma_stride)*(picture_buffer->format.height);
	tmp_buffer = (char*)malloc(data_len1*sizeof(char));
	stream     = (char*)malloc(data_len *sizeof(char));
	/* Get the dimensions of the images of your stream. */
	param->width = picture_buffer->format.width;    
	param->height = picture_buffer->format.height;  
	int tmp_cnt =0;
	memcpy(tmp_buffer,picture_buffer->mem[0].addr,data_len1);
	memset(stream,0,data_len);
	for(col=0;col<param->height;col++)
	{
		for(row=0;row<param->width;row++)
		{
			stream[tmp_cnt] = tmp_buffer[row+col*picture_buffer->format.luma_stride];
			if(tmp_cnt<16)
				printf("stream[%d] %x,tmp_buffer[%d] %x\n",tmp_cnt,stream[tmp_cnt],tmp_cnt,tmp_buffer[row+col*picture_buffer->format.luma_stride]);

			tmp_cnt++;
		}
	}
	printf("tmp_cnt %d, data_len %d\n",tmp_cnt, data_len);
	memcpy(image_data,stream,data_len);
	ar_picture_release_img(handle, picture_buffer);
	free(tmp_buffer);
	free(stream);
	ar_picture_close(handle);
	return 0;
}




int main(int argc, char **argv)
{
  /* Your video stream. */

  /* acquire sensor image*/
  int fp,ret;
  unsigned long start_time,end_time;
  
  char *device_name = NULL;
  char file_name[64];
  device_name = argv[1];
  char *stream = (char *)malloc(VIBE_MEM_SIZE);
  motion_detect_param_t * vibe_param = (motion_detect_param_t *)malloc(1*sizeof(motion_detect_param_t));
  acquire_image(device_name,vibe_param,stream);
  printf("vibe_param width %d, height %d\n",vibe_param->width,vibe_param->height);
  vibe_param->numberOfSamples   = NUM_SAMPLES;
  vibe_param->matchingThreshold = MATCHING_THREADS;
  vibe_param->matchingNumber 	= MATCHING_NUMBER;
  vibe_param->updateFactor 		= UPDATE_FACTOR;
  
  ar_vibe_init(vibe_param);
  memcpy(vibe_param->stream,stream,vibe_param->width*vibe_param->height);
  ar_vibe_proc_first_img(vibe_param);
  

  /* Processes all the following frames of your stream: results are stored in "segmentation_map". */
  int cnt1 =0;
  while (!finished(stream)) {
    fprintf(stderr, ".");cnt1++;

    acquire_image(device_name,vibe_param,stream);
    memcpy(vibe_param->stream,stream,vibe_param->width*vibe_param->height);
	ar_vibe_proc(vibe_param);

	
	#if 1
	sprintf(file_name,"/mnt/calc_img/calc_img_%d.jpg",cnt1);
	fp = open(file_name, O_RDWR|O_CREAT);
	if(!fp)
	{
		printf("open file fail!!  %s line:%d\n", __func__, __LINE__);
		return;
	}
	ret = write(fp,vibe_param->segmentation_map, vibe_param->width * vibe_param->height);
	if(ret != vibe_param->width * vibe_param->height)
		printf("index:%d data_len:%d  ret_len:%d line:%d\n", index, vibe_param->width * vibe_param->height, ret, __LINE__);
	fsync(fp);
	close(fp);
	#endif
	printf("write file cnt_1 %d finished !\n",cnt1);
  }

	printf("finished stream ... \n");
    fprintf(stderr, "\n");

  /* Cleanup allocated memory. */
  ar_vibe_uninit(vibe_param);
  free(stream);

  return(0);
}
