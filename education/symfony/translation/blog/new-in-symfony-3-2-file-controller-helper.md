http://symfony.com/blog/new-in-symfony-3-2-file-controller-helper

# New in Symfony 3.2: File controller helper

This is the first article of the "New in Symfony 3.2" series where we'll showcase the most relevant new features of the upcoming Symfony 3.2 version (to be published on November 2016).

The Symfony base controller is a utility class that includes several helper methods for common controller tasks and provides direct access to the service container. In Symfony 3.2 we added a new helper method called file() to simplify serving binary files.

The simplest way to use the file() helper is to pass the path of the file to download. The browser will force the download of this file and it will assign it the same name as the original file:

```php
use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class BookController extends Controller
{
    public function downloadAction()
    {
        $pdfPath = $this->getParameter('dir.downloads').'/sample.pdf';

        return $this->file($pdfPath);
    }
}
```

If you prefer to set a custom name for the file, use the optional second argument:

```php
return $this->file($pdfPath, 'sample-of-my-book.pdf');
```

If you prefer to show the file contents in the browser instead of forcing its download, use the optional third argument:

```php
use Symfony\Component\HttpFoundation\ResponseHeaderBag;

return $this->file($pdfPath, 'sample.pdf', ResponseHeaderBag::DISPOSITION_INLINE);
```

In addition to file path strings, this helper also accepts File and UploadedFile instances as its first argument:

```php
use Symfony\Component\HttpFoundation\File\File;

$samplePdf = new File($this->getParameter('dir.downloads').'/sample.pdf');

return $this->file($samplePdf);
```
