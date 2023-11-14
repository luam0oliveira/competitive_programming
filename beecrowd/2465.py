# -*- coding: utf-8 -*-

n = int(input())

i, j = [int(i) for i in input().split()]

matrix = [[0] * (n + 2)]
voltar = []
passou = [[False] * (n + 2)]

for h in range(n):
    voltar.append([[-1, -1]] * n )
    line = [int(k) for k in input().split()]
    line.insert(0, 0)
    line.append(0)
    matrix.append(line)
    passou.append([False] * (n + 2))

matrix.append([0] * (n + 2))
passou.append([False] * (n + 2))
passou[i][j] = True
passo = True

while passo:
    # listando as casas adjacentes de mesma linha ou coluna
    atual = matrix[i][j]
    direita = matrix[i][j + 1]
    baixo = matrix[i + 1][j]
    esquerda = matrix[i][j - 1]
    cima = matrix[i - 1][j]

    if atual <= direita and not passou[i][j + 1]:
        voltar[i - 1][j] = [i, j]
        passou[i][j + 1] = True
        j += 1
    elif atual <= baixo and not passou[i + 1][j]:
        voltar[i][j - 1] = [i, j]
        passou[i + 1][j] = True
        i += 1
    elif atual <= esquerda and not passou[i][j - 1]:
        voltar[i - 1][j - 2] = [i, j]
        passou[i][j - 1] = True
        j -= 1
    elif atual <= cima and not passou[i - 1][j]:
        voltar[i - 2][j - 1] = [i, j]
        passou[i - 1][j] = True
        i -= 1
    elif voltar[i - 1][j - 1] != [-1, -1]:
        aux = voltar[i - 1][j - 1]
        voltar[i - 1][j - 1] = [-1, -1]
        i, j = aux
    else:
        passo = False

cont = 0
for i in range(1,n + 1):
	for j in range(1, n + 1):
		if passou[i][j]:
			cont += 1

print(cont)
