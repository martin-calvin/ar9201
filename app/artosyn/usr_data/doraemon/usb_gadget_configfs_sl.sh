#!/bin/sh
#
# start config usb gadget configfs

#set -v

# $1 FrameIndex $2 Width $3 Height $4 Interval1 $5 Interval2 ... ${11} Interval8
function make_format_mjpeg()
{
	mkdir -p functions/uvc.usb$uvc_index/streaming/mjpeg/m/${2}_${3}
	cat <<-EOF > functions/uvc.usb$uvc_index/streaming/mjpeg/m/${2}_${3}/dwFrameInterval
	${4}
	${5}
	${6}
	${7}
	${8}
	${9}
	${10}
	${11}
	EOF

	#echo ${1} > functions/uvc.usb$uvc_index/streaming/mjpeg/m/${2}_${3}/bFrameIndex
	echo ${2} > functions/uvc.usb$uvc_index/streaming/mjpeg/m/${2}_${3}/wWidth
	echo ${3} > functions/uvc.usb$uvc_index/streaming/mjpeg/m/${2}_${3}/wHeight
	echo $((${2}*${3}*80)) > functions/uvc.usb$uvc_index/streaming/mjpeg/m/${2}_${3}/dwMinBitRate
	echo $((${2}*${3}*160)) > functions/uvc.usb$uvc_index/streaming/mjpeg/m/${2}_${3}/dwMaxBitRate
	echo $((${2}*${3}*2)) > functions/uvc.usb$uvc_index/streaming/mjpeg/m/${2}_${3}/dwMaxVideoFrameBufferSize
	echo ${4} > functions/uvc.usb$uvc_index/streaming/mjpeg/m/${2}_${3}/dwDefaultFrameInterval
}

# $1 FrameIndex $2 Width $3 Height $4 Interval1 $5 Interval2 ... ${11} Interval8
function make_format_h265()
{
	mkdir -p functions/uvc.usb$uvc_index/streaming/framebased/h265/${2}_${3}
	cat <<-EOF > functions/uvc.usb$uvc_index/streaming/framebased/h265/${2}_${3}/dwFrameInterval
	${4}
	${5}
	${6}
	${7}
	${8}
	${9}
	${10}
	${11}
	EOF

	#echo ${1} > functions/uvc.usb$uvc_index/streaming/framebased/h265/${2}_${3}/bFrameIndex
	echo ${2} > functions/uvc.usb$uvc_index/streaming/framebased/h265/${2}_${3}/wWidth
	echo ${3} > functions/uvc.usb$uvc_index/streaming/framebased/h265/${2}_${3}/wHeight
	echo $((${2}*${3}*80)) > functions/uvc.usb$uvc_index/streaming/framebased/h265/${2}_${3}/dwMinBitRate
	echo $((${2}*${3}*160)) > functions/uvc.usb$uvc_index/streaming/framebased/h265/${2}_${3}/dwMaxBitRate
	echo ${4} > functions/uvc.usb$uvc_index/streaming/framebased/h265/${2}_${3}/dwDefaultFrameInterval
}

# $1 FrameIndex $2 Width $3 Height $4 Interval1 $5 Interval2 ... ${11} Interval8
function make_format_h264()
{
	mkdir -p functions/uvc.usb$uvc_index/streaming/framebased/h264/${2}_${3}
	cat <<-EOF > functions/uvc.usb$uvc_index/streaming/framebased/h264/${2}_${3}/dwFrameInterval
	${4}
	${5}
	${6}
	${7}
	${8}
	${9}
	${10}
	${11}
	EOF

	#echo ${1} > functions/uvc.usb$uvc_index/streaming/framebased/h264/${2}_${3}/bFrameIndex
	echo ${2} > functions/uvc.usb$uvc_index/streaming/framebased/h264/${2}_${3}/wWidth
	echo ${3} > functions/uvc.usb$uvc_index/streaming/framebased/h264/${2}_${3}/wHeight
	echo $((${2}*${3}*80)) > functions/uvc.usb$uvc_index/streaming/framebased/h264/${2}_${3}/dwMinBitRate
	echo $((${2}*${3}*160)) > functions/uvc.usb$uvc_index/streaming/framebased/h264/${2}_${3}/dwMaxBitRate
	echo ${4} > functions/uvc.usb$uvc_index/streaming/framebased/h264/${2}_${3}/dwDefaultFrameInterval
}

# $1 FrameIndex $2 Width $3 Height $4 Interval1 $5 Interval2 ... ${11} Interval8
function make_format_nv12()
{
	mkdir -p functions/uvc.usb$uvc_index/streaming/uncompressed/nv12/${2}_${3}
	cat <<-EOF > functions/uvc.usb$uvc_index/streaming/uncompressed/nv12/${2}_${3}/dwFrameInterval
	${4}
	${5}
	${6}
	${7}
	${8}
	${9}
	${10}
	${11}
	EOF

	#echo ${1} > functions/uvc.usb$uvc_index/streaming/uncompressed/nv12/${2}_${3}/bFrameIndex
	echo ${2} > functions/uvc.usb$uvc_index/streaming/uncompressed/nv12/${2}_${3}/wWidth
	echo ${3} > functions/uvc.usb$uvc_index/streaming/uncompressed/nv12/${2}_${3}/wHeight
	echo $((${2}*${3}*80)) > functions/uvc.usb$uvc_index/streaming/uncompressed/nv12/${2}_${3}/dwMinBitRate
	echo $((${2}*${3}*160)) > functions/uvc.usb$uvc_index/streaming/uncompressed/nv12/${2}_${3}/dwMaxBitRate
	echo $((${2}*${3}*2)) > functions/uvc.usb$uvc_index/streaming/uncompressed/nv12/${2}_${3}/dwMaxVideoFrameBufferSize
	echo ${4} > functions/uvc.usb$uvc_index/streaming/uncompressed/nv12/${2}_${3}/dwDefaultFrameInterval
}

# $1 FrameIndex $2 Width $3 Height $4 Interval1 $5 Interval2 ... ${11} Interval8
function make_format_yuy2()
{
	mkdir -p functions/uvc.usb$uvc_index/streaming/uncompressed/yuy2/${2}_${3}
	cat <<-EOF > functions/uvc.usb$uvc_index/streaming/uncompressed/yuy2/${2}_${3}/dwFrameInterval
	${4}
	${5}
	${6}
	${7}
	${8}
	${9}
	${10}
	${11}
	EOF

	#echo ${1} > functions/uvc.usb$uvc_index/streaming/uncompressed/yuy2/${2}_${3}/bFrameIndex
	echo ${2} > functions/uvc.usb$uvc_index/streaming/uncompressed/yuy2/${2}_${3}/wWidth
	echo ${3} > functions/uvc.usb$uvc_index/streaming/uncompressed/yuy2/${2}_${3}/wHeight
	echo $((${2}*${3}*80)) > functions/uvc.usb$uvc_index/streaming/uncompressed/yuy2/${2}_${3}/dwMinBitRate
	echo $((${2}*${3}*160)) > functions/uvc.usb$uvc_index/streaming/uncompressed/yuy2/${2}_${3}/dwMaxBitRate
	echo $((${2}*${3}*2)) > functions/uvc.usb$uvc_index/streaming/uncompressed/yuy2/${2}_${3}/dwMaxVideoFrameBufferSize
	echo ${4} > functions/uvc.usb$uvc_index/streaming/uncompressed/yuy2/${2}_${3}/dwDefaultFrameInterval
}

# $1 FrameIndex $2 Width $3 Height $4 Interval1 $5 Interval2 ... ${11} Interval8
function make_format_i420()
{
	mkdir -p functions/uvc.usb$uvc_index/streaming/uncompressed/i420/${2}_${3}
	cat <<-EOF > functions/uvc.usb$uvc_index/streaming/uncompressed/i420/${2}_${3}/dwFrameInterval
	${4}
	${5}
	${6}
	${7}
	${8}
	${9}
	${10}
	${11}
	EOF

	#echo ${1} > functions/uvc.usb$uvc_index/streaming/uncompressed/i420/${2}_${3}/bFrameIndex
	echo ${2} > functions/uvc.usb$uvc_index/streaming/uncompressed/i420/${2}_${3}/wWidth
	echo ${3} > functions/uvc.usb$uvc_index/streaming/uncompressed/i420/${2}_${3}/wHeight
	echo $((${2}*${3}*80)) > functions/uvc.usb$uvc_index/streaming/uncompressed/i420/${2}_${3}/dwMinBitRate
	echo $((${2}*${3}*160)) > functions/uvc.usb$uvc_index/streaming/uncompressed/i420/${2}_${3}/dwMaxBitRate
	echo $((${2}*${3}*2)) > functions/uvc.usb$uvc_index/streaming/uncompressed/i420/${2}_${3}/dwMaxVideoFrameBufferSize
	echo ${4} > functions/uvc.usb$uvc_index/streaming/uncompressed/i420/${2}_${3}/dwDefaultFrameInterval
}

# $1 FrameIndex $2 Width $3 Height $4 Interval1 $5 Interval2 ... ${11} Interval8
function make_format_z16()
{
	mkdir -p functions/uvc.usb$uvc_index/streaming/uncompressed/z16/${2}_${3}
	cat <<-EOF > functions/uvc.usb$uvc_index/streaming/uncompressed/z16/${2}_${3}/dwFrameInterval
	${4}
	${5}
	${6}
	${7}
	${8}
	${9}
	${10}
	${11}
	EOF

	#echo ${1} > functions/uvc.usb$uvc_index/streaming/uncompressed/z16/${2}_${3}/bFrameIndex
	echo ${2} > functions/uvc.usb$uvc_index/streaming/uncompressed/z16/${2}_${3}/wWidth
	echo ${3} > functions/uvc.usb$uvc_index/streaming/uncompressed/z16/${2}_${3}/wHeight
	echo $((${2}*${3}*80)) > functions/uvc.usb$uvc_index/streaming/uncompressed/z16/${2}_${3}/dwMinBitRate
	echo $((${2}*${3}*160)) > functions/uvc.usb$uvc_index/streaming/uncompressed/z16/${2}_${3}/dwMaxBitRate
	echo $((${2}*${3}*2)) > functions/uvc.usb$uvc_index/streaming/uncompressed/z16/${2}_${3}/dwMaxVideoFrameBufferSize
	echo ${4} > functions/uvc.usb$uvc_index/streaming/uncompressed/z16/${2}_${3}/dwDefaultFrameInterval
}

# $1 FrameIndex $2 Width $3 Height $4 Interval1 $5 Interval2 ... ${11} Interval8
function make_format_y16()
{
	mkdir -p functions/uvc.usb$uvc_index/streaming/uncompressed/y16/${2}_${3}
	cat <<-EOF > functions/uvc.usb$uvc_index/streaming/uncompressed/y16/${2}_${3}/dwFrameInterval
	${4}
	${5}
	${6}
	${7}
	${8}
	${9}
	${10}
	${11}
	EOF

	#echo ${1} > functions/uvc.usb$uvc_index/streaming/uncompressed/y16/${2}_${3}/bFrameIndex
	echo ${2} > functions/uvc.usb$uvc_index/streaming/uncompressed/y16/${2}_${3}/wWidth
	echo ${3} > functions/uvc.usb$uvc_index/streaming/uncompressed/y16/${2}_${3}/wHeight
	echo $((${2}*${3}*80)) > functions/uvc.usb$uvc_index/streaming/uncompressed/y16/${2}_${3}/dwMinBitRate
	echo $((${2}*${3}*160)) > functions/uvc.usb$uvc_index/streaming/uncompressed/y16/${2}_${3}/dwMaxBitRate
	echo $((${2}*${3}*2)) > functions/uvc.usb$uvc_index/streaming/uncompressed/y16/${2}_${3}/dwMaxVideoFrameBufferSize
	echo ${4} > functions/uvc.usb$uvc_index/streaming/uncompressed/y16/${2}_${3}/dwDefaultFrameInterval
}

# $1 FrameIndex $2 Width $3 Height $4 Interval1 $5 Interval2 ... ${11} Interval8
function make_format_y8()
{
	mkdir -p functions/uvc.usb$uvc_index/streaming/uncompressed/y8/${2}_${3}
	cat <<-EOF > functions/uvc.usb$uvc_index/streaming/uncompressed/y8/${2}_${3}/dwFrameInterval
	${4}
	${5}
	${6}
	${7}
	${8}
	${9}
	${10}
	${11}
	EOF

	#echo ${1} > functions/uvc.usb$uvc_index/streaming/uncompressed/y8/${2}_${3}/bFrameIndex
	echo ${2} > functions/uvc.usb$uvc_index/streaming/uncompressed/y8/${2}_${3}/wWidth
	echo ${3} > functions/uvc.usb$uvc_index/streaming/uncompressed/y8/${2}_${3}/wHeight
	echo $((${2}*${3}*80)) > functions/uvc.usb$uvc_index/streaming/uncompressed/y8/${2}_${3}/dwMinBitRate
	echo $((${2}*${3}*160)) > functions/uvc.usb$uvc_index/streaming/uncompressed/y8/${2}_${3}/dwMaxBitRate
	echo $((${2}*${3}*2)) > functions/uvc.usb$uvc_index/streaming/uncompressed/y8/${2}_${3}/dwMaxVideoFrameBufferSize
	echo ${4} > functions/uvc.usb$uvc_index/streaming/uncompressed/y8/${2}_${3}/dwDefaultFrameInterval
}


echo USB_CONFIGFS: start ...

gUSB_GADGET_CONFIGFS=$1

if [ $gUSB_GADGET_CONFIGFS == none ]; then
	exit
fi

rndis_index=0
uvc_index=0
orbbec_index=0
hid_index=0
mass_storage_index=0
serial_index=0
adbd_index=0
func_index=1

mount -t configfs none /sys/kernel/config
mkdir /sys/kernel/config/usb_gadget/g1
chmod -R 0770 /sys/kernel/config/usb_gadget/g1
echo $4 > /sys/kernel/config/usb_gadget/g1/idVendor
echo $5 > /sys/kernel/config/usb_gadget/g1/idProduct
echo 0x0310 > /sys/kernel/config/usb_gadget/g1/bcdDevice
echo 0x0200 > /sys/kernel/config/usb_gadget/g1/bcdUSB

mkdir /sys/kernel/config/usb_gadget/g1/strings/0x409
chmod -R 0770 /sys/kernel/config/usb_gadget/g1/strings/0x409
echo "ZBBM5DZFMP" > /sys/kernel/config/usb_gadget/g1/strings/0x409/serialnumber
echo "Orbbec" > /sys/kernel/config/usb_gadget/g1/strings/0x409/manufacturer
echo "Orbbec(R) Astra Live T(TM) 3D Camera" > /sys/kernel/config/usb_gadget/g1/strings/0x409/product

mkdir /sys/kernel/config/usb_gadget/g1/configs/b.1
chmod -R 0770 /sys/kernel/config/usb_gadget/g1/configs/b.1
mkdir /sys/kernel/config/usb_gadget/g1/configs/b.1/strings/0x409
chmod -R 0770 /sys/kernel/config/usb_gadget/g1/configs/b.1/strings/0x409

echo 0x1 > /sys/kernel/config/usb_gadget/g1/os_desc/b_vendor_code
echo "MSFT100" > /sys/kernel/config/usb_gadget/g1/os_desc/qw_sign
echo 1 > /sys/kernel/config/usb_gadget/g1/os_desc/use

echo 500 > /sys/kernel/config/usb_gadget/g1/configs/b.1/MaxPower

funcs=${gUSB_GADGET_CONFIGFS//+/' '}
for word in $funcs
do
	case $word in
	rndis)
		echo USB_CONFIGFS: RNDIS rndis_index $rndis_index func_index $func_index
		mkdir /sys/kernel/config/usb_gadget/g1/functions/rndis.usb$rndis_index
		ln -s /sys/kernel/config/usb_gadget/g1/functions/rndis.usb$rndis_index /sys/kernel/config/usb_gadget/g1/configs/b.1/f$func_index
		if [[ "$2" == "src" ]]; then
			echo DA:AB:C2:D0:2F:F5 > /sys/kernel/config/usb_gadget/g1/functions/rndis.usb$rndis_index/dev_addr
		fi
		if [[ "$2" == "sink" ]]; then
			echo DA:AB:C2:D0:2F:F6 > /sys/kernel/config/usb_gadget/g1/functions/rndis.usb$rndis_index/dev_addr
		fi
		rndis_index=$(( $rndis_index + 1 ))
		func_index=$(( $func_index + 1 ))
		;;

	uvc|uvc_4k|uvc_3072|uvc_1792|uvc_1536)
		echo USB_CONFIGFS: UVC uvc_index $uvc_index func_index $func_index
		mkdir /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index

		if [[ "$2" == "cdns3" ]] || [[ "$3" == "cdns3" ]]; then
			echo 1024 > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpacket
			echo 0    > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxburst
		elif [[ $word == "uvc_3072" ]]; then
			echo 3072 > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpacket
		elif [[ $word == "uvc_1792" ]]; then
			echo 1792 > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpacket
		elif [[ $word == "uvc_1536" ]]; then
			echo 1536 > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpacket
		elif [[ $word == "uvc_4k" ]]; then
			echo 3072 > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpacket
			echo 7    > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxburst
		else
			echo 2048 > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpacket
		fi

		cd /sys/kernel/config/usb_gadget/g1/
		mkdir functions/uvc.usb$uvc_index/control/header/h
		cd functions/uvc.usb$uvc_index/control/

		ln -s header/h class/fs
		ln -s header/h class/ss
		cd /sys/kernel/config/usb_gadget/g1/

		echo 0xEF > bDeviceClass
		echo 0x02 > bDeviceSubClass
		echo 0x01 > bDeviceProtocol
		echo 0x0409 > bcdDevice
		echo 0xC0 > configs/b.1/bmAttributes
		echo 0x01 > configs/b.1/MaxPower

		make_format_mjpeg 1  640  480 333333 400000
		make_format_mjpeg 2  320  240 333333 400000
		make_format_mjpeg 3  800  600 333333 400000
		make_format_mjpeg 4 1280  720 333333 400000
		make_format_mjpeg 5 1280  960 333333 400000
		make_format_mjpeg 6 1920 1080 333333 400000

		#################################exmaple NV12################################
		make_format_nv12 1  640  480 333333 400000
		make_format_nv12 2  320  240 333333 400000
		make_format_nv12 3  800  600 333333 400000
		make_format_nv12 4 1280  720 333333 400000
		make_format_nv12 5 1280  960 333333 400000
		make_format_nv12 6 1920 1080 333333 400000
		echo -ne \\x4e\\x56\\x31\\x32\\x0\\x0\\x10\\x0\\x80\\x0\\x0\\xaa\\x0\\x38\\x9b\\x71 > functions/uvc.usb$uvc_index/streaming/uncompressed/nv12/guidFormat

		#################################example YUY2################################
		make_format_yuy2 1  640  480 333333 400000
		make_format_yuy2 2  320  240 333333 400000
		make_format_yuy2 3  800  600 333333 400000
		make_format_yuy2 4 1280  720 333333 400000
		make_format_yuy2 5 1280  960 333333 400000
		make_format_yuy2 6 1920 1080 333333 400000

		#################################example H264################################
		make_format_h264 1  640  480 333333 400000
		make_format_h264 2  320  240 333333 400000
		make_format_h264 3  800  600 333333 400000
		make_format_h264 4 1280  720 333333 400000
		make_format_h264 5 1280  960 333333 400000
		make_format_h264 6 1920 1080 333333 400000

		#################################example H265################################
		make_format_h265 1  640  480 333333 400000
		make_format_h265 2  320  240 333333 400000
		make_format_h265 3  800  600 333333 400000
		make_format_h265 4 1280  720 333333 400000
		make_format_h265 5 1280  960 333333 400000
		make_format_h265 6 1920 1080 333333 400000
		echo -ne \\x48\\x45\\x56\\x43\\x0\\x0\\x10\\x0\\x80\\x0\\x0\\xaa\\x0\\x38\\x9b\\x71 > functions/uvc.usb$uvc_index/streaming/framebased/h265/guidFormat

		if [[ $word == "uvc_4k" ]]; then
			make_format_mjpeg 7 3840 2160 333333 400000
			make_format_nv12  7 3840 2160 333333 400000
			make_format_yuy2  7 3840 2160 333333 400000
			make_format_h264  7 3840 2160 333333 400000
			make_format_h265  7 3840 2160 333333 400000
		fi

		cd /sys/kernel/config/usb_gadget/g1/
		mkdir functions/uvc.usb$uvc_index/streaming/header/h
		cd functions/uvc.usb$uvc_index/streaming/header/h
		#ln -s ../../framebased/h265
		ln -s ../../framebased/h264
		ln -s ../../mjpeg/m
		#ln -s ../../uncompressed/nv12
		ln -s ../../uncompressed/yuy2
		cd ../../class/fs
		ln -s ../../header/h
		cd ../../class/hs
		ln -s ../../header/h
		cd ../../class/ss
		ln -s ../../header/h

		ln -s /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index /sys/kernel/config/usb_gadget/g1/configs/b.1/f$func_index
		uvc_index=$(( $uvc_index + 1 ))
		func_index=$(( $func_index + 1 ))
		;;

	uvc_hdr|uvc_hdr_1792|uvc_hdr_1536)
		echo USB_CONFIGFS: UVC uvc_index $uvc_index func_index $func_index
		mkdir /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index

		if [[ "$2" == "cdns3" ]] || [[ "$3" == "cdns3" ]]; then
			echo 1024 > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpacket
			echo 0    > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxburst
		elif [[ $word == "uvc_hdr_1792" ]]; then
			echo 1792 > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpacket
		elif [[ $word == "uvc_hdr_1536" ]]; then
			echo 1536 > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpacket
		else
			echo 2048 > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpacket
		fi

		cd /sys/kernel/config/usb_gadget/g1/
		mkdir functions/uvc.usb$uvc_index/control/header/h
		cd functions/uvc.usb$uvc_index/control/

		ln -s header/h class/fs
		ln -s header/h class/ss
		cd /sys/kernel/config/usb_gadget/g1/

		echo 0xEF > bDeviceClass
		echo 0x02 > bDeviceSubClass
		echo 0x01 > bDeviceProtocol
		echo 0x0409 > bcdDevice
		echo 0xC0 > configs/b.1/bmAttributes
		echo 0x01 > configs/b.1/MaxPower

		make_format_mjpeg 1  640  480 400000
		make_format_mjpeg 2  320  240 400000
		make_format_mjpeg 3  800  600 400000
		make_format_mjpeg 4 1280  720 400000
		make_format_mjpeg 5 1280  960 400000
		make_format_mjpeg 6 1920 1080 400000

		cd /sys/kernel/config/usb_gadget/g1/
		mkdir functions/uvc.usb$uvc_index/streaming/header/h
		cd functions/uvc.usb$uvc_index/streaming/header/h
		#ln -s ../../framebased/h265
		#ln -s ../../framebased/h264
		ln -s ../../mjpeg/m
		#ln -s ../../uncompressed/nv12
		#ln -s ../../uncompressed/yuy2
		cd ../../class/fs
		ln -s ../../header/h
		cd ../../class/hs
		ln -s ../../header/h
		cd ../../class/ss
		ln -s ../../header/h

		ln -s /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index /sys/kernel/config/usb_gadget/g1/configs/b.1/f$func_index
		uvc_index=$(( $uvc_index + 1 ))
		func_index=$(( $func_index + 1 ))
		;;

	#just use for uvc_service2 test
	uvc_rgb_demo)
		echo USB_CONFIGFS: UVC uvc_index $uvc_index func_index $func_index
		mkdir /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index

		burstnum=2;
		payload=0;
		let "payload=(burstnum+1)*1024*2"

		echo 1024       > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpacket
		echo $burstnum  > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxburst
		echo $payload   > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpayload

		cd /sys/kernel/config/usb_gadget/g1/
		mkdir functions/uvc.usb$uvc_index/control/header/h
		cd functions/uvc.usb$uvc_index/control/

		ln -s header/h class/fs
		ln -s header/h class/ss
		cd /sys/kernel/config/usb_gadget/g1/

		echo 0xEF > bDeviceClass
		echo 0x02 > bDeviceSubClass
		echo 0x01 > bDeviceProtocol
		echo 0x0409 > bcdDevice
		echo 0xC0 > configs/b.1/bmAttributes
		echo 0x01 > configs/b.1/MaxPower

		#################################example MJPEG##############################
		make_format_mjpeg 1  640  480 166666 333333 400000
		make_format_mjpeg 2 1280  720 166666 333333 400000
		make_format_mjpeg 3 1280  960 166666 333333 400000
		make_format_mjpeg 4 1920 1080 166666 333333 400000
		make_format_mjpeg 5 1920 1440 333333 400000
		make_format_mjpeg 6 3840 2160 333333 400000
		
		#################################example YUY2################################
		make_format_yuy2 1  640  480 166666 333333 400000 
		make_format_yuy2 2 1280  720 166666 333333 400000 
		make_format_yuy2 3 1280  960 166666 333333 400000 
		make_format_yuy2 4 1920  1080 166666 333333 1000000

		#################################exmaple NV12################################
		make_format_nv12 1  640  480 166666 333333 400000 
		make_format_nv12 2 1280  720 166666 333333 400000 
		make_format_nv12 3 1280  960 166666 333333 400000 
		make_format_nv12 4 1920 1080 166666 333333 400000 1000000
		echo 12 > functions/uvc.usb$uvc_index/streaming/uncompressed/nv12/bBitsPerPixel
		echo -ne \\x4e\\x56\\x31\\x32\\x0\\x0\\x10\\x0\\x80\\x0\\x0\\xaa\\x0\\x38\\x9b\\x71 > functions/uvc.usb$uvc_index/streaming/uncompressed/nv12/guidFormat

		#################################example I420################################
		make_format_i420 1  640  480 166666 333333 400000
		make_format_i420 2 1280  720 166666 333333 400000
		make_format_i420 3 1280  960 166666 333333 400000
		make_format_i420 4 1920  1080 166666 333333 1000000
		echo 12 > functions/uvc.usb$uvc_index/streaming/uncompressed/i420/bBitsPerPixel
		echo -ne \\x49\\x34\\x32\\x30\\x0\\x0\\x10\\x0\\x80\\x0\\x0\\xaa\\x0\\x38\\x9b\\x71 > functions/uvc.usb$uvc_index/streaming/uncompressed/i420/guidFormat

		#################################example H264################################
		make_format_h264 1  640 480  166666 333333 400000
		make_format_h264 2 1280 720  166666 333333 400000
		make_format_h264 3 1280 960  166666 333333 400000
		make_format_h264 4 1920 1080 166666 333333 400000
		make_format_h264 5 1920 1440 333333 400000
		
		#################################example H265################################
		make_format_h265 1  640  480 166666 333333 400000
		make_format_h265 2 1280  720 166666 333333 400000
		make_format_h265 3 1280  960 166666 333333 400000
		make_format_h265 4 1920 1080 166666 333333 400000
		make_format_h265 5 1920 1440 333333 400000
		make_format_h265 6 3840 2160 333333 400000		
		echo -ne \\x48\\x45\\x56\\x43\\x0\\x0\\x10\\x0\\x80\\x0\\x0\\xaa\\x0\\x38\\x9b\\x71 > functions/uvc.usb$uvc_index/streaming/framebased/h265/guidFormat

		cd /sys/kernel/config/usb_gadget/g1/
		mkdir functions/uvc.usb$uvc_index/streaming/header/h
		cd functions/uvc.usb$uvc_index/streaming/header/h
		
		#链接顺序要与应用api对应上: getConfigfsFormat
		ln -s ../../mjpeg/m
		ln -s ../../framebased/h264
		ln -s ../../framebased/h265
		ln -s ../../uncompressed/nv12
		ln -s ../../uncompressed/yuy2
		#ln -s ../../uncompressed/i420
		
		cd ../../class/fs
		ln -s ../../header/h
		cd ../../class/hs
		ln -s ../../header/h
		cd ../../class/ss
		ln -s ../../header/h

		ln -s /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index /sys/kernel/config/usb_gadget/g1/configs/b.1/f$func_index
		uvc_index=$(( $uvc_index + 1 ))
		func_index=$(( $func_index + 1 ))
		;;


	orbbec)
		echo USB_CONFIGFS: Orbbec orbbec_index $orbbec_index func_index $func_index
		mkdir /sys/kernel/config/usb_gadget/g1/functions/orbbec.usb$orbbec_index
		
		echo "WINUSB" > /sys/kernel/config/usb_gadget/g1/functions/orbbec.usb$orbbec_index/os_desc/interface.orbbec/compatible_id
		echo 0x0000000000000000 > /sys/kernel/config/usb_gadget/g1/functions/orbbec.usb$orbbec_index/os_desc/interface.orbbec/sub_compatible_id
		
		mkdir /sys/kernel/config/usb_gadget/g1/functions/orbbec.usb$orbbec_index/os_desc/interface.orbbec/DeviceInterfaceGUID
		echo 0x01 > /sys/kernel/config/usb_gadget/g1/functions/orbbec.usb$orbbec_index/os_desc/interface.orbbec/DeviceInterfaceGUID/type
		#data: {A809A97B-B1E1-41ca-9265-E73A778150B4}
		echo -ne \\x7B\\x0\\x41\\x0\\x38\\x0\\x30\\x0\\x39\\x0\\x41\\x0\\x39\\x0\\x37\\x0\\x42\\x0\\x2D\\x0\\x42\\x0\\x31\\x0\\x45\\x0\\x31\\x0\\x2D\\x0\\x34\\x0\\x31\\x0\\x63\\x0\\x61\\x0\\x2D\\x0\\x39\\x0\\x32\\x0\\x36\\x0\\x35\\x0\\x2D\\x0\\x45\\x0\\x37\\x0\\x33\\x0\\x41\\x0\\x37\\x0\\x37\\x0\\x38\\x0\\x31\\x0\\x35\\x0\\x30\\x0\\x42\\x0\\x34\\x0\\x7D\\x0\\x0\\x0	> /sys/kernel/config/usb_gadget/g1/functions/orbbec.usb$orbbec_index/os_desc/interface.orbbec/DeviceInterfaceGUID/data		

		ln -s /sys/kernel/config/usb_gadget/g1/functions/orbbec.usb$orbbec_index /sys/kernel/config/usb_gadget/g1/configs/b.1/f$func_index
		orbbec_index=$(( $orbbec_index + 1 ))
		func_index=$(( $func_index + 1 ))
		;;


	uvc_rgb)
		echo USB_CONFIGFS: UVC uvc_index $uvc_index func_index $func_index
		mkdir /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index

		burstnum=2;
		payload=0;
		let "payload=(burstnum+1)*1024*2"

		echo 1024       > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpacket
		echo $burstnum  > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxburst
		echo $payload   > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpayload

		cd /sys/kernel/config/usb_gadget/g1/
		mkdir functions/uvc.usb$uvc_index/control/header/h
		cd functions/uvc.usb$uvc_index/control/

		ln -s header/h class/fs
		ln -s header/h class/ss
		cd /sys/kernel/config/usb_gadget/g1/

		echo 0xEF > bDeviceClass
		echo 0x02 > bDeviceSubClass
		echo 0x01 > bDeviceProtocol
		echo 0x0409 > bcdDevice
		echo 0xC0 > configs/b.1/bmAttributes
		echo 0x01 > configs/b.1/MaxPower

		#################################example MJPEG##############################
			#################################example MJPEG##############################
	#	make_format_mjpeg 1  640  480 333333 400000
		make_format_mjpeg 1  480  640 166666 333333 400000
		make_format_mjpeg 2 720  1280 166666 333333 400000
		make_format_mjpeg 3 960  1280 166666 333333 400000
		make_format_mjpeg 4 1080 1920 166666 333333 400000
		make_format_mjpeg 5 1440 1920 333333 400000
		make_format_mjpeg 6 2160 3840 333333 400000
		
		#################################example YUY2################################
		make_format_yuy2 1  640  480 166666 333333 400000 
		make_format_yuy2 2  1280 720 166666 333333 400000 
		make_format_yuy2 3 1280  960 166666 333333 400000 
		make_format_yuy2 4 1920  1080 166666 333333 1000000
	#	make_format_yuy2 5 2160  3840 333333 500000 1000000 20000000
	#	make_format_yuy2 6 1920 1080 400000 500000 666666 1000000 20000000

		#################################exmaple NV12################################
		make_format_nv12 1  640  480 166666 333333 400000 
		make_format_nv12 2 1280  720 166666 333333 400000 
		make_format_nv12 3 1280  960 166666 333333 400000 
		make_format_nv12 4 1920 1080 166666 333333 400000 1000000
		echo 12 > functions/uvc.usb$uvc_index/streaming/uncompressed/nv12/bBitsPerPixel
		echo -ne \\x4e\\x56\\x31\\x32\\x0\\x0\\x10\\x0\\x80\\x0\\x0\\xaa\\x0\\x38\\x9b\\x71 > functions/uvc.usb$uvc_index/streaming/uncompressed/nv12/guidFormat

		#################################example I420################################
		make_format_i420 1  640  480 166666 333333 400000
		make_format_i420 2 1280  720 166666 333333 400000
		make_format_i420 3 1280  960 166666 333333 400000
		make_format_i420 4 1920  1080 166666 333333 1000000
		echo 12 > functions/uvc.usb$uvc_index/streaming/uncompressed/i420/bBitsPerPixel
		echo -ne \\x49\\x34\\x32\\x30\\x0\\x0\\x10\\x0\\x80\\x0\\x0\\xaa\\x0\\x38\\x9b\\x71 > functions/uvc.usb$uvc_index/streaming/uncompressed/i420/guidFormat

		#################################example H264################################
	#	make_format_h264 1  640  480 333333 400000
		make_format_h264 1  480  640 166666 333333 400000
		make_format_h264 2 720  1280 166666 333333 400000
		make_format_h264 3 960  1280 166666 333333 400000
		make_format_h264 4 1080 1920 166666 333333 400000
		make_format_h264 5 1440 1920 333333 400000
		
		#################################example H265################################
	#	make_format_h265 1  640  480 333333 400000
		make_format_h265 1  480  640 166666 333333 400000
		make_format_h265 2 720  1280 166666 333333 400000
		make_format_h265 3 960  1280 166666 333333 400000
		make_format_h265 4 1080 1920 166666 333333 400000
		make_format_h265 5 1440 1920 333333 400000
		make_format_h265 6 2160 3840 333333 400000		
		echo -ne \\x48\\x45\\x56\\x43\\x0\\x0\\x10\\x0\\x80\\x0\\x0\\xaa\\x0\\x38\\x9b\\x71 > functions/uvc.usb$uvc_index/streaming/framebased/h265/guidFormat

		cd /sys/kernel/config/usb_gadget/g1/
		mkdir functions/uvc.usb$uvc_index/streaming/header/h
		cd functions/uvc.usb$uvc_index/streaming/header/h
		
		#链接顺序要与应用api对应上: getConfigfsFormat
		ln -s ../../mjpeg/m
		ln -s ../../framebased/h264
		ln -s ../../framebased/h265
		ln -s ../../uncompressed/nv12
		ln -s ../../uncompressed/yuy2
		ln -s ../../uncompressed/i420
		
		cd ../../class/fs
		ln -s ../../header/h
		cd ../../class/hs
		ln -s ../../header/h
		cd ../../class/ss
		ln -s ../../header/h

		ln -s /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index /sys/kernel/config/usb_gadget/g1/configs/b.1/f$func_index
		uvc_index=$(( $uvc_index + 1 ))
		func_index=$(( $func_index + 1 ))
		;;


	uvc_depth)
		echo USB_CONFIGFS: UVC uvc_index $uvc_index func_index $func_index
		mkdir /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index
		
		burstnum=15;
		payload=0;
		let "payload=(burstnum+1)*1024*2"

		echo 1024      > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpacket
		echo $burstnum  > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxburst
		echo $payload  > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpayload
		
		cd /sys/kernel/config/usb_gadget/g1/
		mkdir functions/uvc.usb$uvc_index/control/header/h
		cd functions/uvc.usb$uvc_index/control/

		ln -s header/h class/fs
		ln -s header/h class/ss
		cd /sys/kernel/config/usb_gadget/g1/

		echo 0xEF > bDeviceClass
		echo 0x02 > bDeviceSubClass
		echo 0x01 > bDeviceProtocol
		echo 0x0409 > bcdDevice
		echo 0xC0 > configs/b.1/bmAttributes
		echo 0x01 > configs/b.1/MaxPower

		# #################################exmaple Z16 for Depth#######################
		# make_format_z16 1  640  480 333333 400000
		# make_format_z16 2  320  240 333333 400000
		# echo -ne \\x5a\\x31\\x36\\x20\\x0\\x0\\x10\\x0\\x80\\x0\\x0\\xaa\\x0\\x38\\x9b\\x71 > functions/uvc.usb$uvc_index/streaming/uncompressed/z16/guidFormat

		# #################################exmaple Y16 for raw phase #################
		# make_format_y16 1  640  480 333333 400000
		# make_format_y16 2  320  240 333333 400000
		# make_format_y16 3 1280  960 333333 400000 500000 666666 1000000 20000000
		# make_format_y16 4 1280  970 333333 400000 500000 666666 1000000 20000000
		# echo -ne \\x59\\x31\\x36\\x20\\x0\\x0\\x10\\x0\\x80\\x0\\x0\\xaa\\x0\\x38\\x9b\\x71 > functions/uvc.usb$uvc_index/streaming/uncompressed/y16/guidFormat

		#################################example YUY2################################
		#make_format_yuy2 1  640   480  333333 400000 500000 666666 1000000 20000000
		#make_format_yuy2 2  320   240  333333 400000 500000 666666 
		#make_format_yuy2 3  800   600  333333 400000
		#make_format_yuy2 4  1280  720  333333 400000
		#make_format_yuy2 5  1280  960  333333 400000 500000 666666 1000000 20000000
		#make_format_yuy2 6  1280  970  333333 400000 500000 666666 1000000 20000000
		#make_format_yuy2 7  1920  1080 333333 400000		
		make_format_yuy2 1  960   1280 333333 400000
		make_format_yuy2 2  720   1280 333333 400000
		make_format_yuy2 2  480   640  333333 400000

		cd /sys/kernel/config/usb_gadget/g1/
		mkdir functions/uvc.usb$uvc_index/streaming/header/h
		cd functions/uvc.usb$uvc_index/streaming/header/h
		
		ln -s ../../uncompressed/yuy2
		# ln -s ../../uncompressed/z16
		# ln -s ../../uncompressed/y16
		
		cd ../../class/fs
		ln -s ../../header/h
		cd ../../class/hs
		ln -s ../../header/h
		cd ../../class/ss
		ln -s ../../header/h

		ln -s /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index /sys/kernel/config/usb_gadget/g1/configs/b.1/f$func_index
		uvc_index=$(( $uvc_index + 1 ))
		func_index=$(( $func_index + 1 ))
		;;


	uvc_ir)
		echo USB_CONFIGFS: UVC uvc_index $uvc_index func_index $func_index
		mkdir /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index
		
		burstnum=15;
		payload=0;
		let "payload=(burstnum+1)*1024*2"
		
		echo 1024      > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpacket
		echo $burstnum  > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxburst
		echo $payload  > /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index/streaming_maxpayload
		
		cd /sys/kernel/config/usb_gadget/g1/
		mkdir functions/uvc.usb$uvc_index/control/header/h
		cd functions/uvc.usb$uvc_index/control/

		ln -s header/h class/fs
		ln -s header/h class/ss
		cd /sys/kernel/config/usb_gadget/g1/

		echo 0xEF > bDeviceClass
		echo 0x02 > bDeviceSubClass
		echo 0x01 > bDeviceProtocol
		echo 0x0409 > bcdDevice
		echo 0xC0 > configs/b.1/bmAttributes
		echo 0x01 > configs/b.1/MaxPower

		#################################exmaple Y8################################
		# make_format_y8 1  640  480 333333 400000
		# make_format_y8 2  320  240 333333 400000
		# echo -ne \\x59\\x38\\x20\\x20\\x0\\x0\\x10\\x0\\x80\\x0\\x0\\xaa\\x0\\x38\\x9b\\x71 > functions/uvc.usb$uvc_index/streaming/uncompressed/y8/guidFormat

		#################################example YUY2################################
		# make_format_yuy2 1  640  480 333333 400000 500000 666666 1000000 20000000
		# make_format_yuy2 2  320  240 333333 400000 500000 666666 
		# make_format_yuy2 3 1280  960 333333 400000 500000 666666 1000000 20000000
		# make_format_yuy2 4 1280  970 333333 400000 500000 666666 1000000 20000000		
		make_format_yuy2 1  1280  960  333333 400000
		# make_format_yuy2 2  640   480   333333 400000 500000 666666 1000000 20000000
		# make_format_yuy2 3  480   640  333333 400000 500000 666666 1000000 20000000
		# make_format_yuy2 4  512   640  333333 400000 500000 666666 1000000 20000000
		# make_format_yuy2 5  960   1280 333333 400000 500000 666666 1000000 20000000
		# make_format_yuy2 6  1024  1280 333333 400000 500000 666666 1000000 20000000

		cd /sys/kernel/config/usb_gadget/g1/
		mkdir functions/uvc.usb$uvc_index/streaming/header/h
		cd functions/uvc.usb$uvc_index/streaming/header/h

		ln -s ../../uncompressed/yuy2		
		# ln -s ../../uncompressed/y8

		cd ../../class/fs
		ln -s ../../header/h
		cd ../../class/hs
		ln -s ../../header/h
		cd ../../class/ss
		ln -s ../../header/h

		ln -s /sys/kernel/config/usb_gadget/g1/functions/uvc.usb$uvc_index /sys/kernel/config/usb_gadget/g1/configs/b.1/f$func_index
		uvc_index=$(( $uvc_index + 1 ))
		func_index=$(( $func_index + 1 ))
		;;


	hid|hid_arto)
		echo USB_CONFIGFS: HID hid_index $hid_index func_index $func_index

		mkdir /sys/kernel/config/usb_gadget/g1/functions/hid.usb$hid_index

		echo 0 > /sys/kernel/config/usb_gadget/g1/functions/hid.usb$hid_index/protocol
		echo 512 > /sys/kernel/config/usb_gadget/g1/functions/hid.usb$hid_index/report_length
		if [[ $word == "hid_arto" ]]; then
			echo -ne \\x05\\x8c\\x09\\x01\\xa1\\x01\\x09\\x03\\x15\\x00\\x26\\x00\\xff\\x75\\x40\\x95\\x40\\x81\\x02\\x09\\x04\\x15\\x00\\x26\\x00\\xff\\x75\\x80\\x95\\x40\\x91\\x02\\xc0 > /sys/kernel/config/usb_gadget/g1/functions/hid.usb$hid_index/report_desc
		else
			echo -ne \\x05\\x8c\\x09\\x01\\xa1\\x01\\x09\\x03\\x15\\x00\\x26\\x00\\xff\\x75\\x40\\x95\\x40\\x81\\x02\\x09\\x04\\x15\\x00\\x26\\x00\\xff\\x75\\x40\\x95\\x40\\x91\\x02\\xc0 > /sys/kernel/config/usb_gadget/g1/functions/hid.usb$hid_index/report_desc
		fi

		ln -s /sys/kernel/config/usb_gadget/g1/functions/hid.usb$hid_index /sys/kernel/config/usb_gadget/g1/configs/b.1/f$func_index
		hid_index=$(( $hid_index + 1 ))
		func_index=$(( $func_index + 1 ))
		;;
	mass_storage)
		echo USB_CONFIGFS: MASS_STORAGE mass_storage_index $mass_storage_index func_index $func_index

		mkdir /sys/kernel/config/usb_gadget/g1/functions/mass_storage.usb$mass_storage_index
		mkdir /tmp/pc
		dd if=/dev/zero of=/tmp/msc.vfat.img bs=1M count=70
		mkfs.vfat /tmp/msc.vfat.img
		echo /tmp/msc.vfat.img > /sys/kernel/config/usb_gadget/g1/functions/mass_storage.usb$mass_storage_index/lun.0/file
		mount -t vfat /tmp/msc.vfat.img /tmp/pc

		ln -s /sys/kernel/config/usb_gadget/g1/functions/mass_storage.usb$mass_storage_index /sys/kernel/config/usb_gadget/g1/configs/b.1/f$func_index

		mass_storage_index=$(( $mass_storage_index + 1 ))
		func_index=$(( $func_index + 1 ))
		;;
	serial)
		echo USB_CONFIGFS: SERIAL serial_index $serial_index func_index $func_index

		mkdir -p /sys/kernel/config/usb_gadget/g1/functions/acm.usb$serial_index
		ln -s /sys/kernel/config/usb_gadget/g1/functions/acm.usb$serial_index /sys/kernel/config/usb_gadget/g1/configs/b.1/f$func_index

		serial_index=$(( $serial_index + 1 ))
		func_index=$(( $func_index + 1 ))
		;;
	adbd)
		if [[ $adbd_index == 0 ]]; then
			echo USB_CONFIGFS: ADBD adbd_index $adbd_index func_index $func_index
			cd /
			mkdir /sys/kernel/config/usb_gadget/g1/functions/ffs.adb
			ln -s /sys/kernel/config/usb_gadget/g1/functions/ffs.adb /sys/kernel/config/usb_gadget/g1/configs/b.1/f$func_index
			mkdir -p /dev/usb-ffs/adb
			mount -t functionfs adb /dev/usb-ffs/adb
			cp /usrdata/usr/data/orbbec/adbd /tmp/
			chmod 777 /tmp/adbd
			/tmp/adbd &
			while [ 1 ]; do
				if [ -e /dev/usb-ffs/adb/ep1 ] && [ -e /dev/usb-ffs/adb/ep2 ]; then
					break
				fi
				usleep 100
			done
			adbd_index=$(( $adbd_index + 1 ))
			func_index=$(( $func_index + 1 ))
		else
			echo USB_CONFIGFS: ADBD no support multi function
		fi
		;;
	*)
		echo USB_CONFIGFS: NONE
		echo Usage: gUSB_GADGET_CONFIGFS=rndis+uvc
		exit 1
		;;
	esac
done

ln -s /sys/kernel/config/usb_gadget/g1/configs/b.1 /sys/kernel/config/usb_gadget/g1/os_desc/b.1

echo "$gUSB_GADGET_CONFIGFS" > /sys/kernel/config/usb_gadget/g1/configs/b.1/strings/0x409/configuration
if [[ "$3" == "cdns3" ]]; then
	echo "60300000.cadence_usb" > /sys/kernel/config/usb_gadget/g1/UDC
else
	echo "60500000.dwc3" > /sys/kernel/config/usb_gadget/g1/UDC
fi

func=$( echo $gUSB_GADGET_CONFIGFS | grep rndis)
if [[ "$func" != "" ]]; then
	if [[ "$2" == "sink" ]]; then
		ifconfig usb0 172.16.3.100 up
	else
		ifconfig usb0 192.168.3.100 up
	fi
fi

func=$( echo $gUSB_GADGET_CONFIGFS | grep serial)
if [[ "$func" != "" ]]; then
	echo "ttyGS0::askfirst:-/bin/sh" >> /etc/inittab
	kill -HUP 1
	#passwd root -d ""
	#su root -c "sbin/getty -L -w /dev/ttyGS0 115200 vt100 &"
fi

echo USB_CONFIGFS: finished ...
