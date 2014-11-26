# zabbix

## server install

### install
```shell
apt-get install zabbix-agent
apt-get install zabbix-server-mysql zabbix-frontend-php
apt-get install zabbix-proxy-mysql

apt-get install libmysqld-dev libsnmp-dev libssh2-1-dev libcurl4-gnutls-dev
wget http://repo.zabbix.com/zabbix/2.2/ubuntu/pool/main/z/zabbix/zabbix_2.2.2.orig.tar.gz
./configure --prefix=/usr/local --enable-server --enable-proxy --enable-agent --with-mysql --with-libxml2 --with-net-snmp --with-ssh2 --with-libcurl
make
make install
```

### create user
```shell
groupadd zabbix
useradd -g zabbix zabbix
```

### initialize database
```shell
create database zabbix default charset utf8;
```

# link
- [zabbix download](http://www.zabbix.com/download.php)
- [zabbix doc](http://www.zabbix.com/documentation.php)
- [ttlsa zzabix](http://www.ttlsa.com/monitor/zabbix/)
- [图文讲解zabbix安装全过程（5）](http://www.ttlsa.com/zabbix/install-zabbix-on-linux-5-ttlsa/)
