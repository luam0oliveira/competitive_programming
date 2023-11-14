# -*- coding: utf-8 -*-

op = input()

total = 0
pos = 144
for i in range(pos):
    value = float(input())
    line = i // 12
    col = i % 12
    if line < 5 and (col <= 5 and col > line or col >= 6 and col + line <= 10):
        total += value


if op == 'M':
    total /= 30
print("%.1f" % total)
