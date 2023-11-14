# -*- coding: utf-8 -*-

a, b, c = [int(i) for i in input().split()]

if a + b > c and a + c > b and b + c > a:
    if (a == b and a == c):
        print("Valido-Equilatero")
    elif (a == b or b == c or a == c):
        print("Valido-Isoceles")
    else:
        print("Valido-Escaleno")
    
    if a ** 2 == b ** 2 + c ** 2 or b ** 2 == a ** 2 + c ** 2 or c ** 2 == a ** 2 + b ** 2:
        print("Retangulo: S")
    else:
        print("Retangulo: N")
else:
    print("Invalido")
    