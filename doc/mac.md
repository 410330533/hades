# homebrew
install `ruby -e "$(curl -fsSL https://raw.github.com/mxcl/homebrew/go)"`

# command
```shell
显示Mac隐藏文件的命令：defaults write com.apple.finder AppleShowAllFiles YES
隐藏Mac隐藏文件的命令：defaults write com.apple.finder AppleShowAllFiles NO
```

# install macPorts
```shell
wget https://distfiles.macports.org/MacPorts/MacPorts-2.3.3.tar.bz2
tar -jxvf MacPorts-2.2.1.tar.bz2
cd MacPorts-2.2.1
./configure && make && sudo make install
port selfupdate
port upgrade outdated

vi ~/.profile
PATH=/opt/local/bin:/opt/local/sbin:$PATH
MANPATH=/opt/local/share/man:$MANPATH

port list
port search nginx
port install nginx
port uninstall mysql55 @5.5.33_1
port installed
port load nginx
port unload nginx
port select --set python python27
```

# launchctl
Launchd is Apple's open-source replacement for cron, xinetd, mach_init, and init. You manage launchd services with the launchctl utility.
```shell
launchctl load /Library/LaunchDaemons/org.macports.nginx.plist
launchctl unload /Library/LaunchDaemons/org.macports.nginx.plist
```

# limit
```shell
ulimit -n 10240
/etc/launchd.conf
$HOME/.launchd.conf
launchctl limit maxfiles
launchctl limit maxfiles 1024 65536
```

# link
- [简单制作 OS X Yosemite 10.10 正式版U盘USB启动安装盘方法教程 (全新安装 Mac 系统)](http://www.iplaysoft.com/osx-yosemite-usb-install-drive.html)
- [How to Make an OS X Yosemite Boot Installer USB Drive](http://osxdaily.com/2014/10/16/make-os-x-yosemite-boot-install-drive/)
- [简单4步，创建 OS X Yosemite or Mavericks USB 安装启动盘](http://ksmx.me/create-an-os-x-mavericks-usb-installer/)
- [苹果系统 Mac OS X Yosemite 正式版安装程序镜像下载 (10.10 新功能特性总结)](http://www.iplaysoft.com/osx-yosemite.html)
