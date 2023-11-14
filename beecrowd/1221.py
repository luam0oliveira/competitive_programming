# -*- coding: utf-8 -*-

l = int(input())

for i in range(l):
    n = int(input())
    
    p = True
    
    if n < 2:
        p = False;
    
    for i in range(2, int(n ** (1/2)) + 1):
        if n % i == 0: p = False; break
    
    print("Prime" if p else "Not Prime")
