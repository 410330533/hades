#! /usr/bin/env python
# -*- coding:utf-8 -*-

import threading
import time

class Producer(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
    
    def run(self):
        i=0
        while True and i<5:
            print('i am producing')
            time.sleep(1)
            i += 1

if __name__ == '__main__':
    p = Producer()
    
    p.start()
    p.join()
    
    print('end...')