import scrapy
from cn163.items import Cn163Item

class Cn163Spider(scrapy.Spider):
    name            = 'cn163'
    allowed_domains = ["cn163.net"]
    start_urls      = [
        "http://cn163.net/ddc1/",
    ]

    def parse(self, response):
        for sel in response.xpath('//*[@id="content"]/div/div/div[1]/div[2]/h2/a'):
            item = Cn163Item()
            item['url'] = sel.xpath('@href').extract()[0]
            item['title'] = sel.xpath('text()').extract()[0]
 #           print "url = %s, title = %s" % (item['url'], item['title'])
            yield item
