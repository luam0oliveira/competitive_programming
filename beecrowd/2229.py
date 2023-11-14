# -*- coding: utf-8 -*-

cont = 1
while True:
    m = int(input())
    
    if m == -1:
        break
    
    if m == 0:
        n = 4
    else:
        base = 2
        
        for i in range(0, m):
            base += 2 ** i
        
        n = (base) ** 2
    
    print("Teste %d" % cont)
    print("%d" % n)
    print()
    
    cont += 1
