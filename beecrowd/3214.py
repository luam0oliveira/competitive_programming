# -*- coding: utf-8 -*-

# pega a quantidade de garrafas no inicio, adquiridas durante o dia e quanto
# sao necessarias para trocar por 1
e, f, c = [int(i) for i in input().split()]

# calcula o total vazias
vazias = e + f

# inicializa as bebidas
bebidas = 0

# a cada iterracao verifica se há quantidade necessária para trocar por garrafas
# cheias
while vazias >= c:
    # adiciona o total de garrafas que foram trocadas
    bebidas += vazias // c
    # adiciona os totais que foram trocadas somada aquelas que nao puderam ser 
    # trocadas
    vazias = (vazias // c) + (vazias % c)

print(bebidas)
