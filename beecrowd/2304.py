# -*- coding: utf-8 -*-

# quantidade de saldo inicial e num de operacoes
initial, op = [int(i) for i in input().split()]

# DALIA, ELOI, FELIX
saldo = [initial] * 3
nome = ["D", "E", "F"]

for i in range(op):
    inpt = input().split()
    jogador = inpt[1]
    if inpt[0] == "C":
        valor = int(inpt[2])
        index = nome.index(jogador)
        saldo[index] -= valor

    elif inpt[0] == "V":
        valor = int(inpt[2])
        index = nome.index(jogador)
        saldo[index] += valor
    
    else:
        ganhador = jogador
        pagante = inpt[2]
        valor = int(inpt[3])
        saldo[nome.index(ganhador)] += valor
        saldo[nome.index(pagante)] -= valor

print(*saldo, sep=" ")
