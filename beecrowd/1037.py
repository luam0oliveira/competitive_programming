# -*- coding: utf-8 -*-

n = float(input())

if n > 100 or n < 0:
    print("Fora de intervalo")
elif n > 75:
    print("Intervalo (75,100]")
elif n > 50:
    print("Intervalo (50,75]")
elif n > 25:
    print("Intervalo (25,50]")
else:
    print("Intervalo [0,25]")
