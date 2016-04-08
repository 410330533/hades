# New in Symfony 3.1: Strict Image Validation
# Symfony 3.1新特性：严格图片校验

http://symfony.com/blog/new-in-symfony-3-1-strict-image-validation

The Image constraint is one of the most powerful constraints defined by the Validator component. It allows you to validate the max/min height and width, the max/min ratio of images, whether the format should be portrait or landscape, etc.

Image约束是Validator组件定义的最强大的约束之一。它允许你验证最大/最小高和宽，最大/最小比例，纵向或横向等。

However, it lacked a very important check: validate that the image is not corrupted and therefore, that it will be displayed correctly in your application. That's why Symfony 3.1 includes a new detectCorrupted configuration option and its corresponding corruptedMessage:

然而，它缺少一个重要的检查：验证图片到底破了没，没破，图片就能在你的应用里正确的显示。这就是为什么Symfony 3.1 包含了一个新的 detectCorrupted 配置项和其匹配的 corruptedMessage :

```php
use Symfony\Component\Validator\Constraints as Assert;

class Product
{
    /**
     * @Assert\Image(
     *     detectCorrupted = true,
     *     corruptedMessage = "Product photo is corrupted. Upload it again."
     * )
     */
    protected $photo;
}
```

Internally this feature uses PHP's imagecreatefromstring() function to check that the provided contents can create a valid image. Therefore, before using this new validation, make sure that the GD extension is installed and enabled in your PHP engine.

内部来讲，这个特性是使用了php的 `imagecreatefromstring()` 函数来检查提供的内容是否能创建有效的图片。因此，在使用这个新的校验之前，确保在你的php引擎里装了GD扩展并启用。

As you can imagine, this option makes the validation be slower and consume more memory, but that's a reasonable trade-off when some images are critical for your application.

你能想象，这个选项会使得校验变慢，并消耗更多的内存。但是，当一些图片对你的应用很重要时，这个交易还是值得做的。
