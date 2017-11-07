package main

import (
	"database/sql"
	_ "github.com/go-sql-driver/mysql"
	"io/ioutil"
	"log"
	"net/http"
)

func req(c chan int) {
	url := "http://www.verycd.com/sto/music/"
	resp, err := http.Get(url)
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}
	content := string(body)

	db, err := sql.Open("mysql", "mahone:taobao@/test")
	if err != nil {
		log.Fatal(err)
	}
	defer db.Close()

	stmt, err := db.Prepare("insert into verycd_sto_music(url, content) values(?, ?)")
	if err != nil {
		log.Fatal(err)
	}
	_, err = stmt.Exec(url, content)
	if err != nil {
		log.Fatal(err)
	}

	c <- 1
}

func main() {
	log.Println("download verycd start....")

	c := make(chan int)
	go req(c)
	<-c

	log.Println("download verycd end....")
}
