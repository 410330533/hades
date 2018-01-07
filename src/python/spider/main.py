#! /usr/bin/env python
# -*- coding:utf-8 -*-

import logging
import mp4ba_dot_net

if __name__ == '__main__':
    logging.basicConfig(level=logging.INFO)

    logging.info("begin...")
    c = mp4ba_dot_net.Crawler()
    c.crawl()
