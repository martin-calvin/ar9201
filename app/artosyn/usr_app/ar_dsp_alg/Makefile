# Define target, only one type can be choosed: program, static library or dynamic library.
#------------------------------------------

PROGRAM   = ar_dsp_alg

# Define files
#------------------------------------------

SRCDIRS   = ./src

# Define flags
#------------------------------------------
ifeq ($(CEVA_SWEEPER_PROJ), y)
LDFLAGS   = -lartosyn -lpthread -lavp_buffer -lmultimedia -lm -lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui \
			-lglib-2.0 -lgmodule-2.0 -lgobject-2.0 -lgthread-2.0 -lgio-2.0 -lz -lpcre -lffi -lar_sweeper_gdbus -lar_distance_calc\
			-L ../../../../output/staging/target/usr/lib
CFLAGS    += -I./inc -I$(STAGING_DIR)/target/include \
			 -I$(STAGING_DIR)/target/include/opencv2/opencv_core \
 	     	 -I$(STAGING_DIR)/target/include/opencv2/opencv_imgproc \
         	 -I$(STAGING_DIR)/target/include/opencv2/opencv_imgcodecs \
	     	 -I$(STAGING_DIR)/target/include/opencv2/opencv_highgui  \
	     	 -I$(STAGING_DIR)/target/usr/include/ \
			 -I$(STAGING_DIR)/target/usr/include/glib-2.0 \
	     	 -I$(STAGING_DIR)/target/usr/include/glib-2.0/glib \
	     	 -I$(STAGING_DIR)/target/usr/include/glib-2.0/gio \
	     	 -I$(STAGING_DIR)/target/usr/lib/glib-2.0/include

CXXFLAGS  += -I./inc -I$(STAGING_DIR)/target/include \
	     -I$(STAGING_DIR)/target/include/opencv2/opencv_core \
 	     -I$(STAGING_DIR)/target/include/opencv2/opencv_imgproc \
         -I$(STAGING_DIR)/target/include/opencv2/opencv_imgcodecs \
	     -I$(STAGING_DIR)/target/include/opencv2/opencv_highgui  \
	     -I$(STAGING_DIR)/target/usr/include/ \
	     -I$(STAGING_DIR)/target/usr/include/glib-2.0 \
	     -I$(STAGING_DIR)/target/usr/include/glib-2.0/glib \
	     -I$(STAGING_DIR)/target/usr/include/glib-2.0/gio \
	     -I$(STAGING_DIR)/target/usr/lib/glib-2.0/include \
	     -DENABLE_SWEEPER_OPTION

else
LDFLAGS   = -lartosyn -lpthread -lavp_buffer -lmultimedia -lm -lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui \
                        -L ../../../../output/staging/target/usr/lib
CFLAGS    += -I./inc -I$(STAGING_DIR)/target/include \
                         -I$(STAGING_DIR)/target/include/opencv2/opencv_core \
                 -I$(STAGING_DIR)/target/include/opencv2/opencv_imgproc \
                 -I$(STAGING_DIR)/target/include/opencv2/opencv_imgcodecs \
                 -I$(STAGING_DIR)/target/include/opencv2/opencv_highgui  \
                 -I$(STAGING_DIR)/target/usr/include/ 

CXXFLAGS  += -I./inc -I$(STAGING_DIR)/target/include \
             -I$(STAGING_DIR)/target/include/opencv2/opencv_core \
             -I$(STAGING_DIR)/target/include/opencv2/opencv_imgproc \
         -I$(STAGING_DIR)/target/include/opencv2/opencv_imgcodecs \
             -I$(STAGING_DIR)/target/include/opencv2/opencv_highgui  


endif

CFLAGS    +=
LOCAL_LIB +=

CFLAGS    += -O2 -fomit-frame-pointer -ftree-vectorize -mfpu=neon-vfpv4 -mfloat-abi=hard 

CXXFLAGS    += -O2 -fomit-frame-pointer -ftree-vectorize -mfpu=neon-vfpv4 -mfloat-abi=hard 

LOCAL_LIB += ./libyuv.a


# Include make rule file
#------------------------------------------
include ../../../../makery/usr_app_rule.lmk

