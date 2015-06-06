# -*- coding: utf8 -*-

import scrapy
from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors import LinkExtractor

# scrapy crawl cn163SingleArchive -a archiveIds=17663
class Cn163SingleArchiveSpider(CrawlSpider):
    name = 'cn163SingleArchive'
    allowed_domains = ['cn163.net']
    start_urls = []

    def __init__(self, archiveIds, *args, **kwargs):
        super(Cn163SingleArchiveSpider, self).__init__(*args, **kwargs)
        for archiveId in archiveIds.split(','):
            self.start_urls.append('http://cn163.net/archives/%d/' % int(archiveId))

    def parse_start_url(self, response):
        title = response.css('#content > div.entry_box_s > div.entry_title_box > h2').xpath('text()').extract()[0].encode('utf8')
        title = title.replace('/', '').replace(' ', '').replace(':', '').replace('：', '')
        filename = '%s_%s.link' % (title, response.url.split('/')[-2])
        with open(filename, 'w') as f:
            for a in response.xpath('//*[@id="entry"]//a'):
                f.write("%s\n" % (a.xpath('@href').extract()[0].encode('utf8')))
