# -*- coding: utf-8 -*-

while True:
    l, c, p = [int(i) for i in input().split()]

    if l == c == p == 0:
        break

    matrix = []
    
    position = [0, p] * 1

    furou = False

    for i in range(l):
        line = [int(j) for j in input().split()]
        line.insert(0, 0)
        matrix.append(line)
    
    for i in range(l):
        vent_e = 0
        vent_d = 0
        
        if  position[1] > c or position[1] < 1 or matrix[position[0]][position[1]] != 0:
            furou = True
            break

        for j in range(position[1], -1, -1):
            if matrix[i][j] != 0:
                vent_e = matrix[i][j]
                break
        
        for j in range(position[1], c + 1):
            if matrix[i][j] != 0:
                vent_d = matrix[i][j]
                break
        
        position[1] += vent_e - vent_d
        if position[1] > c or position[1] < 1 or matrix[position[0] - 1 ][position[1]] != 0:
            furou = True
            break
        position[0] += 1
        

    if furou:
        print("BOOM %d %d" % (position[0] + 1, position[1]))
    else:
        print("OUT %d" % (position[1]))
