# Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------

PROGRAM   = test_g711

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------
LDFLAGS   = -lar_g711 -lpthread  
CFLAGS    += -I. -ggdb \
             -DUSR_INCLUDE

# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

