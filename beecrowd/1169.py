# -*- coding: utf-8 -*-

for i in range(int(input())):
    c = int(input())
    
    total = 0
    
    for i in range(c):
        total += 2 ** i
    
    print("%d kg" % (total // 12000))
