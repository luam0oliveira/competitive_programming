# -*- coding: utf-8 -*-

cases = 1
while True:
    a,v = [int(i) for i in input().split()]
    
    if a == v == 0:
        break
    aeroportos = [0] * (a + 1)
    print("Teste %d" %cases)
    for i in range(v):
        x, y = [int(j) for j in input().split()]
        aeroportos[x] += 1
        aeroportos[y] += 1
    
    maior = aeroportos[1]
    pos = [1]
    
    for i in range(2, a + 1):
        if aeroportos[i] == maior:
            pos.append(i)
        elif aeroportos[i] > maior:
            maior = aeroportos[i]
            pos = []
            pos.append(i)
    
    print(*pos, sep=" ", end=" \n")
    print()
    cases += 1
