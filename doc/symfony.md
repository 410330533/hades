# symfony install
```shell
curl -LsS http://symfony.com/installer -o /usr/local/bin/symfony
chmod a+x /usr/local/bin/symfony

composer create-project symfony/framework-standard-edition blog
php app/check.php
```

# symfony installer command
```php
symfony new my_project lts
symfony new my_project 2.3 # symfony branch
symfony new my_project 2.5.6 # specific symfony version
symfony self-update
```

# symfony command
```shell
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
php app/console doctrine:ensure-production-settings
php app/console doctrine:ensure-production-settings --em=default
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
php app/console doctrine:mapping:info
php app/console doctrine:mapping:info --em=default
php app/console doctrine:query:dql "SELECT u FROM UserBundle:User u"
php app/console doctrine:query:dql "SELECT u FROM UserBundle:User u" --hydrate=array
php app/console doctrine:query:dql "SELECT u FROM UserBundle:User u" --first-result=0 --max-result=30
php app/console doctrine:query:sql "SELECT * from user"
php app/console doctrine:schema:update --dump-sql
php app/console doctrine:schema:update --force
php app/console doctrine:schema:update --em=default
php app/console generate:bundle --namespace=Acme/BlogBundle
php app/console generate:controller
php app/console init:acl
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
php app/console server:start
php app/console server:status
php app/console server:stop
php app/console swiftmailer:spool:send --message-limit=10 --time-limit=10 --recover-timeout=900
php app/console twig:lint filename
php app/console twig:lint dirname
php app/console twig:lint @AcmeMyBundle
```

# symfony-doc
```shell
Sphinx http://sphinx-doc.org/latest/install.html
apt-get install python-sphinx

port install py27-sphinx
port select --set python python27
port select --set sphinx py27-sphinx

easy_install sphinx
pip install Sphinx

pip install git+https://github.com/fabpot/sphinx-php.git

git clone git@github.com:symfony/symfony-docs.git
make help
make clean
make dirhtml
```

# link
- [fabpot/sphinx-php](https://github.com/fabpot/sphinx-php)
