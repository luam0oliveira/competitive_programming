# -*- coding: utf-8 -*-

n, m = [int(i) for i in input().split()]

anterior = 0
poss = True

for i in [int(i) for i in input().split()]:
    if i - anterior > m:
        poss = False
        break
    anterior = i

poss = 42195 - anterior <= m

if poss:
    print("S")
else:
    print("N")
