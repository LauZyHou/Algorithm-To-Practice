# -*- coding: utf-8 -*-
"""
Created on Tue Jan 29 14:26:31 2019

@author: Administrator
"""
#import cmath
import math

a, b, n = map(float, input().split())
#print(a,b,n)
c=a*a+b*b+2*a*b*math.cos(n*math.pi/180)
#print(c)
s=math.sqrt(c)
print(s)