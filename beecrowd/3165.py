# -*- coding: utf-8 -*-

def main():
    n = int(input())

    for i in range(n, 1, -1):
        if is_prime(i):
            if is_prime(i - 2):
                print(i - 2, i)
                break

def is_prime(number):
    sqrt = number ** 0.5
    i = 2
    while sqrt >= i:
        if number % i == 0:
            return False
        i += 1
    return True

main()