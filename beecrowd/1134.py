# -*- coding: utf-8 -*-

g = 0
a = 0
d = 0

inp = "0"

while inp != "4":
    inp = input()
    
    if inp == "1":
        g += 1
    elif inp == "2":
        a += 1
    elif inp == "3":
        d += 1

print("MUITO OBRIGADO")
print("Alcool: %d" % g)
print("Gasolina: %d" % a)
print("Diesel: %d" % d)
