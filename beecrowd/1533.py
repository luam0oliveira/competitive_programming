# -*- coding: utf-8 -*-

while True:
    s = int(input())
    if s == 0:
        break
    
    inp = [int(i) for i in input().split()]
    
    posMaior = 0
    posMenor = 1
    
    if inp[posMaior] < inp[posMenor]:
        posMenor, posMaior = posMaior, posMenor
    
    for i in range(s):
        if inp[i] > inp[posMaior]:
            posMenor = posMaior
            posMaior = i
        elif inp[i] > inp[posMenor] and inp[posMaior] > inp[i]:
            posMenor = i
        
    print(posMenor + 1)
