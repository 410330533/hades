# composer
```shell
curl -sS https://getcomposer.org/installer | php
curl -sS https://getcomposer.org/installer | php -- --install-dir=bin

composer init
composer install
composer update
composer update --lock
composer update friendsofsymfony/user-bundle
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

# composer with proxy
```shell
export http_proxy=<your_http_proxy:proxy_port>
export https_proxy=<your_https_proxy:proxy_port>
export HTTP_PROXY_REQUEST_FULLURI=0
export HTTPS_PROXY_REQUEST_FULLURI=0
env | grep http -i

https://getcomposer.org/doc/03-cli.md#http-proxy-or-http-proxy
https://getcomposer.org/doc/03-cli.md#http-proxy-request-fulluri
```

# satis
```php
php composer.phar create-project composer/satis --stability=dev --keep-vcs
```

# link
- [Toran Proxy](https://toranproxy.com/)
