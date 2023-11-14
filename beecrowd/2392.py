# -*- coding: utf-8 -*-

p, s = [int(i) for i in input().split()]

pos = [0 for i in range(p)]

for i in range(s):
    ini, salto = [int(i) for i in input().split()]
    
    ini -= 1
    rng = round(p / salto) + 1
    
    for i in range(rng):
        t = ini - salto * i
        f = ini + salto * i
        if t >= 0 and t < p:
            pos[t] = 1
        if f >= 0 and f < p:
            pos[f] = 1

print(*pos, sep="\n")
