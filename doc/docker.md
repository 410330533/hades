# install
```shell
wget -qO- https://get.docker.com/ | sh
```

# commands
```shell
docker
docker build -t="saymagic/ubuntu-nginx:v2" .
docker commit 6982a9948422 learn/ping
docker images
docker info
docker inspect efefdc74a1d5
docker login
docker logs gitlab
docker ps -l
docker ps -a
docker pull maryatdocker/docker-whale
docker push maryatdocker/docker-whale
docker rmi docker-whale
docker run learn/tutorial echo 'hello world'
docker run -it ubuntu:14.04
docker run -p 80:80 saymagic/ubuntu-nginx:v2
docker search tutoria
docker tag [OPTIONS] IMAGE[:TAG] [REGISTRYHOST/][USERNAME/]NAME[:TAG]
docker tag 7d9495d03763 maryatdocker/docker-whale:latest
docker version
```

# docker compose
```shell
https://docs.docker.com/compose/
curl -L https://github.com/docker/compose/releases/download/1.5.2/docker-compose-`uname -s`-`uname -m` > /usr/local/bin/docker-compose
chmod +x /usr/local/bin/docker-compose

curl -L https://raw.githubusercontent.com/docker/compose/$(docker-compose --version | awk 'NR==1{print $NF}')/contrib/completion/bash/docker-compose > /etc/bash_completion.d/docker-compose

docker-compose --version
```

# docker-registry
```shell
https://docs.docker.com/registry/deploying/

1. insecure registry
docker run -d -p 5000:5000 --restart=always --name registry registry:2

/etc/default/docker
DOCKER_OPTS="--insecure-registry myregistrydomain.com:5000"

2. secure registry
2.1 generate certificate
mkdir -p certs && openssl req \
  -newkey rsa:4096 -nodes -sha256 -keyout certs/domain.key \
  -x509 -days 365 -out certs/domain.crt
2.2 run container
docker run -d -p 5000:5000 --restart=always --name registry \
  -v `pwd`/certs:/certs \
  -e REGISTRY_HTTP_TLS_CERTIFICATE=/certs/domain.crt \
  -e REGISTRY_HTTP_TLS_KEY=/certs/domain.key \
  registry:2
2.3 copy
/etc/docker/certs.d/myregistrydomain.com:5000/ca.crt
```

# shadowsocks
```shell
https://hub.docker.com/r/oddrationale/docker-shadowsocks/
docker pull oddrationale/docker-shadowsocks
docker run -d -p 1984:1984 oddrationale/docker-shadowsocks -s 0.0.0.0 -p 1984 -k $SSPASSWORD -m aes-256-cfb
```

# gitlab
```shell
https://github.com/sameersbn/docker-gitlab
docker pull sameersbn/gitlab:8.3.2
docker pull sameersbn/gitlab:latest

wget https://raw.githubusercontent.com/sameersbn/docker-gitlab/master/docker-compose.yml
pwgen -Bsv1 64
docker-compose up

docker run --name gitlab-postgresql -d \
    --env 'DB_NAME=gitlabhq_production' \
    --env 'DB_USER=gitlab' --env 'DB_PASS=password' \
    --volume /srv/docker/gitlab/postgresql:/var/lib/postgresql \
    sameersbn/postgresql:9.4-11

docker run --name gitlab-redis -d \
    --volume /srv/docker/gitlab/redis:/var/lib/redis \
    sameersbn/redis:latest

docker run --name gitlab -d \
    --link gitlab-postgresql:postgresql --link gitlab-redis:redisio \
    --publish 10022:22 --publish 10080:80 \
    --env 'GITLAB_PORT=10080' --env 'GITLAB_SSH_PORT=10022' \
    --env 'GITLAB_SECRETS_DB_KEY_BASE=long-and-random-alpha-numeric-string' \
    --volume /srv/docker/gitlab/gitlab:/home/git/data \
    sameersbn/gitlab:8.3.2

backup
docker stop gitlab && docker rm gitlab
docker run --name=gitlab -it --rm [OPTIONS] \
  sameersbn/gitlab:latest app:rake gitlab:backup:create

restore
docker stop gitlab && docker rm gitlab
docker run --name=gitlab -it --rm [OPTIONS] \
  sameersbn/gitlab:latest app:rake gitlab:backup:restore
```

# link
- [Docker 简明教程](https://linux.cn/article-5686-1.html)
