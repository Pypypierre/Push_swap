#!/bin/bash
# Excute with admin rights

echo "    _            _ _   _   _       "
echo "   / \   ___ ___(_) |_| \ | | ___  "
echo "  / _ \ / __/ __| | __|  \| |/ _ \ "
echo " / ___ \\__ \__  \ | |_| |\  | (_)"
echo "/_/   \_\___/___/_|\__|_| \_|\___/ "
echo ""
echo "Welcome to the assistant of yunohost to add an external storage to your server !"
echo "01010111 01101111 01110010 01101011  01101111 01100110  01000101 00101110 01000110"
echo "To start, press enter or  any other key to exit"

read answer

if [ "$answer" = "" ]; then
	echo "Let's start my friend"
else
	echo "Goodbye my friend !"
	exit
fi

hdd_uuid=$(blkid | grep "dev/sda1:" | cut -c 12-54)
ssd_uuid=$(blkid | grep "dev/sdb1:" | cut -c 12-54)

#Creating the directories
mkdir /mnt/hdd
mkdir /mnt/ssd

echo "Directories created"

#Mount the disks
mount /dev/sda1 /mnt/hdd
mount /dev/sdb1 /mnt/ssd

echo "Diks mounted"

#Creating subfolders on the disk
mkdir -p /mnt/hdd/home
mkdir -p /mnt/hdd/var/mail
mkdir -p /mnt/ssd/var/lib/mysql
mkdir -p /mnt/ssd/var/lib/postgresql
mkdir -p /mnt/ssd/var/www
mkdir -p /mnt/ssd/opt

echo "Subfolders created"

#Stop services add also databases...
systemctl stop postfix
systemctl stop dovecot 

echo "Services stopped"

#Creating the mount points
#1 | a : Move folders
mv /home /home.bkp
mv /var/mail /var/mail.bkp
mv /var/lib/mysql /var/lib/mysql.bkp
mv /var/lib/postgresql /var/lib/postgresql.bkp
mv /var/www /var/www.bkp
mv /opt /opt.bkp

echo "Move done"

#1 | b : Creation of empty eponymous folders
mkdir /home
mkdir /var/mail
mkdir /var/lib/mysql
mkdir /var/lib/postgresql
mkdir /var/www
mkdir /opt

echo "Empty eponymous folders created"

#2 : Mount the folders on the hard drive
mount --bind /mnt/hdd/home /home
mount --bind /mnt/hdd/var/mail /var/mail
mount --bind /mnt/ssd/var/lib/mysql /var/lib/mysql
mount --bind /mnt/ssd/var/lib/postgresql /var/lib/postgresql
mount --bind /mnt/ssd/var/www /var/www
mount --bind /mnt/ssd/opt /opt

echo "Folders mounted"

#Copying the data
cp -a /home.bkp/. /home/
cp -a /var/mail.bkp/. /var/mail/
cp -a /var/lib/mysql.bkp/. /var/lib/mysql/
cp -a /var/lib/postgresql.bkp/. /var/lib/postgresql/
cp -a /var/www.bkp/. /var/www/
cp -a /opt.bkp/. /opt/

echo "Copy done"

#Restart services and the databases..
systemctl start postfix
systemctl start dovecot

echo "Services restarted"

#Automatically mount on boot
printf "%s /mnt/hdd ext4 defaults,nofail 0 0
/mnt/hdd/home /home none defaults,bind 0 0
/mnt/hdd/var/mail /var/mail none defaults,bind 0 0"  $hdd_uuid  >> /etc/fstab
printf "%s /mnt/ssd ext4 defaults,nofail 0 0
/mnt/ssd/var/lib/mysql /var/lib/mysql none defaults,bind 0 0
/mnt/ssd/var/lib/postgresql /var/lib/postgresql none defaults,bind 0 0
/mnt/ssd/var/www /var/www none defaults,bind 0 0
/mnt/ssd/opt /opt none defaults,bind 0 0"  $ssd_uuid  >> /etc/fstab

echo "Automatic mount after boot configured"
echo "Now ou can then try rebooting the system to check if the disk and subfolders are mounted automatically  : yes or no ?"

read answer

if [ "$answer" = "yes" ]; then
	echo "The system will reboot"
    reboot
else
	echo "Job done, enjoy !"
	echo "But don't forget to check the folders at next boot."

fi
