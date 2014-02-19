# ssh
```shell
apt-get install openssh-server
```

# A无需密码访问B
```shell
在A上生成公钥和私钥 ssh-keygen -t rsa
将A的公钥放到B的信任key中 cat id_rsa.pub >> ~/.ssh/authorized_keys
```

# ssh reverse connection
```shell
1. 被控端执行 ssh -NfR 1111:localhost:22 username@123.123.123.123
将主控端1111端口和被控端22端口绑定

2. 在主控端连接 ssh localhost -p1111
```

