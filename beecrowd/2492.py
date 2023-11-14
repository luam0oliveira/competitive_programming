# -*- coding: utf-8 -*-

while True:
    conexoes = int(input())

    if conexoes == 0:
        break

    XY = {}
    YX = {}
    funcao = True
    inversivel = True

    for i in range(conexoes):
        x, y = input().split(" -> ")

        if x in XY:
            funcao = False
        XY[x] = y
        
        if y in YX:
            inversivel = False
        YX[y] = x
    
    if funcao:
        if inversivel:
            print("Invertible.")
        else:
            print("Not invertible.")
    else:
        print("Not a function.")
