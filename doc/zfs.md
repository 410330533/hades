* zpool
```
zpool list
zpool iostat
zpool status

zpool add poolname /dev/sdc
zpool remove poolname /dev/sdc

zpool replace [-f] [-o property=value] <pool> <device> [new-device]
attach [-f] [-o property=value] <pool> <device> <new-device>
zpool detach <pool> <device>
zpool replace [-f] [-o property=value] <pool> <device> [new-device]

zpool upgrade poolname
zpool upgrade -a

* raid0
zpool create poolname /dev/sdb /dev/sdc

* raid1
zpool create poolname mirror /dev/sdb /dev/sdc

* raid5/raidz1
zpool create poolname raidz1 /dev/sdb /dev/sdc /dev/sdd

* raid6/raidz2
zpool create poolname raidz2 /dev/sdb /dev/sdc /dev/sdd /dev/sde

* raid10
zpool create poolname mirror /dev/sdb /dev/sdc mirror /dev/sdd /dev/sde

zpool destroy poolname
```

* zfs
```
zfs list
zfs list -t snapshot

zfs create poolname/stu
zfs destroy poolname/stu
zfs snapshot poolname/stu@123

zfs set compression=lz4 poolname/stu
zfs get compressratio poolname/stu
zfs set quota=100M poolname/stu
zfs set reservation=100M poolname/stu

zfs snapshot poolname/stu@123
zfs rollback poolname/stu@123
zfs clone poolname/stu@123 poolname/stu/snap123

zfs rename poolname/stu@23 poolname/stu@23-xxx
zfs diff poolname/stu@123 poolname/stu
zfs diff poolname/stu@123 poolname/stu@234
```

* link
https://docs.oracle.com/cd/E23823_01/html/819-5461/preface-1.html#scrolltoc
