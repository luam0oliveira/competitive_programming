# -*- coding: utf-8 -*-

while True:
    n, m = [int(i) for i in input().split()]
    
    if n == m == 0:
        break
    
    rep = []
    in_festa = []
    
    for i in input().split():
        i = int(i)
        
        if i not in in_festa:
            in_festa += [i]
        elif i not in rep:
            rep += [i]
        
    print(len(rep))
