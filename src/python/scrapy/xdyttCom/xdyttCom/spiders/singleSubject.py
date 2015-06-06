# -*- coding: utf8 -*-

import scrapy
from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors import LinkExtractor
from xdyttCom.items import XdyttcomItem

# scrapy crawl singleSubject -a subjectIds=11870
class SingleSubject(CrawlSpider):
    name = 'singleSubject'
    allowed_domains = ['xdytt.comt']
    start_urls = []

    def __init__(self, subjectIds, *args, **kwargs):
        super(SingleSubject, self).__init__(*args, **kwargs)
        for subjectId in subjectIds.split(','):
            self.start_urls.append('http://www.xdytt.com/subject/%d.html' % int(subjectId))

    def parse_start_url(self, response):
        title = response.css('body > div.container.contentmain > div > div > div:nth-child(1) > h1').xpath('text()').extract()[0].encode('utf8')
        downloadLinks = response.css('#torrent a')
        filename = '%s_%s.link' % (title.replace("'", '').replace(' ', '').replace(':', ''), response.url.split('/')[-1].replace('.html', ''))
        with open(filename, 'w') as f:
           for a in downloadLinks:
                f.write("%s\n" % a.xpath('@href').extract()[0].encode('utf8'))

        item = XdyttcomItem()
        item['url']           = response.url
        item['title']         = title
        item['brief']         = "\n".join(response.css('#content > p').xpath('text()').extract())
        item['downloadLinks'] = downloadLinks.xpath('@href').extract()
        yield item
