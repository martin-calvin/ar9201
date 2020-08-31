#include <string.h>
#include <cstdint>
#include <cstdio>
// #include <io.h>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>
#include "tof_calibration_params_parser.h"

void OutputSensorParams(ObToFParam tof_param, std::string params_fname)
{
    std::ofstream cout_params(params_fname);
    cout_params << "[iRIn]" << std::endl;
    cout_params << "[fx, fy, cx, cy] " << tof_param.ir_intrin.fx << " " << tof_param.ir_intrin.fy << " "\
        << tof_param.ir_intrin.cx << " " << tof_param.ir_intrin.cy << std::endl;

    printf("[iRIn]:\n");
    printf("[fx,%f fy,%f cx,%f cy,%f]\n", 
            tof_param.ir_intrin.fx, tof_param.ir_intrin.fy, tof_param.ir_intrin.cx, tof_param.ir_intrin.cy);

    cout_params << "[DSTO]" << std::endl;
    cout_params << "[k1, k2, p1, p2, k3] " << " " << tof_param.distort.k1 << " " << tof_param.distort.k2 << " " \
        << tof_param.distort.t1 << " " << tof_param.distort.t2 << " " << tof_param.distort.k3 << std::endl;

    cout_params << "[lSen]" << std::endl;
    cout_params << "[freq_mode, inter_time] " << tof_param.sensor_param[0].freq_mod << " " << tof_param.sensor_param[0].integral_time << std::endl;
    cout_params << "[lTmp]" << std::endl;
    for (size_t i = 0; i < tof_param.temp_comp[0].vcsel_coeff_size; i++)
    {
        cout_params << tof_param.temp_comp[0].vcsel_temp_comp_coeff[i] << "\t";
        cout_params << tof_param.temp_comp[0].sensor_temp_comp_coeff[i] << std::endl;
    }
    cout_params << "[offset] " << tof_param.temp_comp[0].temp_dist_offset << std::endl;

    cout_params << "hSen" << std::endl;
    cout_params << "[freq_mode, inter_time] " << tof_param.sensor_param[1].freq_mod << " " << tof_param.sensor_param[1].integral_time << std::endl;
    cout_params << "hTmp" << std::endl;
    for (size_t i = 0; i < tof_param.temp_comp[1].vcsel_coeff_size; i++)
    {
        cout_params << tof_param.temp_comp[1].vcsel_temp_comp_coeff[i] << "\t";
        cout_params << tof_param.temp_comp[1].sensor_temp_comp_coeff[i] << std::endl;
    }
    cout_params << "[offset] " << tof_param.temp_comp[1].temp_dist_offset << std::endl;
}

void OutputFPPN(ObToFParam tof_param, std::string fppn_fname, uint8_t freq)
{
    std::ofstream cout_fppn(fppn_fname);
    for (size_t i = 0; i < 480; i++)
    {
        for (size_t j = 0; j < 640; j++)
        {
            cout_fppn << *(tof_param.dist_calib[freq].fppn_lut)<< ",";
            tof_param.dist_calib[freq].fppn_lut++;
        }
        cout_fppn << "\n";
    }
}

void OutputWiggling(ObToFParam tof_param, std::string wiggling_fname, uint8_t freq)
{
    std::ofstream cout_wiggling(wiggling_fname);
    for (size_t k = 0; k < tof_param.dist_calib[freq].wiggling_lut_size; k++)
    {
        cout_wiggling << *(tof_param.dist_calib[freq].wiggling_lut) << "\n";
        tof_param.dist_calib[freq].wiggling_lut++;
    }
}

void OutputSlopeFPPN(ObToFParam tof_param, std::string slope_fppn_fname, uint8_t freq)
{
    if (tof_param.dist_calib[freq].fppn_slope_lut_size < 1)
    {
        return;
    }

    std::ofstream cout_slope_fppn(slope_fppn_fname);
    for (size_t i = 0; i < 480; i++)
    {
        for (size_t j = 0; j < 640; j++)
        {
            cout_slope_fppn << *(tof_param.dist_calib[freq].fppn_slope_lut) << ",";
            tof_param.dist_calib[freq].fppn_slope_lut++;
        }
        cout_slope_fppn << "\n";
    }
}

#if 0
int main(int argc, char ** argv)
{
    if (2 > argc)
    {
        fprintf(stderr, "usage: tof_calib_paramss.bin ");
        return -1;
    }
    char * param_fname = argv[1];
    ObToFParam tof_param;
    ParamParseErr ret = LoadToFCalibrationParams(param_fname, &tof_param);
    if (PARAM_PARSE_OK != ret)
    {
        return -1;
    }
    
    //解析出参数，便于问题定位
    std::string sensor_params_fname = std::string(param_fname).substr(0, std::string(param_fname).length() - 4) + "_params.txt";
    OutputSensorParams(tof_param, sensor_params_fname);
 
    //output lut
    std::string lfppn_fname = std::string(param_fname).substr(0, std::string(param_fname).length() - 4) + "_lCal_fppn.csv";
    OutputFPPN(tof_param, lfppn_fname, 0);
    std::string lwiggling_fname = std::string(param_fname).substr(0, std::string(param_fname).length() - 4) + "_lCal_wiggling.csv";
    OutputWiggling(tof_param, lwiggling_fname, 0);
    std::string lslope_fname = std::string(param_fname).substr(0, std::string(param_fname).length() - 4) + "_lCal_slope.csv";
    OutputSlopeFPPN(tof_param, lslope_fname, 0);

    std::string hfppn_fname = std::string(param_fname).substr(0, std::string(param_fname).length() - 4) + "_hCal_fppn.csv";
    OutputFPPN(tof_param, hfppn_fname, 1);
    std::string hwiggling_fname = std::string(param_fname).substr(0, std::string(param_fname).length() - 4) + "_hCal_wiggling.csv";
    OutputWiggling(tof_param, hwiggling_fname, 1);
    std::string hslope_fname = std::string(param_fname).substr(0, std::string(param_fname).length() - 4) + "_hCal_slope.csv";
    OutputSlopeFPPN(tof_param, hslope_fname, 1);

    ObToFParamsFree();//在参数使用完后，记得释放内存空间
    printf("end\n");
    return 0;
}
#endif