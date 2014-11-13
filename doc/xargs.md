# xargs
```shell
find xargstest/ -name 'file??' | sort | xargs wc -l
find xargstest/ -name 'file?B' | sort | xargs head -n1
find xargstest/ -name 'file??' | xargs myscript.sh
```
