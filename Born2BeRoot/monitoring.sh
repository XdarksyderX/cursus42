#!/bin/bash

#ARCH
arch=$(uname -a)


#CPU PHYSICAL CORES
cpuphy=$(grep "physical id" /proc/cpuinfo | wc -l)

#CPU LOGICAL CORES
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)

#CPU USAGE
cpupercent=$(vmstat 1 5 | tail -1 | awk '{print $15}') #Intervalo de tiempo del 1 al 5

#RAM USAGE
memused=$(free --mega | awk '$1 == "Mem:" {printf $3}')
memtotal=$(free --mega | awk '$1 == "Mem:" {printf $2}')
memper=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

#DISK USAGE
diskused=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_usage += $3} END {print disk_usage}')
disktotal=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_total += $2} END {print disk_total}')
diskpercent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_usage += $3} {disk_total += $2} END {printf("%d"), disk_usage/disk_total*100}')

#LAST BOOT
lastboot=$(who -b | awk '{print $4 " " $5}')
lvmuse=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo "yes"; else echo "no"; fi

#TCP CONNECTIONS
tcpc=$(ss -ta | grep ESTAB | wc -l)

#USER LOG
userlog=$(who | wc -l)

#NETWORK INFORMATION
ip=$(hostname -I)
mac=$(ip link show | grep "link/ether" | awk '{print $2}')

#SUDO USAGE
sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	Architecture: $arch
		CPU physical: $cpuphy
		vCPU: $cpuv
		Memory Usage: $memused/${memtotal}MB ($memper%)
		Disk Usage: $diskused/${disktotal} ($diskpercent%)
		CPU load: $cpupercent%
		Last boot: $lastboot
		LVM use: $lvmuse
		Connections TCP: $tcpc ESTABLISHED
		User log: $userlog
		Network: IP $ip ($mac)
		Sudo: $sudo cmd"