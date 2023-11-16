# -*- coding: utf-8 -*-

def main():
    n = int(input())

    lista = {}

    for _ in range(n):
        num = int(input())
        if num not in lista:
            lista[num] = 1
        else:
            lista[num] += 1
    
    chaves = list(lista.keys())

    chaves.sort()
    
    for chave in chaves:
        print(f"{chave} aparece {lista[chave]} vez(es)")

if __name__ == "__main__":
    main()
