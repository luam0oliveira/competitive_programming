# -*- coding: utf-8 -*-

while True:
	n = int(input())

	if n == 0:
		break

	assinaturas = {}
	for i in range(n):
		nome, assinatura = input().split()
		assinaturas[nome] = assinatura

	m = int(input())

	cont = 0
	for i in range(m):
		nome, assinatura = input().split()
		original = assinaturas[nome]

		diff = 0

		for j in range(len(original)):
			
			if original[j] != assinatura[j]:
				diff += 1
		if diff > 1:
			cont += 1

	print(cont)
