# -*- coding: utf-8 -*-

time = 0
aant = 0
for i in range(int(input())):
    a = int(input())
    if a - aant < 10 and aant != 0:
        time += a - aant
    else:
        time += 10
    aant = a

print(time)
