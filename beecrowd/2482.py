# -*- coding: utf-8 -*-

traducao = {}

n = int(input())

for i in range(n):
    idioma = input()
    palavra = input()
    traducao[idioma] = palavra

m = int(input())

for i in range(m):
    nome = input()
    idioma = input()
    print(nome)
    print(traducao[idioma])
    print()
