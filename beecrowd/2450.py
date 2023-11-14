# -*- coding: utf-8 -*-

# A ideia eh fazer a verificacao para cada uma das celulas anteriores na linha 
# seguinte, se houver algum diferente de 0, invalida a matrix e interrompe o 
# processo

n, m = [int(i) for i in input().split()]

matrix = []

for i in range(n):
    linha = [int(j) for j in input().split()]
    matrix.append(linha)

valido = True
tudoZero = False

for i in range(n):
    linhaZerada = True
    for j in range(m):
        if (matrix[i][j] != 0):
            if tudoZero:
                valido = False
            linhaZerada = False
            for k in range(i + 1, n):
                if j == 0:
                    inicio = 0
                else:
                    inicio = j - 1
                for l in range(inicio, j + 1):
                    if matrix[k][l] != 0:
                        valido = False
                        break
                if not valido:
                    break
            break
        
        if not valido:
            break
    tudoZero = linhaZerada
    if not valido: break

if valido :
    print("S")
else:
    print("N")
