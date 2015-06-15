# php
```shell
apt-get install php5

编译安装 php
apt-get install build-essential libxml2 libxml2-dev libcurl4-gnutls-dev libmcrypt-dev libicu-dev libreadline-dev openssl libssl-dev libmysqld-dev libmysqlclient-dev
./configure --prefix=/usr/local --with-pdo-mysql --with-mysql --with-mysqli --with-curl --with-mcrypt --with-gettext --with-readline --with-openssl --enable-intl --enable-fpm --enable-mbstring --enable-opcache --enable-sockets
make
make install
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

# install pcntl
```shell
http://php.net/manual/en/pcntl.installation.php
--enable-pcntl
```

# install soap
```shell
http://php.net/manual/en/soap.installation.php
--enable-soap
```

# install zip
```shell
http://php.net/manual/en/zip.installation.php
--enable-zip
```

# install zlib
```shell
http://php.net/manual/en/zlib.installation.php
--with-zlib[=DIR]
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

