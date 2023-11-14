# -*- coding: utf-8 -*-

n = int(input())

for i in range(n):
    a = int(input())
    if a > 0:
        print("EVEN POSITIVE" if a % 2 == 0 else "ODD POSITIVE")
    elif a < 0:
        print("EVEN NEGATIVE" if a % 2 == 0 else "ODD NEGATIVE")
    else:
        print("NULL")
