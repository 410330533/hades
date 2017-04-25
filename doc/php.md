# install common
```shell
apt-get install build-essential software-properties-common
```

# make install
```shell
apt-get install libxml2 libxml2-dev libcurl4-gnutls-dev libmcrypt-dev libicu-dev libreadline-dev openssl libssl-dev
./configure --prefix=/usr/local --with-pdo-mysql=mysqlnd --with-mysqli=mysqlnd --with-curl --with-mcrypt --with-gettext --with-readline --with-openssl --with-zlib --enable-intl --enable-fpm --enable-mbstring --enable-opcache --enable-sockets --enable-zip --enable-pcntl --enable-soap --enable-mysqlnd
make
make install
```

###### install inotify
```shell
sudo apt-get install php-pear
sudo apt-get install php7.0-dev
sudo pecl install inotify
add extension=inotify.so
```

# install bcmath
```shell
http://php.net/manual/en/bc.installation.php
--enable-bcmath
```

# install exif
```shell
http://php.net/manual/en/exif.installation.php
--enable-exif
```

# install gd
```shell
http://php.net/manual/en/image.installation.php
apt-get install libjpeg-dev libpng-dev libxpm-dev libfreetype6-dev
--with-gd[=DIR] --with-jpeg-dir --with-png-dir --with-freetype-dir
```

# install imap
```shell
http://php.net/manual/en/imap.installation.php
apt-get install libc-client2007e-dev
--with-imap --with-imap-ssl --with-kerberos
```

# config
```conf
1. opcache
zend_extension=opcache.so
opcache.enable=1
opcache.enable_cli=1

2. 使用新的编译器
GCC 4.8 +
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

# xhprof
```shell
wget http://pecl.php.net/get/xhprof-0.9.4.tgz
tar -zxvf xhprof-0.9.4.tgz
cd xhprof-0.9.4
cd extension/
phpize
./configure --with-php-config=/usr/local/php/bin/php-config
make
make install

apt-get install graphviz

http://php.net/manual/en/book.xhprof.php
```
