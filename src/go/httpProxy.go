package main

import (
	"io"
	"io/ioutil"
	"log"
	"net/http"
)

func handler(w http.ResponseWriter, r *http.Request) {
	var (
		resp *http.Response
		data []byte
		err  error
	)

	r.RequestURI = ""
	r.ParseForm()
	resp, err = http.DefaultClient.Do(r)
	if err != nil {
		http.NotFound(w, r)
		log.Println("default client error...")
		return
	}

	for i, j := range resp.Header {
		for _, k := range j {
			w.Header().Add(i, k)
			log.Println("header:", i, "=", k)
		}
	}

	for _, c := range resp.Cookies() {
		w.Header().Add("Set-Cookie", c.Raw)
		log.Println("Set-Cookie", c.Raw)
	}

	w.WriteHeader(resp.StatusCode)
	data, err = ioutil.ReadAll(resp.Body)
	if err != nil && err != io.EOF {
		http.NotFound(w, r)
		log.Println("read body error...")
		return
	}
	log.Printf("resp.StatusCode = %d len = %d\n", resp.StatusCode, len(data))
	w.Write(data)
}

func main() {
    port := "8888"

	http.HandleFunc("/", handler)
    log.Printf("start serving on port %s\n", port)
	http.ListenAndServe(":"+port, nil)
}
