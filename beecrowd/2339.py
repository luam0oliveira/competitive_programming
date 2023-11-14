# -*- coding: utf-8 -*-

a, b, c = [int(i) for i in input().split()]

if (a * c <= b):
    print("S")
else:
    print("N")