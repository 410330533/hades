# shadowsocks
```shell
apt-get install python-pip
pip install shadowsocks

vi /etc/shadowsocks.json
{
    "server":"服务器 IP 地址",
    "server_port":8388,
    "local_address": "127.0.0.1",
    "local_port":1080,
    "password":"mypassword",
    "timeout":300,
    "method":"aes-256-cfb",
    "fast_open": false,
    "workers": 1
}

server
ssserver -c /etc/shadowsocks.json

local
sslocal -c /etc/shadowsocks.json
```

# link
- [双服务器，CentOS系统，使用Squid和Stunnel搭建翻墙代理服务](http://fuweiyi.com/others/2014/05/15/a-Centos-Squid-Stunnel-proxy.html)
