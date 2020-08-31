# Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------

PROGRAM   = test_dzoom

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------
LDFLAGS   = -lmultimedia -lpthread  -lartosyn
CFLAGS    += -I. -ggdb \
             -I../../../../kernel/mods/linux-linaro-stable-lsk-v4.9-17.07/drivers/media/platform/ar_cam/ \
             -DUSR_INCLUDE

# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

