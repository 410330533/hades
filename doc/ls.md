# command
```shell
# 以各种时间格式附带时间戳列出目录中的内容
ls -l --time-style=[STYLE]
ls --full-time 
[STYLE] 可选值[full-iso/long-iso/iso/locale/+%H:%M:%S:%D]

# 以多种格式列出目录内容，如以逗号分隔、水平格式、长格式、垂直格式、交叉格式等列出。
ls --format=across        # 交叉
ls --format=comma         # 逗号
ls --format=horizontal    # 水平
ls --format=long          # 长格式
ls --format=single-column # 单栏
ls --format=verbose       # 详情
ls --format=vertical      # 垂直

# 根据扩展名、大小、时间和版本对目录内容排序。
ls --sort=extension
ls --sort=size
ls --sort=time
ls --sort=version
ls --sort=none

# 使用ls命令打印目录中各个项的数字UID和GID。
ls -n

# 标准输出结果中打印目录内容中比默认指定的更多栏目。
ls --width 80
ls --width 100

# 通过ls命令为列出的目录内容手动指定的制表符大小而不是默认的8。
ls --tabsize=[value]
```

# links
- [Linux用户应知应会的7个‘ls’命令的独特技巧](https://linux.cn/article-5531-1.html)
