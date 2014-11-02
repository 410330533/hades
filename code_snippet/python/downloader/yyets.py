#! /usr/bin/env python
# -*- coding:utf-8 -*-

import os, sys
import re
import urllib
import urllib2
import codecs
import zipfile
from BeautifulSoup import BeautifulSoup

# 获取 yyets 下载地址
def getYyetsDownloadUrlsByResourceId(resourceId, format='HR-HDTV'):
    url = 'http://www.yyets.com/resource/%d' % (resourceId)
    f = urllib2.urlopen(url)
    soup = BeautifulSoup(''.join(f))
    for ul in soup.findAll('ul', {'class': 'resod_list'}):
        print "season %s" % ul.get('season')
        for li in ul.findAll('li'):
            if format == li.get('format'):
                for a in li.findAll('a'):
                    if u'迅雷' == a.text:
                        print a.get('thunderhref')

if __name__ == '__main__':
    resourceId = int(sys.argv[1])
    getYyetsDownloadUrlsByResourceId(resourceId)
