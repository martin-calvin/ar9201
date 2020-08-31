
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

#if !defined(WIN32) && !defined(X64)
#include <unistd.h>
#else
#include<io.h>
#endif

#if !defined(WIN32) && !defined(X64)
#include <sys/time.h>
#endif
#include "ar_icc.h"
#include "ar_ion.h"

#include "ar_alg_define.h"
#include "ar_img_api.h"
#include "ar_dsp_common.h"
#include "ar_dsp_alg.h"
#include "ar_get_img_list.h"

#include "libyuv.h"
#include "./libyuv/convert_from.h"


extern SYS_CONFIG_st g_sys_cfg;
extern int g_app_quit_flag;
extern int g_thread_exit_cnt;
extern int g_img_thread_is_running;

using namespace cv;
using namespace std;
using namespace libyuv;

static int img_list_len;
static pthread_mutex_t img_list_lock;
static struct img_list * img_list_head;

//-----------Functions-----------------------

int ar_init_img_list()
{
	img_list_head = NULL;
	img_list_len = 0;
    pthread_mutex_init(&img_list_lock, NULL);
	return 0;
}

int ar_add_img_to_list(struct img_list * entry)
{
	pthread_mutex_lock(&img_list_lock);

	AR_PRINTF_DEBUG("add frame id %d \r\n", entry->frame_id);

	struct img_list * tmp = img_list_head;
	struct img_list * tmp_next = NULL;

	if(!img_list_head)
	{
		img_list_head = entry;
		img_list_len++;
		pthread_mutex_unlock(&img_list_lock);
		return 0;
	}

	if(img_list_len < MAX_IMG_LIST_LEN)
	{
		while(tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = entry;
		entry->prev = tmp;
		img_list_len++;

	}
	else
	{
	    // full, rm head or first not in using element, add tail
        if(!tmp->used)
        {
		    img_list_head = tmp->next;
			img_list_head->prev = NULL;
			tmp->img.release();
			tmp->rsz_img.release();
			free(tmp);
        }
		else
		{
            tmp = img_list_head;
			while(tmp->next)
			{
			    if(!tmp->next->used)
			    {
                    break;
				}
				tmp = tmp->next;
			}
			tmp_next = tmp->next;
			if(tmp_next->next)
			{
			   tmp_next->prev->next = tmp_next->next;
			   tmp_next->next->prev = tmp_next->prev;
			}
			else
			{
               tmp_next->prev->next =NULL;
			}

			tmp_next->img.release();
			tmp_next->rsz_img.release();
			free(tmp_next);

		}

		tmp = img_list_head;
		while(tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = entry;
		entry->prev = tmp;

	}

	pthread_mutex_unlock(&img_list_lock);
	return 0;

}


struct img_list * ar_get_img_from_list()
{
	pthread_mutex_lock(&img_list_lock);
	struct img_list * entry = img_list_head;

	if(!entry)
	{
		AR_PRINTF_DEBUG("img list is empty!\r\n");
		pthread_mutex_unlock(&img_list_lock);
		return NULL;
	}

    while(entry)
	{
		if(!entry->used)
		{
			AR_PRINTF_DEBUG("get frame id %d \r\n", entry->frame_id);
			entry->used++;
			break;
		}
		entry = entry->next;
	}

 	pthread_mutex_unlock(&img_list_lock);
	return entry;
	//unlock
}


int ar_release_img_to_list(struct img_list * entry)
{
	pthread_mutex_lock(&img_list_lock);

	if(!entry)
	{
		pthread_mutex_unlock(&img_list_lock);
		return -1;
	}

	AR_PRINTF_DEBUG("release frame id %d \r\n", entry->frame_id);
	entry->released++;

	pthread_mutex_unlock(&img_list_lock);

	ar_recyle_used_img_from_list();

	return 0;

}

int ar_recyle_used_img_from_list( )
{
	pthread_mutex_lock(&img_list_lock);

	struct img_list * entry = img_list_head;
	struct img_list * next = NULL;

	while(entry)
	{
		if(entry->used && entry->used == entry->released)
		{
			//if this is the head
			if(!entry->prev)
			{
				img_list_head = entry->next;
				if(img_list_head)
				{
					img_list_head->prev = NULL;
				}
				next = entry->next;
			}
			else if(!entry->next) //if this is the tail
			{
			    if(!entry->prev)
			    {
				   img_list_head = NULL;
			    }
				else
				{
                    entry->prev->next =NULL;
				}
				next = NULL;
			}
			else //if this is a middle node,remove it
			{
				entry->prev->next = entry->next;
				entry->next->prev = entry->prev;
				next = entry->next;
			}
			AR_PRINTF_DEBUG("recyle frame id %d \r\n", entry->frame_id);
			entry->img.release();
			entry->rsz_img.release();
			free(entry);
			img_list_len--;

			entry = next;
		}
		else
		{
			//just move forward
			entry = entry->next;
		}
	}

	pthread_mutex_unlock(&img_list_lock);
	return 0;
}

#if !defined(WIN32) && !defined(X64)
void * ar_get_img_thread_func(void *arg)
{
	int sensor_fd = 0;
 	ar_rpc_sink_buffer_t *buf_info = NULL;
	struct img_list * img_entry = NULL;
	THREAD_PARAM_st * p_t_param = 0;

	unsigned char * bufy = 0;
	unsigned char * bufu = 0;
	unsigned char * bufv = 0;

        int resize_height = 0;
	int resize_width = 0;

	p_t_param = (THREAD_PARAM_st *)arg;


	if(strcmp(p_t_param->demo_name, "sweeper_ssd") == 0)
	{
	#ifdef ENABLE_SWEEPER_OPTION
		sensor_fd = ar_alg_open_video_stream(SWEEPER_VIDEO_DEVICE);
	#endif
	}
	else if(strlen(p_t_param->dev_name)) //for non-sweeper case
	{
		sensor_fd = ar_alg_open_video_stream(p_t_param->dev_name);
	}
	else
	{
        	sensor_fd = ar_alg_open_video_stream(VIDEO_DEVICE_0);
	}

	if(sensor_fd < 0)
	{
		AR_PRINTF_ERR("Open %s/%s or %s failed!\r\n",VIDEO_DEVICE_0,p_t_param->dev_name,SWEEPER_VIDEO_DEVICE);
		goto _free_and_exit;
	}

  	resize_width  = p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].width;
	resize_height =  p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].height;

	//malloc max 4K buffer: 3840x2160
	bufu = (unsigned char *)malloc( 3840 * 2160);
	bufv = (unsigned char *)malloc( 3840 * 2160);
	if(!bufu || !bufv)
	{
		AR_PRINTF_ERR("Malloc buffer failed!\r\n");
		goto _free_and_exit;
	}

	while(1)
	{
	  if(g_app_quit_flag) break;

	  buf_info = NULL;
	  buf_info = ar_alg_get_img(sensor_fd);  //have sleep
	  if(!buf_info)
	  {
		  AR_PRINTF_ERR("Get sensor img error!\r\n");
		  goto _free_and_exit;
	  }

	  //during sensor stop/start, the buf may have invalid data.
	  if(buf_info->format.height <= 0 || buf_info->format.height > 4096
	  	|| buf_info->format.width <= 0 || buf_info->format.width > 4096)
	  {
	      AR_PRINTF_ERR("Invalid sensor img w/h: %d %d, continue...\r\n", buf_info->format.width, buf_info->format.height);
		  ar_alg_release_img(sensor_fd, buf_info);
		  continue;
	  }

	  img_entry = NULL;
	  img_entry = (struct img_list *)malloc(sizeof(struct img_list));
          if(img_entry ==NULL)
          {
              AR_PRINTF_ERR("Malloc Image error!\r\n");
              ar_alg_release_img(sensor_fd, buf_info);
              continue;
	  }

	  memset(img_entry, 0, sizeof(struct img_list));

	  img_entry->img.create(buf_info->format.height, buf_info->format.width, CV_8UC3);

          if(buf_info->format.format == AR_VIDEO_FORMAT_Y42B)
          {
              //UV 422 to 420
              libyuv::ScalePlane((const uint8_t*)buf_info->mem[1].addr, buf_info->format.chroma_stride, buf_info->format.width/2, buf_info->format.height, 
                                 (uint8_t *)bufu, buf_info->format.width/2/*stride*/, buf_info->format.width/2, buf_info->format.height/2, kFilterNone/*Point sample*/);
              libyuv::ScalePlane((const uint8_t*)buf_info->mem[2].addr, buf_info->format.chroma_stride, buf_info->format.width/2, buf_info->format.height, 
                                 (uint8_t *)bufv, buf_info->format.width/2/*stride*/, buf_info->format.width/2, buf_info->format.height/2, kFilterNone/*Point sample*/);

	      libyuv::H420ToRGB24((const uint8_t*)(buf_info->mem[0].addr), buf_info->format.luma_stride,
                              (const uint8_t*)(bufu), buf_info->format.width/2, 
                              (const uint8_t*)(bufv), buf_info->format.width/2,
                              (uint8_t*)img_entry->img.data, buf_info->format.width * 3, buf_info->format.width, buf_info->format.height);
          }
          else if(buf_info->format.format == AR_VIDEO_FORMAT_I420)
          {
              libyuv::H420ToRGB24((const uint8_t*)(buf_info->mem[0].addr), buf_info->format.luma_stride,
                              (const uint8_t*)(buf_info->mem[1].addr), buf_info->format.chroma_stride,
                              (const uint8_t*)(buf_info->mem[2].addr), buf_info->format.chroma_stride,
                              (uint8_t*)img_entry->img.data, buf_info->format.width * 3, buf_info->format.width, buf_info->format.height);

          }
          else
          {
              AR_PRINTF_ERR("The format is not implemented yet.\r\n");
              free(img_entry);
              ar_alg_release_img(sensor_fd, buf_info);
              continue;
          }

	  img_entry->frame_id = buf_info->frame_id;
	  img_entry->img.cols = buf_info->format.width;
	  img_entry->img.rows  = buf_info->format.height;
          
          ar_alg_release_img(sensor_fd, buf_info);
         
	  img_entry->rsz_img.create(resize_height,resize_width, CV_8UC3);

	  cv::resize(img_entry->img, img_entry->rsz_img, Size(resize_width,resize_height));

	  ar_recyle_used_img_from_list( );

	  ar_add_img_to_list(img_entry);

#ifdef ENABLE_SWEEPER_OPTION
	  //for sweeper, 5 fps is enough ?
	  usleep(60000);
#endif
	}

_free_and_exit:
	if(!bufu)
	{
		free(bufu);
	}
	if(!bufv)
	{
		free(bufv);
	}
	//clear all img list
	img_entry = NULL;
	while((img_entry = ar_get_img_from_list()) != NULL)
	{
		ar_release_img_to_list(img_entry);
	}

	ar_recyle_used_img_from_list();

	if(sensor_fd)
	{
		ar_alg_close_video_stream(sensor_fd);
	}

	g_img_thread_is_running = 0;

	AR_PRINTF_DEBUG("Get img thread exit...\r\n");
	return NULL;
}
#else

void * ar_get_img_thread_func(void *arg)
{
	return NULL;
}

#endif

