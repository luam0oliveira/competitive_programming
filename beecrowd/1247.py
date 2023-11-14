# -*- coding: utf-8 -*-

while True:
    try:
        inp = input()
        d, vf, vg = [int(i) for i in inp.split()]
        
        if vf >= vg:
            print("N")
        else:
            tf = 12 / vf
        
            hip = (12 ** 2 + d ** 2) ** 0.5
            
            tg = hip / vg
            
            if tf < tg:
                print("N")
            else:
                print("S")
        
    except:
        break;
