# -*- coding: utf-8 -*-
import scrapy
from geekCsdnNet.items import GeekcsdnnetItem

class GrabindexSpider(scrapy.Spider):
    name = "grabIndex"
    allowed_domains = ["geek.csdn.net"]
    start_urls = (
        'http://geek.csdn.net/',
    )

    def parse(self, response):
        for li in response.css('body > div.mian.clearfix > div.left.fl > div.content > ul > li'):
            item = GeekcsdnnetItem()
            titleA = li.css('div.content_info > h4 > a')
            tagA = li.css('div.content_info > div.g_tag > a')
            item['url'] = titleA.xpath('@href').extract()[0]
            item['title'] = titleA.xpath('text()').extract()[0]
            item['tags'] = tagA.xpath('text()').extract()
            yield item
