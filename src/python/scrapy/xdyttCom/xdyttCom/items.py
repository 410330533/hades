# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class XdyttcomItem(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    url           = scrapy.Field()
    title         = scrapy.Field()
    scriptWriter  = scrapy.Field()
    director      = scrapy.Field()
    leadingActor  = scrapy.Field()
    country       = scrapy.Field()
    releaseYear   = scrapy.Field()
    genre         = scrapy.Field()
    addAt         = scrapy.Field()
    brief         = scrapy.Field()
    downloadLinks = scrapy.Field()
