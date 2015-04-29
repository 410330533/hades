# rsync
```shell
rsync -zvr /home/aloft/ /backuphomedir # 启用压缩
rsync -azvr /home/aloft/ /backuphomedir # 保留文件和文件夹的属性
rsync -avz /home/aloft/ azmath@192.168.1.4:192.168.1.4:/share/rsysnctest/ # 同步本地到远程主机
rsync -avz azmath@192.168.1.4:192.168.1.4:/share/rsysnctest/ /home/aloft/ # 远程同步到本地
rsync -avzi /backuphomedir /home/aloft/ # 找出文件间的不同
```

# link
- [如何在Linux下使用rsync](http://linux.cn/article-4503-1.html)
