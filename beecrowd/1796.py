# -*- coding: utf-8 -*-

n = int(input())

cont = 0

for i in input().split():
    if i == '0':
        cont += 1

if cont / n > 0.5:
    print("Y")
else:
    print("N")
