# -*- coding: utf-8 -*-

n, s = [int(i) for i in input().split()]

menor = s

for i in range(n):
    s += int(input())
    if menor > s:
        menor = s
print(menor)
