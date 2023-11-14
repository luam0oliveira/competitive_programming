# -*- coding: utf-8 -*-

PI = 3.14159

a, b, c = [float(i) for i in input().split()] 

atri = (a * c) / 2
ac = PI * (c ** 2)
atra = ((a + b) / 2) * c
asq = b ** 2
ar = a * b

print("TRIANGULO: %.3f"% atri)
print("CIRCULO: %.3f"% ac)
print("TRAPEZIO: %.3f"% atra)
print("QUADRADO: %.3f"% asq)
print("RETANGULO: %.3f"% ar)