#!/bin/sh

# exit 0: means enter normal system
# exit 1: means enter clean system
# ATTENTION: rcS depends on the exit status, so don't mistake

# clean system flag file, exsit means clean system, otherwise normal system
flagfile="/usrdata/sirius-clean-system-flag"

if [ -e $flagfile ]; then
	if [ -e "/local/usr/bin/start_$gAPP.sh" ]; then
		# here run customer start_$gAPP.sh
		/local/usr/bin/start_$gAPP.sh $1 $2 $3 $4 $5 $6 $7 $flagfile
	elif [ -e "/usrdata/usr/data/arstack/start_$gAPP.sh" ]; then
		# here run usr_data start_$gAPP.sh
		/usrdata/usr/data/arstack/start_$gAPP.sh $1 $2 $3 $4 $5 $6 $7 $flagfile
	elif [ -e "/usrdata/usr/data/doraemon/start_$gAPP.sh" ]; then
		# here run usr_data start_$gAPP.sh
		/usrdata/usr/data/doraemon/start_$gAPP.sh $1 $2 $3 $4 $5 $6 $7 $flagfile
	else
		# if run /etc start_$gAPP.sh by default
		/etc/init.d/start_$gAPP.sh $1 $2 $3 $4 $5 $6 $7 $flagfile
	fi

	echo "STARTUP clean system COMPLETE"
	# remove flag file, next reboot will enter normal system
	if [ -e $flagfile ]; then
		rm $flagfile
	fi
	sync

	# tell rcS we are in clean system
	exit 1
else
	# tell rcS we should be in normal system
	exit 0
fi

##################################################################################
#====================the below is test, never execute============================#

# starup clean system or normal system by uboot environment variable sirius_system
if [ -e "/local/usr/bin/fw_printenv" ]; then
	system_type=`fw_printenv -n sirius_system` 1>/dev/null 2>&1
	if [ $? == 0 ]; then
		# enter clean system when sirius_system == clean
		if [ $system_type == "clean" ]; then
			/etc/init.d/start_clean_system.sh &
			echo "STARTUP clean system COMPLETE"
			# clear environment sirius_system
			if [ -e "/local/usr/bin/fw_setenv" ]; then
				fw_setenv sirius_system
				if [ $? != 0 ]; then
					echo "Warning: clear environment sirius_system failed"
				fi
			else
				echo "Warning: clear environment sirius_system failed"
			fi
			# tell rcS we are in clean system
			exit 1
		fi
	fi
fi
