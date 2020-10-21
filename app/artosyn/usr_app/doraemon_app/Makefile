# Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------

PROGRAM     = doraemon_app
ARIES_APP_VERSION = "v1.0.0"
SDK_GIT_VERSION   = "$(shell git log -1 --format=%H)"
COMPILE_TIME      = "$(shell date +"%Y-%m-%d %H:%M:%S")"


# Define files
#------------------------------------------
SRCDIRS   = ./
SRCDIRS  += ./util \
            ./usb_bulk \
            ./protocol \
            ./rgb_uvc_service \
            ./tof_stream \
            ./tof_uvc \
            ./tof_dsp \
            ./tof_dsp/Include \
            ./drivers \
            ./depth_process \
            ./event	\
            ./wdt

# Define flags
#------------------------------------------
SDK_PATH       =../../../../
USR_LIB_PATH   =$(SDK_PATH)/lib/usr_lib
KERNEK_MODULER =$(SDK_PATH)/kernel_module
#STAGING_DIR    =$(SDK_PATH)/prebuild/staging

USER_FLAGS += -mfpu=neon-vfpv4 -O2
USER_FLAGS += -DARIES_APP_VERSION=\"$(ARIES_APP_VERSION)\" \
              -DSDK_GIT_VERSION=\"$(SDK_GIT_VERSION)\"     \
              -DCOMPILE_TIME=\"$(COMPILE_TIME)\"  \
              -DUSR_INCLUDE \
               \
              -DLTM_DESC \
              -DUSE_LTC \
              -DLTC_SOURCE \
              -DLTC_EASY  
              #-DENABALE_ALL_LOG			

              

# Define library
#------------------------------------------	
LDFLAGS  += -L$(SDK_PATH)/output/staging/target/usr/lib \
            -L$(SDK_PATH)/output/staging/target/lib  \
            -L$(SDK_PATH)/output/staging/target/include  \
            -L./drivers \
            -L./tof_dsp/lib -ltof_calib_params_parser \
            -lpthread -lm -lglib-2.0 -lgmodule-2.0 -lgobject-2.0 -lgthread-2.0 -lgio-2.0 -lz -lpcre -lffi -lpipeline_ctl \
            -lartosyn \
            -lpthread \
            -lar_log \
            -lavp_buffer \
            -lmultimedia \
            -lobc_tof_drv \
            -lremote_i2c \
            -lar_fifo \
            -lar_lancher \
            -lar_flash 
            
            

# Define include
#------------------------------------------	
INCS     += -I./ \
            -I./include/ \
            -I./include/libyuv \
            -I./include/kernel\
            -I./protocol \
            -I./util \
            -I./event \
            -I./rgb_uvc_service \
            -I./tof_stream \
            -I./tof_uvc \
            -I./usb_bulk \
            -I./tof_dsp \
            -I./tof_dsp/Include \
            -I./depth_process \
            -I./drivers/tof_sensor_lib \
            -I./wdt \
            -I$(USR_LIB_PATH)/artosyn/inc/ion \
            -I$(USR_LIB_PATH)/avp_buffer/ar_video_stream \
            -I$(USR_LIB_PATH)/multimedia/pipeline_ctrl \
            -I$(USR_LIB_PATH)/pipeline_ctl \
            -I$(USR_LIB_PATH)/ar_lancher \
            -I$(KERNEK_MODULER)/rpc_fs \
            -I$(STAGING_DIR)/target/khdr/include \
            -I$(USR_LIB_PATH)/ar_log \
            -I$(STAGING_DIR)/target/include \
            -I$(STAGING_DIR)/target/usr/include/ \
            -I$(STAGING_DIR)/target/usr/include/glib-2.0 \
            -I$(STAGING_DIR)/target/usr/include/glib-2.0/glib \
            -I$(STAGING_DIR)/target/usr/include/glib-2.0/gio \
            -I$(STAGING_DIR)/target/usr/lib/glib-2.0/include \
            -I$(STAGING_DIR)/target/include/ \
            -I$(SDK_PATH)/kernel/mods/linux-linaro-stable-lsk-v4.9-17.07/drivers/media/platform/ar_cam/

CFLAGS   += -DUSR_INCLUDE $(INCS) $(USER_FLAGS)
CXXFLAGS += -std=gnu++11 -std=c++11 -std=gnu++11 -O2 -fopenmp $(INCS) $(USER_FLAGS)

LOCAL_LIB += ./lib/libyuv.a
LOCAL_LIB += ./lib/libzlog.a
LOCAL_LIB += -L./usb_bulk/libs -ltomcrypt -ltommath -luuid
LOCAL_LIB += -L./lib/ -lobc_sl_drv -lpostfilter -lobrefparser


# Include make rule file
#------------------------------------------
include $(SDK_PATH)/makery/usr_app_rule.lmk

