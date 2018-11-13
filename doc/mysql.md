# configuration
```conf
[mysqld]
character_set_server = utf8
collation_server = utf8_general_ci

character_set_server = utf8mb4
collation_server = utf8mb4_general_ci

innodb_file_per_table = 1
innodb_lock_wait_timeout = 120
innodb_buffer_pool_size = 64M

skip-networking = OFF

log_bin = /var/log/mysql/mysql-bin.log
binlog_format = 'MIXED'

slow_query_log = /var/log/mysql/mysql-slow.log
long_query_time = 2
```

# user management
```shell
CREATE USER 'jeffrey'@'localhost' IDENTIFIED BY 'mypass';
http://dev.mysql.com/doc/refman/5.7/en/create-user.html

DROP USER 'jeffrey'@'localhost';
http://dev.mysql.com/doc/refman/5.7/en/drop-user.html

GRANT SELECT ON db2.invoice TO 'jeffrey'@'localhost';
GRANT ALL ON db1.* TO 'jeffrey'@'localhost';
http://dev.mysql.com/doc/refman/5.7/en/grant.html

REVOKE INSERT ON *.* FROM 'jeffrey'@'localhost';
REVOKE ALL PRIVILEGES, GRANT OPTION FROM user [, user] ...
http://dev.mysql.com/doc/refman/5.7/en/revoke.html

SET PASSWORD = PASSWORD('cleartext password');
SET PASSWORD FOR 'jeffrey'@'localhost' = PASSWORD('cleartext password');
http://dev.mysql.com/doc/refman/5.7/en/set-password.html

FLUSH PRIVILEGES;
```

# 恢复数据库管理员密码
```shell
1./etc/init.d/mysql stop
2.mysqld_safe --skip-grant-tables --skip-networking
3.mysql -uroot
4.UPDATE mysql.user SET Password=PASSWORD('MyNewPass') WHERE User='root';
    FLUSH PRIVILEGES;
5.kill -9 6896(msqld_safe进程)
    /etc/init.d/mysql start
6.mysql -uroot -p
```

# 数据库备份, 恢复
```shell
mysqldump --single-transaction --quick db table | gzip > backup.sql.gz
gunzip < backup.sql.gz | mysql
```
