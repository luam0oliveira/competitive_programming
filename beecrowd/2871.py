# -*- coding: utf-8 -*-

while True:
    try:
        m,n = [int(i) for i in input().split()]

        sacas = 0
        litros = 0
        for i in range(m):
            for j in input().split():
                quantidade = int(j)

                litros += quantidade

                if litros >= 60:
                    sacas += litros // 60
                    litros -= (litros // 60) * 60
        print("%d saca(s) e %d litro(s)" %(sacas, litros)) 

    except:
        break
