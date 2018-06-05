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
lvdisplay
lvs

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