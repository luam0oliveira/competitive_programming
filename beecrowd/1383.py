# -*- coding: utf-8 -*-

cases = int(input())
factorial9 = 362880

for case in range(cases):
    matrix = []

    valida = True

    for i in range(9):
        line = [int(j) for j in input().split()]

        factorial = 1

        if valida:
            for j in line:
                factorial *= j

        if factorial != factorial9 or not valida:
            valida = False
            continue

        matrix.append(line)

        if (i + 1) % 3 == 0:
            for l in range(3):
                factorial = 1
                for j in range(3):
                    for k in range(3):
                        factorial *= matrix[j + ((i) // 3 * 3)][l * 3 + k]
                if factorial != factorial9:
                    valida = False
                    break
                
    if valida:
        for i in range(9):
            factorialcolumn = 1
            for j in range(9):
                factorialcolumn *= matrix[j][i]

            if factorialcolumn != factorial9:
                valida = False
                break
    
    print("Instancia %d" %(case + 1))
    if valida:
        print("SIM")
    else:
        print("NAO")
    print()
