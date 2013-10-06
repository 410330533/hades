# homebrew
install `ruby -e "$(curl -fsSL https://raw.github.com/mxcl/homebrew/go)"`

# install macPorts
```shell
wget https://distfiles.macports.org/MacPorts/MacPorts-2.1.3.tar.bz2
tar xjvf MacPorts-2.1.3.tar.bz2
cd MacPorts-2.1.3
./configure && make && sudo make install

sudo port -v selfupdate
```

#macPorts install mysql
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
sudo /opt/local/lib/mysql55/bin/mysql_install_db --user=mysql

6- Start MySQL:
sudo /opt/local/share/mysql55/support-files/mysql.server start

7- Set root password:
/opt/local/lib/mysql55/bin/mysqladmin -u root password 'changepasswordhere'

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

