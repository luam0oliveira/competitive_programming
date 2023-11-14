# -*- coding: utf-8 -*-

cont = [0] * 4

n = int(input())

numbers = [int(i) for i in input().split()]

for i in numbers:
	for j in range(2,6):
		if i % j == 0:
			cont[j - 2] += 1

for i in range(2,6):
	print("%d Multiplo(s) de %d" %(cont[i - 2], i))
