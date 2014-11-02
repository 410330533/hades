#! /usr/bin/env python
# -*- coding:utf-8 -*-

import os, sys
import re
import urllib
import urllib2
import codecs
import zipfile
from BeautifulSoup import BeautifulSoup

# 获取 verycd 音乐下载地址
def get_verycd_music_address(topic_id):
    timeout = 10
    host = 'http://www.verycd.com';
    url = host + '/topics/' + topic_id
    download_file_map = {}
    search_file_addr = ''
    
    # 打开 topic 页面，得到搜索页面地址信息
    f = urllib2.urlopen(url, None, timeout).read()
    soup = BeautifulSoup(''.join(f))
    for item in soup.find('div', {'class': 'emulemain'}).findAll('a'):
        if (item.text == u'搜索下载'): continue
        download_file_map[item.text] = ''
        search_file_addr = item['href']
    
    # 打开搜索页面，得到下载页面地址信息
    f = urllib2.urlopen(search_file_addr, None, timeout).read()
    soup = BeautifulSoup(''.join(f))
    for item in soup.findAll('a', {'class': 'txt_align_con'}):
        if item.text in download_file_map:
            download_file_map[item.text] = host + item['href']
    # 范晓萱.-.[Rain].专辑.(ape).cue http://www.verycd.com/files/9e147a218cb5887afaf0b5597c1f80761152/
    
    # 1.打开下载页面，下载
    # for filename in download_file_map:
        # f = urllib2.urlopen(download_file_map[filename], None, timeout).read()
        # soup = BeautifulSoup(''.join(f))
        # download_file_map[filename] = soup.find('input', {'class': 'downloadButton'})['name']
    
    # 2.根据一些规则转换，免去再测访问页面，提高效率
    # 范晓萱.-.[Rain].专辑.(ape).cue http://www.verycd.com/files/9e147a218cb5887afaf0b5597c1f80761152/
    # ed2k://|file|%E8%8C%83%E6%99%93%E8%90%B1.-.%5BRain%5D.%E4%B8%93%E8%BE%91.%28ape%29.cue|1152|9e147a218cb5887afaf0b5597c1f8076|/
    for filename in download_file_map:
        sign = download_file_map[filename].encode('utf-8', 'ignore').strip('/').split('/')[-1]
        download_file_map[filename] = 'ed2k://|file|' + urllib.quote(filename.encode('utf-8', 'ignore')) + '|' + sign[32:] + '|' + sign[0:32] + '|/'
    
    for item in download_file_map:
        print('%s %s' % (item.encode('utf-8', 'ignore'), download_file_map[item]))


if __name__ == '__main__':
    # topic_id = '139356/'
    #topic_id = sys.argv[1].strip('/')
    #get_verycd_music_address(topic_id)
