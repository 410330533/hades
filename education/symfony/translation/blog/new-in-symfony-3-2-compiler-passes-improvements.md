http://symfony.com/blog/new-in-symfony-3-2-compiler-passes-improvements

# New in Symfony 3.2: Compiler passes improvements

Compiler passes are the mechanism provided by Symfony to manipulate the service definitions while the container is being compiled before the application execution. In Symfony 3.2 we introduced some new features for them.

Compiler passes priorities

The compilation of the container is a complex process that is executed in several steps, called "optimization passes" (e.g. resolving service references) and "removal passes" (e.g. deleting unused services).

When registering a compiler pass, you can select the step in which it's run thanks to the second optional argument of the addCompilerPass() method:

```php
// ...
$container->addCompilerPass(new CustomPass(), PassConfig::TYPE_AFTER_REMOVING);
```

However, you can't select the execution order of the compiler passes in each step, so they are executed in the same order as they are found by Symfony. In some cases this is not acceptable, so Symfony 3.2 allows you to set the priority of the compiler passes.

The priority is defined as the third optional argument of the addCompilerPass() method. The default priority is 0 and its value can be any positive or negative integer. The higher the priority, the earlier it's executed:

```php
// ...
$container->addCompilerPass(new CustomPass(), PassConfig::TYPE_AFTER_REMOVING, 30);
```

Find and sort tagged services

A common need for compiler passes is to find every service tagged with a given tag and then sort those services by priority. Symfony itself needs this feature in several parts of its codebase, so Symfony 3.2 added a trait to find and sort tagged services:

```php
// Before Symfony 3.2
class CustomPass implements CompilerPassInterface
{
    public function process(ContainerBuilder $container)
    {
        $warmers = array();
        foreach ($container->findTaggedServiceIds('kernel.cache_warmer') as $id => $attributes) {
            $priority = isset($attributes[0]['priority']) ? $attributes[0]['priority'] : 0;
            $warmers[$priority][] = new Reference($id);
        }

        krsort($warmers);
        $warmers = call_user_func_array('array_merge', $warmers);

        // ...
    }
}
```

```php
// In Symfony 3.2
use Symfony\Component\DependencyInjection\Compiler\PriorityTaggedServiceTrait;

class CustomPass implements CompilerPassInterface
{
    use PriorityTaggedServiceTrait;

    public function process(ContainerBuilder $container)
    {
        $warmers = $this->findAndSortTaggedServices('kernel.cache_warmer', $container);

        // ...
    }
}
```
