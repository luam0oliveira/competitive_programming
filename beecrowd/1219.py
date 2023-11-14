# -*- coding: utf-8 -*-

PI = 3.1415926535897

while True:
    try:
        a,b,c = [int(i) for i in input().split()]
        
        metadep = (a + b + c) / 2
        
        violetas = (metadep * (metadep - a) * (metadep - b) * (metadep - c)) ** 0.5
        
        r = a * b * c / (violetas * 4)
        
        girasois = PI * r ** 2
        
        raiomenor = violetas / metadep
        rosas = PI * raiomenor ** 2
        
        girasois -= violetas
        violetas -= rosas
        
        print("%.4f %.4f %.4f" %(girasois, violetas, rosas))
    except:
        break
