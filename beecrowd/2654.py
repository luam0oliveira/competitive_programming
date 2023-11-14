# -*- coding: utf-8 -*-

deuses = int(input())

nome, poder, matou, morreu = input().split()

maioresAtributos = {
    "nome": nome,
    "poder": int(poder),
    "matou": int(matou),
    "morreu": int(morreu)
}

for i in range(deuses - 1):
    nome, poder, matou, morreu = input().split()
    poder, matou, morreu = [int(j) for j in [poder, matou, morreu]]

    maiorPoder = poder > maioresAtributos["poder"]
    matouMais = poder == maioresAtributos["poder"] and matou > maioresAtributos["matou"]
    morreuMenos = poder == maioresAtributos["poder"] and matou == maioresAtributos["matou"] and morreu < maioresAtributos["morreu"]
    iguaisNomeMenor = poder == maioresAtributos["poder"] and matou == maioresAtributos["matou"] and morreu == maioresAtributos["morreu"] and nome < maioresAtributos["nome"]
        

    if maiorPoder or matouMais or morreuMenos or iguaisNomeMenor:
        maioresAtributos = {
            "nome": nome,
            "poder": int(poder),
            "matou": int(matou),
            "morreu": int(morreu)
        }
    
print(maioresAtributos["nome"])
