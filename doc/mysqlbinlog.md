# mysqlbinlog
```shell
mysqlbinlog --no-defaults mysql-bin-2.001895 | less
mysqlbinlog mysql-bin.000048 --start-position=93758480 --stop-position=93758616 | mysql -uroot -p
```
