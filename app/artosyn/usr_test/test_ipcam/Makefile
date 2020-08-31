# Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------

PROGRAM   = test_ipcam

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------

LDFLAGS   = -L$(STAGING_DIR)/target/usr/lib -lpthread -lipcam_client \
			-lglib-2.0 -lgmodule-2.0 -lgobject-2.0 -lgthread-2.0 -lgio-2.0 -lz -lpcre -lffi
CFLAGS    += -I. -I-ggdib -I$(USR_LIB_PATH)/lowdelay_client \
              -I$(STAGING_DIR)/target/usr/include/glib-2.0 \
              -I$(STAGING_DIR)/target/usr/include/glib-2.0/glib \
              -I$(STAGING_DIR)/target/usr/include/glib-2.0/gio \
              -I$(STAGING_DIR)/target/usr/lib/glib-2.0/include

# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

