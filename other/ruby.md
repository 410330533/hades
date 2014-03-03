# ROR 环境配置, 参考 http://ruby-china.org/wiki/install_ruby_guide
```shell
0. 安装系统需要的包
sudo apt-get install -y build-essential openssl curl libcurl3-dev libreadline6 libreadline6-dev git zlib1g zlib1g-dev libssl-dev libyaml-dev libxml2-dev libxslt-dev autoconf automake libtool imagemagick libmagickwand-dev libpcre3-dev libsqlite3-dev libmysql-ruby libmysqlclient-dev

1. 安装 RVM
curl -sSL https://get.rvm.io | bash -s stable
载入 RVM 环境（新开 Termal 就不用这么做了，会自动重新载入的）
source ~/.rvm/scripts/rvm
rvm -v
rvm get stable

2. 用 RVM 安装 Ruby 环境
替换 Ruby 下载地址到国内淘宝镜像服务器
for Mac
sed -i .bak 's!ftp.ruby-lang.org/pub/ruby!ruby.taobao.org/mirrors/ruby!' $rvm_path/config/db
for Linux
sed -i 's!ftp.ruby-lang.org/pub/ruby!ruby.taobao.org/mirrors/ruby!' $rvm_path/config/db
rvm autolibs enable
rvm install 2.1.1
rvm 2.1.1 --default
ruby -v
# Removes the ruby, source files and optional gemsets / archives
rvm remove ruby-2.0.0-p247
# Just removes the ruby - leaves everything else
rvm uninstall ruby-2.0.0-p247

3. 更换 gem 源
gem source -r https://rubygems.org/
gem source -a http://ruby.taobao.org
gem -v

4. 安装 Rails 环境
gem install bundler rails
bundle -v
rails -v
```

# unicorn http://unicorn.bogomips.org/
```shell
gem install unicorn
http://unicorn.bogomips.org/examples/unicorn.conf.rb
http://unicorn.bogomips.org/examples/unicorn.conf.minimal.rb
http://unicorn.bogomips.org/examples/nginx.conf
unicorn_rails -c config/unicorn.conf.rb -E production -D
```

# gems
```shell
gem install rails --include-dependencies
gem install capistrano capistrano-ext
gem install ruby-mp3info
```

