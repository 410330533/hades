from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors import LinkExtractor
from cn163.items import Cn163CrawlItem

class Cn163WholeSiteSpider(CrawlSpider):
    name = 'cn163WholeSite'
    allowed_domains = ['cn163.net']
    start_urls = ['http://cn163.net/ddc1/']

    rules = (
        Rule(LinkExtractor(allow=('/ddc1/page/\d+/'))),
        Rule(LinkExtractor(allow=('/archives/\d+/')), callback='parse_archives'),
    )

    def parse_archives(self, response):
        item = Cn163CrawlItem()
        item['url']     = response.url
        item['title']   = response.xpath('//*[@id = "content"]/div[2]/div[2]/h2/text()').extract()[0]

        for a in response.xpath('//*[@id="entry"]/p/a'):
            print '==================='
            print a.xpath('text()').extract()[0]
            print a.xpath('@href').extract()[0]
            print '--------------------'

        yield item
