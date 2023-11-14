# -*- coding: utf-8 -*-

valor_notas = [64, 32, 16, 8, 4, 2, 1]
notas = {
	"W": 64, "H": 32, "Q": 16, "E": 8, "S": 4, "T": 2,"X": 1
}
while True:
	inpt = input()
	if inpt == "*":
		break

	jingle = inpt.split('/')

	corretos = 0
	for i in range(len(jingle)):
		atual = 64
		for j in jingle[i]:
			atual -= notas[j]
		if atual == 0:
			corretos += 1
	print(corretos)
