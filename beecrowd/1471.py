# -*- coding: utf-8 -*-

while True:
    try:
        n, r = [int(i) for i in input().split()]
        
        lst = list(range(1, n + 1))
        
        for i in input().split():
            lst.remove(int(i))
        
        if len(lst) != 0:
            print(*lst, sep=" ", end=" \n")
        else:
            print("*")
    except:
        break
