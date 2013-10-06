# nginx
```conf
apt-get install nginx
php
location / {
    include fastcgi_params;
    fastcgi_param SCRIPT_FILENAME $fastcgi_script_name;
    fastcgi_param PATH_INFO $fastcgi_script_name;
    fastcgi_pass 127.0.0.1:9002;
}

python
location / {
    include uwsgi_params;
    uwsgi_pass 127.0.0.1:9090;
}
```

