# zabbix

## server install

### install
```shell
apt-get install dbconfig-common
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
mysql -hlocalhost -umahone -p zabbix < database/mysql/schema.sql
mysql -hlocalhost -umahone -p zabbix < database/mysql/images.sql
mysql -hlocalhost -umahone -p zabbix < database/mysql/data.sql
```

### config zabbix
```shell
vi /usr/local/etc/zabbix_server.conf
DBName=zabbix
DBUser=root
DBPassword=xxoo
DBPort=3306
```

### start
```shell
/usr/local/sbin/zabbix_server
```

## client install

### install
```shell
./configure --prefix=/usr/local --enable-agent
make
make install
```

### config zabbix
```shell
vi /usr/local/etc/zabbix_agentd.conf
Server=127.0.0.1
ServerActive=127.0.0.1
Hostname=Zabbix server
其中Server和ServerActive都指定zabbixserver的IP地址，不同的是，前者是被动后者是主动。也就是说Server这个配置是用来允许127.0.0.1这个ip来我这取数据。而serverActive的127.0.0.1的意思是，客户端主动提交数据给他。
```

### start
```shell
/usr/local/sbin/zabbix_agentd
```

## zabbix管理网站配置
```shell
cp -rp frontends/php/* zabbix_frontends/
```

# link
- [zabbix download](http://www.zabbix.com/download.php)
- [zabbix doc](http://www.zabbix.com/documentation.php)
- [ttlsa zzabix](http://www.ttlsa.com/monitor/zabbix/)
- [图文讲解zabbix安装全过程（5）](http://www.ttlsa.com/zabbix/install-zabbix-on-linux-5-ttlsa/)
