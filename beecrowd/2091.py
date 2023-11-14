# -*- coding: utf-8 -*-

while True:
	n = int(input())

	if n == 0:
		break

	pares = {}
	numbers = [int(i) for i in input().split()]
	
	for i in range(n):
		if numbers[i] not in pares:
			pares[numbers[i]] = 1
		else:
			pares[numbers[i]] += 1

		if pares[numbers[i]] == 2:
			del pares[numbers[i]]

	print(list(pares.keys())[0])
