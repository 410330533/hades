# command
```shell
apt-get install openssh-server

ssh user@remote_vps -L 3306:127.0.0.1:3306 -N # 在本地的3306端口和远程VPS的3306端口之间将会建立一个SSH隧道
```

# A无需密码访问B
```shell
在A上生成公钥和私钥 ssh-keygen -t rsa
将A的公钥放到B的信任key中 cat id_rsa.pub >> ~/.ssh/authorized_keys
ssh-copy-id -i id_rsa.pub username@127.0.0.1
cat ~/.ssh/id_rsa.pub | ssh user@123.45.56.78 "mkdir -p ~/.ssh && cat >>  ~/.ssh/authorized_keys"
```

# ssh reverse connection
```shell
1. 被控端执行 ssh -NfR 1111:localhost:22 username@123.123.123.123 将主控端1111端口和被控端22端口进行绑定
2. 在主控端连接 ssh localhost -p1111
```

