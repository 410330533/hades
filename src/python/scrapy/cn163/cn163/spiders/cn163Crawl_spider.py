import scrapy
from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors import LinkExtractor

class Cn163CrawlSpider(CrawlSpider):
    name = 'cn163Crawl'
    allowed_domains = ['cn163.net']
    start_urls = ['http://cn163.net/ddc1/']

    rules = (
        Rule(LinkExtractor(allow=))
    )
