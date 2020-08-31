#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "ar_log.h"
#include "Mx6300.h"
#include "Mx6300_ctl.h"
#include "obc_sl_spi.h"
#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* __cplusplus */
  extern int gspifd;
  int Mx6300_get_device_id(uint16_t *dev_Id)
  {
    int ret;
    uint32_t devId;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_GET_DEVICE_ID_ADDR;
    ctrl_msg.pdata = &devId;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:get device id failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *dev_Id = devId & 0xFFFF;
    return OB_SUCCESS;
  }
  int Mx6300_read_fw_version(char *fw)
  {
    int ret;
    uint32_t fwVer;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_GET_FW_VER_ADDR;
    ctrl_msg.pdata = &fwVer;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:get firmware version failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    printf("FW_ver=%#x\n", fwVer);
    snprintf(fw, 8, "%d.%d.%d", (fwVer & 0xFF0000) >> 16, (fwVer & 0xFF00) >> 8, fwVer & 0xFF);
    return OB_SUCCESS;
  }
  int Mx6300_read_hw_version(uint8_t *hw_ver)
  {
    int ret;
    uint32_t hwVer;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_GET_HD_VER_ADDR;
    ctrl_msg.pdata = &hwVer;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:get firmware version failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    printf("HW_ver=%#x\n", hwVer);
    *hw_ver = hwVer & 0xFF;
    return OB_SUCCESS;
  }
  int Mx6300_Stream_control(Stream_ctl_State state)
  {
    int ret;
    uint32_t value;
    switch (state)
    {
    case STREAM_CLOSE:
      value = 0x0;
      break;
    case STREAM_DEPTH_OPEN:
      value = 0x1;
      break;
    case STREAM_IR_OPEN:
      value = 0x2;
      break;
    default:
      value = 0x0;
      break;
    }
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_DEV_CTL_ADDR;
    ctrl_msg.pdata = &value;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    usleep(40000);
    if (ret < 0)
    {
      printf("%s:control stream state failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_get_depth_resolution(uint8_t *res)
  {
    int ret;
    uint32_t res_;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_GET_DEPTH_RES_ADDR;
    ctrl_msg.pdata = &res_;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:get current  depth resolution failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = res_ & 0xFF;
    return OB_SUCCESS;
  }
  int Mx6300_get_ir_resolution(uint8_t *res)
  {
    int ret;
    uint32_t res_;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_GET_IR_RES_ADDR;
    ctrl_msg.pdata = &res_;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:get current  ir resolution failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = res_ & 0xFF;
    return OB_SUCCESS;
  }

  int Mx6300_get_depth_fps(uint8_t *res)
  {
    int ret;
    uint32_t fps;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_GET_DEPTH_FPS_ADDR;
    ctrl_msg.pdata = &fps;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:get depth fps failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = fps & 0xFF;
    return OB_SUCCESS;
  }
  int Mx6300_get_ir_fps(uint8_t *res)
  {
    int ret;
    uint32_t fps;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_GET_IR_FPS_ADDR;
    ctrl_msg.pdata = &fps;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:get ir fps failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = fps & 0xFF;
    return OB_SUCCESS;
  }

   int Mx6300_set_depth_video_mode(Resolution res, uint8_t fps)
   {
      int ret;
    uint32_t res_ = (uint32_t)res;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_DEPTH_RES_ADDR;
    ctrl_msg.pdata = &res_;
    ctrl_msg.dataLen = 4;
    printf("depth_res_=%d,fps=%d\n", res_,fps);
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set depth resolution failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    uint32_t fps_ = (fps<=0 || fps>30)? 30:fps;
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_DEPTH_FPS_ADDR;
    ctrl_msg.pdata = &fps_;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set depth fps failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    uint32_t format = 0x04;
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_DEPTH_PIXFMT_ADDR;
    ctrl_msg.pdata = &format;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set depth format failed\n", __FUNCTION__);
      return OB_FAILURE;
    }

    uint32_t load = 0x01;
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_DEPTH_LOAD_ADDR;
    ctrl_msg.pdata = &load;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:load depth video failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
   }
  int Mx6300_set_depth_resolution(Resolution res)
  {
    int ret;
    uint32_t res_ = (uint32_t)res;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_DEPTH_RES_ADDR;
    ctrl_msg.pdata = &res_;
    ctrl_msg.dataLen = 4;
    printf("depth_res_=%d\n", res_);
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set depth resolution failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    uint32_t fps = 30;
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_DEPTH_FPS_ADDR;
    ctrl_msg.pdata = &fps;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set depth resolution failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    uint32_t format = 0x04;
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_DEPTH_PIXFMT_ADDR;
    ctrl_msg.pdata = &format;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set depth resolution failed\n", __FUNCTION__);
      return OB_FAILURE;
    }

    uint32_t load = 0x01;
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_DEPTH_LOAD_ADDR;
    ctrl_msg.pdata = &load;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:load depth resolution failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }

  	int Mx6300_set_ir_video_mode(Resolution res, uint8_t fps)
    {
     int ret;
    uint32_t res_ = (uint32_t)res;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_IR_RES_ADDR;
    ctrl_msg.pdata = &res_;
    ctrl_msg.dataLen = 4;
    printf("ir_res_=%d,fps=%d\n", res_,fps);
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set ir video failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    uint32_t fps_ = (fps<=0 || fps>30)? 30:fps;
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_IR_FPS_ADDR;
    ctrl_msg.pdata = &fps_;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set ir video failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    uint32_t format = 0x04;
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_IR_PIXFMT_ADDR;
    ctrl_msg.pdata = &format;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set ir video failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    uint32_t load = 0x01;
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_IR_LOAD_ADDR;
    ctrl_msg.pdata = &load;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:load ir video failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
    }
  int Mx6300_set_ir_resolution(Resolution res)
  {
    int ret;
    uint32_t res_ = (uint32_t)res;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_IR_RES_ADDR;
    ctrl_msg.pdata = &res_;
    ctrl_msg.dataLen = 4;
    printf("ir_res_=%d\n", res_);
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set ir resolution failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    uint32_t fps = 30;
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_IR_FPS_ADDR;
    ctrl_msg.pdata = &fps;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set ir resolution failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    uint32_t format = 0x04;
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_IR_PIXFMT_ADDR;
    ctrl_msg.pdata = &format;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set ir resolution failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    uint32_t load = 0x01;
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_IR_LOAD_ADDR;
    ctrl_msg.pdata = &load;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:load ir resolution failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_set_depth_fps(uint8_t value)
  {
    int ret;
    uint32_t fps = value;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_DEPTH_RES_ADDR;
    ctrl_msg.pdata = &fps;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set depth fps failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    uint32_t load = 0x01;
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_DEPTH_LOAD_ADDR;
    ctrl_msg.pdata = &load;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:load depth fps failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_set_ir_fps(uint8_t value)
  {
    int ret;
    uint32_t fps = value;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_IR_FPS_ADDR;
    ctrl_msg.pdata = &fps;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set ir fps failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    uint32_t load = 0x01;
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_IR_LOAD_ADDR;
    ctrl_msg.pdata = &load;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:load ir fps failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_laser_control(uint8_t value)
  {
    int ret;
    uint32_t laser_state = value == 0 ? 0 : 1;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_LASER_ENABLE;
    ctrl_msg.pdata = &laser_state;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set laser state failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }

  int Mx6300_get_laser_status(uint8_t *res)
  {
    int ret;
    uint32_t laser_status;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_LASER_ENABLE;
    ctrl_msg.pdata = &laser_status;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:get laser status failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = (laser_status & 0xFF) == 0 ? 0 : 1;
    return OB_SUCCESS;
  }

  int Mx6300_set_laser_current(uint32_t value)
  {
    int ret;
    uint32_t laser_current = value;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_LASER_LDMP_CURRENT;
    ctrl_msg.pdata = &laser_current;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set laser current failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_get_laser_current(uint32_t *res)
  {
    int ret;
    uint32_t laser_current;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_LASER_LDMP_CURRENT;
    ctrl_msg.pdata = &laser_current;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:get laser current failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = laser_current;
    return OB_SUCCESS;
  }

  int Mx6300_set_laser_time(uint32_t value)
  {
    int ret;
    uint32_t laser_time;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.dataLen = 4;
    for (int i = 0; i < 4; i++)
    {
      ctrl_msg.regaddr = MX6300_CMD_SET_PULSE_WIDTH_ADDR + i;
      laser_time = (value >> (i * 8)) & 0xFF;
      ctrl_msg.pdata = &laser_time;
      ret = obc_sl_spi_write(&ctrl_msg);
      if (ret < 0)
      {
        printf("%s:set laser time failed\n", __FUNCTION__);
        return OB_FAILURE;
      }
    }
    return OB_SUCCESS;
  }
  int Mx6300_get_laser_time(uint32_t *res)
  {
    int ret;
    uint8_t tmpVal[4] = {0};
    uint32_t laser_time;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.dataLen = 4;
    for (uint8_t i = 0; i < 4; i++)
    {
      ctrl_msg.regaddr = MX6300_CMD_GET_PULSE_WIDTH_ADDR + i;
      ctrl_msg.pdata = &laser_time;
      ret = obc_sl_spi_read(&ctrl_msg);
      if (ret < 0)
      {
        printf("%s:get laser current failed\n", __FUNCTION__);
        return OB_FAILURE;
      }
      tmpVal[i] = laser_time & 0xFF;
    }
    *res = tmpVal[0] + (tmpVal[1] << 8) + (tmpVal[2] << 16) + (tmpVal[3] << 24);
    return ret;
  }

  int Mx6300_set_ldp_enable(uint8_t value)
  {
    int ret;
    uint32_t ldp_enable = value == 0 ? 0 : 1;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_LDP_ENALBE_STATUS;
    ctrl_msg.pdata = &ldp_enable;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set ldp  enable failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }

  int Mx6300_get_ldp_enable(uint8_t *res)
  {

    int ret;
    uint32_t ldp_enable;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_LDP_ENALBE_STATUS;
    ctrl_msg.pdata = &ldp_enable;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:get ldp  enable failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = ldp_enable & 0xFF;
    return OB_SUCCESS;
  }

  int Mx6300_set_ldp_calibrate(uint8_t ldp_calibrate)
  {
    int ret;
    uint32_t ldp = (ldp_calibrate == 0 ? 0 : 1);
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_LDP_CALIBRATE;
    ctrl_msg.pdata = &ldp;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set ldp calibrate failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_write_ldp_calibrate_data(uint8_t *pdata)
  {
    return obc_spi_write_ldp_calibrate_data(pdata);
  }
  int Mx6300_get_ldp_data(uint32_t *res)
  {
    int ret;
    uint32_t ldp_data;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_LDP_DATA;
    ctrl_msg.pdata = &ldp_data;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:get ldp  data failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = ldp_data;
    return OB_SUCCESS;
  }

  int Mx6300_get_ldp_scale(uint32_t *res)
  {
    int ret;
    uint32_t ldp_scale;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_LDP_SCALE;
    ctrl_msg.pdata = &ldp_scale;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:get ldp  scale failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = ldp_scale;
    return OB_SUCCESS;
  }
  int Mx6300_set_ldp_scale(uint32_t value)
  {
    int ret;
    uint32_t ldp_scale = value;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_LDP_SCALE;
    ctrl_msg.pdata = &ldp_scale;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s:set ldp  scale failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_flood_control(uint8_t value)
  {
    int ret;
    uint32_t flood_ctl = value == 0 ? 0 : 1;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_SET_FLOOD_MODE_ADDR;
    ctrl_msg.pdata = &flood_ctl;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: flood  control failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_get_flood_status(uint8_t *res)
  {
    int ret;
    uint32_t flood_status;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_CMD_GET_FLOOD_MODE_ADDR;
    ctrl_msg.pdata = &flood_status;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: get flood  status failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = flood_status & 0xFF;
    return OB_SUCCESS;
  }

  int Mx6300_set_laser_flood_led_current(uint32_t value)
  {
    int ret;
    uint32_t flood_current = value;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_FLOOD_LED_CURRENT;
    ctrl_msg.pdata = &flood_current;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set flood  current failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_get_ldp_protect_status(uint8_t *res)
  {
    int ret;
    uint32_t ldp_protect_status;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_LDP_PROTECT_STATUS;
    ctrl_msg.pdata = &ldp_protect_status;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: get ldp protect  status failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = ldp_protect_status & 0xFF;
    return OB_SUCCESS;
  }

  int Mx6300_set_ir_gain(uint32_t value)
  {
    int ret;
    uint32_t ir_gain = value;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_IR_GAIN_ADDR;
    ctrl_msg.pdata = &ir_gain;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set ir gain failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_get_ir_gain(uint32_t *res)
  {
    int ret;
    uint32_t ir_gain;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_IR_GAIN_ADDR;
    ctrl_msg.pdata = &ir_gain;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: get ir gain  status failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = ir_gain;
    return OB_SUCCESS;
  }

  int Mx6300_set_ir_exposure(uint32_t value)
  {
    int ret;
    uint32_t ir_exposure = value;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_IR_EXPO_ADDR;
    ctrl_msg.pdata = &ir_exposure;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set ir exposure failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_get_ir_exposure(uint32_t *res)
  {
    int ret;
    uint32_t ir_exposure;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_IR_EXPO_ADDR;
    ctrl_msg.pdata = &ir_exposure;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: get ir exposure  status failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = ir_exposure;
    return OB_SUCCESS;
  }

  int Mx6300_set_ir_flip(uint8_t value)
  {
    int ret;
    uint32_t ir_flip = value == 0 ? 0 : 1;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_IR_FLIP_ADDR;
    ctrl_msg.pdata = &ir_flip;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set ir flip failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }

  int Mx6300_set_ir_mirror(uint8_t value)
  {
    int ret;
    uint32_t ir_mirror = value == 0 ? 0 : 1;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_IR_MIRROR_ADDR;
    ctrl_msg.pdata = &ir_mirror;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set ir mirror failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_get_ir_mirror(uint8_t *res)
  {
    int ret;
    uint32_t ir_mirror;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_IR_MIRROR_ADDR;
    ctrl_msg.pdata = &ir_mirror;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: get ir mirror  status failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = ir_mirror & 0xFF;
    return OB_SUCCESS;
  }

  int Mx6300_set_depth_hole_filter(uint32_t value)
  {
    int ret;
    uint32_t depth_hole_filter = value;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_DEPTH_HOLE_FILTER;
    ctrl_msg.pdata = &depth_hole_filter;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set depth hole filter failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }

  int Mx6300_set_depth_mirror(uint8_t value)
  {
    int ret;
    uint32_t depth_mirror = value == 0 ? 0 : 1;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_DEPTH_MIRROR;
    ctrl_msg.pdata = &depth_mirror;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set depth mirror failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_get_depth_mirror(uint8_t *res)
  {
    int ret;
    uint32_t depth_mirror;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_DEPTH_MIRROR;
    ctrl_msg.pdata = &depth_mirror;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: get ir mirror  status failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = depth_mirror & 0xFF;
    return OB_SUCCESS;
  }

  int Mx6300_set_depth_d2c_mode(uint8_t value)
  {
    int ret;
    uint32_t d2c = value == 0 ? 0 : 1;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_DEPTH_D2C;
    ctrl_msg.pdata = &d2c;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set depth d2c failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_get_depth_d2c_mode(uint8_t *res)
  {
    int ret;
    uint32_t d2c;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_DEPTH_D2C;
    ctrl_msg.pdata = &d2c;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: get ir mirror  status failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = d2c & 0xFF;
    return OB_SUCCESS;
  }

  int Mx6300_set_postfilter_ncost_thresh(uint32_t value)
  {
    int ret;
    uint32_t postfilter_thresh = value;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_POSTFILTER_NCOST_THRESH;
    ctrl_msg.pdata = &postfilter_thresh;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set postfilter thresh  failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }

  int Mx6300_set_threshfilter(uint32_t value)
  {
    int ret;
    uint32_t thresh_filter = value;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_THRESHFILTER;
    ctrl_msg.pdata = &thresh_filter;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set  thresh filter failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_set_threshfilter_thresh(uint32_t value)
  {
    int ret;
    uint32_t thresh_filter_thresh = value;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_THRESHFILTER_THRESH;
    ctrl_msg.pdata = &thresh_filter_thresh;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set  thresh filter thresh failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }

  int Mx6300_set_postfilter(uint32_t value)
  {
    int ret;
    uint32_t postfilter = value;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_POSTFILTER;
    ctrl_msg.pdata = &postfilter;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set  post filter  failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }

  int Mx6300_set_depth_postfilter_threshhold(uint32_t value)
  {
    int ret;
    uint32_t postfilter_thresh = value;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_DEPTH_POSTFILTER_THRESHOLD;
    ctrl_msg.pdata = &postfilter_thresh;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set detph posffilter threshholds  failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_get_depth_postfilter_threshhold(uint32_t *res)
  {
    int ret;
    uint32_t postfilter_thresh;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_DEPTH_POSTFILTER_THRESHOLD;
    ctrl_msg.pdata = &postfilter_thresh;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: get detph posffilter threshholds  failed\n", __FUNCTION__);
      return OB_FAILURE;
      *res = postfilter_thresh;
    }
    return OB_SUCCESS;
  }

  int Mx6300_set_rectify_enable(uint8_t value)
  {
    int ret;
    uint32_t recitfy_enable = value == 0 ? 0 : 1;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_RECTIFY_ENABLE;
    ctrl_msg.pdata = &recitfy_enable;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set rectify enable  failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_get_rectify_enable(uint8_t *res)
  {
    int ret;
    uint32_t recitfy_enable;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_RECTIFY_ENABLE;
    ctrl_msg.pdata = &recitfy_enable;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: get rectify enable  status failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = recitfy_enable & 0xFF;
    return OB_SUCCESS;
  }
  int Mx6300_get_tca_enable(uint8_t *res)
  {
    int ret;
    uint32_t tca_enable;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_TCA_ENABLE;
    ctrl_msg.pdata = &tca_enable;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: get tca enable  status failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = tca_enable & 0xFF;
    return OB_SUCCESS;
  }
  int Mx6300_set_tca_enable(uint8_t value)
  {
    int ret;
    uint32_t tca_enable = value == 0 ? 0 : 1;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_TCA_ENABLE;
    ctrl_msg.pdata = &tca_enable;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set tca enable  failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }

int Mx6300_get_tec_enable(uint8_t *res)
  {
    int ret;
    uint32_t tec_enable;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_TEC_ENABLE;
    ctrl_msg.pdata = &tec_enable;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: get tec enable  status failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *res = tec_enable & 0xFF;
    return OB_SUCCESS;
  }
  int Mx6300_set_tec_enable(uint8_t value)
  {
    int ret;
    uint32_t tec_enable = value == 0 ? 0 : 1;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_SET_TEC_ENABLE;
    ctrl_msg.pdata = &tec_enable;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: set tec enable  failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_get_componet_temp(Componet_temp *temp)
  {
    int ret;
    uint32_t tmp;
    float tmpf;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_LDM_TEMP;
    ctrl_msg.pdata = &tmp;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: get ldm temperature failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
     memcpy(&tmpf,&tmp,4);
    temp->ldm_temp = tmpf ;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_IR_TEMP;
    ctrl_msg.pdata = &tmp;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: get ir temperature failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
       memcpy(&tmpf,&tmp,4);
    temp->ir_temp = tmpf ;
    ctrl_msg.regaddr = MX6300_RAW_CMD_GET_RGB_TEMP;
    ctrl_msg.pdata = &tmp;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: get rgb temperature failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
      memcpy(&tmpf,&tmp,4);
    temp->rgb_temp = tmpf ;
 //printf("conv:0x%x\n",tmpconv);
    return OB_SUCCESS;
  }
  int Mx6300_read_ahb(uint32_t addr, uint32_t *data)
  {
    int ret;
    uint32_t data_;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = addr;
    ctrl_msg.pdata = &data_;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_read(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: write ahb  failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    *data = data_;
    return OB_SUCCESS;
  }
  int Mx6300_write_ahb(uint32_t addr, uint32_t data)
  {
    int ret;
    uint32_t data_ = data;
    spi_ctrl_msg ctrl_msg = {0};
    ctrl_msg.spi_fd = gspifd;
    ctrl_msg.dev_type = SPI_DEV_MX6300;
    ctrl_msg.regaddr = addr;
    ctrl_msg.pdata = &data_;
    ctrl_msg.dataLen = 4;
    ret = obc_sl_spi_write(&ctrl_msg);
    if (ret < 0)
    {
      printf("%s: write ahb  failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
  int Mx6300_read_i2c(mx6300_i2c_ctrl *i2c_ctrl)
  {
    uint32_t data;
    int ret;
    /*ret= obc_sl_spi_write_i2c(i2c_ctrl->bus, i2c_ctrl->slave_addr,
                                   i2c_ctrl->reg, i2c_ctrl->reg_len,
                                  0, i2c_ctrl->data_len);
    if (ret < 0)
    {
      printf("%s: write i2c(before reading) failed\n", __FUNCTION__);
      return OB_FAILURE;
    }*/
    usleep(3000);
    ret = obc_sl_spi_read_i2c(i2c_ctrl->bus, i2c_ctrl->slave_addr,
                              i2c_ctrl->reg, i2c_ctrl->reg_len,
                              &data, i2c_ctrl->data_len);
    if (ret < 0)
    {
      printf("%s: read i2c  failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    i2c_ctrl->data = data;
    return OB_SUCCESS;
  }
  int Mx6300_write_i2c(mx6300_i2c_ctrl *i2c_ctrl)
  {
    int ret = obc_sl_spi_write_i2c(i2c_ctrl->bus, i2c_ctrl->slave_addr,
                                   i2c_ctrl->reg, i2c_ctrl->reg_len,
                                   i2c_ctrl->data, i2c_ctrl->data_len);
    if (ret < 0)
    {
      printf("%s: write i2c  failed\n", __FUNCTION__);
      return OB_FAILURE;
    }
    return OB_SUCCESS;
  }
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
