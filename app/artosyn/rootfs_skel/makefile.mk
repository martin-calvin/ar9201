#component template variables
component=rootfs_skel
component-out-dir:=$(gOUTPUT_DIR)/$(component)_component
component-targets:=$(component)_component_out_tar

#work dir
$(component)-dir:=.

touch-dir?=touchfiles
patch-dir=. #which dir to go when applying patches

rootfs-dirs=/bin /sbin /usr /proc /sys /dev /etc /mnt /media /var /tmp /local /root /factory /usrdata /doc

$(component)-component-install-deps=$(call need-dir,$(component-out-dir))
define $(component)-make-install-rules
	@echo "$(component)-make-install-rules:"
	for i in $(patsubst /%,%,$(rootfs-dirs)) ; do \
		[ -d $($(component)-dir)/nodes/$$i ] && cp -rfd $($(component)-dir)/nodes/$$i $(component-out-dir)/ ; \
		! [ -d $($(component)-dir)/$$i ] && mkdir -p $(component-out-dir)/$$i ; \
		[ -e $(component-out-dir)/$$i/.gitignore ] && rm -f $(component-out-dir)/$$i/.gitignore  || /bin/true ; \
	done
	cp $(TOPDIR)/versions/sdk.version $(component-out-dir)/etc/
	cp $(TOPDIR)/doc/release_note.txt $(component-out-dir)/doc/
	echo "export gAPP=$(gAPP)" > $(component-out-dir)/etc/init.d/product_profile.sh
	$(FAKEROOT) chmod 777 $(component-out-dir)/etc/init.d/*.sh
	$(FAKEROOT) mknod $(component-out-dir)/dev/console c 5 1
	$(FAKEROOT) mknod $(component-out-dir)/dev/null c 1 3
	$(FAKEROOT) mknod $(component-out-dir)/dev/zero c 1 5
	$(FAKEROOT) chmod a+rwx $(component-out-dir)/tmp
	$(FAKEROOT) chmod o+t $(component-out-dir)/tmp
	$(FAKEROOT) mkdir $(component-out-dir)/dev/pts
	$(FAKEROOT) mkdir $(component-out-dir)/dev/shm
endef

$(component)-component-build-deps=force
define $(component)-make-build-rules
	@echo "$(component)-make-build-rules:"
endef

$(component)-component-configure-deps=#empty
define $(component)-make-configure-rules
	@echo "$(component)-make-configure-rules:"
endef

$(component)-component-patch-deps=#empty
define $(component)-make-patch-rules
	@echo "$(component)-make-patch-rules:"
endef

$(component)-component-prepare-deps=#empty
define $(component)-make-prepare-rules
	@echo "$(component)-make-prepare-rules:"
endef

clean::
	rm -rf $(component-out-dir)

clobber::
	rm -rf $(component-out-dir)

include $(TOPDIR)/makery/component_template.inc
$(eval $(call component_template,$(component)))

