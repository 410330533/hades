# ror 环境配置
```shell
0. 安装系统需要的包
sudo apt-get install -y build-essential openssl libssl-dev curl libreadline6 libreadline6-dev git zlib1g zlib1g-dev libyaml-dev libxml2-dev libxslt-dev autoconf automake libtool imagemagick libmagickwand-dev libpcre3-dev libsqlite3-dev libmysqlclien-dev

1. 安装 RVM
gpg --keyserver hkp://keys.gnupg.net --recv-keys 409B6B1796C275462A1703113804BB82D39DC0E3
curl -sSL https://get.rvm.io | bash -s stable
rvm get stable

2. 用 RVM 安装 Ruby 环境
替换 Ruby 下载地址到国内淘宝镜像服务器
for Mac
sed -i .bak 's!cache.ruby-lang.org/pub/ruby!ruby.taobao.org/mirrors/ruby!' $rvm_path/config/db
for Linux
sed -i 's!cache.ruby-lang.org/pub/ruby!ruby.taobao.org/mirrors/ruby!' $rvm_path/config/db
rvm autolibs enable
rvm list
rvm list known
rvm install 2.1.4
rvm use 2.1.4 --default
rvm use system
rvm remove ruby-2.0.0-p247
rvm uninstall ruby-2.0.0-p247

3. 更换 gem 源
gem source -r https://rubygems.org/
gem source -a http://ruby.taobao.org

4. 安装 Rails 环境
gem install bundler rails

* proxy
export http_proxy="http://example.proxy_name.com:80"
rvm install X --proxy $domain_or_ip:$port
```
## link
- [如何快速正确的安装 Ruby, Rails 运行环境](https://ruby-china.org/wiki/install_ruby_guide)
- [rvm](http://rvm.io/)
- [How To Install Ruby on Rails on Ubuntu 14.04 using RVM](https://www.digitalocean.com/community/tutorials/how-to-install-ruby-on-rails-on-ubuntu-14-04-using-rvm)

# rack https://github.com/rack/rack
```shell
rackup config.ru
```

# unicorn http://unicorn.bogomips.org/
```shell
gem install unicorn
http://unicorn.bogomips.org/examples/unicorn.conf.rb
http://unicorn.bogomips.org/examples/unicorn.conf.minimal.rb
http://unicorn.bogomips.org/examples/nginx.conf
unicorn_rails -c config/unicorn.conf.rb -E production -D
```

# gem
```shell
gem list
gem install rails
gem install capistrano
gem install mongo
gem install mongo_ext
gem install ruby-mp3info
gem install mysql2 -v '0.3.15' -- --with-mysql-config=/opt/local/lib/mysql55/bin/mysql_config

gem fetch china_sms
gem unpack china_sms-0.0.6.gem
gem build halo.gemspec
gem install halo-0.0.1.gem
```

