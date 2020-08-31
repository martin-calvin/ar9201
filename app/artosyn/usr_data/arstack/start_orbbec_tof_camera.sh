#!/bin/sh

#demo_mode=uvc_demo
demo_mode=aries_app

echo "start the sceniaro for" $1
export DBUS_SESSION_BUS_ADDRESS="unix:path=/tmp/dbus-artosyn"
export PATH="/bin:/sbin:/usr/bin:/usr/sbin:/local/usr/bin/:."
export LD_LIBRARY_PATH="/lib:/usr/lib:/local/usr/lib:"

echo gAPP=$1 flashtype=$2 a7rtos_part=$3 ceva0_part=$4 ceva1_part=$5 ceva2_part=$6 ceva3_part=$7

#boot a7 rtos
boot_assist /dev/$3 /local/usr/bin/fw_memory_layout.json &


if [ $demo_mode == aries_app ]; then
	cp -r /local/usr/lib/libffi.so* /lib
	cp -r /local/usr/lib/libgio-2.0.so* /lib
	cp -r /local/usr/lib/libglib-2.0.so* /lib
	cp -r /local/usr/lib/libgmodule-2.0.so* /lib
	cp -r /local/usr/lib/libgobject-2.0.so* /lib
	cp -r /local/usr/lib/libgthread-2.0.so* /lib
	cp -r /local/usr/lib/libpcre.so* /lib
	cp -r /local/usr/lib/libpipeline_ctl.so /lib
	cp -r /local/usr/lib/libz.so* /lib
	cp -r /usrdata/usr/data/orbbec/lib/libobc_tof_drv.so /lib; chmod 777 /lib/libobc_tof_drv.so
	cp -r /usrdata/usr/data/arstack/uart/* /usr/bin
	cp -r /usrdata/usr/data/orbbec/gdb /usr/bin
	cp -r /usrdata/usr/data/orbbec/lib/libtof_calib_params_parser.so /lib; chmod 777 /lib/libtof_calib_params_parser.so
	cp -rf /local/usr/bin/obc_tof_drv /usrdata/usr/data/arstack/ ### used for tof driver test

	#cpu core voltage: 1.85v (0x3C:0.9v, 0x37:0.85v)
	i2cset -f -y 0 0x58 0x0a3 0x37
	i2cset -f -y 0 0x58 0x0a4 0x37

	#Switch off GMAC
	#devmem 0x60630030 32 0xfffffff4

	/usrdata/usr/data/arstack/usb_gadget_configfs_tof.sh orbbec+uvc_rgb+uvc_depth+uvc_ir 0 0 0x2BC5 0x062e

	/local/usr/bin/ar_dbg_service &
	dump_dspmsg -m 0 -f /dev/ttyS2 &

	#devmem 0x64570000 32 0x08003c00 ### dsp clk 600M
	devmem 0x64570000 32 0x02005000 ### dsp clk 800M
	devmem 0x60632000 32 1          ### get cpu temperature

	#ar_dsp_bootup 0 /usrdata/usr/data/arstack/ceva0_me.bin& ### 1 core
	ar_dsp_bootup 0 /usrdata/usr/data/arstack/2cores/ceva0_me.bin&
	ar_dsp_bootup 1 /usrdata/usr/data/arstack/2cores/ceva1_me.bin&

	mkdir -p /mnt/sdcard 
	mount /dev/mmcblk1p1 /mnt/sdcard/ &
	chmod 777 -R sdcard

	cp -f /local/usr/bin/aries_app /tmp/aries_app
	/tmp/aries_app &
fi



if [ $demo_mode == uvc_demo ]; then
	/usrdata/usr/data/arstack/usb_gadget_configfs.sh uvc_bulk_15_4k+uvc_bulk_15_raw 0 0 0x1d6b 0x0101
	
	/local/usr/bin/uvc_service2 --mode uvc --res0 3840 2160 --fps 30 --pipe_index 1 --dev_index 0 -b &
	/local/usr/bin/uvc_service2 --mode uvc --res0 1280 970 --fps 30 --pipe_index 0 --dev_index 1 --raw -b &
fi


/etc/init.d/start_eth.sh &

exit



