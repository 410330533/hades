# mysqlslap
[mysqlslap official doc](http://dev.mysql.com/doc/refman/5.1/en/mysqlslap.html)
```shell
自动生成测试表和数据的形式，分别模拟 50 和 100 个客户端并发连接处理 1000 个 query 的情况。
mysqlslap -a --concurrency=50,100 --number-of-queries=1000

增加 --debug-info 选项，可以输出内存和CPU信息。
mysqlslap -a --concurrency=50,100 --number-of-queries=1000 --debug-info

增加 --iterations 选项，可以 重复执行 5 次
mysqlslap -a --concurrency=50,100 --number-of-queries=1000 --iterations=5 --debug-info

针对远程主机上的 mysql 进行测试。
mysqlslap -a --concurrency=50,100 --number-of-queries=1000 -h 172.16.81.99 -P 3306 -p

使用 --only-print 选项，可以查看 mysqlslap 在测试过程中如何执行的 sql 语句。
在这种方式下，仅会对数据库进行模拟操作。如下显示的自动产生测试表和数据的情况下，
mysqlslap 的执行过程： 创建一个临时的库 mysqlslap ，并在测试结束是会将其删除。
mysqlslap -a --only-print  

使用 --defaults-file 选项，指定从配置文件中读取选项配置。 
使用 --number-int-cols 选项，指定表中会包含 4 个 int 型的列。 
使用 --number-char-cols 选项，指定表中会包含 35 个 char 型的列。 
使用 --engine 选项，指定针对何种存储引擎进行测试。
mysqlslap --defaults-file=/etc/my.cnf --concurrency=50,100,200 --iterations=1 --number-int-cols=4 
--number-char-cols=35 --auto-generate-sql --auto-generate-sql-add-autoincrement --auto-generate-sql-load-type=mixed
--engine=myisam,innodb --number-of-queries=200 --debug-info -S /tmp/mysql.sock
```
