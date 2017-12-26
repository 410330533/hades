# example
```shell
sudo ufw default allow outgoing
sudo ufw default deny incoming

sudo ufw allow ssh
ufw allow 22
ufw allow 1723
ufw allow 80
sudo ufw allow 80/tcp
sudo ufw allow http/tcp
sudo ufw allow 1725/udp
sudo ufw allow from 123.45.67.89
sudo ufw allow from 123.45.67.89/24
sudo ufw allow from 123.45.67.89 to any port 22 proto tcp

sudo ufw status
ufw enable
ufw disable
ufw reload
sudo ufw reset
```

# help
```shell
Usage: ufw COMMAND

Commands:
 enable                          enables the firewall
 disable                         disables the firewall
 default ARG                     set default policy
 logging LEVEL                   set logging to LEVEL
 allow ARGS                      add allow rule
 deny ARGS                       add deny rule
 reject ARGS                     add reject rule
 limit ARGS                      add limit rule
 delete RULE|NUM                 delete RULE
 insert NUM RULE                 insert RULE at NUM
 reload                          reload firewall
 reset                           reset firewall
 status                          show firewall status
 status numbered                 show firewall status as numbered list of RULES
 status verbose                  show verbose firewall status
 show ARG                        show firewall report
 version                         display version information

Application profile commands:
 app list                        list application profiles
 app info PROFILE                show information on PROFILE
 app update PROFILE              update PROFILE
 app default ARG                 set default application policy
```

# link
* https://help.ubuntu.com/community/UFW
* https://www.digitalocean.com/community/tutorials/how-to-set-up-a-firewall-with-ufw-on-ubuntu-14-04
