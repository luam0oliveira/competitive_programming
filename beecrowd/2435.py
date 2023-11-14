# -*- coding: utf-8 -*-

cv, ce, cs = [int(i) for i in input().split()]
fv, fe, fs = [int(i) for i in input().split()]

if  ce / cs > fe / fs:
    print(fv)
else:
    print(cv)
