# Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------

PROGRAM   = test_send_data

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------

LDFLAGS  = -lartosyn
CFLAGS    += -I./ \
             -I$(STAGING_DIR)/target/khdr/include \
             -DUSR_INCLUDE \
             -I ../../../../kernel/mods/linux-linaro-stable-lsk-v4.9-17.07/drivers/media/platform/ar_cam/

# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

