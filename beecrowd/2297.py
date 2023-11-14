# -*- coding: utf-8 -*-

cases = 1
while True:
    n = int(input())
    
    if n == 0:
        break
    
    print("Teste %d" % cases)
    beto = 0
    aldo = 0
    
    for i in range(n):
        a, b = [int(i) for i in input().split()]
        
        aldo += a
        beto += b
        
    if beto > aldo:
        print("Beto")
    else:
        print("Aldo")
    print()
    cases += 1
