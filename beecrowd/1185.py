# -*- coding: utf-8 -*-

d = 12

op = input()

result = 0
cont = 0
for i in range(d):
	for j in range(d):
		valor = float(input())

		if i + j < d - 1:
			result += valor
			cont += 1

if op == 'M':
	result /= cont

print("%.1f" % result)
