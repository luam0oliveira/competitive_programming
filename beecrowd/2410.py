# -*- coding: utf-8 -*-

lista = {}

alunos = int(input())

for i in range(alunos):
    inp = int(input())
    
    if inp not in lista:
        lista[inp] = 0
    
print(len(lista))
