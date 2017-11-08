package main

import (
    "github.com/elazarl/goproxy"
    "log"
    "flag"
    "strconv"
    "strings"
    "net/http"
)

func main() {
    proxy := goproxy.NewProxyHttpServer()
    proxy.OnRequest().DoFunc(func(r *http.Request,ctx *goproxy.ProxyCtx)(*http.Request,*http.Response) {
        url := r.URL.String()

        //iseiya
        if (strings.Contains(url, "iseiya.taobao.com/athena/athenaSceneRecognize.htm")) {
            log.Printf("values = %s", r.URL.Query())
            var (
                buyerNick  = r.URL.Query().Get("msgs")
                sellerNick = r.URL.Query().Get("subUserNick")
            )
            log.Printf("iseiya buyerNick = %s, sellerNick = %s", buyerNick, sellerNick)
            // insert into mysql
        }

        // 客户
        // if (strings.Contains(url, "eco.taobao.com/router/rest")
        //     && r.Header.Get("top-api") == "taobao.crm.members.search") {
        //     var subNick = r.Header.Get("sub-nick")
        // }

        return r,nil
    })
    // proxy.Verbose = true

    var port = flag.Int("port", 8080, "port")
    flag.Parse()

    log.Printf("server start at %d", *port)
    log.Fatal(http.ListenAndServe(":"+strconv.Itoa(*port), proxy))
}
