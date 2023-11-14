# -*- coding: utf-8 -*-

d = 12

n = int(input())
op = input()

result = 0
for i in range(d):
	for j in range(d):
		valor = float(input())

		if i == n:
			result += valor

if op == 'M':
	result /= d

print("%.1f" % result)
