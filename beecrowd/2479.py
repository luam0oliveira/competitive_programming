# -*- coding: utf-8 -*-

def main():
    num = int(input())
    criancas = []
    contC = 0
    contN = 0
    for _ in range(num):
        comp, nome = input().split()

        if comp == "+":
            contC += 1
        else:
            contN += 1
        
        criancas.append(nome)

    criancas.sort()

    print(*criancas, sep="\n")
    print("Se comportaram: %d | Nao se comportaram: %d" % (contC, contN ))
        
main()
