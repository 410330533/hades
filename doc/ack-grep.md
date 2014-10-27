# ack-grep
```shell
apt-get install ack-grep
dpkg-divert --local --divert /usr/bin/ack --rename --add /usr/bin/ack-grep

ack-grep restrict
ack-grep -w restrict
ack-grep -w --php ProductStatus
```

- [Documentation](http://beyondgrep.com/documentation/)
- [How To Install and Use Ack, a Grep Replacement for Developers, on Ubuntu 14.04](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-ack-a-grep-replacement-for-developers-on-ubuntu-14-04)
