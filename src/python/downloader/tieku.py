#! /usr/bin/env python
# -*- coding:utf-8 -*-

import os, sys
import re
import urllib
import urllib2
import codecs
import zipfile
from BeautifulSoup import BeautifulSoup

# 贴库小说下载
def download_tiekuzip_by_tid(tid):
    timeout = 5
    title = ''
    # download page url
    url = 'http://www.tieku.org/download.php?tid=%s' % tid
    
    # get title by tid
    f = unicode(urllib2.urlopen(url, None, timeout).read(), 'gbk', 'ignore').encode('utf-8', 'ignore')
    soup = BeautifulSoup(''.join(f))
    for item in soup.find('table', {'id': 'dh'}).findAll('a', attrs={'href': re.compile('\/\d')}):
        title = item.string
    
    # get download file path
    # url = 'http://www.tieku.org/gettxturl.php?tid=%s' % tid
    # f = unicode(urllib2.urlopen(url, None, timeout).read(), 'gbk', 'ignore').encode('utf-8', 'ignore')
    # soup = BeautifulSoup(''.join(f))
    
    # download
    # remote_path = 'http://www.tieku.org' + soup.find('a')['href']
    remote_path = 'http://www.tieku.org' + '/txt/' + tid[0:3] + '/' + tid + '/' + tid + '.zip'
    local_path = tid + '_' + title
    open(local_path+'.zip', 'w').write(urllib2.urlopen(remote_path, None, timeout).read())
    
    # unzip
    z = zipfile.ZipFile(local_path+'.zip', mode='r')
    open(local_path+'.txt', 'w').write(unicode(z.read(tid + '.txt'), 'gbk', 'ignore').encode('utf-8', 'ignore'))
    # rm zip file
    os.remove(local_path+'.zip')

if __name__ == '__main__':
    #tid = 160401
    #tid = sys.argv[1].strip('/')
    #download_tiekuzip_by_tid(tid)
