#
#------------------------------------------

PROGRAM   = ar_dbg_service

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------
ARSDK = ../../../..
USR_LIB_PATH =../../../../lib/usr_lib
KERNEK_MODULER =../../../../kernel_module
LDFLAGS   += -L../../../../output/staging/target/usr/lib/ -lpthread -lcam_tuning_server -lartosyn -lar_log  -lar_fifo -lar_lancher -lmultimedia -lcjson -lar_bb 
CFLAGS    += -I./ \
             -I$(USR_LIB_PATH)/cam_tuning_server \
             -I$(USR_LIB_PATH)/artosyn/inc/ion \
             -I$(USR_LIB_PATH)/artosyn/inc/backtrace \
             -I$(KERNEK_MODULER)/ardis/ \
             -I$(USR_LIB_PATH)/ar_log \
             -I$(USR_LIB_PATH)/ar_bb \
             -I$(USR_LIB_PATH)/include \
             -I$(USR_LIB_PATH)/ar_fifo \
             -I$(USR_LIB_PATH)/ar_lancher \
             -L../../../../third_party/cjson/cJSON-master/ \
             -I../../../../kernel/mods/linux-linaro-stable-lsk-v4.9-17.07/drivers/media/platform/ar_cam/ \
             -DUSR_INCLUDE
# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

