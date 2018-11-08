# mysqlbinlog
```shell
mysqlbinlog --no-defaults mysql-bin-2.001895 | less
mysqlbinlog --start-date='2014-09-16 14:00:00' --stop-date='2014-09-16 14:20:00'
mysqlbinlog mysql-bin.000048 --start-position=93758480 --stop-position=93758616 | mysql -uroot -p
mysqlbinlog --base64-output=decode-rows -v mysql-bin-2.001895
```
