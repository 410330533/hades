#! /usr/bin/env python
# -*- coding:utf-8 -*-

import logging
import urllib.request
from bs4 import BeautifulSoup

class Crawler:
    host = 'http://www.mp4ba.net/'
    userAgent = 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.89 Safari/537.36'
    timeout = 30

    def __init__(self):
        pass

    def fetch(self, path):
        url = Crawler.host + path
        logging.info('crawl from mp4ba, url = %s' % (url))
        headers = {
            'User-Agent' : Crawler.userAgent
        }
        req = urllib.request.Request(url = url, headers = headers)
        resp = urllib.request.urlopen(req)

        # s = resp.read().decode('utf-8', errors='replace')
        # f = open('mp4ba.html', 'w+')
        # f.write(s)
        # f.close()

        return BeautifulSoup(resp.read(), 'html.parser')

    def crawl(self):
        for i in range(1, 4):
            logging.info('--------------------')
            soup = self.fetch('forum-mp4ba-%i.html' % (i))
            self.parse_by_list(soup)

    def parse_by_list(self, soup):
        # for a in soup.find(id='threadlist').find_all('a', class_="s xst"):
        for a in soup.select('#threadlist a.s'):
            logging.info(a)
            logging.info("href = %s, text = %s" % (a['href'], a.text))