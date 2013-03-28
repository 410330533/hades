# php coding style
## PHP File 文件格式

### 常规
对于只包含有 PHP 代码的文件，结束标志（"?>"）是不允许存在的，PHP自身不需要（"?>"）, 这样做, 可以防止它的末尾的被意外地注入响应。

### 缩进
缩进由四个空格组成，禁止使用制表符 TAB 。

### 行的最大长度
一行 80 字符以内是比较合适，就是说，ZF 的开发者应当努力在可能的情况下保持每行代码少于 80 个字符，在有些情况下，长点也可以, 但最多为 120 个字符。

### 行结束标志
行结束标志遵循 Unix 文本文件的约定，行必需以单个换行符（LF）结束。换行符在文件中表示为 10，或16进制的 0x0A。

## 命名约定
### 类
类名只允许有字母数字字符，在大部分情况下不鼓励使用数字。类名采用驼峰命名法。

### 文件名
对于其它文件，只有字母数字字符、下划线和短横线（"-"）可用，空格是绝对不允许的。
包含任何 PHP 代码的任何文件应当以 ".php" 扩展名结尾，众所周知的视图脚本除外。

### 函数和方法
函数名只包含字母数字字符，下划线是不允许的。数字是允许的但大多数情况下不鼓励。
函数名总是以小写开头，当函数名包含多个单词，每个子的首字母必须大写，这就是所谓的 “驼峰” 格式。
我们一般鼓励使用冗长的名字，函数名应当长到足以说明函数的意图和行为。
函数名尽量采用多个字母带下划线的格式。比如：
```php
query_by_id();
filter_input();
get_element_by_id();
```

### 变量
变量只包含数字字母字符，大多数情况下不鼓励使用数字，下划线不接受。
声明为 "private" 或 "protected" 的实例变量名必须以一个单个下划线开头，这是唯一的下划线在程序中的用法，声明为 "public" 的不应当以下划线开头。
对函数名（见上面 3.3 节）一样，变量名总以小写字母开头并遵循“驼峰式”命名约定。
我们一般鼓励使用冗长的名字，这样容易理解代码。除非在小循环里，不鼓励使用简洁的名字如 "$i" 和 "$n"。

### 常量
常量包含数字字母字符和下划线，数字允许作为常量名。
常量名的所有字母必须大写。
常量中的单词必须以下划线分隔，例如可以这样 CONNECT_TIMEOUT 但不许这样CONNECTTIMEOUT。
常量建议通过 "const" 定义为类的成员，强烈不鼓励使用 "define" 定义的全局常量。

## 编码风格
### PHP 代码划分（Demarcation）
PHP 代码总是用完整的标准的 PHP 标签定界：
```php
<?php
?>
```
短标签是不允许的，只包含 PHP 代码的文件，不要结束标签。

### 字符串
#### 字符串文字
当字符串是文字(不包含变量)，应当用单引号（ apostrophe ）来括起来：
$a = 'Example String';

#### 包含单引号（'）的字符串文字
当文字字符串包含单引号（apostrophe ）就用双引号括起来，特别在 SQL 语句中有用：
$sql = "SELECT `id`, `name` from `people` WHERE `name`='Fred' OR `name`='Susan'";
在转义单引号时，上述语法是首选的，因为很容易阅读。

#### 字符串连接
字符串必需用 "." 操作符连接，在它的前后加上空格以提高可读性：
```php
$company = 'Zend' . ' ' . 'Technologies';
```
当用 "." 操作符连接字符串，鼓励把代码可以分成多个行，也是为提高可读性。在这些例子中，每个连续的行应当由 whitespace 来填补，例如 "." 和 "=" 对齐：
```php
$sql = "SELECT id, name FROM people "
     . "WHERE name = 'Susan' "
     . "ORDER BY name ASC ";
```

### 数组
#### 数字索引数组
索引不能为负数
建议数组索引从 0 开始。
当用 array 函数声明有索引的数组，在每个逗号的后面间隔空格以提高可读性：
```php
$sampleArray = array(1, 2, 3, 'Zend', 'Studio');
```
可以用 "array" 声明多行有索引的数组，在每个连续行的开头要用空格填补对齐：
```php
$sampleArray = array(1, 2, 3, 'Zend', 'Studio',
                     $a, $b, $c,
                     56.44, $d, 500);
```
#### 关联数组
当用声明关联数组，array 我们鼓励把代码分成多行，在每个连续行的开头用空格填补来对齐键和值：
```php
$sampleArray = array('firstKey'  => 'firstValue',
                     'secondKey' => 'secondValue');
```

### 类
#### 类的声明
用 Zend Framework 的命名约定来命名类。
花括号应当从类名下一行开始(the "one true brace" form)。
每个类必须有一个符合 PHPDocumentor 标准的文档块。
类中所有代码必需用四个空格的缩进。
每个 PHP 文件中只有一个类。
放另外的代码到类里允许但不鼓励。在这样的文件中，用两行空格来分隔类和其它代码。
下面是个可接受的类的例子： // 459 9506 － 441 9658 下次从这里开始
```php
/**
 * Documentation Block Here
 */
class SampleClass
{
    // 类的所有内容
    // 必需缩进四个空格
}
```

#### 类成员变量
变量的声明必须在类的顶部，在方法的上方声明。
不允许使用var，要用private、protected或public。直接访问public变量是允许的但不鼓励，最好使用访问器（set/get）。

### 函数和方法
#### 函数和方法声明
在类中的函数必须用 private、 protected 或 public 声明它们的可见性。
象类一样，花括号从函数名的下一行开始(the "one true brace" form)。
强烈反对使用全局函数。
下面是可接受的在类中的函数声明的例子：
```php
/**
 * Documentation Block Here
 */
class Foo
{
    /**
     * Documentation Block Here
     */
    public function bar()
    {
        // 函数的所有内容
        // 必需缩进
    }
}
```

#### 函数和方法的用法
函数的参数应当用逗号和紧接着的空格分开，下面可接受的调用的例子中的函数带有三个参数：
```php
three_arguments(1, 2, 3);
```

带有数组参数的函数，函数的调用可包括 "array" 提示并可以分成多行来提高可读性，同时，书写数组的标准仍然适用：
```php
threeArguments(array(1, 2, 3), 2, 3);
threeArguments(array(1, 2, 3, 'Zend', 'Studio',
                     $a, $b, $c,
                     56.44, $d, 500), 2, 3);
```

### 控制语句
#### if/Else/Elseif
鼓励使用多重圆括号以提高在复杂的条件中划分逻辑组合。
前花括号必须和条件语句在同一行，后花括号单独在最后一行，其中的内容缩进。
```php
if ($a != 2) {
    $a = 2;
}
```
对包括"elseif" 或 "else"的 "if" 语句，和 "if" 结构的格式类似， 下面的例子示例 "if" 语句， 包括 "elseif" 或 "else" 的格式约定：
```php
if ($a != 2) {
    $a = 2;
} else {
    $a = 7;
}

if ($a != 2) {
    $a = 2;
} elseif ($a == 3) {
    $a = 4;
} else {
    $a = 7;
}
```
在有些情况下， PHP 允许这些语句不用花括号，但在(ZF) 代码标准里，它们（"if"、 "elseif" 或 "else" 语句）必须使用花括号。
"elseif" 是允许的但强烈不鼓励，我们支持 "else if" 组合。

#### Switch
"switch" 里的代码必须有四个空格缩进，在"case"里的代码再缩进四个空格。
```php
switch ($numPeople) {
    case 1:
        break;

    case 2:
        break;

    default:
        break;
}
```
switch 语句应当有 default。
注： 有时候，在 falls through 到下个 case 的 case 语句中不写 break or return 很有用。 为了区别于 bug，任何 case 语句中，所有不写 break or return 的地方应当有一个 "// break intentionally omitted" 这样的注释来表明 break 是故意忽略的。

### 注释文档
#### 格式
所有文档块 ("docblocks") 必须和 phpDocumentor 格式兼容，phpDocumentor 格式的描述超出了本文档的范围，关于它的详情，参考：» http://phpdoc.org/。
所有类文件必须在文件的顶部包含文件级 （"file-level"）的 docblock ，在每个类的顶部放置一个 "class-level" 的 docblock。下面是一些例子：

#### 文件
每个包含 PHP 代码的文件必须至少在文件顶部的 docblock 包含这些 phpDocumentor 标签：
```php
/**
 * 文件的简短描述
 *
 * 文件的详细描述（如果有的话）... ...
 *
 * LICENSE: 一些 license 信息
 *
 * @copyright  Copyright (c) 2005-2011 Zend Technologies USA Inc. (http://www.zend.com)
 * @license    http://framework.zend.com/license/3_0.txt   BSD License
 * @version    $Id:$
 * @link       http://framework.zend.com/package/PackageName
 * @since      File available since Release 1.5.0
*/
```

#### 类
每个类必须至少包含这些 phpDocumentor 标签：
```php
/**
 * 类的简述
 *
 * 类的详细描述 （如果有的话）... ...
 *
 * @copyright  Copyright (c) 2005-2011 Zend Technologies USA Inc. (http://www.zend.com)
 * @license    http://framework.zend.com/license/   BSD License
 * @version    Release: @package_version@
 * @link       http://framework.zend.com/package/PackageName
 * @since      Class available since Release 1.5.0
 * @deprecated Class deprecated in Release 2.0.0
 */
```

#### 函数
每个函数，包括对象方法，必须有最少包含下列内容的文档块（docblock）：
函数的描述
所有参数
所有可能的返回值
因为访问级已经通过 "public"、 "private" 或 "protected" 声明， 不需要使用 "@access"。
如果函数/方法抛出一个异常，使用 @throws 于所有已知的异常类：
@throws exceptionclass [description]

## 参考文档
[Zend Framework 的 PHP 编码标准](http://framework.zend.com/manual/zh/coding-standard.html)