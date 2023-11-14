# -*- coding: utf-8 -*-

n = int(input())

for i in range (n):
    t = int(input())
    a, b, c, d = [int(j) for j in input().split()]
    z = int(input())
    
    ok = True
    for cont in [a,b,c,d,t,z]:
        if not cont in range(1,7) or [a,b,c,d,t,z].count(cont) != 1:
            ok = False
            break
    
    if t + z == 7 and b + d == 7 and a + c == 7 and ok:
        print("SIM")
    else:
        print("NAO")
