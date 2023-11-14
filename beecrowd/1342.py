# -*- coding: utf-8 -*-

def main():
    while True:
        p, s = [int(i) for i in input().split()]

        if p == s == 0:
            break
            
        armd = [int(i) for i in input().split()]
        d = int(input())

        pos = [0] * p

        travados = [0] * p

        vez = 0
        venc = -1
        for i in range(d):
            while (travados[vez] == 1):
                travados[vez] = 0
                vez = (vez + 1) % p
            
            d1, d2= [int(j) for j in input().split()]

            casas = d1 + d2

            pos[vez] += casas

            if pos[vez] in armd:
                travados[vez] = 1

            if pos[vez] > s and venc == -1:
                venc = vez + 1
            
            vez = (vez + 1) % p
        print(venc)

main()