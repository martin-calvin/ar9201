#!/bin/sh
#
# Start the network
#

if [ -e "/mod/ar_tzc.ko" ]; then
	echo "insmod ar_tzc.ko"
	insmod /mod/ar_tzc.ko
fi

if [ -e "/mod/mii.ko" ]; then
	echo "insmod mii.ko"
	insmod /mod/mii.ko
fi

if [ -e "/mod/libphy.ko" ]; then
	echo "insmod libphy.ko"
	insmod /mod/libphy.ko
fi

if [ -e "/mod/fixed_phy.ko" ]; then
	echo "insmod fixed_phy.ko"
	insmod /mod/fixed_phy.ko
fi

if [ -e "/mod/of_mdio.ko" ]; then
	echo "insmod of_mdio.ko"
	insmod /mod/of_mdio.ko
fi

if [ -e "/mod/mdio-sirius.ko" ]; then
	echo "insmod mdio-sirius.ko"
	insmod /mod/mdio-sirius.ko
fi

if [ -e "/mod/sirius_eth.ko" ]; then
	echo "insmod sirius_eth.ko"
	insmod /mod/sirius_eth.ko
fi

if [ -e "/mod/netlink_diag.ko" ]; then
	echo "insmod netlink_diag.ko"
	insmod /mod/netlink_diag.ko
fi

if [ -e "/mod/unix.ko" ]; then
	echo "insmod unix.ko"
	insmod /mod/unix.ko
fi

if [ -e "/mod/unix_diag.ko" ]; then
	echo "insmod unix_diag.ko"
	insmod /mod/unix_diag.ko
fi

if [ -e "/mod/dns_resolver.ko" ]; then
	echo "insmod dns_resolver.ko"
	insmod /mod/dns_resolver.ko
fi

if [ -e "/mod/llc.ko" ]; then
	echo "insmod llc.ko"
	insmod /mod/llc.ko
fi

if [ -e "/mod/stp.ko" ]; then
	echo "insmod stp.ko"
	insmod /mod/stp.ko
fi

if [ -e "/mod/bridge.ko" ]; then
	echo "insmod bridge.ko"
	insmod /mod/bridge.ko
fi

if [ -e "/mod/rfkill.ko" ]; then
	echo "insmod rfkill.ko"
	insmod /mod/rfkill.ko
fi

#if [ -e "/mod/cfg80211.ko" ]; then
#	echo "insmod cfg80211.ko"
#	insmod /mod/cfg80211.ko
#fi
#
#if [ -e "/mod/mac80211.ko" ]; then
#	echo "insmod mac80211.ko"
#	insmod /mod/mac80211.ko
#fi

if [ -e "/mod/realtek.ko" ]; then
	echo "insmod realtek.ko"
	insmod /mod/realtek.ko
fi

if [ -e "/mod/af_packet.ko" ]; then
	echo "insmod af_packet.ko"
	insmod /mod/af_packet.ko
fi

if [ -e "/mod/grace.ko" ]; then
	echo "insmod grace.ko"
	insmod /mod/grace.ko
fi

if [ -e "/mod/sunrpc.ko" ]; then
	echo "insmod sunrpc.ko"
	insmod /mod/sunrpc.ko
fi

if [ -e "/mod/lockd.ko" ]; then
	echo "insmod lockd.ko"
	insmod /mod/lockd.ko
fi

if [ -e "/mod/nfs.ko" ]; then
	echo "insmod nfs.ko"
	insmod /mod/nfs.ko
fi

if [ -e "/mod/nfsv2.ko" ]; then
	echo "insmod nfsv2.ko"
	insmod /mod/nfsv2.ko
fi

if [ -e "/mod/nfs_acl.ko" ]; then
	echo "insmod nfs_acl.ko"
	insmod /mod/nfs_acl.ko
fi

if [ -e "/mod/nfsv3.ko" ]; then
	echo "insmod nfsv3.ko"
	insmod /mod/nfsv3.ko
fi

if [ -e "/mod/nfsv4.ko" ]; then
	echo "insmod nfsv4.ko"
	insmod /mod/nfsv4.ko
fi


#disable ipv6
ifconfig lo up

#echo 1 > /proc/sys/net/ipv6/conf/eth0/disable_ipv6

while [ ! -e "/tmp/factory_mount_end" ]; do
	#waiting factory mount done to check if mac avail
	usleep 100000
done

if [ -e "/factory/mac.cfg" ]; then
	echo "setting eth0 mac to eth0 "
	ifconfig eth0 hw ether `cat /factory/mac.cfg`
fi

/sbin/ifconfig eth0 up

#sleep to wait eth0
sleep 1

/sbin/udhcpc -b -i eth0 -s /etc/udhcpc.script -x lease:300 &

if [ -e /local/usr/sbin/dropbear ]; then
	chmod +x /local/usr/bin/scp
	chmod +x /local/usr/sbin/dropbear
	cp /local/usr/bin/scp /usr/bin
	cp /local/usr/sbin/dropbear /tmp/
	/tmp/dropbear 
fi

exit

