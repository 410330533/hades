# [USB Installation Media](https://wiki.archlinux.org/index.php/USB_Installation_Media_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))
```shell
直接覆盖整个 USB 驱动器
dd bs=4M if=/path/to/archlinux.iso of=/dev/sdx && sync

怎样恢复你的 USB 驱动器
dd count=1 bs=512 if=/dev/zero of=/dev/sdx && sync

然后用 gparted 创建一个新的分区表（如"msdos"）和文件系统（如 EXT4，FAT32），或者在终端中：
对于 EXT2/3/4 （相应地调整），命令是：
cfdisk /dev/sdx
mkfs.ext4 /dev/sdx1
e2label /dev/sdx1 USB_STICK

对于 FAT32，安装 dosfstools 软件包并运行：
cfdisk /dev/sdx
mkfs.vfat -F32 /dev/sdx1
dosfslabel /dev/sdx1 USB_STICK
```

# [Beginners' Guide](https://wiki.archlinux.org/index.php/Beginners%27_Guide_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))
```shell
建立网络连接
无线网络
    iw dev
    ip link set wlp3s0 up
    ip link show wlp3s0
    wifi-menu wlp3s0 (接口必须在down状态，否则会报错 ip link set wlp3s0 down)
分区
    fdisk /dev/sda
创建文件系统 格式化
    mkfs.ext4 /dev/sda1
    mkfs.ext4 /dev/sda2
挂载
    mount /dev/sda1 /mnt
    mkdir /mnt/home
    mount /dev/sda2 /mnt/home
选择安装镜像
    vi /etc/pacman.d/mirrorlist
    pacman -Syy
安装基本系统
    pacstrap -i /mnt base base-devel
生成 fstab
    genfstab -U -p /mnt >> /mnt/etc/fstab
Chroot 到新系统
    arch-chroot /mnt /bin/bash

配置系统
locale
    vi /etc/locale.gen
        en_US.UTF-8 UTF-8
        zh_CN.UTF-8 UTF-8
        zh_TW.UTF-8 UTF-8
    locale-gen
    vi /etc/locale.conf
        LANG=en_US.UTF-8
时区
    ln -s /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
硬件时间
    hwclock --systohc --utc
    自动生成 /etc/adjtime
Hostname
    echo archlinux > /etc/hostname
配置网络
    无线网络
        pacman -S iw wpa_supplicant wireless_tools
        pacman -S dialog
        cd /etc/netctl
        cp examples/wireless-wpa my_network
        vi my_network 按照需要修改模版(Interface、ESSID与Key)
        netctl enable my_network 使其启动时自动启动
        自动连接到已知网络
            pacman -S wpa_actiond
            激活netctl-auto服务，他会自动连接到已知的网络并且优雅的处理重新连接和漫游
            systemctl enable netctl-auto@interface_name.service 
设置 Root 密码
    passwd
安装配置启动加载器
    对于BIOS主板
        Grub
            安装grub包并安装它到MBR中
            pacman -S grub
            grub-install --target=i386-pc --recheck /dev/sda
            生成grub配置文件
            grub-mkconfig -o /boot/grub/grub.cfg
卸载分区并重启系统
    先离开chroot环境
    exit
    卸载/mnt中挂载的系统
    umount -R /mnt
    重启计算机
    reboot
```
