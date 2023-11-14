# -*- coding: utf-8 -*-

n = int(input())

for i in range(n):
    a,b = input().split()
    result = ""
    
    lena = len(a)
    lenb = len(b)
    
    lent = lena if lena > lenb else lenb
    
    for j in range(1, lent + 1):
        if lena >= j:
            result += a[j - 1]
        
        if lenb >= j:
            result += b[j - 1]
    print(result)
