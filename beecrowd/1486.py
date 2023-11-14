# -*- coding: utf-8 -*-

while True:
    p,n,c = [int(i) for i in input().split()]
    
    if p == n == c == 0:
        break
    
    linha = []
    
    for i in range(n):
        for j in input().split():
            linha.append(int(j))

    cont = 0
    
    
    
    # Para ir de linha a linha
    for i in range(p):
        # controle de posição
        j = 0
        while j < n:
            x = 0
            if linha[j * p + i] == 1:
                lines = 1
                x = 1
                # print(n - j)
                for x in range(1, n - j):
                    # print(x)
                    if linha[(x + j) * p + i] == 1:
                        lines += 1
                    else:
                        break
                if lines >= c:
                    cont += 1
                j += x
            else:
                j += 1
    
    print(cont)
