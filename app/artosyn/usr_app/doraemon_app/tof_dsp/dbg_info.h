#ifndef __DBG_INFO_H__
#define __DBG_INFO_H__

#include <stdio.h>
#include "arm_to_dsp_data.h"

/* 打印所有ObTofDspParams 结构体成员 */
void debug_info_tofparams_msg(ObTofDspParams *tof);
/* 打印所有work结构体成员 */
void debug_info_work_msg(work *work_msg);

#endif