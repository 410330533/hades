# shadowsocks
```shell
apt-get install python-pip
pip install shadowsocks

vi ~/shadowsocks.json
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
ssserver -c ~/shadowsocks.json
ssserver -c ~/shadowsocks.json -d start
ssserver -c ~/shadowsocks.json -d stop

local
sslocal -c ~/shadowsocks.json
sslocal -c ~/shadowsocks.json -d start
sslocal -c ~/shadowsocks.json -d stop
```
