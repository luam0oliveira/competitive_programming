# -*- coding: utf-8 -*-

d = int(input())

matrix = []

posMag = [0] * 3
magico = 0

somaErr = 0

x = -1
y = -1

for i in range(d):

	inp = input().split()

	linha = []
	soma = 0

	for j in range(d):
		num = int(inp[j])

		soma += num
		
		linha.append(num)
	
	matrix.append(linha)
	if i < 3:
		posMag[i] = soma

if posMag[0] == posMag[1] or posMag[0] == posMag[2]:
	magico = posMag[0]
else:
	magico = posMag[1]

for i in range(d):
	somaCol = 0
	somaLin = 0
	
	for j in range(d):
		somaLin += matrix[i][j]
		somaCol += matrix[j][i]

	if somaCol != magico:
		somaErr = somaCol
		y = i

	if somaLin != magico:
		somaErr = somaLin
		x = i

certo = somaErr - magico

print("%d %d" % (matrix[x][y] - certo, matrix[x][y]))
