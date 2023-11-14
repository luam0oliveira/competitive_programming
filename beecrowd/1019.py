# -*- coding: utf-8 -*-

s = int(input())

h = s // 3600
m = (s - h * 3600 ) // 60
sp = s - h * 3600 - m * 60

print("%d:%d:%d"% (h, m, sp))