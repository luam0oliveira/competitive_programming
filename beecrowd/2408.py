# -*- coding: utf-8 -*-

a, b, c = [int(i) for i in input().split()]

if a > b and b > c or c > b and b > a:
    print(b)
elif b > a and a > c or c > a and a > b:
    print(a)
else:
    print(c)