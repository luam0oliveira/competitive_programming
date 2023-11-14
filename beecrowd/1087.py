# -*- coding: utf-8 -*-

while 1 < 2:
    x1, y1, x2, y2 = [int(i) for i in input().split()]
    
    if x1 == 0 and x2 == 0 and y1 == 0 and y2 == 0:
        break
    
    if x1 == x2 and y1 == y2:
        print("0")
    else:
        dg = False;
        for i in range(1,8):
            a = x1 == x2 - i and y1 == y2 - i
            b = x1 == x2 - i and y1 == y2 + i
            c = x1 == x2 + i and y1 == y2 - i
            d = x1 == x2 + i and y1 == y2 + i
            e = x1 == x2 or y1 == y2
            dg = a or b or c or d or e
            if dg:
                break
        if dg:
            print("1")
        else:
            print("2")
