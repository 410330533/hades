# 18.2.1.1 Deploying Instances for Group Replication

```shell
mkdir data
mysql-8.0.12-linux-glibc2.12-x86_64/bin/mysqld --initialize-insecure --basedir=/db/mysql-8.0.12-linux-glibc2.12-x86_64/ --datadir=/db/data/s1
mysql-8.0.12-linux-glibc2.12-x86_64/bin/mysqld --initialize-insecure --basedir=/db/mysql-8.0.12-linux-glibc2.12-x86_64/ --datadir=/db/data/s2
mysql-8.0.12-linux-glibc2.12-x86_64/bin/mysqld --initialize-insecure --basedir=/db/mysql-8.0.12-linux-glibc2.12-x86_64/ --datadir=/db/data/s3
```

```shell
docker run -e MYSQL_ROOT_PASSWORD=... -d -v ~/git/hades/doc/mysql-group-replication-conf-1:/etc/mysql/conf.d --name mysql-g1 -p 33061:3306 mysql:8.0.13
docker run -e MYSQL_ROOT_PASSWORD=... -d -v ~/git/hades/doc/mysql-group-replication-conf-2:/etc/mysql/conf.d --name mysql-g2 -p 33062:3306 mysql:8.0.13
docker run -e MYSQL_ROOT_PASSWORD=... -d -v ~/git/hades/doc/mysql-group-replication-conf-3:/etc/mysql/conf.d --name mysql-g3 -p 33063:3306 mysql:8.0.13
```

# 18.2.1.2 Configuring an Instance for Group Replication

```conf
[mysqld]
# server configuration
user     = mysql
pid-file = /db/data/s1/mysqld.pid

datadir  = /db/data/s1
basedir  = /db/mysql-8.0.12-linux-glibc2.12-x86_64/

port     = 24801
socket   = /db/data/s1/s1.sock

server_id                 = 1
gtid_mode                 = ON
enforce_gtid_consistency  = ON
binlog_checksum           = NONE

log_bin                   = binlog
log_slave_updates         = ON
binlog_format             = ROW
master_info_repository    = TABLE
relay_log_info_repository = TABLE

transaction_write_set_extraction        = XXHASH64
loose-group_replication_group_name      = "aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa"
loose-group_replication_start_on_boot   = off
loose-group_replication_local_address   = "127.0.0.1:24901"
loose-group_replication_group_seeds     = "127.0.0.1:24901,127.0.0.1:24902,127.0.0.1:24903"
loose-group_replication_bootstrap_group = off
```

# 18.2.1.3 User Credentials
```shell
mysql-8.0.12-linux-glibc2.12-x86_64/bin/mysqld --defaults-file=/db/data/s1/auto.cnf
```

```shell
CREATE USER rpl_user@'%' IDENTIFIED BY '...';
GRANT REPLICATION SLAVE ON *.* TO rpl_user@'%';
FLUSH PRIVILEGES;
```

```shell
CHANGE MASTER TO MASTER_USER='rpl_user', MASTER_PASSWORD='...' FOR CHANNEL 'group_replication_recovery';
```

# ref

https://dev.mysql.com/doc/refman/8.0/en/group-replication.html