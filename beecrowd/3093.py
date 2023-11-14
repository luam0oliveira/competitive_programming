# -*- coding: utf-8 -*-

n = int(input())

# Q J K A
letras = "QJKA"

for i in range(n):
	cartas = [False] * 4
	ok = False
	monte = input()

	for j in letras:
		if j in monte:
			index = letras.index(j)

			cartas[index] = True

		if False not in cartas:
			ok = True
			break
	if ok:
		print("Aaah muleke")
	else:
		print("Ooo raca viu")
