# get
```shell
curl http://www.baidu.com/s?wd=curl
```

# post
```shell
curl -d "name=test&page=1" http://www.baidu.com
```

# 只显示 header
```shell
curl -I  http://www.baidu.com
```

# 添加 header
```shell
curl --header "Content-Type:application/json" http://example.com
```

# 显示通信过程
```shell
curl -v www.baidu.com
curl --trace output.txt www.baidu.com
curl --trace-ascii output.txt www.baidu.com
```

# http method
```shell
curl -X POST www.example.com
curl -X DELETE www.example.com
```

# referer
```shell
curl --referer http://www.example.com http://www.example.com
```

# user agent
```shell
curl --user-agent "[User Agent]" [URL]
```

# link
- [使用curl来调试你的应用](http://segmentfault.com/blog/stormzhang/1190000002393107?utm_source=weekly&utm_medium=email&utm_campaign=email_weekly)
