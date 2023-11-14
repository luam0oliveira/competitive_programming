# -*- coding: utf-8 -*-

# verifica se ha a carta nas ja incluidas se nao tiver adiciona a diferentes e 
# soma um no contador senao soma 1 no repetidas

num = int(input())
cartas = []
diferentes = 0
repetidas = 0

for i in range(num):
    inp = input()


    if inp in cartas:
        repetidas += 1
    else:
        diferentes += 1
        cartas.append(inp)

print(diferentes)
print(repetidas)
