# homebrew
install `ruby -e "$(curl -fsSL https://raw.github.com/mxcl/homebrew/go)"`

# command
```
显示Mac隐藏文件的命令：defaults write com.apple.finder AppleShowAllFiles YES
隐藏Mac隐藏文件的命令：defaults write com.apple.finder AppleShowAllFiles NO
```

# install macPorts
```shell
wget https://distfiles.macports.org/MacPorts/MacPorts-2.1.3.tar.bz2
tar xjvf MacPorts-2.1.3.tar.bz2
cd MacPorts-2.1.3
./configure && make && sudo make install

sudo port -v selfupdate
```
