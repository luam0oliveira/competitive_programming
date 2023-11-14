# -*- coding: utf-8 -*-


while True:
    horas = [" "," "," "," "]
    minutos = [" "," "," "," "," "," "]
    try:

        h, m = [int(i) for i in input().split(":")]

        string = ''' ____________________________________________
|                                            |
|    ____________________________________    |_
|   |                                    |   |_)
|   |   8         4         2         1  |   |
|   |                                    |   |
|   |   %s         %s         %s         %s  |   |
|   |                                    |   |
|   |                                    |   |
|   |   %s     %s     %s     %s     %s     %s  |   |
|   |                                    |   |
|   |   32    16    8     4     2     1  |   |_
|   |____________________________________|   |_)
|                                            |
|____________________________________________|'''

        if h // 8 > 0:
            h -= h // 8 * 8
            horas[0] = "o"
        
        if h // 4 > 0:
            h -= h // 4 * 4
            horas[1] = "o"
        
        if h // 2 > 0:
            h -= h // 2 * 2
            horas[2] = "o"
        
        if h > 0:
            horas[3] = "o"

        
        if m // 32 > 0:
            m -= m // 32 * 32
            minutos[0] = "o"
        
        if m // 16 > 0:
            m -= m // 16 * 16
            minutos[1] = "o"
            
        if m // 8 > 0:
            m -= m // 8 * 8
            minutos[2] = "o"

        if m // 4 > 0:
            m -= m // 4 * 4
            minutos[3] = "o"

        if m // 2 > 0:
            m -= m // 2 * 2
            minutos[4] = "o"

        if m > 0:
            minutos[5] = "o"
    
        print(string % (tuple(horas + minutos)))
        print()
    except Exception as e:
        break
