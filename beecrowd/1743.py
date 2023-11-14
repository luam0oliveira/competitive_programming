# -*- coding: utf-8 -*-

a = input().split()
b = input().split()

passo = True

for i in range(5):
    if a[i] == b[i]:
        passo = False
        break
    
if passo:
    print("Y")
else:
    print("N")
