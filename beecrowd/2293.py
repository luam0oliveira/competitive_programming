# -*- coding: utf-8 -*-

n,m = [int(i) for i in input().split()]

matrix = []
maior = 0

for i in range(n):
	inp = input().split()
	linha = []
	soma = 0

	for j in inp:
		num = int(j)
		soma += num
		linha.append(num)

	if soma > maior:
		maior = soma
	matrix.append(linha)

for i in range(m):
	somaCol = 0
	for j in range(n):
		somaCol += matrix[j][i]

	if somaCol > maior:
		maior = somaCol
print(maior)
