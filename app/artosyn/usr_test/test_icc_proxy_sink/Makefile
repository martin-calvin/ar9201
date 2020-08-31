#
#------------------------------------------

PROGRAM   = test_icc_proxy_sink

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
             -I$(USR_LIB_PATH)/avp_buffer/ \
             -I$(USR_LIB_PATH)/avp_buffer/base_api \
             -I$(USR_LIB_PATH)/avp_buffer/ar_video_stream \
             -I$(USR_LIB_PATH)/avp_buffer/ar_picture_api \
             -I$(KERNEK_MODULER)/rpc_fs\
             -DUSR_INCLUDE

             

# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

