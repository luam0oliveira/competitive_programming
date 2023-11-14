# -*- coding: utf-8 -*-

valor = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]

n = int(input())

for i in range(n):
    inpt = [int(j) for j in list(input())]
    sum = 0
    for j in inpt:
        sum += valor[j]
    
    
    print("%d leds" % sum)
