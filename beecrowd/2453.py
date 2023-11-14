# -*- coding: utf-8 -*-

strings = input().split()

decoded = []
for i in strings:
    text = ""
    length = len(i)
    for j in range(length):
        if j % 2 == 1:
            text += i[j]
    decoded.append(text)

print(*decoded, sep=" ")
