### docker mritd/shadowsocks
```shell
https://hub.docker.com/r/mritd/shadowsocks/
docker run -dt --name ss -p 6443:6443 mritd/shadowsocks -s "-s 0.0.0.0 -p 6443 -m aes-256-cfb -k test123 --fast-open"

server
docker run -dt --name ss -p 6443:6443 -p 6500:6500/udp mritd/shadowsocks -s "-s :: -s 0.0.0.0 -p 6443 -m aes-256-cfb -k test123 --fast-open" -k "-t 127.0.0.1:6443 -l :6500 -mode fast2" -x
ss-server -s :: -s 0.0.0.0 -p 6443 -m aes-256-cfb -k test123 --fast-open kcptun -t 127.0.0.1:6443 -l :6500 -mode fast2

client
docker run -dt --name ss -p 1080:1080 mritd/shadowsocks -m "ss-local" -s "-c /etc/shadowsocks-libev/test.json"
ss-local -c /etc/shadowsocks-libev/test.json
```

### docker oddrationale/docker-shadowsocks
```shell
https://hub.docker.com/r/oddrationale/docker-shadowsocks/
docker pull oddrationale/docker-shadowsocks
docker run -d -p 1984:1984 oddrationale/docker-shadowsocks -s 0.0.0.0 -p 1984 -k $SSPASSWORD -m aes-256-cfb
```

### pip install
```shell
apt-get install python-pip
pip install shadowsocks
```

### config
```conf
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
