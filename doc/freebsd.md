# start ssh
```shell
vi /etc/inetd.conf 删除 ssh #
vi /etc/rc.conf sshd_enable="yes"
vi /etc/ssh/sshd_config
    PermitRootLogin yes
    PasswordAuthentication yes
    PermitEmptyPasswords no
/etc/rc.d/sshd start
```

# port search
```shell
cd /usr/ports
make fetchindex
make index
make quicksearch name=lsof
make search name=lsof
```

# portsnap
```shell
1. To download a compressed snapshot of the Ports Collection into /var/db/portsnap:
# portsnap fetch

2. When running Portsnap for the first time, extract the snapshot into /usr/ports:
# portsnap extract

3. After the first use of Portsnap has been completed as shown above, /usr/ports can be updated as needed by running:
# portsnap fetch
# portsnap update
When using fetch, the extract or the update operation may be run consecutively, like so:
# portsnap fetch update
```

# ports
```shell
make config-recursive
make config
make showconfig
make rmconfig

cd /usr/ports/sysutils/lsof
make install
make clean
make install clean

cd /usr/ports/sysutils/lsof
make deinstall
```

# link
- [freeBSD](http://www.freebsd.org/)
- [ports](http://www.freebsd.org/ports/)
- [5.5. Using the Ports Collection](http://www.freebsd.org/doc/en_US.ISO8859-1/books/handbook/ports-using.html)
