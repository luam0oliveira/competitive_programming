# -*- coding: utf-8 -*-

# cima, direita, baixo, esquerda
vizinhos = [[-1,0, 0], [0,1, 1], [1,0,2], [0,-1,3]]

while True:
    try:
        # linhas, colunas
        m,n = [int(i) for i in input().split()]

        # x, y, direcao
        coord = [-1,-1,-1]

        matrix = [['1'] * (n + 2)]

        for i in range(m):
            linha = input().split()
            if 'X' in linha:
                coord = [i + 1, linha.index('X') + 1, -1]
            linha.insert(0,'1')
            linha.append('1')
            matrix.append(linha)

        matrix.append(['1'] * (n + 2))

        passo = True

        while passo:
            passo = False
            for i in range(4):
                vizinho_x = coord[0] + vizinhos[i][0]
                vizinho_y = coord[1] + vizinhos[i][1]
                delta = max([coord[2], vizinhos[i][2]]) - min([coord[2], vizinhos[i][2]])

                if matrix[vizinho_x][vizinho_y] == '0' and (coord[2] == -1 or delta != 2):
                    if coord[2] == vizinhos[i][2] or coord[2] == -1:
                        print('F', end=" ")
                    else:
                        if coord[2] == 3 and vizinhos[i][2] == 0 or (coord[2] < vizinhos[i][2] and (coord[2] != 0 or vizinhos[i][2] != 3)):
                            print('R', end=" ")
                            print('F', end=" ")
                        else:
                            print('L', end=" ")
                            print('F', end=" ")

                    coord = [vizinho_x, vizinho_y, vizinhos[i][2]]
                    passo = True
                    break
        print('E')
    except Exception as e:
        break
