#
#------------------------------------------

PROGRAM   = ar_logcat

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------
USR_LIB_PATH =../../../../lib/usr_lib
KERNEK_MODULER =../../../../kernel_module
LDFLAGS   += -lpthread -lar_log -lartosyn -L$(STAGING_DIR)/target/usr/lib/ -lLogcat_Tool_Sets
CFLAGS    += -I./ \
             -I$(USR_LIB_PATH)/artosyn/inc/ion \
             -I$(USR_LIB_PATH)/ar_log \
             -I$(KERNEK_MODULER)/rpc_fs \
             -I$(STAGING_DIR)/target/usr/include \
             -DUSR_INCLUDE



# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

