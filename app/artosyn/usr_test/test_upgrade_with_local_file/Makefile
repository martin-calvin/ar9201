# Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------

PROGRAM   = test_upgrade_with_local_file

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------

LDFLAGS   = -lartosyn -lar_flash
CFLAGS    += -I./inc
CFLAGS    += -DLTM_DESC -DUSE_LTC -DLTC_SOURCE -DLTC_EASY
LOCAL_LIB += -L./libs -ltomcrypt -ltommath -luuid

# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

