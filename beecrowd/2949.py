# -*- coding: utf-8 -*-

racas = {
    "X": 0,
    "M": 0,
    "H": 0,
    "E": 0,
    "A": 0,
}

num = int(input())

for i in range(num):
    nome, raca = input().split()

    racas[raca] += 1

print("%d Hobbit(s)" %racas["X"])
print("%d Humano(s)" %racas["H"])
print("%d Elfo(s)" %racas["E"])
print("%d Anao(oes)" %racas["A"])
print("%d Mago(s)" %racas["M"])
