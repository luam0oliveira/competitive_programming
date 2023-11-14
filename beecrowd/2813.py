# -*- coding: utf-8 -*-

dias = int(input())

guarda_chuvas_necessarios = [0, 0]
guarda_chuvas_atuais = [0, 0]

# a ideia principal eh verificar se ha guardas-chuva disponiveis no local
# se nao houver um guarda-chuva eh adicionado ao local

for i in range(dias):
    saida, volta = input().split()

    if saida == "chuva":
        if guarda_chuvas_atuais[0] == 0:
            guarda_chuvas_necessarios[0] += 1
            guarda_chuvas_atuais[1] += 1
        else:
            guarda_chuvas_atuais[0] -= 1
            guarda_chuvas_atuais[1] += 1
    
    if volta == "chuva":
        if guarda_chuvas_atuais[1] == 0:
            guarda_chuvas_necessarios[1] += 1
            guarda_chuvas_atuais[0] += 1
        else:
            guarda_chuvas_atuais[0] += 1
            guarda_chuvas_atuais[1] -= 1

print(*guarda_chuvas_necessarios, sep=" ")
