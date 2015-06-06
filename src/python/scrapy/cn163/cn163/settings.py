# -*- coding: utf-8 -*-

# Scrapy settings for cn163 project
#
# For simplicity, this file contains only the most important settings by
# default. All the other settings are documented here:
#
#     http://doc.scrapy.org/en/latest/topics/settings.html
#

BOT_NAME = 'cn163'

SPIDER_MODULES = ['cn163.spiders']
NEWSPIDER_MODULE = 'cn163.spiders'

# Crawl responsibly by identifying yourself (and your website) on the user-agent
#USER_AGENT = 'cn163 (+http://www.yourdomain.com)'
# DOWNLOAD_DELAY = 2
# RANDOMIZE_DOWNLOAD_DELAY = True
USER_AGENT = 'Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.2311.90 Safari/537.36'
