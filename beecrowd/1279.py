# -*- coding: utf-8 -*-

i = 0
while True:
    try:
        y = int(input())
        
        if i > 1:
            print()
            
        s = False
        h = y % 15 == 0
        b = y % 55 == 0 and (y % 4 == 0 and y % 100 != 0 or y % 400 == 0)
        
        if y % 4 == 0 and y % 100 != 0 or y % 400 == 0:
            print("This is leap year.")
            s = True
        
        if h:
            print("This is huluculu festival year.")
            s = True
        
        if b:
            print("This is bulukulu festival year.")
        
        if not s:
            print("This is an ordinary year.")
        
        if i == 0:
            print()
        i += 1
    except:
        break
