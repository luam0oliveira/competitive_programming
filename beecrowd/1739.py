# -*- coding: utf-8 -*-

memo = {}
three = []

def fibbo(n):
    if n == 1 or n == 2:
        memo[n] = 1
        return 1
    elif n not in memo:
        memo[n] = fibbo(n - 1) + fibbo(n - 2)
        if str(memo[n]).find('3') != -1 or memo[n] % 3 == 0:
            three.append(memo[n])
    return memo[n]

def create_60():
    n = 60
    while len(three) != 60:
        fibbo(n)
        n += 1

def main():
    create_60()
    while True:
        try:
            pos = int(input())
            print(three[pos - 1])
        except:
            break

if __name__ == "__main__":
    main()
