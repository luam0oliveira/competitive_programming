# -*- coding: utf-8 -*-

c = int(input())

for cs in range(c):
    m, n, x, y = [int(i) for i in input().split()]
    parede = []

    for i in range(m):
        line = [int(j) for j in input().split()]
        parede.append(line)

    for i in range(m):
        for j in range(n):
            distanciaX = ((x - 1 - i) ** 2) ** 0.5
            distanciaY = ((y - 1 - j) ** 2) ** 0.5
			
            distancia = int(max([distanciaY, distanciaX]))
			
            dano = 10 - distancia
			
            if dano < 1:
                dano = 1
			
            parede[i][j] += dano

    print("Parede %d:" %(cs + 1))


    for i in parede:
        print(*i, sep=" ")
