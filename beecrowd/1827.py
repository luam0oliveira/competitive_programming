# -*- coding: utf-8 -*-

while True:
    try:
        d = int(input())
        
        matrix = []
        
        meio = d // 2
        
        interna = d // 3
        
        for i in range(d):
            line = [0] * d
            for j in range(d):
                if meio == i == j:
                    line[j] = 4
                elif interna <= j and interna <= i and d - interna > i and d - interna > j:
                    line[j] = 1
                elif (i + j) == d - 1:
                    line[j] = 3
                elif i == j:
                    line[j] = 2
            matrix.append(line)
        
        for i in range(d):
            print(*matrix[i], sep="")
        print()
    except:
        break
