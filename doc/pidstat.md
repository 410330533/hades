# install
```shell
apt-get install sysstat
```

# pidstat

- PID - 被监控的任务的进程号
- %usr - 当在用户层执行(应用程序)时这个任务的cpu使用率，和 nice 优先级无关。注意这个字段计算的cpu时间不包括在虚拟处理器中花去的时间。
- %system - 这个任务在系统层使用时的cpu使用率。
- %guest - 任务花费在虚拟机上的cpu使用率（运行在虚拟处理器）。
- %CPU - 任务总的cpu使用率。在SMP环境(多处理器)中，如果在命令行中输入-I参数的话，cpu使用率会除以你的cpu数量。
- CPU - 正在运行这个任务的处理器编号。
- Command - 这个任务的命令名称。

# pidstat -d -p 16887

- kB_rd/s - 任务从硬盘上的读取速度（kb）
- kB_wr/s - 任务向硬盘中的写入速度（kb）
- kB_ccwr/s - 任务写入磁盘被取消的速率（kb）

# pidstat -r -p 16887

- minflt/s - 从内存中加载数据时每秒出现的小的错误的数目，这些不要求从磁盘载入内存页面。
- majflt/s - 从内存中加载数据时每秒出现的较大错误的数目，这些要求从磁盘载入内存页面。
- VSZ - 虚拟容量：整个进程的虚拟内存使用（kb）
- RSS - 长期内存使用：任务的不可交换物理内存的使用量（kb）

# link

- [pidstat - 监控并统计Linux进程的数据](http://linux.cn/article-4257-1.html)
