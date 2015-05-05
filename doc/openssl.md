# openssl
```shell
# 用于生成服务端私钥文件server.key，后面的参数2048单位是bit，是私钥的长度。
openssl genrsa -out server.key 2048

# openssl生成的私钥中包含了公钥的信息，我们可以根据私钥生成公钥
openssl rsa -in server.key -out server.key.public

# 根据私钥直接生成自签发的数字证书
openssl req -new -x509 -key server.key -out server.crt -days 365
```

# link
- [Go和HTTPS](http://tonybai.com/2015/04/30/go-and-https/)
