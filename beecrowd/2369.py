# -*- coding: utf-8 -*-

# pega o total de consumo
q = int(input())

# inicia o descontado em 10 porque até 10 cm³ nao é cobrado pelo consumo
descontado = 10
total = 7

while descontado <= q:
    # verifica cada intervalo e adiciona ao total
    if descontado >= 11 and descontado <= 30:
        total += 1
    elif descontado >= 31 and descontado <= 100:
        total += 2
    elif descontado >= 101:
        total += 5
    descontado += 1

print(total)
