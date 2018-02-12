# docker install
```shell
https://docs.docker.com/engine/installation/linux/docker-ce/ubuntu/
sudo apt-get remove docker docker-engine docker.io
sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo apt-key fingerprint 0EBFCD88
sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
sudo apt-get update
sudo apt-get install docker-ce
apt-cache madison docker-ce
sudo apt-get install docker-ce=<VERSION>
```

# docker command
```shell
docker save alpine | gzip > alpine-latest.tar.gz
docker load -i alpine-latest.tar.gz
docker save <镜像名> | bzip2 | pv | ssh <用户名>@<主机名> 'cat | docker load'

docker export 7691a814370e > ubuntu.tar
cat ubuntu.tar | docker import - test/ubuntu:v1.0
docker import http://example.com/exampleimage.tgz example/imagerepo

docker build -t="saymagic/ubuntu-nginx:v2" .
docker build -f Dockerfile-redis-no-expose -t mahone3297/redis-no-expose .

docker tag [OPTIONS] IMAGE[:TAG] [REGISTRYHOST/][USERNAME/]NAME[:TAG]
docker tag 7d9495d03763 maryatdocker/docker-whale:latest
docker tag ubuntu:latest 127.0.0.1:5000/ubuntu:latest

docker commit 6982a9948422 learn/ping

docker images
docker image ls ubuntu
docker image ls ubuntu:16.04
docker image ls -a
docker image ls -q
docker image ls -f dangling=true
docker image ls --digests
docker image ls --format "{{.ID}}: {{.Repository}}"
docker image ls --format "table {{.ID}}\t{{.Repository}}\t{{.Tag}}"
docker image prune
docker image rm 894f9a914774
docker image rm 127.0.0.1:5000/ubuntu:latest

docker info
docker inspect efefdc74a1d5
docker login
docker logout docker.domain.com
docker logs gitlab
docker pull maryatdocker/docker-whale
docker push maryatdocker/docker-whale
docker push 127.0.0.1:5000/ubuntu:latest
docker rmi docker-whale
docker version
docker search redis

docker system df
docker system info

docker network create -d bridge my-net

docker run learn/tutorial echo 'hello world'
docker run -it ubuntu:14.04
docker run -p 80:80 saymagic/ubuntu-nginx:v2
docker run -d -p 127.0.0.1::5000 training/webapp python app.py
docker run -d -p 127.0.0.1:5000:5000/udp training/webapp python app.py
docker run -d -p 6379 --name redis mahone3297/redis
docker run -d -p 6379 --name redis-app --link redis:db mahone3297/redis
docker run -it --rm --name busybox1 --network my-net busybox sh

docker container ls
docker container prune

docker volume ls
docker volume inspect my-vol
docker volume rm my-vol
docker volume prune
```

# docker swarm
```shell
docker swarm init
docker swarm join --token SWMTKN-1-61c3i8vgfhdbkobhwl6i77g6dafbyvvo858k19nyku1q7vwx7p-59gcno33s62m384m64tv8pwot 192.168.211.136:2377
docker swarm leave --force
docker node ls
docker node rm

docker service ls
docker service ps getstartedlab_web

docker stack ls
docker stack deploy -c docker-compose.yml getstartedlab
docker stack rm getstartedlab

docker config create redis.conf redis.conf
docker config ls

docker secret ls
docker secret inspect my_password
docker secret create my_password filename
docker secret rm my_password
```

# docker compose
```shell
https://docs.docker.com/compose/
curl -L https://github.com/docker/compose/releases/download/1.5.2/docker-compose-`uname -s`-`uname -m` > /usr/local/bin/docker-compose
chmod +x /usr/local/bin/docker-compose

curl -L https://raw.githubusercontent.com/docker/compose/$(docker-compose --version | awk 'NR==1{print $NF}')/contrib/completion/bash/docker-compose > /etc/bash_completion.d/docker-compose

docker-compose --version
```

# docker registry
```shell
https://docs.docker.com/registry/deploying/

1. insecure registry
docker run -d -p 5000:5000 --restart=always --name registry registry:2
docker run -d -p 5000:5000 -v /opt/data/registry:/var/lib/registry registry

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