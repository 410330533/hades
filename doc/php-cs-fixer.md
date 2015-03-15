# install
```shell
wget http://get.sensiolabs.org/php-cs-fixer.phar -O php-cs-fixer
curl http://get.sensiolabs.org/php-cs-fixer.phar -o php-cs-fixer
sudo chmod a+x php-cs-fixer
sudo mv php-cs-fixer /usr/local/bin/php-cs-fixer
```

# update
```shell
sudo php-cs-fixer self-update
```

# usage
```shell
php php-cs-fixer.phar fix /path/to/dir
php php-cs-fixer.phar fix /path/to/file

php php-cs-fixer.phar fix /path/to/project --level=psr0
php php-cs-fixer.phar fix /path/to/project --level=psr1
php php-cs-fixer.phar fix /path/to/project --level=psr2
php php-cs-fixer.phar fix /path/to/project --level=symfony

php php-cs-fixer.phar fix /path/to/dir --fixers=linefeed,short_tag,indentation
php php-cs-fixer.phar fix /path/to/dir --fixers=-short_tag,-indentation
php php-cs-fixer.phar fix /path/to/dir --fixers=linefeed,-short_tag
```

# link
- [PHP Coding Standards Fixer](http://cs.sensiolabs.org/)
- [github FriendsOfPHP/PHP-CS-Fixer](https://github.com/FriendsOfPHP/PHP-CS-Fixer)
