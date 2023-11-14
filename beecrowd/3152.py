# -*- coding: utf-8 -*-

# SE, SD, ID, IE
terrenoA = []
terrenoB = []

for i in range(4):
    coord = [int(j) for j in input().split()]
    terrenoA.append(coord)

for i in range(4):
    coord = [int(j) for j in input().split()]
    terrenoB.append(coord)

areaA = 0.5 * ((terrenoA[0][0] - terrenoA[2][0]) * (terrenoA[3][1] - terrenoA[1][1]) - (terrenoA[3][0] - terrenoA[1][0]) * (terrenoA[0][1] - terrenoA[2][1]))
areaB = 0.5 * ((terrenoB[0][0] - terrenoB[2][0]) * (terrenoB[3][1] - terrenoB[1][1]) - (terrenoB[3][0] - terrenoB[1][0]) * (terrenoB[0][1] - terrenoB[2][1]))


if areaA > areaB:
    print("terreno A")
else:
    print("terreno B")
