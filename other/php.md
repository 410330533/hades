# php
```shell
sudo add-apt-repository ppa:ondrej/php5
sudo apt-get install ppa-purge
sudo ppa-purge ppa:ondrej/php5

apt-get install php5
apt-get install php-apc
apt-get install php-pear
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
sudo apt-get install build-essential libxml2 libxml2-dev libcurl4-gnutls-dev libjpeg-dev libpng-dev libxpm-dev libfreetype6-dev libmcrypt-dev libicu-dev libreadline-dev
./configure --prefix=/usr/local --enable-fpm --enable-mbstring --with-pdo-mysql --with-mysql --with-mysqli --with-pear --enable-soap --with-curl --with-mcrypt --with-gd --with-readline --enable-intl
make
sudo make install
```

# composer
```shell
curl -sS https://getcomposer.org/installer | php
curl -sS https://getcomposer.org/installer | php -- --install-dir=bin

php composer.phar install
php composer.phar update
php composer.phar update monolog/monolog [...]
```

# phpunit
```shell
sudo pear upgrade PEAR
sudo pear config-set auto_discover 1
sudo pear install pear.phpunit.de/PHPUnit

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

