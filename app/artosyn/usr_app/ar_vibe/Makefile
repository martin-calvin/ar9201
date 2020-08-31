#
#------------------------------------------

PROGRAM   = ar_vibe

# Define files
#------------------------------------------

SRCDIRS   = . 
# Define flags
#------------------------------------------
USR_LIB_PATH =../../../../lib/usr_lib
KERNEK_MODULER =../../../../kernel_module
LDFLAGS  = -lartosyn -lpthread -lar_log -lavp_buffer -lmultimedia -lar_lancher -lm -lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui -lar_vibe 
LDFLAGS +=-L../../../../output/staging/target/usr/lib -L../../../../output/staging/target/lib  -lpthread -lm -lglib-2.0 -lgmodule-2.0 -lgobject-2.0 -lgthread-2.0 -lgio-2.0 -lz -lpcre -lffi -lpipeline_ctl 
CFLAGS    += -I./ -D_FILE_OFFSET_BITS=64
CFLAGS    += -I./ \
 	     -I$(STAGING_DIR)/target/include/opencv2/opencv_core \
 	     -I$(STAGING_DIR)/target/include/opencv2/opencv_imgproc \
             -I$(STAGING_DIR)/target/include/opencv2/opencv_imgcodecs \
	     -I$(STAGING_DIR)/target/include/opencv2/opencv_highgui  \
	     -I$(STAGING_DIR)/target/usr/include/ \
             -I$(USR_LIB_PATH)/artosyn/inc/ion \
             -I$(USR_LIB_PATH)/avp_buffer/ \
             -I$(USR_LIB_PATH)/avp_buffer/base_api \
             -I$(USR_LIB_PATH)/avp_buffer/ar_video_stream \
             -I$(USR_LIB_PATH)/avp_buffer/ar_picture_api \
             -I$(KERNEK_MODULER)/rpc_fs\
             -I$(USR_LIB_PATH)/multimedia/pipeline_ctrl \
             -I$(USR_LIB_PATH)/pipeline_ctl \
             -I$(USR_LIB_PATH)/ceva_scale \
             -I$(USR_LIB_PATH)/ar_lancher \
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
             -DUSR_INCLUDE \
	     -Ofast -mfpu=neon-vfpv4
			 
CXXFLAGS  += -I ./ \
 	     -I$(STAGING_DIR)/target/include/opencv2/opencv_core \
 	     -I$(STAGING_DIR)/target/include/opencv2/opencv_imgproc \
             -I$(STAGING_DIR)/target/include/opencv2/opencv_imgcodecs \
	     -I$(STAGING_DIR)/target/include/opencv2/opencv_highgui  \
	     -I$(STAGING_DIR)/target/usr/include/ \
             -I$(USR_LIB_PATH)/artosyn/inc/ion \
             -I$(USR_LIB_PATH)/avp_buffer/ \
             -I$(USR_LIB_PATH)/avp_buffer/base_api \
             -I$(USR_LIB_PATH)/avp_buffer/ar_video_stream \
             -I$(USR_LIB_PATH)/avp_buffer/ar_picture_api \
             -I$(KERNEK_MODULER)/rpc_fs\
             -I$(USR_LIB_PATH)/multimedia/pipeline_ctrl \
             -I$(USR_LIB_PATH)/pipeline_ctl \
             -I$(USR_LIB_PATH)/ceva_scale \
             -I$(USR_LIB_PATH)/ar_lancher \
             -I$(STAGING_DIR)/target/khdr/include \
             -DUSR_INCLUDE \
	     -I$(STAGING_DIR)/target/include \
	     -I$(STAGING_DIR)/target/usr/include/ \
	     -I$(STAGING_DIR)/target/usr/include/glib-2.0 \
             -I$(STAGING_DIR)/target/usr/include/glib-2.0/glib \
	     -I$(STAGING_DIR)/target/usr/include/glib-2.0/gio \
             -I$(STAGING_DIR)/target/usr/lib/glib-2.0/include \
             -I$(STAGING_DIR)/target/include/ \
	     -I$(STAGING_DIR)/include/ \
#CFLAGS    += 
LOCAL_LIB += 

# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

