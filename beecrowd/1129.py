# -*- coding: utf-8 -*-

let = ['A', 'B', 'C', 'D', 'E'];

while True:
    n = int(input())
    
    if n == 0:
        break
    
    for i in range(0, n):
        pos = 0
        cont = 0
        
        inp = [int(i) for i in input().split()]
        
        for j in range(0, 5):
            if inp[j] <= 127:
                pos = j
                cont += 1
            if cont > 1:
                break
        
        if cont != 1:
            print("*")
        else:
            print(let[pos])
