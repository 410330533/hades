# 18.2.1.1 Deploying Instances for Group Replication

```shell
mkdir data
mysql-8.0/bin/mysqld --initialize-insecure --basedir=$PWD/mysql-8.0 --datadir=$PWD/data/s1
mysql-8.0/bin/mysqld --initialize-insecure --basedir=$PWD/mysql-8.0 --datadir=$PWD/data/s2
mysql-8.0/bin/mysqld --initialize-insecure --basedir=$PWD/mysql-8.0 --datadir=$PWD/data/s3
```

# 18.2.1.2 Configuring an Instance for Group Replication

```
[mysqld]

# server configuration
datadir = <full_path_to_data>/data/s1
basedir = <full_path_to_bin>/mysql-8.0/

port    = 24801
socket  = <full_path_to_sock_dir>/s1.sock


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

# ref

https://dev.mysql.com/doc/refman/8.0/en/group-replication.html