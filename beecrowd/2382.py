# -*- coding: utf-8 -*-

l, a, p, r = [int(i) for i in input().split()]

d = l ** 2 + a ** 2 + p ** 2

if (4 * r ** 2 < d):
    print("N")
else:
    print("S")
