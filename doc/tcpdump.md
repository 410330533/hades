# tcpdump
```shell
监听dns
tcpdump -i eth0 -nt -s 500 port domain

tcpdump -i eth1 "tcp[tcpflags] & (tcp-syn) != 0" # 只捕获tcp syn包
tcpdump -i eth1 "tcp[tcpflags] & (tcp-ack) != 0" # 只捕获tcp ack包
tcpdump -i eth1 "tcp[tcpflags] & (tcp-fin) != 0" # 只捕获tcp fin包
tcpdump -i eth1 "tcp[tcpflags] & (tcp-syn|tcp-ack) != 0" # 只捕获tcp syn或ack包
```

