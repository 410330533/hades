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

# install

* apt
```shell
apt-get install mysql-server-5.7
```
* bin
```shell
./mysqld --defaults-file=~/.my.cnf --initialize
./mysqld --defaults-file=~/.my.cnf --initialize-insecure
./mysqld --defaults-file=~/.my.cnf

./mysql -S /data/sysbench_bare/mysqld.sock -u root -p
./mysql -h 127.0.0.1 -u root -p
```
* mac
```shell
1- Install MacPorts
http://www.macports.org/install.php

2- Update MacPorts:
sudo port selfupdate

3- Install MySQL server and client binaries:
sudo port install mysql55

4- Install MySQL server startup scripts:
sudo port install mysql55-server

5- Initialize the Database:
sudo -u _mysql /opt/local/lib/mysql55/bin/mysql_install_db
sudo /opt/local/lib/mysql55/bin/mysql_install_db --user=mysql

/opt/local/lib/mysql55/bin/mysql_secure_installation

6- Start MySQL:
sudo /opt/local/share/mysql55/support-files/mysql.server start

You can start the MySQL daemon with:
cd /opt/local ; /opt/local/lib/mysql55/bin/mysqld_safe &
You can test the MySQL daemon with mysql-test-run.pl
cd /opt/local/mysql-test ; perl mysql-test-run.pl

7- Set root password:
/opt/local/lib/mysql55/bin/mysqladmin -u root password 'new-password'

8- Enable the startup script so mysql starts on boot
sudo launchctl load -w /Library/LaunchDaemons/org.macports.mysql55-server.plist
– or --
sudo port load mysql55-server

9- If you need to uninstall/reinstall for whatever reason, remove the database directory when you do the uninstall
sudo port uninstall mysql55-server
cd /opt/local/var/db/
sudo rm -rf mysql55/

10- To check the contents of any package:
sudo port contents <package_name>
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
