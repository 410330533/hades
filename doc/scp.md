# example
```shell
scp source_file_name username@destination_host:destination_folder
```

用-v参数来提供SCP进程的详细信息
```shell
scp -v Label.pdf mrarianto@202.x.x.x:. 
```

-p参数会帮到把预计的时间和连接速度会显示在屏幕上。
```shell
scp -p Label.pdf mrarianto@202.x.x.x:.
```

用-C参数来让文件传输更快
```shell
scp -Cpv messages.log mrarianto@202.x.x.x:.
```

SCP默认是用“AES-128”加密算法来加密传输的。如果你想要改用其它加密算法来加密传输，你可以用“-c”参数。
```shell
scp -c 3des Label.pdf mrarianto@202.x.x.x:.
```

在“-l”参数后面的这个400值意思是我们给SCP进程限制了带宽为50 KB/秒。有一点要记住，带宽是以千比特/秒 (kbps)表示的，而8 比特等于1 字节。
```shell
scp -l 400 Label.pdf mrarianto@202.x.x.x:.
```

通常SCP是把22作为默认端口。但是为了安全起见SSH 监听端口改成其它端口。比如说，我们想用2249端口，这种情况下就要指定端口。
```shell
scp -P 2249 Label.pdf mrarianto@202.x.x.x:.
```

递归拷贝文件和文件夹
```shell
scp -r documents mrarianto@202.x.x.x:.
```

禁用进度条和警告/诊断信息
```shell
scp -q Label.pdf mrarianto@202.x.x.x:.
```

# link
- [十个 SCP 传输命令例子](http://linux.cn/article-4527-1.html)
