# -*- coding: utf-8 -*-

n = int(input())

for i in range(n):
    cmd = int(float(input()) * 1000)
    
    cont = 0
    while cmd > 1000:
        cmd /= 2
        cont += 1
    
    print("%d dias" % cont)
