# shadowsocks
```shell
/usr/bin/python /usr/local/bin/ssserver -c /etc/shadowsocks.json -d start
./sslocal -c ~/git/software/shadowsocks.json -d start
```

# conf
```conf
{
    "server":"0.0.0.0",
    "server_port":8388,
    "local_address": "127.0.0.1",
    "local_port":1080,
    "password":"password",
    "timeout":300,
    "method":"aes-256-cfb",
    "fast_open": false,
    "workers": 1
}
```

# link
[shadowsocks](https://github.com/shadowsocks/shadowsocks)
