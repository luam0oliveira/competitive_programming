# -*- coding: utf-8 -*-

cd, cm = [int(i) for i in input().split()]
fd, fm = [int(i) for i in input().split()]

dias = fd - cd

for i in range(cm, fm):
    if i <= 7:
        if i % 2 == 0:
            if i == 2:
                dias += 28
            else:
                dias += 30
        if i % 2 == 1:
            dias += 31
    else:
        if i % 2 == 0:
            dias += 31
        else:
            dias += 30
print(dias)
