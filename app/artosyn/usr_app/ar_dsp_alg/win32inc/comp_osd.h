#ifndef __COMP_OSD_H__
#define __COMP_OSD_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ar_gui.h"

#ifdef __cplusplus
extern "C"{
#endif

#define AR_VISION_MAX_FRAME_PER_PIC	64
#define AR_VISION_LABEL_SIZE		64

#define AR_VISION_MAX_POSITION      8
#define COMP_MAX_NUM 256
#define COMP_IMG_MAX_NUM 16
#define COMP_WORD_CONFIG_NUM 16
#define COMP_MAX_DOTMATRIX_NUM 128

typedef ar_gui_res_t comp_res_t;
typedef ar_gui_config_state_t comp_config_state_t;
typedef ar_gui_point ar_cv_point;
typedef ar_gui_predefined_color_en color_pattern_en;

#define COMP_CEVA_UPDATE (0)

typedef struct
{
	ar_cv_point start;
	ar_cv_point end;
	int    width;
	int    height;
	int    color;
	int    frameLineWidth;
}frame_info_t;

typedef struct
{
    int label[8];
    int    color;
    int    back_color;
    int    index;
    ar_cv_point position;
}label_info_t;

typedef struct
{
	int    index;
	int    weight;
	ar_cv_point  position;
}img_layer_t;

typedef struct
{
	int weight;
	int width;
	int height;
	ar_cv_point position;
}mosic_info_t;

typedef struct{
    int color;
    int radius;
    ar_cv_point     position;
}circle_info_t;

typedef struct
{
    ar_cv_point     position;

    int    ch_color;
    int    back_color;

    int len_charactor;
    int dot_ch_width;
    int dot_ch_height;
    char dot_matrix[1440];

} dot_matrix_charactor_t;

typedef struct
{
	int     frame_num;
	int     label_num;
	int     img_num;
	int     mosic_num;
    int     circle_num;
    frame_info_t  frames[COMP_MAX_NUM];
	label_info_t  labels[COMP_MAX_NUM];
	img_layer_t    imgs[COMP_IMG_MAX_NUM];
    mosic_info_t  mosic[COMP_IMG_MAX_NUM];
    circle_info_t  circles[COMP_MAX_NUM];
    int dot_matrixes_num;
    dot_matrix_charactor_t dot_matrixes[COMP_MAX_DOTMATRIX_NUM];
}layer_user_t;

#if defined(WIN32) || defined(X64)
/*This is for DSP VS simulation*/
__inline int comp_osd_open(const char* name)
{
	return 1;
}
#define comp_osd_close(fd)  do{}while(0)
#define comp_ceva_update(fd, data)  do{}while(0)
#define comp_get_res(fd, data)  do{}while(0)
#else

int comp_osd_open(const char* name);
int comp_osd_close(int fd);
int comp_ceva_update(int fd, void *data);
int comp_get_res(int fd, void* data);
int comp_config_cache(int fd, void *pra);
int comp_config_state(int fd, void *pra);

#endif

#ifdef __cplusplus
}
#endif


#endif

