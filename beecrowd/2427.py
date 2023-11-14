# -*- coding: utf-8 -*-

n = int(input())

pedacos = 1
while n >= 2:
    n /= 2
    pedacos *= 4
print(pedacos)
