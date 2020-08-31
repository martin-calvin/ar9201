#Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------

PROGRAM   = ar_dsp_bootup

# Define files
#------------------------------------------

SRCDIRS   = ./src

# Define flags
#------------------------------------------

LDFLAGS   = -lartosyn -L../../../../output/staging/target/lib
CFLAGS    += -I./inc -I../../../output/staging/target/include -I../../../output/staging/target/include
CFLAGS    += -g $(CEVA_EXTRA_CFLAG) 
LOCAL_LIB += 

# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

