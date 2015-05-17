import scrapy
from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors import LinkExtractor
#from cn163.items import Cn163Item

class Cn163SingleArchiveSpider(CrawlSpider):
    name = 'cn163SingleArchive'
    allowed_domains = ['cn163.net']
    start_urls = [
        'http://cn163.net/archives/1714/',
        'http://cn163.net/archives/3359/',
    ]

    def parse_start_url(self, response):
        filename = '%s.links' % response.url.split('/')[-2]
        with open(filename, 'wb') as f:
            for a in response.xpath('//*[@id="entry"]//a'):
                f.write("%s\n" % (a.xpath('@href').extract()[0].encode('utf8')))
#           print a.xpath('text()').extract()[0]
#           print a.xpath('@href').extract()[0]
