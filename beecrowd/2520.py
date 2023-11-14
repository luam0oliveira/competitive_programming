# -*- coding: utf-8 -*-

while True:
	try:
		n, m = [int(i) for i in input().split()]

		posM = [-1,-1]
		posP = [-1,-1]

		matrix = []

		for i in range(n):
			linha = input().split()
			if posM == [-1,-1] and '2' in linha:
				posM = [i, linha.index('2')]
			if posP == [-1, -1] and '1' in linha:
				posP = [i, linha.index('1')]
			matrix.append(linha)
			
		tempo = max([posM[0],posP[0]]) - min([posM[0],posP[0]]) + (max([posM[1],posP[1]]) - min([posM[1],posP[1]]))

		print(tempo)
	except:
		break
