# -*- coding: utf-8 -*-

import math

while True:
    try:
        v, t = [int(i) for i in input().split()]
        d = 0
        if t != 0:
            a = float(v / t)
            
            d = round(a * ((t * 2) ** 2) / 2)
        
        print(d)
    except:
        break
