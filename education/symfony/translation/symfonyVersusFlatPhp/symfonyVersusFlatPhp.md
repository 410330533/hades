# [Symfony VS 原始PHP](http://symfony.com/doc/current/book/from_flat_php_to_symfony2.html)

为什么用Symfony比直接打开一个文件写原始PHP好？

如果你从来没使用过PHP框架，也不熟悉MVC哲学，或者惊奇为什么Symfony被大肆宣扬，那么这章就是为你准备的。你自己会发现，使用Symfony比原始PHP能更快更好的开发软件。

在这章里，你将会用原始PHP写一个简单的应用，然后重构它，使得更有组织性。随着项目的进行，你将会看到web开发发展这么多年的过程及背后的决定，以及现在的样子。

最后，你将会看到Symfony如何将你从世俗的任务重解救出来，并让你重新夺回代码的控制。

# 用原始PHP写简单博客
在这一章，你将会只用原始PHP来写一个博客应用。一开始，创建一个页面来显示博客内容，这些内容已经在数据库中。用原始PHP写非常快，但是很脏。
```html
<?php
// index.php
$link = new PDO("mysql:host=localhost;dbname=blog_db", 'myuser', 'mypassword');

$result = $link->query('SELECT id, title FROM post');
?>

<!DOCTYPE html>
<html>
    <head>
        <title>List of Posts</title>
    </head>
    <body>
        <h1>List of Posts</h1>
        <ul>
            <?php while ($row = $result->fetch(PDO::FETCH_ASSOC)): ?>
            <li>
                <a href="/show.php?id=<?php echo $row['id'] ?>">
                    <?php echo $row['title'] ?>
                </a>
            </li>
            <?php endwhile ?>
        </ul>
    </body>
</html>

<?php
$link = null;
?>
```
这段代码写起来非常快，执行起来也非常快，但是随着你应用规模的增长，将变的不可维护。这里有几个问题需要处理：
- 没有错误检查 比如，连接到数据库失败？
- 很弱的组织性 如果应用规模增长，这个页面将变的不可维护。处理表单提交的代码放哪里？如何验证如何验证数据？发邮件的代码放哪里？
- 代码很难重用 一旦所有东西都在一个页面里，你就无法在其他页面重用其中的任何一部分。

> 另一个没有提到的问题是数据库和Mysql绑死了。虽然这里没讲到，Symfony将集成[Doctrine](http://www.doctrine-project.org/)，Doctrine是一个致力于数据库抽象和映射的库。

## 独立表现层

## 独立应用逻辑

## 独立布局

# 给博客添加一个“展示”页面

# 前端控制器的拯救

## 创建前端控制器

## 接触Symfony

## 用Symfony写样例应用

## Symfony在哪里交付

# 更好的模板

# 从手册中学习更多
