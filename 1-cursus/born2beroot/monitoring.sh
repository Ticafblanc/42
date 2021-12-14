#!/bin/bash

 wall " #Architecture: $(uname -a)
 		#CPU physical : $(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
		#vCPU : $(grep "^processor" /proc/cpuinfo | wc -l)
		#Memory Usage: $(free -m | awk '$1 == "Mem:" {print $3}')/$(free -m | awk '$1 == "Mem:" {print $2}')MB ($(free | awk '$1 == "Mem:" {printf "%.2f%%", $3/$2*100}'))
		#Disk Usage: $(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')/$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}'    )GB ($(df -Bm | grep '^/dev/' | grep '/boot$' | awk '{ut += $3} {ft += $2} END {printf "%d%%", ut/ft*100}'))
		#CPU load: $(top -bn1 | grep '^%Cpu' | awk '{printf "%.1f%%", 100 - $8}')
		#Last boot: $(who | awk '{print $3 " " $4}')
		#LVM use: $(if [$(lsblk | grep 'lvm' | wc -l) -eq 0]; then echo "no"; else echo "yes"; fi)
		#Connexions TCP: $(grep "TCP" /proc/net/sockstat | awk '{print $3}') ESTABLISHED
		#User log: $(who | wc -l)
		#Network: IP $(hostname -I) ($(ip addr | grep 'link/ether' | awk '{print $2}'))
		#Sudo : $(journalctl _COMM=sudo | grep "COMMAND" | wc -l) cmd   "
