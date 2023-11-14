# -*- coding: utf-8 -*-

while True:
    frase = input()
    
    if frase == '*':
        break
    
    passo = True
    letra = frase[0].lower()

    for i in frase.split():
        if i[0].lower() != letra:
            passo = False
            break
        
    if passo:
        print("Y")
    else:
        print("N")
