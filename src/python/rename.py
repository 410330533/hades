#! /usr/bin/env python
# -*- coding:utf-8 -*-

import sys
import glob
from os.path import join, basename, exists
from os import mkdir, chdir, rename
from shutil import rmtree, move, copy, copytree

# def rename_files(ext):
#     i =  0
#     for f in glob.glob('*.' + ext):
#         name = basename(f)
#         d = '201'+name[1:6]
#         if not exists(d):
#             mkdir(d)
#         rename(name, join(d, name))

#         i += 1
#         print("%d rename from %s, to %s" % (i, name, join(d, name)))

def replace_filename():
    for f in glob.glob('**/*.*', recursive=True):
        old = f
        new = f.replace('【可乐美剧】','')
        print('old = %s, new = %s' % (old, new))
        rename(old, new)

def mv_ml_photo(dir):
    for f in glob.glob(dir + '*.jpg'):
        old = f
        new = 'DCIMP/' + basename(f)

        print('old = %s, new = %s' % (old, new))
        rename(old, new)

    for d in ('.Gif', '100ANDRO', 'Burst', 'Panorama'):
        path = dir + d
        if exists(path):
            print('rmtree dir ' + path)
            rmtree(path)

def mv_xiaomi_photo(ext):
    i = 1
    for f in glob.glob('*.' + ext):
        date = f.split('_')[1]
        if not exists(date):
            mkdir(date)

        old = f
        new = '%s/%s' % (date, f)
        rename(old, new)
        print('i = %d, old = %s, new = %s' % (i, old, new))
        i += 1

if __name__=='__main__':
    srcPath = sys.argv[1]
    chdir(srcPath)

    for ext in ('jpg', 'mp4'):
        mv_xiaomi_photo(ext)

    print('end...')