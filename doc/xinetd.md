# 端口转发
```conf
service http-switch
{
    disable = no
    type = UNLISTED
    socket_type = stream
    protocol = tcp
    wait = no
    redirect = 192.168.10.254 80
    bind = 10.10.10.1
    port = 81
    user = nobody
}
```
