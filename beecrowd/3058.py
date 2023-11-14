# -*- coding: utf-8 -*-

# pegar o numero de mercados a verificar
m = int(input())

# inicia a variavel menor para depois fazer comparacao
menor = 0
for i in range(m):
    # pegar o preco do produto e a quantidade dele em gramas
    preco, quantidade = input().split()
    preco = float(preco)
    quantidade = int(quantidade)
    
    # coloca o primeiro mercado como o menor de todos para depois fazer a
    # comparacao com os demais
    # verifica também se o menor preco é maior que o valor calculado atual,
    # se for maior, entao substitiu pelo valor atual
    if i == 0 or menor > (1000 / quantidade) * preco:
        menor = (1000 / quantidade) * preco

print("%.2f" % menor)
