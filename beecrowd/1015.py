# -*- coding: utf-8 -*-

x1, y1 = [float(i) for i in input().split()]
x2, y2 = [float(i) for i in input().split()]

d = ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5

print("%.4f"% d)