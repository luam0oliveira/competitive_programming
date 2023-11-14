# -*- coding: utf-8 -*-

a,b,c = [int(i) for i in input().split()]

s = (a + b + c) / 2

a = (s * (s-a)*(s-b)*(s-c))** 0.5

print("%.3f m2" %a)
