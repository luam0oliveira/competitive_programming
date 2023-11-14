# -*- coding: utf-8 -*-

n = int(input())

msg = ""

for i in input().split():
    letra = chr(int(i, 16))
    
    msg += letra

print(msg)
