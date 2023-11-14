# -*- coding: utf-8 -*-

n = int(input())
for i in range(n):
    todo, parte = input().split()
    
    tamtodo = len(todo)
    tamparte = len(parte)
    
    inicio = tamtodo - tamparte
    
    fazparte = inicio >= 0
    
    if fazparte:
        for i in range(tamparte):
            if todo[i + inicio] != parte[i]:
                fazparte = False
                break
        
    if fazparte:
        print("encaixa")
    else:
        print("nao encaixa")
