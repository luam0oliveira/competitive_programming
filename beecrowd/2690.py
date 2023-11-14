# -*- coding: utf-8 -*-

CODIGO = [
    "GQaku",
    "ISblv",
    "EOYcmw",
    "FPZdnx",
    "JTeoy",
    "DNXfpz",
    "AKUgq",
    "CMWhr",
    "BLVis",
    "HRjt"
]

cases = int(input())

senhas = []

for i in range(cases):
    senha = ""
    string = "".join(input().split())
    for j in range(12):
        caractere = string[j]
        digito = ""
        for k in range(10):
            if caractere in CODIGO[k]:
                digito = str(k)
                break
        senha += digito
    senhas.append(senha)
print(*senhas, sep="\n")
