# -*- coding: utf-8 -*-

d = int(input())
a, b, c = [int(i) for i in input().split()]

if d > a or d > b or d > c:
    print("N")
else:
    print("S")