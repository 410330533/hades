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
