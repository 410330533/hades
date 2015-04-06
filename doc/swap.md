# install
```shell
free -m
dd if=/dev/zero of=/root/swapfile bs=1M count=1024
mkswap /root/swapfile
swapon /root/swapfile
swapoff /root/swapfile
```

# link
- [Linux新建和增加Swap分区](http://smilejay.com/2012/09/new-or-add-swap/)
