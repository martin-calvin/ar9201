#ifndef __TEST_DSP_H__
#define __TEST_DSP_H__


int dsp_test_init(void);
// dsp从dsp_input_pa地址copy img_len长度数据到dsp_out_va地址
// dsp_input_va: 输入数据的va地址
// dsp_input_pa:输入数据的pa地址给dsp
// dsp_out_va:dsp输出数据的va地址传出
// img_len dsp copy的数据长度
int dsp_test(void *dsp_input_va, void *dsp_input_pa, void *dsp_out_va, int img_len);

#endif