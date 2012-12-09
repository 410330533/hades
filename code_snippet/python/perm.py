#! /usr/bin/env python
# -*- coding:utf-8 -*-

# 设一组数p = {r1, r2, r3, ... ,rn}, 全排列为perm(p)，pn = p - {rn}。
# 因此perm(p) = r1perm(p1), r2perm(p2), r3perm(p3), ... , rnperm(pn)。当n = 1时perm(p} = r1。

import sys

# 在lst中各个位置插入ch，返回各种插入后结果的一个list
def insert(lst, ch):
    retLst = []
    if len(lst) == 0:
       retLst.append(ch)
    else:
        for i in range(len(lst)):
            tmpStr = lst[i]
            for j in range(len(tmpStr) + 1):
                str = tmpStr[:j] + ch + tmpStr[j:]
                retLst.append(str)
    
    return retLst

# 全排列算法，输入lst，返回全排列list
def perm(lst):
    retLst = []
    for ch in lst:
        retLst = insert(retLst, ch)
    
    return retLst

if __name__=='__main__':
    str = '123'
    lst = perm(str)
    for tmp in lst:
        print(tmp)
    print('total: %d' % len(lst))
    
    print('end...')