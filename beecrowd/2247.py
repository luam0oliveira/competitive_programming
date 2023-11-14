# -*- coding: utf-8 -*-

i = 1
while True:
    n = int(input())
    
    if n == 0:
        break
    
    j = 0
    z = 0
    print("Teste %d" % i)
    for l in range(n):
        m, n = [int(k) for k in input().split()]
        
        j += m
        z += n
        
        print("%d" % (j - z))
    print()
    i += 1
