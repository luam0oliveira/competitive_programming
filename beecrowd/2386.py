# -*- coding: utf-8 -*-

# pegar a area de abertura do microscopio
o = int(input()) 

# inicia um contador de quantas estrelas é possivel ver com a configuracao de lente
estrelas = 0
for i in range(int(input())):
    estrela = int(input())
    
    # verifica se a multiplicacao de fotons emitidos pela area de abertura é mais ou igual a 40.000.000
    if estrela * o >= 40000000:
        estrelas+=1
    

print(estrelas)
