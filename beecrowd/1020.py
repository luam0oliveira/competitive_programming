# -*- coding: utf-8 -*-

ind = int(input())

y = ind // 365
m = (ind - y * 365 ) // 30
d = ind - y * 365 - m * 30

print("%d ano(s)"% y)
print("%d mes(es)"% m)
print("%d dia(s)"% d)