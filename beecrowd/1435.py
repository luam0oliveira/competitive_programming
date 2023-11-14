# -*- coding: utf-8 -*-

while True:
    n = int(input())
    
    if n == 0:
        break
    
    matrix = []
    
    for i in range(n):
        linha = [0] * n
        matrix.append(linha)
    
    for k in range(0, n):
        for i in range(k, n - k):
            for j in range(k, n - k):
                matrix[i][j] += 1
    
    for i in range(n):
        for j in range(n):
            if j == n - 1:
                print("%3d" % matrix[i][j])
            else:
                print("%3d" % matrix[i][j], end=" ")
    print()
