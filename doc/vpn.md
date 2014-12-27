# pptp
```shell
apt-get install pptpd

vi /etc/pptpd.conf
localip 192.168.0.1
remoteip 192.168.0.234-238

vi /etc/ppp/chap-secrets
username1 pptpd password1 *

vi /etc/ppp/pptpd-options
ms-dns 8.8.8.8
ms-dns 8.8.4.4

service pptpd restart

vi /etc/sysctl.conf
net.ipv4.ip_forward = 1
sysctl -p

iptables-save > iptables.bak
iptables-restore < iptables.bak

注意：由于阿里云是双网卡，内网eth0，外网eth1，所以这块特别容易误写为eth0，这也是为什么很多杂乱的教程无法配置成功的原因之一
iptables -t nat -A POSTROUTING -s 192.168.0.0/24 -o eth1 -j MASQUERADE
iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
```

# link
- [How To Setup Your Own VPN With PPTP](https://www.digitalocean.com/community/tutorials/how-to-setup-your-own-vpn-with-pptp)
- [VPS 教程系列：Ubuntu 14.04 安装 OpenVPN Static Key 科学上网](http://ttt.tt/160/)
