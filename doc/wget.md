# wget
```shell
# 下载单个文件
wget http://mirror.nbrc.ac.in/centos/7.0.1406/isos/x86_64/CentOS-7.0-1406-x86_64-DVD.iso

# 续传分段下载文件
wget -c http://mirror.nbrc.ac.in/centos/7.0.1406/isos/x86_64/CentOS-7.0-1406-x86_64-DVD.iso

# 后台下载文件
wget -b http://mirror.nbrc.ac.in/centos/7.0.1406/isos/x86_64/CentOS-7.0-1406-x86_64-DVD.iso

# 限制下载速率
wget --limit-rate=100k http://mirror.nbrc.ac.in/centos/7.0.1406/isos/x86_64/CentOS-7.0-1406-x86_64-DVD.iso

# 使用-i选项来下载多个文件
wget -i download-list.txt

# 增加重试次数
wget --tries=75 http://mirror.nbrc.ac.in/centos/7.0.1406/isos/x86_64/CentOS-7.0-1406-x86_64-DVD.iso

# 使用-o选项来重定向wget日志到文件
wget -o download.log http://mirror.nbrc.ac.in/centos/7.0.1406/isos/x86_64/CentOS-7.0-1406-x86_64-DVD.iso

# 下载整个网站用于本地查看
wget --mirror -p --convert-links -P ./<Local-Folder> website-url
–mirror : 开启适用于镜像的选项。
-p : 下载所有能正确显示指定HTML网页的全部必要文件。
–convert-links : 下载完成后，转换文档中的链接以用于本地查看。
-P ./Local-Folder : 保存所有文件和目录到指定的目录。

# 下载过程中拒绝文件类型
wget --reject=png Website-To-Be-Downloaded

# 使用wget -Q设置下载配额
wget -Q10m -i download-list.txt

# 从密码保护的网站下载文件
wget --ftp-user=<user-name> --ftp-password=<password> Download-URL
```
