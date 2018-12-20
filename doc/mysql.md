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
ALTER USER user IDENTIFIED BY 'auth_string';
https://dev.mysql.com/doc/refman/8.0/en/set-password.html

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
