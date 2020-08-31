#component template variables
component=usr_app
component-out-dir:=$(gOUTPUT_DIR)/$(component)_component
component-targets:=$(component)_component_out_tar
component-img-dir:=$(gOUTPUT_DIR)/image

#work dir
sub_app_list := $(gUSER_APP_LIST)

export $(component)-dir:=$(shell pwd)

touch-dir?=touchfiles
patch-dir=. #which dir to go when applying patches

$(component)-component-install-deps=$(call need-dir,$(component-out-dir)/usr/bin)

ifeq ($(CEVA_ADVANCED_ISP_SUPPORT), y)
define $(component)-make-install-rules
	@echo "$(component)-make-install-rules:"
	@echo "ceva0 app isp mode:"
	@$(foreach usr_app, $(sub_app_list), make -C $($(component)-dir)/$(usr_app) install INSTALL_DIR=$(component-out-dir)/usr/bin/ || exit 1;)
	@cp $($(component)-dir)/ar_dsp_alg/src/*_hdr.ini $(component-out-dir)/usr/bin/
	@mv $(component-out-dir)/usr/bin/std_ssd_config_hdr.ini $(component-out-dir)/usr/bin/std_ssd_config.ini
	@mv $(component-out-dir)/usr/bin/face_detect_config_hdr.ini $(component-out-dir)/usr/bin/face_detect_config.ini
	@mv $(component-out-dir)/usr/bin/network_evaluation_config_hdr.ini $(component-out-dir)/usr/bin/network_evaluation_config.ini
	@cp $($(component)-dir)/ar_dsp_alg/src/mtcnn_config.ini $(component-out-dir)/usr/bin/
	@cp $($(component)-dir)/arslam/Data/swdata/arvoc.bin $(component-out-dir)/usr/bin/
	@cp $($(component)-dir)/arslam/Data/swdata/config.yaml $(component-out-dir)/usr/bin/
	@if [ -e customer_start.sh ]; then cp customer_start.sh $(component-out-dir)/usr/bin/; fi
	@if [ -e ./boot_assist/fw_memory_layout.json ]; then \
		cat ./boot_assist/fw_memory_layout.json | sed "s/A7_RTOS_HEAP_SIZE/$(A7_RTOS_HEAP_SIZE)/g" | sed "s/A7_RTOS_DMA_HEAP_SIZE/$(A7_RTOS_DMA_HEAP_SIZE)/g" > ./boot_assist/fw_memory_layout_expand.json; \
		cp ./boot_assist/fw_memory_layout_expand.json $(component-out-dir)/usr/bin/fw_memory_layout.json; \
	fi;
endef
else ifeq ($(CEVA_SWEEPER_PROJ), y)
define $(component)-make-install-rules
	@echo "$(component)-make-install-rules:"
	@echo "ceva sweeper:"
	@$(foreach usr_app, $(sub_app_list), make -C $($(component)-dir)/$(usr_app) install INSTALL_DIR=$(component-out-dir)/usr/bin/ || exit 1;)
	@cp $($(component)-dir)/ar_dsp_alg/src/sweeper*.ini $(component-out-dir)/usr/bin/
	@cp $($(component)-dir)/ar_dsp_alg/src/ar9201_cam_config.txt $(component-out-dir)/usr/bin/
	@cp $($(component)-dir)/arslam/Data/swdata/arvoc.bin $(component-out-dir)/usr/bin/
	@cp $($(component)-dir)/arslam/Data/swdata/config.yaml $(component-out-dir)/usr/bin/
	@if [ -e customer_start.sh ]; then cp customer_start.sh $(component-out-dir)/usr/bin/; fi
	@if [ -e ./boot_assist/fw_memory_layout.json ]; then \
		cat ./boot_assist/fw_memory_layout.json | sed "s/A7_RTOS_HEAP_SIZE/$(A7_RTOS_HEAP_SIZE)/g" | sed "s/A7_RTOS_DMA_HEAP_SIZE/$(A7_RTOS_DMA_HEAP_SIZE)/g" > ./boot_assist/fw_memory_layout_expand.json; \
		cp ./boot_assist/fw_memory_layout_expand.json $(component-out-dir)/usr/bin/fw_memory_layout.json; \
	fi;
endef

else

define $(component)-make-install-rules
	@echo "$(component)-make-install-rules:"
	@echo "ceva0 app cdnn mode: PROGRAM:$(PROGRAM) dtb:$(dtb)"
	@$(foreach usr_app, $(sub_app_list), make -C $($(component)-dir)/$(usr_app) install INSTALL_DIR=$(component-out-dir)/usr/bin/ || exit 1;)
	@-cp $($(component)-dir)/ar_dsp_alg/src/*.ini $(component-out-dir)/usr/bin/
	@if [ -e customer_start.sh ]; then cp customer_start.sh $(component-out-dir)/usr/bin/; fi
	@if [ -e ./boot_assist/fw_memory_layout.json ]; then \
		cat ./boot_assist/fw_memory_layout.json | sed "s/A7_RTOS_HEAP_SIZE/$(A7_RTOS_HEAP_SIZE)/g" | sed "s/A7_RTOS_DMA_HEAP_SIZE/$(A7_RTOS_DMA_HEAP_SIZE)/g" > ./boot_assist/fw_memory_layout_expand.json; \
		cp ./boot_assist/fw_memory_layout_expand.json $(component-out-dir)/usr/bin/fw_memory_layout.json; \
	fi;
endef
endif

$(component)-component-build-deps=$(call need-dir,$(component-out-dir))
define $(component)-make-build-rules
	@echo "$(component)-make-build-rules:"
	@$(foreach usr_app, $(sub_app_list), make -C $($(component)-dir)/$(usr_app) STAGING_DIR=$(gSTAGING_DIR) CEVA_SWEEPER_PROJ=$(CEVA_SWEEPER_PROJ) || exit 1;)
	@$(foreach usr_app, $(sub_app_list), $(gTOOLCHAIN_DIR)/bin/arm-linux-gnueabihf-strip $($(component)-dir)/$(usr_app)/$(usr_app);)
endef

clean::
	@$(foreach usr_app, $(sub_app_list), make -C $($(component)-dir)/$(usr_app) clean;)
	rm -rf $(component-out-dir)

clobber:: clean

#STAGING
staging-dir=$(gOUTPUT_DIR)/$(component)_staging
staging-targets:=$(component)_staging

$(component)-staging-prepare-deps=$(call need-dir,$(staging-dir)/usr/bin)
define $(component)-staging-prepare-rules
    @echo "$(component)-staging-prepare-rules:"
endef

$(component)-staging-prepare-deps=$(call need-dir,$(staging-dir)/usr/bin)
define $(component)-staging-prepare-rules
    @echo "$(component)-staging-prepare-rules:"
endef

#ROOTFS COMPONENT
include $(TOPDIR)/makery/component_template.inc
$(eval $(call component_template,$(component)))

include $(TOPDIR)/makery/staging_template.inc
$(eval $(call staging_template,$(component),$(staging-dir)))

