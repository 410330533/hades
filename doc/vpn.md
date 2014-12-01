# pptp
```shell
apt-get install pptpd

vi /etc/pptpd.conf
localip 10.0.0.1
remoteip 10.0.0.100-200

vi /etc/ppp/chap-secrets
username1 pptpd password1 *

vi /etc/ppp/pptpd-options
ms-dns 8.8.8.8
ms-dns 8.8.4.4

service pptpd restart

vi /etc/sysctl.conf
net.ipv4.ip_forward = 1
sysctl -p
```

# link
- [How To Setup Your Own VPN With PPTP](https://www.digitalocean.com/community/tutorials/how-to-setup-your-own-vpn-with-pptp)
