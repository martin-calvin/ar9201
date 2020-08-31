#component template variables
component=rootfs_app
component-out-dir:=$(gOUTPUT_DIR)/$(component)_component
component-targets:=$(component)_component_out_tar
component-img-dir:=$(gOUTPUT_DIR)/image

#work dir
sub_rootfs_app_list := artosyn_upgrade

export $(component)-dir:=$(shell pwd)

touch-dir?=touchfiles
patch-dir=. #which dir to go when applying patches

$(component)-component-install-deps=$(call need-dir,$(component-out-dir)/usr/bin)



define $(component)-make-install-rules
	@echo "$(component)-make-install-rules:"
	@$(foreach rootfs_app, $(sub_rootfs_app_list), cp $($(component)-dir)/$(rootfs_app)/$(rootfs_app) $(component-out-dir)/usr/bin/;)
endef

$(component)-component-build-deps=$(call need-dir,$(component-out-dir))
define $(component)-make-build-rules
	@echo "$(component)-make-build-rules:"
	@$(foreach rootfs_app, $(sub_rootfs_app_list), make -C $($(component)-dir)/$(rootfs_app) STAGING_DIR=$(gSTAGING_DIR) || exit 1;)
	@$(foreach rootfs_app, $(sub_rootfs_app_list), $(gTOOLCHAIN_DIR)/bin/arm-linux-gnueabihf-strip $($(component)-dir)/$(rootfs_app)/$(rootfs_app);)
endef

clean::
	@$(foreach rootfs_app, $(sub_rootfs_app_list), make -C $($(component)-dir)/$(rootfs_app) clean;)
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

