# -*- coding: utf-8 -*-

grupos = ["bonecos", "arquitetos", "musicos", "desenhistas"]
horaspg = [8,4,6,12]
horastr = [0] * 4
brinquedos = 0

n = int(input())

for elfos in range(n):
	elfo, grupo, horas = input().split()
	horas = int(horas)

	for i in range(4):
		if grupos[i] == grupo:
			horastr[i] += horas
			break

for i in range(4):
	brinquedos += horastr[i] // horaspg[i]

print(brinquedos)
