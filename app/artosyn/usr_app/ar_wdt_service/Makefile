#
#------------------------------------------

PROGRAM   = ar_wdt_service

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------
LDFLAGS   += -lpthread -lartosyn
CFLAGS    += -I./inc \
            -ggdb \
            -DUSR_INCLUDE
# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

