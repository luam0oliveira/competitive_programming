# -*- coding: utf-8 -*-

n = int(input())

for i in range(n):
    m = int(input())
    
    disponiveis = {}
    
    for i in range(m):
        inp = input().split()
        disponiveis[inp[0]] = float(inp[1])
    
    total = 0.0
    p = int(input())
    for i in range(p):
        inp = input().split()
        if inp[0] in disponiveis:
            total += disponiveis[inp[0]] * int(inp[1])
    
    print("R$ %.2f" % total)
