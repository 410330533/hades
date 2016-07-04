http://symfony.com/blog/new-in-symfony-3-2-php-constants-in-yaml-files

# New in Symfony 3.2: PHP constants in YAML files

YAML is arguably the most popular format to define the configuration of the Symfony applications. Unfortunately, due to the YAML format nature, it doesn't provide feature parity with other formats such as XML. In particular, it's not possible to use PHP constants in YAML files, for example as service arguments.

In Symfony 3.2, we decided to augment the YAML format with a custom extension to support PHP constants. If some content in a YAML file is prefixed with the !php/const: string, it's now considered a PHP constant:

```yml
parameters:
    # this is considered a regular string
    foo: PHP_INT_MAX
    # this is considered a PHP constant
    bar: !php/const:PHP_INT_MAX
```

By default, the Symfony Yaml component only parses/generates standard- compliant YAML contents. Therefore, when using the stand-alone Yaml component, you must enable this feature explicitly with the Yaml::PARSE_CONSTANT flag:

```php
use Symfony\Component\Yaml\Yaml;

$yaml = <<<YAML
foo:
    !php/const:PHP_INT_MAX
YAML;

$config = Yaml::parse($yaml, Yaml::PARSE_CONSTANT);
// $config = array('foo' => PHP_INT_MAX);
```

If you use the Symfony framework, this option is enabled by default in the YamlFileLoader used by the DependencyInjection component. This means that you can use PHP constants in your YAML services out-of-the-box:

```yml
# app/config/services.yml
services:
    app.my_service:
        # ...
        arguments:
            - '@app.other_service'
            - !php/const:AppBundle\Entity\BlogPost::MUM_ITEMS
            - !php/const:Symfony\Component\HttpKernel\Kernel::VERSION
```
