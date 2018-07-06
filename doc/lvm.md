* fdisk
```
fdisk /dev/sdb
```

* pv
```
pvcreate /dev/sdb1
pvcreate /dev/sdb2
pvcreate /dev/sdc1
pvcreate /dev/sdc2
pvcreate /dev/sdc3
pvdisplay
pvscan
pvs

pvremove /dev/sdb1
```

* vg
```
vgcreate vg1 /dev/sdb1 /dev/sdb2
vgcreate vg2 /dev/sdc{1,2,3}
vgdisplay
vgscan
vgs

vgextend vg1 /dev/sdb3 /dev/sdb5 /dev/sdb6
vgreduce vg1 /dev/sdb5 /dev/sdb6

vgremove vg1
```

* lv
```
lvcreate -L 10G -n lv1 vg1
lvcreate -l 100%FREE -n lv2 vg1

<!-- create snapshot -->
lvcreate -L 1G -n lv1-snap1 --snapshot /dev/vg1/lv1

<!-- create thin pool -->
apt-get install thin-provisioning-tools

lvcreate --name pool0meta --size 1G vg1 创建元数据卷
lvcreate --name pool0 --size 10G vg1 创建数据卷
lvconvert --thinpool vg1/pool0 --poolmetadata vg1/pool0meta 创建一个精简池
lvconvert --thinpool vg1/pool0 系统自动创建 metadata 卷
lvcreate --name thin1 -V 1G --thinpool vg1/pool0 创建精简卷thin1
lvcreate --name thin2 -V 1G --thinpool vg1/pool0 创建精简卷thin2

lvcreate -L 10G --thinpool pool0 vg1
lvcreate -l+100%FREE --thinpool pool0 vg1
lvcreate -l+100%FREE --poolmetadatasize 1G -T vg1/pool0
lvcreate -l+100%FREE -T vg1/pool0

<!-- create thin lv -->
lvcreate --name lvthin1 --virtualsize 20G --thin vg1/pool0
<!-- create thin lv snapshot -->
lvcreate -n ss1 --snapshot vg1/lvthin1

<!-- thin lv snapshot 需要 active 才能 mount -->
lvchange --activate y --setactivationskip n vg1/ss12

lvdisplay
lvs
http://www.man7.org/linux/man-pages/man8/lvs.8.html

lvresize -L 20G /dev/vg1/lv1
lvresize -L +10G /dev/vg1/lv1
lvresize -L -10G /dev/vg1/lv1
e2fsck -f /dev/vg1/lv1
resize2fs /dev/vg1/lv1

lvremove /dev/vg1/lv1
```

* format
```
mkfs.ext4 /dev/vg1/lv1
mkfs.ext4 /dev/vg1/lv2
```

* mount
```
mount /dev/vg1/lv1 /mnt/lv1
mount /dev/vg1/lv2 /mnt/lv2
umount /mnt/lv1
umount /mnt/lv2
```