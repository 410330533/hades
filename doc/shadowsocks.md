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

Configure Multiple Users
{
    "server": "0.0.0.0",
    "port_password": {
        "8381": "foobar1",
        "8382": "foobar2",
        "8383": "foobar3",
        "8384": "foobar4"
    },
    "timeout": 300,
    "method": "aes-256-cfb"
}

server
ssserver -c /etc/shadowsocks.json
ssserver -c /etc/shadowsocks.json -d start
ssserver -c /etc/shadowsocks.json -d stop

local
sslocal -c /etc/shadowsocks.json
sslocal -c /etc/shadowsocks.json -d start
sslocal -c /etc/shadowsocks.json -d stop
```
