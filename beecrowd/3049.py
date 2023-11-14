# -*- coding: utf-8 -*-

# pega as entradas do usuario das distacias
top = int(input())
bottom = int(input())

# verifica qual das entradas é maior e as ordena sendo top a maior de todas
if top < bottom:
    top, bottom = bottom, top

# calcula a area da nota de felix, se soma a area do retangulo e a area do
# retangulo formado
area = bottom * 70 + (top - bottom) * 35

# faz a verificacao das areas comparando com a metade da nota
if area > (35 * 160):
    print("1")
elif area == (35 * 160):
    print("0")
else:
    print("2")
