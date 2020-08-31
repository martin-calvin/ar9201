#ifndef __AR_ALG_GET_IMG_LIST_H__
#define __AR_ALG_GET_IMG_LIST_H__

//#ifdef __cplusplus
//extern "C"{
//#endif

#include "ar_alg_define.h"

#include "opencv2/opencv.hpp"

#define MAX_IMG_LIST_LEN    8

using namespace cv;
using namespace std;

struct img_list
{
	struct img_list * prev;
	struct img_list * next;
	int used;
	int released;
	int local_used[MAX_DSP_ID];
	int local_released[MAX_DSP_ID];
	unsigned int frame_id;
    unsigned int pts;
	cv::Mat img;
	cv::Mat rsz_img;
};



extern int ar_init_img_list();
extern int ar_add_img_to_list(struct img_list * entry);
extern struct img_list * ar_get_img_from_list();
extern int ar_release_img_to_list(struct img_list * entry);
extern int ar_recyle_used_img_from_list();

//#ifdef __cplusplus
//}
//#endif

#endif //__AR_ALG_GET_IMG_LIST_H__


