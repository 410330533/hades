# nslookup
```shell
nslookup qq.com
nslookup -query=mx qq.com # 查询邮件交换器记录
nslookup -type=ns qq.com # 查询域名服务器
nslookup -type=any qq.com # 查询DNS记录
nslookup -type=soa qq.com # 查询起始授权机构
nslookup -port 56 qq.com # 查询端口号
```
