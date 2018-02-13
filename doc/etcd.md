# install
```
apt-get install etcd
```

# cmd
```
etcdctl member list
etcdctl watch testkey
etcdctl ls

etcdctl put testkey "hello world"
etcdctl get testkey
etcdctl del testkey
```