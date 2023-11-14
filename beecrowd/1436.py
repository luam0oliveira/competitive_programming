# -*- coding: utf-8 -*-

for i in range(int(input())):
    inp = input().split()
    
    n = int(inp.pop(0))
    
    pos = n // 2
    
    print("Case %d: %s" % ( i + 1, inp[pos]))
