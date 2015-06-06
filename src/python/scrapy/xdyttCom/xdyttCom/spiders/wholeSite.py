# -*- coding: utf8 -*-

from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors import LinkExtractor
from xdyttCom.items import XdyttcomItem

# scrapy crawl wholeSite
class WholeSiteSpider(CrawlSpider):
    name = 'wholeSite'
    allowed_domains = ['xdytt.com']
    start_urls = ['http://www.xdytt.com/?item=movie']

    rules = (
        Rule(LinkExtractor(allow=('/page/\d+\?item=movie'))),
        Rule(LinkExtractor(allow=('/subject/\d+\.html')), callback='parse_subject'),
    )

    def parse_subject(self, response):
        title = response.css('body > div.container.contentmain > div > div > div:nth-child(1) > h1').xpath('text()').extract()[0].encode('utf8')
        downloadLinks = response.css('#torrent a')
        filename = '%s_%s.link' % (title.replace("'", '').replace(' ', '').replace(':', ''), response.url.split('/')[-1].replace('.html', ''))
        with open(filename, 'w') as f:
           for a in downloadLinks:
                f.write("%s\n" % a.xpath('@href').extract()[0].encode('utf8'))

        item = XdyttcomItem()
        item['url']           = response.url
        item['title']         = title
        item['brief']         = "\n".join(response.css('#content > p').xpath('text()').extract())
        item['downloadLinks'] = downloadLinks.xpath('@href').extract()
        yield item

