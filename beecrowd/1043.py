# -*- coding: utf-8 -*-

l1, l2, l3 = [float(i) for i in input().split()]

if (l1 + l2 > l3 and l1 + l3 > l2 and l2 + l3 > l1):
    print("Perimetro = %.1f" % (l1 + l2 + l3))
else:
    print("Area = %.1f" % ((l1 + l2) * l3 / 2))
