# Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------

PROGRAM   = ar_dsp_rpc_svr

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------
LDFLAGS   = -lartosyn -lpthread -lm -L ../../../../output/staging/target/usr/lib
CFLAGS    += -I./inc -I$(STAGING_DIR)/target/include 

CXXFLAGS  += -I./inc -I$(STAGING_DIR)/target/include 



CFLAGS    +=
LOCAL_LIB +=

CFLAGS    += -O2 -fomit-frame-pointer -ftree-vectorize -mfpu=neon-vfpv4 -mfloat-abi=hard 

CXXFLAGS    += -O2 -fomit-frame-pointer -ftree-vectorize -mfpu=neon-vfpv4 -mfloat-abi=hard 

LOCAL_LIB += 


# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

