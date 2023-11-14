# -*- coding: utf-8 -*-

p, m = [int(i) for i in input().split()]

cont = 0

for i in range(p):
	matches = [int(j) for j in input().split()]

	zerou = False

	for match in matches:
		if match == 0:
			zerou = True
			break
	if not zerou:
		cont += 1

print(cont)
