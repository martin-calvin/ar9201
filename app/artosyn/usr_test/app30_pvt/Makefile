# Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------

PROGRAM   = app30_pvt

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------
LDFLAGS   = -lmultimedia -lpthread  -lartosyn -lar_log -lavp_buffer -lar_lancher
USR_LIB_PATH =../../../../lib/usr_lib
CFLAGS    += -I. -ggdb \
             -I../../../../kernel/mods/linux-linaro-stable-lsk-v4.9-17.07/drivers/media/platform/ar_cam/ \
             -DUSR_INCLUDE
LDFLAGS +=-L../../../../output/staging/target/usr/lib -L../../../../output/staging/target/lib  -lpthread -lm -lglib-2.0 -lgmodule-2.0 -lgobject-2.0 -lgthread-2.0 -lgio-2.0 -lz -lpcre -lffi -lpipeline_ctl 
CFLAGS  +=-I$(STAGING_DIR)/target/include \
	     -I$(STAGING_DIR)/target/usr/include/ \
	     -I$(STAGING_DIR)/target/usr/include/glib-2.0 \
             -I$(STAGING_DIR)/target/usr/include/glib-2.0/glib \
	     -I$(STAGING_DIR)/target/usr/include/glib-2.0/gio \
             -I$(STAGING_DIR)/target/usr/lib/glib-2.0/include \
             -I$(STAGING_DIR)/target/include/ \
             -I$(USR_LIB_PATH)/pipeline_ctl \


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

