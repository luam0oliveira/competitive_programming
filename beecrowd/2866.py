# -*- coding: utf-8 -*-

num = int(input())

decodificadas = []

for i in range(num):
    palavra = input()

    decodificada = ""
    
    for j in palavra:
        if j.islower():
            decodificada += j 
    
    aux = decodificada
    decodificada = ""
    for j in range(len(aux) - 1 , -1, -1 ):
        decodificada += aux[j]
    
    decodificadas.append(decodificada)

print(*decodificadas, sep="\n")
