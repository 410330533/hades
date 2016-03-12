# user
```shell
useradd -m -g [initial_group] -G [additional_groups] -s [login_shell] [username]

usermod -s /bin/bash -l oldname newname
usermod -aG additional_groups username
usermod -aG docker your-user

userdel -r mahone

passwd mahone
```

# group
```shell
groupadd mahone

groupmod -g 1001 -n new old

groupdel mahone

gpasswd groupname
```

