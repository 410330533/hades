#! /usr/bin/env python
# -*- coding:utf-8 -*-

import os, sys
import re
import urllib
import urllib2
import codecs
import zipfile
from BeautifulSoup import BeautifulSoup

timeout = 5

# 贴库小说下载
def download_tiekuzip_by_tid(tid):    
    # timeout = 5
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
    # tid = 160401
    # tid = sys.argv[1].strip('/')
    # download_tiekuzip_by_tid(tid)
    
    #url = 'http://www.ppmsg.com/siwameitui/201410/23776.html'
    url = sys.argv[1];
    download_5542_pic(url)
    
    # topic_id = '139356/'
    #topic_id = sys.argv[1].strip('/')
    #get_verycd_music_address(topic_id)

    #resourceId = int(sys.argv[1])
    #getYyetsDownloadUrlsByResourceId(resourceId)
