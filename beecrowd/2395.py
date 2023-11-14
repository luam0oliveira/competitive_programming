# -*- coding: utf-8 -*-

a, b, c = [int(i) for i in input().split()]
x, y, z = [int(i) for i in input().split()]

tx = x // a
ty = y // b
tz = z // c
t = tx * ty * tz 
print("%d"% t)