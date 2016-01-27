# [Symfony 和 HTTP 基础](ttp://symfony.com/doc/current/book/http_fundamentals.html)
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

|METHOD|DESCRIPTION|
|---|---|
| GET    | 从服务器上获取资源 |
| POST   | 在服务器上创建资源 |
| PUT    | 更新服务器上的资源 |
| DELETE | 删除服务器上的资源 |

把这个记在脑子里，你能想象从服务器上删除一篇指定博客的请求应该长什么样子，比如：
```
DELETE /blog/15 HTTP/1.1
```
>实际上HTTP规范定义了9个HTTP方法（也称为动作），但是它们中的大部分并没有被广泛使用和支持。事实上，很多现代的浏览器在HTML表单中只支持POST和GET。其他动作在XMLHttpRequests中被支持，就像Symfony的路由一样。

除了第一行，一个HTTP请求总是包含一些其他行信息，他们叫做请求头。请求头提供了很多信息，比如请求的Host，客户端能接受（Accpet）的返回格式，发送请求的应用或客户端（User-Agent）。还有很多请求头，具体信息可以看维基百科的这篇文章[List of HTTP header fields](https://en.wikipedia.org/wiki/List_of_HTTP_header_fields)。
