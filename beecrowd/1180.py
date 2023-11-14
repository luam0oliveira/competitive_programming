# -*- coding: utf-8 -*-

n = int(input())

nums = [int(i) for i in input().split()]

menor = nums[0]
pos = 0

for i in range(n):
    if menor > nums[i]:
        menor = nums[i]
        pos = i

print("Menor valor: %d\nPosicao: %d" %(menor, pos))
