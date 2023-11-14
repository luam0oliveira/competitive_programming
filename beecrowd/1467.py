# -*- coding: utf-8 -*-

while 2 > 1:
    try:
        a, b, c = input().split()
    except:
        break
    if a == b == c:
        print("*")
    elif a == b and b != c:
        print("C")
    elif a == c and b != c:
        print("B")
    else:
        print("A")
