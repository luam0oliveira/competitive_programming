# -*- coding: utf-8 -*-

p, n = [int(i) for i in input().split()]

arra = [int(i) for i in input().split()]

passo = True
anterior = arra[0]

for i in range(1, n):
    modu = arra[i] - anterior
    
    if modu < 0:
        modu *= -1

    if modu > p:
        passo = False
        break
    anterior = arra[i]

if passo:
    print("YOU WIN")
else:
    print("GAME OVER")
