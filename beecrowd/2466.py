# -*- coding: utf-8 -*-

n = int(input())
actual = input().split()

for i in range(n - 1):
    temp = []
    for j in range(n - i - 1):
        if actual[j] != actual [j + 1]:
            temp.append(1)
        else:
            temp.append(-1)
    actual = temp

if actual[0] == -1:
    print("preta")
else:
    print("branca")
