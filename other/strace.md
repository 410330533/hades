# strace
```shell
strace ls
strace php 2>&1 | grep php.ini
strace -p 19931
strace -p 19931 -o process_strace
strace -c ls
strace -t ls
strace -tt ls
strace -ttt ls
strace -r ls
```
