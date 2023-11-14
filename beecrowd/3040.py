# -*- coding: utf-8 -*-

# pegar a quantidades de arvores a verificar 
q = int(input())

for i in range(q):
    # pegar as informacoes sobre a arvore atual
    h, d, g = [int(i) for i in input().split()]
    
    # verifica se a arvore está de acordo com as especificacoes dele
    if h >= 200 and h <= 300 and d >= 50 and g >= 150 :
        print("Sim")
    else:
        print("Nao")
