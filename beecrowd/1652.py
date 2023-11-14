# -*- coding: utf-8 -*-

nc, ne = [int(i) for i in input().split()]

# lista de palavras com suas correcoes (k eh a palavra errada, k + 1 eh sua correcao)
correcoes = []

for i in range(nc):
    errado, correcao = input().split()
    correcoes.append(errado)
    correcoes.append(correcao)

nova_lista = []
for i in range(ne):
    palavra = input()
    try:
        index = correcoes.index(palavra)
        item = correcoes[index + 1]
    except:
        length = len(palavra)
        if length == 1:
            final = palavra + 'e'
        else:
            final = palavra[length - 2:]
        if  'y' == final[1] and final[0] not in 'aeiou':
            item = palavra[:length - 1] + "ies"
        elif 'o' in final[1] or 's' in final[1] or 'x' in final[1]:
            item = palavra + "es"
        elif 'ch' in final or 'sh' in final:
            item = palavra + "es"
        else:
            item = palavra + "s"
    nova_lista.append(item)
print(*nova_lista, sep="\n")
