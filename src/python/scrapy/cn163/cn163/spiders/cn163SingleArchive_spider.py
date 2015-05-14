import scrapy
from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors import LinkExtractor
#from cn163.items import Cn163Item

class Cn163SingleArchiveSpider(CrawlSpider):
    name = 'cn163SingleArchive'
    allowed_domains = ['cn163.net']
    start_urls = [
        'http://cn163.net/archives/1293/',
        'http://cn163.net/archives/1292/',
        'http://cn163.net/archives/17530/',
    ]

    def parse_start_url(self, response):
        for a in response.xpath('//*[@id="entry"]/ol/li/a'):
 #           print a.xpath('text()').extract()[0]
            print a.xpath('@href').extract()[0]
