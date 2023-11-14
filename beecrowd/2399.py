# -*- coding: utf-8 -*-

lines = int(input())

n = [0 for i in range(lines)]

for i in range(lines):
    inp = input()
    if i == 0 and inp == '1':
        n[i] += 1
    if i != 0 and inp == '1':
        n[i - 1] += 1
        n[i] += 1
    if i != lines - 1 and inp == '1':
        n[i + 1] += 1
    
print(*n, sep="\n")
