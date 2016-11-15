#! /usr/bin/env python
# -*- coding:utf-8 -*-

import sys
import glob
from os.path import join, basename, exists
from os import mkdir, chdir, rename

if __name__=='__main__':
    srcPath = 'E:\photo\meilanNote_photo'
    chdir(srcPath)
    
    for f in glob.glob(join(srcPath, '*.gif')):
        name = basename(f)
        k = '201'+name[1:6]
        if not exists(k):
            mkdir(k)
        rename(name, join(k, name))
    
    print('end...')