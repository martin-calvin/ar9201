#!/bin/sh

#/etc/init.d/tcpm_dp_fw_load.sh

demo_mode=uvc_demo
#demo_mode=hdmi_demo
#demo_mode=alg_demo


export DBUS_SESSION_BUS_ADDRESS="unix:path=/tmp/dbus-artosyn"
export PATH="/bin:/sbin:/usr/bin:/usr/sbin:/local/usr/bin/:."
export LD_LIBRARY_PATH="/lib:/usr/lib:/local/usr/lib:"

# if has 8 paramters, means enter clean system, and $8 is flagfile
if [ $# == 8 ]; then
	/etc/init.d/start_clean_system.sh $8
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

#/etc/init.d/usb_gadget_configfs.sh $1
/etc/init.d/usb_gadget_configfs.sh uvc 0 0 0x1d6b 0x0102
/etc/init.d/start_eth.sh &



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
	#/tmp/uvc_service --mode uvc --fps 25 --res0 1920 1080 --res1 640 480 --osd &
fi

if [ -e "/local/usr/bin/test_hid_service" ]; then
	cp -f /local/usr/bin/test_hid_service /tmp/test_hid_service
	/tmp/test_hid_service &
fi

if [ -e "/local/usr/bin/ar_dbg_service" ]; then
	echo "start dbg pc tool"
	/local/usr/bin/ar_dbg_service &
fi

if [ $demo_mode == uvc_demo ]; then
	/tmp/uvc_service --mode uvc --fps 25 --res0 1920 1080 --res1 640 480 --osd &
	#tmp/uvc_service --mode uvc --fps 25 &
	
	sleep 2
	
	ar_dsp_bootup 0 /usrdata/usr/data/arstack/ceva_cdnn/ceva0.bin 
	ar_dsp_bootup 1 /usrdata/usr/data/arstack/ceva_cdnn/ceva1.bin 
	#ar_dsp_bootup 2 /usrdata/usr/data/arstack/ceva_cdnn/ceva2.bin &
	#ar_dsp_bootup 3 /usrdata/usr/data/arstack/ceva_cdnn/ceva3.bin &

	/usrdata/usr/data/arstack/ceva_cdnn/ar_dsp_alg /usrdata/usr/data/arstack/ceva_cdnn/std_ssd_config.ini /dev/video_yuv-1&
		
fi

if [ $demo_mode == hdmi_demo ]; then
	/tmp/uvc_service --mode hdmi --fps 25 --res0 1920 1080 --res1 640 480 --osd &
	
	sleep 2

	ar_dsp_bootup 0 /usrdata/usr/data/arstack/ceva_cdnn/ceva0.bin 
	ar_dsp_bootup 1 /usrdata/usr/data/arstack/ceva_cdnn/ceva1.bin 
	#ar_dsp_bootup 2 /usrdata/usr/data/arstack/ceva_cdnn/ceva2.bin &
	#ar_dsp_bootup 3 /usrdata/usr/data/arstack/ceva_cdnn/ceva3.bin &

	/usrdata/usr/data/arstack/ceva_cdnn/ar_dsp_alg /usrdata/usr/data/arstack/ceva_cdnn/std_ssd_config.ini /dev/video_yuv-1&
	
fi


if [ $demo_mode == alg_demo ]; then
	tmp/uvc_service --mode uvc --fps 25 &

	ar_dsp_bootup 0 /usrdata/usr/data/arstack/ceva0.bin
	ar_dsp_bootup 1 /usrdata/usr/data/arstack/ceva1.bin
	ar_dsp_bootup 2 /usrdata/usr/data/arstack/ceva2.bin
	ar_dsp_bootup 3 /usrdata/usr/data/arstack/ceva3.bin

	cp /usrdata/usr/data/arstack/lena_512x512_400.yuv /mnt/


	/usrdata/usr/data/arstack/test_gauss4coreloop &


#devmem 0x60632000 32 0x1
#while true
#do
#devmem 0x60632910 32
#sleep 10
#done

	
fi



exit

