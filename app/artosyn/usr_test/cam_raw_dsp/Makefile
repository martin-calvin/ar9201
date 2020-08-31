#
#------------------------------------------

PROGRAM   = cam_raw_dsp

# Define files
#------------------------------------------

SRCDIRS   = ./
SRCDIRS   += ./Include \

# Define flags
#------------------------------------------
USR_LIB_PATH =../../../../lib/usr_lib
KERNEK_MODULER =../../../../kernel_module
LDFLAGS   += -L../../../../output/staging/target/usr/lib/ -lpthread -lartosyn -lar_log -lmultimedia -lar_fifo -lavp_buffer
LDFLAGS   += -L./lib/ -ltof_calib_params_parser

             

CFLAGS    += -I./ \
             -I./Include \
             -I$(USR_LIB_PATH)/multimedia \
             -I$(KERNEK_MODULER)/rpc_fs\
             -I$(USR_LIB_PATH)/avp_buffer/ar_picture_api \
             -I$(USR_LIB_PATH)/avp_buffer/ar_video_stream \
             -DUSR_INCLUDE \
             -I../../../../kernel/mods/linux-linaro-stable-lsk-v4.9-17.07/drivers/media/platform/ar_cam/ \
             -I$(USR_LIB_PATH)/ar_log \
             -I$(USR_LIB_PATH)/ar_fifo \
             -I$(USR_LIB_PATH)/multimedia/pipeline_ctrl \

CXXFLAGS += -std=gnu++11 -std=c++11 -std=gnu++11 $(CFLAGS)

# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

