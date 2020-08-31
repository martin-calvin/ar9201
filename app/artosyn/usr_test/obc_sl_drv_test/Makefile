# Define target, only one type can be choosed: program, static library or dynamic library.

PROGRAM   = obc_sl_drv_test

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------
#LDFLAGS   = -lremote_spi -lpthread  -lartosyn
KERNEK_MODULER =../../../../kernel_module
LDFLAGS   += -L../../../../output/staging/target/usr/lib/ \
                            -L ./ -lpthread -lartosyn -lar_log -lmultimedia -lar_fifo -lavp_buffer -lobc_sl_drv -lobrefparser
CFLAGS    += -I./ \
             -I$(USR_LIB_PATH)/multimedia \
             -I$(KERNEK_MODULER)/rpc_fs\
             -I$(USR_LIB_PATH)/avp_buffer/ar_picture_api \
             -I$(USR_LIB_PATH)/avp_buffer/ar_video_stream \
             -DUSR_INCLUDE \
             -I../../../../kernel/mods/linux-linaro-stable-lsk-v4.9-17.07/drivers/media/platform/ar_cam/ \
             -I$(USR_LIB_PATH)/ar_log \
             -I$(USR_LIB_PATH)/ar_fifo \
             -I$(USR_LIB_PATH)/multimedia/pipeline_ctrl \


# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk


