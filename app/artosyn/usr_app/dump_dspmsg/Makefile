#
#------------------------------------------

PROGRAM   = dump_dspmsg

# Define files
#------------------------------------------

SRCDIRS   = ./

# Define flags
#------------------------------------------

LDFLAGS   = -lartosyn -lpthread -L$(STAGING_DIR)/target/usr/lib/ -lLogcat_Tool_Sets
CFLAGS    += -I./ -ggdb -I$(STAGING_DIR)/target/usr/include

# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

