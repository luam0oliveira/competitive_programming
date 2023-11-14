# -*- coding: utf-8 -*-

while True:
    n, p = [int(i) for i in input().split()]
    
    if n == p == 0:
        break;
        
    problemas = [0] * p
    caracteristicas = [1] * 4
    
    for i in range(n):
        inpt = input().split()
        
        todos = True
        algum = False
        
        for j in range(p):
            if inpt[j] == '0':
                todos = False
            else:
                algum = True
            
            if inpt[j] == '1':
                problemas[j] += 1
            
        if todos:
            caracteristicas[0] = 0
            
        if not algum:
            caracteristicas[3] = 0


    for i in range(p):
        if problemas[i] == 0:
            caracteristicas[1] = 0
        elif problemas[i] == n:
            caracteristicas[2] = 0
    
    soma = 0
    
    for i in range(4):
        soma += caracteristicas[i]
    
    print(soma)
