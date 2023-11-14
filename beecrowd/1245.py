# -*- coding: utf-8 -*-

while True:
    botD = []
    botE = []
    for i in range(31):
        botD.append(0)
        botE.append(0)
    par = 0
    
    try:
        n = int(input())
        for i in range(n):
            num, pe = input().split()
            num = int(num)
            if pe == 'D':
                botD[num - 30] += 1
            else:
                botE[num - 30] += 1
    
        for i in range(31):
            if botD[i] > botE[i]:
                par += botE[i]
            else:
                par += botD[i]
        
        print(par)
    
    except Exception as e:
        break
