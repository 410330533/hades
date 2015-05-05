from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors import LinkExtractor
from cn163.items import Cn163Item

class Cn163Spider(CrawlSpider):
    name = 'cn163'
    allowed_domains = ["cn163.net"]
    start_urls = [
        "http://cn163.net/ddc1/",
    ]
    rules = [Rule(LinkExtractor(allow=['/archives/\d+']), 'parse_content')]

    def parse_content(self, response):
        item = Cn163Item()
        item['url'] = response.url
        item['title'] = response.xpath('//*[@id="content"]/div[2]/div[2]/h2/text()').extract()
        return item
