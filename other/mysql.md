# mysql
apt-get install mysql-server
```conf
[mysqld]
    character_set_server = utf8
    collation_server = utf8_general_ci
    innodb_lock_wait_timeout = 120
    innodb_buffer_pool_size = 64M
```
远程访问mysql
```shell
grant all privileges on *.* to mahone@'%' identified by 'taobao'
vi /etc/mysql/my.cnf
    #bind-address = 127.0.0.1
    
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
        
恢复数据库管理员密码:
```shell
1./etc/init.d/mysql stop
2.mysqld_safe --skip-grant-tables --skip-networking
3.mysql -uroot
4.use mysql;
    update user set password=password where user="root";
    flush privileges;
    exit;
5.kill -9 6896(msqld_safe进程)
    /etc/init.d/mysql start
6.mysql -uroot -p
```
数据库备份, 恢复:
```shell
mysqldump -hlocalhost -uroot -ptaobao --default-character-set=utf8 5imimi > 5imimi.sql
mysql -hlocalhost -uroot -ptaobao --default-character-set=utf8 5imimi < 5imimi.sql
mysqldump -h<host> -u<user> -p<password> --no-data 5imimi | sed 's/ AUTO_INCREMENT=[0-9]*\b//' > 5imimi.sql
```

# mysql-proxy
```shell
sudo apt-get install mysql-proxy
sudo vi /etc/mysql-proxy.cnf
```
```conf
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
```
```shell
sudo chmod 660 /etc/mysql-proxy.cnf
sudo mysql-proxy --defaults-file=/etc/mysql-proxy.cnf
```
[mysql-proxy official doc](http://dev.mysql.com/doc/refman/5.0/en/mysql-proxy.html)