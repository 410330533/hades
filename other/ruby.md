# ruby
```bash
apt-get install ruby
apt-get install rubygems
apt-get install ruby-rvm
apt-get install rails
gem install rails --include-dependencies
gem install capistrano capistrano-ext
```
ROR 环境配置, 参考 http://ruby-china.org/wiki/install_ruby_guide
```bash
0. 安装系统需要的包
sudo apt-get install -y build-essential openssl curl libcurl3-dev libreadline6 libreadline6-dev git zlib1g zlib1g-dev libssl-dev libyaml-dev libxml2-dev libxslt-dev autoconf automake libtool imagemagick libmagickwand-dev libpcre3-dev libsqlite3-dev libmysql-ruby libmysqlclient-dev

1. 安装 RVM
curl -L https://get.rvm.io | bash -s stable
载入 RVM 环境（新开 Termal 就不用这么做了，会自动重新载入的）
source ~/.rvm/scripts/rvm
rvm -v

2. 用 RVM 安装 Ruby 环境
替换 Ruby 下载地址到国内淘宝镜像服务器
for Mac
sed -i .bak 's!ftp.ruby-lang.org/pub/ruby!ruby.taobao.org/mirrors/ruby!' $rvm_path/config/db
for Linux
sed -i 's!ftp.ruby-lang.org/pub/ruby!ruby.taobao.org/mirrors/ruby!' $rvm_path/config/db
rvm autolibs enable
安装 Ruby 2.0.0
rvm install 2.0.0

3. 设置 Ruby 版本
rvm 2.0.0 --default
gem source -r https://rubygems.org/
gem source -a http://ruby.taobao.org
ruby -v
gem -v

4. 安装 Rails 环境
gem install bundler rails
bundle -v
rails -v
```

