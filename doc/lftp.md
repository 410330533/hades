# lftp
```shell
apt-get install lftp

lftp ftp://linoxide@localhost
lftp ftp://linoxide@localhost:21

pget linspeed.svg
pget -c linoxide.tar
put linoxide.tar
put -c upload.tar

mirror remote local
mirror -R local remote
mirror -c Directory

queue stop
queue mirror "directory"
queue pget "file.tar"
queue start
queue -d

pget -n 3 file.tar
mirror --use-pget-n=3 linxoxide

kill
kill all

exit
```

# links
- [LFTP : 一个功能强大的命令行FTP程序](https://linux.cn/article-5460-1.html)
