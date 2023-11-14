# -*- coding: utf-8 -*-

o, b, i = [int(float(i) * 1000)  for i in input().split()]

if o < b and b < i or o < i and i < b:
    print("Otavio")
elif b < o and o < i or b < i and i < o:
    print("Bruno")
elif i < b and b < o or i < o and o < b:
    print("Ian")
else:
    print("Empate")
