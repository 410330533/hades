import scrapy
from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors import LinkExtractor
from cn163.items import Cn163CrawlItem

class Cn163CrawlSpider(CrawlSpider):
    name = 'cn163Crawl'
    allowed_domains = ['cn163.net']
    start_urls = ['http://cn163.net/bbcjilu/']

    rules = (
        Rule(LinkExtractor(allow=('/ddc1/page/\d+/'))),
        Rule(LinkExtractor(allow=('/archives/\d+/')), callback='parse_archives'),
    )

    def parse_archives(self, response):
        item = Cn163CrawlItem()
        item['url']     = response.url
        item['title']   = response.xpath('//*[@id = "content"]/div[2]/div[2]/h2/text()').extract()
        item['info']    = response.xpath('//*[@id = "content"]/div[2]/div[2]/div[2]')
        item['content'] = response.xpath('//*[@id = "content"]/div[2]/div[3]')
        return item
