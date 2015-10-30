# go
```shell
下载编译包
https://storage.googleapis.com/golang/go1.5.1.src.tar.gz
https://storage.googleapis.com/golang/go1.5.1.darwin-amd64.tar.gz
https://storage.googleapis.com/golang/go1.5.1.darwin-amd64.pkg
https://storage.googleapis.com/golang/go1.5.1.freebsd-amd64.tar.gz
https://storage.googleapis.com/golang/go1.5.1.linux-386.tar.gz
https://storage.googleapis.com/golang/go1.5.1.linux-amd64.tar.gz
https://storage.googleapis.com/golang/go1.5.1.windows-386.zip
https://storage.googleapis.com/golang/go1.5.1.windows-386.msi
https://storage.googleapis.com/golang/go1.5.1.windows-amd64.zip
https://storage.googleapis.com/golang/go1.5.1.windows-amd64.msi

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
