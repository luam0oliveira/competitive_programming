# -*- coding: utf-8 -*-

n = int(input())
cq = 0
for i in range (n):
    l, c = [int(j) for j in input().split()]
    if l > c:
        cq += c
print(cq)
