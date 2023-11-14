# -*- coding: utf-8 -*-

# direita, baixo, esquerda, cima
vizinhos = [[0,1], [1,0], [0,-1], [-1,0]]

while True: 
    n, m = [int(i) for i in input().split()]
    if n == m == 0:
        break
    matrix = [['X'] * (m + 2)]
    for i in range(n):
        linha = (list(input())) 
        linha.insert(0, 'X')
        linha.append('X')
        matrix.append(linha)
    matrix.append(['X'] * (m + 2))

    passo = True
    while passo:
        passo = False
        for i in range(n):
            for j in range(m):
                if matrix[i + 1][j + 1] == 'T':
                    for k in range(4):
                        valor_vizinho = matrix[vizinhos[k][0] + i + 1][vizinhos[k][1] + j + 1]
                        if valor_vizinho == 'A':
                            matrix[vizinhos[k][0] + i + 1][vizinhos[k][1] + j + 1] = 'T'
                            passo = True
    for i in range(1,n + 1):
        for j in range(1, m + 1):
            print(matrix[i][j], end="")
        print()
    print()
