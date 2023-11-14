# -*- coding: utf-8 -*-

n, c = [int(i) for i in input().split()]

pessoas = 0
passou = False
for i in range(n):
    s, e = [int(i) for i in input().split()]
    
    pessoas += e - s
    
    if pessoas > c:
        passou = True
        break
    
if passou:
    print("S")
else:
    print("N")
