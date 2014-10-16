# samba
```shell
apt-get install samba
service smbd status[start, stop, restart]
useradd -m testsamba
smbpasswd -a testsamba

[root]
    path = / 
    browseable = yes 
    writable = yes
```
