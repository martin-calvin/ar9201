#
#------------------------------------------

PROGRAM   = xvr_client_dbus

# Define files
#------------------------------------------

SRCDIRS   = ./
# Define flags
#------------------------------------------
USR_LIB_PATH =../../../../lib/usr_lib
KERNEK_MODULER =../../../../kernel_module
LDFLAGS  = -lartosyn -lpthread -lar_log -lavp_buffer -lmultimedia -lar_lancher
LDFLAGS +=-L../../../../output/staging/target/usr/lib -L../../../../output/staging/target/lib  -lpthread -lm -lglib-2.0 -lgmodule-2.0 -lgobject-2.0 -lgthread-2.0 -lgio-2.0 -lz -lpcre -lffi -lpipeline_ctl -lxvr_gdbus 
CFLAGS    += -I./ \
             -I$(USR_LIB_PATH)/artosyn/inc/ion \
             -I$(USR_LIB_PATH)/avp_buffer/ \
             -I$(USR_LIB_PATH)/avp_buffer/base_api \
             -I$(USR_LIB_PATH)/avp_buffer/ar_video_stream \
             -I$(USR_LIB_PATH)/avp_buffer/ar_picture_api \
             -I$(KERNEK_MODULER)/rpc_fs\
             -I$(USR_LIB_PATH)/artosyn/inc/ion \
             -I$(USR_LIB_PATH)/avp_buffer/ar_video_stream \
             -I$(USR_LIB_PATH)/multimedia/pipeline_ctrl \
             -I$(USR_LIB_PATH)/pipeline_ctl \
             -I$(USR_LIB_PATH)/ar_lancher \
             -I$(KERNEK_MODULER)/rpc_fs \
             -I$(STAGING_DIR)/target/khdr/include \
             -DUSR_INCLUDE \
             -I$(USR_LIB_PATH)/ar_log \
             -I$(STAGING_DIR)/target/include \
	     -I$(STAGING_DIR)/target/usr/include/ \
	     -I$(STAGING_DIR)/target/usr/include/glib-2.0 \
             -I$(STAGING_DIR)/target/usr/include/glib-2.0/glib \
	     -I$(STAGING_DIR)/target/usr/include/glib-2.0/gio \
             -I$(STAGING_DIR)/target/usr/lib/glib-2.0/include \
             -I$(STAGING_DIR)/target/include/ \
	     -I$(STAGING_DIR)/include/ \
	     -I. -ggdb \
             -I../../../../kernel/mods/linux-linaro-stable-lsk-v4.9-17.07/include/ \
             -I../../../../kernel/mods/linux-linaro-stable-lsk-v4.9-17.07/drivers/media/platform/ar_cam/ \
             -DUSR_INCLUDE
			 
CXXFLAGS  += -I$(STAGING_DIR)/target/include \
	     -I$(STAGING_DIR)/target/usr/include/ \
	     -I$(STAGING_DIR)/target/usr/include/glib-2.0 \
             -I$(STAGING_DIR)/target/usr/include/glib-2.0/glib \
	     -I$(STAGING_DIR)/target/usr/include/glib-2.0/gio \
             -I$(STAGING_DIR)/target/usr/lib/glib-2.0/include \
             -I$(STAGING_DIR)/target/include/
CFLAGS    += 
LOCAL_LIB += 

# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

