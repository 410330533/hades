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
location ~ \.php$ {
    include fastcgi_params;
    fastcgi_split_path_info ^(.+\.php)(/.+)$;
    fastcgi_pass 127.0.0.1:9000;
    fastcgi_index index.php;

    fastcgi_param SCRIPT_FILENAME $fastcgi_script_name;
    fastcgi_param PATH_INFO $fastcgi_script_name;
}
```

- python
```conf
location / {
    include uwsgi_params;
    uwsgi_pass 127.0.0.1:9090;
}
```

- proxy
```conf
location / {
    proxy_pass http://www.google.com;
    proxy_redirect off;
    proxy_set_header X-Real-IP $remote_addr;
    proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
}
```

# link
- [玩转 nginx 反向代理 Google](http://hack0nair.me/2014-10-25-how-to-setup-reverse-proxy-by-nginx/)
- [Nginx 战斗准备：优化指南](https://linux.cn/article-5265-1.html)
