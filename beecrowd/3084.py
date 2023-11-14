# -*- coding: utf-8 -*-

gpm = 360 / 60
gph = 360 / 12

while True:
    try:
        gh, gm = [int(i) for i in input().split()]
    
        h = int(gh // gph) 
        m = int(gm // gpm)
        
        if h < 10:
            h = str("0" + str(h))
        
        if m < 10:
            m = str("0" + str(m))
        
        print("%s:%s" % (h,m))
    except:
        break
