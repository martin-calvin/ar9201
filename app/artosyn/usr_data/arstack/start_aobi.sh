#!/bin/sh


# /etc/init.d/start_$gAPP.sh $gAPP $flashtype $a7rtos_part \
#	$ceva0_part $ceva1_part $ceva2_part $ceva3_part

echo "start the sceniaro for" $1
export DBUS_SESSION_BUS_ADDRESS="unix:path=/tmp/dbus-artosyn"
export PATH="/bin:/sbin:/usr/bin:/usr/sbin:/local/usr/bin/:."
export LD_LIBRARY_PATH="/lib:/usr/lib:/local/usr/lib:"

#boot a7 rtos
boot_assist /dev/$3 /local/usr/bin/fw_memory_layout.json &


usleep 300000


# if has 8 paramters, means enter clean system, and $8 is flagfile

#if [ $# == 8 ]; then
#	/etc/init.d/start_clean_system.sh $8
#	/etc/init.d/usb_gadget_configfs.sh hid_arto+serial+mass_storage 0 0 0x1d6b 0x0100
#        if [ -e "/mod/da9062_wdt.ko" ]; then
#                insmod /mod/da9062_wdt.ko
#        fi
#
#        if [ -e "/local/usr/bin/test_hid_service" ]; then
#                cp -f /local/usr/bin/test_hid_service /tmp/test_hid_service
#                /tmp/test_hid_service &
#        fi
#	exit 0
#fi

echo gAPP=$1 flashtype=$2 a7rtos_part=$3 \
	 ceva0_part=$4 ceva1_part=$5 ceva2_part=$6 ceva3_part=$7

if [ -e "/local/usr/bin/ar_dbg_service" ]; then
    echo "start dbg pc tool"
    /local/usr/bin/ar_dbg_service &
fi



#/usrdata/usr/data/arstack/usb_gadget_configfs_tof.sh uvc_rgb+uvc_depth 0 0 0x2BC5 0x062e
/usrdata/usr/data/arstack/usb_gadget_configfs.sh uvc_bulk_2_4k+uvc_bulk_15_raw 0 0 0x1d6b 0x0101


/local/usr/bin/uvc_service2 --mode uvc --res0 3840 2160 --fps 30 --pipe_index 1 --dev_index 0 -b &
/local/usr/bin/uvc_service2 --mode uvc --res0 1280 970 --fps 30 --pipe_index 0 --dev_index 1 --raw -b &

#/usrdata/usr/data/arstack/usb_gadget_configfs_90.sh uvc 0 0 0x1d6b 0x0100
#/usrdata/usr/data/arstack/uvc_service2 --mode uvc --res0 1920 1080 --fps 30 --pipe_index 0 --angle 90&


if [ -e "/mod/da9062_wdt.ko" ]; then
        insmod /mod/da9062_wdt.ko
fi

if [ -e "/mod/scsi_mod.ko" ]; then
        insmod /mod/scsi_mod.ko
fi

if [ -e "/mod/usb-storage.ko" ]; then
        insmod /mod/usb-storage.ko
fi

# start ethernet....
/etc/init.d/start_eth.sh &

exit
