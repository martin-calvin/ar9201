#!/bin/sh

#param: $1:  flash_type
#       $2:  nor: mtdblockN
#            mcp: N means the mtdN
#            mmcblkNpM:  N: 0 or 1, means mmc0, mmc1


echo "mounting $1:$2 to storage"

if [ $2 == null ]; then
	exit
fi

while true
do
	if [ $1 == mmc0 ] || [ $1 == mmc1 ]; then
		echo mounting $2 /storage
		if [ ! -e /dev/$2 ]; then
			echo "not found /dev/$2"
			break;
		fi
		
		mkdir -p /storage
		chmod 777 -Rfv /storage
		mount -t ext4 /dev/$2 /storage
		if [ $? -ne 0 ]; then
			echo "mount storage failed, try format and remount."
			/etc/mkfs.ext4 -F /dev/$2
		else
			#add by jiangxiaohui 20200828
			a=`cat /proc/partitions | grep -w $2 | awk '{print $3}'`
			b=`df -k -T | grep -w /dev/$2 | awk '{print $3}'`
			echo "xavier, stroage size1: $a KB, size2: $b KB"
			if [ "$a" -gt 5242880 ]; then
				if [ "$b" -lt 2097152 ]; then
					echo "The storage partition has been adjusted, so format and remount"
					umount /storage
					/etc/mkfs.ext4 -F /dev/$2
				else
					break
				fi
			else
				break
			fi
		fi
	fi
	
	sleep 1
done

