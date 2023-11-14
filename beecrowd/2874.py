# -*- coding: utf-8 -*-

while True:
    try:    
        letras = int(input())
        string = ""

        for i in range(letras):
            binario = input()
            string += chr(int(binario,2))
        
        print(string)
    except:
        break
