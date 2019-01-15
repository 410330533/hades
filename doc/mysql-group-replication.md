# 18.2.1.1 Deploying Instances for Group Replication
https://dev.mysql.com/doc/refman/8.0/en/group-replication-getting-started-deploying-instances.html

```shell
mkdir data
mysql-8.0.12-linux-glibc2.12-x86_64/bin/mysqld --initialize-insecure --basedir=/db/mysql-8.0.12-linux-glibc2.12-x86_64/ --datadir=/db/data/s1
mysql-8.0.12-linux-glibc2.12-x86_64/bin/mysqld --initialize-insecure --basedir=/db/mysql-8.0.12-linux-glibc2.12-x86_64/ --datadir=/db/data/s2
mysql-8.0.12-linux-glibc2.12-x86_64/bin/mysqld --initialize-insecure --basedir=/db/mysql-8.0.12-linux-glibc2.12-x86_64/ --datadir=/db/data/s3
```

```shell
docker run -e MYSQL_ROOT_PASSWORD=... -d -v ~/git/hades/doc/mysql-group-replication-conf-1:/etc/mysql/conf.d --name mysql-g1 -h mysql-g1 --network my-mysql-mgr -p 33061:3306 mysql:8.0.13
docker run -e MYSQL_ROOT_PASSWORD=... -d -v ~/git/hades/doc/mysql-group-replication-conf-2:/etc/mysql/conf.d --name mysql-g2 -h mysql-g2 --network my-mysql-mgr -p 33062:3306 mysql:8.0.13
docker run -e MYSQL_ROOT_PASSWORD=... -d -v ~/git/hades/doc/mysql-group-replication-conf-3:/etc/mysql/conf.d --name mysql-g3 -h mysql-g3 --network my-mysql-mgr -p 33063:3306 mysql:8.0.13
```

# 18.2.1.2 Configuring an Instance for Group Replication
https://dev.mysql.com/doc/refman/8.0/en/group-replication-configuring-instances.html

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
https://dev.mysql.com/doc/refman/8.0/en/group-replication-user-credentials.html

```shell
mysql-8.0.12-linux-glibc2.12-x86_64/bin/mysqld --defaults-file=/db/data/s1/auto.cnf
```

```shell
SET SQL_LOG_BIN=0;

CREATE USER rpl_user@'%' IDENTIFIED BY '...';
GRANT REPLICATION SLAVE ON *.* TO rpl_user@'%';
FLUSH PRIVILEGES;

SET SQL_LOG_BIN=1;
```

```shell
CHANGE MASTER TO MASTER_USER='rpl_user', MASTER_PASSWORD='...' FOR CHANNEL 'group_replication_recovery';
```

# 18.2.1.4 Launching Group Replication
https://dev.mysql.com/doc/refman/8.0/en/group-replication-launching.html

```shell
INSTALL PLUGIN group_replication SONAME 'group_replication.so';
```

```shell
SHOW PLUGINS;
```

```shell
s1
SET GLOBAL group_replication_bootstrap_group=ON;
START GROUP_REPLICATION;
SET GLOBAL group_replication_bootstrap_group=OFF;
```

```sql
mysql> SELECT * FROM performance_schema.replication_group_members;
```

```sql
mysql> CREATE DATABASE test;
mysql> USE test;
mysql> CREATE TABLE t1 (c1 INT PRIMARY KEY, c2 TEXT NOT NULL);
mysql> INSERT INTO t1 VALUES (1, 'Luis');

mysql> SELECT * FROM t1;

mysql> SHOW BINLOG EVENTS;
```

# ref

https://dev.mysql.com/doc/refman/8.0/en/group-replication.html
