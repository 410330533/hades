# mysql
apt-get install mysql-server-5.5

macPorts install mysql
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

# configuration
```conf
[mysqld]
character_set_server = utf8
collation_server = utf8_general_ci
innodb_file_per_table = 1
innodb_lock_wait_timeout = 120
innodb_buffer_pool_size = 64M
skip-networking = OFF

log_bin = /var/log/mysql/mysql-bin.log
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
    CHANGE MASTER TO MASTER_HOST='192.168.1.101', MASTER_USER='repl', MASTER_PASSWORD='repl', MASTER_LOG_FILE='mysql-bin.000001', MASTER_LOG_POS=0;
    SHOW MASTER STATUS;
    SHOW SLAVE STATUS;
    STOP SLAVE;
    RESET SLAVE;
    START SLAVE;
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

# mysqlbinlog
```shell
mysqlbinlog --no-defaults mysql-bin-2.001895 | less
mysqlbinlog mysql-bin.000048 --start-position=93758480 --stop-position=93758616 | mysql -uroot -p
```

# mysql-proxy
[mysql-proxy official doc](http://dev.mysql.com/doc/refman/5.0/en/mysql-proxy.html)
```shell
sudo apt-get install mysql-proxy
sudo vi /etc/mysql-proxy.cnf

[mysql-proxy]
admin-address = localhost:4041
admin-username = mahone
admin-password = taobao
admin-lua-script = /usr/share/mysql-proxy/admin.lua

proxy-read-only-backend-addresses = 10.110.22.217:3306;10.12.22.212:3306 (slave server)
proxy-backend-addresses = 10.157.3.54:3306 (master server)
proxy-address = localhost:4040
proxy-lua-script=/usr/share/mysql-proxy/rw-splitting.lua

log-file = /var/tmp/mysql-proxy.log
log-level = debug
daemon = true

sudo chmod 660 /etc/mysql-proxy.cnf
sudo mysql-proxy --defaults-file=/etc/mysql-proxy.cnf
```

# mysqlslap
[mysqlslap official doc](http://dev.mysql.com/doc/refman/5.1/en/mysqlslap.html)
```shell
自动生成测试表和数据的形式，分别模拟 50 和 100 个客户端并发连接处理 1000 个 query 的情况。
mysqlslap -a --concurrency=50,100 --number-of-queries=1000

增加 --debug-info 选项，可以输出内存和CPU信息。
mysqlslap -a --concurrency=50,100 --number-of-queries=1000 --debug-info

增加 --iterations 选项，可以 重复执行 5 次
mysqlslap -a --concurrency=50,100 --number-of-queries=1000 --iterations=5 --debug-info

针对远程主机上的 mysql 进行测试。
mysqlslap -a --concurrency=50,100 --number-of-queries=1000 -h 172.16.81.99 -P 3306 -p

使用 --only-print 选项，可以查看 mysqlslap 在测试过程中如何执行的 sql 语句。
在这种方式下，仅会对数据库进行模拟操作。如下显示的自动产生测试表和数据的情况下，
mysqlslap 的执行过程： 创建一个临时的库 mysqlslap ，并在测试结束是会将其删除。
mysqlslap -a --only-print  

使用 --defaults-file 选项，指定从配置文件中读取选项配置。 
使用 --number-int-cols 选项，指定表中会包含 4 个 int 型的列。 
使用 --number-char-cols 选项，指定表中会包含 35 个 char 型的列。 
使用 --engine 选项，指定针对何种存储引擎进行测试。
mysqlslap --defaults-file=/etc/my.cnf --concurrency=50,100,200 --iterations=1 --number-int-cols=4 
--number-char-cols=35 --auto-generate-sql --auto-generate-sql-add-autoincrement --auto-generate-sql-load-type=mixed
--engine=myisam,innodb --number-of-queries=200 --debug-info -S /tmp/mysql.sock
```
