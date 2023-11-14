# -*- coding: utf-8 -*-

t = int(input())

for i in range(t):
	m, n = [int(j) for j in input().split()]

	traducoes = {}
	
	for k in range(m):
		jp = input()
		pt = input()

		traducoes[jp] = pt

	for k in range(n):
		frase = input()

		palavras = frase.split()

		for i in range(len(palavras)):
			if palavras[i] in traducoes:
				palavras[i] = traducoes[palavras[i]]
		frase = " ".join(palavras)
		print(frase)
	print()
