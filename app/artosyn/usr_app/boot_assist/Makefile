# Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------

PROGRAM   = boot_assist

# Define files
#------------------------------------------

SRCDIRS   = src/

# Define flags
#------------------------------------------

LDFLAGS   = -lartosyn -lpthread -lcjson -L$(STAGING_DIR)/target/usr/lib
CFLAGS    += -O3 -I./inc \
	     -I$(STAGING_DIR)/target/usr/include

# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

