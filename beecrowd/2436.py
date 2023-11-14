# -*- coding: utf-8 -*-

# a ideia para resolucao eh verificar se alguma casa adjacente na mesma linha
# ou coluna possui o linha de caminho, se houver e esta nao for de onde veio,
# entao pode fazer o movimento para aquela casa. para de se verificar se ha 
# caminho se o robo nao fez algum movimento.

l, c = [int(i) for i in input().split()]

a,b = [int(i) for i in input().split()]

matrix = []

for i in range(l):
    
    line = input().split()
    line.insert(0,'0')
    line.insert(c + 1,'0')
    matrix.append(line)

matrix.insert(0 ,['0'] * (c + 1))
matrix.insert(l+1 ,['0'] * (c + 1))

# cima, direita, baixo, esquerda
ultimo = [0] * 4
passo = True
while passo:
    if matrix[a][b + 1] == '1' and ultimo[3] != 1:
        b += 1
        ultimo = [0] * 4
        ultimo[1] = 1
    
    elif matrix[a][b - 1] == '1' and ultimo[1] != 1:
        b -= 1
        ultimo = [0] * 4
        ultimo[3] = 1
        
    elif matrix[a + 1][b] == '1' and ultimo[2] != 1:
        a += 1
        ultimo = [0] * 4
        ultimo[0] = 1
        
    elif matrix[a - 1][b] == '1' and ultimo[0] != 1:
        a -= 1
        ultimo = [0] * 4
        ultimo[2] = 1
    else:
        passo = False
print(a, b)
