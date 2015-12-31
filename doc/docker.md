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
```

# link
- [Docker 简明教程](https://linux.cn/article-5686-1.html)
