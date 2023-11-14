# -*- coding: utf-8 -*-

cases = 1
while True:
    rxi = 0
    rxf = 0
    ryi = 0
    ryf = 0
    
    n = int(input())
    
    if n == 0:
        break
    
    for i in range(n):
        xi, yi, x, y = [int(j) for j in input().split()]
        
        if i == 0:
            rxi = xi
            rxf = x
            ryi = yi
            ryf = y
        
        if rxi < xi:
            rxi = xi
        
        if rxf > x:
            rxf = x
        
        if ryi > yi:
            ryi = yi
        
        if ryf < y:
            ryf = y
        
    print("Teste %d" % cases)
    
    if rxf < rxi or ryf > ryi:
        print("nenhum")
    else:
        print("%d %d %d %d"%(rxi, ryi, rxf, ryf))
    print()
    cases += 1
