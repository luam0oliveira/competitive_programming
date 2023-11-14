# -*- coding: utf-8 -*-

n = int(input())

for i in range(n):
    array = input().split()
    n = int(array.pop(0))
    array = [int(i) for i in array]
    
    media = 0
    
    for i in array:
        media += int(i)
    
    media /= n
    
    cont = 0
    for i in array:
        if i > media:
            cont += 1
    
    print("%.3f%%" % (cont*100/n))
