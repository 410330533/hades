import scrapy
from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors import LinkExtractor
from javdog.items import MovieItem

class Genre(CrawlSpider):
    name = 'genre'
    allowed_domains = ['javdog.com']
    start_urls = ['http://www.javdog.com/cn/genre/2x']

    def parse_start_url(self, response):
        for div in response.css('#waterfall > div'):
            a = div.css('div > div > a')
            item = MovieItem()
            item['name'] = a.xpath('text()').extract()[0]
            item['url'] = a.xpath('@href').extract()[0]
            print "name = %s, url = %s\n" % (a.xpath('text()').extract()[0], a.xpath('@href').extract()[0])
            yield item
