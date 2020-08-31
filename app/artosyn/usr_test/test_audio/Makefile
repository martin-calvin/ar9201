# Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------

PROGRAM   = test_audio

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------
USR_LIB_PATH = ../../../../lib/usr_lib
KERNEK_MODULER =../../../../kernel_module
LDFLAGS   = -lartosyn -lpthread -lmultimedia -lavp_buffer
LDFLAGS   += -L../../../../output/staging/target/usr/lib -L../../../../output/staging/target/lib 
CFLAGS    += -I./inc -I./
CFLAGS    += -I$(USR_LIB_PATH)/multimedia/framework
CFLAGS    += -I$(USR_LIB_PATH)/avp_buffer/base_api
CFLAGS    += -I$(KERNEK_MODULER)/rpc_fs
CFLAGS    += -I$(STAGING_DIR)/target/khdr/include \
             -I../../../../kernel/mods/linux-linaro-stable-lsk-v4.9-17.07/include/ \
             -I../../../../kernel/mods/linux-linaro-stable-lsk-v4.9-17.07/drivers/media/platform/ar_cam/ \
             -DUSR_INCLUDE
# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

