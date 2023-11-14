# -*- coding: utf-8 -*-

pos = 1
maior = int(input())

for i in range(99):
    num = int(input())
    if num > maior:
        maior = num
        pos = i + 2

print(maior)
print(pos)