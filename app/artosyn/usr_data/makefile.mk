#component template variables
component=usr_data
component-out-dir:=$(gOUTPUT_DIR)/$(component)_component
component-targets:=$(component)_component_out_tar

#work dir
sub_data_list := $(gUSER_DATA_LIST)

export $(component)-dir:=$(shell pwd)

touch-dir?=touchfiles
patch-dir=. #which dir to go when datalying patches

$(component)-component-install-deps=$(call need-dir,$(component-out-dir)/usr/data)
define $(component)-make-install-rules
	@echo "$(component)-make-install-rules:"
	@$(foreach usr_data, $(sub_data_list), cp $($(component)-dir)/$(usr_data) $(component-out-dir)/usr/data/ -rf;)
endef

$(component)-component-build-deps=$(call need-dir,$(component-out-dir))
define $(component)-make-build-rules
	@echo "$(component)-make-build-rules:"
endef

clean::
	rm -rf $(component-out-dir)

clobber:: clean

#STAGING
staging-dir=$(gOUTPUT_DIR)/$(component)_staging
staging-targets:=$(component)_staging

$(component)-staging-prepare-deps=$(call need-dir,$(staging-dir)/usr/data)
define $(component)-staging-prepare-rules
    @echo "$(component)-staging-prepare-rules:"
endef




#ROOTFS COMPONENT
include $(TOPDIR)/makery/component_template.inc
$(eval $(call component_template,$(component)))

include $(TOPDIR)/makery/staging_template.inc
$(eval $(call staging_template,$(component),$(staging-dir)))

