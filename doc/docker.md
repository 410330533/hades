# install
```shell
wget -qO- https://get.docker.com/ | sh
sudo docker run hello-world
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
docker ps -l
docker ps -a
docker pull learn/tutorial
docker push learn/ping
docker run learn/tutorial echo 'hello world'
docker run -it ubuntu:14.04
docker run -p 80:80 saymagic/ubuntu-nginx:v2
docker search tutoria
docker version
```

# link
- [Docker 简明教程](https://linux.cn/article-5686-1.html)
