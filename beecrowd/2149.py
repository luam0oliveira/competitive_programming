# -*- coding: utf-8 -*-

def sequence(n):
    if n == 1:
        return 0
    elif n == 2:
        return 1
    elif n % 2 == 0:
        return sequence(n-1) * sequence(n-2)
    return sequence(n-1) + sequence(n-2)

def main():
    while True:
        try:
            num = int(input())

            print(sequence(num))
        except:
            break

if __name__ == "__main__":
    main()
