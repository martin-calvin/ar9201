# Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------
SHARED_LIBRARY = libobc_sl_drv.so
PROGRAM   = obc_sl_drv

# Define files
#------------------------------------------

SRCDIRS   = ./
#INSTALL_HEADERS := obc_sl_drv.h
# Define flags
#------------------------------------------
#LDFLAGS   = -lremote_spi -lpthread  -lartosyn
CFLAGS  += -fPIC
USR_LIB_PATH =../../../../lib/usr_lib

KERNEK_MODULER =../../../../kernel_module

LDFLAGS   += -L../../../../output/staging/target/usr/lib/ -lpthread -lartosyn -lar_log -lmultimedia -lar_fifo -lavp_buffer \
                            -L./3rd/lib/  -lobrefparser \

CFLAGS    += -I./ \
             -I./3rd/include \
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


