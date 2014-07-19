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
sudo apt-get install build-essential libxml2 libxml2-dev libcurl4-gnutls-dev libjpeg-dev libpng-dev libxpm-dev libfreetype6-dev libmcrypt-dev libicu-dev libreadline-dev openssl libssl-dev
./configure --prefix=/usr/local --enable-fpm --enable-mbstring --with-pdo-mysql --with-mysql --with-mysqli --with-pear --enable-soap --with-curl --with-mcrypt --with-gd --with-readline --enable-intl --with-openssl
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
composer update --lock
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
composer dump-autoload --optimize
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

php app/console --shell
php app/console assetic:dump
php app/console assetic:dump --watch
php app/console assets:install web
php app/console assets:install web --symlink
php app/console assets:install web --symlink --relative
php app/console cache:clear
php app/console config:dump-reference FrameworkBundle
php app/console container:debug
php app/console doctrine:database:create
php app/console doctrine:database:drop
php app/console doctrine:generate:entities MyCustomBundle
php app/console doctrine:generate:entities MyCustomBundle:User
php app/console doctrine:generate:entities MyCustomBundle/Entity/User
php app/console doctrine:generate:entities MyCustomBundle/Entity
php app/console doctrine:generate:entity --entity=AcmeBlogBundle:Blog/Post
php app/console doctrine:generate:entity --entity=AcmeBlogBundle:Blog/Post --fields="title:string(255) body:text"
php app/console doctrine:generate:entity --entity=AcmeBlogBundle:Blog/Post --with-repository
php app/console doctrine:generate:entity --entity=AcmeBlogBundle:Blog/Post --format=yml
php app/console doctrine:generate:entity --entity=AcmeBlogBundle:Blog/Post --format=annotation --fields="title:string(255) body:text" --with-repository --no-interaction
php app/console doctrine:mapping:convert xml /path/to/output
php app/console doctrine:mapping:import "MyCustomBundle" xml
php app/console doctrine:mapping:import "MyCustomBundle" xml --em=default
php app/console doctrine:mapping:import "MyCustomBundle" xml --filter=MyMatchedEntity
php app/console doctrine:mapping:import "MyCustomBundle" xml --force
php app/console doctrine:schema:update --dump-sql
php app/console doctrine:schema:update --force
php app/console doctrine:schema:update --em=default
php app/console generate:bundle --namespace=Acme/BlogBundle
php app/console generate:controller
php app/console propel:database:create
php app/console propel:model:build
php app/console propel:sql:build
php app/console propel:sql:insert --force
php app/console propel:build --insert-sql
php app/console propel:migration:generate-diff
php app/console propel:migration:migrate
php app/console propel:model:build
php app/console route:debug
php app/console route:debug _demo
php app/console router:dump-apache
php app/console route:match /demo/
php app/console server:run
php app/console server:run 127.0.0.1:8080
php app/console server:run --docroot=htdocs/
php app/console twig:lint filename
php app/console twig:lint dirname
php app/console twig:lint @AcmeMyBundle
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

