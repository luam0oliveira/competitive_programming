# -*- coding: utf-8 -*-

palavras = {}

m, n = [int(i) for i in input().split()]

for i in range(m):
    inp = input().split()
    palavras[inp[0]] = int(inp[1])

for i in range(n):
    inp = ""
    salario = 0
    while inp != ".":
        inp = input()
        if inp != ".":
            for j in inp.split():
                if j in palavras:
                    salario += palavras[j]
                
    print(salario)
