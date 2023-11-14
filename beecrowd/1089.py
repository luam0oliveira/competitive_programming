# -*- coding: utf-8 -*-

while True:
    n = int(input())
    
    if n == 0:
        break
    
    inp = [int(i) for i in input().split()]
    
    ultima = inp[-1]
    primeira = inp[0]
    
    anterior = ultima
    subindo = ultima <= primeira
    cont = 0
    
    for i in inp:
        if subindo and anterior > i:
            cont += 1
            subindo = False
        elif not subindo and anterior < i:
            cont += 1
            subindo = True
        
        anterior = i
    
    if subindo and anterior > primeira or not subindo and anterior < primeira:
        cont += 1
    
    print(cont)
