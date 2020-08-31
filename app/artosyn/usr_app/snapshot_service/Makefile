#
#------------------------------------------

PROGRAM   = snapshot_service

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------
USR_LIB_PATH =../../../../lib/usr_lib
KERNEK_MODULER =../../../../kernel_module
LDFLAGS   += -lpthread -lartosyn -lar_log -lavp_buffer
CFLAGS    += -I./ \
             -I$(USR_LIB_PATH)/artosyn/inc/ion \
             -I$(USR_LIB_PATH)/avp_buffer/ar_video_stream \
             -I$(KERNEK_MODULER)/rpc_fs\
             -DUSR_INCLUDE

             

# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

