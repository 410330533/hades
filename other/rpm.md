# rpm
```shell
/var/lib/rpm
rpm -ivh rp-pppoe-3.5-32.1.i386.rpm
rpm -Uvh rp-pppoe-3.5-32.1.i386.rpm
rpm -ql logrotate
rpm -qi logrotate
rpm -qc logrotate
rpm -qd logrotate
rpm -qR logrotate
rpm -qf /bin/sh
rpm -qpR filename.i386.rpm
rpm -V logrotate
rpm -Vf /etc/crontab
rpm --import /etc/pki/rpm-gpg/RPM-GPG-KEY-CentOS-5
rpm -e pam
rpm --rebuilddb
rpmbuild --rebuild rp-pppoe-3.5-32.1.src.rpm
rpmbuild -ba rp-pppoe.spec 编译并同时生成RPM与SRPM文件
rpmbuild -bb rp-pppoe.spec 仅编译成RPM文件
```

