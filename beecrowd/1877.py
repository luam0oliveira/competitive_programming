# -*- coding: utf-8 -*-

n, k = [int(i) for i in input().split()]

inp = [int(i) for i in input().split()]

pos_picos = []
pos_vales = []
valido = True

# crescente = 1, decrescente 2
cres = 1 if inp[0] < inp[1] else 2

for i in range(1, n):
    if cres == 1 and inp[i - 1] > inp[i]:
        pos_picos.append(i)
        cres = 2
    elif cres == 2 and inp[i - 1] < inp[i]:
        pos_vales.append(i)
        cres = 1

cres = 1 if inp[0] < inp[1] else 2
for i in range(1, pos_picos[0]):
    if cres == 2 or inp[i - 1] > inp[i]:
        valido = False
        break

for i in range(len(pos_vales)):
    if pos_vales[i] < pos_picos[i] or pos_picos[i + 1] < pos_vales[i]:
        valido = False
        break

for i in range(pos_picos[len(pos_picos) - 1], n - 1):
    if inp[i] < inp[i + 1]:
        valido = False
        break

if len(pos_picos) != k or len(pos_vales) != k - 1:
    valido = False

if valido:
    print("beautiful")
else:
    print("ugly")
