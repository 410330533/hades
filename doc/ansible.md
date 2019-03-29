# ref

https://docs.ansible.com/

# ansible ad-hoc
```
ansible app14* --list-hosts
ansible '*app*' --list-hosts
ansible '192.168.7.201:192.168.7.254' --list-hosts
ansible 'test3:&test' --list-hosts
ansible 'test3:!test' --list-hosts
ansible '~[67]-(db|dns).*\.hunk.*' --list-hosts

ansible app14* -m ping

ansible app14* -m command -a 'ls -l /home'

ansible app14* -m shell -a 'ls -l /home'
ansible app14* -m shell -a 'ls -l /home | grep username'

ansible app14* -m script -a './df.sh'

ansible app14* -m copy -a 'src=df.sh dest=/tmp/dfx.sh'

ansible app14* -m fetch -a 'src=/var/log/lastlog dest=./'

ansible app14* -m file -a 'path=/app/dir2/abc.txt state=touch mode=0666 owner=ftp'
ansible app14* -m file -a 'path=/app/dir2/dir3/dir4 state=directory mode=0666 owner=ftp'
ansible app14* -m file -a 'path=/app/abc.txt state=link src=/app/dir2/abc.txt'

ansible app14* -m hostname -a 'name=6-dns-1.hunk.tech'

ansible app14* -m cron -a 'name="test cron job" job="/bin/echo hello world >> /tmp/cron.log"'
ansible app14* -m cron -a 'disabled=yes name=None minute=*/3 job="/usr/bin/wall hello world"'
ansible app14* -m cron -a 'state=absent name=None'

ansible app14* -m yum -a 'name=tree state=present'
ansible app14* -m yum_repository -a 'state=present name=epel enabled=yes gpgcheck=yes description="Aliyun EPEL" baseurl="http://mirrors.aliyun.com/epel/6/$basearch,http://mirrors.aliyuncs.com/centos/$releasever/os/$basearch/" gpgkey="https://mirrors.aliyun.com/epel/RPM-GPG-KEY-EPEL-6Server"'

ansible app14* -m service -a 'name=httpd state=started'

ansible app14* -m setup -a 'filter=ansible_distribution_version' --tree /tmp/

ansible db -m user -a 'name=hunk4 shell=/sbin/nologin system=yes comment="name is hunk"'
ansible db -m user -a 'name=hunk4 state=present comment="hunk is my"'
ansible db -m user -a 'name=hunk4 state=absent'
ansible db -m user -a 'name=hunk3 state=absent remove=yes'

ansible dns -m get_url -a 'dest=/app/ url="https://github.com/bennojoy/nginx/archive/master.zip"'
ansible dns -m get_url -a 'dest=/app/ELS.txt checksum=sha1:8c9e20bd25525c3ed04ebaa407097fe875f02b2c url="ftp://172.18.0.1/pub/Files/ELS.txt" force=yes'
```

# ansible-playbook
```
ansible-playbook -i hosts -l app14 setup_machine.yml
```

# install
```
apt-get install software-properties-common
apt-add-repository ppa:ansible/ansible
apt-get update
apt-get install ansible
```
