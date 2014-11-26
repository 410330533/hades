# apt
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
apt-get purge packagename
apt-get clean
    这个命令会把安装的软件的备份也删除，但是这样不会影响软件的使用
apt-get autoclean
    定期运行这个命令来清除那些已卸载的软件包的.deb文档。通过这种方式，您能够释放大量的磁盘空间。假如您的需求十分迫切，能够使用apt-get clean以释放更多空间。这个命令会将已安装软件包裹
的.deb文档一并删除。大多数情况下您不会再用到这些.debs文档，因此假如您为磁盘空间不足而感到焦头烂额，这个办法也许值得一试
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

add-apt-repository ppa:webapps/preview
add-apt-repository --remove ppa:webapps/preview 单独地删除某个PPA仓库
apt-get install ppa-purge
ppa-purge ppa:webapps/preview 完整的删除一个PPA仓库并包括来自这个PPA安装或更新过的软件包
```

