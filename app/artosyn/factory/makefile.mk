#component template variables
component=factory
component-out-dir:=$(gOUTPUT_DIR)/$(component)_component
component-targets:=$(component)_component_out_tar
component-img-dir:=$(gOUTPUT_DIR)/image

#work dir
sub_factory_list := $(gFACTORY_LIST)

include $(gA7RTOS_FW_CONFIG)
sub_tunning_list :=
ifeq (x$(FW_CAM_SENSOR_DEV_IMX291), xy)
sub_tunning_list +=cam_imx291
endif
ifeq (x$(FW_CAM_SENSOR_DEV_OV02K10), xy)
sub_tunning_list +=cam_ov02k10
endif
ifeq (x$(FW_CAM_SENSOR_DEV_IMX291_0), xy)
sub_tunning_list +=cam_imx291_0
endif
ifeq (x$(FW_CAM_SENSOR_DEV_IMX290_HDR), xy)
sub_tunning_list +=cam_imx290_hdr
endif
ifeq (x$(FW_CAM_SENSOR_DEV_OV13580), xy)
sub_tunning_list +=cam_ov13580
endif
ifeq (x$(FW_CAM_SENSOR_DEV_OV13580_0), xy)
sub_tunning_list +=cam_ov13580
endif
ifeq (x$(FW_CAM_SENSOR_DEV_IMX307), xy)
sub_tunning_list +=cam_imx307
endif
ifeq (x$(FW_CAM_SENSOR_DEV_IMX307_0), xy)
sub_tunning_list +=cam_imx307
endif

ifeq (x$(FW_CAM_SENSOR_DEV_IMX307_IR), xy)
sub_tunning_list +=cam_imx307_ir
endif

ifeq (x$(FW_CAM_SENSOR_DEV_IMX377_0), xy)
sub_tunning_list +=cam_imx377
endif
ifeq (x$(FW_CAM_SENSOR_DEV_IMX377), xy)
sub_tunning_list +=cam_imx377
endif
ifeq (x$(FW_CAM_SENSOR_DEV_IMX378), xy)
sub_tunning_list +=cam_imx378
endif
ifeq (x$(FW_CAM_SENSOR_DEV_IMX415), xy)
sub_tunning_list +=cam_imx415
endif
ifeq (x$(FW_CAM_SENSOR_DEV_SC2310), xy)
sub_tunning_list +=cam_sc2310
endif

ifeq (x$(FW_CAM_SENSOR_DEV_SC2210), xy)
sub_tunning_list +=cam_sc2210
endif

ifeq (x$(FW_CAM_SENSOR_DEV_SENSOR_SIM), xy)
sub_tunning_list +=sensor_sim
endif
#ifeq (x$(FW_CAM_SENSOR_USE_HDMI), xy)
#sub_tunning_list +=hdmi
#endif
ifeq (x$(FW_CAM_SENSOR_DEV_GC2385), xy)
sub_tunning_list +=cam_gc2385
endif
ifeq (x$(FW_CAM_SENSOR_DEV_GC2385_0), xy)
sub_tunning_list +=cam_gc2385_0
endif

ifeq (x$(FW_CAM_SENSOR_DEV_OV9712), xy)
sub_tunning_list +=cam_ov9712
endif

ifeq (x$(FW_CAM_SENSOR_DEV_RN6862M_CORE), xy)
sub_tunning_list +=cam_imx307
endif
ifeq (x$(FW_CAM_SENSOR_DEV_RN6862M_CORE), xy)
sub_tunning_list +=cam_imx307
endif
ifeq (x$(FW_CAM_SENSOR_DEV_RN6862M_SUB_MIPI1), xy)
sub_tunning_list +=cam_imx307
endif
ifeq (x$(FW_CAM_SENSOR_DEV_RN6862M_SUB_MIPI3), xy)
sub_tunning_list +=cam_imx307
endif

export $(component)-dir:=$(shell pwd)

touch-dir?=touchfiles
patch-dir=. #which dir to go when applying patches

$(component)-component-install-deps=$(call need-dir,$(component-out-dir)/factory) $(call need-dir,$(component-out-dir)/factory/tunning)

define $(component)-make-install-rules
	echo "$(component)-make-install-rules:"
	@$(foreach sub_factory, $(sub_factory_list), cp $($(component)-dir)/$(sub_factory) $(component-out-dir)/factory/ -rf;)
	@$(foreach sub_tunning, $(sub_tunning_list), cp $($(component)-dir)/tunning/$(sub_tunning) $(component-out-dir)/factory/tunning/ -rf;)

endef

$(component)-component-build-deps=$(call need-dir,$(component-out-dir))
define $(component)-make-build-rules
        @echo "$(component)-make-build-rules:"
	make -C tunning/host_tool_src/
endef

clean::
	rm -rf $(component-out-dir)

clobber:: clean

#STAGING
staging-dir=$(gOUTPUT_DIR)/$(component)_staging
staging-targets:=$(component)_staging

$(component)-staging-prepare-deps=$(call need-dir,$(staging-dir)/factory)
define $(component)-staging-prepare-rules
    @echo "$(component)-staging-prepare-rules:"
endef

$(component)-staging-prepare-deps=$(call need-dir,$(staging-dir)/factory)
define $(component)-staging-prepare-rules
    @echo "$(component)-staging-prepare-rules:"
endef

#ROOTFS COMPONENT
include $(TOPDIR)/makery/component_template.inc
$(eval $(call component_template,$(component)))

include $(TOPDIR)/makery/staging_template.inc
$(eval $(call staging_template,$(component),$(staging-dir)))

