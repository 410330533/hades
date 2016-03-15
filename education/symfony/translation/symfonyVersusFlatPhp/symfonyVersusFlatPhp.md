# Symfony versus Flat PHP
# Symfony VS 原始PHP

Why is Symfony better than just opening up a file and writing flat PHP?

为什么用Symfony比直接打开一个文件写原始PHP好？

If you've never used a PHP framework, aren't familiar with the MVC philosophy, or just wonder what all the hype is around Symfony, this chapter is for you. Instead of telling you that Symfony allows you to develop faster and better software than with flat PHP, you'll see for yourself.

如果你从来没使用过PHP框架，也不熟悉MVC哲学，或者惊奇为什么Symfony被大肆宣扬，那么这章就是为你准备的。你自己会发现，使用Symfony比原始PHP能更快更好的开发软件。

In this chapter, you'll write a simple application in flat PHP, and then refactor it to be more organized. You'll travel through time, seeing the decisions behind why web development has evolved over the past several years to where it is now.

在这章里，你将会用原始PHP写一个简单的应用，然后重构它，使得更有组织性。随着项目的进行，你将会看到web开发发展这么多年的过程及背后的决定，以及现在的样子。

By the end, you'll see how Symfony can rescue you from mundane tasks and let you take back control of your code.

最后，你将会看到Symfony如何将你从世俗的任务重解救出来，并让你重新夺回代码的控制。

# A Simple Blog in Flat PHP
# 用原始PHP写简单博客

In this chapter, you'll build the token blog application using only flat PHP. To begin, create a single page that displays blog entries that have been persisted to the database. Writing in flat PHP is quick and dirty:

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

That's quick to write, fast to execute, and, as your app grows, impossible to maintain. There are several problems that need to be addressed:

这段代码写起来非常快，执行起来也非常快，但是随着你应用规模的增长，将变的不可维护。这里有几个问题需要处理：

- No error-checking: What if the connection to the database fails?
- 没有错误检查 比如，连接到数据库失败？
- Poor organization: If the application grows, this single file will become increasingly unmaintainable. Where should you put code to handle a form submission? How can you validate data? Where should code go for sending emails?
- 很弱的组织性 如果应用规模增长，这个页面将变的不可维护。处理表单提交的代码放哪里？如何验证如何验证数据？发邮件的代码放哪里？
- Difficult to reuse code: Since everything is in one file, there's no way to reuse any part of the application for other "pages" of the blog.
- 代码很难重用 一旦所有东西都在一个页面里，你就无法在其他页面重用其中的任何一部分。

> Another problem not mentioned here is the fact that the database is tied to MySQL. Though not covered here, Symfony fully integrates Doctrine, a library dedicated to database abstraction and mapping.

> 另一个没有提到的问题是数据库和Mysql绑死了。虽然这里没讲到，Symfony将集成[Doctrine](http://www.doctrine-project.org/)，Doctrine是一个致力于数据库抽象和映射的库。

## Isolating the Presentation
## 独立表现层

The code can immediately gain from separating the application "logic" from the code that prepares the HTML "presentation":

我们能马上就把业务逻辑代码从HTML代码“表现层”中分离出来：

```php
// index.php
$link = new PDO("mysql:host=localhost;dbname=blog_db", 'myuser', 'mypassword');

$result = $link->query('SELECT id, title FROM post');

$posts = array();
while ($row = $result->fetch(PDO::FETCH_ASSOC)) {
    $posts[] = $row;
}

$link = null;

// include the HTML presentation code
require 'templates/list.php';
```

The HTML code is now stored in a separate file (templates/list.php), which is primarily an HTML file that uses a template-like PHP syntax:

HTML代码现在保存在一个单独的模板文件（templates/list.php）中，这个模板文件主要是一个HTML文件，其中参杂了一些PHP代码：

```html
<!DOCTYPE html>
<html>
    <head>
        <title>List of Posts</title>
    </head>
    <body>
        <h1>List of Posts</h1>
        <ul>
            <?php foreach ($posts as $post): ?>
            <li>
                <a href="/read?id=<?php echo $post['id'] ?>">
                    <?php echo $post['title'] ?>
                </a>
            </li>
            <?php endforeach ?>
        </ul>
    </body>
</html>
```

By convention, the file that contains all the application logic - index.php - is known as a "controller". The term controller is a word you'll hear a lot, regardless of the language or framework you use. It refers simply to the area of your code that processes user input and prepares the response.

按照惯例，我们会把包含所有应用业务逻辑的那个文件（index.php）叫做“控制器”。控制器这个术语你已经听到过很多遍了，不管是在其他语言还是框架里。它是指你代码里处理用户输入并准备输出的那一块。

In this case, the controller prepares data from the database and then includes a template to present that data. With the controller isolated, you could easily change just the template file if you needed to render the blog entries in some other format (e.g. list.json.php for JSON format).

在这个用例里，控制器从数据库里准备数据，然后加载一个模板并展现数据。当控制器独立后，如果你想用其他格式（举例 list.json.php JSON格式）渲染博客内容，你就可以很轻松的修改模板页就可以。

## Isolating the Application (Domain) Logic
## 独立应用逻辑

So far the application contains only one page. But what if a second page needed to use the same database connection, or even the same array of blog posts? Refactor the code so that the core behavior and data-access functions of the application are isolated in a new file called model.php:

到目前为止，这个应用还只有一个页面。

```php
// model.php
function open_database_connection()
{
    $link = new PDO("mysql:host=localhost;dbname=blog_db", 'myuser', 'mypassword');

    return $link;
}

function close_database_connection($link)
{
    $link = null;
}

function get_all_posts()
{
    $link = open_database_connection();

    $result = $link->query('SELECT id, title FROM post');

    $posts = array();
    while ($row = $result->fetch(PDO::FETCH_ASSOC)) {
        $posts[] = $row;
    }
    close_database_connection($link);

    return $posts;
}
```

> The filename model.php is used because the logic and data access of an application is traditionally known as the "model" layer. In a well-organized application, the majority of the code representing your "business logic" should live in the model (as opposed to living in a controller). And unlike in this example, only a portion (or none) of the model is actually concerned with accessing a database.

The controller (index.php) is now very simple:

```php
require_once 'model.php';

$posts = get_all_posts();

require 'templates/list.php';
```

Now, the sole task of the controller is to get data from the model layer of the application (the model) and to call a template to render that data. This is a very simple example of the model-view-controller pattern.

## Isolating the Layout
## 独立布局

At this point, the application has been refactored into three distinct pieces offering various advantages and the opportunity to reuse almost everything on different pages.

The only part of the code that can't be reused is the page layout. Fix that by creating a new layout.php file:

```html
<!-- templates/layout.php -->
<!DOCTYPE html>
<html>
    <head>
        <title><?php echo $title ?></title>
    </head>
    <body>
        <?php echo $content ?>
    </body>
</html>
```

The template (templates/list.php) can now be simplified to "extend" the layout:

```html
<?php $title = 'List of Posts' ?>

<?php ob_start() ?>
    <h1>List of Posts</h1>
    <ul>
        <?php foreach ($posts as $post): ?>
        <li>
            <a href="/read?id=<?php echo $post['id'] ?>">
                <?php echo $post['title'] ?>
            </a>
        </li>
        <?php endforeach ?>
    </ul>
<?php $content = ob_get_clean() ?>

<?php include 'layout.php' ?>
```

You now have a setup that will allow you to reuse the layout. Unfortunately, to accomplish this, you're forced to use a few ugly PHP functions (ob_start(), ob_get_clean()) in the template. Symfony uses a Templating component that allows this to be accomplished cleanly and easily. You'll see it in action shortly.

# Adding a Blog "show" Page
# 给博客添加一个“展示”页面

The blog "list" page has now been refactored so that the code is better-organized and reusable. To prove it, add a blog "show" page, which displays an individual blog post identified by an id query parameter.

To begin, create a new function in the model.php file that retrieves an individual blog result based on a given id:

```php
// model.php
function get_post_by_id($id)
{
    $link = open_database_connection();
    $id = intval($id);
    $result = $link->query('SELECT created_at, title, body FROM post WHERE id = '.$id);
    $row = $result->fetch(PDO::FETCH_ASSOC);

    close_database_connection($link);

    return $row;
}
```

Next, create a new file called show.php - the controller for this new page:

```php
require_once 'model.php';

$post = get_post_by_id($_GET['id']);

require 'templates/show.php';
```

Finally, create the new template file - templates/show.php - to render the individual blog post:

```html
<?php $title = $post['title'] ?>

<?php ob_start() ?>
    <h1><?php echo $post['title'] ?></h1>

    <div class="date"><?php echo $post['created_at'] ?></div>
    <div class="body">
        <?php echo $post['body'] ?>
    </div>
<?php $content = ob_get_clean() ?>

<?php include 'layout.php' ?>
```

Creating the second page is now very easy and no code is duplicated. Still, this page introduces even more lingering problems that a framework can solve for you. For example, a missing or invalid id query parameter will cause the page to crash. It would be better if this caused a 404 page to be rendered, but this can't really be done easily yet. Worse, had you forgotten to clean the id parameter via the intval() function, your entire database would be at risk for an SQL injection attack.

Another major problem is that each individual controller file must include the model.php file. What if each controller file suddenly needed to include an additional file or perform some other global task (e.g. enforce security)? As it stands now, that code would need to be added to every controller file. If you forget to include something in one file, hopefully it doesn't relate to security...

# A "Front Controller" to the Rescue
# 前端控制器的拯救

The solution is to use a front controller: a single PHP file through which all requests are processed. With a front controller, the URIs for the application change slightly, but start to become more flexible:

```
Without a front controller
/index.php          => Blog post list page (index.php executed)
/show.php           => Blog post show page (show.php executed)

With index.php as the front controller
/index.php          => Blog post list page (index.php executed)
/index.php/show     => Blog post show page (index.php executed)
```

> The index.php portion of the URI can be removed if using Apache rewrite rules (or equivalent). In that case, the resulting URI of the blog show page would be simply /show.

When using a front controller, a single PHP file (index.php in this case) renders every request. For the blog post show page, /index.php/show will actually execute the index.php file, which is now responsible for routing requests internally based on the full URI. As you'll see, a front controller is a very powerful tool.

## Creating the Front Controller
## 创建前端控制器

You're about to take a big step with the application. With one file handling all requests, you can centralize things such as security handling, configuration loading, and routing. In this application, index.php must now be smart enough to render the blog post list page or the blog post show page based on the requested URI:

```php
// index.php

// load and initialize any global libraries
require_once 'model.php';
require_once 'controllers.php';

// route the request internally
$uri = parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH);
if ('/index.php' === $uri) {
    list_action();
} elseif ('/index.php/show' === $uri && isset($_GET['id'])) {
    show_action($_GET['id']);
} else {
    header('Status: 404 Not Found');
    echo '<html><body><h1>Page Not Found</h1></body></html>';
}
```

For organization, both controllers (formerly index.php and show.php) are now PHP functions and each has been moved into a separate file, controllers.php:

```php
function list_action()
{
    $posts = get_all_posts();
    require 'templates/list.php';
}

function show_action($id)
{
    $post = get_post_by_id($id);
    require 'templates/show.php';
}
```

As a front controller, index.php has taken on an entirely new role, one that includes loading the core libraries and routing the application so that one of the two controllers (the list_action() and show_action() functions) is called. In reality, the front controller is beginning to look and act a lot like Symfony's mechanism for handling and routing requests.

> Another advantage of a front controller is flexible URLs. Notice that the URL to the blog post show page could be changed from /show to /read by changing code in only one location. Before, an entire file needed to be renamed. In Symfony, URLs are even more flexible.

By now, the application has evolved from a single PHP file into a structure that is organized and allows for code reuse. You should be happier, but far from satisfied. For example, the "routing" system is fickle, and wouldn't recognize that the list page (/index.php) should be accessible also via / (if Apache rewrite rules were added). Also, instead of developing the blog, a lot of time is being spent working on the "architecture" of the code (e.g. routing, calling controllers, templates, etc.). More time will need to be spent to handle form submissions, input validation, logging and security. Why should you have to reinvent solutions to all these routine problems?

## Add a Touch of Symfony
## 接触Symfony

Symfony to the rescue. Before actually using Symfony, you need to download it. This can be done by using Composer, which takes care of downloading the correct version and all its dependencies and provides an autoloader. An autoloader is a tool that makes it possible to start using PHP classes without explicitly including the file containing the class.

In your root directory, create a composer.json file with the following content:

```json
{
    "require": {
        "symfony/symfony": "3.0.*"
    },
    "autoload": {
        "files": ["model.php","controllers.php"]
    }
}
```

Next, download Composer and then run the following command, which will download Symfony into a vendor/ directory:

```shell
$ composer install
```

Beside downloading your dependencies, Composer generates a vendor/autoload.php file, which takes care of autoloading for all the files in the Symfony Framework as well as the files mentioned in the autoload section of your composer.json.

Core to Symfony's philosophy is the idea that an application's main job is to interpret each request and return a response. To this end, Symfony provides both a Request and a Response class. These classes are object-oriented representations of the raw HTTP request being processed and the HTTP response being returned. Use them to improve the blog:

```php
// index.php
require_once 'vendor/autoload.php';

use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;

$request = Request::createFromGlobals();

$uri = $request->getPathInfo();
if ('/' === $uri) {
    $response = list_action();
} elseif ('/show' === $uri && $request->query->has('id')) {
    $response = show_action($request->query->get('id'));
} else {
    $html = '<html><body><h1>Page Not Found</h1></body></html>';
    $response = new Response($html, Response::HTTP_NOT_FOUND);
}

// echo the headers and send the response
$response->send();
```

The controllers are now responsible for returning a Response object. To make this easier, you can add a new render_template() function, which, incidentally, acts quite a bit like the Symfony templating engine:

```php
// controllers.php
use Symfony\Component\HttpFoundation\Response;

function list_action()
{
    $posts = get_all_posts();
    $html = render_template('templates/list.php', array('posts' => $posts));

    return new Response($html);
}

function show_action($id)
{
    $post = get_post_by_id($id);
    $html = render_template('templates/show.php', array('post' => $post));

    return new Response($html);
}

// helper function to render templates
function render_template($path, array $args)
{
    extract($args);
    ob_start();
    require $path;
    $html = ob_get_clean();

    return $html;
}
```

By bringing in a small part of Symfony, the application is more flexible and reliable. The Request provides a dependable way to access information about the HTTP request. Specifically, the getPathInfo() method returns a cleaned URI (always returning /show and never /index.php/show). So, even if the user goes to /index.php/show, the application is intelligent enough to route the request through show_action().

The Response object gives flexibility when constructing the HTTP response, allowing HTTP headers and content to be added via an object-oriented interface. And while the responses in this application are simple, this flexibility will pay dividends as your application grows.

## The Sample Application in Symfony
## 用Symfony写样例应用

The blog has come a long way, but it still contains a lot of code for such a simple application. Along the way, you've made a simple routing system and a method using ob_start() and ob_get_clean() to render templates. If, for some reason, you needed to continue building this "framework" from scratch, you could at least use Symfony's standalone Routing and Templating components, which already solve these problems.

Instead of re-solving common problems, you can let Symfony take care of them for you. Here's the same sample application, now built in Symfony:

```php
// src/AppBundle/Controller/BlogController.php
namespace AppBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class BlogController extends Controller
{
    public function listAction()
    {
        $posts = $this->get('doctrine')
            ->getManager()
            ->createQuery('SELECT p FROM AppBundle:Post p')
            ->execute();

        return $this->render('Blog/list.html.php', array('posts' => $posts));
    }

    public function showAction($id)
    {
        $post = $this->get('doctrine')
            ->getManager()
            ->getRepository('AppBundle:Post')
            ->find($id);

        if (!$post) {
            // cause the 404 page not found to be displayed
            throw $this->createNotFoundException();
        }

        return $this->render('Blog/show.html.php', array('post' => $post));
    }
}
```

The two controllers are still lightweight. Each uses the Doctrine ORM library to retrieve objects from the database and the Templating component to render a template and return a Response object. The list template is now quite a bit simpler:

```html
<!-- app/Resources/views/Blog/list.html.php -->
<?php $view->extend('layout.html.php') ?>

<?php $view['slots']->set('title', 'List of Posts') ?>

<h1>List of Posts</h1>
<ul>
    <?php foreach ($posts as $post): ?>
    <li>
        <a href="<?php echo $view['router']->path(
            'blog_show',
            array('id' => $post->getId())
        ) ?>">
            <?php echo $post->getTitle() ?>
        </a>
    </li>
    <?php endforeach ?>
</ul>
```

The layout is nearly identical:

```html
<!-- app/Resources/views/layout.html.php -->
<!DOCTYPE html>
<html>
    <head>
        <title><?php echo $view['slots']->output(
            'title',
            'Default title'
        ) ?></title>
    </head>
    <body>
        <?php echo $view['slots']->output('_content') ?>
    </body>
</html>
```

> The show template is left as an exercise, as it should be trivial to create based on the list template.

When Symfony's engine (called the Kernel) boots up, it needs a map so that it knows which controllers to execute based on the request information. A routing configuration map provides this information in a readable format:

```yml
# app/config/routing.yml
blog_list:
    path:     /blog
    defaults: { _controller: AppBundle:Blog:list }

blog_show:
    path:     /blog/show/{id}
    defaults: { _controller: AppBundle:Blog:show }
```

Now that Symfony is handling all the mundane tasks, the front controller is dead simple. And since it does so little, you'll never have to touch it once it's created (and if you use a Symfony distribution, you won't even need to create it!):

```php
// web/app.php
require_once __DIR__.'/../app/bootstrap.php';
require_once __DIR__.'/../app/AppKernel.php';

use Symfony\Component\HttpFoundation\Request;

$kernel = new AppKernel('prod', false);
$kernel->handle(Request::createFromGlobals())->send();
```

The front controller's only job is to initialize Symfony's engine (Kernel) and pass it a Request object to handle. Symfony's core then uses the routing map to determine which controller to call. Just like before, the controller method is responsible for returning the final Response object. There's really not much else to it.

For a visual representation of how Symfony handles each request, see the request flow diagram.

## Where Symfony Delivers
## Symfony在哪里交付

In the upcoming chapters, you'll learn more about how each piece of Symfony works and the recommended organization of a project. For now, have a look at how migrating the blog from flat PHP to Symfony has improved life:

- Your application now has clear and consistently organized code (though Symfony doesn't force you into this). This promotes reusability and allows for new developers to be productive in your project more quickly;
- 100% of the code you write is for your application. You don't need to develop or maintain low-level utilities such as autoloading, routing, or rendering controllers;
- Symfony gives you access to open source tools such as Doctrine and the Templating, Security, Form, Validation and Translation components (to name a few);
- The application now enjoys fully-flexible URLs thanks to the Routing component;
- Symfony's HTTP-centric architecture gives you access to powerful tools such as HTTP caching powered by Symfony's internal HTTP cache or more powerful tools such as Varnish. This is covered in a later chapter all about caching.

And perhaps best of all, by using Symfony, you now have access to a whole set of high-quality open source tools developed by the Symfony community! A good selection of Symfony community tools can be found on KnpBundles.com.

# Better Templates
# 更好的模板

If you choose to use it, Symfony comes standard with a templating engine called Twig that makes templates faster to write and easier to read. It means that the sample application could contain even less code! Take, for example, the list template written in Twig:

```html
{# app/Resources/views/blog/list.html.twig #}
{% extends "layout.html.twig" %}

{% block title %}List of Posts{% endblock %}

{% block body %}
    <h1>List of Posts</h1>
    <ul>
        {% for post in posts %}
        <li>
            <a href="{{ path('blog_show', {'id': post.id}) }}">
                {{ post.title }}
            </a>
        </li>
        {% endfor %}
    </ul>
{% endblock %}
```

The corresponding layout.html.twig template is also easier to write:

```html
{# app/Resources/views/layout.html.twig #}
<!DOCTYPE html>
<html>
    <head>
        <title>{% block title %}Default title{% endblock %}</title>
    </head>
    <body>
        {% block body %}{% endblock %}
    </body>
</html>
```

Twig is well-supported in Symfony. And while PHP templates will always be supported in Symfony, the many advantages of Twig will continue to be discussed. For more information, see the templating chapter.

# Learn more from the Cookbook
# 从手册中学习更多

- How to Use PHP instead of Twig for Templates
- How to Define Controllers as Services
