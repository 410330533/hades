#! /usr/bin/env python
# -*- coding:utf-8 -*-

import os, sys
import re
import urllib
import urllib2
import codecs
import zipfile
from BeautifulSoup import BeautifulSoup

# 下载 http://www.ppmsg.com 图片
def download_5542_pic(url):
    timeout = 30
    host = 'http://www.ppmsg.com'
    url_array = url.replace(host, '').replace('.html', '').strip('/').split('/')
    
    # 新建目录
    try:
        os.makedirs('/'.join(url_array))
    except OSError, e:
        pass
    
    # 获取总页数
    f = unicode(urllib2.urlopen(url, None, timeout).read(), 'gbk', 'ignore').encode('utf-8', 'ignore')
    soup = BeautifulSoup(''.join(f))
    totalPage = int(soup.find('ul', {'class': 'image'}).find('strong').string)
    # 获取 title
    title = soup.find('div', {'class': 'title'}).find('h2').string
    open('/'.join(url_array) + '/' + title, 'w').write(url)
    
    curPage = 1
    while (curPage <= totalPage):
        # 下载每页n张图
        i = 0;
        for item in soup.find('ul', {'class': 'file'}).findAll('img'):
            i += 1
            file_name = '/'.join(url_array) + '/' +  str(curPage) + '_' + str(i) + '.jpg'
            if (os.path.exists(file_name)): continue
            
            try:
                open(file_name, 'w').write(urllib2.urlopen(item.attrs[0][1], None, timeout). read())
            except Exception, e:
                print('exception occur')
            print('    download file: ' + file_name + ', done.')
        print('totalPage ' + str(totalPage) + ', downloaded page ' + str(curPage) + ', done.')
        
        curPage += 1
        f = unicode(urllib2.urlopen(url.replace('.html', '_' + str(curPage) + '.html'), None, timeout).read(), 'gbk', 'ignore').encode('utf-8', 'ignore')
        soup = BeautifulSoup(''.join(f))

if __name__ == '__main__':
    #url = 'http://www.ppmsg.com/siwameitui/201410/23776.html'
    url = sys.argv[1];
    download_5542_pic(url)
