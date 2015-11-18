# install
```conf
fdish /dev/sda
mkfs.ext4 /dev/sda
mount /dev/sda /mnt

vi /etc/pacman.d/mirrorlist
Server = http://mirrors.aliyun.com/archlinux/$repo/os/$arch
pacstrap -i /mnt base

genfstab -U -p /mnt >> /mnt/etc/fstab

arch-chroot /mnt /bin/bash

vi /etc/locale.gen
en_US.UTF-8 UTF-8
locale-gen
echo LANG=en_US.UTF-8 > /etc/locale.conf 

ln -s /usr/share/zoneinfo/Asia/Shanghai /etc/localtime

echo arch > /etc/hostname

passwd

pacman -S grub
grub-install --force /dev/sda
grub-mkconfig -o /boot/grub/grub.cfg

exit
umount /mnt
reboot
```
