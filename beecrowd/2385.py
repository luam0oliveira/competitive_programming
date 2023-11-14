# -*- coding: utf-8 -*-

# a ideia principal eh que nao eh necessario construir as duas matrizes com tod
# os os valores, somente aqueles que serao utilizados, no caso a linha de coor
# denada x e a coluna de coordenada y.

# dimensoes da matriz
d = int(input())

# variaveis para calculo de matrix
p,q,r,s,x,y = [int(i) for i in input().split()]

coord_x, coord_y = [int(i) - 1 for i in input().split()]

linhaA = []
linhaB = []

for i in range(d):
    valueA = (p * (coord_x + 1) + q * (i + 1)) % x
    linhaA.append(valueA)
    valueB = (r * (i + 1) + s * (coord_y + 1)) % y
    linhaB.append(valueB)

value = 0

for i in range(d):
    value += linhaA[i] * linhaB[i]

print(value)
