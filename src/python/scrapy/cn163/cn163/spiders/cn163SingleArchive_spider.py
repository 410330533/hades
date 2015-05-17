import scrapy
from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors import LinkExtractor
#from cn163.items import Cn163Item

class Cn163SingleArchiveSpider(CrawlSpider):
    name = 'cn163SingleArchive'
    allowed_domains = ['cn163.net']
    start_urls = []

    def __init__(self, archiveIds, *args, **kwargs):
        super(Cn163SingleArchiveSpider, self).__init__(*args, **kwargs)
        for archiveId in archiveIds.split(','):
            self.start_urls.append('http://cn163.net/archives/%d/' % int(archiveId))

    def parse_start_url(self, response):
        filename = '%s.links' % response.url.split('/')[-2]
        with open(filename, 'wb') as f:
            for a in response.xpath('//*[@id="entry"]//a'):
                f.write("%s\n" % (a.xpath('@href').extract()[0].encode('utf8')))
#           print a.xpath('text()').extract()[0]
#           print a.xpath('@href').extract()[0]
