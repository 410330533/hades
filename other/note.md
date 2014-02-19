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
pkill -kill -t pts/1
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

# time
```shell
sudo dpkg-reconfigure tzdata
sudo ntpdate cn.pool.ntp.org
```

# grub
```shell
update-grub // 更新 grub 信息
grub-install /dev/sda
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

# apache
```shell
apt-get install apache2
vi /etc/apache2/apache2.conf
a2enmod a2dismod
ab -c 100 -n 10000 http://127.0.0.1:8080/
```

# Java
```shell
JAVA_HOME: D:\Program Files (x86)\Java\jdk1.6.0_27
CLASSPATH: .;%JAVA_HOME%\lib\tools.jar;%JAVA_HOME%\lib\dt.jar
Path: %JAVA_HOME%\bin
```

# spawn-fcgi
```shell
apt-get install spawn-fcgi
spawn-fcgi -a 127.0.0.1 -p 9000 -C 10 -u www-data -f /usr/bin/php-cgi
spawn-fcgi -a 127.0.0.1 -p 9002 -F 5 -d /home/mahone/git/test -f /home/mahone/git/test/index.py
```

# memcache
```shell
apt-get install memcached
memcached -m 64 -p 11211 -u memcache -l 127.0.0.1
```

# console printf color
```shell
#define NONE         "\033[m"  
#define RED          "\033[0;32;31m"
#define LIGHT_RED    "\033[1;31m"
#define GREEN        "\033[0;32;32m"
#define LIGHT_GREEN  "\033[1;32m"
#define BLUE         "\033[0;32;34m"
#define LIGHT_BLUE   "\033[1;34m"
#define DARY_GRAY    "\033[1;30m"
#define CYAN         "\033[0;36m"
#define LIGHT_CYAN   "\033[1;36m"
#define PURPLE       "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN        "\033[0;33m"
#define YELLOW       "\033[1;33m"
#define LIGHT_GRAY   "\033[0;37m"
#define WHITE        "\033[1;37m"

背景色                        字体色
40: 黑                          30: 黑
41: 红                          31: 红
42: 绿                          32: 绿
43: 黄                          33: 黄
44: 蓝                          34: 蓝
45: 紫                          35: 紫
46: 深绿                      36: 深绿
47: 白色                      37: 白色

\033[0m   关闭所有属性  
\033[1m   设置高亮度  
\033[4m   下划线  
\033[5m   闪烁  
\033[7m   反显  
\033[8m   消隐  
\033[30m   --   \033[37m   设置前景色  
\033[40m   --   \033[47m   设置背景色  
\033[nA   光标上移n行  
\033[nB   光标下移n行  
\033[nC   光标右移n行  
\033[nD   光标左移n行  
\033[y;xH设置光标位置  
\033[2J   清屏  
\033[K   清除从光标到行尾的内容  
\033[s   保存光标位置  
\033[u   恢复光标位置  
\033[?25l   隐藏光标  
\033[?25h   显示光标
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

