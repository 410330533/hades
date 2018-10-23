# replication
```shell
replication:
    GRANT REPLICATION SLAVE ON *.* TO repl@'192.168.0.%' IDENTIFIED BY 'repl';
    (master):
        server-id = 1
        log_bin = /var/log/mysql/mysql-bin.log
    (slave):
        server-id = 2
        log_bin = /var/log/mysql/mysql-bin.log
        relay_log = /var/log/mysql/mysql-relay-bin.log
        log_slave_updates = 1
        read_only = 1
    show binary logs;
    CHANGE MASTER TO MASTER_HOST='192.168.1.101', master_port=3306, MASTER_USER='repl', MASTER_PASSWORD='repl', MASTER_LOG_FILE='mysql-bin.000001', MASTER_LOG_POS=0;
    SHOW MASTER STATUS;
    SHOW SLAVE STATUS;
    START SLAVE;
    STOP SLAVE;
    RESET MASTER;
    RESET SLAVE;
    mysqldump –master-data –single-transaction –user=username –password=password dbname> dumpfilename
```

# group commit
```
slave_parallel_workers      = 4
slave_parallel_type         = LOGICAL_CLOCK
master_info_repository      = table
relay_log_info_repository   = table
relay_log_recovery          = 1
slave_preserve_commit_order = 1
```
https://www.cnblogs.com/zhoujinyi/p/5704567.html
