# nginx install
```shell
Ubuntu:
Version	Codename
10.04	lucid
12.04	precise
12.10	quantal
13.04	raring
13.10	saucy

nginx_signing.key => http://nginx.org/keys/nginx_signing.key
sudo apt-key add nginx_signing.key

deb http://nginx.org/packages/ubuntu/ codename nginx
deb-src http://nginx.org/packages/ubuntu/ codename nginx

apt-get update
apt-get install nginx
```

# configuration
- php
```conf
location / {
    include fastcgi_params;
    fastcgi_param SCRIPT_FILENAME $fastcgi_script_name;
    fastcgi_param PATH_INFO $fastcgi_script_name;
    fastcgi_pass 127.0.0.1:9002;
}
```

- python
```conf
location / {
    include uwsgi_params;
    uwsgi_pass 127.0.0.1:9090;
}
```

