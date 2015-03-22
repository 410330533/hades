#! /usr/bin/env python
# -*- coding:utf-8 -*-

# 设一组数p = {r1, r2, r3, ... ,rn}, 全排列为perm(p)，pn = p - {rn}。
# 因此perm(p) = r1perm(p1), r2perm(p2), r3perm(p3), ... , rnperm(pn)。当n = 1时perm(p} = r1。

import sys
import glob
import os

if __name__=='__main__':
    src_path = 'D:\TDDOWNLOAD\青城'
    replace_old = '{有声下吧www.Ysx8.com}'
    replace_new = ''
    for i in glob.glob(os.path.join(src_path, '*.mp3')):
        os.rename(i, i.replace(replace_old, replace_new))
    
    print('end...')