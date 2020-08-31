

#include "dbg_info.h"

/* 打印所有ObTofDspParams 结构体成员 */
void debug_info_tofparams_msg(ObTofDspParams *tof)
{
    printf("tof->inputs.constInputs.buf = 0x%x\r\n", tof->inputs.constInputs.buf);

    printf("tof->inputs.constInputs.calibParams.dist_calib[0].fppn_lut = 0x%x\r\n", tof->inputs.constInputs.calibParams.dist_calib[0].fppn_lut);
    printf("tof->inputs.constInputs.calibParams.dist_calib[0].fppn_lut_size = %d\r\n", tof->inputs.constInputs.calibParams.dist_calib[0].fppn_lut_size);
    printf("tof->inputs.constInputs.calibParams.dist_calib[0].phase_offset = %f\r\n", tof->inputs.constInputs.calibParams.dist_calib[0].phase_offset);
    printf("tof->inputs.constInputs.calibParams.dist_calib[0].wiggling_lut = 0x%x\r\n", tof->inputs.constInputs.calibParams.dist_calib[0].wiggling_lut);
    printf("tof->inputs.constInputs.calibParams.dist_calib[0].wiggling_lut_size = %d\r\n", tof->inputs.constInputs.calibParams.dist_calib[0].wiggling_lut_size);
    printf("tof->inputs.constInputs.calibParams.dist_calib[1].fppn_lut = 0x%x\r\n", tof->inputs.constInputs.calibParams.dist_calib[1].fppn_lut);
    printf("tof->inputs.constInputs.calibParams.dist_calib[1].fppn_lut_size = %d\r\n", tof->inputs.constInputs.calibParams.dist_calib[1].fppn_lut_size);
    printf("tof->inputs.constInputs.calibParams.dist_calib[1].phase_offset = %f\r\n", tof->inputs.constInputs.calibParams.dist_calib[1].phase_offset);
    printf("tof->inputs.constInputs.calibParams.dist_calib[1].wiggling_lut = 0x%x\r\n", tof->inputs.constInputs.calibParams.dist_calib[1].wiggling_lut);
    printf("tof->inputs.constInputs.calibParams.dist_calib[1].wiggling_lut_size = %d\r\n", tof->inputs.constInputs.calibParams.dist_calib[1].wiggling_lut_size);

    printf("tof->inputs.constInputs.calibParams.dist_slop_calib.fppn_offset = 0x%x\r\n", tof->inputs.constInputs.calibParams.dist_slop_calib.fppn_offset);
    printf("tof->inputs.constInputs.calibParams.dist_slop_calib.fppn_slop_lut_high = 0x%x\r\n", tof->inputs.constInputs.calibParams.dist_slop_calib.fppn_slop_lut_high);
    printf("tof->inputs.constInputs.calibParams.dist_slop_calib.fppn_slop_lut_high = 0x%x\r\n", tof->inputs.constInputs.calibParams.dist_slop_calib.fppn_slop_lut_low);
    printf("tof->inputs.constInputs.calibParams.dist_slop_calib.scale = %f\r\n", tof->inputs.constInputs.calibParams.dist_slop_calib.scale);

    printf("tof->inputs.constInputs.calibParams.freq_mod[0] = %d\r\n", tof->inputs.constInputs.calibParams.freq_mod[0]);
    printf("tof->inputs.constInputs.calibParams.freq_mod[1] = %d\r\n", tof->inputs.constInputs.calibParams.freq_mod[1]);

    printf("tof->inputs.constInputs.calibParams.headerType = %d\r\n", tof->inputs.constInputs.calibParams.headerType);
    printf("tof->inputs.constInputs.calibParams.res1 = %d\r\n", tof->inputs.constInputs.calibParams.res1);
    printf("tof->inputs.constInputs.calibParams.res2 = %d\r\n", tof->inputs.constInputs.calibParams.res2);
    printf("tof->inputs.constInputs.calibParams.temp_comp[0].sensor_temp_comp_coeff = %f\r\n", tof->inputs.constInputs.calibParams.temp_comp[0].sensor_temp_comp_coeff);
    printf("tof->inputs.constInputs.calibParams.temp_comp[0].temp_dist_offset = %f\r\n", tof->inputs.constInputs.calibParams.temp_comp[0].temp_dist_offset);
    printf("tof->inputs.constInputs.calibParams.temp_comp[0].vcsel_temp_comp_coeff = %f\r\n", tof->inputs.constInputs.calibParams.temp_comp[0].vcsel_temp_comp_coeff);

    printf("tof->inputs.constInputs.calibParams.temp_comp[1].sensor_temp_comp_coeff = %f\r\n", tof->inputs.constInputs.calibParams.temp_comp[1].sensor_temp_comp_coeff);
    printf("tof->inputs.constInputs.calibParams.temp_comp[1].temp_dist_offset = %f\r\n", tof->inputs.constInputs.calibParams.temp_comp[1].temp_dist_offset);
    printf("tof->inputs.constInputs.calibParams.temp_comp[1].vcsel_temp_comp_coeff = %f\r\n", tof->inputs.constInputs.calibParams.temp_comp[1].vcsel_temp_comp_coeff);


    printf("tof->inputs.constInputs.cameraIntrin.cx = %f\r\n", tof->inputs.constInputs.cameraIntrin.cx);
    printf("tof->inputs.constInputs.cameraIntrin.cy = %f\r\n", tof->inputs.constInputs.cameraIntrin.cy);
    printf("tof->inputs.constInputs.cameraIntrin.fx = %f\r\n", tof->inputs.constInputs.cameraIntrin.fx);
    printf("tof->inputs.constInputs.cameraIntrin.fy = %f\r\n", tof->inputs.constInputs.cameraIntrin.fy);

    printf("tof->inputs.constInputs.depthCfg.depth_uint = %f\r\n", tof->inputs.constInputs.depthCfg.depth_uint);
    printf("tof->inputs.constInputs.depthCfg.max_depth = %d\r\n", tof->inputs.constInputs.depthCfg.max_depth);
    printf("tof->inputs.constInputs.depthCfg.min_depth = %d\r\n", tof->inputs.constInputs.depthCfg.min_depth);

    printf("tof->inputs.constInputs.depth_coef = 0x%x\r\n", tof->inputs.constInputs.depth_coef);
    printf("tof->inputs.constInputs.filterCfg.fly_bypass = %d\r\n", tof->inputs.constInputs.filterCfg.fly_bypass);
    printf("tof->inputs.constInputs.filterCfg.fly_fill_hole = %d\r\n", tof->inputs.constInputs.filterCfg.fly_fill_hole);
    printf("tof->inputs.constInputs.filterCfg.fly_noise_coeff = %f\r\n", tof->inputs.constInputs.filterCfg.fly_noise_coeff);
    printf("tof->inputs.constInputs.filterCfg.fly_thres = %f\r\n", tof->inputs.constInputs.filterCfg.fly_thres);
    printf("tof->inputs.constInputs.filterCfg.gaussian_bypass = %d\r\n", tof->inputs.constInputs.filterCfg.gaussian_bypass);
    printf("tof->inputs.constInputs.filterCfg.gaussian_sigma_x = %f\r\n", tof->inputs.constInputs.filterCfg.gaussian_sigma_x);
    printf("tof->inputs.constInputs.filterCfg.gaussian_sigma_y = %f\r\n", tof->inputs.constInputs.filterCfg.gaussian_sigma_y);
    printf("tof->inputs.constInputs.filterCfg.median_bypass = %d\r\n", tof->inputs.constInputs.filterCfg.median_bypass);

    printf("tof->inputs.constInputs.height = %d\r\n", tof->inputs.constInputs.height);
    printf("tof->inputs.constInputs.width = %d\r\n", tof->inputs.constInputs.width);

    printf("tof->inputs.frameInputs.phase_high_nshl_src = 0x%x\r\n", tof->inputs.frameInputs.phase_high_nshl_src);
    printf("tof->inputs.frameInputs.phase_high_shl_src = 0x%x\r\n", tof->inputs.frameInputs.phase_high_shl_src);
    printf("tof->inputs.frameInputs.phase_low_nshl_src = 0x%x\r\n", tof->inputs.frameInputs.phase_low_nshl_src);
    printf("tof->inputs.frameInputs.phase_low_shl_src = 0x%x\r\n", tof->inputs.frameInputs.phase_low_shl_src);
    printf("tof->inputs.frameInputs.tempParams.sensor_temp_high = %.1f\r\n", tof->inputs.frameInputs.tempParams.sensor_temp_high);
    printf("tof->inputs.frameInputs.tempParams.sensor_temp_low = %.1f\r\n", tof->inputs.frameInputs.tempParams.sensor_temp_low);
    printf("tof->inputs.frameInputs.tempParams.vcsel_temp_high = %.1f\r\n", tof->inputs.frameInputs.tempParams.vcsel_temp_high);
    printf("tof->inputs.frameInputs.tempParams.vcsel_temp_low = %.1f\r\n", tof->inputs.frameInputs.tempParams.vcsel_temp_low);

    printf("tof->inputs.multiplex = %d\r\n", tof->inputs.multiplex);

    printf("tof->outputs.amp_high = 0x%x\r\n", tof->outputs.amp_high);
    printf("tof->outputs.amp_low = 0x%x\r\n", tof->outputs.amp_low);
    printf("tof->outputs.cost_times = %d\r\n", tof->outputs.cost_times);
    printf("tof->outputs.depth0 = 0x%x\r\n", tof->outputs.depth0);
    printf("tof->outputs.depth1 = 0x%x\r\n", tof->outputs.depth1);
    printf("tof->outputs.dsp_version.build = %d\r\n", tof->outputs.dsp_version.build);
    printf("tof->outputs.dsp_version.major = %d\r\n", tof->outputs.dsp_version.major);
    printf("tof->outputs.dsp_version.minor = %d\r\n", tof->outputs.dsp_version.minor);
    printf("tof->outputs.dsp_version.patch_level = %d\r\n", tof->outputs.dsp_version.patch_level);
    printf("tof->outputs.ir0 = 0x%x\r\n", tof->outputs.ir_0);
    printf("tof->outputs.ir1 = 0x%x\r\n", tof->outputs.ir_1);
    printf("tof->outputs.status = %d\r\n", tof->outputs.status);
}

/* 打印所有work结构体成员 */
void debug_info_work_msg(work *work_msg)
{
    printf("work_msg->id = %d\n", work_msg->id);
    printf("work_msg->type= %d\n", work_msg->type);
    printf("work_msg->result = %d\n", work_msg->result);
    printf("work_msg->rate = %d\n", work_msg->rate);
    printf("work_msg->cycles = %d\n", work_msg->cycles);

    printf("work_msg->params.algorithm.type = %d\n", work_msg->params.algorithm.type);
    printf("work_msg->params.algorithm.packet_phys = 0x%x\n", work_msg->params.algorithm.packet_phys);
    printf("work_msg->params.algorithm.packet_virt = 0x%x\n", work_msg->params.algorithm.packet_virt);
    printf("work_msg->params.algorithm.size = %d\n", work_msg->params.algorithm.size);
}