```shell
mount -o username=${username},password=${password} //${ip}/e$ /home/win
unmount /home/win

find ~/src -time=mtime -3 -exec ls -l {} \;
find . -name "*.php" -exec dos2unix {} \;
-path pathname -prune: 避开指定子目录pathname查找。
-path expression -prune:避开表达中指定的一组pathname查找。
find . -path "./DontSearchPath" -prune -o -name "datafile*" -print
find . \( -path "./DontSearchPath" -o -path "./DoSearchPath" \) -prune -o -name "datafile*" -print
find . -name "*.php" -exec php -l {} \; | grep -v 'No syntax errors'

dos2unix [-kn] file [newfile]
unix2dos [-kn] file [newfile]

iconv -f 原编码 -t 新编码 filename [-o newfile]

type -a ls
echo $PATH | cut -d ':' -f 1,3
export | cut -c 12-
cat /etc/passwd | sort -t ':' -k 3 -n
last | cut -d ' ' -f1 | sort | uniq -c
last | tee last.list | cut -d ' ' -f1
last | tr '[a-z]' '[A-Z]'
cat /etc/passwd | tr -d ':'
join -t ':' /etc/passwd /etc/shadow
join -t ':' -1 4 /etc/passwd -2 3 /etc/group
paste /etc/passwd /etc/shadow
expand -t 4 filename
split -b 300k /etc/termcap termcap
split -l 10 /etc/termcap termcap
tar -cvf - /home | tar -xvf -
grep -n 'go\{2,5\}g' regular_express.txt
nl /etc/passwd | sed -e '2,5d'
nl /etc/passwd | sed -e '2a drink tea'
nl /etc/passwd | sed -e '2i drink tea'
sed -e 's/replace_str/new_str/g'
printf '%10s %5i %8.2f \n' $ (cat printf.txt)
last -n 5 | awk '{print $1,$3}'
cat /etc/passwd | awk '{FS=":"} $3 < 10 {print $1, $3}'
finger mahone
id mahone
w
who
lastlog
at now +5 minutes
batch 23:00 2012-01-24
pstree
kill -SIGHUP $(ps aux | grep 'syslog' | grep -v 'grep' | awk '{print $2}')
killall -9 httpd
nice -n number vi
renice number PID
free -m
uname -a
uptime
netstat [-atunlp]
lsof -u mahone
logrotate -v /etc/logrotate.conf
runlevel
nmap 192.168.1.100
iostat -d 2 3
dd if=/dev/sda of=/dev/sdb

find / -print | cpio -covB > /dev/st0
cpio -iduv < /dev/st0

dump -0u -f /backupdata/home.dump /home
dump -1u -f /backupdata/home.dump.1 /home
tar --exclude /proc --exclude /mnt --exclude /tmp --exclude /backupdata -jcvp -f /backupdata/system.tar.bz2 /
tar -N '2012-02-06' -jpcv -f /backupdata/home.tar.bz2 /home
tar -jpcvf mysql.`date +%Y-%m-%d`.tar.bz2 /var/lib/mysql
tar -tf log.tar
tar -xf log.tar -C log_dir
rsync -av /home /backupdata
rsync -av -e ssh /backup/weekly mahone@127.0.0.1:/home/backup
echo "Welcome to linuxde.net" | openssl enc -base64
echo "V2VsY29tZSB0byBsaW51eGRlLm5ldAo=" | openssl enc -base64 -d
```

# grub
```shell
update-grub // 更新 grub 信息
grub-install /dev/sda
```

# ibus
```shell
apt-get install ibus-googlepinyin
```

# linux kernel
```shell
make mrproper
make clean
make menuconfig
make oldconfig
make xconfig
make gconfig
make config
make vmlinux 未经压缩的内核
make modules 仅内核模块
make bzImage 经过压缩的内核
make all 进行上述的三个操作
make modules_install
```

# rpm
```shell
/var/lib/rpm
rpm -ivh rp-pppoe-3.5-32.1.i386.rpm
rpm -Uvh rp-pppoe-3.5-32.1.i386.rpm
rpm -ql logrotate
rpm -qi logrotate
rpm -qc logrotate
rpm -qd logrotate
rpm -qR logrotate
rpm -qf /bin/sh
rpm -qpR filename.i386.rpm
rpm -V logrotate
rpm -Vf /etc/crontab
rpm --import /etc/pki/rpm-gpg/RPM-GPG-KEY-CentOS-5
rpm -e pam
rpm --rebuilddb
rpmbuild --rebuild rp-pppoe-3.5-32.1.src.rpm
rpmbuild -ba rp-pppoe.spec 编译并同时生成RPM与SRPM文件
rpmbuild -bb rp-pppoe.spec 仅编译成RPM文件
```

# yum
```shell
yum search raid
yum info mdadm
yum list
yum list updates
yum install pam-devel
yum remove pam-devel
yum clean all
vi /etc/yum.repos.d/CentOS-Base.repo
yum grouplist
yum groupinfo XFCE-4.4
yum groupinstall XFCE-4.4
```

# gcc
```shell
gcc -c hello.c
gcc -O -c hello.c
gcc sin.c -lm -L /usr/lib -I /usr/include
gcc test.c -o xxx -std=c99;
```

# user
```shell
useradd mahone -m -s /bin/bash
passwd mahone
usermod -s /bin/bash -l oldname newname
userdel -r mahone
groupadd mahone
groupmod -g 1001 -n new old
groupdel mahone
gpasswd groupname
```

# shutdown
```shell
shutdown -h now
shutdown -r now
```

# net
```conf
/etc/network/interfaces
auto lo
iface lo inet loopback
auto eth0
iface eth0 inet static
address 192.168.1.102
netmask 255.255.255.0
gateway 192.168.1.1
invoke-rc.d networking restart
```

# apt-get
```shell
/var/cache/apt/archives/
/var/cache/apt/archives/partial/
apt-get build-dep pkgname 安装相关的编译环境
apt-get source pkgname 下载该包的源代码
apt-get check 检查是否有损坏的依赖
apt-get update
    在修改/etc/apt/sources.list或/etc/apt/preferences之後运行该命令。此外您需要定期运行这一命令以确保您的软件包列表是最新的
apt-get install packagename
    安装一个新软件包(参见下文的aptitude)
apt-get remove packagename
    卸载一个已安装的软件包(保留配置文档)
apt-get --purge remove packagename
    卸载一个已安装的软件包(删除配置文档)
apt-get clean
    这个命令会把安装的软件的备份也删除，但是这样不会影响软件的使用
apt-get autoclean
    定期运行这个命令来清除那些已卸载的软件包的.deb文档。通过这种方式，您能够释放大量的磁盘空间。假如您的需求十分迫切，能够使用apt-get clean以释放更多空间。这个命令会将已安装软件包裹的.deb文档一并删除。大多数情况下您不会再用到这些.debs文档，因此假如您为磁盘空间不足而感到焦头烂额，这个办法也许值得一试
apt-get upgrade
    更新任何已安装的软件包
apt-get dist-upgrade
    将系统升级到新版本
apt-cache search string
    在软件包列表中搜索字符串
apt-cache showpkg pkg
    显示软件包信息
apt-cache dumpavail
    打印可用软件包列表
apt-cache show pkg
    显示软件包记录，类似于dpkg –print-avail
apt-cache pkgname
    打印软件包列表中任何软件包的名称
aptitude update
aptitude upgrade
aptitude dist-upgrade
aptitude install pkgname
aptitude remove pkgname
aptitude purge pkgname
aptitude search string
aptitude show pkgname
aptitude clean
aptitude autoclean
```

# cowsay, fortunes
```shell
apt-get install cowsay
apt-get install fortunes
apt-get install fortune-zh
apt-get install fortunes-ubuntu-server
```

# expect
```shell
apt-get install expect
```

# dstat
```shell
apt-get install dstat
dstat -cdlmnpsy
```

# tmux
```shell
apt-get install tmux
```
# byobu
```shell
apt-get install byobu
```

# music
```shell
apt-get install lame
apt-get install mp3splt
apt-get install shntool
apt-get install flac
apt-get install cuetools
apt-get install wavpack
shnsplit -f CDImage.cue -i ape -o "cust ext=mp3 lame -b 320 - %f" CDImage.ape
```

# siege
```shell
apt-get install siege
siege -c100 -r10 -b http://www.qq.com
```

# crontab
```shell
crontab [-u username] [-l|-e|-r]
minute hour day month week command
```

# ssh
```shell
apt-get install openssh-server
ssh-keygen -t rsa
```

# vim
```conf
apt-get install vim
set nu
set hlsearch
set autoindent
set backup
set ruler
set showmode
set backspace=(0,1,2)
set
set all
syntax on
set bg=(light,dark)
set tabstop=4
set shiftwidth=4
set expandtab
:%s/search_str/replace_str/g
```

# rabbitMQ
```shell
http://www.rabbitmq.com/releases/rabbitmq-server/v3.0.4/rabbitmq-server_3.0.4-1_all.deb
deb http://www.rabbitmq.com/debian/ testing main
wget http://www.rabbitmq.com/rabbitmq-signing-key-public.asc
sudo apt-key add rabbitmq-signing-key-public.asc
sudo apt-get install rabbitmq-server
```

# svn
```shell
apt-get install subversion
svnadmin create repository
svnserve -d -r repository
```

# vsftp
```shell
apt-get install vsftpd
service vsftpd status[start, stop, restart]
ftp ftp.ruby-lang.org
ftp> ?
ftp> passive
```

# samba
```shell
apt-get install samba
service smbd status[start, stop, restart]
useradd -m testsamba
smbpasswd -a testsamba
[root]
    path = / 
    browseable = yes 
    writable = yes
```

# apache
```shell
apt-get install apache2
vi /etc/apache2/apache2.conf
a2enmod a2dismod
ab -c 100 -n 10000 http://127.0.0.1:8080/
```

# git
```shell
apt-get install git
git config --global user.name mahone3297
git config --global user.email 329730566@qq.com
git config --global core.editor vim
git config --global color.ui true
git config --global alias.st status
git config --global alias.co checkout
git config --global alias.ci commit
git config --global alias.br branch
git config --unset --global user.name
git commit --amend
git ls-files --stage
git cat-file -p 264b73
git archive master | tar -x -C src
    [remote "origin"]
        fetch = +refs/heads/*:refs/remotes/origin/*
        url = https://github.com/u-cosmetics/oms.git
    [branch "develop"]
        remote = origin
        merge = refs/heads/develop
    [branch "master"]
        remote = origin
        merge = refs/heads/master
    [remote "localpc"]
        url = git@localhost:oms.git
        fetch = +refs/heads/*:refs/remotes/localpc/*
    [remote "all"]
        url = https://github.com/u-cosmetics/oms.git
        url = git@localhost:oms.git
```

# gitosis
```shell
git clone https://github.com/res0nat0r/gitosis.git
cd gitosis
sudo python setup.py install
sudo adduser --system --shell /bin/sh --gecos 'git version control' --group --disabled-password --home /home/git git
sudo -H -u git gitosis-init < /home/mahone/.ssh/id_rsa.pub
git clone git@localhost:gitosis-admin.git
```

# nodejs
```shell
git clone https://github.com/joyent/node.git
cd node
./configure --prefix=$HOME/node --debug
make && make install
curl http://npmjs.org/install.sh | sh
```

# Java
```shell
JAVA_HOME: D:\Program Files (x86)\Java\jdk1.6.0_27
CLASSPATH: .;%JAVA_HOME%\lib\tools.jar;%JAVA_HOME%\lib\dt.jar
Path: %JAVA_HOME%\bin
```

# php
```shell
apt-get install php5
apt-get install php-apc
apt-get install php-pear
apt-get install php5-cli
apt-get install php5-cgi
apt-get install php5-curl
apt-get install php5-dev
apt-get install php5-gd
apt-get install php5-fpm
apt-get install php5-memcache
apt-get install php5-mysql
apt-get install php5-xdebug
```

# phpunit
```shell
pear upgrade pear
pear config-set auto_discover 1
pear install pear.phpunit.de/PHPUnit
```

# phpdoc
```shell
pear upgrade PhpDocumentor
phpdoc -d parsedir -t targetdir -o HTML:default:default
```

# ruby
```bash
apt-get install ruby
apt-get install rubygems
apt-get install ruby-rvm
apt-get install rails
gem install rails --include-dependencies
gem install capistrano capistrano-ext
curl -L https://get.rvm.io | bash -s stable
载入 RVM 环境（新开 Termal 就不用这么做了，会自动重新载入的）
source ~/.rvm/scripts/rvm
替换 Ruby 下载地址到国内淘宝镜像服务器
sed -i .bak 's!ftp.ruby-lang.org/pub/ruby!ruby.taobao.org/mirrors/ruby!' $rvm_path/config/db
安装 readline 包
rvm pkg install readline
安装 Ruby 2.0.0
rvm install 2.0.0 --with-readline-dir=$rvm_path/usr
rvm 2.0.0 --default
gem source -r https://rubygems.org/
gem source -a http://ruby.taobao.org
gem install bundler rails
```

# nginx
```conf
apt-get install nginx
php
location / {
    include fastcgi_params;
    fastcgi_param SCRIPT_FILENAME $fastcgi_script_name;  # [1]
    fastcgi_param PATH_INFO $fastcgi_script_name;        # [2]
    fastcgi_pass 127.0.0.1:9002;
}

python
location / {
    include uwsgi_params;
    uwsgi_pass 127.0.0.1:9090;
}
```

# spawn-fcgi
```shell
apt-get install spawn-fcgi
spawn-fcgi -a 127.0.0.1 -p 9000 -C 10 -u www-data -f /usr/bin/php-cgi
spawn-fcgi -a 127.0.0.1 -p 9002 -F 5 -d /home/mahone/git/test -f /home/mahone/git/test/index.py
```

# rcconf
```shell
apt-get install rcconf
```

# cacti
```shell
apt-get install cacti
```

# mongo
```shell
apt-get install mongodb
pecl install mongo(php扩展)
```

# memcache
```shell
apt-get install memcached
memcached -m 64 -p 11211 -u memcache -l 127.0.0.1
```

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

# python
```shell
apt-get install python
apt-get install python-dev
apt-get install python-setuptools
apt-get install python-opencv
apt-get install python-psyco
apt-get install python-pip
pip install flacsync --upgrade
pip install MySQL-python
pip install web.py
pip install flup
pip install uwsgi
uwsgi -s 127.0.0.1:9090 -w index
pip install pythonbrew
sh setuptools-0.6c11-py2.7.egg
easy_install MySQL-python
easy_install mechanize
easy_install mutagen
easy_install pysox
easy_install web.py
```

#go
```shell
add-apt-repository ppa:gophers/go
apt-get update
apt-get install golang-stable
```

# linux系统启动过程:
```conf
加载BIOS的硬件信息与进行自我测试，并依据设置取得第一个可启动的设备
读取并执行第一个启动设备内MBR的boot loader(即是grub, spfdisk等程序)
依据boot loader的设置加载kernel, kernel会开始检测硬件与加载驱动程序
在硬件驱动成功后，kernel会主动调用init进程，而init会取得run-level信息
init执行/etc/rc.d/rc.sysinit文件来准备软件执行的操作环境(如网络，时区等)
init执行run-level的各个服务的启动(script方式)
init执行/etc/rc.d/rc.local
init执行终端机模拟程序mingetty来启动login程序，最后就等待用户登录
```

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
