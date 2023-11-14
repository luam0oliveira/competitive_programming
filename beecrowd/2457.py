# -*- coding: utf-8 -*-

letra = input().strip()
strings = input().split()

cont = 0
total = len(strings)

for i in strings:
    if letra in i:
        cont += 1

print("%.1f" % (cont * 100 / total))
