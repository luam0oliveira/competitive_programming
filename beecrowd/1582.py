# -*- coding: utf-8 -*-

def mdc(a, b):
    while(b != 0):
        a,b = b, a % b
    return a

def ordenar(lados):
    lados2 = []

    idx = lados.index(max(lados))

    for i in range(3):
        if i != idx:
            lados2.append(lados[i])
        
    lados2.append(lados[idx])
    lados[:] = lados2

def is_pitagorica(lados):
    return lados[2] ** 2 == lados[1] ** 2 + lados[0] ** 2

def main():
    while True:
        try:
            lados = [int(i) for i in input().split()]
            
            ordenar(lados)

            is_pit = is_pitagorica(lados)
            
            is_prim = mdc(lados[2], mdc(lados[0], lados[1])) == 1

            if is_pit and is_prim:
                print("tripla pitagorica primitiva")
            elif is_pit:
                print("tripla pitagorica")
            else:
                print("tripla")

        except:
            break

if __name__ == "__main__":
    main()
