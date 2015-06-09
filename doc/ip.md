# command
```shell
# 显示所有已连接的网络接口
ifconfig -a
ip link show

# 激活或停用网络接口
ifconfig eth1 up
ifconfig eth1 down
ip link set down eth1
ip link set up eth1

# 为网络接口分配IPv4地址
ifconfig eth1 10.0.0.1/24
ip addr add 10.0.0.1/24 dev eth1
ip addr add 10.0.0.1/24 broadcast 10.0.0.255 dev eth1
ip addr add 10.0.0.2/24 broadcast 10.0.0.255 dev eth1
ip addr add 10.0.0.3/24 broadcast 10.0.0.255 dev eth1

# 移除网络接口的IPv4地址
ifconfig eth1 0
ip addr del 10.0.0.1/24 dev eth1

# 显示网络接口的IPv4地址
ifconfig eth1
ip addr show dev eth1

# 为网络接口分配IPv6地址
ifconfig eth1 inet6 add 2002:0db5:0:f102::1/64
ifconfig eth1 inet6 add 2003:0db5:0:f102::1/64
ip -6 addr add 2002:0db5:0:f102::1/64 dev eth1
ip -6 addr add 2003:0db5:0:f102::1/64 dev eth1

# 显示网络接口的IPv6地址
ifconfig eth1
ip -6 addr show dev eth1

# 移除网络设备的IPv6地址
ifconfig eth1 inet6 del 2002:0db5:0:f102::1/64
ip -6 addr del 2002:0db5:0:f102::1/64 dev eth1

# 改变网络接口的MAC地址
ifconfig eth1 hw ether 08:00:27:75:2a:66
ip link set dev eth1 address 08:00:27:75:2a:67

# 查看IP路由表
route -n
netstat -rn
ip route show

# 添加和修改默认路由
route add default gw 192.168.1.2 eth0
route del default gw 192.168.1.1 eth0
ip route add default via 192.168.1.2 dev eth0
ip route replace default via 192.168.1.2 dev eth0

# 添加和移除静态路由
route add -net 172.16.32.0/24 gw 192.168.1.1 dev eth0
route del -net 172.16.32.0/24
ip route add 172.16.32.0/24 via 192.168.1.1 dev eth0
ip route del 172.16.32.0/24

# 查看套接字统计信息
netstat
netstat -l
ss
ss -l

# 查看ARP表
arp -an
ip neigh

# 添加或删除静态ARP项
arp -s 192.168.1.100 00:0c:29:c0:5a:ef
arp -d 192.168.1.100
ip neigh add 192.168.1.100 lladdr 00:0c:29:c0:5a:ef dev eth0
ip neigh del 192.168.1.100 dev eth0

# 添加、删除或查看多播地址
ipmaddr add 33:44:00:00:00:01 dev eth0
ipmaddr del 33:44:00:00:00:01 dev eth0
ipmaddr show dev eth0
netstat -g
ip maddr add 33:44:00:00:00:01 dev eth0
ip maddr del 33:44:00:00:00:01 dev eth0
ip maddr list dev eth0
```

# links
- [iproute2 对决 net-tools](https://linux.cn/article-4326-1.html)
