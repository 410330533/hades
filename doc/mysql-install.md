# install

* apt
```shell
apt-get install mysql-server-5.7
mysql_secure_installation
```
* docker
```shell
docker run -d -e MYSQL_ROOT_PASSWORD=my-secret-pw -p 33061:3306 --name mysql.8.0.13-1 mysql:8.0.13
docker run -d -e MYSQL_ROOT_PASSWORD=my-secret-pw -p 33062:3306 --name mysql.8.0.13-2 mysql:8.0.13
docker run -d -e MYSQL_ROOT_PASSWORD=my-secret-pw -p 33063:3306 --name mysql.8.0.13-3 mysql:8.0.13
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