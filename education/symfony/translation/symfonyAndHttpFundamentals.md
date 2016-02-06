# [Symfony 和 HTTP 基础](http://symfony.com/doc/current/book/http_fundamentals.html)
恭喜！通过学习Symfony，你将变成一个更有生产力，技术更全面和更受欢迎的web开发者（当然，是否更受欢迎，要看你自己了）。创建Symfony是为了解决最根本的问题：即开发一个工具，使得你能更快的开发并创建更可靠的应用，同时，远离你自己的那一套（译注：这里指Symfony有一套好的最佳实践，你跟它做就可以了，避免你自己的那一套东西）。Symfony是站在了很多技术巨人的肩膀上，吸取了很多他们的最佳想法：你将要学习的这套工具和概念代表了成千上万的人通过多年努力的结晶。换句话说，你并不只是在学习“Symfony”，你是在学习web的基础，开发的最佳实践和如何使用很多很赞的新的PHP类库，不管是在Symfony中，还是独立于Symfony。因此，请做好准备。

# HTTP是很简单的
HTTP（对于极客来说是超文本传输协议）是一门用来在两个机器之间彼此通信的文本语言。就是这样！举个例子，当你在 [xkcd](http://xkcd.com/) 网站上查看最近的漫画时，下面的会话（近似的）就发生了：

![http-xkcd.png](http-xkcd.png)

虽然实际使用的语言会更正式一点，但是还是很简单。HTTP就是一种用来描述这样简单的，基于文本的语言的术语。不管你怎么开发网站，你的服务器的目的始终都是理解简单文本请求，并返回简单文本响应。

Symfony就是基于这样的现实被创造出来的。不管你是否意识到，HTTP就是你每天都在使用的东西。和Symfony一起，你将学习如何精通它。

## 步骤一：客户端发送一个请求
网络上的每个会话都会从一个请求开始。这个请求，就是一个客户端（举例 浏览器，智能手机应用等）创建的特殊格式的文本消息，就是HTTP。客户端发送请求到服务器，然后就等待响应。

我们来看看一个浏览器和xkcd网站服务器之间交互的第一部分（请求）：

![http-xkcd-request.png](http-xkcd-request.png)

按照HTTP协议，这个HTTP请求实际上像下面这样：
```
GET / HTTP/1.1
Host: xkcd.com
Accept: text/html
User-Agent: Mozilla/5.0 (Macintosh)
```
这个简单的文本准确地描述了关于请求资源的所有信息。HTTP请求的第一行是最重要的，并且包含了两件事：URI和HTTP方法。

URI（举例 /，/contact等）标识了这个客户端想要资源的唯一地址。HTTP方法（举例 GET）定义了你想对资源做什么。HTTP方法是请求的动作，并定义了一些操作资源的公共方法。

| METHOD | DESCRIPTION |
| ---    | ---         |
| GET    | 从服务器上获取资源   |
| POST   | 在服务器上创建资源   |
| PUT    | 更新服务器上的资源   |
| DELETE | 删除服务器上的资源   |

把这个记在脑子里，你能想象从服务器上删除一篇指定博客的请求应该长什么样子，比如：
```
DELETE /blog/15 HTTP/1.1
```
>实际上HTTP规范定义了9个HTTP方法（也称为动作），但是它们中的大部分并没有被广泛使用和支持。事实上，很多现代的浏览器在HTML表单中只支持POST和GET。其他动作在XMLHttpRequests中被支持，就像Symfony的路由一样。

除了第一行，一个HTTP请求总是包含一些其他行信息，他们叫做请求头。请求头提供了很多信息，比如请求的Host，客户端能接受（Accpet）的返回格式，发送请求的应用或客户端（User-Agent）。还有很多请求头，具体信息可以看维基百科的这篇文章[List of HTTP header fields](https://en.wikipedia.org/wiki/List_of_HTTP_header_fields)。

## 步骤二：服务器返回一个响应
一旦服务器接收到了请求，它就能清楚的知道客户端要的是什么资源（通过URI），以及客户端想要对资源做的什么操作（通过method）。举个例子，一个GET请求，服务器准备好资源并在HTTP响应中返回。考虑从xkcd服务器返回请求：

![http-xkcd.png](http-xkcd.png)

翻译成HTTP，发回给浏览器的响应看起来像这样：
```
HTTP/1.1 200 OK
Date: Sat, 02 Apr 2011 21:05:05 GMT
Server: lighttpd/1.4.19
Content-Type: text/html

<html>
  <!-- ... HTML for the xkcd comic -->
</html>
```
HTTP响应包含了请求的资源（在这个例子中就是HTML），同时也包含了这个响应的其他信息。第一行特别重要，并且包含了HTTP响应状态码（这个例子中是200）。状态码报告了响应的状态，如，请求成功了吗？有报错吗？不同的状态码表示成功，错误，或者客户端需要做些什么事（比如，重定向到另一个页面）。你能在这里[List of HTTP status codes](https://en.wikipedia.org/wiki/List_of_HTTP_status_codes)找到状态码的完整列表。

就像请求一样，HTTP响应中也包含一些HTTP头。举例，一个重要的HTTP响应头是Content-Type。同一资源的主体，也能被以多种格式返回，比如HTML，XML，JSON，响应头Content-Type使用text/html来告诉客户端到底使用了哪种格式返回。从这里[list of common media types](https://www.iana.org/assignments/media-types/media-types.xhtml)你能得到一个完整的媒介类型列表。

还有很多HTTP头，其中的一些非常强大。举例，某些请求头可以用来创建一个非常强大的缓存系统。

## 请求，响应和web开发
这个 请求-响应 会话模式是网络上所有通信的基础。它很强大，也很重要，但又很简单。

最重要的事实是：不管你用什么语言，创造什么类型的应用（web，手机，JSON API）或者遵循什么开发哲学，一个应用的最终目标始终都是理解每个请求，并创建和返回适当的响应。

Symfony就是基于这样的现实被架构的。

>想用学习更多HTTP规范，可以参考[HTTP 1.1 RFC](http://www.w3.org/Protocols/rfc2616/rfc2616.html)或[HTTP Bis](https://datatracker.ietf.org/wg/httpbis/documents/)（用更直白的方式来说明HTTP规范）。Firefox中有一个扩展[Live HTTP Headers](https://addons.mozilla.org/en-US/firefox/addon/live-http-headers/)，它能很好的用于查看请求头和响应头。

# PHP中的请求和响应
在PHP中，你如何跟请求交互，并创建响应呢？事实上，PHP帮你把整个流程做了一点抽象：
```php
$uri = $_SERVER['REQUEST_URI'];
$foo = $_GET['foo'];

header('Content-Type: text/html');
echo 'The URI requested is: '.$uri;
echo 'The value of the "foo" parameter is: '.$foo;
```
就像听起来那么奇怪，这个小应用事实上已经从HTTP请求上获取信息，并用来创造了一个HTTP响应。为了避免解析原始的HTTP请求消息，PHP帮你准备了一些超级全局变量，比如$_SERVER和$_GET，这些变量包含了请求的全部信息。同样的，为了避免返回HTTP格式的消息，你可以使用header函数来创造响应头并能轻松地打印出响应的实际内容。PHP会创造一个真的HTTP响应并把它返回给客户端。
```
HTTP/1.1 200 OK
Date: Sat, 03 Apr 2011 02:14:33 GMT
Server: Apache/2.2.17 (Unix)
Content-Type: text/html

The URI requested is: /testing?foo=symfony
The value of the "foo" parameter is: symfony
```

# Symfony中的请求和响应
Symfony相对于原始的PHP来说，它提供了2个类，来让你更轻松地与请求和响应交互。Request类就是HTTP消息用面向对象的形式展现。有了它，你就能随意的获取请求信息：
```php
use Symfony\Component\HttpFoundation\Request;

$request = Request::createFromGlobals();

// the URI being requested (e.g. /about) minus any query parameters
$request->getPathInfo();

// retrieve GET and POST variables respectively
$request->query->get('foo');
$request->request->get('bar', 'default value if bar does not exist');

// retrieve SERVER variables
$request->server->get('HTTP_HOST');

// retrieves an instance of UploadedFile identified by foo
$request->files->get('foo');

// retrieve a COOKIE value
$request->cookies->get('PHPSESSID');

// retrieve an HTTP request header, with normalized, lowercase keys
$request->headers->get('host');
$request->headers->get('content_type');

$request->getMethod();    // GET, POST, PUT, DELETE, HEAD
$request->getLanguages(); // an array of languages the client accepts
```
Request类还在后台默默的做了很多事，使得你不用为此操心。举例，isSecure方法通过检查3个不同值来判断用户是否使用了一个安全连接（例如 HTTPS）。

>参数包和请求属性

>就像你看到的，$_GET和$_POST变量可以通过公开属性query和request来访问。这些对象都是[ParameterBag](http://api.symfony.com/3.0/Symfony/Component/HttpFoundation/ParameterBag.html)对象，它们都有一些方法，比如get(),has(),all()等。事实上，上面例子中每个使用过的公开属性，都是ParameterBag类的实例

>Request类也有一个公开的attributes属性，这个属性有一些数据，这些数据跟应用内部如何工作相关。对于Symfony框架来说，attributes包含一些路由匹配的返回值，比如_controller,id(如果你有一个id通配符)，甚至是匹配的路由的名字(_route)。attributes就是一个存储请求指定上下文信息的一个地方。

Symfony还提供Response类，一个HTTP响应消息的PHP形式的展现。它允许你的应用通过面向对象接口的方式构造这个响应并返回给客户端：
```php
use Symfony\Component\HttpFoundation\Response;

$response = new Response();

$response->setContent('<html><body><h1>Hello world!</h1></body></html>');
$response->setStatusCode(Response::HTTP_OK);
$response->headers->set('Content-Type', 'text/html');

// prints the HTTP headers followed by the content
$response->send();
```
如果Symfony不提供其他任何东西，你也已经有了一个能轻松获取请求信息，并以面向对象的方式创建响应的工具箱。就像你看到的Symfony那么多强大的特性，你要记住，你应用的目标永远都是解析请求并基于你的应用逻辑创建合适的响应。

>Request和Response类在Symfony中是独立的组件，叫做HttpFoundation。这个组件能被完全独立于Symfony使用，并能提供处理会话和文件上传功能的类。

# 从请求到响应的旅程
就像HTTP一样，Request和Response对象也非常简单。创建一个应用的难点在于在他们之间写点什么。换句话说，就是解析一个请求的信息并创建响应。

你的应用可能做很多事，像发邮件，处理表单提交，保存东西到数据库，渲染HTML页面和保护内容的安全性。你如何管理所有这些东西，并且保持你的代码有组织且可维护？

Symfony就是用来解决这些问题的，所以你无需为此烦恼。

## 前端控制器
传统的，站点的每个页面都是一个物理页：
```
index.php
contact.php
blog.php
```
这种方法有不少问题，比如URL的可扩展性（假如你想将blog.php修改为news.php但不破坏你所有的连接？）和每页必须手动包含一些核心文件使得安全，数据库连接，页面的一致性。

一个更好的解决方案是使用前端控制器：一个简单的PHP文件，它会处理每个到你这个应用的请求。比如：

| URL                | ACTION             |
| ---                | ---                |
| /index.php         | executes index.php |
| /index.php/contact | executes index.php |
| /index.php/blog    | executes index.php |

>使用Apache的mod_rewrite（或者其他服务器的类似功能），URL能轻松的改写成简洁的形式，比如/，/contact和/blog。

现在，所有请求都被相同的方式处理。和之前每个文件执行不同的文件不同，现在前端控制器始终都会执行，而且不同的URL路由到应用的不同部分这个过程也在内部完成。这解决了前面提到的两个问题。几乎所有的现代web应用都这样做，比如WordPress。

## 保持代码的组织性
在前端控制器里，你必须要分清楚什么代码应该被执行，什么内容需要返回。为了弄清楚这个，你需要检查URI并根据它的值来执行代码的不同部分。这样，你的代码马上会变的比较难看：
```php
// index.php
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;

$request = Request::createFromGlobals();
$path = $request->getPathInfo(); // the URI path being requested

if (in_array($path, array('', '/'))) {
    $response = new Response('Welcome to the homepage.');
} elseif ('/contact' === $path) {
    $response = new Response('Contact us');
} else {
    $response = new Response('Page not found.', Response::HTTP_NOT_FOUND);
}
$response->send();
```
解决这个问题比较困难。幸运的是，这正是Symfony被设计来解决的问题。

## Symfony应用流
当你用Symfony来处理每个请求时，生活变得更加美好了。Symfony用同样的模式处理每个请求。

![request-flow.png](request-flow.png)

请求被路由解析，并传到控制器函数，然后返回Response对象。

路由配置文件中会定义好映射，不同的url映射到不同的PHP函数。上面说的PHP函数，叫控制器。他们的职责，是和其他工具一起，利用请求的信息，来返回一个Response对象。换句话说，控制器是你代码的入口：就是你解析请求并创建响应。

很简单！我们回顾下：
- 每个请求都会执行前端控制器
- 路由系统根据请求信息和你创建的路由配置决定执行哪个PHP函数
- PHP函数被执行，然后创建并返回合适的Response对象

## Symfony处理请求实战
先不深入细节，我们先来看一个实例。假设你想添加一个/contact页面到你的Symfony应用。首先，在你的路由配置文件中为/contact添加一个入口：
```yaml
# app/config/routing.yml
contact:
    path:     /contact
    defaults: { _controller: AppBundle:Main:contact }
```
当有人访问/contact页面时，这个路由就被匹配到了，指定的控制器就被执行。就像你将在[路由](http://symfony.com/doc/current/book/routing.html)学到的，AppBundle:Main:contact是一个字符串简写，它指向了MainController中的contactAction函数：
```php
// src/AppBundle/Controller/MainController.php
namespace AppBundle\Controller;

use Symfony\Component\HttpFoundation\Response;

class MainController
{
    public function contactAction()
    {
        return new Response('<h1>Contact us!</h1>');
    }
}
```
在这个非常简单的例子里，控制器非常简单的创建了一个包含HTML内容`<h1>Contact us!</h1>`的Response对象。在[控制器章节](http://symfony.com/doc/current/book/controller.html)，你将会学到控制器如何渲染页面，将你的“表现层”代码（举例，那些写到HTML的代码）放在一个单独的模板文件中。这就解放了控制器，使得它只需要关注最重要的部分：与数据库的交互，处理提交数据，或发送邮件消息。

# Symfony：创建你的应用，而不是你的工具
你现在应该知道，所有app的目的，都是解析请求并创建合适的响应。随着应用规模的增长，保持你代码的组织性和可维护性变的越来越困难。有些复杂的事情是你不得不反复做的：保存数据到数据库，渲染和重用模板，处理表单提交，发邮件，校验用户输入，处理安全问题。

好消息是上面这些问题没有一个是独一无二的。Symfony提供了一整套的框架工具来帮你创建你的应用，而不是你的工具。Symfony不会强加给你任何东西，你可以选择使用全栈Symfony框架，或者只使用其中的一部分。

## 独立的工具：Symfony组件
Symfony是什么？首先，Symfony是超过二十多个独立的库，这些组件可以被用在其他任何PHP项目中。这些库，叫做Symfony组件，这些组件包含一些在任何情况下都有用的东西，不管你以什么样的形式开发你的应用。我们来看一些：
- HttpFoundation 包含Request和Response类，也包含一些其他用于处理会话和文件上传的类。
- Routing 强大快速的路由系统允许你映射一个指定的URI（比如 /contact）将被如何处理（比如 执行contactAction方法）
- Form 一个用来创建表单，处理表单提交，功能齐全且可扩展的框架。
- Validator 创建规则，然后验证用户提交的数据是否符合这些规则的系统。
- Templating 渲染模板，处理模板继承（举例 模板被布局装饰）和处理其他一些公共的模板任务的工具箱。
- Security 一个处理应用内各种安全问题的强大类库
- Translation 在你应用内翻译字符串的框架
上面的这些框架都是解耦的，能被用于任何PHP项目，不管你是否使用Symfony框架。他们每一个都可以在需要时被使用，也可以在必要时被替换。

## 完整解决方案：Symfony框架
那么，什么是Symfony框架呢？Symfony框架就是一个PHP类库，它完成两个不同的任务：
- 提供一些可选组件（比如 Symfony组件）和第三方库（比如 Swift Mailer用来发邮件）。
- 提供合理的配置和一个“胶水”库将所有这些连起来。
这个框架的目的是集成很多独立的工具，给开发者提供一致的体验。即使这个框架它自己也是一个Symfony bundle（比如 一个插件）且可被整个配置和替换。

Symfony提供了一套强大的工具集来实现快速开发web应用，同时不强加给你任何东西。普通用户通过一个Symfony发行版可以快速上手，它提供了一个项目的骨架和合理的配置。对于更多高级用户，只有想不到，没有做不到。
