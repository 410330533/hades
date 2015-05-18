```shell
rename [-v -n -f] <pcre> <files>

rename 's/\.jpeg$/\.jpg/' *.jpeg
rename 'y/A-Z/a-z/' *
rename 'y/a-z/A-Z/' *
rename -v 's/img_(\d{4})\.jpeg$/dan_$1\.jpg/' *.jpeg
```

# links
- [Linux有问必答：如何在Linux下重命名多个文件](https://linux.cn/article-4905-1.html)
