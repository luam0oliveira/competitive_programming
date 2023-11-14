# -*- coding: utf-8 -*-

cases = 1
while True:
    a, b = [int(i) for i in input().split()]
    
    if a == b == 0:
        break
    
    nol = 0
    pos = b
    nm = 0
    
    if a > b:
        nm = 26 * b + b
        
        while nm >= a and pos < a:
            nol += 1
            pos += b
    else:
        nm = a
    
    if nm >= a:
        print("Case %d: %d" % (cases, nol))
    else:
        print("Case %d: impossible" % cases)
    cases += 1
