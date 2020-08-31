# Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------

PROGRAM   = test_spi_seic

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------

USR_LIB_PATH =../../../../lib/usr_lib
LDFLAGS  = -lspi_seic -lar_gpio
CFLAGS    += -I$(USR_LIB_PATH)/spi_seic/ \
             -I ./


# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

