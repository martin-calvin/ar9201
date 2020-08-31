# Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------

PROGRAM   = test_remote_spi

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------
#LDFLAGS   = -lremote_spi -lpthread  -lartosyn
LDFLAGS   =  -lpthread  -lartosyn
CFLAGS    += -I. -ggdb \
             -DUSR_INCLUDE

# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

