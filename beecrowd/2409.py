# -*- coding: utf-8 -*-

a, b, c = [int(i) for i in input().split()]
h, l = [int(i) for i in input().split()]

if a > b:
    a, b = b, a
if a > c:
    a, c = c, a
if b > c:
    b, c = c, a

if h >= l:
    if (a <= l and b <= h):
        print("S")
    else:
        print("N")
else:
    if (a <= h and b <= l):
        print("S")
    else:
        print("N")
