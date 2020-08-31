#
#------------------------------------------
SHARED_LIBRARY = libobc_tof_drv.so
PROGRAM   = obc_tof_drv

# Define files
#------------------------------------------

SRCDIRS   = ./
SRCDIRS  += ./driver \
            ./app \
            ./csp \
            ./tof_sensor_lib

INSTALL_HEADERS := obc_tof_drv.h

# Define flags
#------------------------------------------
AR_SDK_PATH = ../../../../
USR_LIB_PATH =$(AR_SDK_PATH)/lib/usr_lib
KERNEK_MODULER =$(AR_SDK_PATH)/kernel_module
LDFLAGS   += -L$(AR_SDK_PATH)/output/staging/target/usr/lib \
             -L$(AR_SDK_PATH)/output/staging/target/lib  \
             -lpthread -lartosyn -lar_log -lmultimedia -lar_fifo -lavp_buffer -lremote_i2c -lm
CFLAGS    += -I./ \
             -I./driver \
             -I./app \
             -I./csp \
             -I./tof_sensor_lib\
             -I$(USR_LIB_PATH)/multimedia \
             -I$(KERNEK_MODULER)/rpc_fs\
             -I$(USR_LIB_PATH)/avp_buffer/ar_picture_api \
             -I$(USR_LIB_PATH)/avp_buffer/ar_video_stream \
             -DUSR_INCLUDE \
             -I$(AR_SDK_PATH)/kernel/mods/linux-linaro-stable-lsk-v4.9-17.07/drivers/media/platform/ar_cam/ \
             -I$(AR_SDK_PATH)/prebuild/staging/target/include/ \
             -I$(USR_LIB_PATH)/ar_log \
             -I$(USR_LIB_PATH)/ar_fifo \
             -I$(USR_LIB_PATH)/multimedia/pipeline_ctrl \

# Include make rule file
#------------------------------------------
include $(AR_SDK_PATH)/makery/usr_app_rule.lmk
