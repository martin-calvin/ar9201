#!/bin/sh

source /etc/init.d/product_profile.sh

FILE_NAME="/usrdata/usr/data/doraemon/start_$gAPP.sh"
KEY_STRING="usb_gadget_configfs_sl"
ADB_ENABLE_STRING="\\\t/usrdata/usr/data/doraemon/usb_gadget_configfs_sl.sh orbbec+uvc_rgb+uvc_depth+uvc_ir+adbd 0 0 0x2BC5 0x0630"
ADB_DISABLE_STRING="\\\t/usrdata/usr/data/doraemon/usb_gadget_configfs_sl.sh orbbec+uvc_rgb+uvc_depth+uvc_ir 0 0 0x2BC5 0x0630"


usage()
{
	echo "usage: $0 [adb_on | adb_off | adb_status]"
}


#==========start============

#在start_orbbec_tof_camera.sh脚本中查找到第一个枚举usb的代码行号
ADB_LIEN_NUMBER=$(grep -rn ${KEY_STRING} ${FILE_NAME} | awk -F ':' 'NR==1 {print $1}')

#提取usb枚举功能列表中最后一个功能的字符串(开adb功能,统一把"adbd"放最后面)
USB_ENUM_STRING=$(grep -rn ${KEY_STRING} ${FILE_NAME} | awk -F ' ' 'NR==1 {print $3}' | awk -F '+' 'NR==1 {print $NF}')

#echo ${ADB_LIEN_NUMBER}
#echo ${USB_ENUM_STRING}

if [ "$1" == "adb_on" ] ; then
	sed  -i "$ADB_LIEN_NUMBER c ${ADB_ENABLE_STRING}" $FILE_NAME
	echo "adb switch on success, effective after restart system!"
	sync
elif [ "$1" == "adb_off" ] ; then
	sed  -i "$ADB_LIEN_NUMBER c ${ADB_DISABLE_STRING}" $FILE_NAME
	echo "adb switch off success, effective after restart system!"
	sync
elif [ "$1" == "adb_status" ] ; then
	if [[ $USB_ENUM_STRING == "adbd" ]]; then
		echo "adb_status_on"
	else
		echo "adb_status_off"
	fi
else
    usage
    exit 0
fi


