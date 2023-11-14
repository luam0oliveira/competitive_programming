# -*- coding: utf-8 -*-

n = int(input())

for i in range(n):
    x1, y1, x2, y2, x3, y3 = [int(i) for i in input().split()]
    
    area =((x1 * y2) + (y1 * x3) + (x2 * y3) - (x3 * y2) - (y3 * x1) - (x2 * y1)) / 2
    
    if area < 0:
        area *= -1
    
    print("%.3f" % area)
