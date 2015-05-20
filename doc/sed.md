# command
```shell
find src/ -name "*.php" | xargs grep 'UCOBJ_HUITONG' --color -nw  | awk -F: '{print $1}' | xargs sed -i s/UCOBJ_HUITONG/BESTBJ/
```

# link
- [sed 简明教程](http://coolshell.cn/articles/9104.html)
