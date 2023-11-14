# -*- coding: utf-8 -*-

i = 1
while True:
    try:
        m = int(input())
        
        if m == 0:
            break
        
        n50 = m // 50
        m -= n50 * 50
        
        n10 = m // 10
        m -= n10 * 10
        
        n5 = m // 5
        m -= n5 * 5
        
        n1 = m
        
        print("Teste %d" % i)
        print("%d %d %d %d" % (n50, n10, n5, n1))
        print()
        i += 1
    except:
        break
