#! /usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os
import time
from mechanize import Browser
# mechanize 示例

def fetch():
    br = Browser()                # Create a browser
    map = {};
    
    # br.open(login_url)            # Open the login page
    # br.select_form(id="signform")  # Find the login form
    # br['username'] = username     # Set the form values
    # br['password'] = password
    # resp = br.submit()            # Submit the form
    
    br.open('http://www.verycd.com/sto/music/china/')
    nice_links = [l for l in br.links()
                    if 'topics' in l.url]
    if not nice_links:
        return None
    
    for link in nice_links:
        if link.url in map.keys():
            continue
        
        try:
            response = br.follow_link(link)
            map[link.url] = br.title()
        except Exception, e:
            print >> sys.stderr, e
    
    return map;

if __name__ == '__main__':
    map = fetch()
    for i in map:
        print "%s - %s" % (i, map[i])
