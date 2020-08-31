# Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------

PROGRAM   = artosyn_upgrade

# Define files
#------------------------------------------

SRCDIRS   = ./src

# Define flags
#------------------------------------------
LDFLAGS   = -lar_flash
CFLAGS    += -DLTM_DESC -DUSE_LTC -DLTC_SOURCE -DLTC_EASY
LOCAL_LIB += -L./libs -ltomcrypt -ltommath -luuid

# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

