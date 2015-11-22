package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
)

func req(c chan int) {
	resp, err := http.Get("http://www.verycd.com/sto/music/china/")
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(string(body))
	c <- 1
}

func main() {
	log.Println("download verycd start....")

	c := make(chan int)
	go req(c)
	<-c

	log.Println("download verycd end....")
}
