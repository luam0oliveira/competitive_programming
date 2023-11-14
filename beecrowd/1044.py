# -*- coding: utf-8 -*-

n1, n2 = [int(i) for i in input().split()]

if n1 % n2 == 0 or n2 % n1 == 0:
    print("Sao Multiplos")
else:
    print("Nao sao Multiplos")