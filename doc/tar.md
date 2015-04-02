# tar

## tar
```shell
tar cvf archive.tar file1 file2 file3

tar -zcvf MyImages-14-09-12.tar.gz /home/MyImages
tar -zcvf MyImages-14-09-12.tgz /home/MyImages

tar -jcvf Phpfiles-org.tar.bz2 /home/php
```

## untar
```shell
tar -xvf public_html-14-09-12.tar
tar -xvf public_html-14-09-12.tar -C /home/public_html/videos/
```

## untar single file
```shell
tar -xvf cleanfiles.sh.tar cleanfiles.sh
tar -zxvf tecmintbackup.tar.gz tecmintbackup.xml
tar -jxvf Phpfiles-org.tar.bz2 home/php/index.php
```

## untar multiple files
```shell
tar -xvf tecmint-14-09-12.tar "file 1" "file 2"
tar -zxvf MyImages-14-09-12.tar.gz "file 1" "file 2"
tar -jxvf Phpfiles-org.tar.bz2 "file 1" "file 2"
```

## untar a group of files using wildcard
```shell
tar -xvf Phpfiles-org.tar --wildcards '*.php'
tar -zxvf Phpfiles-org.tar.gz --wildcards '*.php'
tar -jxvf Phpfiles-org.tar.bz2 --wildcards '*.php'
```

## list content
```shell
tar -tvf uploadprogress.tar
tar -tvf staging.tecmint.com.tar.gz
tar -tvf Phpfiles-org.tar.bz2
```

## add files or directories to archive file
```shell
tar -rvf tecmint-14-09-12.tar xyz.txt
tar -rvf tecmint-14-09-12.tar php
tar -rvf MyImages-14-09-12.tar.gz xyz.txt
tar -rvf Phpfiles-org.tar.bz2 xyz.txt
```

## 对归档文件进行更新 ( u / --update)
```shell
tar uvf archive.tar newfile.c
```

## 从归档中删除文件 (--delete)
```shell
tar --delete -f archive.tar file1.c
```

## verify
```shell
tar -tvfW tecmint-14-09-12.tar
```

## check the size of the tar
```shell
tar -czf - tecmint-14-09-12.tar | wc -c
tar -czf - MyImages-14-09-12.tar.gz | wc -c
tar -czf - Phpfiles-org.tar.bz2 | wc -c
```

# link
- [18 Tar Command Examples in Linux](http://www.tecmint.com/18-tar-command-examples-in-linux/)
- [Linux 下最为人熟知的归档/压缩工具](http://linux.cn/article-5131-1.html)
