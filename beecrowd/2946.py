# -*- coding: utf-8 -*-

def binary_to_decimal(number):
    tam = len(number)
    num = 0

    for i in range(tam):
        num += int(number[tam - i - 1]) * (2 ** i)
    
    return num


def main():
    number = input()
    number = int(number, 2)
    cases = int(input())

    divisores = []
    nenhum = True
    for _ in range(cases):
        divisor = int(input())

        if number % divisor == 0:
            divisores.append(divisor)
            nenhum = False
    
    if nenhum:
        print("Nenhum")
    else:
        divisores.sort()
        print(*divisores, sep=" ")

main()