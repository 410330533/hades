# go
```shell
add-apt-repository ppa:gophers/go
apt-get update
apt-get install golang-stable

下载编译包
https://storage.googleapis.com/golang/go1.4.linux-386.tar.gz
https://storage.googleapis.com/golang/go1.4.linux-amd64.tar.gz

tar -C /usr/local -xzf go$VERSION.$OS-$ARCH.tar.gz
export PATH=$PATH:/usr/local/go/bin

Installing to a custom location
export GOROOT=$HOME/go
export PATH=$PATH:$GOROOT/bin
```

# link
- [Getting Started](http://golang.org/doc/install)
- [How to Write Go Code](http://golang.org/doc/code.html)
- [Go Slices: usage and internals](http://blog.golang.org/go-slices-usage-and-internals)
