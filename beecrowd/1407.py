# -*- coding: utf-8 -*-

def main():
    while True:
        n,c,k = [int(i) for i in input().split()]

        if n == c == k == 0:
            break
        nb = [0] * k

        menor = float("inf")

        for i in range(n):
            numbers = input().split()
            for num in numbers:
                num = int(num)
                nb[num - 1] += 1
                if nb[num - 1] < menor:
                    menor = nb[num - 1]
        menor = min(nb)
        first = True
        for i in range(k):
            if nb[i] == menor:
                if first:
                    print(i + 1, end="")
                    first = False
                else:
                    print(" %d" % (i + 1), end="")
        print()
        
main()