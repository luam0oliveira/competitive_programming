# -*- coding: utf-8 -*-

d = 12

op = input()

resultado = 0

for i in range(d):
	for j in range(d):
		num = float(input())
		if i + j >= d and j > i:
			resultado += num

if op == 'M':
	resultado /= ((d ** 2) - d * 2) / 4

print("%.1f" % resultado)
