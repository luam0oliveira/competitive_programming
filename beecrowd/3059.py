# -*- coding: utf-8 -*-

n, i , f = [int(j) for j in input().split()]

numbers = [int(j) for j in input().split()]

cont = 0

for k in range(n):
	for l in range(k, n):
		if numbers[l] == numbers[k]:
			continue
		soma = numbers[k] + numbers[l]
		if soma >= i and soma <= f:
			cont += 1

print(cont)
