# -*- coding: utf-8 -*-

n, m, s = [int(i) for i in input().split()]

exercitoA = 0
exercitoB = 0

for i in range(s):
    ax, ay, ah = [int(j) for j in input().split()]

    if (m * ax / n) < ay:
        exercitoA += ah
    else:
        exercitoB += ah

print(exercitoA, exercitoB) 
