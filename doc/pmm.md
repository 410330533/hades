* pmm-server
```
docker create \
   -v /opt/prometheus/data \
   -v /opt/consul-data \
   -v /var/lib/mysql \
   -v /var/lib/grafana \
   --name pmm-data \
   percona/pmm-server:1.12.0 /bin/true

docker run -d \
   -p 2080:80 \
   --volumes-from pmm-data \
   --name pmm-server \
   --restart always \
   percona/pmm-server:1.12.0

docker run -d \
    -p 2080:80 \
    --name pmm-server \
    -e SERVER_USER=admin -e SERVER_PASSWORD=admin \
    --restart always \
    percona/pmm-server:1.12.0
```

* pmm-client
```
pmm-admin list
pmm-admin config --server 192.168.211.136:2080 --server-user admin --server-password admin
pmm-admin add mysql --disable-tablestats
pmm-admin add mysql --user monitor --password '123456' --host localhost --port 3306 instance-01
pmm-admin add mysql --user monitor --password '123456' --host localhost --port 3307 instance-02
pmm-admin add mysql --user root --password root --create-user
GRANT SELECT, PROCESS, SUPER, REPLICATION CLIENT, RELOAD ON *.* TO 'pmm'@' localhost' IDENTIFIED BY 'pass' WITH MAX_USER_CONNECTIONS 10;
GRANT SELECT, UPDATE, DELETE, DROP ON performance_schema.* TO 'pmm'@'localhost';
flush privileges;
pmm-admin repair
pmm-admin stop --all
pmm-admin start --all
```