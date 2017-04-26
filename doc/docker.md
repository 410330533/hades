# install
```shell
https://docs.docker.com/engine/installation/linux/ubuntu/
sudo apt-get remove docker docker-engine
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

curl -L https://github.com/docker/compose/releases/download/1.12.0/docker-compose-`uname -s`-`uname -m` > /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose
docker-compose --version
```

# commands
```shell
docker build -t="saymagic/ubuntu-nginx:v2" .
docker build -f Dockerfile-redis-no-expose -t mahone3297/redis-no-expose .

docker run learn/tutorial echo 'hello world'
docker run -it ubuntu:14.04
docker run -p 80:80 saymagic/ubuntu-nginx:v2
docker run -d -p 6379 --name redis mahone3297/redis
docker run -d -p 6379 --name redis-app --link redis:db mahone3297/redis

docker tag [OPTIONS] IMAGE[:TAG] [REGISTRYHOST/][USERNAME/]NAME[:TAG]
docker tag 7d9495d03763 maryatdocker/docker-whale:latest

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
docker version
docker search redis
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
