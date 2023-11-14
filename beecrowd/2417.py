# -*- coding: utf-8 -*-

cv, ce, cs, fv, fe, fs = [int(i) for i in input().split()]

pc = cv * 3 + ce
pf = fv * 3 + fe

if pc > pf or pc == pf and cs > fs:
    print("C")
elif pf > pc or pc == pf and cs < fs:
    print("F")
else:
    print("=")
