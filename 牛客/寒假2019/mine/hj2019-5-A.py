# -*- coding: utf-8 -*-
"""
Created on Thu Jan 31 16:04:28 2019

@author: Administrator
没有通过全部测试用例,不知道为啥
"""
import math
l1,l2=map(float,input().split())
R=l1+l2
R2=R**2

r=l1-l2

t=int(input())
while(t!=0):
    t-=1
    x,y=map(float,input().split())
    R2_=x**2+y**2
    if(R2_<=R2): # 大圈里面
        if(l2>=l1 or r**2<=R2_): # l2更长或在小圈外面
            print("0")
            continue
    R_=math.sqrt(R2_)
    if(R2_>R2):
        print('%.8f'%abs(R_-R))
    else:
        print('%.8f'%abs(r-R_))
    