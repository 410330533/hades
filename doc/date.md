# date
```shell
date --set='2014-11-10 13:13:01'
date +'%Y%m%d %H%m' --set='20140928 1518'
date --set='+5 minutes'
date --set='-2 weeks'
date --set='+3 months'
date --set='-3 months +2 weeks -5 minutes'

hwclock --systohc
ntpdate -u <NTP 服务器名或IP>
```
