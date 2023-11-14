# -*- coding: utf-8 -*-

posicoesvizinhas = [[0,1], [1,0], [0,-1], [-1,0]]

while True:
	try:
		n, m = [int(i) for i in input().split()]
		matrix = [[0] * (m * 2)]

		for i in range(n):
			linha = [int(j) for j in input().split()]

			linha.insert(0,0)
			linha.append(0)

			matrix.append(linha)

		matrix.append([0] * (m * 2))

		for i in range(1, n + 1):
			for j in range(1, m + 1):
				saida = 9
				if matrix[i][j] != 1:
					paesVizinhos = 0
					for k in range(4):
						linha = i + posicoesvizinhas[k][0]
						coluna = j + posicoesvizinhas[k][1]

						if matrix[linha][coluna] == 1:
							paesVizinhos += 1

					saida = paesVizinhos
				print(saida, end="")
			print()
	except:
		break
