* 具有免费与开源版本的 Percona 监控和管理（PMM）
    ```
    http://www.cnblogs.com/o-to-s/articles/6807333.html

    docker run -p 2080:80 percona/pmm-server:1.8.1

    https://www.percona.com/downloads/pmm/1.1.2/binary/debian/trusty/x86_64/
    https://www.percona.com/downloads/pmm/1.8.1/binary/debian/xenial/x86_64/pmm-client_1.8.1-1.xenial_amd64.deb
    pmm-admin list
    pmm-admin add mysql --user --password --host 10.2.0.42 --port 3306
    pmm-admin repair
    ```
* lepus
    ```
    http://www.lepus.cc/
    ```
