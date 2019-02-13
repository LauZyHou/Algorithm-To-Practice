# -*- coding: utf-8 -*-
"""
Created on Thu Jan 31 16:55:58 2019

@author: Administrator
群里老哥说的方法:判断是否形成三角形
不形成就大边-小1-小2
"""

import math
l1,l2=map(float,input().split())

t=int(input())
while(t!=0):
    t-=1
    x,y=map(float,input().split())
    l3=math.sqrt(x**2+y**2)
    if(l1+l2>l3 and l2+l3>l1 and l3+l1>l2):
        print(0)
    else:
        a=[l1,l2,l3]
        a.sort(reverse=True)
        print(a[0]-a[1]-a[2])