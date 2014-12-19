今天谈一个编码规范的问题，由此引发了一个bug。该bug的fix，在commit 1ef50d980d41765c4fbb55a152327f7dc02aef7b，大家可以看下。

我们平常写代码，判断字符串相等，是怎么写的呢？
```php
if ($username == 'Jack')
```
是像这样写的吗？如果是的话，会不会有问题？如果你少写一个`=`，如下
```php
if ($username = 'Jack')
```
脚本解析器完全不会报错，无任何语法错误，会继续执行。这样写代码什么意思呢？代表把`'Jack'`赋值给`$username`变量，然后判断`$username`变量是否为空。这里，因为`$username`已经赋值为`'Jack'`，所以永远不可能为空，所以相当于if判断永远成立。这样的写法，即使在C中，也是不会编译报错的。那这样的问题，怎么办呢？参考下面的写法：
```php
if ('Jack' == $username)
```
把常量写在前面，仍旧可以达到判断是否相等的目的。并且，假如你少写了一个等号，执行会报错，因为不能改变常量值。

# link
- [php-fig](http://www.php-fig.org/)
- [php the right way](http://www.phptherightway.com/)
