# -*- coding: utf-8 -*-

while True:
    n = int(input())
    
    if n == 0:
        break
    
    lados = 0
    
    for i in range(n):
        leng, numb = [int(i) for i in input().split()]
        
        lados += numb // 2
        
    print(lados // 2)
