#
#------------------------------------------

PROGRAM   = ar_dvfs_service

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------
USR_LIB_PATH =../../../../lib/usr_lib
KERNEK_MODULER =../../../../kernel_module
LDFLAGS   = -lartosyn -lpthread
CFLAGS    += -I./ -ggdb $(KERNEL_EXTRA_CFLAG)






# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

