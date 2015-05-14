import scrapy
#from cn163.items import Cn163Item

class Cn163SingleArchiveSpider(scrapy.Spider):
    name = 'cn163SingleArchive'
    allowed_domains = ['cn163.net']
    start_urls = [
        'http://cn163.net/archives/1461/',
        'http://cn163.net/archives/1468/',
        'http://cn163.net/archives/1467/',
        'http://cn163.net/archives/1466/',
    ]

    def parse(self, response):
        for a in response.xpath('//*[@id="entry"]/ol/li/a'):
 #           print a.xpath('text()').extract()[0]
            print a.xpath('@href').extract()[0]
