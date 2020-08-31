
/*********MTCNN Demo process***********/
#if !defined(WIN32) && !defined(X64)
#include <unistd.h>
#else
#include<io.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <dirent.h>

#include "libyuv.h"
#include "./libyuv/convert_from.h"

#if !defined(WIN32) && !defined(X64)
#include <sys/time.h>
#endif

#include "opencv2/opencv.hpp"

#include "ar_icc.h"
#include "ar_ion.h"
#include "ar_alg_define.h"
#if defined(WIN32) || defined(X64)
#include "ar_dsp_rpc.h"
#endif

#include "ar_alg.h"
#include "ar_img_api.h"
#include "ar_dsp_common.h"
#include "ar_dsp_alg.h"

#include "comp_osd.h"
#include "ar_get_img_list.h"

extern SYS_CONFIG_st g_sys_cfg;
extern int g_app_quit_flag;
extern int g_thread_exit_cnt;
extern int g_osd_fd;

static inline void sample_image_calc_resolution(SAMPLE_RECTBOX_T* rectbox)
{
	rectbox->x1 = (float)(int)(rectbox->x1);
	rectbox->y1 = (float)(int)(rectbox->y1);
	rectbox->x2 = (float)(int)(rectbox->x2);
	rectbox->y2 = (float)(int)(rectbox->y2);
	rectbox->width = rectbox->x2 - rectbox->x1 + 1;
	rectbox->height = rectbox->y2 - rectbox->y1 + 1;
}

int sample_image_crop_easy(SAMPLE_PICTURE_T* source, SAMPLE_RECTBOX_T* cropbox, SAMPLE_PICTURE_T* picture)
{
	sample_image_calc_resolution(cropbox);
	int bufsize = (int)((cropbox->width) * (cropbox->height) * source->channel);
	if (picture->size < bufsize){
		AR_PRINTF_ERR("image buffer %d small than %d\r\n", picture->size, bufsize);
		return -1;
	}

	if (cropbox->width >= 0 && cropbox->height >= 0 &&
		cropbox->x1 < source->width && cropbox->y1 < source->height){
	}
	else{
		return -2;
	}

	cropbox->width += cropbox->x1;
	cropbox->height += cropbox->y1;

	cropbox->x1 = (cropbox->x1 > 0) ? cropbox->x1 : 0;
	cropbox->y1 = (cropbox->y1 > 0) ? cropbox->y1 : 0;

	cropbox->width = (cropbox->width > source->width) ? source->width : cropbox->width;
	cropbox->height = (cropbox->height > source->height) ? source->height : cropbox->height;

	cropbox->width -= cropbox->x1;
	cropbox->height -= cropbox->y1;

	cropbox->x2 = cropbox->x1 + cropbox->width - 1;
	cropbox->y2 = cropbox->y1 + cropbox->height - 1;

	picture->width = cropbox->width;
	picture->height = cropbox->height;
	picture->channel = source->channel;
	picture->stride = picture->channel * picture->width;
	picture->format = source->format;

	int h = 0;
#if 0
	for (h = cropbox->y1; h <= cropbox->y2; h++){
		for (w = cropbox->x1; w <= cropbox->x2; w++){
			for (c = 0; c < source->channel; c++){
				unsigned char pixel = source->buffer[h * source->stride + w * source->channel + c];
				int h1 = h - cropbox->y1;
				int w1 = w - cropbox->x1;
				picture->buffer[h1 * picture->width * picture->channel + w1 * picture->channel + c] = pixel;
			}
		}
	}
#else
	for (h = cropbox->y1; h <= cropbox->y2; h++){
		int h1 = h - cropbox->y1;
		memcpy((picture->buffer+(h1 * picture->width * picture->channel )) ,(source->buffer+(h * source->stride +(int)(cropbox->x1 *source->channel))),(cropbox->x2 - cropbox->x1 + 1)*source->channel);
	}
#endif

	return 0;
}

int sample_image_crop_resize_easy(SAMPLE_PICTURE_T* source, SAMPLE_RECTBOX_T* cropbox, SAMPLE_PICATTR_T* attr, SAMPLE_PICTURE_T* picture,int bias_w, int bias_h)
{
	sample_image_calc_resolution(cropbox);
	//if (picture->size < bufsize){
	//	AR_PRINTF_ERR("image buffer %d small than %d\r\n", picture->size, bufsize);
	//	return -1;
	//}

	if (cropbox->width >= 0 && cropbox->height >= 0 &&
		cropbox->x1 < source->width && cropbox->y1 < source->height){
	}
	else{
		return -2;
	}

	cropbox->width += cropbox->x1;
	cropbox->height += cropbox->y1;

	cropbox->x1 = (cropbox->x1 > 0) ? cropbox->x1 : 0;
	cropbox->y1 = (cropbox->y1 > 0) ? cropbox->y1 : 0;

	cropbox->width = (cropbox->width > source->width) ? source->width : cropbox->width;
	cropbox->height = (cropbox->height > source->height) ? source->height : cropbox->height;

	cropbox->width -= cropbox->x1;
	cropbox->height -= cropbox->y1;

	cropbox->x2 = cropbox->x1 + cropbox->width - 1;
	cropbox->y2 = cropbox->y1 + cropbox->height - 1;

	int crop_source_width = cropbox->width;
	int crop_source_height = cropbox->height;
	int crop_source_format = source->format;

	/*int w, h, c;
	for (h = cropbox->y1; h <= cropbox->y2; h++){
	for (w = cropbox->x1; w <= cropbox->x2; w++){
	for (c = 0; c < source->channel; c++){
	unsigned char pixel = source->buffer[h * source->stride + w * source->channel + c];
	int h1 = h - cropbox->y1;
	int w1 = w - cropbox->x1;
	picture->buffer[h1 * picture->width * picture->channel + w1 * picture->channel + c] = pixel;
	}
	}
	}*/

	picture->stride = picture->channel * picture->width;
	picture->format = crop_source_format;

	int h, w;
	float w_scale = (float)(crop_source_width - 1) / (attr->width - 1);
	float h_scale = (float)(crop_source_height - 1) / (attr->height - 1);

	for (h = 0; h < attr->height; h++){
		for (w = 0; w < attr->width; w++){
			float sx = w * w_scale;
			float sy = h * h_scale;
			int ix = (int)sx;
			int iy = (int)sy;
			float dx = sx - ix;
			float dy = sy - iy;

			//unsigned char urgb[3] = { 0 };
			//unsigned char drgb[3] = { 0 };
			//wen-opt:
			float urgb[3] = { 0 };
			float drgb[3] = { 0 };

			int ix1 = (ix < crop_source_width - 1) ? ix + 1 : ix;
			int iy1 = (iy < crop_source_height - 1) ? iy + 1 : iy;

			ix += cropbox->x1;
			iy += cropbox->y1;

			ix1 += cropbox->x1;
			iy1 += cropbox->y1;

			int piontA = iy * source->stride + ix * source->channel;
			int pointB = iy * source->stride + ix1 * source->channel;
			int pointC = iy1 * source->stride + ix * source->channel;
			int pointD = iy1 * source->stride + ix1 * source->channel;

			//int pointT = h * picture->stride + w * picture->channel;//??????!
			int pointT = (bias_h + h) * picture->stride + (bias_w + w) * picture->channel;

			urgb[0] = (1 - dx) * source->buffer[piontA + 0] + dx * source->buffer[pointB + 0];
			urgb[1] = (1 - dx) * source->buffer[piontA + 1] + dx * source->buffer[pointB + 1];
			urgb[2] = (1 - dx) * source->buffer[piontA + 2] + dx * source->buffer[pointB + 2];

			drgb[0] = (1 - dx) * source->buffer[pointC + 0] + dx * source->buffer[pointD + 0];
			drgb[1] = (1 - dx) * source->buffer[pointC + 1] + dx * source->buffer[pointD + 1];
			drgb[2] = (1 - dx) * source->buffer[pointC + 2] + dx * source->buffer[pointD + 2];

			picture->buffer[pointT + 0] = (unsigned char)((1 - dy) * urgb[0] + dy * drgb[0] + 0.5);
			picture->buffer[pointT + 1] = (unsigned char)((1 - dy) * urgb[1] + dy * drgb[1] + 0.5);
			picture->buffer[pointT + 2] = (unsigned char)((1 - dy) * urgb[2] + dy * drgb[2] + 0.5);
		}
	}
	return 0;

}

int sample_image_resize_easy(SAMPLE_PICTURE_T* source, SAMPLE_PICATTR_T* attr, SAMPLE_PICTURE_T* picture)
{
	picture->width = attr->width;
	picture->height = attr->height;
	picture->channel = source->channel;
	picture->stride = picture->channel * picture->width;
	picture->format = source->format;

	int h, w;
	float w_scale = (float)(source->width - 1) / (attr->width - 1);
	float h_scale = (float)(source->height - 1) / (attr->height - 1);

	for (h = 0; h < attr->height; h++){
		for (w = 0; w < attr->width; w++){
			float sx = w * w_scale;
			float sy = h * h_scale;
			int ix = (int)sx;
			int iy = (int)sy;
			float dx = sx - ix;
			float dy = sy - iy;

			//unsigned char urgb[3] = { 0 };
			//unsigned char drgb[3] = { 0 };
			//wen-opt:
			float urgb[3] = { 0 };
			float drgb[3] = { 0 };

			int ix1 = (ix < source->width - 1) ? ix + 1 : ix;
			int iy1 = (iy < source->height - 1) ? iy + 1 : iy;

			int piontA = iy * source->stride + ix * source->channel;
			int pointB = iy * source->stride + ix1 * source->channel;
			int pointC = iy1 * source->stride + ix * source->channel;
			int pointD = iy1 * source->stride + ix1 * source->channel;

			int pointT = h * attr->width * attr->channel + w * attr->channel;

			urgb[0] = (1 - dx) * source->buffer[piontA + 0] + dx * source->buffer[pointB + 0];
			urgb[1] = (1 - dx) * source->buffer[piontA + 1] + dx * source->buffer[pointB + 1];
			urgb[2] = (1 - dx) * source->buffer[piontA + 2] + dx * source->buffer[pointB + 2];

			drgb[0] = (1 - dx) * source->buffer[pointC + 0] + dx * source->buffer[pointD + 0];
			drgb[1] = (1 - dx) * source->buffer[pointC + 1] + dx * source->buffer[pointD + 1];
			drgb[2] = (1 - dx) * source->buffer[pointC + 2] + dx * source->buffer[pointD + 2];

			picture->buffer[pointT + 0] = (unsigned char)((1 - dy) * urgb[0] + dy * drgb[0] + 0.5);
			picture->buffer[pointT + 1] = (unsigned char)((1 - dy) * urgb[1] + dy * drgb[1] + 0.5);
			picture->buffer[pointT + 2] = (unsigned char)((1 - dy) * urgb[2] + dy * drgb[2] + 0.5);
		}
	}
	return 0;

}

int sample_image_resize_easy_opt(SAMPLE_PICTURE_T* source, SAMPLE_PICATTR_T* attr, SAMPLE_PICTURE_T* picture, int bias_w, int bias_h )
{
	//picture->width = attr->width;
	//picture->height = attr->height;
	//picture->channel = source->channel;
	picture->stride = picture->channel * picture->width;
	picture->format = source->format;

	int h, w;
	float w_scale = (float)(source->width - 1) / (attr->width - 1);
	float h_scale = (float)(source->height - 1) / (attr->height - 1);

	for (h = 0; h < attr->height; h++){
		for (w = 0; w < attr->width; w++){
			float sx = w * w_scale;
			float sy = h * h_scale;
			int ix = (int)sx;
			int iy = (int)sy;
			float dx = sx - ix;
			float dy = sy - iy;

			//unsigned char urgb[3] = { 0 };
			//unsigned char drgb[3] = { 0 };
			//wen-opt:
			float urgb[3] = { 0 };
			float drgb[3] = { 0 };

			int ix1 = (ix < source->width - 1) ? ix + 1 : ix;
			int iy1 = (iy < source->height - 1) ? iy + 1 : iy;

			int piontA = iy * source->stride + ix * source->channel;
			int pointB = iy * source->stride + ix1 * source->channel;
			int pointC = iy1 * source->stride + ix * source->channel;
			int pointD = iy1 * source->stride + ix1 * source->channel;

			//int pointT = h * picture->stride + w * picture->channel;//??????!
			int pointT = (bias_h + h) * picture->stride + (bias_w + w) * picture->channel;

			urgb[0] = (1 - dx) * source->buffer[piontA + 0] + dx * source->buffer[pointB + 0];
			urgb[1] = (1 - dx) * source->buffer[piontA + 1] + dx * source->buffer[pointB + 1];
			urgb[2] = (1 - dx) * source->buffer[piontA + 2] + dx * source->buffer[pointB + 2];

			drgb[0] = (1 - dx) * source->buffer[pointC + 0] + dx * source->buffer[pointD + 0];
			drgb[1] = (1 - dx) * source->buffer[pointC + 1] + dx * source->buffer[pointD + 1];
			drgb[2] = (1 - dx) * source->buffer[pointC + 2] + dx * source->buffer[pointD + 2];

			picture->buffer[pointT + 0] = (unsigned char)((1 - dy) * urgb[0] + dy * drgb[0] + 0.5);
			picture->buffer[pointT + 1] = (unsigned char)((1 - dy) * urgb[1] + dy * drgb[1] + 0.5);
			picture->buffer[pointT + 2] = (unsigned char)((1 - dy) * urgb[2] + dy * drgb[2] + 0.5);

		}
	}
	return 0;

}


static int score_compare(const void* item1, const void* item2) {
	SAMPLE_ODSCORE_T* score1 = (SAMPLE_ODSCORE_T*)item1;
	SAMPLE_ODSCORE_T* score2 = (SAMPLE_ODSCORE_T*)item2;

	if (score1->score < score2->score) {
		return -1;
	}
	else if (score1->score > score2->score) {
		return 1;
	}
	return 0;
}

static void compute_nms( SAMPLE_RECTBOX_T* boxs, int box_size, SAMPLE_ODSCORE_T* scores,
                                int score_size, const float threshold,const char* modelname )
{
	if (box_size == 0)
	{
		return;
	}

	qsort(scores, score_size, sizeof(scores[0]), score_compare);

	int order = 0;
	float inter = 0;
	float maxX = 0;
	float maxY = 0;
	float minX = 0;
	float minY = 0;
	float maxH = 0;
	float maxW = 0;

	int score_index;
	int box_index;
	//int hero_count = 0;

	for (score_index = score_size - 1; score_index >= 0; score_index--)
	{
		order = scores[score_index].order;
		if (order < 0)
		{
			continue;
		}

		int index;
		for (index = score_index - 1; index >= 0; index--)
		{
			box_index = scores[index].order;
			if (box_index < 0)
			{
				continue;
			}

			if ( boxs[box_index].valid )
			{
				maxX = sample_max(boxs[box_index].x1, boxs[order].x1);
				maxY = sample_max(boxs[box_index].y1, boxs[order].y1);
				minX = sample_min(boxs[box_index].x2, boxs[order].x2);
				minY = sample_min(boxs[box_index].y2, boxs[order].y2);
				maxW = sample_max((minX - maxX + 1), 0.0);
				maxH = sample_max((minY - maxY + 1), 0.0);

				inter = maxW * maxH;
				//IOU:
				//inter = inter / (boxs[box_index].area + boxs[order].area - inter);

				if (strcmp(modelname, "iom") == 0)
				{
					inter = inter / ((boxs[box_index].area < boxs[order].area) ? boxs[box_index].area : boxs[order].area);
				}
				else
				{
					inter = inter / (boxs[box_index].area + boxs[order].area - inter);
				}


				if (inter > threshold)
				{
					boxs[box_index].valid = 0;
					scores[index].order   = -1;
				}
			}
		}
		//*******************************************************************************
	}

}

static inline int calculate_box_area(SAMPLE_RECTBOX_T* box)
{
	box->width = box->x2 - box->x1 + 1;
	box->height = box->y2 - box->y1 + 1;
	box->area = box->width * box->height;
	return 0;
}

static inline int convert_box_square(SAMPLE_RECTBOX_T* box)
{
	box->width = box->x2 - box->x1;
	box->height = box->y2 - box->y1;

	float ourside = sample_max(box->width, box->height);
	box->x1 += box->width * 0.5 - ourside * 0.5;
	box->y1 += box->height * 0.5 - ourside * 0.5;
	box->x2 = box->x1 + ourside;
	box->y2 = box->y1 + ourside;

	//wen-opt: not needed here!
	//calculate_box_area(box);

	return 0;
}

static int detect_pnet_object(SAMPLE_CONTEXT_T* context, ArCdnnOutputBuffer* prob, ArCdnnOutputBuffer* conv, int outside, float scale, float prob_threshold, float nms_threshold)
{
	int inside = 2 * outside + 11;
	float stride = 0.0;
	if (outside != 1){
		stride = (float)(inside - 12) / (outside - 1);
	}

	int width_index = 0, height_index = 0;

	int data_offset = prob->width * prob->height;

	int begin_box_count = context->temp_box_count;
	int begin_score_count = context->temp_score_count;

	int box_count = 0;
	int order_count = 0;

	float x1, y1, x2, y2;
	for (width_index = 0; width_index < prob->width; width_index++) {
		for (height_index = 0; height_index < prob->height; height_index++) {
			int data_index = width_index + height_index * prob->width;
			float pconf = ((float*)(prob->pdata))[data_offset + data_index];
			if (pconf >= prob_threshold) {

				SAMPLE_RECTBOX_T box = { 0 };

				#if(0)
				// Here keep the orignal version that is the same with Caffe
				float original_x1 = (float)(int)((width_index * stride + 0) * scale);
				float original_y1 = (float)(int)((height_index * stride + 0) * scale);
				float original_x2 = (float)(int)((width_index * stride + 11) * scale);
				float original_y2 = (float)(int)((height_index * stride + 11) * scale);
				#else
				float original_x1 = ((width_index * stride + 0) * scale);
				float original_y1 = ((height_index * stride + 0) * scale);
				float original_x2 = ((width_index * stride + 11) * scale);
				float original_y2 = ((height_index * stride + 11) * scale);
				#endif

				int planesize = conv->width * conv->height;
				x1 = ((float*)(conv->pdata))[data_index + planesize * 0];
				y1 = ((float*)(conv->pdata))[data_index + planesize * 1];
				x2 = ((float*)(conv->pdata))[data_index + planesize * 2];
				y2 = ((float*)(conv->pdata))[data_index + planesize * 3];

				box.valid = 1;
				// Fix by bwang
#if(0)//#if 1//fixed by wen
				box.x1 = original_x1 + y1 * 12.0 * scale;
				box.y1 = original_y1 + x1 * 12.0 * scale;
				box.x2 = original_x2 + y2 * 12.0 * scale;
				box.y2 = original_y2 + x2 * 12.0 * scale;
				box.score = pconf;
#else
				box.x1 = original_x1 + x1 * 12.0 * scale;
				box.y1 = original_y1 + y1 * 12.0 * scale;
				#if(ADAPT_FOR_RUIWEI)
				box.x2 = original_x1 + x2 * 12.0 * scale;
				box.y2 = original_y1 + y2 * 12.0 * scale;
				#else
				box.x2 = original_x2 + x2 * 12.0 * scale;
				box.y2 = original_y2 + y2 * 12.0 * scale;
				#endif
				box.score = pconf;
#endif
				convert_box_square(&box);

				#if(1)
				box.x1 = sample_max(0, box.x1);
				box.y1 = sample_max(0, box.y1);
				box.x2 = sample_min(SOURCE_IMAG_SIZE_W, box.x2);
				box.y2 = sample_min(SOURCE_IMAG_SIZE_H, box.y2);
				#else
				//Same with Caffe
				box.x1 = (int)sample_max(0, box.x1);
				box.y1 = (int)sample_max(0, box.y1);
				box.x2 = (int)sample_min(width, box.x2);
				box.y2 = (int)sample_min(height, box.y2);
				#endif

				calculate_box_area(&box);

				//SAMPLE_DEBUG((&context->profile), "Index %d Post [%d,%d] Rect [%f,%f,%f,%f] Score %f\r\n", box_count, width_index, height_index, box.x1, box.y1, box.x2, box.y2, pconf);
				box_count++;

				if ((box.x2 > box.x1) && (box.y2 > box.y1)){
					// ok
				}
				else{
					//SAMPLE_DEBUG(&context->profile, "Invalid Post [%d,%d] Rect [%f,%f,%f,%f] Score %f\r\n", width_index, height_index, box.x1, box.y1, box.x2, box.y2, pconf);
					continue;
				}

				if (context->temp_box_count >= context->temp_box_size || context->temp_score_count >= context->temp_score_size){
					//SAMPLE_ERROR(NULL, "PNet Box number large than catpacity\r\n");
					continue;
				}

				SAMPLE_RECTBOX_T*  mybox = &context->temp_boxs[context->temp_box_count];
				context->temp_box_count++;
				memcpy(mybox, &box, sizeof(box));

				SAMPLE_ODSCORE_T* myods = &context->temp_scores[context->temp_score_count];
				myods->order = order_count;
				myods->score = pconf;
				context->temp_score_count++;
				order_count++;
			}
		}
	}

	box_count = context->temp_box_count - begin_box_count;

	//SAMPLE_DEBUG(NULL, "PNET Record Before %d, Now %d, Box_count %d\r\n", begin_box_count, context->temp_box_count, box_count);

	int score_count = context->temp_score_count - begin_score_count;

	//SAMPLE_DEBUG(NULL, "PNET Score Before %d, Now %d, Score_count %d\r\n", begin_score_count, context->temp_score_count, score_count);
	/*
	if (context->profile.dump_outputs){
		int tmpindex = 0;
		for (tmpindex = begin_box_count; tmpindex < context->temp_box_count; tmpindex++){
			SAMPLE_DEBUG(NULL, "PNET Before NMS, Index %d Valid %d Rect [%f,%f,%f,%f] Score %f\r\n", tmpindex,
				context->temp_boxs[tmpindex].valid, context->temp_boxs[tmpindex].x1, context->temp_boxs[tmpindex].y1,
				context->temp_boxs[tmpindex].x2, context->temp_boxs[tmpindex].y2, context->temp_boxs[tmpindex].score);
		}
	} */

	compute_nms(&context->temp_boxs[begin_box_count], box_count, &context->temp_scores[begin_score_count], score_count, nms_threshold, "iou");

	/*
	if (context->profile.dump_outputs){
		int tmpindex = 0;
		for (tmpindex = begin_box_count; tmpindex < context->temp_box_count; tmpindex++){
			SAMPLE_DEBUG(NULL, "PNET After NMS, Index %d Valid %d Rect [%f,%f,%f,%f] Score %f\r\n", tmpindex,
				context->temp_boxs[tmpindex].valid, context->temp_boxs[tmpindex].x1, context->temp_boxs[tmpindex].y1,
				context->temp_boxs[tmpindex].x2, context->temp_boxs[tmpindex].y2, context->temp_boxs[tmpindex].score);
		}
	} */

	return box_count;
}

static int detect_pnet_object_splice_opt(SAMPLE_CONTEXT_T* context, ArCdnnOutputBuffer* prob, ArCdnnOutputBuffer* conv, int outside, float scale,
	                                               float prob_threshold,float nms_threshold,int x0,int y0,int tile_w, int tile_h)
{
	int   inside = 2 * outside + 11;
	float stride = 0.0;
	if (outside != 1)
	{
		stride = (float)(inside - 12) / (outside - 1);
		// my view -- Not good!
		//stride = (float)((2 * outside + 10) - 1 ) / (outside - 1);//???
	}

	int width_index = 0, height_index = 0;

	int data_offset = prob->width * prob->height;
	int planesize   = conv->width * conv->height;

	int begin_box_count = context->temp_box_count;
	int begin_score_count = context->temp_score_count;

	int box_count = 0;
	int order_count = 0;

	float x1, y1, x2, y2;
	for (width_index = 0; width_index < tile_w; width_index++)
	{
		for (height_index = 0; height_index < tile_h; height_index++)
		{
			int dataIndex = width_index +x0 + (height_index+y0) * prob->width;
			float pconf = ((float*)(prob->pdata))[data_offset + dataIndex];
			if (pconf >= prob_threshold)
			{
				SAMPLE_RECTBOX_T box = { 0 };
				#if(0)
				//same with Caffe
				float original_x1 = (float)(int)((width_index * stride + 0) * scale);
				float original_y1 = (float)(int)((height_index * stride + 0) * scale);
				float original_x2 = (float)(int)((width_index * stride + 11) * scale);
				float original_y2 = (float)(int)((height_index * stride + 11) * scale);
				#else
				float original_x1 = ((width_index * stride + 0) * scale);
				float original_y1 = ((height_index * stride + 0) * scale);
				float original_x2 = ((width_index * stride + 11) * scale);
				float original_y2 = ((height_index * stride + 11) * scale);
				#endif

				x1 = ((float*)(conv->pdata))[dataIndex + planesize * 0];
				y1 = ((float*)(conv->pdata))[dataIndex + planesize * 1];
				x2 = ((float*)(conv->pdata))[dataIndex + planesize * 2];
				y2 = ((float*)(conv->pdata))[dataIndex + planesize * 3];

				box.valid = 1;
				// Fix by bwang
#if(0)//#if 1//fixed by wen

				box.x1 = original_x1 + y1 * 12.0 * scale;
				box.y1 = original_y1 + x1 * 12.0 * scale;
				box.x2 = original_x2 + y2 * 12.0 * scale;
				box.y2 = original_y2 + x2 * 12.0 * scale;
				box.score = pconf;
#else
				box.x1 = original_x1 + x1 * 12.0 * scale;
				box.y1 = original_y1 + y1 * 12.0 * scale;
				#if(ADAPT_FOR_RUIWEI)
				box.x2 = original_x1 + x2 * 12.0 * scale;
				box.y2 = original_y1 + y2 * 12.0 * scale;
				#else
				box.x2 = original_x2 + x2 * 12.0 * scale;
				box.y2 = original_y2 + y2 * 12.0 * scale;
				#endif
				box.score = pconf;
#endif
				convert_box_square(&box);

				#if(1)
				box.x1 = sample_max(0, box.x1);
				box.y1 = sample_max(0, box.y1);
				//wen
				box.x2 = sample_min(SOURCE_IMAG_SIZE_W, box.x2);
				box.y2 = sample_min(SOURCE_IMAG_SIZE_H, box.y2);
				#else
				//Same with Caffe
				box.x1 = (int)sample_max(0, box.x1);
				box.y1 = (int)sample_max(0, box.y1);
				box.x2 = (int)sample_min(width, box.x2);
				box.y2 = (int)sample_min(height, box.y2);
				#endif

				calculate_box_area(&box);

				//SAMPLE_DEBUG((&context->profile), "Index %d Post [%d,%d] Rect [%f,%f,%f,%f] Score %f\r\n", box_count, width_index, height_index, box.x1, box.y1, box.x2, box.y2, pconf);
				box_count++;

				if ((box.x2 > box.x1) && (box.y2 > box.y1)){
					// ok
				}
				else{
					//SAMPLE_DEBUG(&context->profile, "Invalid Post [%d,%d] Rect [%f,%f,%f,%f] Score %f\r\n", width_index, height_index, box.x1, box.y1, box.x2, box.y2, pconf);
					continue;
				}

				if (context->temp_box_count >= context->temp_box_size || context->temp_score_count >= context->temp_score_size){
					//SAMPLE_ERROR(NULL, "PNet Box number large than catpacity\r\n");
					continue;
				}

				SAMPLE_RECTBOX_T*  mybox = &context->temp_boxs[context->temp_box_count];
				context->temp_box_count++;
				memcpy(mybox, &box, sizeof(box));

				SAMPLE_ODSCORE_T* myods = &context->temp_scores[context->temp_score_count];
				myods->order = order_count;
				myods->score = pconf;
				context->temp_score_count++;
				order_count++;
			}
		}
	}

	box_count = context->temp_box_count - begin_box_count;

	//SAMPLE_DEBUG(NULL, "PNET Record Before %d, Now %d, Box_count %d\r\n", begin_box_count, context->temp_box_count, box_count);

	int score_count = context->temp_score_count - begin_score_count;

	compute_nms(&context->temp_boxs[begin_box_count], box_count, &context->temp_scores[begin_score_count], score_count, nms_threshold, "iou");

	return box_count;
}


static int _box_compare(const void* item1, const void* item2) {
	SAMPLE_RECTBOX_T* box1 = (SAMPLE_RECTBOX_T*)item1;
	SAMPLE_RECTBOX_T* box2 = (SAMPLE_RECTBOX_T*)item2;

	if (box1->valid > box2->valid){
		return -1;
	}
	else if (box1->valid < box2->valid){
		return 1;
	}

	if (box1->score > box2->score) {
		return -1;
	}
	else if (box1->score < box2->score) {
		return 1;
	}
	return 0;
}

static void sample_sort_boxs_score(SAMPLE_RECTBOX_T* boxs, int box_count)
{
	qsort(boxs, box_count, sizeof(boxs[0]), _box_compare);
}

static int filter_rnet_object(SAMPLE_CONTEXT_T* context, int width, int height, float roi_threshold, float nms_threshold)
{
	int index;
	float h, w;
	float x1, y1, x2, y2;
	float dx1, dx2, dy1, dy2;
	int box_count = 0;
	int score_count = 0;
	SAMPLE_RECTBOX_T* rectangle = NULL;
	SAMPLE_RECTBOX_T* roiboxs = context->temp_boxs;
	int roibox_size = context->temp_box_count;

	for (index = 0; index < roibox_size; index++){
		rectangle = roiboxs[index].parent;
		if (roiboxs[index].score >= roi_threshold){
			SAMPLE_RECTBOX_T box = { 0 };
			x1 = rectangle->x1;
			y1 = rectangle->y1;
			x2 = rectangle->x2;
			y2 = rectangle->y2;

			dx1 = roiboxs[index].x1;
			dy1 = roiboxs[index].y1;
			dx2 = roiboxs[index].x2;
			dy2 = roiboxs[index].y2;

			w = x2 - x1;
			h = y2 - y1;
			box.valid = 1;
			box.x1 = x1 + dx1 * w;
			box.y1 = y1 + dy1 * h;
			#if(ADAPT_FOR_RUIWEI)
			box.x2 = x1 + dx2 * w;
			box.y2 = y1 + dy2 * h;
			#else
			box.x2 = x2 + dx2 * w;
			box.y2 = y2 + dy2 * h;
			#endif
			box.score = roiboxs[index].score;

			convert_box_square(&box);

			#if(1)
			box.x1 = sample_max(0, box.x1);
			box.y1 = sample_max(0, box.y1);
			box.x2 = sample_min(width, box.x2);
			box.y2 = sample_min(height, box.y2);
			#else
			//same with Caffe
			box.x1 = (int)sample_max(0, box.x1);
			box.y1 = (int)sample_max(0, box.y1);
			box.x2 = (int)sample_min(width, box.x2);
			box.y2 = (int)sample_min(height, box.y2);
			#endif

			calculate_box_area(&box);

			if ((box.x2 > box.x1) && (box.y2 > box.y1)){
				// ok;
			}
			else{
				continue;
			}

			SAMPLE_RECTBOX_T* mybox = &context->temp_boxs[box_count];
			box_count++;
			memcpy(mybox, &box, sizeof(box));

			SAMPLE_ODSCORE_T* myods = &context->temp_scores[score_count];
			myods->order = score_count;
			myods->score = box.score;
			score_count++;
		}
	}

	compute_nms(context->temp_boxs, box_count, context->temp_scores, score_count, nms_threshold, "iou");

	sample_sort_boxs_score(context->temp_boxs, box_count);
	int box_index = 0, count = 0;
	for (box_index = 0; box_index < box_count; box_index++){
		if (context->temp_boxs[box_index].valid){
			count++;
		}
	}

	context->box_count = count;
	memcpy(context->boxs, context->temp_boxs, sizeof(SAMPLE_RECTBOX_T)* count);

	if (BOXES_SORT_PRINT){
		for (box_index = 0; box_index < box_count; box_index++){
			AR_PRINTF_DEBUG("RNET Index %d, Valid %d, Rect [%f,%f,%f,%f], Score %f\r\n", box_index, context->temp_boxs[box_index].valid,
				context->temp_boxs[box_index].x1, context->temp_boxs[box_index].y1, context->temp_boxs[box_index].x2, context->temp_boxs[box_index].y2, context->temp_boxs[box_index].score);
		}
	}

	return count;
}

static int filter_onet_object(SAMPLE_CONTEXT_T* context, int width, int height, float roi_threshold, float nms_threshold)
{
	int index, tmpindex;
	float h, w;
	float x1, y1, x2, y2;
	float dx1, dx2, dy1, dy2;
	int box_count = 0;
	int fea_count = 0;
	int score_count = 0;
	SAMPLE_RECTBOX_T* rectangle = NULL;
	SAMPLE_RECTBOX_T* roiboxs = context->temp_boxs;
	int roibox_size = context->temp_box_count;

	for (index = 0; index < roibox_size; index++)
	{
		if (roiboxs[index].score >= roi_threshold)
		{
			rectangle = roiboxs[index].parent;

			SAMPLE_RECTBOX_T box = { 0 };
			SAMPLE_FEATURE_T feature = { 0 };
			x1 = rectangle->x1;
			y1 = rectangle->y1;
			x2 = rectangle->x2;
			y2 = rectangle->y2;

			dx1 = roiboxs[index].x1;
			dy1 = roiboxs[index].y1;
			dx2 = roiboxs[index].x2;
			dy2 = roiboxs[index].y2;

			w = x2 - x1;
			h = y2 - y1;

			for (tmpindex = 0; tmpindex < 5; tmpindex++)
			{
				feature.records[tmpindex].x = w * roiboxs[index].feature->records[tmpindex].x + x1;
				feature.records[tmpindex].y = h * roiboxs[index].feature->records[tmpindex].y + y1;

			}

			box.valid = 1;
			box.x1 = x1 + dx1 * w;
			box.y1 = y1 + dy1 * h;
			#if(ADAPT_FOR_RUIWEI)
			box.x2 = x1 + dx2 * w;
			box.y2 = y1 + dy2 * h;
			#else
			box.x2 = x2 + dx2 * w;
			box.y2 = y2 + dy2 * h;
			#endif
			box.score = roiboxs[index].score;

			#if(1)
			box.x1 = sample_max(0, box.x1);
			box.y1 = sample_max(0, box.y1);
			box.x2 = sample_min(width, box.x2);
			box.y2 = sample_min(height, box.y2);
			#else
			//Same with Caffe
			box.x1 = (int)sample_max(0, box.x1);
			box.y1 = (int)sample_max(0, box.y1);
			box.x2 = (int)sample_min(width, box.x2);
			box.y2 = (int)sample_min(height, box.y2);
			#endif

			calculate_box_area(&box);

			if ((box.x2 > box.x1) && (box.y2 > box.y1)){
				// ok;
			}
			else{
				continue;
			}

			SAMPLE_FEATURE_T* myfea = &context->features[fea_count];
			fea_count++;
			memcpy(myfea, &feature, sizeof(feature));

			SAMPLE_RECTBOX_T* mybox = &context->temp_boxs[box_count];
			box_count++;
			memcpy(mybox, &box, sizeof(box));
			mybox->feature = myfea;

			SAMPLE_ODSCORE_T* myods = &context->temp_scores[score_count];
			myods->order = score_count;
			myods->score = box.score;
			score_count++;
		}
	}

	compute_nms(context->temp_boxs, box_count, context->temp_scores, score_count, nms_threshold, "iom");

	sample_sort_boxs_score(context->temp_boxs, box_count);
	int box_index = 0, count = 0;
	for (box_index = 0; box_index < box_count; box_index++){
		if (context->temp_boxs[box_index].valid){
			count++;
		}
	}

	context->box_count = count;
	memcpy(context->boxs, context->temp_boxs, sizeof(SAMPLE_RECTBOX_T)* count);


	if (0){
		for (box_index = 0; box_index < box_count; box_index++){
			AR_PRINTF_DEBUG("ONET Index %d, Valid %d, Rect [%f,%f,%f,%f], Score %f\r\n", box_index, context->temp_boxs[box_index].valid,
				context->temp_boxs[box_index].x1, context->temp_boxs[box_index].y1, context->temp_boxs[box_index].x2, context->temp_boxs[box_index].y2, context->temp_boxs[box_index].score);
		}
	}

	return count;
}


static inline void calculate_min_rectangle(SAMPLE_RECTBOX_T* target, int x, int y, int width, int height) {
	int x1 = (int)(sample_max(target->x1, x) + 0.5);
	int y1 = (int)(sample_max(target->y1, y) + 0.5);
	int twidth = (sample_min(target->x1 + target->width, x + width) - x1 + 1);
	int theight = (sample_min(target->y1 + target->height, y + height) - y1 + 1);

	target->x1 = x1;
	target->y1 = y1;
	target->width = twidth;
	target->height = theight;
	target->x2 = x1 + twidth - 1;
	target->y2 = y1 + theight - 1;
}

static int mtcnn_process_ronet_opt(AR_DSP_ALG_st* dsp_alg_ptr, AR_DSP_OUTPUT_st* dsp_out_ptr, SAMPLE_CONTEXT_T* context, SAMPLE_PICTURE_T* source_image, SAMPLE_PICTURE_T* picture, int width, int height, int comb_num_x, int max_net_num )
{
	int index, ret;

	unsigned long ROpre_start, ROinf_start, ROinf_end;

	/*
	SAMPLE_PICTURE_T picture = {0};
	picture.buffer  = (unsigned char*)context->pixel_buffer;
	picture.size    = context->pixel_buffer_size;
	picture.width   = width_num * 24;
	picture.height  = width_num * 24;
	picture.channel = source_image->channel;
	*/

	SAMPLE_PICATTR_T picattr = {0};
	picattr.width   = width;
	picattr.height  = height;
	picattr.channel = source_image->channel;

	MEASURE_TIME(ROpre_start);
	/*
	SAMPLE_PICTURE_T  temp_image = {0};
	temp_image.buffer = (unsigned char *)(context->temp_buffer);
	temp_image.size   = context->temp_buffer_size;
	*/
	context->temp_box_count = 0;
	context->temp_score_count = 0;
	context->temp_feature_count = 0;

	//wen-opt: multiple rnets/onets
	int net_box_num    = comb_num_x * comb_num_x;
	//int max_box_num    = net_box_num * max_net_num;
	context->box_count = sample_min(context->box_count, net_box_num * max_net_num );

	int total_box_cnt = 0;
	int res_box_num = context->box_count;

	for (int net_index=0; net_index < max_net_num; net_index++)
	{

		res_box_num -= (net_index * net_box_num);
		int loop_count = sample_min(res_box_num, net_box_num);
		loop_count = sample_max(loop_count, 0);

		int index_re = 0;

		for (index = 0; index < loop_count; index++)
		{
			int box_index = (net_index * net_box_num) + index;
			if (box_index >= context->box_count)
			{
				break;
			}

			if (context->boxs[box_index].valid)
			{
				SAMPLE_RECTBOX_T* cropbox = &context->boxs[box_index];

				#if(BOX_MINU_ADJUST)
				sample_image_calc_resolution(cropbox);
				int size = (cropbox->width + cropbox->height) * 0.5;
				int cx = cropbox->x1 + cropbox->width * 0.5;
				int cy = cropbox->y1 + cropbox->height * 0.5;
				cropbox->x1 = cx - size * 0.5;
				cropbox->y1 = cy - size * 0.5;
				cropbox->width = size;
				cropbox->height = size;

				calculate_min_rectangle(cropbox, 0, 0, source_image->width, source_image->height);
				#endif

				if (cropbox->width <= 0 || cropbox->height <= 0)
				{
					cropbox->valid = 0;
					continue;
				}

#if (0)
				//if(sample_image_crop_fast_opt(source_image, cropbox, &swaped, 0) != 0)
				if(sample_image_crop_easy(source_image, cropbox, &swaped) != 0)
				{
					cropbox->valid = 0;
					continue;
				}

				int place_w = (index_re % comb_num_x) * picattr.width;
				int place_h = (index_re / comb_num_x) * picattr.height;

				//sample_image_resize_trans_fast_opt( &swaped, &picattr, &picture, &temp_image, place_w, place_h, 0 );
				sample_image_resize_easy_opt(&swaped, &picattr, picture, place_w, place_h);
#else

				int place_w = (index_re % comb_num_x) * picattr.width;
				int place_h = (index_re / comb_num_x) * picattr.height;

				//sample_image_resize_trans_fast_opt( &swaped, &picattr, &picture, &temp_image, place_w, place_h, 0 );
				//sample_image_resize_easy_opt(&swaped, &picattr, picture, place_w, place_h);

				if(sample_image_crop_resize_easy(source_image, cropbox, &picattr, picture, place_w, place_h) != 0)
				{
					cropbox->valid = 0;
					continue;
				}
#endif
				index_re+=1;
			}
		}


		/*
		status |= arCdnnDetectProcess(context->rnet_detect_handle);
		//SAMPLE_TRACE(profile, "XNet Detect Process Result %x\r\n", status);
		AR_ASSERT(status == 0);

		output_count = arCdnnGetResultTailsNum(context->rnet_detect_handle);
		status |= arCdnnGetResultBuffers(context->rnet_detect_handle, context->output_buffers);
		AR_ASSERT(status == 0);
		*/
		//wen: clear the output buffer
		memset(dsp_out_ptr, 0, sizeof(ArCdnnOutputBuffer));
        int net_id = dsp_alg_ptr->alg_type;


		MEASURE_TIME(ROinf_start);
		AR_PRINTF_DEBUG("[DSP%d]RO pre : %ld ms\r\n", dsp_alg_ptr->dsp_id, ROinf_start - ROpre_start);

		ret = ar_do_algrithom(dsp_alg_ptr);
		if(ret < 0)
		{
			AR_PRINTF_ERR("Error calling ar_do_algrithom: %d\r\n",ret);
			return -1;
		}

		MEASURE_TIME(ROinf_end);
		AR_PRINTF_DEBUG("[DSP%d]ROinf : %ld ms\r\n", dsp_alg_ptr->dsp_id, ROinf_end - ROinf_start);

		dsp_alg_ptr->alg_type = net_id;

		ArCdnnOutputBuffer* cls_box = NULL, *loc_box = NULL, *pts_box = NULL;
		int output_index = 0;
		for (output_index = 0; output_index < dsp_out_ptr->buffer_num; output_index++)
		{
			if (strcmp(dsp_out_ptr->output_buffer[output_index].buffer_name, "prob1") == 0)
			{
				cls_box = &(dsp_out_ptr->output_buffer[output_index]);

			}
			else if (strcmp(dsp_out_ptr->output_buffer[output_index].buffer_name, "conv5-2") == 0)
			{
				loc_box = &(dsp_out_ptr->output_buffer[output_index]);

			}
			else if (strcmp(dsp_out_ptr->output_buffer[output_index].buffer_name, "conv6-2") == 0)
			{
				loc_box = &(dsp_out_ptr->output_buffer[output_index]);

			}
			else if (strcmp(dsp_out_ptr->output_buffer[output_index].buffer_name, "conv6-3") == 0)
			{
				pts_box = &(dsp_out_ptr->output_buffer[output_index]);

			}
		}

		if (cls_box == NULL || loc_box == NULL)
		{
			AR_PRINTF_ERR("MAY BE ERROR WHEN GET THE OUTPUT!\r\n");
			return -1;
		}

		//int elem_span = 2;
		int elem_span = 3;
		int out_len = elem_span * (comb_num_x - 1) + 1;
		int PlaneSize = out_len * out_len;
		int place_w, place_h, siteInPlane;

		index_re=0;

		for (index=0; index < loop_count; index++)
		{
			int box_index = (net_index * net_box_num) + index;
			if (box_index >= context->box_count)
			{
				break;
			}

			if ( context->boxs[box_index].valid )
			{
				SAMPLE_RECTBOX_T* box = &context->temp_boxs[context->temp_box_count];
				context->temp_box_count++;
				place_w=index_re % comb_num_x;
				place_h=index_re / comb_num_x;
				box->valid = 1;

				siteInPlane   = place_w*elem_span+place_h*out_len*elem_span;

				box->score = ((float *)(cls_box->pdata))[siteInPlane + PlaneSize*1];

				box->x1 = ((float *)(loc_box->pdata))[siteInPlane + PlaneSize*0];
				box->y1 = ((float *)(loc_box->pdata))[siteInPlane + PlaneSize*1];
				box->x2 =  ((float *)(loc_box->pdata))[siteInPlane + PlaneSize*2];
				box->y2 =  ((float *)(loc_box->pdata))[siteInPlane + PlaneSize*3];

				box->parent = &(context->boxs[box_index]);

				//AR_PRINTF_DEBUG("RNET Output Index %d, Rect [%f,%f,%f,%f], Socre %f\r\n",
				//context->temp_box_count, box->x1, box->y1, box->x2, box->y2, box->score);

				if ( pts_box != NULL )
				{
					SAMPLE_FEATURE_T* fea = &(context->temp_features[context->temp_feature_count]);
					context->temp_feature_count++;
					int markIdx;
					for (markIdx = 0; markIdx < 5; markIdx++)
					{
						fea->records[markIdx].x = ((float*)(pts_box->pdata))[siteInPlane + PlaneSize * markIdx];
						fea->records[markIdx].y = ((float*)(pts_box->pdata))[siteInPlane + PlaneSize * (markIdx + 5)];
					}
					box->feature = fea;
				}
				///////////////////////////////////////////////////////////////////////////////*/

				//AR_PRINT("rnet print  %f, [%f,%f] [%f,%f] \r\n",box->score, box->x1, box->y1, box->x2, box->y2);
				index_re++;
			}
		}

		//
		total_box_cnt += net_box_num;
		if (total_box_cnt >= context->box_count)
		{
			break;
		}

	}

	//AR_PRINT("Rnet finish!  %d\r\n",context->temp_box_count);
	return context->temp_box_count;
}

using namespace cv;
using namespace std;
using namespace libyuv;

void * pthread_run_mtcnn_test(void *arg)
{
	SAMPLE_RECTBOX_T  mtcnn_boxes[MAX_RECTBOX_SIZE];
	SAMPLE_ODSCORE_T  mtcnn_scores[MAX_RECTBOX_SIZE];
	SAMPLE_FEATURE_T  mtcnn_features[MAX_FEATURE_SIZE];
	SAMPLE_RECTBOX_T  mtcnn_temp_boxes[MAX_RECTBOX_SIZE];
	SAMPLE_ODSCORE_T  mtcnn_temp_scores[MAX_RECTBOX_SIZE];
	SAMPLE_FEATURE_T  mtcnn_temp_features[MAX_FEATURE_SIZE];

	AR_DSP_ALG_st * p_dsp_alg = 0;
	THREAD_PARAM_st * p_t_param = 0;

	AR_DSP_DETECT_RESULTS_st detect_results = {0};
	AR_POINT_st points[5] = {0};
	layer_user_t osd_layer = {0};

	int ret = 0;
	int input_len[AR_DSP_ALG_MAX_INPUT_NUM] = {0};
	unsigned char * input_va[AR_DSP_ALG_MAX_INPUT_NUM] = {0};
	unsigned char * input_pa[AR_DSP_ALG_MAX_INPUT_NUM] = {0};

	int output_pdata_len = 0;

	unsigned char * output_pdata_va = 0;
	unsigned char * output_pdata_pa = 0;
	unsigned char * sram_addr_va = 0;
	unsigned char * sram_addr_pa = 0;

	int i = 0;
	int dsp_id = 0;
	unsigned long long frame_id = 0;
	unsigned char * ext_mem_addr_va = 0;
	unsigned char * ext_mem_addr_pa = 0;

	AR_DSP_CFG_st  * p_dsp_cfg = 0;

	unsigned long start_time = 0;
	//measure time
	unsigned long  total_start = 0, gimg_start = 0, gimg_end = 0, total_end = 0;
	unsigned long  P0pre_start = 0, P0inf_start = 0, P0post_start = 0, P0post_end = 0;
	unsigned long  P1pre_start = 0, P1inf_start = 0, P1post_start = 0, P1post_end = 0;
	unsigned long  P01_start = 0, P01_end = 0;
	unsigned long  Rpost_start = 0, Rpost_end = 0, Opost_start = 0, Opost_end = 0;

	int net_id_0 = 0;
	int net_id_1 = 0;

	struct dirent ** in_file;
	char file_name[FILE_PATH_STR_LEN];

	char result_file_name_onet[FILE_PATH_STR_LEN];

	char ini_file_name[FILE_PATH_STR_LEN];
	int file_type = INVALID_IMG_FILE;

	unsigned long long frame_processed = 0;
	int scandir_num = 0;
	int scandir_count = 0;

	SAMPLE_CONTEXT_T  mtcnn_context = {0};
	SAMPLE_CONTEXT_T* context = &mtcnn_context;
	SAMPLE_PICTURE_T source_img = {0};
	SAMPLE_PICTURE_T input_pic  = {0};

	int box_countP = 0;
	int box_countR = 0;
	unsigned int all_box_cnt = 0;
	unsigned int succ_detect_cnt = 0;

	float _box_threshold[AR_DSP_ALG_MAX_NN_PER_DSP] = { 0.6, 0.6, 0.6, 0.6, 0 };
    float _nms_threshold[AR_DSP_ALG_MAX_NN_PER_DSP] = { 0.7, 0.7, 0.7, 0.7, 0 };

	context->box_size = MAX_RECTBOX_SIZE;
	context->boxs = &(mtcnn_boxes[0]);
	context->score_size = MAX_RECTBOX_SIZE;
	context->scores = &(mtcnn_scores[0]);
	context->feature_size = MAX_FEATURE_SIZE;
	context->features = &(mtcnn_features[0]);
	context->temp_box_size = MAX_RECTBOX_SIZE;
	context->temp_boxs = &(mtcnn_temp_boxes[0]);
	context->temp_score_size = MAX_RECTBOX_SIZE;
	context->temp_scores = &(mtcnn_temp_scores[0]);
	context->temp_feature_size = MAX_FEATURE_SIZE;
	context->temp_features = &(mtcnn_temp_features[0]);


	p_t_param = (THREAD_PARAM_st *)arg;

	struct img_list * entry_ptr = NULL;
	cv::Mat dst_img;

	ar_ion_init(AR_DSP_HEAP_ID);

	dsp_id = p_t_param->dsp_id;
	AR_PRINTF_DEBUG("[DSP%d]Start running mtcnn...\r\n", dsp_id);

	p_dsp_cfg = (AR_DSP_CFG_st *)malloc(sizeof(*p_dsp_cfg));
	if (!p_dsp_cfg)
	{
		AR_PRINTF_ERR("Malloc dsp cfg failed.\r\n");
		goto _free_and_exit;
	}
	memset(p_dsp_cfg, 0, sizeof(*p_dsp_cfg));

	p_dsp_alg = (AR_DSP_ALG_st *)malloc(sizeof(*p_dsp_alg));
	if (!p_dsp_alg)
	{
		AR_PRINTF_ERR("Malloc dsp alg failed.\r\n");
		goto _free_and_exit;
	}
	memset(p_dsp_alg, 0, sizeof(*p_dsp_alg));

	//Malloc input buffer, shared by all networks
	for(i = 0; i < AR_DSP_ALG_MAX_INPUT_NUM; i++)
	{
		input_len[i] = ar_get_max_input_len(p_t_param, i);
		if(input_len[i] <= 0)
		{
			continue;
		}

		AR_PRINTF_DEBUG("[DSP%d]Malloc input buf len %d\r\n", dsp_id, input_len[i]);
		AR_GET_ION_MEMORY(input_va[i], input_pa[i], input_len[i]);
		AR_PRINTF_DEBUG("[DSP%d]Input va %x pa %x\r\n", dsp_id, (unsigned int)input_va[i], (unsigned int)input_pa[i]);
	}

	//Malloc output pdata buffer for dsp, make sure the buffer is big enough
	//it can be shared by all networks
	output_pdata_len = ar_get_max_pdata_len(p_t_param);
	AR_PRINTF_DEBUG("[DSP%d]Malloc output pdata buf len %d\r\n", dsp_id, output_pdata_len);
	AR_GET_ION_MEMORY(output_pdata_va, output_pdata_pa, output_pdata_len);
	AR_PRINTF_DEBUG("[DSP%d]Output_pdata va %x pa %x\r\n", dsp_id, (unsigned int)output_pdata_va, (unsigned int)output_pdata_pa);

	//Malloc ext memory for cdnn lib
	AR_PRINTF_DEBUG("[DSP%d]Malloc ext mem len %d\r\n", dsp_id, p_t_param->cdnn_ext_mem_size);
	AR_GET_ION_MEMORY(ext_mem_addr_va, ext_mem_addr_pa, p_t_param->cdnn_ext_mem_size);
	AR_PRINTF_DEBUG("[DSP%d]Ext va %x pa %x\r\n", dsp_id, (unsigned int)ext_mem_addr_va, (unsigned int)ext_mem_addr_pa);

	//check if sram is configured
	if(!p_t_param->cdnn_sram_heap_start && p_t_param->cdnn_sram_heap_size)
	{
		AR_GET_ION_MEMORY(sram_addr_va, sram_addr_pa, p_t_param->cdnn_sram_heap_size);
		p_t_param->cdnn_sram_heap_start = (unsigned long)sram_addr_pa;
	}

	AR_PRINTF_DEBUG("[DSP%d]Sram pa %lx size 0x%lx\r\n", dsp_id, p_t_param->cdnn_sram_heap_start, p_t_param->cdnn_sram_heap_size);

#ifdef USER_DEFINED_TEST
	unsigned char * user_test_va = 0;
	unsigned char * user_test_pa = 0;

	//Malloc user defined data, only for test
	AR_GET_ION_MEMORY(user_test_va, user_test_pa, sizeof(AR_USR_DATA_TEST_st));
	((AR_USR_DATA_TEST_st *)user_test_va)->input_param = 0x1234;
	((AR_USR_DATA_TEST_st *)user_test_va)->return_val = 0;
#endif

	//if I need load weight file ?
	if(g_sys_cfg.who_load_weight_data == p_t_param->dsp_id || g_sys_cfg.who_load_weight_data == -1)
	{
		ret = ar_prepare_weight_file(p_t_param->dsp_id, p_t_param->ini_cnn_cfg);
		if(ret < 0)
		{
			AR_PRINTF_ERR("[DSP%d]Prepare weight file error!\r\n", dsp_id);
			goto _free_and_exit;
		}
	}
	else
	{
		ret = ar_copy_weight_load_addr(g_sys_cfg.who_load_weight_data, p_t_param->ini_cnn_cfg);
		if(ret < 0)
		{
			AR_PRINTF_ERR("[DSP%d]Prepare weight file error!\r\n", dsp_id);
			goto _free_and_exit;
		}
	}

	//set the parameters and send to dsp
	for(i = 0; i < AR_DSP_ALG_MAX_NN_PER_DSP; i++)
	{
		memcpy(&p_dsp_cfg->cnn_cfg[i], &p_t_param->ini_cnn_cfg[i].cnn_cfg, sizeof(AR_DSP_CNN_CFG_st));
		if(p_dsp_cfg->cnn_cfg[i].network_id)
		{
			AR_PRINTF_DEBUG("[DSP%d]DSP Cfg %d : network id: %d\r\n",dsp_id, i, p_dsp_cfg->cnn_cfg[i].network_id);
			p_dsp_cfg->cnn_cfg[i].input_buf[0] = (unsigned long)input_pa[0];
			p_dsp_cfg->cnn_cfg[i].input_buf[1] = (unsigned long)input_pa[1];
			p_dsp_cfg->cnn_cfg[i].input_buf[2] = (unsigned long)input_pa[2];
			p_dsp_cfg->cnn_cfg[i].input_buf[3] = (unsigned long)input_pa[3];

			p_dsp_cfg->cnn_cfg[i].buffer_pa_for_pdata = (unsigned long)output_pdata_pa;
			p_dsp_cfg->cnn_cfg[i].buffer_va_for_pdata = (unsigned long)output_pdata_va;

			_box_threshold[i] = p_t_param->ini_cnn_cfg[i].cnn_cfg.output_threshold;
		}
	}

	p_dsp_cfg->cdnn_sram_heap_start = p_t_param->cdnn_sram_heap_start;
	p_dsp_cfg->cdnn_sram_heap_size = p_t_param->cdnn_sram_heap_size;
	p_dsp_cfg->cdnn_ext_mem_addr = (unsigned long)ext_mem_addr_pa;
	p_dsp_cfg->cdnn_ext_mem_size = p_t_param->cdnn_ext_mem_size;
	p_dsp_cfg->dsp_log_level = g_sys_cfg.loglevel;

#ifdef USER_DEFINED_TEST
	//only for user cfg test
	p_dsp_cfg->user_cfg[0].operation_id = 0x1234;
	p_dsp_cfg->user_cfg[0].params = user_test_pa;
#endif

	AR_PRINTF_DEBUG("[DSP%d]Configuring DSP...\r\n", dsp_id);
	ret = ar_alg_cfg_dsp(p_t_param->dsp_id, (char *)p_dsp_cfg, sizeof(*p_dsp_cfg));
	if(ret < 0)
	{
		AR_PRINTF_ERR("[DSP%d]Configuration failed!\r\n", dsp_id);
		goto _free_and_exit;
	}
	AR_PRINTF_DEBUG("[DSP%d]Configuration succeed!\r\n", dsp_id);


	//open local image list, in this demo, we get an image and pass the results to next network, save to one file finally.
	if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_LOCAL_FILE)
	{

        scandir_num = scandir( p_t_param->ini_cnn_cfg[0].local_img_directory, &in_file, 0, ar_alphasort);
		AR_PRINTF_DEBUG("[DSP%d] ini %s\r\n", dsp_id, p_t_param->inifile);
		ret = cut_ini_file_name(p_t_param->inifile, ini_file_name);
		if(ret < 0)
		{
			strcpy(ini_file_name, "unknown");
		}

		snprintf(result_file_name_onet, FILE_PATH_STR_LEN, "%s%s_results_dsp%d.txt", p_t_param->ini_cnn_cfg[0].local_img_directory, ini_file_name, dsp_id);
		if(access(result_file_name_onet, F_OK) != -1)
		{
			remove(result_file_name_onet);
		}

	}

	AR_PRINTF_DEBUG("[DSP%d]== Start process ==\r\n", dsp_id);
	MEASURE_TIME(start_time);

	p_dsp_alg->input[0].size = input_len[0];
	p_dsp_alg->input[0].rgbbuff = (char *)input_pa[0];

	input_pic.size = input_len[0];
	input_pic.buffer = (unsigned char *)input_va[0];

    if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_LOCAL_FILE)
	{
		source_img.size = input_len[0];
		source_img.buffer  = (unsigned char *)malloc(source_img.size);

		if(!(source_img.buffer))
		{
			AR_PRINTF_ERR("Malloc image buffer error!\r\n");
			goto _free_and_exit;
		}
		memset(source_img.buffer, 0, source_img.size);
    }

	memset(&p_dsp_alg->cv_ops, 0, sizeof(p_dsp_alg->cv_ops));
	memset(&p_dsp_alg->output, 0, sizeof(p_dsp_alg->output));
	MEASURE_TIME(total_start);

	while(1)
	{
		if(g_app_quit_flag) break;

		MEASURE_TIME(gimg_start);

		if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_LOCAL_FILE)
		{
			if(scandir_count == scandir_num)
			{
				break;
			}

			//currently, we don't support recursive DIR
			if(in_file[scandir_count]->d_type != DT_REG)
			{
				free(in_file[scandir_count]);
				scandir_count ++;
				continue;
			}

			snprintf(file_name, FILE_PATH_STR_LEN, "%s%s", p_t_param->ini_cnn_cfg[0].local_img_directory, in_file[scandir_count]->d_name);
			printf("%s%s \r\n", p_t_param->ini_cnn_cfg[0].local_img_directory, in_file[scandir_count]->d_name);
            free(in_file[scandir_count]);
			scandir_count++;

			file_type = get_image_file_type(file_name);

			if(file_type == RGB_RAW_DATA_FILE || file_type == BGR_RAW_DATA_FILE)
			{
				ret = ar_load_file(file_name, (char *)source_img.buffer, 0);
				if(ret < 0)
				{
					AR_PRINTF_ERR("Load file error: %s\r\n", file_name);
					continue;
				}

				source_img.width   = SOURCE_IMAG_SIZE_W;
				source_img.height  = SOURCE_IMAG_SIZE_H;

			}
			else if(file_type == JPG_BMP_PNG_IMG_FILE)
			{
				dst_img = cv::imread(file_name);
				if(dst_img.empty())
				{
				   AR_PRINTF_ERR("[DSP%d]Imread file failed!\r\n", dsp_id);
				   continue;
				}
				//memcpy(source_img.buffer, dst_img.data, dst_img.rows * dst_img.cols * dst_img.channels());
				source_img.buffer = (unsigned char*)dst_img.data;
				source_img.width   = dst_img.cols;
				source_img.height  = dst_img.rows;
			}
			else
			{
				continue;
			}

		}
		else //sensor mode, DSP will convert YUV to RGB if format = AR_DSP_IMG_FMT_YUV
		{
			entry_ptr = ar_get_img_from_list();
			if(!entry_ptr)
            {
                 continue;
			}

			source_img.buffer  = entry_ptr->img.data;
			source_img.width   = entry_ptr->img.cols;
			source_img.height  = entry_ptr->img.rows;


			memcpy(input_va[0],(unsigned char*)entry_ptr->rsz_img.data, entry_ptr->rsz_img.cols*entry_ptr->rsz_img.rows*entry_ptr->rsz_img.channels());

			frame_id = entry_ptr->frame_id;
			frame_processed++;

		}

		MEASURE_TIME(gimg_end);
		AR_PRINTF_DEBUG("[DSP%d]get_img : %ld ms\r\n", dsp_id, gimg_end - gimg_start);

		memset(&osd_layer, 0, sizeof(osd_layer));
		memset(&detect_results, 0, sizeof(detect_results));

		context->temp_box_count = 0;
		context->temp_score_count = 0;
		context->temp_feature_count = 0;
		int all_box_count = 0;
		int all_score_count = 0;


		{ //pnet0
			MEASURE_TIME(P0pre_start);

           // memset(&detect_results, 0, sizeof(detect_results));
			p_dsp_alg->dsp_id = p_t_param->dsp_id;
			p_dsp_alg->alg_type = p_dsp_cfg->cnn_cfg[0].network_id;

			p_dsp_alg->input[0].width = p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].width;
			p_dsp_alg->input[0].height =  p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].height;
			p_dsp_alg->input[0].channel =  p_t_param->ini_cnn_cfg[0].cnn_cfg.input_params[0].nChannels;
			p_dsp_alg->input[0].format = p_t_param->ini_cnn_cfg[0].cnn_cfg.input_format[0];

			source_img.dynamic = 0;
			source_img.channel = p_dsp_alg->input[0].channel;
			source_img.stride = source_img.width * source_img.channel;
			source_img.format = p_dsp_alg->input[0].format;

			if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_LOCAL_FILE)
			{

				SAMPLE_PICATTR_T  attr = {0};
				attr.channel = p_dsp_alg->input[0].channel;
				attr.width	 = p_dsp_alg->input[0].width;
				attr.height  = p_dsp_alg->input[0].height;
				//memset(input_pic.buffer, 0, input_pic.size);
				sample_image_resize_easy(&source_img, &attr, &input_pic);
			}

			MEASURE_TIME(P0inf_start);
			AR_PRINTF_DEBUG("[DSP%d]p0 pre : %ld ms\r\n", dsp_id, P0inf_start - P0pre_start);

			net_id_0 = p_dsp_alg->alg_type;

			ret = ar_do_algrithom(p_dsp_alg);
			if(ret < 0)
			{
				AR_PRINTF_ERR("[DSP%d]Error calling ar_do_algrithom: %d, quit!\r\n", dsp_id, ret);
				goto _free_and_exit;
			}
			if(p_dsp_alg->exit_code < 0)
			{
				AR_PRINTF_ERR("[DSP%d]DSP returns %d, continue...\r\n!\r\n", dsp_id, p_dsp_alg->exit_code);
				ar_update_osd(g_osd_fd, &osd_layer);
				if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_SENSOR_IMG)
				{
					ar_release_img_to_list(entry_ptr);
					entry_ptr = NULL;
				}
				continue;
			}

			MEASURE_TIME(P0post_start);
			AR_PRINTF_DEBUG("[DSP%d]p0 infere : %ld ms\r\n", dsp_id, P0post_start - P0inf_start);

			p_dsp_alg->alg_type = net_id_0;

			AR_DSP_OUTPUT_st *pOutput = (AR_DSP_OUTPUT_st *)&p_dsp_alg->output;
			ArCdnnOutputBuffer* cls_box = NULL, *loc_box = NULL;
			for (int output_index = 0; output_index < pOutput->buffer_num; output_index++)
			{
				if (strcmp(pOutput->output_buffer[output_index].buffer_name, "prob1") == 0)
				{
					cls_box = &(pOutput->output_buffer[output_index]);
				}
				else if (strcmp(pOutput->output_buffer[output_index].buffer_name, "conv4-2") == 0)
				{
					loc_box = &(pOutput->output_buffer[output_index]);
				}
			}

			if (cls_box != NULL && loc_box != NULL)
			{
				int outside = sample_max(cls_box->width, cls_box->height);
				float scaler = SOURCE_IMAG_SIZE_W * 1.0 / PNET_ORG_SIZE_140x84_W;
				detect_pnet_object(context, cls_box, loc_box, outside, scaler, _box_threshold[0], 0.5 /*for individual pnet NMS*/);
			}

			if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_STATS)
			{
				AR_PRINTF_DEBUG("[DSP%d] P0net : \r\n", dsp_id);
				ar_dump_statistics(dsp_id, &p_dsp_alg->statistics);
			}

			MEASURE_TIME(P0post_end);
			AR_PRINTF_DEBUG("[DSP%d]p0 post : %ld ms\r\n", dsp_id, P0post_end - P0post_start);
		}


		{ //pnet1

			//memset(&detect_results, 0, sizeof(detect_results));
			MEASURE_TIME(P1pre_start);

			p_dsp_alg->dsp_id = p_t_param->dsp_id;
			p_dsp_alg->alg_type = p_dsp_cfg->cnn_cfg[1].network_id;

			p_dsp_alg->input[0].width = p_t_param->ini_cnn_cfg[1].cnn_cfg.input_params[0].width;
			p_dsp_alg->input[0].height =  p_t_param->ini_cnn_cfg[1].cnn_cfg.input_params[0].height;
			p_dsp_alg->input[0].channel =	p_t_param->ini_cnn_cfg[1].cnn_cfg.input_params[0].nChannels;
			p_dsp_alg->input[0].format = p_t_param->ini_cnn_cfg[1].cnn_cfg.input_format[0];

			int PLICE_NUM=6;

			int plice_site[6][2]={{0,0},{0,84},{80,84},{0,144},{60,144},{60,174}};
			int plice_size[6][2]={{112,84},{80,60},/*{28,22}*/{28,20},{60,45},{40,30},{20,15}};

			int out_site[6][2]={{0,0},{0,42},{40,42},{0,72},{30,72},{30,87}};
			int out_size[6][2]={{51,37},{35,25},/*{9,6}*/{9,5},{25,18},{15,10},{5,3}};

			float scale_factor = 1.0/SOURCE_IMAG_SIZE_W;
			float plice_scale[6]={112*scale_factor, 80*scale_factor, 28*scale_factor/*ËõÓë·Å±ÈÀýÓÐ²î±ð*/, 60*scale_factor, 40*scale_factor, 20*scale_factor};

			//memset(input_pic.buffer, 0, input_pic.size);

			input_pic.width  = p_t_param->ini_cnn_cfg[1].cnn_cfg.input_params[0].width;
			input_pic.height = p_t_param->ini_cnn_cfg[1].cnn_cfg.input_params[0].height;
			input_pic.channel= p_t_param->ini_cnn_cfg[1].cnn_cfg.input_params[0].nChannels;

			int in_idx;
			for (in_idx = 0; in_idx < PLICE_NUM; in_idx++)
			{
				SAMPLE_PICATTR_T  attr = {0};

				attr.channel = source_img.channel;
				attr.width	 = plice_size[in_idx][0];
				attr.height  = plice_size[in_idx][1];

				int place_w  = plice_site[in_idx][0];
				int place_h  = plice_site[in_idx][1];

				sample_image_resize_easy_opt(&source_img, &attr, &input_pic, place_w, place_h);
			}
			MEASURE_TIME(P1inf_start);
			AR_PRINTF_DEBUG("[DSP%d]p1 pre : %ld ms\r\n", dsp_id, P1inf_start - P1pre_start);

			net_id_1 = p_dsp_alg->alg_type;

			ret = ar_do_algrithom(p_dsp_alg);

			if(ret < 0)
			{
				AR_PRINTF_ERR("[DSP%d]Error calling ar_do_algrithom: %d, quit!\r\n", dsp_id, ret);
				goto _free_and_exit;
			}
			if(p_dsp_alg->exit_code < 0)
			{
				AR_PRINTF_ERR("[DSP%d]DSP returns %d, continue...\r\n!\r\n", dsp_id, p_dsp_alg->exit_code);
				ar_update_osd(g_osd_fd, &osd_layer);
				if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_SENSOR_IMG)
				{
					ar_release_img_to_list(entry_ptr);
					entry_ptr = NULL;
				}
				continue;
			}

			MEASURE_TIME(P1post_start);
			AR_PRINTF_DEBUG("[DSP%d]p1 infere : %ld ms\r\n", dsp_id, P1post_start - P1inf_start);

			p_dsp_alg->alg_type = net_id_1;

			AR_DSP_OUTPUT_st *pOutput = (AR_DSP_OUTPUT_st *)&p_dsp_alg->output;

			ArCdnnOutputBuffer* cls_box = NULL, *loc_box = NULL;

			for (int output_index = 0; output_index < pOutput->buffer_num; output_index++)
			{
				if (strcmp(pOutput->output_buffer[output_index].buffer_name, "prob1") == 0)
				{
					cls_box = &(pOutput->output_buffer[output_index]);
				}
				else if (strcmp(pOutput->output_buffer[output_index].buffer_name, "conv4-2") == 0)
				{
					loc_box = &(pOutput->output_buffer[output_index]);
				}
			}

			if (cls_box != NULL && loc_box != NULL)
			{
				int out_idx;
				for (out_idx = 0; out_idx < PLICE_NUM; out_idx++)
				{
					int outside = sample_max(out_size[out_idx][0], out_size[out_idx][1]);
					detect_pnet_object_splice_opt(context, cls_box, loc_box, outside, 1.0/plice_scale[out_idx], _box_threshold[0], 0.5,
												  out_site[out_idx][0], out_site[out_idx][1], out_size[out_idx][0], out_size[out_idx][1]);
				}
			}
			MEASURE_TIME(P1post_end);
			AR_PRINTF_DEBUG("[DSP%d]p1net post : %ld ms\r\n", dsp_id, P1post_end - P1post_start);

			if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_STATS)
			{
				AR_PRINTF_DEBUG("[DSP%d] P1net : \r\n", dsp_id);
				ar_dump_statistics(dsp_id, &p_dsp_alg->statistics);
			}
		}

		MEASURE_TIME(P01_start);
		for (int box_index = 0; box_index < context->temp_box_count; box_index++)
		{
			if (context->temp_boxs[box_index].valid)
			{
				if (all_box_count >= context->box_size || all_score_count >= context->score_size)
				{
					//ar_update_osd(g_osd_fd, &osd_layer);
					//if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_SENSOR_IMG)
					//{
					//	ar_release_img_to_list(entry_ptr);
					//	entry_ptr = NULL;
					//}
					continue;
				}
				context->boxs[all_box_count] = context->temp_boxs[box_index];
				all_box_count++;
				context->scores[all_score_count].order = all_score_count;
				context->scores[all_score_count].score = context->temp_boxs[box_index].score;
				all_score_count++;
			}
		}
		compute_nms(context->boxs, all_box_count, context->scores, all_score_count, _nms_threshold[0], "iou");
		sample_sort_boxs_score(context->boxs, all_box_count);

		int box_count = 0;
		for (int box_index = 0; box_index < all_box_count; box_index++)
		{
			if (context->boxs[box_index].valid)
			{
				box_count++;
			}
		}
		context->box_count = box_count;

		if (0)
		{
			for (int box_index = 0; box_index < all_box_count; box_index++)
			{
				AR_PRINTF_DEBUG("PNET Index %d, Valid %d, Rect [%f,%f,%f,%f], Score %f\r\n", box_index, context->boxs[box_index].valid,
					context->boxs[box_index].x1, context->boxs[box_index].y1, context->boxs[box_index].x2, context->boxs[box_index].y2, context->boxs[box_index].score);
			}
		}

		if ( context->box_count <= 0 )
		{
			ar_update_osd(g_osd_fd, &osd_layer);
			if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_SENSOR_IMG)
			{
				ar_release_img_to_list(entry_ptr);
				entry_ptr = NULL;
			}
			continue;
		}

		box_countP = context->box_count;

		MEASURE_TIME(P01_end);
		AR_PRINTF_DEBUG("[DSP%d]p0 + p1 post : %ld ms\r\n", dsp_id, P01_end - P01_start);

		/*******************************[RNET PROC] *****************************/
		{ //rnet
			//memset(&detect_results, 0, sizeof(detect_results));
			p_dsp_alg->dsp_id = p_t_param->dsp_id;
			p_dsp_alg->alg_type = p_dsp_cfg->cnn_cfg[2].network_id;

			p_dsp_alg->input[0].width = p_t_param->ini_cnn_cfg[2].cnn_cfg.input_params[0].width;
			p_dsp_alg->input[0].height =  p_t_param->ini_cnn_cfg[2].cnn_cfg.input_params[0].height;
			p_dsp_alg->input[0].channel =	p_t_param->ini_cnn_cfg[2].cnn_cfg.input_params[0].nChannels;
			p_dsp_alg->input[0].format = p_t_param->ini_cnn_cfg[2].cnn_cfg.input_format[0];

			input_pic.width  = p_t_param->ini_cnn_cfg[2].cnn_cfg.input_params[0].width;
			input_pic.height = p_t_param->ini_cnn_cfg[2].cnn_cfg.input_params[0].height;
			input_pic.channel= p_t_param->ini_cnn_cfg[2].cnn_cfg.input_params[0].nChannels;

			//printf("==Start call dsp with input: %x output: %x\r\n", input_pa, output_pa);
			int box_count = mtcnn_process_ronet_opt( p_dsp_alg,
												    (AR_DSP_OUTPUT_st *)&p_dsp_alg->output,
												    context,
				                                    &source_img,
				                                    &input_pic,
				                                    24, 24, 8, MAX_RNET_NUM );



			MEASURE_TIME(Rpost_start);

			if(box_count <= 0)
			{
				ar_update_osd(g_osd_fd, &osd_layer);
				if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_SENSOR_IMG)
				{
					ar_release_img_to_list(entry_ptr);
					entry_ptr = NULL;
				}
				continue;
			}

			box_count = filter_rnet_object(context, source_img.width, source_img.height, _box_threshold[1], _nms_threshold[1]);

			if(box_count <= 0)
			{
				ar_update_osd(g_osd_fd, &osd_layer);
				if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_SENSOR_IMG)
				{
					ar_release_img_to_list(entry_ptr);
					entry_ptr = NULL;
				}
				continue;
			}

			box_countR = box_count;
			MEASURE_TIME(Rpost_end);
			AR_PRINTF_DEBUG("[DSP%d]rnet post : %ld ms\r\n", dsp_id, Rpost_end - Rpost_start);


			if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_STATS)
			{
				AR_PRINTF_DEBUG("[DSP%d] Rnet : \r\n", dsp_id);
				ar_dump_statistics(dsp_id, &p_dsp_alg->statistics);
			}
		}

		{ //onet
			//memset(&detect_results, 0, sizeof(detect_results));

			p_dsp_alg->dsp_id = p_t_param->dsp_id;
			p_dsp_alg->alg_type = p_dsp_cfg->cnn_cfg[3].network_id;

			p_dsp_alg->input[0].width = p_t_param->ini_cnn_cfg[3].cnn_cfg.input_params[0].width;
			p_dsp_alg->input[0].height =  p_t_param->ini_cnn_cfg[3].cnn_cfg.input_params[0].height;
			p_dsp_alg->input[0].channel =	p_t_param->ini_cnn_cfg[3].cnn_cfg.input_params[0].nChannels;
			p_dsp_alg->input[0].format = p_t_param->ini_cnn_cfg[3].cnn_cfg.input_format[0];
			//p_dsp_alg->input[0].size = img_size;

			input_pic.width  = p_t_param->ini_cnn_cfg[3].cnn_cfg.input_params[0].width;
			input_pic.height = p_t_param->ini_cnn_cfg[3].cnn_cfg.input_params[0].height;
			input_pic.channel= p_t_param->ini_cnn_cfg[3].cnn_cfg.input_params[0].nChannels;

			//printf("==Start call dsp with input: %x output: %x\r\n", input_pa, output_pa);
			int box_count = mtcnn_process_ronet_opt( p_dsp_alg,
													(AR_DSP_OUTPUT_st *)&p_dsp_alg->output,
													context,
													&source_img,
													&input_pic,
													48, 48, 4, MAX_ONET_NUM);
			//printf("0 box_count %d \r\n",box_count);
			MEASURE_TIME(Opost_start);

			if(box_count <= 0)
			{
				ar_update_osd(g_osd_fd, &osd_layer);
				if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_SENSOR_IMG)
				{
					ar_release_img_to_list(entry_ptr);
					entry_ptr = NULL;
				}
				continue;
			}

			box_count = filter_onet_object(context, source_img.width, source_img.height, _box_threshold[2], _nms_threshold[2]);
			MEASURE_TIME(Opost_end);
			AR_PRINTF_DEBUG("[DSP%d] Onet post : %ld ms\r\n", dsp_id, Opost_end - Opost_start);

			MEASURE_TIME(total_end);
			AR_PRINTF_DEBUG("[DSP%d]Time elapsed : %ld ms, processed frame: %lld\r\n", dsp_id, total_end - total_start, frame_processed);

			all_box_cnt += box_count;

			if (box_count > 0) succ_detect_cnt++;

			if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_RESULTS)
			{
				AR_PRINTF_DEBUG("succ_detect_cnt:%d \r\n",succ_detect_cnt);
				//printf(" img640x480_%d: TimeCost %lld, ", test_set_cnt, start4 - start2 );
				AR_PRINTF_DEBUG(" box_countP %d box_countR %d, ", box_countP, box_countR );
				AR_PRINTF_DEBUG(" NumOfDetectedFaces %d	 Confidence %f \r\n", box_count, context->boxs[0].score * 100 );
			}

			if(box_count <= 0)
			{
				ar_update_osd(g_osd_fd, &osd_layer);
				if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_SENSOR_IMG)
				{
					ar_release_img_to_list(entry_ptr);
					entry_ptr = NULL;
				}
				continue;
			}

			detect_results.object_num = context->box_count;
			for(int box_idx = 0; box_idx < context->box_count; box_idx++)
			{
				AR_DSP_DETECT_OBJ_st *pDetectObj = &(detect_results.objects[box_idx]);
				SAMPLE_RECTBOX_T *pBoxs = &(context->boxs[box_idx]);
				pDetectObj->index = box_idx;
				pDetectObj->score = pBoxs->score;
				pDetectObj->rect.x = pBoxs->x1;
				pDetectObj->rect.y = pBoxs->y1;
				pDetectObj->rect.width = pBoxs->width;
				pDetectObj->rect.height = pBoxs->height;
				strcpy(pDetectObj->label, "face");

			    for(int fest_index =0; fest_index <5; fest_index++ )
		       	{
	               points[fest_index].x = context->boxs[box_idx].feature->records[fest_index].x;
				   points[fest_index].y = context->boxs[box_idx].feature->records[fest_index].y;
			    }
				if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_SENSOR_IMG
					&& g_sys_cfg.dump_ctrl & AR_DSP_DUMP_OSD)
				{
					ar_fill_osd_layer(g_osd_fd, pDetectObj, points, 5,
							source_img.width, source_img.height, &osd_layer);
				}
			}

			if(p_t_param->ini_cnn_cfg[0].input_source == AR_DSP_ALG_RUN_SENSOR_IMG)
			{
			   ar_release_img_to_list(entry_ptr);
			   entry_ptr = NULL;

				if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_OSD)
				{
					ar_update_osd(g_osd_fd, &osd_layer);
				}
			}
			else
			{
				//save local dataset results.
				ar_save_detect_output_to_file(result_file_name_onet, file_name, &detect_results);
			}

			if(g_sys_cfg.dump_ctrl & AR_DSP_DUMP_STATS)
			{
				AR_PRINTF_DEBUG("[DSP%d] Onet : \r\n", dsp_id);
				ar_dump_statistics(dsp_id, &p_dsp_alg->statistics);
			}

		}

		if (g_sys_cfg.dump_ctrl & AR_DSP_DUMP_RESULTS)
		{
			int index = 0;
			for (index = 0; index < context->box_count; index++){
				AR_PRINTF_DEBUG("[DSP%d]----> Frame %lld person score %f coordinate [%f, %f, %f, %f]\r\n",
					dsp_id, frame_id,
					context->boxs[index].score * 100,
					context->boxs[index].x1, context->boxs[index].y1, context->boxs[index].x2, context->boxs[index].y2);
			}
		}


	}

	AR_PRINTF_DEBUG("[DSP%d] Test finished...\r\n", dsp_id);

_free_and_exit:

	if (p_dsp_alg)
	{
		free(p_dsp_alg);
	}

	if (p_dsp_cfg)
	{
		free(p_dsp_cfg);
	}

	if(entry_ptr)
	{
		ar_release_img_to_list(entry_ptr);
	}

	for(i = 0; i < AR_DSP_ALG_MAX_INPUT_NUM; i++)
	{
		if(input_va[i])
		{
			AR_RELEASE_ION_MEMORY(input_va[i]);
		}
	}

	if(output_pdata_va)
	{
		AR_RELEASE_ION_MEMORY(output_pdata_va);
	}

	if(ext_mem_addr_va)
	{
		AR_RELEASE_ION_MEMORY(ext_mem_addr_va);
	}

	if(sram_addr_va)
	{
		AR_RELEASE_ION_MEMORY(sram_addr_va);
	}

	g_thread_exit_cnt++;

	return NULL;
	//pthread_exit((void *)"Terminate");

}



