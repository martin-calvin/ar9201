#!/bin/sh

#/etc/init.d/tcpm_dp_fw_load.sh

export DBUS_SESSION_BUS_ADDRESS="unix:path=/tmp/dbus-artosyn"
export PATH="/bin:/sbin:/usr/bin:/usr/sbin:/local/usr/bin/:."
export LD_LIBRARY_PATH="/lib:/usr/lib:/local/usr/lib:"

# if has 8 paramters, means enter clean system, and $8 is flagfile
if [ $# == 8 ]; then
	/etc/init.d/start_clean_system.sh $8
	/etc/init.d/usb_gadget_configfs.sh hid_arto+serial+mass_storage 0 0 0x1d6b 0x0100
	if [ -e "/mod/da9062_wdt.ko" ]; then
		insmod /mod/da9062_wdt.ko
	fi

	if [ -e "/local/usr/bin/test_hid_service" ]; then
		cp -f /local/usr/bin/test_hid_service /tmp/test_hid_service
		/tmp/test_hid_service &
	fi
	exit 0
fi

# /etc/init.d/start_$gAPP.sh $gAPP $flashtype $a7rtos_part \
#	$ceva0_part $ceva1_part $ceva2_part $ceva3_part

echo "start the sceniaro for" $1

echo gAPP=$1 flashtype=$2 a7rtos_part=$3 \
	 ceva0_part=$4 ceva1_part=$5 ceva2_part=$6 ceva3_part=$7

#define isp function on ceva0 : null, eis, hdr
ceva0_isp_function=null

#boot a7 rtos
boot_assist /dev/$3 /local/usr/bin/fw_memory_layout.json &

# nfs setting example
#mkdir -p /nfs
#mount -t nfs -o nolock 192.168.200.6:/nfs_share/klbai /nfs
#boot_assist /nfs/a7_rtos.nonsec.img fw_memory_layout.json &

/etc/init.d/usb_gadget_configfs.sh rndis+uvc+hid_arto 0 0 0x1d6b 0x0102

if [ -e "/local/usr/bin/uvc_service2" ]; then
	echo "start uvc server"
	#usleep 220000
	cp -r /local/usr/lib/libffi.so* /lib
	cp -r /local/usr/lib/libgio-2.0.so* /lib
	cp -r /local/usr/lib/libglib-2.0.so* /lib
	cp -r /local/usr/lib/libgmodule-2.0.so* /lib
	cp -r /local/usr/lib/libgobject-2.0.so* /lib
	cp -r /local/usr/lib/libgthread-2.0.so* /lib
	cp -r /local/usr/lib/libpcre.so* /lib
	cp -r /local/usr/lib/libpipeline_ctl.so /lib
	cp -r /local/usr/lib/libz.so* /lib
	cp -f /local/usr/bin/uvc_service2 /tmp/uvc_service
	/tmp/uvc_service --mode uvc --fps 30 --res0 1920 1080 --res1 640 480 --osd &
fi

if [ -e "/local/usr/bin/test_hid_service" ]; then
	cp -f /local/usr/bin/test_hid_service /tmp/test_hid_service
	/tmp/test_hid_service &
fi

if [ -e "/local/usr/bin/ar_dbg_service" ]; then
	echo "start dbg pc tool"
	/local/usr/bin/ar_dbg_service &
fi

# start dsp $ceva0_part $ceva1_part $ceva2_part $ceva3_part $5:dev interface $6: config
if [ $ceva0_isp_function == eis ]; then
	/etc/init.d/start_dsp.sh /local/usr/bin/ceva0_eis.bin /dev/$5 /dev/null /dev/null /dev/video_yuv-1 /local/usr/bin/std_ssd_config_eis.ini &
elif [ $ceva0_isp_function == hdr ]; then
	/etc/init.d/start_dsp.sh /local/usr/bin/ceva0_hdr.bin /dev/$5 /dev/null /dev/null /dev/video_yuv-1 /local/usr/bin/std_ssd_config_hdr.ini &
else
	/etc/init.d/start_dsp.sh /dev/$4 /dev/$5 /dev/null /dev/null /dev/video_yuv-1 /local/usr/bin/std_ssd_config.ini &
fi;

if [ -e "/mod/da9062_wdt.ko" ]; then
        sleep 1
        insmod /mod/da9062_wdt.ko
fi

exit

