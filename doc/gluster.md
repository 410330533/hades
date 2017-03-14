# install
```shell
add-apt-repository ppa:gluster/glusterfs-3.8
apt-get update
apt-get install glusterfs-server
```

# get started
* config the trusted pool
```shell
gluster peer probe 192.168.211.136
gluster peer detach 192.168.211.136
gluster peer status
```

* set up a glusterFS volume
```shell
gluster volume create gv0 replica 2 192.168.211.136:/home/gv0 192.168.211.128:/home/gv0
gluster volume create gv0 replica 2 192.168.211.136:/home/gv1 192.168.211.136:/home/gv2
gluster volume start gv0
gluster volume stop gv0
gluster volume status gv0
gluster volume delete gv0
gluster volume info
```

* mount client
```shell
mkdir ~/gluster_client/
mount -t glusterfs 192.168.211.128:/gv0 ~/gluster_client/
```

# doc
* http://gluster.readthedocs.io/en/latest/Quick-Start-Guide/Quickstart/
