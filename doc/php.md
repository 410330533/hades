# php
```shell
apt-get install php5
apt-get install php5-cli
apt-get install php5-cgi
apt-get install php5-curl
apt-get install php5-dev
apt-get install php5-gd
apt-get install php5-fpm
apt-get install php5-memcache
apt-get install php5-mysql
apt-get install php5-xdebug

编译安装 php
sudo apt-get install build-essential libxml2 libxml2-dev libcurl4-gnutls-dev libjpeg-dev libpng-dev libxpm-dev libfreetype6-dev libmcrypt-dev libicu-dev libreadline-dev openssl libssl-dev libmysqld-dev libmysqlclient-dev
./configure --prefix=/usr/local --with-pdo-mysql --with-mysql --with-mysqli --with-pear --with-curl --with-mcrypt --with-gd --with-jpeg-dir --with-png-dir --with-freetype-dir --with-gettext --with-readline --with-openssl --enable-intl --enable-soap --enable-zip --enable-pcntl --enable-fpm --enable-mbstring --enable-opcache --enable-bcmath --enable-sockets --enable-exif
make
sudo make install
```

# install zlib
```shell
http://php.net/manual/en/zlib.installation.php
--with-zlib[=DIR]
```

# install imap
```shell
http://php.net/manual/en/imap.installation.php
apt-get install libc-client2007e-dev
--with-imap --with-imap-ssl --with-kerberos
```

# link
- [Alternative PHP Cache](http://php.net/manual/en/book.apc.php)
- [How To Install Linux, nginx, MySQL, PHP (LEMP) stack on Ubuntu 14.04](https://www.digitalocean.com/community/tutorials/how-to-install-linux-nginx-mysql-php-lemp-stack-on-ubuntu-14-04)
- [How to Install Laravel with an Nginx Web Server on Ubuntu 14.04](https://www.digitalocean.com/community/tutorials/how-to-install-laravel-with-an-nginx-web-server-on-ubuntu-14-04)

# phpunit
```shell
wget https://phar.phpunit.de/phpunit.phar
chmod +x phpunit.phar
mv phpunit.phar /usr/local/bin/phpunit
phpunit --version
```

# phpdoc
```shell
pear upgrade PhpDocumentor
phpdoc -d parsedir -t targetdir -o HTML:default:default
```

