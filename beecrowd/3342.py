# -*- coding: utf-8 -*-

# pega qual o tamanho do lado do tabuleiro q x q
q = int(input())

# inicia os contadores de casas brancas e pretas
branca = 0
preta = 0

for i in range(q):
    for j in range(q):
        # faz a verificacao de casas pretas e brancas
        if (i + j) % 2 == 0 :
            branca += 1
        else:
            preta += 1
            
print("%d casas brancas e %d casas pretas" % (branca, preta))
