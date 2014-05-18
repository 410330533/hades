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
sudo apt-get install build-essential libxml2 libxml2-dev libcurl4-gnutls-dev libjpeg-dev libpng-dev libxpm-dev libfreetype6-dev libmcrypt-dev libicu-dev libreadline-dev
./configure --prefix=/usr/local --enable-fpm --enable-mbstring --with-pdo-mysql --with-mysql --with-mysqli --with-pear --enable-soap --with-curl --with-mcrypt --with-gd --with-readline --enable-intl
make
sudo make install
```

# composer
```shell
curl -sS https://getcomposer.org/installer | php
curl -sS https://getcomposer.org/installer | php -- --install-dir=bin

composer init
composer install
composer update
composer update vendor/package vendor/package2
composer update vendor/*
composer require
composer require vendor/package:2.* vendor/package2:dev-master
composer global require fabpot/php-cs-fixer:dev-master
composer global update
composer search monolog
composer show
composer show monolog/monolog
composer show monolog/monolog 1.0.2
composer depends --link-type=require monolog/monolog
composer validate
composer status
composer self-update
composer self-update --rollback
composer config --list
composer config repositories.foo vcs http://github.com/foo/bar
composer create-project doctrine/orm path 2.2.*
composer diagnose
composer archive vendor/package 2.0.21 --format=zip
composer help install
```

# symfony
```shell
composer create-project symfony/framework-standard-edition symfony_test ~2.4
php app/check.php
php app/console server:run
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

