# -*- coding: utf-8 -*-

import sys

def pre(palavra):
    final = []
    tam_palavra = len(palavra)
    metade = int((tam_palavra -1) / 2)
    for i in range(tam_palavra -1, -1, -1):
        letra = ""
        if (palavra[i] >= 'a' and palavra[i] <= 'z') or (palavra[i] >= 'A' and palavra[i] <= 'Z'):
            letra = chr(ord(palavra[i]) + 3)

        else:
            letra = palavra[i]

        if i <= metade:
            letra = chr(ord(letra) - 1)
        final.append(letra)

    return "".join(final)

def main():
    cases = int(input())
    for i in range(cases):
        palavra = sys.stdin.readline().rstrip()
        sys.stdout.write(pre(palavra) + "\n")

main()