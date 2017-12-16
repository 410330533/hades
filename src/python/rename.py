#! /usr/bin/env python
# -*- coding:utf-8 -*-

import sys
import glob
from os.path import join, basename, exists
from os import mkdir, chdir, rename

def rename_files(ext):
    i =  0
    for f in glob.glob('*.' + ext):
        name = basename(f)
        d = '201'+name[1:6]
        if not exists(d):
            mkdir(d)
        rename(name, join(d, name))

        i += 1
        print("%d rename from %s, to %s" % (i, name, join(d, name)))

if __name__=='__main__':
    srcPath = sys.argv[1]
    chdir(srcPath)

    for ext in ['jpg', 'mp4']:
        rename_files(ext)

    print('end...')