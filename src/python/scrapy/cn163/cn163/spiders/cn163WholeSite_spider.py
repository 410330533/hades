# -*- coding: utf8 -*-

from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors import LinkExtractor
from cn163.items import Cn163CrawlItem

# scrapy crawl cn163WholeSite
class Cn163WholeSiteSpider(CrawlSpider):
    name = 'cn163WholeSite'
    allowed_domains = ['cn163.net']
    start_urls = ['http://cn163.net/ddc1/']

    rules = (
        Rule(LinkExtractor(allow=('/ddc1/page/\d+/'))),
        Rule(LinkExtractor(allow=('/archives/\d+/')), callback='parse_archives'),
    )

    def parse_archives(self, response):
        title = response.css('#content > div.entry_box_s > div.entry_title_box > h2').xpath('text()').extract()[0].encode('utf8')
        title = title.replace('/', '').replace(' ', '').replace(':', '').replace('：', '')
        filename = '%s_%s.link' % (title, response.url.split('/')[-2])
        with open(filename, 'w') as f:
            for a in response.xpath('//*[@id="entry"]//a'):
                f.write("%s\n" % (a.xpath('@href').extract()[0].encode('utf8')))

        item = Cn163CrawlItem()
        item['url']   = response.url
        item['title'] = title
        item['downloadLinks'] = response.xpath('//*[@id="entry"]//a/@href').extract()
        yield item
